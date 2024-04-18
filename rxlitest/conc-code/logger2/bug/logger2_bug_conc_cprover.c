int __TRANS_thread_running[] = {0, 0, 0, 0};

void __VERIFIER_atomic_TRANS_atomic_assume_task_communicate(void) {
__CPROVER_assume( __TRANS_thread_running[1]==0);
}

void TRANS_atomic_assume_task_communicate(void) {
__CPROVER_assume( __TRANS_thread_running[1]==0);
}

void __VERIFIER_atomic_TRANS_task_communicate_enter_thread() {
__CPROVER_assume( __TRANS_thread_running[1]==0);
__TRANS_thread_running[0]=1;
__CPROVER_assume( __TRANS_thread_running[1]==0);
}

void __VERIFIER_atomic_TRANS_task_communicate_leave_thread() {
__CPROVER_assume( __TRANS_thread_running[1]==0);
__TRANS_thread_running[0]=0;
__CPROVER_assume( __TRANS_thread_running[1]==0);
}

void __VERIFIER_atomic_TRANS_atomic_assume_task_communicate2(void) {
__CPROVER_assume( __TRANS_thread_running[0]==0);
}

void TRANS_atomic_assume_task_communicate2(void) {
__CPROVER_assume( __TRANS_thread_running[0]==0);
}

void __VERIFIER_atomic_TRANS_task_communicate2_enter_thread() {
__CPROVER_assume( __TRANS_thread_running[0]==0);
__TRANS_thread_running[1]=1;
__CPROVER_assume( __TRANS_thread_running[0]==0);
}

void __VERIFIER_atomic_TRANS_task_communicate2_leave_thread() {
__CPROVER_assume( __TRANS_thread_running[0]==0);
__TRANS_thread_running[1]=0;
__CPROVER_assume( __TRANS_thread_running[0]==0);
}

void __VERIFIER_atomic_TRANS_atomic_assume_task_measure(void) {
__CPROVER_assume(__TRANS_thread_running[0]==0 && __TRANS_thread_running[1]==0);
}

void TRANS_atomic_assume_task_measure(void) {
__CPROVER_assume(__TRANS_thread_running[0]==0 && __TRANS_thread_running[1]==0);
}

void __VERIFIER_atomic_TRANS_task_measure_enter_thread() {
__CPROVER_assume(__TRANS_thread_running[0]==0 && __TRANS_thread_running[1]==0);
__TRANS_thread_running[2]=1;
__CPROVER_assume(__TRANS_thread_running[0]==0 && __TRANS_thread_running[1]==0);
}

void __VERIFIER_atomic_TRANS_task_measure_leave_thread() {
__CPROVER_assume(__TRANS_thread_running[0]==0 && __TRANS_thread_running[1]==0);
__TRANS_thread_running[2]=0;
__CPROVER_assume(__TRANS_thread_running[0]==0 && __TRANS_thread_running[1]==0);
}

void __VERIFIER_atomic_TRANS_atomic_assume_task_ext_power(void) {
__CPROVER_assume(__TRANS_thread_running[0]==0 && __TRANS_thread_running[1]==0 && __TRANS_thread_running[2]==0);
}

void TRANS_atomic_assume_task_ext_power(void) {
__CPROVER_assume(__TRANS_thread_running[0]==0 && __TRANS_thread_running[1]==0 && __TRANS_thread_running[2]==0);
}

void __VERIFIER_atomic_TRANS_task_ext_power_enter_thread() {
__CPROVER_assume(__TRANS_thread_running[0]==0 && __TRANS_thread_running[1]==0 && __TRANS_thread_running[2]==0);
__TRANS_thread_running[3]=1;
__CPROVER_assume(__TRANS_thread_running[0]==0 && __TRANS_thread_running[1]==0 && __TRANS_thread_running[2]==0);
}

void __VERIFIER_atomic_TRANS_task_ext_power_leave_thread() {
__CPROVER_assume(__TRANS_thread_running[0]==0 && __TRANS_thread_running[1]==0 && __TRANS_thread_running[2]==0);
__TRANS_thread_running[3]=0;
__CPROVER_assume(__TRANS_thread_running[0]==0 && __TRANS_thread_running[1]==0 && __TRANS_thread_running[2]==0);
}

//void irq_err(void) {ERROR: goto ERROR;}

#include <assert.h>
#include <pthread.h>

typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;

#define MAX_RECORDS  64
uint8_t numberOfRecords;
uint16_t records[MAX_RECORDS];

