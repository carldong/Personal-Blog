/**
   This is the linker script for the LPC810/Cortex-M0+ tutorial series:
   00-Getting_Started.
   Originally posted on:
   http://homepages.rpi.edu/~dongr2/
   
   Licence: Do anything with it, I don't care. Public Domain. Just
   remember I don't give any warrenty
 */

ENTRY(Reset_Handler);
MEMORY {
    FLASH(rx) : ORIGIN = 0x0, LENGTH = 4K
    RAM(rwx) : ORIGIN = 0x10000000, LENGTH = 1K
}

SECTIONS {
    . = ORIGIN(FLASH);
    .text : {
        KEEP(* (.isr_vectors));
	. = ALIGN(4);
	. = 0xC4;		/* The end of vectors. Just for tutorial 0 */
	__vec_enc__ = .;
	* (.text);
	__end_text__ = .;
    }
    __stack_top = ORIGIN(RAM) + LENGTH(RAM);
}

__end = .;
PROVIDE(etext = __end_text__);
PROVIDE(end = .);
