#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

int x=0;
int y=3;

void *t1(void *arg)
{
    printf("t1");
    for(int i = 9; i >= 0 ; i--) {
        if(x == i){
            y = 2;
            x = 1;
        }
    }
}
void *t2(void *arg)
{
    printf("t2");
    if(y==3){
        y=15;
        x=2;
    }
    if(x==1){
        y=0;
    }
}

int main(int argc, char **argv) {
    printf("start\n");
    pthread_t id1, id2;
    pthread_create(&id1, NULL, t1, NULL);
    pthread_create(&id2, NULL, t2, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}