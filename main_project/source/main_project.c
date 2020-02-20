
#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>

#include <stdio.h>


//extern void myfunc(int* answer);
extern void test_function(int* test, int* test2);
extern void add_variables(int* num_one, int* num_two, int* answer);
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

	//assembler2.s
	int test = 0;		//R0 - assembler2.s
	int test2 = 0;		//R1 - assembler2.s

	//assembler3.s
	int num_one = 15;	//R0 - add_variables.s
	int num_two = 74;	//R1 - add_variables.s
	int answer = 0;		//R2 - add_variables.s

	// main loop
	while (1) 
	{		
		//myfunc(&x); // this should update the value of x using the asm function
		test_function(&test, &test2);
		add_variables(&num_one, &num_two, &answer);

		// ansi escape sequence to set print co-ordinates
		// /x1b[line;columnH
		//printf("\x1b[10;10Hresult = %d", x);
		//printf("\x1b[5;5HResult of Test = %d", test);
		printf("\x1b[4;1Htest_function R0: %d", test);
		printf("\x1b[5;1Htest_function R1: %d", test2);

		printf("\x1b[8;1HAdd Variables");
		printf("\x1b[9;1HNumber One = %d", num_one);
		printf("\x1b[10;1HNumber Two = %d", num_two);
		printf("\x1b[11;1HTotal = %d", answer);





		VBlankIntrWait();
	}
}


