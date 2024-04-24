#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

unsigned int timerCount = 0;
int P1OUT;
int LED_0;
int LED_1;
int WDTCLT;
int WDTPW;
int WDTCTL;
int WDTHOLD;
int LED_DIR;
int LED_OUT;
int CCTL0;
int CCIE;
int TACTL;
int TASSEL_2;
int MC_2;
#define LIMIT 3
int cnt1, cnt2, cnt3;

// void Timer_A_isr();
// void Timer_B_isr();
// void Timer_Force_isr();

void Timer_A_isr ()
{
     // Timer_Force();
    //  while (cnt1 < LIMIT) {
        //timerCount = (timerCount + 1) % 8;
        timerCount = 1;
        //timerCount++;
        // assert(timerCount == 0);
    //    if (timerCount != 0) {
    //        //assert(0);
    //    }
        if(timerCount == 0) {
            P1OUT = (LED_0 + LED_1);
        }
        cnt1++;
    //  }
}

// Priority 2
void Timer_B_isr ()
{
    //  while (cnt2 < LIMIT) {
        //timerCount = (timerCount + 1) % 4;
        timerCount = 1;
        // assert(timerCount == 0);
    //    if (timerCount != 0) {
    //        // assert(0);
    //    }
        if (timerCount == 0) {
            P1OUT  = LED_0;
        }
        cnt2++;
    //  }
}

// Priority 3
void Timer_Force_isr ()
{
    //  while (cnt3 < LIMIT) {
        // traditional: violated
        // our method: not violated
        // timerCount = 0;

        if (timerCount != 0) {
            // assert(0);
        }
        timerCount = 1;
        cnt3++;
    //  }
}

int main(int argc, char **argv) {

    WDTCTL = WDTPW + WDTHOLD; // Stop watchdog timer
    //LED_DIR |= (LED_0 + LED_1); // Set P1.0 and P1.6 to output direction
    LED_DIR = LED_0 + LED_1;
    //LED_OUT &= ~(LED_0 + LED_1); // Set the LEDs off
    LED_OUT = 1 + (LED_0+LED_1);

    CCTL0 = CCIE;
    TACTL = TASSEL_2 + MC_2; // Set the timer A to SMCLCK, Continuous
    // Clear the timer and enable timer interrupt
    timerCount = 0;

    printf("start\n");
    pthread_t id1, id2, id3;
    pthread_create(&id1, NULL, (void*)Timer_A_isr, NULL);
    pthread_create(&id2, NULL, (void*)Timer_B_isr, NULL);
    pthread_create(&id3, NULL, (void*)Timer_Force_isr, NULL);
    pthread_join(id3, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}
