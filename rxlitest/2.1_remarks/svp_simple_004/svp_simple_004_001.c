#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

#define MAX_LENGTH 4
#define TRIGGER 3

volatile int svp_simple_004_001_condition1 = 1;
volatile int svp_simple_004_001_condition2 = 1;
volatile int svp_simple_004_001_condition3 = 1;
volatile int svp_simple_004_001_condition4 = 1;
volatile int svp_simple_004_001_condition5 = 1;
volatile int svp_simple_004_001_condition6 = 1;

volatile int svp_simple_004_001_global_var1 = 0x11;
volatile int svp_simple_004_001_global_var2 = 0x22;
volatile int svp_simple_004_001_global_var3 = 0x33;

void svp_simple_004_001_main() {
//  init();
  int reader1, reader2;
  int reader3, reader4;
  int reader5, reader6;
//  disable_isr(2);

  if (svp_simple_004_001_condition1 == 1) {
    reader1 = svp_simple_004_001_global_var1;
    reader5 = svp_simple_004_001_global_var3;
  }

  if (svp_simple_004_001_condition2 == 1) {
    reader2 = svp_simple_004_001_global_var1;
    reader6 = svp_simple_004_001_global_var3;
  }
  if(reader1 != reader2) {
    assert(0);
  }

  if (svp_simple_004_001_condition4 == 1){
      reader3 = svp_simple_004_001_global_var2;
  }

  if (svp_simple_004_001_condition5 == 1){
      reader4 = svp_simple_004_001_global_var2;
  }
}

void svp_simple_004_001_isr_1() {
  svp_simple_004_001_condition6 = 0;

  if (svp_simple_004_001_condition3 == 1)
    svp_simple_004_001_global_var1 = 0xaa;
  else
    svp_simple_004_001_global_var3 = 0xcc;

//  enable_isr(2);
}

void svp_simple_004_001_isr_2() {
  if (svp_simple_004_001_condition6 == 1)
    svp_simple_004_001_global_var2 = 0x22;
}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2, id3;
    pthread_create(&id1, NULL, (void*)svp_simple_004_001_main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_004_001_isr_1, NULL);
    pthread_create(&id3, NULL, (void*)svp_simple_004_001_isr_2, NULL);
    pthread_join(id3, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}
//    reader1 = svp_simple_004_001_global_var1;  R
//    svp_simple_004_001_global_var1 = 0xaa;  W
//    reader2 = svp_simple_004_001_global_var1; R
