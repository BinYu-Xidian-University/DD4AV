#include <iostream>
#include <ctime>

#include <time.h>
//volatile int svp_simple_001_001_global_var;
//volatile int svp_simple_001_001_global_array[10000];
//volatile int svp_simple_001_001_global_flag = 0;
//int TRIGGER = 9;
//int main() {
//    // ��ȡ��ǰʱ��
//    clock_t start = clock();
//	int cnt=0;
//    // �����������Ҫͳ��ʱ��Ĵ���Ƭ��
//    // ���磺һ���򵥵�ѭ��
//    for (int i = 0; i < 100; i++){
//        svp_simple_001_001_global_array[i] = 1;
//    }
//    // int i= TRIGGER;
//    for (int i = 0; i < 100; i++) {
//        if (i == TRIGGER){
//            svp_simple_001_001_global_array[i] = 2;
//        }
//    }
//
//    // ��ȡ��ǰʱ��
//    clock_t end = clock();
//
//    // ����ִ��ʱ�䣨�Ժ���Ϊ��λ��
//    double elapsed = double(end - start) / CLOCKS_PER_SEC * 1000.0;
//
//    // ������
//    std::cout << "ִ��ʱ��Ϊ " << elapsed << " ����" << std::endl;
//
//    return 0;
//}
/*
 * racebench2.1_remarks
 * Filename:svp_simple_001_001
 * Template File:svp_simple_001
 * Created by Beijing Sunwise Information Technology Ltd. on 19/11/25.
 * Copyright ? 2019�� Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [˵��]:
 * ���������:svp_simple_001_001_main
 * �ж����:svp_simple_001_001_isr_1,svp_simple_001_001_isr_2
 * �жϼ�����ȼ����жϺ���Ϊ��׼���жϺ�Խ�ߣ��ж����ȼ�Խ�ߡ�
 *
 *
 *
 *
 */

//#include "../common.h"

volatile int svp_simple_001_001_global_var;
volatile int svp_simple_001_001_global_array[10000];
volatile int svp_simple_001_001_global_flag = 0;

#define TRIGGER 9999

int main() {


      clock_t start, end;
    double elapsed;
    
    // ��ȡ��ʼʱ��
    start = clock();

  for (int i = 0; i < 10000; i++) svp_simple_001_001_global_array[i] = 0;

  for (int i = 0; i < 10000; i++) {
    if (i == TRIGGER) svp_simple_001_001_global_array[i] = 1;
  }
  // ��ȡ����ʱ��
    end = clock();

    // ����ִ��ʱ�䣨�Ժ���Ϊ��λ��
    elapsed = ((double) (end - start)) / CLOCKS_PER_SEC * 1000.0;

    // ������
    printf("ִ��ʱ��Ϊ %f ����\n", elapsed);

    return 0;
}

void svp_simple_001_001_isr_1() {
//  idlerun();
  svp_simple_001_001_global_flag = 1;

  svp_simple_001_001_global_var = 0;
  svp_simple_001_001_global_var = 1;
    
//  enable_isr(2);
//
//  idlerun();
}

void svp_simple_001_001_isr_2() {
  int reader1, reader3;
  if (svp_simple_001_001_global_flag ==
      1)
    reader1 = svp_simple_001_001_global_array[TRIGGER];
  else {
    reader1 =
        svp_simple_001_001_global_array[0];    }

  reader3 = svp_simple_001_001_global_array
      [1000];

  int reader2;
  reader2 = svp_simple_001_001_global_var;
}
//bug��:
//1.svp_simple_001_001_global_array <W#32>,<R#55>,<W#35>
//�󱨵㣺
//1.svp_simple_001_001_global_var<W#43><R#63><W#44>
//2.svp_simple_001_001_global_array<W#32><R#60><W#35>

