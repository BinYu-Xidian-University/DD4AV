extern void idlerun();
extern int __VERIFIER_nondet_int();
extern void enable_isr(int);

extern void disable_isr(int);

extern int rand();

void init();



#define MAX_LENGTH 50
#define TRIGGER 49

volatile int svp_simple_006_001_global_var1;
volatile int svp_simple_006_001_global_var2;
volatile unsigned char flag = 0x55;
void svp_simple_006_001_main() {
//  init();
  int reader1, reader2;

  for (int i = 0; i < MAX_LENGTH; i++) {
      for (int j = 0; j < MAX_LENGTH; j++) {
        if (i == j) {
          if (i == 0) {
            reader1 = svp_simple_006_001_global_var1;
          }
          else if (i == 3) {
            reader2 = svp_simple_006_001_global_var1;
          }
          else if (i == 6) {
            reader2 = svp_simple_006_001_global_var1;
          }
        }
      }
  }

  for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (((i + j) == 6) && (i < j)) {
            svp_simple_006_001_global_var2 = 0x02;
        }
      }
  }
}

void svp_simple_001_001_isr_1() {
  int reader2;
//  idlerun();

  svp_simple_006_001_global_var1 = 0;
  reader2 = svp_simple_006_001_global_var2;
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
//1.svp_simple_006_001_global_var1<R#33>,<W#52>,<R#35>
//误报点:
//1.svp_simple_006_001_global_var1<R#35>,<W#52>,<R#37>
//2.svp_simple_006_001_global_var2<W#44>,<R#53>,<W#44>