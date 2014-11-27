/**
   This is the startup code for the LPC810/Cortex-M0+ tutorial series:
   00-Getting_Started.
   Originally posted on:
   http://homepages.rpi.edu/~dongr2/
   
   Licence: Do anything with it, I don't care. Public Domain. Just
   remember I don't give any warrenty
*/
	.syntax unified
	.thumb

	.section .isr_vectors
	.align
	.long __stack_top
	.long Reset_Handler
	
	.text
	.align

	.thumb_func
	.global Reset_Handler
Reset_Handler:
crt0:
	b main
