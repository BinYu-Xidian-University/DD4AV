#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

volatile int svp_simple_020_001_global_var;

volatile int svp_simple_020_001_global_para;

volatile int svp_simple_020_001_global_flag;

void svp_simple_020_001_main() {
  int reader1, reader2;
  int svp_simple_020_001_local_var1, svp_simple_020_001_local_var2;
//  svp_simple_020_001_local_var1 = rand();
//  svp_simple_020_001_local_var2 = rand();
  svp_simple_020_001_local_var1 = 1;
  svp_simple_020_001_local_var2 = 2;

  if (svp_simple_020_001_local_var1 + svp_simple_020_001_local_var2 > svp_simple_020_001_global_para){
      reader1 = svp_simple_020_001_global_var;
  }
  if (svp_simple_020_001_local_var1 + svp_simple_020_001_local_var2 < svp_simple_020_001_global_para){
      reader2 = svp_simple_020_001_global_var;
  }
}

void svp_simple_020_001_isr_1() {
  svp_simple_020_001_global_var = 0x01;
  svp_simple_020_001_global_flag = 1;
}

void svp_simple_020_001_isr_2() {
  if (svp_simple_020_001_global_flag == 1) {
    svp_simple_020_001_global_para = 11;
    svp_simple_020_001_global_var = 0x05;
  }
}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2, id3;
    pthread_create(&id1, NULL, (void*)svp_simple_020_001_main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_020_001_isr_1, NULL);
    pthread_create(&id3, NULL, (void*)svp_simple_020_001_isr_2, NULL);
    pthread_join(id3, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}

// TP
// svp_simple_020_001_global_var: (R23,W31,R26)
// svp_simple_020_001_global_var: (R23,W38,R26)


