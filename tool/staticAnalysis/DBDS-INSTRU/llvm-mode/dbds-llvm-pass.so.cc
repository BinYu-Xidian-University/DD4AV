/* GNU C Compiler Detection */
#ifdef __clang_version__
  #if __clang_major__ == 4
    #define LLVM_4
  #endif
  #if __clang_major__ == 11 || __clang_major__ == 12
    #define LLVM_11
  #endif
#endif

#define AFL_LLVM_PASS
#include "config.h"
#include "debug.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono> 
#include <algorithm>
#include <cassert>
#include "llvm/Pass.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/ADT/SmallVector.h"
#include <llvm/IR/Type.h>
#include <llvm/IR/User.h>
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/PassManager.h"
#include "llvm/IR/LegacyPassManager.h"
#include <llvm/IR/Module.h>			// for Module
#include <llvm/IR/Function.h>		// for Function
#include <llvm/IR/BasicBlock.h>		// for BasicBlock
#include <llvm/IR/Instructions.h>	// for Instructions
#include <llvm/IR/GlobalVariable.h>	// for GlobalVariable
#include <llvm/IR/InstrTypes.h>		// for TerminatorInst
#include <llvm/IR/IntrinsicInst.h>	// for intrinsic instruction
#include <llvm/IR/InstIterator.h>	// for inst iteration
#include <llvm/IR/CFG.h>			// for CFG
#include "llvm/IR/Constant.h"
#include "llvm/IR/Dominators.h"
#include "llvm/IR/DebugInfo.h"
#include "llvm/Analysis/PostDominators.h"
#include "llvm/Analysis/CallGraph.h"
#include <llvm/Analysis/CFG.h>		// for CFG
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Transforms/Utils/Local.h"	// for FindDbgAddrUses
#include <llvm/Support/CommandLine.h>
#include "llvm/Support/Debug.h"
#include "llvm/Support/Compiler.h"
#include "llvm/Support/raw_ostream.h"
#include <llvm/IRReader/IRReader.h>			// for isIRFiler isBitcode
#include <sys/resource.h>					// increase stack size
#include <boost/algorithm/string.hpp>

#ifdef LLVM_11
  #include <llvm/Pass.h>
#else
  #include "llvm/IR/CallSite.h"
  #include <llvm/PassAnalysisSupport.h>
#endif

using namespace llvm;
using namespace llvm;
using namespace std::chrono;
using namespace std;
using std::vector;

#define DEBUG_TYPE "DBDSPass"

namespace {

	class DBDSPass : public ModulePass {

    public:

		static char ID;
		DBDSPass() : ModulePass(ID) { }

		bool runOnModule(Module &M) override;

		StringRef getPassName() const override {
			return "DBDS Instrumentation";
		}

  };

}

char DBDSPass::ID = 0;

uint16_t address_hash_encoding(const char* str){
	uint16_t encodingNum = 0;//kl mod
	for(int k=0; k<strlen(str); k++){
		encodingNum *= int(str[k]);
		encodingNum = encodingNum + int(str[k]);
	}
	return encodingNum;
}

uint16_t string_hash_encoding(const char* str){
	// uint16_t encodingNum = 26;
	// for(int k=0; k<strlen(str); k++){
	// 	encodingNum *= int(str[k]);
	// 	encodingNum = encodingNum + int(str[k]);
	// }
	uint16_t encodingNum = 0;//kl mod
	
	uint16_t number = 0;

    const char* ptr = str;

    // Skip leading whitespaces
    
	while(*ptr != ':')
	{
		ptr++;
	}
	ptr++;
    // Extract digits
    while (*ptr >= '0' && *ptr <= '9') {
        number = number * 10 + (*ptr - '0');
        ptr++;
    }
	encodingNum = number;
	return encodingNum;
}

