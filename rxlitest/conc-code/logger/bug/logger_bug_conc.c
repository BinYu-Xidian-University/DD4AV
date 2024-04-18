
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

void __VERIFIER_atomic_TRANS_atomic_assume_task_communicate(void) {
__VERIFIER_assume(__TRANS_thread_running[1]==0);
}

void TRANS_atomic_assume_task_communicate(void) {
__VERIFIER_assume(__TRANS_thread_running[1]==0);
}

void __VERIFIER_atomic_TRANS_task_communicate_enter_thread() {
__VERIFIER_assume(__TRANS_thread_running[1]==0);
__TRANS_thread_running[0]=1;
__VERIFIER_assume(__TRANS_thread_running[1]==0);
}

void __VERIFIER_atomic_TRANS_task_communicate_leave_thread() {
__VERIFIER_assume(__TRANS_thread_running[1]==0);
__TRANS_thread_running[0]=0;
__VERIFIER_assume(__TRANS_thread_running[1]==0);
}

/*
void __VERIFIER_atomic_TRANS_atomic_assume_task_measure(void) {
__VERIFIER_assume(1);
}

void TRANS_atomic_assume_task_measure(void) {
__VERIFIER_assume(1);
}
*/

void __VERIFIER_atomic_TRANS_task_measure_enter_thread() {
__TRANS_thread_running[1]=1;
}

void __VERIFIER_atomic_TRANS_task_measure_leave_thread() {
__TRANS_thread_running[1]=0;
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
const int __CPROVER_thread_priorities[] = {5, 22};
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
  //if (numberOfRecords!=0) irq_err();
}

extern uint16_t read_sensor_value();
void *task_measure(void *arg) {
__VERIFIER_atomic_TRANS_task_measure_enter_thread();

  tickCounter++;

  if (tickCounter == interval) {
    uint16_t value = read_sensor_value();
 
    tickCounter = 0;
    intervalCounter++;
    
    records[numberOfRecords] =  value;
    numberOfRecords++;
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
//void task_communicate(void) {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_TRANS_task_communicate_enter_thread();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  uint8_t decodingStatus;
TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
  //uint8_t cmd = get_cmd(&decodingStatus);
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  uint8_t cmd = read_cmd();
TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  decodingStatus = CMD_DEC_ERROR;
TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();

  if(cmd==CMD_STOP || cmd==CMD_READ_STATE || 
     cmd==CMD_READ_DATA || cmd==CMD_START) {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_communicate();
    decodingStatus = CMD_DEC_OK;
TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
  }

__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  uint8_t rspStatus = RSP_SUCCESS;
TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();

  if (decodingStatus != CMD_DEC_OK) {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_communicate();
    rspStatus = RSP_ERROR;
TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
  }
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
  if (rspStatus == RSP_SUCCESS) {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
    switch(cmd) {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
      case CMD_STOP:   
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
// Lihao: lift if
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  uint8_t tmp_systemState = systemState;
TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
  if (tmp_systemState != LOGGING) {
  //if (systemState != LOGGING) {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_communicate();
           rspStatus = RSP_ERROR;
TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
        } else { //stop();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_communicate();
          systemState = IDLE;
TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
        }
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_communicate();
        send_response();
TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
        break;
      case CMD_READ_STATE:
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_communicate();
        send_response();
TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
	break;
      case CMD_READ_DATA:
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_communicate();
        send_response();
TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
	break;
      case CMD_START:
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
 // Lihao: lift if
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  tmp_systemState = systemState;
TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
  if (tmp_systemState != IDLE) { 
  //if (systemState != IDLE) { 
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_communicate();
          rspStatus = RSP_ERROR;  
TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
        } else {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_communicate();
          uint32_t _startTime = get_uint32();
TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_communicate();
          uint16_t _interval = get_uint16();
TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
	  //start(_startTime,_interval);
	  // Lihao: lift if
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_communicate();
        uint8_t tmp_numberOfRecords = numberOfRecords;
TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
   if (tmp_numberOfRecords+1 >= MAX_RECORDS) { //stop();
   //if (numberOfRecords+1 >= MAX_RECORDS) { //stop();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_communicate();
            systemState = IDLE;
TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
          }
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_communicate();
          intervalCounter = 0;
TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_communicate();
          tickCounter = 0;
TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_communicate();
          numberOfRecords = 0;
TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_communicate();
          startTime = _startTime;
TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_communicate();
          interval = _interval;
TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_communicate();
          systemState = LOGGING;
TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_communicate();
          //assert(numberOfRecords==0);
          __VERIFIER_assert(numberOfRecords==0);
          //if (numberOfRecords!=0) irq_err();
TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
        }
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_task_communicate();
        send_response();
TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
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
