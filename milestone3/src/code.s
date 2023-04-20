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
	push	%r10
	call	main.2
	addq	$8, %rsp
	movq	%rbp, %rsp
	pop	%rbp
	ret
main.2:
	push	%rbp
	movq	%rsp, %rbp
	push	$0
	movq	$3, %r10
	imulq	$3, %r10
	imulq	$8, %r10
	movq	%r10, %rdi
	call	malloc@PLT
	movq	%rax, %r10
	movq	%r10, -8(%rbp)
	movq	-8(%rbp), %r10
	movq	$0, %r11
	imulq	$3, %r11
	imulq	$8, %r11
	addq	%r11, %r10
	movq	$0, %r11
	imulq	$8, %r11
	addq	%r11, %r10
	movq	$1, (%r10)
	movq	-8(%rbp), %r11
	movq	$0, %r12
	imulq	$3, %r12
	imulq	$8, %r12
	addq	%r12, %r11
	movq	$1, %r12
	imulq	$8, %r12
	addq	%r12, %r11
	movq	$2, (%r11)
	movq	-8(%rbp), %r12
	movq	$0, %r13
	imulq	$3, %r13
	imulq	$8, %r13
	addq	%r13, %r12
	movq	$2, %r13
	imulq	$8, %r13
	addq	%r13, %r12
	movq	$3, (%r12)
	movq	-8(%rbp), %r13
	movq	$1, %r14
	imulq	$3, %r14
	imulq	$8, %r14
	addq	%r14, %r13
	movq	$0, %r14
	imulq	$8, %r14
	addq	%r14, %r13
	movq	$4, (%r13)
	movq	-8(%rbp), %r14
	movq	$1, %r15
	imulq	$3, %r15
	imulq	$8, %r15
	addq	%r15, %r14
	movq	$1, %r15
	imulq	$8, %r15
	addq	%r15, %r14
	movq	$5, (%r14)
	push	$0
	movq	$0, -16(%rbp)
	push	$0
	movq	$0, -24(%rbp)
L12:
	movq	-24(%rbp), %r15
	movq	$3, %rdx
	cmp	%r15, %rdx
	setg	%al
	movzbq	%al, %r15
	test	%r15, %r15
	jnz	L.4
	jmp	L.1
L.4:
	push	$0
	movq	$0, -32(%rbp)
L13:
	movq	-32(%rbp), %r8
	movq	$3, %rdx
	cmp	%r8, %rdx
	setg	%al
	movzbq	%al, %r15
	test	%r15, %r15
	jnz	L.3
	jmp	L.2
L.3:
	movq	-8(%rbp), %r8
	movq	-24(%rbp), %r14
	imulq	$3, %r14
	imulq	$8, %r14
	addq	%r14, %r8
	movq	-32(%rbp), %r14
	imulq	$8, %r14
	addq	%r14, %r8
	movq	-16(%rbp), %r14
	addq	(%r8), %r14
	movq	%r14, -16(%rbp)
	movq	-32(%rbp), %r15
	movq	-32(%rbp), %r14
	addq	$1, %r14
	movq	%r14, -32(%rbp)
	jmp	L13
L.2:
	movq	-24(%rbp), %r14
	movq	-24(%rbp), %r8
	addq	$1, %r8
	movq	%r8, -24(%rbp)
	jmp	L12
L.1:
	addq	$16, %rsp
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
	movq	16(%rbp), %r8
	movq	%r8, %rax
	movq	%rbp, %rsp
	popq	%rbp
	ret
