	.file	"dynomads.c"
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.local	q
	.comm	q,40,32
	.local	dq
	.comm	dq,40,32
	.local	ddq
	.comm	ddq,40,32
	.local	L
	.comm	L,48,32
	.local	pdis
	.comm	pdis,120,32
	.local	Mass
	.comm	Mass,40,32
	.local	I
	.comm	I,360,32
	.type	avek, @function
avek:
.LFB0:
	.file 1 "dynomads.c"
	.loc 1 58 0
	.cfi_startproc
	pushl	%ebp
.LCFI0:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI1:
	.cfi_def_cfa_register 5
	call	mcount
	.loc 1 59 0
	movl	8(%ebp), %eax
	fldl	L(,%eax,8)
	.loc 1 60 0
	popl	%ebp
	ret
	.cfi_endproc
.LFE0:
	.size	avek, .-avek
	.type	alphavek, @function
alphavek:
.LFB1:
	.loc 1 62 0
	.cfi_startproc
	pushl	%ebp
.LCFI2:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI3:
	.cfi_def_cfa_register 5
	call	mcount
	.loc 1 64 0
	movl	8(%ebp), %eax
	fldl	alv.3324(,%eax,8)
	.loc 1 65 0
	popl	%ebp
	ret
	.cfi_endproc
.LFE1:
	.size	alphavek, .-alphavek
	.type	dvek, @function
dvek:
.LFB2:
	.loc 1 67 0
	.cfi_startproc
	pushl	%ebp
.LCFI4:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI5:
	.cfi_def_cfa_register 5
	call	mcount
	.loc 1 69 0
	cmpl	$0, 8(%ebp)
	jne	.L6
	fldl	q
	jmp	.L7
.L6:
	.loc 1 70 0
	movl	8(%ebp), %eax
	fldl	dv.3330(,%eax,8)
.L7:
	.loc 1 71 0
	popl	%ebp
	ret
	.cfi_endproc
.LFE2:
	.size	dvek, .-dvek
	.type	ddvek, @function
ddvek:
.LFB3:
	.loc 1 73 0
	.cfi_startproc
	pushl	%ebp
.LCFI6:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI7:
	.cfi_def_cfa_register 5
	call	mcount
	.loc 1 75 0
	cmpl	$0, 8(%ebp)
	jne	.L10
	fldl	dq
	jmp	.L11
.L10:
	.loc 1 76 0
	movl	8(%ebp), %eax
	fldl	dv.3338(,%eax,8)
.L11:
	.loc 1 77 0
	popl	%ebp
	ret
	.cfi_endproc
.LFE3:
	.size	ddvek, .-ddvek
	.type	dddvek, @function
dddvek:
.LFB4:
	.loc 1 79 0
	.cfi_startproc
	pushl	%ebp
.LCFI8:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI9:
	.cfi_def_cfa_register 5
	call	mcount
	.loc 1 81 0
	cmpl	$0, 8(%ebp)
	jne	.L14
	fldl	ddq
	jmp	.L15
.L14:
	.loc 1 82 0
	movl	8(%ebp), %eax
	fldl	dv.3346(,%eax,8)
.L15:
	.loc 1 83 0
	popl	%ebp
	ret
	.cfi_endproc
.LFE4:
	.size	dddvek, .-dddvek
	.type	tvek, @function
tvek:
.LFB5:
	.loc 1 86 0
	.cfi_startproc
	pushl	%ebp
.LCFI10:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI11:
	.cfi_def_cfa_register 5
	call	mcount
	.loc 1 87 0
	cmpl	$0, 8(%ebp)
	jne	.L18
	fldz
	jmp	.L19
.L18:
	.loc 1 88 0
	cmpl	$1, 8(%ebp)
	jne	.L20
	fldl	q+8
	jmp	.L19
.L20:
	.loc 1 89 0
	cmpl	$2, 8(%ebp)
	jne	.L21
	fldl	q+16
	jmp	.L19
.L21:
	.loc 1 90 0
	cmpl	$3, 8(%ebp)
	jne	.L22
	fldl	q+24
	fldl	.LC2
	faddp	%st, %st(1)
	jmp	.L19
.L22:
	.loc 1 91 0
	fldl	q+32
.L19:
	.loc 1 92 0
	popl	%ebp
	ret
	.cfi_endproc
.LFE5:
	.size	tvek, .-tvek
	.type	dtvek, @function
dtvek:
.LFB6:
	.loc 1 94 0
	.cfi_startproc
	pushl	%ebp
.LCFI12:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI13:
	.cfi_def_cfa_register 5
	call	mcount
	.loc 1 95 0
	cmpl	$0, 8(%ebp)
	jne	.L25
	fldz
	jmp	.L26
.L25:
	.loc 1 96 0
	movl	8(%ebp), %eax
	fldl	dq(,%eax,8)
.L26:
	.loc 1 97 0
	popl	%ebp
	ret
	.cfi_endproc
.LFE6:
	.size	dtvek, .-dtvek
	.type	ddtvek, @function
ddtvek:
.LFB7:
	.loc 1 99 0
	.cfi_startproc
	pushl	%ebp
.LCFI14:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI15:
	.cfi_def_cfa_register 5
	call	mcount
	.loc 1 100 0
	cmpl	$0, 8(%ebp)
	jne	.L29
	fldz
	jmp	.L30
.L29:
	.loc 1 101 0
	movl	8(%ebp), %eax
	fldl	ddq(,%eax,8)
.L30:
	.loc 1 102 0
	popl	%ebp
	ret
	.cfi_endproc
.LFE7:
	.size	ddtvek, .-ddtvek
	.local	ptrans
	.comm	ptrans,144,32
	.type	P, @function
P:
.LFB8:
	.loc 1 106 0
	.cfi_startproc
	pushl	%ebp
.LCFI16:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI17:
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$36, %esp
	call	mcount
	.loc 1 108 0
	movl	8(%ebp), %eax
	movl	last_timestep.3383(,%eax,4), %eax
	cmpl	12(%ebp), %eax
	je	.L33
	.cfi_offset 3, -12
	cmpl	$0, 8(%ebp)
	jle	.L34
.L33:
	.loc 1 109 0
	movl	8(%ebp), %eax
	movl	last_timestep.3383(,%eax,4), %eax
	cmpl	$-1, %eax
	je	.L34
	movl	$ptrans, %ecx
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	(%ecx,%eax), %eax
	jmp	.L35
.L34:
	.loc 1 111 0
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, last_timestep.3383(,%eax,4)
	.loc 1 112 0
	cmpl	$5, 8(%ebp)
	jne	.L36
	.loc 1 113 0
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldz
	fstpl	ptrans(%eax)
	.loc 1 114 0
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	$1, %eax
	fldz
	fstpl	ptrans(,%eax,8)
	.loc 1 115 0
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldz
	fstpl	ptrans+16(%eax)
	jmp	.L37
