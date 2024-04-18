#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

volatile int svp_simple_022_001_global_var1;
volatile int svp_simple_022_001_global_var2;
volatile int svp_simple_022_001_global_var3;
volatile int else_flag = 0;
volatile int svp_simple_022_001_global_array[4];
void svp_simple_022_001_func_1();
void svp_simple_022_001_func_2();
void svp_simple_022_001_func_3();
void svp_simple_022_001_func_4();
void svp_simple_022_001_init();

void svp_simple_022_001_main() {
  svp_simple_022_001_init();

  svp_simple_022_001_global_var1 = 0;  
  svp_simple_022_001_func_1();
  int i;
  for (i = 0; i < 4; i++) {
    svp_simple_022_001_global_array[i] = 0;
  }
  svp_simple_022_001_func_2();
  svp_simple_022_001_global_var3 = svp_simple_022_001_global_var1;
  if(svp_simple_022_001_global_var3 == 18 && else_flag == 1) {
//    printf("error");
    assert(0);
  }
}

void svp_simple_022_001_init() {
//  svp_simple_022_001_global_var1 = rand();
//  svp_simple_022_001_global_var2 = rand();
//  svp_simple_022_001_global_var3 = rand();

  svp_simple_022_001_global_var1 = 1;
  svp_simple_022_001_global_var2 = 2;
  svp_simple_022_001_global_var3 = 3;

//  init();
}

void svp_simple_022_001_func_1() { svp_simple_022_001_func_3(); }

void svp_simple_022_001_func_2() { svp_simple_022_001_func_4(); }

void svp_simple_022_001_func_3() {
  if (svp_simple_022_001_global_var1 >= 12) {
    assert(0);
    svp_simple_022_001_global_var1 = 12;       
  } else {
    svp_simple_022_001_global_var1 = 0;
    else_flag = 1;
  }
}

void svp_simple_022_001_func_4() {
  svp_simple_022_001_global_var3 = svp_simple_022_001_global_var1;  
}
void svp_simple_022_001_isr_1() {
  svp_simple_022_001_global_var1 = 18;
}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2;
    pthread_create(&id1, NULL, (void*)svp_simple_022_001_main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_022_001_isr_1, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}

//  svp_simple_022_001_global_var1 = 0;          W
//  svp_simple_022_001_global_var1 = 0;          W
//  if (svp_simple_022_001_global_var1 >= 12) {  R

//  if (svp_simple_022_001_global_var1 >= 12) {  R
//  svp_simple_022_001_global_var1 = 0;          W
//  svp_simple_022_001_global_var1 = 0;          R

//  svp_simple_022_001_global_var1 = 0;          R
//  svp_simple_022_001_global_var1 = 0;          W
//  svp_simple_022_001_global_var3 = svp_simple_022_001_global_var1;  R

//  svp_simple_022_001_global_var3 = svp_simple_022_001_global_var1;  R
//  svp_simple_022_001_global_var1 = 0;          W
//  svp_simple_022_001_global_var3 = svp_simple_022_001_global_var1;  R

// 1: svp_simple_022_001_global_var1 <W, #32>, <W,#66>, <R,#55>
// 2: svp_simple_022_001_global_var1 <R, #55>, <W,#66>, <R,#58>
// 3: svp_simple_022_001_global_var1 <R, #58>, <W,#66>, <R,#63>
// 4: svp_simple_022_001_global_var1 <R, #63>, <W,#66>, <R,#39>

// 可能误报
// 1: svp_simple_022_001_global_var1 <W, #32>, <W,#66>, <R,#39>
// 2: svp_simple_022_001_global_var1 <R, #55>, <W,#66>, <R,#56>
// 3: svp_simple_022_001_global_var1 <R, #55>, <W,#66>, <R,#63>