int CountLines(char *filename)
{
    ifstream ReadFile;
    int n=0;
    string line;
    ReadFile.open(filename,ios::in);//ios::in 表示以只读的方式读取文件
    if(ReadFile.fail())//文件打开失败:返回0
    {
        return 0;
    }
    else//文件存在
    {
        while(getline(ReadFile,line,'\n'))
        {
            if (line.size() == 0 || line.empty())
              continue;
            else
              n++;
        }
        ReadFile.close();
        return n;
    }
}
std::string getDynamicAddress(const Value* val) {
    if (val == nullptr) return "empty val";
    std::string rltstr;
    std::string str;
    raw_string_ostream rawstr(str);
    // raw_string_ostream Loadstr(str);
	// raw_string_ostream Storestr(str);
    if (const Instruction *inst = dyn_cast<Instruction>(val)) {
        if (const LoadInst *loadInst = dyn_cast<LoadInst>(inst)) {
            const Value *address = loadInst->getPointerOperand();
            address->print(rawstr);
			rltstr = "Load:" + rawstr.str();
        } else if (const StoreInst *storeInst = dyn_cast<StoreInst>(inst)) {
            const Value *address = storeInst->getPointerOperand();
			address->print(rawstr);
            rltstr = "Store:" + rawstr.str();
        } else {
            rltstr = "Unsupported instruction type";
        }
    } else {
        rltstr = "Unsupported value type";
    }
    
    return rltstr;
}


std::string getSourceLoc(const Value* val) {
  if(val==NULL)  return "empty val";

  std::string str;
  raw_string_ostream rawstr(str);
  if (const Instruction *inst = dyn_cast<Instruction>(val)) {
    if (isa<AllocaInst>(inst)) {
#ifdef LLVM_4 /* LLVM 4.0 */
	  DbgDeclareInst* DDI = llvm::FindAllocaDbgDeclare(const_cast<Instruction*>(inst));
      if (DDI) {
        DIVariable *DIVar = cast<DIVariable>(DDI->getVariable());
        rawstr << DIVar->getLine();
      }
#else /* LLVM 6.0+ */
      for (DbgInfoIntrinsic *DII : FindDbgAddrUses(const_cast<Instruction*>(inst))) {
        if (DbgDeclareInst *DDI = dyn_cast<DbgDeclareInst>(DII)) {
          DIVariable *DIVar = cast<DIVariable>(DDI->getVariable());
          rawstr << DIVar->getLine();
          break;
        }
      }
#endif
	  
    }
    else if (MDNode *N = inst->getMetadata("dbg")) { // Here I is an LLVM instruction
      DILocation* Loc = cast<DILocation>(N); // DILocation is in DebugInfo.h
      unsigned Line = Loc->getLine();
      StringRef File = Loc->getFilename();
      rawstr << File << ":" << Line;
      //StringRef Dir = Loc->getDirectory();
      //rawstr << Dir << "/" << File << ":" << Line;
    }
  }
  else {
    //Can only get source location for instruction, argument, global var or function.
    rawstr << "N.A.";
  }
  return rawstr.str();
}

// wcventure: the start of dbds-llvm-pass --------------------------------------------------------------------------------------

