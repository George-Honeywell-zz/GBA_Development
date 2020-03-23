
#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
//#include <../../../../../devkitPro/libtonc/include/tonc_input.h>
#include <../../../../../devkitPro/libgba/include/gba_input.h>
#include <stdio.h>

#define KEY_MASK 0x03FF

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

	//Controller Input
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	


	// main loop
	while (1) 
	{
		VBlankIntrWait();
		scanKeys();
		u16 buttonPressed = keysDown();


		if (buttonPressed & KEY_A) {
			iprintf("\x1b[0;0HKeys Down.");
			iprintf("\x1b[1;0HA Key Pressed. %d", a);
			a++;
		}

		iprintf("\x1b[2;0H~~~~~~~~~~~~~~~");
		if (buttonPressed & KEY_B) {
			iprintf("\x1b[3;0HKeys Down Repeat.");
			iprintf("\x1b[4;0HB Key Pressed. %d", b);
			b++;
		}
		iprintf("\x1b[5;0H~~~~~~~~~~~~~~~");
		if (buttonPressed & KEY_L) {
			iprintf("\x1b[6;0HKeys Up.");
			iprintf("\x1b[7;0HR Key Pressed. %d", c);
			c++;
		}
		iprintf("\x1b[8;0H~~~~~~~~~~~~~~~");
		if (buttonPressed & KEY_R) {
			iprintf("\x1b[9;0HKeys Held.");
			iprintf("\x1b[10;0HL Key Pressed. %d", d);
			d++;
		}
	}
}


