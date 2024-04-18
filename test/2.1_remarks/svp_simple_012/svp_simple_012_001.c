#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

int svp_simple_012_001_global_var;

void svp_simple_012_001_main() {

  int *p;
  p = &svp_simple_012_001_global_var;
  svp_simple_012_001_global_var = 0x01;
  *p = 0x02;
}

void svp_simple_012_001_isr_1() {
  int reader1;
  reader1 = svp_simple_012_001_global_var;
}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2;
    pthread_create(&id1, NULL, (void*)svp_simple_012_001_main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_012_001_isr_1, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}

//  svp_simple_012_001_global_var = 0x01;   W
//  reader1 = svp_simple_012_001_global_var; R
//  *p = 0x02;   W
