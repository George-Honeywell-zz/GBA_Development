
#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>

#include <stdio.h>

//---------------------------------------------------------------------------------
// Program entry point
//---------------------------------------------------------------------------------
int main(void) {
//---------------------------------------------------------------------------------

	// the vblank interrupt must be enabled for VBlankIntrWait() to work
	irqInit();
	irqEnable(IRQ_VBLANK);

	// generic setup function
	consoleDemoInit();


	/*
		ptr[0] - assuming this is the 'row' it's on.
		ptr[0] shows a black dot in the top left hand corner. First row.
		ptr[1] shows a black dot in the top left hand corner. Second Row.
		etc...

		= 0000 - shows the dot in the emulator as BLACK
		= 0001 - shows the dot in the emulator as WHITE
	*/
	unsigned int* ptr = (unsigned int*)0x6000c20; //'a'
	//ptr[1] = 0001; 

	//0bXXXX can be used to change the colour value of each Pixel.
	//This is done from RIGHT to LEFT.
	ptr[4] = 0b00010000000100000001000000010000;

	// main loop
	while (1) 
	{
		// ansi escape sequence to clear screen and home cursor
		// /x1b[line;columnH
		iprintf("\x1b[2J");

		// ansi escape sequence to set print co-ordinates
		// /x1b[line;columnH
		iprintf("\x1b[2;0Ha b c d e f g h i j\nk l m n o p q r\ns t u v w x y z");



	
		VBlankIntrWait();
	}
}


