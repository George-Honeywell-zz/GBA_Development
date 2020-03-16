
#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
//#include <../../../../../devkitPro/libtonc/include/tonc_input.h>
#include <../../../../../devkitPro/libgba/include/gba_input.h>
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

	//Controller Input
	scanKeys();
	u16 button;
	


	
	// main loop
	while (1) 
	{
		VBlankIntrWait();

		if (keysHeld(KEY_A & button)) {
			iprintf("\x1b[2;0HA Key Pressed.");
		}
	}
}


