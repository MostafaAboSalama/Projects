CC = arm-none-eabi-
CFLAGS = -g -gdwarf-2 -mcpu=cortex-m3
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
PROJECT_NAME = FirstTermProject1

all: $(PROJECT_NAME).bin
	@echo "========== Build Done ============="


%.o: %.c
	$(CC)gcc.exe $(CFLAGS) -c $< -o $@
	
$(PROJECT_NAME).elf: $(OBJ)
	$(CC)ld.exe  -T linker_script.ld $(OBJ) -o $@ -Map=MapFile
	
$(PROJECT_NAME).bin: $(PROJECT_NAME).elf 
	$(CC)objcopy.exe  -O binary $<  $@
	
clean_all:
	rm *.elf *.bin *.o

clean:
	rm *.elf *.bin