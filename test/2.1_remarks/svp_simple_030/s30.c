extern void idlerun();

extern void enable_isr(int);

extern void disable_isr(int);
extern int __VERIFIER_nondet_int();
extern int rand();

void svp_simple_030_001_init();
void addData();
volatile int svp_simple_030_001_isr_1_flag;
volatile int svp_simple_030_001_gloable_var;


int svp_simple_030_001_main() {
//  svp_simple_030_001_init();
  svp_simple_030_001_gloable_var = 15;
  svp_simple_030_001_isr_1_flag = 1;
//  disable_isr(-1);
//  enable_isr(1);
  if (svp_simple_030_001_gloable_var > 12) {
    svp_simple_030_001_gloable_var = 0;
  }
  return 0;
}

void svp_simple_030_001_init() {
  svp_simple_030_001_gloable_var = __VERIFER_nondet_int();
  svp_simple_030_001_isr_1_flag = __VERIFER_nondet_int();

//  init();
}

void addData() {
  int tmp = svp_simple_030_001_gloable_var+1;
  svp_simple_030_001_gloable_var=tmp;
}

void svp_simple_001_001_isr_1() {
  addData();
  svp_simple_030_001_isr_1_flag = 0;
//  enable_isr(2);
}
void svp_simple_001_001_isr_2() {
  if (svp_simple_030_001_isr_1_flag) {
    int tmp = svp_simple_030_001_gloable_var+1;
    svp_simple_030_001_gloable_var=tmp;
  }
}
void svp_simple_030_001_isr_3() {
    int tmp = svp_simple_030_001_gloable_var+1;
    svp_simple_030_001_gloable_var=tmp;
}
void init() { enable_isr(-1); }

void idlerun() {
  int i = 0;
  for (i = 0; i <= 100; i++) {
    //		print2("Running....");
  }
}

// bug点：
// 1.svp_simple_030_001_gloable_var <R, #30>, <W, #44>, <W, #31>

// 误报点：
// 1.svp_simple_030_001_gloable_var <R, #29>, <W, #52>, <W, #30>
// 2.svp_simple_030_001_gloable_var <R, #29>, <W, #56>, <W, #30>