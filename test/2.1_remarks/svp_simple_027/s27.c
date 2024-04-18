extern void idlerun();

extern void enable_isr(int);
extern int __VERIFIER_nondet_int();
extern void disable_isr(int);

extern int rand();

void init();

void svp_simple_027_001_init();

volatile int svp_simple_027_001_gloable_var;
int svp_simple_027_001_main() {
//  svp_simple_027_001_init();
  svp_simple_027_001_gloable_var = 411;

//  disable_isr(-1);
//  enable_isr(1);
  if (svp_simple_027_001_gloable_var > 12) {
    svp_simple_027_001_gloable_var = 0;
  }

  return 0;
}

void svp_simple_027_001_init() {
  svp_simple_027_001_gloable_var =  __VERIFER_nondet_int();

//  init();
}

void svp_simple_001_001_isr_1() {
  int tmp = svp_simple_027_001_gloable_var + 1;
  svp_simple_027_001_gloable_var = tmp;
//  enable_isr(2);
}
void svp_simple_001_001_isr_2() {
  int tmp = svp_simple_027_001_gloable_var + 2;
  svp_simple_027_001_gloable_var = tmp;
}
void svp_simple_027_001_isr_3() {
  int tmp = svp_simple_027_001_gloable_var + 3;
  svp_simple_027_001_gloable_var = tmp;
}

//void init() { enable_isr(-1); }

void idlerun() {
  int i = 0;
  for (i = 0; i <= 100; i++) {
    //		print2("Running....");
  }
}

// bug点：
// 1.svp_simple_027_001_gloable_var <R, #30>, <W, 44>, <W, #31>
// 2.svp_simple_027_001_gloable_var <R, #30>, <W, 48>, <W, #31>

// 误报点：
// 1.svp_simple_027_001_gloable_var <R, #27>, <W, 48>, <W, #28>