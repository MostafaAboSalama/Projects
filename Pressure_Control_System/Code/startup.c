/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    startup.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Author  : Mostafa AboSalama
 *
 */  
 
#include <stdint.h>

extern int main();

extern uint32_t _E_text;
extern uint32_t _S_data;
extern uint32_t _E_data;
extern uint32_t _S_bss;
extern uint32_t _E_bss;
extern uint32_t _stackTop;

void Reset_HANDLER();

void Default_HANDLER()
{
	Reset_HANDLER();
}

void NMI_HANDLER	  (void) __attribute__((weak, alias("Default_HANDLER")));
void HardFault_HANDLER(void) __attribute__((weak, alias("Default_HANDLER")));
void MemManage_HANDLER(void) __attribute__((weak, alias("Default_HANDLER")));
void BusFault_HANDLER (void) __attribute__((weak, alias("Default_HANDLER")));

uint32_t VectorsSection[] __attribute__((section(".vectors"))) = 
{
	(uint32_t) &_stackTop,
	(uint32_t) &NMI_HANDLER		  ,
	(uint32_t) &HardFault_HANDLER ,
	(uint32_t) &MemManage_HANDLER ,
	(uint32_t) &BusFault_HANDLER 
};

void Reset_HANDLER()
{
	uint8_t* PSrc =  (uint8_t*)(&_E_text);
	uint8_t* PDest = (uint8_t*)(&_S_data);
	uint32_t dataSize = (uint32_t*)(&_E_data) - (uint32_t*)(&_S_data);
	
	for(uint32_t i = 0; i < dataSize; i++)
	{
		*PDest = *PSrc;
		PDest++;
		PSrc++;
	}
	
	uint8_t* PStart =  (uint8_t*)(&_S_bss);
	uint32_t bssSize = (uint32_t*)(&_E_bss) - (uint32_t*)(&_S_bss);
	for(uint32_t i = 0; i < bssSize; i++)
	{
		*PStart = 0;
		PStart++;
	}
	
	main();
}
