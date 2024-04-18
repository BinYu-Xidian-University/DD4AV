#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

volatile int *svp_simple_009_001_p;
volatile int *svp_simple_009_001_q;

volatile int *svp_simple_009_001_m;

void svp_simple_009_001_main() {

  int svp_simple_009_001_local_var1 = 0x01;
  int svp_simple_009_001_local_var2 = 0x09;

  svp_simple_009_001_p = &svp_simple_009_001_local_var1;
  svp_simple_009_001_q = &svp_simple_009_001_local_var1;

  *svp_simple_009_001_p = 0x02;
  *svp_simple_009_001_q = 0x03;

  svp_simple_009_001_m = &svp_simple_009_001_local_var2;

  *svp_simple_009_001_m = 0x06;
  *svp_simple_009_001_m = 0x06;
}

void svp_simple_009_001_isr_1() {
  int reader1, reader2;

  reader1 = *svp_simple_009_001_p;

  int svp_simple_009_001_local_var3 = 0x08;
  svp_simple_009_001_m = &svp_simple_009_001_local_var3;
  reader2 = *svp_simple_009_001_m;
}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2;
    pthread_create(&id1, NULL, (void*)svp_simple_009_001_main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_009_001_isr_1, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}

//  *svp_simple_009_001_p = 0x02;    W
//  reader1 = *svp_simple_009_001_p; R
//  *svp_simple_009_001_q = 0x03;    W
