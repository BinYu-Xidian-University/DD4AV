
extern void __VERIFIER_atomic_begin();
extern void __VERIFIER_atomic_end();
extern void __VERIFIER_assume(int);

void __VERIFIER_assert(int x)
{
  if(!x)
   ERROR: goto ERROR;
}

//void irq_err(void) {ERROR: goto ERROR;}


int __TRANS_thread_running[] = {0, 0};

void __VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask(void) {
__VERIFIER_assume(__TRANS_thread_running[1]==0);
}

void TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask(void) {
__VERIFIER_assume(__TRANS_thread_running[1]==0);
}

void __VERIFIER_atomic_TRANS_AlarmToTimerC_0_fired_runTask_enter_thread() {
__VERIFIER_assume(__TRANS_thread_running[1]==0);
__TRANS_thread_running[0]=1;
__VERIFIER_assume(__TRANS_thread_running[1]==0);
}

void __VERIFIER_atomic_TRANS_AlarmToTimerC_0_fired_runTask_leave_thread() {
__VERIFIER_assume(__TRANS_thread_running[1]==0);
__TRANS_thread_running[0]=0;
__VERIFIER_assume(__TRANS_thread_running[1]==0);
}

/*
void __VERIFIER_atomic_TRANS_atomic_assume_VirtualizeTimerC_0_updateFromTimer_runTask(void) {
__VERIFIER_assume(1);
}

void TRANS_atomic_assume_VirtualizeTimerC_0_updateFromTimer_runTask(void) {
__VERIFIER_assume(1);
}
*/

void __VERIFIER_atomic_TRANS_VirtualizeTimerC_0_updateFromTimer_runTask_enter_thread() {
__TRANS_thread_running[1]=1;
}

void __VERIFIER_atomic_TRANS_VirtualizeTimerC_0_updateFromTimer_runTask_leave_thread() {
__TRANS_thread_running[1]=0;
}

/* A model of the MSP430 memory map and CPU functions 
 *
 * THE MSP430 MEMORY MAP
 *
The MSP430 is a very clean 16-bit byte-addressed processor with a 64K unified
address space, and memory-mapped peripherals. The current family ranges from a
20-pin package with 1K of ROM and 128 bytes of RAM to 100-pin packages with 60K
of ROM and 2K of RAM. All current MSP430s share a common memory map. The amount
of each type of memory varies with the device, but the overall layout is common.

At the low end of memory is a 512 byte space for the memory-mapped peripherals.
The first 256 bytes of this are on an 8-bit bus, and can only be accessed 8 bits
at a time. The second 256 bytes are on a 16-bit bus, and can only be accessed 16
bits at a time.

RAM begins at address 0x200. If there is 2K of RAM, it extends from address
0x0200 to 0x9FF. The main ROM is always at the highest addresses. In the 60K
version it extends from address 0x1100 to 0xFFFF (see below for what happens
between 0x1000 and 0x10FF).

Processors with flash memory have a 1K serial bootloader ROM at addresses 0x0C00
to 0x0FFF. This is unalterable, masked, ROM. It contains a factory set program
to erase and reprogram the on board flash memory.  Processors with flash memory
also have an additional 128 or 256 bytes of flash memory between addresses
0x1000 and 0x107F or 0x10FF. The only real difference between this and the main
flash memory is that this is erasable in 128 byte pages. This makes it more
suitable for efficiently handling configuration data.
 *
 *
 * REGISTERS 
 */
unsigned short _R0;    /* R0/PC Program Counter     */
unsigned short _R1;    /* R1/SP Stack Pointer       */
unsigned short _R2;    /* R2/SR/CG1 Status          */
unsigned short _R3;    /* R3/CG2 Constant Generator */
unsigned short _R4;    /* General Purpose           */
unsigned short _R5;    /* General Purpose           */
unsigned short _R6;    /* General Purpose           */
unsigned short _R7;    /* General Purpose           */
unsigned short _R8;    /* General Purpose           */
unsigned short _R9;    /* General Purpose           */
unsigned short _R10;   /* General Purpose           */
unsigned short _R11;   /* General Purpose           */
unsigned short _R12;   /* General Purpose           */
unsigned short _R13;   /* General Purpose           */
unsigned short _R14;   /* General Purpose           */
unsigned short _R15;   /* General Purpose           */

// GIE: General Interrupt Enable
// 0: interrupts disabled; 1: interrupts enabled
// bit 0 in "_R2"

#define     set_GIE (_R2 |= 0x0008)  

#define   unset_GIE (_R2 &= 0xfff7) 

#define enabled_GIE ((_R2 & 0x0008) != 0x0000)

/* PERIPHERALS
 *
-  8-bit SFR             0000h -> 000Fh      
-  8-bit peripherals     0010h -> 00FFh    
- 16-bit peripherals     0100h -> 01FFh  

The MSP430's memory mapped peripheral registers are termed Special Function
Registers (SFRs). Consider a peripheral a normal variable, which is simply
mapped to the specific memory location.
 *
 * 8-bit SFR:
 */
unsigned char _IE1;    /* 0x0000 Interrupt Enable 1 */
unsigned char _IE2;    /* 0x0001 Interrupt Enable 2 */
unsigned char _IFG1;   /* 0x0002 Interrupt Flag 1   */
unsigned char _IFG2;   /* 0x0003 Interrupt Flag 2   */
unsigned char _ME1;    /* 0x0004 Module Enable 1    */
unsigned char _ME2;    /* 0x0005 Module Enable 2    */

/* 8-bit peripherals:
 *
 * Port P1 
 */
unsigned char _P1IN;     /* 0x0020 Input                 */
unsigned char _P1OUT;    /* 0x0021 Output                */
unsigned char _P1DIR;    /* 0x0022 Direction             */
unsigned char _P1IFG;    /* 0x0023 Interrupt Flag        */
unsigned char _P1IES;    /* 0x0024 Interrupt-Edge Select */
unsigned char _P1IE;     /* 0x0025 Interrupt Enable      */
unsigned char _P1SEL;    /* 0x0026 Selection             */

/*
 * Port P2
 */
unsigned char _P2IN;     /* 0x0028 Input                 */
unsigned char _P2OUT;    /* 0x0029 Output                */
unsigned char _P2DIR;    /* 0x002A Direction             */
unsigned char _P2IFG;    /* 0x002B Interrupt Flag        */
unsigned char _P2IES;    /* 0x002C Interrupt-Edge Select */
unsigned char _P2IE;     /* 0x002D Interrupt Enable      */
unsigned char _P2SEL;    /* 0x002E Selection             */

/*
 * Port P3
 */
unsigned char _P3IN;     /* 0x0018 Input                 */
unsigned char _P3OUT;    /* 0x0019 Output                */
unsigned char _P3DIR;    /* 0x001A Direction             */
unsigned char _P3SEL;    /* 0x001B Selection             */

/*
 * Port P4
 */
unsigned char _P4IN;     /* 0x001C Input                 */
unsigned char _P4OUT;    /* 0x001D Output                */
unsigned char _P4DIR;    /* 0x001E Direction             */
unsigned char _P4SEL;    /* 0x001F Selection             */

/*
 * Port P5
 */
unsigned char _P5IN;     /* 0x0030 Input                 */
unsigned char _P5OUT;    /* 0x0031 Output                */
unsigned char _P5DIR;    /* 0x0032 Direction             */
unsigned char _P5SEL;    /* 0x0033 Selection             */

/*
 * Port P6
 */
unsigned char _P6IN;     /* 0x0034 Input                 */
unsigned char _P6OUT;    /* 0x0035 Output                */
unsigned char _P6DIR;    /* 0x0036 Direction             */
unsigned char _P6SEL;    /* 0x0037 Selection             */

/*
 * BrownOUT, SVS
 */
unsigned char _SVSCTL;   /* 0x0055 SVS */ 

/*
 * Basic Clock
 */
unsigned char _BCSCTL2;   /* 0x0058 Basic clock system control2 */
unsigned char _BCSCTL1;   /* 0x0057 Basic clock system control1 */
unsigned char _DCOCTL;    /* 0x0056 DCO clock frequency control */

/*
 * Comparator_A
 */
unsigned char _CAPD;      /* 0x005B Comparator_A port disable   */
unsigned char _CACTL2;    /* 0x005A Comparator_A control2       */
unsigned char _CACTL1;    /* 0x0059 Comparator_A control1       */

/*
 * USART0 (UART or SPImode - the default)
 */
unsigned char _U0TXBUF;   /* 0x0077 Transmit buffer    */
unsigned char _U0RXBUF;   /* 0x0076 Receive buffer     */
unsigned char _U0BR1;     /* 0x0075 Baud rate          */
unsigned char _U0BR0;     /* 0x0074 Baud rate          */
unsigned char _U0MCTL;    /* 0x0073 Modulation control */
unsigned char _U0RCTL;    /* 0x0072 Receive control    */
unsigned char _U0TCTL;    /* 0x0071 Transmit control   */
unsigned char _U0CTL;     /* 0x0070 USART control      */

/*
 * USART1 (MSP430F16x and MSP430F161x only)
 */
unsigned short _U1TXBUF;  /* 0x007F Transmit buffer */
unsigned short _U1RXBUF;  /* 0x007E Receive buffer  */
unsigned short _U1BR1;    /* 0x007D Baud rate       */
unsigned short _U1BR0;    /* 0x007C Baud rate       */
unsigned short _U1MCTL;   /* 0x007B Modulation control      */
unsigned short _U1RCTL;   /* 0x007A Receive control */
unsigned short _U1TCTL;   /* 0x0079 Transmit control        */
unsigned short _U1CTL;    /* 0x0078 USART control   */

/*
 * Watchdog 
 */
unsigned short _WDTCTL;   /* 0x0120 Watchdog Timer control */

/*
 * Flash 
 */
unsigned short _FCTL3;  /* 0x012C Flash control 3        */
unsigned short _FCTL2;  /* 0x012A Flash control 2        */
unsigned short _FCTL1;  /* 0x0128 Flash control 1        */

/*
 * Hardware Multiplier (MSP430F16x and MSP430F161x only) 
 */

unsigned short _SUMEXT; /* 0x013E Sum extend                     */
unsigned short _RESHI;  /* 0x013C Result high word               */
unsigned short _RESLO;  /* 0x013A Result low word                */
unsigned short _OP2;    /* 0x0138 Second operand                 */
unsigned short _MACS;   /* 0x0136 Multiply signed +accumulate/operand1   */
unsigned short _MAC;    /* 0x0134 Multiply+accumulate/operand1   */
unsigned short _MPYS;   /* 0x0132 Multiply signed/operand1       */
unsigned short _MPY;    /* 0x0130 Multiply unsigned/operand1     */

/*
 * Timer_A3
 */
unsigned short _TACCTL2;  /* 0x0166 Capture/compare control 2      */
unsigned short _TACCTL1;  /* 0x0164 Capture/compare control 1      */
unsigned short _TACCTL0;  /* 0x0162 Capture/compare control 0      */
unsigned short _TACTL;    /* 0x0160 Timer_A control                */
unsigned short _TAIV;     /* 0x012E Timer_A interrupt vector       */
unsigned short _TACCR2;   /* 0x0176 Capture/compare register 2     */
unsigned short _TACCR1;   /* 0x0174 Capture/compare register 1     */
unsigned short _TACCR0;   /* 0x0172 Capture/compare register 0     */
unsigned short _TAR;      /* 0x0170 Timer_A count register         */

void set_TACTL_bit2()
{
  _TAR    = 0x0000;
  _TACTL &= 0xFF0B; /* reset [7-6], [5-4], [2] */
}

/* 
 * Timer_B3 
 */
unsigned short _TBCCR6;   /* 0x019E Capture/compare register 6     */
unsigned short _TBCCR5;   /* 0x019C Capture/compare register 5     */
unsigned short _TBCCR4;   /* 0x019A Capture/compare register 4     */
unsigned short _TBCCR3;   /* 0x0198 Capture/compare register 3     */
unsigned short _TBCCR2;   /* 0x0196 Capture/compare register 2     */
unsigned short _TBCCR1;   /* 0x0194 Capture/compare register 1     */
unsigned short _TBCCR0;   /* 0x0192 Capture/compare register 0     */
unsigned short _TBR;      /* 0x0190 Timer_B count register         */
unsigned short _TBCCTL6;  /* 0x018E Capture/compare control 6      */
unsigned short _TBCCTL5;  /* 0x018C Capture/compare control 5      */
unsigned short _TBCCTL4;  /* 0x018A Capture/compare control 4      */
unsigned short _TBCCTL3;  /* 0x0188 Capture/compare control 3      */
unsigned short _TBCCTL2;  /* 0x0186 Capture/compare control 2      */
unsigned short _TBCCTL1;  /* 0x0184 Capture/compare control 1      */
unsigned short _TBCCTL0;  /* 0x0182 Capture/compare control 0      */
unsigned short _TBCTL;    /* 0x0180 Timer_B control                */
unsigned short _TBIV;     /* 0x011E Timer_B interrupt vector       */

void set_TBCTL_bit2()
{
  _TBR    = 0x0000;
  _TBCTL &= 0xFF0B; /* reset [7-6], [5-4], [2] */
}

/*
Reserved 016Eh 
Reserved 016Ch 
Reserved 016Ah 
Reserved 0168h 

Reserved 017Eh 
Reserved 017Ch 
Reserved 017Ah 
Reserved 0178h 
 */

/*
 * ADC12
 */
unsigned short _ADC12IV;        /* 0x01A8 Interrupt-vector-word register */
unsigned short _ADC12IE;        /* 0x01A6 Inerrupt-enable register       */
unsigned short _ADC12IFG;       /* 0x01A4 Inerrupt-flag register */
unsigned short _ADC12CTL1;      /* 0x01A2 Control register 1     */
unsigned short _ADC12CTL0;      /* 0x01A0 Control register 0     */

unsigned short _ADC12MEM[16];   /* 0x0140 Conversion memory 0-15    */
unsigned char  _ADC12MCTL[16];  /* 0x0080 ADC memory-control register0    */

/* 
 * DAC12
 */
unsigned short _DAC12_1DAT;   /* 0x01CA DAC12_1 data     */
unsigned short _DAC12_1CTL;   /* 0x01C2 DAC12_1 control  */
unsigned short _DAC12_0DAT;   /* 0x01C8 DAC12_0 data     */
unsigned short _DAC12_0CTL;   /* 0x01C0 DAC12_0 control  */

/* 
 * DMA 
 */
unsigned short _DMA2SZ;   /* 0x01F6 DMA channel 2 transfer size        */
unsigned short _DMA2DA;   /* 0x01F4 DMA channel 2 destination address  */
unsigned short _DMA2SA;   /* 0x01F2 DMA channel 2 source address       */
unsigned short _DMA2CTL;  /* 0x01F0 DMA channel 2 control              */
unsigned short _DMA1SZ;   /* 0x01EE DMA channel 1 transfer size        */
unsigned short _DMA1DA;   /* 0x01EC DMA channel 1 destination address  */
unsigned short _DMA1SA;   /* 0x01EA DMA channel 1 source address       */
unsigned short _DMA1CTL;  /* 0x01E8 DMA channel 1 control              */
unsigned short _DMA0SZ;   /* 0x01E6 DMA channel 0 transfer size        */
unsigned short _DMA0DA;   /* 0x01E4 DMA channel 0 destination address  */
unsigned short _DMA0SA;   /* 0x01E2 DMA channel 0 source address       */
unsigned short _DMA0CTL;  /* 0x01E0 DMA channel 0 control              */
unsigned short _DMACTL1;  /* 0x0124 DMA module control 1               */
unsigned short _DMACTL0;  /* 0x0122 DMA module control 0               */

/* 
 * MSP430 devices have up to 6 digital I/O ports implemented, P1 - P6. Each 
 * port has eight I/O pins. Every I/O pin is individually configurable for 
 * input or output direction, and each I/O line can be individually read or 
 * written to. Ports P1 and P2 have interrupt capability. All P1 I/O lines 
 * source a single interrupt vector, and all P2 I/O lines source a different, 
 * single interrupt vector. 
 *
 * Each bit in each PxIN (READ-ONLY) register reflects the value of the input signal 
 * at the corresponding I/O pin. Each bit in each PxOUT register is the value to 
 * be output on the corresponding I/O pin (0: low, 1: high). Each bit in each 
 * PxDIR register selects the direction of the corresponding I/O pin (0: input
 * direction, 1: output). Each PxSEL bit is used to select the pin function - 
 * I/O port (0) or peripheral module function (1).
 */

/* TIMER_A, TIMER_B
 * - Interrupt vector register for fast decoding of all Timer_A interrupts
 * - The 16-bit timer/counter register, TAR, increments or decrements (depending
      on mode of operation) with each rising edge of the clock signal. The timer 
      can generate an interrupt when it overflows. TAR may be cleared by setting 
      the TACLR bit. 
 */

/*
 * MSP430 initial conditions after system reset:
 *
 * - [HW] The RST/NMI pin is configured in the reset mode. 
 * - [SW] I/O pins are switched to input mode as described in the Digital I/O chapter. 
 * - [SW] Other peripheral modules and registers are initialized as described in their 
 *   respective chapters in this manual. 
 * - [HW] Status register (SR) is reset. 
 * - [HW] The watchdog timer powers up active in watchdog mode. 
 * - [HW] Program counter (PC) is loaded with address contained at reset vector 
 *   location (0FFFEh). CPU execution begins at that address. 
 *
 * After a system reset, user software must initialize the MSP430 for the 
 * application requirements. The following must occur: 
 * - [HW] Initialize the SP, typically to the top of RAM. 
 * - [HW] Initialize the watchdog to the requirements of the application. 
 * - [SW] Configure peripheral modules to the requirements of the application. 
 *
 */
void set_initial_configuration()
{
  /* I/O ports are initialized in MotePlatformC_Init_init() -- nothing to do */

  /* SR doesn't show up in software; GIE does, as __asm("dint"/"eint") */
  /* reset GIE */

  /* all other initializations seem irrelevant to the software */
}


//#include "msp430_hw.h"
//#include "lib/libc_string.h"
#include <pthread.h>

//int test; // Lihao

extern nondet_bv();

//typedef int ptrdiff_t; // Lihao

typedef int unsigned size_t; // Lihao

//typedef int wchar_t; // Lihao

struct __nesc_attr_nonnull ;

struct __nesc_attr_bnd {
  void *lo;
  void *hi;
};

struct __nesc_attr_bnd_nok {
  void *lo;
  void *hi;
};

struct __nesc_attr_count {
  int n;
};

struct __nesc_attr_count_nok {
  int n;
};

struct __nesc_attr_one ;

struct __nesc_attr_one_nok ;

struct __nesc_attr_dmemset {
  int a1;
  int a2;
  int a3;
};

