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

//#define svp_simple_021_001_CNT (volatile unsigned int *)0x10000000
volatile unsigned int *svp_simple_021_001_CNT;

volatile unsigned16 svp_simple_021_001_tc_block_rcvd_bytes_ch1;
volatile unsigned16 svp_simple_021_001_tc_block_rcvd_bytes_ch2;
volatile unsigned16 svp_simple_021_001_tc_block_rcvd_bytes;
volatile unsigned8 svp_simple_021_001_tc_chan1_buff[4];
volatile unsigned8 svp_simple_021_001_tc_chan2_buff[4];
volatile unsigned8 *svp_simple_021_001_tc_buff_p;
unsigned svp_simple_021_001_flag_chan1 = 0;

struct svp_simple_021_001_tc_block_data {
  unsigned8 type;
  unsigned8 id;
  unsigned8 valid_len;
};

void svp_simple_021_001_init() {
//  svp_simple_021_001_tc_block_rcvd_bytes_ch1 = rand();
//  svp_simple_021_001_tc_block_rcvd_bytes_ch2 = rand();
  svp_simple_021_001_tc_block_rcvd_bytes_ch1 = 18;
  svp_simple_021_001_tc_block_rcvd_bytes_ch2 = 2;
//  init();
}

void svp_simple_021_001_RecvTcBlock() {

  if (svp_simple_021_001_tc_block_rcvd_bytes_ch1 >= 16) {
    svp_simple_021_001_tc_block_rcvd_bytes_ch1 = 0;       
    int i;
    for (i = 0; i < 4; i++) {
      svp_simple_021_001_tc_chan1_buff[i] = 0;
    }
    svp_simple_021_001_flag_chan1 = 0xFF;
  }
}

void svp_simple_021_001_main() {
  struct svp_simple_021_001_tc_block_data tc_block;

  svp_simple_021_001_init();

  svp_simple_021_001_RecvTcBlock();
  int ichan;
  for (ichan = 0; ichan < 2; ichan++) {
    if (ichan == 0) {
      svp_simple_021_001_tc_buff_p = svp_simple_021_001_tc_chan1_buff;
      svp_simple_021_001_tc_block_rcvd_bytes = svp_simple_021_001_tc_block_rcvd_bytes_ch1;
//      printf("bytes=%d\n",svp_simple_021_001_tc_block_rcvd_bytes);
//      printf("bytes_ch1=%d\n",svp_simple_021_001_tc_block_rcvd_bytes_ch1);
    } else {
      svp_simple_021_001_tc_buff_p = svp_simple_021_001_tc_chan2_buff;
      svp_simple_021_001_tc_block_rcvd_bytes = svp_simple_021_001_tc_block_rcvd_bytes_ch2;
    }
    if((svp_simple_021_001_tc_block_rcvd_bytes == ((*(svp_simple_021_001_CNT) >> 3) & 0x1FFF)) && (svp_simple_021_001_flag_chan1 == 0xFF)) {
        assert(0);
    }
    if((svp_simple_021_001_tc_block_rcvd_bytes == 0) && (svp_simple_021_001_flag_chan1 == 0xFF)) {
        assert(0);
    }
    tc_block.type = *(svp_simple_021_001_tc_buff_p + 2);
    tc_block.id = *(svp_simple_021_001_tc_buff_p + 4);
    tc_block.valid_len = *(svp_simple_021_001_tc_buff_p + 5);
  }
}

void svp_simple_021_001_isr_1() {
  svp_simple_021_001_tc_block_rcvd_bytes_ch1 = (*(svp_simple_021_001_CNT) >> 3) & 0x1FFF;
}

int main(int argc, char **argv) {

    svp_simple_021_001_CNT = (volatile unsigned int *)malloc(sizeof(unsigned int));
    *svp_simple_021_001_CNT = 24; // 初始化

    printf("start\n");
    pthread_t id1, id2;
    pthread_create(&id1, NULL, (void*)svp_simple_021_001_main, NULL);
    pthread_create(&id2, NULL, (void*)svp_simple_021_001_isr_1, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}

//  if (svp_simple_021_001_tc_block_rcvd_bytes_ch1 >= 16) {
//  svp_simple_021_001_tc_block_rcvd_bytes_ch1 =
//    svp_simple_021_001_tc_block_rcvd_bytes_ch1 = 0;

//svp_simple_021_001_tc_block_rcvd_bytes_ch1 = 0;
//svp_simple_021_001_tc_block_rcvd_bytes_ch1 =
//      svp_simple_021_001_tc_block_rcvd_bytes = svp_simple_021_001_tc_block_rcvd_bytes_ch1;

//if (svp_simple_021_001_tc_block_rcvd_bytes_ch1 >= 16) {
//svp_simple_021_001_tc_block_rcvd_bytes_ch1 =
//svp_simple_021_001_tc_block_rcvd_bytes = svp_simple_021_001_tc_block_rcvd_bytes_ch1;

// bug点：
// 1.svp_simple_021_001_tc_block_rcvd_bytes_ch1 <R,#44>, <W,#79>, <W,#45>
// 2.svp_simple_021_001_tc_block_rcvd_bytes_ch1 <W,#45>, <W,#79>, <R,#65>
// 3.svp_simple_021_001_tc_block_rcvd_bytes_ch1 <R,#44>, <W,#79>, <R,#65>