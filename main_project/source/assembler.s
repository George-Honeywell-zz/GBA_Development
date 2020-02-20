.THUMB				@ turn on thumb
.ALIGN  2			@ align code correctly for GBA
.GLOBL  my_function		@ name of function goes here




.THUMB_FUNC			@ we are about to declare a thumb function
my_function:		@ function start



push { r4-r7, lr }	@ push r4-r7 and link register onto stack. Your function might use these
					@ registers, so we need to preserve the values just in case!
					@ we dont need to worry about r0-r3 as it is assumed they will be regularly messed up anyway
	
@ Is to comment in Assembly.
@ the magic happens here!
@ r0-r3 will automatically contain the parameters sent when calling the function.

	@ ldr r4, [r0]		@ hopefully whichever function called this left a memory address in r0 - dereference value into r4
	@ add r4, #5		@ add 1 to value in r4
	@ str r4, [r0] 		@ store data in r4 at r0 address





pop { r4-r7 }		@ pop first 4 values from stack back into r4-r7, and also
pop { r3 }			@ pop the next value from stack (stored value for lr) into some unused register, e.g. r3 -
					@ we cannot overwrite lr so we have to do it via a normal register
bx r3				@ "branch and exchange" (return) back to C, using the previous value for lr stored in r3
@ ==================================
