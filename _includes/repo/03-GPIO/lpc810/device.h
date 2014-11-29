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
} GPIO_TypeDef;

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
  uint32_t RESERVED9;
  __IO uint32_t PINENABLE0;
} SWM_TypeDef;

#define IOCON ((LPC_IOCON_TypeDef *) ((uint32_t) 0x40044000))
#define GPIO0 ((GPIO_TypeDef *) ((uint32_t) 0xA0000000))
#define SWM ((SWM_TypeDef *) ((uint32_t) 0x4000C000))

#endif // DEVICE_H
