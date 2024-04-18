extern void idlerun();
extern int __VERIFIER_nondet_int();
extern void enable_isr(int);

extern void disable_isr(int);

extern int rand();

void init();


volatile int svp_simple_016_001_global_var1;

void svp_simple_016_001_main() {
//  init();
    int reader1;
    svp_simple_016_001_global_var1 = 0x01;

    reader1 = svp_simple_016_001_global_var1 +
              svp_simple_016_001_global_var1 +
              svp_simple_016_001_global_var1;
//  int tmp1 = svp_simple_016_001_global_var1;
//  int tmp2 = svp_simple_016_001_global_var1+tmp1;
//  reader1 = svp_simple_016_001_global_var1+tmp2;
}

void svp_simple_001_001_isr_1() {
//  idlerun();
  svp_simple_016_001_global_var1 = 0x09;
}
//void init() { enable_isr(-1); }
//
//void idlerun() {
//  int i = 0;
//  for (i = 0; i <= 100; i++) {
//    //		print2("Running....");
//  }
//}
//bug点:
//1.svp_simple_016_001_global_var1<W#28>,<R#37>,<R#29>
//2.svp_simple_016_001_global_var1<R#29>,<W#37>,<R#30>
//3.svp_simple_016·_001_global_var1<R#30>,<W#37>,<R#31>