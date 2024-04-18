
extern void __VERIFIER_atomic_begin();
extern void __VERIFIER_atomic_end();
extern void __VERIFIER_assume(int);

void __VERIFIER_assert(int x)
{ 
  if(!x)
   ERROR: goto ERROR;
}

//void irq_err(void) {ERROR: goto ERROR;}


int __TRANS_thread_running[] = {0, 0};

/*
void __VERIFIER_atomic_TRANS_atomic_assume_task_communicate(void) {
__VERIFIER_assume(1);
}

void __VERIFIER_atomic_TRANS_atomic_assume_task_communicate(void) {
__VERIFIER_assume(1);
}
*/

void __VERIFIER_atomic_TRANS_task_communicate_enter_thread() {
__TRANS_thread_running[0]=1;
}

void __VERIFIER_atomic_TRANS_task_communicate_leave_thread() {
__TRANS_thread_running[0]=0;
}

void __VERIFIER_atomic_TRANS_atomic_assume_task_measure(void) {
__VERIFIER_assume(__TRANS_thread_running[0]==0);
}

void TRANS_atomic_assume_task_measure(void) {
__VERIFIER_assume(__TRANS_thread_running[0]==0);
}

void __VERIFIER_atomic_TRANS_task_measure_enter_thread() {
__VERIFIER_assume(__TRANS_thread_running[0]==0);
__TRANS_thread_running[1]=1;
__VERIFIER_assume(__TRANS_thread_running[0]==0);
}

void __VERIFIER_atomic_TRANS_task_measure_leave_thread() {
__VERIFIER_assume(__TRANS_thread_running[0]==0);
__TRANS_thread_running[1]=0;
__VERIFIER_assume(__TRANS_thread_running[0]==0);
}


#include <pthread.h> 
#include <assert.h>

typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;

#define MAX_RECORDS  64
uint16_t numberOfRecords;
uint16_t records[MAX_RECORDS];

#define MAX_BUFFER  64
uint8_t msgBuffer[MAX_BUFFER];

uint32_t intervalCounter; 
uint16_t tickCounter;     
uint16_t interval;     
uint32_t startTime;

#define IDLE 0
#define LOGGING 1
uint8_t systemState;

#define CMD_DEC_OK 1
#define CMD_DEC_ERROR 0
#define RSP_SUCCESS 1
#define RSP_ERROR 0

#define TASK_COMMUNICATE 1
#define TASK_MEASURE 2

#define CMD_START 1
#define CMD_STOP 2
#define CMD_READ_STATE 3
#define CMD_READ_DATA 4

// Lihao
const int __CPROVER_thread_priorities[] = {5, 2};
const char* __CPROVER_threads[] = {"c::task_communicate", "c::task_measure"};

void stop(void)
{
  systemState = IDLE;
}

void start(uint32_t _startTime,uint16_t _interval)
{
  if (numberOfRecords+1 >= MAX_RECORDS) {//stop();
    systemState = IDLE;
  }
  intervalCounter = 0;
  tickCounter = 0;
  numberOfRecords = 0;
  startTime = _startTime;
  interval = _interval;
  systemState = LOGGING;
  //assert(numberOfRecords==0);
  __VERIFIER_assert(numberOfRecords==0);
  //if(numberOfRecords!=0) irq_err();
}

