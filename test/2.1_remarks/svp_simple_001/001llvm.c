/*
 * racebench2.0
 * Filename:svp_simple_001_001
 * Template File:svp_simple_001
 * Created by Beijing Sunwise Information Technology Ltd. on 19/10/30.
 * Copyright © 2019年 Beijing Sunwise Information Technology Ltd. All rights reserved.
 * [说明]:
 * 主程序入口:svp_simple_001_001_main
 * 中断入口:svp_simple_001_001_isr_1,svp_simple_001_001_isr_2
 * 中断间的优先级以中断号作为标准，中断号越高，中断优先级越高。
 *
 *
 *
 *
 */

#include "../common.h"
#include <stdio.h>
volatile int svp_simple_001_001_global_var;
volatile int svp_simple_001_001_global_array[10000];
volatile int svp_simple_001_001_global_flag = 0;
int a = 1;
#define TRIGGER 9
void disable_isr(int num){}

void main() {
//   init();

  disable_isr(2);

//   idlerun();

    printf("1\n");
    for (int i = 0; i < 10; i++)
    {
        svp_simple_001_001_global_array[i] = 0;
        printf("this is firLoop %d\n",i);
    }

    for (int i = 0; i < 10; i++) {
        if (i == TRIGGER)
        {
            svp_simple_001_001_global_array[i] = 1;
            svp_simple_001_001_global_array[i] = 0;
            printf("this is secLoop %d\n",i);
        }

    }
}
void svp_simple_001_001_isr_1() {
//   idlerun();
    printf("this is isr1\n");
    svp_simple_001_001_global_flag = 1;
    svp_simple_001_001_global_var = 0;
    svp_simple_001_001_global_var = 1;
  enable_isr(2);

//   idlerun();
}

void svp_simple_001_001_isr_2() {
    int reader1, reader3;
    printf("this is isr2\n");
    if (svp_simple_001_001_global_flag ==
        1)
        reader1 = svp_simple_001_001_global_array[TRIGGER];
    else {
        reader1 = svp_simple_001_001_global_array[0];    }

    reader3 = svp_simple_001_001_global_array[1000];
    int reader2;
    reader2 = svp_simple_001_001_global_var;
}