struct __nesc_attr_dmemcpy {
  int a1;
  int a2;
  int a3;
};

struct __nesc_attr_nts ;

typedef char signed int8_t;

typedef char unsigned uint8_t;

/* Lihao
typedef int int16_t;

typedef int unsigned uint16_t;

typedef long int32_t;

typedef long unsigned uint32_t;

typedef long long int64_t;

typedef long long unsigned uint64_t;

typedef int16_t intptr_t;

typedef uint16_t uintptr_t;
*/

typedef struct {
  char unsigned (data[1]);
} __attribute((packed)) nx_int8_t;

typedef int8_t __nesc_nxbase_nx_int8_t;

typedef struct {
  char unsigned (data[2]);
} __attribute((packed)) nx_int16_t;

typedef int16_t __nesc_nxbase_nx_int16_t;

typedef struct {
  char unsigned (data[4]);
} __attribute((packed)) nx_int32_t;

typedef int32_t __nesc_nxbase_nx_int32_t;

typedef struct {
  char unsigned (data[8]);
} __attribute((packed)) nx_int64_t;

typedef int64_t __nesc_nxbase_nx_int64_t;

typedef struct {
  char unsigned (data[1]);
} __attribute((packed)) nx_uint8_t;

typedef uint8_t __nesc_nxbase_nx_uint8_t;

typedef struct {
  char unsigned (data[2]);
} __attribute((packed)) nx_uint16_t;

typedef uint16_t __nesc_nxbase_nx_uint16_t;

typedef struct {
  char unsigned (data[4]);
} __attribute((packed)) nx_uint32_t;

typedef uint32_t __nesc_nxbase_nx_uint32_t;

typedef struct {
  char unsigned (data[8]);
} __attribute((packed)) nx_uint64_t;

typedef uint64_t __nesc_nxbase_nx_uint64_t;

typedef struct {
  char unsigned (data[1]);
} __attribute((packed)) nxle_int8_t;

typedef int8_t __nesc_nxbase_nxle_int8_t;

typedef struct {
  char unsigned (data[2]);
} __attribute((packed)) nxle_int16_t;

typedef int16_t __nesc_nxbase_nxle_int16_t;

typedef struct {
  char unsigned (data[4]);
} __attribute((packed)) nxle_int32_t;

typedef int32_t __nesc_nxbase_nxle_int32_t;

typedef struct {
  char unsigned (data[8]);
} __attribute((packed)) nxle_int64_t;

typedef int64_t __nesc_nxbase_nxle_int64_t;

typedef struct {
  char unsigned (data[1]);
} __attribute((packed)) nxle_uint8_t;

typedef uint8_t __nesc_nxbase_nxle_uint8_t;

typedef struct {
  char unsigned (data[2]);
} __attribute((packed)) nxle_uint16_t;

typedef uint16_t __nesc_nxbase_nxle_uint16_t;

typedef struct {
  char unsigned (data[4]);
} __attribute((packed)) nxle_uint32_t;

typedef uint32_t __nesc_nxbase_nxle_uint32_t;

typedef struct {
  char unsigned (data[8]);
} __attribute((packed)) nxle_uint64_t;

typedef uint64_t __nesc_nxbase_nxle_uint64_t;

typedef char unsigned u_char;

typedef short unsigned u_short;

typedef int unsigned u_int;

typedef long unsigned u_long;

typedef short unsigned ushort;

typedef int unsigned uint;

typedef uint8_t u_int8_t;

typedef uint16_t u_int16_t;

typedef uint32_t u_int32_t;

typedef uint64_t u_int64_t;

typedef u_int64_t u_quad_t;

typedef int64_t quad_t;

typedef quad_t *qaddr_t;

typedef char *caddr_t;

typedef const char *c_caddr_t;

typedef volatile char *v_caddr_t;

typedef u_int32_t fixpt_t;

typedef u_int32_t gid_t;

typedef u_int32_t in_addr_t;

typedef u_int16_t in_port_t;

typedef u_int32_t ino_t;

typedef long key_t;

typedef u_int16_t mode_t;

typedef u_int16_t nlink_t;

typedef quad_t rlim_t;

typedef int32_t segsz_t;

typedef int32_t swblk_t;

typedef int32_t ufs_daddr_t;

typedef int32_t ufs_time_t;

typedef u_int32_t uid_t;

extern void *memset(void *arg_0x702690, int arg_0x7027e8, size_t arg_0x702980) ;

extern void *memset(void *arg_0x1045650, int arg_0x10457a8, size_t arg_0x1045940) ;

typedef struct __nesc_unnamed4242 {
  int quot;
  int rem;
} div_t;

typedef struct __nesc_unnamed4243 {
  long quot;
  long rem;
} ldiv_t;

typedef int long __int32_t; // Lihao

typedef int long unsigned __uint32_t; // Lihao

typedef long _off_t;

typedef long _ssize_t;

typedef __uint32_t __ULong;

struct _glue {
  struct _glue  *_next;
  int _niobs;
  struct __sFILE  *_iobs;
};

struct _Bigint {
  struct _Bigint  *_next;
  int _k;
  int _maxwds;
  int _sign;
  int _wds;
  __ULong (_x[1]);
};

struct __tm {
  int __tm_sec;
  int __tm_min;
  int __tm_hour;
  int __tm_mday;
  int __tm_mon;
  int __tm_year;
  int __tm_wday;
  int __tm_yday;
  int __tm_isdst;
};

struct _atexit {
  struct _atexit  *_next;
  int _ind;
  void (*_fns[32])( void ) ;
};

struct __sbuf {
  char unsigned *_base;
  int _size;
};

typedef long _fpos_t;

struct __sFILE {
  char unsigned *_p;
  int _r;
  int _w;
  short _flags;
  short _file;
  struct __sbuf  _bf;
  int _lbfsize;
  void *_cookie;
  int *_read(void *_cookie, char *_buf, int _n) ;
  int *_write(void *_cookie, const char *_buf, int _n) ;
  _fpos_t *_seek(void *_cookie, _fpos_t _offset, int _whence) ;
  int *_close(void *_cookie) ;
  struct __sbuf  _ub;
  char unsigned *_up;
  int _ur;
  char unsigned (_ubuf[3]);
  char unsigned (_nbuf[1]);
  struct __sbuf  _lb;
  int _blksize;
  int _offset;
  struct _reent  *_data;
};

struct _rand48 {
  short unsigned (_seed[3]);
  short unsigned (_mult[3]);
  short unsigned _add;
};

struct _reent {
  int _errno;
  struct __sFILE  *_stdin;
  struct __sFILE  *_stdout;
  struct __sFILE  *_stderr;
  int _inc;
  char (_emergency[25]);
  int _current_category;
  const char *_current_locale;
  int __sdidinit;
  void *__cleanup(struct _reent  *arg_0x1073ab8) ;
  struct _Bigint  *_result;
  int _result_k;
  struct _Bigint  *_p5s;
  struct _Bigint  *_freelist;
  int _cvtlen;
  char *_cvtbuf;
  union __nesc_unnamed4244  {
  struct __nesc_unnamed4245 {
  int unsigned _unused_rand;
  char *_strtok_last;
  char (_asctime_buf[26]);
  struct __tm  _localtime_buf;
  int _gamma_signgam;
  __extension__ long long unsigned _rand_next;
  struct _rand48  _r48;
} _reent;
  struct __nesc_unnamed4246 {
  char unsigned (*_nextf[30]);
  int unsigned (_nmalloc[30]);
} _unused;
} _new;
  struct _atexit  *_atexit;
  struct _atexit  _atexit0;
  void *_sig_func(int arg_0x1077c98) ;
  struct _glue  __sglue;
  struct __sFILE  (__sf[3]);
};

struct _reent ;

union __dmath  {
  __uint32_t (i[2]);
  double d;
};

union __dmath ;

struct exception {
  int type;
  char *name;
  double arg1;
  double arg2;
  double retval;
  int err;
};

enum __fdlibm_version { __fdlibm_ieee = -1, __fdlibm_svid, __fdlibm_xopen, __fdlibm_posix };

enum __fdlibm_version;

typedef uint8_t bool;

enum __nesc_unnamed4247 { FALSE = 0, TRUE = 1 };

typedef nx_int8_t nx_bool;

struct __nesc_attr_atmostonce ;

struct __nesc_attr_atleastonce ;

struct __nesc_attr_exactlyonce ;

enum __nesc_unnamed4248 { SUCCESS = 0, FAIL = 1, ESIZE = 2, ECANCEL = 3, EOFF = 4, EBUSY = 5, EINVAL = 6, ERETRY = 7, ERESERVE = 8, EALREADY = 9, ENOMEM = 10, ENOACK = 11, ELAST = 11 };

typedef uint8_t error_t;

typedef union port  {
  volatile char unsigned reg_p;
  volatile struct __nesc_unnamed4249 {
  unsigned char __p0 :1;
  char unsigned __p1 :1;
  unsigned char __p2 :1;
  char unsigned __p3 :1;
  unsigned char __p4 :1;
  char unsigned __p5 :1;
  unsigned char __p6 :1;
  char unsigned __p7 :1;
} __pin;
} ioregister_t;

struct port_full_t {
  ioregister_t in;
  ioregister_t out;
  ioregister_t dir;
  ioregister_t ifg;
  ioregister_t ies;
  ioregister_t ie;
  ioregister_t sel;
};

struct port_simple_t {
  ioregister_t in;
  ioregister_t out;
  ioregister_t dir;
  ioregister_t sel;
};

struct port_full_t ;

struct port_full_t ;

struct port_simple_t ;

struct port_simple_t ;

struct port_simple_t ;

struct port_simple_t ;

typedef struct __nesc_unnamed4250 {
  volatile unsigned taifg :1;
  volatile unsigned taie :1;
  volatile unsigned taclr :1;
  volatile unsigned dummy :1;
  volatile unsigned tamc :2;
  volatile unsigned taid :2;
  volatile unsigned tassel :2;
} __attribute((packed)) tactl_t;

typedef struct __nesc_unnamed4251 {
  volatile unsigned ccifg :1;
  volatile unsigned cov :1;
  volatile unsigned out :1;
  volatile unsigned cci :1;
  volatile unsigned ccie :1;
  volatile unsigned outmod :3;
  volatile unsigned cap :1;
  volatile unsigned dummy :1;
  volatile unsigned scci :1;
  volatile unsigned scs :1;
  volatile unsigned ccis :2;
  volatile unsigned cm :2;
} __attribute((packed)) tacctl_t;

struct timera_t {
  tactl_t ctl;
  tacctl_t cctl0;
  tacctl_t cctl1;
  tacctl_t cctl2;
  volatile unsigned (dummy[4]);
  volatile unsigned tar;
  volatile unsigned taccr0;
  volatile unsigned taccr1;
  volatile unsigned taccr2;
};

struct timera_t ;

typedef struct __nesc_unnamed4252 {
  volatile unsigned tbifg :1;
  volatile unsigned tbie :1;
  volatile unsigned tbclr :1;
  volatile unsigned dummy1 :1;
  volatile unsigned tbmc :2;
  volatile unsigned tbid :2;
  volatile unsigned tbssel :2;
  volatile unsigned dummy2 :1;
  volatile unsigned tbcntl :2;
  volatile unsigned tbclgrp :2;
} __attribute((packed)) tbctl_t;

typedef struct __nesc_unnamed4253 {
  volatile unsigned ccifg :1;
  volatile unsigned cov :1;
  volatile unsigned out :1;
  volatile unsigned cci :1;
  volatile unsigned ccie :1;
  volatile unsigned outmod :3;
  volatile unsigned cap :1;
  volatile unsigned clld :2;
  volatile unsigned scs :1;
  volatile unsigned ccis :2;
  volatile unsigned cm :2;
} __attribute((packed)) tbcctl_t;

struct timerb_t {
  tbctl_t ctl;
  tbcctl_t cctl0;
  tbcctl_t cctl1;
  tbcctl_t cctl2;
  tbcctl_t cctl3;
  tbcctl_t cctl4;
  tbcctl_t cctl5;
  tbcctl_t cctl6;
  volatile unsigned tbr;
  volatile unsigned tbccr0;
  volatile unsigned tbccr1;
  volatile unsigned tbccr2;
  volatile unsigned tbccr3;
  volatile unsigned tbccr4;
  volatile unsigned tbccr5;
  volatile unsigned tbccr6;
};

struct timerb_t ;

typedef struct __nesc_unnamed4254 {
  volatile unsigned adc12sc :1;
  volatile unsigned enc :1;
  volatile unsigned adc12tovie :1;
  volatile unsigned adc12ovie :1;
  volatile unsigned adc12on :1;
  volatile unsigned refon :1;
  volatile unsigned r2_5v :1;
  volatile unsigned msc :1;
  volatile unsigned sht0 :4;
  volatile unsigned sht1 :4;
} __attribute((packed)) adc12ctl0_t;

typedef struct __nesc_unnamed4255 {
  volatile unsigned adc12busy :1;
  volatile unsigned conseq :2;
  volatile unsigned adc12ssel :2;
  volatile unsigned adc12div :3;
  volatile unsigned issh :1;
  volatile unsigned shp :1;
  volatile unsigned shs :2;
  volatile unsigned cstartadd :4;
} __attribute((packed)) adc12ctl1_t;

typedef struct __nesc_unnamed4256 {
  volatile unsigned bit0 :1;
  volatile unsigned bit1 :1;
  volatile unsigned bit2 :1;
  volatile unsigned bit3 :1;
  volatile unsigned bit4 :1;
  volatile unsigned bit5 :1;
  volatile unsigned bit6 :1;
  volatile unsigned bit7 :1;
  volatile unsigned bit8 :1;
  volatile unsigned bit9 :1;
  volatile unsigned bit10 :1;
  volatile unsigned bit11 :1;
  volatile unsigned bit12 :1;
  volatile unsigned bit13 :1;
  volatile unsigned bit14 :1;
  volatile unsigned bit15 :1;
} __attribute((packed)) adc12xflg_t;

struct adc12_t {
  adc12ctl0_t ctl0;
  adc12ctl1_t ctl1;
  adc12xflg_t ifg;
  adc12xflg_t ie;
  adc12xflg_t iv;
};

struct adc12_t ;

typedef uint8_t mcu_power_t;

inline static mcu_power_t mcombine(mcu_power_t m1, mcu_power_t m2) ;

enum __nesc_unnamed4257 { MSP430_POWER_ACTIVE = 0, MSP430_POWER_LPM0 = 1, MSP430_POWER_LPM1 = 2, MSP430_POWER_LPM2 = 3, MSP430_POWER_LPM3 = 4, MSP430_POWER_LPM4 = 5 };

inline static void __nesc_disable_interrupt( void ) ;

inline static void __nesc_enable_interrupt( void ) ;

typedef bool __nesc_atomic_t;

__nesc_atomic_t __nesc_atomic_start( void ) ;

void __nesc_atomic_end(__nesc_atomic_t reenable_interrupts) ;

__nesc_atomic_t __nesc_atomic_start( void ) ;

void __nesc_atomic_end(__nesc_atomic_t reenable_interrupts) ;

typedef struct {
  char unsigned (data[4]);
} __attribute((packed)) nx_float;

typedef float __nesc_nxbase_nx_float;

inline static void TOSH_SET_SIMO0_PIN() ;

inline static void TOSH_CLR_SIMO0_PIN() ;

inline static void TOSH_MAKE_SIMO0_OUTPUT() ;

inline static void TOSH_SET_UCLK0_PIN() ;

inline static void TOSH_CLR_UCLK0_PIN() ;

inline static void TOSH_MAKE_UCLK0_OUTPUT() ;

enum __nesc_unnamed4258 { TOSH_HUMIDITY_ADDR = 5, TOSH_HUMIDTEMP_ADDR = 3, TOSH_HUMIDITY_RESET = 0x1E };

inline static void TOSH_SET_FLASH_CS_PIN() ;

inline static void TOSH_CLR_FLASH_CS_PIN() ;

inline static void TOSH_MAKE_FLASH_CS_OUTPUT() ;

inline static void TOSH_SET_FLASH_HOLD_PIN() ;

inline static void TOSH_MAKE_FLASH_HOLD_OUTPUT() ;

enum __nesc_unnamed4259 { MSP430TIMER_CM_NONE = 0, MSP430TIMER_CM_RISING = 1, MSP430TIMER_CM_FALLING = 2, MSP430TIMER_CM_BOTH = 3, MSP430TIMER_STOP_MODE = 0, MSP430TIMER_UP_MODE = 1, MSP430TIMER_CONTINUOUS_MODE = 2, MSP430TIMER_UPDOWN_MODE = 3, MSP430TIMER_TACLK = 0, MSP430TIMER_TBCLK = 0, MSP430TIMER_ACLK = 1, MSP430TIMER_SMCLK = 2, MSP430TIMER_INCLK = 3, MSP430TIMER_CLOCKDIV_1 = 0, MSP430TIMER_CLOCKDIV_2 = 1, MSP430TIMER_CLOCKDIV_4 = 2, MSP430TIMER_CLOCKDIV_8 = 3 };

typedef struct __nesc_unnamed4260 {
  int ccifg :1;
  int cov :1;
  int out :1;
  int cci :1;
  int ccie :1;
  int outmod :3;
  int cap :1;
  int clld :2;
  int scs :1;
  int ccis :2;
  int cm :2;
} msp430_compare_control_t;

typedef struct __nesc_unnamed4261 {
  int taifg :1;
  int taie :1;
  int taclr :1;
  int _unused0 :1;
  int mc :2;
  int id :2;
  int tassel :2;
  int _unused1 :6;
} msp430_timer_a_control_t;

typedef struct __nesc_unnamed4262 {
  int tbifg :1;
  int tbie :1;
  int tbclr :1;
  int _unused0 :1;
  int mc :2;
  int id :2;
  int tbssel :2;
  int _unused1 :1;
  int cntl :2;
  int tbclgrp :2;
  int _unused2 :1;
} msp430_timer_b_control_t;

typedef struct __nesc_unnamed4263 {
  int notUsed;
} TMilli;

typedef struct __nesc_unnamed4264 {
  int notUsed;
} T32khz;

typedef struct __nesc_unnamed4265 {
  int notUsed;
} TMicro;

enum __nesc_unnamed4266 { LEDS_LED0 = 1 << 0, LEDS_LED1 = 1 << 1, LEDS_LED2 = 1 << 2, LEDS_LED3 = 1 << 3, LEDS_LED4 = 1 << 4, LEDS_LED5 = 1 << 5, LEDS_LED6 = 1 << 6, LEDS_LED7 = 1 << 7 };

typedef TMilli BlinkC_Timer0_precision_tag;

typedef TMilli BlinkC_Timer1_precision_tag;

typedef TMilli BlinkC_Timer2_precision_tag;