#define MAX_BUFFER 16

uint32_t periodCounter; 
uint16_t tickCounter;     
uint16_t period;     
uint32_t startTime;

#define IDLE 0
#define LOGGING 1
#define SLEEP 2
uint8_t systemState;

#define CMD_DEC_OK 1
#define CMD_DEC_ERROR 0
#define RSP_SUCCESS 1
#define RSP_ERROR 0

#define CMD_RESTART 1
#define CMD_STOP 2
#define CMD_READ_STATE 3
#define CMD_READ_DATA 4

// Lihao
const int __CPROVER_thread_priorities[] = {22, 5, 1};
const char* __CPROVER_threads[] = {"c::task_communicate", "c::task_measure", "c::task_ext_power"};

void restart(uint32_t _startTime,uint16_t _period)
{
  if (numberOfRecords+1 >= MAX_RECORDS) {
    systemState = IDLE;
  }
  periodCounter = 0;
  tickCounter = 0;
  numberOfRecords = 0;
  startTime = _startTime;
  period = _period;
  systemState = LOGGING;
}

extern uint16_t read_sensor_value();
extern uint16_t process_value(uint32_t time, uint16_t value);
//void *task_measure(void *args) {
void task_measure(void) {
__VERIFIER_atomic_TRANS_atomic_assume_task_measure();
__VERIFIER_atomic_TRANS_task_measure_enter_thread();
__VERIFIER_atomic_TRANS_atomic_assume_task_measure();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_measure();
  __CPROVER_assume(systemState==LOGGING);
TRANS_atomic_assume_task_measure();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_measure();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_measure();
  tickCounter++;
TRANS_atomic_assume_task_measure();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_measure();
  // Lihao: lift if
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_measure();
  uint16_t tmp_tickCounter = tickCounter;
TRANS_atomic_assume_task_measure();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_measure();
  if (tmp_tickCounter == period) {
  //if (tickCounter == period) {
__VERIFIER_atomic_TRANS_atomic_assume_task_measure();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_measure();
    uint16_t value = read_sensor_value();
TRANS_atomic_assume_task_measure();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_measure();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_measure();
    uint8_t pos = numberOfRecords;
TRANS_atomic_assume_task_measure();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_measure();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_measure();
    uint32_t _startTime = startTime;
TRANS_atomic_assume_task_measure();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_measure();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_measure();
    uint32_t currentTime = _startTime + period*periodCounter+tickCounter;
TRANS_atomic_assume_task_measure();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_measure();
 
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_measure();
    tickCounter = 0;
TRANS_atomic_assume_task_measure();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_measure();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_measure();
    periodCounter++;
TRANS_atomic_assume_task_measure();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_measure();
    
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_measure();
    records[pos] =  process_value(currentTime,value);
TRANS_atomic_assume_task_measure();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_measure();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_measure();
    numberOfRecords++;
TRANS_atomic_assume_task_measure();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_measure();
    //assert(startTime==_startTime);
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_measure();
    assert(numberOfRecords==pos+1);
    //if (numberOfRecords!=pos+1) irq_err();
TRANS_atomic_assume_task_measure();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_measure();
  }
__VERIFIER_atomic_TRANS_task_measure_leave_thread();
}

extern uint8_t get_power_status();
//void *task_ext_power(void *args) {
void task_ext_power(void) {
__VERIFIER_atomic_TRANS_atomic_assume_task_ext_power();
__VERIFIER_atomic_TRANS_task_ext_power_enter_thread();
__VERIFIER_atomic_TRANS_atomic_assume_task_ext_power();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_ext_power();
  uint8_t power = get_power_status();
TRANS_atomic_assume_task_ext_power();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_ext_power();
  // Lihao: lift if
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_ext_power();
  uint8_t tmp_systemState = systemState;
TRANS_atomic_assume_task_ext_power();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_ext_power();
  if(power && tmp_systemState==SLEEP) {
  //if(power && systemState==SLEEP) {
__VERIFIER_atomic_TRANS_atomic_assume_task_ext_power();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_ext_power();
    systemState = IDLE;
TRANS_atomic_assume_task_ext_power();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_ext_power();
  }

__VERIFIER_atomic_TRANS_atomic_assume_task_ext_power();
   // Lihao: lift if
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_ext_power();
  tmp_systemState = systemState;
TRANS_atomic_assume_task_ext_power();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_ext_power();
  if(!power && tmp_systemState==IDLE) {
  //if(!power && systemState==IDLE) {
__VERIFIER_atomic_TRANS_atomic_assume_task_ext_power();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_ext_power();
    systemState = SLEEP;
TRANS_atomic_assume_task_ext_power();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_ext_power();
  }
__VERIFIER_atomic_TRANS_task_ext_power_leave_thread();
}

