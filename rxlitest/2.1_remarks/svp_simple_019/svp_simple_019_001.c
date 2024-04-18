#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

volatile int svp_simple_019_001_global_condition1 = 1;
volatile int svp_simple_019_001_global_condition2 = 1;
volatile int svp_simple_019_001_global_condition3 = 1;

volatile int svp_simple_019_001_global_para1 = 1;
volatile int svp_simple_019_001_global_para2 = 2;
volatile int svp_simple_019_001_global_para3 = 3;

volatile int svp_simple_019_001_global_var1 = 4;
volatile int svp_simple_019_001_global_var2;

void svp_simple_019_001_main() {
  int reader1, reader2, reader3, reader4, reader5 = 0;
//  init();
//  svp_simple_019_001_global_para1 = rand() % 10;
//  svp_simple_019_001_global_para2 = rand() % 10;
//  svp_simple_019_001_global_para3 = rand() % 10;

  if ((svp_simple_019_001_global_para1 + svp_simple_019_001_global_para3) > svp_simple_019_001_global_para2) {
      reader1 = svp_simple_019_001_global_var2;
  }
  reader2 = svp_simple_019_001_global_var2;
  if ((svp_simple_019_001_global_condition1 == 1) && (svp_simple_019_001_global_condition2 == 1)) {
      reader3 = svp_simple_019_001_global_var1;
  }
//  idlerun();
//  disable_isr(1);
  if ((svp_simple_019_001_global_condition1 == 1) && (svp_simple_019_001_global_condition3 == 1))
  {
//    enable_isr(1);
    reader4 = svp_simple_019_001_global_var1;
  }
//  idlerun();
//  disable_isr(1);
  if ((svp_simple_019_001_global_condition2 == 1) && (svp_simple_019_001_global_condition3 == 0))
  {
//    enable_isr(1);
    reader5 = svp_simple_019_001_global_var1;
  }
  if((reader4 == 1 || reader4 == 4) && reader5 == 1) {
    assert(0);
  }
}

void svp_simple_019_001_isr_1() {
//  idlerun();
  if ((svp_simple_019_001_global_para1 + svp_simple_019_001_global_para3) < svp_simple_019_001_global_para2){
      svp_simple_019_001_global_var2 = 0x55;
  }

  svp_simple_019_001_global_condition3 = 0;

  svp_simple_019_001_global_var1 = 0x01;
}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2;
    pthread_create(&id1, NULL, (void*)svp_simple_019_001_main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_019_001_isr_1, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}

//    reader3 = svp_simple_019_001_global_var1;
//  svp_simple_019_001_global_var1 = 0x01;
//    reader4 = svp_simple_019_001_global_var1;
