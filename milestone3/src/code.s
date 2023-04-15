test_16.main:
	push rbp
	mov	rsp, rbp
	push $0
	mov	0, -8(%ebp)
	push $0
	push $0
	mov	-8(%ebp), t2
	test t3, t3
	jz L-1
	mov	-8(%ebp), t5
	add	(t5), 1
	mov	t6, 1
	mov	t6, t8
	jmp L-2
L-1:
	mov	-24(%ebp), t4
	mov	(t4), t8
L-2:
	mov	-16(%ebp), t1
	mov	t8, (t1)
	mov	-8(%ebp), t0
	mov	(t1), (t0)
	imul	10, 11
	mov	t0, 11
	imul	t0, 12
	mov	t1, 12
	imul	t1, 8
	mov	t2, 8
	t3 = allocate t2
	mov	t3, -32(%ebp)
	mov	-32(%ebp), t1
	mov	(t1), t2
	mov	4, t3
	imul	t3, 11
	mov	t3, 11
	imul	t3, 12
	mov	t3, 12
	imul	t3, 8
	mov	t3, 8
	add	t2, t3
	mov	t2, t3
	mov	t2, t4
	mov	5, t5
	imul	t5, 12
	mov	t5, 12
	imul	t5, 8
	mov	t5, 8
	add	t4, t5
	mov	t4, t5
	mov	t4, t13
	mov	-32(%ebp), t6
	mov	(t6), t7
	mov	2, t8
	imul	t8, 11
	mov	t8, 11
	imul	t8, 12
	mov	t8, 12
	imul	t8, 8
	mov	t8, 8
	add	t7, t8
	mov	t7, t8
	mov	t7, t9
	mov	2, t10
	imul	t10, 12
	mov	t10, 12
	imul	t10, 8
	mov	t10, 8
	add	t9, t10
	mov	t9, t10
	mov	t9, t11
	mov	3, t12
	imul	t12, 8
	mov	t12, 8
	add	t11, t12
	mov	t11, t12
	mov	(t11), t14
	imul	t14, 8
	mov	t14, 8
	add	t13, t14
	mov	t13, t14
	mov	-16(%ebp), t0
	mov	(t13), (t0)
	mov	rbp, rsp
	pop rbp
	ret
