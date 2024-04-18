#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

char* ptr;
int x = 0, y = 3;

void task_main() {
    int t;
    if(x == 0){ //R(x)
       y = 2;   //W(y)
    }
    if(y == 5){  //R(y)
        assert(0);
    }
}

void isr1() {
    free(ptr);
    if(x == 1){  //R(x)
        y = 5;   //W(y)
    }
    ptr=NULL;
}

void isr2() {
    free(ptr);
    if(y == 2){ //R(y)
       x = 1;   //W(x)
    }
    ptr=NULL;
}

int main(int argc, char **argv) {
    printf("start\n");

    ptr = (char*)malloc(7);
	ptr[0]='a';

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