uint8_t get_cmd(uint8_t* buffer, uint8_t* cmd) {
}

uint16_t get_uint16(uint8_t* buffer, uint8_t pos) {
  return (((uint16_t)buffer[pos])<<8) | (uint16_t)buffer[pos+1];
}
void put_uint16(uint8_t* buffer, uint8_t pos, uint16_t val) {
  buffer[pos] = (uint8_t)(val>>8);
  buffer[pos+1] = (uint8_t)val;
}
uint32_t get_uint32(uint8_t* buffer, uint8_t pos) {
  return (((uint32_t)buffer[pos])<<24) | 
         (((uint32_t)buffer[pos+1])<<16) | 
         (((uint32_t)buffer[pos+2])<<8) | 
         (uint32_t)buffer[pos+3];
}
void put_uint32(uint8_t* buffer, uint8_t pos, uint32_t val) {
  buffer[pos] = (uint8_t)(val>>24);
  buffer[pos+1] = (uint8_t)(val>>16);
  buffer[pos+2] = (uint8_t)(val>>8);
  buffer[pos+3] = (uint8_t)val;
}
extern uint8_t nondet_uint8();
uint8_t receive_cmd(uint8_t* buffer) {
  buffer[0] = nondet_uint8();
  buffer[1] = nondet_uint8();
  buffer[2] = nondet_uint8();
  buffer[3] = nondet_uint8();
  buffer[4] = nondet_uint8();
  buffer[5] = nondet_uint8();
  buffer[6] = nondet_uint8();
}
extern void send_response(uint8_t* buffer, uint8_t len);
uint8_t msgBuffer[MAX_BUFFER];

