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



//#define svp_simple_031_001_CNT (volatile unsigned int *)0x10000000
volatile unsigned int *svp_simple_031_001_CNT;
volatile unsigned16 svp_simple_031_001_tc_block_rcvd_bytes_ch1;
volatile unsigned16 svp_simple_031_001_tc_block_rcvd_bytes_ch2;
volatile unsigned16 svp_simple_031_001_tc_block_rcvd_bytes;
volatile unsigned8 svp_simple_031_001_tc_chan1_buff[256];
volatile unsigned8 svp_simple_031_001_tc_chan2_buff[256];
volatile unsigned8 *svp_simple_031_001_tc_buff_p;
volatile unsigned32 svp_simple_031_001_gloable_var1 = 20;
volatile unsigned svp_simple_031_001_flag_chan1 = 0;

struct svp_simple_031_001_tc_block_data {
  unsigned type;
  unsigned id;
  unsigned valid_len;
};
void svp_simple_031_001_main() {
  //  svp_simple_031_001_tc_block_rcvd_bytes_ch1 = rand();
//  svp_simple_031_001_tc_block_rcvd_bytes_ch2 = rand();
  svp_simple_031_001_tc_block_rcvd_bytes_ch1 = 16;
  svp_simple_031_001_tc_block_rcvd_bytes_ch2 = 15;
  struct svp_simple_031_001_tc_block_data tc_block;

  int ichan = 0;
  if (ichan == 0) {
    svp_simple_031_001_tc_buff_p = svp_simple_031_001_tc_chan1_buff;
    svp_simple_031_001_tc_block_rcvd_bytes = svp_simple_031_001_tc_block_rcvd_bytes_ch1;
  }
  tc_block.type = *(svp_simple_031_001_tc_buff_p + 2);
  tc_block.id = *(svp_simple_031_001_tc_buff_p + 4);
  tc_block.valid_len = *(svp_simple_031_001_tc_buff_p + 5);
  if (svp_simple_031_001_tc_block_rcvd_bytes_ch1 >= 16) {
    int c;
  if (svp_simple_031_001_gloable_var1 < svp_simple_031_001_tc_block_rcvd_bytes_ch1) {
    c = asvp_simple_031_001_gloable_var1 * svp_simple_031_001_tc_block_rcvd_bytes_ch1b;
  } else {
    if (svp_simple_031_001_tc_block_rcvd_bytes_ch1 > 0) {
    c= 10;
  } else {
    c= 0;
  }
  }
    svp_simple_031_001_flag_chan1 = 1;
  }

}



void svp_simple_031_001_isr_1() {
  svp_simple_031_001_tc_block_rcvd_bytes_ch1 = (*(svp_simple_031_001_CNT) >> 3) & 0x1FFF;
}

int main(int argc, char **argv) {

    svp_simple_031_001_CNT = (volatile unsigned int *)malloc(sizeof(unsigned int));
    *svp_simple_031_001_CNT = 24;

    printf("start\n");
    pthread_t id1, id2;
    pthread_create(&id1, NULL, (void*)svp_simple_031_001_main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_031_001_isr_1, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}