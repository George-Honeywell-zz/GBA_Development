
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
	unsigned int* ptr =  (unsigned int*)0x6000380; //'a'
	unsigned int* ptr2 = (unsigned int*)0x6000c40;
	//unsigned int* ptr3 = (unsigned int*)0x6000c60;
	//ptr[1] = 0001; 

	//0bXXXX can be used to change the colour value of each Pixel.
	//This is done from RIGHT to LEFT.
	//for (int i = 0; i < 8; i++) {
		//for (int j = 0; j < 8; j++) {
			ptr[0] = 0b0001 << 28;
			ptr[1] = 0b00000000000000000000000000000000;
			ptr[2] = 0b00000000000000000000000000000000;
			ptr[3] = 0b00000000000000000000000000000000;
			ptr[4] = 0b00000000000000000000000000000000;
			ptr[5] = 0b00000000000000000000000000000000;
			ptr[6] = 0b00000000000000000000000000000000;
			ptr[7] = 0b00000000000000000000000000000000;

			ptr2[0] = 0b00010000000000000000000000000001;
			ptr2[1] = 0b00010001000000000000000000010001;
			ptr2[2] = 0b00010000000100000000000100000001;
			ptr2[3] = 0b00010000000000010001000000000001;
			ptr2[4] = 0b00000001000100010001000100010000;
			ptr2[5] = 0b00000000000000000000000000000000;
			ptr2[6] = 0b00000000000100010001000100000000;
			ptr2[7] = 0b00000000000000000000000000000000;

			//ptr3[0] = 0b00000000000000010000000000000000;
			//ptr3[1] = 0b00000000000100010000000000000000;
			//ptr3[2] = 0b00000001000100010000000000000000;
			//ptr3[3] = 0b00010001000100010001000100010001;
			//ptr3[4] = 0b00000001000100010000000000000000;
			//ptr3[5] = 0b00000000000100010000000000000000;
			//ptr3[6] = 0b00000000000000010000000000000000;
			//ptr3[7] = 0b00000000000000000000000000000000;
			
		//}
	//}

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


