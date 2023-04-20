.LC0:
	.string  "%d\n"
	.text
	.globl main
System.println:
	pushq	%rbp
	movq	%rsp, %rbp
	movq	24(%rbp), %rsi
	leaq	.LC0(%rip), %rdi
	movq	$0, %rax
	call printf@PLT
	movq	$0, %rax
	movq	%rbp, %rsp
	popq	%rbp
	ret

Bicycle.ctor.2:
	push	%rbp
	movq	%rsp, %rbp
	push	16(%rbp)
	call	Bicycle.ctor
	addq	$8, %rsp
	movq	%rax, 16(%rbp)
	movq	16(%rbp), %r10
	addq	$0, %r10
	movq	24(%rbp), %r11
	movq	%r11, (%r10)
	movq	16(%rbp), %r10
	addq	$8, %r10
	movq	32(%rbp), %r11
	movq	%r11, (%r10)
	movq	16(%rbp), %r10
	movq	%r10, %rax
	movq	%rbp, %rsp
	popq	%rbp
	ret

Bicycle.applyBrake:
	push	%rbp
	movq	%rsp, %rbp
	movq	16(%rbp), %r10
	addq	$8, %r10
	movq	(%r10), %r10
	subq	24(%rbp), %r10
	movq	%r10, ()
	movq	%rbp, %rsp
	popq	%rbp
	ret

Bicycle.speedUp:
	push	%rbp
	movq	%rsp, %rbp
	movq	16(%rbp), 
	addq	$8, 
	movq	(), 
	addq	24(%rbp), 
	movq	, ()
	movq	%rbp, %rsp
	popq	%rbp
	ret

Bicycle.ctor:
	push	%rbp
	movq	%rsp, %rbp
	movq	16(%rbp), 
	movq	, %rax
	movq	%rbp, %rsp
	popq	%rbp
	ret
MountainBike.ctor.3:
	push	%rbp
	movq	%rsp, %rbp
	push	16(%rbp)
	call	MountainBike.ctor
	addq	$8, %rsp
	movq	%rax, 16(%rbp)
	movq	16(%rbp), 
	addq	$16, 
	movq	40(%rbp), %r10
	movq	%r10, ()
	movq	16(%rbp), 
	movq	, %rax
	movq	%rbp, %rsp
	popq	%rbp
	ret

MountainBike.setHeight:
	push	%rbp
	movq	%rsp, %rbp
	movq	16(%rbp), 
	addq	$16, 
	movq	24(%rbp), %r10
	movq	%r10, ()
	movq	%rbp, %rsp
	popq	%rbp
	ret

MountainBike.ctor:
	push	%rbp
	movq	%rsp, %rbp
	movq	16(%rbp), 
	movq	, %rax
	movq	%rbp, %rsp
	popq	%rbp
	ret
main:
	push	%rbp
	movq	%rsp, %rbp
	movq	$0, 
	movq	, %rdi
	call	malloc@PLT
	movq	%rax, 
	push	
	call	main.2
	addq	$8, %rsp
	movq	%rbp, %rsp
	pop	%rbp
	ret
main.2:
	push	%rbp
	movq	%rsp, %rbp
	push	$0
	movq	$24, 
	movq	, %rdi
	call	malloc@PLT
	movq	%rax, 
	push	$25
	push	$100
	push	$3
	push	
	call	MountainBike.ctor.3
	addq	$32, %rsp
	movq	%rax, 
	movq	, -8(%rbp)
	push	$0
	movq	-8(%rbp), 
	addq	$16, 
	movq	(), 
	movq	, -16(%rbp)
	push	-16(%rbp)
	push	$0
	call	System.println
	addq	$16, %rsp
	movq	%rbp, %rsp
	popq	%rbp
	ret

test_8.ctor:
	push	%rbp
	movq	%rsp, %rbp
	movq	16(%rbp), 
	movq	, %rax
	movq	%rbp, %rsp
	popq	%rbp
	ret
