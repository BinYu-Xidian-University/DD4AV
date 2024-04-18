#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

#define MAX_LENGTH 4
#define TRIGGER 3

volatile int svp_simple_013_001_global_var1;
volatile int svp_simple_013_001_global_var2;

int svp_simple_013_001_global_flag1 = 0;
int svp_simple_013_001_global_flag2 = 1;

void svp_simple_013_001_main() {
//  init();
//  disable_isr(2);
//  disable_isr(3);

  int reader1, reader2;
  int reader3, reader4;

  for (int i = 0; i < MAX_LENGTH; i++) {
      if (i == TRIGGER) {
        reader1 = svp_simple_013_001_global_var1;
      }
  }

  reader2 = svp_simple_013_001_global_var1;
  printf("reader1: %d, reader2: %d\n", reader1, reader2);
  if(reader1 != reader2) {
    assert(0);
  }

  reader3 = svp_simple_013_001_global_var2;

  reader4 = svp_simple_013_001_global_var2;
}

void svp_simple_013_001_isr_1() {
//  idlerun();
//  enable_isr(2);
//  idlerun();
}

void svp_simple_013_001_isr_2() {
//  idlerun();
  svp_simple_013_001_global_flag1 = 1;

  svp_simple_013_001_global_flag2 = 0;
//  enable_isr(3);
//  idlerun();
}

void svp_simple_013_001_isr_3() {
  if (svp_simple_013_001_global_flag1 == 1) {
    svp_simple_013_001_global_var1 = 0x01;
  }
  if (svp_simple_013_001_global_flag2 == 1) {
    svp_simple_013_001_global_var2 = 0x01;
  }
}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2, id3, id4;
    pthread_create(&id1, NULL, (void*)svp_simple_013_001_main, NULL);
//    pthread_create(&id2, NULL, (void*)svp_simple_013_001_isr_1, NULL);
    pthread_create(&id3, NULL, (void*)svp_simple_013_001_isr_2, NULL);
    pthread_create(&id4, NULL, (void*)svp_simple_013_001_isr_3, NULL);
    pthread_join(id4, NULL);
    pthread_join(id3, NULL);
//    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}

//    if (i == TRIGGER) reader1 = svp_simple_013_001_global_var1;
//  if (svp_simple_013_001_global_flag1 == 1) svp_simple_013_001_global_var1 = 0x01;
//  reader2 = svp_simple_013_001_global_var1;