bool DBDSPass::runOnModule(Module &M) {
	
	LLVMContext &C = M.getContext();
	IntegerType *Int16Ty = IntegerType::getInt32Ty(C);
	IntegerType *Int32Ty = IntegerType::getInt32Ty(C);
	
	// 添加插桩函数的声明
	llvm::LLVMContext& context = M.getContext ();
	llvm::IRBuilder<> builder(context); 
	
	//Function instr_LOC
	std::vector<Type*> argTypesLOC;
	argTypesLOC.push_back(builder.getInt8PtrTy());
	argTypesLOC.push_back(builder.getInt32Ty());
	ArrayRef<Type*> argTypesRefLOC(argTypesLOC);
	llvm::FunctionType *funcLOCType = FunctionType::get(builder.getVoidTy(),argTypesRefLOC,false);
	llvm::Function *instr_LOCFunc = Function::Create(funcLOCType, llvm::Function::ExternalLinkage, "_Z9instr_LOCPvj", &M);

	// Function instr_SLOC
	std::vector<Type*> argTypesSLOC;
	argTypesSLOC.push_back(builder.getInt8PtrTy());
	argTypesSLOC.push_back(builder.getInt16Ty());
	argTypesSLOC.push_back(builder.getInt16Ty());
	ArrayRef<Type*> argTypesRefSLOC(argTypesSLOC);
	llvm::FunctionType *funcSLOCType = FunctionType::get(builder.getVoidTy(),argTypesRefSLOC,false);
	llvm::Function *instr_SLOCFunc = Function::Create(funcSLOCType, llvm::Function::ExternalLinkage, "_Z16instr_LOC_stringPvtt", &M);

	// Function instr_Call()
	std::vector<Type*> argTypesCall;
	argTypesCall.push_back(builder.getInt8PtrTy());
	ArrayRef<Type*> argTypesRefCall(argTypesCall);
	llvm::FunctionType *funcCallType = llvm::FunctionType::get(builder.getVoidTy(), argTypesRefCall, false);
	llvm::Function *instr_CallFunc = llvm::Function::Create(funcCallType, llvm::Function::ExternalLinkage, "_Z10instr_CallPv", &M);

	// Function instr_PthreadCall()
	std::vector<Type*> argTypesPthreadCall;
	argTypesPthreadCall.push_back(builder.getInt8PtrTy());
	ArrayRef<Type*> argTypesRefPthreadCall(argTypesPthreadCall);
	llvm::FunctionType *funcPthreadCallType = llvm::FunctionType::get(builder.getVoidTy(), argTypesRefPthreadCall, false);
	llvm::Function *instr_PthreadCallFunc = llvm::Function::Create(funcPthreadCallType, llvm::Function::ExternalLinkage, "_Z17instr_PthreadCallPv", &M);

	// Function instr_Return()
	std::vector<Type*> argTypesRet;
	argTypesRet.push_back(builder.getInt8PtrTy());
	ArrayRef<Type*> argTypesRefRet(argTypesRet);
	llvm::FunctionType *funcReturnType = llvm::FunctionType::get(builder.getVoidTy(), argTypesRefRet, false);
	llvm::Function *instr_ReturnFunc = llvm::Function::Create(funcReturnType, llvm::Function::ExternalLinkage, "_Z12instr_ReturnPv", &M);

	// Function instr_create()
	std::vector<Type*> argTypesCreate;
	argTypesCreate.push_back(Type::getInt64PtrTy(C));
	argTypesCreate.push_back(builder.getInt8PtrTy());
	ArrayRef<Type*> argTypesRefCreate(argTypesCreate);
	llvm::FunctionType *funcCreateType = llvm::FunctionType::get(builder.getVoidTy(), argTypesRefCreate, false);
	llvm::Function *instr_CreateFunc = llvm::Function::Create(funcCreateType, llvm::Function::ExternalLinkage, "_Z20instr_pthread_createPmPv", &M);
	
	// Function instr_Join
	std::vector<Type*> argTypesJoin;
	argTypesJoin.push_back(builder.getInt64Ty());
	ArrayRef<Type*> argTypesRefJoin(argTypesJoin);
	llvm::FunctionType *funcJoinType = FunctionType::get(builder.getVoidTy(),argTypesRefJoin,false);
	llvm::Function *instr_JoinFunc = Function::Create(funcJoinType, llvm::Function::ExternalLinkage, "_Z18instr_pthread_joinm", &M);

	// Function before_pthread_create
	llvm::FunctionType *funcBFCType = llvm::FunctionType::get(builder.getVoidTy(), false);
	llvm::Function *instr_BFCFunc = llvm::Function::Create(funcBFCType, llvm::Function::ExternalLinkage, "_Z21before_pthread_createv", &M);

	// Function traceEnd
	llvm::FunctionType *functraceEndType = llvm::FunctionType::get(builder.getVoidTy(), false);
	llvm::Function *instr_traceEndFunc = llvm::Function::Create(functraceEndType, llvm::Function::ExternalLinkage, "_Z8traceEndv", &M);
	
	/*wcventure 打开ConConfig文件*/

	char *Con_PATH = NULL;
	char *ConFileName;
	int linesNum = 0;
	int ConcurrencyInsteresting = 0;
	Con_PATH = getenv("Con_PATH");
	
	if (Con_PATH == NULL || strcmp(Con_PATH, "") == 0){
		ConcurrencyInsteresting = 0;
		outs() << "[DEBUG] Will use defult instru\n";
	}
	

	if (Con_PATH != NULL && Con_PATH[0] != '.' && Con_PATH[0] != ' ') {
		ConFileName = (char*)malloc(strlen(Con_PATH) + 1);
		if (ConFileName == NULL) {
			exit(1);
			return false;
		}
		strcpy(ConFileName, Con_PATH);
		linesNum = CountLines(ConFileName);
	} else {
		outs () << "[DEBUG] Please export Con_PATH" << "\n";
	}

	ifstream read_file;
	read_file.open(ConFileName, ios::binary);

	if (read_file.fail()) {
		outs() << "[DEBUG] Failed to open ConConfig file." << "\n";
		outs() << "[DEBUG] The program quit without execution." << "\n";
		ConcurrencyInsteresting = 0;
		exit(1);
		return false;
	} else {
		ConcurrencyInsteresting = 1;
		outs() << "[DEBUG] The ConConfig file was successfully opened.\n[DEBUG] The file is " << ConFileName << "\n[DEBUG]\n";
	}

	if (ConcurrencyInsteresting == 1) {
		string* ConLine = new string[linesNum];
		string line;
		for (int i=0; getline(read_file, line); i++){
			if (!line.empty() && line[line.size() - 1] == '\r'){
				if (line.size() == 1)
					ConLine[i] = "N.A.";
				else {
					ConLine[i] = line.erase(line.size() - 1);
					int spaceIndex = ConLine[i].find(" ");
					if (spaceIndex>=0)
						ConLine[i] = ConLine[i].substr(0,spaceIndex);
				}
			}
			else if (line.size() == 0 || line.empty())
			{
				continue;
			}
			else {
				ConLine[i] = line;
				int spaceIndex = ConLine[i].find(" ");
				if (spaceIndex>=0)
					ConLine[i] = ConLine[i].substr(0,spaceIndex);
			}
		}
#ifdef WC_DEBUG
		outs() << "[DEBUG] All the Concurent insteresting line are shown as follow:" << "\n";
		for (int i = 0; i < linesNum; i++){
			outs() << "[DEBUG]  " << i + 1 << ")\t" << ConLine[i].c_str() << "\n";
		}
#endif
		free(ConFileName);
		read_file.close();
		
		std::set<llvm::Function*> pthreadCallFunction; //找pthread_create的参数
		std::set<llvm::Function*>::iterator setit; //定义前向集合迭代器
		int Only_Instru_pthread_create = 0; //创建线程的函数是否只考虑pthread_create
		for (Module::iterator function = M.begin(), FEnd = M.end(); function != FEnd; function++) { 
			if (function->isDeclaration() || function->size() == 0){
				continue;
			}
			
			for (Function::iterator basicblock = function->begin(), BBEnd = function->end(); basicblock != BBEnd; basicblock++) { //遍历每一个Basic Block
				for(BasicBlock::iterator instruction = basicblock->begin(), IEnd = basicblock->end(); instruction!=IEnd; instruction++) {	//遍历每一条instruction
					if(Instruction *inst = dyn_cast<Instruction>(instruction)) {
						if(inst->getOpcode() == Instruction::Call){
							std::string instr_create = "pthread_create";
							if(inst->getNumOperands() == 5 ){ //操作数大于5
								if (instr_create == std::string(inst->getOperand(4)->getName())){ //找pthread_create
									Function *pthread_task = dyn_cast<Function>(inst->getOperand(2)->stripPointerCasts());
									if (pthread_task != NULL) {
										pthreadCallFunction.insert(pthread_task);
										Only_Instru_pthread_create = 1;
									}
								}
							}
						}
					}
				}
			}
		}

		if (Only_Instru_pthread_create == 0) { //找不到pthread_create函数，那就可能有用户封装了平pthread_create
			for (Module::iterator function = M.begin(), FEnd = M.end(); function != FEnd; function++) { 
				if (function->isDeclaration() || function->size() == 0){
					continue;
				}
				for (Function::iterator basicblock = function->begin(), BBEnd = function->end(); basicblock != BBEnd; basicblock++) { //遍历每一个Basic Block

					for(BasicBlock::iterator instruction = basicblock->begin(), IEnd = basicblock->end(); instruction!=IEnd; instruction++) {	//遍历每一条instruction
				
						if(Instruction *inst = dyn_cast<Instruction>(instruction)) {
							if(inst->getOpcode() == Instruction::Call){
								std::string instr_create2 = "PR_CreateThread";
								if(inst->getNumOperands() >= 5 ){ //操作数大于5

									int find_thread_flag = 0;
									int arg_id = 0;
									
									if (Only_Instru_pthread_create == 0 && inst->getNumOperands() == 8 && instr_create2 == std::string(inst->getOperand(7)->getName())){
										find_thread_flag = 1;
										arg_id = 1;
									}

									if (find_thread_flag==1){
										Function *pthread_task = dyn_cast<Function>(inst->getOperand(arg_id)->stripPointerCasts());
										pthreadCallFunction.insert(pthread_task);
									}
								}

								std::string instr_create3 = "create_pthread";
								if(inst->getNumOperands() >= 6 ){ //操作数大于6

									int find_thread_flag = 0;
									int arg_id = 0;
									
									if (Only_Instru_pthread_create == 0 && inst->getNumOperands() == 6 && instr_create3 == std::string(inst->getOperand(5)->getName())){
										find_thread_flag = 1;
										arg_id = 3;
									}

									if (find_thread_flag==1){
										Function *pthread_task = dyn_cast<Function>(inst->getOperand(arg_id)->stripPointerCasts());
										
										pthreadCallFunction.insert(pthread_task);
									}
								}
							}
						}
					}
				}
			}
		}
			
		
		// 后面才是正事		
		for (Module::iterator function = M.begin(), FEnd = M.end(); function != FEnd; function++) { //遍历每一个Function
			
			if (function->isDeclaration() || function->size() == 0){
				continue;
			}
			
			//if (std::string("conn_sett") == std::string(function->getName())) // some function in tests cause Segmentation fault when running pass 'Combine redundant instructions'
				//continue;
			
			BasicBlock::iterator FIP = function->begin()->getFirstInsertionPt(); // 函数入口插
			SmallVector<Value *, 1> retArg;//用一个Vector存放参数
			Value *CurFuncVa = ConstantExpr::getBitCast(&(*function), Type::getInt8PtrTy(C));
			retArg.push_back(CurFuncVa);
			IRBuilder<> IRB(&(*FIP));
			IRB.CreateCall(instr_CallFunc, retArg);

			if (function->getName() == "main") {				
				//main开头强制有一个关键点,同时可以设置此Pass忽略main函数
				SmallVector<Value *, 2> mlocArg;
				Value *conInte = ConstantInt::get(Int32Ty, 0);
				Value *CurFuncVal = ConstantExpr::getBitCast(&(*function), Type::getInt8PtrTy(C));
				mlocArg.push_back(CurFuncVal);
				mlocArg.push_back(conInte);
				IRB.CreateCall(instr_LOCFunc, mlocArg);
				//continue;
			} else {//对pthread_create的目标函数插桩
				
				Function* curF = &*function;
				for(setit = pthreadCallFunction.begin(); setit != pthreadCallFunction.end(); setit++) {  
					if (*setit == curF){
						SmallVector<Value *, 1> PCFArg;
						Value *CurFuncVal = ConstantExpr::getBitCast(&(*function), Type::getInt8PtrTy(C));
						PCFArg.push_back(CurFuncVal);
						IRB.CreateCall(instr_PthreadCallFunc, PCFArg);
						//outs() << curF->getName() << "\n";
						continue;
					}
				}
			}
			
			std::string LastLocString = "";

			for (Function::iterator basicblock = function->begin(), BBEnd = function->end(); basicblock != BBEnd; basicblock++) { //遍历每一个Basic Block

				//std::string LastLocString = "";
				
				for(BasicBlock::iterator instruction = basicblock->begin(), IEnd = basicblock->end(); instruction!=IEnd; instruction++) {	//遍历每一条instruction
			  
					if(Instruction *inst = dyn_cast<Instruction>(instruction)) {
						
						IRBuilder<> IRBuild(&(*(instruction)));//插桩的位置，插在该指令的后面
						
						if(inst->getOpcode() == Instruction::Ret) // Ret指令前插
						{
							SmallVector<Value *, 1> retArg;//用一个Vector存放参数
							Value *CurFuncVa = ConstantExpr::getBitCast(&(*function), Type::getInt8PtrTy(C));
							retArg.push_back(CurFuncVa);
							IRBuild.CreateCall(instr_ReturnFunc, retArg);
						}
						
						if(inst->getOpcode() == Instruction::Call){

							std::string instr_exit = "_exit";
							if(inst->getNumOperands() == 2 ){ //操作数大于2
								if(instr_exit == std::string(inst->getOperand(1)->getName())){
									//在exit前方插
									IRBuild.CreateCall(instr_traceEndFunc);
								}
							}

							std::string instr_create = "pthread_create";
							std::string instr_create2 = "PR_CreateThread";
							std::string instr_create3 = "create_pthread";
							std::string instr_join = "pthread_join";
							if(inst->getNumOperands() >= 5 ){ //操作数大于5

								if (Only_Instru_pthread_create == 1 && inst->getNumOperands() == 5 && instr_create == std::string(inst->getOperand(4)->getName())) { //找pthread_create
									
									//在pthread_create前方插
									IRBuild.CreateCall(instr_BFCFunc);
									
									//在pthread_create后方插
									SmallVector<Value *, 2> createArg;//用一个Vector存放参数
									Function *pthread_task = dyn_cast<Function>(inst->getOperand(2)->stripPointerCasts());
									Value *OpFuncV = ConstantExpr::getBitCast(pthread_task, Type::getInt8PtrTy(C));
									createArg.push_back(inst->getOperand(0));
									createArg.push_back(OpFuncV);
									BasicBlock::iterator tmptier = instruction;
									tmptier++;
									IRBuilder<> IRNEXT_Build(&(*(tmptier)));
									IRNEXT_Build.CreateCall(instr_CreateFunc, createArg);
									
								} else if (Only_Instru_pthread_create == 0 && inst->getNumOperands() == 8 && instr_create2 == std::string(inst->getOperand(7)->getName())) { //PR_CreateThread

									//PR_CreateThread
									IRBuild.CreateCall(instr_BFCFunc);
								} else if (Only_Instru_pthread_create == 0 && inst->getNumOperands() == 6 && instr_create3 == std::string(inst->getOperand(5)->getName())) { //create_pthread

									//create_pthread
									IRBuild.CreateCall(instr_BFCFunc);

									SmallVector<Value *, 2> createArg;//用一个Vector存放参数
									Function *pthread_task = dyn_cast<Function>(inst->getOperand(3)->stripPointerCasts());
									Value *OpFuncV = ConstantExpr::getBitCast(pthread_task, Type::getInt8PtrTy(C));
									createArg.push_back(inst->getOperand(0));
									createArg.push_back(OpFuncV);
									BasicBlock::iterator tmptier = instruction;
									tmptier++;
									IRBuilder<> IRNEXT_Build(&(*(tmptier)));
									IRNEXT_Build.CreateCall(instr_CreateFunc, createArg);
								}

							} else if(inst->getNumOperands() >= 3 ){ //操作数大于3
								
								if ((inst->getNumOperands() == 3 && instr_join == std::string(inst->getOperand(2)->getName())) //找pthread_join
									){
									SmallVector<Value *, 1> JoinArg;//用一个Vector存放参数
									JoinArg.push_back(inst->getOperand(0));
									BasicBlock::iterator tmptier = instruction;
									tmptier++;
									IRBuilder<> IRNEXT_Build(&(*(tmptier)));
									IRNEXT_Build.CreateCall(instr_JoinFunc, JoinArg);
								}
							}
						}
						
						//指令对应的代码行号
						std::string SourceLoc = getSourceLoc(inst);//利用getsl函数实现获得指令的行号
						std::string DynamicAddress = getDynamicAddress(inst);//获取执行地址
						//过滤掉自己插桩的instr_Call和instr_PthreadCallFunc
						if(inst->getOpcode() == Instruction::Call) {
							if (inst->getNumOperands()==2 && (inst->getOperand(1)==instr_PthreadCallFunc || inst->getOperand(1)==instr_CallFunc)){
								continue;
							}
						}

						if (LastLocString == SourceLoc) //跟上一条指令的行号一样，略过
							continue;
                        LastLocString = SourceLoc;

						if (SourceLoc.size() == 0) //SourceLoc为空则不用比较了，直接continue
							continue;
						
						if (SourceLoc.find(":")== std::string::npos) //SourceLoc可能取得有问题
							continue;
						
						std::string tmpstring("./");
						if (SourceLoc.compare(0, tmpstring.length(), tmpstring) == 0) {//如果SourceLoc前两个字符为"./", 则删除掉
							SourceLoc.erase(0,2);
						}
												
						for (int i = 0; i < linesNum; i++){
							if (boost::algorithm::ends_with(ConLine[i], SourceLoc)) { //rather than ConLine[i] == SourceLoc
								
								outs() << "[DEBUG] Instrumentation for " << SourceLoc << "\n";
											
								/*std::string strLocNum  = SourceLoc.substr(SourceLoc.find(":")+1);
								unsigned int LocNum = std::stoi(strLocNum); //行号转成整数
								
								SmallVector<Value *, 2> locArg;//用一个Vector存放参数
								Value *conInt = ConstantInt::get(Int32Ty, LocNum);
								Value *CurFuncV = ConstantExpr::getBitCast(&(*function), Type::getInt8PtrTy(C));
								locArg.push_back(CurFuncV);
								locArg.push_back(conInt);
								IRBuild.CreateCall(instr_LOCFunc, locArg);*/
								
								SmallVector<Value *, 2> slocArg;
								unsigned int tmpHashInt = string_hash_encoding(SourceLoc.c_str());
								Value *SlocLine = ConstantInt::get(Int16Ty, tmpHashInt);
								unsigned int tmpAddress =  address_hash_encoding(DynamicAddress.c_str());//kl add
								outs()<<"[DEBUG]"<<DynamicAddress.c_str() << "\n";
								Value *DAdress = ConstantInt::get(Int16Ty, tmpAddress);
								Value *CurFuncVa = ConstantExpr::getBitCast(&(*function), Type::getInt8PtrTy(C));
								slocArg.push_back(CurFuncVa);
								slocArg.push_back(SlocLine);
								slocArg.push_back(DAdress);
								IRBuild.CreateCall(instr_SLOCFunc, slocArg);
                                
                                break;
							}
						}
					}
				}
			}
		}
	}
	return true;
}


static void registerDBDSPass(const PassManagerBuilder &,
                            legacy::PassManagerBase &PM) {
	PM.add(new DBDSPass());
}


static RegisterStandardPasses RegisterDBDSPass(
    PassManagerBuilder::EP_ModuleOptimizerEarly, registerDBDSPass);

static RegisterStandardPasses RegisterDBDSPass0(
    PassManagerBuilder::EP_EnabledOnOptLevel0, registerDBDSPass);
