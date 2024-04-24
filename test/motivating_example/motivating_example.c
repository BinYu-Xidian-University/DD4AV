#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

volatile int x=0,flag=0;
void task_main() {
    flag = 1;
    if(x == 0) {
        flag = 2;
    }
}

void isr1() {
    if (flag == 2) {
        flag = 4;
    }
}

void isr2() {
    if (flag == 88) {
        x = 11;
        flag = 6;
    }
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