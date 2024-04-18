#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

typedef unsigned char unsigned8;
typedef unsigned short unsigned16;
typedef unsigned int unsigned32;
typedef unsigned long long unsigned64;

typedef signed char signed8;
typedef signed short signed16;
typedef signed int signed32;
typedef signed long long signed64;

union bytetoword {
  unsigned char bytedata[2];
  unsigned int worddata;
};

volatile int svp_simple_024_001_global_var;
volatile int svp_simple_024_001_global_array[100];
volatile unsigned8 svp_simple_024_001_reset_RT;
unsigned int svp_simple_024_001_RTData(int *array, int size);
void svp_simple_024_001_init();

void svp_simple_024_001_main() {
  union bytetoword svp_simple_024_001_local_a, svp_simple_024_001_local_b;
  svp_simple_024_001_init();
  svp_simple_024_001_local_a.worddata = svp_simple_024_001_RTData((int *)svp_simple_024_001_global_array, 0);
  svp_simple_024_001_local_b.worddata = svp_simple_024_001_RTData((int *)svp_simple_024_001_global_array, 1);
  if(svp_simple_024_001_local_a.worddata == 256 || svp_simple_024_001_local_b.worddata == 256) {
    assert(0);
  }
  int svp_simple_024_001_local_casereg =
      svp_simple_024_001_local_a.worddata | svp_simple_024_001_local_b.worddata & 0x02f0;

  switch (svp_simple_024_001_local_casereg) {
    case 0x02f0:
      svp_simple_024_001_reset_RT = 1;
      break;
    case 0x0390:
      svp_simple_024_001_reset_RT = 0;
      break;
    default:
      break;
  }
}
void svp_simple_024_001_init() {
//  svp_simple_024_001_global_var = rand();
  svp_simple_024_001_global_var = 2;

//  init();
}

unsigned int svp_simple_024_001_RTData(int *array, int index) {
  union bytetoword svp_simple_024_001_local_r;
  svp_simple_024_001_local_r.bytedata[0] = array[index + 1];  
  svp_simple_024_001_local_r.bytedata[1] = array[index];

//  if(svp_simple_024_001_local_r.bytedata[0] != svp_simple_024_001_local_r.bytedata[1]) {
//    assert(0);
//  }
  return svp_simple_024_001_local_r.worddata;
}
void svp_simple_024_001_isr_1() {
  for (int i = 0; i < 4; i++) {
    svp_simple_024_001_global_array[i] = 1;
  }
}

int main(int argc, char **argv) {

    printf("start\n");
    pthread_t id1, id2;
    pthread_create(&id1, NULL, (void*)svp_simple_024_001_main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_024_001_isr_1, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}

//  svp_simple_024_001_local_r.bytedata[0] = array[index + 1];  R
//    svp_simple_024_001_global_array[i] = 0;                   W
//  svp_simple_024_001_local_r.bytedata[1] = array[index];      R
