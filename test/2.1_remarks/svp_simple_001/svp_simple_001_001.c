#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

volatile int svp_simple_001_001_global_var;
volatile int svp_simple_001_001_global_array[100];
volatile int svp_simple_001_001_global_flag = 0;
#define MAX_LENGTH 10
int TRIGGER = 9;

void svp_simple_001_001_main() {

    for (int i = 0; i < MAX_LENGTH; i++){
        svp_simple_001_001_global_array[i] = 1;
    }
    for (int i = 0; i < MAX_LENGTH; i++) {
        if (i == TRIGGER){
            svp_simple_001_001_global_array[i] = 2;
        }
    }
}

void svp_simple_001_001_isr_1() {

    svp_simple_001_001_global_flag = 1;
    svp_simple_001_001_global_var = 0;
    svp_simple_001_001_global_var = 1;

}

void svp_simple_001_001_isr_2() {
    int reader1, reader3;
    if (svp_simple_001_001_global_flag == 1){
        reader1 = svp_simple_001_001_global_array[TRIGGER];
    }
    else {
        reader1 = svp_simple_001_001_global_array[0];
    }
    reader3 = svp_simple_001_001_global_array[1];
    int reader2;
    reader2 = svp_simple_001_001_global_var;
}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2, id3;
    pthread_create(&id1, NULL, (void*)svp_simple_001_001_main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_001_001_isr_1, NULL);
    pthread_create(&id3, NULL, (void*)svp_simple_001_001_isr_2, NULL);
    pthread_join(id3, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}


// TP  
// svp_simple_001_001_global_array[TRIGGER]:(W17,R37,W21)
// svp_simple_001_001_global_var:(W29,R44,W30)

// FP
// not a shareValue: (W17,R40,W21)  arr[TRIGGER]/arr[0]/arr[TRIGGER]
// not a shareValue: (W17,R42,W21)  arr[TRIGGER]/arr[1]/arr[TRIGGER]
