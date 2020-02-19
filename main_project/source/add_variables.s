.THUMB
.ALIGN 2
.GLOBL add_variables

.THUMB_FUNC
add_variables:

push {r4-r7, lr}
	@assembly here

	ldr r2, [r0]
	ldr r1, [r1]
	add r0, r1, r2
	str r2, [r1]

	




pop {r4-r7}
pop {r3}
bx r3