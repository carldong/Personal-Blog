extern void Reset_Handler(void);
extern void NMI_Handler(void);
extern void HardFault_Handler(void);
extern void SVCall_Handler(void);
extern void PendSV_Handler(void);
extern void SysTick_Handler(void);

extern void SPI0_IRQ(void);
extern void SPI1_IRQ(void);
extern void UART0_IRQ(void);
extern void UART1_IRQ(void);
extern void UART2_IRQ(void);
extern void I2C0_IRQ(void);
extern void SCT_IRQ(void);
extern void MRT_IRQ(void);
extern void CMP_IRQ(void);
extern void WDT_IRQ(void);
extern void BOD_IRQ(void);
extern void WKT_IRQ(void);
extern void PININT0_IRQ(void);
extern void PININT1_IRQ(void);
extern void PININT2_IRQ(void);
extern void PININT3_IRQ(void);
extern void PININT4_IRQ(void);
extern void PININT5_IRQ(void);
extern void PININT6_IRQ(void);
extern void PININT7_IRQ(void);

__attribute__((naked)) 
void _unhandled_exception(void) {
    for(;;);
}

void NMI_Handler(void) __attribute__((weak, alias("_unhandled_exception")));
void HardFault_Handler(void) __attribute__((weak, alias("_unhandled_exception")));
void SVCall_Handler(void) __attribute__((weak, alias("_unhandled_exception")));
void PendSV_Handler(void) __attribute__((weak, alias("_unhandled_exception")));
void SysTick_Handler(void) __attribute__((weak, alias("_unhandled_exception")));

void SPI0_IRQ(void) __attribute__((weak, alias("_unhandled_exception")));
void SPI1_IRQ(void) __attribute__((weak, alias("_unhandled_exception")));
void UART0_IRQ(void) __attribute__((weak, alias("_unhandled_exception")));
void UART1_IRQ(void) __attribute__((weak, alias("_unhandled_exception")));
void UART2_IRQ(void) __attribute__((weak, alias("_unhandled_exception")));
void I2C0_IRQ(void) __attribute__((weak, alias("_unhandled_exception")));
void SCT_IRQ(void) __attribute__((weak, alias("_unhandled_exception")));
void MRT_IRQ(void) __attribute__((weak, alias("_unhandled_exception")));
void CMP_IRQ(void) __attribute__((weak, alias("_unhandled_exception")));
void WDT_IRQ(void) __attribute__((weak, alias("_unhandled_exception")));
void BOD_IRQ(void) __attribute__((weak, alias("_unhandled_exception")));
void WKT_IRQ(void) __attribute__((weak, alias("_unhandled_exception")));
void PININT0_IRQ(void) __attribute__((weak, alias("_unhandled_exception")));
void PININT1_IRQ(void) __attribute__((weak, alias("_unhandled_exception")));
void PININT2_IRQ(void) __attribute__((weak, alias("_unhandled_exception")));
void PININT3_IRQ(void) __attribute__((weak, alias("_unhandled_exception")));
void PININT4_IRQ(void) __attribute__((weak, alias("_unhandled_exception")));
void PININT5_IRQ(void) __attribute__((weak, alias("_unhandled_exception")));
void PININT6_IRQ(void) __attribute__((weak, alias("_unhandled_exception")));
void PININT7_IRQ(void) __attribute__((weak, alias("_unhandled_exception")));