enum Msp430Timer32khzC_0___nesc_unnamed4267 { Msp430Timer32khzC_0_ALARM_ID = 0U };

typedef T32khz Msp430AlarmC_0_frequency_tag;

typedef Msp430AlarmC_0_frequency_tag Msp430AlarmC_0_Alarm_precision_tag;

typedef uint16_t Msp430AlarmC_0_Alarm_size_type;

typedef T32khz Msp430CounterC_0_frequency_tag;

typedef Msp430CounterC_0_frequency_tag Msp430CounterC_0_Counter_precision_tag;

typedef uint16_t Msp430CounterC_0_Counter_size_type;

typedef TMilli TransformCounterC_0_to_precision_tag;

typedef uint32_t TransformCounterC_0_to_size_type;

typedef T32khz TransformCounterC_0_from_precision_tag;

typedef uint16_t TransformCounterC_0_from_size_type;

typedef uint32_t TransformCounterC_0_upper_count_type;

typedef TransformCounterC_0_from_precision_tag TransformCounterC_0_CounterFrom_precision_tag;

typedef TransformCounterC_0_from_size_type TransformCounterC_0_CounterFrom_size_type;

typedef TransformCounterC_0_to_precision_tag TransformCounterC_0_Counter_precision_tag;

typedef TransformCounterC_0_to_size_type TransformCounterC_0_Counter_size_type;

typedef TMilli TransformAlarmC_0_to_precision_tag;

typedef uint32_t TransformAlarmC_0_to_size_type;

typedef T32khz TransformAlarmC_0_from_precision_tag;

typedef uint16_t TransformAlarmC_0_from_size_type;

typedef TransformAlarmC_0_to_precision_tag TransformAlarmC_0_Alarm_precision_tag;

typedef TransformAlarmC_0_to_size_type TransformAlarmC_0_Alarm_size_type;

typedef TransformAlarmC_0_from_precision_tag TransformAlarmC_0_AlarmFrom_precision_tag;

typedef TransformAlarmC_0_from_size_type TransformAlarmC_0_AlarmFrom_size_type;

typedef TransformAlarmC_0_to_precision_tag TransformAlarmC_0_Counter_precision_tag;

typedef TransformAlarmC_0_to_size_type TransformAlarmC_0_Counter_size_type;

typedef TMilli AlarmToTimerC_0_precision_tag;

typedef AlarmToTimerC_0_precision_tag AlarmToTimerC_0_Alarm_precision_tag;

typedef uint32_t AlarmToTimerC_0_Alarm_size_type;

typedef AlarmToTimerC_0_precision_tag AlarmToTimerC_0_Timer_precision_tag;

typedef TMilli VirtualizeTimerC_0_precision_tag;

typedef VirtualizeTimerC_0_precision_tag VirtualizeTimerC_0_TimerFrom_precision_tag;

typedef VirtualizeTimerC_0_precision_tag VirtualizeTimerC_0_Timer_precision_tag;

typedef TMilli CounterToLocalTimeC_0_precision_tag;

typedef CounterToLocalTimeC_0_precision_tag CounterToLocalTimeC_0_LocalTime_precision_tag;

typedef CounterToLocalTimeC_0_precision_tag CounterToLocalTimeC_0_Counter_precision_tag;

typedef uint32_t CounterToLocalTimeC_0_Counter_size_type;

static error_t PlatformP_Init_init( void ) ;

static error_t MotePlatformC_Init_init( void ) ;

static void Msp430ClockP_Msp430ClockInit_defaultInitClocks( void ) ;

static void Msp430ClockP_Msp430ClockInit_default_initTimerB( void ) ;

static void Msp430ClockP_Msp430ClockInit_defaultInitTimerA( void ) ;

static void Msp430ClockP_Msp430ClockInit_default_initTimerA( void ) ;

static void Msp430ClockP_Msp430ClockInit_defaultInitTimerB( void ) ;

static void Msp430ClockP_Msp430ClockInit_default_initClocks( void ) ;

static error_t Msp430ClockP_Init_init( void ) ;

static void Msp430TimerP_1_VectorTimerX0_fired( void ) ;

static void Msp430TimerP_1_Overflow_fired( void ) ;

static void Msp430TimerP_1_Event_default_fired(uint8_t arg_0x1561800) ;

static uint16_t Msp430TimerP_1_Timer_get( void ) ;

static bool Msp430TimerP_1_Timer_isOverflowPending( void ) ;

static uint16_t Msp430TimerCapComP_3_Capture_getEvent( void ) ;

static void Msp430TimerCapComP_3_Capture_default_captured(uint16_t time) ;

static msp430_compare_control_t Msp430TimerCapComP_3_Control_getControl( void ) ;

static void Msp430TimerCapComP_3_Control_enableEvents( void ) ;

static void Msp430TimerCapComP_3_Control_setControlAsCompare( void ) ;

static void Msp430TimerCapComP_3_Control_disableEvents( void ) ;

static void Msp430TimerCapComP_3_Control_clearPendingInterrupt( void ) ;

static void Msp430TimerCapComP_3_Event_fired( void ) ;

static void Msp430TimerCapComP_3_Compare_setEvent(uint16_t time) ;

static void Msp430TimerCapComP_3_Compare_setEventFromNow(uint16_t delta) ;

static void Msp430TimerCapComP_3_Timer_overflow( void ) ;

static uint16_t Msp430TimerCapComP_4_Capture_getEvent( void ) ;

static void Msp430TimerCapComP_4_Capture_default_captured(uint16_t time) ;

static msp430_compare_control_t Msp430TimerCapComP_4_Control_getControl( void ) ;

static void Msp430TimerCapComP_4_Event_fired( void ) ;

static void Msp430TimerCapComP_4_Compare_default_fired( void ) ;

static void Msp430TimerCapComP_4_Timer_overflow( void ) ;

static uint16_t Msp430TimerCapComP_5_Capture_getEvent( void ) ;

static void Msp430TimerCapComP_5_Capture_default_captured(uint16_t time) ;

static msp430_compare_control_t Msp430TimerCapComP_5_Control_getControl( void ) ;

static void Msp430TimerCapComP_5_Event_fired( void ) ;

static void Msp430TimerCapComP_5_Compare_default_fired( void ) ;

static void Msp430TimerCapComP_5_Timer_overflow( void ) ;

static uint16_t Msp430TimerCapComP_6_Capture_getEvent( void ) ;

static void Msp430TimerCapComP_6_Capture_default_captured(uint16_t time) ;

static msp430_compare_control_t Msp430TimerCapComP_6_Control_getControl( void ) ;

static void Msp430TimerCapComP_6_Event_fired( void ) ;

static void Msp430TimerCapComP_6_Compare_default_fired( void ) ;

static void Msp430TimerCapComP_6_Timer_overflow( void ) ;

static uint16_t Msp430TimerCapComP_7_Capture_getEvent( void ) ;

static void Msp430TimerCapComP_7_Capture_default_captured(uint16_t time) ;

static msp430_compare_control_t Msp430TimerCapComP_7_Control_getControl( void ) ;

static void Msp430TimerCapComP_7_Event_fired( void ) ;

static void Msp430TimerCapComP_7_Compare_default_fired( void ) ;

static void Msp430TimerCapComP_7_Timer_overflow( void ) ;

static uint16_t Msp430TimerCapComP_8_Capture_getEvent( void ) ;

static void Msp430TimerCapComP_8_Capture_default_captured(uint16_t time) ;

static msp430_compare_control_t Msp430TimerCapComP_8_Control_getControl( void ) ;

static void Msp430TimerCapComP_8_Event_fired( void ) ;

static void Msp430TimerCapComP_8_Compare_default_fired( void ) ;

static void Msp430TimerCapComP_8_Timer_overflow( void ) ;

static uint16_t Msp430TimerCapComP_9_Capture_getEvent( void ) ;

static void Msp430TimerCapComP_9_Capture_default_captured(uint16_t time) ;

static msp430_compare_control_t Msp430TimerCapComP_9_Control_getControl( void ) ;

static void Msp430TimerCapComP_9_Event_fired( void ) ;

static void Msp430TimerCapComP_9_Compare_default_fired( void ) ;

static void Msp430TimerCapComP_9_Timer_overflow( void ) ;

static error_t SchedulerBasicP_TaskBasic_postTask(uint8_t arg_0x147bb38) ;

static void SchedulerBasicP_TaskBasic_default_runTask(uint8_t arg_0x147bb38) ;

static void SchedulerBasicP_Scheduler_init( void ) ;

static void SchedulerBasicP_Scheduler_taskLoop( void ) ;

static bool SchedulerBasicP_Scheduler_runNextTask( void ) ;

static mcu_power_t McuSleepC_McuPowerOverride_default_lowestState( void ) ;

static void McuSleepC_McuSleep_sleep( void ) ;

static void BlinkC_Timer0_fired( void ) ;

static void BlinkC_Boot_booted( void ) ;

static void BlinkC_Timer1_fired( void ) ;

static void BlinkC_Timer2_fired( void ) ;

static error_t LedsP_Init_init( void ) ;

static void LedsP_Leds_led0Toggle( void ) ;

static void LedsP_Leds_led1Toggle( void ) ;

static void LedsP_Leds_led2Toggle( void ) ;

static void HplMsp430GeneralIOP_36_IO_toggle( void ) ;

static void HplMsp430GeneralIOP_36_IO_makeOutput( void ) ;

static void HplMsp430GeneralIOP_36_IO_set( void ) ;

static void HplMsp430GeneralIOP_37_IO_toggle( void ) ;

static void HplMsp430GeneralIOP_37_IO_makeOutput( void ) ;

static void HplMsp430GeneralIOP_37_IO_set( void ) ;

static void HplMsp430GeneralIOP_38_IO_toggle( void ) ;

static void HplMsp430GeneralIOP_38_IO_makeOutput( void ) ;

static void HplMsp430GeneralIOP_38_IO_set( void ) ;

static void Msp430GpioC_0_GeneralIO_toggle( void ) ;

static void Msp430GpioC_0_GeneralIO_makeOutput( void ) ;

static void Msp430GpioC_0_GeneralIO_set( void ) ;

static void Msp430GpioC_1_GeneralIO_toggle( void ) ;

static void Msp430GpioC_1_GeneralIO_makeOutput( void ) ;

static void Msp430GpioC_1_GeneralIO_set( void ) ;

static void Msp430GpioC_2_GeneralIO_toggle( void ) ;

static void Msp430GpioC_2_GeneralIO_makeOutput( void ) ;

static void Msp430GpioC_2_GeneralIO_set( void ) ;

static void Msp430AlarmC_0_Msp430Compare_fired( void ) ;

static void Msp430AlarmC_0_Msp430Timer_overflow( void ) ;

static void Msp430AlarmC_0_Alarm_startAt(Msp430AlarmC_0_Alarm_size_type t0, Msp430AlarmC_0_Alarm_size_type dt) ;

static void Msp430AlarmC_0_Alarm_stop( void ) ;

static error_t Msp430AlarmC_0_Init_init( void ) ;

static void Msp430CounterC_0_Msp430Timer_overflow( void ) ;

static Msp430CounterC_0_Counter_size_type Msp430CounterC_0_Counter_get( void ) ;

static bool Msp430CounterC_0_Counter_isOverflowPending( void ) ;

static void TransformCounterC_0_CounterFrom_overflow( void ) ;

static TransformCounterC_0_Counter_size_type TransformCounterC_0_Counter_get( void ) ;

static TransformAlarmC_0_Alarm_size_type TransformAlarmC_0_Alarm_getNow( void ) ;

static void TransformAlarmC_0_Alarm_startAt(TransformAlarmC_0_Alarm_size_type t0, TransformAlarmC_0_Alarm_size_type dt) ;

static TransformAlarmC_0_Alarm_size_type TransformAlarmC_0_Alarm_getAlarm( void ) ;

static void TransformAlarmC_0_Alarm_stop( void ) ;

static void TransformAlarmC_0_AlarmFrom_fired( void ) ;

static void TransformAlarmC_0_Counter_overflow( void ) ;

static void AlarmToTimerC_0_fired_runTask( void ) ;

static void AlarmToTimerC_0_Alarm_fired( void ) ;

static uint32_t AlarmToTimerC_0_Timer_getNow( void ) ;

static void AlarmToTimerC_0_Timer_startOneShotAt(uint32_t t0, uint32_t dt) ;

static void AlarmToTimerC_0_Timer_stop( void ) ;

static void VirtualizeTimerC_0_updateFromTimer_runTask( void ) ;

static void VirtualizeTimerC_0_TimerFrom_fired( void ) ;

static void VirtualizeTimerC_0_Timer_default_fired(uint8_t arg_0x18a3ea0) ;

static void VirtualizeTimerC_0_Timer_startPeriodic(uint8_t arg_0x18a3ea0, uint32_t dt) ;

static void CounterToLocalTimeC_0_Counter_overflow( void ) ;

static error_t PlatformP_MoteInit_init( void ) ;

static error_t PlatformP_MoteClockInit_init( void ) ;

static error_t PlatformP_LedsInit_init( void ) ;

inline static error_t PlatformP_Init_init( void ) ;

__inline static void MotePlatformC_TOSH_wait( void ) ;

static void MotePlatformC_TOSH_FLASH_M25P_DP_bit(bool set) ;

inline static void MotePlatformC_TOSH_FLASH_M25P_DP( void ) ;

inline static error_t MotePlatformC_Init_init( void ) ;

static void Msp430ClockP_Msp430ClockInit_initTimerB( void ) ;

static void Msp430ClockP_Msp430ClockInit_initTimerA( void ) ;

static void Msp430ClockP_Msp430ClockInit_initClocks( void ) ;

enum Msp430ClockP___nesc_unnamed4268 { Msp430ClockP_ACLK_CALIB_PERIOD = 8, Msp430ClockP_TARGET_DCO_DELTA = (4096 / 32) * Msp430ClockP_ACLK_CALIB_PERIOD };

inline static void Msp430ClockP_Msp430ClockInit_defaultInitClocks( void ) ;

inline static void Msp430ClockP_Msp430ClockInit_defaultInitTimerA( void ) ;

inline static void Msp430ClockP_Msp430ClockInit_defaultInitTimerB( void ) ;

inline static void Msp430ClockP_Msp430ClockInit_default_initClocks( void ) ;

inline static void Msp430ClockP_Msp430ClockInit_default_initTimerA( void ) ;

inline static void Msp430ClockP_Msp430ClockInit_default_initTimerB( void ) ;

inline static void Msp430ClockP_startTimerA( void ) ;

inline static void Msp430ClockP_startTimerB( void ) ;

inline static error_t Msp430ClockP_Init_init( void ) ;

static void Msp430TimerP_1_Event_fired(uint8_t arg_0x1561800) ;

static void Msp430TimerP_1_Timer_overflow( void ) ;

static uint16_t Msp430TimerP_1_Timer_get( void ) ;

inline static bool Msp430TimerP_1_Timer_isOverflowPending( void ) ;

inline static void Msp430TimerP_1_VectorTimerX0_fired( void ) ;

inline static void Msp430TimerP_1_Overflow_fired( void ) ;

static void Msp430TimerP_1_Event_default_fired(uint8_t n) ;

typedef msp430_compare_control_t Msp430TimerCapComP_0_cc_t;

typedef msp430_compare_control_t Msp430TimerCapComP_1_cc_t;

typedef msp430_compare_control_t Msp430TimerCapComP_2_cc_t;

static void Msp430TimerCapComP_3_Capture_captured(uint16_t time) ;

static void Msp430TimerCapComP_3_Compare_fired( void ) ;

static uint16_t Msp430TimerCapComP_3_Timer_get( void ) ;

typedef msp430_compare_control_t Msp430TimerCapComP_3_cc_t;

inline static uint16_t Msp430TimerCapComP_3_CC2int(Msp430TimerCapComP_3_cc_t x) ;

inline static Msp430TimerCapComP_3_cc_t Msp430TimerCapComP_3_int2CC(uint16_t x) ;

inline static uint16_t Msp430TimerCapComP_3_compareControl( void ) ;

inline static Msp430TimerCapComP_3_cc_t Msp430TimerCapComP_3_Control_getControl( void ) ;

inline static void Msp430TimerCapComP_3_Control_clearPendingInterrupt( void ) ;

inline static void Msp430TimerCapComP_3_Control_setControlAsCompare( void ) ;

inline static void Msp430TimerCapComP_3_Control_enableEvents( void ) ;

inline static void Msp430TimerCapComP_3_Control_disableEvents( void ) ;

inline static uint16_t Msp430TimerCapComP_3_Capture_getEvent( void ) ;

inline static void Msp430TimerCapComP_3_Compare_setEvent(uint16_t x) ;

inline static void Msp430TimerCapComP_3_Compare_setEventFromNow(uint16_t x) ;

inline static void Msp430TimerCapComP_3_Event_fired( void ) ;

inline static void Msp430TimerCapComP_3_Capture_default_captured(uint16_t n) ;

inline static void Msp430TimerCapComP_3_Timer_overflow( void ) ;

static void Msp430TimerCapComP_4_Capture_captured(uint16_t time) ;

static void Msp430TimerCapComP_4_Compare_fired( void ) ;

typedef msp430_compare_control_t Msp430TimerCapComP_4_cc_t;

inline static Msp430TimerCapComP_4_cc_t Msp430TimerCapComP_4_int2CC(uint16_t x) ;

inline static Msp430TimerCapComP_4_cc_t Msp430TimerCapComP_4_Control_getControl( void ) ;

inline static uint16_t Msp430TimerCapComP_4_Capture_getEvent( void ) ;

inline static void Msp430TimerCapComP_4_Event_fired( void ) ;

inline static void Msp430TimerCapComP_4_Capture_default_captured(uint16_t n) ;

inline static void Msp430TimerCapComP_4_Compare_default_fired( void ) ;

inline static void Msp430TimerCapComP_4_Timer_overflow( void ) ;

static void Msp430TimerCapComP_5_Capture_captured(uint16_t time) ;

static void Msp430TimerCapComP_5_Compare_fired( void ) ;

typedef msp430_compare_control_t Msp430TimerCapComP_5_cc_t;

inline static Msp430TimerCapComP_5_cc_t Msp430TimerCapComP_5_int2CC(uint16_t x) ;

inline static Msp430TimerCapComP_5_cc_t Msp430TimerCapComP_5_Control_getControl( void ) ;

inline static uint16_t Msp430TimerCapComP_5_Capture_getEvent( void ) ;

inline static void Msp430TimerCapComP_5_Event_fired( void ) ;

inline static void Msp430TimerCapComP_5_Capture_default_captured(uint16_t n) ;

inline static void Msp430TimerCapComP_5_Compare_default_fired( void ) ;

inline static void Msp430TimerCapComP_5_Timer_overflow( void ) ;

static void Msp430TimerCapComP_6_Capture_captured(uint16_t time) ;

