#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

volatile int svp_simple_016_001_global_var1;
//volatile int reader1;

void svp_simple_016_001_main() {
//  init();
  int reader1;
  svp_simple_016_001_global_var1 = 0x01;
  reader1 = svp_simple_016_001_global_var1 +
            svp_simple_016_001_global_var1 +
            svp_simple_016_001_global_var1;
  if(reader1 == 0x1B || reader1 == 0x13 || reader1 == 0x0B) {
    assert(0);
  }

}

void svp_simple_016_001_isr_1() {
//  idlerun();
  svp_simple_016_001_global_var1 = 0x09;
}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2;
    pthread_create(&id1, NULL, (void*)svp_simple_016_001_main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_016_001_isr_1, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}

//  svp_simple_016_001_global_var1 = 0x01;  W
//  svp_simple_016_001_global_var1 = 0x09;  W
//  svp_simple_016_001_global_var1 +        R

//   reader1 = svp_simple_016_001_global_var1 +     R
//  svp_simple_016_001_global_var1 = 0x09;          W
//            svp_simple_016_001_global_var1 +      R

//            svp_simple_016_001_global_var1 +  R
//  svp_simple_016_001_global_var1 = 0x09;      W
//            svp_simple_016_001_global_var1;   R
