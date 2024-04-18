#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

volatile int svp_simple_020_001_global_var = 4;

volatile int svp_simple_020_001_global_para;

volatile int svp_simple_020_001_global_flag = 0;

void svp_simple_020_001_main() {
//  init();
//  disable_isr(2);
  int reader1, reader2;
  int svp_simple_020_001_local_var1, svp_simple_020_001_local_var2;
//  svp_simple_020_001_local_var1 = rand();
//  svp_simple_020_001_local_var2 = rand();
  svp_simple_020_001_local_var1 = 1;
  svp_simple_020_001_local_var2 = 2;

  if (svp_simple_020_001_local_var1 + svp_simple_020_001_local_var2 > svp_simple_020_001_global_para){
      reader1 = svp_simple_020_001_global_var;
  }
  if (svp_simple_020_001_local_var1 + svp_simple_020_001_local_var2 < svp_simple_020_001_global_para){
      reader2 = svp_simple_020_001_global_var;
  }


//  printf("reader1=%d, reader2=%d\n", reader1, reader2);
  if((reader1 == 1 && reader2 == 5) || (reader1 == 4 && reader2 == 5)) {
    assert(0);
  }
}

void svp_simple_020_001_isr_1() {
  svp_simple_020_001_global_var = 0x01;
  
  svp_simple_020_001_global_flag = 1;
//  enable_isr(2);
}

void svp_simple_020_001_isr_2() {
  if (svp_simple_020_001_global_flag == 1) {
    svp_simple_020_001_global_para = 11;
    svp_simple_020_001_global_var = 0x05;
  }
}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2, id3;
    pthread_create(&id1, NULL, (void*)svp_simple_020_001_main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_020_001_isr_1, NULL);
    pthread_create(&id3, NULL, (void*)svp_simple_020_001_isr_2, NULL);
    pthread_join(id3, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}

//    reader1 = svp_simple_020_001_global_var;
//    svp_simple_020_001_global_var = 0x05;
//    reader2 = svp_simple_020_001_global_var;

//> svp_simple_020_001_global_para)
//    svp_simple_020_001_global_para = 11;
// < svp_simple_020_001_global_para)

//bug点:
//1.svp_simple_020_001_global_var<R#37>,<W#53>,<R#40>
//2.svp_simple_020_001_global_para<R#36>,<W#52>,<R#39>
//误报点:
//1.svp_simple_020_001_global_var<R#37>,<W#44>,<R#40>