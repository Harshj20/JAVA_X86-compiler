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
	movq	$1, -8(%rbp)
L8:
	push	-8(%rbp)
	push	$0
	call	System.println
	addq	$16, %rsp
	movq	-8(%rbp), %r10
	addq	$1, %r10
	movq	%r10, -8(%rbp)
	movq	-8(%rbp), %r10
	movq	$6, %rdx
	cmp	%r10, %rdx
	setg	%al
	movzbq	%al, %r10
	test	%r10, %r10
	jnz	L.2
	jmp	L.1
L.2:
	jmp	L8
L.1:
	push	$0
	movq	$21, -16(%rbp)
	push	$0
	movq	$0, -24(%rbp)
L9:
	movq	-24(%rbp), %r11
	addq	-16(%rbp), %r11
	movq	%r11, %r10
	movq	%r10, -24(%rbp)
	movq	-16(%rbp), %r10
	subq	$1, %r10
	movq	%r10, -16(%rbp)
	movq	-16(%rbp), %r10
	movq	$10, %rdx
	cmp	%r10, %rdx
	setl	%al
	movzbq	%al, %r10
	test	%r10, %r10
	jnz	L.4
	jmp	L.3
L.4:
	jmp	L9
L.3:
	pushq	%r10
	push	-24(%rbp)
	push	$0
	call	System.println
	addq	$16, %rsp
	popq %r10
	movq	%rbp, %rsp
	popq	%rbp
	ret

test_15.ctor:
	push	%rbp
	movq	%rsp, %rbp
	movq	16(%rbp), %r11
	movq	%r11, %rax
	movq	%rbp, %rsp
	popq	%rbp
	ret
