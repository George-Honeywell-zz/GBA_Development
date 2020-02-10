
#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>

#include <stdio.h>


//extern void myfunc(int* answer);
extern void my_function(int* x, int* y, int* total);
//extern void test_function(int* result);
// need "extern" because the function body is in an external .s file

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

	// ansi escape sequence to clear screen and home cursor
	// /x1b[line;columnH
	iprintf("\x1b[2J");


	int x = 1;		//R0 
	int y = 2;		//R1
	int total = 0;	//R2

	
	// main loop
	while (1) 
	{		
		//myfunc(&x); // this should update the value of x using the asm function
		//test_function(&test);
		my_function(&x, &y, &total);

		// ansi escape sequence to set print co-ordinates
		// /x1b[line;columnH
		//printf("\x1b[10;10Hresult = %d", x);
		//printf("\x1b[5;5HResult of Test = %d", test);
		printf("\x1b[1;1HX = %d", x);
		printf("\x1b[2;1HY = %d", y);
		printf("\x1b[3;1HTotal = %d", total);



		VBlankIntrWait();
	}
}


