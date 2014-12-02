/**
   This is the device header file for LPC810, for the
   LPC810 Cortex-M0+ Programming from Scratch
   tutorial series.
   
   Author: Rongcui Dong
   Originally posted: http://homepages.rpi.edu/~dongr2/

   License: Public Domain. No warrenty of any kind. Appreciated but not 
   required to keep my name
 */
#ifndef DEVICE_H
#define DEVICE_H

#include <inttypes.h>

#define __I volatile const
#define __O volatile
#define __IO volatile

/**
    @brief The structure of IOCON registers.
*/
typedef union {
  __IO uint32_t W;
  __IO uint16_t PIO;
} IOCON_TypeDef;

/**
   @brief The structures that groups all IOCON registers
 */

typedef struct {
  IOCON_TypeDef PIO0_17;
  IOCON_TypeDef PIO0_13;
  IOCON_TypeDef PIO0_12;
  IOCON_TypeDef PIO0_5;
  IOCON_TypeDef PIO0_4;
  IOCON_TypeDef PIO0_3;
  IOCON_TypeDef PIO0_2;
  IOCON_TypeDef PIO0_11;
  IOCON_TypeDef PIO0_10;
  IOCON_TypeDef PIO0_16;
  IOCON_TypeDef PIO0_15;
  IOCON_TypeDef PIO0_1;
  IOCON_TypeDef RESERVED;
  IOCON_TypeDef PIO0_9;
  IOCON_TypeDef PIO0_8;
  IOCON_TypeDef PIO0_7;
  IOCON_TypeDef PIO0_6;
  IOCON_TypeDef PIO0_0;
  IOCON_TypeDef PIO0_14;
} LPC_IOCON_TypeDef;

/**
   @brief Structure of GPIO port register
 */
typedef struct {
  struct {			/* Offset: 0x0000 */
    __IO uint8_t B0;
    __IO uint8_t B1;
    __IO uint8_t B2;
    __IO uint8_t B3;
    __IO uint8_t B4;
    __IO uint8_t B5;
    __IO uint8_t B6;
    __IO uint8_t B7;
    __IO uint8_t B8;
    __IO uint8_t B9;
    __IO uint8_t B10;
    __IO uint8_t B11;
    __IO uint8_t B12;
    __IO uint8_t B13;
    __IO uint8_t B14;
    __IO uint8_t B15;
    __IO uint8_t B16;
    __IO uint8_t B17;
  } PBYTE;

  uint8_t RESERVED0[0xFED];

  struct {			/* Offset: 0x1000 */
    __IO uint32_t W0;
    __IO uint32_t W1;
    __IO uint32_t W2;
    __IO uint32_t W3;
    __IO uint32_t W4;
    __IO uint32_t W5;
    __IO uint32_t W6;
    __IO uint32_t W7;
    __IO uint32_t W8;
    __IO uint32_t W9;
    __IO uint32_t W10;
    __IO uint32_t W11;
    __IO uint32_t W12;
    __IO uint32_t W13;
    __IO uint32_t W14;
    __IO uint32_t W15;
    __IO uint32_t W16;
    __IO uint32_t W17;
  } PWORD;

  uint8_t RESERVED1[0xFB8];
  __IO uint32_t DIR;			/* Offset: 0x2000 */
  uint8_t RESERVED2[0x7C];
  __IO uint32_t MASK;		/* Offset: 0x2080 */
  uint8_t RESERVED3[0x7C];
  __IO uint32_t PIN;			/* Offset: 0x2100 */
  uint8_t RESERVED4[0x7C];
  __IO uint32_t MPIN;
  uint8_t RESERVED5[0x7C];
  __IO uint32_t SET;
  uint8_t RESERVED6[0x7C];
  __O uint32_t CLR;
  uint8_t RESERVED7[0x7C];
  __O uint32_t NOT;
} LPC_GPIO_TypeDef;

/**
   @brief Struct of Switch Matrix
 */
typedef struct {
  __IO uint32_t PINASSIGN0;
  __IO uint32_t PINASSIGN1;
  __IO uint32_t PINASSIGN2;
  __IO uint32_t PINASSIGN3;
  __IO uint32_t PINASSIGN4;
  __IO uint32_t PINASSIGN5;
  __IO uint32_t PINASSIGN6;
  __IO uint32_t PINASSIGN7;
  __IO uint32_t PINASSIGN8;
  uint8_t RESERVED9[0x19C];
  __IO uint32_t PINENABLE0;
} LPC_SWM_TypeDef;

/**
   @brief System configuration registers (SYSCON)
   @note Base address 0x40048000
 */