static void Msp430TimerCapComP_6_Compare_fired( void ) ;

typedef msp430_compare_control_t Msp430TimerCapComP_6_cc_t;

inline static Msp430TimerCapComP_6_cc_t Msp430TimerCapComP_6_int2CC(uint16_t x) ;

inline static Msp430TimerCapComP_6_cc_t Msp430TimerCapComP_6_Control_getControl( void ) ;

inline static uint16_t Msp430TimerCapComP_6_Capture_getEvent( void ) ;

inline static void Msp430TimerCapComP_6_Event_fired( void ) ;

inline static void Msp430TimerCapComP_6_Capture_default_captured(uint16_t n) ;

inline static void Msp430TimerCapComP_6_Compare_default_fired( void ) ;

inline static void Msp430TimerCapComP_6_Timer_overflow( void ) ;

static void Msp430TimerCapComP_7_Capture_captured(uint16_t time) ;

static void Msp430TimerCapComP_7_Compare_fired( void ) ;

typedef msp430_compare_control_t Msp430TimerCapComP_7_cc_t;

inline static Msp430TimerCapComP_7_cc_t Msp430TimerCapComP_7_int2CC(uint16_t x) ;

inline static Msp430TimerCapComP_7_cc_t Msp430TimerCapComP_7_Control_getControl( void ) ;

inline static uint16_t Msp430TimerCapComP_7_Capture_getEvent( void ) ;

inline static void Msp430TimerCapComP_7_Event_fired( void ) ;

inline static void Msp430TimerCapComP_7_Capture_default_captured(uint16_t n) ;

inline static void Msp430TimerCapComP_7_Compare_default_fired( void ) ;

inline static void Msp430TimerCapComP_7_Timer_overflow( void ) ;

static void Msp430TimerCapComP_8_Capture_captured(uint16_t time) ;

static void Msp430TimerCapComP_8_Compare_fired( void ) ;

typedef msp430_compare_control_t Msp430TimerCapComP_8_cc_t;

inline static Msp430TimerCapComP_8_cc_t Msp430TimerCapComP_8_int2CC(uint16_t x) ;

inline static Msp430TimerCapComP_8_cc_t Msp430TimerCapComP_8_Control_getControl( void ) ;

inline static uint16_t Msp430TimerCapComP_8_Capture_getEvent( void ) ;

inline static void Msp430TimerCapComP_8_Event_fired( void ) ;

inline static void Msp430TimerCapComP_8_Capture_default_captured(uint16_t n) ;

inline static void Msp430TimerCapComP_8_Compare_default_fired( void ) ;

inline static void Msp430TimerCapComP_8_Timer_overflow( void ) ;

static void Msp430TimerCapComP_9_Capture_captured(uint16_t time) ;

static void Msp430TimerCapComP_9_Compare_fired( void ) ;

typedef msp430_compare_control_t Msp430TimerCapComP_9_cc_t;

inline static Msp430TimerCapComP_9_cc_t Msp430TimerCapComP_9_int2CC(uint16_t x) ;

inline static Msp430TimerCapComP_9_cc_t Msp430TimerCapComP_9_Control_getControl( void ) ;

inline static uint16_t Msp430TimerCapComP_9_Capture_getEvent( void ) ;

inline static void Msp430TimerCapComP_9_Event_fired( void ) ;

inline static void Msp430TimerCapComP_9_Capture_default_captured(uint16_t n) ;

inline static void Msp430TimerCapComP_9_Compare_default_fired( void ) ;

inline static void Msp430TimerCapComP_9_Timer_overflow( void ) ;

static void Msp430TimerCommonP_VectorTimerB0_fired( void ) ;

void sig_TIMERB0_VECTOR( void ) ;

static error_t RealMainP_SoftwareInit_init( void ) ;

static void RealMainP_Boot_booted( void ) ;

static error_t RealMainP_PlatformInit_init( void ) ;

static void RealMainP_Scheduler_init( void ) ;

static void RealMainP_Scheduler_taskLoop( void ) ;

static bool RealMainP_Scheduler_runNextTask( void ) ;

//int main( void ) ;
void main( void ) ; // Lihao

static void SchedulerBasicP_TaskBasic_runTask(uint8_t arg_0x147bb38) ;

static void SchedulerBasicP_McuSleep_sleep( void ) ;

enum SchedulerBasicP___nesc_unnamed4269 { SchedulerBasicP_NUM_TASKS = 2U, SchedulerBasicP_NO_TASK = 255 };

uint8_t SchedulerBasicP_m_head;

uint8_t SchedulerBasicP_m_tail;

uint8_t (SchedulerBasicP_m_next[SchedulerBasicP_NUM_TASKS]);

__inline static uint8_t SchedulerBasicP_popTask( void ) ;

inline static bool SchedulerBasicP_isWaiting(uint8_t id) ;

inline static bool SchedulerBasicP_pushTask(uint8_t id) ;

inline static void SchedulerBasicP_Scheduler_init( void ) ;

static bool SchedulerBasicP_Scheduler_runNextTask( void ) ;

inline static void SchedulerBasicP_Scheduler_taskLoop( void ) ;

static error_t SchedulerBasicP_TaskBasic_postTask(uint8_t id) ;

inline static void SchedulerBasicP_TaskBasic_default_runTask(uint8_t id) ;

static mcu_power_t McuSleepC_McuPowerOverride_lowestState( void ) ;

bool McuSleepC_dirty = TRUE;

mcu_power_t McuSleepC_powerState = MSP430_POWER_ACTIVE;

const uint16_t (McuSleepC_msp430PowerBits[MSP430_POWER_LPM4 + 1]) = {0, 0x0010, 0x0040 + 0x0010, 0x0080 + 0x0010, (0x0080 + 0x0040) + 0x0010, ((0x0080 + 0x0040) + 0x0020) + 0x0010};

inline static mcu_power_t McuSleepC_getPowerState( void ) ;

inline static void McuSleepC_computePowerState( void ) ;

inline static void McuSleepC_McuSleep_sleep( void ) ;

inline static mcu_power_t McuSleepC_McuPowerOverride_default_lowestState( void ) ;

static void BlinkC_Timer0_startPeriodic(uint32_t dt) ;

static void BlinkC_Timer1_startPeriodic(uint32_t dt) ;

static void BlinkC_Leds_led0Toggle( void ) ;

static void BlinkC_Leds_led1Toggle( void ) ;

static void BlinkC_Leds_led2Toggle( void ) ;

static void BlinkC_Timer2_startPeriodic(uint32_t dt) ;

inline static void BlinkC_Boot_booted( void ) ;

inline static void BlinkC_Timer0_fired( void ) ;

inline static void BlinkC_Timer1_fired( void ) ;

inline static void BlinkC_Timer2_fired( void ) ;

static void LedsP_Led0_toggle( void ) ;

static void LedsP_Led0_makeOutput( void ) ;

static void LedsP_Led0_set( void ) ;

static void LedsP_Led1_toggle( void ) ;

static void LedsP_Led1_makeOutput( void ) ;

static void LedsP_Led1_set( void ) ;

static void LedsP_Led2_toggle( void ) ;

static void LedsP_Led2_makeOutput( void ) ;

static void LedsP_Led2_set( void ) ;

inline static error_t LedsP_Init_init( void ) ;

inline static void LedsP_Leds_led0Toggle( void ) ;

inline static void LedsP_Leds_led1Toggle( void ) ;

inline static void LedsP_Leds_led2Toggle( void ) ;

inline static void HplMsp430GeneralIOP_36_IO_set( void ) ;

inline static void HplMsp430GeneralIOP_36_IO_toggle( void ) ;

inline static void HplMsp430GeneralIOP_36_IO_makeOutput( void ) ;

inline static void HplMsp430GeneralIOP_37_IO_set( void ) ;

inline static void HplMsp430GeneralIOP_37_IO_toggle( void ) ;

inline static void HplMsp430GeneralIOP_37_IO_makeOutput( void ) ;

inline static void HplMsp430GeneralIOP_38_IO_set( void ) ;

inline static void HplMsp430GeneralIOP_38_IO_toggle( void ) ;

inline static void HplMsp430GeneralIOP_38_IO_makeOutput( void ) ;

static void Msp430GpioC_0_HplGeneralIO_toggle( void ) ;

static void Msp430GpioC_0_HplGeneralIO_makeOutput( void ) ;

static void Msp430GpioC_0_HplGeneralIO_set( void ) ;

inline static void Msp430GpioC_0_GeneralIO_set( void ) ;

inline static void Msp430GpioC_0_GeneralIO_toggle( void ) ;

inline static void Msp430GpioC_0_GeneralIO_makeOutput( void ) ;

static void Msp430GpioC_1_HplGeneralIO_toggle( void ) ;

static void Msp430GpioC_1_HplGeneralIO_makeOutput( void ) ;

static void Msp430GpioC_1_HplGeneralIO_set( void ) ;

inline static void Msp430GpioC_1_GeneralIO_set( void ) ;

inline static void Msp430GpioC_1_GeneralIO_toggle( void ) ;

inline static void Msp430GpioC_1_GeneralIO_makeOutput( void ) ;

static void Msp430GpioC_2_HplGeneralIO_toggle( void ) ;

static void Msp430GpioC_2_HplGeneralIO_makeOutput( void ) ;

static void Msp430GpioC_2_HplGeneralIO_set( void ) ;

inline static void Msp430GpioC_2_GeneralIO_set( void ) ;

inline static void Msp430GpioC_2_GeneralIO_toggle( void ) ;

inline static void Msp430GpioC_2_GeneralIO_makeOutput( void ) ;

static void Msp430AlarmC_0_Msp430Compare_setEvent(uint16_t time) ;

static void Msp430AlarmC_0_Msp430Compare_setEventFromNow(uint16_t delta) ;

static uint16_t Msp430AlarmC_0_Msp430Timer_get( void ) ;

static void Msp430AlarmC_0_Alarm_fired( void ) ;

static void Msp430AlarmC_0_Msp430TimerControl_enableEvents( void ) ;

static void Msp430AlarmC_0_Msp430TimerControl_setControlAsCompare( void ) ;

static void Msp430AlarmC_0_Msp430TimerControl_disableEvents( void ) ;

static void Msp430AlarmC_0_Msp430TimerControl_clearPendingInterrupt( void ) ;

inline static error_t Msp430AlarmC_0_Init_init( void ) ;

inline static void Msp430AlarmC_0_Alarm_stop( void ) ;

inline static void Msp430AlarmC_0_Msp430Compare_fired( void ) ;

inline static void Msp430AlarmC_0_Alarm_startAt(uint16_t t0, uint16_t dt) ;

inline static void Msp430AlarmC_0_Msp430Timer_overflow( void ) ;

static uint16_t Msp430CounterC_0_Msp430Timer_get( void ) ;

static bool Msp430CounterC_0_Msp430Timer_isOverflowPending( void ) ;

static void Msp430CounterC_0_Counter_overflow( void ) ;

inline static uint16_t Msp430CounterC_0_Counter_get( void ) ;

inline static bool Msp430CounterC_0_Counter_isOverflowPending( void ) ;

inline static void Msp430CounterC_0_Msp430Timer_overflow( void ) ;

static TransformCounterC_0_CounterFrom_size_type TransformCounterC_0_CounterFrom_get( void ) ;

static bool TransformCounterC_0_CounterFrom_isOverflowPending( void ) ;

static void TransformCounterC_0_Counter_overflow( void ) ;

TransformCounterC_0_upper_count_type TransformCounterC_0_m_upper;

enum TransformCounterC_0___nesc_unnamed4270 { TransformCounterC_0_LOW_SHIFT_RIGHT = 5, TransformCounterC_0_HIGH_SHIFT_LEFT = (8 * sizeof( TransformCounterC_0_from_size_type )) - TransformCounterC_0_LOW_SHIFT_RIGHT, TransformCounterC_0_NUM_UPPER_BITS = ((8 * sizeof( TransformCounterC_0_to_size_type )) - (8 * sizeof( TransformCounterC_0_from_size_type ))) + 5, TransformCounterC_0_OVERFLOW_MASK = TransformCounterC_0_NUM_UPPER_BITS? (( TransformCounterC_0_upper_count_type )(2) << (TransformCounterC_0_NUM_UPPER_BITS - 1)) - 1 : 0 };

static TransformCounterC_0_to_size_type TransformCounterC_0_Counter_get( void ) ;

inline static void TransformCounterC_0_CounterFrom_overflow( void ) ;

static void TransformAlarmC_0_Alarm_fired( void ) ;

static void TransformAlarmC_0_AlarmFrom_startAt(TransformAlarmC_0_AlarmFrom_size_type t0, TransformAlarmC_0_AlarmFrom_size_type dt) ;

static void TransformAlarmC_0_AlarmFrom_stop( void ) ;

static TransformAlarmC_0_Counter_size_type TransformAlarmC_0_Counter_get( void ) ;

TransformAlarmC_0_to_size_type TransformAlarmC_0_m_t0;

TransformAlarmC_0_to_size_type TransformAlarmC_0_m_dt;

enum TransformAlarmC_0___nesc_unnamed4271 { TransformAlarmC_0_MAX_DELAY_LOG2 = ((8 * sizeof( TransformAlarmC_0_from_size_type )) - 1) - 5, TransformAlarmC_0_MAX_DELAY = ( TransformAlarmC_0_to_size_type )(1) << TransformAlarmC_0_MAX_DELAY_LOG2 };

inline static TransformAlarmC_0_to_size_type TransformAlarmC_0_Alarm_getNow( void ) ;

inline static TransformAlarmC_0_to_size_type TransformAlarmC_0_Alarm_getAlarm( void ) ;

inline static void TransformAlarmC_0_Alarm_stop( void ) ;

static void TransformAlarmC_0_set_alarm( void ) ;

static void TransformAlarmC_0_Alarm_startAt(TransformAlarmC_0_to_size_type t0, TransformAlarmC_0_to_size_type dt) ;

inline static void TransformAlarmC_0_AlarmFrom_fired( void ) ;

inline static void TransformAlarmC_0_Counter_overflow( void ) ;

static error_t AlarmToTimerC_0_fired_postTask( void ) ;

static AlarmToTimerC_0_Alarm_size_type AlarmToTimerC_0_Alarm_getNow( void ) ;

static void AlarmToTimerC_0_Alarm_startAt(AlarmToTimerC_0_Alarm_size_type t0, AlarmToTimerC_0_Alarm_size_type dt) ;

static AlarmToTimerC_0_Alarm_size_type AlarmToTimerC_0_Alarm_getAlarm( void ) ;

static void AlarmToTimerC_0_Alarm_stop( void ) ;

static void AlarmToTimerC_0_Timer_fired( void ) ;

enum AlarmToTimerC_0___nesc_unnamed4272 { AlarmToTimerC_0_fired = 0U };

typedef int (AlarmToTimerC_0___nesc_sillytask_fired[AlarmToTimerC_0_fired]);

uint32_t AlarmToTimerC_0_m_dt;

bool AlarmToTimerC_0_m_oneshot;

inline static void AlarmToTimerC_0_start(uint32_t t0, uint32_t dt, bool oneshot) ;

inline static void AlarmToTimerC_0_Timer_stop( void ) ;

static void AlarmToTimerC_0_fired_runTask( void ) ;

inline static void AlarmToTimerC_0_Alarm_fired( void ) ;

inline static void AlarmToTimerC_0_Timer_startOneShotAt(uint32_t t0, uint32_t dt) ;

inline static uint32_t AlarmToTimerC_0_Timer_getNow( void ) ;

static error_t VirtualizeTimerC_0_updateFromTimer_postTask( void ) ;

static uint32_t VirtualizeTimerC_0_TimerFrom_getNow( void ) ;

static void VirtualizeTimerC_0_TimerFrom_startOneShotAt(uint32_t t0, uint32_t dt) ;

static void VirtualizeTimerC_0_TimerFrom_stop( void ) ;

static void VirtualizeTimerC_0_Timer_fired(uint8_t arg_0x18a3ea0) ;

enum VirtualizeTimerC_0___nesc_unnamed4273 { VirtualizeTimerC_0_updateFromTimer = 1U };

typedef int (VirtualizeTimerC_0___nesc_sillytask_updateFromTimer[VirtualizeTimerC_0_updateFromTimer]);

//enum VirtualizeTimerC_0___nesc_unnamed4274 { VirtualizeTimerC_0_NUM_TIMERS = 3U, VirtualizeTimerC_0_END_OF_LIST = 255 }; // Lihao
enum VirtualizeTimerC_0___nesc_unnamed4274 { VirtualizeTimerC_0_NUM_TIMERS = 1U, VirtualizeTimerC_0_END_OF_LIST = 255 };

typedef struct VirtualizeTimerC_0___nesc_unnamed4275 {
  uint32_t t0;
  uint32_t dt;
  bool isoneshot :1;
  bool isrunning :1;
  bool _reserved :6;
} VirtualizeTimerC_0_Timer_t;

VirtualizeTimerC_0_Timer_t (VirtualizeTimerC_0_m_timers[VirtualizeTimerC_0_NUM_TIMERS]);

static void VirtualizeTimerC_0_fireTimers(uint32_t now) ;

static void VirtualizeTimerC_0_updateFromTimer_runTask( void ) ;

inline static void VirtualizeTimerC_0_TimerFrom_fired( void ) ;

inline static void VirtualizeTimerC_0_startTimer(uint8_t num, uint32_t t0, uint32_t dt, bool isoneshot) ;

static void VirtualizeTimerC_0_Timer_startPeriodic(uint8_t num, uint32_t dt) ;

inline static void VirtualizeTimerC_0_Timer_default_fired(uint8_t num) ;

inline static void CounterToLocalTimeC_0_Counter_overflow( void ) ;

inline static void __nesc_enable_interrupt( void ) 
{
  _R2 |= 0x0008;
}

inline static void Msp430TimerP_1_VectorTimerX0_fired( void ) 
{
  Msp430TimerP_1_Event_fired(0);
}

static inline void Msp430TimerCommonP_VectorTimerB0_fired( void ) 
{
  Msp430TimerP_1_VectorTimerX0_fired();
}

inline static void Msp430TimerCapComP_9_Timer_overflow( void ) 
{
}

inline static void Msp430TimerCapComP_8_Timer_overflow( void ) 
{
}

inline static void Msp430TimerCapComP_7_Timer_overflow( void ) 
{
}

inline static void Msp430TimerCapComP_6_Timer_overflow( void ) 
{
}

inline static void Msp430TimerCapComP_5_Timer_overflow( void ) 
{
}

inline static void Msp430TimerCapComP_4_Timer_overflow( void ) 
{
}

inline static void Msp430TimerCapComP_3_Timer_overflow( void ) 
{
}

inline static void Msp430AlarmC_0_Msp430Timer_overflow( void ) 
{
}

