#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

int x=0;
int y=3;

void *t1(void *arg)
{
    if(x==0){
        printf("t1.2\n");
        y=2;
        printf("t1.3\n");
        x=1;
        x=3;
    }
}
void *t2(void *arg)
{
    if(y==3){
        printf("t2.2\n");
        y=15;
        printf("t2.3\n");
        x=2;
        x=3;
        y=5;
        x=4;
    }
    if(x==1){
        printf("t2.5\n");
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