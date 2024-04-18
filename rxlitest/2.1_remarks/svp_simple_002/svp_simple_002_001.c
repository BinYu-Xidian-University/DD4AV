#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>


#define MAX_LENGTH 4
#define TRIGGER 3

volatile int svp_simple_002_001_global_array[MAX_LENGTH];
volatile int casee2_global_var;

void svp_simple_002_001_main() {

      int a = 0;
//    init();
//    idlerun();
}

void svp_simple_002_001_isr_1() {
    int mininum, maxnum;
    for (int i = 0; i < MAX_LENGTH; i++) {
        if (i == TRIGGER) svp_simple_002_001_global_array[TRIGGER] = 1;
        if (i == MAX_LENGTH + 1) //到不了
            svp_simple_002_001_global_array[TRIGGER] = 1;
    }
    mininum = svp_simple_002_001_global_array[TRIGGER] - 10;

    maxnum = svp_simple_002_001_global_array[0] + 10;

    if(mininum > 0) {
        // assert(0);
    }
}

void svp_simple_002_001_isr_2() {
    svp_simple_002_001_global_array[TRIGGER] = 999;

}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2, id3;
    pthread_create(&id1, NULL, (void*)svp_simple_002_001_main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_002_001_isr_1, NULL);
    pthread_create(&id3, NULL, (void*)svp_simple_002_001_isr_2, NULL);
    pthread_join(id3, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}

//bug点:
//svp_simple_002_001_global_array[TRIGGER] = 1;  W
//svp_simple_002_001_global_array[TRIGGER] = 999; W
//mininum = svp_simple_002_001_global_array[TRIGGER] - 10; R
