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
#define LIMIT 20
int cnt1, cnt2, cnt3, cnt4, cnt5;
//void Timer_A_isr();
//void Timer_B_isr();
//void Timer_C_isr();
void Timer_Reset();
void Timer_Force();
void Timer_A_isr ()
{

    timerCount ++;
    cnt4++;
    timerCount = 1;
    if (timerCount != 0) {
    }
    if(timerCount == 0) {
        P1OUT = (LED_0 + LED_1);
    }
        cnt1++;
}
void Timer_B_isr ()
{
        timerCount = 1;
        if (timerCount != 0) {}
        if (timerCount == 0) {
            P1OUT  = LED_0;}
        cnt2++;
        timerCount = 0;
        if (timerCount != 0) {}
        cnt5++;
}
void Timer_C_isr (){
timerCount = 1;
        if (timerCount != 0) {}
        if (timerCount == 0) {
            P1OUT  = LED_0;}
        cnt3++;
}
void Timer_Force ()
{
        timerCount ++;
        cnt4++;
}
void Timer_Reset ()
{
        timerCount = 0;
        if (timerCount != 0) {}
        cnt5++;
}

int main(int argc, char **argv) {

    WDTCTL = 
    WDTPW +
    WDTHOLD; 
    LED_DIR = 
    LED_0 + 
    LED_1;
    LED_OUT = 1 
    + (LED_0+LED_1);

    CCTL0 = 
    CCIE;
    TACTL = 
    TASSEL_2 + MC_2; // Set the timer A to SMCLCK, Continuous
    timerCount = 0;
    printf("start\n");
    pthread_t id1, id2, id3, id4, id5;
    pthread_create(&id1, NULL, (void*)Timer_A_isr, NULL);
    pthread_create(&id2, NULL, (void*)Timer_B_isr, NULL);
    pthread_create(&id3, NULL, (void*)Timer_C_isr, NULL);
    pthread_create(&id4, NULL, (void*)Timer_Force, NULL);
    pthread_create(&id5, NULL, (void*)Timer_Reset, NULL);
    pthread_join(id5, NULL);
    pthread_join(id4, NULL);
    pthread_join(id3, NULL);
    pthread_join(id2, NULL);
    pthread_join(id1, NULL);
    printf("finished\n");

    return 0;
}


