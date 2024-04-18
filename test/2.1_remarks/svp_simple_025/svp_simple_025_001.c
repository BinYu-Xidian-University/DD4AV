#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

volatile int svp_simple_025_001_global_var;
volatile int *svp_simple_025_001_global_array[100];
volatile int *ptr;

void svp_simple_025_001_main() {
  svp_simple_025_001_global_var = 1;
  ptr = &svp_simple_025_001_global_var;
  *ptr = *ptr + 1;
}

void svp_simple_025_001_isr_1() {
  svp_simple_025_001_global_var = 0;
}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2;
    pthread_create(&id1, NULL, (void*)svp_simple_025_001_main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_025_001_isr_1, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}

//  *ptr_var = *ptr_var + 1;
//  svp_simple_025_001_global_var = 0;
//  *ptr_var = *ptr_var + 1;