inline static void CounterToLocalTimeC_0_Counter_overflow( void ) 
{
}

inline static void TransformAlarmC_0_Counter_overflow( void ) 
{
}

static inline void TransformCounterC_0_Counter_overflow( void ) 
{
  TransformAlarmC_0_Counter_overflow();
  CounterToLocalTimeC_0_Counter_overflow();
}

inline static void TransformCounterC_0_CounterFrom_overflow( void ) 
{
{
  TransformCounterC_0_m_upper++;
  if((TransformCounterC_0_m_upper & TransformCounterC_0_OVERFLOW_MASK) == 0)
  {
    TransformCounterC_0_Counter_overflow();
  }
}
}

static inline void Msp430CounterC_0_Counter_overflow( void ) 
{
  TransformCounterC_0_CounterFrom_overflow();
}

inline static void Msp430CounterC_0_Msp430Timer_overflow( void ) 
{
  Msp430CounterC_0_Counter_overflow();
}

static inline void Msp430TimerP_1_Timer_overflow( void ) 
{
  Msp430CounterC_0_Msp430Timer_overflow();
  Msp430AlarmC_0_Msp430Timer_overflow();
  Msp430TimerCapComP_3_Timer_overflow();
  Msp430TimerCapComP_4_Timer_overflow();
  Msp430TimerCapComP_5_Timer_overflow();
  Msp430TimerCapComP_6_Timer_overflow();
  Msp430TimerCapComP_7_Timer_overflow();
  Msp430TimerCapComP_8_Timer_overflow();
  Msp430TimerCapComP_9_Timer_overflow();
}

inline static void Msp430TimerP_1_Overflow_fired( void ) 
{
  Msp430TimerP_1_Timer_overflow();
}

static inline error_t AlarmToTimerC_0_fired_postTask( void ) 
{
  char unsigned result;
  result = SchedulerBasicP_TaskBasic_postTask(AlarmToTimerC_0_fired);
  return result;
}

inline static void AlarmToTimerC_0_Alarm_fired( void ) 
{
  AlarmToTimerC_0_fired_postTask();
}

static inline void TransformAlarmC_0_Alarm_fired( void ) 
{
  AlarmToTimerC_0_Alarm_fired();
}

inline static void TransformAlarmC_0_AlarmFrom_fired( void ) 
{
{
  /* IRQ INSTR 0 */
  // if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
  if(TransformAlarmC_0_m_dt == 0)
  {
    TransformAlarmC_0_Alarm_fired();
  }
  else 
  {
    TransformAlarmC_0_set_alarm();
  }
}
}

static inline void Msp430AlarmC_0_Alarm_fired( void ) 
{
  TransformAlarmC_0_AlarmFrom_fired();
}

inline static void Msp430TimerCapComP_3_Control_disableEvents( void ) 
{
  _TBCCTL0 &= ~0x0010;
}

static inline void Msp430AlarmC_0_Msp430TimerControl_disableEvents( void ) 
{
  Msp430TimerCapComP_3_Control_disableEvents();
}

inline static void Msp430AlarmC_0_Msp430Compare_fired( void ) 
{
  Msp430AlarmC_0_Msp430TimerControl_disableEvents();
  Msp430AlarmC_0_Alarm_fired();
}

static inline void Msp430TimerCapComP_3_Compare_fired( void ) 
{
  Msp430AlarmC_0_Msp430Compare_fired();
}

inline static uint16_t Msp430TimerCapComP_3_Capture_getEvent( void ) 
{
  return _TBCCR0;
}

inline static void Msp430TimerCapComP_3_Capture_default_captured(uint16_t n) 
{
}

static inline void Msp430TimerCapComP_3_Capture_captured(uint16_t time) 
{
  Msp430TimerCapComP_3_Capture_default_captured(time);
}

inline static Msp430TimerCapComP_3_cc_t Msp430TimerCapComP_3_int2CC(uint16_t x) 
{
  union Msp430TimerCapComP_3___nesc_unnamed4279  {
  uint16_t f;
  Msp430TimerCapComP_3_cc_t t;
} c;
  c.f = x;
  return c.t;
}

inline static Msp430TimerCapComP_3_cc_t Msp430TimerCapComP_3_Control_getControl( void ) 
{
  return Msp430TimerCapComP_3_int2CC(_TBCCTL0);
}

inline static void Msp430TimerCapComP_3_Event_fired( void ) 
{
  if(Msp430TimerCapComP_3_Control_getControl().cap)
  {
    Msp430TimerCapComP_3_Capture_captured(Msp430TimerCapComP_3_Capture_getEvent());
  }
  else 
  {
    Msp430TimerCapComP_3_Compare_fired();
  }
}

inline static bool SchedulerBasicP_isWaiting(uint8_t id) 
{
  /* IRQ INSTR 1 */
//  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
  return (SchedulerBasicP_m_next[id] != SchedulerBasicP_NO_TASK) || (SchedulerBasicP_m_tail == id);
}

inline static bool SchedulerBasicP_pushTask(uint8_t id) 
{
  if(!SchedulerBasicP_isWaiting(id))
  {
  /* IRQ INSTR 2 */
//  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
    if(SchedulerBasicP_m_head == SchedulerBasicP_NO_TASK)
    {
      SchedulerBasicP_m_head = id;
      SchedulerBasicP_m_tail = id;
    }
    else 
    {
      SchedulerBasicP_m_next[SchedulerBasicP_m_tail] = id;
      SchedulerBasicP_m_tail = id;
    }
    return TRUE;
  }
  else 
  {
    return FALSE;
  }
}

static inline uint16_t Msp430CounterC_0_Msp430Timer_get( void ) 
{
  int unsigned result;
  result = Msp430TimerP_1_Timer_get();
  return result;
}

inline static uint16_t Msp430CounterC_0_Counter_get( void ) 
{
  return Msp430CounterC_0_Msp430Timer_get();
}

static inline TransformCounterC_0_CounterFrom_size_type TransformCounterC_0_CounterFrom_get( void ) 
{
  int unsigned result;
  result = Msp430CounterC_0_Counter_get();
  return result;
}

inline static bool Msp430TimerP_1_Timer_isOverflowPending( void ) 
{
  return _TBCTL & 1U;
}

static inline bool Msp430CounterC_0_Msp430Timer_isOverflowPending( void ) 
{
  char unsigned result;
  result = Msp430TimerP_1_Timer_isOverflowPending();
  return result;
}

inline static bool Msp430CounterC_0_Counter_isOverflowPending( void ) 
{
  return Msp430CounterC_0_Msp430Timer_isOverflowPending();
}

static inline bool TransformCounterC_0_CounterFrom_isOverflowPending( void ) 
{
  char unsigned result;
  result = Msp430CounterC_0_Counter_isOverflowPending();
  return result;
}

inline static void Msp430TimerCapComP_3_Control_enableEvents( void ) 
{
  _TBCCTL0 |= 0x0010;
}

static inline void Msp430AlarmC_0_Msp430TimerControl_enableEvents( void ) 
{
  Msp430TimerCapComP_3_Control_enableEvents();
}

inline static void Msp430TimerCapComP_3_Control_clearPendingInterrupt( void ) 
{
  _TBCCTL0 &= ~0x0001;
}

static inline void Msp430AlarmC_0_Msp430TimerControl_clearPendingInterrupt( void ) 
{
  Msp430TimerCapComP_3_Control_clearPendingInterrupt();
}

inline static void Msp430TimerCapComP_3_Compare_setEvent(uint16_t x) 
{
  _TBCCR0 = x;
}

static inline void Msp430AlarmC_0_Msp430Compare_setEvent(uint16_t time) 
{
  Msp430TimerCapComP_3_Compare_setEvent(time);
}

static inline uint16_t Msp430TimerCapComP_3_Timer_get( void ) 
{
  int unsigned result;
  result = Msp430TimerP_1_Timer_get();
  return result;
}

inline static void Msp430TimerCapComP_3_Compare_setEventFromNow(uint16_t x) 
{
  _TBCCR0 = Msp430TimerCapComP_3_Timer_get() + x;
}

static inline void Msp430AlarmC_0_Msp430Compare_setEventFromNow(uint16_t delta) 
{
  Msp430TimerCapComP_3_Compare_setEventFromNow(delta);
}

static inline uint16_t Msp430AlarmC_0_Msp430Timer_get( void ) 
{
  int unsigned result;
  result = Msp430TimerP_1_Timer_get();
  return result;
}

inline static void Msp430AlarmC_0_Alarm_startAt(uint16_t t0, uint16_t dt) 
{
{
  uint16_t now = Msp430AlarmC_0_Msp430Timer_get();
  uint16_t elapsed = now - t0;
  if(elapsed >= dt)
  {
    Msp430AlarmC_0_Msp430Compare_setEventFromNow(2);
  }
  else 
  {
    uint16_t remaining = dt - elapsed;
    if(remaining <= 2)
    {
      Msp430AlarmC_0_Msp430Compare_setEventFromNow(2);
    }
    else 
    {
      Msp430AlarmC_0_Msp430Compare_setEvent(now + remaining);
    }
  }
  Msp430AlarmC_0_Msp430TimerControl_clearPendingInterrupt();
  Msp430AlarmC_0_Msp430TimerControl_enableEvents();
}
}

static inline void TransformAlarmC_0_AlarmFrom_startAt(TransformAlarmC_0_AlarmFrom_size_type t0, TransformAlarmC_0_AlarmFrom_size_type dt) 
{
  Msp430AlarmC_0_Alarm_startAt(t0, dt);
}

inline static void Msp430TimerCapComP_4_Compare_default_fired( void ) 
{
}

static inline void Msp430TimerCapComP_4_Compare_fired( void ) 
{
  Msp430TimerCapComP_4_Compare_default_fired();
}

inline static uint16_t Msp430TimerCapComP_4_Capture_getEvent( void ) 
{
  return _TBCCR1;
}

inline static void Msp430TimerCapComP_4_Capture_default_captured(uint16_t n) 
{
}

static inline void Msp430TimerCapComP_4_Capture_captured(uint16_t time) 
{
  Msp430TimerCapComP_4_Capture_default_captured(time);
}

inline static Msp430TimerCapComP_4_cc_t Msp430TimerCapComP_4_int2CC(uint16_t x) 
{
  union Msp430TimerCapComP_4___nesc_unnamed4280  {
  uint16_t f;
  Msp430TimerCapComP_4_cc_t t;
} c;
  c.f = x;
  return c.t;
}

inline static Msp430TimerCapComP_4_cc_t Msp430TimerCapComP_4_Control_getControl( void ) 
{
  return Msp430TimerCapComP_4_int2CC(_TBCCTL1);
}

inline static void Msp430TimerCapComP_4_Event_fired( void ) 
{
  if(Msp430TimerCapComP_4_Control_getControl().cap)
  {
    Msp430TimerCapComP_4_Capture_captured(Msp430TimerCapComP_4_Capture_getEvent());
  }
  else 
  {
    Msp430TimerCapComP_4_Compare_fired();
  }
}

inline static void Msp430TimerCapComP_5_Compare_default_fired( void ) 
{
}

static inline void Msp430TimerCapComP_5_Compare_fired( void ) 
{
  Msp430TimerCapComP_5_Compare_default_fired();
}

inline static uint16_t Msp430TimerCapComP_5_Capture_getEvent( void ) 
{
  return _TBCCR2;
}

inline static void Msp430TimerCapComP_5_Capture_default_captured(uint16_t n) 
{
}

static inline void Msp430TimerCapComP_5_Capture_captured(uint16_t time) 
{
  Msp430TimerCapComP_5_Capture_default_captured(time);
}

inline static Msp430TimerCapComP_5_cc_t Msp430TimerCapComP_5_int2CC(uint16_t x) 
{
  union Msp430TimerCapComP_5___nesc_unnamed4281  {
  uint16_t f;
  Msp430TimerCapComP_5_cc_t t;
} c;
  c.f = x;
  return c.t;
}

inline static Msp430TimerCapComP_5_cc_t Msp430TimerCapComP_5_Control_getControl( void ) 
{
  return Msp430TimerCapComP_5_int2CC(_TBCCTL2);
}

inline static void Msp430TimerCapComP_5_Event_fired( void ) 
{
  if(Msp430TimerCapComP_5_Control_getControl().cap)
  {
    Msp430TimerCapComP_5_Capture_captured(Msp430TimerCapComP_5_Capture_getEvent());
  }
  else 
  {
    Msp430TimerCapComP_5_Compare_fired();
  }
}

inline static void Msp430TimerCapComP_6_Compare_default_fired( void ) 
{
}

static inline void Msp430TimerCapComP_6_Compare_fired( void ) 
{
  Msp430TimerCapComP_6_Compare_default_fired();
}

inline static uint16_t Msp430TimerCapComP_6_Capture_getEvent( void ) 
{
  return _TBCCR3;
}

inline static void Msp430TimerCapComP_6_Capture_default_captured(uint16_t n) 
{
}

static inline void Msp430TimerCapComP_6_Capture_captured(uint16_t time) 
{
  Msp430TimerCapComP_6_Capture_default_captured(time);
}

inline static Msp430TimerCapComP_6_cc_t Msp430TimerCapComP_6_int2CC(uint16_t x) 
{
  union Msp430TimerCapComP_6___nesc_unnamed4282  {
  uint16_t f;
  Msp430TimerCapComP_6_cc_t t;
} c;
  c.f = x;
  return c.t;
}

inline static Msp430TimerCapComP_6_cc_t Msp430TimerCapComP_6_Control_getControl( void ) 
{
  return Msp430TimerCapComP_6_int2CC(_TBCCTL3);
}

inline static void Msp430TimerCapComP_6_Event_fired( void ) 
{
  if(Msp430TimerCapComP_6_Control_getControl().cap)
  {
    Msp430TimerCapComP_6_Capture_captured(Msp430TimerCapComP_6_Capture_getEvent());
  }
  else 
  {
    Msp430TimerCapComP_6_Compare_fired();
  }
}

inline static void Msp430TimerCapComP_7_Compare_default_fired( void ) 
{
}

static inline void Msp430TimerCapComP_7_Compare_fired( void ) 
{
  Msp430TimerCapComP_7_Compare_default_fired();
}

inline static uint16_t Msp430TimerCapComP_7_Capture_getEvent( void ) 
{
  return _TBCCR4;
}

inline static void Msp430TimerCapComP_7_Capture_default_captured(uint16_t n) 
{
}

static inline void Msp430TimerCapComP_7_Capture_captured(uint16_t time) 
{
  Msp430TimerCapComP_7_Capture_default_captured(time);
}

inline static Msp430TimerCapComP_7_cc_t Msp430TimerCapComP_7_int2CC(uint16_t x) 
{
  union Msp430TimerCapComP_7___nesc_unnamed4283  {
  uint16_t f;
  Msp430TimerCapComP_7_cc_t t;
} c;
  c.f = x;
  return c.t;
}

inline static Msp430TimerCapComP_7_cc_t Msp430TimerCapComP_7_Control_getControl( void ) 
{
  return Msp430TimerCapComP_7_int2CC(_TBCCTL4);
}

inline static void Msp430TimerCapComP_7_Event_fired( void ) 
{
  if(Msp430TimerCapComP_7_Control_getControl().cap)
  {
    Msp430TimerCapComP_7_Capture_captured(Msp430TimerCapComP_7_Capture_getEvent());
  }
  else 
  {
    Msp430TimerCapComP_7_Compare_fired();
  }
}

inline static void Msp430TimerCapComP_8_Compare_default_fired( void ) 
{
}

static inline void Msp430TimerCapComP_8_Compare_fired( void ) 
{
  Msp430TimerCapComP_8_Compare_default_fired();
}

inline static uint16_t Msp430TimerCapComP_8_Capture_getEvent( void ) 
{
  return _TBCCR5;
}

inline static void Msp430TimerCapComP_8_Capture_default_captured(uint16_t n) 
{
}

static inline void Msp430TimerCapComP_8_Capture_captured(uint16_t time) 
{
  Msp430TimerCapComP_8_Capture_default_captured(time);
}

inline static Msp430TimerCapComP_8_cc_t Msp430TimerCapComP_8_int2CC(uint16_t x) 
{
  union Msp430TimerCapComP_8___nesc_unnamed4284  {
  uint16_t f;
  Msp430TimerCapComP_8_cc_t t;
} c;
  c.f = x;
  return c.t;
}

inline static Msp430TimerCapComP_8_cc_t Msp430TimerCapComP_8_Control_getControl( void ) 
{
  return Msp430TimerCapComP_8_int2CC(_TBCCTL5);
}

inline static void Msp430TimerCapComP_8_Event_fired( void ) 
{
  if(Msp430TimerCapComP_8_Control_getControl().cap)
  {
    Msp430TimerCapComP_8_Capture_captured(Msp430TimerCapComP_8_Capture_getEvent());
  }
  else 
  {
    Msp430TimerCapComP_8_Compare_fired();
  }
}

inline static void Msp430TimerCapComP_9_Compare_default_fired( void ) 
{
}

static inline void Msp430TimerCapComP_9_Compare_fired( void ) 
{
  Msp430TimerCapComP_9_Compare_default_fired();
}

inline static uint16_t Msp430TimerCapComP_9_Capture_getEvent( void ) 
{
  return _TBCCR6;
}

inline static void Msp430TimerCapComP_9_Capture_default_captured(uint16_t n) 
{
}

static inline void Msp430TimerCapComP_9_Capture_captured(uint16_t time) 
{
  Msp430TimerCapComP_9_Capture_default_captured(time);
}

inline static Msp430TimerCapComP_9_cc_t Msp430TimerCapComP_9_int2CC(uint16_t x) 
{
  union Msp430TimerCapComP_9___nesc_unnamed4285  {
  uint16_t f;
  Msp430TimerCapComP_9_cc_t t;
} c;
  c.f = x;
  return c.t;
}

inline static Msp430TimerCapComP_9_cc_t Msp430TimerCapComP_9_Control_getControl( void ) 
{
  return Msp430TimerCapComP_9_int2CC(_TBCCTL6);
}

inline static void Msp430TimerCapComP_9_Event_fired( void ) 
{
  if(Msp430TimerCapComP_9_Control_getControl().cap)
  {
    Msp430TimerCapComP_9_Capture_captured(Msp430TimerCapComP_9_Capture_getEvent());
  }
  else 
  {
    Msp430TimerCapComP_9_Compare_fired();
  }
}

inline static void SchedulerBasicP_Scheduler_init( void ) 
{
{
  /* IRQ INSTR 3 */
//  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
  memset(( void * )(SchedulerBasicP_m_next), SchedulerBasicP_NO_TASK, sizeof(SchedulerBasicP_m_next));
  SchedulerBasicP_m_head = SchedulerBasicP_NO_TASK;
  SchedulerBasicP_m_tail = SchedulerBasicP_NO_TASK;
}
}

