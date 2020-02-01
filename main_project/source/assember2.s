.THUMB
.ALIGN	2
.GLOBL test_function


.THUMB_FUNC
test_function:

push {r4-r7, lr}
	@assembly here

	ldr r4, [r0]
	add r4, #5
	str r4, [r0]

pop { r4-r7 }
pop { r3 }

bx r3


	