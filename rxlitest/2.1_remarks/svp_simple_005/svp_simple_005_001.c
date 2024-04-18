#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

#define MAX_LENGTH 4
#define TRIGGER 3
#define TRIGGER1 1

volatile int svp_simple_005_001_global_condition = 0;

volatile int svp_simple_005_001_global_var;

void svp_simple_005_001_main() {
//  init();
  for (int i = 0; i < MAX_LENGTH; i++) {
    for (int j = 0; j < MAX_LENGTH; j++) {
      if ((i == TRIGGER) && (j == TRIGGER1))
        svp_simple_005_001_global_var = 0x01;
    }
  }

  if (svp_simple_005_001_global_condition == 1)
    svp_simple_005_001_global_var = 0x09;

  svp_simple_005_001_global_var = 0x05;
}

void svp_simple_005_001_isr_1() {
//  idlerun();
  int reader;
  reader = svp_simple_005_001_global_var;
  if(reader == 0x01){
    assert(0);
  }
}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2;
    pthread_create(&id1, NULL, (void*)svp_simple_005_001_main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_005_001_isr_1, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}
//  svp_simple_005_001_global_var = 0x01; W
//  reader = svp_simple_005_001_global_var; R
//  svp_simple_005_001_global_var = 0x05; W
