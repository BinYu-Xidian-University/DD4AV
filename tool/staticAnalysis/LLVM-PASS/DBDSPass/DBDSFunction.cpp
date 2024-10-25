#include "sched.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <map>
#include <dlfcn.h>
#include <cxxabi.h>
#include <ctime>
#include <chrono>
#include <pthread.h>
#include <time.h>
#include <fstream>
#include <iostream>
#include <sys/syscall.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/syscall.h>
#ifdef __linux__
#  include <linux/kernel.h>
#  include <linux/sched.h>
#  include <linux/types.h>
#endif /* __linux__ */

using namespace std;
using namespace std::chrono;

#define SHARE_MEMORY_THREAD_NUM 10
#define SHARE_MEMORY_ARRAY_SIZE 2000

typedef struct Sched_Info {
	uint64_t time;										// the execution time of the program (nsec)
	unsigned int N;										// number of threads concerned
	unsigned int M;										// number of kep points per thread
	unsigned int tupleScheduling;						// now considering tuple scheduling :1, otherwise: 0; Then it save the hash ID of first touched key point
	unsigned int kpNumArray[SHARE_MEMORY_THREAD_NUM];	// the specific kpNum of each My_tid Thread, only consider almost 10 thread
	unsigned int kp[SHARE_MEMORY_ARRAY_SIZE];			// how many times should a thread yield before a kp
	unsigned int kpLoc[SHARE_MEMORY_ARRAY_SIZE];		// the hash ID of Key Point
	unsigned int kpOrder[SHARE_MEMORY_ARRAY_SIZE];		// recored the order of key points
	
	/* KrystalRay enable/disable/r/w record*/

	unsigned int enableLine[SHARE_MEMORY_ARRAY_SIZE];	//record the Line of enablefunc
	unsigned int disableLine[SHARE_MEMORY_ARRAY_SIZE];	//record the Line of disablefunc
	unsigned int readLine[SHARE_MEMORY_ARRAY_SIZE];	//record the Line of read op
	unsigned int writeLine[SHARE_MEMORY_ARRAY_SIZE];	//record the Line of write op
} sched_info;//此处是共享变量结构体的定义

static bool NeedDryRun = false;
static bool DBDSRun = true;
static bool NoTrace = false;
static bool TupleScheduling = false;

static int num_td = 0;						// number of threads concerned
static int num_kp = 0;						// number of kep points per thread
static uint64_t DBDSruntime = 1000*1000;	// nsec
static unsigned int kpYield[SHARE_MEMORY_ARRAY_SIZE] = {0};	// how many times should a thread yield before a kp
static int c_tid = 0;						// child tid, initially 0
static int curSyncOrder = 1;				// recored the current order of key point, initially 1

static FILE *fp_trace;
static int mainTid;

static std::map<long int, int> my_tidMap;                       // the map from tid to My_Tid
static std::map<long int, int>::iterator my_tidMapiter;
static std::map<long int, long int> idx_kpMap;                  // the map from tid to idx_kp
static std::map<long int, long int> idx_original_kpMap;         // the map from tid to idx_kp (Initial Value)
static std::map<long int, long int>::iterator idx_kpMapiter;
static std::map<unsigned long int, long int> mapThread2Pid;     // the map from thread ID to tid
static std::map<unsigned long int, long int>::iterator T2Piter;
static std::map<long int, unsigned int> mapTid;                 // the map form tid to dynamic number of Key Points
static std::map<long int, unsigned int>::iterator Tiditer;
static system_clock::time_point startDryRun;			//与endDryRun变量共同完成对于程序的计时
static system_clock::time_point endDryRun;

sched_info * si;                                                //the information used to guide the scheduling

inline const char *get_funcname(const char *src) {
	int status = 99;
	const char *f = abi::__cxa_demangle(src, nullptr, nullptr, &status);
	return f == nullptr ? src : f;
}

uint16_t string_hash_encoding(char* str){
	uint16_t encodingNum = 26;
	for(int k=0;k<strlen(str);k++){
		encodingNum *= int(str[k]);
		encodingNum = encodingNum + int(str[k]);
	}
	return encodingNum;
}

