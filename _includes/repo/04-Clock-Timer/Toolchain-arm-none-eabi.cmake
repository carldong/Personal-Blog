# Toolchain for arm-none-eabi
# Author: Rongcui Dong
# Original site: http://homepages.rpi.edu/~dongr2/
# License: Public Domain
# NO WARRENTY, of course
# Do whatever you like with this. Good if you acknowledge my name,
# but you are not required to do so
#
# Inspired by:
# http://www.vtk.org/Wiki/CMake_Cross_Compiling#The_toolchain_file
# http://stackoverflow.com/questions/15132185/mixing-c-sources-and-assembly-source-and-build-with-cmake
#
# Rewritten by me
INCLUDE(CMakeForceCompiler)

SET(CMAKE_SYSTEM_NAME Generic)

# Set the correct toolchain. arm-elf might work, I haven't tested
CMAKE_FORCE_C_COMPILER(arm-none-eabi-gcc GNU)
CMAKE_FORCE_CXX_COMPILER(arm-none-eabi-g++ GNU)
SET(OBJCOPY arm-none-eabi-objcopy)
SET(OBJDUMP arm-none-eabi-objdump)
SET(NM arm-none-eabi-nm)
SET(SIZE arm-none-eabi-size)

# Add your toolchain install path if you like.
#SET(CMAKE_FIND_ROOT_PATH /opt/arm-none-eabi-toolchain)

SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY BOTH)
SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE BOTH)

# Enable preprocessor on assembly files
SET(ASM_OPTIONS "-x assembler-with-cpp")
# Assembler Flags
SET(CMAKE_ASM_FLAGS "${CMAKE_C_CFLAGS} ${ASM_OPTIONS}")