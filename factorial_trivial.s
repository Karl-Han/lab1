	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 12, 0	sdk_version 12, 3
	.globl	__Z19factorial_recursioni       ## -- Begin function _Z19factorial_recursioni
	.p2align	4, 0x90
__Z19factorial_recursioni:              ## @_Z19factorial_recursioni
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	%edi, -8(%rbp)
	cmpl	$0, -8(%rbp)
	jne	LBB0_2
## %bb.1:
	movl	$1, -4(%rbp)
	jmp	LBB0_3
LBB0_2:
	movl	-8(%rbp), %eax
	movl	%eax, -12(%rbp)                 ## 4-byte Spill
	movl	-8(%rbp), %edi
	subl	$1, %edi
	callq	__Z19factorial_recursioni
	movl	%eax, %ecx
	movl	-12(%rbp), %eax                 ## 4-byte Reload
	imull	%ecx, %eax
	movl	%eax, -4(%rbp)
LBB0_3:
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	__Z14factorial_loopi            ## -- Begin function _Z14factorial_loopi
	.p2align	4, 0x90
__Z14factorial_loopi:                   ## @_Z14factorial_loopi
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
	movl	$1, -8(%rbp)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$0, -4(%rbp)
	jle	LBB1_3
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	movl	-4(%rbp), %eax
	imull	-8(%rbp), %eax
	movl	%eax, -8(%rbp)
	movl	-4(%rbp), %eax
	addl	$-1, %eax
	movl	%eax, -4(%rbp)
	jmp	LBB1_1
LBB1_3:
	movl	-8(%rbp), %eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_main                           ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	cmpl	$1, -8(%rbp)
	jne	LBB2_2
## %bb.1:
	leaq	L_.str(%rip), %rdi
	leaq	-20(%rbp), %rsi
	movb	$0, %al
	callq	_scanf
	jmp	LBB2_6
LBB2_2:
	movq	$0, -32(%rbp)
	movq	-16(%rbp), %rax
	movq	8(%rax), %rdi
	movq	-32(%rbp), %rsi
	movl	$10, %edx
	callq	_strtol
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rax
                                        ## kill: def $eax killed $eax killed $rax
	movl	%eax, -20(%rbp)
	movl	-20(%rbp), %esi
	leaq	L_.str.1(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movslq	-20(%rbp), %rax
	cmpq	-40(%rbp), %rax
	sete	%al
	xorb	$-1, %al
	testb	$1, %al
	jne	LBB2_3
	jmp	LBB2_4
LBB2_3:
	leaq	L___func__.main(%rip), %rdi
	leaq	L_.str.2(%rip), %rsi
	leaq	L_.str.3(%rip), %rcx
	movl	$40, %edx
	callq	___assert_rtn
LBB2_4:
	jmp	LBB2_5
LBB2_5:
	jmp	LBB2_6
LBB2_6:
	movl	-20(%rbp), %edi
	callq	__Z19factorial_recursioni
	movl	%eax, -44(%rbp)
	movl	-20(%rbp), %edi
	callq	__Z14factorial_loopi
	movl	%eax, -48(%rbp)
	movl	-44(%rbp), %eax
	cmpl	-48(%rbp), %eax
	sete	%al
	xorb	$-1, %al
	testb	$1, %al
	jne	LBB2_7
	jmp	LBB2_8
LBB2_7:
	leaq	L___func__.main(%rip), %rdi
	leaq	L_.str.2(%rip), %rsi
	leaq	L_.str.4(%rip), %rcx
	movl	$46, %edx
	callq	___assert_rtn
LBB2_8:
	jmp	LBB2_9
LBB2_9:
	movl	-20(%rbp), %esi
	leaq	L_.str.5(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	-44(%rbp), %esi
	leaq	L_.str.6(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	-48(%rbp), %esi
	leaq	L_.str.7(%rip), %rdi
	movb	$0, %al
	callq	_printf
	xorl	%eax, %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d"

L_.str.1:                               ## @.str.1
	.asciz	"%d\n"

L___func__.main:                        ## @__func__.main
	.asciz	"main"

L_.str.2:                               ## @.str.2
	.asciz	"factorial_trivial.cpp"

L_.str.3:                               ## @.str.3
	.asciz	"n == temp"

L_.str.4:                               ## @.str.4
	.asciz	"fac_rec == fac_lo"

L_.str.5:                               ## @.str.5
	.asciz	"Factorial of %d is\n"

L_.str.6:                               ## @.str.6
	.asciz	"Recursion: %d\n"

L_.str.7:                               ## @.str.7
	.asciz	"Loop: %d\n"

.subsections_via_symbols