//void *task_communicate(void *args) {
void task_communicate(void) {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_TRANS_task_communicate_enter_thread();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  uint8_t tmp_systemState; // Lihao: lift if 
  uint8_t tmp_numberOfRecords; // Lihao: lift if
  __CPROVER_assume(systemState!=SLEEP);
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
  // Lihao: inline 
  //uint8_t len = receive_cmd(msgBuffer);
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  msgBuffer[0] = nondet_uint8();
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  msgBuffer[1] = nondet_uint8();
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  msgBuffer[2] = nondet_uint8();
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  msgBuffer[3] = nondet_uint8();
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  msgBuffer[4] = nondet_uint8();
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  msgBuffer[5] = nondet_uint8();
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  msgBuffer[6] = nondet_uint8();
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();

__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  uint8_t cmd = msgBuffer[0];
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  uint8_t decodingStatus = CMD_DEC_ERROR;
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
  if(cmd==CMD_STOP || cmd==CMD_READ_STATE || cmd==CMD_READ_DATA ||
     cmd==CMD_RESTART) {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
    decodingStatus = CMD_DEC_OK;
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
  }
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
  if (decodingStatus != CMD_DEC_OK) {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
    msgBuffer[0] = RSP_ERROR;
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
    send_response(msgBuffer,1);
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
  } else {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
    uint8_t rspStatus = RSP_SUCCESS;
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
    switch(cmd) {
      case CMD_STOP:   
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
// Lihao: lift if
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  tmp_systemState = systemState;
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
        if (tmp_systemState != LOGGING) {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
          rspStatus = RSP_ERROR;
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
        } else {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
          systemState = IDLE;
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
        }
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
        msgBuffer[0] = rspStatus;
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
// Lihao: lift if
 __CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  tmp_systemState = systemState;
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
        if(tmp_systemState==SLEEP) {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_TRANS_task_communicate_leave_thread();
          return ;
        }
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
        send_response(msgBuffer,1);
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
        break;
      case CMD_READ_STATE:
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
        msgBuffer[0] = rspStatus;
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
        msgBuffer[1] = systemState;
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
        msgBuffer[2] = numberOfRecords;
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
	// Lihao: inline
        //put_uint32(msgBuffer,3,startTime);
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
   	msgBuffer[3] = (uint8_t)(startTime>>24);
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  	msgBuffer[4] = (uint8_t)(startTime>>16);
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  	msgBuffer[5] = (uint8_t)(startTime>>8);
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  	msgBuffer[6] = (uint8_t)startTime;
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
// Lihao: lift if
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  tmp_systemState = systemState;
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
        if(tmp_systemState==SLEEP) {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_TRANS_task_communicate_leave_thread();
          return ;
        }
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
        send_response(msgBuffer,7);
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
	break;
      case CMD_READ_DATA: {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
        uint8_t pos = msgBuffer[1];
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
   // Lihao: lift if
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
        tmp_numberOfRecords = numberOfRecords;
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
        if(pos>=tmp_numberOfRecords) {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
          msgBuffer[0] = RSP_ERROR;
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
// Lihao: lift if
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  tmp_systemState = systemState;
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
          if(tmp_systemState==SLEEP) {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_TRANS_task_communicate_leave_thread();
            return ;
          }
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
          send_response(msgBuffer,1);
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
  	} else {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
          msgBuffer[0] = RSP_SUCCESS;
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
	  // Lihao: inline
          //put_uint16(msgBuffer,1,records[pos]);
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
          msgBuffer[1] = (uint8_t)(records[pos]>>8);
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
          msgBuffer[2] = (uint8_t)records[pos];
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
// Lihao: lift if
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  tmp_systemState = systemState;
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
          if(tmp_systemState==SLEEP) {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_TRANS_task_communicate_leave_thread();
            return ;
          }
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
          send_response(msgBuffer,3);
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
	}
	break;
      }
      case CMD_RESTART: {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
        uint32_t _startTime = get_uint32(msgBuffer,1);
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
        uint16_t _period = get_uint16(msgBuffer,5);
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
	// Lihao: inline
        //restart(_startTime,_period);
    // Lihao: lift if
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
        tmp_numberOfRecords = numberOfRecords;
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
        if (tmp_numberOfRecords+1 >= MAX_RECORDS) {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
          systemState = IDLE;
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
        }
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  	periodCounter = 0;
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  	tickCounter = 0;
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  	numberOfRecords = 0;
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  	startTime = _startTime;
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  	period = _period;
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  	systemState = LOGGING;
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();

__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
        msgBuffer[0] = rspStatus;
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
  // Lihao: lift if
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
  tmp_systemState = systemState;
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
        if(tmp_systemState==SLEEP) {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__VERIFIER_atomic_TRANS_task_communicate_leave_thread();
          return ;
        }
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate();
        send_response(msgBuffer,1);
TRANS_atomic_assume_task_communicate();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
        break;
      }
      default: 
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate();
        break;
    }
__VERIFIER_atomic_TRANS_task_communicate_leave_thread();
  }
__VERIFIER_atomic_TRANS_task_communicate_leave_thread();
}

