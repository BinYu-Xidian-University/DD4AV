#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

volatile unsigned8 svp_simple_029_001_tm_blocks[4096];
volatile unsigned8 svp_simple_029_001_average_adjust_flag;
volatile unsigned8 svp_simple_029_001_average_adjust_count;
volatile unsigned8 (*svp_simple_029_001_ptr_GetTmData)(unsigned32);

void svp_simple_029_001_main() {
  unsigned8 svp_simple_029_001_local_status = 1;

  for (int i = 0; i < 4096; i++) {
//    svp_simple_029_001_tm_blocks[i] = rand();
     svp_simple_029_001_tm_blocks[i] = 0x01;
  }
  svp_simple_029_001_average_adjust_flag = 0xFF;

  svp_simple_029_001_ptr_SetTmData = svp_simple_029_001_SetTmData;
  svp_simple_029_001_ptr_GetTmData = svp_simple_029_001_GetTmData;
  svp_simple_029_001_ptr_SetSelfCtrlFlag = svp_simple_029_001_SetSelfCtrlFlag;
  
  if (svp_simple_029_001_local_status == 1) {
      unsigned8 tmp1;
      unsigned8 tmp2;
      unsigned8 ctrl_sts;

      if(tmp1 == 0) {
        tmp1 = 1;
      }

      tmp1 <<= 0;
      tmp2 = 1;
      tmp2 <<= ~tmp2;

      ctrl_sts = svp_simple_029_001_tm_blocks[36];
      ctrl_sts -= svp_simple_029_001_tm_blocks[37];
      ctrl_sts |= tmp1;

      svp_simple_029_001_tm_blocks[36] = ctrl_sts;
  }
}

void svp_simple_029_001_isr_1() {
  if (svp_simple_029_001_average_adjust_flag == 0xFF) {
    unsigned8 tmp;
    tmp = svp_simple_029_001_average_adjust_count+1;
    svp_simple_029_001_average_adjust_count = tmp;
    svp_simple_029_001_tm_blocks[36] = svp_simple_029_001_average_adjust_count;
  } else {
    svp_simple_029_001_average_adjust_count = 0;
    svp_simple_029_001_tm_blocks[36] = svp_simple_029_001_average_adjust_count;
  }
}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2;
    pthread_create(&id1, NULL, (void*)svp_simple_029_001_main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_029_001_isr_1, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}

// bug点：
// 1.svp_simple_029_001_tm_blocks[36] <R, #80>, <W, #83>, <W, #83>

// 误报点：
//1.svp_simple_029_001_tm_blocks[36] <R, #80>, <W, #83>, <R, #80>
