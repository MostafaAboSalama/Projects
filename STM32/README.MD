<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Embedded C Baremetal Software Development on  STM32F103C8 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

Project Information : https://fringe-tugboat-68e.notion.site/Project-Title-Embedded-C-Baremetal-Software-Development-on-STM32F103C8-87f6dc76f02e4907bcd704b7a7dbba47


Project Main Steps :

1) Setup StartUp Code "Check startup.c".
2) Setup Linker Script "Check linkerScript.ld".
3) Implement main.c using the given drivers.
4) Setup makefile.
5) Create the schematic on proteus.

###############################################################################################################################################


Steps in Details:
1) StartUp Code :
                 # define StackStart (given)
                 # Implement Reset Handler (copy .data, initalize bss, call main)
                
2) Linker Script :
                 # Give Reset Hnadler to Entry.
                 # use MEMORY to define Flash, SRAM
                 # Use SECTION to instruct Startup Code.


3) Main.c :
                 # Initialize Clock, LCD.
                 # Declare instances from GPIO_PIN_CONFIG_T type.
                 # Use functions given in lcd.h, Stm32_F103C6_GPIO.h to do whatever you want.

4) makefile :
                 # get main.o using main.c
                 # get Stm32_F103C6_GPIO.o using Stm32_F103C6_GPIO.c
                 # get lcd.o using lcd.c
                 # get Startup.o using Startup.c
                 # get AboSalama.elf using main.o, Stm32_F103C6_GPIO.o, lcd.o, Startup.o
                 # get all using main.o, Stm32_F103C6_GPIO.o, lcd.o, Startup.o, AboSalama.elf
                 # make all to compile.

5) Proteus :
                 # Create a new project.
                 # Add LM016L, STM32, LEDS.
                 # Connect the pins correctly "Check lcd.h".
                 # Run.