.LC0:
	.string  "%d\n"
PrintStream.println:
	pushq	%rbp
	movq	%rsp, %rbp
	movq	-8(%rbp), %rsi
	leaq	.LC0(%rip), %rdi
	movq	$0, %rax
	call	printf@PLT
	movq	$0, %rax
	movq	%rbp, %rsp
	popq	%rbp
	ret
Test.ctor:
	push	%rbp
	movq	%rsp, %rbp
	push	$0
	movq	$3, %r10
	imulq	$4, %r10
	addq	$2, %r10
	movq	%r10, -8(%rbp)
	push	$0
	movq	-8(%rbp), %r10
	imulq	$2, %r10
	movq	-8(%rbp), %r11
	imulq	$3, %r11
	addq	%r11, %r10
	movq	%r10, -16(%rbp)
	movq	8(%rbp), %r10
	subq	$0, (%r10)
	movq	(%r10), %r10
	movq	-16(%rbp), %r11
	push	%r11
	push	this
	call	PrintStream.println
	movq	$%rsp, %r12
	subq	$8, %r12
	movq	%rbp, %r12
	pop	%rbp
	ret