.L36:
	.loc 1 119 0
	movl	8(%ebp), %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	avek
	movl	%ebx, %eax
	addl	%eax, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	fstpl	ptrans(%eax)
	.loc 1 120 0
	movl	8(%ebp), %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	alphavek
	fstpl	(%esp)
	call	sin
	fchs
	fstpl	-24(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	dvek
	fmull	-24(%ebp)
	movl	%ebx, %eax
	addl	%eax, %eax
	addl	%ebx, %eax
	addl	$1, %eax
	fstpl	ptrans(,%eax,8)
	.loc 1 121 0
	movl	8(%ebp), %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	alphavek
	fstpl	(%esp)
	call	cos
	fstpl	-16(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	dvek
	fmull	-16(%ebp)
	movl	%ebx, %eax
	addl	%eax, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	fstpl	ptrans+16(%eax)
.L37:
	.loc 1 123 0
	movl	$ptrans, %ecx
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	(%ecx,%eax), %eax
.L35:
	.loc 1 124 0
	addl	$36, %esp
	popl	%ebx
	popl	%ebp
	ret
	.cfi_endproc
.LFE8:
	.size	P, .-P
	.local	rtrans
	.comm	rtrans,432,32
	.type	R, @function
R:
.LFB9:
	.loc 1 128 0
	.cfi_startproc
	pushl	%ebp
.LCFI18:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI19:
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	call	mcount
	.loc 1 130 0
	movl	8(%ebp), %eax
	movl	last_timestep.3425(,%eax,4), %eax
	cmpl	12(%ebp), %eax
	je	.L40
	.cfi_offset 3, -12
	cmpl	$0, 8(%ebp)
	jne	.L41
.L40:
	.loc 1 131 0
	movl	8(%ebp), %eax
	movl	last_timestep.3425(,%eax,4), %eax
	cmpl	$-1, %eax
	je	.L41
	movl	8(%ebp), %eax
	jmp	.L42
.L41:
	.loc 1 133 0
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, last_timestep.3425(,%eax,4)
	.loc 1 134 0
	cmpl	$5, 8(%ebp)
	jne	.L43
	.loc 1 135 0
	movl	8(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fld1
	fstpl	rtrans(%eax)
	.loc 1 136 0
	movl	8(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	addl	$1, %eax
	fldz
	fstpl	rtrans(,%eax,8)
	.loc 1 137 0
	movl	8(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldz
	fstpl	rtrans+16(%eax)
	.loc 1 138 0
	movl	8(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldz
	fstpl	rtrans+24(%eax)
	.loc 1 139 0
	movl	8(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fld1
	fstpl	rtrans+32(%eax)
	.loc 1 140 0
	movl	8(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldz
	fstpl	rtrans+40(%eax)
	.loc 1 141 0
	movl	8(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldz
	fstpl	rtrans+48(%eax)
	.loc 1 142 0
	movl	8(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldz
	fstpl	rtrans+56(%eax)
	.loc 1 143 0
	movl	8(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fld1
	fstpl	rtrans+64(%eax)
	jmp	.L44
.L43:
	.loc 1 146 0
	movl	8(%ebp), %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	tvek
	fstpl	(%esp)
	call	cos
	movl	%ebx, %eax
	sall	$3, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	fstpl	rtrans(%eax)
	.loc 1 147 0
	movl	8(%ebp), %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	tvek
	fstpl	(%esp)
	call	sin
	fchs
	movl	%ebx, %eax
	sall	$3, %eax
	addl	%ebx, %eax
	addl	$1, %eax
	fstpl	rtrans(,%eax,8)
	.loc 1 148 0
	movl	8(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldz
	fstpl	rtrans+16(%eax)
	.loc 1 149 0
	movl	8(%ebp), %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	tvek
	fstpl	(%esp)
	call	sin
	fstpl	-40(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	alphavek
	fstpl	(%esp)
	call	cos
	fmull	-40(%ebp)
	movl	%ebx, %eax
	sall	$3, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	fstpl	rtrans+24(%eax)
	.loc 1 150 0
	movl	8(%ebp), %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	tvek
	fstpl	(%esp)
	call	cos
	fstpl	-32(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	alphavek
	fstpl	(%esp)
	call	cos
	fmull	-32(%ebp)
	movl	%ebx, %eax
	sall	$3, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	fstpl	rtrans+32(%eax)
	.loc 1 151 0
	movl	8(%ebp), %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	alphavek
	fstpl	(%esp)
	call	sin
	fchs
	movl	%ebx, %eax
	sall	$3, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	fstpl	rtrans+40(%eax)
	.loc 1 152 0
	movl	8(%ebp), %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	tvek
	fstpl	(%esp)
	call	sin
	fstpl	-24(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	alphavek
	fstpl	(%esp)
	call	sin
	fmull	-24(%ebp)
	movl	%ebx, %eax
	sall	$3, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	fstpl	rtrans+48(%eax)
	.loc 1 153 0
	movl	8(%ebp), %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	tvek
	fstpl	(%esp)
	call	cos
	fstpl	-16(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	alphavek
	fstpl	(%esp)
	call	sin
	fmull	-16(%ebp)
	movl	%ebx, %eax
	sall	$3, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	fstpl	rtrans+56(%eax)
	.loc 1 154 0
	movl	8(%ebp), %ebx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	alphavek
	fstpl	(%esp)
	call	cos
	movl	%ebx, %eax
	sall	$3, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	fstpl	rtrans+64(%eax)
.L44:
	.loc 1 156 0
	movl	8(%ebp), %eax
.L42:
	.loc 1 157 0
	addl	$52, %esp
	popl	%ebx
	popl	%ebp
	ret
	.cfi_endproc
.LFE9:
	.size	R, .-R
	.local	vvec
	.comm	vvec,144,32
	.type	computeV, @function
computeV:
.LFB10:
	.loc 1 161 0
	.cfi_startproc
	pushl	%ebp
.LCFI20:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI21:
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$84, %esp
	call	mcount
	.loc 1 168 0
	cmpl	$-1, 8(%ebp)
	jne	.L47
	.cfi_offset 3, -12
	.loc 1 169 0
	fldz
	fstpl	vvec+120
	.loc 1 170 0
	fldz
	fstpl	vvec+128
	.loc 1 171 0
	fldz
	fstpl	vvec+136
	.loc 1 172 0
	movl	$vvec+120, %eax
	jmp	.L48
.L47:
	.loc 1 174 0
	movl	8(%ebp), %eax
	movl	last_timestep.3498(,%eax,4), %eax
	cmpl	12(%ebp), %eax
	jne	.L49
	.loc 1 175 0
	movl	8(%ebp), %eax
	movl	last_timestep.3498(,%eax,4), %eax
	cmpl	$-1, %eax
	je	.L49
	movl	$vvec, %ecx
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	(%ecx,%eax), %eax
	jmp	.L48
.L49:
	.loc 1 177 0
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, last_timestep.3498(,%eax,4)
	.loc 1 178 0
	movl	8(%ebp), %eax
	leal	-1(%eax), %edx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	computeOmega
	movl	%eax, -12(%ebp)
	.loc 1 179 0
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	P
	movl	%eax, -16(%ebp)
	.loc 1 180 0
	movl	8(%ebp), %eax
	leal	-1(%eax), %edx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	computeV
	movl	%eax, -20(%ebp)
	.loc 1 181 0
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	R
	movl	%eax, -24(%ebp)
	.loc 1 182 0
	movl	8(%ebp), %edx
	movl	-20(%ebp), %eax
	fldl	(%eax)
	movl	-12(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	movl	-16(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	-12(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	movl	-16(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	faddp	%st, %st(1)
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fstpl	vvec(%eax)
	.loc 1 183 0
	movl	8(%ebp), %edx
	movl	-20(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	movl	-12(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	movl	-16(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	-12(%ebp), %eax
	fldl	(%eax)
	movl	-16(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	faddp	%st, %st(1)
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	$1, %eax
	fstpl	vvec(,%eax,8)
	.loc 1 184 0
	movl	8(%ebp), %edx
	movl	-20(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	movl	-12(%ebp), %eax
	fldl	(%eax)
	movl	-16(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	-12(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	movl	-16(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	faddp	%st, %st(1)
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fstpl	vvec+16(%eax)
	.loc 1 185 0
	movl	-24(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans(%eax)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	vvec(%eax)
	fmulp	%st, %st(1)
	movl	-24(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+24(%eax)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	$1, %eax
	fldl	vvec(,%eax,8)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-24(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+48(%eax)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	vvec+16(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstpl	-48(%ebp)
	.loc 1 186 0
	movl	-24(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	addl	$1, %eax
	fldl	rtrans(,%eax,8)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	vvec(%eax)
	fmulp	%st, %st(1)
	movl	-24(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+32(%eax)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	$1, %eax
	fldl	vvec(,%eax,8)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-24(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+56(%eax)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	vvec+16(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstpl	-40(%ebp)
	.loc 1 187 0
	movl	-24(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+16(%eax)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	vvec(%eax)
	fmulp	%st, %st(1)
	movl	-24(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+40(%eax)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	$1, %eax
	fldl	vvec(,%eax,8)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-24(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+64(%eax)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	vvec+16(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstpl	-32(%ebp)
	.loc 1 188 0
	movl	8(%ebp), %edx
	fldl	-48(%ebp)
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fstpl	vvec(%eax)
	.loc 1 189 0
	movl	8(%ebp), %edx
	fldl	-40(%ebp)
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	$1, %eax
	fstpl	vvec(,%eax,8)
	.loc 1 190 0
	movl	8(%ebp), %ebx
	fldl	-32(%ebp)
	fstpl	-64(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	ddvek
	faddl	-64(%ebp)
	movl	%ebx, %eax
	addl	%eax, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	fstpl	vvec+16(%eax)
	.loc 1 191 0
	movl	$vvec, %ecx
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	(%ecx,%eax), %eax
.L48:
	.loc 1 192 0
	addl	$84, %esp
	popl	%ebx
	popl	%ebp
	ret
	.cfi_endproc
.LFE10:
	.size	computeV, .-computeV
	.local	om
	.comm	om,144,32
	.type	computeOmega, @function
computeOmega:
.LFB11:
	.loc 1 196 0
	.cfi_startproc
	pushl	%ebp
.LCFI22:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI23:
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	call	mcount
	.loc 1 200 0
	cmpl	$-1, 8(%ebp)
	jne	.L52
	.cfi_offset 3, -12
	.loc 1 201 0
	fldz
	fstpl	om+120
	.loc 1 202 0
	fldz
	fstpl	om+128
	.loc 1 203 0
	fldz
	fstpl	om+136
	.loc 1 204 0
	movl	$om+120, %eax
	jmp	.L53
.L52:
	.loc 1 206 0
	movl	8(%ebp), %eax
	movl	last_timestep.3629(,%eax,4), %eax
	cmpl	12(%ebp), %eax
	jne	.L54
	.loc 1 207 0
	movl	8(%ebp), %eax
	movl	last_timestep.3629(,%eax,4), %eax
	cmpl	$-1, %eax
	je	.L54
	movl	$om, %ecx
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	(%ecx,%eax), %eax
	jmp	.L53
.L54:
	.loc 1 209 0
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, last_timestep.3629(,%eax,4)
	.loc 1 210 0
	movl	8(%ebp), %eax
	leal	-1(%eax), %edx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	computeOmega
	movl	%eax, -12(%ebp)
	.loc 1 211 0
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	R
	movl	%eax, -16(%ebp)
	.loc 1 212 0
	movl	8(%ebp), %edx
	movl	-16(%ebp), %ecx
	movl	%ecx, %eax
	sall	$3, %eax
	addl	%ecx, %eax
	sall	$3, %eax
	fldl	rtrans(%eax)
	movl	-12(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	-16(%ebp), %ecx
	movl	%ecx, %eax
	sall	$3, %eax
	addl	%ecx, %eax
	sall	$3, %eax
	fldl	rtrans+24(%eax)
	movl	-12(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-16(%ebp), %ecx
	movl	%ecx, %eax
	sall	$3, %eax
	addl	%ecx, %eax
	sall	$3, %eax
	fldl	rtrans+48(%eax)
	movl	-12(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fstpl	om(%eax)
	.loc 1 213 0
	movl	8(%ebp), %edx
	movl	-16(%ebp), %ecx
	movl	%ecx, %eax
	sall	$3, %eax
	addl	%ecx, %eax
	addl	$1, %eax
	fldl	rtrans(,%eax,8)
	movl	-12(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	-16(%ebp), %ecx
	movl	%ecx, %eax
	sall	$3, %eax
	addl	%ecx, %eax
	sall	$3, %eax
	fldl	rtrans+32(%eax)
	movl	-12(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-16(%ebp), %ecx
	movl	%ecx, %eax
	sall	$3, %eax
	addl	%ecx, %eax
	sall	$3, %eax
	fldl	rtrans+56(%eax)
	movl	-12(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	$1, %eax
	fstpl	om(,%eax,8)
	.loc 1 214 0
	movl	8(%ebp), %ebx
	movl	-16(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+16(%eax)
	movl	-12(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	-16(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+40(%eax)
	movl	-12(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-16(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+64(%eax)
	movl	-12(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstpl	-32(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	dtvek
	faddl	-32(%ebp)
	movl	%ebx, %eax
	addl	%eax, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	fstpl	om+16(%eax)
	.loc 1 215 0
	movl	$om, %ecx
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	(%ecx,%eax), %eax
.L53:
	.loc 1 216 0
	addl	$52, %esp
	popl	%ebx
	popl	%ebp
	ret
	.cfi_endproc
.LFE11:
	.size	computeOmega, .-computeOmega
	.local	omd
	.comm	omd,144,32
	.type	computeOmegaDot, @function
computeOmegaDot:
.LFB12:
	.loc 1 219 0
	.cfi_startproc
	pushl	%ebp
.LCFI24:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI25:
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$132, %esp
	call	mcount
	.loc 1 226 0
	cmpl	$-1, 8(%ebp)
	jne	.L57
	.cfi_offset 3, -12
	.loc 1 227 0
	fldz
	fstpl	omd+120
	.loc 1 228 0
	fldz
	fstpl	omd+128
	.loc 1 229 0
	fldz
	fstpl	omd+136
	.loc 1 230 0
	movl	$omd+120, %eax
	jmp	.L58
.L57:
	.loc 1 232 0
	movl	8(%ebp), %eax
	movl	last_timestep.3714(,%eax,4), %eax
	cmpl	12(%ebp), %eax
	jne	.L59
	.loc 1 233 0
	movl	8(%ebp), %eax
	movl	last_timestep.3714(,%eax,4), %eax
	cmpl	$-1, %eax
	je	.L59
	movl	$omd, %ecx
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	(%ecx,%eax), %eax
	jmp	.L58
.L59:
	.loc 1 235 0
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, last_timestep.3714(,%eax,4)
	.loc 1 236 0
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	R
	movl	%eax, -20(%ebp)
	.loc 1 237 0
	movl	8(%ebp), %eax
	leal	-1(%eax), %edx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	computeOmegaDot
	movl	%eax, -12(%ebp)
	.loc 1 238 0
	movl	8(%ebp), %eax
	leal	-1(%eax), %edx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	computeOmega
	movl	%eax, -16(%ebp)
	.loc 1 239 0
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans(%eax)
	movl	-16(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+24(%eax)
	movl	-16(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+48(%eax)
	movl	-16(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstpl	-48(%ebp)
	.loc 1 240 0
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	addl	$1, %eax
	fldl	rtrans(,%eax,8)
	movl	-16(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+32(%eax)
	movl	-16(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+56(%eax)
	movl	-16(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstpl	-40(%ebp)
	.loc 1 241 0
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+16(%eax)
	movl	-16(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+40(%eax)
	movl	-16(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+64(%eax)
	movl	-16(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstpl	-32(%ebp)
	.loc 1 242 0
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans(%eax)
	movl	-12(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+24(%eax)
	movl	-12(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+48(%eax)
	movl	-12(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstpl	-72(%ebp)
	.loc 1 243 0
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	addl	$1, %eax
	fldl	rtrans(,%eax,8)
	movl	-12(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+32(%eax)
	movl	-12(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+56(%eax)
	movl	-12(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstpl	-64(%ebp)
	.loc 1 244 0
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+16(%eax)
	movl	-12(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+40(%eax)
	movl	-12(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+64(%eax)
	movl	-12(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstpl	-56(%ebp)
	.loc 1 245 0
	movl	8(%ebp), %ebx
	fldl	-72(%ebp)
	fstpl	-112(%ebp)
	fldl	-40(%ebp)
	fstpl	-104(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	dtvek
	fmull	-104(%ebp)
	faddl	-112(%ebp)
	movl	%ebx, %eax
	addl	%eax, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	fstpl	omd(%eax)
	.loc 1 246 0
	movl	8(%ebp), %ebx
	fldl	-64(%ebp)
	fstpl	-96(%ebp)
	fldl	-48(%ebp)
	fstpl	-88(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	dtvek
	fmull	-88(%ebp)
	fsubrl	-96(%ebp)
	movl	%ebx, %eax
	addl	%eax, %eax
	addl	%ebx, %eax
	addl	$1, %eax
	fstpl	omd(,%eax,8)
	.loc 1 247 0
	movl	8(%ebp), %ebx
	fldl	-56(%ebp)
	fstpl	-80(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	ddtvek
	faddl	-80(%ebp)
	movl	%ebx, %eax
	addl	%eax, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	fstpl	omd+16(%eax)
	.loc 1 248 0
	movl	$omd, %ecx
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	(%ecx,%eax), %eax
.L58:
	.loc 1 249 0
	addl	$132, %esp
	popl	%ebx
	popl	%ebp
	ret
	.cfi_endproc
.LFE12:
	.size	computeOmegaDot, .-computeOmegaDot
	.local	ved
	.comm	ved,144,32
	.type	computeVDot, @function
computeVDot:
.LFB13:
	.loc 1 251 0
	.cfi_startproc
	pushl	%ebp
.LCFI26:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI27:
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$164, %esp
	call	mcount
	.loc 1 262 0
	cmpl	$-1, 8(%ebp)
	jne	.L62
	.cfi_offset 3, -12
	.loc 1 263 0
	fldl	.LC4
	fstpl	ved+120
	.loc 1 264 0
	fldz
	fstpl	ved+128
	.loc 1 265 0
	fldz
	fstpl	ved+136
	.loc 1 266 0
	movl	$ved+120, %eax
	jmp	.L63
.L62:
	.loc 1 268 0
	movl	8(%ebp), %eax
	movl	last_timestep.3864(,%eax,4), %eax
	cmpl	12(%ebp), %eax
	jne	.L64
	.loc 1 269 0
	movl	8(%ebp), %eax
	movl	last_timestep.3864(,%eax,4), %eax
	cmpl	$-1, %eax
	je	.L64
	movl	$ved, %ecx
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	(%ecx,%eax), %eax
	jmp	.L63
.L64:
	.loc 1 271 0
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, last_timestep.3864(,%eax,4)
	.loc 1 272 0
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	R
	movl	%eax, -28(%ebp)
	.loc 1 273 0
	movl	8(%ebp), %eax
	leal	-1(%eax), %edx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	computeOmegaDot
	movl	%eax, -16(%ebp)
	.loc 1 274 0
	movl	8(%ebp), %eax
	leal	-1(%eax), %edx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	computeOmega
	movl	%eax, -20(%ebp)
	.loc 1 275 0
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	computeOmega
	movl	%eax, -24(%ebp)
	.loc 1 276 0
	movl	8(%ebp), %eax
	leal	-1(%eax), %edx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	computeVDot
	movl	%eax, -12(%ebp)
	.loc 1 277 0
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	P
	movl	%eax, -32(%ebp)
	.loc 1 278 0
	movl	-20(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	movl	-32(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	-20(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	movl	-32(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fstpl	-56(%ebp)
	.loc 1 279 0
	movl	-20(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	movl	-32(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	-20(%ebp), %eax
	fldl	(%eax)
	movl	-32(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fstpl	-48(%ebp)
	.loc 1 280 0
	movl	-20(%ebp), %eax
	fldl	(%eax)
	movl	-32(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	-20(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	movl	-32(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fstpl	-40(%ebp)
	.loc 1 281 0
	movl	-16(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	movl	-32(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	-16(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	movl	-32(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fstpl	-104(%ebp)
	.loc 1 282 0
	movl	-16(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	movl	-32(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	-16(%ebp), %eax
	fldl	(%eax)
	movl	-32(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fstpl	-96(%ebp)
	.loc 1 283 0
	movl	-16(%ebp), %eax
	fldl	(%eax)
	movl	-32(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	-16(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	movl	-32(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fstpl	-88(%ebp)
	.loc 1 284 0
	fldl	-104(%ebp)
	movl	-20(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fldl	-40(%ebp)
	fmulp	%st, %st(1)
	movl	-20(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fldl	-48(%ebp)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-12(%ebp), %eax
	fldl	(%eax)
	faddp	%st, %st(1)
	fstpl	-80(%ebp)
	.loc 1 285 0
	fldl	-96(%ebp)
	movl	-20(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fldl	-56(%ebp)
	fmulp	%st, %st(1)
	movl	-20(%ebp), %eax
	fldl	(%eax)
	fldl	-40(%ebp)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-12(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	faddp	%st, %st(1)
	fstpl	-72(%ebp)
	.loc 1 286 0
	fldl	-88(%ebp)
	movl	-20(%ebp), %eax
	fldl	(%eax)
	fldl	-48(%ebp)
	fmulp	%st, %st(1)
	movl	-20(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fldl	-56(%ebp)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-12(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	faddp	%st, %st(1)
	fstpl	-64(%ebp)
	.loc 1 287 0
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans(%eax)
	fldl	-80(%ebp)
	fmulp	%st, %st(1)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+24(%eax)
	fldl	-72(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+48(%eax)
	fldl	-64(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstpl	-56(%ebp)
	.loc 1 288 0
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	addl	$1, %eax
	fldl	rtrans(,%eax,8)
	fldl	-80(%ebp)
	fmulp	%st, %st(1)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+32(%eax)
	fldl	-72(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+56(%eax)
	fldl	-64(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstpl	-48(%ebp)
	.loc 1 289 0
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+16(%eax)
	fldl	-80(%ebp)
	fmulp	%st, %st(1)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+40(%eax)
	fldl	-72(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+64(%eax)
	fldl	-64(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstpl	-40(%ebp)
	.loc 1 290 0
	movl	8(%ebp), %ebx
	fldl	-56(%ebp)
	fstpl	-144(%ebp)
	movl	-24(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fld	%st(0)
	faddp	%st, %st(1)
	fstpl	-136(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	ddvek
	fmull	-136(%ebp)
	faddl	-144(%ebp)
	movl	%ebx, %eax
	addl	%eax, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	fstpl	ved(%eax)
	.loc 1 291 0
	movl	8(%ebp), %ebx
	fldl	-48(%ebp)
	fstpl	-128(%ebp)
	movl	-24(%ebp), %eax
	fldl	(%eax)
	fldl	.LC5
	fmulp	%st, %st(1)
	fstpl	-120(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	ddvek
	fmull	-120(%ebp)
	faddl	-128(%ebp)
	movl	%ebx, %eax
	addl	%eax, %eax
	addl	%ebx, %eax
	addl	$1, %eax
	fstpl	ved(,%eax,8)
	.loc 1 292 0
	movl	8(%ebp), %ebx
	fldl	-40(%ebp)
	fstpl	-112(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	dddvek
	faddl	-112(%ebp)
	movl	%ebx, %eax
	addl	%eax, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	fstpl	ved+16(%eax)
	.loc 1 293 0
	movl	$ved, %ecx
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	(%ecx,%eax), %eax
.L63:
	.loc 1 294 0
	addl	$164, %esp
	popl	%ebx
	popl	%ebp
	ret
	.cfi_endproc
.LFE13:
	.size	computeVDot, .-computeVDot
	.local	vedc
	.comm	vedc,120,32
	.type	computeForce, @function
computeForce:
.LFB14:
	.loc 1 299 0
	.cfi_startproc
	pushl	%ebp
.LCFI28:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI29:
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$80, %esp
	call	mcount
	.loc 1 307 0
	movl	8(%ebp), %eax
	movl	last_timestep.4061(,%eax,4), %eax
	cmpl	12(%ebp), %eax
	jne	.L67
	.cfi_offset 3, -16
	.cfi_offset 6, -12
	.loc 1 308 0
	movl	8(%ebp), %eax
	movl	last_timestep.4061(,%eax,4), %eax
	cmpl	$-1, %eax
	je	.L67
	movl	$vedc, %ecx
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	(%ecx,%eax), %eax
	jmp	.L68
.L67:
	.loc 1 310 0
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, last_timestep.4061(,%eax,4)
	.loc 1 311 0
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	computeOmegaDot
	movl	%eax, -16(%ebp)
	.loc 1 312 0
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	computeOmega
	movl	%eax, -20(%ebp)
	.loc 1 313 0
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	computeVDot
	movl	%eax, -24(%ebp)
	.loc 1 314 0
	movl	-16(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	pdis+16(%eax)
	fmulp	%st, %st(1)
	movl	-16(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	$1, %eax
	fldl	pdis(,%eax,8)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fstpl	-48(%ebp)
	.loc 1 315 0
	movl	-16(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	pdis(%eax)
	fmulp	%st, %st(1)
	movl	-16(%ebp), %eax
	fldl	(%eax)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	pdis+16(%eax)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fstpl	-40(%ebp)
	.loc 1 316 0
	movl	-16(%ebp), %eax
	fldl	(%eax)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	$1, %eax
	fldl	pdis(,%eax,8)
	fmulp	%st, %st(1)
	movl	-16(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	pdis(%eax)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fstpl	-32(%ebp)
	.loc 1 317 0
	movl	-20(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	pdis+16(%eax)
	fmulp	%st, %st(1)
	movl	-20(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	$1, %eax
	fldl	pdis(,%eax,8)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fstpl	-72(%ebp)
	.loc 1 318 0
	movl	-20(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	pdis(%eax)
	fmulp	%st, %st(1)
	movl	-20(%ebp), %eax
	fldl	(%eax)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	pdis+16(%eax)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fstpl	-64(%ebp)
	.loc 1 319 0
	movl	-20(%ebp), %eax
	fldl	(%eax)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	$1, %eax
	fldl	pdis(,%eax,8)
	fmulp	%st, %st(1)
	movl	-20(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	pdis(%eax)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fstpl	-56(%ebp)
	.loc 1 320 0
	movl	8(%ebp), %edx
	fldl	-48(%ebp)
	movl	-20(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fldl	-56(%ebp)
	fmulp	%st, %st(1)
	movl	-20(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fldl	-64(%ebp)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-24(%ebp), %eax
	fldl	(%eax)
	faddp	%st, %st(1)
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fstpl	vedc(%eax)
	.loc 1 321 0
	movl	8(%ebp), %edx
	fldl	-40(%ebp)
	movl	-20(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fldl	-72(%ebp)
	fmulp	%st, %st(1)
	movl	-20(%ebp), %eax
	fldl	(%eax)
	fldl	-56(%ebp)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-24(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	faddp	%st, %st(1)
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	$1, %eax
	fstpl	vedc(,%eax,8)
	.loc 1 322 0
	movl	8(%ebp), %edx
	fldl	-32(%ebp)
	movl	-20(%ebp), %eax
	fldl	(%eax)
	fldl	-64(%ebp)
	fmulp	%st, %st(1)
	movl	-20(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fldl	-72(%ebp)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-24(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	faddp	%st, %st(1)
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fstpl	vedc+16(%eax)
	.loc 1 323 0
	movl	$0, -12(%ebp)
	jmp	.L69
.L70:
	movl	8(%ebp), %edx
	movl	-12(%ebp), %ebx
	movl	8(%ebp), %ecx
	movl	-12(%ebp), %esi
	movl	%ecx, %eax
	addl	%eax, %eax
	addl	%ecx, %eax
	addl	%esi, %eax
	fldl	vedc(,%eax,8)
	movl	8(%ebp), %eax
	fldl	Mass(,%eax,8)
	fmulp	%st, %st(1)
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fstpl	vedc(,%eax,8)
	addl	$1, -12(%ebp)
.L69:
	cmpl	$2, -12(%ebp)
	jle	.L70
	.loc 1 324 0
	movl	$vedc, %ecx
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	(%ecx,%eax), %eax
.L68:
	.loc 1 325 0
	addl	$80, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.cfi_endproc
.LFE14:
	.size	computeForce, .-computeForce
	.local	cn
	.comm	cn,120,32
	.type	computeN, @function
computeN:
.LFB15:
	.loc 1 328 0
	.cfi_startproc
	pushl	%ebp
.LCFI30:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI31:
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$84, %esp
	call	mcount
	.loc 1 335 0
	movl	8(%ebp), %eax
	movl	last_timestep.4206(,%eax,4), %eax
	cmpl	12(%ebp), %eax
	jne	.L73
	.cfi_offset 3, -12
	.loc 1 337 0
	movl	8(%ebp), %eax
	movl	last_timestep.4206(,%eax,4), %eax
	cmpl	$-1, %eax
	je	.L73
	movl	$cn, %ecx
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	(%ecx,%eax), %eax
	jmp	.L74
.L73:
	.loc 1 339 0
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, last_timestep.4206(,%eax,4)
	.loc 1 340 0
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	computeOmega
	movl	%eax, -12(%ebp)
	.loc 1 341 0
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	computeOmegaDot
	movl	%eax, -16(%ebp)
	.loc 1 342 0
	movl	$0, -20(%ebp)
	jmp	.L75
.L76:
	.loc 1 344 0
	movl	-20(%ebp), %ebx
	movl	8(%ebp), %edx
	movl	-20(%ebp), %ecx
	movl	%ecx, %eax
	addl	%eax, %eax
	addl	%ecx, %eax
	leal	0(,%eax,8), %ecx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	(%ecx,%eax), %eax
	addl	$I, %eax
	fldl	(%eax)
	movl	-16(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	8(%ebp), %edx
	movl	-20(%ebp), %ecx
	movl	%ecx, %eax
	addl	%eax, %eax
	addl	%ecx, %eax
	leal	0(,%eax,8), %ecx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	(%ecx,%eax), %eax
	addl	$I+8, %eax
	fldl	(%eax)
	movl	-16(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	8(%ebp), %edx
	movl	-20(%ebp), %ecx
	movl	%ecx, %eax
	addl	%eax, %eax
	addl	%ecx, %eax
	leal	0(,%eax,8), %ecx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	(%ecx,%eax), %eax
	addl	$I+16, %eax
	fldl	(%eax)
	movl	-16(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstpl	-48(%ebp,%ebx,8)
	.loc 1 345 0
	movl	-20(%ebp), %ebx
	movl	8(%ebp), %edx
	movl	-20(%ebp), %ecx
	movl	%ecx, %eax
	addl	%eax, %eax
	addl	%ecx, %eax
	leal	0(,%eax,8), %ecx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	(%ecx,%eax), %eax
	addl	$I, %eax
	fldl	(%eax)
	movl	-12(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	8(%ebp), %edx
	movl	-20(%ebp), %ecx
	movl	%ecx, %eax
	addl	%eax, %eax
	addl	%ecx, %eax
	leal	0(,%eax,8), %ecx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	(%ecx,%eax), %eax
	addl	$I+8, %eax
	fldl	(%eax)
	movl	-12(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	8(%ebp), %edx
	movl	-20(%ebp), %ecx
	movl	%ecx, %eax
	addl	%eax, %eax
	addl	%ecx, %eax
	leal	0(,%eax,8), %ecx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	(%ecx,%eax), %eax
	addl	$I+16, %eax
	fldl	(%eax)
	movl	-12(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstpl	-72(%ebp,%ebx,8)
	.loc 1 342 0
	addl	$1, -20(%ebp)
.L75:
	cmpl	$2, -20(%ebp)
	jle	.L76
	.loc 1 347 0
	movl	8(%ebp), %edx
	fldl	-48(%ebp)
	movl	-12(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fldl	-56(%ebp)
	fmulp	%st, %st(1)
	movl	-12(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fldl	-64(%ebp)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	faddp	%st, %st(1)
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fstpl	cn(%eax)
	.loc 1 348 0
	movl	8(%ebp), %edx
	fldl	-40(%ebp)
	movl	-12(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fldl	-72(%ebp)
	fmulp	%st, %st(1)
	movl	-12(%ebp), %eax
	fldl	(%eax)
	fldl	-56(%ebp)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	faddp	%st, %st(1)
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	$1, %eax
	fstpl	cn(,%eax,8)
	.loc 1 349 0
	movl	8(%ebp), %edx
	fldl	-32(%ebp)
	movl	-12(%ebp), %eax
	fldl	(%eax)
	fldl	-64(%ebp)
	fmulp	%st, %st(1)
	movl	-12(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fldl	-72(%ebp)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	faddp	%st, %st(1)
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fstpl	cn+16(%eax)
	.loc 1 350 0
	movl	$cn, %ecx
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	(%ecx,%eax), %eax
.L74:
	.loc 1 351 0
	addl	$84, %esp
	popl	%ebx
	popl	%ebp
	ret
	.cfi_endproc
.LFE15:
	.size	computeN, .-computeN
	.local	inwaf
	.comm	inwaf,144,32
	.type	inwardForce, @function
inwardForce:
.LFB16:
	.loc 1 355 0
	.cfi_startproc
	pushl	%ebp
.LCFI32:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI33:
	.cfi_def_cfa_register 5
	subl	$40, %esp
	call	mcount
	.loc 1 360 0
	cmpl	$5, 8(%ebp)
	jne	.L79
	.loc 1 361 0
	fldz
	fstpl	inwaf+120
	.loc 1 362 0
	fldz
	fstpl	inwaf+128
	.loc 1 363 0
	fldz
	fstpl	inwaf+136
	.loc 1 364 0
	movl	$inwaf+120, %eax
	jmp	.L80
.L79:
	.loc 1 366 0
	movl	8(%ebp), %eax
	movl	last_timestep.4310(,%eax,4), %eax
	cmpl	12(%ebp), %eax
	jne	.L81
	.loc 1 367 0
	movl	8(%ebp), %eax
	movl	last_timestep.4310(,%eax,4), %eax
	cmpl	$-1, %eax
	je	.L81
	movl	$inwaf, %ecx
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	(%ecx,%eax), %eax
	jmp	.L80
.L81:
	.loc 1 369 0
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, last_timestep.4310(,%eax,4)
	.loc 1 370 0
	movl	8(%ebp), %eax
	leal	1(%eax), %edx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	R
	movl	%eax, -16(%ebp)
	.loc 1 371 0
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	computeForce
	movl	%eax, -20(%ebp)
	.loc 1 372 0
	movl	8(%ebp), %eax
	leal	1(%eax), %edx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	inwardForce
	movl	%eax, -12(%ebp)
	.loc 1 373 0
	movl	8(%ebp), %edx
	movl	-16(%ebp), %ecx
	movl	%ecx, %eax
	sall	$3, %eax
	addl	%ecx, %eax
	sall	$3, %eax
	fldl	rtrans(%eax)
	movl	-12(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	-16(%ebp), %ecx
	movl	%ecx, %eax
	sall	$3, %eax
	addl	%ecx, %eax
	addl	$1, %eax
	fldl	rtrans(,%eax,8)
	movl	-12(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-16(%ebp), %ecx
	movl	%ecx, %eax
	sall	$3, %eax
	addl	%ecx, %eax
	sall	$3, %eax
	fldl	rtrans+16(%eax)
	movl	-12(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-20(%ebp), %eax
	fldl	(%eax)
	faddp	%st, %st(1)
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fstpl	inwaf(%eax)
	.loc 1 374 0
	movl	8(%ebp), %edx
	movl	-16(%ebp), %ecx
	movl	%ecx, %eax
	sall	$3, %eax
	addl	%ecx, %eax
	sall	$3, %eax
	fldl	rtrans+24(%eax)
	movl	-12(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	-16(%ebp), %ecx
	movl	%ecx, %eax
	sall	$3, %eax
	addl	%ecx, %eax
	sall	$3, %eax
	fldl	rtrans+32(%eax)
	movl	-12(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-16(%ebp), %ecx
	movl	%ecx, %eax
	sall	$3, %eax
	addl	%ecx, %eax
	sall	$3, %eax
	fldl	rtrans+40(%eax)
	movl	-12(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-20(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	faddp	%st, %st(1)
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	$1, %eax
	fstpl	inwaf(,%eax,8)
	.loc 1 375 0
	movl	8(%ebp), %edx
	movl	-16(%ebp), %ecx
	movl	%ecx, %eax
	sall	$3, %eax
	addl	%ecx, %eax
	sall	$3, %eax
	fldl	rtrans+48(%eax)
	movl	-12(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	-16(%ebp), %ecx
	movl	%ecx, %eax
	sall	$3, %eax
	addl	%ecx, %eax
	sall	$3, %eax
	fldl	rtrans+56(%eax)
	movl	-12(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-16(%ebp), %ecx
	movl	%ecx, %eax
	sall	$3, %eax
	addl	%ecx, %eax
	sall	$3, %eax
	fldl	rtrans+64(%eax)
	movl	-12(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-20(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	faddp	%st, %st(1)
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fstpl	inwaf+16(%eax)
	.loc 1 376 0
	movl	$inwaf, %ecx
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	(%ecx,%eax), %eax
.L80:
	.loc 1 377 0
	leave
	ret
	.cfi_endproc
.LFE16:
	.size	inwardForce, .-inwardForce
	.local	inwat
	.comm	inwat,144,32
	.type	inwardTorque, @function
inwardTorque:
.LFB17:
	.loc 1 380 0
	.cfi_startproc
	pushl	%ebp
.LCFI34:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI35:
	.cfi_def_cfa_register 5
	subl	$120, %esp
	call	mcount
	.loc 1 391 0
	cmpl	$5, 8(%ebp)
	jne	.L84
	.loc 1 392 0
	fldz
	fstpl	inwat+120
	.loc 1 393 0
	fldz
	fstpl	inwat+128
	.loc 1 394 0
	fldz
	fstpl	inwat+136
	.loc 1 395 0
	movl	$inwat+120, %eax
	jmp	.L85
.L84:
	.loc 1 397 0
	movl	8(%ebp), %eax
	movl	last_timestep.4407(,%eax,4), %eax
	cmpl	12(%ebp), %eax
	jne	.L86
	.loc 1 398 0
	movl	8(%ebp), %eax
	movl	last_timestep.4407(,%eax,4), %eax
	cmpl	$-1, %eax
	je	.L86
	movl	$inwat, %ecx
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	(%ecx,%eax), %eax
	jmp	.L85
.L86:
	.loc 1 400 0
	movl	8(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, last_timestep.4407(,%eax,4)
	.loc 1 401 0
	movl	8(%ebp), %eax
	leal	1(%eax), %edx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	R
	movl	%eax, -20(%ebp)
	.loc 1 402 0
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	computeN
	movl	%eax, -24(%ebp)
	.loc 1 403 0
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	computeForce
	movl	%eax, -28(%ebp)
	.loc 1 404 0
	movl	8(%ebp), %eax
	leal	1(%eax), %edx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	P
	movl	%eax, -32(%ebp)
	.loc 1 405 0
	movl	8(%ebp), %eax
	leal	1(%eax), %edx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	inwardForce
	movl	%eax, -16(%ebp)
	.loc 1 406 0
	movl	8(%ebp), %eax
	leal	1(%eax), %edx
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	inwardTorque
	movl	%eax, -12(%ebp)
	.loc 1 407 0
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans(%eax)
	movl	-12(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	addl	$1, %eax
	fldl	rtrans(,%eax,8)
	movl	-12(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	addl	$1, %eax
	fldl	rtrans(,%eax,8)
	movl	-12(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-24(%ebp), %eax
	fldl	(%eax)
	faddp	%st, %st(1)
	fstpl	-56(%ebp)
	.loc 1 408 0
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+24(%eax)
	movl	-12(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+32(%eax)
	movl	-12(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+40(%eax)
	movl	-12(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-24(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	faddp	%st, %st(1)
	fstpl	-48(%ebp)
	.loc 1 409 0
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+48(%eax)
	movl	-12(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+56(%eax)
	movl	-12(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+64(%eax)
	movl	-12(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-24(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	faddp	%st, %st(1)
	fstpl	-40(%ebp)
	.loc 1 410 0
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	$1, %eax
	fldl	pdis(,%eax,8)
	movl	-28(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	pdis+16(%eax)
	movl	-28(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fstpl	-104(%ebp)
	.loc 1 411 0
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	pdis+16(%eax)
	movl	-28(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	pdis(%eax)
	movl	-28(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fstpl	-96(%ebp)
	.loc 1 412 0
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	pdis(%eax)
	movl	-28(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	$1, %eax
	fldl	pdis(,%eax,8)
	movl	-28(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fstpl	-88(%ebp)
	.loc 1 413 0
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans(%eax)
	movl	-16(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	addl	$1, %eax
	fldl	rtrans(,%eax,8)
	movl	-16(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	addl	$1, %eax
	fldl	rtrans(,%eax,8)
	movl	-16(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstpl	-80(%ebp)
	.loc 1 414 0
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+24(%eax)
	movl	-16(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+32(%eax)
	movl	-16(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+40(%eax)
	movl	-16(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstpl	-72(%ebp)
	.loc 1 415 0
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+48(%eax)
	movl	-16(%ebp), %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+56(%eax)
	movl	-16(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-20(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	rtrans+64(%eax)
	movl	-16(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstpl	-64(%ebp)
	.loc 1 416 0
	movl	8(%ebp), %edx
	movl	-32(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fldl	-64(%ebp)
	fmulp	%st, %st(1)
	movl	-32(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fldl	-72(%ebp)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	-104(%ebp)
	faddp	%st, %st(1)
	fldl	-56(%ebp)
	faddp	%st, %st(1)
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fstpl	inwat(%eax)
	.loc 1 417 0
	movl	8(%ebp), %edx
	movl	-32(%ebp), %eax
	addl	$16, %eax
	fldl	(%eax)
	fldl	-80(%ebp)
	fmulp	%st, %st(1)
	movl	-32(%ebp), %eax
	fldl	(%eax)
	fldl	-64(%ebp)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	-96(%ebp)
	faddp	%st, %st(1)
	fldl	-48(%ebp)
	faddp	%st, %st(1)
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	$1, %eax
	fstpl	inwat(,%eax,8)
	.loc 1 418 0
	movl	8(%ebp), %edx
	movl	-32(%ebp), %eax
	fldl	(%eax)
	fldl	-72(%ebp)
	fmulp	%st, %st(1)
	movl	-32(%ebp), %eax
	addl	$8, %eax
	fldl	(%eax)
	fldl	-80(%ebp)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	-88(%ebp)
	faddp	%st, %st(1)
	fldl	-40(%ebp)
	faddp	%st, %st(1)
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fstpl	inwat+16(%eax)
	.loc 1 419 0
	movl	$inwat, %ecx
	movl	8(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	(%ecx,%eax), %eax
.L85:
	.loc 1 420 0
	leave
	ret
	.cfi_endproc
.LFE17:
	.size	inwardTorque, .-inwardTorque
.globl setq
	.type	setq, @function
setq:
.LFB18:
	.loc 1 422 0
	.cfi_startproc
	pushl	%ebp
.LCFI36:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI37:
	.cfi_def_cfa_register 5
	subl	$40, %esp
	call	mcount
	movl	8(%ebp), %eax
	movl	%eax, -8(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -4(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	20(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	24(%ebp), %eax
	movl	%eax, -24(%ebp)
	movl	28(%ebp), %eax
	movl	%eax, -20(%ebp)
	movl	32(%ebp), %eax
	movl	%eax, -32(%ebp)
	movl	36(%ebp), %eax
	movl	%eax, -28(%ebp)
	movl	40(%ebp), %eax
	movl	%eax, -40(%ebp)
	movl	44(%ebp), %eax
	movl	%eax, -36(%ebp)
	.loc 1 423 0
	fldl	-8(%ebp)
	fstpl	q
	.loc 1 424 0
	fldl	-16(%ebp)
	fstpl	q+8
	.loc 1 425 0
	fldl	-24(%ebp)
	fstpl	q+16
	.loc 1 426 0
	fldl	-32(%ebp)
	fstpl	q+24
	.loc 1 427 0
	fldl	-40(%ebp)
	fstpl	q+32
	.loc 1 428 0
	leave
	ret
	.cfi_endproc
.LFE18:
	.size	setq, .-setq
.globl setdq
	.type	setdq, @function
setdq:
.LFB19:
	.loc 1 430 0
	.cfi_startproc
	pushl	%ebp
.LCFI38:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI39:
	.cfi_def_cfa_register 5
	subl	$40, %esp
	call	mcount
	movl	8(%ebp), %eax
	movl	%eax, -8(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -4(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	20(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	24(%ebp), %eax
	movl	%eax, -24(%ebp)
	movl	28(%ebp), %eax
	movl	%eax, -20(%ebp)
	movl	32(%ebp), %eax
	movl	%eax, -32(%ebp)
	movl	36(%ebp), %eax
	movl	%eax, -28(%ebp)
	movl	40(%ebp), %eax
	movl	%eax, -40(%ebp)
	movl	44(%ebp), %eax
	movl	%eax, -36(%ebp)
	.loc 1 431 0
	fldl	-8(%ebp)
	fstpl	dq
	.loc 1 432 0
	fldl	-16(%ebp)
	fstpl	dq+8
	.loc 1 433 0
	fldl	-24(%ebp)
	fstpl	dq+16
	.loc 1 434 0
	fldl	-32(%ebp)
	fstpl	dq+24
	.loc 1 435 0
	fldl	-40(%ebp)
	fstpl	dq+32
	.loc 1 436 0
	leave
	ret
	.cfi_endproc
.LFE19:
	.size	setdq, .-setdq
.globl setddq
	.type	setddq, @function
setddq:
.LFB20:
	.loc 1 438 0
	.cfi_startproc
	pushl	%ebp
.LCFI40:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI41:
	.cfi_def_cfa_register 5
	subl	$40, %esp
	call	mcount
	movl	8(%ebp), %eax
	movl	%eax, -8(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -4(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	20(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	24(%ebp), %eax
	movl	%eax, -24(%ebp)
	movl	28(%ebp), %eax
	movl	%eax, -20(%ebp)
	movl	32(%ebp), %eax
	movl	%eax, -32(%ebp)
	movl	36(%ebp), %eax
	movl	%eax, -28(%ebp)
	movl	40(%ebp), %eax
	movl	%eax, -40(%ebp)
	movl	44(%ebp), %eax
	movl	%eax, -36(%ebp)
	.loc 1 439 0
	fldl	-8(%ebp)
	fstpl	ddq
	.loc 1 440 0
	fldl	-16(%ebp)
	fstpl	ddq+8
	.loc 1 441 0
	fldl	-24(%ebp)
	fstpl	ddq+16
	.loc 1 442 0
	fldl	-32(%ebp)
	fstpl	ddq+24
	.loc 1 443 0
	fldl	-40(%ebp)
	fstpl	ddq+32
	.loc 1 444 0
	leave
	ret
	.cfi_endproc
.LFE20:
	.size	setddq, .-setddq
.globl setLinkLength
	.type	setLinkLength, @function
setLinkLength:
.LFB21:
	.loc 1 447 0
	.cfi_startproc
	pushl	%ebp
.LCFI42:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI43:
	.cfi_def_cfa_register 5
	subl	$8, %esp
	call	mcount
	movl	8(%ebp), %eax
	movl	%eax, -8(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -4(%ebp)
	.loc 1 448 0
	movl	16(%ebp), %eax
	addl	$1, %eax
	fldl	-8(%ebp)
	fldl	.LC6
	fmulp	%st, %st(1)
	fstpl	L(,%eax,8)
	.loc 1 451 0
	fld1
	fstpl	L+16
	.loc 1 452 0
	fldl	.LC7
	fstpl	L+24
	.loc 1 455 0
	leave
	ret
	.cfi_endproc
.LFE21:
	.size	setLinkLength, .-setLinkLength
	.local	Mfive
	.comm	Mfive,8,8
.globl setMass
	.type	setMass, @function
setMass:
.LFB22:
	.loc 1 460 0
	.cfi_startproc
	pushl	%ebp
.LCFI44:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI45:
	.cfi_def_cfa_register 5
	subl	$8, %esp
	call	mcount
	movl	8(%ebp), %eax
	movl	%eax, -8(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -4(%ebp)
	.loc 1 461 0
	movl	16(%ebp), %eax
	fldl	-8(%ebp)
	fstpl	Mass(,%eax,8)
	.loc 1 462 0
	cmpl	$4, 16(%ebp)
	jne	.L97
	fldl	-8(%ebp)
	fstpl	Mfive
.L97:
	.loc 1 463 0
	cmpl	$0, 16(%ebp)
	jne	.L98
	movl	16(%ebp), %eax
	fldl	.LC8
	fstpl	Mass(,%eax,8)
.L98:
	.loc 1 464 0
	cmpl	$1, 16(%ebp)
	jne	.L99
	movl	16(%ebp), %eax
	fldl	.LC9
	fstpl	Mass(,%eax,8)
.L99:
	.loc 1 465 0
	cmpl	$2, 16(%ebp)
	jne	.L100
	movl	16(%ebp), %eax
	fldl	.LC10
	fstpl	Mass(,%eax,8)
.L100:
	.loc 1 466 0
	cmpl	$3, 16(%ebp)
	jne	.L101
	movl	16(%ebp), %eax
	fldl	.LC11
	fstpl	Mass(,%eax,8)
.L101:
	.loc 1 467 0
	cmpl	$4, 16(%ebp)
	jne	.L103
	movl	16(%ebp), %eax
	fldl	Mfive
	fstpl	Mass(,%eax,8)
.L103:
	.loc 1 468 0
	leave
	ret
	.cfi_endproc
.LFE22:
	.size	setMass, .-setMass
.globl setMassDisplacement
	.type	setMassDisplacement, @function
setMassDisplacement:
.LFB23:
	.loc 1 470 0
	.cfi_startproc
	pushl	%ebp
.LCFI46:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI47:
	.cfi_def_cfa_register 5
	subl	$24, %esp
	call	mcount
	movl	8(%ebp), %eax
	movl	%eax, -8(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -4(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	20(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	24(%ebp), %eax
	movl	%eax, -24(%ebp)
	movl	28(%ebp), %eax
	movl	%eax, -20(%ebp)
	.loc 1 471 0
	movl	32(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	-8(%ebp)
	fstpl	pdis(%eax)
	.loc 1 472 0
	movl	32(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	addl	$1, %eax
	fldl	-16(%ebp)
	fstpl	pdis(,%eax,8)
	.loc 1 473 0
	movl	32(%ebp), %edx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	-24(%ebp)
	fstpl	pdis+16(%eax)
	.loc 1 474 0
	leave
	ret
	.cfi_endproc
.LFE23:
	.size	setMassDisplacement, .-setMassDisplacement
.globl setInertiaTensor
	.type	setInertiaTensor, @function
setInertiaTensor:
.LFB24:
	.loc 1 479 0
	.cfi_startproc
	pushl	%ebp
.LCFI48:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI49:
	.cfi_def_cfa_register 5
	subl	$72, %esp
	call	mcount
	movl	8(%ebp), %eax
	movl	%eax, -8(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -4(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	20(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	24(%ebp), %eax
	movl	%eax, -24(%ebp)
	movl	28(%ebp), %eax
	movl	%eax, -20(%ebp)
	movl	32(%ebp), %eax
	movl	%eax, -32(%ebp)
	movl	36(%ebp), %eax
	movl	%eax, -28(%ebp)
	movl	40(%ebp), %eax
	movl	%eax, -40(%ebp)
	movl	44(%ebp), %eax
	movl	%eax, -36(%ebp)
	movl	48(%ebp), %eax
	movl	%eax, -48(%ebp)
	movl	52(%ebp), %eax
	movl	%eax, -44(%ebp)
	movl	56(%ebp), %eax
	movl	%eax, -56(%ebp)
	movl	60(%ebp), %eax
	movl	%eax, -52(%ebp)
	movl	64(%ebp), %eax
	movl	%eax, -64(%ebp)
	movl	68(%ebp), %eax
	movl	%eax, -60(%ebp)
	movl	72(%ebp), %eax
	movl	%eax, -72(%ebp)
	movl	76(%ebp), %eax
	movl	%eax, -68(%ebp)
	.loc 1 480 0
	movl	80(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	-8(%ebp)
	fstpl	I(%eax)
	.loc 1 481 0
	movl	80(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	addl	$1, %eax
	fldl	-16(%ebp)
	fstpl	I(,%eax,8)
	.loc 1 482 0
	movl	80(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	-24(%ebp)
	fstpl	I+16(%eax)
	.loc 1 483 0
	movl	80(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	-32(%ebp)
	fstpl	I+24(%eax)
	.loc 1 484 0
	movl	80(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	-40(%ebp)
	fstpl	I+32(%eax)
	.loc 1 485 0
	movl	80(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	-48(%ebp)
	fstpl	I+40(%eax)
	.loc 1 486 0
	movl	80(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	-56(%ebp)
	fstpl	I+48(%eax)
	.loc 1 487 0
	movl	80(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	-64(%ebp)
	fstpl	I+56(%eax)
	.loc 1 488 0
	movl	80(%ebp), %edx
	movl	%edx, %eax
	sall	$3, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	-72(%ebp)
	fstpl	I+64(%eax)
	.loc 1 489 0
	leave
	ret
	.cfi_endproc
.LFE24:
	.size	setInertiaTensor, .-setInertiaTensor
.globl oldtau
	.type	oldtau, @function
oldtau:
.LFB25:
	.loc 1 491 0
	.cfi_startproc
	pushl	%ebp
.LCFI50:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI51:
	.cfi_def_cfa_register 5
	subl	$24, %esp
	call	mcount
	.loc 1 492 0
	cmpl	$0, 8(%ebp)
	jne	.L109
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	inwardForce
	addl	$16, %eax
	fldl	(%eax)
	fldl	.LC12
	fmulp	%st, %st(1)
	jmp	.L110
.L109:
	.loc 1 494 0
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	inwardTorque
	addl	$16, %eax
	fldl	(%eax)
.L110:
	.loc 1 495 0
	leave
	ret
	.cfi_endproc
.LFE25:
	.size	oldtau, .-oldtau
	.comm	taus,40,32
.globl computetaus
	.type	computetaus, @function
computetaus:
.LFB26:
	.file 2 "tau.c"
	.loc 2 5 0
	.cfi_startproc
	pushl	%ebp
.LCFI52:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI53:
	.cfi_def_cfa_register 5
	subl	$184, %esp
	call	mcount
	.loc 2 6 0
	fldl	q+8
	fstpl	(%esp)
	call	cos
	fstpl	-16(%ebp)
	.loc 2 7 0
	fldl	q+8
	fstpl	(%esp)
	call	sin
	fstpl	-24(%ebp)
	.loc 2 8 0
	fldl	q+16
	fstpl	(%esp)
	call	cos
	fstpl	-32(%ebp)
	.loc 2 9 0
	fldl	q+16
	fstpl	(%esp)
	call	sin
	fstpl	-40(%ebp)
	.loc 2 10 0
	fldl	q+24
	fstpl	(%esp)
	call	cos
	fstpl	-48(%ebp)
	.loc 2 11 0
	fldl	q+24
	fstpl	(%esp)
	call	sin
	fstpl	-56(%ebp)
	.loc 2 12 0
	fldl	q+32
	fstpl	(%esp)
	call	cos
	fstpl	-64(%ebp)
	.loc 2 13 0
	fldl	q+32
	fstpl	(%esp)
	call	sin
	fstpl	-72(%ebp)
	.loc 2 14 0
	fldl	q+32
	fadd	%st(0), %st
	fstpl	(%esp)
	call	cos
	fstpl	-80(%ebp)
	.loc 2 15 0
	fldl	q+32
	fadd	%st(0), %st
	fstpl	(%esp)
	call	sin
	fstpl	-88(%ebp)
	.loc 2 16 0
	fldl	q+8
	fldl	q+16
	faddp	%st, %st(1)
	fldl	q+24
	faddp	%st, %st(1)
	fstpl	(%esp)
	call	cos
	fstpl	-96(%ebp)
	.loc 2 17 0
	fldl	q+8
	fldl	q+16
	faddp	%st, %st(1)
	fldl	q+24
	faddp	%st, %st(1)
	fstpl	(%esp)
	call	sin
	fstpl	-104(%ebp)
	.loc 2 18 0
	fldl	q+8
	fldl	q+16
	faddp	%st, %st(1)
	fstpl	(%esp)
	call	cos
	fstpl	-112(%ebp)
	.loc 2 19 0
	fldl	q+8
	fldl	q+16
	faddp	%st, %st(1)
	fstpl	(%esp)
	call	sin
	fstpl	-120(%ebp)
	.loc 2 20 0
	fldl	q+16
	fldl	q+24
	faddp	%st, %st(1)
	fstpl	(%esp)
	call	cos
	fstpl	-128(%ebp)
	.loc 2 21 0
	fldl	q+16
	fldl	q+24
	faddp	%st, %st(1)
	fstpl	(%esp)
	call	sin
	fstpl	-136(%ebp)
	.loc 2 22 0
	fldl	ddq
	fldl	.LC13
	fmulp	%st, %st(1)
	fldl	ddq
	fldl	dq+32
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmull	-64(%ebp)
	fldl	pdis+96
	fmull	-72(%ebp)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	ddq+32
	fldl	pdis+96
	fmull	-64(%ebp)
	fldl	pdis+104
	fmull	-72(%ebp)
	fsubrp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	.LC12
	fmulp	%st, %st(1)
	fstpl	taus
	.loc 2 23 0
	fldl	Mfive
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	ddq+8
	fmulp	%st, %st(1)
	fldl	Mfive
	fldl	.LC14
	fmulp	%st, %st(1)
	fldl	ddq+8
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	.LC15
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	.LC16
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	.LC17
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC18
	fmulp	%st, %st(1)
	fmull	-32(%ebp)
	fldl	ddq+8
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-32(%ebp)
	fldl	.LC19
	fmulp	%st, %st(1)
	fldl	ddq+8
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC14
	fmulp	%st, %st(1)
	fldl	ddq+16
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	.LC16
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC20
	fmulp	%st, %st(1)
	fmull	-32(%ebp)
	fldl	ddq+16
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-32(%ebp)
	fldl	.LC21
	fmulp	%st, %st(1)
	fldl	ddq+16
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	I+136
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	I+208
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	I+208
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	I+280
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	I+280
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+24
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	I+280
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	I+288
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	I+288
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+24
	fldl	I+288
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	I+320
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	I+320
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+24
	fldl	I+320
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	.LC22
	fmulp	%st, %st(1)
	fldl	pdis+24
	fmulp	%st, %st(1)
	fldl	pdis+24
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-16(%ebp)
	fldl	.LC23
	fmulp	%st, %st(1)
	fldl	pdis+32
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	.LC22
	fmulp	%st, %st(1)
	fldl	pdis+32
	fmulp	%st, %st(1)
	fldl	pdis+32
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-32(%ebp)
	fldl	.LC24
	fmulp	%st, %st(1)
	fldl	ddq+8
	fmulp	%st, %st(1)
	fldl	pdis+48
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-32(%ebp)
	fldl	.LC17
	fmulp	%st, %st(1)
	fldl	ddq+16
	fmulp	%st, %st(1)
	fldl	pdis+48
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	.LC17
	fmulp	%st, %st(1)
	fldl	pdis+48
	fmulp	%st, %st(1)
	fldl	pdis+48
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	.LC17
	fmulp	%st, %st(1)
	fldl	pdis+48
	fmulp	%st, %st(1)
	fldl	pdis+48
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-112(%ebp)
	fldl	.LC25
	fmulp	%st, %st(1)
	fldl	pdis+56
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-32(%ebp)
	fldl	.LC26
	fmulp	%st, %st(1)
	fldl	dq+8
	fmulp	%st, %st(1)
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	pdis+56
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-32(%ebp)
	fldl	.LC27
	fmulp	%st, %st(1)
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	pdis+56
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	.LC17
	fmulp	%st, %st(1)
	fldl	pdis+56
	fmulp	%st, %st(1)
	fldl	pdis+56
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	.LC17
	fmulp	%st, %st(1)
	fldl	pdis+56
	fmulp	%st, %st(1)
	fldl	pdis+56
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-96(%ebp)
	fldl	.LC28
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-128(%ebp)
	fldl	.LC29
	fmulp	%st, %st(1)
	fldl	dq+8
	fmulp	%st, %st(1)
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-128(%ebp)
	fldl	.LC30
	fmulp	%st, %st(1)
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-48(%ebp)
	fldl	.LC31
	fmulp	%st, %st(1)
	fldl	dq+8
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-128(%ebp)
	fldl	.LC29
	fmulp	%st, %st(1)
	fldl	dq+8
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-48(%ebp)
	fldl	.LC31
	fmulp	%st, %st(1)
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-128(%ebp)
	fldl	.LC29
	fmulp	%st, %st(1)
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-48(%ebp)
	fldl	.LC32
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-128(%ebp)
	fldl	.LC30
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	.LC15
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	.LC15
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+24
	fldl	.LC15
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-48(%ebp)
	fldl	.LC31
	fmulp	%st, %st(1)
	fldl	ddq+8
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-128(%ebp)
	fldl	.LC29
	fmulp	%st, %st(1)
	fldl	ddq+8
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-48(%ebp)
	fldl	.LC31
	fmulp	%st, %st(1)
	fldl	ddq+16
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-128(%ebp)
	fldl	.LC30
	fmulp	%st, %st(1)
	fldl	ddq+16
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-48(%ebp)
	fldl	.LC32
	fmulp	%st, %st(1)
	fldl	ddq+24
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-128(%ebp)
	fldl	.LC30
	fmulp	%st, %st(1)
	fldl	ddq+24
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	.LC15
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	.LC15
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+24
	fldl	.LC15
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	Mfive
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	Mfive
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+24
	fldl	Mfive
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	Mfive
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	Mfive
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+24
	fldl	Mfive
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	dq+24
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+296
	fmulp	%st, %st(1)
	fldl	dq+24
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+312
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	ddq+16
	faddp	%st, %st(1)
	fldl	ddq+24
	faddp	%st, %st(1)
	fldl	I+288
	fldl	I+320
	fsubrp	%st, %st(1)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	ddq+8
	fldl	Mfive
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	Mfive
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC33
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	Mfive
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	ddq+16
	fldl	Mfive
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	dq+8
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+296
	fldl	I+312
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC5
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	dq+16
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+296
	fldl	I+312
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC5
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+24
	fldl	Mfive
	fmulp	%st, %st(1)
	fldl	pdis+96
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+104
	fldl	pdis+104
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmull	-80(%ebp)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC18
	fmulp	%st, %st(1)
	fmull	-48(%ebp)
	fldl	ddq+8
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC34
	fmulp	%st, %st(1)
	fmull	-128(%ebp)
	fldl	ddq+8
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC18
	fmulp	%st, %st(1)
	fmull	-48(%ebp)
	fldl	ddq+16
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fadd	%st(0), %st
	fmull	-128(%ebp)
	fldl	ddq+16
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC20
	fmulp	%st, %st(1)
	fmull	-48(%ebp)
	fldl	ddq+24
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fadd	%st(0), %st
	fmull	-128(%ebp)
	fldl	ddq+24
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	ddq+8
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	ddq+16
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	ddq+24
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC35
	fmulp	%st, %st(1)
	fmull	-24(%ebp)
	faddp	%st, %st(1)
	fldl	-24(%ebp)
	fldl	.LC28
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-24(%ebp)
	fldl	.LC25
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	pdis+24
	fldl	.LC23
	fmulp	%st, %st(1)
	fmull	-24(%ebp)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC36
	fmulp	%st, %st(1)
	fldl	dq+8
	fmulp	%st, %st(1)
	fldl	dq+16
	fmulp	%st, %st(1)
	fmull	-40(%ebp)
	faddp	%st, %st(1)
	fldl	dq+8
	fldl	.LC31
	fmulp	%st, %st(1)
	fldl	dq+16
	fmulp	%st, %st(1)
	fmull	-40(%ebp)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC37
	fmulp	%st, %st(1)
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	dq+16
	fmulp	%st, %st(1)
	fmull	-40(%ebp)
	faddp	%st, %st(1)
	fldl	dq+16
	fldl	.LC32
	fmulp	%st, %st(1)
	fldl	dq+16
	fmulp	%st, %st(1)
	fmull	-40(%ebp)
	faddp	%st, %st(1)
	fldl	dq+8
	fldl	.LC26
	fmulp	%st, %st(1)
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	pdis+48
	fmulp	%st, %st(1)
	fmull	-40(%ebp)
	faddp	%st, %st(1)
	fldl	dq+16
	fldl	.LC27
	fmulp	%st, %st(1)
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	pdis+48
	fmulp	%st, %st(1)
	fmull	-40(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	.LC26
	fmulp	%st, %st(1)
	fldl	pdis+56
	fmulp	%st, %st(1)
	fmull	-40(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	.LC27
	fmulp	%st, %st(1)
	fldl	pdis+56
	fmulp	%st, %st(1)
	fmull	-40(%ebp)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC38
	fmulp	%st, %st(1)
	fmull	-120(%ebp)
	faddp	%st, %st(1)
	fldl	-120(%ebp)
	fldl	.LC39
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	pdis+48
	fldl	.LC25
	fmulp	%st, %st(1)
	fmull	-120(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	.LC31
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	fmull	-56(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	.LC31
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	fmull	-56(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+24
	fldl	.LC32
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	fmull	-56(%ebp)
	faddp	%st, %st(1)
	fldl	dq+8
	fldl	.LC19
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	fmull	-56(%ebp)
	faddp	%st, %st(1)
	fldl	dq+16
	fldl	.LC19
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	fmull	-56(%ebp)
	faddp	%st, %st(1)
	fldl	dq+24
	fldl	.LC21
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	fmull	-56(%ebp)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC36
	fmulp	%st, %st(1)
	fldl	dq+8
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fmull	-56(%ebp)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC36
	fmulp	%st, %st(1)
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fmull	-56(%ebp)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC37
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fmull	-56(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	.LC29
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	fmull	-136(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	.LC30
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	fmull	-136(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+24
	fldl	.LC30
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	fmull	-136(%ebp)
	faddp	%st, %st(1)
	fldl	dq+8
	fldl	.LC40
	fmulp	%st, %st(1)
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	fmull	-136(%ebp)
	faddp	%st, %st(1)
	fldl	dq+16
	fldl	.LC15
	fmulp	%st, %st(1)
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	fmull	-136(%ebp)
	faddp	%st, %st(1)
	fldl	dq+8
	fldl	.LC40
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	fmull	-136(%ebp)
	faddp	%st, %st(1)
	fldl	dq+16
	fldl	.LC40
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	fmull	-136(%ebp)
	faddp	%st, %st(1)
	fldl	dq+24
	fldl	.LC15
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	fmull	-136(%ebp)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC33
	fmulp	%st, %st(1)
	fldl	dq+8
	fmulp	%st, %st(1)
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fmull	-136(%ebp)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC5
	fmulp	%st, %st(1)
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fmull	-136(%ebp)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC33
	fmulp	%st, %st(1)
	fldl	dq+8
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fmull	-136(%ebp)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC33
	fmulp	%st, %st(1)
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fmull	-136(%ebp)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC5
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fmull	-136(%ebp)
	faddp	%st, %st(1)
	fldl	-64(%ebp)
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+32
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+304
	fmulp	%st, %st(1)
	fldl	ddq+32
	fldl	I+328
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-96(%ebp)
	fldl	.LC41
	fmulp	%st, %st(1)
	fldl	dq+16
	fldl	dq+24
	faddp	%st, %st(1)
	fmull	-128(%ebp)
	fldl	dq+8
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+16
	faddp	%st, %st(1)
	fldl	dq+24
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	-48(%ebp)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	dq+8
	fldl	dq+16
	faddp	%st, %st(1)
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+24
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	dq+32
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	-48(%ebp)
	fldl	.LC7
	fmulp	%st, %st(1)
	faddl	-128(%ebp)
	fldl	pdis+112
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	ddq+32
	fldl	pdis+104
	fmulp	%st, %st(1)
	fldl	-48(%ebp)
	fldl	.LC7
	fmulp	%st, %st(1)
	faddl	-128(%ebp)
	fldl	pdis+112
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	ddq+8
	fldl	.LC5
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	-56(%ebp)
	fldl	.LC7
	fmulp	%st, %st(1)
	faddl	-136(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+24
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	-56(%ebp)
	fldl	.LC7
	fmulp	%st, %st(1)
	faddl	-136(%ebp)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	dq+8
	fldl	dq+16
	faddp	%st, %st(1)
	fldl	dq+24
	faddp	%st, %st(1)
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	fldl	-56(%ebp)
	fldl	.LC7
	fmulp	%st, %st(1)
	faddl	-136(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	-56(%ebp)
	fldl	.LC20
	fmulp	%st, %st(1)
	faddl	-136(%ebp)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	Mfive
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	pdis+80
	fldl	.LC43
	fmulp	%st, %st(1)
	fmull	-104(%ebp)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC35
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fmull	-104(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+32
	fldl	I+304
	fmulp	%st, %st(1)
	fldl	dq+32
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+328
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	pdis+104
	fldl	-96(%ebp)
	fldl	.LC4
	fmulp	%st, %st(1)
	fldl	dq+32
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	fldl	ddq+32
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	dq+24
	fldl	dq+8
	fldl	dq+16
	faddp	%st, %st(1)
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+24
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	fldl	dq+32
	fldl	dq+32
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	fldl	ddq+32
	fldl	pdis+96
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fmull	-48(%ebp)
	fldl	dq+8
	fldl	dq+16
	faddp	%st, %st(1)
	fldl	dq+24
	faddp	%st, %st(1)
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	ddq+8
	fldl	ddq+16
	faddp	%st, %st(1)
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	ddq+24
	faddp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmull	-56(%ebp)
	faddp	%st, %st(1)
	fldl	.LC7
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	dq+16
	fmull	-128(%ebp)
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	fldl	ddq+32
	fmull	-128(%ebp)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	dq+24
	fmull	-128(%ebp)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	dq+32
	fmull	-128(%ebp)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	dq+24
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fmull	-136(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+8
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	fmull	-136(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	pdis+104
	fmulp	%st, %st(1)
	fmull	-136(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+24
	fldl	pdis+104
	fmulp	%st, %st(1)
	fmull	-136(%ebp)
	faddp	%st, %st(1)
	fldl	dq+16
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+24
	fmull	-128(%ebp)
	fldl	pdis+104
	fmulp	%st, %st(1)
	fldl	dq+32
	fldl	pdis+96
	fmulp	%st, %st(1)
	fmull	-136(%ebp)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	dq+8
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+16
	fldl	dq+24
	faddp	%st, %st(1)
	fmull	-128(%ebp)
	fldl	pdis+104
	fmulp	%st, %st(1)
	fldl	dq+32
	fldl	pdis+96
	fmulp	%st, %st(1)
	fmull	-136(%ebp)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fadd	%st(0), %st
	fmull	-72(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	ddq+16
	faddp	%st, %st(1)
	fldl	ddq+24
	faddp	%st, %st(1)
	fldl	I+296
	fldl	I+312
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	fldl	dq+8
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+288
	fldl	I+320
	fsubrp	%st, %st(1)
	fldl	pdis+96
	fchs
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+104
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	dq+16
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+288
	fldl	I+320
	fsubrp	%st, %st(1)
	fldl	pdis+96
	fchs
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+104
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	dq+24
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+288
	fldl	I+320
	fsubrp	%st, %st(1)
	fldl	pdis+96
	fchs
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+104
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	fldl	ddq+8
	fldl	ddq+16
	faddp	%st, %st(1)
	fldl	ddq+24
	faddp	%st, %st(1)
	fldl	Mfive
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fadd	%st(0), %st
	faddp	%st, %st(1)
	fmull	-88(%ebp)
	faddp	%st, %st(1)
	fldl	.LC44
	fdivrp	%st, %st(1)
	fstpl	taus+8
	.loc 2 24 0
	fldl	Mfive
	fldl	.LC14
	fmulp	%st, %st(1)
	fldl	ddq+8
	fmulp	%st, %st(1)
	fldl	ddq+8
	fldl	.LC16
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC20
	fmulp	%st, %st(1)
	fmull	-32(%ebp)
	fldl	ddq+8
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-32(%ebp)
	fldl	.LC21
	fmulp	%st, %st(1)
	fldl	ddq+8
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC14
	fmulp	%st, %st(1)
	fldl	ddq+16
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	.LC16
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	I+208
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	I+208
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	I+280
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	I+280
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+24
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	I+280
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	I+288
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	I+288
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+24
	fldl	I+288
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	I+320
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	I+320
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+24
	fldl	I+320
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-32(%ebp)
	fldl	.LC17
	fmulp	%st, %st(1)
	fldl	ddq+8
	fmulp	%st, %st(1)
	fldl	pdis+48
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	.LC17
	fmulp	%st, %st(1)
	fldl	pdis+48
	fmulp	%st, %st(1)
	fldl	pdis+48
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	.LC17
	fmulp	%st, %st(1)
	fldl	pdis+48
	fmulp	%st, %st(1)
	fldl	pdis+48
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-112(%ebp)
	fldl	.LC25
	fmulp	%st, %st(1)
	fldl	pdis+56
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-32(%ebp)
	fldl	.LC17
	fmulp	%st, %st(1)
	fldl	dq+8
	fmulp	%st, %st(1)
	fldl	dq+8
	fmulp	%st, %st(1)
	fldl	pdis+56
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	.LC17
	fmulp	%st, %st(1)
	fldl	pdis+56
	fmulp	%st, %st(1)
	fldl	pdis+56
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	.LC17
	fmulp	%st, %st(1)
	fldl	pdis+56
	fmulp	%st, %st(1)
	fldl	pdis+56
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-96(%ebp)
	fldl	.LC28
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-128(%ebp)
	fldl	.LC15
	fmulp	%st, %st(1)
	fldl	dq+8
	fmulp	%st, %st(1)
	fldl	dq+8
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-48(%ebp)
	fldl	.LC31
	fmulp	%st, %st(1)
	fldl	dq+8
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-48(%ebp)
	fldl	.LC31
	fmulp	%st, %st(1)
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-48(%ebp)
	fldl	.LC32
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	.LC15
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	.LC15
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+24
	fldl	.LC15
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-48(%ebp)
	fldl	.LC31
	fmulp	%st, %st(1)
	fldl	ddq+8
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-128(%ebp)
	fldl	.LC30
	fmulp	%st, %st(1)
	fldl	ddq+8
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-48(%ebp)
	fldl	.LC31
	fmulp	%st, %st(1)
	fldl	ddq+16
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-48(%ebp)
	fldl	.LC32
	fmulp	%st, %st(1)
	fldl	ddq+24
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	.LC15
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	.LC15
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+24
	fldl	.LC15
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	Mfive
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	Mfive
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+24
	fldl	Mfive
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	Mfive
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	Mfive
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+24
	fldl	Mfive
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	dq+24
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+296
	fmulp	%st, %st(1)
	fldl	dq+24
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+312
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	ddq+16
	faddp	%st, %st(1)
	fldl	ddq+24
	faddp	%st, %st(1)
	fldl	I+288
	fldl	I+320
	fsubrp	%st, %st(1)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	ddq+8
	fldl	Mfive
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	Mfive
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC33
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	Mfive
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	ddq+16
	fldl	Mfive
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	dq+8
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+296
	fldl	I+312
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC5
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	dq+16
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+296
	fldl	I+312
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC5
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+24
	fldl	Mfive
	fmulp	%st, %st(1)
	fldl	pdis+96
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+104
	fldl	pdis+104
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmull	-80(%ebp)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC18
	fmulp	%st, %st(1)
	fmull	-48(%ebp)
	fldl	ddq+8
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fadd	%st(0), %st
	fmull	-128(%ebp)
	fldl	ddq+8
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC18
	fmulp	%st, %st(1)
	fmull	-48(%ebp)
	fldl	ddq+16
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC20
	fmulp	%st, %st(1)
	fmull	-48(%ebp)
	fldl	ddq+24
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	ddq+8
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	ddq+16
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	ddq+24
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC20
	fmulp	%st, %st(1)
	fldl	dq+8
	fmulp	%st, %st(1)
	fldl	dq+8
	fmulp	%st, %st(1)
	fmull	-40(%ebp)
	faddp	%st, %st(1)
	fldl	dq+8
	fldl	.LC21
	fmulp	%st, %st(1)
	fldl	dq+8
	fmulp	%st, %st(1)
	fmull	-40(%ebp)
	faddp	%st, %st(1)
	fldl	dq+8
	fldl	.LC17
	fmulp	%st, %st(1)
	fldl	dq+8
	fmulp	%st, %st(1)
	fldl	pdis+48
	fmulp	%st, %st(1)
	fmull	-40(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	.LC27
	fmulp	%st, %st(1)
	fldl	pdis+56
	fmulp	%st, %st(1)
	fmull	-40(%ebp)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC38
	fmulp	%st, %st(1)
	fmull	-120(%ebp)
	faddp	%st, %st(1)
	fldl	-120(%ebp)
	fldl	.LC39
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	pdis+48
	fldl	.LC25
	fmulp	%st, %st(1)
	fmull	-120(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	.LC31
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	fmull	-56(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	.LC31
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	fmull	-56(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+24
	fldl	.LC32
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	fmull	-56(%ebp)
	faddp	%st, %st(1)
	fldl	dq+8
	fldl	.LC19
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	fmull	-56(%ebp)
	faddp	%st, %st(1)
	fldl	dq+16
	fldl	.LC19
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	fmull	-56(%ebp)
	faddp	%st, %st(1)
	fldl	dq+24
	fldl	.LC21
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	fmull	-56(%ebp)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC36
	fmulp	%st, %st(1)
	fldl	dq+8
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fmull	-56(%ebp)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC36
	fmulp	%st, %st(1)
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fmull	-56(%ebp)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC37
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fmull	-56(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	.LC30
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	fmull	-136(%ebp)
	faddp	%st, %st(1)
	fldl	dq+8
	fldl	.LC30
	fmulp	%st, %st(1)
	fldl	dq+8
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	fmull	-136(%ebp)
	faddp	%st, %st(1)
	fldl	Mfive
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+8
	fmulp	%st, %st(1)
	fldl	dq+8
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fmull	-136(%ebp)
	faddp	%st, %st(1)
	fldl	-64(%ebp)
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+32
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+304
	fmulp	%st, %st(1)
	fldl	ddq+32
	fldl	I+328
	fldl	pdis+104
	fldl	Mfive
	fmulp	%st, %st(1)
	fldl	-48(%ebp)
	fldl	.LC7
	fmulp	%st, %st(1)
	fldl	pdis+112
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	dq+8
	fldl	dq+16
	faddp	%st, %st(1)
	fldl	dq+24
	faddp	%st, %st(1)
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	fldl	ddq+8
	fldl	ddq+16
	faddp	%st, %st(1)
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	ddq+24
	faddp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fmull	-56(%ebp)
	fldl	dq+24
	fldl	dq+8
	fldl	dq+16
	faddp	%st, %st(1)
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+24
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	fldl	dq+32
	fldl	dq+32
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmull	-48(%ebp)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	.LC7
	fmulp	%st, %st(1)
	fldl	pdis+96
	fldl	-96(%ebp)
	fldl	.LC4
	fmulp	%st, %st(1)
	fldl	dq+32
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	pdis+96
	fldl	dq+8
	fmull	-128(%ebp)
	fldl	dq+8
	fmulp	%st, %st(1)
	fldl	ddq+8
	fmull	-136(%ebp)
	fsubrp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	pdis+80
	fldl	.LC43
	fmulp	%st, %st(1)
	fmull	-104(%ebp)
	faddp	%st, %st(1)
	fldl	Mfive
	fldl	.LC35
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fmull	-104(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+32
	fldl	I+304
	fmulp	%st, %st(1)
	fldl	dq+32
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+328
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	pdis+104
	fldl	-96(%ebp)
	fldl	.LC4
	fmulp	%st, %st(1)
	fldl	dq+32
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	fldl	ddq+32
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	dq+24
	fldl	dq+8
	fldl	dq+16
	faddp	%st, %st(1)
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+24
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	fldl	dq+32
	fldl	dq+32
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	fldl	ddq+32
	fldl	pdis+96
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fmull	-48(%ebp)
	fldl	dq+8
	fldl	dq+16
	faddp	%st, %st(1)
	fldl	dq+24
	faddp	%st, %st(1)
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	ddq+8
	fldl	ddq+16
	faddp	%st, %st(1)
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	ddq+24
	faddp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmull	-56(%ebp)
	faddp	%st, %st(1)
	fldl	.LC7
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	pdis+104
	fldl	ddq+8
	fmull	-136(%ebp)
	fldl	dq+8
	fmull	-128(%ebp)
	fldl	dq+8
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fadd	%st(0), %st
	fmull	-72(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	ddq+16
	faddp	%st, %st(1)
	fldl	ddq+24
	faddp	%st, %st(1)
	fldl	I+296
	fldl	I+312
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	fldl	dq+8
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+288
	fldl	I+320
	fsubrp	%st, %st(1)
	fldl	pdis+96
	fchs
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+104
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	dq+16
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+288
	fldl	I+320
	fsubrp	%st, %st(1)
	fldl	pdis+96
	fchs
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+104
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	dq+24
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+288
	fldl	I+320
	fsubrp	%st, %st(1)
	fldl	pdis+96
	fchs
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+104
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	Mfive
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	fldl	ddq+8
	fldl	ddq+16
	faddp	%st, %st(1)
	fldl	ddq+24
	faddp	%st, %st(1)
	fldl	Mfive
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fadd	%st(0), %st
	faddp	%st, %st(1)
	fmull	-88(%ebp)
	faddp	%st, %st(1)
	fldl	.LC44
	fdivrp	%st, %st(1)
	fstpl	taus+16
	.loc 2 25 0
	fldl	ddq+8
	fldl	ddq+16
	faddp	%st, %st(1)
	fldl	ddq+24
	faddp	%st, %st(1)
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	I+280
	fmulp	%st, %st(1)
	fldl	ddq+8
	fldl	I+288
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fmull	-80(%ebp)
	fldl	I+288
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	ddq+16
	fldl	I+288
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fmull	-80(%ebp)
	fldl	I+288
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	ddq+24
	fldl	I+288
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+24
	fmull	-80(%ebp)
	fldl	I+288
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	-80(%ebp)
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+8
	fmulp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+296
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-80(%ebp)
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+296
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-80(%ebp)
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+296
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-64(%ebp)
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+304
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-80(%ebp)
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+8
	fmulp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+312
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-80(%ebp)
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+312
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-80(%ebp)
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+312
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	I+320
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fmull	-80(%ebp)
	fldl	I+320
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	I+320
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fmull	-80(%ebp)
	fldl	I+320
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+24
	fldl	I+320
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+24
	fmull	-80(%ebp)
	fldl	I+320
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-96(%ebp)
	fldl	.LC41
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	fldl	ddq+8
	fldl	ddq+16
	faddp	%st, %st(1)
	fldl	ddq+24
	faddp	%st, %st(1)
	fldl	pdis+72
	fldl	pdis+72
	fmulp	%st, %st(1)
	fldl	pdis+80
	fldl	pdis+80
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	dq+8
	fldl	dq+16
	faddp	%st, %st(1)
	fldl	dq+8
	fldl	dq+16
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	fldl	ddq+8
	fldl	ddq+16
	faddp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fmull	-48(%ebp)
	fldl	ddq+8
	fldl	ddq+16
	faddp	%st, %st(1)
	fldl	pdis+72
	fmulp	%st, %st(1)
	fldl	dq+8
	fldl	dq+16
	faddp	%st, %st(1)
	fldl	dq+8
	fldl	dq+16
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	fldl	pdis+80
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmull	-56(%ebp)
	fsubrp	%st, %st(1)
	fldl	.LC7
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	dq+8
	fldl	dq+8
	fmulp	%st, %st(1)
	fldl	pdis+72
	fmull	-128(%ebp)
	fldl	pdis+80
	fmull	-136(%ebp)
	fsubrp	%st, %st(1)
	fmulp	%st, %st(1)
	fldl	ddq+8
	fldl	pdis+80
	fmull	-128(%ebp)
	fldl	pdis+72
	fmull	-136(%ebp)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	pdis+80
	fldl	.LC4
	fmulp	%st, %st(1)
	fmull	-104(%ebp)
	faddp	%st, %st(1)
	fldl	.LC15
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	dq+32
	fldl	.LC5
	fmulp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+328
	fmulp	%st, %st(1)
	fmull	-72(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+32
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	I+328
	fmull	-64(%ebp)
	fldl	I+304
	fmull	-72(%ebp)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	dq+8
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+288
	fmulp	%st, %st(1)
	fmull	-88(%ebp)
	faddp	%st, %st(1)
	fldl	dq+16
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+288
	fmulp	%st, %st(1)
	fmull	-88(%ebp)
	faddp	%st, %st(1)
	fldl	dq+24
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+288
	fmulp	%st, %st(1)
	fmull	-88(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	I+296
	fmulp	%st, %st(1)
	fmull	-88(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	I+296
	fmulp	%st, %st(1)
	fmull	-88(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+24
	fldl	I+296
	fmulp	%st, %st(1)
	fmull	-88(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	I+312
	fmulp	%st, %st(1)
	fmull	-88(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	I+312
	fmulp	%st, %st(1)
	fmull	-88(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+24
	fldl	I+312
	fmulp	%st, %st(1)
	fmull	-88(%ebp)
	faddp	%st, %st(1)
	fldl	dq+8
	fldl	.LC5
	fmulp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+320
	fmulp	%st, %st(1)
	fmull	-88(%ebp)
	faddp	%st, %st(1)
	fldl	dq+16
	fldl	.LC5
	fmulp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+320
	fmulp	%st, %st(1)
	fmull	-88(%ebp)
	faddp	%st, %st(1)
	fldl	dq+24
	fldl	.LC5
	fmulp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+320
	fmulp	%st, %st(1)
	fmull	-88(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	ddq+16
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+24
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	pdis+104
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	pdis+104
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+24
	fldl	pdis+104
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	ddq+16
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	dq+8
	fldl	.LC33
	fmulp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	dq+16
	fldl	.LC33
	fmulp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	dq+24
	fldl	.LC33
	fmulp	%st, %st(1)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	pdis+104
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	ddq+16
	fldl	pdis+104
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	ddq+24
	fldl	pdis+96
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+104
	fldl	pdis+104
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmull	-80(%ebp)
	faddp	%st, %st(1)
	fldl	-48(%ebp)
	fldl	.LC20
	fmulp	%st, %st(1)
	fldl	ddq+8
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-128(%ebp)
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	ddq+8
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-48(%ebp)
	fldl	.LC20
	fmulp	%st, %st(1)
	fldl	ddq+16
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+24
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	dq+8
	fldl	.LC20
	fmulp	%st, %st(1)
	fldl	dq+8
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fmull	-56(%ebp)
	faddp	%st, %st(1)
	fldl	dq+8
	fldl	.LC18
	fmulp	%st, %st(1)
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fmull	-56(%ebp)
	faddp	%st, %st(1)
	fldl	dq+16
	fldl	.LC20
	fmulp	%st, %st(1)
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fmull	-56(%ebp)
	faddp	%st, %st(1)
	fldl	dq+8
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+8
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fmull	-136(%ebp)
	faddp	%st, %st(1)
	fldl	-64(%ebp)
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	ddq+32
	fldl	pdis+104
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fchs
	fstpl	-160(%ebp)
	fldl	pdis+96
	fstpl	-152(%ebp)
	fldl	-96(%ebp)
	fldl	.LC4
	fmulp	%st, %st(1)
	fldl	dq+32
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	ddq+16
	faddp	%st, %st(1)
	fmull	-56(%ebp)
	fldl	dq+8
	fldl	dq+16
	faddp	%st, %st(1)
	fmull	-48(%ebp)
	fldl	dq+8
	fldl	dq+16
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	.LC7
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fmull	-136(%ebp)
	fldl	dq+8
	fmull	-128(%ebp)
	fldl	dq+8
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	faddp	%st, %st(1)
	fmull	-152(%ebp)
	fsubrl	-160(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	pdis+112
	fldl	.LC35
	fmulp	%st, %st(1)
	fmull	-104(%ebp)
	faddp	%st, %st(1)
	fldl	pdis+104
	fldl	-96(%ebp)
	fldl	.LC4
	fmulp	%st, %st(1)
	fldl	dq+32
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	ddq+16
	faddp	%st, %st(1)
	fmull	-56(%ebp)
	fldl	dq+8
	fldl	dq+16
	faddp	%st, %st(1)
	fmull	-48(%ebp)
	fldl	dq+8
	fldl	dq+16
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	.LC7
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fmull	-136(%ebp)
	fldl	dq+8
	fmull	-128(%ebp)
	fldl	dq+8
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	fldl	ddq+32
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fadd	%st(0), %st
	fmull	-72(%ebp)
	faddp	%st, %st(1)
	fldl	dq+24
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	ddq+8
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+24
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	dq+24
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	dq+8
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	pdis+96
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+104
	fldl	pdis+104
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	dq+16
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	pdis+96
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+104
	fldl	pdis+104
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	.LC5
	fmulp	%st, %st(1)
	fmull	-88(%ebp)
	faddp	%st, %st(1)
	fldl	Mfive
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	.LC44
	fdivrp	%st, %st(1)
	fstpl	taus+24
	.loc 2 26 0
	fldl	-64(%ebp)
	fldl	.LC5
	fmulp	%st, %st(1)
	fmull	-64(%ebp)
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	I+296
	fmulp	%st, %st(1)
	fldl	-64(%ebp)
	fmull	-64(%ebp)
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	I+296
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	-64(%ebp)
	fmull	-64(%ebp)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	I+296
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	dq+16
	fmull	-64(%ebp)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+304
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	dq+24
	fmull	-64(%ebp)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+304
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	dq+16
	fmull	-64(%ebp)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+336
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	dq+24
	fmull	-64(%ebp)
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+336
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fmull	-64(%ebp)
	fldl	I+344
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+16
	fmull	-64(%ebp)
	fldl	I+344
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+24
	fmull	-64(%ebp)
	fldl	I+344
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+32
	fldl	I+352
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	dq+16
	fmull	-64(%ebp)
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	I+320
	fmulp	%st, %st(1)
	fmull	-72(%ebp)
	faddp	%st, %st(1)
	fldl	dq+24
	fmull	-64(%ebp)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	I+320
	fmulp	%st, %st(1)
	fmull	-72(%ebp)
	faddp	%st, %st(1)
	fldl	dq+16
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+328
	fmulp	%st, %st(1)
	fmull	-72(%ebp)
	faddp	%st, %st(1)
	fldl	dq+24
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+328
	fmulp	%st, %st(1)
	fmull	-72(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+8
	fldl	I+336
	fmulp	%st, %st(1)
	fmull	-72(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+16
	fldl	I+336
	fmulp	%st, %st(1)
	fmull	-72(%ebp)
	faddp	%st, %st(1)
	fldl	ddq+24
	fldl	I+336
	fmulp	%st, %st(1)
	fmull	-72(%ebp)
	faddp	%st, %st(1)
	fldl	dq+16
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+344
	fmulp	%st, %st(1)
	fmull	-72(%ebp)
	fsubrp	%st, %st(1)
	fldl	dq+24
	fldl	dq+32
	fmulp	%st, %st(1)
	fldl	I+344
	fmulp	%st, %st(1)
	fmull	-72(%ebp)
	fsubrp	%st, %st(1)
	fldl	dq+16
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	I+312
	fmulp	%st, %st(1)
	fmull	-72(%ebp)
	fmull	-72(%ebp)
	faddp	%st, %st(1)
	fldl	dq+16
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	I+312
	fmulp	%st, %st(1)
	fmull	-72(%ebp)
	fmull	-72(%ebp)
	faddp	%st, %st(1)
	fldl	dq+24
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	I+312
	fmulp	%st, %st(1)
	fmull	-72(%ebp)
	fmull	-72(%ebp)
	faddp	%st, %st(1)
	fldl	dq+16
	fldl	dq+16
	fmulp	%st, %st(1)
	fldl	I+288
	fmulp	%st, %st(1)
	fmull	-88(%ebp)
	fldl	.LC5
	fdivrp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	dq+16
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	I+288
	fmulp	%st, %st(1)
	fmull	-88(%ebp)
	fsubrp	%st, %st(1)
	fldl	dq+24
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	I+288
	fmulp	%st, %st(1)
	fmull	-88(%ebp)
	fldl	.LC5
	fdivrp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	dq+16
	fldl	dq+24
	fmulp	%st, %st(1)
	fldl	I+320
	fmulp	%st, %st(1)
	fmull	-88(%ebp)
	faddp	%st, %st(1)
	fldl	dq+8
	fldl	dq+8
	fmulp	%st, %st(1)
	fldl	I+320
	fmull	-64(%ebp)
	fmull	-72(%ebp)
	fldl	-64(%ebp)
	fmull	-64(%ebp)
	fldl	I+296
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	I+312
	fmull	-72(%ebp)
	fmull	-72(%ebp)
	faddp	%st, %st(1)
	fldl	I+288
	fmull	-88(%ebp)
	fldl	.LC5
	fdivrp	%st, %st(1)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstpl	-144(%ebp)
	fldl	-80(%ebp)
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	dq+8
	fldl	dq+16
	faddp	%st, %st(1)
	fldl	dq+24
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	fldl	dq+8
	fldl	dq+16
	faddp	%st, %st(1)
	fldl	dq+24
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+104
	fmulp	%st, %st(1)
	fldl	ddq+32
	fld	%st(0)
	faddp	%st, %st(1)
	fldl	pdis+96
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+104
	fldl	pdis+104
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	-64(%ebp)
	fldl	.LC5
	fmulp	%st, %st(1)
	fldl	pdis+104
	fldl	ddq+8
	fldl	ddq+16
	faddp	%st, %st(1)
	fldl	ddq+24
	faddp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fldl	ddq+8
	fldl	ddq+16
	faddp	%st, %st(1)
	fmull	-48(%ebp)
	fldl	dq+8
	fldl	dq+16
	faddp	%st, %st(1)
	fldl	dq+8
	fldl	dq+16
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	fmull	-56(%ebp)
	faddp	%st, %st(1)
	fldl	.LC7
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fmull	-128(%ebp)
	fldl	dq+8
	fldl	dq+8
	fmulp	%st, %st(1)
	fmull	-136(%ebp)
	faddp	%st, %st(1)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	fldl	ddq
	fldl	pdis+96
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fldl	pdis+104
	fldl	.LC41
	fmulp	%st, %st(1)
	fmull	-104(%ebp)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq
	fldl	pdis+104
	fmulp	%st, %st(1)
	fldl	pdis+96
	fldl	ddq+8
	fldl	ddq+16
	faddp	%st, %st(1)
	fldl	ddq+24
	faddp	%st, %st(1)
	fldl	pdis+112
	fmulp	%st, %st(1)
	fldl	ddq+8
	fldl	ddq+16
	faddp	%st, %st(1)
	fmull	-48(%ebp)
	fldl	dq+8
	fldl	dq+16
	faddp	%st, %st(1)
	fldl	dq+8
	fldl	dq+16
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	fmull	-56(%ebp)
	faddp	%st, %st(1)
	fldl	.LC7
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	ddq+8
	fmull	-128(%ebp)
	fldl	dq+8
	fldl	dq+8
	fmulp	%st, %st(1)
	fmull	-136(%ebp)
	faddp	%st, %st(1)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	pdis+96
	fldl	.LC41
	fmulp	%st, %st(1)
	fmull	-104(%ebp)
	faddp	%st, %st(1)
	fldl	.LC5
	fmulp	%st, %st(1)
	fmull	-72(%ebp)
	faddp	%st, %st(1)
	fldl	dq+8
	fldl	dq+16
	faddp	%st, %st(1)
	fldl	dq+24
	faddp	%st, %st(1)
	fldl	dq+8
	fldl	dq+16
	faddp	%st, %st(1)
	fldl	dq+24
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	fldl	pdis+96
	fldl	pdis+96
	fmulp	%st, %st(1)
	fldl	pdis+104
	fldl	pdis+104
	fmulp	%st, %st(1)
	fsubrp	%st, %st(1)
	fmulp	%st, %st(1)
	fmull	-88(%ebp)
	faddp	%st, %st(1)
	fldl	Mfive
	fmulp	%st, %st(1)
	fldl	.LC44
	fdivrp	%st, %st(1)
	fldl	-144(%ebp)
	faddp	%st, %st(1)
	fldl	dq+8
	fldl	dq+32
	fldl	I+336
	fldl	I+304
	fsubrp	%st, %st(1)
	fmull	-64(%ebp)
	fldl	I+328
	fldl	I+344
	fsubrp	%st, %st(1)
	fmull	-72(%ebp)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	fldl	dq+16
	fldl	dq+24
	faddp	%st, %st(1)
	fldl	-64(%ebp)
	fldl	.LC5
	fmulp	%st, %st(1)
	fmull	-64(%ebp)
	fldl	I+296
	fmulp	%st, %st(1)
	fldl	I+312
	fadd	%st(0), %st
	fmull	-72(%ebp)
	fmull	-72(%ebp)
	faddp	%st, %st(1)
	fldl	I+320
	fldl	I+288
	fsubrp	%st, %st(1)
	fmull	-88(%ebp)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstpl	taus+32
	.loc 2 27 0
	leave
	ret
	.cfi_endproc
.LFE26:
	.size	computetaus, .-computetaus
.globl fric
	.data
	.align 32
	.type	fric, @object
	.size	fric, 200
fric:
	.long	-2121650622
	.long	1059378210
	.long	-1717986918
	.long	1069128089
	.long	967955062
	.long	1074483645
	.long	-2023409258
	.long	1075994203
	.long	-581223837
	.long	1058243133
	.long	-1785518923
	.long	1062901079
	.long	-885249797
	.long	1069127840
	.long	-1844298814
	.long	1080673593
	.long	-1227384830
	.long	1075216845
	.long	-1497182993
	.long	1078256231
	.long	0
	.long	0
	.long	1323493141
	.long	1069128045
	.long	-515637968
	.long	1079908048
	.long	191183082
	.long	1078780948
	.long	-429722129
	.long	1061160970
	.long	1441437754
	.long	1057132710
	.long	-1717986918
	.long	1069128089
	.long	679905005
	.long	1077715155
	.long	2053140053
	.long	1079117012
	.long	-1526188110
	.long	1070799093
	.long	-799828739
	.long	1052168487
	.long	1135828497
	.long	1069128089
	.long	887800664
	.long	1077539703
	.long	376978557
	.long	1077227858
	.long	398704906
	.long	1052289434
	.text
.globl sgn
	.type	sgn, @function
sgn:
.LFB27:
	.loc 2 31 0
	.cfi_startproc
	pushl	%ebp
.LCFI54:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI55:
	.cfi_def_cfa_register 5
	subl	$8, %esp
	call	mcount
	movl	8(%ebp), %eax
	movl	%eax, -8(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -4(%ebp)
	.loc 2 32 0
	fldl	-8(%ebp)
	fldl	.LC45
	fucompp
	fnstsw	%ax
	testb	$69, %ah
	sete	%al
	testb	%al, %al
	je	.L115
	.loc 2 33 0
	fld1
	fchs
	jmp	.L116
.L115:
	.loc 2 34 0
	fldl	-8(%ebp)
	fldl	.LC47
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	seta	%al
	testb	%al, %al
	je	.L117
	.loc 2 35 0
	fld1
	jmp	.L116
.L117:
	.loc 2 37 0
	fldz
.L116:
	.loc 2 38 0
	leave
	ret
	.cfi_endproc
.LFE27:
	.size	sgn, .-sgn
.globl tau
	.type	tau, @function
tau:
.LFB28:
	.loc 2 40 0
	.cfi_startproc
	pushl	%ebp
.LCFI56:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI57:
	.cfi_def_cfa_register 5
	subl	$56, %esp
	call	mcount
	.loc 2 41 0
	movl	8(%ebp), %eax
	fldl	taus(,%eax,8)
	fstpl	-32(%ebp)
	movl	8(%ebp), %eax
	fldl	dq(,%eax,8)
	fstpl	(%esp)
	call	sgn
	fstpl	-24(%ebp)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	fric(%eax)
	fstpl	-16(%ebp)
	movl	8(%ebp), %eax
	fldl	dq(,%eax,8)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	$1, %eax
	fldl	fric(,%eax,8)
	fdivrp	%st, %st(1)
	fabs
	fchs
	fstpl	(%esp)
	call	exp
	fldl	-16(%ebp)
	fmulp	%st, %st(1)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	fric+16(%eax)
	faddp	%st, %st(1)
	movl	8(%ebp), %eax
	fldl	dq(,%eax,8)
	fabs
	movl	8(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	fric+24(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmull	-24(%ebp)
	fldl	-32(%ebp)
	faddp	%st, %st(1)
	movl	8(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	fldl	fric+32(%eax)
	movl	8(%ebp), %eax
	fldl	ddq(,%eax,8)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	.loc 2 42 0
	leave
	ret
	.cfi_endproc
.LFE28:
	.size	tau, .-tau
	.data
	.align 4
	.type	last_timestep.4407, @object
	.size	last_timestep.4407, 24
last_timestep.4407:
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.align 4
	.type	last_timestep.4310, @object
	.size	last_timestep.4310, 24
last_timestep.4310:
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.align 4
	.type	last_timestep.4206, @object
	.size	last_timestep.4206, 20
last_timestep.4206:
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.align 4
	.type	last_timestep.4061, @object
	.size	last_timestep.4061, 20
last_timestep.4061:
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.align 4
	.type	last_timestep.3864, @object
	.size	last_timestep.3864, 24
last_timestep.3864:
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.align 4
	.type	last_timestep.3714, @object
	.size	last_timestep.3714, 24
last_timestep.3714:
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.align 4
	.type	last_timestep.3629, @object
	.size	last_timestep.3629, 24
last_timestep.3629:
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.align 4
	.type	last_timestep.3498, @object
	.size	last_timestep.3498, 24
last_timestep.3498:
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.align 4
	.type	last_timestep.3425, @object
	.size	last_timestep.3425, 24
last_timestep.3425:
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.align 4
	.type	last_timestep.3383, @object
	.size	last_timestep.3383, 24
last_timestep.3383:
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.long	-1
	.local	dv.3346
	.comm	dv.3346,40,32
	.local	dv.3338
	.comm	dv.3338,40,32
	.local	dv.3330
	.comm	dv.3330,40,32
	.align 32
	.type	alv.3324, @object
	.size	alv.3324, 40
alv.3324:
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	1413754152
	.long	1073291771
	.section	.rodata
	.align 8
.LC2:
	.long	1413754152
	.long	1073291771
	.align 8
.LC4:
	.long	1374389535
	.long	1076076216
	.align 8
.LC5:
	.long	0
	.long	-1073741824
	.align 8
.LC6:
	.long	-755914244
	.long	1062232653
	.align 8
.LC7:
	.long	68719477
	.long	1072762454
	.align 8
.LC8:
	.long	0
	.long	1080279040
	.align 8
.LC9:
	.long	687194767
	.long	1078816604
	.align 8
.LC10:
	.long	-920840988
	.long	1079030757
	.align 8
.LC11:
	.long	-1030792151
	.long	1074997493
	.align 8
.LC12:
	.long	-1717986918
	.long	1067030937
	.align 8
.LC13:
	.long	-831505669
	.long	1081214856
	.align 8
.LC14:
	.long	-1593192348
	.long	1073884803
	.align 8
.LC15:
	.long	-1030792151
	.long	1076046069
	.align 8
.LC16:
	.long	-576407975
	.long	1076217287
	.align 8
.LC17:
	.long	-920840988
	.long	1080079333
	.align 8
.LC18:
	.long	68719477
	.long	1074859606
	.align 8
.LC19:
	.long	-153931628
	.long	1077177519
	.align 8
.LC20:
	.long	68719477
	.long	1073811030
	.align 8
.LC21:
	.long	-153931628
	.long	1076128943
	.align 8
.LC22:
	.long	687194767
	.long	1079865180
	.align 8
.LC23:
	.long	453548546
	.long	-1064170466
	.align 8
.LC24:
	.long	-920840988
	.long	1081127909
	.align 8
.LC25:
	.long	-968119988
	.long	-1064010927
	.align 8
.LC26:
	.long	-920840988
	.long	-1066355739
	.align 8
.LC27:
	.long	-920840988
	.long	-1067404315
	.align 8
.LC28:
	.long	185542588
	.long	-1068007755
	.align 8
.LC29:
	.long	-1030792151
	.long	-1070389003
	.align 8
.LC30:
	.long	-1030792151
	.long	-1071437579
	.align 8
.LC31:
	.long	-153931628
	.long	-1070306129
	.align 8
.LC32:
	.long	-153931628
	.long	-1071354705
	.align 8
.LC33:
	.long	0
	.long	-1072693248
	.align 8
.LC34:
	.long	0
	.long	1074790400
	.align 8
.LC35:
	.long	1374389535
	.long	-1070358856
	.align 8
.LC36:
	.long	68719477
	.long	-1072624042
	.align 8
.LC37:
	.long	68719477
	.long	-1073672618
	.align 8
.LC38:
	.long	846623954
	.long	-1070273992
	.align 8
.LC39:
	.long	-1992644922
	.long	-1067906131
	.align 8
.LC40:
	.long	-1030792151
	.long	1077094645
	.align 8
.LC41:
	.long	1374389535
	.long	-1071407432
	.align 8
.LC42:
	.long	68719477
	.long	-1074721194
	.align 8
.LC43:
	.long	185542588
	.long	1079475893
	.align 8
.LC44:
	.long	0
	.long	1073741824
	.align 8
.LC45:
	.long	-1998362383
	.long	-1092290379
	.align 8
.LC47:
	.long	-1998362383
	.long	1055193269
	.text
.Letext0:
	.section	.debug_loc,"",@progbits
.Ldebug_loc0:
.LLST0:
	.long	.LFB0-.Ltext0
	.long	.LCFI0-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI0-.Ltext0
	.long	.LCFI1-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI1-.Ltext0
	.long	.LFE0-.Ltext0
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST1:
	.long	.LFB1-.Ltext0
	.long	.LCFI2-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI2-.Ltext0
	.long	.LCFI3-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI3-.Ltext0
	.long	.LFE1-.Ltext0
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST2:
	.long	.LFB2-.Ltext0
	.long	.LCFI4-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI4-.Ltext0
	.long	.LCFI5-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI5-.Ltext0
	.long	.LFE2-.Ltext0
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST3:
	.long	.LFB3-.Ltext0
	.long	.LCFI6-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI6-.Ltext0
	.long	.LCFI7-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI7-.Ltext0
	.long	.LFE3-.Ltext0
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST4:
	.long	.LFB4-.Ltext0
	.long	.LCFI8-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI8-.Ltext0
	.long	.LCFI9-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI9-.Ltext0
	.long	.LFE4-.Ltext0
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST5:
	.long	.LFB5-.Ltext0
	.long	.LCFI10-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI10-.Ltext0
	.long	.LCFI11-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI11-.Ltext0
	.long	.LFE5-.Ltext0
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST6:
	.long	.LFB6-.Ltext0
	.long	.LCFI12-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI12-.Ltext0
	.long	.LCFI13-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI13-.Ltext0
	.long	.LFE6-.Ltext0
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST7:
	.long	.LFB7-.Ltext0
	.long	.LCFI14-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI14-.Ltext0
	.long	.LCFI15-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI15-.Ltext0
	.long	.LFE7-.Ltext0
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST8:
	.long	.LFB8-.Ltext0
	.long	.LCFI16-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI16-.Ltext0
	.long	.LCFI17-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI17-.Ltext0
	.long	.LFE8-.Ltext0
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST9:
	.long	.LFB9-.Ltext0
	.long	.LCFI18-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI18-.Ltext0
	.long	.LCFI19-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI19-.Ltext0
	.long	.LFE9-.Ltext0
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST10:
	.long	.LFB10-.Ltext0
	.long	.LCFI20-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI20-.Ltext0
	.long	.LCFI21-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI21-.Ltext0
	.long	.LFE10-.Ltext0
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST11:
	.long	.LFB11-.Ltext0
	.long	.LCFI22-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI22-.Ltext0
	.long	.LCFI23-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI23-.Ltext0
	.long	.LFE11-.Ltext0
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST12:
	.long	.LFB12-.Ltext0
	.long	.LCFI24-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI24-.Ltext0
	.long	.LCFI25-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI25-.Ltext0
	.long	.LFE12-.Ltext0
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST13:
	.long	.LFB13-.Ltext0
	.long	.LCFI26-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI26-.Ltext0
	.long	.LCFI27-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI27-.Ltext0
	.long	.LFE13-.Ltext0
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST14:
	.long	.LFB14-.Ltext0
	.long	.LCFI28-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI28-.Ltext0
	.long	.LCFI29-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI29-.Ltext0
	.long	.LFE14-.Ltext0
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST15:
	.long	.LFB15-.Ltext0
	.long	.LCFI30-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI30-.Ltext0
	.long	.LCFI31-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI31-.Ltext0
	.long	.LFE15-.Ltext0
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST16:
	.long	.LFB16-.Ltext0
	.long	.LCFI32-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI32-.Ltext0
	.long	.LCFI33-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI33-.Ltext0
	.long	.LFE16-.Ltext0
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST17:
	.long	.LFB17-.Ltext0
	.long	.LCFI34-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI34-.Ltext0
	.long	.LCFI35-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI35-.Ltext0
	.long	.LFE17-.Ltext0
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST18:
	.long	.LFB18-.Ltext0
	.long	.LCFI36-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI36-.Ltext0
	.long	.LCFI37-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI37-.Ltext0
	.long	.LFE18-.Ltext0
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST19:
	.long	.LFB19-.Ltext0
	.long	.LCFI38-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI38-.Ltext0
	.long	.LCFI39-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI39-.Ltext0
	.long	.LFE19-.Ltext0
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST20:
	.long	.LFB20-.Ltext0
	.long	.LCFI40-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI40-.Ltext0
	.long	.LCFI41-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI41-.Ltext0
	.long	.LFE20-.Ltext0
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST21:
	.long	.LFB21-.Ltext0
	.long	.LCFI42-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI42-.Ltext0
	.long	.LCFI43-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI43-.Ltext0
	.long	.LFE21-.Ltext0
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST22:
	.long	.LFB22-.Ltext0
	.long	.LCFI44-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI44-.Ltext0
	.long	.LCFI45-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI45-.Ltext0
	.long	.LFE22-.Ltext0
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST23:
	.long	.LFB23-.Ltext0
	.long	.LCFI46-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI46-.Ltext0
	.long	.LCFI47-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI47-.Ltext0
	.long	.LFE23-.Ltext0
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST24:
	.long	.LFB24-.Ltext0
	.long	.LCFI48-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI48-.Ltext0
	.long	.LCFI49-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI49-.Ltext0
	.long	.LFE24-.Ltext0
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST25:
	.long	.LFB25-.Ltext0
	.long	.LCFI50-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI50-.Ltext0
	.long	.LCFI51-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI51-.Ltext0
	.long	.LFE25-.Ltext0
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST26:
	.long	.LFB26-.Ltext0
	.long	.LCFI52-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI52-.Ltext0
	.long	.LCFI53-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI53-.Ltext0
	.long	.LFE26-.Ltext0
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST27:
	.long	.LFB27-.Ltext0
	.long	.LCFI54-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI54-.Ltext0
	.long	.LCFI55-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI55-.Ltext0
	.long	.LFE27-.Ltext0
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST28:
	.long	.LFB28-.Ltext0
	.long	.LCFI56-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI56-.Ltext0
	.long	.LCFI57-.Ltext0
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI57-.Ltext0
	.long	.LFE28-.Ltext0
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
	.file 3 "fric.c"
	.section	.debug_info
	.long	0xd8b
	.value	0x2
	.long	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.long	.LASF73
	.byte	0x1
	.long	.LASF74
	.long	.LASF75
	.long	.Ltext0
	.long	.Letext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.long	.LASF0
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x2
	.byte	0x4
	.byte	0x5
	.long	.LASF1
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF2
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.long	.LASF3
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.long	.LASF4
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.long	.LASF5
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF6
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.long	.LASF7
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF8
	.uleb128 0x4
	.byte	0x4
	.byte	0x7
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF9
	.uleb128 0x2
	.byte	0xc
	.byte	0x4
	.long	.LASF10
	.uleb128 0x2
	.byte	0x8
	.byte	0x4
	.long	.LASF11
	.uleb128 0x5
	.long	.LASF12
	.byte	0x1
	.byte	0x3a
	.byte	0x1
	.long	0x7c
	.long	.LFB0
	.long	.LFE0
	.long	.LLST0
	.long	0xac
	.uleb128 0x6
	.string	"i"
	.byte	0x1
	.byte	0x3a
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.byte	0x0
	.uleb128 0x5
	.long	.LASF13
	.byte	0x1
	.byte	0x3e
	.byte	0x1
	.long	0x7c
	.long	.LFB1
	.long	.LFE1
	.long	.LLST1
	.long	0xe6
	.uleb128 0x6
	.string	"i"
	.byte	0x1
	.byte	0x3e
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x7
	.string	"alv"
	.byte	0x1
	.byte	0x3f
	.long	0xe6
	.byte	0x5
	.byte	0x3
	.long	alv.3324
	.byte	0x0
	.uleb128 0x8
	.long	0x7c
	.long	0xf6
	.uleb128 0x9
	.long	0x6b
	.byte	0x4
	.byte	0x0
	.uleb128 0x5
	.long	.LASF14
	.byte	0x1
	.byte	0x43
	.byte	0x1
	.long	0x7c
	.long	.LFB2
	.long	.LFE2
	.long	.LLST2
	.long	0x12f
	.uleb128 0x6
	.string	"i"
	.byte	0x1
	.byte	0x43
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x7
	.string	"dv"
	.byte	0x1
	.byte	0x44
	.long	0xe6
	.byte	0x5
	.byte	0x3
	.long	dv.3330
	.byte	0x0
	.uleb128 0x5
	.long	.LASF15
	.byte	0x1
	.byte	0x49
	.byte	0x1
	.long	0x7c
	.long	.LFB3
	.long	.LFE3
	.long	.LLST3
	.long	0x168
	.uleb128 0x6
	.string	"i"
	.byte	0x1
	.byte	0x49
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x7
	.string	"dv"
	.byte	0x1
	.byte	0x4a
	.long	0xe6
	.byte	0x5
	.byte	0x3
	.long	dv.3338
	.byte	0x0
	.uleb128 0x5
	.long	.LASF16
	.byte	0x1
	.byte	0x4f
	.byte	0x1
	.long	0x7c
	.long	.LFB4
	.long	.LFE4
	.long	.LLST4
	.long	0x1a1
	.uleb128 0x6
	.string	"i"
	.byte	0x1
	.byte	0x4f
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x7
	.string	"dv"
	.byte	0x1
	.byte	0x50
	.long	0xe6
	.byte	0x5
	.byte	0x3
	.long	dv.3346
	.byte	0x0
	.uleb128 0x5
	.long	.LASF17
	.byte	0x1
	.byte	0x56
	.byte	0x1
	.long	0x7c
	.long	.LFB5
	.long	.LFE5
	.long	.LLST5
	.long	0x1ca
	.uleb128 0x6
	.string	"i"
	.byte	0x1
	.byte	0x56
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.byte	0x0
	.uleb128 0x5
	.long	.LASF18
	.byte	0x1
	.byte	0x5e
	.byte	0x1
	.long	0x7c
	.long	.LFB6
	.long	.LFE6
	.long	.LLST6
	.long	0x1f3
	.uleb128 0x6
	.string	"i"
	.byte	0x1
	.byte	0x5e
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.byte	0x0
	.uleb128 0x5
	.long	.LASF19
	.byte	0x1
	.byte	0x63
	.byte	0x1
	.long	0x7c
	.long	.LFB7
	.long	.LFE7
	.long	.LLST7
	.long	0x21c
	.uleb128 0x6
	.string	"i"
	.byte	0x1
	.byte	0x63
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.byte	0x0
	.uleb128 0xa
	.string	"P"
	.byte	0x1
	.byte	0x6a
	.byte	0x1
	.long	0x262
	.long	.LFB8
	.long	.LFE8
	.long	.LLST8
	.long	0x262
	.uleb128 0x6
	.string	"i"
	.byte	0x1
	.byte	0x6a
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0xb
	.long	.LASF20
	.byte	0x1
	.byte	0x6a
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0xc
	.long	.LASF21
	.byte	0x1
	.byte	0x6b
	.long	0x268
	.byte	0x5
	.byte	0x3
	.long	last_timestep.3383
	.byte	0x0
	.uleb128 0xd
	.byte	0x4
	.long	0x7c
	.uleb128 0x8
	.long	0x2c
	.long	0x278
	.uleb128 0x9
	.long	0x6b
	.byte	0x5
	.byte	0x0
	.uleb128 0xa
	.string	"R"
	.byte	0x1
	.byte	0x80
	.byte	0x1
	.long	0x2c
	.long	.LFB9
	.long	.LFE9
	.long	.LLST9
	.long	0x2be
	.uleb128 0x6
	.string	"i"
	.byte	0x1
	.byte	0x80
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0xb
	.long	.LASF20
	.byte	0x1
	.byte	0x80
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0xc
	.long	.LASF21
	.byte	0x1
	.byte	0x81
	.long	0x268
	.byte	0x5
	.byte	0x3
	.long	last_timestep.3425
	.byte	0x0
	.uleb128 0x5
	.long	.LASF22
	.byte	0x1
	.byte	0xa1
	.byte	0x1
	.long	0x262
	.long	.LFB10
	.long	.LFE10
	.long	.LLST10
	.long	0x344
	.uleb128 0x6
	.string	"i"
	.byte	0x1
	.byte	0xa1
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0xb
	.long	.LASF20
	.byte	0x1
	.byte	0xa1
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x7
	.string	"o"
	.byte	0x1
	.byte	0xa2
	.long	0x262
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x7
	.string	"p"
	.byte	0x1
	.byte	0xa3
	.long	0x262
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x7
	.string	"l"
	.byte	0x1
	.byte	0xa4
	.long	0x262
	.byte	0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0xc
	.long	.LASF23
	.byte	0x1
	.byte	0xa5
	.long	0x344
	.byte	0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0x7
	.string	"r"
	.byte	0x1
	.byte	0xa6
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0xc
	.long	.LASF21
	.byte	0x1
	.byte	0xa7
	.long	0x268
	.byte	0x5
	.byte	0x3
	.long	last_timestep.3498
	.byte	0x0
	.uleb128 0x8
	.long	0x7c
	.long	0x354
	.uleb128 0x9
	.long	0x6b
	.byte	0x2
	.byte	0x0
	.uleb128 0x5
	.long	.LASF24
	.byte	0x1
	.byte	0xc4
	.byte	0x1
	.long	0x262
	.long	.LFB11
	.long	.LFE11
	.long	.LLST11
	.long	0x3b6
	.uleb128 0x6
	.string	"i"
	.byte	0x1
	.byte	0xc4
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0xb
	.long	.LASF20
	.byte	0x1
	.byte	0xc4
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x7
	.string	"ino"
	.byte	0x1
	.byte	0xc5
	.long	0x262
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x7
	.string	"r"
	.byte	0x1
	.byte	0xc6
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0xc
	.long	.LASF21
	.byte	0x1
	.byte	0xc7
	.long	0x268
	.byte	0x5
	.byte	0x3
	.long	last_timestep.3629
	.byte	0x0
	.uleb128 0x5
	.long	.LASF25
	.byte	0x1
	.byte	0xdb
	.byte	0x1
	.long	0x262
	.long	.LFB12
	.long	.LFE12
	.long	.LLST12
	.long	0x443
	.uleb128 0x6
	.string	"i"
	.byte	0x1
	.byte	0xdb
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0xb
	.long	.LASF20
	.byte	0x1
	.byte	0xdb
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0xc
	.long	.LASF26
	.byte	0x1
	.byte	0xdc
	.long	0x262
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x7
	.string	"ino"
	.byte	0x1
	.byte	0xdd
	.long	0x262
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x7
	.string	"r"
	.byte	0x1
	.byte	0xde
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0xc
	.long	.LASF23
	.byte	0x1
	.byte	0xdf
	.long	0x344
	.byte	0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0x7
	.string	"tem"
	.byte	0x1
	.byte	0xe0
	.long	0x344
	.byte	0x3
	.byte	0x91
	.sleb128 -80
	.uleb128 0xc
	.long	.LASF21
	.byte	0x1
	.byte	0xe1
	.long	0x268
	.byte	0x5
	.byte	0x3
	.long	last_timestep.3714
	.byte	0x0
	.uleb128 0x5
	.long	.LASF27
	.byte	0x1
	.byte	0xfb
	.byte	0x1
	.long	0x262
	.long	.LFB13
	.long	.LFE13
	.long	.LLST13
	.long	0x50b
	.uleb128 0x6
	.string	"i"
	.byte	0x1
	.byte	0xfb
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0xb
	.long	.LASF20
	.byte	0x1
	.byte	0xfb
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0xc
	.long	.LASF28
	.byte	0x1
	.byte	0xfc
	.long	0x262
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0xc
	.long	.LASF26
	.byte	0x1
	.byte	0xfd
	.long	0x262
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x7
	.string	"ino"
	.byte	0x1
	.byte	0xfe
	.long	0x262
	.byte	0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0x7
	.string	"o"
	.byte	0x1
	.byte	0xff
	.long	0x262
	.byte	0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0xe
	.string	"r"
	.byte	0x1
	.value	0x100
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0xe
	.string	"p"
	.byte	0x1
	.value	0x101
	.long	0x262
	.byte	0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0xf
	.long	.LASF23
	.byte	0x1
	.value	0x102
	.long	0x344
	.byte	0x2
	.byte	0x91
	.sleb128 -64
	.uleb128 0xe
	.string	"tem"
	.byte	0x1
	.value	0x103
	.long	0x344
	.byte	0x3
	.byte	0x91
	.sleb128 -88
	.uleb128 0xf
	.long	.LASF29
	.byte	0x1
	.value	0x104
	.long	0x344
	.byte	0x3
	.byte	0x91
	.sleb128 -112
	.uleb128 0xf
	.long	.LASF21
	.byte	0x1
	.value	0x105
	.long	0x268
	.byte	0x5
	.byte	0x3
	.long	last_timestep.3864
	.byte	0x0
	.uleb128 0x10
	.long	.LASF30
	.byte	0x1
	.value	0x12b
	.byte	0x1
	.long	0x262
	.long	.LFB14
	.long	.LFE14
	.long	.LLST14
	.long	0x5ac
	.uleb128 0x11
	.string	"i"
	.byte	0x1
	.value	0x12b
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x12
	.long	.LASF20
	.byte	0x1
	.value	0x12b
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0xe
	.string	"j"
	.byte	0x1
	.value	0x12c
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0xe
	.string	"od"
	.byte	0x1
	.value	0x12d
	.long	0x262
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0xe
	.string	"o"
	.byte	0x1
	.value	0x12e
	.long	0x262
	.byte	0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0xe
	.string	"vd"
	.byte	0x1
	.value	0x12f
	.long	0x262
	.byte	0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0xf
	.long	.LASF23
	.byte	0x1
	.value	0x130
	.long	0x344
	.byte	0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0xe
	.string	"tem"
	.byte	0x1
	.value	0x131
	.long	0x344
	.byte	0x3
	.byte	0x91
	.sleb128 -80
	.uleb128 0xf
	.long	.LASF21
	.byte	0x1
	.value	0x132
	.long	0x5ac
	.byte	0x5
	.byte	0x3
	.long	last_timestep.4061
	.byte	0x0
	.uleb128 0x8
	.long	0x2c
	.long	0x5bc
	.uleb128 0x9
	.long	0x6b
	.byte	0x4
	.byte	0x0
	.uleb128 0x10
	.long	.LASF31
	.byte	0x1
	.value	0x148
	.byte	0x1
	.long	0x262
	.long	.LFB15
	.long	.LFE15
	.long	.LLST15
	.long	0x64f
	.uleb128 0x11
	.string	"i"
	.byte	0x1
	.value	0x148
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x12
	.long	.LASF20
	.byte	0x1
	.value	0x148
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0xe
	.string	"o"
	.byte	0x1
	.value	0x149
	.long	0x262
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0xe
	.string	"od"
	.byte	0x1
	.value	0x14a
	.long	0x262
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0xf
	.long	.LASF23
	.byte	0x1
	.value	0x14b
	.long	0x344
	.byte	0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0xe
	.string	"tem"
	.byte	0x1
	.value	0x14c
	.long	0x344
	.byte	0x3
	.byte	0x91
	.sleb128 -80
	.uleb128 0xe
	.string	"j"
	.byte	0x1
	.value	0x14d
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0xf
	.long	.LASF21
	.byte	0x1
	.value	0x14e
	.long	0x5ac
	.byte	0x5
	.byte	0x3
	.long	last_timestep.4206
	.byte	0x0
	.uleb128 0x10
	.long	.LASF32
	.byte	0x1
	.value	0x163
	.byte	0x1
	.long	0x262
	.long	.LFB16
	.long	.LFE16
	.long	.LLST16
	.long	0x6c6
	.uleb128 0x11
	.string	"i"
	.byte	0x1
	.value	0x163
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x12
	.long	.LASF20
	.byte	0x1
	.value	0x163
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0xf
	.long	.LASF33
	.byte	0x1
	.value	0x164
	.long	0x262
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0xf
	.long	.LASF34
	.byte	0x1
	.value	0x165
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0xe
	.string	"f"
	.byte	0x1
	.value	0x166
	.long	0x262
	.byte	0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0xf
	.long	.LASF21
	.byte	0x1
	.value	0x167
	.long	0x268
	.byte	0x5
	.byte	0x3
	.long	last_timestep.4310
	.byte	0x0
	.uleb128 0x10
	.long	.LASF35
	.byte	0x1
	.value	0x17c
	.byte	0x1
	.long	0x262
	.long	.LFB17
	.long	.LFE17
	.long	.LLST17
	.long	0x795
	.uleb128 0x11
	.string	"i"
	.byte	0x1
	.value	0x17c
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x12
	.long	.LASF20
	.byte	0x1
	.value	0x17c
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0xf
	.long	.LASF36
	.byte	0x1
	.value	0x17d
	.long	0x262
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0xf
	.long	.LASF33
	.byte	0x1
	.value	0x17e
	.long	0x262
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0xf
	.long	.LASF34
	.byte	0x1
	.value	0x17f
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0xe
	.string	"t"
	.byte	0x1
	.value	0x180
	.long	0x262
	.byte	0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0xe
	.string	"f"
	.byte	0x1
	.value	0x181
	.long	0x262
	.byte	0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0xe
	.string	"p"
	.byte	0x1
	.value	0x182
	.long	0x262
	.byte	0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0xf
	.long	.LASF23
	.byte	0x1
	.value	0x183
	.long	0x344
	.byte	0x2
	.byte	0x91
	.sleb128 -64
	.uleb128 0xf
	.long	.LASF29
	.byte	0x1
	.value	0x184
	.long	0x344
	.byte	0x3
	.byte	0x91
	.sleb128 -88
	.uleb128 0xe
	.string	"tem"
	.byte	0x1
	.value	0x185
	.long	0x344
	.byte	0x3
	.byte	0x91
	.sleb128 -112
	.uleb128 0xf
	.long	.LASF21
	.byte	0x1
	.value	0x186
	.long	0x268
	.byte	0x5
	.byte	0x3
	.long	last_timestep.4407
	.byte	0x0
	.uleb128 0x13
	.byte	0x1
	.long	.LASF37
	.byte	0x1
	.value	0x1a6
	.byte	0x1
	.long	.LFB18
	.long	.LFE18
	.long	.LLST18
	.long	0x7f1
	.uleb128 0x11
	.string	"a"
	.byte	0x1
	.value	0x1a6
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0x11
	.string	"b"
	.byte	0x1
	.value	0x1a6
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x11
	.string	"c"
	.byte	0x1
	.value	0x1a6
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x11
	.string	"d"
	.byte	0x1
	.value	0x1a6
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x11
	.string	"e"
	.byte	0x1
	.value	0x1a6
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -48
	.byte	0x0
	.uleb128 0x13
	.byte	0x1
	.long	.LASF38
	.byte	0x1
	.value	0x1ae
	.byte	0x1
	.long	.LFB19
	.long	.LFE19
	.long	.LLST19
	.long	0x84d
	.uleb128 0x11
	.string	"a"
	.byte	0x1
	.value	0x1ae
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0x11
	.string	"b"
	.byte	0x1
	.value	0x1ae
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x11
	.string	"c"
	.byte	0x1
	.value	0x1ae
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x11
	.string	"d"
	.byte	0x1
	.value	0x1ae
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x11
	.string	"e"
	.byte	0x1
	.value	0x1ae
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -48
	.byte	0x0
	.uleb128 0x13
	.byte	0x1
	.long	.LASF39
	.byte	0x1
	.value	0x1b6
	.byte	0x1
	.long	.LFB20
	.long	.LFE20
	.long	.LLST20
	.long	0x8a9
	.uleb128 0x11
	.string	"a"
	.byte	0x1
	.value	0x1b6
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0x11
	.string	"b"
	.byte	0x1
	.value	0x1b6
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x11
	.string	"c"
	.byte	0x1
	.value	0x1b6
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x11
	.string	"d"
	.byte	0x1
	.value	0x1b6
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x11
	.string	"e"
	.byte	0x1
	.value	0x1b6
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -48
	.byte	0x0
	.uleb128 0x13
	.byte	0x1
	.long	.LASF40
	.byte	0x1
	.value	0x1be
	.byte	0x1
	.long	.LFB21
	.long	.LFE21
	.long	.LLST21
	.long	0x8e0
	.uleb128 0x11
	.string	"l"
	.byte	0x1
	.value	0x1be
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0x11
	.string	"idx"
	.byte	0x1
	.value	0x1be
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 8
	.byte	0x0
	.uleb128 0x13
	.byte	0x1
	.long	.LASF41
	.byte	0x1
	.value	0x1cb
	.byte	0x1
	.long	.LFB22
	.long	.LFE22
	.long	.LLST22
	.long	0x917
	.uleb128 0x11
	.string	"m"
	.byte	0x1
	.value	0x1cb
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0x11
	.string	"idx"
	.byte	0x1
	.value	0x1cb
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 8
	.byte	0x0
	.uleb128 0x13
	.byte	0x1
	.long	.LASF42
	.byte	0x1
	.value	0x1d5
	.byte	0x1
	.long	.LFB23
	.long	.LFE23
	.long	.LLST23
	.long	0x96b
	.uleb128 0x11
	.string	"p0"
	.byte	0x1
	.value	0x1d5
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0x11
	.string	"p1"
	.byte	0x1
	.value	0x1d5
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x11
	.string	"p2"
	.byte	0x1
	.value	0x1d5
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x11
	.string	"idx"
	.byte	0x1
	.value	0x1d5
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 24
	.byte	0x0
	.uleb128 0x13
	.byte	0x1
	.long	.LASF43
	.byte	0x1
	.value	0x1db
	.byte	0x1
	.long	.LFB24
	.long	.LFE24
	.long	.LLST24
	.long	0xa1f
	.uleb128 0x11
	.string	"i00"
	.byte	0x1
	.value	0x1db
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0x11
	.string	"i01"
	.byte	0x1
	.value	0x1db
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x11
	.string	"i02"
	.byte	0x1
	.value	0x1db
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x11
	.string	"i10"
	.byte	0x1
	.value	0x1dc
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x11
	.string	"i11"
	.byte	0x1
	.value	0x1dc
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x11
	.string	"i12"
	.byte	0x1
	.value	0x1dc
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0x11
	.string	"i20"
	.byte	0x1
	.value	0x1dd
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -64
	.uleb128 0x11
	.string	"i21"
	.byte	0x1
	.value	0x1dd
	.long	0x7c
	.byte	0x3
	.byte	0x91
	.sleb128 -72
	.uleb128 0x11
	.string	"i22"
	.byte	0x1
	.value	0x1dd
	.long	0x7c
	.byte	0x3
	.byte	0x91
	.sleb128 -80
	.uleb128 0x11
	.string	"idx"
	.byte	0x1
	.value	0x1de
	.long	0x2c
	.byte	0x3
	.byte	0x91
	.sleb128 72
	.byte	0x0
	.uleb128 0x14
	.byte	0x1
	.long	.LASF61
	.byte	0x1
	.value	0x1eb
	.byte	0x1
	.long	0x7c
	.long	.LFB25
	.long	.LFE25
	.long	.LLST25
	.long	0xa5a
	.uleb128 0x11
	.string	"i"
	.byte	0x1
	.value	0x1eb
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x12
	.long	.LASF20
	.byte	0x1
	.value	0x1eb
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.byte	0x0
	.uleb128 0x15
	.byte	0x1
	.long	.LASF44
	.byte	0x2
	.byte	0x5
	.byte	0x1
	.long	.LFB26
	.long	.LFE26
	.long	.LLST26
	.long	0xb5e
	.uleb128 0xc
	.long	.LASF45
	.byte	0x2
	.byte	0x6
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0xc
	.long	.LASF46
	.byte	0x2
	.byte	0x7
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0xc
	.long	.LASF47
	.byte	0x2
	.byte	0x8
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0xc
	.long	.LASF48
	.byte	0x2
	.byte	0x9
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0xc
	.long	.LASF49
	.byte	0x2
	.byte	0xa
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0xc
	.long	.LASF50
	.byte	0x2
	.byte	0xb
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -64
	.uleb128 0xc
	.long	.LASF51
	.byte	0x2
	.byte	0xc
	.long	0x7c
	.byte	0x3
	.byte	0x91
	.sleb128 -72
	.uleb128 0xc
	.long	.LASF52
	.byte	0x2
	.byte	0xd
	.long	0x7c
	.byte	0x3
	.byte	0x91
	.sleb128 -80
	.uleb128 0xc
	.long	.LASF53
	.byte	0x2
	.byte	0xe
	.long	0x7c
	.byte	0x3
	.byte	0x91
	.sleb128 -88
	.uleb128 0xc
	.long	.LASF54
	.byte	0x2
	.byte	0xf
	.long	0x7c
	.byte	0x3
	.byte	0x91
	.sleb128 -96
	.uleb128 0xc
	.long	.LASF55
	.byte	0x2
	.byte	0x10
	.long	0x7c
	.byte	0x3
	.byte	0x91
	.sleb128 -104
	.uleb128 0xc
	.long	.LASF56
	.byte	0x2
	.byte	0x11
	.long	0x7c
	.byte	0x3
	.byte	0x91
	.sleb128 -112
	.uleb128 0xc
	.long	.LASF57
	.byte	0x2
	.byte	0x12
	.long	0x7c
	.byte	0x3
	.byte	0x91
	.sleb128 -120
	.uleb128 0xc
	.long	.LASF58
	.byte	0x2
	.byte	0x13
	.long	0x7c
	.byte	0x3
	.byte	0x91
	.sleb128 -128
	.uleb128 0xc
	.long	.LASF59
	.byte	0x2
	.byte	0x14
	.long	0x7c
	.byte	0x3
	.byte	0x91
	.sleb128 -136
	.uleb128 0xc
	.long	.LASF60
	.byte	0x2
	.byte	0x15
	.long	0x7c
	.byte	0x3
	.byte	0x91
	.sleb128 -144
	.byte	0x0
	.uleb128 0x16
	.byte	0x1
	.string	"sgn"
	.byte	0x2
	.byte	0x1f
	.byte	0x1
	.long	0x7c
	.long	.LFB27
	.long	.LFE27
	.long	.LLST27
	.long	0xb88
	.uleb128 0x6
	.string	"a"
	.byte	0x2
	.byte	0x1f
	.long	0x7c
	.byte	0x2
	.byte	0x91
	.sleb128 -16
	.byte	0x0
	.uleb128 0x16
	.byte	0x1
	.string	"tau"
	.byte	0x2
	.byte	0x28
	.byte	0x1
	.long	0x7c
	.long	.LFB28
	.long	.LFE28
	.long	.LLST28
	.long	0xbb2
	.uleb128 0x6
	.string	"n"
	.byte	0x2
	.byte	0x28
	.long	0x2c
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.byte	0x0
	.uleb128 0x7
	.string	"q"
	.byte	0x1
	.byte	0x26
	.long	0xe6
	.byte	0x5
	.byte	0x3
	.long	q
	.uleb128 0x7
	.string	"dq"
	.byte	0x1
	.byte	0x28
	.long	0xe6
	.byte	0x5
	.byte	0x3
	.long	dq
	.uleb128 0x7
	.string	"ddq"
	.byte	0x1
	.byte	0x2a
	.long	0xe6
	.byte	0x5
	.byte	0x3
	.long	ddq
	.uleb128 0x8
	.long	0x7c
	.long	0xbf2
	.uleb128 0x9
	.long	0x6b
	.byte	0x5
	.byte	0x0
	.uleb128 0x7
	.string	"L"
	.byte	0x1
	.byte	0x2c
	.long	0xbe2
	.byte	0x5
	.byte	0x3
	.long	L
	.uleb128 0x8
	.long	0x7c
	.long	0xc17
	.uleb128 0x9
	.long	0x6b
	.byte	0x4
	.uleb128 0x9
	.long	0x6b
	.byte	0x2
	.byte	0x0
	.uleb128 0xc
	.long	.LASF62
	.byte	0x1
	.byte	0x2e
	.long	0xc01
	.byte	0x5
	.byte	0x3
	.long	pdis
	.uleb128 0xc
	.long	.LASF63
	.byte	0x1
	.byte	0x30
	.long	0xe6
	.byte	0x5
	.byte	0x3
	.long	Mass
	.uleb128 0x8
	.long	0x7c
	.long	0xc55
	.uleb128 0x9
	.long	0x6b
	.byte	0x4
	.uleb128 0x9
	.long	0x6b
	.byte	0x2
	.uleb128 0x9
	.long	0x6b
	.byte	0x2
	.byte	0x0
	.uleb128 0x7
	.string	"I"
	.byte	0x1
	.byte	0x32
	.long	0xc39
	.byte	0x5
	.byte	0x3
	.long	I
	.uleb128 0x8
	.long	0x7c
	.long	0xc7a
	.uleb128 0x9
	.long	0x6b
	.byte	0x5
	.uleb128 0x9
	.long	0x6b
	.byte	0x2
	.byte	0x0
	.uleb128 0xc
	.long	.LASF64
	.byte	0x1
	.byte	0x68
	.long	0xc64
	.byte	0x5
	.byte	0x3
	.long	ptrans
	.uleb128 0x8
	.long	0x7c
	.long	0xca7
	.uleb128 0x9
	.long	0x6b
	.byte	0x5
	.uleb128 0x9
	.long	0x6b
	.byte	0x2
	.uleb128 0x9
	.long	0x6b
	.byte	0x2
	.byte	0x0
	.uleb128 0xc
	.long	.LASF65
	.byte	0x1
	.byte	0x7e
	.long	0xc8b
	.byte	0x5
	.byte	0x3
	.long	rtrans
	.uleb128 0xc
	.long	.LASF66
	.byte	0x1
	.byte	0x9f
	.long	0xc64
	.byte	0x5
	.byte	0x3
	.long	vvec
	.uleb128 0x7
	.string	"om"
	.byte	0x1
	.byte	0xc2
	.long	0xc64
	.byte	0x5
	.byte	0x3
	.long	om
	.uleb128 0x7
	.string	"omd"
	.byte	0x1
	.byte	0xd9
	.long	0xc64
	.byte	0x5
	.byte	0x3
	.long	omd
	.uleb128 0x7
	.string	"ved"
	.byte	0x1
	.byte	0xfa
	.long	0xc64
	.byte	0x5
	.byte	0x3
	.long	ved
	.uleb128 0xf
	.long	.LASF67
	.byte	0x1
	.value	0x12a
	.long	0xc01
	.byte	0x5
	.byte	0x3
	.long	vedc
	.uleb128 0xe
	.string	"cn"
	.byte	0x1
	.value	0x147
	.long	0xc01
	.byte	0x5
	.byte	0x3
	.long	cn
	.uleb128 0xf
	.long	.LASF68
	.byte	0x1
	.value	0x162
	.long	0xc64
	.byte	0x5
	.byte	0x3
	.long	inwaf
	.uleb128 0xf
	.long	.LASF69
	.byte	0x1
	.value	0x17b
	.long	0xc64
	.byte	0x5
	.byte	0x3
	.long	inwat
	.uleb128 0xf
	.long	.LASF70
	.byte	0x1
	.value	0x1c9
	.long	0x7c
	.byte	0x5
	.byte	0x3
	.long	Mfive
	.uleb128 0x17
	.long	.LASF71
	.byte	0x2
	.byte	0x4
	.long	0xe6
	.byte	0x1
	.byte	0x5
	.byte	0x3
	.long	taus
	.uleb128 0x8
	.long	0x7c
	.long	0xd7c
	.uleb128 0x9
	.long	0x6b
	.byte	0x4
	.uleb128 0x9
	.long	0x6b
	.byte	0x4
	.byte	0x0
	.uleb128 0x17
	.long	.LASF72
	.byte	0x3
	.byte	0x1
	.long	0xd66
	.byte	0x1
	.byte	0x5
	.byte	0x3
	.long	fric
	.byte	0x0
	.section	.debug_abbrev
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x10
	.uleb128 0x6
	.byte	0x0
	.byte	0x0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0x0
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0x0
	.byte	0x0
	.uleb128 0x4
	.uleb128 0x24
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.byte	0x0
	.byte	0x0
	.uleb128 0x5
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0x6
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x6
	.uleb128 0x5
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x7
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x8
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x9
	.uleb128 0x21
	.byte	0x0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0x0
	.byte	0x0
	.uleb128 0xa
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0x6
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0xb
	.uleb128 0x5
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0xc
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0xd
	.uleb128 0xf
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0xe
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0xf
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x10
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0x6
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x11
	.uleb128 0x5
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x12
	.uleb128 0x5
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x13
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0x6
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x14
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0x6
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x15
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0x6
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x16
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0xc
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0x6
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x17
	.uleb128 0x34
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x2
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.section	.debug_pubnames,"",@progbits
	.long	0xb4
	.value	0x2
	.long	.Ldebug_info0
	.long	0xd8f
	.long	0x795
	.string	"setq"
	.long	0x7f1
	.string	"setdq"
	.long	0x84d
	.string	"setddq"
	.long	0x8a9
	.string	"setLinkLength"
	.long	0x8e0
	.string	"setMass"
	.long	0x917
	.string	"setMassDisplacement"
	.long	0x96b
	.string	"setInertiaTensor"
	.long	0xa1f
	.string	"oldtau"
	.long	0xa5a
	.string	"computetaus"
	.long	0xb5e
	.string	"sgn"
	.long	0xb88
	.string	"tau"
	.long	0xd54
	.string	"taus"
	.long	0xd7c
	.string	"fric"
	.long	0x0
	.section	.debug_aranges,"",@progbits
	.long	0x1c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x4
	.byte	0x0
	.value	0x0
	.value	0x0
	.long	.Ltext0
	.long	.Letext0-.Ltext0
	.long	0x0
	.long	0x0
	.section	.debug_str,"MS",@progbits,1
.LASF39:
	.string	"setddq"
.LASF16:
	.string	"dddvek"
.LASF60:
	.string	"sin23"
.LASF8:
	.string	"long long unsigned int"
.LASF71:
	.string	"taus"
.LASF61:
	.string	"oldtau"
.LASF73:
	.string	"GNU C 4.4.1"
.LASF43:
	.string	"setInertiaTensor"
.LASF58:
	.string	"sin12"
.LASF2:
	.string	"long long int"
.LASF6:
	.string	"signed char"
.LASF17:
	.string	"tvek"
.LASF44:
	.string	"computetaus"
.LASF1:
	.string	"long int"
.LASF57:
	.string	"cos12"
.LASF11:
	.string	"double"
.LASF31:
	.string	"computeN"
.LASF22:
	.string	"computeV"
.LASF24:
	.string	"computeOmega"
.LASF29:
	.string	"temo"
.LASF23:
	.string	"temp"
.LASF38:
	.string	"setdq"
.LASF0:
	.string	"unsigned int"
.LASF59:
	.string	"cos23"
.LASF37:
	.string	"setq"
.LASF5:
	.string	"long unsigned int"
.LASF70:
	.string	"Mfive"
.LASF41:
	.string	"setMass"
.LASF4:
	.string	"short unsigned int"
.LASF74:
	.string	"dynomads.c"
.LASF65:
	.string	"rtrans"
.LASF49:
	.string	"cosq3"
.LASF55:
	.string	"cos123"
.LASF15:
	.string	"ddvek"
.LASF32:
	.string	"inwardForce"
.LASF10:
	.string	"long double"
.LASF30:
	.string	"computeForce"
.LASF46:
	.string	"sinq1"
.LASF48:
	.string	"sinq2"
.LASF50:
	.string	"sinq3"
.LASF52:
	.string	"sinq4"
.LASF53:
	.string	"cos2q4"
.LASF75:
	.string	"/home/luz/Desktop/CP6000/code/libmpnrobot/libmpnrobot"
.LASF40:
	.string	"setLinkLength"
.LASF34:
	.string	"outr"
.LASF62:
	.string	"pdis"
.LASF45:
	.string	"cosq1"
.LASF47:
	.string	"cosq2"
.LASF14:
	.string	"dvek"
.LASF51:
	.string	"cosq4"
.LASF3:
	.string	"unsigned char"
.LASF72:
	.string	"fric"
.LASF7:
	.string	"short int"
.LASF56:
	.string	"sin123"
.LASF18:
	.string	"dtvek"
.LASF21:
	.string	"last_timestep"
.LASF28:
	.string	"invd"
.LASF9:
	.string	"char"
.LASF42:
	.string	"setMassDisplacement"
.LASF68:
	.string	"inwaf"
.LASF54:
	.string	"sin2q4"
.LASF69:
	.string	"inwat"
.LASF63:
	.string	"Mass"
.LASF26:
	.string	"inod"
.LASF33:
	.string	"outinwf"
.LASF13:
	.string	"alphavek"
.LASF64:
	.string	"ptrans"
.LASF36:
	.string	"outinwt"
.LASF67:
	.string	"vedc"
.LASF25:
	.string	"computeOmegaDot"
.LASF19:
	.string	"ddtvek"
.LASF66:
	.string	"vvec"
.LASF27:
	.string	"computeVDot"
.LASF35:
	.string	"inwardTorque"
.LASF12:
	.string	"avek"
.LASF20:
	.string	"timestep"
	.ident	"GCC: (Ubuntu 4.4.1-4ubuntu9) 4.4.1"
	.section	.note.GNU-stack,"",@progbits
