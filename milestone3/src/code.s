Test.ctor:
	push rbp
	movq	rsp, rbp
	movq	16(%rbp), %r10
	movq	, 
	addq	0, 
	movq	%r10, (%r11)
	movq	24(%rbp), %r12
	movq	, 
	addq	8, 
	movq	%r12, (%r13)
	push $0
	movq	16(%rbp), %r14
	movq	%r14, %r15
	addq	$1, %r15
	addq	$3, %r15
	t3 = cast_to_int 3.0
	addq	, %r15
	movq	%r15, -8(%rbp)
	push $0
	movq	$3, 
	imulq	$4, 
	addq	$2, 
	movq	, -16(%rbp)
	push $0
	movq	-16(%rbp), 
	imulq	$2, 
	movq	-16(%rbp), %r15
	imulq	$3, %r15
	addq	%r15, 
	movq	, %r15
	movq	%r15, -24(%rbp)
	movq	rbp, rsp
	pop rbp
	ret
Test.display:
	push rbp
	movq	rsp, rbp
	movq	8(%rbp), 
	subq	$0, ()
	movq	(), 
	addq	$0, 
	t4 = cast_to_string t3
	t5 = "a = " +string t4
	t6 = t5 +string " b = "
	addq	$8, 
	t8 = cast_to_string t7
	addq	, 
	push t9
	push t1
	call PrintStream.println
	movq	$rsp, 
	subq	$8, 
	movq	rbp, 
	pop rbp
	ret
Test.main:
	push rbp
	movq	, rbp
	push $0
	movq	16, %r15
	t3 = allocate t2
	push 10
	push 20
	push t3
	Call Test.ctor
	movq	$rsp, %r8
	subq	$16, %r8
	movq	, -24(%rbp)
	movq	-24(%rbp), 
	push this
	call Test.display
	movq	rbp, %r8
	pop rbp
	ret
