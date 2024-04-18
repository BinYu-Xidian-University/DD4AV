# racebench 2.1_remarks

该测试集仅适用于单变量访问序模式的测试。

该测试集为简单测试集racebench2.1带注释版本，给出了预埋的bug点和预埋的误报点。

*注：*

* *所有用例均遵循标准C语法。*
* *测试用例不考虑中断的周期性，中断可以在允许中断的情况下打断主程序或者低级中断，打断的时刻不定，位置不定*
* *目前测试工具只能在一次执行中，中断一次，并且不能中断自己*

## 用例集配置说明

* 中断号用于测试用例中提供的中断开关函数。
* 优先级数字越大，优先级越高
* 这里是没有enable和disable的版本，原本的enable_isr(n)和disable_isr(n)被视为unlock和lock原语。其中n表示中断号，当n为-1时，表示屏蔽/打开所有中断。
* 已经标出了所有TP（真实报告）和FP（误报），如有未标注的，请联系ruixuelicn@163.com


### 简单用例集

共31个测试用例。

| 序号 | 用例名               | 主程序入口              | 中断入口/中断号/优先级                                       |标注|
| ---- | -------------------- | ----------------------- | ------------------------------------------------------------ |---------------------------------------------------------------|
| 1    | svp_simple_001_001.c | svp_simple_001_001_main | svp_simple_001_001_isr_1/1/1   svp_simple_001_001_isr_2/2/2  |循环+数组|
| 2    | svp_simple_002_001.c | svp_simple_002_001_main | svp_simple_002_001_isr_1/1/1     svp_simple_002_001_isr_2/2/2 |循环+数组|
| 3    | svp_simple_003_001.c | svp_simple_003_001_main | svp_simple_003_001_isr_1/1/1     svp_simple_003_001_isr_2/2/2 |循环|
| 4    | svp_simple_004_001.c | svp_simple_004_001_main | svp_simple_004_001_isr_1/1/1    svp_simple_004_001_isr_2/2/2 |无特殊|
| 5    | svp_simple_005_001.c | svp_simple_005_001_main | svp_simple_005_001_isr_1/1/1                                 |双层循环|
| 6    | svp_simple_006_001.c | svp_simple_006_001_main | svp_simple_006_001_isr_1/1/1                                 |双层循环|
| 7    | svp_simple_007_001.c | svp_simple_007_001_main | svp_simple_007_001_isr_1/1/1                                 |数组|
| 8    | svp_simple_008_001.c | svp_simple_008_001_main | svp_simple_008_001_isr_1/1/1                                 |数组|
| 9    | svp_simple_009_001.c | svp_simple_009_001_main | svp_simple_009_001_isr_1/1/1                                 |指针|
| 10   | svp_simple_010_001.c | svp_simple_010_001_main | svp_simple_010_001_isr_1/1/1                                 |联合体/结构体|
| 11   | svp_simple_011_001.c | svp_simple_011_001_main | svp_simple_011_001_isr_1/1/1                                 |指针|
| 12   | svp_simple_012_001.c | svp_simple_012_001_main | svp_simple_012_001_isr_1/1/1                                 |指针|
| 13   | svp_simple_013_001.c | svp_simple_013_001_main | svp_simple_013_001_isr_1/1/1  svp_simple_013_001_isr_2/2/2  svp_simple_013_001_isr_3/3/3 |isr_1没有中断点|
| 14   | svp_simple_014_001.c | svp_simple_014_001_main | svp_simple_014_001_isr_1/1/1    svp_simple_014_001_isr_2/2/2   svp_simple_014_001_isr_3/3/3 |main没有中断点|
| 15   | svp_simple_015_001.c | svp_simple_015_001_main | svp_simple_015_001_isr_1/1/1                                 |有rand()|
| 16   | svp_simple_016_001.c | svp_simple_016_001_main | svp_simple_016_001_isr_1/1/1                                 |隔行操作|
| 17   | svp_simple_017_001.c | svp_simple_017_001_main | svp_simple_017_001_isr_1/1/1                                 |for循环条件为共享变量，出现既有读又有写的情况|
| 18   | svp_simple_018_001.c | svp_simple_018_001_main | svp_simple_018_001_isr_1/1/1  svp_simple_018_001_isr_2/2/2   |指令级别|
| 19   | svp_simple_019_001.c | svp_simple_019_001_main | svp_simple_019_001_isr_1/1/1                                 |有rand+隔行|
| 20   | svp_simple_020_001.c | svp_simple_020_001_main | svp_simple_020_001_isr_1/1/1   svp_simple_020_001_isr_2/2/2  |有rand|
| 21   | svp_simple_021_001.c | svp_simple_021_001_main | svp_simple_021_001_isr_1/1/1                                 |循环+结构体|
| 22   | svp_simple_022_001.c | svp_simple_022_001_main | svp_simple_022_001_isr_1/1/1                                 |循环+数组+rand|
| 23   | svp_simple_023_001.c | svp_simple_023_001_main | svp_simple_023_001_isr_1/1/1                                 |rand+函数调用|
| 24   | svp_simple_024_001.c | svp_simple_024_001_main | svp_simple_024_001_isr_1/1/1                                 |联合体+带参函数|
| 25   | svp_simple_025_001.c | svp_simple_025_001_main | svp_simple_025_001_isr_1/1/1                                 |指针|
| 26   | svp_simple_026_001.c | svp_simple_026_001_main | svp_simple_026_001_isr_1/1/1     svp_simple_026_001_isr_2/2/2 |函数调用|
| 27   | svp_simple_027_001.c | svp_simple_027_001_main | svp_simple_027_001_isr_1/1/1    svp_simple_027_001_isr_2/2/2    svp_simple_027_001_isr_3/3/3 |rand+函数调用|
| 28   | svp_simple_028_001.c | svp_simple_028_001_main | svp_simple_028_001_isr_1/1/1     svp_simple_028_001_isr_2/2/2    svp_simple_028_001_isr_3/3/3 |指令级别+函数调用+rand|
| 29   | svp_simple_029_001.c | svp_simple_029_001_main | svp_simple_029_001_isr_1/1/1                                 |带参函数+指令级别+rand|指令级别+函数调用|
| 30   | svp_simple_030_001.c | svp_simple_030_001_main | svp_simple_030_001_isr_1/1/1     svp_simple_030_001_isr_2/2/2  svp_simple_030_001_isr_3/3/3 |函数调用+rand|
| 31   | svp_simple_031_001.c | svp_simple_031_001_main | svp_simple_031_001_isr_1/1/1                                 |指针+函数调用|

