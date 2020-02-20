.THUMB
.ALIGN	2
.GLOBL test_function


.THUMB_FUNC
test_function:

push {r4-r7, lr}
	@assembly here

	@ ~~~ Increases the TEST variable by 5 with each loop.
	ldr r5, [r0]
	add r5, #1
	str r5, [r0]

	ldr r5, [r1]
	add r5, #2
	str r5, [r1]

	@ ~~~ Testing assembly FOR loop. Branching & Comparing
	

	@ ~~~ LDR Practice


pop { r4-r7 }
pop { r3 }

bx r3


	