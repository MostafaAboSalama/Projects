ENTRY (Reset_Handler)

MEMORY{
	FLASH(rx): ORIGIN = 0x08000000, LENGTH = 64K
	SRAM(rwx): ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
	.text :
	{
		*(.isr_vector)
		*(.text)
		*(.rodata)
		. = ALIGN(4);
		_etext = . ;
	} >FLASH
	
	.data :
	{
		_sdata = . ;
		*(sdata)
		. = ALIGN(4);
		_edata = . ;
	} >SRAM AT>FLASH
	
	.bss :
	{
		_sbss = . ;
		*(sbss)
		. = ALIGN(4);
		_ebss = . ;
	} >SRAM
	
}