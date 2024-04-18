#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

typedef union pack1 {
  unsigned char header;
  unsigned int data;
} svp_simple_010_001_union;

typedef struct pack2 {
  unsigned char header;
  unsigned int data;
} svp_simple_010_001_struct;

volatile svp_simple_010_001_union svp_simple_010_001_global_union;
volatile svp_simple_010_001_struct svp_simple_010_001_global_struct;

void svp_simple_010_001_main() {
//  init();
  int svp_simple_010_001_local_var1 = 0x01;
  int svp_simple_010_001_local_var2 = 0x02;

  int svp_simple_010_001_local_var3 = 0x03;
  int svp_simple_010_001_local_var4 = 0x04;

  svp_simple_010_001_global_union.header = svp_simple_010_001_local_var1;
  svp_simple_010_001_global_union.data = svp_simple_010_001_local_var2;

  svp_simple_010_001_global_struct.header = svp_simple_010_001_local_var3;
  svp_simple_010_001_global_struct.data = svp_simple_010_001_local_var4;
}

void svp_simple_010_001_isr_1() {
//  idlerun();
  int reader1, reader2;

  reader1 = svp_simple_010_001_global_union.header;
  if(reader1 == 0x01) {
    assert(0);
  }
  reader2 = svp_simple_010_001_global_struct.header;
}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2;
    pthread_create(&id1, NULL, (void*)svp_simple_010_001_main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_010_001_isr_1, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}

//  svp_simple_010_001_global_union.header = svp_simple_010_001_local_var1;   W
//  reader1 = svp_simple_010_001_global_union.header;                       R
//  svp_simple_010_001_global_union.data = svp_simple_010_001_local_var2;   W
