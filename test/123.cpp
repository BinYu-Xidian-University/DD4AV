#include <iostream>
#include <ctime>

#include <time.h>
//volatile int svp_simple_001_001_global_var;
//volatile int svp_simple_001_001_global_array[10000];
//volatile int svp_simple_001_001_global_flag = 0;
//int TRIGGER = 9;
//int main() {
//    // 获取当前时间
//    clock_t start = clock();
//	int cnt=0;
//    // 这里放置你想要统计时间的代码片段
//    // 例如：一个简单的循环
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
//    // 获取当前时间
//    clock_t end = clock();
//
//    // 计算执行时间（以毫秒为单位）
//    double elapsed = double(end - start) / CLOCKS_PER_SEC * 1000.0;
//
//    // 输出结果
//    std::cout << "执行时间为 " << elapsed << " 毫秒" << std::endl;
//
//    return 0;
//}
/*
 * racebench2.1_remarks
 * Filename:svp_simple_001_001
 * Template File:svp_simple_001
 * Created by Beijing Sunwise Information Technology Ltd. on 19/11/25.
 * Copyright ? 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [说明]:
 * 主程序入口:svp_simple_001_001_main
 * 中断入口:svp_simple_001_001_isr_1,svp_simple_001_001_isr_2
 * 中断间的优先级以中断号作为标准，中断号越高，中断优先级越高。
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
    
    // 获取开始时间
    start = clock();

  for (int i = 0; i < 10000; i++) svp_simple_001_001_global_array[i] = 0;

  for (int i = 0; i < 10000; i++) {
    if (i == TRIGGER) svp_simple_001_001_global_array[i] = 1;
  }
  // 获取结束时间
    end = clock();

    // 计算执行时间（以毫秒为单位）
    elapsed = ((double) (end - start)) / CLOCKS_PER_SEC * 1000.0;

    // 输出结果
    printf("执行时间为 %f 毫秒\n", elapsed);

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
//bug点:
//1.svp_simple_001_001_global_array <W#32>,<R#55>,<W#35>
//误报点：
//1.svp_simple_001_001_global_var<W#43><R#63><W#44>
//2.svp_simple_001_001_global_array<W#32><R#60><W#35>