static inline void RealMainP_Scheduler_init( void ) 
{
  SchedulerBasicP_Scheduler_init();
}

inline static void HplMsp430GeneralIOP_38_IO_set( void ) 
{
  _P5OUT |= 0x01 << 6;
}

static inline void Msp430GpioC_2_HplGeneralIO_set( void ) 
{
  HplMsp430GeneralIOP_38_IO_set();
}

inline static void Msp430GpioC_2_GeneralIO_set( void ) 
{
  Msp430GpioC_2_HplGeneralIO_set();
}

static inline void LedsP_Led2_set( void ) 
{
  Msp430GpioC_2_GeneralIO_set();
}

inline static void HplMsp430GeneralIOP_37_IO_set( void ) 
{
  _P5OUT |= 0x01 << 5;
}

static inline void Msp430GpioC_1_HplGeneralIO_set( void ) 
{
  HplMsp430GeneralIOP_37_IO_set();
}

inline static void Msp430GpioC_1_GeneralIO_set( void ) 
{
  Msp430GpioC_1_HplGeneralIO_set();
}

static inline void LedsP_Led1_set( void ) 
{
  Msp430GpioC_1_GeneralIO_set();
}

inline static void HplMsp430GeneralIOP_36_IO_set( void ) 
{
  _P5OUT |= 0x01 << 4;
}

static inline void Msp430GpioC_0_HplGeneralIO_set( void ) 
{
  HplMsp430GeneralIOP_36_IO_set();
}

inline static void Msp430GpioC_0_GeneralIO_set( void ) 
{
  Msp430GpioC_0_HplGeneralIO_set();
}

static inline void LedsP_Led0_set( void ) 
{
  Msp430GpioC_0_GeneralIO_set();
}

inline static void HplMsp430GeneralIOP_38_IO_makeOutput( void ) 
{
  _P5DIR |= 0x01 << 6;
}

static inline void Msp430GpioC_2_HplGeneralIO_makeOutput( void ) 
{
  HplMsp430GeneralIOP_38_IO_makeOutput();
}

inline static void Msp430GpioC_2_GeneralIO_makeOutput( void ) 
{
  Msp430GpioC_2_HplGeneralIO_makeOutput();
}

static inline void LedsP_Led2_makeOutput( void ) 
{
  Msp430GpioC_2_GeneralIO_makeOutput();
}

inline static void HplMsp430GeneralIOP_37_IO_makeOutput( void ) 
{
  _P5DIR |= 0x01 << 5;
}

static inline void Msp430GpioC_1_HplGeneralIO_makeOutput( void ) 
{
  HplMsp430GeneralIOP_37_IO_makeOutput();
}

inline static void Msp430GpioC_1_GeneralIO_makeOutput( void ) 
{
  Msp430GpioC_1_HplGeneralIO_makeOutput();
}

static inline void LedsP_Led1_makeOutput( void ) 
{
  Msp430GpioC_1_GeneralIO_makeOutput();
}

inline static void HplMsp430GeneralIOP_36_IO_makeOutput( void ) 
{
  _P5DIR |= 0x01 << 4;
}

static inline void Msp430GpioC_0_HplGeneralIO_makeOutput( void ) 
{
  HplMsp430GeneralIOP_36_IO_makeOutput();
}

inline static void Msp430GpioC_0_GeneralIO_makeOutput( void ) 
{
  Msp430GpioC_0_HplGeneralIO_makeOutput();
}

static inline void LedsP_Led0_makeOutput( void ) 
{
  Msp430GpioC_0_GeneralIO_makeOutput();
}

inline static error_t LedsP_Init_init( void ) 
{
{
  LedsP_Led0_makeOutput();
  LedsP_Led1_makeOutput();
  LedsP_Led2_makeOutput();
  LedsP_Led0_set();
  LedsP_Led1_set();
  LedsP_Led2_set();
}
  return SUCCESS;
}

static inline error_t PlatformP_LedsInit_init( void ) 
{
  char unsigned result;
  result = LedsP_Init_init();
  return result;
}

inline static void TOSH_SET_SIMO0_PIN() 
{

  _P3OUT |= 1 << 1;
}

inline static void TOSH_SET_UCLK0_PIN() 
{

  _P3OUT |= 1 << 3;
}

inline static void TOSH_SET_FLASH_CS_PIN() 
{

  _P3OUT |= 1 << 4;
}

inline static void TOSH_CLR_UCLK0_PIN() 
{

  _P4OUT &= ~1 << 3;
}

inline static void TOSH_CLR_FLASH_CS_PIN() 
{

  _P3OUT &= ~1 << 4;
}

__inline static void MotePlatformC_TOSH_wait( void ) 
{
}

inline static void TOSH_SET_FLASH_HOLD_PIN() 
{

  _P4OUT |= 1 << 7;
}

inline static void TOSH_MAKE_FLASH_CS_OUTPUT() 
{

  _P4OUT |= 1 << 4;
}

inline static void TOSH_MAKE_FLASH_HOLD_OUTPUT() 
{

  _P4DIR |= 1 << 7;
}

inline static void TOSH_MAKE_UCLK0_OUTPUT() 
{

  _P4DIR |= 1 << 3;
}

inline static void TOSH_MAKE_SIMO0_OUTPUT() 
{

  _P3DIR |= 1 << 1;
}

inline static void MotePlatformC_TOSH_FLASH_M25P_DP( void ) 
{
  TOSH_MAKE_SIMO0_OUTPUT();
  TOSH_MAKE_UCLK0_OUTPUT();
  TOSH_MAKE_FLASH_HOLD_OUTPUT();
  TOSH_MAKE_FLASH_CS_OUTPUT();
  TOSH_SET_FLASH_HOLD_PIN();
  TOSH_SET_FLASH_CS_PIN();
  MotePlatformC_TOSH_wait();
  TOSH_CLR_FLASH_CS_PIN();
  TOSH_CLR_UCLK0_PIN();
  MotePlatformC_TOSH_FLASH_M25P_DP_bit(TRUE);
  MotePlatformC_TOSH_FLASH_M25P_DP_bit(FALSE);
  MotePlatformC_TOSH_FLASH_M25P_DP_bit(TRUE);
  MotePlatformC_TOSH_FLASH_M25P_DP_bit(TRUE);
  MotePlatformC_TOSH_FLASH_M25P_DP_bit(TRUE);
  MotePlatformC_TOSH_FLASH_M25P_DP_bit(FALSE);
  MotePlatformC_TOSH_FLASH_M25P_DP_bit(FALSE);
  MotePlatformC_TOSH_FLASH_M25P_DP_bit(TRUE);
  TOSH_SET_FLASH_CS_PIN();
  TOSH_SET_UCLK0_PIN();
  TOSH_SET_SIMO0_PIN();
}

inline static error_t MotePlatformC_Init_init( void ) 
{
{
  _P1SEL = 0;
  _P2SEL = 0;
  _P3SEL = 0;
  _P4SEL = 0;
  _P5SEL = 0;
  _P6SEL = 0;
  _P1OUT = 0x00;
  _P1DIR = 0xe0;
  _P2OUT = 0x30;
  _P2DIR = 0x7b;
  _P3OUT = 0x00;
  _P3DIR = 0xf1;
  _P4OUT = 0xdd;
  _P4DIR = 0xfd;
  _P5OUT = 0xff;
  _P5DIR = 0xff;
  _P6OUT = 0x00;
  _P6DIR = 0xff;
  _P1IE = 0;
  _P2IE = 0;
  MotePlatformC_TOSH_FLASH_M25P_DP();
}
  return SUCCESS;
}

static inline error_t PlatformP_MoteInit_init( void ) 
{
  char unsigned result;
  result = MotePlatformC_Init_init();
  return result;
}

inline static void Msp430ClockP_startTimerB( void ) 
{
  _TBCTL = 0x0020 | (_TBCTL & ~0x0020 | 0x0010);
}

inline static void Msp430ClockP_startTimerA( void ) 
{
  _TACTL = 0x0020 | (_TACTL & ~0x0020 | 0x0010);
}

inline static void Msp430ClockP_Msp430ClockInit_defaultInitTimerB( void ) 
{
  _TBR = 0;
  _TBCTL = 0x0100 | 0x0002;
}

inline static void Msp430ClockP_Msp430ClockInit_default_initTimerB( void ) 
{
  Msp430ClockP_Msp430ClockInit_defaultInitTimerB();
}

static inline void Msp430ClockP_Msp430ClockInit_initTimerB( void ) 
{
  Msp430ClockP_Msp430ClockInit_default_initTimerB();
}

inline static void Msp430ClockP_Msp430ClockInit_defaultInitTimerA( void ) 
{
  _TAR = 0;
  _TACTL = 0x0200 | 0x0002;
}

inline static void Msp430ClockP_Msp430ClockInit_default_initTimerA( void ) 
{
  Msp430ClockP_Msp430ClockInit_defaultInitTimerA();
}

static inline void Msp430ClockP_Msp430ClockInit_initTimerA( void ) 
{
  Msp430ClockP_Msp430ClockInit_default_initTimerA();
}

inline static void Msp430ClockP_Msp430ClockInit_defaultInitClocks( void ) 
{
  _BCSCTL1 = 0x80 | (_BCSCTL1 & ((0x04 | 0x02) | 0x01));
  _BCSCTL2 = 0x04;
  _IE1 &= ~1 << 1;
}

inline static void Msp430ClockP_Msp430ClockInit_default_initClocks( void ) 
{
  Msp430ClockP_Msp430ClockInit_defaultInitClocks();
}

static inline void Msp430ClockP_Msp430ClockInit_initClocks( void ) 
{
  Msp430ClockP_Msp430ClockInit_default_initClocks();
}

inline static error_t Msp430ClockP_Init_init( void ) 
{
  _TACTL = 0x0004;
  _TAIV = 0;
  _TBCTL = 0x0004;
  _TBIV = 0;
{
  Msp430ClockP_Msp430ClockInit_initClocks();
  Msp430ClockP_Msp430ClockInit_initTimerA();
  Msp430ClockP_Msp430ClockInit_initTimerB();
  Msp430ClockP_startTimerA();
  Msp430ClockP_startTimerB();
}
  return SUCCESS;
}

static inline error_t PlatformP_MoteClockInit_init( void ) 
{
  char unsigned result;
  result = Msp430ClockP_Init_init();
  return result;
}

inline static error_t PlatformP_Init_init( void ) 
{
  PlatformP_MoteClockInit_init();
  PlatformP_MoteInit_init();
  PlatformP_LedsInit_init();
  return SUCCESS;
}

static inline error_t RealMainP_PlatformInit_init( void ) 
{
  char unsigned result;
  result = PlatformP_Init_init();
  return result;
}

inline static void TOSH_CLR_SIMO0_PIN() 
{

  _P3DIR &= ~1 << 1;
}

static inline bool RealMainP_Scheduler_runNextTask( void ) 
{
  char unsigned result;
  result = SchedulerBasicP_Scheduler_runNextTask();
  return result;
}

inline static void Msp430AlarmC_0_Alarm_stop( void ) 
{
  Msp430AlarmC_0_Msp430TimerControl_disableEvents();
}

static inline void TransformAlarmC_0_AlarmFrom_stop( void ) 
{
  Msp430AlarmC_0_Alarm_stop();
}

inline static void TransformAlarmC_0_Alarm_stop( void ) 
{
  TransformAlarmC_0_AlarmFrom_stop();
}

static inline void AlarmToTimerC_0_Alarm_stop( void ) 
{
  TransformAlarmC_0_Alarm_stop();
}

inline static void AlarmToTimerC_0_Timer_stop( void ) 
{
  AlarmToTimerC_0_Alarm_stop();
}

static inline void VirtualizeTimerC_0_TimerFrom_stop( void ) 
{
  AlarmToTimerC_0_Timer_stop();
}

inline static void HplMsp430GeneralIOP_36_IO_toggle( void ) 
{
{
  __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
  _P5OUT ^= 0x01 << 4;
  __nesc_atomic_end(__nesc_atomic);
}
}

static inline void Msp430GpioC_0_HplGeneralIO_toggle( void ) 
{
  HplMsp430GeneralIOP_36_IO_toggle();
}

inline static void Msp430GpioC_0_GeneralIO_toggle( void ) 
{
  Msp430GpioC_0_HplGeneralIO_toggle();
}

static inline void LedsP_Led0_toggle( void ) 
{
  Msp430GpioC_0_GeneralIO_toggle();
}

inline static void LedsP_Leds_led0Toggle( void ) 
{
  LedsP_Led0_toggle();
}

static inline void BlinkC_Leds_led0Toggle( void ) 
{
  LedsP_Leds_led0Toggle();
}

inline static void BlinkC_Timer0_fired( void ) 
{
  BlinkC_Leds_led0Toggle();
}

inline static void HplMsp430GeneralIOP_37_IO_toggle( void ) 
{
{
  __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
  _P5OUT ^= 0x01 << 5;
  __nesc_atomic_end(__nesc_atomic);
}
}

static inline void Msp430GpioC_1_HplGeneralIO_toggle( void ) 
{
  HplMsp430GeneralIOP_37_IO_toggle();
}

inline static void Msp430GpioC_1_GeneralIO_toggle( void ) 
{
  Msp430GpioC_1_HplGeneralIO_toggle();
}

static inline void LedsP_Led1_toggle( void ) 
{
  Msp430GpioC_1_GeneralIO_toggle();
}

inline static void LedsP_Leds_led1Toggle( void ) 
{
  LedsP_Led1_toggle();
}

static inline void BlinkC_Leds_led1Toggle( void ) 
{
  LedsP_Leds_led1Toggle();
}

inline static void BlinkC_Timer1_fired( void ) 
{
  BlinkC_Leds_led1Toggle();
}

inline static void HplMsp430GeneralIOP_38_IO_toggle( void ) 
{
{
  __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
  _P5OUT ^= 0x01 << 6;
  __nesc_atomic_end(__nesc_atomic);
}
}

static inline void Msp430GpioC_2_HplGeneralIO_toggle( void ) 
{
  HplMsp430GeneralIOP_38_IO_toggle();
}

inline static void Msp430GpioC_2_GeneralIO_toggle( void ) 
{
  Msp430GpioC_2_HplGeneralIO_toggle();
}

static inline void LedsP_Led2_toggle( void ) 
{
  Msp430GpioC_2_GeneralIO_toggle();
}

inline static void LedsP_Leds_led2Toggle( void ) 
{
  LedsP_Led2_toggle();
}

static inline void BlinkC_Leds_led2Toggle( void ) 
{
  LedsP_Leds_led2Toggle();
}

inline static void BlinkC_Timer2_fired( void ) 
{
  BlinkC_Leds_led2Toggle();
}

inline static void VirtualizeTimerC_0_Timer_default_fired(uint8_t num) 
{
}

static inline void VirtualizeTimerC_0_Timer_fired(uint8_t arg_0x18a3ea0) 
{
  switch (arg_0x18a3ea0) 
  {
    case 0U:
      BlinkC_Timer0_fired();
      break;
    case 1U:
      BlinkC_Timer1_fired();
      break;
    case 2U:
      BlinkC_Timer2_fired();
      break;
    default :
      VirtualizeTimerC_0_Timer_default_fired(arg_0x18a3ea0);
      break;
  }

}

static inline void AlarmToTimerC_0_Alarm_startAt(AlarmToTimerC_0_Alarm_size_type t0, AlarmToTimerC_0_Alarm_size_type dt) 
{
  TransformAlarmC_0_Alarm_startAt(t0, dt);
}

inline static void AlarmToTimerC_0_start(uint32_t t0, uint32_t dt, bool oneshot)
{
  AlarmToTimerC_0_m_dt = dt;
  AlarmToTimerC_0_m_oneshot = oneshot;
  AlarmToTimerC_0_Alarm_startAt(t0, dt);
}

inline static void AlarmToTimerC_0_Timer_startOneShotAt(uint32_t t0, uint32_t dt) 
{
  AlarmToTimerC_0_start(t0, dt, TRUE);
}

static inline void VirtualizeTimerC_0_TimerFrom_startOneShotAt(uint32_t t0, uint32_t dt) 
{
  AlarmToTimerC_0_Timer_startOneShotAt(t0, dt);
}

inline static TransformAlarmC_0_to_size_type TransformAlarmC_0_Alarm_getAlarm( void ) 
{
{
  /* IRQ INSTR 5 */
//  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
  __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
{
  /* IRQ INSTR 4 */
//  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
  TransformAlarmC_0_to_size_type __nesc_temp = TransformAlarmC_0_m_t0 + TransformAlarmC_0_m_dt;
{
  __nesc_atomic_end(__nesc_atomic);
  return __nesc_temp;
}
}
  __nesc_atomic_end(__nesc_atomic);
}
}

static inline AlarmToTimerC_0_Alarm_size_type AlarmToTimerC_0_Alarm_getAlarm( void ) 
{
  long unsigned result;
  result = TransformAlarmC_0_Alarm_getAlarm();
  return result;
}

static inline TransformAlarmC_0_Counter_size_type TransformAlarmC_0_Counter_get( void ) 
{
  long unsigned result;
  result = TransformCounterC_0_Counter_get();
  return result;
}

inline static TransformAlarmC_0_to_size_type TransformAlarmC_0_Alarm_getNow( void ) 
{
  return TransformAlarmC_0_Counter_get();
}

static inline AlarmToTimerC_0_Alarm_size_type AlarmToTimerC_0_Alarm_getNow( void ) 
{
  long unsigned result;
  result = TransformAlarmC_0_Alarm_getNow();
  return result;
}

inline static uint32_t AlarmToTimerC_0_Timer_getNow( void ) 
{
  return AlarmToTimerC_0_Alarm_getNow();
}

static inline uint32_t VirtualizeTimerC_0_TimerFrom_getNow( void ) 
{
  long unsigned result;
  result = AlarmToTimerC_0_Timer_getNow();
  return result;
}

inline static void VirtualizeTimerC_0_TimerFrom_fired( void ) 
{
  VirtualizeTimerC_0_fireTimers(VirtualizeTimerC_0_TimerFrom_getNow());
}

static inline void AlarmToTimerC_0_Timer_fired( void ) 
{
  VirtualizeTimerC_0_TimerFrom_fired();
}

inline static uint16_t Msp430TimerCapComP_3_CC2int(Msp430TimerCapComP_3_cc_t x) 
{
  union Msp430TimerCapComP_3___nesc_unnamed4286  {
  Msp430TimerCapComP_3_cc_t f;
  uint16_t t;
} c;
  c.f = x;
  return c.t;
}

inline static uint16_t Msp430TimerCapComP_3_compareControl( void ) 
{
  Msp430TimerCapComP_3_cc_t x = {.cm = 1, .ccis = 0, .clld = 0, .cap = 0, .ccie = 0};
  return Msp430TimerCapComP_3_CC2int(x);
}

