#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

volatile int svp_simple_028_001_isr_1_flag;
volatile int svp_simple_028_001_gloable_var;

int svp_simple_028_001__main() {

  svp_simple_028_001_gloable_var = 15;
  svp_simple_028_001_isr_1_flag = 20;

  if (svp_simple_028_001_gloable_var > 12) {  
    svp_simple_028_001_gloable_var = 0;     
  }
  return 0;
}

void svp_simple_028_001_isr_1() {
  int tmp = svp_simple_028_001_gloable_var + 1;
  svp_simple_028_001_gloable_var=tmp;
  svp_simple_028_001_isr_1_flag = 0;
}

void svp_simple_028_001_isr_2() {
  if (svp_simple_028_001_isr_1_flag) {
    int tmp = svp_simple_028_001_gloable_var + 1;
    svp_simple_028_001_gloable_var=tmp;
  }
}

void svp_simple_028_001_isr_3() {
  int tmp = svp_simple_028_001_gloable_var + 1;
  svp_simple_028_001_gloable_var=tmp;
}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2,id3,id4;
    pthread_create(&id1, NULL, (void*)svp_simple_028_001__main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_028_001_isr_1, NULL);
    pthread_create(&id3, NULL, (void*)svp_simple_028_001_isr_2, NULL);
    pthread_create(&id4, NULL, (void*)svp_simple_028_001_isr_3, NULL);
    pthread_join(id4,NULL);
    pthread_join(id3,NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}

// TP
// svp_simple_028_001_gloable_var (R13,W24,W16)
// svp_simple_028_001_gloable_var (R13,W31,W16)
// svp_simple_028_001_gloable_var (R13,W37,W16)
// svp_simple_028_001_gloable_var (R16,W24,W17)
// svp_simple_028_001_gloable_var (R16,W31,W17)
// svp_simple_028_001_gloable_var (R16,W37,W17)
// svp_simple_028_001_gloable_var (R23,W31,W24)
// svp_simple_028_001_gloable_var (R23,W37,W24)
// svp_simple_028_001_gloable_var (R30,W37,W31)

// FP
