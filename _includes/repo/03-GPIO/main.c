/**
   Author: Rongcui Dong

   This is the main code for the
   LPC810 Cortex-M0+ Programming from Scratch
   tutorial series.

   Originally posted on:
   http://homepages.rpi.edu/~dongr2/

   Licence: Do anything with it, I don't care. Public Domain. Just
   remember I don't give any warrenty
*/
#include "lpc810/device.h"

unsigned long wait;
unsigned long until = 0xDEADBEEF;
const unsigned long begin = 0xDEAFBEEF;

const uint32_t test = (uint32_t) &(SWM->PINENABLE0);

typedef unsigned int volatile * vp;
void main() {
  /* PIO0_2 is used by SWD, so disable it */
  SWM->PINENABLE0 = 0xFFFFFFBFUL;
  /* Set GPIO Direction */
  GPIO0->DIR |= 1 << 2;
  for(;;) {
    /* Toggle the LED */
    GPIO0->NOT |= 1 << 2;
    wait = begin;
    while (wait > until) --wait;		/* WAIT */
  }
}