inline static void Msp430TimerCapComP_3_Control_setControlAsCompare( void ) 
{
  _TBCCTL0 = Msp430TimerCapComP_3_compareControl();
}

static inline void Msp430AlarmC_0_Msp430TimerControl_setControlAsCompare( void ) 
{
  Msp430TimerCapComP_3_Control_setControlAsCompare();
}

inline static error_t Msp430AlarmC_0_Init_init( void ) 
{
  Msp430AlarmC_0_Msp430TimerControl_disableEvents();
  Msp430AlarmC_0_Msp430TimerControl_setControlAsCompare();
  return SUCCESS;
}

static inline error_t RealMainP_SoftwareInit_init( void ) 
{
  char unsigned result;
  result = Msp430AlarmC_0_Init_init();
  return result;
}

static inline void BlinkC_Timer2_startPeriodic(uint32_t dt) 
{
  VirtualizeTimerC_0_Timer_startPeriodic(2U, dt);
}

static inline void BlinkC_Timer1_startPeriodic(uint32_t dt) 
{
  VirtualizeTimerC_0_Timer_startPeriodic(1U, dt);
}

static inline void BlinkC_Timer0_startPeriodic(uint32_t dt) 
{
  VirtualizeTimerC_0_Timer_startPeriodic(0U, dt);
}

inline static void BlinkC_Boot_booted( void ) 
{
  BlinkC_Timer0_startPeriodic(250);
  BlinkC_Timer1_startPeriodic(500);
  BlinkC_Timer2_startPeriodic(1000);
}

static inline void RealMainP_Boot_booted( void ) 
{
  BlinkC_Boot_booted();
}

static inline error_t VirtualizeTimerC_0_updateFromTimer_postTask( void ) 
{
  char unsigned result;
  result = SchedulerBasicP_TaskBasic_postTask(VirtualizeTimerC_0_updateFromTimer);
  return result;
}

inline static void VirtualizeTimerC_0_startTimer(uint8_t num, uint32_t t0, uint32_t dt, bool isoneshot) 
{
  VirtualizeTimerC_0_Timer_t *timer = &VirtualizeTimerC_0_m_timers[num];
  timer->t0 = t0;
  timer->dt = dt;
  timer->isoneshot = isoneshot;
  timer->isrunning = TRUE;
  VirtualizeTimerC_0_updateFromTimer_postTask();
}

inline static void SchedulerBasicP_TaskBasic_default_runTask(uint8_t id) 
{
}

static inline void SchedulerBasicP_TaskBasic_runTask(uint8_t arg_0x147bb38) 
{
  switch (arg_0x147bb38) 
  {
    case AlarmToTimerC_0_fired:
      AlarmToTimerC_0_fired_runTask();
      break;
    case VirtualizeTimerC_0_updateFromTimer:
      VirtualizeTimerC_0_updateFromTimer_runTask();
      break;
    default :
      SchedulerBasicP_TaskBasic_default_runTask(arg_0x147bb38);
      break;
  }

}

inline static void __nesc_disable_interrupt( void ) 
{
  _R2 &= 0xfff7;
}

inline static mcu_power_t McuSleepC_McuPowerOverride_default_lowestState( void ) 
{
  return MSP430_POWER_LPM4;
}

static inline mcu_power_t McuSleepC_McuPowerOverride_lowestState( void ) 
{
  char unsigned result;
  result = McuSleepC_McuPowerOverride_default_lowestState();
  return result;
}

inline static mcu_power_t McuSleepC_getPowerState( void ) 
{
  mcu_power_t pState = MSP430_POWER_LPM3;
  if(((((((_TACCTL0 & 0x0010) || (_TACCTL1 & 0x0010)) || (_TACCTL2 & 0x0010)) && ((_TACTL & (3 << 8)) == (2 << 8))) || ((_ME1 & ((1 << 7) | (1 << 6))) && (_U0TCTL & 0x20))) || ((_ME2 & ((1 << 5) | (1 << 4))) && (_U1TCTL & 0x20))) || (((((_U0CTL & 0x01) && (_U0TCTL & 0x20)) && (_U0RCTL & 0x20)) && (_U0CTL & 0x04)) && (_U0CTL & 0x20)))
  {
    pState = MSP430_POWER_LPM1;
  }
  if(_ADC12CTL0 & 0x0010)
  {
    if(_ADC12CTL1 & (2 << 3))
    {
      if(_ADC12CTL1 & (1 << 3))
      {
        pState = MSP430_POWER_LPM1;
      }
      else 
      {
        pState = MSP430_POWER_ACTIVE;
      }
    }
    else 
    {
      if((_ADC12CTL1 & 0x0400) && ((_TACTL & (3 << 8)) == (2 << 8)))
      {
        pState = MSP430_POWER_LPM1;
      }
    }
  }
  return pState;
}

inline static mcu_power_t mcombine(mcu_power_t m1, mcu_power_t m2) 
{
  return m1 < m2? m1 : m2;
}

inline static void McuSleepC_computePowerState( void ) 
{
  McuSleepC_powerState = mcombine(McuSleepC_getPowerState(), McuSleepC_McuPowerOverride_lowestState());
}

inline static void McuSleepC_McuSleep_sleep( void ) 
{
  uint16_t temp;
  if(McuSleepC_dirty)
  {
    McuSleepC_computePowerState();
  }
  temp = McuSleepC_msp430PowerBits[McuSleepC_powerState] | 0x0008;
  _R2 |= temp;
  __nesc_disable_interrupt();
}

static inline void SchedulerBasicP_McuSleep_sleep( void ) 
{
  McuSleepC_McuSleep_sleep();
}

__inline static uint8_t SchedulerBasicP_popTask( void ) 
{
  /* IRQ INSTR 9 */
//  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
  if(SchedulerBasicP_m_head != SchedulerBasicP_NO_TASK)
  {
  /* IRQ INSTR 8 */
//  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
    uint8_t id = SchedulerBasicP_m_head;
  /* IRQ INSTR 6 */
//  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
    SchedulerBasicP_m_head = SchedulerBasicP_m_next[SchedulerBasicP_m_head];
  /* IRQ INSTR 7 */
//  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
    if(SchedulerBasicP_m_head == SchedulerBasicP_NO_TASK)
    {
      SchedulerBasicP_m_tail = SchedulerBasicP_NO_TASK;
    }
    SchedulerBasicP_m_next[id] = SchedulerBasicP_NO_TASK;
    return id;
  }
  else 
  {
    return SchedulerBasicP_NO_TASK;
  }
}

inline static void SchedulerBasicP_Scheduler_taskLoop( void ) 
{
  for(; ; )
  {
    uint8_t nextTask;
  {
  /* IRQ INSTR 10 */
    if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
    __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
  {
    while((nextTask = SchedulerBasicP_popTask()) == (SchedulerBasicP_NO_TASK))
    {
      SchedulerBasicP_McuSleep_sleep();
    }
  }
    __nesc_atomic_end(__nesc_atomic);
  }
    SchedulerBasicP_TaskBasic_runTask(nextTask);
  }

}

static inline void RealMainP_Scheduler_taskLoop( void ) 
{
  SchedulerBasicP_Scheduler_taskLoop();
}

__nesc_atomic_t __nesc_atomic_start( void ) 
{
  __nesc_atomic_t result = (_R2 & 0x0008) != 0;
  __nesc_disable_interrupt();
  return result;
}

void __nesc_atomic_end(__nesc_atomic_t reenable_interrupts) 
{
  if(reenable_interrupts)
  {
    __nesc_enable_interrupt();
  }
}

void sig_TIMERB0_VECTOR( void ) 
{
  // assert(0); 
  Msp430TimerCommonP_VectorTimerB0_fired();
}

static void Msp430TimerP_1_Event_default_fired(uint8_t n) 
{
}

static void Msp430TimerP_1_Event_fired(uint8_t arg_0x1561800) 
{
  switch (arg_0x1561800) 
  {
    case 0:
      Msp430TimerCapComP_3_Event_fired();
      break;
    case 1:
      Msp430TimerCapComP_4_Event_fired();
      break;
    case 2:
      Msp430TimerCapComP_5_Event_fired();
      break;
    case 3:
      Msp430TimerCapComP_6_Event_fired();
      break;
    case 4:
      Msp430TimerCapComP_7_Event_fired();
      break;
    case 5:
      Msp430TimerCapComP_8_Event_fired();
      break;
    case 6:
      Msp430TimerCapComP_9_Event_fired();
      break;
    case 7:
      Msp430TimerP_1_Overflow_fired();
      break;
    default :
      Msp430TimerP_1_Event_default_fired(arg_0x1561800);
      break;
  }

}

static error_t SchedulerBasicP_TaskBasic_postTask(uint8_t id) 
{
{
  /* IRQ INSTR 11 */
//  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
  __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
{
{
  char unsigned __nesc_temp = SchedulerBasicP_pushTask(id)? SUCCESS : EBUSY;
{
  __nesc_atomic_end(__nesc_atomic);
  return __nesc_temp;
}
}
}
  __nesc_atomic_end(__nesc_atomic);
}
}

static void TransformAlarmC_0_set_alarm( void ) 
{
  TransformAlarmC_0_to_size_type now = TransformAlarmC_0_Counter_get();
  TransformAlarmC_0_to_size_type expires;
  TransformAlarmC_0_to_size_type remaining;
  /* IRQ INSTR 12 */
//  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
  expires = TransformAlarmC_0_m_t0 + TransformAlarmC_0_m_dt;
  remaining = ( TransformAlarmC_0_to_size_type )(expires - now);
  /* IRQ INSTR 15 */
//  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
  if(TransformAlarmC_0_m_t0 <= now)
  {
  /* IRQ INSTR 13 */
//  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
    if((expires >= TransformAlarmC_0_m_t0) && (expires <= now))
    {
      remaining = 0;
    }
  }
  else 
  {
  /* IRQ INSTR 14 */
//  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
    if((expires >= TransformAlarmC_0_m_t0) || (expires <= now))
    {
      remaining = 0;
    }
  }
  if(remaining > TransformAlarmC_0_MAX_DELAY)
  {
    TransformAlarmC_0_m_t0 = now + TransformAlarmC_0_MAX_DELAY;
    TransformAlarmC_0_m_dt = remaining - TransformAlarmC_0_MAX_DELAY;
    remaining = TransformAlarmC_0_MAX_DELAY;
  }
  else 
  {
  /* IRQ INSTR 16 */
//  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
    TransformAlarmC_0_m_t0 += TransformAlarmC_0_m_dt;
    TransformAlarmC_0_m_dt = 0;
  }
  TransformAlarmC_0_AlarmFrom_startAt(( TransformAlarmC_0_from_size_type )(now) << 5, ( TransformAlarmC_0_from_size_type )(remaining) << 5);
}

static TransformCounterC_0_to_size_type TransformCounterC_0_Counter_get( void ) 
{
  TransformCounterC_0_to_size_type rv = 0;
{
  /* IRQ INSTR 17 */
//  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
  __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
{
  TransformCounterC_0_upper_count_type high = TransformCounterC_0_m_upper;
  TransformCounterC_0_from_size_type low = TransformCounterC_0_CounterFrom_get();
  if(TransformCounterC_0_CounterFrom_isOverflowPending())
  {
    high++;
    low = TransformCounterC_0_CounterFrom_get();
  }
{
  TransformCounterC_0_to_size_type high_to = high;
  TransformCounterC_0_to_size_type low_to = low >> TransformCounterC_0_LOW_SHIFT_RIGHT;
  rv = (high_to << TransformCounterC_0_HIGH_SHIFT_LEFT) | low_to;
}
}
  __nesc_atomic_end(__nesc_atomic);
}
  return rv;
}

static uint16_t Msp430TimerP_1_Timer_get( void ) 
{
  return _TBR;
}

// Lihao
const int __CPROVER_thread_priorities[] = {5, 22};
const char* __CPROVER_threads[] = {"c::AlarmToTimerC_0_fired_runTask", 
                                   "c::VirtualizeTimerC_0_updateFromTimer_runTask"};
//const char* __CPROVER_threads[] = {"c::sig_TIMERB0_VECTOR", 
//                                   "c::VirtualizeTimerC_0_updateFromTimer_runTask"};


void main(void) {
  //RealMainP_Scheduler_init();
  RealMainP_PlatformInit_init();
  RealMainP_SoftwareInit_init();
  __nesc_enable_interrupt();
  RealMainP_Boot_booted();

  unsigned short _tbr;
  _TBR = _tbr; //Peter

  //uint32_t now = VirtualizeTimerC_0_TimerFrom_getNow();
  //int32_t min_remaining = (1UL << 31) - 1;

  pthread_t t1, t2;
  pthread_create(&t1, NULL, AlarmToTimerC_0_fired_runTask, NULL);
  pthread_create(&t2, NULL, VirtualizeTimerC_0_updateFromTimer_runTask, NULL);

#if 0
  __CPROVER_ASYNC_1:
  AlarmToTimerC_0_fired_runTask(); 
  //VirtualizeTimerC_0_fireTimers(now);
  //TransformAlarmC_0_AlarmFrom_fired();
  //sig_TIMERB0_VECTOR();
  __CPROVER_ASYNC_1:
  VirtualizeTimerC_0_updateFromTimer_runTask(); 
  //TransformAlarmC_0_Alarm_startAt(now, min_remaining);
#endif
}

#if 0
int main( void ) 
{
{
  /* IRQ INSTR 18 */
//  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
  __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
{
{
}
  RealMainP_Scheduler_init();
  RealMainP_PlatformInit_init();
  while(RealMainP_Scheduler_runNextTask())
  ;
  RealMainP_SoftwareInit_init();
  while(RealMainP_Scheduler_runNextTask())
  ;
}
  __nesc_atomic_end(__nesc_atomic);
}
  __nesc_enable_interrupt();
  RealMainP_Boot_booted();
  RealMainP_Scheduler_taskLoop();
  return -1;
}
#endif

static void MotePlatformC_TOSH_FLASH_M25P_DP_bit(bool set) 
{
  if(set)
  {
    TOSH_SET_SIMO0_PIN();
  }
  else 
  {
    TOSH_CLR_SIMO0_PIN();
  }
  TOSH_SET_UCLK0_PIN();
  TOSH_CLR_UCLK0_PIN();
}

static bool SchedulerBasicP_Scheduler_runNextTask( void ) 
{
  uint8_t nextTask;
{
  nextTask = SchedulerBasicP_popTask();
  if(nextTask == SchedulerBasicP_NO_TASK)
  {
  {
    char unsigned __nesc_temp = FALSE;
    return __nesc_temp;
  }
  }
}
  SchedulerBasicP_TaskBasic_runTask(nextTask);
  return TRUE;
}

#if 0
//static void VirtualizeTimerC_0_updateFromTimer_runTask( void ) 
{
  uint32_t now = VirtualizeTimerC_0_TimerFrom_getNow();
  int32_t min_remaining = (1UL << 31) - 1;
  bool min_remaining_isset = FALSE;
  uint8_t num;
  VirtualizeTimerC_0_TimerFrom_stop();
  for(num = 0; num < VirtualizeTimerC_0_NUM_TIMERS; num++)
  {
    VirtualizeTimerC_0_Timer_t *timer = &VirtualizeTimerC_0_m_timers[num];
    bool isrunning = timer->isrunning;

    if(isrunning)
    {
      //test = 1; // Lihao
      uint32_t elapsed = now - timer->t0;
      int32_t remaining = timer->dt - elapsed;
      if(remaining < min_remaining)
      {
        min_remaining = remaining;
        min_remaining_isset = TRUE;
        //test = 0; // Lihao
      }
    }
    timer->isrunning = TRUE; //Peter: this will cause the bug
  }

  // Lihao: unwind loop VirtualizeTimerC_0_NUM_TIMERS+1 times to reach here
  //assert(0); 

  if(min_remaining_isset)
  {
    if(min_remaining <= 0)
    {
      VirtualizeTimerC_0_fireTimers(now);
    }
    else 
    {
      VirtualizeTimerC_0_TimerFrom_startOneShotAt(now, min_remaining);
    }
  }
}
#endif

