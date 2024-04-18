#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>


#define MAX_LENGTH 500
#define TRIGGER 499

volatile int svp_simple_003_001_global_var1;
volatile int svp_simple_003_001_global_var2;

volatile int svp_simple_003_001_global_flag = 1;
volatile int svp_simple_003_001_global_flag1 = 0;

void svp_simple_003_001_main() {
  int reader1, reader2;
  int reader3, reader4;
  for (int i = 0; i < MAX_LENGTH; i++) {
    if (i == TRIGGER) {
      reader3 = svp_simple_003_001_global_var2;
    }
  }
  for (int j = MAX_LENGTH; j > 0; j--) {
    if (j == TRIGGER) {
      reader4 = svp_simple_003_001_global_var2;
    }
  }
  for (int i = 0; i < MAX_LENGTH; i++) {
    if (i == TRIGGER) {
      reader1 = svp_simple_003_001_global_var1;
    }
  }
  for (int j = MAX_LENGTH; j > 0; j--) {
    if (j == TRIGGER) {
      reader2 = svp_simple_003_001_global_var1;
    }
  }
}

void svp_simple_003_001_isr_1() {
  svp_simple_003_001_global_var2 = 999;
  if (svp_simple_003_001_global_flag == 1) {
    svp_simple_003_001_global_var1 = 999;
  } else if (svp_simple_003_001_global_flag1 == 2) {
    svp_simple_003_001_global_var1 = 888;
  }
}

void svp_simple_003_001_isr_2() {
  svp_simple_003_001_global_flag = 1;
}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2, id3;
    pthread_create(&id1, NULL, (void*)svp_simple_003_001_main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_003_001_isr_1, NULL);
    pthread_create(&id3, NULL, (void*)svp_simple_003_001_isr_2, NULL);
    pthread_join(id3, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}

// TP
// svp_simple_003_001_global_var1:(R33, W46, R38)
// svp_simple_003_001_global_var2:(R23, W44, R28)


// FP
// svp_simple_003_001_global_var1: (R33, W48, R38)  cannot cover this path
