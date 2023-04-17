.LC0:
	.string  "%d\n"
	.text
	.globl main
System.println:
	pushq	%rbp
	movq	%rsp, %rbp
	movq	16(%rbp), %rsi
	leaq	.LC0(%rip), %rdi
	movq	$0, %rax
	call printf@PLT
	movq	$0, %rax
	movq	%rbp, %rsp
	popq	%rbp
	ret

test_5.foo:
	push	%rbp
	movq	%rsp, %rbp
	push	$0
	movq	24(%rbp), %r10
	movq	16(%rbp), %r11
	subq	%r11, %r10
	movq	%r10, -8(%rbp)
	movq	-8(%rbp), %r10
	movq	%r10, %rax
	movq	%rbp, %rsp
	popq	%rbp
	ret

main:
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
	push	$0
	movq	-16(%rbp), %r10
	push	%r10
	push	$2
	call	test_5.foo
	addq	$16, %rsp
	movq	%rax, %r11
	movq	%r11, -24(%rbp)
	movq	-24(%rbp), %r11
	push	%r11
	call	System.println
	addq	$8, %rsp
	movq	%rbp, %rsp
	popq	%rbp
	ret