void __attribute__((constructor)) traceBegin(void) {
	  
	mainTid = gettid();

	//获取环境变量，看是否需要DryRun
	char *Dry_Run = NULL;
	Dry_Run = getenv("Dry_Run");
	
	if (Dry_Run != NULL && strcmp(Dry_Run, "1") == 0){
		NeedDryRun = true;
	}
	
	//获取环境变量，看是否DBDS
	char *DBDS_Run = NULL;
	DBDS_Run = getenv("DBDS_Run");
	
	if (DBDS_Run != NULL && strcmp(DBDS_Run, "0") == 0){
		DBDSRun = false;
	}
	
	//获取环境变量，看是否DBDS
	char *NO_Trace = NULL;
	NO_Trace = getenv("NO_Trace");
	
	if (NO_Trace != NULL && strcmp(NO_Trace, "0") == 1){
		NoTrace = true;
	}
	
	//配置共享内存
	int shmid;
	key_t key = 1111;
	
	// Setup shared memory
	if ((shmid = shmget(key, sizeof(sched_info), IPC_CREAT | 0666)) < 0) {
		//printf("Error getting shared memory id. 1\n");
		DBDSRun = false;
	}
	// Attached shared memory
	if ((sched_info *) -1 == (si = (sched_info *)shmat(shmid, NULL, 0))) {
		//printf("Error attaching shared memory id. 2\n");
		DBDSRun = false;
	}

	// Initialize kpNumArray
	for (int i = 0; i < SHARE_MEMORY_THREAD_NUM; i++){
		si -> kpNumArray[i] = 0;
	}
	
	// Initialize kpLoc, kpOrder
	for (int i = 0; i < SHARE_MEMORY_ARRAY_SIZE; i++){
		si -> kpLoc[i] = 0;
		si -> kpOrder[i] = 0;
	}

	/* KrystalRay Initialize LineInfo*/
	// for (int i = 0; i < SHARE_MEMORY_ARRAY_SIZE; i++){
	// 	si -> enableLine[i] = 0;
	// 	si -> disableLine[i] = 0;
	// 	si -> readLine[i] = 0;
	// 	si -> writeLine[i] = 0;
	// 	// string kpLocstr[SHARE_MEMORY_ARRAY_SIZE] = "";
	// }

	// check whether in TupleScheduling
	if (si -> tupleScheduling == 1)
		TupleScheduling = true;
    
	set_tid_to_run(0);
	
	//start DBDSRun
	if (DBDSRun) {
		
		num_td = si -> N;
		num_kp = si -> M;
		DBDSruntime = si -> time;
		
		for (int i = 0; i < num_td*num_kp && i < SHARE_MEMORY_ARRAY_SIZE; i++)
			kpYield[i] = si -> kp[i];
	}
	
	//start NeedDryRun
	if (NeedDryRun) {
		if (NoTrace==true)			
			fp_trace = NULL;
		else
			fp_trace = fopen("func_trace.log", "w");
		startDryRun = system_clock::now();	//程序计时开始
	}

}

void __attribute__((destructor)) traceEnd(void) {

	unsigned int pidNum, MaxKPNum=0;
	for(Tiditer = mapTid.begin(), pidNum = 0; Tiditer != mapTid.end(); Tiditer++, pidNum++)
	{
		if(Tiditer->second > MaxKPNum && Tiditer->first != mainTid)
			MaxKPNum = Tiditer->second;
		if (my_tidMap[Tiditer->first - 1] < 10)
			si -> kpNumArray[my_tidMap[Tiditer->first - 1]] = Tiditer->second; // ignore main thread, here need to use (my_tid-1)
	}		
	
	si -> N = pidNum - 1;
	si -> M = MaxKPNum;

	if (NeedDryRun) {//这个模块是用来输出log的
		
		endDryRun = system_clock::now();	//程序结束用时
		
		auto durationDryRun = duration_cast<microseconds>(endDryRun - startDryRun);
		double DryRunTime = double(durationDryRun.count()) * microseconds::period::num / microseconds::period::den; //s为单位
		
		si -> time = (uint64_t)(DryRunTime*1000*1000);

		if (fp_trace != NULL) {
			
			fprintf(fp_trace, "Summary(Time: %lf (s))\n", DryRunTime);
			fprintf(fp_trace, "Summary(");
			for(Tiditer = mapTid.begin(); Tiditer != mapTid.end(); Tiditer++)
			{
				if(Tiditer != mapTid.begin())
					fprintf(fp_trace, ", ");
				fprintf(fp_trace, "%ld: %u", Tiditer->first, Tiditer->second);
			}
			fprintf(fp_trace, ")\n");
			fprintf(fp_trace, "Summary(ThraedNum:%d, KPNum:%d)\n", pidNum-1, MaxKPNum);
			
			fclose(fp_trace);
		}
	}
}

void instr_Call (void *func) 
{
	if (NeedDryRun) {
		Dl_info info;
		if (dladdr(func, &info) && fp_trace != NULL){
			fprintf(fp_trace, "Thread %ld (%lu) enter function: %s\n", gettid(), pthread_self(), get_funcname(info.dli_sname));
		}
	}
}

void instr_Return (void *func)
{
	if (NeedDryRun) {
		Dl_info info;
		if (dladdr(func, &info) && fp_trace != NULL){
			fprintf(fp_trace, "Thread %ld (%lu) exit function: %s\n", gettid(), pthread_self(), get_funcname(info.dli_sname));
		}
	}
}

void instr_LOC (void *func ,unsigned int a) 
{
    if(mapTid.find(gettid())!=mapTid.end())
    {
        mapTid[gettid()]++;
    } else {
        mapTid.insert(pair<long int, unsigned int>(gettid(), 1));;
    }
    
    if (NeedDryRun) {
		Dl_info info;
		
		if (dladdr(func, &info) && fp_trace != NULL){
			fprintf(fp_trace, "Tid: %ld, Function: %s, KeyPoint: %u\n", gettid(), get_funcname(info.dli_sname), a);
		}
	}
}