extern uint16_t read_sensor_value();
void *task_measure(void *arg) {
__VERIFIER_atomic_TRANS_atomic_assume_task_measure();
__VERIFIER_atomic_TRANS_task_measure_enter_thread();
__VERIFIER_atomic_TRANS_atomic_assume_task_measure();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_measure();
  tickCounter++;
TRANS_atomic_assume_task_measure();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_measure();
  // Lihao: lift if
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_measure();
  uint16_t tmp_tickCounter = tickCounter;
TRANS_atomic_assume_task_measure();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_measure();
 if (tmp_tickCounter == interval) {
 //if (tickCounter == interval) {
__VERIFIER_atomic_TRANS_atomic_assume_task_measure();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_measure();
    uint16_t value = read_sensor_value();
TRANS_atomic_assume_task_measure();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_measure();
 
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_measure();
    tickCounter = 0;
TRANS_atomic_assume_task_measure();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_measure();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_measure();
    intervalCounter++;
TRANS_atomic_assume_task_measure();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_measure();
    
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_measure();
    records[numberOfRecords] =  value;
TRANS_atomic_assume_task_measure();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_measure();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_measure();
    numberOfRecords++;
TRANS_atomic_assume_task_measure();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_measure();
  }
__VERIFIER_atomic_TRANS_task_measure_leave_thread();
}

extern uint8_t read_cmd();
uint8_t get_cmd(uint8_t* decodingStatus) {
  uint8_t cmd = read_cmd();
  *decodingStatus = CMD_DEC_ERROR;

  if(cmd==CMD_STOP || cmd==CMD_READ_STATE || 
     cmd==CMD_READ_DATA || cmd==CMD_START) {
    *decodingStatus = CMD_DEC_OK;
  }
  return cmd;
}

extern uint16_t get_uint16();
extern uint32_t get_uint32();
extern void send_response();
void *task_communicate(void *arg) {
__VERIFIER_atomic_TRANS_task_communicate_enter_thread();

  uint8_t decodingStatus;
  //uint8_t cmd = get_cmd(&decodingStatus);
  uint8_t cmd = read_cmd();
  decodingStatus = CMD_DEC_ERROR;

  if(cmd==CMD_STOP || cmd==CMD_READ_STATE || 
     cmd==CMD_READ_DATA || cmd==CMD_START) {
    decodingStatus = CMD_DEC_OK;
  }

  uint8_t rspStatus = RSP_SUCCESS;

  if (decodingStatus != CMD_DEC_OK) {
    rspStatus = RSP_ERROR;
  }
  if (rspStatus == RSP_SUCCESS) {
    switch(cmd) {
      case CMD_STOP:   
        if (systemState != LOGGING) {
           rspStatus = RSP_ERROR;
        } else { //stop();
          systemState = IDLE;
        }
        send_response();
        break;
      case CMD_READ_STATE:
        send_response();
	break;
      case CMD_READ_DATA:
        send_response();
	break;
      case CMD_START:
        if (systemState != IDLE) { 
          rspStatus = RSP_ERROR;  
        } else {
          uint32_t _startTime = get_uint32();
          uint16_t _interval = get_uint16();
	  //start(_startTime,_interval);
	  if (numberOfRecords+1 >= MAX_RECORDS) { //stop();
            systemState = IDLE;
          }
          intervalCounter = 0;
          tickCounter = 0;
          numberOfRecords = 0;
          startTime = _startTime;
          interval = _interval;
          systemState = LOGGING;
          //assert(numberOfRecords==0);
          __VERIFIER_assert(numberOfRecords==0);
          //if(numberOfRecords!=0) irq_err();
        }
        send_response();
        break;
      default: break;
    }
  }

__VERIFIER_atomic_TRANS_task_communicate_leave_thread();
}


void initialize(void) {
  systemState = IDLE;
}

void run(void)
{
  // Lihao
//while(1) {
  pthread_t t1, t2;
  pthread_create(&t1, NULL, task_communicate, NULL);
  pthread_create(&t2, NULL, task_measure, NULL);
//}

/*
  __CPROVER_ASYNC_1: 
  task_communicate();

  __CPROVER_ASYNC_1: 
  task_measure();
*/

/*
  while(1) {
    uint8_t currentTask;
    switch(currentTask) {
      case TASK_COMMUNICATE :
        task_communicate();
	break;
      case TASK_MEASURE:
        task_measure();
        break;
      default: break;
    }
  }
*/
}

void main() {
    initialize();
    run();
}
