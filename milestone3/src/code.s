Test.ctor:
	push rbp
	movq	rsp, rbp
	push $0
	movq	$3, %r10
	imulq	$4, %r10
	addq	$2, %r10
	movq	%r10, -8(%rbp)
	push $0
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
	push t3
	push this
	call PrintStream.println
	movq	$rsp, %r12
	subq	$8, %r12
	movq	rbp, %r12
	pop rbp
	ret
