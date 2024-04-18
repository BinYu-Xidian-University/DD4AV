#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

#define MAX_LENGTH 4
#define TRIGGER 3

volatile int svp_simple_017_001_global_var;
volatile int svp_simple_017_001_local_array[MAX_LENGTH];

void svp_simple_017_001_main() {
//  init();
  int i = 0;

  for (svp_simple_017_001_global_var = 0; svp_simple_017_001_global_var < MAX_LENGTH;
       svp_simple_017_001_global_var++)
  {
    svp_simple_017_001_local_array[svp_simple_017_001_global_var] = i++;
  }
  if(i < 4) {
    assert(0);
  }
}

void svp_simple_017_001_isr_1() {
//  idlerun();
  // 如果所有RWW都被视为原子性违背，而不管是否真的对程序造成错误：
//  if(svp_simple_017_001_global_var == TRIGGER) {
//    assert(0);
//  }

  svp_simple_017_001_global_var = TRIGGER;

  svp_simple_017_001_local_array[TRIGGER] = 0;
}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2;
    pthread_create(&id1, NULL, (void*)svp_simple_017_001_main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_017_001_isr_1, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}

//  for (svp_simple_017_001_global_var = 0; W
//  svp_simple_017_001_global_var = TRIGGER;  W
//  for (...svp_simple_017_001_global_var < MAX_LENGTH; R

//  for (...svp_simple_017_001_global_var < MAX_LENGTH;  R
//  svp_simple_017_001_global_var = TRIGGER;  W
//    svp_simple_017_001_local_array[svp_simple_017_001_global_var] = i++;  R

//    svp_simple_017_001_local_array[svp_simple_017_001_global_var] = i++;R
//  svp_simple_017_001_global_var = TRIGGER;  W
//       svp_simple_017_001_global_var++)  W

//       svp_simple_017_001_global_var++)  W
//  svp_simple_017_001_global_var = TRIGGER;  W
//  for (svp_simple_017_001_global_var = 0; svp_simple_017_001_global_var < MAX_LENGTH;  R
