/**
    Author: Rongcui Dong

    This is the linker script for the LPC810/Cortex-M0+ tutorial series:
    02-BSS_Data
    Originally posted on:
    http://homepages.rpi.edu/~dongr2/
   
    Licence: Do anything with it, I don't care. Public Domain. Just
    remember I don't give any warrenty
 */
ENTRY(Reset_Handler);
MEMORY {
    FLASH(rx) : ORIGIN = 0x0, LENGTH = 0x1000 /* 4K */
    RAM(rwx) : ORIGIN = 0x10000000, LENGTH = 0x400 /* 1K */
}

SECTIONS {
    . = ORIGIN(FLASH);
    .text : {
        KEEP(* (.isr_vectors));
        . = ALIGN(4);
        __vec_end__ = .;
        /*. = 0xC4;*/ /* End of vectors */
        * (.text);
        . = ALIGN(4);
	* (.rodata);
	. = ALIGN(4);
        __end_text__ = .;
    } > FLASH

    __flash_sdata__ = .;

    .data : AT(__flash_sdata__){
    	__data_start__ = .;
        * (.data);
        . = ALIGN(4);
	__data_end__ = .;
    } > RAM
    __data_size__ = __data_end__ - __data_start__;
    
    .bss : {
        __bss_start__ = .;
    	* (.bss);
        . = ALIGN(4);
        __bss_end__ = .;
    } > RAM
    __bss_size__ = __bss_end__ - __bss_start__;
    __stack_top = ORIGIN(RAM) + LENGTH(RAM);
}

_end = .;
PROVIDE(end = .);