void instr_PthreadCall (void *func) //pthread_create中调用的那个函数
{
	if(mapThread2Pid.find(pthread_self())==mapThread2Pid.end()){
		mapThread2Pid.insert(pair<unsigned long int, long int>(pthread_self(), gettid()));
	}

	while(get_tid_to_run() == 0);		// wait until its his turn
	int sched_tid = get_tid_to_run();	// acquire the tid for sechduling
    
	if(my_tidMap.find(gettid())==my_tidMap.end()){
		my_tidMap.insert(pair<long int, int>(gettid(), sched_tid));
	}
    
    if(idx_kpMap.find(gettid())==idx_kpMap.end()){
		long int tid2index = (sched_tid-1) * num_kp;
        idx_kpMap.insert(pair<long int, long int>(gettid(), tid2index));
		idx_original_kpMap.insert(pair<long int, long int>(gettid(), tid2index));
        if (DBDSRun) {
            set_sched_dl((uint64_t)(DBDSruntime * 1000), (uint64_t)(DBDSruntime * 1000 * 10), (uint64_t)(DBDSruntime * 1000 * 10));
        }
    }
    
    set_tid_to_run(0);					// notify main thread to run

}

void before_pthread_create(){
	while(get_tid_to_run() != 0);		// wait until its his turn
	c_tid++;							// get the next child tid
	set_tid_to_run(c_tid);				// notify thread 1 to get ready
}//readme 239-241

void instr_pthread_create(unsigned long int *threadId, void *func){

	if (NeedDryRun) {

		Dl_info info;
		int SavePID;

		if(mapThread2Pid.find(*threadId)!=mapThread2Pid.end())
			SavePID = mapThread2Pid[*threadId];
		else
			SavePID = 0;
	
		if (fp_trace != NULL && dladdr(func, &info)){
			fprintf(fp_trace, "Thread %u (%lu) execute pthread_create(%s)\n", SavePID, *threadId, get_funcname(info.dli_sname));
		}
	}
}
void instr_pthread_join(unsigned long int threadId){
	if (NeedDryRun) {
		if (fp_trace != NULL){
			fprintf(fp_trace, "Thread %ld (%lu) execute pthread_join()\n", mapThread2Pid[threadId], threadId);
		}
	}
}



void instr_LOC_string (void *func ,void* str)//应该是在这个函数对关键点前后进行了操作，我们需要改动这个函数来实现我们的信息收集 void*str->string
{
	if(mapTid.find(gettid())!=mapTid.end())					// record kp number
	{
		mapTid[gettid()]++;

	} else {
		mapTid.insert(pair<long int, unsigned int>(gettid(), 1));;
	}

	unsigned int encodingNum = 0;							// hash encoding
	if(gettid()!=mainTid){
		char *strptr = (char *)str;
		encodingNum = string_hash_encoding(strptr);
	}
	
	char *char_str = static_cast<char*>(str);

    // 使用 char_str 进行处理，比如调用 strtol 函数将字符串转换为整数
    char *endptr;
    int result = strtol(char_str, &endptr, 10);//kl mod
	int loc = result;
	printf("loc is %d\n",loc);


	if (DBDSRun){
		if(gettid()!=mainTid){
			
			//printf("Thread %d (%lu): %d times to yield at kpYield[%lu] (%s).\n", my_tidMap[gettid()], gettid(), kpYield[idx_kpMap[gettid()]], idx_kpMap[gettid()], str);
			
			while(1) {										// perform DBDS yield pattern
				if(kpYield[idx_kpMap[gettid()]] <= 0) break;
				sched_yield();
				kpYield[idx_kpMap[gettid()]]--;
			}

			//idx_kpMap[gettid()]++; // move down already

			if (TupleScheduling){							// record the who first execute
				if (si -> tupleScheduling == 1)
					si -> tupleScheduling = encodingNum;
				else
					;
			}
		}
	}

	if(gettid()!=mainTid){
		si -> kpLoc[idx_kpMap[gettid()]] = encodingNum;		// save the hash ID           no kl direct location line
		printf("loc is %d\n",loc);
		// string kpLocstr[idx_kpMap[gettid()]] = str;


		int kp_order = __sync_fetch_and_add(&curSyncOrder, 1);
		si -> kpOrder[idx_kpMap[gettid()]] = kp_order;		// save the kp execution order
	}
    
    if(gettid()!=mainTid){
		if (idx_kpMap[gettid()] >= idx_original_kpMap[gettid()] + num_kp) {
			// if idx_kpMap[gettid()] reach the end of the bound of the thread, move idx_kpMap[gettid()] to the end.
			idx_kpMap[gettid()] = num_td*num_kp;
		} else {
			// increase one
			idx_kpMap[gettid()]++;
		}
    }
    
	if (NeedDryRun) {
		Dl_info info;
			
		if (dladdr(func, &info) && fp_trace != NULL){
			fprintf(fp_trace, "Tid: %ld, Function: %s, KeyPoint: %s\n", gettid(), get_funcname(info.dli_sname), str);
		}
	}
}