typedef struct {
  __IO uint32_t SYSTEMREMAP;	/* 0x000 */
  __IO uint32_t PRESETCTRL;	/* 0x004 */
  __IO uint32_t SYSPLLCTRL;	/* 0x008 */
  __I uint32_t SYSPLLSTAT;	/* 0x00C */
  uint8_t RESERVED1[0x010];
  __IO uint32_t SYSOSCCTRL;	/* 0x020 */
  __IO uint32_t WDTOSCCTRL;	/* 0x024 */
  uint8_t RESERVED2[0x008];
  __IO uint32_t SYSRSTSTAT;	/* 0x030 */
  uint8_t RESERVED3[0x00C];
  __IO uint32_t SYSPLLCLKSEL;	/* 0x040 */
  __IO uint32_t SYSPLLCLKUEN;	/* 0x044 */
  uint8_t RESERVED4[0x028];
  __IO uint32_t MAINCLKSEL;	/* 0x070 */
  __IO uint32_t MAINCLKUEN;	/* 0x074 */
  __IO uint32_t SYSAHBCLKDIC;	/* 0x078 */
  uint8_t RESERVED5[0x004];
  __IO uint32_t SYSAHBCLKCTRL;	/* 0x080 */
  uint8_t RESERVED6[0x010];
  __IO uint32_t UARTCLKDIV;	/* 0x094 */
  uint8_t RESERVED7[0x048];
  __IO uint32_t CLKOUTSEL;	/* 0x0E0 */
  __IO uint32_t CLKOUTUEN;	/* 0x0E4 */
  __IO uint32_t CLKOUTDIV;	/* 0x0E8 */
  uint8_t RESERVED8[0x004];
  __IO uint32_t UARTFRGDIV;	/* 0x0F0 */
  __IO uint32_t UARTFRGMULT;	/* 0x0F4 */
  uint8_t RESERVED9[0x004];
  __IO uint32_t EXTTRACECMD;	/* 0x0FC */
  __I uint32_t PIOPORCAP0;	/* 0x100 */
  uint8_t RESERVED10[0x030];
  __IO uint32_t IOCONCLKDIV6;	/* 0x134 */
  __IO uint32_t IOCONCLKDIV5;	/* 0x138 */
  __IO uint32_t IOCONCLKDIV4;	/* 0x13C */
  __IO uint32_t IOCONCLKDIV3;	/* 0x140 */
  __IO uint32_t IOCONCLKDIV2;	/* 0x144 */
  __IO uint32_t IOCONCLKDIV1;	/* 0x148 */
  __IO uint32_t IOCONCLKDIV0;	/* 0x14C */
  __IO uint32_t BODCTRL;	/* 0x150 */
  __IO uint32_t SYSTCKCAL;	/* 0x154 */
  uint8_t RESERVED11[0x018];
  __IO uint32_t IRQLATENCY;	/* 0x170 */
  __IO uint32_t NMISRC;		/* 0x174 */
  __IO uint32_t PINTSEL0;	/* 0x178 */
  __IO uint32_t PINTSEL1;	/* 0x17C */
  __IO uint32_t PINTSEL2;	/* 0x180 */
  __IO uint32_t PINTSEL3;	/* 0x184 */
  __IO uint32_t PINTSEL4;	/* 0x188 */
  __IO uint32_t PINTSEL5;	/* 0x18C */
  __IO uint32_t PINTSEL6;	/* 0x190 */
  __IO uint32_t PINTSEL7;	/* 0x194 */
  uint8_t RESERVED12[0x06C];
  __IO uint32_t STARTERP0;	/* 0x204 */
  uint8_t RESERVED13[0x00C];
  __IO uint32_t STARTERP1;	/* 0x214 */
  uint8_t RESERVED14[0x018];
  __IO uint32_t PDSLEEPCFG;	/* 0x230 */
  __IO uint32_t PDAWAKECFG;	/* 0x234 */
  __IO uint32_t PDRUNCFG;	/* 0x238 */
  uint8_t RESERVED15[0x1BC];
  __I uint32_t DEVICE_ID;	/* 0x3F8 */
} LPC_SYSCON_TypeDef;

/* Device Registers */
#define SYSCON ((LPC_SYSCON_TypeDef *) 0x40048000UL)
#define IOCON ((LPC_IOCON_TypeDef *) 0x40044000UL)
#define GPIO0 ((LPC_GPIO_TypeDef *) 0xA0000000UL)
#define SWM ((LPC_SWM_TypeDef *) 0x4000C000UL)

#endif // DEVICE_H
