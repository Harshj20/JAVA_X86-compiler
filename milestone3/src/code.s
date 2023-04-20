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

test_13.fib:
	push	%rbp
	movq	%rsp, %rbp
	movq	24(%rbp), %r10
	movq	$1, %rdx
	cmp	%r10, %rdx
	setge	%al
	movzbq	%al, %r10
	test	%r10, %r10
	jnz	L.1
	jmp	L.2
L.1:
	movq	24(%rbp), %r11
	movq	%r11, %rax
	movq	%rbp, %rsp
	popq	%rbp
	ret
L.2:
	pushq	%r10
	movq	24(%rbp), %r11
	subq	$1, %r11
	push	%r11
	push	16(%rbp)
	call	test_13.fib
	addq	$16, %rsp
	popq %r10
	movq	%rax, %r11
	pushq	%r10
	pushq	%r11
	movq	24(%rbp), %r12
	subq	$2, %r12
	push	%r12
	push	16(%rbp)
	call	test_13.fib
	addq	$16, %rsp
	popq %r11
	popq %r10
	movq	%rax, %r12
	addq	%r12, %r11
	movq	%r11, %rax
	movq	%rbp, %rsp
	popq	%rbp
	ret

main:
	push	%rbp
	movq	%rsp, %rbp
	movq	$0, %r11
	movq	%r11, %rdi
	call	malloc@PLT
	movq	%rax, %r11
	pushq	%r10
	pushq	%r11
	push	%r11
	call	main.2
	addq	$8, %rsp
	popq %r11
	popq %r10
	movq	%rbp, %rsp
	pop	%rbp
	ret
main.2:
	push	%rbp
	movq	%rsp, %rbp
	push	$0
	movq	$9, -8(%rbp)
	pushq	%r10
	pushq	%r10
	push	-8(%rbp)
	push	16(%rbp)
	call	test_13.fib
	addq	$16, %rsp
	popq %r10
	movq	%rax, %r11
	push	%r11
	push	$0
	call	System.println
	addq	$16, %rsp
	popq %r10
	movq	%rbp, %rsp
	popq	%rbp
	ret

test_13.ctor:
	push	%rbp
	movq	%rsp, %rbp
	movq	16(%rbp), %r11
	movq	%r11, %rax
	movq	%rbp, %rsp
	popq	%rbp
	ret
