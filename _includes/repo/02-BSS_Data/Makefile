TGT = main
CSRC =
ASRC =
ASRC += crt0.S
CSRC += main.c
CSRC += vectors.c
LDS = ./LPC810/lpc810.ld

OBJS = $(CSRC:.c=.o)
OBJS += $(ASRC:.S=.o)

CC=arm-none-eabi-gcc
LD=arm-none-eabi-gcc
OBJCOPY=arm-none-eabi-objcopy
OBJDUMP=arm-none-eabi-objdump
NM=arm-none-eabi-nm
SIZE=arm-none-eabi-size

FLASH = lpc21isp
PORT = /dev/ttyUSB0
BAUD = 115200
KFREQ = 12000

CFLAGS=-O0 -mthumb -mcpu=cortex-m0plus -nostartfiles -ggdb
LDFLAGS=-Wl,-T$(LDS),-nostdlib,-Map=$(TGT).map

all: $(TGT).hex

%.o: %.S
	$(CC) $(CFLAGS) -c $^ -o $@

$(TGT).elf: $(OBJS)
	$(LD) $(CFLAGS) $(LDFLAGS) $^ -o $@

$(TGT).hex: $(TGT).elf
	$(OBJCOPY) $< -O ihex $@
	$(OBJDUMP) -SD $< > $(TGT).disasm
	$(NM) -n $(TGT).elf > $(TGT).sym
	$(SIZE) $(TGT).elf

clean:
	rm -rf *.elf *.hex *.map *.o *.disasm

flash:
	$(FLASH) $(TGT).hex $(PORT) $(BAUD) $(KFREQ)
