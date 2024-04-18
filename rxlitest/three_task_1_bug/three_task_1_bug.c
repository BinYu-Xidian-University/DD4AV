#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

int x = 0, y = 0;

void task_main() {
    //enable(isr_a);
    x = -1;
    printf("task_main\n");
    y = 2;
}

void isr1() {
    x = 1;
    printf("isr1\n");
    y = x + y;
//    enable(isr_b);
//    assert(y < 5 || y == 6);
    assert(y != 5);
}

void isr2() {
    if (x == 1){
        printf("isr2\n");
        y = 5;
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

//原子性违背---断言错误
//#<14> #<24> #<16>  WWR
