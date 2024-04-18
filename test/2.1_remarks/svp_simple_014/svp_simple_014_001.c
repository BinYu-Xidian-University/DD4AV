#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

#define MAX_LENGTH 100
#define TRIGGER 99

volatile int svp_simple_014_001_global_var1 = 0x01;
volatile int svp_simple_014_001_global_var2 = 0x02;

int svp_simple_014_001_global_flag1 = 0;
int svp_simple_014_001_global_flag2 = 1;

void svp_simple_014_001_main() {
//  init();
//  idlerun();
}

void svp_simple_014_001_isr_1() {
  int reader1, reader2;
  int reader3, reader4;

  for (int i = 0; i < MAX_LENGTH; i++){
    if (i == TRIGGER){
        reader1 = svp_simple_014_001_global_var1;
    }
  }
  reader2 = svp_simple_014_001_global_var1;

  reader3 = svp_simple_014_001_global_var2;

  reader4 = svp_simple_014_001_global_var2;
}

void svp_simple_014_001_isr_2() {
  svp_simple_014_001_global_flag1 = 1;
  svp_simple_014_001_global_flag2 = 0;
}

void svp_simple_014_001_isr_3() {
  if (svp_simple_014_001_global_flag1 == 1) svp_simple_014_001_global_var1 = 0x09;
  if (svp_simple_014_001_global_flag2 == 1) svp_simple_014_001_global_var2 = 0x09;
}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2, id3, id4;
//    pthread_create(&id1, NULL, (void*)svp_simple_014_001_main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_014_001_isr_1, NULL);
    pthread_create(&id3, NULL, (void*)svp_simple_014_001_isr_2, NULL);
    pthread_create(&id4, NULL, (void*)svp_simple_014_001_isr_3, NULL);
    pthread_join(id4, NULL);
    pthread_join(id3, NULL);
    pthread_join(id2, NULL);
//    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}

// TP
// svp_simple_014_001_global_var1: (R28,W44,R31)
// svp_simple_014_001_global_var2: (R33,W45,R35)

// FP