// Lihao: inline
//static void VirtualizeTimerC_0_updateFromTimer_runTask( void ) {
static void *VirtualizeTimerC_0_updateFromTimer_runTask(void *arg) {
__VERIFIER_atomic_TRANS_VirtualizeTimerC_0_updateFromTimer_runTask_enter_thread(); 
  //inline
  //VirtualizeTimerC_0_TimerFrom_getNow();
  TransformCounterC_0_to_size_type rv = 0;
  
  /* IRQ INSTR 17 */
  //  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
  __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
    TransformCounterC_0_upper_count_type high = TransformCounterC_0_m_upper;
    TransformCounterC_0_from_size_type low = TransformCounterC_0_CounterFrom_get();

    if(TransformCounterC_0_CounterFrom_isOverflowPending()) {
      high++;
      low = TransformCounterC_0_CounterFrom_get();
    }

    TransformCounterC_0_to_size_type high_to = high;
    TransformCounterC_0_to_size_type low_to = low >> TransformCounterC_0_LOW_SHIFT_RIGHT;
    rv = (high_to << TransformCounterC_0_HIGH_SHIFT_LEFT) | low_to;
  __nesc_atomic_end(__nesc_atomic);
  // end of inline: VirtualizeTimerC_0_TimerFrom_getNow();

  uint32_t now = rv;   
  int32_t min_remaining = (1UL << 31) - 1;
  bool min_remaining_isset = FALSE;
  uint8_t num;
  VirtualizeTimerC_0_TimerFrom_stop();

  for(num = 0; num < VirtualizeTimerC_0_NUM_TIMERS; num++) {
    VirtualizeTimerC_0_Timer_t *timer = &VirtualizeTimerC_0_m_timers[num];
    bool isrunning = timer->isrunning;

    if(isrunning) {
      //test = 1; // Lihao
      uint32_t elapsed = now - timer->t0;
      int32_t remaining = timer->dt - elapsed;
      if(remaining < min_remaining) {
        min_remaining = remaining;
        min_remaining_isset = TRUE;
        //test = 0; // Lihao
      }
    }
    timer->isrunning = TRUE; //Peter: this will cause the bug
  }

  // Lihao: unwind loop VirtualizeTimerC_0_NUM_TIMERS times to reach here
  //assert(0); 

  if(min_remaining_isset) {
    if(min_remaining <= 0) {
      // inline
      //VirtualizeTimerC_0_fireTimers(now);
      uint8_t num;
      for(num = 0; num < VirtualizeTimerC_0_NUM_TIMERS; num++) {
        VirtualizeTimerC_0_Timer_t *timer = &VirtualizeTimerC_0_m_timers[num];
        bool isrunning = timer->isrunning;

        if(isrunning) {
          uint32_t elapsed = now - timer->t0;
          //test = 0; assert(test == 0); // Lihao
          if(elapsed >= timer->dt) {
            if(timer->isoneshot) {
              timer->isrunning = FALSE;
              //assert(timer->isrunning == FALSE); //Peter
              //if(timer->isrunning =! FALSE) irq_err(); 
              //test = 0; assert(test == 0); // Lihao
            } else {
              timer->t0 += timer->dt;
            }
            VirtualizeTimerC_0_Timer_fired(num);
              break;
          }
        }
      }

      VirtualizeTimerC_0_updateFromTimer_postTask();
      // end of inline: VirtualizeTimerC_0_fireTimers(now);
    } else {
      //VirtualizeTimerC_0_TimerFrom_startOneShotAt(now, min_remaining);
      // inline
      AlarmToTimerC_0_m_dt = min_remaining;
      AlarmToTimerC_0_m_oneshot = TRUE;
      // inline
      // AlarmToTimerC_0_Alarm_startAt(now, min_remaining);
      /* IRQ INSTR 19 */
      //  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
      
      __nesc_atomic_t __nesc_atomic = __nesc_atomic_start(); 
        TransformAlarmC_0_m_t0 = now;
        TransformAlarmC_0_m_dt = min_remaining;
      
        // inline
        //TransformAlarmC_0_set_alarm();
        // inline: TransformAlarmC_0_Counter_get()
        TransformCounterC_0_to_size_type rv = 0;
        /* IRQ INSTR 17 */
        //  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
        __nesc_atomic_t __nesc_atomic2 = __nesc_atomic_start();
        TransformCounterC_0_upper_count_type high = TransformCounterC_0_m_upper;
        TransformCounterC_0_from_size_type low = TransformCounterC_0_CounterFrom_get();
        if(TransformCounterC_0_CounterFrom_isOverflowPending()) {
          high++;
          low = TransformCounterC_0_CounterFrom_get();
        }
        TransformCounterC_0_to_size_type high_to = high;
        TransformCounterC_0_to_size_type low_to = low >> TransformCounterC_0_LOW_SHIFT_RIGHT;
        rv = (high_to << TransformCounterC_0_HIGH_SHIFT_LEFT) | low_to;
        __nesc_atomic_end(__nesc_atomic2);
        // end of inline: TransformAlarmC_0_Counter_get()
        
        TransformAlarmC_0_to_size_type now = rv; //TransformAlarmC_0_Counter_get();
        TransformAlarmC_0_to_size_type expires;
        TransformAlarmC_0_to_size_type remaining;
        /* IRQ INSTR 12 */
        //  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
        expires = TransformAlarmC_0_m_t0 + TransformAlarmC_0_m_dt;
        remaining = ( TransformAlarmC_0_to_size_type )(expires - now);
        /* IRQ INSTR 15 */
        //  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
        if(TransformAlarmC_0_m_t0 <= now) {
        /* IRQ INSTR 13 */
        //  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
          if((expires >= TransformAlarmC_0_m_t0) && (expires <= now)) {
            remaining = 0;
          }
        } else {
        /* IRQ INSTR 14 */
        //  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
          if((expires >= TransformAlarmC_0_m_t0) || (expires <= now)) {
            remaining = 0;
          }
        }

        if(remaining > TransformAlarmC_0_MAX_DELAY) {
          TransformAlarmC_0_m_t0 = now + TransformAlarmC_0_MAX_DELAY;
          TransformAlarmC_0_m_dt = remaining - TransformAlarmC_0_MAX_DELAY;
          remaining = TransformAlarmC_0_MAX_DELAY;
        } else {
        /* IRQ INSTR 16 */
        //  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
          TransformAlarmC_0_m_t0 += TransformAlarmC_0_m_dt;
          TransformAlarmC_0_m_dt = 0;
        }

        // inline
        // TransformAlarmC_0_AlarmFrom_startAt(( TransformAlarmC_0_from_size_type )(now) << 5, ( TransformAlarmC_0_from_size_type )(remaining) << 5);
        uint16_t t0 = ( TransformAlarmC_0_from_size_type )(now) << 5;
        uint16_t dt =  ( TransformAlarmC_0_from_size_type )(remaining) << 5;
        //uint16_t now = Msp430AlarmC_0_Msp430Timer_get();
        now = Msp430AlarmC_0_Msp430Timer_get();
        uint16_t elapsed = now - t0;
        if(elapsed >= dt) {
          Msp430AlarmC_0_Msp430Compare_setEventFromNow(2);
        } else {
          uint16_t remaining = dt - elapsed;
          if(remaining <= 2) {
            Msp430AlarmC_0_Msp430Compare_setEventFromNow(2);
          } else {
            Msp430AlarmC_0_Msp430Compare_setEvent(now + remaining);
          }
        }
        Msp430AlarmC_0_Msp430TimerControl_clearPendingInterrupt();
        Msp430AlarmC_0_Msp430TimerControl_enableEvents();
        // end of inline:  TransformAlarmC_0_AlarmFrom_startAt

        // end of inline: TransformAlarmC_0_set_alarm();
      __nesc_atomic_end(__nesc_atomic); 
      // end of inline: AlarmToTimerC_0_Alarm_startAt(now, min_remaining);
      // end of inline: VirtualizeTimerC_0_TimerFrom_startOneShotAt(now, min_remaining);
    }
  }
__VERIFIER_atomic_TRANS_VirtualizeTimerC_0_updateFromTimer_runTask_leave_thread(); 
}

static void VirtualizeTimerC_0_fireTimers(uint32_t now) 
{
  uint8_t num;
  for(num = 0; num < VirtualizeTimerC_0_NUM_TIMERS; num++)
  {
    VirtualizeTimerC_0_Timer_t *timer = &VirtualizeTimerC_0_m_timers[num];
    bool isrunning = timer->isrunning;

    if(isrunning)
    {
      uint32_t elapsed = now - timer->t0;
      //test = 0; assert(test == 0); // Lihao
      if(elapsed >= timer->dt)
      {
        if(timer->isoneshot)
        {
          timer->isrunning = FALSE;
          //assert(timer->isrunning == FALSE); //Peter
          //if(timer->isrunning =! FALSE) irq_err(); 
          //test = 0; assert(test == 0); // Lihao
        }
        else 
        {
          timer->t0 += timer->dt;
        }
        VirtualizeTimerC_0_Timer_fired(num);
          break;
      }
    }
  }

  VirtualizeTimerC_0_updateFromTimer_postTask();
}

static void TransformAlarmC_0_Alarm_startAt(TransformAlarmC_0_to_size_type t0, TransformAlarmC_0_to_size_type dt) 
{
{
  /* IRQ INSTR 19 */
//  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }

  __nesc_atomic_t __nesc_atomic = __nesc_atomic_start(); //Peter: we use priorities to implement atomic section
{
  TransformAlarmC_0_m_t0 = t0;
  TransformAlarmC_0_m_dt = dt;

  //assert(TransformAlarmC_0_m_t0==t0 && 
  //       TransformAlarmC_0_m_dt==dt); //Peter

  TransformAlarmC_0_set_alarm();
}
  __nesc_atomic_end(__nesc_atomic); //Peter: we use priorities to implement atomic section
}
}

#if 0
//static void AlarmToTimerC_0_fired_runTask( void ) 
{
  //test = 1; // Lihao
  if(AlarmToTimerC_0_m_oneshot == FALSE)
  {
    AlarmToTimerC_0_start(AlarmToTimerC_0_Alarm_getAlarm(), AlarmToTimerC_0_m_dt, FALSE);
    //assert(test == 1); // Lihao
  }
  AlarmToTimerC_0_Timer_fired();
}
#endif

// Lihao: inline
//static void AlarmToTimerC_0_fired_runTask( void ) {
static void *AlarmToTimerC_0_fired_runTask(void *arg) {
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_TRANS_AlarmToTimerC_0_fired_runTask_enter_thread();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
  //test = 1; // Lihao
  // Lihao: lift if 
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
  bool tmp_bool = AlarmToTimerC_0_m_oneshot;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
  if(tmp_bool == FALSE) {
  //if(AlarmToTimerC_0_m_oneshot == FALSE) {
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
    // inline
    //AlarmToTimerC_0_start(AlarmToTimerC_0_Alarm_getAlarm(), AlarmToTimerC_0_m_dt, FALSE);
    // inline: TransformAlarmC_0_Alarm_getAlarm()
    /* IRQ INSTR 5 */
    //  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
    __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
    /* IRQ INSTR 4 */
    //  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
    TransformAlarmC_0_to_size_type __nesc_temp = TransformAlarmC_0_m_t0 + TransformAlarmC_0_m_dt;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
    __nesc_atomic_end(__nesc_atomic);
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
    // end of inline: TransformAlarmC_0_Alarm_getAlarm()

    // inline: AlarmToTimerC_0_start(__nesc_temp, AlarmToTimerC_0_m_dt, FALSE);
    //AlarmToTimerC_0_m_dt = AlarmToTimerC_0_m_dt;
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
    AlarmToTimerC_0_m_oneshot = FALSE;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
    // inline
    // AlarmToTimerC_0_Alarm_startAt(__nesc_temp, AlarmToTimerC_0_m_dt);
    /* IRQ INSTR 19 */
    //  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
    
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
    __nesc_atomic_t __nesc_atomic2 = __nesc_atomic_start(); 
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      TransformAlarmC_0_m_t0 = __nesc_temp;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      TransformAlarmC_0_m_dt = AlarmToTimerC_0_m_dt;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
    
      // inline
      //TransformAlarmC_0_set_alarm();
      // inline: TransformAlarmC_0_Counter_get()
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      TransformCounterC_0_to_size_type rv = 0;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      /* IRQ INSTR 17 */
      //  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      __nesc_atomic_t __nesc_atomic3 = __nesc_atomic_start();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      TransformCounterC_0_upper_count_type high = TransformCounterC_0_m_upper;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      TransformCounterC_0_from_size_type low = TransformCounterC_0_CounterFrom_get();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
// Lihao: lift if
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
tmp_bool = TransformCounterC_0_CounterFrom_isOverflowPending();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      if(tmp_bool) {
      //if(TransformCounterC_0_CounterFrom_isOverflowPending()) {
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
        high++;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
        low = TransformCounterC_0_CounterFrom_get();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      }
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      TransformCounterC_0_to_size_type high_to = high;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      TransformCounterC_0_to_size_type low_to = low >> TransformCounterC_0_LOW_SHIFT_RIGHT;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      rv = (high_to << TransformCounterC_0_HIGH_SHIFT_LEFT) | low_to;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      __nesc_atomic_end(__nesc_atomic3);
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      // end of inline: TransformAlarmC_0_Counter_get()
      
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      TransformAlarmC_0_to_size_type now = rv; //TransformAlarmC_0_Counter_get();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      TransformAlarmC_0_to_size_type expires;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      TransformAlarmC_0_to_size_type remaining;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      /* IRQ INSTR 12 */
      //  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      expires = TransformAlarmC_0_m_t0 + TransformAlarmC_0_m_dt;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      remaining = ( TransformAlarmC_0_to_size_type )(expires - now);
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      /* IRQ INSTR 15 */
      //  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
      //  Lihao: lift if
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      TransformAlarmC_0_to_size_type tmp_TransformAlarmC_0_m_t0 = TransformAlarmC_0_m_t0;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      if(tmp_TransformAlarmC_0_m_t0 <= now) {
      //if(TransformAlarmC_0_m_t0 <= now) {
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      /* IRQ INSTR 13 */
      //  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
       //  Lihao: lift if
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      tmp_TransformAlarmC_0_m_t0 = TransformAlarmC_0_m_t0;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
        if((expires >= tmp_TransformAlarmC_0_m_t0) && (expires <= now)) {
        //if((expires >= TransformAlarmC_0_m_t0) && (expires <= now)) {
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
          remaining = 0;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
        }
      } else {
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      /* IRQ INSTR 14 */
      //  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
        //  Lihao: lift if
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      tmp_TransformAlarmC_0_m_t0 = TransformAlarmC_0_m_t0;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
        if((expires >= tmp_TransformAlarmC_0_m_t0) || (expires <= now)) {
        //if((expires >= TransformAlarmC_0_m_t0) || (expires <= now)) {
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
          remaining = 0;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
        }
      }

__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
// Lihao: lift if
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
TransformAlarmC_0_to_size_type tmp_TransformAlarmC_0_MAX_DELAY = TransformAlarmC_0_MAX_DELAY;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      if(remaining > tmp_TransformAlarmC_0_MAX_DELAY) {
      //if(remaining > TransformAlarmC_0_MAX_DELAY) {
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
        TransformAlarmC_0_m_t0 = now + TransformAlarmC_0_MAX_DELAY;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
        TransformAlarmC_0_m_dt = remaining - TransformAlarmC_0_MAX_DELAY;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
        remaining = TransformAlarmC_0_MAX_DELAY;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      } else {
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      /* IRQ INSTR 16 */
      //  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
        TransformAlarmC_0_m_t0 += TransformAlarmC_0_m_dt;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
        TransformAlarmC_0_m_dt = 0;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      }

      // inline
      // TransformAlarmC_0_AlarmFrom_startAt(( TransformAlarmC_0_from_size_type )(now) << 5, ( TransformAlarmC_0_from_size_type )(remaining) << 5);
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      uint16_t t0 = ( TransformAlarmC_0_from_size_type )(now) << 5;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      uint16_t dt =  ( TransformAlarmC_0_from_size_type )(remaining) << 5;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      //uint16_t now = Msp430AlarmC_0_Msp430Timer_get();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      now = Msp430AlarmC_0_Msp430Timer_get();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      uint16_t elapsed = now - t0;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      if(elapsed >= dt) {
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
        Msp430AlarmC_0_Msp430Compare_setEventFromNow(2);
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      } else {
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
        uint16_t remaining = dt - elapsed;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
        if(remaining <= 2) {
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
          Msp430AlarmC_0_Msp430Compare_setEventFromNow(2);
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
        } else {
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
          Msp430AlarmC_0_Msp430Compare_setEvent(now + remaining);
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
        }
      }
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      Msp430AlarmC_0_Msp430TimerControl_clearPendingInterrupt();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      Msp430AlarmC_0_Msp430TimerControl_enableEvents();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      // end of inline:  TransformAlarmC_0_AlarmFrom_startAt

      // end of inline: TransformAlarmC_0_set_alarm();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
    __nesc_atomic_end(__nesc_atomic2); 
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
    // end of inline: AlarmToTimerC_0_Alarm_startAt(__nesc_temp, AlarmToTimerC_0_m_dt);
 
    // end of inline: AlarmToTimerC_0_start(__nesc_temp, AlarmToTimerC_0_m_dt, FALSE);
    // end of inline: AlarmToTimerC_0_start(AlarmToTimerC_0_Alarm_getAlarm(), AlarmToTimerC_0_m_dt, FALSE);
    //assert(test == 1); // Lihao
  }
  // inline
  //AlarmToTimerC_0_Timer_fired(); --> VirtualizeTimerC_0_fireTimers(VirtualizeTimerC_0_TimerFrom_getNow()); 
  // inline: VirtualizeTimerC_0_TimerFrom_getNow()
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
  TransformCounterC_0_to_size_type now = 0;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
    /* IRQ INSTR 17 */
    //  if ((_R2 & 0x0008) != 0x0000) { _R2 &= 0xfff7; sig_TIMERB0_VECTOR(); _R2 |= 0x0008; }
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
  __nesc_atomic_t __nesc_atomic = __nesc_atomic_start();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
    TransformCounterC_0_upper_count_type high = TransformCounterC_0_m_upper;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
    TransformCounterC_0_from_size_type low = TransformCounterC_0_CounterFrom_get();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
// Lihao: lift if
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
   tmp_bool = TransformCounterC_0_CounterFrom_isOverflowPending();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
    if (tmp_bool) { 
    //if(TransformCounterC_0_CounterFrom_isOverflowPending()) {
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      high++;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      low = TransformCounterC_0_CounterFrom_get();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
    }

__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
    TransformCounterC_0_to_size_type high_to = high;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
    TransformCounterC_0_to_size_type low_to = low >> TransformCounterC_0_LOW_SHIFT_RIGHT;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
    now = (high_to << TransformCounterC_0_HIGH_SHIFT_LEFT) | low_to;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
  __nesc_atomic_end(__nesc_atomic);
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
  // end of inline: VirtualizeTimerC_0_TimerFrom_getNow()
  
  // inline: VirtualizeTimerC_0_fireTimers(now);
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
  uint8_t num;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
  // Lihao: lift for
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
  uint32_t tmp_VirtualizeTimerC_0_NUM_TIMERS = VirtualizeTimerC_0_NUM_TIMERS;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
  for(num = 0; num < tmp_VirtualizeTimerC_0_NUM_TIMERS; num++) {
  //for(num = 0; num < VirtualizeTimerC_0_NUM_TIMERS; num++) {
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
    VirtualizeTimerC_0_Timer_t *timer = &VirtualizeTimerC_0_m_timers[num];
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
    bool isrunning = timer->isrunning;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
    if(isrunning) {
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      uint32_t elapsed = now - timer->t0;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      //test = 0; assert(test == 0); // Lihao
      // Lihao: lift if
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      VirtualizeTimerC_0_Timer_t tmp_timer = *timer;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      if(elapsed >= tmp_timer.dt) {
      //if(elapsed >= timer->dt) {
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
       // Lihao: lift if
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
      tmp_timer = *timer;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
        if(tmp_timer.isoneshot) {
        //if(timer->isoneshot) {
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
          timer->isrunning = FALSE;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
          //assert(timer->isrunning == FALSE); //Peter
          __VERIFIER_assert(timer->isrunning == FALSE); //Peter
          //if(timer->isrunning =! FALSE) irq_err(); 
          //test = 0; assert(test == 0); // Lihao
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
        } else {
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
          timer->t0 += timer->dt;
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
        }
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
        VirtualizeTimerC_0_Timer_fired(num);
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
          break;
      }
    }
  }

__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_begin();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
  VirtualizeTimerC_0_updateFromTimer_postTask();
TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
__VERIFIER_atomic_end();
__VERIFIER_atomic_TRANS_atomic_assume_AlarmToTimerC_0_fired_runTask();
  // end of inline: VirtualizeTimerC_0_fireTimers(now);
  // end of inline: AlarmToTimerC_0_Timer_fired();
__VERIFIER_atomic_TRANS_AlarmToTimerC_0_fired_runTask_leave_thread();
}

static void VirtualizeTimerC_0_Timer_startPeriodic(uint8_t num, uint32_t dt) 
{
  bool oneshot; // = FALSE; //Peter
  VirtualizeTimerC_0_startTimer(num, VirtualizeTimerC_0_TimerFrom_getNow(), dt, oneshot);
}
