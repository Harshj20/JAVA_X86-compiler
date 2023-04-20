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

main:
	push	%rbp
	movq	%rsp, %rbp
	push	$0
	movq	$14, -8(%rbp)
	push	$0
	movq	%r10, -16(%rbp)
	push	-8(%rbp)
	push	$0
	call	System.println
	addq	$16, %rsp
	push	-16(%rbp)
	push	$0
	call	System.println
	addq	$16, %rsp
	movq	%rbp, %rsp
	popq	%rbp
	ret

test_15.ctor:
	push	%rbp
	movq	%rsp, %rbp
	movq	16(%rbp), %r10
	movq	%r10, %rax
	movq	%rbp, %rsp
	popq	%rbp
	ret
