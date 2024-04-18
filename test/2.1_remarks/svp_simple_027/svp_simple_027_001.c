#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

volatile int svp_simple_027_001_gloable_var;

int svp_simple_027_001_main() {
  // svp_simple_027_001_gloable_var = RAND();
  svp_simple_027_001_gloable_var = 411;
  if (svp_simple_027_001_gloable_var > 12) {  
    svp_simple_027_001_gloable_var = 0;       
  }
  return 0;
}

void svp_simple_027_001_isr_1() {
  int tmp = svp_simple_027_001_gloable_var + 1;
  svp_simple_027_001_gloable_var = tmp;
}

void svp_simple_027_001_isr_2() {
  int tmp = svp_simple_027_001_gloable_var + 2;
  svp_simple_027_001_gloable_var = tmp;
}

void svp_simple_027_001_isr_3() {
  int tmp = svp_simple_027_001_gloable_var + 3;
  svp_simple_027_001_gloable_var = tmp;
}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2,id3,id4;
    pthread_create(&id1, NULL, (void*)svp_simple_027_001_main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_027_001_isr_1, NULL);
    pthread_create(&id3, NULL, (void*)svp_simple_027_001_isr_2, NULL);
    pthread_create(&id4, NULL, (void*)svp_simple_027_001_isr_3, NULL);
    pthread_join(id4,NULL);
    pthread_join(id3,NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}

// TP
// svp_simple_027_001_gloable_var: (R12,W21,W13)
// svp_simple_027_001_gloable_var: (R12,W26,W13)
// svp_simple_027_001_gloable_var: (R12,W31,W13)
// svp_simple_027_001_gloable_var: (R13,W21,W14)
// svp_simple_027_001_gloable_var: (R13,W26,W14)
// svp_simple_027_001_gloable_var: (R13,W31,W14)
// svp_simple_027_001_gloable_var: (R20,W26,W21)
// svp_simple_027_001_gloable_var: (R20,W31,W21)
// svp_simple_027_001_gloable_var: (R25,W31,W26)

// FP

