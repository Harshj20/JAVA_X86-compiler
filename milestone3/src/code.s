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
	call	test_10.ctor
	addq	$8, %rsp
	popq %r10
	movq	%rax, 16(%rbp)
	push	16(%rbp)
	call	main.2
	addq	$8, %rsp
	movq	%rbp, %rsp
	pop	%rbp
	ret
main.2:
	push	%rbp
	movq	%rsp, %rbp
	push	$0
	movq	$15, -8(%rbp)
L8:
	movq	$1, %r10
	test	%r10, %r10
	jnz	L.4
	jmp	L.1
L.4:
	movq	$10, %r11
	movq	$12, %rdx
	cmp	%r11, %rdx
	setg	%al
	movzbq	%al, %r11
	test	%r11, %r11
	jnz	L.2
	movq	$7, -8(%rbp)
	push	$0
	movq	$10, -16(%rbp)
	addq	$8, %rsp
	jmp	L8
	addq	$8, %rsp
	jmp	L.3
L.2:
	movq	$67, -8(%rbp)
	push	$0
	movq	$10, -16(%rbp)
	addq	$8, %rsp
	jmp	L.1
	addq	$8, %rsp
L.3:
	jmp	L8
L.1:
	pushq	%r10
	pushq	%r11
	push	-8(%rbp)
	push	$0
	call	System.println
	addq	$16, %rsp
	popq %r11
	popq %r10
L11:
	movq	$1, %r10
	test	%r10, %r10
	jnz	L.8
	jmp	L.5
L.8:
	movq	$10, %r12
	movq	$12, %rdx
	cmp	%r12, %rdx
	setl	%al
	movzbq	%al, %r11
	test	%r11, %r11
	jnz	L.6
	movq	$7, -8(%rbp)
	push	$0
	movq	$10, -16(%rbp)
	addq	$8, %rsp
	jmp	L.5
	addq	$8, %rsp
	jmp	L.7
L.6:
	movq	$67, -8(%rbp)
	push	$0
	movq	$10, -16(%rbp)
	addq	$8, %rsp
	jmp	L11
	addq	$8, %rsp
L.7:
	jmp	L11
L.5:
	pushq	%r10
	pushq	%r11
	push	-8(%rbp)
	push	$0
	call	System.println
	addq	$16, %rsp
	popq %r11
	popq %r10
	movq	$1, %rax
	movq	%rbp, %rsp
	popq	%rbp
	ret

test_10.ctor:
	push	%rbp
	movq	%rsp, %rbp
	movq	16(%rbp), %r12
	movq	%r12, %rax
	movq	%rbp, %rsp
	popq	%rbp
	ret
