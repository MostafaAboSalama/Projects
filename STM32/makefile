CC = arm-none-eabi-gcc
CFLAGS = -c -mcpu=$(ARCH) -std=gnu11 -mthumb
LDFLAGS = -T linkerScript.ld -nostdlib -Wl,-Map=AboSalama.map
ARCH = Cortex-M3

main.o: main.c
	$(CC) $(CFLAGS) $^ -o $@

Stm32_F103C6_GPIO.o: Stm32_F103C6_GPIO.c
	$(CC) $(CFLAGS) $^ -o $@

lcd.o: lcd.c
	$(CC) $(CFLAGS) $^ -o $@

Startup.o: startup.c
	$(CC) $(CFLAGS) $^ -o $@

AboSalama.elf: main.o Stm32_F103C6_GPIO.o lcd.o Startup.o
	$(CC) $(LDFLAGS) $^ -o $@

all:  main.o Stm32_F103C6_GPIO.o lcd.o Startup.o AboSalama.elf

clean:
	rm -rf *.o


