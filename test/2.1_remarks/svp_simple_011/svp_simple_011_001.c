#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

int svp_simple_011_001_global_var1;
int svp_simple_011_001_global_var2;
int svp_simple_011_001_global_var3;

volatile int *svp_simple_011_001_u;
volatile int *p;
volatile int *q;
volatile int *m;

void svp_simple_011_001_main() {
  p = &svp_simple_011_001_global_var1;
  q = &svp_simple_011_001_global_var1;

  *p = 0x01;
  *q = 0x02;

  svp_simple_011_001_u = &svp_simple_011_001_global_var2;
  *svp_simple_011_001_u = 0x01;
  svp_simple_011_001_u = &svp_simple_011_001_global_var3;
  *svp_simple_011_001_u = 0x02;
}

void svp_simple_011_001_isr_1() {
  int reader1, reader2;
  m = &svp_simple_011_001_global_var1;
  reader1 = *m;
  reader2 = *svp_simple_011_001_u;
}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2;
    pthread_create(&id1, NULL, (void*)svp_simple_011_001_main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_011_001_isr_1, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}

//  *p = 0x01;    W
//  reader1 = *m; R
//  *q = 0x02;    W