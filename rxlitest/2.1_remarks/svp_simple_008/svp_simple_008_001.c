#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

void svp_simple_008_001_func_1();

#define MAX_LENGTH 4
#define TRIGGER 3

volatile int svp_simple_008_001_global_var;

volatile int svp_simple_008_001_global_array[10];

void svp_simple_008_001_main() {
//  init();
  int p = 1;
  int q = 2;

  svp_simple_008_001_global_array[p + q] = 0x09;

  svp_simple_008_001_global_array[3] = 0x01;

  svp_simple_008_001_func_1();
}

void svp_simple_008_001_func_1() {
  int reader1, reader2;
  int i = 1;
  int j = 1;
  int p = 1;
  int q = 3;
  reader1 = svp_simple_008_001_global_array[i * 2 + j * 1];
  if(reader1 == 0x05){
    assert(0);
  }
  reader2 = svp_simple_008_001_global_array[p + q];
}

void svp_simple_008_001_isr_1() {
  for (int k = 0; k < 4; k++) svp_simple_008_001_global_array[k] = 0x05;
}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2;
    pthread_create(&id1, NULL, (void*)svp_simple_008_001_main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_008_001_isr_1, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}

//  svp_simple_008_001_global_array[3] = 0x01; W
//  svp_simple_008_001_global_array[k] = 0x05;     W
//  reader1 = svp_simple_008_001_global_array[i * 2 + j * 1];R
