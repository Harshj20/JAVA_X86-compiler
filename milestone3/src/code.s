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

main:
	push	%rbp
	movq	%rsp, %rbp
	push	$0
	movq	$2, %r10
	movq	$3, %rdx
	cmp	%r10, %rdx
	setl	%al
	movzbq	%al, %r10
	movq	%r10, -8(%rbp)
	push	$0
	movq	$2, -16(%rbp)
	movq	$4, %r10
	movq	$2, %rdx
	cmp	%r10, %rdx
	setl	%al
	movzbq	%al, %r10
	test	%r10, %r10
	jz	L-1
	jmp	L-2
L-1:
	movq	-16(%rbp), %r11
	push	%r11
	call	System.println
	addq	$8, %rsp
	addq	$0, %rsp
L-2:
	movq	%rbp, %rsp
	popq	%rbp
	ret

