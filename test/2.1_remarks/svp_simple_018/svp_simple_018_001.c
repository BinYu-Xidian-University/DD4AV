#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

volatile float svp_simple_018_001_para1;
volatile float svp_simple_018_001_para2;

void svp_simple_018_001_main() {

  float svp_simple_018_001_perimete = 0;
  float svp_simple_018_001_area = 0;

  float perimete = 0.0;
  float tmp1 = 2 * svp_simple_018_001_para1;
  float tmp2 = tmp1 * svp_simple_018_001_para2;
  svp_simple_018_001_perimete = tmp2;

  float area = 0.0;
  float tmp3 = svp_simple_018_001_para1;
  float tmp4 = tmp3 * svp_simple_018_001_para2;
  float tmp5 = tmp4 * svp_simple_018_001_para2;
  svp_simple_018_001_area = tmp5;
}

void svp_simple_018_001_isr_1() {
  svp_simple_018_001_para1 = 2.0;
}

void svp_simple_018_001_isr_2() {
  svp_simple_018_001_para2 = 1.0;
}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2, id3;
    pthread_create(&id1, NULL, (void*)svp_simple_018_001_main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_018_001_isr_1, NULL);
    pthread_create(&id3, NULL, (void*)svp_simple_018_001_isr_2, NULL);
    pthread_join(id3, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}

// TP
// svp_simple_018_001_para1: (R17,W29,R22)
// svp_simple_018_001_para2: (R18,W33,R23)
// svp_simple_018_001_para2: (R23,W33,R24)

// FP
// svp_simple_018_001_para2: (R18,W33,R24)
