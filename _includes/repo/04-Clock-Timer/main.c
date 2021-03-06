/**
   Author: Rongcui Dong

   This is the main code for the
   LPC810 Cortex-M0+ Programming from Scratch
   tutorial series.

   Originally posted on:
   http://homepages.rpi.edu/~dongr2/

   License: Do anything with it, I don't care. Public Domain. Just
   remember I don't give any warrenty
*/
#include "lpc810/device.h"

unsigned long wait;
unsigned long until = 0xDEADBEEF;
const unsigned long begin = 0xDEAFBEEF;

const uint32_t test = (uint32_t) &(SWM->PINENABLE0);

typedef unsigned int volatile * vp;

void ClockInit(void);

void ClockInit(void) {
  /* Set MSEL=5, PSEL=2, resulting in 60MHz main clock */
  SYSCON->SYSPLLCTRL = SYSPLLCTRL_MSEL_BITS(5)
    | SYSPLLCTRL_PSEL_BITS(2);

  /* Use internal RC */
  SYSCON->SYSPLLCLKSEL = SYSAHBCLKSEL_IRC;
  /* Update clock source */
  SYSCON->SYSPLLCLKUEN = 0;	/* Write 0 first */
  SYSCON->SYSPLLCLKUEN = 1;	/* Write 0 first */

  while(SYSCON->SYSPLLSTAT & SYSPLLSTAT_LOCK_MASK); /* Wait for PLL to lock */
  /* TODO: Main clock */
}

void main() {
  /* PIO0_2 is used by SWD, so disable it */
  SWM->PINENABLE0 |= (SWM_PINENABLE0_SWCLK_EN | SWM_PINENABLE0_SWDIO_EN);
  /* Set GPIO Direction */
  GPIO0->DIR |= _BV(2);
  for(;;) {
    /* Toggle the LED */
    GPIO0->NOT |= _BV(2);
    wait = begin;
    while (wait > until) --wait;		/* WAIT */
  }
}

