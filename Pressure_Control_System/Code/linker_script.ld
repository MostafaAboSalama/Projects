/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    linker_script.ld    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 * Author  : Mostafa AboSalama
 *
 */  
 
MEMORY
{
	FLASH(rx): ORIGIN = 0x08000000	LENGTH = 128K 
	SRAM(rwx): ORIGIN = 0x20000000	LENGTH = 20K 
}

SECTIONS
{
	.text : 
	{
		*(.vectors)
		*(.text)
		_E_text = .;
		. = ALIGN(4);
	}>FLASH
	
	.data : 
	{
		_S_data = .;
		*(.data)
		_E_data = .;
		. = ALIGN(4);
	}>SRAM AT > FLASH
	
	.bss : 
	{
		_S_bss = .;
		*(.bss)
		_E_bss = .;
		. = ALIGN(4);
	}>SRAM	
	
	. = . + 0x1000;
	. = ALIGN(4);
	_stackTop = .;
}