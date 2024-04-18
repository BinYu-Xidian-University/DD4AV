#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

#define MAX_LENGTH 10
#define TRIGGER 5

volatile int svp_simple_017_001_global_var;
volatile int svp_simple_017_001_local_array[MAX_LENGTH];

void svp_simple_017_001_main() {
  int i = 0;

  for (svp_simple_017_001_global_var = 0; 
       svp_simple_017_001_global_var < MAX_LENGTH;
       svp_simple_017_001_global_var++)
  {
    svp_simple_017_001_local_array[svp_simple_017_001_global_var] = i++;
  }
}

void svp_simple_017_001_isr_1() {
  svp_simple_017_001_global_var = TRIGGER;
  svp_simple_017_001_local_array[TRIGGER] = 0;
}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2;
    pthread_create(&id1, NULL, (void*)svp_simple_017_001_main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_017_001_isr_1, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}

// TP
// svp_simple_017_001_global_var: (R18,W26,R18)
// svp_simple_017_001_global_var: (R18,W26,R21)
// svp_simple_017_001_global_var: (R21,W26,W19)
// svp_simple_017_001_global_var: (W19,W26,R18)

// FP
// svp_simple_017_001_global_var: (W18,W26,R18)  interrupt only occur in function, not between init and judgement

