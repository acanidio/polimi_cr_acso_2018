	.data
v:	.word	1, 2, 3, 4, 5
	.text
init:	add 	$s0, $zero, $zero
cond:	slti 	$s1, $s0, 5
	beq	$s1, $zero, end
	la	$s2, v
	sll	$s3, $s0, 2
	add	$s3, $s3, $s2
	lw	$s4, ($s3)
	mul	$s4, $s4, 2
	sw	$s4, ($s3)
inc:	addi	$s0, $s0, 1
	b	cond
end: