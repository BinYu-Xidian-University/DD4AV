#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

#define MAX_LENGTH 4
#define TRIGGER 3

volatile int svp_simple_007_001_global_var=0;

volatile int svp_simple_007_001_global_array[5];

void svp_simple_007_001_main() {
//  init();
  int reader1, reader2;

  svp_simple_007_001_global_array[svp_simple_007_001_global_var] = 0x01;

  reader2 = svp_simple_007_001_global_array[svp_simple_007_001_global_var];

  int i = rand();
  int i = 2;
//  if (i == 2)
    svp_simple_007_001_global_array[i] = 0x02;
  else
    svp_simple_007_001_global_array[i] = 0x09;

  reader1 = svp_simple_007_001_global_array[2];
  if(reader1 == 0x09){
    assert(0);
  }
}

void svp_simple_007_001_isr_1() {
//  idlerun();
  svp_simple_007_001_global_array[2] = 0x09;

  svp_simple_007_001_global_var += 1;
  svp_simple_007_001_global_array[svp_simple_007_001_global_var] = 0x09;
}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2;
    pthread_create(&id1, NULL, (void*)svp_simple_007_001_main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_007_001_isr_1, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}
//    svp_simple_007_001_global_array[i] = 0x02;  W
//  svp_simple_007_001_global_array[2] = 0x09;   W
//  reader1 = svp_simple_007_001_global_array[2];  R
