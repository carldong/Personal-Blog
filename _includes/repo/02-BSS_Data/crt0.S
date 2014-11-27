/**
    Author: Rongcui Dong

    This is the startup code for the LPC810/Cortex-M0+ tutorial series:
    02-BSS_Data
    Originally posted on:
    http://homepages.rpi.edu/~dongr2/
   
    Licence: Do anything with it, I don't care. Public Domain. Just
    remember I don't give any warrenty
*/
	/*
	This is the startup file for LPC81x. The C definition of the vector tables are defined in vector.c
	*/
	.syntax unified
	.thumb
	.section .isr_vectors

	.align 2 

	.long __stack_top
	.long Reset_Handler
	.long NMI_Handler
	.long HardFault_Handler
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long SVCall_Handler
	.long 0
	.long 0
	.long PendSV_Handler
	.long SysTick_Handler
	.long 0

	/* IRQ 0 */
	.long SPI0_IRQ
	.long SPI1_IRQ
	.long 0
	.long UART0_IRQ
	.long UART1_IRQ
	.long UART2_IRQ
	.long 0
	.long 0
	/* IRQ 8 */
	.long I2C0_IRQ
	.long SCT_IRQ
	.long MRT_IRQ
	.long CMP_IRQ
	.long WDT_IRQ
	.long BOD_IRQ
	.long 0
	.long WKT_IRQ
	/* IRQ 16 */
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	.long 0
	/* IRQ 24 */
	.long PININT0_IRQ
	.long PININT1_IRQ
	.long PININT2_IRQ
	.long PININT3_IRQ
	.long PININT4_IRQ
	.long PININT5_IRQ
	.long PININT6_IRQ
	.long PININT7_IRQ

	.text
	.align

	.thumb_func
	.global Reset_Handler
Reset_Handler:
	cpsid i
	ldr r0, =__flash_sdata__
	ldr r1, =__data_start__
	ldr r2, =__data_size__

	@@ If data_size == 0
	cmp r2, #0
	beq init_bss

copy:
	ldrb r4, [r0]		@ Load *r0 to r4
	strb r4, [r1]		@ Load r4 to *r1
	adds r0, r0, #1		@ Increment flash pointer
	adds r1, r1, #1		@ Increment RAM pointer
	subs r2, r2, #1		@ Loop until all data are copied
	bne copy

init_bss:
	ldr r0, =__bss_start__
	ldr r1, =__bss_end__
	ldr r2, =__bss_size__

	cmp r2, #0
	beq crt0

	movs r4, #0
zero:
	strb r4, [r0]		@ Zero out
	adds r0, r0, #1		@ Increment pointer
	subs r2, r2, #1
	bne zero

crt0:
	cpsie i
	b main
.align
