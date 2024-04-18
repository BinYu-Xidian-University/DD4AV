#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

volatile int svp_simple_016_001_global_var1;

void svp_simple_016_001_main() {
    int reader1;
    svp_simple_016_001_global_var1 = 0x01;
    int tmp1 = svp_simple_016_001_global_var1;
    int tmp2 = svp_simple_016_001_global_var1 + tmp1;
    reader1 = svp_simple_016_001_global_var1 + tmp2;

}

void svp_simple_016_001_isr_1() {
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

// TP
// svp_simple_016_001_global_var1: (R12,W21,R13)
// svp_simple_016_001_global_var1: (R13,W21,R14)
// svp_simple_016_001_global_var1: (R14,W21,R15)

