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

Add.set:
	push	%rbp
	movq	%rsp, %rbp
	movq	16(%rbp), %r10
	addq	$0, %r10
	movq	24(%rbp), %r11
	movq	%r11, (%r10)
	movq	%rbp, %rsp
	popq	%rbp
	ret

Add.ctor.2:
	push	%rbp
	movq	%rsp, %rbp
	movq	24(%rbp), %r10
	addq	32(%rbp), %r10
	movq	16(%rbp), %r11
	addq	$0, %r11
	movq	%r10, (%r11)
	movq	16(%rbp), %r10
	movq	%r10, %rax
	movq	%rbp, %rsp
	popq	%rbp
	ret

Add.sum:
	push	%rbp
	movq	%rsp, %rbp
	movq	24(%rbp), %r10
	addq	32(%rbp), %r10
	movq	%r10, %rax
	movq	%rbp, %rsp
	popq	%rbp
	ret

Add.ctor:
	push	%rbp
	movq	%rsp, %rbp
	movq	16(%rbp), %r10
	movq	%r10, %rax
	movq	%rbp, %rsp
	popq	%rbp
	ret
main:
	push	%rbp
	movq	%rsp, %rbp
	movq	$0, %r10
	movq	%r10, %rdi
	call	malloc@PLT
	movq	%rax, %r10
	pushq	%r10
	push	%r10
	call	main.2
	addq	$8, %rsp
	popq %r10
	movq	%rbp, %rsp
	pop	%rbp
	ret
main.2:
	push	%rbp
	movq	%rsp, %rbp
	push	$0
	movq	$16, %r10
	movq	%r10, %rdi
	call	malloc@PLT
	movq	%rax, %r10
	pushq	%r10
	push	%r10
	call	Add.ctor
	addq	$8, %rsp
	popq %r10
	movq	%rax, %r10
	movq	%r10, -8(%rbp)
	push	$10
	push	-8(%rbp)
	call	Add.set
	addq	$16, %rsp
	push	$0
	movq	-8(%rbp), %r10
	addq	$0, %r10
	movq	(%r10), %r10
	addq	$1, %r10
	pushq	%r10
	push	$20
	push	$10
	push	$0
	call	Add.sum
	addq	$24, %rsp
	popq %r10
	movq	%rax, %r11
	addq	%r11, %r10
	movq	%r10, -16(%rbp)
	push	-16(%rbp)
	push	$0
	call	System.println
	addq	$16, %rsp
	movq	%rbp, %rsp
	popq	%rbp
	ret

test_14.ctor:
	push	%rbp
	movq	%rsp, %rbp
	movq	16(%rbp), %r10
	movq	%r10, %rax
	movq	%rbp, %rsp
	popq	%rbp
	ret
