/**
   Author: Rongcui Dong

   This is the main code for the LPC810/Cortex-M0+ tutorial series:
   00-Getting_Started.
   Originally posted on:
   http://homepages.rpi.edu/~dongr2/

   Inspired by http://midibel.com/blink0.html, but I rewrote the whole
   thing
   
   Licence: Do anything with it, I don't care. Public Domain. Just
   remember I don't give any warrenty
*/

unsigned long wait;
unsigned long until = 0xDEADBEEF;

typedef unsigned int volatile * vp;
void main() {
  /* PIO0_2 is used by SWD, so disable it */
  *(vp) 0x4000C1C0 = 0xFFFFFFBFUL;	/* PINENABLE0 register */
  /* Set GPIO Direction */
  *(vp) 0xA0002000 |= 1 << 2;	/* DIR0, set PIO0_2 to output */
  for(;;) {
    /* Toggle the LED */
    *(vp) 0xA0002300 |= 1 << 2;	/* NOT0 register */
    wait = 0xDEAFBEEF;
    while (wait > until) --wait;		/* WAIT */
  }
}

