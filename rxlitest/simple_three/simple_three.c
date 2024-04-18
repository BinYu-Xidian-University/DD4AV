#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

int y,z=0;

void *mmain(void *args)
{
    //disable_isr(2)
    int p,m = 1,n = 1;
    if(m + n > y)
        p = m;
    if(m + n < y)
        p = n;
}

void *isr_1(void *args)
{
    y = 0;
    z = 1;
    //enable_isr(2);
}

void *isr_2(void *args)
{
     if(z > 0){
        y = 11;
        z = 0;
     }
}


int main(int argc, char **argv) {
    printf("start\n");
    pthread_t id1, id2, id3;
    pthread_create(&id1, NULL, mmain, NULL);
    pthread_create(&id2, NULL, isr_1, NULL);
    pthread_create(&id3, NULL, isr_2, NULL);
    pthread_join(id3, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}