#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

#define MAX_LENGTH 50
#define TRIGGER49

volatile int svp_simple_006_001_global_var1;
volatile int svp_simple_006_001_global_var2;
volatile unsigned char flag = 0x55;
void svp_simple_006_001_main() {
  int reader1, reader2;
  
  for (int i = 0; i < MAX_LENGTH; i++) {
      for (int j = 0; j < MAX_LENGTH; j++) {
        if (i == j) {
          if (i == 0) {
            reader1 = svp_simple_006_001_global_var1;
          }
          else if (i == 3) {
            reader2 = svp_simple_006_001_global_var1;
          }
          else if (i == MAX_LENGTH + 1) {
            reader2 = svp_simple_006_001_global_var1;
          }
        }
      }
  }

  for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (((i + j) == 6) && (i < j)) {
            svp_simple_006_001_global_var2 = 0x02;
        }
      }
  }
}

void svp_simple_006_001_isr_1() {
  int reader2;
  svp_simple_006_001_global_var1 = 0;
  reader2 = svp_simple_006_001_global_var2;
}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2;
    pthread_create(&id1, NULL, (void*)svp_simple_006_001_main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_006_001_isr_1, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}

// TP
// svp_simple_006_001_global_var1:(R21,W44,R24)

// FP
// svp_simple_006_001_global_var1:(R24,W44,R27)   cannot cover this path
// svp_simple_006_001_global_var2:(W21,R45,W21)   

