	.file	"parser.c"
	.text
	.globl	lookahead
	.bss
	.align 4
	.type	lookahead, @object
	.size	lookahead, 4
lookahead:
	.zero	4
	.text
	.globl	E
	.type	E, @function
E:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	lookahead(%rip), %eax
	cmpl	$43, %eax
	je	.L2
	movl	lookahead(%rip), %eax
	cmpl	$45, %eax
	jne	.L3
.L2:
	movl	lookahead(%rip), %eax
	movl	%eax, %edi
	call	match
.L3:
	call	T
	call	R
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	E, .-E
	.globl	T
	.type	T, @function
T:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	call	F
	call	Q
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	T, .-T
	.globl	F
	.type	F, @function
F:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	lookahead(%rip), %eax
	cmpl	$40, %eax
	je	.L6
	cmpl	$1025, %eax
	je	.L7
	jmp	.L10
.L6:
	movl	$40, %edi
	call	match
	call	E
	movl	$41, %edi
	call	match
	jmp	.L9
.L7:
	movl	$1025, %edi
	call	match
	jmp	.L9
.L10:
	movl	$1024, %edi
	call	match
	nop
.L9:
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	F, .-F
	.globl	R
	.type	R, @function
R:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	lookahead(%rip), %eax
	cmpl	$43, %eax
	je	.L12
	cmpl	$45, %eax
	je	.L13
	jmp	.L15
.L12:
	movl	$43, %edi
	call	match
	call	T
	call	R
	jmp	.L14
.L13:
	movl	$45, %edi
	call	match
	call	T
	call	R
	nop
.L14:
.L15:
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	R, .-R
	.globl	Q
	.type	Q, @function
Q:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	lookahead(%rip), %eax
	cmpl	$42, %eax
	je	.L17
	cmpl	$47, %eax
	je	.L18
	jmp	.L20
.L17:
	movl	$42, %edi
	call	match
	call	F
	call	Q
	jmp	.L19
.L18:
	movl	$47, %edi
	call	match
	call	F
	call	Q
	nop
.L19:
.L20:
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	Q, .-Q
	.section	.rodata
.LC0:
	.string	"token mismatch\n"
	.text
	.globl	match
	.type	match, @function
match:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	lookahead(%rip), %eax
	cmpl	%eax, -4(%rbp)
	jne	.L22
	movq	source(%rip), %rax
	movq	%rax, %rdi
	call	gettoken
	movl	%eax, lookahead(%rip)
	jmp	.L24
.L22:
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$15, %edx
	movl	$1, %esi
	movl	$.LC0, %edi
	call	fwrite
	movl	$-3, %edi
	call	exit
.L24:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	match, .-match
	.ident	"GCC: (GNU) 14.1.1 20240701 (Red Hat 14.1.1-7)"
	.section	.note.GNU-stack,"",@progbits
