#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

volatile int svp_simple_015_001_global_var1;
volatile int svp_simple_015_001_global_var2;

void svp_simple_015_001_main() {

//  int x = rand();
//  int y = rand();
//  int z;
//  int p = rand();
  int x = 4;
  int y = 2;
  int z;
  int p = 1;

  if ((svp_simple_015_001_global_var1 < y) &&
      (svp_simple_015_001_global_var1 > x)) {
      z = x + y;
  }

  p == 1 ? svp_simple_015_001_global_var2 : svp_simple_015_001_global_var2;
}

void svp_simple_015_001_isr_1() {
  svp_simple_015_001_global_var1 = 5;
  svp_simple_015_001_global_var2 = 5;
}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2;
    pthread_create(&id1, NULL, (void*)svp_simple_015_001_main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_015_001_isr_1, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}

// TP
// svp_simple_015_001_global_var1: (R22,W31,R23)

// FP
// svp_simple_015_001_global_var2: (R27,W32,R27)


