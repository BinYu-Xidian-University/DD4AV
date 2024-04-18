#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

volatile int x=1,TRIGGER=99,flag=0;
void task_main() {
    int y = x;
    for (int i=0; i<100; i++) {
        if (i == TRIGGER){
            y = x + i;
        }
    }
    x = 2;
    if(flag == 2){
        x = 3;
    }
    x = 4;
}

void isr1() {
    int y = x;
    for (int i=0; i<100; i++) {
        if (i == TRIGGER){
            y = x + i;
        }
    }
    x = 2;
    if(flag == 2){
        x = 3;
    }
    x = 4;
}

void isr2() {
    int y = x;
    for (int i=0; i<100; i++) {
        if (i == TRIGGER){
            y = x + i;
        }
    }
    x = 2;
    if(flag == 2){
        x = 3;
    }
    x = 4;
}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2, id3;
    pthread_create(&id1, NULL, (void*)task_main, NULL);
    pthread_create(&id2, NULL, (void*)isr1, NULL);
    pthread_create(&id3, NULL, (void*)isr2, NULL);
    pthread_join(id3, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}