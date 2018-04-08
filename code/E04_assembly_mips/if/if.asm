	.data

	.text
	addi	$s0, $zero, 1
	addi	$s1, $zero, 3
	add	$s0, $s0, $s1
	sgt	$s2, $s0, $s1
	bne	$s2, $zero, end
	add	$s1, $s1, $s0
end:	