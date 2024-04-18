#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

void svp_simple_018_001_main();

float svp_simple_018_001_func1();

float svp_simple_018_001_func2();

void svp_simple_018_001_isr_func1();

volatile float svp_simple_018_001_para1;
volatile float svp_simple_018_001_para2;

void svp_simple_018_001_main() {
//  init();
  float svp_simple_018_001_perimete = 0;
  float svp_simple_018_001_area = 0;
  svp_simple_018_001_perimete = svp_simple_018_001_func1();
  svp_simple_018_001_area = svp_simple_018_001_func2();
}

float svp_simple_018_001_func1() {
  float perimete = 0.0;
  perimete = 2 * svp_simple_018_001_para1 *
            svp_simple_018_001_para2;
  return perimete;
}

float svp_simple_018_001_func2() {
  float area = 0.0;
  area = svp_simple_018_001_para1 *
         svp_simple_018_001_para2 *
         svp_simple_018_001_para2;
  return area;
}

void svp_simple_018_001_isr_func1() {
  svp_simple_018_001_para2 = 1.0;
}

void svp_simple_018_001_isr_1() {
//  idlerun();
  svp_simple_018_001_para1 = 2.0;
}

void svp_simple_018_001_isr_2() {
//  idlerun();
  svp_simple_018_001_isr_func1();
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

//  perimete = 2 * svp_simple_018_001_para1 *   R
//  svp_simple_018_001_para1 = 2.0;             W
//  area = svp_simple_018_001_para1 *           R

//             func1():svp_simple_018_001_para2;        R
//  svp_simple_018_001_para2 = 1.0;             W
//                      svp_simple_018_001_para2 *           R

//             func2():svp_simple_018_001_para2;        R
//  svp_simple_018_001_para2 = 1.0;             W
//         svp_simple_018_001_para2;