//void *task_communicate2(void *args) {
void task_communicate2(void) {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__VERIFIER_atomic_TRANS_task_communicate2_enter_thread();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
  uint8_t tmp_systemState; // Lihao: lift if 
  uint8_t tmp_numberOfRecords; // Lihao: lift if
  __CPROVER_assume(systemState!=SLEEP);
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
  // Lihao: inline 
  //uint8_t len = receive_cmd(msgBuffer);
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
  msgBuffer[0] = nondet_uint8();
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
  msgBuffer[1] = nondet_uint8();
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
  msgBuffer[2] = nondet_uint8();
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
  msgBuffer[3] = nondet_uint8();
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
  msgBuffer[4] = nondet_uint8();
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
  msgBuffer[5] = nondet_uint8();
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
  msgBuffer[6] = nondet_uint8();
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();

__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
  uint8_t cmd = msgBuffer[0];
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
  uint8_t decodingStatus = CMD_DEC_ERROR;
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
  if(cmd==CMD_STOP || cmd==CMD_READ_STATE || cmd==CMD_READ_DATA ||
     cmd==CMD_RESTART) {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
    decodingStatus = CMD_DEC_OK;
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
  }
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
  if (decodingStatus != CMD_DEC_OK) {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
    msgBuffer[0] = RSP_ERROR;
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
    send_response(msgBuffer,1);
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
  } else {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
    uint8_t rspStatus = RSP_SUCCESS;
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
    switch(cmd) {
      case CMD_STOP:   
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
// Lihao: lift if
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
  tmp_systemState = systemState;
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
        if (tmp_systemState != LOGGING) {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
          rspStatus = RSP_ERROR;
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
        } else {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
          systemState = IDLE;
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
        }
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
        msgBuffer[0] = rspStatus;
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
// Lihao: lift if
 __CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
  tmp_systemState = systemState;
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
        if(tmp_systemState==SLEEP) {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__VERIFIER_atomic_TRANS_task_communicate2_leave_thread();
          return ;
        }
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
        send_response(msgBuffer,1);
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
        break;
      case CMD_READ_STATE:
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
        msgBuffer[0] = rspStatus;
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
        msgBuffer[1] = systemState;
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
        msgBuffer[2] = numberOfRecords;
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
	// Lihao: inline
        //put_uint32(msgBuffer,3,startTime);
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
   	msgBuffer[3] = (uint8_t)(startTime>>24);
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
  	msgBuffer[4] = (uint8_t)(startTime>>16);
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
  	msgBuffer[5] = (uint8_t)(startTime>>8);
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
  	msgBuffer[6] = (uint8_t)startTime;
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
// Lihao: lift if
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
  tmp_systemState = systemState;
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
        if(tmp_systemState==SLEEP) {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__VERIFIER_atomic_TRANS_task_communicate2_leave_thread();
          return ;
        }
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
        send_response(msgBuffer,7);
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
	break;
      case CMD_READ_DATA: {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
        uint8_t pos = msgBuffer[1];
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
   // Lihao: lift if
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
        tmp_numberOfRecords = numberOfRecords;
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
        if(pos>=tmp_numberOfRecords) {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
          msgBuffer[0] = RSP_ERROR;
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
// Lihao: lift if
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
  tmp_systemState = systemState;
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
          if(tmp_systemState==SLEEP) {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__VERIFIER_atomic_TRANS_task_communicate2_leave_thread();
            return ;
          }
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
          send_response(msgBuffer,1);
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
  	} else {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
          msgBuffer[0] = RSP_SUCCESS;
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
	  // Lihao: inline
          //put_uint16(msgBuffer,1,records[pos]);
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
          msgBuffer[1] = (uint8_t)(records[pos]>>8);
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
          msgBuffer[2] = (uint8_t)records[pos];
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
// Lihao: lift if
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
  tmp_systemState = systemState;
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
          if(tmp_systemState==SLEEP) {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__VERIFIER_atomic_TRANS_task_communicate2_leave_thread();
            return ;
          }
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
          send_response(msgBuffer,3);
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
	}
	break;
      }
      case CMD_RESTART: {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
        uint32_t _startTime = get_uint32(msgBuffer,1);
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
        uint16_t _period = get_uint16(msgBuffer,5);
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
	// Lihao: inline
        //restart(_startTime,_period);
    // Lihao: lift if
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
        tmp_numberOfRecords = numberOfRecords;
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
        if (tmp_numberOfRecords+1 >= MAX_RECORDS) {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
          systemState = IDLE;
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
        }
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
  	periodCounter = 0;
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
  	tickCounter = 0;
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
  	numberOfRecords = 0;
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
  	startTime = _startTime;
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
  	period = _period;
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
  	systemState = LOGGING;
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();

__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
        msgBuffer[0] = rspStatus;
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
  // Lihao: lift if
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
  tmp_systemState = systemState;
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
        if(tmp_systemState==SLEEP) {
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__VERIFIER_atomic_TRANS_task_communicate2_leave_thread();
          return ;
        }
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_begin();
TRANS_atomic_assume_task_communicate2();
        send_response(msgBuffer,1);
TRANS_atomic_assume_task_communicate2();
__CPROVER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
        break;
      }
      default: 
__VERIFIER_atomic_TRANS_atomic_assume_task_communicate2();
        break;
    }
__VERIFIER_atomic_TRANS_task_communicate2_leave_thread();
  }
__VERIFIER_atomic_TRANS_task_communicate2_leave_thread();
}


void initialize(void) {
  systemState = SLEEP;
  periodCounter = 0;
  tickCounter = 0;
  startTime = 0;
  numberOfRecords = 0;
}

void run(void)
{
  // Lihao
#if 0
  pthread_t t1, t2, t3, t4;
  pthread_create(&t1, NULL, task_ext_power, NULL);
  pthread_create(&t2, NULL, task_communicate, NULL);
  pthread_create(&t3, NULL, task_communicate, NULL);
  pthread_create(&t4, NULL, task_measure, NULL);
#endif

  // while(1) {
    __CPROVER_ASYNC_1: 
    task_ext_power();

    __CPROVER_ASYNC_1: 
    task_communicate();

    __CPROVER_ASYNC_1: 
    task_communicate2();

    __CPROVER_ASYNC_1: 
    task_measure();
    //  }
}

void main() {
    initialize();
    run();
}
