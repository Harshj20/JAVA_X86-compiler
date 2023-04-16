foo:
	pushq	%rbp
	movq	%rsp, %rbp
	sub 	%rsp, 4
	movl	12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4(%rbp)
	movq	%rbp, %rsp
	popq	%rbp
	ret
.LC0:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
	pushq	%rbp
	movq	%rsp, %rbp
	sub 	%rsp, 4
	sub 	%rsp, 4
	sub 	%rsp, 4
	movl 	$10, -12(%rbp)
	call	foo
	cltq
	addq	$4, %rsp
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addl	$20, %eax
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %eax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rdi
	movq	$0, %rax
	call	printf@PLT
	movq	$0, %rax
	movq	%rbp, %rsp
	popq	%rbp
	ret
