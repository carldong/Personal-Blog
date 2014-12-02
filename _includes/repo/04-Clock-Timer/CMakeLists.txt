# Project CMake file for use in tutorial series
# Author: Rongcui Dong
# Original site: http://homepages.rpi.edu/~dongr2/
# License: Public Domain
# NO WARRENTY, of course
# Do whatever you like with this. Good if you acknowledge my name,
# but you are not required to do so

# CMake starts supporting cross compiling since 2.6
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

# Must be specified BEFORE the "PROJECT" line
SET(CMAKE_TOOLCHAIN_FILE "Toolchain-arm-none-eabi.cmake")

# Our project. Both C and ASM  exist
PROJECT("04-Clock-Timer" C ASM)

# The output files variables
SET(TGT "main")
SET(ELF "${TGT}.elf")
SET(HEX "${TGT}.hex")

# Information about the target device
SET(CPU "lpc810")
SET(FLASH "lpc21isp")
SET(PORT "/dev/ttyUSB0")
SET(BAUD 115200)
SET(KFREQ 12000)

# C Sources
SET (CSRC
  ${CMAKE_CURRENT_SOURCE_DIR}/main.c
  ${CMAKE_CURRENT_SOURCE_DIR}/${CPU}/vectors.c
  )

# Assembly Sources
SET (ASRC
  ${CMAKE_CURRENT_SOURCE_DIR}/${CPU}/crt0.S
  )

# Linker Script
SET(LDS
  ${CMAKE_CURRENT_SOURCE_DIR}/${CPU}/${CPU}.ld
  )

# Flags
SET(CMAKE_C_FLAGS
  "-O0 -mthumb -mcpu=cortex-m0plus -nostartfiles -ggdb"
  )

SET(CMAKE_ASM_FLAGS
  "${CMAKE_ASM_FLAGS} ${CMAKE_C_FLAGS}"
  )

SET(CMAKE_EXE_LINKER_FLAGS "-T\"${LDS}\" -nostdlib")

# Main ELF file
ADD_EXECUTABLE(${ELF}
  ${CSRC}
  ${ASRC}
  )

# To recompile when linker script is changed.
# Inspired by: http://www.cmake.org/pipermail/cmake/2010-May/037206.html
SET_SOURCE_FILES_PROPERTIES (
  main.c PROPERTIES OBJECT_DEPENDS ${LDS}
  )

# Make the HEX file, disassembly, symbol table
ADD_CUSTOM_COMMAND(OUTPUT ${HEX} ${TGT}.disasm ${TGT}.sym
  DEPENDS ${ELF}
  COMMAND ${OBJCOPY} ${ELF} -O ihex ${HEX}
  COMMAND ${OBJDUMP} -SD ${ELF} > ${TGT}.disasm
  COMMAND ${NM} -n ${ELF} > ${TGT}.sym
  COMMAND ${SIZE} ${ELF}
  VERBATIM)

# Make the hex target automatically invoked
ADD_CUSTOM_TARGET(hex ALL
  DEPENDS ${HEX}
  VERBATIM)

# The target to program the device
ADD_CUSTOM_TARGET(flash
  DEPENDS ${HEX}
  COMMAND ${FLASH} ${HEX} ${PORT} ${BAUD} ${KFREQ}
  VERBATIM)
