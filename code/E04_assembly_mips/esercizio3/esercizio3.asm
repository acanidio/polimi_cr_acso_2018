	.data

	.text
	addi	$s0, $zero, 2
A:	slt	$s2, $s0, $s1
	beq	$s2, $zero, B
	addi	$s1, $s0, -3
	j	A
B:	mul	$s0, $s1, $s0
