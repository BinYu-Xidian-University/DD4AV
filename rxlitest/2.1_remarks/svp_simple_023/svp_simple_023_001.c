#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

volatile int svp_simple_023_001_global_var;
void svp_simple_023_001_func_1(int x);
void svp_simple_023_001_init();

void svp_simple_023_001_main() {
  svp_simple_023_001_init();
  svp_simple_023_001_func_1(svp_simple_023_001_global_var);  
}
void svp_simple_023_001_init() {
//  svp_simple_023_001_global_var = rand();
  svp_simple_023_001_global_var = 3;

//  init();
}

void svp_simple_023_001_func_1(int var) {
  if (var > 0 && var < 12) {
    svp_simple_023_001_global_var = svp_simple_023_001_global_var + 1;
    if(svp_simple_023_001_global_var == 1) {
        assert(0);
    }
  }
}
void svp_simple_023_001_isr_1() {
  svp_simple_023_001_global_var = 0; 
}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2;
    pthread_create(&id1, NULL, (void*)svp_simple_023_001_main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_023_001_isr_1, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}

//  svp_simple_023_001_func_1(svp_simple_023_001_global_var);  R
//  svp_simple_023_001_global_var = 0; W
//  svp_simple_023_001_global_var = svp_simple_023_001_global_var + 1;  R+W?

//  svp_simple_023_001_global_var = svp_simple_023_001_global_var + 1;  R
//  svp_simple_023_001_global_var = 0; W
//  svp_simple_023_001_global_var = svp_simple_023_001_global_var + 1;  W
