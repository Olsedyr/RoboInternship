	.file	"genscript.c"
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.text
.Ltext0:
.globl layerHeightMM
	.bss
	.align 4
	.type	layerHeightMM, @object
	.size	layerHeightMM, 4
layerHeightMM:
	.zero	4
.globl coeff
	.align 32
	.type	coeff, @object
	.size	coeff, 10900
coeff:
	.zero	10900
	.text
.globl convert
	.type	convert, @function
convert:
.LFB9:
	.file 1 "genscript.c"
	.loc 1 20 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI0:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI1:
	.cfi_def_cfa_register 5
	call	mcount
	.loc 1 20 0
	.loc 1 21 0
	movl	12(%ebp), %eax
	movl	44(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2592, %eax
	flds	(%eax)
	fadds	16(%ebp)
	movl	40(%ebp), %eax
	movl	44(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2592, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	movl	8(%ebp), %eax
	fstps	(%eax)
	.loc 1 22 0
	movl	12(%ebp), %eax
	movl	44(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2596, %eax
	flds	(%eax)
	fadds	20(%ebp)
	movl	40(%ebp), %eax
	movl	44(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2596, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	movl	8(%ebp), %eax
	fstps	4(%eax)
	.loc 1 23 0
	movl	12(%ebp), %eax
	movl	44(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2600, %eax
	flds	(%eax)
	fadds	24(%ebp)
	movl	40(%ebp), %eax
	movl	44(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2600, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	movl	8(%ebp), %eax
	fstps	8(%eax)
	.loc 1 24 0
	movl	12(%ebp), %eax
	movl	44(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2604, %eax
	flds	(%eax)
	fadds	28(%ebp)
	movl	40(%ebp), %eax
	movl	44(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2604, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	movl	8(%ebp), %eax
	fstps	12(%eax)
	.loc 1 25 0
	movl	12(%ebp), %eax
	movl	44(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2608, %eax
	flds	(%eax)
	fadds	32(%ebp)
	movl	40(%ebp), %eax
	movl	44(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2608, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	movl	8(%ebp), %eax
	fstps	16(%eax)
	.loc 1 26 0
	movl	12(%ebp), %eax
	movl	44(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2612, %eax
	flds	(%eax)
	fadds	36(%ebp)
	movl	40(%ebp), %eax
	movl	44(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2612, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	movl	8(%ebp), %eax
	fstps	20(%eax)
	.loc 1 27 0
	popl	%ebp
	ret
	.cfi_endproc
.LFE9:
	.size	convert, .-convert
	.section	.rodata
	.align 4
.LC4:
	.string	"POINT %s %3.2f,%3.2f,%3.2f,%3.2f,%3.2f,%3.2f,10.0 %s"
	.text
.globl split
	.type	split, @function
split:
.LFB10:
	.loc 1 33 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI2:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI3:
	.cfi_def_cfa_register 5
	subl	$408, %esp
	call	mcount
	movl	8(%ebp), %eax
	movl	%eax, -316(%ebp)
	movl	64(%ebp), %eax
	movl	%eax, -320(%ebp)
	movl	68(%ebp), %eax
	movl	%eax, -324(%ebp)
	movl	72(%ebp), %eax
	movl	%eax, -328(%ebp)
	.loc 1 33 0
	movl	%gs:20, %eax
	movl	%eax, -12(%ebp)
	xorl	%eax, %eax
.LBB2:
	.loc 1 37 0
	movl	$0x00000000, %eax
	movl	%eax, -308(%ebp)
	.loc 1 38 0
	cmpl	$0, 60(%ebp)
	jns	.L4
	.loc 1 40 0
	flds	36(%ebp)
	fsubs	12(%ebp)
	flds	36(%ebp)
	fsubs	12(%ebp)
	fmulp	%st, %st(1)
	flds	40(%ebp)
	fsubs	16(%ebp)
	flds	40(%ebp)
	fsubs	16(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	flds	44(%ebp)
	fsubs	20(%ebp)
	flds	44(%ebp)
	fsubs	20(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	flds	48(%ebp)
	fsubs	24(%ebp)
	flds	48(%ebp)
	fsubs	24(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	flds	52(%ebp)
	fsubs	28(%ebp)
	flds	52(%ebp)
	fsubs	28(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	flds	56(%ebp)
	fsubs	32(%ebp)
	flds	56(%ebp)
	fsubs	32(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fld	%st(0)
	fsqrt
	fucom	%st(0)
	fnstsw	%ax
	sahf
	jp	.L18
	je	.L19
	fstp	%st(0)
	jmp	.L17
.L18:
	fstp	%st(0)
.L17:
	fstpl	(%esp)
	call	sqrt
	jmp	.L5
.L19:
	fstp	%st(1)
.L5:
	fnstcw	-334(%ebp)
	movzwl	-334(%ebp), %eax
	movb	$12, %ah
	movw	%ax, -336(%ebp)
	fldcw	-336(%ebp)
	fistpl	-276(%ebp)
	fldcw	-334(%ebp)
	.loc 1 41 0
	fildl	-276(%ebp)
	fldl	.LC2
	fdivrp	%st, %st(1)
	fldcw	-336(%ebp)
	fistpl	-332(%ebp)
	fldcw	-334(%ebp)
	movl	-332(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -280(%ebp)
	.loc 1 42 0
	movl	60(%ebp), %eax
	negl	%eax
	cmpl	-280(%ebp), %eax
	jle	.L6
	negl	60(%ebp)
	jmp	.L7
.L6:
	movl	-280(%ebp), %eax
	movl	%eax, 60(%ebp)
.L7:
	.loc 1 43 0
	cmpl	$0, 60(%ebp)
	jg	.L8
	movl	$0, %eax
	jmp	.L9
.L8:
	.loc 1 44 0
	movl	60(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -332(%ebp)
	fildl	-332(%ebp)
	fld1
	fdivp	%st, %st(1)
	fstps	-312(%ebp)
	.loc 1 45 0
	movl	$0, -272(%ebp)
	jmp	.L10
.L11:
	.loc 1 47 0
	flds	-308(%ebp)
	fadds	-312(%ebp)
	fstps	-308(%ebp)
	.loc 1 48 0
	flds	36(%ebp)
	fsubs	12(%ebp)
	fmuls	-308(%ebp)
	fadds	12(%ebp)
	fstps	-284(%ebp)
	.loc 1 49 0
	flds	40(%ebp)
	fsubs	16(%ebp)
	fmuls	-308(%ebp)
	fadds	16(%ebp)
	fstps	-288(%ebp)
	.loc 1 50 0
	flds	44(%ebp)
	fsubs	20(%ebp)
	fmuls	-308(%ebp)
	fadds	20(%ebp)
	fstps	-292(%ebp)
	.loc 1 51 0
	flds	48(%ebp)
	fsubs	24(%ebp)
	fmuls	-308(%ebp)
	fadds	24(%ebp)
	fstps	-296(%ebp)
	.loc 1 52 0
	flds	52(%ebp)
	fsubs	28(%ebp)
	fmuls	-308(%ebp)
	fadds	28(%ebp)
	fstps	-300(%ebp)
	.loc 1 53 0
	flds	56(%ebp)
	fsubs	32(%ebp)
	fmuls	-308(%ebp)
	fadds	32(%ebp)
	fstps	-304(%ebp)
	.loc 1 54 0
	flds	-304(%ebp)
	flds	-300(%ebp)
	flds	-296(%ebp)
	flds	-292(%ebp)
	flds	-288(%ebp)
	flds	-284(%ebp)
	fxch	%st(5)
	movl	-328(%ebp), %eax
	movl	%eax, 60(%esp)
	fstpl	52(%esp)
	fxch	%st(3)
	fstpl	44(%esp)
	fxch	%st(1)
	fstpl	36(%esp)
	fstpl	28(%esp)
	fstpl	20(%esp)
	fstpl	12(%esp)
	movl	-324(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC4, 4(%esp)
	leal	-268(%ebp), %eax
	movl	%eax, (%esp)
	call	sprintf
	.loc 1 55 0
	movl	-320(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-268(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-316(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -316(%ebp)
	.loc 1 45 0
	addl	$1, -272(%ebp)
.L10:
	movl	-272(%ebp), %eax
	cmpl	60(%ebp), %eax
	setl	%al
	testb	%al, %al
	jne	.L11
	jmp	.L12
.L4:
	.loc 1 58 0
	cmpl	$0, 60(%ebp)
	jle	.L12
	.loc 1 60 0
	movl	60(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -332(%ebp)
	fildl	-332(%ebp)
	fld1
	fdivp	%st, %st(1)
	fstps	-312(%ebp)
	.loc 1 61 0
	movl	$1, -272(%ebp)
	jmp	.L13
.L14:
	.loc 1 63 0
	flds	-308(%ebp)
	fadds	-312(%ebp)
	fstps	-308(%ebp)
	.loc 1 64 0
	flds	36(%ebp)
	fsubs	12(%ebp)
	fmuls	-308(%ebp)
	fadds	12(%ebp)
	fstps	-284(%ebp)
	.loc 1 65 0
	flds	40(%ebp)
	fsubs	16(%ebp)
	fmuls	-308(%ebp)
	fadds	16(%ebp)
	fstps	-288(%ebp)
	.loc 1 66 0
	flds	44(%ebp)
	fsubs	20(%ebp)
	fmuls	-308(%ebp)
	fadds	20(%ebp)
	fstps	-292(%ebp)
	.loc 1 67 0
	flds	48(%ebp)
	fsubs	24(%ebp)
	fmuls	-308(%ebp)
	fadds	24(%ebp)
	fstps	-296(%ebp)
	.loc 1 68 0
	flds	52(%ebp)
	fsubs	28(%ebp)
	fmuls	-308(%ebp)
	fadds	28(%ebp)
	fstps	-300(%ebp)
	.loc 1 69 0
	flds	56(%ebp)
	fsubs	32(%ebp)
	fmuls	-308(%ebp)
	fadds	32(%ebp)
	fstps	-304(%ebp)
	.loc 1 70 0
	flds	-304(%ebp)
	flds	-300(%ebp)
	flds	-296(%ebp)
	flds	-292(%ebp)
	flds	-288(%ebp)
	flds	-284(%ebp)
	fxch	%st(5)
	movl	-328(%ebp), %eax
	movl	%eax, 60(%esp)
	fstpl	52(%esp)
	fxch	%st(3)
	fstpl	44(%esp)
	fxch	%st(1)
	fstpl	36(%esp)
	fstpl	28(%esp)
	fstpl	20(%esp)
	fstpl	12(%esp)
	movl	-324(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC4, 4(%esp)
	leal	-268(%ebp), %eax
	movl	%eax, (%esp)
	call	sprintf
	.loc 1 71 0
	movl	-320(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-268(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-316(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -316(%ebp)
	.loc 1 61 0
	addl	$1, -272(%ebp)
.L13:
	movl	-272(%ebp), %eax
	cmpl	60(%ebp), %eax
	setl	%al
	testb	%al, %al
	jne	.L14
.L12:
	.loc 1 74 0
	movl	-316(%ebp), %eax
.L9:
.LBE2:
	.loc 1 75 0
	movl	-12(%ebp), %edx
	xorl	%gs:20, %edx
	je	.L16
	call	__stack_chk_fail
.L16:
	leave
	ret
	.cfi_endproc
.LFE10:
	.size	split, .-split
.globl convertsplit
	.type	convertsplit, @function
convertsplit:
.LFB11:
	.loc 1 80 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI4:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI5:
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$476, %esp
	call	mcount
	movl	8(%ebp), %eax
	movl	%eax, -348(%ebp)
	movl	36(%ebp), %eax
	movl	%eax, -352(%ebp)
	movl	64(%ebp), %eax
	movl	%eax, -356(%ebp)
	movl	68(%ebp), %eax
	movl	%eax, -360(%ebp)
	movl	76(%ebp), %eax
	movl	%eax, -364(%ebp)
	movl	80(%ebp), %eax
	movl	%eax, -368(%ebp)
	movl	84(%ebp), %eax
	movl	%eax, -372(%ebp)
	.loc 1 80 0
	movl	%gs:20, %eax
	movl	%eax, -28(%ebp)
	xorl	%eax, %eax
.LBB3:
	.loc 1 84 0
	movl	-360(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-368(%ebp), %eax
	movl	%eax, (%esp)
	.cfi_offset 3, -20
	.cfi_offset 6, -16
	.cfi_offset 7, -12
	call	getFrameIdx
	movl	%eax, %ebx
	movl	-360(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-352(%ebp), %eax
	movl	%eax, (%esp)
	call	getFrameIdx
	movl	-360(%ebp), %edx
	movl	%edx, 36(%esp)
	movl	%ebx, 32(%esp)
	movl	32(%ebp), %edx
	movl	%edx, 28(%esp)
	movl	28(%ebp), %edx
	movl	%edx, 24(%esp)
	movl	24(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	20(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	leal	-308(%ebp), %eax
	movl	%eax, (%esp)
	call	convert
	.loc 1 85 0
	movl	-360(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-368(%ebp), %eax
	movl	%eax, (%esp)
	call	getFrameIdx
	movl	%eax, %ebx
	movl	-360(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-356(%ebp), %eax
	movl	%eax, (%esp)
	call	getFrameIdx
	movl	-360(%ebp), %edx
	movl	%edx, 36(%esp)
	movl	%ebx, 32(%esp)
	movl	60(%ebp), %edx
	movl	%edx, 28(%esp)
	movl	56(%ebp), %edx
	movl	%edx, 24(%esp)
	movl	52(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	48(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	44(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	40(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	leal	-332(%ebp), %eax
	movl	%eax, (%esp)
	call	convert
	.loc 1 88 0
	movl	-312(%ebp), %ecx
	movl	-316(%ebp), %esi
	movl	-320(%ebp), %edx
	movl	%edx, -400(%ebp)
	movl	-324(%ebp), %eax
	movl	%eax, -396(%ebp)
	movl	-328(%ebp), %edx
	movl	%edx, -392(%ebp)
	movl	-332(%ebp), %eax
	movl	%eax, -388(%ebp)
	movl	-288(%ebp), %edx
	movl	%edx, -384(%ebp)
	movl	-292(%ebp), %eax
	movl	%eax, -380(%ebp)
	movl	-296(%ebp), %edx
	movl	%edx, -376(%ebp)
	movl	-300(%ebp), %edi
	movl	-304(%ebp), %ebx
	movl	-308(%ebp), %edx
	movl	-372(%ebp), %eax
	movl	%eax, 64(%esp)
	movl	-368(%ebp), %eax
	movl	%eax, 60(%esp)
	movl	-364(%ebp), %eax
	movl	%eax, 56(%esp)
	movl	72(%ebp), %eax
	movl	%eax, 52(%esp)
	movl	%ecx, 48(%esp)
	movl	%esi, 44(%esp)
	movl	-400(%ebp), %eax
	movl	%eax, 40(%esp)
	movl	-396(%ebp), %eax
	movl	%eax, 36(%esp)
	movl	-392(%ebp), %eax
	movl	%eax, 32(%esp)
	movl	-388(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	-384(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	-380(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	-376(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	%edi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	-348(%ebp), %eax
	movl	%eax, (%esp)
	call	split
	movl	%eax, -348(%ebp)
	.loc 1 89 0
	cmpl	$0, 88(%ebp)
	je	.L21
	.loc 1 99 0
	flds	-312(%ebp)
	flds	-316(%ebp)
	flds	-320(%ebp)
	flds	-324(%ebp)
	flds	-328(%ebp)
	flds	-332(%ebp)
	fxch	%st(5)
	movl	-372(%ebp), %eax
	movl	%eax, 60(%esp)
	fstpl	52(%esp)
	fxch	%st(3)
	fstpl	44(%esp)
	fxch	%st(1)
	fstpl	36(%esp)
	fstpl	28(%esp)
	fstpl	20(%esp)
	fstpl	12(%esp)
	movl	-368(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC4, 4(%esp)
	leal	-284(%ebp), %eax
	movl	%eax, (%esp)
	call	sprintf
	.loc 1 100 0
	movl	-364(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-284(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-348(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -348(%ebp)
.L21:
	.loc 1 102 0
	movl	-348(%ebp), %eax
.LBE3:
	.loc 1 103 0
	movl	-28(%ebp), %edx
	xorl	%gs:20, %edx
	je	.L23
	call	__stack_chk_fail
.L23:
	addl	$476, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.cfi_endproc
.LFE11:
	.size	convertsplit, .-convertsplit
.globl _Z11spiralMacroP9tmpnRobotP11tmpnPathDefPiffffffP10tmpnVectoriii
	.type	_Z11spiralMacroP9tmpnRobotP11tmpnPathDefPiffffffP10tmpnVectoriii, @function
_Z11spiralMacroP9tmpnRobotP11tmpnPathDefPiffffffP10tmpnVectoriii:
.LFB12:
	.loc 1 125 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI6:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI7:
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$116, %esp
	call	mcount
	.loc 1 125 0
.LBB4:
.LBB5:
	.loc 1 127 0
	movl	$0, -12(%ebp)
	jmp	.L25
	.cfi_offset 3, -12
.L26:
.LBB6:
	.loc 1 128 0
	fildl	-12(%ebp)
	fmuls	40(%ebp)
	fildl	48(%ebp)
	fdivrp	%st, %st(1)
	fstps	-16(%ebp)
	.loc 1 129 0
	flds	-16(%ebp)
	fdivs	40(%ebp)
	fstps	-20(%ebp)
	.loc 1 130 0
	movl	44(%ebp), %eax
	flds	(%eax)
	fstpl	-96(%ebp)
	flds	-20(%ebp)
	fld1
	fsubrp	%st, %st(1)
	fldl	.LC5
	fmulp	%st, %st(1)
	flds	-20(%ebp)
	fld1
	fsubrp	%st, %st(1)
	fmulp	%st, %st(1)
	flds	-20(%ebp)
	fmulp	%st, %st(1)
	flds	20(%ebp)
	fmulp	%st, %st(1)
	fstpl	-88(%ebp)
	flds	36(%ebp)
	fldl	.LC6
	fmulp	%st, %st(1)
	flds	-16(%ebp)
	fmulp	%st, %st(1)
	fstpl	(%esp)
	call	sin
	fmull	-88(%ebp)
	fldl	-96(%ebp)
	faddp	%st, %st(1)
	flds	24(%ebp)
	fldl	.LC7
	fmulp	%st, %st(1)
	flds	-20(%ebp)
	fldl	.LC8
	fmulp	%st, %st(1)
	flds	-20(%ebp)
	fmulp	%st, %st(1)
	flds	-20(%ebp)
	flds	.LC9
	fmulp	%st, %st(1)
	fmuls	-20(%ebp)
	fmuls	-20(%ebp)
	faddp	%st, %st(1)
	flds	-20(%ebp)
	fldl	.LC8
	fmulp	%st, %st(1)
	flds	-20(%ebp)
	fmulp	%st, %st(1)
	flds	-20(%ebp)
	fmulp	%st, %st(1)
	flds	-20(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-60(%ebp)
	flds	-60(%ebp)
	fstps	-44(%ebp)
	.loc 1 131 0
	movl	44(%ebp), %eax
	flds	4(%eax)
	flds	-20(%ebp)
	flds	-20(%ebp)
	fldl	.LC10
	fmulp	%st, %st(1)
	flds	-20(%ebp)
	fmulp	%st, %st(1)
	flds	-20(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	.LC11
	fmulp	%st, %st(1)
	flds	32(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-60(%ebp)
	flds	-60(%ebp)
	fstps	-40(%ebp)
	.loc 1 132 0
	movl	44(%ebp), %eax
	flds	8(%eax)
	fstpl	-80(%ebp)
	flds	-20(%ebp)
	fld1
	fsubrp	%st, %st(1)
	fldl	.LC12
	fmulp	%st, %st(1)
	flds	-20(%ebp)
	fmulp	%st, %st(1)
	flds	-20(%ebp)
	fmulp	%st, %st(1)
	flds	20(%ebp)
	fmulp	%st, %st(1)
	fstpl	-72(%ebp)
	flds	36(%ebp)
	fldl	.LC6
	fmulp	%st, %st(1)
	flds	-16(%ebp)
	fmulp	%st, %st(1)
	fldl	.LC13
	faddp	%st, %st(1)
	fstpl	(%esp)
	call	sin
	fmull	-72(%ebp)
	fldl	-80(%ebp)
	faddp	%st, %st(1)
	flds	28(%ebp)
	fldl	.LC7
	fmulp	%st, %st(1)
	flds	-20(%ebp)
	fldl	.LC8
	fmulp	%st, %st(1)
	flds	-20(%ebp)
	fmulp	%st, %st(1)
	flds	-20(%ebp)
	flds	.LC9
	fmulp	%st, %st(1)
	fmuls	-20(%ebp)
	fmuls	-20(%ebp)
	faddp	%st, %st(1)
	flds	-20(%ebp)
	fldl	.LC8
	fmulp	%st, %st(1)
	flds	-20(%ebp)
	fmulp	%st, %st(1)
	flds	-20(%ebp)
	fmulp	%st, %st(1)
	flds	-20(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-60(%ebp)
	flds	-60(%ebp)
	fstps	-36(%ebp)
	.loc 1 133 0
	movl	44(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, -32(%ebp)
	.loc 1 134 0
	movl	44(%ebp), %eax
	movl	16(%eax), %eax
	movl	%eax, -28(%ebp)
	.loc 1 135 0
	movl	44(%ebp), %eax
	movl	20(%eax), %eax
	movl	%eax, -24(%ebp)
	.loc 1 136 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-44(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$320, %eax
	movl	%ecx, (%eax)
	.loc 1 137 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-40(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$324, %eax
	movl	%ecx, (%eax)
	.loc 1 138 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-36(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$328, %eax
	movl	%ecx, (%eax)
	.loc 1 139 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-32(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$332, %eax
	movl	%ecx, (%eax)
	.loc 1 140 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-28(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$336, %eax
	movl	%ecx, (%eax)
	.loc 1 141 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-24(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$340, %eax
	movl	%ecx, (%eax)
	.loc 1 142 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	leal	308(%eax), %edx
	movl	52(%ebp), %eax
	movl	%eax, (%edx)
	.loc 1 143 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	fildl	56(%ebp)
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	addl	$316, %eax
	fstps	(%eax)
	.loc 1 144 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	addl	$312, %eax
	movl	$0, (%eax)
	.loc 1 145 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	leal	344(%eax), %edx
	movl	$0x41200000, %eax
	movl	%eax, (%edx)
	.loc 1 146 0
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	leal	1(%eax), %edx
	movl	16(%ebp), %eax
	movl	%edx, (%eax)
.LBE6:
	.loc 1 127 0
	addl	$1, -12(%ebp)
.L25:
	movl	48(%ebp), %eax
	addl	$1, %eax
	cmpl	-12(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L26
.LBE5:
.LBE4:
	.loc 1 148 0
	addl	$116, %esp
	popl	%ebx
	popl	%ebp
	ret
	.cfi_endproc
.LFE12:
	.size	_Z11spiralMacroP9tmpnRobotP11tmpnPathDefPiffffffP10tmpnVectoriii, .-_Z11spiralMacroP9tmpnRobotP11tmpnPathDefPiffffffP10tmpnVectoriii
	.section	.text.spiralspeed,"axG",@progbits,spiralspeed,comdat
	.weak	spiralspeed
	.type	spiralspeed, @function
spiralspeed:
.LFB13:
	.loc 1 151 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI8:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI9:
	.cfi_def_cfa_register 5
	call	mcount
	.loc 1 151 0
	.loc 1 152 0
	flds	8(%ebp)
	flds	.LC15
	fmulp	%st, %st(1)
	flds	12(%ebp)
	flds	.LC16
	fmulp	%st, %st(1)
	fdivrp	%st, %st(1)
	.loc 1 153 0
	popl	%ebp
	ret
	.cfi_endproc
.LFE13:
	.size	spiralspeed, .-spiralspeed
	.text
.globl _Z11uplineMacroP9tmpnRobotP11tmpnPathDefPiffP10tmpnVectoriii
	.type	_Z11uplineMacroP9tmpnRobotP11tmpnPathDefPiffP10tmpnVectoriii, @function
_Z11uplineMacroP9tmpnRobotP11tmpnPathDefPiffP10tmpnVectoriii:
.LFB14:
	.loc 1 171 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI10:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI11:
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	call	mcount
	.loc 1 171 0
.LBB7:
.LBB8:
	.loc 1 173 0
	movl	$0, -8(%ebp)
	jmp	.L31
	.cfi_offset 3, -12
.L32:
.LBB9:
	.loc 1 174 0
	fildl	-8(%ebp)
	fmuls	24(%ebp)
	fildl	32(%ebp)
	fdivrp	%st, %st(1)
	fstps	-12(%ebp)
	.loc 1 175 0
	flds	-12(%ebp)
	fdivs	24(%ebp)
	fld1
	fsubp	%st, %st(1)
	fstps	-16(%ebp)
	.loc 1 176 0
	movl	28(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -40(%ebp)
	.loc 1 177 0
	movl	28(%ebp), %eax
	flds	4(%eax)
	flds	-16(%ebp)
	flds	-16(%ebp)
	fldl	.LC10
	fmulp	%st, %st(1)
	flds	-16(%ebp)
	fmulp	%st, %st(1)
	flds	-16(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	.LC11
	fmulp	%st, %st(1)
	flds	20(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-56(%ebp)
	flds	-56(%ebp)
	fstps	-36(%ebp)
	.loc 1 178 0
	movl	28(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, -32(%ebp)
	.loc 1 179 0
	movl	28(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, -28(%ebp)
	.loc 1 180 0
	movl	28(%ebp), %eax
	movl	16(%eax), %eax
	movl	%eax, -24(%ebp)
	.loc 1 181 0
	movl	28(%ebp), %eax
	movl	20(%eax), %eax
	movl	%eax, -20(%ebp)
	.loc 1 182 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-40(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$320, %eax
	movl	%ecx, (%eax)
	.loc 1 183 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-36(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$324, %eax
	movl	%ecx, (%eax)
	.loc 1 184 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-32(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$328, %eax
	movl	%ecx, (%eax)
	.loc 1 185 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-28(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$332, %eax
	movl	%ecx, (%eax)
	.loc 1 186 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-24(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$336, %eax
	movl	%ecx, (%eax)
	.loc 1 187 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-20(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$340, %eax
	movl	%ecx, (%eax)
	.loc 1 188 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	leal	308(%eax), %edx
	movl	36(%ebp), %eax
	movl	%eax, (%edx)
	.loc 1 189 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	fildl	40(%ebp)
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	addl	$316, %eax
	fstps	(%eax)
	.loc 1 190 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	addl	$312, %eax
	movl	$0, (%eax)
	.loc 1 191 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	leal	344(%eax), %edx
	movl	$0x41200000, %eax
	movl	%eax, (%edx)
	.loc 1 192 0
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	leal	1(%eax), %edx
	movl	16(%ebp), %eax
	movl	%edx, (%eax)
.LBE9:
	.loc 1 173 0
	addl	$1, -8(%ebp)
.L31:
	movl	-8(%ebp), %eax
	cmpl	32(%ebp), %eax
	setl	%al
	testb	%al, %al
	jne	.L32
.LBE8:
.LBE7:
	.loc 1 194 0
	addl	$52, %esp
	popl	%ebx
	popl	%ebp
	ret
	.cfi_endproc
.LFE14:
	.size	_Z11uplineMacroP9tmpnRobotP11tmpnPathDefPiffP10tmpnVectoriii, .-_Z11uplineMacroP9tmpnRobotP11tmpnPathDefPiffP10tmpnVectoriii
	.section	.text.uplinespeed,"axG",@progbits,uplinespeed,comdat
	.weak	uplinespeed
	.type	uplinespeed, @function
uplinespeed:
.LFB15:
	.loc 1 197 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI12:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI13:
	.cfi_def_cfa_register 5
	call	mcount
	.loc 1 197 0
	.loc 1 198 0
	flds	8(%ebp)
	flds	.LC15
	fmulp	%st, %st(1)
	flds	12(%ebp)
	fadd	%st(0), %st
	fdivrp	%st, %st(1)
	.loc 1 199 0
	popl	%ebp
	ret
	.cfi_endproc
.LFE15:
	.size	uplinespeed, .-uplinespeed
	.text
.globl _Z15fastUplineMacroP9tmpnRobotP11tmpnPathDefPiffP10tmpnVectoriii
	.type	_Z15fastUplineMacroP9tmpnRobotP11tmpnPathDefPiffP10tmpnVectoriii, @function
_Z15fastUplineMacroP9tmpnRobotP11tmpnPathDefPiffP10tmpnVectoriii:
.LFB16:
	.loc 1 202 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI14:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI15:
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$52, %esp
	call	mcount
	.loc 1 202 0
.LBB10:
	.loc 1 204 0
	flds	20(%ebp)
	fld	%st(0)
	faddp	%st, %st(1)
	flds	24(%ebp)
	fmuls	24(%ebp)
	fdivrp	%st, %st(1)
	fstps	-8(%ebp)
.LBB11:
	.loc 1 205 0
	movl	$0, -12(%ebp)
	jmp	.L37
	.cfi_offset 3, -12
.L38:
.LBB12:
	.loc 1 206 0
	fildl	-12(%ebp)
	fmuls	24(%ebp)
	fildl	32(%ebp)
	fdivrp	%st, %st(1)
	fstps	-16(%ebp)
	.loc 1 207 0
	movl	28(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -40(%ebp)
	.loc 1 208 0
	movl	28(%ebp), %eax
	flds	4(%eax)
	fsubs	20(%ebp)
	flds	-8(%ebp)
	fldl	.LC17
	fmulp	%st, %st(1)
	flds	-16(%ebp)
	fmulp	%st, %st(1)
	flds	-16(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-56(%ebp)
	flds	-56(%ebp)
	fstps	-36(%ebp)
	.loc 1 209 0
	movl	28(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, -32(%ebp)
	.loc 1 210 0
	movl	28(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, -28(%ebp)
	.loc 1 211 0
	movl	28(%ebp), %eax
	movl	16(%eax), %eax
	movl	%eax, -24(%ebp)
	.loc 1 212 0
	movl	28(%ebp), %eax
	movl	20(%eax), %eax
	movl	%eax, -20(%ebp)
	.loc 1 213 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-40(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$320, %eax
	movl	%ecx, (%eax)
	.loc 1 214 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-36(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$324, %eax
	movl	%ecx, (%eax)
	.loc 1 215 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-32(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$328, %eax
	movl	%ecx, (%eax)
	.loc 1 216 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-28(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$332, %eax
	movl	%ecx, (%eax)
	.loc 1 217 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-24(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$336, %eax
	movl	%ecx, (%eax)
	.loc 1 218 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-20(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$340, %eax
	movl	%ecx, (%eax)
	.loc 1 219 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	leal	308(%eax), %edx
	movl	36(%ebp), %eax
	movl	%eax, (%edx)
	.loc 1 220 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	fildl	40(%ebp)
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	addl	$316, %eax
	fstps	(%eax)
	.loc 1 221 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	addl	$312, %eax
	movl	$0, (%eax)
	.loc 1 222 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	leal	344(%eax), %edx
	movl	$0x41200000, %eax
	movl	%eax, (%edx)
	.loc 1 223 0
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	leal	1(%eax), %edx
	movl	16(%ebp), %eax
	movl	%edx, (%eax)
.LBE12:
	.loc 1 205 0
	addl	$1, -12(%ebp)
.L37:
	movl	-12(%ebp), %eax
	cmpl	32(%ebp), %eax
	setl	%al
	testb	%al, %al
	jne	.L38
.LBE11:
.LBE10:
	.loc 1 225 0
	addl	$52, %esp
	popl	%ebx
	popl	%ebp
	ret
	.cfi_endproc
.LFE16:
	.size	_Z15fastUplineMacroP9tmpnRobotP11tmpnPathDefPiffP10tmpnVectoriii, .-_Z15fastUplineMacroP9tmpnRobotP11tmpnPathDefPiffP10tmpnVectoriii
	.section	.text._Z15fastuplinespeedff,"axG",@progbits,_Z15fastuplinespeedff,comdat
	.weak	_Z15fastuplinespeedff
	.type	_Z15fastuplinespeedff, @function
_Z15fastuplinespeedff:
.LFB17:
	.loc 1 228 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI16:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI17:
	.cfi_def_cfa_register 5
	call	mcount
	.loc 1 228 0
	.loc 1 229 0
	flds	8(%ebp)
	fadd	%st(0), %st
	fdivs	12(%ebp)
	.loc 1 230 0
	popl	%ebp
	ret
	.cfi_endproc
.LFE17:
	.size	_Z15fastuplinespeedff, .-_Z15fastuplinespeedff
	.text
.globl _Z13downlineMacroP9tmpnRobotP11tmpnPathDefPiffP10tmpnVectoriii
	.type	_Z13downlineMacroP9tmpnRobotP11tmpnPathDefPiffP10tmpnVectoriii, @function
_Z13downlineMacroP9tmpnRobotP11tmpnPathDefPiffP10tmpnVectoriii:
.LFB18:
	.loc 1 247 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
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
	.loc 1 247 0
.LBB13:
.LBB14:
	.loc 1 249 0
	movl	$0, -8(%ebp)
	jmp	.L43
	.cfi_offset 3, -12
.L44:
.LBB15:
	.loc 1 250 0
	fildl	-8(%ebp)
	fmuls	24(%ebp)
	fildl	32(%ebp)
	fdivrp	%st, %st(1)
	fstps	-12(%ebp)
	.loc 1 251 0
	flds	-12(%ebp)
	fdivs	24(%ebp)
	fstps	-16(%ebp)
	.loc 1 252 0
	movl	28(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -40(%ebp)
	.loc 1 253 0
	movl	28(%ebp), %eax
	flds	4(%eax)
	flds	-16(%ebp)
	flds	-16(%ebp)
	fldl	.LC10
	fmulp	%st, %st(1)
	flds	-16(%ebp)
	fmulp	%st, %st(1)
	flds	-16(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fldl	.LC11
	fmulp	%st, %st(1)
	flds	20(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-56(%ebp)
	flds	-56(%ebp)
	fstps	-36(%ebp)
	.loc 1 254 0
	movl	28(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, -32(%ebp)
	.loc 1 255 0
	movl	28(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, -28(%ebp)
	.loc 1 256 0
	movl	28(%ebp), %eax
	movl	16(%eax), %eax
	movl	%eax, -24(%ebp)
	.loc 1 257 0
	movl	28(%ebp), %eax
	movl	20(%eax), %eax
	movl	%eax, -20(%ebp)
	.loc 1 258 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-40(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$320, %eax
	movl	%ecx, (%eax)
	.loc 1 259 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-36(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$324, %eax
	movl	%ecx, (%eax)
	.loc 1 260 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-32(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$328, %eax
	movl	%ecx, (%eax)
	.loc 1 261 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-28(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$332, %eax
	movl	%ecx, (%eax)
	.loc 1 262 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-24(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$336, %eax
	movl	%ecx, (%eax)
	.loc 1 263 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-20(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$340, %eax
	movl	%ecx, (%eax)
	.loc 1 264 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	leal	308(%eax), %edx
	movl	36(%ebp), %eax
	movl	%eax, (%edx)
	.loc 1 265 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	fildl	40(%ebp)
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	addl	$316, %eax
	fstps	(%eax)
	.loc 1 266 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	addl	$312, %eax
	movl	$0, (%eax)
	.loc 1 267 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	leal	344(%eax), %edx
	movl	$0x41200000, %eax
	movl	%eax, (%edx)
	.loc 1 268 0
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	leal	1(%eax), %edx
	movl	16(%ebp), %eax
	movl	%edx, (%eax)
.LBE15:
	.loc 1 249 0
	addl	$1, -8(%ebp)
.L43:
	movl	32(%ebp), %eax
	addl	$1, %eax
	cmpl	-8(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L44
.LBE14:
.LBE13:
	.loc 1 270 0
	addl	$52, %esp
	popl	%ebx
	popl	%ebp
	ret
	.cfi_endproc
.LFE18:
	.size	_Z13downlineMacroP9tmpnRobotP11tmpnPathDefPiffP10tmpnVectoriii, .-_Z13downlineMacroP9tmpnRobotP11tmpnPathDefPiffP10tmpnVectoriii
	.section	.text.downlinespeed,"axG",@progbits,downlinespeed,comdat
	.weak	downlinespeed
	.type	downlinespeed, @function
downlinespeed:
.LFB19:
	.loc 1 273 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI20:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI21:
	.cfi_def_cfa_register 5
	call	mcount
	.loc 1 273 0
	.loc 1 274 0
	flds	8(%ebp)
	flds	.LC9
	fmulp	%st, %st(1)
	flds	12(%ebp)
	fadd	%st(0), %st
	fdivrp	%st, %st(1)
	.loc 1 275 0
	popl	%ebp
	ret
	.cfi_endproc
.LFE19:
	.size	downlinespeed, .-downlinespeed
	.text
.globl _Z17fastDownlineMacroP9tmpnRobotP11tmpnPathDefPiffP10tmpnVectoriii
	.type	_Z17fastDownlineMacroP9tmpnRobotP11tmpnPathDefPiffP10tmpnVectoriii, @function
_Z17fastDownlineMacroP9tmpnRobotP11tmpnPathDefPiffP10tmpnVectoriii:
.LFB20:
	.loc 1 278 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
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
	.loc 1 278 0
.LBB16:
	.loc 1 280 0
	flds	20(%ebp)
	fld	%st(0)
	faddp	%st, %st(1)
	flds	24(%ebp)
	fmuls	24(%ebp)
	fdivrp	%st, %st(1)
	fstps	-8(%ebp)
.LBB17:
	.loc 1 281 0
	movl	$0, -12(%ebp)
	jmp	.L49
	.cfi_offset 3, -12
.L50:
.LBB18:
	.loc 1 282 0
	fildl	-12(%ebp)
	fmuls	24(%ebp)
	fildl	32(%ebp)
	fdivrp	%st, %st(1)
	fstps	-16(%ebp)
	.loc 1 283 0
	flds	24(%ebp)
	fsubs	-16(%ebp)
	fstps	-20(%ebp)
	.loc 1 284 0
	movl	28(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -44(%ebp)
	.loc 1 285 0
	movl	28(%ebp), %eax
	flds	4(%eax)
	fsubs	20(%ebp)
	flds	-8(%ebp)
	fldl	.LC17
	fmulp	%st, %st(1)
	flds	-20(%ebp)
	fmulp	%st, %st(1)
	flds	-20(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-56(%ebp)
	flds	-56(%ebp)
	fstps	-40(%ebp)
	.loc 1 286 0
	movl	28(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, -36(%ebp)
	.loc 1 287 0
	movl	28(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, -32(%ebp)
	.loc 1 288 0
	movl	28(%ebp), %eax
	movl	16(%eax), %eax
	movl	%eax, -28(%ebp)
	.loc 1 289 0
	movl	28(%ebp), %eax
	movl	20(%eax), %eax
	movl	%eax, -24(%ebp)
	.loc 1 290 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-44(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$320, %eax
	movl	%ecx, (%eax)
	.loc 1 291 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-40(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$324, %eax
	movl	%ecx, (%eax)
	.loc 1 292 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-36(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$328, %eax
	movl	%ecx, (%eax)
	.loc 1 293 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-32(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$332, %eax
	movl	%ecx, (%eax)
	.loc 1 294 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-28(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$336, %eax
	movl	%ecx, (%eax)
	.loc 1 295 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	-24(%ebp), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$340, %eax
	movl	%ecx, (%eax)
	.loc 1 296 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	leal	308(%eax), %edx
	movl	36(%ebp), %eax
	movl	%eax, (%edx)
	.loc 1 297 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	fildl	40(%ebp)
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	addl	$316, %eax
	fstps	(%eax)
	.loc 1 298 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	addl	$312, %eax
	movl	$0, (%eax)
	.loc 1 299 0
	movl	16(%ebp), %eax
	movl	(%eax), %edx
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	leal	344(%eax), %edx
	movl	$0x41200000, %eax
	movl	%eax, (%edx)
	.loc 1 300 0
	movl	16(%ebp), %eax
	movl	(%eax), %eax
	leal	1(%eax), %edx
	movl	16(%ebp), %eax
	movl	%edx, (%eax)
.LBE18:
	.loc 1 281 0
	addl	$1, -12(%ebp)
.L49:
	movl	32(%ebp), %eax
	addl	$1, %eax
	cmpl	-12(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L50
.LBE17:
.LBE16:
	.loc 1 302 0
	addl	$52, %esp
	popl	%ebx
	popl	%ebp
	ret
	.cfi_endproc
.LFE20:
	.size	_Z17fastDownlineMacroP9tmpnRobotP11tmpnPathDefPiffP10tmpnVectoriii, .-_Z17fastDownlineMacroP9tmpnRobotP11tmpnPathDefPiffP10tmpnVectoriii
	.section	.text._Z17fastdownlinespeedff,"axG",@progbits,_Z17fastdownlinespeedff,comdat
	.weak	_Z17fastdownlinespeedff
	.type	_Z17fastdownlinespeedff, @function
_Z17fastdownlinespeedff:
.LFB21:
	.loc 1 305 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI24:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI25:
	.cfi_def_cfa_register 5
	call	mcount
	.loc 1 305 0
	.loc 1 306 0
	flds	8(%ebp)
	flds	.LC16
	fmulp	%st, %st(1)
	fdivs	12(%ebp)
	.loc 1 307 0
	popl	%ebp
	ret
	.cfi_endproc
.LFE21:
	.size	_Z17fastdownlinespeedff, .-_Z17fastdownlinespeedff
	.text
.globl blendquintic
	.type	blendquintic, @function
blendquintic:
.LFB22:
	.loc 1 314 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI26:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI27:
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$332, %esp
	call	mcount
	.loc 1 314 0
.LBB19:
	.loc 1 318 0
	movl	$0, -32(%ebp)
	jmp	.L55
	.cfi_offset 3, -20
	.cfi_offset 6, -16
	.cfi_offset 7, -12
.L56:
	.loc 1 319 0
	movl	-32(%ebp), %eax
	movl	-32(%ebp), %ecx
	movl	16(%ebp), %edx
	movl	(%edx,%ecx,4), %edx
	movl	%edx, -204(%ebp,%eax,4)
	.loc 1 320 0
	movl	-32(%ebp), %ecx
	movl	-32(%ebp), %edx
	movl	20(%ebp), %eax
	movl	(%eax,%edx,4), %eax
	leal	6(%ecx), %edx
	movl	%eax, -204(%ebp,%edx,4)
	.loc 1 321 0
	movl	-32(%ebp), %ecx
	movl	-32(%ebp), %edx
	movl	24(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC18
	fmulp	%st, %st(1)
	leal	12(%ecx), %eax
	fstps	-204(%ebp,%eax,4)
	.loc 1 322 0
	movl	-32(%ebp), %ebx
	movl	-32(%ebp), %edx
	movl	16(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC19
	fmulp	%st, %st(1)
	movl	-32(%ebp), %edx
	movl	28(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC20
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-32(%ebp), %edx
	movl	20(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC21
	fmulp	%st, %st(1)
	movl	-32(%ebp), %edx
	movl	32(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC22
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	flds	40(%ebp)
	flds	.LC9
	fmulp	%st, %st(1)
	movl	-32(%ebp), %edx
	movl	24(%ebp), %eax
	flds	(%eax,%edx,4)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-32(%ebp), %edx
	movl	36(%ebp), %eax
	flds	(%eax,%edx,4)
	fmuls	40(%ebp)
	faddp	%st, %st(1)
	fmuls	40(%ebp)
	faddp	%st, %st(1)
	fstpl	-304(%ebp)
	flds	40(%ebp)
	fldl	.LC23
	fstpl	8(%esp)
	fstpl	(%esp)
	call	pow
	fadd	%st(0), %st
	fdivrl	-304(%ebp)
	fstps	-220(%ebp)
	flds	-220(%ebp)
	leal	18(%ebx), %eax
	fstps	-204(%ebp,%eax,4)
	.loc 1 323 0
	movl	-32(%ebp), %ebx
	movl	-32(%ebp), %edx
	movl	16(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC24
	fmulp	%st, %st(1)
	movl	-32(%ebp), %edx
	movl	28(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC25
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-32(%ebp), %edx
	movl	20(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC26
	fmulp	%st, %st(1)
	movl	-32(%ebp), %edx
	movl	32(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC27
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	flds	40(%ebp)
	flds	.LC15
	fmulp	%st, %st(1)
	movl	-32(%ebp), %edx
	movl	24(%ebp), %eax
	flds	(%eax,%edx,4)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	flds	40(%ebp)
	flds	.LC16
	fmulp	%st, %st(1)
	movl	-32(%ebp), %edx
	movl	36(%ebp), %eax
	flds	(%eax,%edx,4)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmuls	40(%ebp)
	faddp	%st, %st(1)
	fstpl	-296(%ebp)
	flds	40(%ebp)
	fldl	.LC28
	fstpl	8(%esp)
	fstpl	(%esp)
	call	pow
	fadd	%st(0), %st
	fdivrl	-296(%ebp)
	fstps	-220(%ebp)
	flds	-220(%ebp)
	leal	24(%ebx), %eax
	fstps	-204(%ebp,%eax,4)
	.loc 1 324 0
	movl	-32(%ebp), %ebx
	movl	-32(%ebp), %edx
	movl	16(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC29
	fmulp	%st, %st(1)
	movl	-32(%ebp), %edx
	movl	28(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC21
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-32(%ebp), %edx
	movl	20(%ebp), %eax
	flds	(%eax,%edx,4)
	movl	-32(%ebp), %edx
	movl	32(%ebp), %eax
	flds	(%eax,%edx,4)
	faddp	%st, %st(1)
	flds	.LC30
	fmulp	%st, %st(1)
	movl	-32(%ebp), %edx
	movl	24(%ebp), %eax
	flds	(%eax,%edx,4)
	movl	-32(%ebp), %edx
	movl	36(%ebp), %eax
	flds	(%eax,%edx,4)
	fsubrp	%st, %st(1)
	fmuls	40(%ebp)
	faddp	%st, %st(1)
	fmuls	40(%ebp)
	faddp	%st, %st(1)
	fchs
	fstpl	-288(%ebp)
	flds	40(%ebp)
	fldl	.LC31
	fstpl	8(%esp)
	fstpl	(%esp)
	call	pow
	fadd	%st(0), %st
	fdivrl	-288(%ebp)
	fstps	-220(%ebp)
	flds	-220(%ebp)
	leal	30(%ebx), %eax
	fstps	-204(%ebp,%eax,4)
	.loc 1 318 0
	addl	$1, -32(%ebp)
.L55:
	cmpl	$4, -32(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L56
	.loc 1 326 0
	movl	$0, -28(%ebp)
	jmp	.L57
.L62:
.LBB20:
	.loc 1 327 0
	fildl	-28(%ebp)
	fmuls	40(%ebp)
	fildl	44(%ebp)
	fdivrp	%st, %st(1)
	fstps	-36(%ebp)
	.loc 1 328 0
	movl	-28(%ebp), %eax
	cmpl	44(%ebp), %eax
	jne	.L58
	.loc 1 329 0
	cmpl	$0, 60(%ebp)
	je	.L64
.L58:
	.loc 1 331 0
	movl	$0, -32(%ebp)
	jmp	.L60
.L61:
	.loc 1 332 0
	movl	-32(%ebp), %ebx
	movl	-32(%ebp), %eax
	addl	$30, %eax
	flds	-204(%ebp,%eax,4)
	fstpl	-280(%ebp)
	flds	-36(%ebp)
	fldl	.LC31
	fstpl	8(%esp)
	fstpl	(%esp)
	call	pow
	fldl	-280(%ebp)
	fmulp	%st, %st(1)
	fstpl	-272(%ebp)
	movl	-32(%ebp), %eax
	addl	$24, %eax
	flds	-204(%ebp,%eax,4)
	fstpl	-264(%ebp)
	flds	-36(%ebp)
	fldl	.LC28
	fstpl	8(%esp)
	fstpl	(%esp)
	call	pow
	fmull	-264(%ebp)
	fldl	-272(%ebp)
	faddp	%st, %st(1)
	fstpl	-256(%ebp)
	movl	-32(%ebp), %eax
	addl	$18, %eax
	flds	-204(%ebp,%eax,4)
	fstpl	-248(%ebp)
	flds	-36(%ebp)
	fldl	.LC23
	fstpl	8(%esp)
	fstpl	(%esp)
	call	pow
	fmull	-248(%ebp)
	fldl	-256(%ebp)
	faddp	%st, %st(1)
	fstpl	-240(%ebp)
	movl	-32(%ebp), %eax
	addl	$12, %eax
	flds	-204(%ebp,%eax,4)
	fstpl	-232(%ebp)
	flds	-36(%ebp)
	fldl	.LC32
	fstpl	8(%esp)
	fstpl	(%esp)
	call	pow
	fmull	-232(%ebp)
	fldl	-240(%ebp)
	faddp	%st, %st(1)
	movl	-32(%ebp), %eax
	addl	$6, %eax
	flds	-204(%ebp,%eax,4)
	fmuls	-36(%ebp)
	faddp	%st, %st(1)
	movl	-32(%ebp), %eax
	flds	-204(%ebp,%eax,4)
	faddp	%st, %st(1)
	fstps	-220(%ebp)
	flds	-220(%ebp)
	fstps	-60(%ebp,%ebx,4)
	.loc 1 331 0
	addl	$1, -32(%ebp)
.L60:
	cmpl	$4, -32(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L61
	.loc 1 334 0
	movl	-44(%ebp), %esi
	movl	-48(%ebp), %ebx
	movl	-52(%ebp), %ecx
	movl	-56(%ebp), %edx
	movl	-60(%ebp), %eax
	movl	48(%ebp), %edi
	movl	%edi, 28(%esp)
	movl	$0x00000000, %edi
	movl	%edi, 24(%esp)
	movl	%esi, 20(%esp)
	movl	%ebx, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	52(%ebp), %eax
	movl	%eax, (%esp)
	call	tmpnComputeFKlogic
	.loc 1 335 0
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	52(%ebp), %eax
	movl	1316(%eax), %ecx
	movl	8(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$320, %eax
	movl	%ecx, (%eax)
	.loc 1 336 0
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	52(%ebp), %eax
	movl	1320(%eax), %ecx
	movl	8(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$324, %eax
	movl	%ecx, (%eax)
	.loc 1 337 0
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	52(%ebp), %eax
	movl	1324(%eax), %ecx
	movl	8(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$328, %eax
	movl	%ecx, (%eax)
	.loc 1 338 0
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	52(%ebp), %eax
	movl	1328(%eax), %ecx
	movl	8(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$332, %eax
	movl	%ecx, (%eax)
	.loc 1 339 0
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	52(%ebp), %eax
	movl	1332(%eax), %ecx
	movl	8(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$336, %eax
	movl	%ecx, (%eax)
	.loc 1 340 0
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	52(%ebp), %eax
	movl	1336(%eax), %ecx
	movl	8(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$340, %eax
	movl	%ecx, (%eax)
	.loc 1 341 0
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	leal	308(%eax), %edx
	movl	48(%ebp), %eax
	movl	%eax, (%edx)
	.loc 1 342 0
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	fildl	56(%ebp)
	movl	8(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	addl	$316, %eax
	fstps	(%eax)
	.loc 1 343 0
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	addl	$312, %eax
	movl	$0, (%eax)
	.loc 1 344 0
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	leal	344(%eax), %edx
	movl	$0x41200000, %eax
	movl	%eax, (%edx)
	.loc 1 345 0
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	leal	1(%eax), %edx
	movl	12(%ebp), %eax
	movl	%edx, (%eax)
.LBE20:
	.loc 1 326 0
	addl	$1, -28(%ebp)
.L57:
	movl	44(%ebp), %eax
	addl	$1, %eax
	cmpl	-28(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L62
	jmp	.L63
.L64:
.LBB21:
	.loc 1 329 0
	nop
.L63:
.LBE21:
.LBE19:
	.loc 1 347 0
	addl	$332, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.cfi_endproc
.LFE22:
	.size	blendquintic, .-blendquintic
.globl blendquinticmaxvel
	.type	blendquinticmaxvel, @function
blendquinticmaxvel:
.LFB23:
	.loc 1 350 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI28:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI29:
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$308, %esp
	call	mcount
	.loc 1 350 0
.LBB22:
	.loc 1 352 0
	movl	$100, -20(%ebp)
	.loc 1 355 0
	leal	-76(%ebp), %edx
	movl	$0, %ecx
	movl	$24, %eax
	movl	%eax, %ebx
	.cfi_offset 3, -12
	andl	$-4, %ebx
	movl	$0, %eax
.L66:
	movl	%ecx, (%edx,%eax)
	addl	$4, %eax
	cmpl	%ebx, %eax
	jb	.L66
	addl	%eax, %edx
	.loc 1 356 0
	movl	$0, -16(%ebp)
	jmp	.L68
.L69:
	.loc 1 357 0
	movl	-16(%ebp), %eax
	movl	-16(%ebp), %ecx
	movl	12(%ebp), %edx
	movl	(%edx,%ecx,4), %edx
	movl	%edx, -196(%ebp,%eax,4)
	.loc 1 358 0
	movl	-16(%ebp), %ecx
	movl	-16(%ebp), %edx
	movl	16(%ebp), %eax
	movl	(%eax,%edx,4), %eax
	leal	6(%ecx), %edx
	movl	%eax, -196(%ebp,%edx,4)
	.loc 1 359 0
	movl	-16(%ebp), %ebx
	movl	-16(%ebp), %edx
	movl	8(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC19
	fmulp	%st, %st(1)
	movl	-16(%ebp), %edx
	movl	20(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC20
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-16(%ebp), %edx
	movl	12(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC21
	fmulp	%st, %st(1)
	movl	-16(%ebp), %edx
	movl	24(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC22
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	flds	32(%ebp)
	flds	.LC9
	fmulp	%st, %st(1)
	movl	-16(%ebp), %edx
	movl	16(%ebp), %eax
	flds	(%eax,%edx,4)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-16(%ebp), %edx
	movl	28(%ebp), %eax
	flds	(%eax,%edx,4)
	fmuls	32(%ebp)
	faddp	%st, %st(1)
	fmuls	32(%ebp)
	faddp	%st, %st(1)
	flds	.LC15
	fmulp	%st, %st(1)
	fstpl	-272(%ebp)
	flds	32(%ebp)
	fldl	.LC23
	fstpl	8(%esp)
	fstpl	(%esp)
	call	pow
	fadd	%st(0), %st
	fdivrl	-272(%ebp)
	fstps	-204(%ebp)
	flds	-204(%ebp)
	leal	12(%ebx), %eax
	fstps	-196(%ebp,%eax,4)
	.loc 1 360 0
	movl	-16(%ebp), %ebx
	movl	-16(%ebp), %edx
	movl	8(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC24
	fmulp	%st, %st(1)
	movl	-16(%ebp), %edx
	movl	20(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC25
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-16(%ebp), %edx
	movl	12(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC26
	fmulp	%st, %st(1)
	movl	-16(%ebp), %edx
	movl	24(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC27
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	flds	32(%ebp)
	flds	.LC15
	fmulp	%st, %st(1)
	movl	-16(%ebp), %edx
	movl	16(%ebp), %eax
	flds	(%eax,%edx,4)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	flds	32(%ebp)
	flds	.LC16
	fmulp	%st, %st(1)
	movl	-16(%ebp), %edx
	movl	28(%ebp), %eax
	flds	(%eax,%edx,4)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmuls	32(%ebp)
	faddp	%st, %st(1)
	fadd	%st(0), %st
	fstpl	-264(%ebp)
	flds	32(%ebp)
	fldl	.LC28
	fstpl	8(%esp)
	fstpl	(%esp)
	call	pow
	fdivrl	-264(%ebp)
	fstps	-204(%ebp)
	flds	-204(%ebp)
	leal	18(%ebx), %eax
	fstps	-196(%ebp,%eax,4)
	.loc 1 361 0
	movl	-16(%ebp), %ebx
	movl	-16(%ebp), %edx
	movl	8(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC29
	fmulp	%st, %st(1)
	movl	-16(%ebp), %edx
	movl	20(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC21
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-16(%ebp), %edx
	movl	12(%ebp), %eax
	flds	(%eax,%edx,4)
	movl	-16(%ebp), %edx
	movl	24(%ebp), %eax
	flds	(%eax,%edx,4)
	faddp	%st, %st(1)
	flds	.LC30
	fmulp	%st, %st(1)
	movl	-16(%ebp), %edx
	movl	16(%ebp), %eax
	flds	(%eax,%edx,4)
	movl	-16(%ebp), %edx
	movl	28(%ebp), %eax
	flds	(%eax,%edx,4)
	fsubrp	%st, %st(1)
	fmuls	32(%ebp)
	faddp	%st, %st(1)
	fmuls	32(%ebp)
	faddp	%st, %st(1)
	flds	.LC33
	fmulp	%st, %st(1)
	fstpl	-256(%ebp)
	flds	32(%ebp)
	fldl	.LC31
	fstpl	8(%esp)
	fstpl	(%esp)
	call	pow
	fadd	%st(0), %st
	fdivrl	-256(%ebp)
	fstps	-204(%ebp)
	flds	-204(%ebp)
	leal	24(%ebx), %eax
	fstps	-196(%ebp,%eax,4)
	.loc 1 356 0
	addl	$1, -16(%ebp)
.L68:
	cmpl	$4, -16(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L69
	.loc 1 363 0
	movl	$0, -12(%ebp)
	jmp	.L70
.L74:
.LBB23:
	.loc 1 364 0
	fildl	-12(%ebp)
	fmuls	32(%ebp)
	fildl	-20(%ebp)
	fdivrp	%st, %st(1)
	fstps	-24(%ebp)
	.loc 1 365 0
	movl	$0, -16(%ebp)
	jmp	.L71
.L73:
	.loc 1 366 0
	movl	-16(%ebp), %ebx
	movl	-16(%ebp), %eax
	addl	$24, %eax
	flds	-196(%ebp,%eax,4)
	fstpl	-248(%ebp)
	flds	-24(%ebp)
	fldl	.LC28
	fstpl	8(%esp)
	fstpl	(%esp)
	call	pow
	fldl	-248(%ebp)
	fmulp	%st, %st(1)
	fstpl	-240(%ebp)
	movl	-16(%ebp), %eax
	addl	$18, %eax
	flds	-196(%ebp,%eax,4)
	fstpl	-232(%ebp)
	flds	-24(%ebp)
	fldl	.LC23
	fstpl	8(%esp)
	fstpl	(%esp)
	call	pow
	fmull	-232(%ebp)
	fldl	-240(%ebp)
	faddp	%st, %st(1)
	fstpl	-224(%ebp)
	movl	-16(%ebp), %eax
	addl	$12, %eax
	flds	-196(%ebp,%eax,4)
	fstpl	-216(%ebp)
	flds	-24(%ebp)
	fldl	.LC32
	fstpl	8(%esp)
	fstpl	(%esp)
	call	pow
	fmull	-216(%ebp)
	fldl	-224(%ebp)
	faddp	%st, %st(1)
	movl	-16(%ebp), %eax
	addl	$6, %eax
	flds	-196(%ebp,%eax,4)
	fmuls	-24(%ebp)
	faddp	%st, %st(1)
	movl	-16(%ebp), %eax
	flds	-196(%ebp,%eax,4)
	faddp	%st, %st(1)
	fabs
	fstps	-204(%ebp)
	flds	-204(%ebp)
	fstps	-52(%ebp,%ebx,4)
	.loc 1 367 0
	movl	-16(%ebp), %eax
	flds	-52(%ebp,%eax,4)
	movl	-16(%ebp), %eax
	flds	-76(%ebp,%eax,4)
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	seta	%al
	testb	%al, %al
	je	.L72
	movl	-16(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	-52(%ebp,%edx,4), %edx
	movl	%edx, -76(%ebp,%eax,4)
.L72:
	.loc 1 365 0
	addl	$1, -16(%ebp)
.L71:
	cmpl	$4, -16(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L73
.LBE23:
	.loc 1 363 0
	addl	$1, -12(%ebp)
.L70:
	movl	-20(%ebp), %eax
	addl	$1, %eax
	cmpl	-12(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L74
	.loc 1 370 0
	movl	$0x00000000, %eax
	movl	%eax, -28(%ebp)
	.loc 1 371 0
	movl	$0, -16(%ebp)
	jmp	.L75
.L77:
	.loc 1 372 0
	movl	-16(%ebp), %eax
	movl	-16(%ebp), %edx
	flds	-76(%ebp,%edx,4)
	movl	-16(%ebp), %ecx
	movl	36(%ebp), %edx
	flds	(%edx,%ecx,4)
	fdivrp	%st, %st(1)
	fstps	-52(%ebp,%eax,4)
	.loc 1 373 0
	movl	-16(%ebp), %eax
	flds	-52(%ebp,%eax,4)
	flds	-28(%ebp)
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	seta	%al
	testb	%al, %al
	je	.L76
	movl	-16(%ebp), %eax
	movl	-52(%ebp,%eax,4), %eax
	movl	%eax, -28(%ebp)
.L76:
	.loc 1 371 0
	addl	$1, -16(%ebp)
.L75:
	cmpl	$4, -16(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L77
	.loc 1 375 0
	movl	-28(%ebp), %eax
	movl	%eax, -284(%ebp)
	flds	-284(%ebp)
.LBE22:
	.loc 1 376 0
	addl	$308, %esp
	popl	%ebx
	popl	%ebp
	ret
	.cfi_endproc
.LFE23:
	.size	blendquinticmaxvel, .-blendquinticmaxvel
.globl blendquinticmaxacc
	.type	blendquinticmaxacc, @function
blendquinticmaxacc:
.LFB24:
	.loc 1 379 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI30:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI31:
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$276, %esp
	call	mcount
	.loc 1 379 0
.LBB24:
	.loc 1 381 0
	movl	$60, -20(%ebp)
	.loc 1 382 0
	movl	$60, -24(%ebp)
	.loc 1 385 0
	leal	-88(%ebp), %edx
	movl	$0, %ecx
	movl	$24, %eax
	movl	%eax, %ebx
	.cfi_offset 3, -12
	andl	$-4, %ebx
	movl	$0, %eax
.L80:
	movl	%ecx, (%edx,%eax)
	addl	$4, %eax
	cmpl	%ebx, %eax
	jb	.L80
	addl	%eax, %edx
	.loc 1 387 0
	leal	-112(%ebp), %edx
	movl	$0, %ecx
	movl	$24, %eax
	movl	%eax, %ebx
	andl	$-4, %ebx
	movl	$0, %eax
.L82:
	movl	%ecx, (%edx,%eax)
	addl	$4, %eax
	cmpl	%ebx, %eax
	jb	.L82
	addl	%eax, %edx
	.loc 1 388 0
	movl	$0, -16(%ebp)
	jmp	.L84
.L85:
	.loc 1 389 0
	movl	-16(%ebp), %eax
	movl	-16(%ebp), %ecx
	movl	16(%ebp), %edx
	movl	(%edx,%ecx,4), %edx
	movl	%edx, -208(%ebp,%eax,4)
	.loc 1 390 0
	movl	-16(%ebp), %ebx
	movl	-16(%ebp), %edx
	movl	8(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC19
	fmulp	%st, %st(1)
	movl	-16(%ebp), %edx
	movl	20(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC20
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-16(%ebp), %edx
	movl	12(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC21
	fmulp	%st, %st(1)
	movl	-16(%ebp), %edx
	movl	24(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC22
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	flds	32(%ebp)
	flds	.LC9
	fmulp	%st, %st(1)
	movl	-16(%ebp), %edx
	movl	16(%ebp), %eax
	flds	(%eax,%edx,4)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-16(%ebp), %edx
	movl	28(%ebp), %eax
	flds	(%eax,%edx,4)
	fmuls	32(%ebp)
	faddp	%st, %st(1)
	fmuls	32(%ebp)
	faddp	%st, %st(1)
	flds	.LC15
	fmulp	%st, %st(1)
	fstpl	-248(%ebp)
	flds	32(%ebp)
	fldl	.LC23
	fstpl	8(%esp)
	fstpl	(%esp)
	call	pow
	fdivrl	-248(%ebp)
	fstps	-220(%ebp)
	flds	-220(%ebp)
	leal	6(%ebx), %eax
	fstps	-208(%ebp,%eax,4)
	.loc 1 391 0
	movl	-16(%ebp), %ebx
	movl	-16(%ebp), %edx
	movl	8(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC24
	fmulp	%st, %st(1)
	movl	-16(%ebp), %edx
	movl	20(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC25
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-16(%ebp), %edx
	movl	12(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC26
	fmulp	%st, %st(1)
	movl	-16(%ebp), %edx
	movl	24(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC27
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	flds	32(%ebp)
	flds	.LC15
	fmulp	%st, %st(1)
	movl	-16(%ebp), %edx
	movl	16(%ebp), %eax
	flds	(%eax,%edx,4)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	flds	32(%ebp)
	flds	.LC16
	fmulp	%st, %st(1)
	movl	-16(%ebp), %edx
	movl	28(%ebp), %eax
	flds	(%eax,%edx,4)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fmuls	32(%ebp)
	faddp	%st, %st(1)
	flds	.LC30
	fmulp	%st, %st(1)
	fstpl	-240(%ebp)
	flds	32(%ebp)
	fldl	.LC28
	fstpl	8(%esp)
	fstpl	(%esp)
	call	pow
	fdivrl	-240(%ebp)
	fstps	-220(%ebp)
	flds	-220(%ebp)
	leal	12(%ebx), %eax
	fstps	-208(%ebp,%eax,4)
	.loc 1 392 0
	movl	-16(%ebp), %ebx
	movl	-16(%ebp), %edx
	movl	8(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC29
	fmulp	%st, %st(1)
	movl	-16(%ebp), %edx
	movl	20(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC21
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-16(%ebp), %edx
	movl	12(%ebp), %eax
	flds	(%eax,%edx,4)
	movl	-16(%ebp), %edx
	movl	24(%ebp), %eax
	flds	(%eax,%edx,4)
	faddp	%st, %st(1)
	flds	.LC30
	fmulp	%st, %st(1)
	movl	-16(%ebp), %edx
	movl	16(%ebp), %eax
	flds	(%eax,%edx,4)
	movl	-16(%ebp), %edx
	movl	28(%ebp), %eax
	flds	(%eax,%edx,4)
	fsubrp	%st, %st(1)
	fmuls	32(%ebp)
	faddp	%st, %st(1)
	fmuls	32(%ebp)
	faddp	%st, %st(1)
	flds	.LC34
	fmulp	%st, %st(1)
	fstpl	-232(%ebp)
	flds	32(%ebp)
	fldl	.LC31
	fstpl	8(%esp)
	fstpl	(%esp)
	call	pow
	fdivrl	-232(%ebp)
	fstps	-220(%ebp)
	flds	-220(%ebp)
	leal	18(%ebx), %eax
	fstps	-208(%ebp,%eax,4)
	.loc 1 388 0
	addl	$1, -16(%ebp)
.L84:
	cmpl	$4, -16(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L85
	.loc 1 394 0
	fildl	-20(%ebp)
	flds	32(%ebp)
	fdivp	%st, %st(1)
	fstps	-28(%ebp)
	.loc 1 395 0
	movl	$0, -12(%ebp)
	jmp	.L86
.L90:
.LBB25:
	.loc 1 396 0
	fildl	-12(%ebp)
	fmuls	-28(%ebp)
	fstps	-32(%ebp)
	.loc 1 397 0
	movl	$0, -16(%ebp)
	jmp	.L87
.L89:
	.loc 1 398 0
	movl	-16(%ebp), %eax
	movl	-16(%ebp), %edx
	addl	$18, %edx
	flds	-208(%ebp,%edx,4)
	fmuls	-32(%ebp)
	fmuls	-32(%ebp)
	fmuls	-32(%ebp)
	movl	-16(%ebp), %edx
	addl	$12, %edx
	flds	-208(%ebp,%edx,4)
	fmuls	-32(%ebp)
	fmuls	-32(%ebp)
	faddp	%st, %st(1)
	movl	-16(%ebp), %edx
	addl	$6, %edx
	flds	-208(%ebp,%edx,4)
	fmuls	-32(%ebp)
	faddp	%st, %st(1)
	movl	-16(%ebp), %edx
	flds	-208(%ebp,%edx,4)
	faddp	%st, %st(1)
	fabs
	fstps	-64(%ebp,%eax,4)
	.loc 1 399 0
	movl	-16(%ebp), %eax
	flds	-64(%ebp,%eax,4)
	movl	-16(%ebp), %eax
	flds	-88(%ebp,%eax,4)
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	seta	%al
	testb	%al, %al
	je	.L88
	.loc 1 400 0
	movl	-16(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	-64(%ebp,%edx,4), %edx
	movl	%edx, -88(%ebp,%eax,4)
	.loc 1 401 0
	movl	-16(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, -112(%ebp,%eax,4)
.L88:
	.loc 1 397 0
	addl	$1, -16(%ebp)
.L87:
	cmpl	$4, -16(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L89
.LBE25:
	.loc 1 395 0
	addl	$1, -12(%ebp)
.L86:
	movl	-20(%ebp), %eax
	addl	$1, %eax
	cmpl	-12(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L90
	.loc 1 405 0
	movl	$0, -16(%ebp)
	jmp	.L91
.L96:
	.loc 1 408 0
	movl	-16(%ebp), %eax
	flds	-112(%ebp,%eax,4)
	fsubs	-28(%ebp)
	fldz
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	seta	%al
	testb	%al, %al
	je	.L92
	movl	-16(%ebp), %eax
	flds	-112(%ebp,%eax,4)
	fadds	-28(%ebp)
	flds	32(%ebp)
	fucompp
	fnstsw	%ax
	testb	$69, %ah
	sete	%al
	testb	%al, %al
	je	.L92
	.loc 1 409 0
	movl	$0, -12(%ebp)
	jmp	.L93
.L95:
.LBB26:
	.loc 1 410 0
	movl	-16(%ebp), %eax
	flds	-112(%ebp,%eax,4)
	fsubs	-28(%ebp)
	flds	-28(%ebp)
	fld	%st(0)
	faddp	%st, %st(1)
	fildl	-12(%ebp)
	fmulp	%st, %st(1)
	fildl	-24(%ebp)
	fdivrp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-36(%ebp)
	.loc 1 411 0
	movl	-16(%ebp), %eax
	movl	-16(%ebp), %edx
	addl	$18, %edx
	flds	-208(%ebp,%edx,4)
	fmuls	-36(%ebp)
	fmuls	-36(%ebp)
	fmuls	-36(%ebp)
	movl	-16(%ebp), %edx
	addl	$12, %edx
	flds	-208(%ebp,%edx,4)
	fmuls	-36(%ebp)
	fmuls	-36(%ebp)
	faddp	%st, %st(1)
	movl	-16(%ebp), %edx
	addl	$6, %edx
	flds	-208(%ebp,%edx,4)
	fmuls	-36(%ebp)
	faddp	%st, %st(1)
	movl	-16(%ebp), %edx
	flds	-208(%ebp,%edx,4)
	faddp	%st, %st(1)
	fabs
	fstps	-64(%ebp,%eax,4)
	.loc 1 412 0
	movl	-16(%ebp), %eax
	flds	-64(%ebp,%eax,4)
	movl	-16(%ebp), %eax
	flds	-88(%ebp,%eax,4)
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	seta	%al
	testb	%al, %al
	je	.L94
	.loc 1 413 0
	movl	-16(%ebp), %eax
	movl	-16(%ebp), %edx
	movl	-64(%ebp,%edx,4), %edx
	movl	%edx, -88(%ebp,%eax,4)
.L94:
.LBE26:
	.loc 1 409 0
	addl	$1, -12(%ebp)
.L93:
	movl	-24(%ebp), %eax
	addl	$1, %eax
	cmpl	-12(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L95
.L92:
	.loc 1 405 0
	addl	$1, -16(%ebp)
.L91:
	cmpl	$4, -16(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L96
	.loc 1 422 0
	movl	$0x00000000, %eax
	movl	%eax, -40(%ebp)
	.loc 1 423 0
	movl	$0, -16(%ebp)
	jmp	.L97
.L99:
	.loc 1 425 0
	movl	-16(%ebp), %eax
	movl	-16(%ebp), %edx
	flds	-88(%ebp,%edx,4)
	movl	-16(%ebp), %ecx
	movl	36(%ebp), %edx
	flds	(%edx,%ecx,4)
	fdivrp	%st, %st(1)
	fstps	-64(%ebp,%eax,4)
	.loc 1 426 0
	movl	-16(%ebp), %eax
	flds	-64(%ebp,%eax,4)
	flds	-40(%ebp)
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	seta	%al
	testb	%al, %al
	je	.L98
	movl	-16(%ebp), %eax
	movl	-64(%ebp,%eax,4), %eax
	movl	%eax, -40(%ebp)
.L98:
	.loc 1 423 0
	addl	$1, -16(%ebp)
.L97:
	cmpl	$4, -16(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L99
	.loc 1 428 0
	movl	-40(%ebp), %eax
	movl	%eax, -252(%ebp)
	flds	-252(%ebp)
.LBE24:
	.loc 1 429 0
	addl	$276, %esp
	popl	%ebx
	popl	%ebp
	ret
	.cfi_endproc
.LFE24:
	.size	blendquinticmaxacc, .-blendquinticmaxacc
.globl blendcubic
	.type	blendcubic, @function
blendcubic:
.LFB25:
	.loc 1 438 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI32:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI33:
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$204, %esp
	call	mcount
	.loc 1 438 0
.LBB27:
	.loc 1 442 0
	movl	$0, -32(%ebp)
	jmp	.L102
	.cfi_offset 3, -20
	.cfi_offset 6, -16
	.cfi_offset 7, -12
.L103:
	.loc 1 443 0
	movl	-32(%ebp), %eax
	movl	-32(%ebp), %ecx
	movl	16(%ebp), %edx
	movl	(%edx,%ecx,4), %edx
	movl	%edx, -164(%ebp,%eax,4)
	.loc 1 444 0
	movl	-32(%ebp), %ecx
	movl	-32(%ebp), %edx
	movl	20(%ebp), %eax
	movl	(%eax,%edx,4), %eax
	leal	6(%ecx), %edx
	movl	%eax, -164(%ebp,%edx,4)
	.loc 1 445 0
	movl	-32(%ebp), %ecx
	movl	-32(%ebp), %edx
	movl	16(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC15
	fmulp	%st, %st(1)
	movl	-32(%ebp), %edx
	movl	24(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC9
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-32(%ebp), %edx
	movl	20(%ebp), %eax
	flds	(%eax,%edx,4)
	fadd	%st(0), %st
	fmuls	32(%ebp)
	faddp	%st, %st(1)
	movl	-32(%ebp), %edx
	movl	28(%ebp), %eax
	flds	(%eax,%edx,4)
	fmuls	32(%ebp)
	faddp	%st, %st(1)
	fchs
	flds	32(%ebp)
	fmuls	32(%ebp)
	fdivrp	%st, %st(1)
	fstps	-172(%ebp)
	flds	-172(%ebp)
	leal	12(%ecx), %eax
	fstps	-164(%ebp,%eax,4)
	.loc 1 446 0
	movl	-32(%ebp), %ecx
	movl	-32(%ebp), %edx
	movl	20(%ebp), %eax
	flds	(%eax,%edx,4)
	fchs
	fmuls	32(%ebp)
	movl	-32(%ebp), %edx
	movl	28(%ebp), %eax
	flds	(%eax,%edx,4)
	fmuls	32(%ebp)
	fsubrp	%st, %st(1)
	movl	-32(%ebp), %edx
	movl	16(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC16
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-32(%ebp), %edx
	movl	24(%ebp), %eax
	flds	(%eax,%edx,4)
	fadd	%st(0), %st
	faddp	%st, %st(1)
	fchs
	flds	32(%ebp)
	fmuls	32(%ebp)
	fmuls	32(%ebp)
	fdivrp	%st, %st(1)
	fstps	-172(%ebp)
	flds	-172(%ebp)
	leal	18(%ecx), %eax
	fstps	-164(%ebp,%eax,4)
	.loc 1 442 0
	addl	$1, -32(%ebp)
.L102:
	cmpl	$4, -32(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L103
	.loc 1 448 0
	movl	$0, -28(%ebp)
	jmp	.L104
.L109:
.LBB28:
	.loc 1 449 0
	fildl	-28(%ebp)
	fmuls	32(%ebp)
	fildl	36(%ebp)
	fdivrp	%st, %st(1)
	fstps	-36(%ebp)
	.loc 1 451 0
	movl	-28(%ebp), %eax
	cmpl	36(%ebp), %eax
	jne	.L105
	.loc 1 452 0
	cmpl	$0, 52(%ebp)
	je	.L111
.L105:
	.loc 1 454 0
	flds	-36(%ebp)
	fmuls	-36(%ebp)
	fstps	-40(%ebp)
	.loc 1 455 0
	flds	-40(%ebp)
	fmuls	-36(%ebp)
	fstps	-44(%ebp)
	.loc 1 456 0
	movl	$0, -32(%ebp)
	jmp	.L107
.L108:
	.loc 1 457 0
	movl	-32(%ebp), %eax
	movl	-32(%ebp), %edx
	addl	$18, %edx
	flds	-164(%ebp,%edx,4)
	fmuls	-44(%ebp)
	movl	-32(%ebp), %edx
	addl	$12, %edx
	flds	-164(%ebp,%edx,4)
	fmuls	-40(%ebp)
	faddp	%st, %st(1)
	movl	-32(%ebp), %edx
	addl	$6, %edx
	flds	-164(%ebp,%edx,4)
	fmuls	-36(%ebp)
	faddp	%st, %st(1)
	movl	-32(%ebp), %edx
	flds	-164(%ebp,%edx,4)
	faddp	%st, %st(1)
	fstps	-68(%ebp,%eax,4)
	.loc 1 456 0
	addl	$1, -32(%ebp)
.L107:
	cmpl	$4, -32(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L108
	.loc 1 459 0
	movl	-52(%ebp), %esi
	movl	-56(%ebp), %ebx
	movl	-60(%ebp), %ecx
	movl	-64(%ebp), %edx
	movl	-68(%ebp), %eax
	movl	40(%ebp), %edi
	movl	%edi, 28(%esp)
	movl	$0x00000000, %edi
	movl	%edi, 24(%esp)
	movl	%esi, 20(%esp)
	movl	%ebx, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	44(%ebp), %eax
	movl	%eax, (%esp)
	call	tmpnComputeFKlogic
	.loc 1 460 0
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	44(%ebp), %eax
	movl	1316(%eax), %ecx
	movl	8(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$320, %eax
	movl	%ecx, (%eax)
	.loc 1 461 0
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	44(%ebp), %eax
	movl	1320(%eax), %ecx
	movl	8(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$324, %eax
	movl	%ecx, (%eax)
	.loc 1 462 0
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	44(%ebp), %eax
	movl	1324(%eax), %ecx
	movl	8(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$328, %eax
	movl	%ecx, (%eax)
	.loc 1 463 0
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	44(%ebp), %eax
	movl	1328(%eax), %ecx
	movl	8(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$332, %eax
	movl	%ecx, (%eax)
	.loc 1 464 0
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	44(%ebp), %eax
	movl	1332(%eax), %ecx
	movl	8(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$336, %eax
	movl	%ecx, (%eax)
	.loc 1 465 0
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	44(%ebp), %eax
	movl	1336(%eax), %ecx
	movl	8(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$340, %eax
	movl	%ecx, (%eax)
	.loc 1 466 0
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	leal	308(%eax), %edx
	movl	40(%ebp), %eax
	movl	%eax, (%edx)
	.loc 1 467 0
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	fildl	48(%ebp)
	movl	8(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	addl	$316, %eax
	fstps	(%eax)
	.loc 1 468 0
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	addl	$312, %eax
	movl	$0, (%eax)
	.loc 1 469 0
	movl	12(%ebp), %eax
	movl	(%eax), %edx
	movl	8(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	leal	344(%eax), %edx
	movl	$0x41200000, %eax
	movl	%eax, (%edx)
	.loc 1 470 0
	movl	12(%ebp), %eax
	movl	(%eax), %eax
	leal	1(%eax), %edx
	movl	12(%ebp), %eax
	movl	%edx, (%eax)
.LBE28:
	.loc 1 448 0
	addl	$1, -28(%ebp)
.L104:
	movl	36(%ebp), %eax
	addl	$1, %eax
	cmpl	-28(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L109
	jmp	.L110
.L111:
.LBB29:
	.loc 1 452 0
	nop
.L110:
.LBE29:
.LBE27:
	.loc 1 472 0
	addl	$204, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.cfi_endproc
.LFE25:
	.size	blendcubic, .-blendcubic
.globl blendcubicmaxvel
	.type	blendcubicmaxvel, @function
blendcubicmaxvel:
.LFB26:
	.loc 1 476 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI34:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI35:
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$228, %esp
	call	mcount
	.loc 1 476 0
.LBB30:
	.loc 1 480 0
	leal	-72(%ebp), %edx
	movl	$0, %ecx
	movl	$24, %eax
	movl	%eax, %ebx
	.cfi_offset 3, -12
	andl	$-4, %ebx
	movl	$0, %eax
.L113:
	movl	%ecx, (%edx,%eax)
	addl	$4, %eax
	cmpl	%ebx, %eax
	jb	.L113
	addl	%eax, %edx
	.loc 1 481 0
	movl	$0, -12(%ebp)
	jmp	.L115
.L116:
	.loc 1 483 0
	movl	-12(%ebp), %ecx
	movl	-12(%ebp), %edx
	movl	12(%ebp), %eax
	movl	(%eax,%edx,4), %eax
	leal	6(%ecx), %edx
	movl	%eax, -168(%ebp,%edx,4)
	.loc 1 484 0
	movl	-12(%ebp), %ecx
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC15
	fmulp	%st, %st(1)
	movl	-12(%ebp), %edx
	movl	16(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC9
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-12(%ebp), %edx
	movl	12(%ebp), %eax
	flds	(%eax,%edx,4)
	fadd	%st(0), %st
	fmuls	24(%ebp)
	faddp	%st, %st(1)
	movl	-12(%ebp), %edx
	movl	20(%ebp), %eax
	flds	(%eax,%edx,4)
	fmuls	24(%ebp)
	faddp	%st, %st(1)
	fchs
	flds	24(%ebp)
	fmuls	24(%ebp)
	fdivrp	%st, %st(1)
	fstps	-172(%ebp)
	flds	-172(%ebp)
	leal	12(%ecx), %eax
	fstps	-168(%ebp,%eax,4)
	.loc 1 485 0
	movl	-12(%ebp), %ecx
	movl	-12(%ebp), %edx
	movl	12(%ebp), %eax
	flds	(%eax,%edx,4)
	fchs
	fmuls	24(%ebp)
	movl	-12(%ebp), %edx
	movl	20(%ebp), %eax
	flds	(%eax,%edx,4)
	fmuls	24(%ebp)
	fsubrp	%st, %st(1)
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC16
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-12(%ebp), %edx
	movl	16(%ebp), %eax
	flds	(%eax,%edx,4)
	fadd	%st(0), %st
	faddp	%st, %st(1)
	fchs
	flds	24(%ebp)
	fmuls	24(%ebp)
	fmuls	24(%ebp)
	fdivrp	%st, %st(1)
	fstps	-172(%ebp)
	flds	-172(%ebp)
	leal	18(%ecx), %eax
	fstps	-168(%ebp,%eax,4)
	.loc 1 481 0
	addl	$1, -12(%ebp)
.L115:
	cmpl	$4, -12(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L116
	.loc 1 488 0
	movl	$0x00000000, %eax
	movl	%eax, -16(%ebp)
	.loc 1 489 0
	movl	$0, -12(%ebp)
	jmp	.L117
.L119:
	.loc 1 490 0
	movl	-12(%ebp), %ebx
	movl	-12(%ebp), %eax
	addl	$18, %eax
	flds	-168(%ebp,%eax,4)
	flds	.LC15
	fmulp	%st, %st(1)
	fstpl	-200(%ebp)
	flds	-16(%ebp)
	fldl	.LC32
	fstpl	8(%esp)
	fstpl	(%esp)
	call	pow
	fldl	-200(%ebp)
	fmulp	%st, %st(1)
	movl	-12(%ebp), %eax
	addl	$12, %eax
	flds	-168(%ebp,%eax,4)
	fadd	%st(0), %st
	fmuls	-16(%ebp)
	faddp	%st, %st(1)
	movl	-12(%ebp), %eax
	addl	$6, %eax
	flds	-168(%ebp,%eax,4)
	faddp	%st, %st(1)
	fabs
	fstps	-172(%ebp)
	flds	-172(%ebp)
	fstps	-48(%ebp,%ebx,4)
	.loc 1 491 0
	movl	-12(%ebp), %eax
	flds	-48(%ebp,%eax,4)
	movl	-12(%ebp), %eax
	flds	-72(%ebp,%eax,4)
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	seta	%al
	testb	%al, %al
	je	.L118
	movl	-12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	-48(%ebp,%edx,4), %edx
	movl	%edx, -72(%ebp,%eax,4)
.L118:
	.loc 1 489 0
	addl	$1, -12(%ebp)
.L117:
	cmpl	$4, -12(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L119
	.loc 1 493 0
	movl	24(%ebp), %eax
	movl	%eax, -16(%ebp)
	.loc 1 494 0
	movl	$0, -12(%ebp)
	jmp	.L120
.L122:
	.loc 1 495 0
	movl	-12(%ebp), %ebx
	movl	-12(%ebp), %eax
	addl	$18, %eax
	flds	-168(%ebp,%eax,4)
	flds	.LC15
	fmulp	%st, %st(1)
	fstpl	-192(%ebp)
	flds	-16(%ebp)
	fldl	.LC32
	fstpl	8(%esp)
	fstpl	(%esp)
	call	pow
	fldl	-192(%ebp)
	fmulp	%st, %st(1)
	movl	-12(%ebp), %eax
	addl	$12, %eax
	flds	-168(%ebp,%eax,4)
	fadd	%st(0), %st
	fmuls	-16(%ebp)
	faddp	%st, %st(1)
	movl	-12(%ebp), %eax
	addl	$6, %eax
	flds	-168(%ebp,%eax,4)
	faddp	%st, %st(1)
	fabs
	fstps	-172(%ebp)
	flds	-172(%ebp)
	fstps	-48(%ebp,%ebx,4)
	.loc 1 496 0
	movl	-12(%ebp), %eax
	flds	-48(%ebp,%eax,4)
	movl	-12(%ebp), %eax
	flds	-72(%ebp,%eax,4)
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	seta	%al
	testb	%al, %al
	je	.L121
	movl	-12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	-48(%ebp,%edx,4), %edx
	movl	%edx, -72(%ebp,%eax,4)
.L121:
	.loc 1 494 0
	addl	$1, -12(%ebp)
.L120:
	cmpl	$4, -12(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L122
	.loc 1 498 0
	movl	$0, -12(%ebp)
	jmp	.L123
.L125:
.LBB31:
	.loc 1 500 0
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC15
	fmulp	%st, %st(1)
	movl	-12(%ebp), %edx
	movl	16(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC9
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-12(%ebp), %edx
	movl	12(%ebp), %eax
	flds	(%eax,%edx,4)
	fadd	%st(0), %st
	fmuls	24(%ebp)
	faddp	%st, %st(1)
	movl	-12(%ebp), %edx
	movl	20(%ebp), %eax
	flds	(%eax,%edx,4)
	fmuls	24(%ebp)
	faddp	%st, %st(1)
	fmuls	24(%ebp)
	movl	-12(%ebp), %edx
	movl	8(%ebp), %eax
	flds	(%eax,%edx,4)
	fld	%st(0)
	faddp	%st, %st(1)
	movl	-12(%ebp), %edx
	movl	16(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC16
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-12(%ebp), %edx
	movl	12(%ebp), %eax
	flds	(%eax,%edx,4)
	fmuls	24(%ebp)
	faddp	%st, %st(1)
	movl	-12(%ebp), %edx
	movl	20(%ebp), %eax
	flds	(%eax,%edx,4)
	fmuls	24(%ebp)
	faddp	%st, %st(1)
	flds	.LC15
	fmulp	%st, %st(1)
	fdivrp	%st, %st(1)
	fstps	-20(%ebp)
	.loc 1 501 0
	flds	-20(%ebp)
	fldz
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	setae	%al
	testb	%al, %al
	je	.L124
	flds	-20(%ebp)
	flds	24(%ebp)
	fucompp
	fnstsw	%ax
	testb	$5, %ah
	sete	%al
	testb	%al, %al
	je	.L124
	.loc 1 502 0
	movl	-12(%ebp), %ebx
	movl	-12(%ebp), %eax
	addl	$18, %eax
	flds	-168(%ebp,%eax,4)
	flds	.LC15
	fmulp	%st, %st(1)
	fstpl	-184(%ebp)
	flds	-20(%ebp)
	fldl	.LC32
	fstpl	8(%esp)
	fstpl	(%esp)
	call	pow
	fldl	-184(%ebp)
	fmulp	%st, %st(1)
	movl	-12(%ebp), %eax
	addl	$12, %eax
	flds	-168(%ebp,%eax,4)
	fadd	%st(0), %st
	fmuls	-20(%ebp)
	faddp	%st, %st(1)
	movl	-12(%ebp), %eax
	addl	$6, %eax
	flds	-168(%ebp,%eax,4)
	faddp	%st, %st(1)
	fabs
	fstps	-172(%ebp)
	flds	-172(%ebp)
	fstps	-48(%ebp,%ebx,4)
	.loc 1 503 0
	movl	-12(%ebp), %eax
	flds	-48(%ebp,%eax,4)
	movl	-12(%ebp), %eax
	flds	-72(%ebp,%eax,4)
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	seta	%al
	testb	%al, %al
	je	.L124
	movl	-12(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	-48(%ebp,%edx,4), %edx
	movl	%edx, -72(%ebp,%eax,4)
.L124:
.LBE31:
	.loc 1 498 0
	addl	$1, -12(%ebp)
.L123:
	cmpl	$4, -12(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L125
	.loc 1 507 0
	movl	$0x00000000, %eax
	movl	%eax, -24(%ebp)
	.loc 1 508 0
	movl	$0, -12(%ebp)
	jmp	.L126
.L128:
	.loc 1 509 0
	movl	-12(%ebp), %eax
	movl	-12(%ebp), %edx
	flds	-72(%ebp,%edx,4)
	movl	-12(%ebp), %ecx
	movl	28(%ebp), %edx
	flds	(%edx,%ecx,4)
	fdivrp	%st, %st(1)
	fstps	-48(%ebp,%eax,4)
	.loc 1 510 0
	movl	-12(%ebp), %eax
	flds	-48(%ebp,%eax,4)
	flds	-24(%ebp)
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	seta	%al
	testb	%al, %al
	je	.L127
	movl	-12(%ebp), %eax
	movl	-48(%ebp,%eax,4), %eax
	movl	%eax, -24(%ebp)
.L127:
	.loc 1 508 0
	addl	$1, -12(%ebp)
.L126:
	cmpl	$4, -12(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L128
	.loc 1 513 0
	movl	-24(%ebp), %eax
	movl	%eax, -204(%ebp)
	flds	-204(%ebp)
.LBE30:
	.loc 1 514 0
	addl	$228, %esp
	popl	%ebx
	popl	%ebp
	ret
	.cfi_endproc
.LFE26:
	.size	blendcubicmaxvel, .-blendcubicmaxvel
.globl blendcubicmaxacc
	.type	blendcubicmaxacc, @function
blendcubicmaxacc:
.LFB27:
	.loc 1 517 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI36:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI37:
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$168, %esp
	call	mcount
	.loc 1 517 0
.LBB32:
	.loc 1 521 0
	leal	-64(%ebp), %edx
	movl	$0, %ecx
	movl	$24, %eax
	movl	%eax, %ebx
	.cfi_offset 3, -12
	andl	$-4, %ebx
	movl	$0, %eax
.L131:
	movl	%ecx, (%edx,%eax)
	addl	$4, %eax
	cmpl	%ebx, %eax
	jb	.L131
	addl	%eax, %edx
	.loc 1 522 0
	movl	$0, -8(%ebp)
	jmp	.L133
.L134:
	.loc 1 525 0
	movl	-8(%ebp), %ecx
	movl	-8(%ebp), %edx
	movl	8(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC15
	fmulp	%st, %st(1)
	movl	-8(%ebp), %edx
	movl	16(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC9
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-8(%ebp), %edx
	movl	12(%ebp), %eax
	flds	(%eax,%edx,4)
	fadd	%st(0), %st
	fmuls	24(%ebp)
	faddp	%st, %st(1)
	movl	-8(%ebp), %edx
	movl	20(%ebp), %eax
	flds	(%eax,%edx,4)
	fmuls	24(%ebp)
	faddp	%st, %st(1)
	fchs
	flds	24(%ebp)
	fmuls	24(%ebp)
	fdivrp	%st, %st(1)
	fstps	-168(%ebp)
	flds	-168(%ebp)
	leal	12(%ecx), %eax
	fstps	-160(%ebp,%eax,4)
	.loc 1 526 0
	movl	-8(%ebp), %ecx
	movl	-8(%ebp), %edx
	movl	12(%ebp), %eax
	flds	(%eax,%edx,4)
	fchs
	fmuls	24(%ebp)
	movl	-8(%ebp), %edx
	movl	20(%ebp), %eax
	flds	(%eax,%edx,4)
	fmuls	24(%ebp)
	fsubrp	%st, %st(1)
	movl	-8(%ebp), %edx
	movl	8(%ebp), %eax
	flds	(%eax,%edx,4)
	flds	.LC16
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-8(%ebp), %edx
	movl	16(%ebp), %eax
	flds	(%eax,%edx,4)
	fadd	%st(0), %st
	faddp	%st, %st(1)
	fchs
	flds	24(%ebp)
	fmuls	24(%ebp)
	fmuls	24(%ebp)
	fdivrp	%st, %st(1)
	fstps	-168(%ebp)
	flds	-168(%ebp)
	leal	18(%ecx), %eax
	fstps	-160(%ebp,%eax,4)
	.loc 1 522 0
	addl	$1, -8(%ebp)
.L133:
	cmpl	$4, -8(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L134
	.loc 1 530 0
	movl	$0x00000000, %eax
	movl	%eax, -12(%ebp)
	.loc 1 531 0
	movl	$0, -8(%ebp)
	jmp	.L135
.L137:
	.loc 1 532 0
	movl	-8(%ebp), %eax
	movl	-8(%ebp), %edx
	addl	$18, %edx
	flds	-160(%ebp,%edx,4)
	flds	.LC30
	fmulp	%st, %st(1)
	fmuls	-12(%ebp)
	movl	-8(%ebp), %edx
	addl	$12, %edx
	flds	-160(%ebp,%edx,4)
	fadd	%st(0), %st
	faddp	%st, %st(1)
	fabs
	fstps	-40(%ebp,%eax,4)
	.loc 1 533 0
	movl	-8(%ebp), %eax
	flds	-40(%ebp,%eax,4)
	movl	-8(%ebp), %eax
	flds	-64(%ebp,%eax,4)
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	seta	%al
	testb	%al, %al
	je	.L136
	movl	-8(%ebp), %eax
	movl	-8(%ebp), %edx
	movl	-40(%ebp,%edx,4), %edx
	movl	%edx, -64(%ebp,%eax,4)
.L136:
	.loc 1 531 0
	addl	$1, -8(%ebp)
.L135:
	cmpl	$4, -8(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L137
	.loc 1 535 0
	movl	24(%ebp), %eax
	movl	%eax, -12(%ebp)
	.loc 1 536 0
	movl	$0, -8(%ebp)
	jmp	.L138
.L140:
	.loc 1 537 0
	movl	-8(%ebp), %eax
	movl	-8(%ebp), %edx
	addl	$18, %edx
	flds	-160(%ebp,%edx,4)
	flds	.LC30
	fmulp	%st, %st(1)
	fmuls	-12(%ebp)
	movl	-8(%ebp), %edx
	addl	$12, %edx
	flds	-160(%ebp,%edx,4)
	fadd	%st(0), %st
	faddp	%st, %st(1)
	fabs
	fstps	-40(%ebp,%eax,4)
	.loc 1 538 0
	movl	-8(%ebp), %eax
	flds	-40(%ebp,%eax,4)
	movl	-8(%ebp), %eax
	flds	-64(%ebp,%eax,4)
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	seta	%al
	testb	%al, %al
	je	.L139
	movl	-8(%ebp), %eax
	movl	-8(%ebp), %edx
	movl	-40(%ebp,%edx,4), %edx
	movl	%edx, -64(%ebp,%eax,4)
.L139:
	.loc 1 536 0
	addl	$1, -8(%ebp)
.L138:
	cmpl	$4, -8(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L140
	.loc 1 541 0
	movl	$0x00000000, %eax
	movl	%eax, -16(%ebp)
	.loc 1 542 0
	movl	$0, -8(%ebp)
	jmp	.L141
.L143:
	.loc 1 543 0
	movl	-8(%ebp), %eax
	movl	-8(%ebp), %edx
	flds	-64(%ebp,%edx,4)
	movl	-8(%ebp), %ecx
	movl	28(%ebp), %edx
	flds	(%edx,%ecx,4)
	fdivrp	%st, %st(1)
	fstps	-40(%ebp,%eax,4)
	.loc 1 544 0
	movl	-8(%ebp), %eax
	flds	-40(%ebp,%eax,4)
	flds	-16(%ebp)
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	seta	%al
	testb	%al, %al
	je	.L142
	movl	-8(%ebp), %eax
	movl	-40(%ebp,%eax,4), %eax
	movl	%eax, -16(%ebp)
.L142:
	.loc 1 542 0
	addl	$1, -8(%ebp)
.L141:
	cmpl	$4, -8(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L143
	.loc 1 547 0
	movl	-16(%ebp), %eax
	movl	%eax, -172(%ebp)
	flds	-172(%ebp)
.LBE32:
	.loc 1 548 0
	addl	$168, %esp
	popl	%ebx
	popl	%ebp
	ret
	.cfi_endproc
.LFE27:
	.size	blendcubicmaxacc, .-blendcubicmaxacc
.globl trajopt
	.type	trajopt, @function
trajopt:
.LFB28:
	.loc 1 581 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI38:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI39:
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$27212, %esp
	call	mcount
	movl	8(%ebp), %eax
	movl	%eax, -26764(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -26768(%ebp)
	movl	44(%ebp), %eax
	movl	%eax, -26772(%ebp)
	movl	48(%ebp), %eax
	movl	%eax, -26776(%ebp)
	movl	52(%ebp), %eax
	movl	%eax, -26780(%ebp)
	movl	56(%ebp), %eax
	movl	%eax, -26784(%ebp)
	movl	60(%ebp), %eax
	movl	%eax, -26788(%ebp)
	movl	64(%ebp), %eax
	movl	%eax, -26792(%ebp)
	movl	68(%ebp), %eax
	movl	%eax, -26796(%ebp)
	movl	72(%ebp), %eax
	movl	%eax, -26800(%ebp)
	movl	76(%ebp), %eax
	movl	%eax, -26804(%ebp)
	movl	80(%ebp), %eax
	movl	%eax, -26808(%ebp)
	movl	84(%ebp), %eax
	movl	%eax, -26812(%ebp)
	movl	88(%ebp), %eax
	movl	%eax, -26816(%ebp)
	.loc 1 581 0
	movl	%gs:20, %eax
	movl	%eax, -28(%ebp)
	xorl	%eax, %eax
.LBB33:
	.loc 1 583 0
	movl	$23760, 8(%esp)
	movl	-26764(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-23788(%ebp), %eax
	movl	%eax, (%esp)
	.cfi_offset 3, -20
	.cfi_offset 6, -16
	.cfi_offset 7, -12
	call	memcpy
	.loc 1 584 0
	movl	$0, -13048(%ebp)
	.loc 1 585 0
	movl	$1, -23792(%ebp)
	.loc 1 586 0
	leal	-23792(%ebp), %eax
	movl	%eax, -23796(%ebp)
	.loc 1 587 0
	movl	$0, -23800(%ebp)
	.loc 1 588 0
	movl	$0, -23804(%ebp)
	movl	$0, -23808(%ebp)
	movl	$0, -23812(%ebp)
	.loc 1 589 0
	movl	$0x00000000, %eax
	movl	%eax, -23816(%ebp)
	.loc 1 594 0
	movl	$24, 8(%esp)
	movl	-26788(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-23968(%ebp), %eax
	movl	%eax, (%esp)
	call	memcpy
	.loc 1 595 0
	movl	$24, 8(%esp)
	movl	-26780(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-23992(%ebp), %eax
	movl	%eax, (%esp)
	call	memcpy
	.loc 1 598 0
	movl	$24, 8(%esp)
	movl	-26792(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-24016(%ebp), %eax
	movl	%eax, (%esp)
	call	memcpy
	.loc 1 599 0
	movl	$24, 8(%esp)
	movl	-26784(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-24040(%ebp), %eax
	movl	%eax, (%esp)
	call	memcpy
	.loc 1 601 0
	movl	$0, -23820(%ebp)
	.loc 1 602 0
	movl	-26812(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$2, %eax
	jne	.L146
	.loc 1 603 0
	movl	-26812(%ebp), %eax
	flds	24(%eax)
	flds	.LC35
	fmulp	%st, %st(1)
	fnstcw	-26822(%ebp)
	movzwl	-26822(%ebp), %eax
	movb	$12, %ah
	movw	%ax, -26824(%ebp)
	fldcw	-26824(%ebp)
	fistpl	-23820(%ebp)
	fldcw	-26822(%ebp)
	.loc 1 604 0
	flds	-23988(%ebp)
	movl	-26812(%ebp), %eax
	flds	16(%eax)
	faddp	%st, %st(1)
	fstps	-23988(%ebp)
	.loc 1 605 0
	movl	$0x00000000, %eax
	movl	%eax, -24040(%ebp)
	.loc 1 606 0
	movl	-26812(%ebp), %eax
	movl	24(%eax), %edx
	movl	-26812(%ebp), %eax
	movl	16(%eax), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	uplinespeed
	fstps	-24036(%ebp)
	.loc 1 607 0
	movl	$0x00000000, %eax
	movl	%eax, -24032(%ebp)
	.loc 1 608 0
	movl	$0x00000000, %eax
	movl	%eax, -24028(%ebp)
	.loc 1 609 0
	movl	$0x00000000, %eax
	movl	%eax, -24024(%ebp)
	.loc 1 610 0
	movl	$0x00000000, %eax
	movl	%eax, -24020(%ebp)
	jmp	.L147
.L146:
	.loc 1 612 0
	movl	-26812(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$4, %eax
	jne	.L147
	.loc 1 613 0
	movl	-26812(%ebp), %eax
	flds	24(%eax)
	flds	.LC35
	fmulp	%st, %st(1)
	fnstcw	-26822(%ebp)
	movzwl	-26822(%ebp), %eax
	movb	$12, %ah
	movw	%ax, -26824(%ebp)
	fldcw	-26824(%ebp)
	fistpl	-23820(%ebp)
	fldcw	-26822(%ebp)
	.loc 1 614 0
	flds	-23988(%ebp)
	movl	-26812(%ebp), %eax
	flds	16(%eax)
	faddp	%st, %st(1)
	fstps	-23988(%ebp)
	.loc 1 615 0
	movl	$0x00000000, %eax
	movl	%eax, -24040(%ebp)
	.loc 1 616 0
	movl	-26812(%ebp), %eax
	movl	24(%eax), %edx
	movl	-26812(%ebp), %eax
	movl	16(%eax), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_Z15fastuplinespeedff
	fstps	-24036(%ebp)
	.loc 1 617 0
	movl	$0x00000000, %eax
	movl	%eax, -24032(%ebp)
	.loc 1 618 0
	movl	$0x00000000, %eax
	movl	%eax, -24028(%ebp)
	.loc 1 619 0
	movl	$0x00000000, %eax
	movl	%eax, -24024(%ebp)
	.loc 1 620 0
	movl	$0x00000000, %eax
	movl	%eax, -24020(%ebp)
.L147:
	.loc 1 622 0
	movl	$0, -23824(%ebp)
	.loc 1 623 0
	movl	-26816(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$1, %eax
	jne	.L148
	.loc 1 624 0
	movl	-26816(%ebp), %eax
	flds	24(%eax)
	flds	.LC35
	fmulp	%st, %st(1)
	fnstcw	-26822(%ebp)
	movzwl	-26822(%ebp), %eax
	movb	$12, %ah
	movw	%ax, -26824(%ebp)
	fldcw	-26824(%ebp)
	fistpl	-23824(%ebp)
	fldcw	-26822(%ebp)
	.loc 1 625 0
	flds	-23964(%ebp)
	movl	-26816(%ebp), %eax
	flds	16(%eax)
	faddp	%st, %st(1)
	fstps	-23964(%ebp)
	.loc 1 626 0
	movl	$0x00000000, %eax
	movl	%eax, -24016(%ebp)
	.loc 1 627 0
	movl	-26816(%ebp), %eax
	movl	24(%eax), %edx
	movl	-26816(%ebp), %eax
	movl	16(%eax), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	spiralspeed
	fstps	-24012(%ebp)
	.loc 1 628 0
	movl	$0x00000000, %eax
	movl	%eax, -24008(%ebp)
	.loc 1 629 0
	movl	$0x00000000, %eax
	movl	%eax, -24004(%ebp)
	.loc 1 630 0
	movl	$0x00000000, %eax
	movl	%eax, -24000(%ebp)
	.loc 1 631 0
	movl	$0x00000000, %eax
	movl	%eax, -23996(%ebp)
	jmp	.L149
.L148:
	.loc 1 633 0
	movl	-26816(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$3, %eax
	jne	.L150
	.loc 1 634 0
	movl	-26816(%ebp), %eax
	flds	24(%eax)
	flds	.LC35
	fmulp	%st, %st(1)
	fnstcw	-26822(%ebp)
	movzwl	-26822(%ebp), %eax
	movb	$12, %ah
	movw	%ax, -26824(%ebp)
	fldcw	-26824(%ebp)
	fistpl	-23824(%ebp)
	fldcw	-26822(%ebp)
	.loc 1 635 0
	flds	-23964(%ebp)
	movl	-26816(%ebp), %eax
	flds	16(%eax)
	faddp	%st, %st(1)
	fstps	-23964(%ebp)
	.loc 1 636 0
	movl	$0x00000000, %eax
	movl	%eax, -24016(%ebp)
	.loc 1 637 0
	movl	-26816(%ebp), %eax
	movl	24(%eax), %edx
	movl	-26816(%ebp), %eax
	movl	16(%eax), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	downlinespeed
	fstps	-24012(%ebp)
	.loc 1 638 0
	movl	$0x00000000, %eax
	movl	%eax, -24008(%ebp)
	.loc 1 639 0
	movl	$0x00000000, %eax
	movl	%eax, -24004(%ebp)
	.loc 1 640 0
	movl	$0x00000000, %eax
	movl	%eax, -24000(%ebp)
	.loc 1 641 0
	movl	$0x00000000, %eax
	movl	%eax, -23996(%ebp)
	jmp	.L149
.L150:
	.loc 1 643 0
	movl	-26816(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$5, %eax
	jne	.L149
	.loc 1 644 0
	movl	-26816(%ebp), %eax
	flds	24(%eax)
	flds	.LC35
	fmulp	%st, %st(1)
	fnstcw	-26822(%ebp)
	movzwl	-26822(%ebp), %eax
	movb	$12, %ah
	movw	%ax, -26824(%ebp)
	fldcw	-26824(%ebp)
	fistpl	-23824(%ebp)
	fldcw	-26822(%ebp)
	.loc 1 645 0
	flds	-23964(%ebp)
	movl	-26816(%ebp), %eax
	flds	16(%eax)
	faddp	%st, %st(1)
	fstps	-23964(%ebp)
	.loc 1 646 0
	movl	$0x00000000, %eax
	movl	%eax, -24016(%ebp)
	.loc 1 647 0
	movl	-26816(%ebp), %eax
	movl	24(%eax), %edx
	movl	-26816(%ebp), %eax
	movl	16(%eax), %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_Z17fastdownlinespeedff
	fstps	-24012(%ebp)
	.loc 1 648 0
	movl	$0x00000000, %eax
	movl	%eax, -24008(%ebp)
	.loc 1 649 0
	movl	$0x00000000, %eax
	movl	%eax, -24004(%ebp)
	.loc 1 650 0
	movl	$0x00000000, %eax
	movl	%eax, -24000(%ebp)
	.loc 1 651 0
	movl	$0x00000000, %eax
	movl	%eax, -23996(%ebp)
.L149:
	.loc 1 660 0
	flds	-23992(%ebp)
	flds	-24040(%ebp)
	fldl	.LC36
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24160(%ebp)
	.loc 1 661 0
	flds	-23988(%ebp)
	flds	-24036(%ebp)
	fldl	.LC36
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24156(%ebp)
	.loc 1 662 0
	flds	-23984(%ebp)
	flds	-24032(%ebp)
	fldl	.LC36
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24152(%ebp)
	.loc 1 663 0
	flds	-23980(%ebp)
	flds	-24028(%ebp)
	fldl	.LC36
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24148(%ebp)
	.loc 1 664 0
	flds	-23976(%ebp)
	flds	-24024(%ebp)
	fldl	.LC36
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24144(%ebp)
	.loc 1 665 0
	flds	-23972(%ebp)
	flds	-24020(%ebp)
	fldl	.LC36
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24140(%ebp)
	.loc 1 667 0
	flds	-23968(%ebp)
	flds	-24016(%ebp)
	fldl	.LC36
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24184(%ebp)
	.loc 1 668 0
	flds	-23964(%ebp)
	flds	-24012(%ebp)
	fldl	.LC36
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24180(%ebp)
	.loc 1 669 0
	flds	-23960(%ebp)
	flds	-24008(%ebp)
	fldl	.LC36
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24176(%ebp)
	.loc 1 670 0
	flds	-23956(%ebp)
	flds	-24004(%ebp)
	fldl	.LC36
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24172(%ebp)
	.loc 1 671 0
	flds	-23952(%ebp)
	flds	-24000(%ebp)
	fldl	.LC36
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24168(%ebp)
	.loc 1 672 0
	flds	-23948(%ebp)
	flds	-23996(%ebp)
	fldl	.LC36
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24164(%ebp)
	.loc 1 674 0
	movl	-23972(%ebp), %edi
	movl	-23976(%ebp), %esi
	movl	-23980(%ebp), %ebx
	movl	-23984(%ebp), %ecx
	movl	-23988(%ebp), %edx
	movl	-23992(%ebp), %eax
	movl	%eax, -26960(%ebp)
	movl	36(%ebp), %eax
	movl	%eax, -26916(%ebp)
	movl	-26916(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	%edi, 24(%esp)
	movl	%esi, 20(%esp)
	movl	%ebx, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	-26960(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-23788(%ebp), %eax
	movl	%eax, (%esp)
	call	tmpnComputeIK
	.loc 1 675 0
	movl	-21504(%ebp), %eax
	movl	%eax, -24064(%ebp)
	movl	-21500(%ebp), %eax
	movl	%eax, -24060(%ebp)
	movl	-21496(%ebp), %eax
	movl	%eax, -24056(%ebp)
	movl	-21492(%ebp), %eax
	movl	%eax, -24052(%ebp)
	movl	-21488(%ebp), %eax
	movl	%eax, -24048(%ebp)
	movl	-21484(%ebp), %eax
	movl	%eax, -24044(%ebp)
	.loc 1 676 0
	movl	-23948(%ebp), %edi
	movl	-23952(%ebp), %esi
	movl	-23956(%ebp), %ebx
	movl	-23960(%ebp), %ecx
	movl	-23964(%ebp), %edx
	movl	-23968(%ebp), %eax
	movl	%eax, -26960(%ebp)
	movl	40(%ebp), %eax
	movl	%eax, -26920(%ebp)
	movl	-26920(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	%edi, 24(%esp)
	movl	%esi, 20(%esp)
	movl	%ebx, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	-26960(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-23788(%ebp), %eax
	movl	%eax, (%esp)
	call	tmpnComputeIK
	.loc 1 677 0
	movl	-21504(%ebp), %eax
	movl	%eax, -24088(%ebp)
	movl	-21500(%ebp), %eax
	movl	%eax, -24084(%ebp)
	movl	-21496(%ebp), %eax
	movl	%eax, -24080(%ebp)
	movl	-21492(%ebp), %eax
	movl	%eax, -24076(%ebp)
	movl	-21488(%ebp), %eax
	movl	%eax, -24072(%ebp)
	movl	-21484(%ebp), %eax
	movl	%eax, -24068(%ebp)
	.loc 1 679 0
	movl	-24140(%ebp), %edi
	movl	-24144(%ebp), %esi
	movl	-24148(%ebp), %ebx
	movl	-24152(%ebp), %ecx
	movl	-24156(%ebp), %edx
	movl	-24160(%ebp), %eax
	movl	%eax, -26960(%ebp)
	movl	36(%ebp), %eax
	movl	%eax, -26924(%ebp)
	movl	-26924(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	%edi, 24(%esp)
	movl	%esi, 20(%esp)
	movl	%ebx, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	-26960(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-23788(%ebp), %eax
	movl	%eax, (%esp)
	call	tmpnComputeIK
	.loc 1 680 0
	movl	-21504(%ebp), %eax
	movl	%eax, -24112(%ebp)
	movl	-21500(%ebp), %eax
	movl	%eax, -24108(%ebp)
	movl	-21496(%ebp), %eax
	movl	%eax, -24104(%ebp)
	movl	-21492(%ebp), %eax
	movl	%eax, -24100(%ebp)
	movl	-21488(%ebp), %eax
	movl	%eax, -24096(%ebp)
	movl	-21484(%ebp), %eax
	movl	%eax, -24092(%ebp)
	.loc 1 681 0
	movl	-24164(%ebp), %edi
	movl	-24168(%ebp), %esi
	movl	-24172(%ebp), %ebx
	movl	-24176(%ebp), %ecx
	movl	-24180(%ebp), %edx
	movl	-24184(%ebp), %eax
	movl	%eax, -26960(%ebp)
	movl	40(%ebp), %eax
	movl	%eax, -26928(%ebp)
	movl	-26928(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	%edi, 24(%esp)
	movl	%esi, 20(%esp)
	movl	%ebx, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	-26960(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-23788(%ebp), %eax
	movl	%eax, (%esp)
	call	tmpnComputeIK
	.loc 1 682 0
	movl	-21504(%ebp), %eax
	movl	%eax, -24136(%ebp)
	movl	-21500(%ebp), %eax
	movl	%eax, -24132(%ebp)
	movl	-21496(%ebp), %eax
	movl	%eax, -24128(%ebp)
	movl	-21492(%ebp), %eax
	movl	%eax, -24124(%ebp)
	movl	-21488(%ebp), %eax
	movl	%eax, -24120(%ebp)
	movl	-21484(%ebp), %eax
	movl	%eax, -24116(%ebp)
	.loc 1 684 0
	flds	-24112(%ebp)
	flds	-24064(%ebp)
	fsubrp	%st, %st(1)
	flds	.LC37
	fmulp	%st, %st(1)
	fstps	-24208(%ebp)
	.loc 1 685 0
	flds	-24108(%ebp)
	flds	-24060(%ebp)
	fsubrp	%st, %st(1)
	flds	.LC37
	fmulp	%st, %st(1)
	fstps	-24204(%ebp)
	.loc 1 686 0
	flds	-24104(%ebp)
	flds	-24056(%ebp)
	fsubrp	%st, %st(1)
	flds	.LC37
	fmulp	%st, %st(1)
	fstps	-24200(%ebp)
	.loc 1 687 0
	flds	-24100(%ebp)
	flds	-24052(%ebp)
	fsubrp	%st, %st(1)
	flds	.LC37
	fmulp	%st, %st(1)
	fstps	-24196(%ebp)
	.loc 1 688 0
	flds	-24096(%ebp)
	flds	-24048(%ebp)
	fsubrp	%st, %st(1)
	flds	.LC37
	fmulp	%st, %st(1)
	fstps	-24192(%ebp)
	.loc 1 689 0
	flds	-24092(%ebp)
	flds	-24044(%ebp)
	fsubrp	%st, %st(1)
	flds	.LC37
	fmulp	%st, %st(1)
	fstps	-24188(%ebp)
	.loc 1 691 0
	flds	-24136(%ebp)
	flds	-24088(%ebp)
	fsubrp	%st, %st(1)
	flds	.LC37
	fmulp	%st, %st(1)
	fstps	-24232(%ebp)
	.loc 1 692 0
	flds	-24132(%ebp)
	flds	-24084(%ebp)
	fsubrp	%st, %st(1)
	flds	.LC37
	fmulp	%st, %st(1)
	fstps	-24228(%ebp)
	.loc 1 693 0
	flds	-24128(%ebp)
	flds	-24080(%ebp)
	fsubrp	%st, %st(1)
	flds	.LC37
	fmulp	%st, %st(1)
	fstps	-24224(%ebp)
	.loc 1 694 0
	flds	-24124(%ebp)
	flds	-24076(%ebp)
	fsubrp	%st, %st(1)
	flds	.LC37
	fmulp	%st, %st(1)
	fstps	-24220(%ebp)
	.loc 1 695 0
	flds	-24120(%ebp)
	flds	-24072(%ebp)
	fsubrp	%st, %st(1)
	flds	.LC37
	fmulp	%st, %st(1)
	fstps	-24216(%ebp)
	.loc 1 696 0
	flds	-24116(%ebp)
	flds	-24068(%ebp)
	fsubrp	%st, %st(1)
	flds	.LC37
	fmulp	%st, %st(1)
	fstps	-24212(%ebp)
	.loc 1 703 0
	movl	-26796(%ebp), %eax
	movl	24(%eax), %eax
	testl	%eax, %eax
	je	.L151
	movl	-26796(%ebp), %eax
	flds	(%eax)
	jmp	.L152
.L151:
	flds	-23992(%ebp)
	movl	-26796(%ebp), %eax
	flds	(%eax)
	faddp	%st, %st(1)
.L152:
	fstps	-24256(%ebp)
	.loc 1 704 0
	movl	-26796(%ebp), %eax
	movl	28(%eax), %eax
	testl	%eax, %eax
	je	.L153
	movl	-26796(%ebp), %eax
	flds	4(%eax)
	jmp	.L154
.L153:
	flds	-23988(%ebp)
	movl	-26796(%ebp), %eax
	flds	4(%eax)
	faddp	%st, %st(1)
.L154:
	fstps	-24252(%ebp)
	.loc 1 705 0
	movl	-26796(%ebp), %eax
	movl	32(%eax), %eax
	testl	%eax, %eax
	je	.L155
	movl	-26796(%ebp), %eax
	flds	8(%eax)
	jmp	.L156
.L155:
	flds	-23984(%ebp)
	movl	-26796(%ebp), %eax
	flds	8(%eax)
	faddp	%st, %st(1)
.L156:
	fstps	-24248(%ebp)
	.loc 1 706 0
	movl	-26796(%ebp), %eax
	movl	36(%eax), %eax
	testl	%eax, %eax
	je	.L157
	movl	-26796(%ebp), %eax
	flds	12(%eax)
	jmp	.L158
.L157:
	flds	-23980(%ebp)
	movl	-26796(%ebp), %eax
	flds	12(%eax)
	faddp	%st, %st(1)
.L158:
	fstps	-24244(%ebp)
	.loc 1 707 0
	movl	-26796(%ebp), %eax
	movl	40(%eax), %eax
	testl	%eax, %eax
	je	.L159
	movl	-26796(%ebp), %eax
	flds	16(%eax)
	jmp	.L160
.L159:
	flds	-23976(%ebp)
	movl	-26796(%ebp), %eax
	flds	16(%eax)
	faddp	%st, %st(1)
.L160:
	fstps	-24240(%ebp)
	.loc 1 708 0
	movl	-26796(%ebp), %eax
	movl	44(%eax), %eax
	testl	%eax, %eax
	je	.L161
	movl	-26796(%ebp), %eax
	flds	20(%eax)
	jmp	.L162
.L161:
	flds	-23972(%ebp)
	movl	-26796(%ebp), %eax
	flds	20(%eax)
	faddp	%st, %st(1)
.L162:
	fstps	-24236(%ebp)
	.loc 1 709 0
	movl	-26804(%ebp), %eax
	movl	24(%eax), %eax
	testl	%eax, %eax
	je	.L163
	movl	-26804(%ebp), %eax
	flds	(%eax)
	jmp	.L164
.L163:
	flds	-23968(%ebp)
	movl	-26804(%ebp), %eax
	flds	(%eax)
	faddp	%st, %st(1)
.L164:
	fstps	-24280(%ebp)
	.loc 1 710 0
	movl	-26804(%ebp), %eax
	movl	28(%eax), %eax
	testl	%eax, %eax
	je	.L165
	movl	-26804(%ebp), %eax
	flds	4(%eax)
	jmp	.L166
.L165:
	flds	-23964(%ebp)
	movl	-26804(%ebp), %eax
	flds	4(%eax)
	faddp	%st, %st(1)
.L166:
	fstps	-24276(%ebp)
	.loc 1 711 0
	movl	-26804(%ebp), %eax
	movl	32(%eax), %eax
	testl	%eax, %eax
	je	.L167
	movl	-26804(%ebp), %eax
	flds	8(%eax)
	jmp	.L168
.L167:
	flds	-23960(%ebp)
	movl	-26804(%ebp), %eax
	flds	8(%eax)
	faddp	%st, %st(1)
.L168:
	fstps	-24272(%ebp)
	.loc 1 712 0
	movl	-26804(%ebp), %eax
	movl	36(%eax), %eax
	testl	%eax, %eax
	je	.L169
	movl	-26804(%ebp), %eax
	flds	12(%eax)
	jmp	.L170
.L169:
	flds	-23956(%ebp)
	movl	-26804(%ebp), %eax
	flds	12(%eax)
	faddp	%st, %st(1)
.L170:
	fstps	-24268(%ebp)
	.loc 1 713 0
	movl	-26804(%ebp), %eax
	movl	40(%eax), %eax
	testl	%eax, %eax
	je	.L171
	movl	-26804(%ebp), %eax
	flds	16(%eax)
	jmp	.L172
.L171:
	flds	-23952(%ebp)
	movl	-26804(%ebp), %eax
	flds	16(%eax)
	faddp	%st, %st(1)
.L172:
	fstps	-24264(%ebp)
	.loc 1 714 0
	movl	-26804(%ebp), %eax
	movl	44(%eax), %eax
	testl	%eax, %eax
	je	.L173
	movl	-26804(%ebp), %eax
	flds	20(%eax)
	jmp	.L174
.L173:
	flds	-23948(%ebp)
	movl	-26804(%ebp), %eax
	flds	20(%eax)
	faddp	%st, %st(1)
.L174:
	fstps	-24260(%ebp)
	.loc 1 720 0
	flds	-24256(%ebp)
	movl	-26800(%ebp), %eax
	flds	(%eax)
	fldl	.LC36
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24304(%ebp)
	.loc 1 721 0
	flds	-24252(%ebp)
	movl	-26800(%ebp), %eax
	flds	4(%eax)
	fldl	.LC36
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24300(%ebp)
	.loc 1 722 0
	flds	-24248(%ebp)
	movl	-26800(%ebp), %eax
	flds	8(%eax)
	fldl	.LC36
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24296(%ebp)
	.loc 1 723 0
	flds	-24244(%ebp)
	movl	-26800(%ebp), %eax
	flds	12(%eax)
	fldl	.LC36
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24292(%ebp)
	.loc 1 724 0
	flds	-24240(%ebp)
	movl	-26800(%ebp), %eax
	flds	16(%eax)
	fldl	.LC36
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24288(%ebp)
	.loc 1 725 0
	flds	-24236(%ebp)
	movl	-26800(%ebp), %eax
	flds	20(%eax)
	fldl	.LC36
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24284(%ebp)
	.loc 1 727 0
	flds	-24280(%ebp)
	movl	-26808(%ebp), %eax
	flds	(%eax)
	fldl	.LC36
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24328(%ebp)
	.loc 1 728 0
	flds	-24276(%ebp)
	movl	-26808(%ebp), %eax
	flds	4(%eax)
	fldl	.LC36
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24324(%ebp)
	.loc 1 729 0
	flds	-24272(%ebp)
	movl	-26808(%ebp), %eax
	flds	8(%eax)
	fldl	.LC36
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24320(%ebp)
	.loc 1 730 0
	flds	-24268(%ebp)
	movl	-26808(%ebp), %eax
	flds	12(%eax)
	fldl	.LC36
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24316(%ebp)
	.loc 1 731 0
	flds	-24264(%ebp)
	movl	-26808(%ebp), %eax
	flds	16(%eax)
	fldl	.LC36
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24312(%ebp)
	.loc 1 732 0
	flds	-24260(%ebp)
	movl	-26808(%ebp), %eax
	flds	20(%eax)
	fldl	.LC36
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24308(%ebp)
	.loc 1 733 0
	movl	-24236(%ebp), %edi
	movl	-24240(%ebp), %esi
	movl	-24244(%ebp), %ebx
	movl	-24248(%ebp), %ecx
	movl	-24252(%ebp), %edx
	movl	-24256(%ebp), %eax
	movl	%eax, -26960(%ebp)
	movl	36(%ebp), %eax
	movl	%eax, -26932(%ebp)
	movl	-26932(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	%edi, 24(%esp)
	movl	%esi, 20(%esp)
	movl	%ebx, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	-26960(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-23788(%ebp), %eax
	movl	%eax, (%esp)
	call	tmpnComputeIK
	.loc 1 734 0
	movl	-21504(%ebp), %eax
	movl	%eax, -24352(%ebp)
	movl	-21500(%ebp), %eax
	movl	%eax, -24348(%ebp)
	movl	-21496(%ebp), %eax
	movl	%eax, -24344(%ebp)
	movl	-21492(%ebp), %eax
	movl	%eax, -24340(%ebp)
	movl	-21488(%ebp), %eax
	movl	%eax, -24336(%ebp)
	movl	-21484(%ebp), %eax
	movl	%eax, -24332(%ebp)
	.loc 1 735 0
	movl	-24284(%ebp), %edi
	movl	-24288(%ebp), %esi
	movl	-24292(%ebp), %ebx
	movl	-24296(%ebp), %ecx
	movl	-24300(%ebp), %edx
	movl	-24304(%ebp), %eax
	movl	%eax, -26960(%ebp)
	movl	36(%ebp), %eax
	movl	%eax, -26936(%ebp)
	movl	-26936(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	%edi, 24(%esp)
	movl	%esi, 20(%esp)
	movl	%ebx, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	-26960(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-23788(%ebp), %eax
	movl	%eax, (%esp)
	call	tmpnComputeIK
	.loc 1 736 0
	movl	-21504(%ebp), %eax
	movl	%eax, -24376(%ebp)
	movl	-21500(%ebp), %eax
	movl	%eax, -24372(%ebp)
	movl	-21496(%ebp), %eax
	movl	%eax, -24368(%ebp)
	movl	-21492(%ebp), %eax
	movl	%eax, -24364(%ebp)
	movl	-21488(%ebp), %eax
	movl	%eax, -24360(%ebp)
	movl	-21484(%ebp), %eax
	movl	%eax, -24356(%ebp)
	.loc 1 738 0
	movl	-24260(%ebp), %edi
	movl	-24264(%ebp), %esi
	movl	-24268(%ebp), %ebx
	movl	-24272(%ebp), %ecx
	movl	-24276(%ebp), %edx
	movl	-24280(%ebp), %eax
	movl	%eax, -26960(%ebp)
	movl	40(%ebp), %eax
	movl	%eax, -26940(%ebp)
	movl	-26940(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	%edi, 24(%esp)
	movl	%esi, 20(%esp)
	movl	%ebx, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	-26960(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-23788(%ebp), %eax
	movl	%eax, (%esp)
	call	tmpnComputeIK
	.loc 1 739 0
	movl	-21504(%ebp), %eax
	movl	%eax, -24400(%ebp)
	movl	-21500(%ebp), %eax
	movl	%eax, -24396(%ebp)
	movl	-21496(%ebp), %eax
	movl	%eax, -24392(%ebp)
	movl	-21492(%ebp), %eax
	movl	%eax, -24388(%ebp)
	movl	-21488(%ebp), %eax
	movl	%eax, -24384(%ebp)
	movl	-21484(%ebp), %eax
	movl	%eax, -24380(%ebp)
	.loc 1 740 0
	movl	-24308(%ebp), %edi
	movl	-24312(%ebp), %esi
	movl	-24316(%ebp), %ebx
	movl	-24320(%ebp), %ecx
	movl	-24324(%ebp), %edx
	movl	-24328(%ebp), %eax
	movl	%eax, -26960(%ebp)
	movl	40(%ebp), %eax
	movl	%eax, -26944(%ebp)
	movl	-26944(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	%edi, 24(%esp)
	movl	%esi, 20(%esp)
	movl	%ebx, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	-26960(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-23788(%ebp), %eax
	movl	%eax, (%esp)
	call	tmpnComputeIK
	.loc 1 741 0
	movl	-21504(%ebp), %eax
	movl	%eax, -24424(%ebp)
	movl	-21500(%ebp), %eax
	movl	%eax, -24420(%ebp)
	movl	-21496(%ebp), %eax
	movl	%eax, -24416(%ebp)
	movl	-21492(%ebp), %eax
	movl	%eax, -24412(%ebp)
	movl	-21488(%ebp), %eax
	movl	%eax, -24408(%ebp)
	movl	-21484(%ebp), %eax
	movl	%eax, -24404(%ebp)
	.loc 1 743 0
	flds	-24376(%ebp)
	flds	-24352(%ebp)
	fsubrp	%st, %st(1)
	flds	.LC37
	fmulp	%st, %st(1)
	fstps	-24448(%ebp)
	.loc 1 744 0
	flds	-24372(%ebp)
	flds	-24348(%ebp)
	fsubrp	%st, %st(1)
	flds	.LC37
	fmulp	%st, %st(1)
	fstps	-24444(%ebp)
	.loc 1 745 0
	flds	-24368(%ebp)
	flds	-24344(%ebp)
	fsubrp	%st, %st(1)
	flds	.LC37
	fmulp	%st, %st(1)
	fstps	-24440(%ebp)
	.loc 1 746 0
	flds	-24364(%ebp)
	flds	-24340(%ebp)
	fsubrp	%st, %st(1)
	flds	.LC37
	fmulp	%st, %st(1)
	fstps	-24436(%ebp)
	.loc 1 747 0
	flds	-24360(%ebp)
	flds	-24336(%ebp)
	fsubrp	%st, %st(1)
	flds	.LC37
	fmulp	%st, %st(1)
	fstps	-24432(%ebp)
	.loc 1 748 0
	flds	-24356(%ebp)
	flds	-24332(%ebp)
	fsubrp	%st, %st(1)
	flds	.LC37
	fmulp	%st, %st(1)
	fstps	-24428(%ebp)
	.loc 1 750 0
	flds	-24424(%ebp)
	flds	-24400(%ebp)
	fsubrp	%st, %st(1)
	flds	.LC37
	fmulp	%st, %st(1)
	fstps	-24472(%ebp)
	.loc 1 751 0
	flds	-24420(%ebp)
	flds	-24396(%ebp)
	fsubrp	%st, %st(1)
	flds	.LC37
	fmulp	%st, %st(1)
	fstps	-24468(%ebp)
	.loc 1 752 0
	flds	-24416(%ebp)
	flds	-24392(%ebp)
	fsubrp	%st, %st(1)
	flds	.LC37
	fmulp	%st, %st(1)
	fstps	-24464(%ebp)
	.loc 1 753 0
	flds	-24412(%ebp)
	flds	-24388(%ebp)
	fsubrp	%st, %st(1)
	flds	.LC37
	fmulp	%st, %st(1)
	fstps	-24460(%ebp)
	.loc 1 754 0
	flds	-24408(%ebp)
	flds	-24384(%ebp)
	fsubrp	%st, %st(1)
	flds	.LC37
	fmulp	%st, %st(1)
	fstps	-24456(%ebp)
	.loc 1 755 0
	flds	-24404(%ebp)
	flds	-24380(%ebp)
	fsubrp	%st, %st(1)
	flds	.LC37
	fmulp	%st, %st(1)
	fstps	-24452(%ebp)
	.loc 1 763 0
	leal	-24824(%ebp), %ebx
	movl	$0, %eax
	movl	$10, %edx
	movl	%ebx, %edi
	movl	%edx, %ecx
	rep stosl
	.loc 1 764 0
	leal	-24864(%ebp), %ebx
	movl	$0, %eax
	movl	$10, %edx
	movl	%ebx, %edi
	movl	%edx, %ecx
	rep stosl
	.loc 1 765 0
	leal	-24904(%ebp), %ebx
	movl	$0, %eax
	movl	$10, %edx
	movl	%ebx, %edi
	movl	%edx, %ecx
	rep stosl
	.loc 1 766 0
	leal	-24944(%ebp), %ebx
	movl	$0, %eax
	movl	$10, %edx
	movl	%ebx, %edi
	movl	%edx, %ecx
	rep stosl
	.loc 1 770 0
	movl	28(%ebp), %eax
	cmpl	$1, %eax
	je	.L177
	cmpl	$1, %eax
	jg	.L180
	testl	%eax, %eax
	je	.L176
	jmp	.L175
.L180:
	cmpl	$2, %eax
	je	.L178
	cmpl	$3, %eax
	je	.L179
	jmp	.L175
.L176:
	.loc 1 772 0
	flds	-24064(%ebp)
	fstpl	-24824(%ebp)
	.loc 1 773 0
	flds	-24060(%ebp)
	fstpl	-24816(%ebp)
	.loc 1 774 0
	flds	-24056(%ebp)
	fstpl	-24808(%ebp)
	.loc 1 775 0
	flds	-24052(%ebp)
	fstpl	-24800(%ebp)
	.loc 1 776 0
	flds	-24048(%ebp)
	fstpl	-24792(%ebp)
	.loc 1 778 0
	flds	-24088(%ebp)
	fstpl	-24904(%ebp)
	.loc 1 779 0
	flds	-24084(%ebp)
	fstpl	-24896(%ebp)
	.loc 1 780 0
	flds	-24080(%ebp)
	fstpl	-24888(%ebp)
	.loc 1 781 0
	flds	-24076(%ebp)
	fstpl	-24880(%ebp)
	.loc 1 782 0
	flds	-24072(%ebp)
	fstpl	-24872(%ebp)
	.loc 1 783 0
	jmp	.L175
.L177:
	.loc 1 785 0
	flds	-24352(%ebp)
	fstpl	-24824(%ebp)
	.loc 1 786 0
	flds	-24348(%ebp)
	fstpl	-24816(%ebp)
	.loc 1 787 0
	flds	-24344(%ebp)
	fstpl	-24808(%ebp)
	.loc 1 788 0
	flds	-24340(%ebp)
	fstpl	-24800(%ebp)
	.loc 1 789 0
	flds	-24336(%ebp)
	fstpl	-24792(%ebp)
	.loc 1 791 0
	flds	-24448(%ebp)
	fstpl	-24864(%ebp)
	.loc 1 792 0
	flds	-24444(%ebp)
	fstpl	-24856(%ebp)
	.loc 1 793 0
	flds	-24440(%ebp)
	fstpl	-24848(%ebp)
	.loc 1 794 0
	flds	-24436(%ebp)
	fstpl	-24840(%ebp)
	.loc 1 795 0
	flds	-24432(%ebp)
	fstpl	-24832(%ebp)
	.loc 1 797 0
	flds	-24088(%ebp)
	fstpl	-24904(%ebp)
	.loc 1 798 0
	flds	-24084(%ebp)
	fstpl	-24896(%ebp)
	.loc 1 799 0
	flds	-24080(%ebp)
	fstpl	-24888(%ebp)
	.loc 1 800 0
	flds	-24076(%ebp)
	fstpl	-24880(%ebp)
	.loc 1 801 0
	flds	-24072(%ebp)
	fstpl	-24872(%ebp)
	.loc 1 802 0
	jmp	.L175
.L178:
	.loc 1 804 0
	flds	-24064(%ebp)
	fstpl	-24824(%ebp)
	.loc 1 805 0
	flds	-24060(%ebp)
	fstpl	-24816(%ebp)
	.loc 1 806 0
	flds	-24056(%ebp)
	fstpl	-24808(%ebp)
	.loc 1 807 0
	flds	-24052(%ebp)
	fstpl	-24800(%ebp)
	.loc 1 808 0
	flds	-24048(%ebp)
	fstpl	-24792(%ebp)
	.loc 1 810 0
	flds	-24400(%ebp)
	fstpl	-24904(%ebp)
	.loc 1 811 0
	flds	-24396(%ebp)
	fstpl	-24896(%ebp)
	.loc 1 812 0
	flds	-24392(%ebp)
	fstpl	-24888(%ebp)
	.loc 1 813 0
	flds	-24388(%ebp)
	fstpl	-24880(%ebp)
	.loc 1 814 0
	flds	-24384(%ebp)
	fstpl	-24872(%ebp)
	.loc 1 816 0
	flds	-24472(%ebp)
	fstpl	-24944(%ebp)
	.loc 1 817 0
	flds	-24468(%ebp)
	fstpl	-24936(%ebp)
	.loc 1 818 0
	flds	-24464(%ebp)
	fstpl	-24928(%ebp)
	.loc 1 819 0
	flds	-24460(%ebp)
	fstpl	-24920(%ebp)
	.loc 1 820 0
	flds	-24456(%ebp)
	fstpl	-24912(%ebp)
	.loc 1 821 0
	jmp	.L175
.L179:
	.loc 1 823 0
	flds	-24352(%ebp)
	fstpl	-24824(%ebp)
	.loc 1 824 0
	flds	-24348(%ebp)
	fstpl	-24816(%ebp)
	.loc 1 825 0
	flds	-24344(%ebp)
	fstpl	-24808(%ebp)
	.loc 1 826 0
	flds	-24340(%ebp)
	fstpl	-24800(%ebp)
	.loc 1 827 0
	flds	-24336(%ebp)
	fstpl	-24792(%ebp)
	.loc 1 829 0
	flds	-24448(%ebp)
	fstpl	-24864(%ebp)
	.loc 1 830 0
	flds	-24444(%ebp)
	fstpl	-24856(%ebp)
	.loc 1 831 0
	flds	-24440(%ebp)
	fstpl	-24848(%ebp)
	.loc 1 832 0
	flds	-24436(%ebp)
	fstpl	-24840(%ebp)
	.loc 1 833 0
	flds	-24432(%ebp)
	fstpl	-24832(%ebp)
	.loc 1 835 0
	flds	-24400(%ebp)
	fstpl	-24904(%ebp)
	.loc 1 836 0
	flds	-24396(%ebp)
	fstpl	-24896(%ebp)
	.loc 1 837 0
	flds	-24392(%ebp)
	fstpl	-24888(%ebp)
	.loc 1 838 0
	flds	-24388(%ebp)
	fstpl	-24880(%ebp)
	.loc 1 839 0
	flds	-24384(%ebp)
	fstpl	-24872(%ebp)
	.loc 1 841 0
	flds	-24472(%ebp)
	fstpl	-24944(%ebp)
	.loc 1 842 0
	flds	-24468(%ebp)
	fstpl	-24936(%ebp)
	.loc 1 843 0
	flds	-24464(%ebp)
	fstpl	-24928(%ebp)
	.loc 1 844 0
	flds	-24460(%ebp)
	fstpl	-24920(%ebp)
	.loc 1 845 0
	flds	-24456(%ebp)
	fstpl	-24912(%ebp)
.L175:
	.loc 1 852 0
	leal	-25144(%ebp), %ebx
	movl	$0, %eax
	movl	$10, %edx
	movl	%ebx, %edi
	movl	%edx, %ecx
	rep stosl
	movl	-26772(%ebp), %eax
	flds	(%eax)
	flds	.LC38
	fmulp	%st, %st(1)
	fstpl	-25144(%ebp)
	movl	-26772(%ebp), %eax
	flds	4(%eax)
	flds	.LC39
	fmulp	%st, %st(1)
	flds	.LC40
	fdivrp	%st, %st(1)
	fstpl	-25136(%ebp)
	movl	-26772(%ebp), %eax
	flds	8(%eax)
	flds	.LC39
	fmulp	%st, %st(1)
	flds	.LC40
	fdivrp	%st, %st(1)
	fstpl	-25128(%ebp)
	movl	-26772(%ebp), %eax
	flds	12(%eax)
	flds	.LC39
	fmulp	%st, %st(1)
	flds	.LC40
	fdivrp	%st, %st(1)
	fstpl	-25120(%ebp)
	movl	-26772(%ebp), %eax
	flds	16(%eax)
	flds	.LC39
	fmulp	%st, %st(1)
	flds	.LC40
	fdivrp	%st, %st(1)
	fstpl	-25112(%ebp)
	.loc 1 853 0
	leal	-25184(%ebp), %ebx
	movl	$0, %eax
	movl	$10, %edx
	movl	%ebx, %edi
	movl	%edx, %ecx
	rep stosl
	movl	-26776(%ebp), %eax
	flds	(%eax)
	flds	.LC38
	fmulp	%st, %st(1)
	fstpl	-25184(%ebp)
	movl	-26776(%ebp), %eax
	flds	4(%eax)
	flds	.LC39
	fmulp	%st, %st(1)
	flds	.LC40
	fdivrp	%st, %st(1)
	fstpl	-25176(%ebp)
	movl	-26776(%ebp), %eax
	flds	8(%eax)
	flds	.LC39
	fmulp	%st, %st(1)
	flds	.LC40
	fdivrp	%st, %st(1)
	fstpl	-25168(%ebp)
	movl	-26776(%ebp), %eax
	flds	12(%eax)
	flds	.LC39
	fmulp	%st, %st(1)
	flds	.LC40
	fdivrp	%st, %st(1)
	fstpl	-25160(%ebp)
	movl	-26776(%ebp), %eax
	flds	16(%eax)
	flds	.LC39
	fmulp	%st, %st(1)
	flds	.LC40
	fdivrp	%st, %st(1)
	fstpl	-25152(%ebp)
	.loc 1 855 0
	fldl	-24824(%ebp)
	fldl	.LC41
	fmulp	%st, %st(1)
	fstpl	-24984(%ebp)
	.loc 1 856 0
	fldl	-24816(%ebp)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fstpl	-24976(%ebp)
	.loc 1 857 0
	fldl	-24808(%ebp)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fstpl	-24968(%ebp)
	.loc 1 858 0
	fldl	-24800(%ebp)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fstpl	-24960(%ebp)
	.loc 1 859 0
	fldl	-24792(%ebp)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fstpl	-24952(%ebp)
	.loc 1 860 0
	fldl	-24864(%ebp)
	fldl	.LC41
	fmulp	%st, %st(1)
	fstpl	-25024(%ebp)
	.loc 1 861 0
	fldl	-24856(%ebp)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fstpl	-25016(%ebp)
	.loc 1 862 0
	fldl	-24848(%ebp)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fstpl	-25008(%ebp)
	.loc 1 863 0
	fldl	-24840(%ebp)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fstpl	-25000(%ebp)
	.loc 1 864 0
	fldl	-24832(%ebp)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fstpl	-24992(%ebp)
	.loc 1 866 0
	fldl	-24904(%ebp)
	fldl	.LC41
	fmulp	%st, %st(1)
	fstpl	-25064(%ebp)
	.loc 1 867 0
	fldl	-24896(%ebp)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fstpl	-25056(%ebp)
	.loc 1 868 0
	fldl	-24888(%ebp)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fstpl	-25048(%ebp)
	.loc 1 869 0
	fldl	-24880(%ebp)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fstpl	-25040(%ebp)
	.loc 1 870 0
	fldl	-24872(%ebp)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fstpl	-25032(%ebp)
	.loc 1 871 0
	fldl	-24944(%ebp)
	fldl	.LC41
	fmulp	%st, %st(1)
	fstpl	-25104(%ebp)
	.loc 1 872 0
	fldl	-24936(%ebp)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fstpl	-25096(%ebp)
	.loc 1 873 0
	fldl	-24928(%ebp)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fstpl	-25088(%ebp)
	.loc 1 874 0
	fldl	-24920(%ebp)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fstpl	-25080(%ebp)
	.loc 1 875 0
	fldl	-24912(%ebp)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fstpl	-25072(%ebp)
	.loc 1 877 0
	movl	-25184(%ebp), %eax
	movl	%eax, 204(%esp)
	movl	-25180(%ebp), %eax
	movl	%eax, 208(%esp)
	movl	-25176(%ebp), %eax
	movl	%eax, 212(%esp)
	movl	-25172(%ebp), %eax
	movl	%eax, 216(%esp)
	movl	-25168(%ebp), %eax
	movl	%eax, 220(%esp)
	movl	-25164(%ebp), %eax
	movl	%eax, 224(%esp)
	movl	-25160(%ebp), %eax
	movl	%eax, 228(%esp)
	movl	-25156(%ebp), %eax
	movl	%eax, 232(%esp)
	movl	-25152(%ebp), %eax
	movl	%eax, 236(%esp)
	movl	-25148(%ebp), %eax
	movl	%eax, 240(%esp)
	movl	-25144(%ebp), %eax
	movl	%eax, 164(%esp)
	movl	-25140(%ebp), %eax
	movl	%eax, 168(%esp)
	movl	-25136(%ebp), %eax
	movl	%eax, 172(%esp)
	movl	-25132(%ebp), %eax
	movl	%eax, 176(%esp)
	movl	-25128(%ebp), %eax
	movl	%eax, 180(%esp)
	movl	-25124(%ebp), %eax
	movl	%eax, 184(%esp)
	movl	-25120(%ebp), %eax
	movl	%eax, 188(%esp)
	movl	-25116(%ebp), %eax
	movl	%eax, 192(%esp)
	movl	-25112(%ebp), %eax
	movl	%eax, 196(%esp)
	movl	-25108(%ebp), %eax
	movl	%eax, 200(%esp)
	movl	-25104(%ebp), %eax
	movl	%eax, 124(%esp)
	movl	-25100(%ebp), %eax
	movl	%eax, 128(%esp)
	movl	-25096(%ebp), %eax
	movl	%eax, 132(%esp)
	movl	-25092(%ebp), %eax
	movl	%eax, 136(%esp)
	movl	-25088(%ebp), %eax
	movl	%eax, 140(%esp)
	movl	-25084(%ebp), %eax
	movl	%eax, 144(%esp)
	movl	-25080(%ebp), %eax
	movl	%eax, 148(%esp)
	movl	-25076(%ebp), %eax
	movl	%eax, 152(%esp)
	movl	-25072(%ebp), %eax
	movl	%eax, 156(%esp)
	movl	-25068(%ebp), %eax
	movl	%eax, 160(%esp)
	movl	-25064(%ebp), %eax
	movl	%eax, 84(%esp)
	movl	-25060(%ebp), %eax
	movl	%eax, 88(%esp)
	movl	-25056(%ebp), %eax
	movl	%eax, 92(%esp)
	movl	-25052(%ebp), %eax
	movl	%eax, 96(%esp)
	movl	-25048(%ebp), %eax
	movl	%eax, 100(%esp)
	movl	-25044(%ebp), %eax
	movl	%eax, 104(%esp)
	movl	-25040(%ebp), %eax
	movl	%eax, 108(%esp)
	movl	-25036(%ebp), %eax
	movl	%eax, 112(%esp)
	movl	-25032(%ebp), %eax
	movl	%eax, 116(%esp)
	movl	-25028(%ebp), %eax
	movl	%eax, 120(%esp)
	movl	-25024(%ebp), %eax
	movl	%eax, 44(%esp)
	movl	-25020(%ebp), %eax
	movl	%eax, 48(%esp)
	movl	-25016(%ebp), %eax
	movl	%eax, 52(%esp)
	movl	-25012(%ebp), %eax
	movl	%eax, 56(%esp)
	movl	-25008(%ebp), %eax
	movl	%eax, 60(%esp)
	movl	-25004(%ebp), %eax
	movl	%eax, 64(%esp)
	movl	-25000(%ebp), %eax
	movl	%eax, 68(%esp)
	movl	-24996(%ebp), %eax
	movl	%eax, 72(%esp)
	movl	-24992(%ebp), %eax
	movl	%eax, 76(%esp)
	movl	-24988(%ebp), %eax
	movl	%eax, 80(%esp)
	movl	-24984(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-24980(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-24976(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	-24972(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	-24968(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	-24964(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	-24960(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	-24956(%ebp), %eax
	movl	%eax, 32(%esp)
	movl	-24952(%ebp), %eax
	movl	%eax, 36(%esp)
	movl	-24948(%ebp), %eax
	movl	%eax, 40(%esp)
	leal	-26752(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4baneC1E16tmpnJointsDUnionS0_S0_S0_S0_S0_
	.loc 1 878 0
	leal	-26752(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4bane7optimerEv
	.loc 1 881 0
	leal	-23936(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-25584(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-26752(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4bane9getResultER8baneConfRd
	.loc 1 883 0
	fldl	-23936(%ebp)
	fldl	.LC44
	fmulp	%st, %st(1)
	fldl	.LC17
	faddp	%st, %st(1)
	fnstcw	-26822(%ebp)
	movzwl	-26822(%ebp), %eax
	movb	$12, %ah
	movw	%ax, -26824(%ebp)
	fldcw	-26824(%ebp)
	fistpl	-23804(%ebp)
	fldcw	-26822(%ebp)
	.loc 1 884 0
	fldl	-23936(%ebp)
	fldl	.LC28
	fmulp	%st, %st(1)
	fstps	-23816(%ebp)
	.loc 1 889 0
	movl	28(%ebp), %eax
	cmpl	$1, %eax
	je	.L183
	cmpl	$1, %eax
	jg	.L186
	testl	%eax, %eax
	.loc 1 908 0
	jmp	.L181
.L186:
	.loc 1 889 0
	cmpl	$2, %eax
	je	.L184
	cmpl	$3, %eax
	je	.L185
	jmp	.L181
.L184:
	.loc 1 891 0
	movl	-24088(%ebp), %eax
	movl	%eax, -24568(%ebp)
	.loc 1 892 0
	movl	-24084(%ebp), %eax
	movl	%eax, -24564(%ebp)
	.loc 1 893 0
	movl	-24080(%ebp), %eax
	movl	%eax, -24560(%ebp)
	.loc 1 894 0
	movl	-24076(%ebp), %eax
	movl	%eax, -24556(%ebp)
	.loc 1 895 0
	movl	-24072(%ebp), %eax
	movl	%eax, -24552(%ebp)
	.loc 1 896 0
	movl	-24232(%ebp), %eax
	movl	%eax, -24592(%ebp)
	.loc 1 897 0
	movl	-24228(%ebp), %eax
	movl	%eax, -24588(%ebp)
	.loc 1 898 0
	movl	-24224(%ebp), %eax
	movl	%eax, -24584(%ebp)
	.loc 1 899 0
	movl	-24220(%ebp), %eax
	movl	%eax, -24580(%ebp)
	.loc 1 900 0
	movl	-24216(%ebp), %eax
	movl	%eax, -24576(%ebp)
	.loc 1 901 0
	movl	$0x00000000, %eax
	movl	%eax, -24616(%ebp)
	.loc 1 902 0
	movl	$0x00000000, %eax
	movl	%eax, -24612(%ebp)
	.loc 1 903 0
	movl	$0x00000000, %eax
	movl	%eax, -24608(%ebp)
	.loc 1 904 0
	movl	$0x00000000, %eax
	movl	%eax, -24604(%ebp)
	.loc 1 905 0
	movl	$0x00000000, %eax
	movl	%eax, -24600(%ebp)
	.loc 1 906 0
	jmp	.L181
.L185:
	.loc 1 910 0
	movl	-24088(%ebp), %eax
	movl	%eax, -24568(%ebp)
	.loc 1 911 0
	movl	-24084(%ebp), %eax
	movl	%eax, -24564(%ebp)
	.loc 1 912 0
	movl	-24080(%ebp), %eax
	movl	%eax, -24560(%ebp)
	.loc 1 913 0
	movl	-24076(%ebp), %eax
	movl	%eax, -24556(%ebp)
	.loc 1 914 0
	movl	-24072(%ebp), %eax
	movl	%eax, -24552(%ebp)
	.loc 1 915 0
	movl	-24232(%ebp), %eax
	movl	%eax, -24592(%ebp)
	.loc 1 916 0
	movl	-24228(%ebp), %eax
	movl	%eax, -24588(%ebp)
	.loc 1 917 0
	movl	-24224(%ebp), %eax
	movl	%eax, -24584(%ebp)
	.loc 1 918 0
	movl	-24220(%ebp), %eax
	movl	%eax, -24580(%ebp)
	.loc 1 919 0
	movl	-24216(%ebp), %eax
	movl	%eax, -24576(%ebp)
	.loc 1 920 0
	movl	$0x00000000, %eax
	movl	%eax, -24616(%ebp)
	.loc 1 921 0
	movl	$0x00000000, %eax
	movl	%eax, -24612(%ebp)
	.loc 1 922 0
	movl	$0x00000000, %eax
	movl	%eax, -24608(%ebp)
	.loc 1 923 0
	movl	$0x00000000, %eax
	movl	%eax, -24604(%ebp)
	.loc 1 924 0
	movl	$0x00000000, %eax
	movl	%eax, -24600(%ebp)
.L183:
	.loc 1 927 0
	movl	-24064(%ebp), %eax
	movl	%eax, -24496(%ebp)
	.loc 1 928 0
	movl	-24060(%ebp), %eax
	movl	%eax, -24492(%ebp)
	.loc 1 929 0
	movl	-24056(%ebp), %eax
	movl	%eax, -24488(%ebp)
	.loc 1 930 0
	movl	-24052(%ebp), %eax
	movl	%eax, -24484(%ebp)
	.loc 1 931 0
	movl	-24048(%ebp), %eax
	movl	%eax, -24480(%ebp)
	.loc 1 932 0
	movl	-24208(%ebp), %eax
	movl	%eax, -24520(%ebp)
	.loc 1 933 0
	movl	-24204(%ebp), %eax
	movl	%eax, -24516(%ebp)
	.loc 1 934 0
	movl	-24200(%ebp), %eax
	movl	%eax, -24512(%ebp)
	.loc 1 935 0
	movl	-24196(%ebp), %eax
	movl	%eax, -24508(%ebp)
	.loc 1 936 0
	movl	-24192(%ebp), %eax
	movl	%eax, -24504(%ebp)
	.loc 1 937 0
	movl	$0x00000000, %eax
	movl	%eax, -24544(%ebp)
	.loc 1 938 0
	movl	$0x00000000, %eax
	movl	%eax, -24540(%ebp)
	.loc 1 939 0
	movl	$0x00000000, %eax
	movl	%eax, -24536(%ebp)
	.loc 1 940 0
	movl	$0x00000000, %eax
	movl	%eax, -24532(%ebp)
	.loc 1 941 0
	movl	$0x00000000, %eax
	movl	%eax, -24528(%ebp)
.L181:
	.loc 1 944 0
	movl	$0x3f866666, %eax
	movl	%eax, -23828(%ebp)
	.loc 1 945 0
	fld1
	fdivs	-23828(%ebp)
	fstps	-23832(%ebp)
	.loc 1 948 0
	fldl	-24824(%ebp)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24640(%ebp)
	.loc 1 949 0
	fldl	-24816(%ebp)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24636(%ebp)
	.loc 1 950 0
	fldl	-24808(%ebp)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24632(%ebp)
	.loc 1 951 0
	fldl	-24800(%ebp)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24628(%ebp)
	.loc 1 952 0
	fldl	-24792(%ebp)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24624(%ebp)
	.loc 1 953 0
	fldz
	fstpl	8(%esp)
	movl	$0, 4(%esp)
	leal	-26752(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4bane10dcubicpolyEid
	fldl	.LC47
	fmulp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24664(%ebp)
	.loc 1 954 0
	fldz
	fstpl	8(%esp)
	movl	$1, 4(%esp)
	leal	-26752(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4bane10dcubicpolyEid
	fldl	.LC43
	fmulp	%st, %st(1)
	fldl	.LC42
	fdivrp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24660(%ebp)
	.loc 1 955 0
	fldz
	fstpl	8(%esp)
	movl	$2, 4(%esp)
	leal	-26752(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4bane10dcubicpolyEid
	fldl	.LC43
	fmulp	%st, %st(1)
	fldl	.LC42
	fdivrp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24656(%ebp)
	.loc 1 956 0
	fldz
	fstpl	8(%esp)
	movl	$3, 4(%esp)
	leal	-26752(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4bane10dcubicpolyEid
	fldl	.LC43
	fmulp	%st, %st(1)
	fldl	.LC42
	fdivrp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24652(%ebp)
	.loc 1 957 0
	fldz
	fstpl	8(%esp)
	movl	$4, 4(%esp)
	leal	-26752(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4bane10dcubicpolyEid
	fldl	.LC43
	fmulp	%st, %st(1)
	fldl	.LC42
	fdivrp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24648(%ebp)
	.loc 1 958 0
	flds	-24664(%ebp)
	fldl	.LC48
	fmulp	%st, %st(1)
	fstpl	-26912(%ebp)
	fldz
	fstpl	8(%esp)
	movl	$0, 4(%esp)
	leal	-26752(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4bane11ddcubicpolyEid
	fldl	.LC47
	fmulp	%st, %st(1)
	flds	-23832(%ebp)
	fmulp	%st, %st(1)
	faddl	-26912(%ebp)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24688(%ebp)
	.loc 1 959 0
	flds	-24660(%ebp)
	fldl	.LC48
	fmulp	%st, %st(1)
	fstpl	-26904(%ebp)
	fldz
	fstpl	8(%esp)
	movl	$1, 4(%esp)
	leal	-26752(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4bane11ddcubicpolyEid
	fldl	.LC43
	fmulp	%st, %st(1)
	fldl	.LC42
	fdivrp	%st, %st(1)
	flds	-23832(%ebp)
	fmulp	%st, %st(1)
	faddl	-26904(%ebp)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24684(%ebp)
	.loc 1 960 0
	flds	-24656(%ebp)
	fldl	.LC48
	fmulp	%st, %st(1)
	fstpl	-26896(%ebp)
	fldz
	fstpl	8(%esp)
	movl	$2, 4(%esp)
	leal	-26752(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4bane11ddcubicpolyEid
	fldl	.LC43
	fmulp	%st, %st(1)
	fldl	.LC42
	fdivrp	%st, %st(1)
	flds	-23832(%ebp)
	fmulp	%st, %st(1)
	faddl	-26896(%ebp)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24680(%ebp)
	.loc 1 961 0
	flds	-24652(%ebp)
	fldl	.LC48
	fmulp	%st, %st(1)
	fstpl	-26888(%ebp)
	fldz
	fstpl	8(%esp)
	movl	$3, 4(%esp)
	leal	-26752(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4bane11ddcubicpolyEid
	fldl	.LC43
	fmulp	%st, %st(1)
	fldl	.LC42
	fdivrp	%st, %st(1)
	flds	-23832(%ebp)
	fmulp	%st, %st(1)
	faddl	-26888(%ebp)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24676(%ebp)
	.loc 1 962 0
	flds	-24648(%ebp)
	fldl	.LC48
	fmulp	%st, %st(1)
	fstpl	-26880(%ebp)
	fldz
	fstpl	8(%esp)
	movl	$4, 4(%esp)
	leal	-26752(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4bane11ddcubicpolyEid
	fldl	.LC43
	fmulp	%st, %st(1)
	fldl	.LC42
	fdivrp	%st, %st(1)
	flds	-23832(%ebp)
	fmulp	%st, %st(1)
	faddl	-26880(%ebp)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24672(%ebp)
	.loc 1 964 0
	fldl	-24904(%ebp)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24712(%ebp)
	.loc 1 965 0
	fldl	-24896(%ebp)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24708(%ebp)
	.loc 1 966 0
	fldl	-24888(%ebp)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24704(%ebp)
	.loc 1 967 0
	fldl	-24880(%ebp)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24700(%ebp)
	.loc 1 968 0
	fldl	-24872(%ebp)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24696(%ebp)
	.loc 1 970 0
	fldl	-23936(%ebp)
	fldl	.LC49
	fmulp	%st, %st(1)
	fstps	-23836(%ebp)
	.loc 1 972 0
	flds	-23836(%ebp)
	fstpl	8(%esp)
	movl	$0, 4(%esp)
	leal	-26752(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4bane10dcubicpolyEid
	fldl	.LC47
	fmulp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24736(%ebp)
	.loc 1 973 0
	flds	-23836(%ebp)
	fstpl	8(%esp)
	movl	$1, 4(%esp)
	leal	-26752(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4bane10dcubicpolyEid
	fldl	.LC43
	fmulp	%st, %st(1)
	fldl	.LC42
	fdivrp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24732(%ebp)
	.loc 1 974 0
	flds	-23836(%ebp)
	fstpl	8(%esp)
	movl	$2, 4(%esp)
	leal	-26752(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4bane10dcubicpolyEid
	fldl	.LC43
	fmulp	%st, %st(1)
	fldl	.LC42
	fdivrp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24728(%ebp)
	.loc 1 975 0
	flds	-23836(%ebp)
	fstpl	8(%esp)
	movl	$3, 4(%esp)
	leal	-26752(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4bane10dcubicpolyEid
	fldl	.LC43
	fmulp	%st, %st(1)
	fldl	.LC42
	fdivrp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24724(%ebp)
	.loc 1 976 0
	flds	-23836(%ebp)
	fstpl	8(%esp)
	movl	$4, 4(%esp)
	leal	-26752(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4bane10dcubicpolyEid
	fldl	.LC43
	fmulp	%st, %st(1)
	fldl	.LC42
	fdivrp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24720(%ebp)
	.loc 1 977 0
	flds	-24736(%ebp)
	fldl	.LC48
	fmulp	%st, %st(1)
	fstpl	-26872(%ebp)
	flds	-23836(%ebp)
	fstpl	8(%esp)
	movl	$0, 4(%esp)
	leal	-26752(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4bane11ddcubicpolyEid
	fldl	.LC47
	fmulp	%st, %st(1)
	flds	-23832(%ebp)
	fmulp	%st, %st(1)
	faddl	-26872(%ebp)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24760(%ebp)
	.loc 1 978 0
	flds	-24732(%ebp)
	fldl	.LC48
	fmulp	%st, %st(1)
	fstpl	-26864(%ebp)
	flds	-23836(%ebp)
	fstpl	8(%esp)
	movl	$1, 4(%esp)
	leal	-26752(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4bane11ddcubicpolyEid
	fldl	.LC43
	fmulp	%st, %st(1)
	fldl	.LC42
	fdivrp	%st, %st(1)
	flds	-23832(%ebp)
	fmulp	%st, %st(1)
	faddl	-26864(%ebp)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24756(%ebp)
	.loc 1 979 0
	flds	-24728(%ebp)
	fldl	.LC48
	fmulp	%st, %st(1)
	fstpl	-26856(%ebp)
	flds	-23836(%ebp)
	fstpl	8(%esp)
	movl	$2, 4(%esp)
	leal	-26752(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4bane11ddcubicpolyEid
	fldl	.LC43
	fmulp	%st, %st(1)
	fldl	.LC42
	fdivrp	%st, %st(1)
	flds	-23832(%ebp)
	fmulp	%st, %st(1)
	faddl	-26856(%ebp)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24752(%ebp)
	.loc 1 980 0
	flds	-24724(%ebp)
	fldl	.LC48
	fmulp	%st, %st(1)
	fstpl	-26848(%ebp)
	flds	-23836(%ebp)
	fstpl	8(%esp)
	movl	$3, 4(%esp)
	leal	-26752(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4bane11ddcubicpolyEid
	fldl	.LC43
	fmulp	%st, %st(1)
	fldl	.LC42
	fdivrp	%st, %st(1)
	flds	-23832(%ebp)
	fmulp	%st, %st(1)
	faddl	-26848(%ebp)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24748(%ebp)
	.loc 1 981 0
	flds	-24720(%ebp)
	fldl	.LC48
	fmulp	%st, %st(1)
	fstpl	-26840(%ebp)
	flds	-23836(%ebp)
	fstpl	8(%esp)
	movl	$4, 4(%esp)
	leal	-26752(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4bane11ddcubicpolyEid
	fldl	.LC43
	fmulp	%st, %st(1)
	fldl	.LC42
	fdivrp	%st, %st(1)
	flds	-23832(%ebp)
	fmulp	%st, %st(1)
	faddl	-26840(%ebp)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24744(%ebp)
	.loc 1 984 0
	cmpl	$1, 28(%ebp)
	je	.L187
	cmpl	$3, 28(%ebp)
	jne	.L188
.L187:
.LBB34:
	.loc 1 986 0
	movl	$0x00000000, %eax
	movl	%eax, -23844(%ebp)
	movl	$0x40a00000, %eax
	movl	%eax, -23848(%ebp)
	.loc 1 987 0
	flds	-23848(%ebp)
	fadds	-23844(%ebp)
	flds	.LC18
	fmulp	%st, %st(1)
	fstps	-23852(%ebp)
	.loc 1 988 0
	movl	-23852(%ebp), %eax
	movl	%eax, -23840(%ebp)
	.loc 1 989 0
	flds	-23848(%ebp)
	fsubs	-23844(%ebp)
	fstps	-23856(%ebp)
	.loc 1 991 0
	jmp	.L189
.L197:
	.loc 1 993 0
	cmpl	$1, 92(%ebp)
	jne	.L190
	.loc 1 995 0
	movl	-26776(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	-23840(%ebp), %eax
	movl	%eax, 24(%esp)
	leal	-24688(%ebp), %eax
	movl	%eax, 20(%esp)
	leal	-24664(%ebp), %eax
	movl	%eax, 16(%esp)
	leal	-24640(%ebp), %eax
	movl	%eax, 12(%esp)
	leal	-24544(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-24520(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-24496(%ebp), %eax
	movl	%eax, (%esp)
	call	blendquinticmaxacc
	fstps	-23860(%ebp)
	.loc 1 996 0
	movl	-26772(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	-23840(%ebp), %eax
	movl	%eax, 24(%esp)
	leal	-24688(%ebp), %eax
	movl	%eax, 20(%esp)
	leal	-24664(%ebp), %eax
	movl	%eax, 16(%esp)
	leal	-24640(%ebp), %eax
	movl	%eax, 12(%esp)
	leal	-24544(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-24520(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-24496(%ebp), %eax
	movl	%eax, (%esp)
	call	blendquinticmaxvel
	fstps	-23864(%ebp)
	jmp	.L191
.L190:
	.loc 1 1000 0
	movl	-26776(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	-23840(%ebp), %eax
	movl	%eax, 16(%esp)
	leal	-24664(%ebp), %eax
	movl	%eax, 12(%esp)
	leal	-24640(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-24520(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-24496(%ebp), %eax
	movl	%eax, (%esp)
	call	blendcubicmaxacc
	fstps	-23860(%ebp)
	.loc 1 1001 0
	movl	-26772(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	-23840(%ebp), %eax
	movl	%eax, 16(%esp)
	leal	-24664(%ebp), %eax
	movl	%eax, 12(%esp)
	leal	-24640(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-24520(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-24496(%ebp), %eax
	movl	%eax, (%esp)
	call	blendcubicmaxvel
	fstps	-23864(%ebp)
.L191:
	.loc 1 1003 0
	flds	-23860(%ebp)
	flds	-23864(%ebp)
	fucompp
	fnstsw	%ax
	testb	$69, %ah
	sete	%al
	testb	%al, %al
	je	.L192
	.loc 1 1004 0
	movl	-23864(%ebp), %eax
	movl	%eax, -23860(%ebp)
.L192:
	.loc 1 1006 0
	flds	-23860(%ebp)
	fld1
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	seta	%al
	testb	%al, %al
	je	.L193
	.loc 1 1007 0
	movl	-23852(%ebp), %eax
	movl	%eax, -23844(%ebp)
	jmp	.L194
.L193:
	.loc 1 1009 0
	flds	-23860(%ebp)
	fld1
	fucompp
	fnstsw	%ax
	testb	$69, %ah
	sete	%al
	testb	%al, %al
	je	.L245
	.loc 1 1010 0
	movl	-23852(%ebp), %eax
	movl	%eax, -23848(%ebp)
.L194:
	.loc 1 1013 0
	flds	-23848(%ebp)
	fadds	-23844(%ebp)
	flds	.LC18
	fmulp	%st, %st(1)
	fstps	-23852(%ebp)
	.loc 1 1014 0
	movl	-23852(%ebp), %eax
	movl	%eax, -23840(%ebp)
	.loc 1 1015 0
	flds	-23848(%ebp)
	fsubs	-23844(%ebp)
	fstps	-23856(%ebp)
.L189:
	.loc 1 991 0
	flds	-23856(%ebp)
	fldl	.LC51
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	seta	%al
	testb	%al, %al
	jne	.L197
	jmp	.L196
.L245:
	.loc 1 1012 0
	nop
.L196:
	.loc 1 1018 0
	flds	-23840(%ebp)
	flds	.LC35
	fmulp	%st, %st(1)
	fldl	.LC17
	faddp	%st, %st(1)
	fnstcw	-26822(%ebp)
	movzwl	-26822(%ebp), %eax
	movb	$12, %ah
	movw	%ax, -26824(%ebp)
	fldcw	-26824(%ebp)
	fistpl	-23808(%ebp)
	fldcw	-26822(%ebp)
	.loc 1 1019 0
	flds	-23816(%ebp)
	fadds	-23840(%ebp)
	fstps	-23816(%ebp)
.L188:
.LBE34:
	.loc 1 1022 0
	cmpl	$2, 28(%ebp)
	je	.L198
	cmpl	$3, 28(%ebp)
	jne	.L250
.L198:
.LBB35:
	.loc 1 1024 0
	movl	$0x00000000, %eax
	movl	%eax, -23872(%ebp)
	movl	$0x40a00000, %eax
	movl	%eax, -23876(%ebp)
	.loc 1 1025 0
	flds	-23876(%ebp)
	fadds	-23872(%ebp)
	flds	.LC18
	fmulp	%st, %st(1)
	fstps	-23880(%ebp)
	.loc 1 1026 0
	movl	-23880(%ebp), %eax
	movl	%eax, -23868(%ebp)
	.loc 1 1028 0
	flds	-23876(%ebp)
	fsubs	-23872(%ebp)
	fstps	-23892(%ebp)
	.loc 1 1029 0
	jmp	.L200
.L208:
	.loc 1 1030 0
	cmpl	$1, 92(%ebp)
	jne	.L201
	.loc 1 1032 0
	movl	-26776(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	-23868(%ebp), %eax
	movl	%eax, 24(%esp)
	leal	-24616(%ebp), %eax
	movl	%eax, 20(%esp)
	leal	-24592(%ebp), %eax
	movl	%eax, 16(%esp)
	leal	-24568(%ebp), %eax
	movl	%eax, 12(%esp)
	leal	-24760(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-24736(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-24712(%ebp), %eax
	movl	%eax, (%esp)
	call	blendquinticmaxacc
	fstps	-23884(%ebp)
	.loc 1 1033 0
	movl	-26772(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	-23868(%ebp), %eax
	movl	%eax, 24(%esp)
	leal	-24616(%ebp), %eax
	movl	%eax, 20(%esp)
	leal	-24592(%ebp), %eax
	movl	%eax, 16(%esp)
	leal	-24568(%ebp), %eax
	movl	%eax, 12(%esp)
	leal	-24760(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-24736(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-24712(%ebp), %eax
	movl	%eax, (%esp)
	call	blendquinticmaxvel
	fstps	-23888(%ebp)
	jmp	.L202
.L201:
	.loc 1 1037 0
	movl	-26776(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	-23868(%ebp), %eax
	movl	%eax, 16(%esp)
	leal	-24592(%ebp), %eax
	movl	%eax, 12(%esp)
	leal	-24568(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-24736(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-24712(%ebp), %eax
	movl	%eax, (%esp)
	call	blendcubicmaxacc
	fstps	-23884(%ebp)
	.loc 1 1038 0
	movl	-26772(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	-23868(%ebp), %eax
	movl	%eax, 16(%esp)
	leal	-24592(%ebp), %eax
	movl	%eax, 12(%esp)
	leal	-24568(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-24736(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-24712(%ebp), %eax
	movl	%eax, (%esp)
	call	blendcubicmaxvel
	fstps	-23888(%ebp)
.L202:
	.loc 1 1040 0
	flds	-23884(%ebp)
	flds	-23888(%ebp)
	fucompp
	fnstsw	%ax
	testb	$69, %ah
	sete	%al
	testb	%al, %al
	je	.L203
	.loc 1 1041 0
	movl	-23888(%ebp), %eax
	movl	%eax, -23884(%ebp)
.L203:
	.loc 1 1044 0
	flds	-23884(%ebp)
	fld1
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	seta	%al
	testb	%al, %al
	je	.L204
	.loc 1 1045 0
	movl	-23880(%ebp), %eax
	movl	%eax, -23872(%ebp)
	jmp	.L205
.L204:
	.loc 1 1047 0
	flds	-23884(%ebp)
	fld1
	fucompp
	fnstsw	%ax
	testb	$69, %ah
	sete	%al
	testb	%al, %al
	je	.L246
	.loc 1 1048 0
	movl	-23880(%ebp), %eax
	movl	%eax, -23876(%ebp)
.L205:
	.loc 1 1051 0
	flds	-23876(%ebp)
	fadds	-23872(%ebp)
	flds	.LC18
	fmulp	%st, %st(1)
	fstps	-23880(%ebp)
	.loc 1 1052 0
	movl	-23880(%ebp), %eax
	movl	%eax, -23868(%ebp)
	.loc 1 1053 0
	flds	-23876(%ebp)
	fsubs	-23872(%ebp)
	fstps	-23892(%ebp)
.L200:
	.loc 1 1029 0
	flds	-23892(%ebp)
	fldl	.LC51
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	seta	%al
	testb	%al, %al
	jne	.L208
	jmp	.L207
.L246:
	.loc 1 1050 0
	nop
.L207:
	.loc 1 1056 0
	flds	-23868(%ebp)
	flds	.LC35
	fmulp	%st, %st(1)
	fldl	.LC17
	faddp	%st, %st(1)
	fnstcw	-26822(%ebp)
	movzwl	-26822(%ebp), %eax
	movb	$12, %ah
	movw	%ax, -26824(%ebp)
	fldcw	-26824(%ebp)
	fistpl	-23812(%ebp)
	fldcw	-26822(%ebp)
	.loc 1 1057 0
	flds	-23816(%ebp)
	fadds	-23868(%ebp)
	fstps	-23816(%ebp)
	jmp	.L199
.L250:
	fnstcw	-26822(%ebp)
	movzwl	-26822(%ebp), %eax
	movb	$12, %ah
	movw	%ax, -26824(%ebp)
.L199:
.LBE35:
	.loc 1 1063 0
	movl	-26812(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	.L209
	.loc 1 1064 0
	movl	-23820(%ebp), %eax
	addl	%eax, -23804(%ebp)
	.loc 1 1065 0
	flds	-23816(%ebp)
	fildl	-23820(%ebp)
	fldl	.LC52
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-23816(%ebp)
.L209:
	.loc 1 1067 0
	movl	-26816(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	je	.L210
	.loc 1 1068 0
	movl	-23824(%ebp), %eax
	addl	%eax, -23804(%ebp)
	.loc 1 1069 0
	flds	-23816(%ebp)
	fildl	-23824(%ebp)
	fldl	.LC52
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-23816(%ebp)
.L210:
	.loc 1 1071 0
	cmpl	$1, 28(%ebp)
	jne	.L211
	.loc 1 1072 0
	movl	-23808(%ebp), %eax
	addl	%eax, -23804(%ebp)
	jmp	.L212
.L211:
	.loc 1 1074 0
	cmpl	$2, 28(%ebp)
	jne	.L213
	.loc 1 1075 0
	movl	-23812(%ebp), %eax
	addl	%eax, -23804(%ebp)
	jmp	.L212
.L213:
	.loc 1 1077 0
	cmpl	$3, 28(%ebp)
	jne	.L212
	.loc 1 1078 0
	movl	-23812(%ebp), %eax
	movl	-23808(%ebp), %edx
	leal	(%edx,%eax), %eax
	addl	%eax, -23804(%ebp)
.L212:
	.loc 1 1080 0
	fildl	-23808(%ebp)
	fmuls	32(%ebp)
	fldl	.LC52
	fmulp	%st, %st(1)
	fldl	.LC17
	faddp	%st, %st(1)
	fldcw	-26824(%ebp)
	fistpl	-23896(%ebp)
	fldcw	-26822(%ebp)
	.loc 1 1081 0
	fildl	-23812(%ebp)
	fmuls	32(%ebp)
	fldl	.LC52
	fmulp	%st, %st(1)
	fldl	.LC17
	faddp	%st, %st(1)
	fldcw	-26824(%ebp)
	fistpl	-23900(%ebp)
	fldcw	-26822(%ebp)
	.loc 1 1082 0
	fildl	-23820(%ebp)
	fmuls	32(%ebp)
	fldl	.LC52
	fmulp	%st, %st(1)
	fldl	.LC17
	faddp	%st, %st(1)
	fldcw	-26824(%ebp)
	fistpl	-23904(%ebp)
	fldcw	-26822(%ebp)
	.loc 1 1083 0
	fildl	-23824(%ebp)
	fmuls	32(%ebp)
	fldl	.LC52
	fmulp	%st, %st(1)
	fldl	.LC17
	faddp	%st, %st(1)
	fldcw	-26824(%ebp)
	fistpl	-23908(%ebp)
	fldcw	-26822(%ebp)
	.loc 1 1084 0
	fldl	-23936(%ebp)
	fldl	.LC28
	fmulp	%st, %st(1)
	flds	32(%ebp)
	fmulp	%st, %st(1)
	fldl	.LC17
	faddp	%st, %st(1)
	fldcw	-26824(%ebp)
	fistpl	-23912(%ebp)
	fldcw	-26822(%ebp)
	.loc 1 1085 0
	movl	-23900(%ebp), %eax
	movl	-23896(%ebp), %edx
	leal	(%edx,%eax), %eax
	addl	-23912(%ebp), %eax
	addl	-23904(%ebp), %eax
	addl	-23908(%ebp), %eax
	movl	%eax, -23916(%ebp)
	.loc 1 1086 0
	fildl	-23804(%ebp)
	fld	%st(0)
	faddp	%st, %st(1)
	fildl	-23916(%ebp)
	fdivrp	%st, %st(1)
	fldcw	-26824(%ebp)
	fistpl	-26828(%ebp)
	fldcw	-26822(%ebp)
	movl	-26828(%ebp), %eax
	addl	%eax, -23804(%ebp)
	.loc 1 1087 0
	flds	-23816(%ebp)
	flds	-23816(%ebp)
	fld	%st(0)
	faddp	%st, %st(1)
	fildl	-23916(%ebp)
	fdivrp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-23816(%ebp)
	.loc 1 1092 0
	movl	-26812(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$2, %eax
	jne	.L214
	.loc 1 1093 0
	movl	-26812(%ebp), %eax
	movl	28(%eax), %eax
	cmpl	$2, %eax
	jne	.L215
	.loc 1 1094 0
	addl	$1, -23800(%ebp)
	.loc 1 1095 0
	movl	-26768(%ebp), %eax
	movl	25192(%eax), %edx
	movl	-26768(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%ecx,%eax), %eax
	leal	25196(%eax), %edx
	movl	-23800(%ebp), %eax
	movl	%eax, (%edx)
	.loc 1 1096 0
	movl	-26768(%ebp), %eax
	movl	25192(%eax), %edx
	movl	-26768(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%ecx,%eax), %eax
	addl	$25204, %eax
	movl	$-1, (%eax)
	.loc 1 1097 0
	movl	-26768(%ebp), %eax
	movl	25192(%eax), %edx
	movl	-26768(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%ecx,%eax), %eax
	addl	$25200, %eax
	movl	$0, (%eax)
	.loc 1 1098 0
	movl	-26768(%ebp), %eax
	movl	25192(%eax), %eax
	leal	1(%eax), %edx
	movl	-26768(%ebp), %eax
	movl	%edx, 25192(%eax)
.L215:
	.loc 1 1101 0
	movl	-26812(%ebp), %eax
	movl	24(%eax), %edx
	movl	-26812(%ebp), %eax
	movl	16(%eax), %eax
	movl	-23800(%ebp), %ecx
	movl	%ecx, 32(%esp)
	movl	36(%ebp), %ecx
	movl	%ecx, 28(%esp)
	movl	-23904(%ebp), %ecx
	movl	%ecx, 24(%esp)
	leal	-23992(%ebp), %ecx
	movl	%ecx, 20(%esp)
	movl	%edx, 16(%esp)
	movl	%eax, 12(%esp)
	movl	-23796(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-26768(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-23788(%ebp), %eax
	movl	%eax, (%esp)
	call	_Z11uplineMacroP9tmpnRobotP11tmpnPathDefPiffP10tmpnVectoriii
	.loc 1 1102 0
	movl	-26812(%ebp), %eax
	movl	28(%eax), %eax
	cmpl	$1, %eax
	jne	.L247
	.loc 1 1103 0
	addl	$1, -23800(%ebp)
	.loc 1 1104 0
	movl	-26768(%ebp), %eax
	movl	25192(%eax), %edx
	movl	-26768(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%ecx,%eax), %eax
	leal	25196(%eax), %edx
	movl	-23800(%ebp), %eax
	movl	%eax, (%edx)
	.loc 1 1105 0
	movl	-26768(%ebp), %eax
	movl	25192(%eax), %edx
	movl	-26768(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%ecx,%eax), %eax
	addl	$25204, %eax
	movl	$-1, (%eax)
	.loc 1 1106 0
	movl	-26768(%ebp), %eax
	movl	25192(%eax), %edx
	movl	-26768(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%ecx,%eax), %eax
	addl	$25200, %eax
	movl	$0, (%eax)
	.loc 1 1107 0
	movl	-26768(%ebp), %eax
	movl	25192(%eax), %eax
	leal	1(%eax), %edx
	movl	-26768(%ebp), %eax
	movl	%edx, 25192(%eax)
	jmp	.L217
.L214:
	.loc 1 1110 0
	movl	-26812(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$4, %eax
	jne	.L217
	.loc 1 1111 0
	movl	-26812(%ebp), %eax
	movl	28(%eax), %eax
	cmpl	$2, %eax
	jne	.L218
	.loc 1 1112 0
	addl	$1, -23800(%ebp)
	.loc 1 1113 0
	movl	-26768(%ebp), %eax
	movl	25192(%eax), %edx
	movl	-26768(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%ecx,%eax), %eax
	leal	25196(%eax), %edx
	movl	-23800(%ebp), %eax
	movl	%eax, (%edx)
	.loc 1 1114 0
	movl	-26768(%ebp), %eax
	movl	25192(%eax), %edx
	movl	-26768(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%ecx,%eax), %eax
	addl	$25204, %eax
	movl	$-1, (%eax)
	.loc 1 1115 0
	movl	-26768(%ebp), %eax
	movl	25192(%eax), %edx
	movl	-26768(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%ecx,%eax), %eax
	addl	$25200, %eax
	movl	$0, (%eax)
	.loc 1 1116 0
	movl	-26768(%ebp), %eax
	movl	25192(%eax), %eax
	leal	1(%eax), %edx
	movl	-26768(%ebp), %eax
	movl	%edx, 25192(%eax)
.L218:
	.loc 1 1119 0
	movl	-26812(%ebp), %eax
	movl	24(%eax), %edx
	movl	-26812(%ebp), %eax
	movl	16(%eax), %eax
	movl	-23800(%ebp), %ecx
	movl	%ecx, 32(%esp)
	movl	36(%ebp), %ecx
	movl	%ecx, 28(%esp)
	movl	-23904(%ebp), %ecx
	movl	%ecx, 24(%esp)
	leal	-23992(%ebp), %ecx
	movl	%ecx, 20(%esp)
	movl	%edx, 16(%esp)
	movl	%eax, 12(%esp)
	movl	-23796(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-26768(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-23788(%ebp), %eax
	movl	%eax, (%esp)
	call	_Z15fastUplineMacroP9tmpnRobotP11tmpnPathDefPiffP10tmpnVectoriii
	.loc 1 1120 0
	movl	-26812(%ebp), %eax
	movl	28(%eax), %eax
	cmpl	$1, %eax
	jne	.L217
	.loc 1 1121 0
	addl	$1, -23800(%ebp)
	.loc 1 1122 0
	movl	-26768(%ebp), %eax
	movl	25192(%eax), %edx
	movl	-26768(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%ecx,%eax), %eax
	leal	25196(%eax), %edx
	movl	-23800(%ebp), %eax
	movl	%eax, (%edx)
	.loc 1 1123 0
	movl	-26768(%ebp), %eax
	movl	25192(%eax), %edx
	movl	-26768(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%ecx,%eax), %eax
	addl	$25204, %eax
	movl	$-1, (%eax)
	.loc 1 1124 0
	movl	-26768(%ebp), %eax
	movl	25192(%eax), %edx
	movl	-26768(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%ecx,%eax), %eax
	addl	$25200, %eax
	movl	$0, (%eax)
	.loc 1 1125 0
	movl	-26768(%ebp), %eax
	movl	25192(%eax), %eax
	leal	1(%eax), %edx
	movl	-26768(%ebp), %eax
	movl	%edx, 25192(%eax)
	jmp	.L217
.L247:
	.loc 1 1107 0
	nop
.L217:
	.loc 1 1129 0
	cmpl	$1, 28(%ebp)
	je	.L219
	cmpl	$3, 28(%ebp)
	jne	.L220
.L219:
	.loc 1 1130 0
	cmpl	$1, 92(%ebp)
	jne	.L221
	.loc 1 1131 0
	fildl	-23808(%ebp)
	fldl	.LC52
	fmulp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	movl	$0, 52(%esp)
	movl	-23800(%ebp), %eax
	movl	%eax, 48(%esp)
	leal	-23788(%ebp), %eax
	movl	%eax, 44(%esp)
	movl	36(%ebp), %eax
	movl	%eax, 40(%esp)
	movl	-23896(%ebp), %eax
	movl	%eax, 36(%esp)
	fstps	32(%esp)
	leal	-24688(%ebp), %eax
	movl	%eax, 28(%esp)
	leal	-24664(%ebp), %eax
	movl	%eax, 24(%esp)
	leal	-24640(%ebp), %eax
	movl	%eax, 20(%esp)
	leal	-24544(%ebp), %eax
	movl	%eax, 16(%esp)
	leal	-24520(%ebp), %eax
	movl	%eax, 12(%esp)
	leal	-24496(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-23796(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-26768(%ebp), %eax
	movl	%eax, (%esp)
	call	blendquintic
	jmp	.L220
.L221:
	.loc 1 1133 0
	fildl	-23808(%ebp)
	fldl	.LC52
	fmulp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	movl	$0, 44(%esp)
	movl	-23800(%ebp), %eax
	movl	%eax, 40(%esp)
	leal	-23788(%ebp), %eax
	movl	%eax, 36(%esp)
	movl	36(%ebp), %eax
	movl	%eax, 32(%esp)
	movl	-23896(%ebp), %eax
	movl	%eax, 28(%esp)
	fstps	24(%esp)
	leal	-24664(%ebp), %eax
	movl	%eax, 20(%esp)
	leal	-24640(%ebp), %eax
	movl	%eax, 16(%esp)
	leal	-24520(%ebp), %eax
	movl	%eax, 12(%esp)
	leal	-24496(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-23796(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-26768(%ebp), %eax
	movl	%eax, (%esp)
	call	blendcubic
.L220:
.LBB36:
	.loc 1 1140 0
	movl	$0, -23920(%ebp)
	jmp	.L222
.L227:
.LBB37:
	.loc 1 1142 0
	fildl	-23920(%ebp)
	fldl	.LC28
	fmulp	%st, %st(1)
	fldl	-23936(%ebp)
	fmulp	%st, %st(1)
	fildl	-23912(%ebp)
	fdivrp	%st, %st(1)
	fstpl	-23944(%ebp)
	.loc 1 1143 0
	movl	-23920(%ebp), %eax
	cmpl	-23912(%ebp), %eax
	jne	.L223
	.loc 1 1144 0
	cmpl	$2, 28(%ebp)
	je	.L248
	cmpl	$3, 28(%ebp)
	je	.L249
.L225:
	.loc 1 1145 0
	fldl	-23936(%ebp)
	fldl	.LC53
	fmulp	%st, %st(1)
	fstpl	-23944(%ebp)
.L223:
	.loc 1 1147 0
	fldl	-23944(%ebp)
	fstpl	8(%esp)
	movl	$0, 4(%esp)
	leal	-26752(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4bane9cubicpolyEid
	fldl	.LC47
	fmulp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24784(%ebp)
	.loc 1 1148 0
	fldl	-23944(%ebp)
	fstpl	8(%esp)
	movl	$1, 4(%esp)
	leal	-26752(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4bane9cubicpolyEid
	fldl	.LC43
	fmulp	%st, %st(1)
	fldl	.LC42
	fdivrp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24780(%ebp)
	.loc 1 1149 0
	fldl	-23944(%ebp)
	fstpl	8(%esp)
	movl	$2, 4(%esp)
	leal	-26752(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4bane9cubicpolyEid
	fldl	.LC43
	fmulp	%st, %st(1)
	fldl	.LC42
	fdivrp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24776(%ebp)
	.loc 1 1150 0
	fldl	-23944(%ebp)
	fstpl	8(%esp)
	movl	$3, 4(%esp)
	leal	-26752(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4bane9cubicpolyEid
	fldl	.LC43
	fmulp	%st, %st(1)
	fldl	.LC42
	fdivrp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24772(%ebp)
	.loc 1 1151 0
	fldl	-23944(%ebp)
	fstpl	8(%esp)
	movl	$4, 4(%esp)
	leal	-26752(%ebp), %eax
	movl	%eax, (%esp)
	call	_ZN4bane9cubicpolyEid
	fldl	.LC43
	fmulp	%st, %st(1)
	fldl	.LC42
	fdivrp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	fstps	-24768(%ebp)
	.loc 1 1152 0
	movl	$0x00000000, %eax
	movl	%eax, -24764(%ebp)
	.loc 1 1154 0
	movl	-24764(%ebp), %edi
	movl	-24768(%ebp), %esi
	movl	-24772(%ebp), %ebx
	movl	-24776(%ebp), %ecx
	movl	-24780(%ebp), %edx
	movl	-24784(%ebp), %eax
	movl	%eax, -26960(%ebp)
	movl	36(%ebp), %eax
	movl	%eax, -26948(%ebp)
	movl	-26948(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	%edi, 24(%esp)
	movl	%esi, 20(%esp)
	movl	%ebx, 16(%esp)
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	-26960(%ebp), %edx
	movl	%edx, 4(%esp)
	leal	-23788(%ebp), %eax
	movl	%eax, (%esp)
	call	tmpnComputeFKlogic
	.loc 1 1155 0
	movl	-23792(%ebp), %edx
	movl	-22472(%ebp), %ecx
	movl	-26768(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$320, %eax
	movl	%ecx, (%eax)
	.loc 1 1156 0
	movl	-23792(%ebp), %edx
	movl	-22468(%ebp), %ecx
	movl	-26768(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$324, %eax
	movl	%ecx, (%eax)
	.loc 1 1157 0
	movl	-23792(%ebp), %edx
	movl	-22464(%ebp), %ecx
	movl	-26768(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$328, %eax
	movl	%ecx, (%eax)
	.loc 1 1158 0
	movl	-23792(%ebp), %edx
	movl	-22460(%ebp), %ecx
	movl	-26768(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$332, %eax
	movl	%ecx, (%eax)
	.loc 1 1159 0
	movl	-23792(%ebp), %edx
	movl	-22456(%ebp), %ecx
	movl	-26768(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$336, %eax
	movl	%ecx, (%eax)
	.loc 1 1160 0
	movl	-23792(%ebp), %edx
	movl	-22452(%ebp), %ecx
	movl	-26768(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$340, %eax
	movl	%ecx, (%eax)
	.loc 1 1161 0
	movl	-23792(%ebp), %edx
	movl	-26768(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	leal	308(%eax), %edx
	movl	36(%ebp), %eax
	movl	%eax, (%edx)
	.loc 1 1162 0
	movl	-23792(%ebp), %edx
	fildl	-23800(%ebp)
	movl	-26768(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	addl	$316, %eax
	fstps	(%eax)
	.loc 1 1163 0
	movl	-23792(%ebp), %edx
	movl	-26768(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	addl	$312, %eax
	movl	$0, (%eax)
	.loc 1 1164 0
	movl	-23792(%ebp), %edx
	movl	-26768(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	leal	344(%eax), %edx
	movl	$0x41200000, %eax
	movl	%eax, (%edx)
	.loc 1 1165 0
	movl	-23792(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -23792(%ebp)
.LBE37:
	.loc 1 1140 0
	addl	$1, -23920(%ebp)
.L222:
	movl	-23912(%ebp), %eax
	addl	$1, %eax
	cmpl	-23920(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L227
	jmp	.L226
.L248:
.LBB38:
	.loc 1 1144 0
	nop
	jmp	.L226
.L249:
	nop
.L226:
.LBE38:
.LBE36:
	.loc 1 1171 0
	cmpl	$2, 28(%ebp)
	je	.L228
	cmpl	$3, 28(%ebp)
	jne	.L229
.L228:
.LBB39:
	.loc 1 1172 0
	movl	$0, -23924(%ebp)
	.loc 1 1173 0
	movl	-26816(%ebp), %eax
	movl	(%eax), %eax
	testl	%eax, %eax
	jne	.L230
	movl	$1, -23924(%ebp)
.L230:
	.loc 1 1174 0
	cmpl	$1, 92(%ebp)
	jne	.L231
	.loc 1 1175 0
	fildl	-23812(%ebp)
	fldl	.LC52
	fmulp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	movl	-23924(%ebp), %eax
	movl	%eax, 52(%esp)
	movl	-23800(%ebp), %eax
	movl	%eax, 48(%esp)
	leal	-23788(%ebp), %eax
	movl	%eax, 44(%esp)
	movl	40(%ebp), %eax
	movl	%eax, 40(%esp)
	movl	-23900(%ebp), %eax
	movl	%eax, 36(%esp)
	fstps	32(%esp)
	leal	-24616(%ebp), %eax
	movl	%eax, 28(%esp)
	leal	-24592(%ebp), %eax
	movl	%eax, 24(%esp)
	leal	-24568(%ebp), %eax
	movl	%eax, 20(%esp)
	leal	-24760(%ebp), %eax
	movl	%eax, 16(%esp)
	leal	-24736(%ebp), %eax
	movl	%eax, 12(%esp)
	leal	-24712(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-23796(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-26768(%ebp), %eax
	movl	%eax, (%esp)
	call	blendquintic
	jmp	.L229
.L231:
	.loc 1 1177 0
	fildl	-23812(%ebp)
	fldl	.LC52
	fmulp	%st, %st(1)
	fstps	-26820(%ebp)
	flds	-26820(%ebp)
	movl	-23924(%ebp), %eax
	movl	%eax, 44(%esp)
	movl	-23800(%ebp), %eax
	movl	%eax, 40(%esp)
	leal	-23788(%ebp), %eax
	movl	%eax, 36(%esp)
	movl	40(%ebp), %eax
	movl	%eax, 32(%esp)
	movl	-23900(%ebp), %eax
	movl	%eax, 28(%esp)
	fstps	24(%esp)
	leal	-24592(%ebp), %eax
	movl	%eax, 20(%esp)
	leal	-24568(%ebp), %eax
	movl	%eax, 16(%esp)
	leal	-24736(%ebp), %eax
	movl	%eax, 12(%esp)
	leal	-24712(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-23796(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-26768(%ebp), %eax
	movl	%eax, (%esp)
	call	blendcubic
.L229:
.LBE39:
	.loc 1 1181 0
	movl	-26816(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$1, %eax
	jne	.L232
	.loc 1 1182 0
	movl	-26816(%ebp), %eax
	movl	28(%eax), %eax
	cmpl	$2, %eax
	jne	.L233
	.loc 1 1183 0
	addl	$1, -23800(%ebp)
	.loc 1 1184 0
	movl	-26768(%ebp), %eax
	movl	25192(%eax), %edx
	movl	-26768(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%ecx,%eax), %eax
	leal	25196(%eax), %edx
	movl	-23800(%ebp), %eax
	movl	%eax, (%edx)
	.loc 1 1185 0
	movl	-26768(%ebp), %eax
	movl	25192(%eax), %edx
	movl	-26768(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%ecx,%eax), %eax
	addl	$25204, %eax
	movl	$-1, (%eax)
	.loc 1 1186 0
	movl	-26768(%ebp), %eax
	movl	25192(%eax), %edx
	movl	-26768(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%ecx,%eax), %eax
	addl	$25200, %eax
	movl	$0, (%eax)
	.loc 1 1187 0
	movl	-26768(%ebp), %eax
	movl	25192(%eax), %eax
	leal	1(%eax), %edx
	movl	-26768(%ebp), %eax
	movl	%edx, 25192(%eax)
.L233:
	.loc 1 1189 0
	movl	-26816(%ebp), %eax
	movl	24(%eax), %ecx
	movl	%ecx, -26832(%ebp)
	movl	-26816(%ebp), %eax
	movl	20(%eax), %edi
	movl	-26816(%ebp), %eax
	movl	16(%eax), %esi
	movl	-26816(%ebp), %eax
	movl	12(%eax), %ebx
	movl	-26816(%ebp), %eax
	movl	8(%eax), %ecx
	movl	-26816(%ebp), %eax
	movl	4(%eax), %edx
	movl	-23800(%ebp), %eax
	movl	%eax, 48(%esp)
	movl	40(%ebp), %eax
	movl	%eax, 44(%esp)
	movl	-23908(%ebp), %eax
	movl	%eax, 40(%esp)
	leal	-23968(%ebp), %eax
	movl	%eax, 36(%esp)
	movl	-26832(%ebp), %eax
	movl	%eax, 32(%esp)
	movl	%edi, 28(%esp)
	movl	%esi, 24(%esp)
	movl	%ebx, 20(%esp)
	movl	%ecx, 16(%esp)
	movl	%edx, 12(%esp)
	movl	-23796(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-26768(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-23788(%ebp), %eax
	movl	%eax, (%esp)
	call	_Z11spiralMacroP9tmpnRobotP11tmpnPathDefPiffffffP10tmpnVectoriii
	jmp	.L234
.L232:
	.loc 1 1191 0
	movl	-26816(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$3, %eax
	jne	.L235
	.loc 1 1192 0
	movl	-26816(%ebp), %eax
	movl	28(%eax), %eax
	cmpl	$2, %eax
	jne	.L236
	.loc 1 1193 0
	addl	$1, -23800(%ebp)
	.loc 1 1194 0
	movl	-26768(%ebp), %eax
	movl	25192(%eax), %edx
	movl	-26768(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%ecx,%eax), %eax
	leal	25196(%eax), %edx
	movl	-23800(%ebp), %eax
	movl	%eax, (%edx)
	.loc 1 1195 0
	movl	-26768(%ebp), %eax
	movl	25192(%eax), %edx
	movl	-26768(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%ecx,%eax), %eax
	addl	$25204, %eax
	movl	$-1, (%eax)
	.loc 1 1196 0
	movl	-26768(%ebp), %eax
	movl	25192(%eax), %edx
	movl	-26768(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%ecx,%eax), %eax
	addl	$25200, %eax
	movl	$0, (%eax)
	.loc 1 1197 0
	movl	-26768(%ebp), %eax
	movl	25192(%eax), %eax
	leal	1(%eax), %edx
	movl	-26768(%ebp), %eax
	movl	%edx, 25192(%eax)
.L236:
	.loc 1 1199 0
	movl	-26816(%ebp), %eax
	movl	24(%eax), %edx
	movl	-26816(%ebp), %eax
	movl	16(%eax), %eax
	movl	-23800(%ebp), %ecx
	movl	%ecx, 32(%esp)
	movl	40(%ebp), %ecx
	movl	%ecx, 28(%esp)
	movl	-23908(%ebp), %ecx
	movl	%ecx, 24(%esp)
	leal	-23968(%ebp), %ecx
	movl	%ecx, 20(%esp)
	movl	%edx, 16(%esp)
	movl	%eax, 12(%esp)
	movl	-23796(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-26768(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-23788(%ebp), %eax
	movl	%eax, (%esp)
	call	_Z13downlineMacroP9tmpnRobotP11tmpnPathDefPiffP10tmpnVectoriii
	jmp	.L234
.L235:
	.loc 1 1201 0
	movl	-26816(%ebp), %eax
	movl	(%eax), %eax
	cmpl	$5, %eax
	jne	.L234
	.loc 1 1202 0
	movl	-26816(%ebp), %eax
	movl	28(%eax), %eax
	cmpl	$2, %eax
	jne	.L237
	.loc 1 1203 0
	addl	$1, -23800(%ebp)
	.loc 1 1204 0
	movl	-26768(%ebp), %eax
	movl	25192(%eax), %edx
	movl	-26768(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%ecx,%eax), %eax
	leal	25196(%eax), %edx
	movl	-23800(%ebp), %eax
	movl	%eax, (%edx)
	.loc 1 1205 0
	movl	-26768(%ebp), %eax
	movl	25192(%eax), %edx
	movl	-26768(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%ecx,%eax), %eax
	addl	$25204, %eax
	movl	$-1, (%eax)
	.loc 1 1206 0
	movl	-26768(%ebp), %eax
	movl	25192(%eax), %edx
	movl	-26768(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$2, %eax
	leal	(%ecx,%eax), %eax
	addl	$25200, %eax
	movl	$0, (%eax)
	.loc 1 1207 0
	movl	-26768(%ebp), %eax
	movl	25192(%eax), %eax
	leal	1(%eax), %edx
	movl	-26768(%ebp), %eax
	movl	%edx, 25192(%eax)
.L237:
	.loc 1 1209 0
	movl	-26816(%ebp), %eax
	movl	24(%eax), %edx
	movl	-26816(%ebp), %eax
	movl	16(%eax), %eax
	movl	-23800(%ebp), %ecx
	movl	%ecx, 32(%esp)
	movl	40(%ebp), %ecx
	movl	%ecx, 28(%esp)
	movl	-23908(%ebp), %ecx
	movl	%ecx, 24(%esp)
	leal	-23968(%ebp), %ecx
	movl	%ecx, 20(%esp)
	movl	%edx, 16(%esp)
	movl	%eax, 12(%esp)
	movl	-23796(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-26768(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	-23788(%ebp), %eax
	movl	%eax, (%esp)
	call	_Z17fastDownlineMacroP9tmpnRobotP11tmpnPathDefPiffP10tmpnVectoriii
.L234:
	.loc 1 1212 0
	movl	-23792(%ebp), %edx
	movl	-23792(%ebp), %eax
	leal	-1(%eax), %ecx
	movl	-26768(%ebp), %ebx
	movl	%ecx, %eax
	addl	%eax, %eax
	addl	%ecx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$320, %eax
	movl	(%eax), %ecx
	movl	-26768(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$320, %eax
	movl	%ecx, (%eax)
	.loc 1 1213 0
	movl	-23792(%ebp), %edx
	movl	-23792(%ebp), %eax
	leal	-1(%eax), %ecx
	movl	-26768(%ebp), %ebx
	movl	%ecx, %eax
	addl	%eax, %eax
	addl	%ecx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$324, %eax
	movl	(%eax), %ecx
	movl	-26768(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$324, %eax
	movl	%ecx, (%eax)
	.loc 1 1214 0
	movl	-23792(%ebp), %edx
	movl	-23792(%ebp), %eax
	leal	-1(%eax), %ecx
	movl	-26768(%ebp), %ebx
	movl	%ecx, %eax
	addl	%eax, %eax
	addl	%ecx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$328, %eax
	movl	(%eax), %ecx
	movl	-26768(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$328, %eax
	movl	%ecx, (%eax)
	.loc 1 1215 0
	movl	-23792(%ebp), %edx
	movl	-23792(%ebp), %eax
	leal	-1(%eax), %ecx
	movl	-26768(%ebp), %ebx
	movl	%ecx, %eax
	addl	%eax, %eax
	addl	%ecx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$332, %eax
	movl	(%eax), %ecx
	movl	-26768(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$332, %eax
	movl	%ecx, (%eax)
	.loc 1 1216 0
	movl	-23792(%ebp), %edx
	movl	-23792(%ebp), %eax
	leal	-1(%eax), %ecx
	movl	-26768(%ebp), %ebx
	movl	%ecx, %eax
	addl	%eax, %eax
	addl	%ecx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$336, %eax
	movl	(%eax), %ecx
	movl	-26768(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$336, %eax
	movl	%ecx, (%eax)
	.loc 1 1217 0
	movl	-23792(%ebp), %edx
	movl	-23792(%ebp), %eax
	leal	-1(%eax), %ecx
	movl	-26768(%ebp), %ebx
	movl	%ecx, %eax
	addl	%eax, %eax
	addl	%ecx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$340, %eax
	movl	(%eax), %ecx
	movl	-26768(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$340, %eax
	movl	%ecx, (%eax)
	.loc 1 1218 0
	movl	-23792(%ebp), %edx
	movl	-23792(%ebp), %eax
	leal	-1(%eax), %ecx
	movl	-26768(%ebp), %ebx
	movl	%ecx, %eax
	addl	%eax, %eax
	addl	%ecx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$308, %eax
	movl	(%eax), %ecx
	movl	-26768(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$308, %eax
	movl	%ecx, (%eax)
	.loc 1 1219 0
	movl	-23792(%ebp), %edx
	movl	-23792(%ebp), %eax
	leal	-1(%eax), %ecx
	movl	-26768(%ebp), %ebx
	movl	%ecx, %eax
	addl	%eax, %eax
	addl	%ecx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$316, %eax
	movl	(%eax), %ecx
	movl	-26768(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$316, %eax
	movl	%ecx, (%eax)
	.loc 1 1220 0
	movl	-23792(%ebp), %edx
	movl	-26768(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	addl	$312, %eax
	movl	$0, (%eax)
	.loc 1 1221 0
	movl	-23792(%ebp), %edx
	movl	-26768(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	leal	344(%eax), %edx
	movl	$0x41200000, %eax
	movl	%eax, (%edx)
	.loc 1 1222 0
	movl	-23792(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -23792(%ebp)
	.loc 1 1225 0
	movl	-26768(%ebp), %eax
	movl	368(%eax), %edx
	movl	-26768(%ebp), %eax
	movl	%edx, 320(%eax)
	.loc 1 1226 0
	movl	-26768(%ebp), %eax
	movl	372(%eax), %edx
	movl	-26768(%ebp), %eax
	movl	%edx, 324(%eax)
	.loc 1 1227 0
	movl	-26768(%ebp), %eax
	movl	376(%eax), %edx
	movl	-26768(%ebp), %eax
	movl	%edx, 328(%eax)
	.loc 1 1228 0
	movl	-26768(%ebp), %eax
	movl	380(%eax), %edx
	movl	-26768(%ebp), %eax
	movl	%edx, 332(%eax)
	.loc 1 1229 0
	movl	-26768(%ebp), %eax
	movl	384(%eax), %edx
	movl	-26768(%ebp), %eax
	movl	%edx, 336(%eax)
	.loc 1 1230 0
	movl	-26768(%ebp), %eax
	movl	388(%eax), %edx
	movl	-26768(%ebp), %eax
	movl	%edx, 340(%eax)
	.loc 1 1231 0
	movl	-26768(%ebp), %eax
	movl	356(%eax), %edx
	movl	-26768(%ebp), %eax
	movl	%edx, 308(%eax)
	.loc 1 1232 0
	movl	-26768(%ebp), %eax
	movl	$0x00000000, %edx
	movl	%edx, 316(%eax)
	.loc 1 1233 0
	movl	-26768(%ebp), %eax
	movl	$0, 312(%eax)
	.loc 1 1234 0
	movl	-26768(%ebp), %eax
	movl	$0x41200000, %edx
	movl	%edx, 344(%eax)
	.loc 1 1237 0
	flds	96(%ebp)
	flds	.LC35
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jp	.L251
	je	.L238
.L251:
.L244:
.LBB40:
	.loc 1 1239 0
	movl	$0, -23928(%ebp)
	jmp	.L240
.L241:
	.loc 1 1241 0
	movl	-23928(%ebp), %edx
	movl	-26768(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	leal	332(%eax), %edx
	movl	96(%ebp), %eax
	movl	%eax, (%edx)
	.loc 1 1239 0
	addl	$1, -23928(%ebp)
.L240:
	movl	-23792(%ebp), %eax
	cmpl	%eax, -23928(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L241
.L238:
.LBE40:
	.loc 1 1244 0
	fildl	-23804(%ebp)
	movl	-26768(%ebp), %eax
	fstps	300(%eax)
	.loc 1 1246 0
	movl	-23792(%ebp), %edx
	movl	-26768(%ebp), %eax
	movl	%edx, 268(%eax)
	.loc 1 1248 0
	movl	-26764(%ebp), %eax
	movl	10748(%eax), %edx
	movl	-26768(%ebp), %eax
	movl	%edx, 288(%eax)
	.loc 1 1249 0
	movl	-26764(%ebp), %eax
	movl	10752(%eax), %edx
	movl	-26768(%ebp), %eax
	movl	%edx, 296(%eax)
	.loc 1 1251 0
	movl	-23816(%ebp), %eax
	movl	%eax, -26956(%ebp)
	flds	-26956(%ebp)
.LBE33:
	.loc 1 1252 0
	movl	-28(%ebp), %edx
	xorl	%gs:20, %edx
	je	.L243
	fstp	%st(0)
	call	__stack_chk_fail
.L243:
	addl	$27212, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.cfi_endproc
.LFE28:
	.size	trajopt, .-trajopt
.globl _Z7uniformdd
	.type	_Z7uniformdd, @function
_Z7uniformdd:
.LFB29:
	.loc 1 1255 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
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
	movl	%eax, -16(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, -24(%ebp)
	movl	20(%ebp), %eax
	movl	%eax, -20(%ebp)
.LBB41:
	.loc 1 1257 0
	fldl	-24(%ebp)
	fsubl	-16(%ebp)
	fstpl	-40(%ebp)
	call	rand
	movl	%eax, -28(%ebp)
	fildl	-28(%ebp)
	fldl	-40(%ebp)
	fmulp	%st, %st(1)
	fldl	.LC54
	fdivrp	%st, %st(1)
	faddl	-16(%ebp)
.LBE41:
	.loc 1 1258 0
	leave
	ret
	.cfi_endproc
.LFE29:
	.size	_Z7uniformdd, .-_Z7uniformdd
.globl _Z11randomindexi
	.type	_Z11randomindexi, @function
_Z11randomindexi:
.LFB30:
	.loc 1 1261 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI42:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI43:
	.cfi_def_cfa_register 5
	subl	$24, %esp
	call	mcount
	.loc 1 1261 0
	.loc 1 1262 0
	fildl	8(%ebp)
	fstpl	-24(%ebp)
	call	rand
	movl	%eax, -12(%ebp)
	fildl	-12(%ebp)
	fldl	-24(%ebp)
	fmulp	%st, %st(1)
	fldl	.LC55
	fdivrp	%st, %st(1)
	fnstcw	-14(%ebp)
	movzwl	-14(%ebp), %eax
	movb	$12, %ah
	movw	%ax, -16(%ebp)
	fldcw	-16(%ebp)
	fistpl	-12(%ebp)
	fldcw	-14(%ebp)
	movl	-12(%ebp), %eax
	.loc 1 1263 0
	leave
	ret
	.cfi_endproc
.LFE30:
	.size	_Z11randomindexi, .-_Z11randomindexi
.globl _Z3VADddddddPdS_
	.type	_Z3VADddddddPdS_, @function
_Z3VADddddddPdS_:
.LFB31:
	.loc 1 1265 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI44:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI45:
	.cfi_def_cfa_register 5
	subl	$96, %esp
	call	mcount
	movl	8(%ebp), %eax
	movl	%eax, -56(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -52(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, -64(%ebp)
	movl	20(%ebp), %eax
	movl	%eax, -60(%ebp)
	movl	24(%ebp), %eax
	movl	%eax, -72(%ebp)
	movl	28(%ebp), %eax
	movl	%eax, -68(%ebp)
	movl	32(%ebp), %eax
	movl	%eax, -80(%ebp)
	movl	36(%ebp), %eax
	movl	%eax, -76(%ebp)
	movl	40(%ebp), %eax
	movl	%eax, -88(%ebp)
	movl	44(%ebp), %eax
	movl	%eax, -84(%ebp)
	movl	48(%ebp), %eax
	movl	%eax, -96(%ebp)
	movl	52(%ebp), %eax
	movl	%eax, -92(%ebp)
.LBB42:
	.loc 1 1268 0
	fldl	-56(%ebp)
	fsubl	-64(%ebp)
	fldl	-56(%ebp)
	fsubl	-72(%ebp)
	fmulp	%st, %st(1)
	fldl	-80(%ebp)
	fdivp	%st, %st(1)
	fstpl	-24(%ebp)
	.loc 1 1269 0
	fldl	-64(%ebp)
	fsubl	-56(%ebp)
	fldl	-64(%ebp)
	fsubl	-72(%ebp)
	fmulp	%st, %st(1)
	fldl	-88(%ebp)
	fdivp	%st, %st(1)
	fstpl	-32(%ebp)
	.loc 1 1270 0
	fldl	-72(%ebp)
	fsubl	-56(%ebp)
	fldl	-72(%ebp)
	fsubl	-64(%ebp)
	fmulp	%st, %st(1)
	fldl	-96(%ebp)
	fdivp	%st, %st(1)
	fstpl	-40(%ebp)
	.loc 1 1271 0
	fldl	-24(%ebp)
	faddl	-32(%ebp)
	faddl	-40(%ebp)
	fstpl	-8(%ebp)
	.loc 1 1272 0
	fldl	-56(%ebp)
	faddl	-64(%ebp)
	fmull	-40(%ebp)
	fldl	-56(%ebp)
	faddl	-72(%ebp)
	fmull	-32(%ebp)
	faddp	%st, %st(1)
	fldl	-64(%ebp)
	faddl	-72(%ebp)
	fmull	-24(%ebp)
	faddp	%st, %st(1)
	fchs
	fstpl	-16(%ebp)
	.loc 1 1273 0
	fldl	-8(%ebp)
	fadd	%st(0), %st
	movl	60(%ebp), %eax
	fstpl	(%eax)
	.loc 1 1274 0
	movl	60(%ebp), %eax
	fldl	(%eax)
	fmull	-64(%ebp)
	faddl	-16(%ebp)
	movl	56(%ebp), %eax
	fstpl	(%eax)
.LBE42:
	.loc 1 1275 0
	leave
	ret
	.cfi_endproc
.LFE31:
	.size	_Z3VADddddddPdS_, .-_Z3VADddddddPdS_
	.section	.rodata
	.align 4
.LC56:
	.string	"\n------------------before--------------------------"
	.align 4
.LC57:
	.string	"%0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f\n"
.LC63:
	.string	"BINGO!!! %i %0.4f %0.4f\n"
	.align 4
.LC64:
	.string	"\n------------------after--------------------------"
	.text
.globl jerkMinimizer
	.type	jerkMinimizer, @function
jerkMinimizer:
.LFB32:
	.loc 1 1278 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI46:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI47:
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$160860, %esp
	call	mcount
	.loc 1 1278 0
.LBB43:
	.loc 1 1279 0
	movl	$0, (%esp)
	.cfi_offset 3, -20
	.cfi_offset 6, -16
	.cfi_offset 7, -12
	call	time
	movl	%eax, (%esp)
	call	srand
	.loc 1 1280 0
	movl	$.LC56, (%esp)
	call	puts
	.loc 1 1281 0
	movl	$0, -28(%ebp)
	movl	$0, -32(%ebp)
	.loc 1 1282 0
	movl	12(%ebp), %eax
	flds	300(%eax)
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fldl	.LC47
	fmulp	%st, %st(1)
	fdivrp	%st, %st(1)
	fstps	-36(%ebp)
	.loc 1 1288 0
	fldz
	fstpl	-80432(%ebp)
	.loc 1 1289 0
	fldz
	fstpl	-80424(%ebp)
	.loc 1 1290 0
	fldz
	fstpl	-80416(%ebp)
	.loc 1 1291 0
	fldz
	fstpl	-80408(%ebp)
	.loc 1 1292 0
	fldz
	fstpl	-80400(%ebp)
	.loc 1 1293 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$80408, %eax
	fldz
	fstpl	(%eax)
	.loc 1 1294 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$80408, %eax
	fldz
	fstpl	8(%eax)
	.loc 1 1295 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$80392, %eax
	fldz
	fstpl	(%eax)
	.loc 1 1296 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$80392, %eax
	fldz
	fstpl	8(%eax)
	.loc 1 1297 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$80376, %eax
	fldz
	fstpl	(%eax)
	.loc 1 1298 0
	movl	$0, -28(%ebp)
	jmp	.L259
.L260:
	.loc 1 1300 0
	movl	-28(%ebp), %edx
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	addl	$340, %eax
	movl	(%eax), %edx
	movl	%edx, -160672(%ebp)
	movl	-28(%ebp), %edx
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	addl	$336, %eax
	movl	(%eax), %edx
	movl	%edx, -160668(%ebp)
	movl	-28(%ebp), %edx
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	addl	$332, %eax
	movl	(%eax), %edi
	movl	-28(%ebp), %edx
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	addl	$328, %eax
	movl	(%eax), %esi
	movl	-28(%ebp), %edx
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	addl	$324, %eax
	movl	(%eax), %ebx
	movl	-28(%ebp), %edx
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	addl	$320, %eax
	movl	(%eax), %eax
	movl	16(%ebp), %edx
	movl	%edx, 28(%esp)
	movl	-160672(%ebp), %edx
	movl	%edx, 24(%esp)
	movl	-160668(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	tmpnComputeIK
	.loc 1 1301 0
	movl	-28(%ebp), %edx
	movl	8(%ebp), %eax
	flds	2284(%eax)
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$40408, %eax
	fstpl	(%eax)
	.loc 1 1302 0
	movl	-28(%ebp), %edx
	movl	8(%ebp), %eax
	flds	2288(%eax)
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$40408, %eax
	fstpl	8(%eax)
	.loc 1 1303 0
	movl	-28(%ebp), %edx
	movl	8(%ebp), %eax
	flds	2292(%eax)
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$40392, %eax
	fstpl	(%eax)
	.loc 1 1304 0
	movl	-28(%ebp), %edx
	movl	8(%ebp), %eax
	flds	2296(%eax)
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$40392, %eax
	fstpl	8(%eax)
	.loc 1 1305 0
	movl	-28(%ebp), %edx
	movl	8(%ebp), %eax
	flds	2300(%eax)
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$40376, %eax
	fstpl	(%eax)
	.loc 1 1298 0
	addl	$1, -28(%ebp)
.L259:
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	cmpl	-28(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L260
	.loc 1 1307 0
	movl	$1, -28(%ebp)
	jmp	.L261
.L264:
	.loc 1 1309 0
	movl	$0, -32(%ebp)
	jmp	.L262
.L263:
	.loc 1 1311 0
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	leal	-80432(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	addl	%eax, %ecx
	movl	-28(%ebp), %eax
	leal	1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-40432(%ebp,%eax,8)
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-40432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	leal	-1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-40432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fildl	-28(%ebp)
	fmuls	-36(%ebp)
	movl	-28(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fxch	%st(5)
	leal	-72(%ebp), %eax
	movl	%eax, 52(%esp)
	movl	%ecx, 48(%esp)
	fstpl	40(%esp)
	fxch	%st(3)
	fstpl	32(%esp)
	fxch	%st(1)
	fstpl	24(%esp)
	fstpl	16(%esp)
	fstpl	8(%esp)
	fstpl	(%esp)
	call	_Z3VADddddddPdS_
	.loc 1 1309 0
	addl	$1, -32(%ebp)
.L262:
	cmpl	$4, -32(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L263
	.loc 1 1307 0
	addl	$1, -28(%ebp)
.L261:
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	subl	$1, %eax
	cmpl	-28(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L264
	.loc 1 1314 0
	fldz
	fstpl	-120432(%ebp)
	.loc 1 1315 0
	fldz
	fstpl	-120424(%ebp)
	.loc 1 1316 0
	fldz
	fstpl	-120416(%ebp)
	.loc 1 1317 0
	fldz
	fstpl	-120408(%ebp)
	.loc 1 1318 0
	fldz
	fstpl	-120400(%ebp)
	.loc 1 1319 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$120408, %eax
	fldz
	fstpl	(%eax)
	.loc 1 1320 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$120408, %eax
	fldz
	fstpl	8(%eax)
	.loc 1 1321 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$120392, %eax
	fldz
	fstpl	(%eax)
	.loc 1 1322 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$120392, %eax
	fldz
	fstpl	8(%eax)
	.loc 1 1323 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$120376, %eax
	fldz
	fstpl	(%eax)
	.loc 1 1324 0
	movl	$1, -28(%ebp)
	jmp	.L265
.L268:
	.loc 1 1326 0
	movl	$0, -32(%ebp)
	jmp	.L266
.L267:
	.loc 1 1328 0
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	leal	-120432(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	addl	%eax, %ecx
	movl	-28(%ebp), %eax
	leal	1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-80432(%ebp,%eax,8)
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-80432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	leal	-1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-80432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fildl	-28(%ebp)
	fmuls	-36(%ebp)
	movl	-28(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fxch	%st(5)
	leal	-72(%ebp), %eax
	movl	%eax, 52(%esp)
	movl	%ecx, 48(%esp)
	fstpl	40(%esp)
	fxch	%st(3)
	fstpl	32(%esp)
	fxch	%st(1)
	fstpl	24(%esp)
	fstpl	16(%esp)
	fstpl	8(%esp)
	fstpl	(%esp)
	call	_Z3VADddddddPdS_
	.loc 1 1326 0
	addl	$1, -32(%ebp)
.L266:
	cmpl	$4, -32(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L267
	.loc 1 1324 0
	addl	$1, -28(%ebp)
.L265:
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	subl	$1, %eax
	cmpl	-28(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L268
	.loc 1 1331 0
	fldz
	fstpl	-160432(%ebp)
	.loc 1 1332 0
	fldz
	fstpl	-160424(%ebp)
	.loc 1 1333 0
	fldz
	fstpl	-160416(%ebp)
	.loc 1 1334 0
	fldz
	fstpl	-160408(%ebp)
	.loc 1 1335 0
	fldz
	fstpl	-160400(%ebp)
	.loc 1 1336 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160408, %eax
	fldz
	fstpl	(%eax)
	.loc 1 1337 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160408, %eax
	fldz
	fstpl	8(%eax)
	.loc 1 1338 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160392, %eax
	fldz
	fstpl	(%eax)
	.loc 1 1339 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160392, %eax
	fldz
	fstpl	8(%eax)
	.loc 1 1340 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160376, %eax
	fldz
	fstpl	(%eax)
	.loc 1 1341 0
	movl	$1, -28(%ebp)
	jmp	.L269
.L272:
	.loc 1 1343 0
	movl	$0, -32(%ebp)
	jmp	.L270
.L271:
	.loc 1 1345 0
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	leal	-160432(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	addl	%eax, %ecx
	movl	-28(%ebp), %eax
	leal	1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-120432(%ebp,%eax,8)
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-120432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	leal	-1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-120432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fildl	-28(%ebp)
	fmuls	-36(%ebp)
	movl	-28(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fxch	%st(5)
	leal	-72(%ebp), %eax
	movl	%eax, 52(%esp)
	movl	%ecx, 48(%esp)
	fstpl	40(%esp)
	fxch	%st(3)
	fstpl	32(%esp)
	fxch	%st(1)
	fstpl	24(%esp)
	fstpl	16(%esp)
	fstpl	8(%esp)
	fstpl	(%esp)
	call	_Z3VADddddddPdS_
	.loc 1 1343 0
	addl	$1, -32(%ebp)
.L270:
	cmpl	$4, -32(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L271
	.loc 1 1341 0
	addl	$1, -28(%ebp)
.L269:
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	subl	$1, %eax
	cmpl	-28(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L272
	.loc 1 1348 0
	movl	$0, -28(%ebp)
	jmp	.L273
.L274:
	.loc 1 1350 0
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160376, %eax
	fldl	(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160376, %eax
	fldl	(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fmulp	%st, %st(1)
	fstpl	-160664(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$120376, %eax
	fldl	(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fstpl	-160656(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$80376, %eax
	fldl	(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fstpl	-160648(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$40376, %eax
	fldl	(%eax)
	fstpl	-160640(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160392, %eax
	fldl	8(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160392, %eax
	fldl	8(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fmulp	%st, %st(1)
	fstpl	-160632(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$120392, %eax
	fldl	8(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fstpl	-160624(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$80392, %eax
	fldl	8(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fstpl	-160616(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$40392, %eax
	fldl	8(%eax)
	fstpl	-160608(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160392, %eax
	fldl	(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160392, %eax
	fldl	(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fmulp	%st, %st(1)
	fstpl	-160600(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$120392, %eax
	fldl	(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fstpl	-160592(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$80392, %eax
	fldl	(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fstpl	-160584(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$40392, %eax
	fldl	(%eax)
	fstpl	-160576(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160408, %eax
	fldl	8(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160408, %eax
	fldl	8(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fmulp	%st, %st(1)
	fstpl	-160568(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$120408, %eax
	fldl	8(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$80408, %eax
	fldl	8(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$40408, %eax
	fldl	8(%eax)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160408, %eax
	fldl	(%eax)
	fldl	.LC41
	fmulp	%st, %st(1)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160408, %eax
	fldl	(%eax)
	fldl	.LC41
	fmulp	%st, %st(1)
	fmulp	%st, %st(1)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$120408, %eax
	fldl	(%eax)
	fldl	.LC41
	fmulp	%st, %st(1)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$80408, %eax
	fldl	(%eax)
	fldl	.LC41
	fmulp	%st, %st(1)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$40408, %eax
	fldl	(%eax)
	fildl	-28(%ebp)
	fmuls	-36(%ebp)
	fstpl	-160688(%ebp)
	fldl	-160664(%ebp)
	fstpl	164(%esp)
	fldl	-160656(%ebp)
	fstpl	156(%esp)
	fldl	-160648(%ebp)
	fstpl	148(%esp)
	fldl	-160640(%ebp)
	fstpl	140(%esp)
	fldl	-160632(%ebp)
	fstpl	132(%esp)
	fldl	-160624(%ebp)
	fstpl	124(%esp)
	fldl	-160616(%ebp)
	fstpl	116(%esp)
	fldl	-160608(%ebp)
	fstpl	108(%esp)
	fldl	-160600(%ebp)
	fstpl	100(%esp)
	fldl	-160592(%ebp)
	fstpl	92(%esp)
	fldl	-160584(%ebp)
	fstpl	84(%esp)
	fldl	-160576(%ebp)
	fstpl	76(%esp)
	fldl	-160568(%ebp)
	fstpl	68(%esp)
	fxch	%st(6)
	fstpl	60(%esp)
	fxch	%st(4)
	fstpl	52(%esp)
	fxch	%st(2)
	fstpl	44(%esp)
	fstpl	36(%esp)
	fstpl	28(%esp)
	fstpl	20(%esp)
	fstpl	12(%esp)
	fldl	-160688(%ebp)
	fstpl	4(%esp)
	movl	$.LC57, (%esp)
	call	printf
	.loc 1 1348 0
	addl	$1, -28(%ebp)
.L273:
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	cmpl	-28(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L274
	.loc 1 1353 0
	movl	$0, -44(%ebp)
	.loc 1 1357 0
	movl	$0, -40(%ebp)
	jmp	.L275
.L314:
.LBB44:
	.loc 1 1359 0
	movl	12(%ebp), %eax
	flds	300(%eax)
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fldl	.LC47
	fmulp	%st, %st(1)
	fdivrp	%st, %st(1)
	fstps	-36(%ebp)
	.loc 1 1360 0
	fldz
	fstpl	-80432(%ebp)
	fldz
	fstpl	-80424(%ebp)
	fldz
	fstpl	-80416(%ebp)
	fldz
	fstpl	-80408(%ebp)
	fldz
	fstpl	-80400(%ebp)
	.loc 1 1361 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$80408, %eax
	fldz
	fstpl	(%eax)
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$80408, %eax
	fldz
	fstpl	8(%eax)
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$80392, %eax
	fldz
	fstpl	(%eax)
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$80392, %eax
	fldz
	fstpl	8(%eax)
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$80376, %eax
	fldz
	fstpl	(%eax)
	.loc 1 1362 0
	movl	$1, -28(%ebp)
	jmp	.L276
.L279:
	.loc 1 1364 0
	movl	$0, -32(%ebp)
	jmp	.L277
.L278:
	.loc 1 1366 0
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	leal	-80432(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	addl	%eax, %ecx
	movl	-28(%ebp), %eax
	leal	1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-40432(%ebp,%eax,8)
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-40432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	leal	-1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-40432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fildl	-28(%ebp)
	fmuls	-36(%ebp)
	movl	-28(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fxch	%st(5)
	leal	-72(%ebp), %eax
	movl	%eax, 52(%esp)
	movl	%ecx, 48(%esp)
	fstpl	40(%esp)
	fxch	%st(3)
	fstpl	32(%esp)
	fxch	%st(1)
	fstpl	24(%esp)
	fstpl	16(%esp)
	fstpl	8(%esp)
	fstpl	(%esp)
	call	_Z3VADddddddPdS_
	.loc 1 1364 0
	addl	$1, -32(%ebp)
.L277:
	cmpl	$4, -32(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L278
	.loc 1 1362 0
	addl	$1, -28(%ebp)
.L276:
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	subl	$1, %eax
	cmpl	-28(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L279
	.loc 1 1369 0
	fldz
	fstpl	-120432(%ebp)
	fldz
	fstpl	-120424(%ebp)
	fldz
	fstpl	-120416(%ebp)
	fldz
	fstpl	-120408(%ebp)
	fldz
	fstpl	-120400(%ebp)
	.loc 1 1370 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$120408, %eax
	fldz
	fstpl	(%eax)
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$120408, %eax
	fldz
	fstpl	8(%eax)
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$120392, %eax
	fldz
	fstpl	(%eax)
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$120392, %eax
	fldz
	fstpl	8(%eax)
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$120376, %eax
	fldz
	fstpl	(%eax)
	.loc 1 1371 0
	movl	$1, -28(%ebp)
	jmp	.L280
.L283:
	.loc 1 1373 0
	movl	$0, -32(%ebp)
	jmp	.L281
.L282:
	.loc 1 1375 0
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	leal	-120432(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	addl	%eax, %ecx
	movl	-28(%ebp), %eax
	leal	1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-80432(%ebp,%eax,8)
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-80432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	leal	-1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-80432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fildl	-28(%ebp)
	fmuls	-36(%ebp)
	movl	-28(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fxch	%st(5)
	leal	-72(%ebp), %eax
	movl	%eax, 52(%esp)
	movl	%ecx, 48(%esp)
	fstpl	40(%esp)
	fxch	%st(3)
	fstpl	32(%esp)
	fxch	%st(1)
	fstpl	24(%esp)
	fstpl	16(%esp)
	fstpl	8(%esp)
	fstpl	(%esp)
	call	_Z3VADddddddPdS_
	.loc 1 1373 0
	addl	$1, -32(%ebp)
.L281:
	cmpl	$4, -32(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L282
	.loc 1 1371 0
	addl	$1, -28(%ebp)
.L280:
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	subl	$1, %eax
	cmpl	-28(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L283
	.loc 1 1378 0
	fldz
	fstpl	-160432(%ebp)
	fldz
	fstpl	-160424(%ebp)
	fldz
	fstpl	-160416(%ebp)
	fldz
	fstpl	-160408(%ebp)
	fldz
	fstpl	-160400(%ebp)
	.loc 1 1379 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160408, %eax
	fldz
	fstpl	(%eax)
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160408, %eax
	fldz
	fstpl	8(%eax)
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160392, %eax
	fldz
	fstpl	(%eax)
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160392, %eax
	fldz
	fstpl	8(%eax)
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160376, %eax
	fldz
	fstpl	(%eax)
	.loc 1 1380 0
	movl	$1, -28(%ebp)
	jmp	.L284
.L287:
	.loc 1 1382 0
	movl	$0, -32(%ebp)
	jmp	.L285
.L286:
	.loc 1 1384 0
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	leal	-160432(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	addl	%eax, %ecx
	movl	-28(%ebp), %eax
	leal	1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-120432(%ebp,%eax,8)
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-120432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	leal	-1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-120432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fildl	-28(%ebp)
	fmuls	-36(%ebp)
	movl	-28(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fxch	%st(5)
	leal	-72(%ebp), %eax
	movl	%eax, 52(%esp)
	movl	%ecx, 48(%esp)
	fstpl	40(%esp)
	fxch	%st(3)
	fstpl	32(%esp)
	fxch	%st(1)
	fstpl	24(%esp)
	fstpl	16(%esp)
	fstpl	8(%esp)
	fstpl	(%esp)
	call	_Z3VADddddddPdS_
	.loc 1 1382 0
	addl	$1, -32(%ebp)
.L285:
	cmpl	$4, -32(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L286
	.loc 1 1380 0
	addl	$1, -28(%ebp)
.L284:
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	subl	$1, %eax
	cmpl	-28(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L287
	.loc 1 1390 0
	movl	$0, -32(%ebp)
	jmp	.L288
.L313:
	.loc 1 1392 0
	movl	$1, -28(%ebp)
	jmp	.L289
.L290:
	.loc 1 1394 0
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	leal	-80432(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	addl	%eax, %ecx
	movl	-28(%ebp), %eax
	leal	1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-40432(%ebp,%eax,8)
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-40432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	leal	-1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-40432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fildl	-28(%ebp)
	fmuls	-36(%ebp)
	movl	-28(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fxch	%st(5)
	leal	-72(%ebp), %eax
	movl	%eax, 52(%esp)
	movl	%ecx, 48(%esp)
	fstpl	40(%esp)
	fxch	%st(3)
	fstpl	32(%esp)
	fxch	%st(1)
	fstpl	24(%esp)
	fstpl	16(%esp)
	fstpl	8(%esp)
	fstpl	(%esp)
	call	_Z3VADddddddPdS_
	.loc 1 1392 0
	addl	$1, -28(%ebp)
.L289:
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	subl	$1, %eax
	cmpl	-28(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L290
	.loc 1 1396 0
	movl	$1, -28(%ebp)
	jmp	.L291
.L292:
	.loc 1 1398 0
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	leal	-120432(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	addl	%eax, %ecx
	movl	-28(%ebp), %eax
	leal	1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-80432(%ebp,%eax,8)
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-80432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	leal	-1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-80432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fildl	-28(%ebp)
	fmuls	-36(%ebp)
	movl	-28(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fxch	%st(5)
	leal	-72(%ebp), %eax
	movl	%eax, 52(%esp)
	movl	%ecx, 48(%esp)
	fstpl	40(%esp)
	fxch	%st(3)
	fstpl	32(%esp)
	fxch	%st(1)
	fstpl	24(%esp)
	fstpl	16(%esp)
	fstpl	8(%esp)
	fstpl	(%esp)
	call	_Z3VADddddddPdS_
	.loc 1 1396 0
	addl	$1, -28(%ebp)
.L291:
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	subl	$1, %eax
	cmpl	-28(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L292
	.loc 1 1400 0
	movl	$1, -28(%ebp)
	jmp	.L293
.L294:
	.loc 1 1402 0
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	leal	-160432(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	addl	%eax, %ecx
	movl	-28(%ebp), %eax
	leal	1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-120432(%ebp,%eax,8)
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-120432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	leal	-1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-120432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fildl	-28(%ebp)
	fmuls	-36(%ebp)
	movl	-28(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fxch	%st(5)
	leal	-72(%ebp), %eax
	movl	%eax, 52(%esp)
	movl	%ecx, 48(%esp)
	fstpl	40(%esp)
	fxch	%st(3)
	fstpl	32(%esp)
	fxch	%st(1)
	fstpl	24(%esp)
	fstpl	16(%esp)
	fstpl	8(%esp)
	fstpl	(%esp)
	call	_Z3VADddddddPdS_
	.loc 1 1400 0
	addl	$1, -28(%ebp)
.L293:
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	subl	$1, %eax
	cmpl	-28(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L294
	.loc 1 1404 0
	movl	$0x00000000, %eax
	movl	%eax, -48(%ebp)
	.loc 1 1405 0
	movl	$2, -44(%ebp)
	.loc 1 1406 0
	movl	$2, -28(%ebp)
	jmp	.L295
.L297:
	.loc 1 1408 0
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ecx, %eax
	fldl	-160432(%ebp,%eax,8)
	fstps	-56(%ebp)
	.loc 1 1409 0
	flds	-56(%ebp)
	fmuls	-56(%ebp)
	fstps	-56(%ebp)
	.loc 1 1410 0
	flds	-56(%ebp)
	flds	-48(%ebp)
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	seta	%al
	testb	%al, %al
	je	.L296
	.loc 1 1412 0
	movl	-56(%ebp), %eax
	movl	%eax, -48(%ebp)
	.loc 1 1413 0
	movl	-28(%ebp), %eax
	movl	%eax, -44(%ebp)
.L296:
	.loc 1 1406 0
	addl	$1, -28(%ebp)
.L295:
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	subl	$2, %eax
	cmpl	-28(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L297
	.loc 1 1416 0
	cmpl	$1, -44(%ebp)
	jle	.L298
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	subl	$3, %eax
	cmpl	-44(%ebp), %eax
	jl	.L298
	.loc 1 1418 0
	fld1
	fstpl	8(%esp)
	fldz
	fstpl	(%esp)
	call	_Z7uniformdd
	fldl	.LC17
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	setae	%al
	testb	%al, %al
	je	.L299
	.loc 1 1419 0
	movl	$2, (%esp)
	call	_Z11randomindexi
	addl	%eax, -44(%ebp)
	jmp	.L298
.L299:
	.loc 1 1421 0
	movl	$2, (%esp)
	call	_Z11randomindexi
	subl	%eax, -44(%ebp)
.L298:
	.loc 1 1425 0
	movl	$0x00000000, %eax
	movl	%eax, -56(%ebp)
	.loc 1 1426 0
	movl	$0, -28(%ebp)
	jmp	.L300
.L301:
	.loc 1 1428 0
	flds	-56(%ebp)
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ecx, %eax
	fldl	-160432(%ebp,%eax,8)
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ecx, %eax
	fldl	-160432(%ebp,%eax,8)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-56(%ebp)
	.loc 1 1426 0
	addl	$1, -28(%ebp)
.L300:
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	cmpl	-28(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L301
	.loc 1 1430 0
	movl	-56(%ebp), %eax
	movl	%eax, -52(%ebp)
	.loc 1 1433 0
	movl	-32(%ebp), %ecx
	movl	-44(%ebp), %eax
	leal	-1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-40432(%ebp,%eax,8)
	fstpl	-352(%ebp,%ecx,8)
	.loc 1 1434 0
	movl	-32(%ebp), %ecx
	movl	-44(%ebp), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-40432(%ebp,%eax,8)
	fstpl	-392(%ebp,%ecx,8)
	.loc 1 1435 0
	movl	-32(%ebp), %ecx
	movl	-44(%ebp), %eax
	leal	1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-40432(%ebp,%eax,8)
	fstpl	-432(%ebp,%ecx,8)
	.loc 1 1436 0
	movl	$0, -60(%ebp)
	jmp	.L302
.L312:
	.loc 1 1438 0
	movl	-32(%ebp), %ecx
	movl	-44(%ebp), %eax
	leal	-1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-40432(%ebp,%eax,8)
	fstpl	-232(%ebp,%ecx,8)
	.loc 1 1439 0
	movl	-32(%ebp), %ecx
	movl	-44(%ebp), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-40432(%ebp,%eax,8)
	fstpl	-272(%ebp,%ecx,8)
	.loc 1 1440 0
	movl	-32(%ebp), %ecx
	movl	-44(%ebp), %eax
	leal	1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-40432(%ebp,%eax,8)
	fstpl	-312(%ebp,%ecx,8)
	.loc 1 1441 0
	movl	-32(%ebp), %ebx
	movl	-44(%ebp), %eax
	leal	-1(%eax), %edx
	movl	-32(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ecx, %eax
	fldl	-40432(%ebp,%eax,8)
	movl	-40(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fldl	.LC59
	fdivp	%st, %st(1)
	fldl	.LC60
	faddp	%st, %st(1)
	movl	-44(%ebp), %edx
	movl	-32(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ecx, %eax
	fldl	-40432(%ebp,%eax,8)
	movl	-44(%ebp), %eax
	leal	-1(%eax), %edx
	movl	-32(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ecx, %eax
	fldl	-40432(%ebp,%eax,8)
	fsubrp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-44(%ebp), %eax
	leal	-1(%eax), %edx
	movl	-32(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ecx, %eax
	fldl	-40432(%ebp,%eax,8)
	fxch	%st(1)
	fstpl	8(%esp)
	fstpl	(%esp)
	call	_Z7uniformdd
	fstpl	-112(%ebp,%ebx,8)
	.loc 1 1442 0
	movl	-32(%ebp), %ebx
	movl	-44(%ebp), %edx
	movl	-32(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ecx, %eax
	fldl	-40432(%ebp,%eax,8)
	fldl	.LC61
	fmulp	%st, %st(1)
	movl	-44(%ebp), %edx
	movl	-32(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ecx, %eax
	fldl	-40432(%ebp,%eax,8)
	fldl	.LC62
	fmulp	%st, %st(1)
	fxch	%st(1)
	fstpl	8(%esp)
	fstpl	(%esp)
	call	_Z7uniformdd
	fstpl	-152(%ebp,%ebx,8)
	.loc 1 1443 0
	movl	-32(%ebp), %ebx
	movl	-44(%ebp), %eax
	leal	1(%eax), %edx
	movl	-32(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ecx, %eax
	fldl	-40432(%ebp,%eax,8)
	movl	-40(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fldl	.LC59
	fdivp	%st, %st(1)
	fldl	.LC60
	faddp	%st, %st(1)
	movl	-44(%ebp), %edx
	movl	-32(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ecx, %eax
	fldl	-40432(%ebp,%eax,8)
	movl	-44(%ebp), %eax
	leal	1(%eax), %edx
	movl	-32(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ecx, %eax
	fldl	-40432(%ebp,%eax,8)
	fsubrp	%st, %st(1)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-44(%ebp), %eax
	leal	1(%eax), %edx
	movl	-32(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ecx, %eax
	fldl	-40432(%ebp,%eax,8)
	fxch	%st(1)
	fstpl	8(%esp)
	fstpl	(%esp)
	call	_Z7uniformdd
	fstpl	-192(%ebp,%ebx,8)
	.loc 1 1444 0
	movl	-44(%ebp), %eax
	leal	-1(%eax), %edx
	movl	-32(%ebp), %ecx
	movl	-32(%ebp), %eax
	fldl	-112(%ebp,%eax,8)
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ecx, %eax
	fstpl	-40432(%ebp,%eax,8)
	.loc 1 1445 0
	movl	-44(%ebp), %edx
	movl	-32(%ebp), %ecx
	movl	-32(%ebp), %eax
	fldl	-152(%ebp,%eax,8)
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ecx, %eax
	fstpl	-40432(%ebp,%eax,8)
	.loc 1 1446 0
	movl	-44(%ebp), %eax
	leal	1(%eax), %edx
	movl	-32(%ebp), %ecx
	movl	-32(%ebp), %eax
	fldl	-192(%ebp,%eax,8)
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ecx, %eax
	fstpl	-40432(%ebp,%eax,8)
	.loc 1 1448 0
	movl	$1, -28(%ebp)
	jmp	.L303
.L304:
	.loc 1 1450 0
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	leal	-80432(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	addl	%eax, %ecx
	movl	-28(%ebp), %eax
	leal	1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-40432(%ebp,%eax,8)
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-40432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	leal	-1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-40432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fildl	-28(%ebp)
	fmuls	-36(%ebp)
	movl	-28(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fxch	%st(5)
	leal	-72(%ebp), %eax
	movl	%eax, 52(%esp)
	movl	%ecx, 48(%esp)
	fstpl	40(%esp)
	fxch	%st(3)
	fstpl	32(%esp)
	fxch	%st(1)
	fstpl	24(%esp)
	fstpl	16(%esp)
	fstpl	8(%esp)
	fstpl	(%esp)
	call	_Z3VADddddddPdS_
	.loc 1 1448 0
	addl	$1, -28(%ebp)
.L303:
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	subl	$1, %eax
	cmpl	-28(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L304
	.loc 1 1452 0
	movl	$1, -28(%ebp)
	jmp	.L305
.L306:
	.loc 1 1454 0
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	leal	-120432(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	addl	%eax, %ecx
	movl	-28(%ebp), %eax
	leal	1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-80432(%ebp,%eax,8)
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-80432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	leal	-1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-80432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fildl	-28(%ebp)
	fmuls	-36(%ebp)
	movl	-28(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fxch	%st(5)
	leal	-72(%ebp), %eax
	movl	%eax, 52(%esp)
	movl	%ecx, 48(%esp)
	fstpl	40(%esp)
	fxch	%st(3)
	fstpl	32(%esp)
	fxch	%st(1)
	fstpl	24(%esp)
	fstpl	16(%esp)
	fstpl	8(%esp)
	fstpl	(%esp)
	call	_Z3VADddddddPdS_
	.loc 1 1452 0
	addl	$1, -28(%ebp)
.L305:
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	subl	$1, %eax
	cmpl	-28(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L306
	.loc 1 1456 0
	movl	$1, -28(%ebp)
	jmp	.L307
.L308:
	.loc 1 1458 0
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	leal	-160432(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	addl	%eax, %ecx
	movl	-28(%ebp), %eax
	leal	1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-120432(%ebp,%eax,8)
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-120432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	leal	-1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-120432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fildl	-28(%ebp)
	fmuls	-36(%ebp)
	movl	-28(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fxch	%st(5)
	leal	-72(%ebp), %eax
	movl	%eax, 52(%esp)
	movl	%ecx, 48(%esp)
	fstpl	40(%esp)
	fxch	%st(3)
	fstpl	32(%esp)
	fxch	%st(1)
	fstpl	24(%esp)
	fstpl	16(%esp)
	fstpl	8(%esp)
	fstpl	(%esp)
	call	_Z3VADddddddPdS_
	.loc 1 1456 0
	addl	$1, -28(%ebp)
.L307:
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	subl	$1, %eax
	cmpl	-28(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L308
	.loc 1 1460 0
	movl	$0x00000000, %eax
	movl	%eax, -56(%ebp)
	.loc 1 1461 0
	movl	$0, -28(%ebp)
	jmp	.L309
.L310:
	.loc 1 1463 0
	flds	-56(%ebp)
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ecx, %eax
	fldl	-160432(%ebp,%eax,8)
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ecx, %eax
	fldl	-160432(%ebp,%eax,8)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-56(%ebp)
	.loc 1 1461 0
	addl	$1, -28(%ebp)
.L309:
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	cmpl	-28(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L310
	.loc 1 1465 0
	flds	-56(%ebp)
	flds	-52(%ebp)
	fucompp
	fnstsw	%ax
	testb	$69, %ah
	sete	%al
	testb	%al, %al
	je	.L311
	.loc 1 1467 0
	flds	-56(%ebp)
	flds	-52(%ebp)
	fxch	%st(1)
	fstpl	16(%esp)
	fstpl	8(%esp)
	movl	-32(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC63, (%esp)
	call	printf
	.loc 1 1468 0
	movl	-56(%ebp), %eax
	movl	%eax, -52(%ebp)
	.loc 1 1469 0
	movl	-32(%ebp), %eax
	movl	-32(%ebp), %edx
	fldl	-112(%ebp,%edx,8)
	fstpl	-352(%ebp,%eax,8)
	.loc 1 1470 0
	movl	-32(%ebp), %eax
	movl	-32(%ebp), %edx
	fldl	-152(%ebp,%edx,8)
	fstpl	-392(%ebp,%eax,8)
	.loc 1 1471 0
	movl	-32(%ebp), %eax
	movl	-32(%ebp), %edx
	fldl	-192(%ebp,%edx,8)
	fstpl	-432(%ebp,%eax,8)
.L311:
	.loc 1 1475 0
	movl	-44(%ebp), %eax
	leal	-1(%eax), %edx
	movl	-32(%ebp), %ecx
	movl	-32(%ebp), %eax
	fldl	-232(%ebp,%eax,8)
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ecx, %eax
	fstpl	-40432(%ebp,%eax,8)
	.loc 1 1476 0
	movl	-44(%ebp), %edx
	movl	-32(%ebp), %ecx
	movl	-32(%ebp), %eax
	fldl	-272(%ebp,%eax,8)
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ecx, %eax
	fstpl	-40432(%ebp,%eax,8)
	.loc 1 1477 0
	movl	-44(%ebp), %eax
	leal	1(%eax), %edx
	movl	-32(%ebp), %ecx
	movl	-32(%ebp), %eax
	fldl	-312(%ebp,%eax,8)
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ecx, %eax
	fstpl	-40432(%ebp,%eax,8)
	.loc 1 1436 0
	addl	$1, -60(%ebp)
.L302:
	cmpl	$2, -60(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L312
	.loc 1 1480 0
	movl	-44(%ebp), %eax
	leal	-1(%eax), %edx
	movl	-32(%ebp), %ecx
	movl	-32(%ebp), %eax
	fldl	-352(%ebp,%eax,8)
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ecx, %eax
	fstpl	-40432(%ebp,%eax,8)
	.loc 1 1481 0
	movl	-44(%ebp), %edx
	movl	-32(%ebp), %ecx
	movl	-32(%ebp), %eax
	fldl	-392(%ebp,%eax,8)
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ecx, %eax
	fstpl	-40432(%ebp,%eax,8)
	.loc 1 1482 0
	movl	-44(%ebp), %eax
	leal	1(%eax), %edx
	movl	-32(%ebp), %ecx
	movl	-32(%ebp), %eax
	fldl	-432(%ebp,%eax,8)
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ecx, %eax
	fstpl	-40432(%ebp,%eax,8)
	.loc 1 1390 0
	addl	$1, -32(%ebp)
.L288:
	cmpl	$4, -32(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L313
.LBE44:
	.loc 1 1357 0
	addl	$1, -40(%ebp)
.L275:
	movl	-40(%ebp), %eax
	cmpl	20(%ebp), %eax
	setl	%al
	testb	%al, %al
	jne	.L314
	.loc 1 1513 0
	movl	$0, -28(%ebp)
	jmp	.L315
.L316:
	.loc 1 1515 0
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$40376, %eax
	fldl	(%eax)
	fstps	-160444(%ebp)
	flds	-160444(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$40392, %eax
	fldl	8(%eax)
	fstps	-160444(%ebp)
	flds	-160444(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$40392, %eax
	fldl	(%eax)
	fstps	-160444(%ebp)
	flds	-160444(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$40408, %eax
	fldl	8(%eax)
	fstps	-160444(%ebp)
	flds	-160444(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$40408, %eax
	fldl	(%eax)
	fstps	-160444(%ebp)
	flds	-160444(%ebp)
	fxch	%st(4)
	movl	16(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 24(%esp)
	fstps	20(%esp)
	fxch	%st(2)
	fstps	16(%esp)
	fstps	12(%esp)
	fstps	8(%esp)
	fstps	4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	tmpnComputeFKlogic
	.loc 1 1516 0
	movl	-28(%ebp), %edx
	movl	8(%ebp), %eax
	movl	1316(%eax), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$320, %eax
	movl	%ecx, (%eax)
	.loc 1 1517 0
	movl	-28(%ebp), %edx
	movl	8(%ebp), %eax
	movl	1320(%eax), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$324, %eax
	movl	%ecx, (%eax)
	.loc 1 1518 0
	movl	-28(%ebp), %edx
	movl	8(%ebp), %eax
	movl	1324(%eax), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$328, %eax
	movl	%ecx, (%eax)
	.loc 1 1519 0
	movl	-28(%ebp), %edx
	movl	8(%ebp), %eax
	movl	1328(%eax), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$332, %eax
	movl	%ecx, (%eax)
	.loc 1 1520 0
	movl	-28(%ebp), %edx
	movl	8(%ebp), %eax
	movl	1332(%eax), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$336, %eax
	movl	%ecx, (%eax)
	.loc 1 1521 0
	movl	-28(%ebp), %edx
	movl	8(%ebp), %eax
	movl	1336(%eax), %ecx
	movl	12(%ebp), %ebx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ebx,%eax), %eax
	addl	$340, %eax
	movl	%ecx, (%eax)
	.loc 1 1513 0
	addl	$1, -28(%ebp)
.L315:
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	cmpl	-28(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L316
	.loc 1 1523 0
	movl	$.LC64, (%esp)
	call	puts
	.loc 1 1524 0
	fldz
	fstpl	-80432(%ebp)
	.loc 1 1525 0
	fldz
	fstpl	-80424(%ebp)
	.loc 1 1526 0
	fldz
	fstpl	-80416(%ebp)
	.loc 1 1527 0
	fldz
	fstpl	-80408(%ebp)
	.loc 1 1528 0
	fldz
	fstpl	-80400(%ebp)
	.loc 1 1529 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$80408, %eax
	fldz
	fstpl	(%eax)
	.loc 1 1530 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$80408, %eax
	fldz
	fstpl	8(%eax)
	.loc 1 1531 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$80392, %eax
	fldz
	fstpl	(%eax)
	.loc 1 1532 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$80392, %eax
	fldz
	fstpl	8(%eax)
	.loc 1 1533 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$80376, %eax
	fldz
	fstpl	(%eax)
	.loc 1 1534 0
	movl	$0, -28(%ebp)
	jmp	.L317
.L318:
	.loc 1 1536 0
	movl	-28(%ebp), %edx
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	addl	$340, %eax
	movl	(%eax), %edx
	movl	%edx, -160560(%ebp)
	movl	-28(%ebp), %edx
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	addl	$336, %eax
	movl	(%eax), %edx
	movl	%edx, -160556(%ebp)
	movl	-28(%ebp), %edx
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	addl	$332, %eax
	movl	(%eax), %edi
	movl	-28(%ebp), %edx
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	addl	$328, %eax
	movl	(%eax), %esi
	movl	-28(%ebp), %edx
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	addl	$324, %eax
	movl	(%eax), %ebx
	movl	-28(%ebp), %edx
	movl	12(%ebp), %ecx
	movl	%edx, %eax
	addl	%eax, %eax
	addl	%edx, %eax
	sall	$4, %eax
	leal	(%ecx,%eax), %eax
	addl	$320, %eax
	movl	(%eax), %eax
	movl	16(%ebp), %edx
	movl	%edx, 28(%esp)
	movl	-160560(%ebp), %edx
	movl	%edx, 24(%esp)
	movl	-160556(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	tmpnComputeIK
	.loc 1 1537 0
	movl	-28(%ebp), %edx
	movl	8(%ebp), %eax
	flds	2284(%eax)
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$40408, %eax
	fstpl	(%eax)
	.loc 1 1538 0
	movl	-28(%ebp), %edx
	movl	8(%ebp), %eax
	flds	2288(%eax)
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$40408, %eax
	fstpl	8(%eax)
	.loc 1 1539 0
	movl	-28(%ebp), %edx
	movl	8(%ebp), %eax
	flds	2292(%eax)
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$40392, %eax
	fstpl	(%eax)
	.loc 1 1540 0
	movl	-28(%ebp), %edx
	movl	8(%ebp), %eax
	flds	2296(%eax)
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$40392, %eax
	fstpl	8(%eax)
	.loc 1 1541 0
	movl	-28(%ebp), %edx
	movl	8(%ebp), %eax
	flds	2300(%eax)
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$40376, %eax
	fstpl	(%eax)
	.loc 1 1534 0
	addl	$1, -28(%ebp)
.L317:
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	cmpl	-28(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L318
	.loc 1 1543 0
	movl	$1, -28(%ebp)
	jmp	.L319
.L322:
	.loc 1 1545 0
	movl	$0, -32(%ebp)
	jmp	.L320
.L321:
	.loc 1 1547 0
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	leal	-80432(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	addl	%eax, %ecx
	movl	-28(%ebp), %eax
	leal	1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-40432(%ebp,%eax,8)
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-40432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	leal	-1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-40432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fildl	-28(%ebp)
	fmuls	-36(%ebp)
	movl	-28(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fxch	%st(5)
	leal	-72(%ebp), %eax
	movl	%eax, 52(%esp)
	movl	%ecx, 48(%esp)
	fstpl	40(%esp)
	fxch	%st(3)
	fstpl	32(%esp)
	fxch	%st(1)
	fstpl	24(%esp)
	fstpl	16(%esp)
	fstpl	8(%esp)
	fstpl	(%esp)
	call	_Z3VADddddddPdS_
	.loc 1 1545 0
	addl	$1, -32(%ebp)
.L320:
	cmpl	$4, -32(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L321
	.loc 1 1543 0
	addl	$1, -28(%ebp)
.L319:
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	subl	$1, %eax
	cmpl	-28(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L322
	.loc 1 1550 0
	fldz
	fstpl	-120432(%ebp)
	.loc 1 1551 0
	fldz
	fstpl	-120424(%ebp)
	.loc 1 1552 0
	fldz
	fstpl	-120416(%ebp)
	.loc 1 1553 0
	fldz
	fstpl	-120408(%ebp)
	.loc 1 1554 0
	fldz
	fstpl	-120400(%ebp)
	.loc 1 1555 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$120408, %eax
	fldz
	fstpl	(%eax)
	.loc 1 1556 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$120408, %eax
	fldz
	fstpl	8(%eax)
	.loc 1 1557 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$120392, %eax
	fldz
	fstpl	(%eax)
	.loc 1 1558 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$120392, %eax
	fldz
	fstpl	8(%eax)
	.loc 1 1559 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$120376, %eax
	fldz
	fstpl	(%eax)
	.loc 1 1560 0
	movl	$1, -28(%ebp)
	jmp	.L323
.L326:
	.loc 1 1562 0
	movl	$0, -32(%ebp)
	jmp	.L324
.L325:
	.loc 1 1564 0
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	leal	-120432(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	addl	%eax, %ecx
	movl	-28(%ebp), %eax
	leal	1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-80432(%ebp,%eax,8)
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-80432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	leal	-1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-80432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fildl	-28(%ebp)
	fmuls	-36(%ebp)
	movl	-28(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fxch	%st(5)
	leal	-72(%ebp), %eax
	movl	%eax, 52(%esp)
	movl	%ecx, 48(%esp)
	fstpl	40(%esp)
	fxch	%st(3)
	fstpl	32(%esp)
	fxch	%st(1)
	fstpl	24(%esp)
	fstpl	16(%esp)
	fstpl	8(%esp)
	fstpl	(%esp)
	call	_Z3VADddddddPdS_
	.loc 1 1562 0
	addl	$1, -32(%ebp)
.L324:
	cmpl	$4, -32(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L325
	.loc 1 1560 0
	addl	$1, -28(%ebp)
.L323:
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	subl	$1, %eax
	cmpl	-28(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L326
	.loc 1 1567 0
	fldz
	fstpl	-160432(%ebp)
	.loc 1 1568 0
	fldz
	fstpl	-160424(%ebp)
	.loc 1 1569 0
	fldz
	fstpl	-160416(%ebp)
	.loc 1 1570 0
	fldz
	fstpl	-160408(%ebp)
	.loc 1 1571 0
	fldz
	fstpl	-160400(%ebp)
	.loc 1 1572 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160408, %eax
	fldz
	fstpl	(%eax)
	.loc 1 1573 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160408, %eax
	fldz
	fstpl	8(%eax)
	.loc 1 1574 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160392, %eax
	fldz
	fstpl	(%eax)
	.loc 1 1575 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160392, %eax
	fldz
	fstpl	8(%eax)
	.loc 1 1576 0
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	leal	-1(%eax), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160376, %eax
	fldz
	fstpl	(%eax)
	.loc 1 1577 0
	movl	$1, -28(%ebp)
	jmp	.L327
.L330:
	.loc 1 1579 0
	movl	$0, -32(%ebp)
	jmp	.L328
.L329:
	.loc 1 1581 0
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	leal	-160432(%ebp), %ecx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	sall	$3, %eax
	addl	%eax, %ecx
	movl	-28(%ebp), %eax
	leal	1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-120432(%ebp,%eax,8)
	movl	-28(%ebp), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-120432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	leal	-1(%eax), %edx
	movl	-32(%ebp), %ebx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%ebx, %eax
	fldl	-120432(%ebp,%eax,8)
	movl	-28(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fildl	-28(%ebp)
	fmuls	-36(%ebp)
	movl	-28(%ebp), %eax
	subl	$1, %eax
	movl	%eax, -160448(%ebp)
	fildl	-160448(%ebp)
	fmuls	-36(%ebp)
	fxch	%st(5)
	leal	-72(%ebp), %eax
	movl	%eax, 52(%esp)
	movl	%ecx, 48(%esp)
	fstpl	40(%esp)
	fxch	%st(3)
	fstpl	32(%esp)
	fxch	%st(1)
	fstpl	24(%esp)
	fstpl	16(%esp)
	fstpl	8(%esp)
	fstpl	(%esp)
	call	_Z3VADddddddPdS_
	.loc 1 1579 0
	addl	$1, -32(%ebp)
.L328:
	cmpl	$4, -32(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L329
	.loc 1 1577 0
	addl	$1, -28(%ebp)
.L327:
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	subl	$1, %eax
	cmpl	-28(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L330
	.loc 1 1584 0
	movl	$0, -28(%ebp)
	jmp	.L331
.L332:
	.loc 1 1586 0
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160376, %eax
	fldl	(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160376, %eax
	fldl	(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fmulp	%st, %st(1)
	fstpl	-160552(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$120376, %eax
	fldl	(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fstpl	-160544(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$80376, %eax
	fldl	(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fstpl	-160536(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$40376, %eax
	fldl	(%eax)
	fstpl	-160528(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160392, %eax
	fldl	8(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160392, %eax
	fldl	8(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fmulp	%st, %st(1)
	fstpl	-160520(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$120392, %eax
	fldl	8(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fstpl	-160512(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$80392, %eax
	fldl	8(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fstpl	-160504(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$40392, %eax
	fldl	8(%eax)
	fstpl	-160496(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160392, %eax
	fldl	(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160392, %eax
	fldl	(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fmulp	%st, %st(1)
	fstpl	-160488(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$120392, %eax
	fldl	(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fstpl	-160480(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$80392, %eax
	fldl	(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fstpl	-160472(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$40392, %eax
	fldl	(%eax)
	fstpl	-160464(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160408, %eax
	fldl	8(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160408, %eax
	fldl	8(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	fmulp	%st, %st(1)
	fstpl	-160456(%ebp)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$120408, %eax
	fldl	8(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$80408, %eax
	fldl	8(%eax)
	fldl	.LC42
	fmulp	%st, %st(1)
	fldl	.LC43
	fdivrp	%st, %st(1)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$40408, %eax
	fldl	8(%eax)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160408, %eax
	fldl	(%eax)
	fldl	.LC41
	fmulp	%st, %st(1)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$160408, %eax
	fldl	(%eax)
	fldl	.LC41
	fmulp	%st, %st(1)
	fmulp	%st, %st(1)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$120408, %eax
	fldl	(%eax)
	fldl	.LC41
	fmulp	%st, %st(1)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$80408, %eax
	fldl	(%eax)
	fldl	.LC41
	fmulp	%st, %st(1)
	movl	-28(%ebp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	sall	$3, %eax
	leal	-24(%ebp), %edx
	leal	(%edx,%eax), %eax
	subl	$40408, %eax
	fldl	(%eax)
	fildl	-28(%ebp)
	fmuls	-36(%ebp)
	fstpl	-160688(%ebp)
	fldl	-160552(%ebp)
	fstpl	164(%esp)
	fldl	-160544(%ebp)
	fstpl	156(%esp)
	fldl	-160536(%ebp)
	fstpl	148(%esp)
	fldl	-160528(%ebp)
	fstpl	140(%esp)
	fldl	-160520(%ebp)
	fstpl	132(%esp)
	fldl	-160512(%ebp)
	fstpl	124(%esp)
	fldl	-160504(%ebp)
	fstpl	116(%esp)
	fldl	-160496(%ebp)
	fstpl	108(%esp)
	fldl	-160488(%ebp)
	fstpl	100(%esp)
	fldl	-160480(%ebp)
	fstpl	92(%esp)
	fldl	-160472(%ebp)
	fstpl	84(%esp)
	fldl	-160464(%ebp)
	fstpl	76(%esp)
	fldl	-160456(%ebp)
	fstpl	68(%esp)
	fxch	%st(6)
	fstpl	60(%esp)
	fxch	%st(4)
	fstpl	52(%esp)
	fxch	%st(2)
	fstpl	44(%esp)
	fstpl	36(%esp)
	fstpl	28(%esp)
	fstpl	20(%esp)
	fstpl	12(%esp)
	fldl	-160688(%ebp)
	fstpl	4(%esp)
	movl	$.LC57, (%esp)
	call	printf
	.loc 1 1584 0
	addl	$1, -28(%ebp)
.L331:
	movl	12(%ebp), %eax
	movl	268(%eax), %eax
	cmpl	-28(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L332
.LBE43:
	.loc 1 1588 0
	addl	$160860, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.cfi_endproc
.LFE32:
	.size	jerkMinimizer, .-jerkMinimizer
.globl convertToFrame
	.type	convertToFrame, @function
convertToFrame:
.LFB33:
	.loc 1 1592 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI48:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI49:
	.cfi_def_cfa_register 5
	call	mcount
	.loc 1 1592 0
	.loc 1 1593 0
	movl	16(%ebp), %eax
	flds	12(%eax)
	movl	12(%ebp), %eax
	movl	24(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2592, %eax
	flds	(%eax)
	faddp	%st, %st(1)
	movl	20(%ebp), %eax
	movl	24(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2592, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	movl	8(%ebp), %eax
	fstps	(%eax)
	.loc 1 1594 0
	movl	16(%ebp), %eax
	flds	16(%eax)
	movl	12(%ebp), %eax
	movl	24(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2596, %eax
	flds	(%eax)
	faddp	%st, %st(1)
	movl	20(%ebp), %eax
	movl	24(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2596, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	movl	8(%ebp), %eax
	fstps	4(%eax)
	.loc 1 1595 0
	movl	16(%ebp), %eax
	flds	20(%eax)
	movl	12(%ebp), %eax
	movl	24(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2600, %eax
	flds	(%eax)
	faddp	%st, %st(1)
	movl	20(%ebp), %eax
	movl	24(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2600, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	movl	8(%ebp), %eax
	fstps	8(%eax)
	.loc 1 1596 0
	movl	16(%ebp), %eax
	flds	24(%eax)
	movl	12(%ebp), %eax
	movl	24(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2604, %eax
	flds	(%eax)
	faddp	%st, %st(1)
	movl	20(%ebp), %eax
	movl	24(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2604, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	movl	8(%ebp), %eax
	fstps	12(%eax)
	.loc 1 1597 0
	movl	16(%ebp), %eax
	flds	28(%eax)
	movl	12(%ebp), %eax
	movl	24(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2608, %eax
	flds	(%eax)
	faddp	%st, %st(1)
	movl	20(%ebp), %eax
	movl	24(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2608, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	movl	8(%ebp), %eax
	fstps	16(%eax)
	.loc 1 1598 0
	movl	16(%ebp), %eax
	flds	32(%eax)
	movl	12(%ebp), %eax
	movl	24(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2612, %eax
	flds	(%eax)
	faddp	%st, %st(1)
	movl	20(%ebp), %eax
	movl	24(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2612, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	movl	8(%ebp), %eax
	fstps	20(%eax)
	.loc 1 1599 0
	popl	%ebp
	ret
	.cfi_endproc
.LFE33:
	.size	convertToFrame, .-convertToFrame
.globl convertToFrame_vectorstyle
	.type	convertToFrame_vectorstyle, @function
convertToFrame_vectorstyle:
.LFB34:
	.loc 1 1602 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI50:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI51:
	.cfi_def_cfa_register 5
	call	mcount
	.loc 1 1602 0
	.loc 1 1603 0
	movl	16(%ebp), %eax
	flds	(%eax)
	movl	12(%ebp), %eax
	flds	256(%eax)
	faddp	%st, %st(1)
	movl	20(%ebp), %eax
	flds	256(%eax)
	fsubrp	%st, %st(1)
	movl	8(%ebp), %eax
	fstps	(%eax)
	.loc 1 1604 0
	movl	16(%ebp), %eax
	flds	4(%eax)
	movl	12(%ebp), %eax
	flds	260(%eax)
	faddp	%st, %st(1)
	movl	20(%ebp), %eax
	flds	260(%eax)
	fsubrp	%st, %st(1)
	movl	8(%ebp), %eax
	fstps	4(%eax)
	.loc 1 1605 0
	movl	16(%ebp), %eax
	flds	8(%eax)
	movl	12(%ebp), %eax
	flds	264(%eax)
	faddp	%st, %st(1)
	movl	20(%ebp), %eax
	flds	264(%eax)
	fsubrp	%st, %st(1)
	movl	8(%ebp), %eax
	fstps	8(%eax)
	.loc 1 1606 0
	movl	16(%ebp), %eax
	flds	12(%eax)
	movl	12(%ebp), %eax
	flds	268(%eax)
	faddp	%st, %st(1)
	movl	20(%ebp), %eax
	flds	268(%eax)
	fsubrp	%st, %st(1)
	movl	8(%ebp), %eax
	fstps	12(%eax)
	.loc 1 1607 0
	movl	16(%ebp), %eax
	flds	16(%eax)
	movl	12(%ebp), %eax
	flds	272(%eax)
	faddp	%st, %st(1)
	movl	20(%ebp), %eax
	flds	272(%eax)
	fsubrp	%st, %st(1)
	movl	8(%ebp), %eax
	fstps	16(%eax)
	.loc 1 1608 0
	movl	16(%ebp), %eax
	flds	20(%eax)
	movl	12(%ebp), %eax
	flds	276(%eax)
	faddp	%st, %st(1)
	movl	20(%ebp), %eax
	flds	276(%eax)
	fsubrp	%st, %st(1)
	movl	8(%ebp), %eax
	fstps	20(%eax)
	.loc 1 1609 0
	popl	%ebp
	ret
	.cfi_endproc
.LFE34:
	.size	convertToFrame_vectorstyle, .-convertToFrame_vectorstyle
	.section	.rodata
.LC65:
	.string	"base"
	.text
.globl blendCorner3
	.type	blendCorner3, @function
blendCorner3:
.LFB35:
	.loc 1 1612 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI52:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI53:
	.cfi_def_cfa_register 5
	subl	$440, %esp
	call	mcount
	.loc 1 1612 0
.LBB45:
	.loc 1 1620 0
	movl	$-3, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -16(%ebp)
	.loc 1 1621 0
	movl	$-2, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -20(%ebp)
	.loc 1 1622 0
	movl	$-1, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -24(%ebp)
	.loc 1 1623 0
	movl	$0, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -28(%ebp)
	.loc 1 1624 0
	movl	$1, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -32(%ebp)
	.loc 1 1625 0
	movl	$2, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -36(%ebp)
	.loc 1 1626 0
	movl	$3, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -40(%ebp)
	.loc 1 1628 0
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC65, (%esp)
	call	getFrameIdx
	movl	%eax, -12(%ebp)
	.loc 1 1629 0
	movl	-16(%ebp), %edx
	movl	-16(%ebp), %eax
	movl	144(%eax), %eax
	movl	8(%ebp), %ecx
	movl	%ecx, 16(%esp)
	movl	-12(%ebp), %ecx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	leal	-68(%ebp), %eax
	movl	%eax, (%esp)
	call	convertToFrame
	.loc 1 1630 0
	movl	-20(%ebp), %edx
	movl	-20(%ebp), %eax
	movl	144(%eax), %eax
	movl	8(%ebp), %ecx
	movl	%ecx, 16(%esp)
	movl	-12(%ebp), %ecx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	leal	-92(%ebp), %eax
	movl	%eax, (%esp)
	call	convertToFrame
	.loc 1 1631 0
	movl	-24(%ebp), %edx
	movl	-24(%ebp), %eax
	movl	144(%eax), %eax
	movl	8(%ebp), %ecx
	movl	%ecx, 16(%esp)
	movl	-12(%ebp), %ecx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	leal	-116(%ebp), %eax
	movl	%eax, (%esp)
	call	convertToFrame
	.loc 1 1632 0
	movl	-28(%ebp), %edx
	movl	-28(%ebp), %eax
	movl	144(%eax), %eax
	movl	8(%ebp), %ecx
	movl	%ecx, 16(%esp)
	movl	-12(%ebp), %ecx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	leal	-140(%ebp), %eax
	movl	%eax, (%esp)
	call	convertToFrame
	.loc 1 1633 0
	movl	-32(%ebp), %edx
	movl	-32(%ebp), %eax
	movl	144(%eax), %eax
	movl	8(%ebp), %ecx
	movl	%ecx, 16(%esp)
	movl	-12(%ebp), %ecx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	leal	-164(%ebp), %eax
	movl	%eax, (%esp)
	call	convertToFrame
	.loc 1 1634 0
	movl	-36(%ebp), %edx
	movl	-36(%ebp), %eax
	movl	144(%eax), %eax
	movl	8(%ebp), %ecx
	movl	%ecx, 16(%esp)
	movl	-12(%ebp), %ecx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	leal	-188(%ebp), %eax
	movl	%eax, (%esp)
	call	convertToFrame
	.loc 1 1635 0
	movl	-40(%ebp), %edx
	movl	-40(%ebp), %eax
	movl	144(%eax), %eax
	movl	8(%ebp), %ecx
	movl	%ecx, 16(%esp)
	movl	-12(%ebp), %ecx
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	leal	-212(%ebp), %eax
	movl	%eax, (%esp)
	call	convertToFrame
	.loc 1 1636 0
	flds	-92(%ebp)
	flds	-68(%ebp)
	fsubrp	%st, %st(1)
	fstps	-284(%ebp)
	.loc 1 1637 0
	flds	-88(%ebp)
	flds	-64(%ebp)
	fsubrp	%st, %st(1)
	fstps	-280(%ebp)
	.loc 1 1638 0
	flds	-84(%ebp)
	flds	-60(%ebp)
	fsubrp	%st, %st(1)
	fstps	-276(%ebp)
	.loc 1 1639 0
	flds	-76(%ebp)
	flds	-52(%ebp)
	fsubrp	%st, %st(1)
	fstps	-268(%ebp)
	.loc 1 1641 0
	flds	-208(%ebp)
	flds	-184(%ebp)
	fsubrp	%st, %st(1)
	fstps	-304(%ebp)
	.loc 1 1642 0
	flds	-212(%ebp)
	flds	-188(%ebp)
	fsubrp	%st, %st(1)
	fstps	-308(%ebp)
	.loc 1 1643 0
	flds	-204(%ebp)
	flds	-180(%ebp)
	fsubrp	%st, %st(1)
	fstps	-300(%ebp)
	.loc 1 1644 0
	flds	-196(%ebp)
	flds	-172(%ebp)
	fsubrp	%st, %st(1)
	fstps	-292(%ebp)
	.loc 1 1646 0
	movl	$0x00000000, %eax
	movl	%eax, -260(%ebp)
	flds	-284(%ebp)
	fabs
	flds	-308(%ebp)
	fabs
	fucompp
	fnstsw	%ax
	testb	$5, %ah
	sete	%al
	testb	%al, %al
	je	.L339
	movl	$0x3f800000, %eax
	movl	%eax, -260(%ebp)
.L339:
	.loc 1 1647 0
	movl	$0x00000000, %eax
	movl	%eax, -256(%ebp)
	flds	-280(%ebp)
	fabs
	flds	-304(%ebp)
	fabs
	fucompp
	fnstsw	%ax
	testb	$5, %ah
	sete	%al
	testb	%al, %al
	je	.L340
	movl	$0x3f800000, %eax
	movl	%eax, -256(%ebp)
.L340:
	.loc 1 1648 0
	movl	$0x00000000, %eax
	movl	%eax, -252(%ebp)
	flds	-276(%ebp)
	fabs
	flds	-300(%ebp)
	fabs
	fucompp
	fnstsw	%ax
	testb	$5, %ah
	sete	%al
	testb	%al, %al
	je	.L341
	movl	$0x3f800000, %eax
	movl	%eax, -252(%ebp)
.L341:
	.loc 1 1649 0
	movl	$0x00000000, %eax
	movl	%eax, -244(%ebp)
	flds	-268(%ebp)
	fabs
	flds	-292(%ebp)
	fabs
	fucompp
	fnstsw	%ax
	testb	$5, %ah
	sete	%al
	testb	%al, %al
	je	.L342
	movl	$0x3f800000, %eax
	movl	%eax, -244(%ebp)
.L342:
	.loc 1 1653 0
	movl	$0x3ec90fdb, %eax
	movl	%eax, -44(%ebp)
	.loc 1 1655 0
	flds	-260(%ebp)
	fld1
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jne	.L360
	jp	.L360
.L356:
	.loc 1 1657 0
	flds	-44(%ebp)
	flds	.LC9
	fmulp	%st, %st(1)
	fstpl	(%esp)
	call	sin
	fld1
	faddp	%st, %st(1)
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	-332(%ebp)
	.loc 1 1658 0
	flds	-44(%ebp)
	flds	.LC16
	fmulp	%st, %st(1)
	fstpl	(%esp)
	call	sin
	fld1
	faddp	%st, %st(1)
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	-356(%ebp)
	.loc 1 1659 0
	flds	-44(%ebp)
	fstpl	(%esp)
	call	sin
	fld1
	fsubp	%st, %st(1)
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	-380(%ebp)
	jmp	.L345
.L360:
	.loc 1 1663 0
	flds	-44(%ebp)
	fstpl	(%esp)
	call	sin
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	-332(%ebp)
	.loc 1 1664 0
	flds	-44(%ebp)
	fadd	%st(0), %st
	fstpl	(%esp)
	call	sin
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	-356(%ebp)
	.loc 1 1665 0
	flds	-44(%ebp)
	flds	.LC15
	fmulp	%st, %st(1)
	fstpl	(%esp)
	call	sin
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	-380(%ebp)
.L345:
	.loc 1 1668 0
	flds	-256(%ebp)
	fld1
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jne	.L361
	jp	.L361
.L357:
	.loc 1 1670 0
	flds	-44(%ebp)
	flds	.LC9
	fmulp	%st, %st(1)
	fstpl	(%esp)
	call	sin
	fld1
	faddp	%st, %st(1)
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	-328(%ebp)
	.loc 1 1671 0
	flds	-44(%ebp)
	flds	.LC16
	fmulp	%st, %st(1)
	fstpl	(%esp)
	call	sin
	fld1
	faddp	%st, %st(1)
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	-352(%ebp)
	.loc 1 1672 0
	flds	-44(%ebp)
	fstpl	(%esp)
	call	sin
	fld1
	fsubp	%st, %st(1)
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	-376(%ebp)
	jmp	.L348
.L361:
	.loc 1 1676 0
	flds	-44(%ebp)
	fstpl	(%esp)
	call	sin
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	-328(%ebp)
	.loc 1 1677 0
	flds	-44(%ebp)
	fadd	%st(0), %st
	fstpl	(%esp)
	call	sin
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	-352(%ebp)
	.loc 1 1678 0
	flds	-44(%ebp)
	flds	.LC15
	fmulp	%st, %st(1)
	fstpl	(%esp)
	call	sin
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	-376(%ebp)
.L348:
	.loc 1 1682 0
	flds	-252(%ebp)
	fld1
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jne	.L362
	jp	.L362
.L358:
	.loc 1 1684 0
	flds	-44(%ebp)
	flds	.LC9
	fmulp	%st, %st(1)
	fstpl	(%esp)
	call	sin
	fld1
	faddp	%st, %st(1)
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	-324(%ebp)
	.loc 1 1685 0
	flds	-44(%ebp)
	flds	.LC16
	fmulp	%st, %st(1)
	fstpl	(%esp)
	call	sin
	fld1
	faddp	%st, %st(1)
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	-348(%ebp)
	.loc 1 1686 0
	flds	-44(%ebp)
	fstpl	(%esp)
	call	sin
	fld1
	fsubp	%st, %st(1)
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	-372(%ebp)
	jmp	.L351
.L362:
	.loc 1 1690 0
	flds	-44(%ebp)
	fstpl	(%esp)
	call	sin
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	-324(%ebp)
	.loc 1 1691 0
	flds	-44(%ebp)
	fadd	%st(0), %st
	fstpl	(%esp)
	call	sin
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	-348(%ebp)
	.loc 1 1692 0
	flds	-44(%ebp)
	flds	.LC15
	fmulp	%st, %st(1)
	fstpl	(%esp)
	call	sin
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	-372(%ebp)
.L351:
	.loc 1 1695 0
	flds	-244(%ebp)
	fld1
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jne	.L363
	jp	.L363
.L359:
	.loc 1 1697 0
	flds	-44(%ebp)
	flds	.LC9
	fmulp	%st, %st(1)
	fstpl	(%esp)
	call	sin
	fld1
	faddp	%st, %st(1)
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	-316(%ebp)
	.loc 1 1698 0
	flds	-44(%ebp)
	flds	.LC16
	fmulp	%st, %st(1)
	fstpl	(%esp)
	call	sin
	fld1
	faddp	%st, %st(1)
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	-340(%ebp)
	.loc 1 1699 0
	flds	-44(%ebp)
	fstpl	(%esp)
	call	sin
	fld1
	fsubp	%st, %st(1)
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	-364(%ebp)
	jmp	.L354
.L363:
	.loc 1 1703 0
	flds	-44(%ebp)
	fstpl	(%esp)
	call	sin
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	-316(%ebp)
	.loc 1 1704 0
	flds	-44(%ebp)
	fadd	%st(0), %st
	fstpl	(%esp)
	call	sin
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	-340(%ebp)
	.loc 1 1705 0
	flds	-44(%ebp)
	flds	.LC15
	fmulp	%st, %st(1)
	fstpl	(%esp)
	call	sin
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	-364(%ebp)
.L354:
	.loc 1 1708 0
	flds	-188(%ebp)
	flds	-92(%ebp)
	fsubrp	%st, %st(1)
	fstps	-236(%ebp)
	.loc 1 1709 0
	flds	-184(%ebp)
	flds	-88(%ebp)
	fsubrp	%st, %st(1)
	fstps	-232(%ebp)
	.loc 1 1710 0
	flds	-180(%ebp)
	flds	-84(%ebp)
	fsubrp	%st, %st(1)
	fstps	-228(%ebp)
	.loc 1 1711 0
	flds	-172(%ebp)
	flds	-76(%ebp)
	fsubrp	%st, %st(1)
	fstps	-220(%ebp)
	.loc 1 1713 0
	flds	-92(%ebp)
	flds	-332(%ebp)
	flds	-236(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-24(%ebp), %eax
	movl	144(%eax), %eax
	movl	8(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2592, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	movl	-24(%ebp), %eax
	fstps	12(%eax)
	.loc 1 1714 0
	flds	-92(%ebp)
	flds	-356(%ebp)
	flds	-236(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-28(%ebp), %eax
	movl	144(%eax), %eax
	movl	8(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2592, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	movl	-28(%ebp), %eax
	fstps	12(%eax)
	.loc 1 1715 0
	flds	-92(%ebp)
	flds	-380(%ebp)
	flds	-236(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-32(%ebp), %eax
	movl	144(%eax), %eax
	movl	8(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2592, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	movl	-32(%ebp), %eax
	fstps	12(%eax)
	.loc 1 1717 0
	flds	-88(%ebp)
	flds	-328(%ebp)
	flds	-232(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-24(%ebp), %eax
	movl	144(%eax), %eax
	movl	8(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2596, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	movl	-24(%ebp), %eax
	fstps	16(%eax)
	.loc 1 1718 0
	flds	-88(%ebp)
	flds	-352(%ebp)
	flds	-232(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-28(%ebp), %eax
	movl	144(%eax), %eax
	movl	8(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2596, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	movl	-28(%ebp), %eax
	fstps	16(%eax)
	.loc 1 1719 0
	flds	-88(%ebp)
	flds	-376(%ebp)
	flds	-232(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-32(%ebp), %eax
	movl	144(%eax), %eax
	movl	8(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2596, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	movl	-32(%ebp), %eax
	fstps	16(%eax)
	.loc 1 1721 0
	flds	-84(%ebp)
	flds	-324(%ebp)
	flds	-228(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-24(%ebp), %eax
	movl	144(%eax), %eax
	movl	8(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2600, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	movl	-24(%ebp), %eax
	fstps	20(%eax)
	.loc 1 1722 0
	flds	-84(%ebp)
	flds	-348(%ebp)
	flds	-228(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-28(%ebp), %eax
	movl	144(%eax), %eax
	movl	8(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2600, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	movl	-28(%ebp), %eax
	fstps	20(%eax)
	.loc 1 1723 0
	flds	-84(%ebp)
	flds	-372(%ebp)
	flds	-228(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-32(%ebp), %eax
	movl	144(%eax), %eax
	movl	8(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2600, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	movl	-32(%ebp), %eax
	fstps	20(%eax)
	.loc 1 1725 0
	flds	-76(%ebp)
	flds	-316(%ebp)
	flds	-220(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-24(%ebp), %eax
	movl	144(%eax), %eax
	movl	8(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2608, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	movl	-24(%ebp), %eax
	fstps	28(%eax)
	.loc 1 1726 0
	flds	-76(%ebp)
	flds	-340(%ebp)
	flds	-220(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-28(%ebp), %eax
	movl	144(%eax), %eax
	movl	8(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2608, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	movl	-28(%ebp), %eax
	fstps	28(%eax)
	.loc 1 1727 0
	flds	-76(%ebp)
	flds	-364(%ebp)
	flds	-220(%ebp)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	movl	-32(%ebp), %eax
	movl	144(%eax), %eax
	movl	8(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2608, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	movl	-32(%ebp), %eax
	fstps	28(%eax)
.LBE45:
	.loc 1 1728 0
	leave
	ret
	.cfi_endproc
.LFE35:
	.size	blendCorner3, .-blendCorner3
.globl seekCorner
	.type	seekCorner, @function
seekCorner:
.LFB36:
	.loc 1 1731 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI54:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI55:
	.cfi_def_cfa_register 5
	subl	$56, %esp
	call	mcount
	.loc 1 1731 0
.LBB46:
	.loc 1 1733 0
	movl	$-1, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1734 0
	movl	-12(%ebp), %eax
	flds	20(%eax)
	flds	20(%ebp)
	fldl	.LC17
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-28(%ebp)
	flds	-28(%ebp)
	movl	-12(%ebp), %eax
	fstps	20(%eax)
	.loc 1 1735 0
	movl	$-2, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1736 0
	movl	-12(%ebp), %eax
	flds	20(%eax)
	fadds	20(%ebp)
	movl	-12(%ebp), %eax
	fstps	20(%eax)
	.loc 1 1737 0
	movl	$-3, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1738 0
	movl	-12(%ebp), %eax
	flds	12(%eax)
	flds	16(%ebp)
	fldl	.LC17
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-28(%ebp)
	flds	-28(%ebp)
	movl	-12(%ebp), %eax
	fstps	12(%eax)
	.loc 1 1739 0
	movl	-12(%ebp), %eax
	flds	20(%eax)
	fadds	20(%ebp)
	movl	-12(%ebp), %eax
	fstps	20(%eax)
	.loc 1 1740 0
	movl	$-4, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1741 0
	movl	-12(%ebp), %eax
	flds	12(%eax)
	fadds	16(%ebp)
	movl	-12(%ebp), %eax
	fstps	12(%eax)
	.loc 1 1742 0
	movl	-12(%ebp), %eax
	flds	20(%eax)
	fadds	20(%ebp)
	movl	-12(%ebp), %eax
	fstps	20(%eax)
	.loc 1 1743 0
	movl	$-5, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1744 0
	movl	-12(%ebp), %eax
	flds	20(%eax)
	flds	20(%ebp)
	fldl	.LC17
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-28(%ebp)
	flds	-28(%ebp)
	movl	-12(%ebp), %eax
	fstps	20(%eax)
	.loc 1 1745 0
	movl	-12(%ebp), %eax
	flds	12(%eax)
	fadds	16(%ebp)
	movl	-12(%ebp), %eax
	fstps	12(%eax)
	.loc 1 1746 0
	movl	$-6, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1747 0
	movl	-12(%ebp), %eax
	flds	12(%eax)
	fadds	16(%ebp)
	movl	-12(%ebp), %eax
	fstps	12(%eax)
	.loc 1 1748 0
	movl	$-7, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1749 0
	movl	-12(%ebp), %eax
	flds	12(%eax)
	fadds	16(%ebp)
	movl	-12(%ebp), %eax
	fstps	12(%eax)
	.loc 1 1750 0
	movl	-12(%ebp), %eax
	flds	20(%eax)
	flds	20(%ebp)
	fldl	.LC67
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-28(%ebp)
	flds	-28(%ebp)
	movl	-12(%ebp), %eax
	fstps	20(%eax)
	.loc 1 1751 0
	movl	$-8, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1752 0
	movl	-12(%ebp), %eax
	flds	12(%eax)
	fadds	16(%ebp)
	movl	-12(%ebp), %eax
	fstps	12(%eax)
	.loc 1 1753 0
	movl	-12(%ebp), %eax
	flds	20(%eax)
	fsubs	20(%ebp)
	movl	-12(%ebp), %eax
	fstps	20(%eax)
	.loc 1 1754 0
	movl	$-9, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1755 0
	movl	-12(%ebp), %eax
	flds	12(%eax)
	flds	16(%ebp)
	fldl	.LC17
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-28(%ebp)
	flds	-28(%ebp)
	movl	-12(%ebp), %eax
	fstps	12(%eax)
	.loc 1 1756 0
	movl	-12(%ebp), %eax
	flds	20(%eax)
	fsubs	20(%ebp)
	movl	-12(%ebp), %eax
	fstps	20(%eax)
	.loc 1 1757 0
	movl	$-10, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1758 0
	movl	-12(%ebp), %eax
	flds	20(%eax)
	fsubs	20(%ebp)
	movl	-12(%ebp), %eax
	fstps	20(%eax)
	.loc 1 1759 0
	movl	$-11, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1760 0
	movl	-12(%ebp), %eax
	flds	12(%eax)
	flds	16(%ebp)
	fldl	.LC67
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-28(%ebp)
	flds	-28(%ebp)
	movl	-12(%ebp), %eax
	fstps	12(%eax)
	.loc 1 1761 0
	movl	-12(%ebp), %eax
	flds	20(%eax)
	fsubs	20(%ebp)
	movl	-12(%ebp), %eax
	fstps	20(%eax)
	.loc 1 1762 0
	movl	$-12, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1763 0
	movl	-12(%ebp), %eax
	flds	12(%eax)
	fsubs	16(%ebp)
	movl	-12(%ebp), %eax
	fstps	12(%eax)
	.loc 1 1764 0
	movl	-12(%ebp), %eax
	flds	20(%eax)
	fsubs	20(%ebp)
	movl	-12(%ebp), %eax
	fstps	20(%eax)
	.loc 1 1765 0
	movl	$-13, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1766 0
	movl	-12(%ebp), %eax
	flds	12(%eax)
	fsubs	16(%ebp)
	movl	-12(%ebp), %eax
	fstps	12(%eax)
	.loc 1 1767 0
	movl	-12(%ebp), %eax
	flds	20(%eax)
	flds	20(%ebp)
	fldl	.LC67
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-28(%ebp)
	flds	-28(%ebp)
	movl	-12(%ebp), %eax
	fstps	20(%eax)
	.loc 1 1768 0
	movl	$-14, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1769 0
	movl	-12(%ebp), %eax
	flds	12(%eax)
	fsubs	16(%ebp)
	movl	-12(%ebp), %eax
	fstps	12(%eax)
	.loc 1 1770 0
	movl	$-15, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1771 0
	movl	-12(%ebp), %eax
	flds	12(%eax)
	fsubs	16(%ebp)
	movl	-12(%ebp), %eax
	fstps	12(%eax)
	.loc 1 1772 0
	movl	-12(%ebp), %eax
	flds	20(%eax)
	flds	20(%ebp)
	fldl	.LC17
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-28(%ebp)
	flds	-28(%ebp)
	movl	-12(%ebp), %eax
	fstps	20(%eax)
	.loc 1 1773 0
	movl	$-16, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1774 0
	movl	-12(%ebp), %eax
	flds	12(%eax)
	fsubs	16(%ebp)
	movl	-12(%ebp), %eax
	fstps	12(%eax)
	.loc 1 1775 0
	movl	-12(%ebp), %eax
	flds	20(%eax)
	fadds	20(%ebp)
	movl	-12(%ebp), %eax
	fstps	20(%eax)
	.loc 1 1776 0
	movl	$-17, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1777 0
	movl	-12(%ebp), %eax
	flds	12(%eax)
	flds	16(%ebp)
	fldl	.LC67
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-28(%ebp)
	flds	-28(%ebp)
	movl	-12(%ebp), %eax
	fstps	12(%eax)
	.loc 1 1778 0
	movl	-12(%ebp), %eax
	flds	20(%eax)
	fadds	20(%ebp)
	movl	-12(%ebp), %eax
	fstps	20(%eax)
	.loc 1 1779 0
	movl	$-18, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1780 0
	movl	-12(%ebp), %eax
	flds	20(%eax)
	fadds	20(%ebp)
	movl	-12(%ebp), %eax
	fstps	20(%eax)
	.loc 1 1781 0
	movl	$-19, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1782 0
	movl	-12(%ebp), %eax
	flds	20(%eax)
	flds	20(%ebp)
	fldl	.LC17
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-28(%ebp)
	flds	-28(%ebp)
	movl	-12(%ebp), %eax
	fstps	20(%eax)
.LBE46:
	.loc 1 1783 0
	leave
	ret
	.cfi_endproc
.LFE36:
	.size	seekCorner, .-seekCorner
.globl seekCornerX
	.type	seekCornerX, @function
seekCornerX:
.LFB37:
	.loc 1 1786 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI56:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI57:
	.cfi_def_cfa_register 5
	subl	$56, %esp
	call	mcount
	.loc 1 1786 0
.LBB47:
	.loc 1 1789 0
	movl	$-1, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1790 0
	movl	-12(%ebp), %eax
	flds	20(%eax)
	flds	16(%ebp)
	fldl	.LC67
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-28(%ebp)
	flds	-28(%ebp)
	movl	-12(%ebp), %eax
	fstps	20(%eax)
	.loc 1 1791 0
	movl	$-2, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1792 0
	movl	-12(%ebp), %eax
	flds	20(%eax)
	fsubs	16(%ebp)
	movl	-12(%ebp), %eax
	fstps	20(%eax)
	.loc 1 1793 0
	movl	$-3, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1794 0
	movl	-12(%ebp), %eax
	flds	20(%eax)
	flds	16(%ebp)
	fldl	.LC67
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-28(%ebp)
	flds	-28(%ebp)
	movl	-12(%ebp), %eax
	fstps	20(%eax)
	.loc 1 1796 0
	movl	$-5, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1797 0
	movl	-12(%ebp), %eax
	flds	20(%eax)
	flds	20(%ebp)
	fldl	.LC17
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-28(%ebp)
	flds	-28(%ebp)
	movl	-12(%ebp), %eax
	fstps	20(%eax)
	.loc 1 1798 0
	movl	$-6, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1799 0
	movl	-12(%ebp), %eax
	flds	20(%eax)
	fadds	20(%ebp)
	movl	-12(%ebp), %eax
	fstps	20(%eax)
	.loc 1 1800 0
	movl	$-7, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1801 0
	movl	-12(%ebp), %eax
	flds	20(%eax)
	flds	20(%ebp)
	fldl	.LC17
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-28(%ebp)
	flds	-28(%ebp)
	movl	-12(%ebp), %eax
	fstps	20(%eax)
	.loc 1 1803 0
	movl	$-9, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1804 0
	movl	-12(%ebp), %eax
	flds	12(%eax)
	flds	24(%ebp)
	fldl	.LC67
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-28(%ebp)
	flds	-28(%ebp)
	movl	-12(%ebp), %eax
	fstps	12(%eax)
	.loc 1 1805 0
	movl	$-10, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1806 0
	movl	-12(%ebp), %eax
	flds	12(%eax)
	fsubs	24(%ebp)
	movl	-12(%ebp), %eax
	fstps	12(%eax)
	.loc 1 1807 0
	movl	$-11, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1808 0
	movl	-12(%ebp), %eax
	flds	12(%eax)
	flds	24(%ebp)
	fldl	.LC67
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-28(%ebp)
	flds	-28(%ebp)
	movl	-12(%ebp), %eax
	fstps	12(%eax)
	.loc 1 1810 0
	movl	$-13, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1811 0
	movl	-12(%ebp), %eax
	flds	12(%eax)
	flds	28(%ebp)
	fldl	.LC17
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-28(%ebp)
	flds	-28(%ebp)
	movl	-12(%ebp), %eax
	fstps	12(%eax)
	.loc 1 1812 0
	movl	$-14, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1813 0
	movl	-12(%ebp), %eax
	flds	12(%eax)
	fadds	28(%ebp)
	movl	-12(%ebp), %eax
	fstps	12(%eax)
	.loc 1 1814 0
	movl	$-15, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPoint
	movl	%eax, -12(%ebp)
	.loc 1 1815 0
	movl	-12(%ebp), %eax
	flds	12(%eax)
	flds	28(%ebp)
	fldl	.LC17
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-28(%ebp)
	flds	-28(%ebp)
	movl	-12(%ebp), %eax
	fstps	12(%eax)
.LBE47:
	.loc 1 1817 0
	leave
	ret
	.cfi_endproc
.LFE37:
	.size	seekCornerX, .-seekCornerX
	.section	.rodata
	.align 4
.LC68:
	.string	"error: ppscript (%s) not found!\n"
	.text
.globl expandPath
	.type	expandPath, @function
expandPath:
.LFB38:
	.loc 1 1820 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI58:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI59:
	.cfi_def_cfa_register 5
	subl	$56, %esp
	call	mcount
	.loc 1 1820 0
.LBB48:
	.loc 1 1822 0
	movl	tworkcell, %eax
	movl	%eax, 4(%esp)
	movl	20(%ebp), %eax
	movl	%eax, (%esp)
	call	getPPScript
	movl	%eax, -12(%ebp)
	.loc 1 1823 0
	cmpl	$0, -12(%ebp)
	jne	.L369
	.loc 1 1824 0
	movl	stderr, %eax
	movl	20(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	$.LC68, 4(%esp)
	movl	%eax, (%esp)
	call	fprintf
	.loc 1 1825 0
	movl	$1, (%esp)
	call	exit
.L369:
	.loc 1 1827 0
	movl	-12(%ebp), %eax
	movl	256(%eax), %eax
	cmpl	$6, %eax
	jne	.L370
	.loc 1 1828 0
	movl	trobot, %eax
	movl	24(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	20(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	expandSubPathKatrineIn
	jmp	.L371
.L370:
	.loc 1 1829 0
	movl	-12(%ebp), %eax
	movl	256(%eax), %eax
	cmpl	$7, %eax
	jne	.L372
	.loc 1 1830 0
	movl	trobot, %eax
	movl	24(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	20(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	expandSubPathKatrineOut
	jmp	.L371
.L372:
	.loc 1 1833 0
	movl	-12(%ebp), %eax
	movl	256(%eax), %eax
	andl	$1, %eax
	testl	%eax, %eax
	jne	.L373
	.loc 1 1835 0
	movl	trobot, %eax
	movl	24(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	20(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	expandPathGeneralBoptInHeader
	jmp	.L371
.L373:
	.loc 1 1839 0
	movl	trobot, %eax
	movl	24(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	20(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	12(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	8(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	expandPathGeneralBoptOutHeader
.L371:
.LBE48:
	.loc 1 1842 0
	leave
	ret
	.cfi_endproc
.LFE38:
	.size	expandPath, .-expandPath
	.section	.rodata
	.align 4
.LC69:
	.string	"wrong type ppscript for runbopt!!"
	.text
.globl expandBopt
	.type	expandBopt, @function
expandBopt:
.LFB39:
	.loc 1 1854 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI60:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI61:
	.cfi_def_cfa_register 5
	subl	$72, %esp
	call	mcount
	.loc 1 1854 0
.LBB49:
	.loc 1 1855 0
	movl	$0, -12(%ebp)
	.loc 1 1863 0
	movl	12(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -36(%ebp)
	.loc 1 1865 0
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	getPrevPPScriptCommand
	movl	%eax, -12(%ebp)
	.loc 1 1866 0
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, -16(%ebp)
	.loc 1 1868 0
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	movl	256(%eax), %eax
	movl	%eax, -24(%ebp)
	.loc 1 1869 0
	movl	-12(%ebp), %eax
	movl	4(%eax), %eax
	movl	260(%eax), %eax
	movl	%eax, -28(%ebp)
	.loc 1 1870 0
	movl	tworkcell, %eax
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, (%esp)
	call	getPPScript
	movl	%eax, -20(%ebp)
	.loc 1 1872 0
	movl	tworkcell, %eax
	movl	%eax, (%esp)
	call	getBoptCoeff
	movl	%eax, -32(%ebp)
	.loc 1 1873 0
	cmpl	$0, -32(%ebp)
	jne	.L376
	.loc 1 1874 0
	movl	$.LC69, (%esp)
	call	puts
	jmp	.L378
.L376:
	.loc 1 1876 0
	movl	-36(%ebp), %eax
	movl	-32(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	-28(%ebp), %edx
	movl	%edx, 16(%esp)
	movl	-16(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	-24(%ebp), %edx
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	expandPathBoptGeneral
.L378:
.LBE49:
	.loc 1 1877 0
	leave
	ret
	.cfi_endproc
.LFE39:
	.size	expandBopt, .-expandBopt
.globl generateProgram
	.type	generateProgram, @function
generateProgram:
.LFB40:
	.loc 1 1885 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI62:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI63:
	.cfi_def_cfa_register 5
	subl	$40, %esp
	call	mcount
	.loc 1 1885 0
.LBB50:
	.loc 1 1887 0
	movl	tworkcell, %eax
	movl	%eax, 4(%esp)
	movl	28(%ebp), %eax
	movl	%eax, (%esp)
	call	getPPScript
	movl	%eax, -12(%ebp)
	.loc 1 1888 0
	movl	$0, %eax
.LBE50:
	.loc 1 1889 0
	leave
	ret
	.cfi_endproc
.LFE40:
	.size	generateProgram, .-generateProgram
	.section	.rodata
.LC70:
	.string	"COUNTER delaystop = 1"
	.align 4
.LC71:
	.string	"PATH bopt-pick-%s-%d id=%d,type=%d,time=%d,loadgroup=%d,runbopt=1"
.LC72:
	.string	"END"
	.align 4
.LC73:
	.string	"PATH bopt-place-%s-%d id=%d,type=%d,time=%d,loadgroup=%d,runbopt=1"
.LC74:
	.string	"COUNTER cAItems += 1"
	.align 4
.LC75:
	.string	"PATH bopt-home id=%d,type=%d,time=%d,loadgroup=%d,runbopt=1"
.LC76:
	.string	"COUNTER delaystop = 0"
	.text
.globl expandPathGeneralBoptInHeader
	.type	expandPathGeneralBoptInHeader, @function
expandPathGeneralBoptInHeader:
.LFB41:
	.loc 1 1892 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI64:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI65:
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$580, %esp
	call	mcount
	movl	8(%ebp), %eax
	movl	%eax, -540(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -544(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, -548(%ebp)
	movl	24(%ebp), %eax
	movl	%eax, -552(%ebp)
	.loc 1 1892 0
	movl	%gs:20, %eax
	movl	%eax, -12(%ebp)
	xorl	%eax, %eax
.LBB51:
	.loc 1 1896 0
	movl	tworkcell, %eax
	movl	%eax, 4(%esp)
	movl	-552(%ebp), %eax
	movl	%eax, (%esp)
	.cfi_offset 3, -12
	call	getPPScript
	movl	%eax, -532(%ebp)
	.loc 1 1897 0
	movl	20(%ebp), %eax
	sall	$5, %eax
	movl	%eax, %edx
	sall	$5, %edx
	addl	%edx, %eax
	addl	$272, %eax
	addl	-532(%ebp), %eax
	movl	%eax, -528(%ebp)
	.loc 1 1899 0
	movl	-548(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC70, 4(%esp)
	movl	-544(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -544(%ebp)
	.loc 1 1905 0
	movl	-528(%ebp), %eax
	movl	1028(%eax), %edx
	movl	-528(%ebp), %eax
	movl	1028(%eax), %eax
	movl	-528(%ebp), %ecx
	leal	512(%ecx), %ebx
	movl	28(%ebp), %ecx
	movl	%ecx, 28(%esp)
	movl	$1000, 24(%esp)
	movl	$20, 20(%esp)
	movl	%edx, 16(%esp)
	movl	%eax, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	$.LC71, 4(%esp)
	leal	-524(%ebp), %eax
	movl	%eax, (%esp)
	call	sprintf
	.loc 1 1906 0
	movl	-548(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-524(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-544(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -544(%ebp)
	.loc 1 1911 0
	movl	-548(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC72, 4(%esp)
	movl	-544(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -544(%ebp)
	.loc 1 1916 0
	movl	-528(%ebp), %eax
	movl	1028(%eax), %edx
	movl	-528(%ebp), %eax
	movl	1028(%eax), %eax
	movl	-528(%ebp), %ecx
	leal	768(%ecx), %ebx
	movl	28(%ebp), %ecx
	movl	%ecx, 28(%esp)
	movl	$1000, 24(%esp)
	movl	$21, 20(%esp)
	movl	%edx, 16(%esp)
	movl	%eax, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	$.LC73, 4(%esp)
	leal	-524(%ebp), %eax
	movl	%eax, (%esp)
	call	sprintf
	.loc 1 1917 0
	movl	-548(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-524(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-544(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -544(%ebp)
	.loc 1 1922 0
	movl	-548(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC72, 4(%esp)
	movl	-544(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -544(%ebp)
	.loc 1 1925 0
	movl	-548(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC74, 4(%esp)
	movl	-544(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -544(%ebp)
	.loc 1 1931 0
	movl	-528(%ebp), %eax
	movl	1028(%eax), %eax
	movl	28(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	$1000, 16(%esp)
	movl	$22, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$.LC75, 4(%esp)
	leal	-524(%ebp), %eax
	movl	%eax, (%esp)
	call	sprintf
	.loc 1 1932 0
	movl	-548(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-524(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-544(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -544(%ebp)
	.loc 1 1937 0
	movl	-548(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC72, 4(%esp)
	movl	-544(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -544(%ebp)
	.loc 1 1940 0
	movl	-548(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC76, 4(%esp)
	movl	-544(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -544(%ebp)
	.loc 1 1941 0
	movl	-544(%ebp), %eax
.LBE51:
	.loc 1 1942 0
	movl	-12(%ebp), %edx
	xorl	%gs:20, %edx
	je	.L383
	call	__stack_chk_fail
.L383:
	addl	$580, %esp
	popl	%ebx
	popl	%ebp
	ret
	.cfi_endproc
.LFE41:
	.size	expandPathGeneralBoptInHeader, .-expandPathGeneralBoptInHeader
	.section	.rodata
.LC77:
	.string	"COUNTER cBItems += 1"
	.text
.globl expandPathGeneralBoptOutHeader
	.type	expandPathGeneralBoptOutHeader, @function
expandPathGeneralBoptOutHeader:
.LFB42:
	.loc 1 1945 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI66:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI67:
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$580, %esp
	call	mcount
	movl	8(%ebp), %eax
	movl	%eax, -540(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -544(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, -548(%ebp)
	movl	24(%ebp), %eax
	movl	%eax, -552(%ebp)
	.loc 1 1945 0
	movl	%gs:20, %eax
	movl	%eax, -12(%ebp)
	xorl	%eax, %eax
.LBB52:
	.loc 1 1949 0
	movl	tworkcell, %eax
	movl	%eax, 4(%esp)
	movl	-552(%ebp), %eax
	movl	%eax, (%esp)
	.cfi_offset 3, -12
	call	getPPScript
	movl	%eax, -532(%ebp)
	.loc 1 1950 0
	movl	20(%ebp), %eax
	sall	$5, %eax
	movl	%eax, %edx
	sall	$5, %edx
	addl	%edx, %eax
	addl	$272, %eax
	addl	-532(%ebp), %eax
	movl	%eax, -528(%ebp)
	.loc 1 1952 0
	movl	-548(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC70, 4(%esp)
	movl	-544(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -544(%ebp)
	.loc 1 1957 0
	movl	-528(%ebp), %eax
	movl	1028(%eax), %edx
	movl	-528(%ebp), %eax
	movl	1028(%eax), %eax
	movl	-528(%ebp), %ecx
	leal	512(%ecx), %ebx
	movl	28(%ebp), %ecx
	movl	%ecx, 28(%esp)
	movl	$1000, 24(%esp)
	movl	$23, 20(%esp)
	movl	%edx, 16(%esp)
	movl	%eax, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	$.LC71, 4(%esp)
	leal	-524(%ebp), %eax
	movl	%eax, (%esp)
	call	sprintf
	.loc 1 1958 0
	movl	-548(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-524(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-544(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -544(%ebp)
	.loc 1 1963 0
	movl	-548(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC72, 4(%esp)
	movl	-544(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -544(%ebp)
	.loc 1 1969 0
	movl	-528(%ebp), %eax
	movl	1028(%eax), %edx
	movl	-528(%ebp), %eax
	movl	1028(%eax), %eax
	movl	-528(%ebp), %ecx
	leal	768(%ecx), %ebx
	movl	28(%ebp), %ecx
	movl	%ecx, 28(%esp)
	movl	$1000, 24(%esp)
	movl	$24, 20(%esp)
	movl	%edx, 16(%esp)
	movl	%eax, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	$.LC73, 4(%esp)
	leal	-524(%ebp), %eax
	movl	%eax, (%esp)
	call	sprintf
	.loc 1 1970 0
	movl	-548(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-524(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-544(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -544(%ebp)
	.loc 1 1975 0
	movl	-548(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC72, 4(%esp)
	movl	-544(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -544(%ebp)
	.loc 1 1977 0
	movl	-548(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC77, 4(%esp)
	movl	-544(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -544(%ebp)
	.loc 1 1983 0
	movl	-528(%ebp), %eax
	movl	1028(%eax), %eax
	movl	28(%ebp), %edx
	movl	%edx, 20(%esp)
	movl	$1000, 16(%esp)
	movl	$25, 12(%esp)
	movl	%eax, 8(%esp)
	movl	$.LC75, 4(%esp)
	leal	-524(%ebp), %eax
	movl	%eax, (%esp)
	call	sprintf
	.loc 1 1984 0
	movl	-548(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-524(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-544(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -544(%ebp)
	.loc 1 1989 0
	movl	-548(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC72, 4(%esp)
	movl	-544(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -544(%ebp)
	.loc 1 1992 0
	movl	-548(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC76, 4(%esp)
	movl	-544(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -544(%ebp)
	.loc 1 1993 0
	movl	-544(%ebp), %eax
.LBE52:
	.loc 1 1994 0
	movl	-12(%ebp), %edx
	xorl	%gs:20, %edx
	je	.L386
	call	__stack_chk_fail
.L386:
	addl	$580, %esp
	popl	%ebx
	popl	%ebp
	ret
	.cfi_endproc
.LFE42:
	.size	expandPathGeneralBoptOutHeader, .-expandPathGeneralBoptOutHeader
	.section	.rodata
.LC78:
	.string	"home"
	.text
.globl expandPathBoptGeneral
	.type	expandPathBoptGeneral, @function
expandPathBoptGeneral:
.LFB43:
	.loc 1 2008 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI68:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI69:
	.cfi_def_cfa_register 5
	pushl	%esi
	pushl	%ebx
	subl	$112, %esp
	call	mcount
	.loc 1 2008 0
.LBB53:
	.loc 1 2014 0
	movl	tworkcell, %eax
	movl	%eax, 4(%esp)
	movl	20(%ebp), %eax
	movl	%eax, (%esp)
	.cfi_offset 3, -16
	.cfi_offset 6, -12
	call	getPPScript
	movl	%eax, -28(%ebp)
	.loc 1 2015 0
	movl	-28(%ebp), %eax
	movl	268(%eax), %eax
	movl	%eax, -32(%ebp)
	.loc 1 2016 0
	movl	-28(%ebp), %eax
	movl	264(%eax), %eax
	movl	%eax, -36(%ebp)
	.loc 1 2017 0
	movl	16(%ebp), %eax
	sall	$5, %eax
	movl	%eax, %edx
	sall	$5, %edx
	addl	%edx, %eax
	addl	$272, %eax
	addl	-28(%ebp), %eax
	movl	%eax, -24(%ebp)
	.loc 1 2018 0
	movl	-24(%ebp), %eax
	movl	1024(%eax), %eax
	movl	%eax, -40(%ebp)
	.loc 1 2019 0
	movl	-24(%ebp), %eax
	movl	1028(%eax), %eax
	movl	%eax, -44(%ebp)
	.loc 1 2020 0
	movl	-24(%ebp), %eax
	leal	512(%eax), %edx
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	getFrameIdx
	imull	$280, %eax, %eax
	addl	$2320, %eax
	addl	8(%ebp), %eax
	addl	$16, %eax
	movl	%eax, -16(%ebp)
	.loc 1 2021 0
	movl	-24(%ebp), %eax
	leal	768(%eax), %edx
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	getFrameIdx
	imull	$280, %eax, %eax
	addl	$2320, %eax
	addl	8(%ebp), %eax
	addl	$16, %eax
	movl	%eax, -12(%ebp)
	.loc 1 2022 0
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC78, (%esp)
	call	getFrameIdx
	imull	$280, %eax, %eax
	addl	$2320, %eax
	addl	8(%ebp), %eax
	addl	$16, %eax
	movl	%eax, -20(%ebp)
	.loc 1 2024 0
	movl	12(%ebp), %eax
	movl	280(%eax), %eax
	cmpl	$20, %eax
	jne	.L388
	.loc 1 2026 0
	movl	12(%ebp), %eax
	movl	280(%eax), %edx
	movl	-28(%ebp), %eax
	movl	256(%eax), %eax
	movl	-24(%ebp), %ecx
	leal	256(%ecx), %ebx
	movl	28(%ebp), %ecx
	movl	%ecx, 48(%esp)
	movl	%edx, 44(%esp)
	movl	%eax, 40(%esp)
	movl	24(%ebp), %eax
	movl	%eax, 36(%esp)
	movl	%ebx, 32(%esp)
	movl	$0, 28(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	-40(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$-1, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	expandPathBoptGeneric
	jmp	.L394
.L388:
	.loc 1 2028 0
	movl	12(%ebp), %eax
	movl	280(%eax), %eax
	cmpl	$21, %eax
	jne	.L390
	.loc 1 2030 0
	movl	12(%ebp), %eax
	movl	280(%eax), %edx
	movl	-28(%ebp), %eax
	movl	256(%eax), %eax
	movl	-24(%ebp), %ecx
	leal	256(%ecx), %esi
	movl	-24(%ebp), %ecx
	leal	256(%ecx), %ebx
	movl	28(%ebp), %ecx
	movl	%ecx, 48(%esp)
	movl	%edx, 44(%esp)
	movl	%eax, 40(%esp)
	movl	24(%ebp), %eax
	movl	%eax, 36(%esp)
	movl	%esi, 32(%esp)
	movl	%ebx, 28(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	$-1, 12(%esp)
	movl	-40(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	expandPathBoptGeneric
	jmp	.L394
.L390:
	.loc 1 2032 0
	movl	12(%ebp), %eax
	movl	280(%eax), %eax
	cmpl	$22, %eax
	jne	.L391
	.loc 1 2034 0
	movl	12(%ebp), %eax
	movl	280(%eax), %edx
	movl	-28(%ebp), %eax
	movl	256(%eax), %eax
	movl	-24(%ebp), %ecx
	leal	256(%ecx), %ebx
	movl	28(%ebp), %ecx
	movl	%ecx, 48(%esp)
	movl	%edx, 44(%esp)
	movl	%eax, 40(%esp)
	movl	24(%ebp), %eax
	movl	%eax, 36(%esp)
	movl	$0, 32(%esp)
	movl	%ebx, 28(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	$-1, 12(%esp)
	movl	$-1, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	expandPathBoptGeneric
	jmp	.L394
.L391:
	.loc 1 2036 0
	movl	12(%ebp), %eax
	movl	280(%eax), %eax
	cmpl	$23, %eax
	jne	.L392
	.loc 1 2038 0
	movl	12(%ebp), %eax
	movl	280(%eax), %edx
	movl	-28(%ebp), %eax
	movl	256(%eax), %eax
	movl	-24(%ebp), %ecx
	leal	256(%ecx), %ebx
	movl	28(%ebp), %ecx
	movl	%ecx, 48(%esp)
	movl	%edx, 44(%esp)
	movl	%eax, 40(%esp)
	movl	24(%ebp), %eax
	movl	%eax, 36(%esp)
	movl	%ebx, 32(%esp)
	movl	$0, 28(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	$-1, 12(%esp)
	movl	$-1, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	expandPathBoptGeneric
	jmp	.L394
.L392:
	.loc 1 2040 0
	movl	12(%ebp), %eax
	movl	280(%eax), %eax
	cmpl	$24, %eax
	jne	.L393
	.loc 1 2042 0
	movl	12(%ebp), %eax
	movl	280(%eax), %edx
	movl	-28(%ebp), %eax
	movl	256(%eax), %eax
	movl	-24(%ebp), %ecx
	leal	256(%ecx), %esi
	movl	-24(%ebp), %ecx
	leal	256(%ecx), %ebx
	movl	28(%ebp), %ecx
	movl	%ecx, 48(%esp)
	movl	%edx, 44(%esp)
	movl	%eax, 40(%esp)
	movl	24(%ebp), %eax
	movl	%eax, 36(%esp)
	movl	%esi, 32(%esp)
	movl	%ebx, 28(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	-40(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	$-1, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	expandPathBoptGeneric
	jmp	.L394
.L393:
	.loc 1 2044 0
	movl	12(%ebp), %eax
	movl	280(%eax), %eax
	cmpl	$25, %eax
	jne	.L394
	.loc 1 2046 0
	movl	12(%ebp), %eax
	movl	280(%eax), %edx
	movl	-28(%ebp), %eax
	movl	256(%eax), %eax
	movl	-24(%ebp), %ecx
	leal	256(%ecx), %ebx
	movl	28(%ebp), %ecx
	movl	%ecx, 48(%esp)
	movl	%edx, 44(%esp)
	movl	%eax, 40(%esp)
	movl	24(%ebp), %eax
	movl	%eax, 36(%esp)
	movl	$0, 32(%esp)
	movl	%ebx, 28(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	-44(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	$-1, 12(%esp)
	movl	-40(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	expandPathBoptGeneric
.L394:
.LBE53:
	.loc 1 2048 0
	addl	$112, %esp
	popl	%ebx
	popl	%esi
	popl	%ebp
	ret
	.cfi_endproc
.LFE43:
	.size	expandPathBoptGeneral, .-expandPathBoptGeneral
.globl viavectpos1
	.bss
	.align 32
	.type	viavectpos1, @object
	.size	viavectpos1, 48
viavectpos1:
	.zero	48
.globl viavecthast1
	.align 4
	.type	viavecthast1, @object
	.size	viavecthast1, 24
viavecthast1:
	.zero	24
.globl viavectpos2
	.align 32
	.type	viavectpos2, @object
	.size	viavectpos2, 48
viavectpos2:
	.zero	48
.globl viavecthast2
	.align 4
	.type	viavecthast2, @object
	.size	viavecthast2, 24
viavecthast2:
	.zero	24
.globl viavectabs1
	.align 4
	.type	viavectabs1, @object
	.size	viavectabs1, 24
viavectabs1:
	.zero	24
.globl viavectabs2
	.align 4
	.type	viavectabs2, @object
	.size	viavectabs2, 24
viavectabs2:
	.zero	24
.globl toVector
	.align 4
	.type	toVector, @object
	.size	toVector, 24
toVector:
	.zero	24
.globl fromVector
	.align 4
	.type	fromVector, @object
	.size	fromVector, 24
fromVector:
	.zero	24
.globl startmacro
	.align 32
	.type	startmacro, @object
	.size	startmacro, 32
startmacro:
	.zero	32
.globl endmacro
	.align 32
	.type	endmacro, @object
	.size	endmacro, 32
endmacro:
	.zero	32
	.section	.rodata
	.align 4
.LC81:
	.string	"Item is (%s , %s). adjusting with bfgplhtr(%f %f %f %f %f %f %f %f)\n"
.LC80:
	.string	"nothing"
	.text
.globl expandPathBoptGeneric
	.type	expandPathBoptGeneric, @function
expandPathBoptGeneric:
.LFB44:
	.loc 1 2074 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI70:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI71:
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%ebx
	subl	$752, %esp
	call	mcount
	movl	8(%ebp), %eax
	movl	%eax, -636(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -640(%ebp)
	movl	28(%ebp), %eax
	movl	%eax, -644(%ebp)
	movl	32(%ebp), %eax
	movl	%eax, -648(%ebp)
	movl	36(%ebp), %eax
	movl	%eax, -652(%ebp)
	movl	40(%ebp), %eax
	movl	%eax, -656(%ebp)
	movl	56(%ebp), %eax
	movl	%eax, -660(%ebp)
	.loc 1 2074 0
	movl	%gs:20, %eax
	movl	%eax, -12(%ebp)
	xorl	%eax, %eax
.LBB54:
	.loc 1 2076 0
	leal	-300(%ebp), %ebx
	.cfi_offset 3, -16
	.cfi_offset 7, -12
	movl	$0, %eax
	movl	$70, %edx
	movl	%ebx, %edi
	movl	%edx, %ecx
	rep stosl
	movl	$1702060386, -300(%ebp)
	movl	$0, -296(%ebp)
	leal	-292(%ebp), %ebx
	movl	$0, %eax
	movl	$62, %edx
	movl	%ebx, %edi
	movl	%edx, %ecx
	rep stosl
	.loc 1 2077 0
	movl	$0x00000000, %eax
	movl	%eax, -424(%ebp)
	movl	$0x00000000, %eax
	movl	%eax, -420(%ebp)
	movl	$0x00000000, %eax
	movl	%eax, -416(%ebp)
	movl	$0x00000000, %eax
	movl	%eax, -412(%ebp)
	movl	$0x00000000, %eax
	movl	%eax, -408(%ebp)
	movl	$0x00000000, %eax
	movl	%eax, -404(%ebp)
	.loc 1 2079 0
	cmpl	$0, -644(%ebp)
	je	.L396
	cmpl	$0, -648(%ebp)
	jne	.L397
.L396:
	movl	$0, %eax
	jmp	.L398
.L397:
	.loc 1 2080 0
	movl	52(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	48(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-660(%ebp), %eax
	movl	%eax, (%esp)
	call	getBoptCoeffItem
	movl	%eax, -316(%ebp)
	.loc 1 2081 0
	cmpl	$0, -316(%ebp)
	jne	.L399
	movl	$0, %eax
	jmp	.L398
.L399:
	.loc 1 2082 0
	movl	-640(%ebp), %eax
	movl	52(%ebp), %edx
	movl	%edx, 280(%eax)
	.loc 1 2084 0
	movl	-316(%ebp), %eax
	movl	10872(%eax), %eax
	movl	%eax, -320(%ebp)
	.loc 1 2086 0
	movl	-316(%ebp), %eax
	movl	10892(%eax), %eax
	movl	%eax, -324(%ebp)
	.loc 1 2087 0
	movl	-316(%ebp), %eax
	movl	10876(%eax), %eax
	movl	%eax, -328(%ebp)
	.loc 1 2088 0
	movl	-316(%ebp), %eax
	movl	10880(%eax), %eax
	movl	%eax, -332(%ebp)
	.loc 1 2089 0
	movl	-316(%ebp), %eax
	movl	10896(%eax), %eax
	movl	%eax, -336(%ebp)
	.loc 1 2091 0
	leal	-300(%ebp), %eax
	movl	%eax, 12(%esp)
	leal	-424(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-644(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$fromVector, (%esp)
	call	convertToFrame_vectorstyle
	.loc 1 2092 0
	leal	-300(%ebp), %eax
	movl	%eax, 12(%esp)
	leal	-424(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-648(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$toVector, (%esp)
	call	convertToFrame_vectorstyle
	.loc 1 2095 0
	movl	tworkcell, %eax
	movl	%eax, 4(%esp)
	movl	-652(%ebp), %eax
	movl	%eax, (%esp)
	call	getItem
	movl	%eax, -308(%ebp)
	.loc 1 2096 0
	movl	tworkcell, %eax
	movl	%eax, 4(%esp)
	movl	-656(%ebp), %eax
	movl	%eax, (%esp)
	call	getItem
	movl	%eax, -312(%ebp)
	.loc 1 2100 0
	cmpl	$0, -308(%ebp)
	je	.L400
	.loc 1 2102 0
	cmpl	$22, 52(%ebp)
	je	.L401
	cmpl	$25, 52(%ebp)
	je	.L401
	cmpl	$44, 52(%ebp)
	jne	.L402
.L401:
	.loc 1 2103 0
	flds	fromVector+4
	movl	-308(%ebp), %eax
	flds	788(%eax)
	faddp	%st, %st(1)
	fstps	fromVector+4
	.loc 1 2102 0
	jmp	.L403
.L402:
	.loc 1 2105 0
	flds	fromVector+4
	movl	-308(%ebp), %eax
	flds	784(%eax)
	faddp	%st, %st(1)
	fstps	fromVector+4
.L403:
	.loc 1 2106 0
	cmpl	$-1, 16(%ebp)
	je	.L404
	.loc 1 2108 0
	flds	fromVector+4
	fildl	16(%ebp)
	movl	-308(%ebp), %eax
	flds	780(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	fromVector+4
.L404:
	.loc 1 2110 0
	cmpl	$24, 52(%ebp)
	je	.L405
	cmpl	$43, 52(%ebp)
	jne	.L454
.L405:
	.loc 1 2111 0
	flds	fromVector
	movl	-308(%ebp), %eax
	flds	792(%eax)
	fsubrp	%st, %st(1)
	fstps	fromVector
	jmp	.L407
.L400:
	.loc 1 2115 0
	flds	fromVector+4
	fildl	16(%ebp)
	faddp	%st, %st(1)
	fstps	fromVector+4
	jmp	.L407
.L454:
	.loc 1 2111 0
	nop
.L407:
	.loc 1 2117 0
	cmpl	$0, -312(%ebp)
	je	.L408
	.loc 1 2119 0
	cmpl	$20, 52(%ebp)
	je	.L409
	cmpl	$23, 52(%ebp)
	jne	.L410
.L409:
	.loc 1 2120 0
	flds	toVector+4
	movl	-312(%ebp), %eax
	flds	784(%eax)
	faddp	%st, %st(1)
	fstps	toVector+4
	.loc 1 2119 0
	jmp	.L411
.L410:
	.loc 1 2122 0
	flds	toVector+4
	movl	-312(%ebp), %eax
	flds	788(%eax)
	faddp	%st, %st(1)
	fstps	toVector+4
.L411:
	.loc 1 2123 0
	cmpl	$-1, 20(%ebp)
	je	.L412
	.loc 1 2125 0
	flds	toVector+4
	fildl	20(%ebp)
	movl	-312(%ebp), %eax
	flds	780(%eax)
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	toVector+4
.L412:
	.loc 1 2127 0
	cmpl	$23, 52(%ebp)
	je	.L413
	cmpl	$44, 52(%ebp)
	jne	.L455
.L413:
	.loc 1 2128 0
	flds	toVector
	movl	-312(%ebp), %eax
	flds	792(%eax)
	fsubrp	%st, %st(1)
	fstps	toVector
	jmp	.L415
.L408:
	.loc 1 2132 0
	flds	toVector+4
	fildl	20(%ebp)
	faddp	%st, %st(1)
	fstps	toVector+4
	jmp	.L415
.L455:
	.loc 1 2128 0
	nop
.L415:
	.loc 1 2134 0
	flds	fromVector+4
	fsubs	-332(%ebp)
	flds	-328(%ebp)
	fsubs	-332(%ebp)
	fdivrp	%st, %st(1)
	fstps	-340(%ebp)
	.loc 1 2135 0
	fld1
	fsubs	-340(%ebp)
	fstps	-344(%ebp)
	.loc 1 2136 0
	flds	toVector+4
	fsubs	-332(%ebp)
	flds	-328(%ebp)
	fsubs	-332(%ebp)
	fdivrp	%st, %st(1)
	fstps	-352(%ebp)
	.loc 1 2137 0
	fld1
	fsubs	-352(%ebp)
	fstps	-348(%ebp)
	.loc 1 2138 0
	flds	fromVector+8
	flds	toVector+8
	fsubrp	%st, %st(1)
	fabs
	fdivs	-324(%ebp)
	fstps	-356(%ebp)
	.loc 1 2139 0
	flds	toVector+4
	flds	fromVector+4
	fsubrp	%st, %st(1)
	fabs
	flds	-328(%ebp)
	fsubs	-332(%ebp)
	fdivrp	%st, %st(1)
	fstps	-360(%ebp)
	.loc 1 2140 0
	flds	toVector+12
	flds	fromVector+12
	fsubrp	%st, %st(1)
	fabs
	flds	.LC40
	fdivrp	%st, %st(1)
	fstps	-364(%ebp)
	.loc 1 2141 0
	flds	toVector+16
	flds	fromVector+16
	fsubrp	%st, %st(1)
	flds	.LC79
	fdivrp	%st, %st(1)
	fstps	-368(%ebp)
	.loc 1 2142 0
	movl	.LC80, %eax
	movl	.LC80+4, %edx
	movl	%eax, -20(%ebp)
	movl	%edx, -16(%ebp)
	.loc 1 2145 0
	cmpl	$0, -308(%ebp)
	jne	.L416
	.loc 1 2146 0
	leal	-20(%ebp), %eax
	movl	%eax, -372(%ebp)
	jmp	.L417
.L416:
	.loc 1 2148 0
	movl	-308(%ebp), %eax
	addl	$256, %eax
	movl	%eax, -372(%ebp)
.L417:
	.loc 1 2149 0
	cmpl	$0, -312(%ebp)
	jne	.L418
	.loc 1 2150 0
	leal	-20(%ebp), %eax
	movl	%eax, -376(%ebp)
	jmp	.L419
.L418:
	.loc 1 2152 0
	movl	-312(%ebp), %eax
	addl	$256, %eax
	movl	%eax, -376(%ebp)
.L419:
	.loc 1 2153 0
	movl	rs_param+2600, %eax
	testl	%eax, %eax
	jle	.L420
	flds	-368(%ebp)
	flds	-364(%ebp)
	flds	-360(%ebp)
	flds	-356(%ebp)
	flds	-348(%ebp)
	flds	-352(%ebp)
	flds	-344(%ebp)
	flds	-340(%ebp)
	fxch	%st(7)
	fstpl	68(%esp)
	fxch	%st(5)
	fstpl	60(%esp)
	fxch	%st(3)
	fstpl	52(%esp)
	fxch	%st(1)
	fstpl	44(%esp)
	fstpl	36(%esp)
	fstpl	28(%esp)
	fstpl	20(%esp)
	fstpl	12(%esp)
	movl	-376(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-372(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC81, (%esp)
	call	printf
.L420:
	.loc 1 2171 0
	movl	-316(%ebp), %eax
	movl	10764(%eax), %eax
	testl	%eax, %eax
	jne	.L421
	.loc 1 2173 0
	movl	$0, startmacro
	jmp	.L422
.L421:
	.loc 1 2175 0
	movl	-316(%ebp), %eax
	movl	10764(%eax), %eax
	cmpl	$1, %eax
	jne	.L423
	.loc 1 2177 0
	movl	$1, startmacro
	.loc 1 2178 0
	movl	-316(%ebp), %eax
	movl	10768(%eax), %eax
	movl	%eax, startmacro+28
	.loc 1 2179 0
	movl	-316(%ebp), %eax
	movl	10772(%eax), %eax
	movl	%eax, startmacro+16
	.loc 1 2180 0
	movl	-316(%ebp), %eax
	flds	10776(%eax)
	flds	-344(%ebp)
	fmuls	-344(%ebp)
	fmuls	-344(%ebp)
	fld1
	fsubp	%st, %st(1)
	fmulp	%st, %st(1)
	fldl	.LC82
	faddp	%st, %st(1)
	fstps	-664(%ebp)
	flds	-664(%ebp)
	fstps	startmacro+24
	.loc 1 2181 0
	movl	-316(%ebp), %eax
	flds	10780(%eax)
	flds	-344(%ebp)
	fmuls	-344(%ebp)
	fmuls	-344(%ebp)
	fmuls	-344(%ebp)
	fld1
	fsubp	%st, %st(1)
	fmulp	%st, %st(1)
	fstps	startmacro+4
	.loc 1 2182 0
	movl	-316(%ebp), %eax
	movl	10784(%eax), %eax
	movl	%eax, startmacro+8
	.loc 1 2183 0
	movl	-316(%ebp), %eax
	flds	10788(%eax)
	fmuls	-340(%ebp)
	fstps	startmacro+12
	.loc 1 2184 0
	movl	-316(%ebp), %eax
	movl	10792(%eax), %eax
	movl	%eax, startmacro+20
	jmp	.L422
.L423:
	.loc 1 2186 0
	movl	-316(%ebp), %eax
	movl	10764(%eax), %eax
	cmpl	$2, %eax
	jne	.L424
	.loc 1 2188 0
	movl	$2, startmacro
	.loc 1 2189 0
	movl	-316(%ebp), %eax
	movl	10768(%eax), %eax
	movl	%eax, startmacro+28
	.loc 1 2190 0
	movl	-316(%ebp), %eax
	movl	10772(%eax), %eax
	movl	%eax, startmacro+16
	.loc 1 2191 0
	movl	-316(%ebp), %eax
	movl	10776(%eax), %eax
	movl	%eax, startmacro+24
	jmp	.L422
.L424:
	.loc 1 2193 0
	movl	-316(%ebp), %eax
	movl	10764(%eax), %eax
	cmpl	$4, %eax
	jne	.L425
	.loc 1 2195 0
	movl	$4, startmacro
	.loc 1 2196 0
	movl	-316(%ebp), %eax
	movl	10768(%eax), %eax
	movl	%eax, startmacro+28
	.loc 1 2197 0
	movl	-316(%ebp), %eax
	movl	10772(%eax), %eax
	movl	%eax, startmacro+16
	.loc 1 2198 0
	movl	-316(%ebp), %eax
	movl	10776(%eax), %eax
	movl	%eax, startmacro+24
	jmp	.L422
.L425:
	.loc 1 2200 0
	movl	-316(%ebp), %eax
	movl	10764(%eax), %eax
	cmpl	$3, %eax
	jne	.L426
	.loc 1 2202 0
	movl	$3, startmacro
	.loc 1 2203 0
	movl	-316(%ebp), %eax
	movl	10768(%eax), %eax
	movl	%eax, startmacro+28
	.loc 1 2204 0
	movl	-316(%ebp), %eax
	movl	10772(%eax), %eax
	movl	%eax, startmacro+16
	.loc 1 2205 0
	movl	-316(%ebp), %eax
	movl	10776(%eax), %eax
	movl	%eax, startmacro+24
	jmp	.L422
.L426:
	.loc 1 2207 0
	movl	-316(%ebp), %eax
	movl	10764(%eax), %eax
	cmpl	$5, %eax
	jne	.L422
	.loc 1 2209 0
	movl	$5, startmacro
	.loc 1 2210 0
	movl	-316(%ebp), %eax
	movl	10768(%eax), %eax
	movl	%eax, startmacro+28
	.loc 1 2211 0
	movl	-316(%ebp), %eax
	movl	10772(%eax), %eax
	movl	%eax, startmacro+16
	.loc 1 2212 0
	movl	-316(%ebp), %eax
	movl	10776(%eax), %eax
	movl	%eax, startmacro+24
.L422:
	.loc 1 2214 0
	movl	-316(%ebp), %eax
	movl	10796(%eax), %eax
	testl	%eax, %eax
	jne	.L427
	.loc 1 2216 0
	movl	$0, endmacro
	jmp	.L428
.L427:
	.loc 1 2218 0
	movl	-316(%ebp), %eax
	movl	10796(%eax), %eax
	cmpl	$1, %eax
	jne	.L429
	.loc 1 2220 0
	movl	$1, endmacro
	.loc 1 2221 0
	movl	-316(%ebp), %eax
	movl	10800(%eax), %eax
	movl	%eax, endmacro+28
	.loc 1 2222 0
	movl	-316(%ebp), %eax
	movl	10804(%eax), %eax
	movl	%eax, endmacro+16
	.loc 1 2223 0
	movl	-316(%ebp), %eax
	flds	10808(%eax)
	flds	-348(%ebp)
	fmuls	-348(%ebp)
	fmuls	-348(%ebp)
	fld1
	fsubp	%st, %st(1)
	fmulp	%st, %st(1)
	fldl	.LC82
	faddp	%st, %st(1)
	fstps	-664(%ebp)
	flds	-664(%ebp)
	fstps	endmacro+24
	.loc 1 2224 0
	movl	-316(%ebp), %eax
	flds	10812(%eax)
	flds	-348(%ebp)
	fmuls	-348(%ebp)
	fmuls	-348(%ebp)
	fmuls	-348(%ebp)
	fld1
	fsubp	%st, %st(1)
	fmulp	%st, %st(1)
	fstps	endmacro+4
	.loc 1 2225 0
	movl	-316(%ebp), %eax
	movl	10816(%eax), %eax
	movl	%eax, endmacro+8
	.loc 1 2226 0
	movl	-316(%ebp), %eax
	flds	10820(%eax)
	fmuls	-352(%ebp)
	fstps	endmacro+12
	.loc 1 2227 0
	movl	-316(%ebp), %eax
	movl	10824(%eax), %eax
	movl	%eax, endmacro+20
	jmp	.L428
.L429:
	.loc 1 2229 0
	movl	-316(%ebp), %eax
	movl	10796(%eax), %eax
	cmpl	$2, %eax
	jne	.L430
	.loc 1 2231 0
	movl	$2, endmacro
	.loc 1 2232 0
	movl	-316(%ebp), %eax
	movl	10800(%eax), %eax
	movl	%eax, endmacro+28
	.loc 1 2233 0
	movl	-316(%ebp), %eax
	movl	10804(%eax), %eax
	movl	%eax, endmacro+16
	.loc 1 2234 0
	movl	-316(%ebp), %eax
	movl	10808(%eax), %eax
	movl	%eax, endmacro+24
	jmp	.L428
.L430:
	.loc 1 2236 0
	movl	-316(%ebp), %eax
	movl	10796(%eax), %eax
	cmpl	$4, %eax
	jne	.L431
	.loc 1 2238 0
	movl	$4, endmacro
	.loc 1 2239 0
	movl	-316(%ebp), %eax
	movl	10800(%eax), %eax
	movl	%eax, endmacro+28
	.loc 1 2240 0
	movl	-316(%ebp), %eax
	movl	10804(%eax), %eax
	movl	%eax, endmacro+16
	.loc 1 2241 0
	movl	-316(%ebp), %eax
	movl	10808(%eax), %eax
	movl	%eax, endmacro+24
	jmp	.L428
.L431:
	.loc 1 2243 0
	movl	-316(%ebp), %eax
	movl	10796(%eax), %eax
	cmpl	$3, %eax
	jne	.L432
	.loc 1 2245 0
	movl	$3, endmacro
	.loc 1 2246 0
	movl	-316(%ebp), %eax
	movl	10800(%eax), %eax
	movl	%eax, endmacro+28
	.loc 1 2247 0
	movl	-316(%ebp), %eax
	movl	10804(%eax), %eax
	movl	%eax, endmacro+16
	.loc 1 2248 0
	movl	-316(%ebp), %eax
	movl	10808(%eax), %eax
	movl	%eax, endmacro+24
	jmp	.L428
.L432:
	.loc 1 2250 0
	movl	-316(%ebp), %eax
	movl	10796(%eax), %eax
	cmpl	$5, %eax
	jne	.L428
	.loc 1 2252 0
	movl	$5, endmacro
	.loc 1 2253 0
	movl	-316(%ebp), %eax
	movl	10800(%eax), %eax
	movl	%eax, endmacro+28
	.loc 1 2254 0
	movl	-316(%ebp), %eax
	movl	10804(%eax), %eax
	movl	%eax, endmacro+16
	.loc 1 2255 0
	movl	-316(%ebp), %eax
	movl	10808(%eax), %eax
	movl	%eax, endmacro+24
.L428:
	.loc 1 2258 0
	movl	-316(%ebp), %eax
	movl	10884(%eax), %eax
	movl	%eax, -380(%ebp)
	.loc 1 2261 0
	movl	-316(%ebp), %eax
	flds	10828(%eax)
	flds	.LC35
	fmulp	%st, %st(1)
	fstps	-448(%ebp)
	.loc 1 2262 0
	movl	-316(%ebp), %eax
	flds	10832(%eax)
	flds	.LC40
	fmulp	%st, %st(1)
	flds	.LC39
	fdivrp	%st, %st(1)
	fstps	-444(%ebp)
	.loc 1 2263 0
	movl	-316(%ebp), %eax
	flds	10836(%eax)
	flds	.LC40
	fmulp	%st, %st(1)
	flds	.LC39
	fdivrp	%st, %st(1)
	fstps	-440(%ebp)
	.loc 1 2264 0
	movl	-316(%ebp), %eax
	flds	10840(%eax)
	flds	.LC40
	fmulp	%st, %st(1)
	flds	.LC39
	fdivrp	%st, %st(1)
	fstps	-436(%ebp)
	.loc 1 2265 0
	movl	-316(%ebp), %eax
	flds	10844(%eax)
	flds	.LC40
	fmulp	%st, %st(1)
	flds	.LC39
	fdivrp	%st, %st(1)
	fstps	-432(%ebp)
	.loc 1 2267 0
	movl	-316(%ebp), %eax
	flds	10848(%eax)
	flds	.LC35
	fmulp	%st, %st(1)
	fstps	-472(%ebp)
	.loc 1 2268 0
	movl	-316(%ebp), %eax
	flds	10852(%eax)
	flds	.LC40
	fmulp	%st, %st(1)
	flds	.LC39
	fdivrp	%st, %st(1)
	fstps	-468(%ebp)
	.loc 1 2269 0
	movl	-316(%ebp), %eax
	flds	10856(%eax)
	flds	.LC40
	fmulp	%st, %st(1)
	flds	.LC39
	fdivrp	%st, %st(1)
	fstps	-464(%ebp)
	.loc 1 2270 0
	movl	-316(%ebp), %eax
	flds	10860(%eax)
	flds	.LC40
	fmulp	%st, %st(1)
	flds	.LC39
	fdivrp	%st, %st(1)
	fstps	-460(%ebp)
	.loc 1 2271 0
	movl	-316(%ebp), %eax
	flds	10864(%eax)
	flds	.LC40
	fmulp	%st, %st(1)
	flds	.LC39
	fdivrp	%st, %st(1)
	fstps	-456(%ebp)
	.loc 1 2279 0
	movl	-316(%ebp), %eax
	addl	$1804, %eax
	movl	%eax, -552(%ebp)
	.loc 1 2280 0
	movl	-316(%ebp), %eax
	addl	$2252, %eax
	movl	%eax, -548(%ebp)
	.loc 1 2281 0
	movl	-316(%ebp), %eax
	addl	$2700, %eax
	movl	%eax, -544(%ebp)
	.loc 1 2282 0
	movl	-316(%ebp), %eax
	addl	$3148, %eax
	movl	%eax, -540(%ebp)
	.loc 1 2283 0
	movl	-316(%ebp), %eax
	addl	$3596, %eax
	movl	%eax, -536(%ebp)
	.loc 1 2284 0
	movl	-316(%ebp), %eax
	addl	$4044, %eax
	movl	%eax, -532(%ebp)
	.loc 1 2285 0
	movl	-316(%ebp), %eax
	addl	$4492, %eax
	movl	%eax, -528(%ebp)
	.loc 1 2286 0
	movl	-316(%ebp), %eax
	addl	$4940, %eax
	movl	%eax, -524(%ebp)
	.loc 1 2287 0
	movl	-316(%ebp), %eax
	addl	$5388, %eax
	movl	%eax, -520(%ebp)
	.loc 1 2288 0
	movl	-316(%ebp), %eax
	addl	$5836, %eax
	movl	%eax, -516(%ebp)
	.loc 1 2289 0
	movl	-316(%ebp), %eax
	addl	$6284, %eax
	movl	%eax, -512(%ebp)
	.loc 1 2290 0
	movl	-316(%ebp), %eax
	addl	$6732, %eax
	movl	%eax, -508(%ebp)
	.loc 1 2291 0
	movl	-316(%ebp), %eax
	addl	$7180, %eax
	movl	%eax, -504(%ebp)
	.loc 1 2292 0
	movl	-316(%ebp), %eax
	addl	$7628, %eax
	movl	%eax, -500(%ebp)
	.loc 1 2293 0
	movl	-316(%ebp), %eax
	addl	$8076, %eax
	movl	%eax, -496(%ebp)
	.loc 1 2294 0
	movl	-316(%ebp), %eax
	addl	$8524, %eax
	movl	%eax, -492(%ebp)
	.loc 1 2295 0
	movl	-316(%ebp), %eax
	addl	$8972, %eax
	movl	%eax, -488(%ebp)
	.loc 1 2296 0
	movl	-316(%ebp), %eax
	addl	$9420, %eax
	movl	%eax, -484(%ebp)
	.loc 1 2297 0
	movl	-316(%ebp), %eax
	addl	$9868, %eax
	movl	%eax, -480(%ebp)
	.loc 1 2298 0
	movl	-316(%ebp), %eax
	addl	$10316, %eax
	movl	%eax, -476(%ebp)
	.loc 1 2300 0
	movl	$0, -400(%ebp)
	jmp	.L433
.L450:
	.loc 1 2302 0
	movl	$0x00000000, %eax
	movl	%eax, -384(%ebp)
	.loc 1 2303 0
	movl	$0, -392(%ebp)
	jmp	.L434
.L449:
	.loc 1 2305 0
	movl	-400(%ebp), %eax
	movl	-552(%ebp,%eax,4), %edx
	movl	-392(%ebp), %eax
	sall	$2, %eax
	leal	0(,%eax,8), %ecx
	movl	%ecx, %ebx
	subl	%eax, %ebx
	movl	%ebx, %eax
	leal	(%edx,%eax), %eax
	movl	20(%eax), %eax
	movl	%eax, -388(%ebp)
	.loc 1 2306 0
	flds	-388(%ebp)
	fldz
	fxch	%st(1)
	fucompp
	fnstsw	%ax
	sahf
	jp	.L456
	je	.L435
.L456:
.L453:
	.loc 1 2308 0
	movl	$0, -396(%ebp)
	jmp	.L437
.L448:
.LBB55:
	.loc 1 2310 0
	movl	-400(%ebp), %eax
	movl	-552(%ebp,%eax,4), %edx
	movl	-392(%ebp), %eax
	sall	$2, %eax
	leal	0(,%eax,8), %ecx
	movl	%ecx, %ebx
	subl	%eax, %ebx
	movl	%ebx, %eax
	addl	%eax, %edx
	movl	-396(%ebp), %eax
	movzbl	4(%edx,%eax), %eax
	movb	%al, -301(%ebp)
	.loc 1 2311 0
	movsbl	-301(%ebp),%eax
	subl	$98, %eax
	cmpl	$18, %eax
	ja	.L438
	movl	.L447(,%eax,4), %eax
	jmp	*%eax
	.section	.rodata
	.align 4
	.align 4
.L447:
	.long	.L439
	.long	.L438
	.long	.L438
	.long	.L438
	.long	.L440
	.long	.L441
	.long	.L442
	.long	.L438
	.long	.L438
	.long	.L438
	.long	.L443
	.long	.L438
	.long	.L438
	.long	.L438
	.long	.L444
	.long	.L438
	.long	.L445
	.long	.L438
	.long	.L446
	.text
.L440:
	.loc 1 2314 0
	flds	-388(%ebp)
	fmuls	-344(%ebp)
	fstps	-388(%ebp)
	.loc 1 2315 0
	jmp	.L438
.L439:
	.loc 1 2317 0
	flds	-388(%ebp)
	fmuls	-340(%ebp)
	fstps	-388(%ebp)
	.loc 1 2318 0
	jmp	.L438
.L444:
	.loc 1 2320 0
	flds	-388(%ebp)
	fmuls	-348(%ebp)
	fstps	-388(%ebp)
	.loc 1 2321 0
	jmp	.L438
.L441:
	.loc 1 2323 0
	flds	-388(%ebp)
	fmuls	-352(%ebp)
	fstps	-388(%ebp)
	.loc 1 2324 0
	jmp	.L438
.L443:
	.loc 1 2326 0
	flds	-388(%ebp)
	fmuls	-356(%ebp)
	fstps	-388(%ebp)
	.loc 1 2327 0
	jmp	.L438
.L442:
	.loc 1 2329 0
	flds	-388(%ebp)
	fmuls	-360(%ebp)
	fstps	-388(%ebp)
	.loc 1 2330 0
	jmp	.L438
.L446:
	.loc 1 2332 0
	flds	-388(%ebp)
	fmuls	-364(%ebp)
	fstps	-388(%ebp)
	.loc 1 2333 0
	jmp	.L438
.L445:
	.loc 1 2335 0
	flds	-388(%ebp)
	fmuls	-368(%ebp)
	fstps	-388(%ebp)
.L438:
.LBE55:
	.loc 1 2308 0
	addl	$1, -396(%ebp)
.L437:
	movl	-400(%ebp), %eax
	movl	-552(%ebp,%eax,4), %edx
	movl	-392(%ebp), %eax
	sall	$2, %eax
	leal	0(,%eax,8), %ecx
	movl	%ecx, %edi
	subl	%eax, %edi
	movl	%edi, %eax
	leal	(%edx,%eax), %eax
	movl	(%eax), %eax
	cmpl	-396(%ebp), %eax
	setg	%al
	testb	%al, %al
	jne	.L448
	.loc 1 2342 0
	flds	-384(%ebp)
	fadds	-388(%ebp)
	fstps	-384(%ebp)
.L435:
	.loc 1 2303 0
	addl	$1, -392(%ebp)
.L434:
	cmpl	$15, -392(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L449
	.loc 1 2345 0
	movl	-400(%ebp), %eax
	movl	-384(%ebp), %edx
	movl	%edx, -632(%ebp,%eax,4)
	.loc 1 2300 0
	addl	$1, -400(%ebp)
.L433:
	cmpl	$19, -400(%ebp)
	setle	%al
	testb	%al, %al
	jne	.L450
	.loc 1 2347 0
	movl	-632(%ebp), %eax
	movl	%eax, viavectpos1
	.loc 1 2348 0
	movl	-316(%ebp), %eax
	movl	1828(%eax), %eax
	movl	%eax, viavectpos1+24
	.loc 1 2349 0
	movl	-628(%ebp), %eax
	movl	%eax, viavectpos1+4
	.loc 1 2350 0
	movl	-316(%ebp), %eax
	movl	2276(%eax), %eax
	movl	%eax, viavectpos1+28
	.loc 1 2351 0
	movl	-624(%ebp), %eax
	movl	%eax, viavectpos1+8
	.loc 1 2352 0
	movl	-316(%ebp), %eax
	movl	2724(%eax), %eax
	movl	%eax, viavectpos1+32
	.loc 1 2353 0
	movl	-620(%ebp), %eax
	movl	%eax, viavectpos1+12
	.loc 1 2354 0
	movl	-316(%ebp), %eax
	movl	3172(%eax), %eax
	movl	%eax, viavectpos1+36
	.loc 1 2355 0
	movl	-616(%ebp), %eax
	movl	%eax, viavectpos1+16
	.loc 1 2356 0
	movl	-316(%ebp), %eax
	movl	3620(%eax), %eax
	movl	%eax, viavectpos1+40
	.loc 1 2357 0
	movl	-612(%ebp), %eax
	movl	%eax, viavectpos2
	.loc 1 2358 0
	movl	-316(%ebp), %eax
	movl	4068(%eax), %eax
	movl	%eax, viavectpos2+24
	.loc 1 2359 0
	movl	-608(%ebp), %eax
	movl	%eax, viavectpos2+4
	.loc 1 2360 0
	movl	-316(%ebp), %eax
	movl	4516(%eax), %eax
	movl	%eax, viavectpos2+28
	.loc 1 2361 0
	movl	-604(%ebp), %eax
	movl	%eax, viavectpos2+8
	.loc 1 2362 0
	movl	-316(%ebp), %eax
	movl	4964(%eax), %eax
	movl	%eax, viavectpos2+32
	.loc 1 2363 0
	movl	-600(%ebp), %eax
	movl	%eax, viavectpos2+12
	.loc 1 2364 0
	movl	-316(%ebp), %eax
	movl	5412(%eax), %eax
	movl	%eax, viavectpos2+36
	.loc 1 2365 0
	movl	-596(%ebp), %eax
	movl	%eax, viavectpos2+16
	.loc 1 2366 0
	movl	-316(%ebp), %eax
	movl	5860(%eax), %eax
	movl	%eax, viavectpos2+40
	.loc 1 2367 0
	movl	-592(%ebp), %eax
	movl	%eax, viavecthast1
	.loc 1 2368 0
	movl	-588(%ebp), %eax
	movl	%eax, viavecthast1+4
	.loc 1 2369 0
	movl	-584(%ebp), %eax
	movl	%eax, viavecthast1+8
	.loc 1 2370 0
	movl	-580(%ebp), %eax
	movl	%eax, viavecthast1+12
	.loc 1 2371 0
	movl	-576(%ebp), %eax
	movl	%eax, viavecthast1+16
	.loc 1 2372 0
	movl	-572(%ebp), %eax
	movl	%eax, viavecthast2
	.loc 1 2373 0
	movl	-568(%ebp), %eax
	movl	%eax, viavecthast2+4
	.loc 1 2374 0
	movl	-564(%ebp), %eax
	movl	%eax, viavecthast2+8
	.loc 1 2375 0
	movl	-560(%ebp), %eax
	movl	%eax, viavecthast2+12
	.loc 1 2376 0
	movl	-556(%ebp), %eax
	movl	%eax, viavecthast2+16
	.loc 1 2378 0
	movl	-316(%ebp), %eax
	movl	10868(%eax), %ecx
	movl	-316(%ebp), %eax
	movl	10868(%eax), %edx
	movl	-316(%ebp), %eax
	movl	264(%eax), %eax
	movl	-336(%ebp), %ebx
	movl	%ebx, 88(%esp)
	movl	-320(%ebp), %ebx
	movl	%ebx, 84(%esp)
	movl	$endmacro, 80(%esp)
	movl	$startmacro, 76(%esp)
	movl	$viavecthast2, 72(%esp)
	movl	$viavectpos2, 68(%esp)
	movl	$viavecthast1, 64(%esp)
	movl	$viavectpos1, 60(%esp)
	leal	-424(%ebp), %ebx
	movl	%ebx, 56(%esp)
	movl	$toVector, 52(%esp)
	leal	-424(%ebp), %ebx
	movl	%ebx, 48(%esp)
	movl	$fromVector, 44(%esp)
	leal	-472(%ebp), %ebx
	movl	%ebx, 40(%esp)
	leal	-448(%ebp), %ebx
	movl	%ebx, 36(%esp)
	movl	%ecx, 32(%esp)
	movl	%edx, 28(%esp)
	movl	-380(%ebp), %edx
	movl	%edx, 24(%esp)
	movl	%eax, 20(%esp)
	movl	44(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	52(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	24(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-640(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-636(%ebp), %eax
	movl	%eax, (%esp)
	call	trajopt
	fstp	%st(0)
	.loc 1 2379 0
	movl	-640(%ebp), %eax
	flds	300(%eax)
	movl	-316(%ebp), %eax
	flds	10888(%eax)
	fmulp	%st, %st(1)
	movl	-640(%ebp), %eax
	fstps	300(%eax)
	.loc 1 2380 0
	movl	$1, %eax
.L398:
.LBE54:
	.loc 1 2381 0
	movl	-12(%ebp), %edx
	xorl	%gs:20, %edx
	je	.L452
	call	__stack_chk_fail
.L452:
	addl	$752, %esp
	popl	%ebx
	popl	%edi
	popl	%ebp
	ret
	.cfi_endproc
.LFE44:
	.size	expandPathBoptGeneric, .-expandPathBoptGeneric
.globl expandBoptLoader
	.type	expandBoptLoader, @function
expandBoptLoader:
.LFB45:
	.loc 1 2384 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI72:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI73:
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$100, %esp
	call	mcount
	.loc 1 2384 0
.LBB56:
	.loc 1 2385 0
	movl	$0, -12(%ebp)
	.loc 1 2386 0
	movl	$0, -16(%ebp)
	.loc 1 2388 0
	movl	12(%ebp), %eax
	addl	$12, %eax
	movl	%eax, -20(%ebp)
	.loc 1 2389 0
	movl	12(%ebp), %eax
	addl	$820, %eax
	movl	%eax, -24(%ebp)
	.loc 1 2394 0
	movl	$-1, -28(%ebp)
	.loc 1 2395 0
	movl	$-1, -32(%ebp)
	.loc 1 2397 0
	movl	12(%ebp), %eax
	movl	816(%eax), %eax
	testl	%eax, %eax
	je	.L458
	.cfi_offset 3, -12
	.loc 1 2399 0
	movl	12(%ebp), %eax
	movl	816(%eax), %edx
	movl	12(%ebp), %eax
	movl	292(%eax), %eax
	imull	$284, %eax, %eax
	addl	$512, %eax
	leal	(%edx,%eax), %eax
	addl	$12, %eax
	movl	%eax, -12(%ebp)
	.loc 1 2400 0
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -28(%ebp)
.L458:
	.loc 1 2403 0
	movl	12(%ebp), %eax
	movl	1624(%eax), %eax
	testl	%eax, %eax
	je	.L459
	.loc 1 2405 0
	movl	12(%ebp), %eax
	movl	1624(%eax), %edx
	movl	12(%ebp), %eax
	movl	1100(%eax), %eax
	imull	$284, %eax, %eax
	addl	$512, %eax
	leal	(%edx,%eax), %eax
	addl	$12, %eax
	movl	%eax, -16(%ebp)
	.loc 1 2406 0
	movl	-16(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -32(%ebp)
.L459:
	.loc 1 2421 0
	movl	tworkcell, %eax
	movl	%eax, (%esp)
	call	getBoptCoeff
	movl	12(%ebp), %edx
	movl	4(%edx), %ecx
	movl	12(%ebp), %edx
	movl	(%edx), %edx
	movl	12(%ebp), %ebx
	addl	$1892, %ebx
	movl	%eax, 48(%esp)
	movl	%ecx, 44(%esp)
	movl	%edx, 40(%esp)
	movl	$0, 36(%esp)
	movl	$0, 32(%esp)
	movl	$0, 28(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, 24(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, 20(%esp)
	movl	$0, 16(%esp)
	movl	$-1, 12(%esp)
	movl	$-1, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	expandPathBoptGeneric
.LBE56:
	.loc 1 2436 0
	addl	$100, %esp
	popl	%ebx
	popl	%ebp
	ret
	.cfi_endproc
.LFE45:
	.size	expandBoptLoader, .-expandBoptLoader
	.section	.rodata
.LC84:
	.string	"SUB %s"
	.align 4
.LC85:
	.string	"PATH %s-%s-%d-%d id=%d,type=%d,time=%d,loadgroup=2,runbopt=0"
	.align 4
.LC86:
	.string	"POINT conveyorB 0,0,0,0,0,0,10 case"
.LC88:
	.string	"case"
.LC90:
	.string	"POSITIONHINT 2"
	.text
.globl generateProgramNS
	.type	generateProgramNS, @function
generateProgramNS:
.LFB46:
	.loc 1 2451 0
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
.LCFI74:
	.cfi_def_cfa_offset 8
	movl	%esp, %ebp
	.cfi_offset 5, -8
.LCFI75:
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$540, %esp
	call	mcount
	movl	8(%ebp), %eax
	movl	%eax, -380(%ebp)
	movl	12(%ebp), %eax
	movl	%eax, -384(%ebp)
	movl	16(%ebp), %eax
	movl	%eax, -388(%ebp)
	movl	28(%ebp), %eax
	movl	%eax, -392(%ebp)
	.loc 1 2451 0
	movl	%gs:20, %eax
	movl	%eax, -28(%ebp)
	xorl	%eax, %eax
.LBB57:
	.loc 1 2463 0
	movl	$5100, -292(%ebp)
	movl	$7, -300(%ebp)
	.loc 1 2464 0
	movl	$0x43c80000, %eax
	movl	%eax, -304(%ebp)
	.loc 1 2474 0
	movl	tworkcell, %eax
	movl	%eax, 4(%esp)
	movl	-392(%ebp), %eax
	movl	%eax, (%esp)
	.cfi_offset 3, -20
	.cfi_offset 6, -16
	.cfi_offset 7, -12
	call	getPPScript
	movl	%eax, -316(%ebp)
	.loc 1 2475 0
	movl	-316(%ebp), %eax
	movl	264(%eax), %eax
	movl	%eax, -300(%ebp)
	.loc 1 2477 0
	movl	-392(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC84, 4(%esp)
	leal	-284(%ebp), %eax
	movl	%eax, (%esp)
	call	sprintf
	.loc 1 2478 0
	movl	-388(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-284(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-380(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -380(%ebp)
	.loc 1 2480 0
	call	copyFramesFromSTMtoRobot
	.loc 1 2482 0
	movl	24(%ebp), %eax
	imull	-300(%ebp), %eax
	movl	%eax, -296(%ebp)
	.loc 1 2483 0
	movl	$0, -288(%ebp)
	jmp	.L462
.L505:
	.loc 1 2485 0
	movl	-296(%ebp), %eax
	sall	$5, %eax
	movl	%eax, %edx
	sall	$5, %edx
	addl	%edx, %eax
	addl	$272, %eax
	addl	-316(%ebp), %eax
	movl	%eax, -312(%ebp)
	addl	$1, -296(%ebp)
	.loc 1 2486 0
	fildl	20(%ebp)
	movl	-312(%ebp), %eax
	fstps	1036(%eax)
	.loc 1 2487 0
	movl	-312(%ebp), %eax
	leal	512(%eax), %edx
	movl	-384(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	getFrameIdx
	movl	%eax, -324(%ebp)
	.loc 1 2488 0
	movl	-324(%ebp), %eax
	imull	$280, %eax, %eax
	addl	$2320, %eax
	addl	-384(%ebp), %eax
	addl	$16, %eax
	movl	%eax, -332(%ebp)
	.loc 1 2489 0
	movl	-312(%ebp), %eax
	leal	768(%eax), %edx
	movl	-384(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	getFrameIdx
	movl	%eax, -320(%ebp)
	.loc 1 2490 0
	movl	-320(%ebp), %eax
	imull	$280, %eax, %eax
	addl	$2320, %eax
	addl	-384(%ebp), %eax
	addl	$16, %eax
	movl	%eax, -328(%ebp)
	.loc 1 2491 0
	movl	20(%ebp), %eax
	addl	$3500, %eax
	movl	%eax, -336(%ebp)
	.loc 1 2492 0
	movl	-312(%ebp), %eax
	flds	1040(%eax)
	flds	.LC83
	fucompp
	fnstsw	%ax
	testb	$5, %ah
	sete	%al
	testb	%al, %al
	je	.L463
	addl	$500, -336(%ebp)
.L463:
	.loc 1 2493 0
	cmpl	$3499, -336(%ebp)
	jg	.L464
	movl	$3500, -336(%ebp)
.L464:
	.loc 1 2494 0
	movl	-292(%ebp), %edx
	addl	$1, -292(%ebp)
	movl	-312(%ebp), %eax
	movl	1028(%eax), %eax
	movl	-312(%ebp), %ecx
	leal	768(%ecx), %esi
	movl	-312(%ebp), %ecx
	leal	512(%ecx), %ebx
	movl	-336(%ebp), %ecx
	movl	%ecx, 32(%esp)
	movl	$13, 28(%esp)
	movl	%edx, 24(%esp)
	movl	%eax, 20(%esp)
	movl	24(%ebp), %eax
	movl	%eax, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%ebx, 8(%esp)
	movl	$.LC85, 4(%esp)
	leal	-284(%ebp), %eax
	movl	%eax, (%esp)
	call	sprintf
	.loc 1 2495 0
	movl	-388(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-284(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-380(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -380(%ebp)
	.loc 1 2496 0
	movl	-388(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC86, 4(%esp)
	movl	-380(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -380(%ebp)
	.loc 1 2497 0
	movl	-388(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC86, 4(%esp)
	movl	-380(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -380(%ebp)
	.loc 1 2498 0
	movl	-388(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC86, 4(%esp)
	movl	-380(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -380(%ebp)
	.loc 1 2499 0
	movl	-388(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC86, 4(%esp)
	movl	-380(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -380(%ebp)
	movl	-380(%ebp), %eax
	movl	%eax, -340(%ebp)
	.loc 1 2504 0
	movl	-312(%ebp), %eax
	leal	512(%eax), %ebx
	movl	-312(%ebp), %eax
	leal	512(%eax), %ecx
	movl	-312(%ebp), %eax
	flds	1048(%eax)
	flds	.LC18
	fmulp	%st, %st(1)
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	-304(%ebp)
	fucompp
	fnstsw	%ax
	testb	$5, %ah
	sete	%al
	testb	%al, %al
	je	.L465
	flds	-304(%ebp)
	flds	.LC87
	faddp	%st, %st(1)
	jmp	.L466
.L465:
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	.LC87
	faddp	%st, %st(1)
.L466:
	movl	-320(%ebp), %eax
	movl	-384(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2596, %eax
	flds	(%eax)
	faddp	%st, %st(1)
	movl	-324(%ebp), %eax
	movl	-384(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2596, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	fldz
	fucompp
	fnstsw	%ax
	testb	$5, %ah
	sete	%al
	testb	%al, %al
	je	.L467
	fldz
	fxch	%st(1)
	jmp	.L468
.L467:
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	-304(%ebp)
	fucompp
	fnstsw	%ax
	testb	$5, %ah
	sete	%al
	testb	%al, %al
	je	.L469
	flds	-304(%ebp)
	flds	.LC87
	faddp	%st, %st(1)
	jmp	.L470
.L469:
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	.LC87
	faddp	%st, %st(1)
.L470:
	movl	-320(%ebp), %eax
	movl	-384(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2596, %eax
	flds	(%eax)
	faddp	%st, %st(1)
	movl	-324(%ebp), %eax
	movl	-384(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2596, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	fxch	%st(1)
.L468:
	movl	-312(%ebp), %eax
	leal	512(%eax), %edx
	movl	$1, 80(%esp)
	movl	$.LC88, 76(%esp)
	movl	%ebx, 72(%esp)
	movl	-388(%ebp), %eax
	movl	%eax, 68(%esp)
	movl	$-1, 64(%esp)
	movl	-384(%ebp), %eax
	movl	%eax, 60(%esp)
	movl	%ecx, 56(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 52(%esp)
	fstps	48(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 44(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 40(%esp)
	fstps	36(%esp)
	movl	$0x43fa0000, %eax
	movl	%eax, 32(%esp)
	movl	%edx, 28(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 24(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 20(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 16(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 12(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 8(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 4(%esp)
	movl	-380(%ebp), %eax
	movl	%eax, (%esp)
	call	convertsplit
	movl	%eax, -380(%ebp)
	movl	-380(%ebp), %eax
	movl	%eax, -348(%ebp)
	.loc 1 2508 0
	movl	-312(%ebp), %eax
	addl	$768, %eax
	movl	%eax, -452(%ebp)
	movl	-312(%ebp), %eax
	addl	$768, %eax
	movl	%eax, -448(%ebp)
	movl	-312(%ebp), %eax
	movl	1048(%eax), %esi
	movl	-312(%ebp), %eax
	movl	1040(%eax), %ebx
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	-304(%ebp)
	fucompp
	fnstsw	%ax
	testb	$5, %ah
	sete	%al
	testb	%al, %al
	je	.L471
	flds	-304(%ebp)
	flds	.LC87
	faddp	%st, %st(1)
	jmp	.L472
.L471:
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	.LC87
	faddp	%st, %st(1)
.L472:
	movl	-312(%ebp), %eax
	movl	1032(%eax), %ecx
	movl	-312(%ebp), %eax
	leal	512(%eax), %edi
	movl	-312(%ebp), %eax
	flds	1048(%eax)
	flds	.LC18
	fmulp	%st, %st(1)
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	-304(%ebp)
	fucompp
	fnstsw	%ax
	testb	$5, %ah
	sete	%al
	testb	%al, %al
	je	.L473
	flds	-304(%ebp)
	flds	.LC87
	faddp	%st, %st(1)
	jmp	.L474
.L473:
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	.LC87
	faddp	%st, %st(1)
.L474:
	movl	-320(%ebp), %eax
	movl	-384(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2596, %eax
	flds	(%eax)
	faddp	%st, %st(1)
	movl	-324(%ebp), %eax
	movl	-384(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2596, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	fldz
	fucompp
	fnstsw	%ax
	testb	$5, %ah
	sete	%al
	testb	%al, %al
	je	.L475
	fldz
	fxch	%st(2)
	jmp	.L476
.L475:
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	-304(%ebp)
	fucompp
	fnstsw	%ax
	testb	$5, %ah
	sete	%al
	testb	%al, %al
	je	.L477
	flds	-304(%ebp)
	flds	.LC87
	faddp	%st, %st(1)
	jmp	.L478
.L477:
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	.LC87
	faddp	%st, %st(1)
.L478:
	movl	-320(%ebp), %eax
	movl	-384(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2596, %eax
	flds	(%eax)
	faddp	%st, %st(1)
	movl	-324(%ebp), %eax
	movl	-384(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2596, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	fxch	%st(2)
.L476:
	movl	$1, 80(%esp)
	movl	$.LC88, 76(%esp)
	movl	-452(%ebp), %edx
	movl	%edx, 72(%esp)
	movl	-388(%ebp), %eax
	movl	%eax, 68(%esp)
	movl	$-1, 64(%esp)
	movl	-384(%ebp), %eax
	movl	%eax, 60(%esp)
	movl	-448(%ebp), %eax
	movl	%eax, 56(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 52(%esp)
	movl	%esi, 48(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 44(%esp)
	movl	%ebx, 40(%esp)
	fstps	36(%esp)
	movl	%ecx, 32(%esp)
	movl	%edi, 28(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 24(%esp)
	fstps	20(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 16(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 12(%esp)
	fstps	8(%esp)
	movl	$0x43fa0000, %eax
	movl	%eax, 4(%esp)
	movl	-380(%ebp), %eax
	movl	%eax, (%esp)
	call	convertsplit
	movl	%eax, -380(%ebp)
	movl	-380(%ebp), %eax
	movl	%eax, -352(%ebp)
	.loc 1 2512 0
	movl	-312(%ebp), %eax
	leal	768(%eax), %ecx
	movl	-312(%ebp), %eax
	addl	$768, %eax
	movl	%eax, -444(%ebp)
	movl	-312(%ebp), %eax
	movl	1048(%eax), %edi
	movl	-312(%ebp), %eax
	movl	1040(%eax), %edx
	movl	%edx, -440(%ebp)
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	-304(%ebp)
	fucompp
	fnstsw	%ax
	testb	$5, %ah
	sete	%al
	testb	%al, %al
	je	.L479
	flds	-304(%ebp)
	flds	.LC87
	faddp	%st, %st(1)
	jmp	.L480
.L479:
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	.LC87
	faddp	%st, %st(1)
.L480:
	movl	-312(%ebp), %eax
	movl	1032(%eax), %edx
	movl	%edx, -436(%ebp)
	movl	-312(%ebp), %eax
	addl	$768, %eax
	movl	%eax, -432(%ebp)
	movl	-312(%ebp), %eax
	movl	1048(%eax), %esi
	movl	-312(%ebp), %eax
	movl	1040(%eax), %ebx
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	-304(%ebp)
	fucompp
	fnstsw	%ax
	testb	$5, %ah
	sete	%al
	testb	%al, %al
	je	.L481
	flds	-304(%ebp)
	flds	.LC87
	faddp	%st, %st(1)
	fxch	%st(1)
	jmp	.L482
.L481:
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	.LC87
	faddp	%st, %st(1)
	fxch	%st(1)
.L482:
	movl	-312(%ebp), %eax
	movl	1032(%eax), %edx
	movl	$1, 80(%esp)
	movl	$.LC88, 76(%esp)
	movl	%ecx, 72(%esp)
	movl	-388(%ebp), %eax
	movl	%eax, 68(%esp)
	movl	$3, 64(%esp)
	movl	-384(%ebp), %eax
	movl	%eax, 60(%esp)
	movl	-444(%ebp), %eax
	movl	%eax, 56(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 52(%esp)
	movl	%edi, 48(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 44(%esp)
	movl	-440(%ebp), %eax
	movl	%eax, 40(%esp)
	fstps	36(%esp)
	movl	-436(%ebp), %eax
	movl	%eax, 32(%esp)
	movl	-432(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 24(%esp)
	movl	%esi, 20(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 16(%esp)
	movl	%ebx, 12(%esp)
	fstps	8(%esp)
	movl	%edx, 4(%esp)
	movl	-380(%ebp), %eax
	movl	%eax, (%esp)
	call	convertsplit
	movl	%eax, -380(%ebp)
	movl	-380(%ebp), %eax
	movl	%eax, -356(%ebp)
	.loc 1 2513 0
	movl	-388(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC90, 4(%esp)
	movl	-380(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -380(%ebp)
	.loc 1 2517 0
	movl	-312(%ebp), %eax
	leal	768(%eax), %ecx
	movl	-312(%ebp), %eax
	addl	$768, %eax
	movl	%eax, -428(%ebp)
	movl	-312(%ebp), %eax
	movl	1048(%eax), %edi
	movl	-312(%ebp), %eax
	movl	1040(%eax), %edx
	movl	%edx, -424(%ebp)
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	-304(%ebp)
	fucompp
	fnstsw	%ax
	testb	$5, %ah
	sete	%al
	testb	%al, %al
	je	.L483
	flds	-304(%ebp)
	flds	.LC87
	faddp	%st, %st(1)
	jmp	.L484
.L483:
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	.LC87
	faddp	%st, %st(1)
.L484:
	movl	-312(%ebp), %eax
	movl	1032(%eax), %edx
	movl	%edx, -420(%ebp)
	movl	-312(%ebp), %eax
	addl	$768, %eax
	movl	%eax, -416(%ebp)
	movl	-312(%ebp), %eax
	movl	1048(%eax), %esi
	movl	-312(%ebp), %eax
	movl	1040(%eax), %ebx
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	-304(%ebp)
	fucompp
	fnstsw	%ax
	testb	$5, %ah
	sete	%al
	testb	%al, %al
	je	.L485
	flds	-304(%ebp)
	flds	.LC87
	faddp	%st, %st(1)
	fxch	%st(1)
	jmp	.L486
.L485:
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	.LC87
	faddp	%st, %st(1)
	fxch	%st(1)
.L486:
	movl	-312(%ebp), %eax
	movl	1032(%eax), %edx
	movl	$1, 80(%esp)
	movl	$.LC88, 76(%esp)
	movl	%ecx, 72(%esp)
	movl	-388(%ebp), %eax
	movl	%eax, 68(%esp)
	movl	$3, 64(%esp)
	movl	-384(%ebp), %eax
	movl	%eax, 60(%esp)
	movl	-428(%ebp), %eax
	movl	%eax, 56(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 52(%esp)
	movl	%edi, 48(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 44(%esp)
	movl	-424(%ebp), %eax
	movl	%eax, 40(%esp)
	fstps	36(%esp)
	movl	-420(%ebp), %eax
	movl	%eax, 32(%esp)
	movl	-416(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 24(%esp)
	movl	%esi, 20(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 16(%esp)
	movl	%ebx, 12(%esp)
	fstps	8(%esp)
	movl	%edx, 4(%esp)
	movl	-380(%ebp), %eax
	movl	%eax, (%esp)
	call	convertsplit
	movl	%eax, -380(%ebp)
	movl	-380(%ebp), %eax
	movl	%eax, -360(%ebp)
	.loc 1 2521 0
	movl	-312(%ebp), %eax
	leal	768(%eax), %ecx
	movl	-312(%ebp), %eax
	addl	$768, %eax
	movl	%eax, -412(%ebp)
	movl	-312(%ebp), %eax
	movl	1048(%eax), %edi
	movl	-312(%ebp), %eax
	movl	1040(%eax), %edx
	movl	%edx, -408(%ebp)
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	-304(%ebp)
	fucompp
	fnstsw	%ax
	testb	$5, %ah
	sete	%al
	testb	%al, %al
	je	.L487
	flds	-304(%ebp)
	flds	.LC91
	faddp	%st, %st(1)
	jmp	.L488
.L487:
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	.LC91
	faddp	%st, %st(1)
.L488:
	movl	-312(%ebp), %eax
	movl	1032(%eax), %edx
	movl	%edx, -404(%ebp)
	movl	-312(%ebp), %eax
	addl	$768, %eax
	movl	%eax, -400(%ebp)
	movl	-312(%ebp), %eax
	movl	1048(%eax), %esi
	movl	-312(%ebp), %eax
	movl	1040(%eax), %ebx
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	-304(%ebp)
	fucompp
	fnstsw	%ax
	testb	$5, %ah
	sete	%al
	testb	%al, %al
	je	.L489
	flds	-304(%ebp)
	flds	.LC87
	faddp	%st, %st(1)
	fxch	%st(1)
	jmp	.L490
.L489:
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	.LC87
	faddp	%st, %st(1)
	fxch	%st(1)
.L490:
	movl	-312(%ebp), %eax
	movl	1032(%eax), %edx
	movl	$1, 80(%esp)
	movl	$.LC88, 76(%esp)
	movl	%ecx, 72(%esp)
	movl	-388(%ebp), %eax
	movl	%eax, 68(%esp)
	movl	$-1, 64(%esp)
	movl	-384(%ebp), %eax
	movl	%eax, 60(%esp)
	movl	-412(%ebp), %eax
	movl	%eax, 56(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 52(%esp)
	movl	%edi, 48(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 44(%esp)
	movl	-408(%ebp), %eax
	movl	%eax, 40(%esp)
	fstps	36(%esp)
	movl	-404(%ebp), %eax
	movl	%eax, 32(%esp)
	movl	-400(%ebp), %eax
	movl	%eax, 28(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 24(%esp)
	movl	%esi, 20(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 16(%esp)
	movl	%ebx, 12(%esp)
	fstps	8(%esp)
	movl	%edx, 4(%esp)
	movl	-380(%ebp), %eax
	movl	%eax, (%esp)
	call	convertsplit
	movl	%eax, -380(%ebp)
	movl	-380(%ebp), %eax
	movl	%eax, -364(%ebp)
	.loc 1 2525 0
	movl	-312(%ebp), %eax
	leal	768(%eax), %ebx
	movl	-312(%ebp), %eax
	leal	512(%eax), %edi
	movl	-312(%ebp), %eax
	flds	1048(%eax)
	flds	.LC18
	fmulp	%st, %st(1)
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	-304(%ebp)
	fucompp
	fnstsw	%ax
	testb	$5, %ah
	sete	%al
	testb	%al, %al
	je	.L491
	flds	-304(%ebp)
	flds	.LC91
	faddp	%st, %st(1)
	jmp	.L492
.L491:
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	.LC91
	faddp	%st, %st(1)
.L492:
	movl	-320(%ebp), %eax
	movl	-384(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2596, %eax
	flds	(%eax)
	faddp	%st, %st(1)
	movl	-324(%ebp), %eax
	movl	-384(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2596, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	fldz
	fucompp
	fnstsw	%ax
	testb	$5, %ah
	sete	%al
	testb	%al, %al
	je	.L493
	fldz
	jmp	.L494
.L493:
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	-304(%ebp)
	fucompp
	fnstsw	%ax
	testb	$5, %ah
	sete	%al
	testb	%al, %al
	je	.L495
	flds	-304(%ebp)
	flds	.LC91
	faddp	%st, %st(1)
	jmp	.L496
.L495:
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	.LC91
	faddp	%st, %st(1)
.L496:
	movl	-320(%ebp), %eax
	movl	-384(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2596, %eax
	flds	(%eax)
	faddp	%st, %st(1)
	movl	-324(%ebp), %eax
	movl	-384(%ebp), %edx
	imull	$280, %eax, %eax
	leal	(%edx,%eax), %eax
	addl	$2596, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
.L494:
	movl	-312(%ebp), %eax
	leal	768(%eax), %esi
	movl	-312(%ebp), %eax
	movl	1048(%eax), %ecx
	movl	-312(%ebp), %eax
	movl	1040(%eax), %edx
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	-304(%ebp)
	fucompp
	fnstsw	%ax
	testb	$5, %ah
	sete	%al
	testb	%al, %al
	je	.L497
	flds	-304(%ebp)
	flds	.LC91
	faddp	%st, %st(1)
	fxch	%st(2)
	jmp	.L498
.L497:
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	.LC91
	faddp	%st, %st(1)
	fxch	%st(2)
.L498:
	movl	-312(%ebp), %eax
	movl	1032(%eax), %eax
	movl	$1, 80(%esp)
	movl	$.LC88, 76(%esp)
	movl	%ebx, 72(%esp)
	movl	-388(%ebp), %ebx
	movl	%ebx, 68(%esp)
	movl	$-1, 64(%esp)
	movl	-384(%ebp), %ebx
	movl	%ebx, 60(%esp)
	movl	%edi, 56(%esp)
	movl	$0x00000000, %ebx
	movl	%ebx, 52(%esp)
	fstps	48(%esp)
	movl	$0x00000000, %ebx
	movl	%ebx, 44(%esp)
	movl	$0x00000000, %ebx
	movl	%ebx, 40(%esp)
	fstps	36(%esp)
	movl	$0x44098000, %ebx
	movl	%ebx, 32(%esp)
	movl	%esi, 28(%esp)
	movl	$0x00000000, %ebx
	movl	%ebx, 24(%esp)
	movl	%ecx, 20(%esp)
	movl	$0x00000000, %ecx
	movl	%ecx, 16(%esp)
	movl	%edx, 12(%esp)
	fstps	8(%esp)
	movl	%eax, 4(%esp)
	movl	-380(%ebp), %eax
	movl	%eax, (%esp)
	call	convertsplit
	movl	%eax, -380(%ebp)
	movl	-380(%ebp), %eax
	movl	%eax, -368(%ebp)
	.loc 1 2529 0
	movl	-312(%ebp), %eax
	leal	512(%eax), %ebx
	movl	-312(%ebp), %eax
	leal	512(%eax), %ecx
	movl	-312(%ebp), %eax
	leal	512(%eax), %edx
	movl	-312(%ebp), %eax
	flds	1048(%eax)
	flds	.LC18
	fmulp	%st, %st(1)
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	-304(%ebp)
	fucompp
	fnstsw	%ax
	testb	$5, %ah
	sete	%al
	testb	%al, %al
	je	.L499
	flds	-304(%ebp)
	flds	.LC91
	faddp	%st, %st(1)
	jmp	.L500
.L499:
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	.LC91
	faddp	%st, %st(1)
.L500:
	movl	-320(%ebp), %eax
	movl	-384(%ebp), %esi
	imull	$280, %eax, %eax
	leal	(%esi,%eax), %eax
	addl	$2596, %eax
	flds	(%eax)
	faddp	%st, %st(1)
	movl	-324(%ebp), %eax
	movl	-384(%ebp), %esi
	imull	$280, %eax, %eax
	leal	(%esi,%eax), %eax
	addl	$2596, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	fldz
	fucompp
	fnstsw	%ax
	testb	$5, %ah
	sete	%al
	testb	%al, %al
	je	.L501
	fldz
	fxch	%st(1)
	jmp	.L502
.L501:
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	-304(%ebp)
	fucompp
	fnstsw	%ax
	testb	$5, %ah
	sete	%al
	testb	%al, %al
	je	.L503
	flds	-304(%ebp)
	flds	.LC91
	faddp	%st, %st(1)
	jmp	.L504
.L503:
	movl	-312(%ebp), %eax
	flds	1036(%eax)
	flds	.LC91
	faddp	%st, %st(1)
.L504:
	movl	-320(%ebp), %eax
	movl	-384(%ebp), %esi
	imull	$280, %eax, %eax
	leal	(%esi,%eax), %eax
	addl	$2596, %eax
	flds	(%eax)
	faddp	%st, %st(1)
	movl	-324(%ebp), %eax
	movl	-384(%ebp), %esi
	imull	$280, %eax, %eax
	leal	(%esi,%eax), %eax
	addl	$2596, %eax
	flds	(%eax)
	fsubrp	%st, %st(1)
	fxch	%st(1)
.L502:
	movl	$0, 80(%esp)
	movl	$.LC88, 76(%esp)
	movl	%ebx, 72(%esp)
	movl	-388(%ebp), %eax
	movl	%eax, 68(%esp)
	movl	$-1, 64(%esp)
	movl	-384(%ebp), %eax
	movl	%eax, 60(%esp)
	movl	%ecx, 56(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 52(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 48(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 44(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 40(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 36(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 32(%esp)
	movl	%edx, 28(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 24(%esp)
	fstps	20(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 16(%esp)
	movl	$0x00000000, %eax
	movl	%eax, 12(%esp)
	fstps	8(%esp)
	movl	$0x44098000, %eax
	movl	%eax, 4(%esp)
	movl	-380(%ebp), %eax
	movl	%eax, (%esp)
	call	convertsplit
	movl	%eax, -380(%ebp)
	movl	-380(%ebp), %eax
	movl	%eax, -344(%ebp)
	.loc 1 2530 0
	movl	-388(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC86, 4(%esp)
	movl	-380(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -380(%ebp)
	movl	-380(%ebp), %eax
	movl	%eax, -344(%ebp)
	.loc 1 2531 0
	movl	-388(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC86, 4(%esp)
	movl	-380(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -380(%ebp)
	.loc 1 2532 0
	movl	-388(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC86, 4(%esp)
	movl	-380(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -380(%ebp)
	.loc 1 2533 0
	movl	-388(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC86, 4(%esp)
	movl	-380(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -380(%ebp)
	.loc 1 2534 0
	movl	-388(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC72, 4(%esp)
	movl	-380(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -380(%ebp)
	.loc 1 2537 0
	movl	-340(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-384(%ebp), %eax
	movl	%eax, (%esp)
	call	blendCorner3
	.loc 1 2538 0
	movl	-348(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-384(%ebp), %eax
	movl	%eax, (%esp)
	call	blendCorner3
	.loc 1 2539 0
	movl	-352(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-384(%ebp), %eax
	movl	%eax, (%esp)
	call	blendCorner3
	.loc 1 2540 0
	movl	-360(%ebp), %eax
	movl	8(%eax), %eax
	movl	%eax, 4(%esp)
	movl	-384(%ebp), %eax
	movl	%eax, (%esp)
	call	blendCorner3
	.loc 1 2541 0
	movl	-364(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-384(%ebp), %eax
	movl	%eax, (%esp)
	call	blendCorner3
	.loc 1 2542 0
	movl	-368(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-384(%ebp), %eax
	movl	%eax, (%esp)
	call	blendCorner3
	.loc 1 2543 0
	movl	-344(%ebp), %eax
	movl	12(%eax), %eax
	movl	%eax, 4(%esp)
	movl	-384(%ebp), %eax
	movl	%eax, (%esp)
	call	blendCorner3
	.loc 1 2546 0
	movl	-340(%ebp), %eax
	movl	4(%eax), %eax
	movl	-340(%ebp), %edx
	movl	4(%edx), %edx
	flds	28(%edx)
	movl	-340(%ebp), %edx
	movl	8(%edx), %edx
	movl	4(%edx), %edx
	flds	28(%edx)
	movl	-340(%ebp), %edx
	movl	4(%edx), %edx
	flds	28(%edx)
	fsubrp	%st, %st(1)
	fldl	.LC93
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	28(%eax)
	.loc 1 2548 0
	movl	-348(%ebp), %eax
	movl	8(%eax), %eax
	movl	4(%eax), %eax
	flds	28(%eax)
	movl	-348(%ebp), %eax
	movl	4(%eax), %eax
	flds	28(%eax)
	fsubrp	%st, %st(1)
	fstps	-308(%ebp)
	.loc 1 2549 0
	movl	-348(%ebp), %eax
	movl	12(%eax), %eax
	movl	4(%eax), %eax
	movl	-348(%ebp), %edx
	movl	12(%edx), %edx
	movl	4(%edx), %edx
	flds	28(%edx)
	flds	-308(%ebp)
	fldl	.LC94
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	28(%eax)
	.loc 1 2550 0
	movl	-348(%ebp), %eax
	movl	4(%eax), %eax
	movl	-348(%ebp), %edx
	movl	4(%edx), %edx
	flds	28(%edx)
	flds	-308(%ebp)
	fldl	.LC95
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	28(%eax)
	.loc 1 2551 0
	movl	-348(%ebp), %eax
	movl	8(%eax), %eax
	movl	4(%eax), %eax
	movl	-348(%ebp), %edx
	movl	8(%edx), %edx
	movl	4(%edx), %edx
	flds	28(%edx)
	flds	-308(%ebp)
	fldl	.LC94
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	28(%eax)
	.loc 1 2553 0
	movl	-352(%ebp), %eax
	movl	12(%eax), %eax
	movl	4(%eax), %eax
	flds	28(%eax)
	movl	-352(%ebp), %eax
	movl	4(%eax), %eax
	flds	28(%eax)
	fsubrp	%st, %st(1)
	fstps	-308(%ebp)
	.loc 1 2554 0
	movl	-352(%ebp), %eax
	movl	12(%eax), %eax
	movl	4(%eax), %eax
	movl	-352(%ebp), %edx
	movl	12(%edx), %edx
	movl	4(%edx), %edx
	flds	28(%edx)
	flds	-308(%ebp)
	fldl	.LC94
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	28(%eax)
	.loc 1 2555 0
	movl	-352(%ebp), %eax
	movl	4(%eax), %eax
	movl	-352(%ebp), %edx
	movl	4(%edx), %edx
	flds	28(%edx)
	flds	-308(%ebp)
	fldl	.LC96
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	28(%eax)
	.loc 1 2556 0
	movl	-352(%ebp), %eax
	movl	8(%eax), %eax
	movl	4(%eax), %eax
	movl	-352(%ebp), %edx
	movl	8(%edx), %edx
	movl	4(%edx), %edx
	flds	28(%edx)
	flds	-308(%ebp)
	fldl	.LC94
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	28(%eax)
	.loc 1 2558 0
	movl	-364(%ebp), %eax
	movl	8(%eax), %eax
	movl	4(%eax), %eax
	flds	28(%eax)
	movl	-364(%ebp), %eax
	movl	4(%eax), %eax
	flds	28(%eax)
	fsubrp	%st, %st(1)
	fstps	-308(%ebp)
	.loc 1 2559 0
	movl	-364(%ebp), %eax
	movl	12(%eax), %eax
	movl	4(%eax), %eax
	movl	-364(%ebp), %edx
	movl	12(%edx), %edx
	movl	4(%edx), %edx
	flds	28(%edx)
	flds	-308(%ebp)
	fldl	.LC94
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	28(%eax)
	.loc 1 2560 0
	movl	-364(%ebp), %eax
	movl	4(%eax), %eax
	movl	-364(%ebp), %edx
	movl	4(%edx), %edx
	flds	28(%edx)
	flds	-308(%ebp)
	fldl	.LC96
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	28(%eax)
	.loc 1 2561 0
	movl	-364(%ebp), %eax
	movl	8(%eax), %eax
	movl	4(%eax), %eax
	movl	-364(%ebp), %edx
	movl	8(%edx), %edx
	movl	4(%edx), %edx
	flds	28(%edx)
	flds	-308(%ebp)
	fldl	.LC94
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	28(%eax)
	.loc 1 2563 0
	movl	-368(%ebp), %eax
	movl	12(%eax), %eax
	movl	4(%eax), %eax
	flds	28(%eax)
	movl	-368(%ebp), %eax
	movl	4(%eax), %eax
	flds	28(%eax)
	fsubrp	%st, %st(1)
	fstps	-308(%ebp)
	.loc 1 2564 0
	movl	-368(%ebp), %eax
	movl	12(%eax), %eax
	movl	4(%eax), %eax
	movl	-368(%ebp), %edx
	movl	12(%edx), %edx
	movl	4(%edx), %edx
	flds	28(%edx)
	flds	-308(%ebp)
	fldl	.LC94
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	28(%eax)
	.loc 1 2565 0
	movl	-368(%ebp), %eax
	movl	4(%eax), %eax
	movl	-368(%ebp), %edx
	movl	4(%edx), %edx
	flds	28(%edx)
	flds	-308(%ebp)
	fldl	.LC95
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	28(%eax)
	.loc 1 2566 0
	movl	-368(%ebp), %eax
	movl	8(%eax), %eax
	movl	4(%eax), %eax
	movl	-368(%ebp), %edx
	movl	8(%edx), %edx
	movl	4(%edx), %edx
	flds	28(%edx)
	flds	-308(%ebp)
	fldl	.LC94
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	28(%eax)
	.loc 1 2568 0
	movl	-344(%ebp), %eax
	movl	4(%eax), %eax
	movl	-344(%ebp), %edx
	movl	4(%edx), %edx
	flds	28(%edx)
	movl	-344(%ebp), %edx
	movl	12(%edx), %edx
	movl	4(%edx), %edx
	flds	28(%edx)
	movl	-344(%ebp), %edx
	movl	4(%edx), %edx
	flds	28(%edx)
	fsubrp	%st, %st(1)
	fldl	.LC93
	fmulp	%st, %st(1)
	faddp	%st, %st(1)
	fstps	-396(%ebp)
	flds	-396(%ebp)
	fstps	28(%eax)
	.loc 1 2570 0
	movl	-344(%ebp), %eax
	movl	12(%eax), %eax
	movl	4(%eax), %eax
	movl	-344(%ebp), %edx
	movl	12(%edx), %edx
	movl	4(%edx), %edx
	flds	16(%edx)
	flds	.LC14
	faddp	%st, %st(1)
	fstps	16(%eax)
	.loc 1 2571 0
	movl	-344(%ebp), %eax
	movl	4(%eax), %eax
	movl	-344(%ebp), %edx
	movl	4(%edx), %edx
	flds	16(%edx)
	flds	.LC20
	faddp	%st, %st(1)
	fstps	16(%eax)
	.loc 1 2572 0
	movl	-344(%ebp), %eax
	movl	8(%eax), %eax
	movl	4(%eax), %eax
	movl	-344(%ebp), %edx
	movl	8(%edx), %edx
	movl	4(%edx), %edx
	flds	16(%edx)
	flds	.LC14
	faddp	%st, %st(1)
	fstps	16(%eax)
	.loc 1 2483 0
	addl	$1, -288(%ebp)
.L462:
	movl	-288(%ebp), %eax
	cmpl	-300(%ebp), %eax
	setl	%al
	testb	%al, %al
	jne	.L505
	.loc 1 2574 0
	movl	-388(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$.LC72, 4(%esp)
	movl	-380(%ebp), %eax
	movl	%eax, (%esp)
	call	addCommandString
	movl	%eax, -380(%ebp)
	.loc 1 2575 0
	movl	-380(%ebp), %eax
.LBE57:
	.loc 1 2576 0
	movl	-28(%ebp), %edx
	xorl	%gs:20, %edx
	je	.L507
	call	__stack_chk_fail
.L507:
	addl	$540, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.cfi_endproc
.LFE46:
	.size	generateProgramNS, .-generateProgramNS
	.section	.rodata
	.align 8
	.type	_ZZ7uniformddE4rmax, @object
	.size	_ZZ7uniformddE4rmax, 8
_ZZ7uniformddE4rmax:
	.long	0
	.long	1105199104
	.align 8
.LC2:
	.long	1649267442
	.long	1079582736
	.align 8
.LC5:
	.long	-1431655765
	.long	1075489450
	.align 8
.LC6:
	.long	1413754152
	.long	1075388923
	.align 8
.LC7:
	.long	-858993459
	.long	1076186316
	.align 8
.LC8:
	.long	0
	.long	1073217536
	.align 4
.LC9:
	.long	-1069547520
	.align 8
.LC10:
	.long	1431655765
	.long	-1076538027
	.align 8
.LC11:
	.long	0
	.long	-1074266112
	.align 8
.LC12:
	.long	-1431655765
	.long	-1071994198
	.align 8
.LC13:
	.long	1413754152
	.long	1074340347
	.align 4
.LC14:
	.long	1092616192
	.align 4
.LC15:
	.long	1077936128
	.align 4
.LC16:
	.long	-1073741824
	.align 8
.LC17:
	.long	0
	.long	1071644672
	.align 4
.LC18:
	.long	1056964608
	.align 4
.LC19:
	.long	-1046478848
	.align 4
.LC20:
	.long	1101004800
	.align 4
.LC21:
	.long	-1052770304
	.align 4
.LC22:
	.long	-1056964608
	.align 8
.LC23:
	.long	0
	.long	1074266112
	.align 4
.LC24:
	.long	1106247680
	.align 4
.LC25:
	.long	-1041235968
	.align 4
.LC26:
	.long	1098907648
	.align 4
.LC27:
	.long	1096810496
	.align 8
.LC28:
	.long	0
	.long	1074790400
	.align 4
.LC29:
	.long	1094713344
	.align 4
.LC30:
	.long	1086324736
	.align 8
.LC31:
	.long	0
	.long	1075052544
	.align 8
.LC32:
	.long	0
	.long	1073741824
	.align 4
.LC33:
	.long	-1063256064
	.align 4
.LC34:
	.long	-1054867456
	.align 4
.LC35:
	.long	1148846080
	.align 8
.LC36:
	.long	-755914244
	.long	1061184077
	.align 4
.LC37:
	.long	1157234688
	.align 4
.LC38:
	.long	981668463
	.align 4
.LC39:
	.long	1078530011
	.align 4
.LC40:
	.long	1127481344
	.align 8
.LC41:
	.long	-536870912
	.long	1062232653
	.align 8
.LC42:
	.long	1610612736
	.long	1074340347
	.align 8
.LC43:
	.long	0
	.long	1080459264
	.align 8
.LC44:
	.long	0
	.long	1085227008
	.align 8
.LC47:
	.long	0
	.long	1083129856
	.align 8
.LC48:
	.long	-755914244
	.long	1063281229
	.align 8
.LC49:
	.long	2043167482
	.long	1074790399
	.align 8
.LC51:
	.long	-350469331
	.long	1059731170
	.align 8
.LC52:
	.long	-755914244
	.long	1062232653
	.align 8
.LC53:
	.long	-225179981
	.long	1074790399
	.align 8
.LC54:
	.long	0
	.long	1105199104
	.align 8
.LC55:
	.long	-4194304
	.long	1105199103
	.align 8
.LC59:
	.long	1202590843
	.long	1064598241
	.align 8
.LC60:
	.long	1202590843
	.long	1065646817
	.align 8
.LC61:
	.long	-1030792151
	.long	1072703733
	.align 8
.LC62:
	.long	2061584302
	.long	1072672276
	.align 8
.LC67:
	.long	0
	.long	-1075838976
	.align 4
.LC79:
	.long	1135869952
	.align 8
.LC82:
	.long	-1717986918
	.long	1071225241
	.align 4
.LC83:
	.long	1137180672
	.align 4
.LC87:
	.long	1128792064
	.align 4
.LC91:
	.long	1133903872
	.align 8
.LC93:
	.long	1374389535
	.long	1070931640
	.align 8
.LC94:
	.long	858993459
	.long	1069757235
	.align 8
.LC95:
	.long	2061584302
	.long	1071099412
	.align 8
.LC96:
	.long	-1546188227
	.long	1071791472
	.text
.Letext0:
	.section	.debug_loc,"",@progbits
.Ldebug_loc0:
.LLST0:
	.long	.LFB9
	.long	.LCFI0
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI0
	.long	.LCFI1
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI1
	.long	.LFE9
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST1:
	.long	.LFB10
	.long	.LCFI2
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI2
	.long	.LCFI3
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI3
	.long	.LFE10
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST2:
	.long	.LFB11
	.long	.LCFI4
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI4
	.long	.LCFI5
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI5
	.long	.LFE11
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST3:
	.long	.LFB12
	.long	.LCFI6
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI6
	.long	.LCFI7
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI7
	.long	.LFE12
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST4:
	.long	.LFB13
	.long	.LCFI8
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI8
	.long	.LCFI9
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI9
	.long	.LFE13
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST5:
	.long	.LFB14
	.long	.LCFI10
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI10
	.long	.LCFI11
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI11
	.long	.LFE14
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST6:
	.long	.LFB15
	.long	.LCFI12
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI12
	.long	.LCFI13
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI13
	.long	.LFE15
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST7:
	.long	.LFB16
	.long	.LCFI14
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI14
	.long	.LCFI15
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI15
	.long	.LFE16
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST8:
	.long	.LFB17
	.long	.LCFI16
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI16
	.long	.LCFI17
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI17
	.long	.LFE17
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST9:
	.long	.LFB18
	.long	.LCFI18
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI18
	.long	.LCFI19
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI19
	.long	.LFE18
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST10:
	.long	.LFB19
	.long	.LCFI20
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI20
	.long	.LCFI21
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI21
	.long	.LFE19
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST11:
	.long	.LFB20
	.long	.LCFI22
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI22
	.long	.LCFI23
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI23
	.long	.LFE20
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST12:
	.long	.LFB21
	.long	.LCFI24
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI24
	.long	.LCFI25
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI25
	.long	.LFE21
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST13:
	.long	.LFB22
	.long	.LCFI26
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI26
	.long	.LCFI27
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI27
	.long	.LFE22
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST14:
	.long	.LFB23
	.long	.LCFI28
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI28
	.long	.LCFI29
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI29
	.long	.LFE23
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST15:
	.long	.LFB24
	.long	.LCFI30
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI30
	.long	.LCFI31
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI31
	.long	.LFE24
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST16:
	.long	.LFB25
	.long	.LCFI32
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI32
	.long	.LCFI33
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI33
	.long	.LFE25
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST17:
	.long	.LFB26
	.long	.LCFI34
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI34
	.long	.LCFI35
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI35
	.long	.LFE26
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST18:
	.long	.LFB27
	.long	.LCFI36
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI36
	.long	.LCFI37
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI37
	.long	.LFE27
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST19:
	.long	.LFB28
	.long	.LCFI38
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI38
	.long	.LCFI39
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI39
	.long	.LFE28
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST20:
	.long	.LFB29
	.long	.LCFI40
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI40
	.long	.LCFI41
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI41
	.long	.LFE29
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST21:
	.long	.LFB30
	.long	.LCFI42
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI42
	.long	.LCFI43
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI43
	.long	.LFE30
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST22:
	.long	.LFB31
	.long	.LCFI44
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI44
	.long	.LCFI45
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI45
	.long	.LFE31
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST23:
	.long	.LFB32
	.long	.LCFI46
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI46
	.long	.LCFI47
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI47
	.long	.LFE32
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST24:
	.long	.LFB33
	.long	.LCFI48
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI48
	.long	.LCFI49
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI49
	.long	.LFE33
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST25:
	.long	.LFB34
	.long	.LCFI50
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI50
	.long	.LCFI51
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI51
	.long	.LFE34
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST26:
	.long	.LFB35
	.long	.LCFI52
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI52
	.long	.LCFI53
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI53
	.long	.LFE35
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST27:
	.long	.LFB36
	.long	.LCFI54
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI54
	.long	.LCFI55
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI55
	.long	.LFE36
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST28:
	.long	.LFB37
	.long	.LCFI56
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI56
	.long	.LCFI57
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI57
	.long	.LFE37
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST29:
	.long	.LFB38
	.long	.LCFI58
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI58
	.long	.LCFI59
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI59
	.long	.LFE38
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST30:
	.long	.LFB39
	.long	.LCFI60
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI60
	.long	.LCFI61
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI61
	.long	.LFE39
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST31:
	.long	.LFB40
	.long	.LCFI62
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI62
	.long	.LCFI63
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI63
	.long	.LFE40
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST32:
	.long	.LFB41
	.long	.LCFI64
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI64
	.long	.LCFI65
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI65
	.long	.LFE41
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST33:
	.long	.LFB42
	.long	.LCFI66
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI66
	.long	.LCFI67
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI67
	.long	.LFE42
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST34:
	.long	.LFB43
	.long	.LCFI68
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI68
	.long	.LCFI69
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI69
	.long	.LFE43
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST35:
	.long	.LFB44
	.long	.LCFI70
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI70
	.long	.LCFI71
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI71
	.long	.LFE44
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST36:
	.long	.LFB45
	.long	.LCFI72
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI72
	.long	.LCFI73
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI73
	.long	.LFE45
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
.LLST37:
	.long	.LFB46
	.long	.LCFI74
	.value	0x2
	.byte	0x74
	.sleb128 4
	.long	.LCFI74
	.long	.LCFI75
	.value	0x2
	.byte	0x74
	.sleb128 8
	.long	.LCFI75
	.long	.LFE46
	.value	0x2
	.byte	0x75
	.sleb128 8
	.long	0x0
	.long	0x0
	.file 2 "/usr/lib/gcc/i486-linux-gnu/4.4.1/include/stddef.h"
	.file 3 "/usr/include/bits/types.h"
	.file 4 "/usr/include/bits/time.h"
	.file 5 "/usr/include/bits/pthreadtypes.h"
	.file 6 "/usr/include/libio.h"
	.file 7 "tmpnrobot.h"
	.file 8 "genscript.h"
	.file 9 "bopt.h"
	.file 10 "/usr/include/stdio.h"
	.file 11 "cmd.h"
	.section	.debug_info
	.long	0x6670
	.value	0x2
	.long	.Ldebug_abbrev0
	.byte	0x4
	.uleb128 0x1
	.long	.LASF759
	.byte	0x4
	.long	.LASF760
	.long	.LASF761
	.long	0x0
	.long	0x0
	.long	.Ldebug_ranges0+0x48
	.long	.Ldebug_line0
	.uleb128 0x2
	.long	.LASF10
	.byte	0x2
	.byte	0xd3
	.long	0x34
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.long	.LASF0
	.uleb128 0x4
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.long	.LASF1
	.uleb128 0x3
	.byte	0x8
	.byte	0x5
	.long	.LASF2
	.uleb128 0x5
	.byte	0x4
	.byte	0x7
	.uleb128 0x3
	.byte	0x2
	.byte	0x7
	.long	.LASF3
	.uleb128 0x6
	.byte	0x4
	.long	0x60
	.uleb128 0x7
	.long	0x65
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF4
	.uleb128 0x3
	.byte	0x1
	.byte	0x8
	.long	.LASF5
	.uleb128 0x3
	.byte	0x4
	.byte	0x7
	.long	.LASF6
	.uleb128 0x3
	.byte	0x1
	.byte	0x6
	.long	.LASF7
	.uleb128 0x3
	.byte	0x2
	.byte	0x5
	.long	.LASF8
	.uleb128 0x3
	.byte	0x8
	.byte	0x7
	.long	.LASF9
	.uleb128 0x2
	.long	.LASF11
	.byte	0x3
	.byte	0x38
	.long	0x49
	.uleb128 0x2
	.long	.LASF12
	.byte	0x3
	.byte	0x8d
	.long	0x42
	.uleb128 0x2
	.long	.LASF13
	.byte	0x3
	.byte	0x8e
	.long	0x8f
	.uleb128 0x8
	.long	0x3b
	.long	0xc0
	.uleb128 0x9
	.long	0x50
	.byte	0x1
	.byte	0x0
	.uleb128 0x2
	.long	.LASF14
	.byte	0x3
	.byte	0x95
	.long	0x42
	.uleb128 0x2
	.long	.LASF15
	.byte	0x3
	.byte	0x97
	.long	0x42
	.uleb128 0xa
	.byte	0x4
	.uleb128 0x6
	.byte	0x4
	.long	0x65
	.uleb128 0xb
	.long	.LASF18
	.byte	0x8
	.byte	0x4
	.byte	0x46
	.long	0x107
	.uleb128 0xc
	.long	.LASF16
	.byte	0x4
	.byte	0x47
	.long	0xc0
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0xc
	.long	.LASF17
	.byte	0x4
	.byte	0x48
	.long	0xcb
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.byte	0x0
	.uleb128 0xb
	.long	.LASF19
	.byte	0x4
	.byte	0x5
	.byte	0x44
	.long	0x122
	.uleb128 0xc
	.long	.LASF20
	.byte	0x5
	.byte	0x45
	.long	0x122
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x107
	.uleb128 0x2
	.long	.LASF21
	.byte	0x5
	.byte	0x46
	.long	0x107
	.uleb128 0xd
	.long	.LASF23
	.byte	0x18
	.byte	0x5
	.byte	0x4d
	.long	0x1df
	.uleb128 0xb
	.long	.LASF22
	.byte	0x18
	.byte	0x5
	.byte	0x4f
	.long	0x1bd
	.uleb128 0xd
	.long	.LASF23
	.byte	0x4
	.byte	0x5
	.byte	0x60
	.long	0x16e
	.uleb128 0xe
	.long	.LASF24
	.byte	0x5
	.byte	0x61
	.long	0x3b
	.uleb128 0xe
	.long	.LASF25
	.byte	0x5
	.byte	0x62
	.long	0x128
	.byte	0x0
	.uleb128 0xc
	.long	.LASF26
	.byte	0x5
	.byte	0x50
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0xc
	.long	.LASF27
	.byte	0x5
	.byte	0x51
	.long	0x34
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0xc
	.long	.LASF28
	.byte	0x5
	.byte	0x52
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0xc
	.long	.LASF29
	.byte	0x5
	.byte	0x58
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0xc
	.long	.LASF30
	.byte	0x5
	.byte	0x5e
	.long	0x34
	.byte	0x2
	.byte	0x23
	.uleb128 0x10
	.uleb128 0xf
	.long	0x14b
	.byte	0x2
	.byte	0x23
	.uleb128 0x14
	.byte	0x0
	.uleb128 0xe
	.long	.LASF31
	.byte	0x5
	.byte	0x65
	.long	0x13f
	.uleb128 0xe
	.long	.LASF32
	.byte	0x5
	.byte	0x66
	.long	0x1df
	.uleb128 0xe
	.long	.LASF33
	.byte	0x5
	.byte	0x67
	.long	0x42
	.byte	0x0
	.uleb128 0x8
	.long	0x65
	.long	0x1ef
	.uleb128 0x9
	.long	0x50
	.byte	0x17
	.byte	0x0
	.uleb128 0xd
	.long	.LASF23
	.byte	0x30
	.byte	0x5
	.byte	0x74
	.long	0x29a
	.uleb128 0xb
	.long	.LASF34
	.byte	0x2c
	.byte	0x5
	.byte	0x76
	.long	0x278
	.uleb128 0xc
	.long	.LASF26
	.byte	0x5
	.byte	0x77
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0xc
	.long	.LASF35
	.byte	0x5
	.byte	0x78
	.long	0x34
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0xc
	.long	.LASF36
	.byte	0x5
	.byte	0x79
	.long	0x88
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0xc
	.long	.LASF37
	.byte	0x5
	.byte	0x7a
	.long	0x88
	.byte	0x2
	.byte	0x23
	.uleb128 0x10
	.uleb128 0xc
	.long	.LASF38
	.byte	0x5
	.byte	0x7b
	.long	0x88
	.byte	0x2
	.byte	0x23
	.uleb128 0x18
	.uleb128 0xc
	.long	.LASF39
	.byte	0x5
	.byte	0x7c
	.long	0xd6
	.byte	0x2
	.byte	0x23
	.uleb128 0x20
	.uleb128 0xc
	.long	.LASF40
	.byte	0x5
	.byte	0x7d
	.long	0x34
	.byte	0x2
	.byte	0x23
	.uleb128 0x24
	.uleb128 0xc
	.long	.LASF41
	.byte	0x5
	.byte	0x7e
	.long	0x34
	.byte	0x2
	.byte	0x23
	.uleb128 0x28
	.byte	0x0
	.uleb128 0xe
	.long	.LASF31
	.byte	0x5
	.byte	0x7f
	.long	0x1fb
	.uleb128 0xe
	.long	.LASF32
	.byte	0x5
	.byte	0x80
	.long	0x29a
	.uleb128 0xe
	.long	.LASF33
	.byte	0x5
	.byte	0x81
	.long	0x49
	.byte	0x0
	.uleb128 0x8
	.long	0x65
	.long	0x2aa
	.uleb128 0x9
	.long	0x50
	.byte	0x2f
	.byte	0x0
	.uleb128 0x8
	.long	0x65
	.long	0x2ba
	.uleb128 0x9
	.long	0x50
	.byte	0x7
	.byte	0x0
	.uleb128 0x10
	.long	0x3b
	.uleb128 0x11
	.long	.LASF42
	.byte	0x94
	.byte	0x6
	.value	0x10f
	.long	0x480
	.uleb128 0x12
	.long	.LASF43
	.byte	0x6
	.value	0x110
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF44
	.byte	0x6
	.value	0x115
	.long	0xd8
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF45
	.byte	0x6
	.value	0x116
	.long	0xd8
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x12
	.long	.LASF46
	.byte	0x6
	.value	0x117
	.long	0xd8
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x12
	.long	.LASF47
	.byte	0x6
	.value	0x118
	.long	0xd8
	.byte	0x2
	.byte	0x23
	.uleb128 0x10
	.uleb128 0x12
	.long	.LASF48
	.byte	0x6
	.value	0x119
	.long	0xd8
	.byte	0x2
	.byte	0x23
	.uleb128 0x14
	.uleb128 0x12
	.long	.LASF49
	.byte	0x6
	.value	0x11a
	.long	0xd8
	.byte	0x2
	.byte	0x23
	.uleb128 0x18
	.uleb128 0x12
	.long	.LASF50
	.byte	0x6
	.value	0x11b
	.long	0xd8
	.byte	0x2
	.byte	0x23
	.uleb128 0x1c
	.uleb128 0x12
	.long	.LASF51
	.byte	0x6
	.value	0x11c
	.long	0xd8
	.byte	0x2
	.byte	0x23
	.uleb128 0x20
	.uleb128 0x12
	.long	.LASF52
	.byte	0x6
	.value	0x11e
	.long	0xd8
	.byte	0x2
	.byte	0x23
	.uleb128 0x24
	.uleb128 0x12
	.long	.LASF53
	.byte	0x6
	.value	0x11f
	.long	0xd8
	.byte	0x2
	.byte	0x23
	.uleb128 0x28
	.uleb128 0x12
	.long	.LASF54
	.byte	0x6
	.value	0x120
	.long	0xd8
	.byte	0x2
	.byte	0x23
	.uleb128 0x2c
	.uleb128 0x12
	.long	.LASF55
	.byte	0x6
	.value	0x122
	.long	0x4be
	.byte	0x2
	.byte	0x23
	.uleb128 0x30
	.uleb128 0x12
	.long	.LASF56
	.byte	0x6
	.value	0x124
	.long	0x4c4
	.byte	0x2
	.byte	0x23
	.uleb128 0x34
	.uleb128 0x12
	.long	.LASF57
	.byte	0x6
	.value	0x126
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x38
	.uleb128 0x12
	.long	.LASF58
	.byte	0x6
	.value	0x12a
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x3c
	.uleb128 0x12
	.long	.LASF59
	.byte	0x6
	.value	0x12c
	.long	0x9a
	.byte	0x2
	.byte	0x23
	.uleb128 0x40
	.uleb128 0x12
	.long	.LASF60
	.byte	0x6
	.value	0x130
	.long	0x53
	.byte	0x2
	.byte	0x23
	.uleb128 0x44
	.uleb128 0x12
	.long	.LASF61
	.byte	0x6
	.value	0x131
	.long	0x7a
	.byte	0x2
	.byte	0x23
	.uleb128 0x46
	.uleb128 0x12
	.long	.LASF62
	.byte	0x6
	.value	0x132
	.long	0x4ca
	.byte	0x2
	.byte	0x23
	.uleb128 0x47
	.uleb128 0x12
	.long	.LASF63
	.byte	0x6
	.value	0x136
	.long	0x4da
	.byte	0x2
	.byte	0x23
	.uleb128 0x48
	.uleb128 0x12
	.long	.LASF64
	.byte	0x6
	.value	0x13f
	.long	0xa5
	.byte	0x2
	.byte	0x23
	.uleb128 0x4c
	.uleb128 0x12
	.long	.LASF65
	.byte	0x6
	.value	0x148
	.long	0xd6
	.byte	0x2
	.byte	0x23
	.uleb128 0x54
	.uleb128 0x12
	.long	.LASF66
	.byte	0x6
	.value	0x149
	.long	0xd6
	.byte	0x2
	.byte	0x23
	.uleb128 0x58
	.uleb128 0x12
	.long	.LASF67
	.byte	0x6
	.value	0x14a
	.long	0xd6
	.byte	0x2
	.byte	0x23
	.uleb128 0x5c
	.uleb128 0x12
	.long	.LASF68
	.byte	0x6
	.value	0x14b
	.long	0xd6
	.byte	0x2
	.byte	0x23
	.uleb128 0x60
	.uleb128 0x12
	.long	.LASF69
	.byte	0x6
	.value	0x14c
	.long	0x29
	.byte	0x2
	.byte	0x23
	.uleb128 0x64
	.uleb128 0x12
	.long	.LASF70
	.byte	0x6
	.value	0x14e
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x68
	.uleb128 0x12
	.long	.LASF71
	.byte	0x6
	.value	0x150
	.long	0x4e0
	.byte	0x2
	.byte	0x23
	.uleb128 0x6c
	.byte	0x0
	.uleb128 0x13
	.long	.LASF762
	.byte	0x6
	.byte	0xb4
	.uleb128 0xb
	.long	.LASF72
	.byte	0xc
	.byte	0x6
	.byte	0xba
	.long	0x4be
	.uleb128 0xc
	.long	.LASF73
	.byte	0x6
	.byte	0xbb
	.long	0x4be
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0xc
	.long	.LASF74
	.byte	0x6
	.byte	0xbc
	.long	0x4c4
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0xc
	.long	.LASF75
	.byte	0x6
	.byte	0xc0
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x487
	.uleb128 0x6
	.byte	0x4
	.long	0x2bf
	.uleb128 0x8
	.long	0x65
	.long	0x4da
	.uleb128 0x9
	.long	0x50
	.byte	0x0
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x480
	.uleb128 0x8
	.long	0x65
	.long	0x4f0
	.uleb128 0x9
	.long	0x50
	.byte	0x27
	.byte	0x0
	.uleb128 0x3
	.byte	0xc
	.byte	0x4
	.long	.LASF76
	.uleb128 0x3
	.byte	0x8
	.byte	0x4
	.long	.LASF77
	.uleb128 0x8
	.long	0x3b
	.long	0x50e
	.uleb128 0x9
	.long	0x50
	.byte	0x5
	.byte	0x0
	.uleb128 0x14
	.long	.LASF78
	.value	0x218
	.byte	0x7
	.value	0x1f1
	.long	0x596
	.uleb128 0x12
	.long	.LASF79
	.byte	0x7
	.value	0x1f2
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF80
	.byte	0x7
	.value	0x1f3
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF81
	.byte	0x7
	.value	0x1f4
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x12
	.long	.LASF82
	.byte	0x7
	.value	0x1f5
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x12
	.long	.LASF83
	.byte	0x7
	.value	0x1f6
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x10
	.uleb128 0x12
	.long	.LASF84
	.byte	0x7
	.value	0x1f7
	.long	0x59d
	.byte	0x2
	.byte	0x23
	.uleb128 0x14
	.uleb128 0x15
	.string	"key"
	.byte	0x7
	.value	0x1f8
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x18
	.uleb128 0x12
	.long	.LASF85
	.byte	0x7
	.value	0x1f9
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x118
	.byte	0x0
	.uleb128 0x3
	.byte	0x4
	.byte	0x4
	.long	.LASF86
	.uleb128 0x6
	.byte	0x4
	.long	0x81
	.uleb128 0x8
	.long	0x65
	.long	0x5b3
	.uleb128 0x9
	.long	0x50
	.byte	0xff
	.byte	0x0
	.uleb128 0x16
	.long	.LASF78
	.byte	0x7
	.value	0x1fa
	.long	0x50e
	.uleb128 0x14
	.long	.LASF87
	.value	0x7eb0
	.byte	0x7
	.value	0x1fd
	.long	0x64f
	.uleb128 0x12
	.long	.LASF88
	.byte	0x7
	.value	0x1fe
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF89
	.byte	0x7
	.value	0x1ff
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.uleb128 0x12
	.long	.LASF90
	.byte	0x7
	.value	0x200
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x104
	.uleb128 0x12
	.long	.LASF91
	.byte	0x7
	.value	0x201
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x108
	.uleb128 0x12
	.long	.LASF92
	.byte	0x7
	.value	0x202
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x10c
	.uleb128 0x12
	.long	.LASF93
	.byte	0x7
	.value	0x203
	.long	0x64f
	.byte	0x3
	.byte	0x23
	.uleb128 0x110
	.uleb128 0x12
	.long	.LASF94
	.byte	0x7
	.value	0x204
	.long	0x65f
	.byte	0x4
	.byte	0x23
	.uleb128 0x54d0
	.uleb128 0x12
	.long	.LASF95
	.byte	0x7
	.value	0x205
	.long	0x65f
	.byte	0x4
	.byte	0x23
	.uleb128 0x69c0
	.byte	0x0
	.uleb128 0x8
	.long	0x5b3
	.long	0x65f
	.uleb128 0x9
	.long	0x50
	.byte	0x27
	.byte	0x0
	.uleb128 0x8
	.long	0x5b3
	.long	0x66f
	.uleb128 0x9
	.long	0x50
	.byte	0x9
	.byte	0x0
	.uleb128 0x16
	.long	.LASF87
	.byte	0x7
	.value	0x206
	.long	0x5bf
	.uleb128 0x14
	.long	.LASF96
	.value	0x1e8
	.byte	0x7
	.value	0x209
	.long	0x726
	.uleb128 0x15
	.string	"sfd"
	.byte	0x7
	.value	0x20a
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF97
	.byte	0x7
	.value	0x20b
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF98
	.byte	0x7
	.value	0x20c
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x12
	.long	.LASF99
	.byte	0x7
	.value	0x20d
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x12
	.long	.LASF100
	.byte	0x7
	.value	0x20e
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x10c
	.uleb128 0x12
	.long	.LASF101
	.byte	0x7
	.value	0x20f
	.long	0x726
	.byte	0x3
	.byte	0x23
	.uleb128 0x110
	.uleb128 0x12
	.long	.LASF102
	.byte	0x7
	.value	0x210
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x114
	.uleb128 0x12
	.long	.LASF103
	.byte	0x7
	.value	0x211
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x118
	.uleb128 0x12
	.long	.LASF104
	.byte	0x7
	.value	0x212
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x11c
	.uleb128 0x12
	.long	.LASF105
	.byte	0x7
	.value	0x213
	.long	0x72c
	.byte	0x3
	.byte	0x23
	.uleb128 0x120
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x66f
	.uleb128 0x8
	.long	0x81
	.long	0x73c
	.uleb128 0x9
	.long	0x50
	.byte	0x63
	.byte	0x0
	.uleb128 0x16
	.long	.LASF96
	.byte	0x7
	.value	0x214
	.long	0x67b
	.uleb128 0x14
	.long	.LASF106
	.value	0xa8c
	.byte	0x7
	.value	0x217
	.long	0x786
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x218
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF108
	.byte	0x7
	.value	0x219
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.uleb128 0x12
	.long	.LASF109
	.byte	0x7
	.value	0x21a
	.long	0x786
	.byte	0x3
	.byte	0x23
	.uleb128 0x104
	.byte	0x0
	.uleb128 0x8
	.long	0x73c
	.long	0x796
	.uleb128 0x9
	.long	0x50
	.byte	0x4
	.byte	0x0
	.uleb128 0x16
	.long	.LASF106
	.byte	0x7
	.value	0x21b
	.long	0x748
	.uleb128 0x14
	.long	.LASF110
	.value	0x220
	.byte	0x7
	.value	0x22e
	.long	0x848
	.uleb128 0x12
	.long	.LASF98
	.byte	0x7
	.value	0x22f
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF80
	.byte	0x7
	.value	0x230
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x15
	.string	"reg"
	.byte	0x7
	.value	0x231
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x12
	.long	.LASF111
	.byte	0x7
	.value	0x232
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x12
	.long	.LASF112
	.byte	0x7
	.value	0x233
	.long	0xd6
	.byte	0x2
	.byte	0x23
	.uleb128 0x10
	.uleb128 0x12
	.long	.LASF84
	.byte	0x7
	.value	0x234
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x14
	.uleb128 0x12
	.long	.LASF81
	.byte	0x7
	.value	0x235
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x18
	.uleb128 0x12
	.long	.LASF113
	.byte	0x7
	.value	0x236
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x1c
	.uleb128 0x15
	.string	"key"
	.byte	0x7
	.value	0x237
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x20
	.uleb128 0x12
	.long	.LASF85
	.byte	0x7
	.value	0x238
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x120
	.byte	0x0
	.uleb128 0x16
	.long	.LASF110
	.byte	0x7
	.value	0x239
	.long	0x7a2
	.uleb128 0x17
	.long	.LASF114
	.long	0x1aa10
	.byte	0x7
	.value	0x23c
	.long	0x8e6
	.uleb128 0x12
	.long	.LASF88
	.byte	0x7
	.value	0x23d
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF89
	.byte	0x7
	.value	0x23e
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.uleb128 0x12
	.long	.LASF90
	.byte	0x7
	.value	0x23f
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x104
	.uleb128 0x12
	.long	.LASF91
	.byte	0x7
	.value	0x240
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x108
	.uleb128 0x12
	.long	.LASF92
	.byte	0x7
	.value	0x241
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x10c
	.uleb128 0x12
	.long	.LASF93
	.byte	0x7
	.value	0x242
	.long	0x8e6
	.byte	0x3
	.byte	0x23
	.uleb128 0x110
	.uleb128 0x12
	.long	.LASF94
	.byte	0x7
	.value	0x243
	.long	0x8f6
	.byte	0x4
	.byte	0x23
	.uleb128 0x6b50
	.uleb128 0x12
	.long	.LASF95
	.byte	0x7
	.value	0x244
	.long	0x8e6
	.byte	0x4
	.byte	0x23
	.uleb128 0x13fd0
	.byte	0x0
	.uleb128 0x8
	.long	0x848
	.long	0x8f6
	.uleb128 0x9
	.long	0x50
	.byte	0x31
	.byte	0x0
	.uleb128 0x8
	.long	0x848
	.long	0x906
	.uleb128 0x9
	.long	0x50
	.byte	0x63
	.byte	0x0
	.uleb128 0x16
	.long	.LASF114
	.byte	0x7
	.value	0x245
	.long	0x854
	.uleb128 0x14
	.long	.LASF115
	.value	0x214
	.byte	0x7
	.value	0x248
	.long	0x990
	.uleb128 0x12
	.long	.LASF116
	.byte	0x7
	.value	0x249
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x15
	.string	"sfd"
	.byte	0x7
	.value	0x24a
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.uleb128 0x12
	.long	.LASF97
	.byte	0x7
	.value	0x24b
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x104
	.uleb128 0x12
	.long	.LASF99
	.byte	0x7
	.value	0x24c
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x108
	.uleb128 0x12
	.long	.LASF117
	.byte	0x7
	.value	0x24d
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x208
	.uleb128 0x12
	.long	.LASF118
	.byte	0x7
	.value	0x24e
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x20c
	.uleb128 0x12
	.long	.LASF101
	.byte	0x7
	.value	0x24f
	.long	0x990
	.byte	0x3
	.byte	0x23
	.uleb128 0x210
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x906
	.uleb128 0x16
	.long	.LASF115
	.byte	0x7
	.value	0x250
	.long	0x912
	.uleb128 0x14
	.long	.LASF119
	.value	0x954
	.byte	0x7
	.value	0x253
	.long	0x9e0
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x254
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF108
	.byte	0x7
	.value	0x255
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.uleb128 0x15
	.string	"mac"
	.byte	0x7
	.value	0x256
	.long	0x9e0
	.byte	0x3
	.byte	0x23
	.uleb128 0x104
	.byte	0x0
	.uleb128 0x8
	.long	0x996
	.long	0x9f0
	.uleb128 0x9
	.long	0x50
	.byte	0x3
	.byte	0x0
	.uleb128 0x16
	.long	.LASF119
	.byte	0x7
	.value	0x257
	.long	0x9a2
	.uleb128 0x14
	.long	.LASF120
	.value	0x20c
	.byte	0x7
	.value	0x25b
	.long	0xa57
	.uleb128 0x12
	.long	.LASF80
	.byte	0x7
	.value	0x25c
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF81
	.byte	0x7
	.value	0x25d
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF121
	.byte	0x7
	.value	0x25e
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x15
	.string	"key"
	.byte	0x7
	.value	0x25f
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x12
	.long	.LASF85
	.byte	0x7
	.value	0x260
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x10c
	.byte	0x0
	.uleb128 0x16
	.long	.LASF120
	.byte	0x7
	.value	0x261
	.long	0x9fc
	.uleb128 0x14
	.long	.LASF122
	.value	0x1174
	.byte	0x7
	.value	0x264
	.long	0xadf
	.uleb128 0x15
	.string	"sfd"
	.byte	0x7
	.value	0x265
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF97
	.byte	0x7
	.value	0x266
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF99
	.byte	0x7
	.value	0x267
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x12
	.long	.LASF117
	.byte	0x7
	.value	0x268
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x108
	.uleb128 0x12
	.long	.LASF123
	.byte	0x7
	.value	0x269
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x10c
	.uleb128 0x12
	.long	.LASF100
	.byte	0x7
	.value	0x26a
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x110
	.uleb128 0x12
	.long	.LASF101
	.byte	0x7
	.value	0x26b
	.long	0xadf
	.byte	0x3
	.byte	0x23
	.uleb128 0x114
	.byte	0x0
	.uleb128 0x8
	.long	0xa57
	.long	0xaef
	.uleb128 0x9
	.long	0x50
	.byte	0x7
	.byte	0x0
	.uleb128 0x16
	.long	.LASF122
	.byte	0x7
	.value	0x26c
	.long	0xa63
	.uleb128 0x14
	.long	.LASF124
	.value	0x3560
	.byte	0x7
	.value	0x26f
	.long	0xb39
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x270
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF108
	.byte	0x7
	.value	0x271
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.uleb128 0x12
	.long	.LASF125
	.byte	0x7
	.value	0x272
	.long	0xb39
	.byte	0x3
	.byte	0x23
	.uleb128 0x104
	.byte	0x0
	.uleb128 0x8
	.long	0xaef
	.long	0xb49
	.uleb128 0x9
	.long	0x50
	.byte	0x2
	.byte	0x0
	.uleb128 0x16
	.long	.LASF124
	.byte	0x7
	.value	0x273
	.long	0xafb
	.uleb128 0x14
	.long	.LASF126
	.value	0x318
	.byte	0x7
	.value	0x285
	.long	0xc0c
	.uleb128 0x18
	.long	.LASF23
	.byte	0x4
	.byte	0x7
	.value	0x28c
	.long	0xb89
	.uleb128 0x19
	.long	.LASF127
	.byte	0x7
	.value	0x28d
	.long	0x59d
	.uleb128 0x19
	.long	.LASF128
	.byte	0x7
	.value	0x28e
	.long	0xc0c
	.byte	0x0
	.uleb128 0x12
	.long	.LASF129
	.byte	0x7
	.value	0x286
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF130
	.byte	0x7
	.value	0x287
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF131
	.byte	0x7
	.value	0x288
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x12
	.long	.LASF132
	.byte	0x7
	.value	0x289
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x12
	.long	.LASF133
	.byte	0x7
	.value	0x28a
	.long	0x53
	.byte	0x2
	.byte	0x23
	.uleb128 0x10
	.uleb128 0xf
	.long	0xb63
	.byte	0x2
	.byte	0x23
	.uleb128 0x14
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x290
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x18
	.uleb128 0x15
	.string	"key"
	.byte	0x7
	.value	0x291
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x118
	.uleb128 0x12
	.long	.LASF134
	.byte	0x7
	.value	0x292
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x218
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x53
	.uleb128 0x16
	.long	.LASF126
	.byte	0x7
	.value	0x293
	.long	0xb55
	.uleb128 0x14
	.long	.LASF135
	.value	0x5ee8
	.byte	0x7
	.value	0x296
	.long	0xcbd
	.uleb128 0x12
	.long	.LASF98
	.byte	0x7
	.value	0x297
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF136
	.byte	0x7
	.value	0x298
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF88
	.byte	0x7
	.value	0x299
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x104
	.uleb128 0x12
	.long	.LASF108
	.byte	0x7
	.value	0x29a
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x204
	.uleb128 0x12
	.long	.LASF91
	.byte	0x7
	.value	0x29b
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x208
	.uleb128 0x12
	.long	.LASF92
	.byte	0x7
	.value	0x29c
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x20c
	.uleb128 0x12
	.long	.LASF137
	.byte	0x7
	.value	0x29d
	.long	0xcbd
	.byte	0x3
	.byte	0x23
	.uleb128 0x210
	.uleb128 0x12
	.long	.LASF94
	.byte	0x7
	.value	0x29e
	.long	0xc0c
	.byte	0x4
	.byte	0x23
	.uleb128 0x5ee0
	.uleb128 0x12
	.long	.LASF95
	.byte	0x7
	.value	0x29f
	.long	0xc0c
	.byte	0x4
	.byte	0x23
	.uleb128 0x5ee4
	.byte	0x0
	.uleb128 0x8
	.long	0xc12
	.long	0xccd
	.uleb128 0x9
	.long	0x50
	.byte	0x1d
	.byte	0x0
	.uleb128 0x16
	.long	.LASF135
	.byte	0x7
	.value	0x2a0
	.long	0xc1e
	.uleb128 0x14
	.long	.LASF138
	.value	0x10bc
	.byte	0x7
	.value	0x2a3
	.long	0xd84
	.uleb128 0x15
	.string	"sfd"
	.byte	0x7
	.value	0x2a4
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF139
	.byte	0x7
	.value	0x2a5
	.long	0x2ba
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF97
	.byte	0x7
	.value	0x2a6
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x12
	.long	.LASF99
	.byte	0x7
	.value	0x2a7
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x12
	.long	.LASF100
	.byte	0x7
	.value	0x2a8
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x10c
	.uleb128 0x12
	.long	.LASF101
	.byte	0x7
	.value	0x2a9
	.long	0xd84
	.byte	0x3
	.byte	0x23
	.uleb128 0x110
	.uleb128 0x12
	.long	.LASF91
	.byte	0x7
	.value	0x2aa
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x114
	.uleb128 0x12
	.long	.LASF94
	.byte	0x7
	.value	0x2ab
	.long	0xd8a
	.byte	0x3
	.byte	0x23
	.uleb128 0x118
	.uleb128 0x12
	.long	.LASF92
	.byte	0x7
	.value	0x2ac
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x8e8
	.uleb128 0x12
	.long	.LASF95
	.byte	0x7
	.value	0x2ad
	.long	0xd8a
	.byte	0x3
	.byte	0x23
	.uleb128 0x8ec
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0xccd
	.uleb128 0x8
	.long	0x53
	.long	0xd9b
	.uleb128 0x1a
	.long	0x50
	.value	0x3e7
	.byte	0x0
	.uleb128 0x16
	.long	.LASF138
	.byte	0x7
	.value	0x2ae
	.long	0xcd9
	.uleb128 0x14
	.long	.LASF140
	.value	0x54b0
	.byte	0x7
	.value	0x2b1
	.long	0xde5
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x2b2
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF108
	.byte	0x7
	.value	0x2b3
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.uleb128 0x15
	.string	"dio"
	.byte	0x7
	.value	0x2b4
	.long	0xde5
	.byte	0x3
	.byte	0x23
	.uleb128 0x104
	.byte	0x0
	.uleb128 0x8
	.long	0xd9b
	.long	0xdf5
	.uleb128 0x9
	.long	0x50
	.byte	0x4
	.byte	0x0
	.uleb128 0x16
	.long	.LASF140
	.byte	0x7
	.value	0x2b5
	.long	0xda7
	.uleb128 0x14
	.long	.LASF141
	.value	0x108
	.byte	0x7
	.value	0x2cf
	.long	0xe3e
	.uleb128 0x12
	.long	.LASF142
	.byte	0x7
	.value	0x2d0
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x15
	.string	"key"
	.byte	0x7
	.value	0x2d1
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF128
	.byte	0x7
	.value	0x2d2
	.long	0xe3e
	.byte	0x3
	.byte	0x23
	.uleb128 0x104
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x34
	.uleb128 0x16
	.long	.LASF141
	.byte	0x7
	.value	0x2d3
	.long	0xe01
	.uleb128 0x14
	.long	.LASF143
	.value	0x231c
	.byte	0x7
	.value	0x2d6
	.long	0xf0d
	.uleb128 0x12
	.long	.LASF98
	.byte	0x7
	.value	0x2d7
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF136
	.byte	0x7
	.value	0x2d8
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF88
	.byte	0x7
	.value	0x2d9
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x104
	.uleb128 0x12
	.long	.LASF89
	.byte	0x7
	.value	0x2da
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x204
	.uleb128 0x12
	.long	.LASF144
	.byte	0x7
	.value	0x2db
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x208
	.uleb128 0x12
	.long	.LASF145
	.byte	0x7
	.value	0x2dc
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x20c
	.uleb128 0x12
	.long	.LASF146
	.byte	0x7
	.value	0x2dd
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x210
	.uleb128 0x12
	.long	.LASF147
	.byte	0x7
	.value	0x2de
	.long	0xf0d
	.byte	0x3
	.byte	0x23
	.uleb128 0x214
	.uleb128 0x12
	.long	.LASF148
	.byte	0x7
	.value	0x2df
	.long	0xf0d
	.byte	0x3
	.byte	0x23
	.uleb128 0x1294
	.uleb128 0x12
	.long	.LASF94
	.byte	0x7
	.value	0x2e0
	.long	0x34
	.byte	0x3
	.byte	0x23
	.uleb128 0x2314
	.uleb128 0x12
	.long	.LASF95
	.byte	0x7
	.value	0x2e1
	.long	0x34
	.byte	0x3
	.byte	0x23
	.uleb128 0x2318
	.byte	0x0
	.uleb128 0x8
	.long	0xe44
	.long	0xf1d
	.uleb128 0x9
	.long	0x50
	.byte	0xf
	.byte	0x0
	.uleb128 0x16
	.long	.LASF143
	.byte	0x7
	.value	0x2e2
	.long	0xe50
	.uleb128 0x14
	.long	.LASF149
	.value	0x114
	.byte	0x7
	.value	0x2e5
	.long	0xf95
	.uleb128 0x15
	.string	"sfd"
	.byte	0x7
	.value	0x2e6
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF97
	.byte	0x7
	.value	0x2e7
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF99
	.byte	0x7
	.value	0x2e8
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x12
	.long	.LASF117
	.byte	0x7
	.value	0x2e9
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x108
	.uleb128 0x12
	.long	.LASF100
	.byte	0x7
	.value	0x2ea
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x10c
	.uleb128 0x12
	.long	.LASF101
	.byte	0x7
	.value	0x2eb
	.long	0xf95
	.byte	0x3
	.byte	0x23
	.uleb128 0x110
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0xf1d
	.uleb128 0x16
	.long	.LASF149
	.byte	0x7
	.value	0x2ec
	.long	0xf29
	.uleb128 0x14
	.long	.LASF150
	.value	0x568
	.byte	0x7
	.value	0x2ef
	.long	0xfd4
	.uleb128 0x12
	.long	.LASF108
	.byte	0x7
	.value	0x2f0
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF151
	.byte	0x7
	.value	0x2f1
	.long	0xfd4
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.byte	0x0
	.uleb128 0x8
	.long	0xf9b
	.long	0xfe4
	.uleb128 0x9
	.long	0x50
	.byte	0x4
	.byte	0x0
	.uleb128 0x16
	.long	.LASF150
	.byte	0x7
	.value	0x2f2
	.long	0xfa7
	.uleb128 0x8
	.long	0x596
	.long	0x1000
	.uleb128 0x9
	.long	0x50
	.byte	0x13
	.byte	0x0
	.uleb128 0x8
	.long	0x596
	.long	0x1010
	.uleb128 0x9
	.long	0x50
	.byte	0x5
	.byte	0x0
	.uleb128 0x11
	.long	.LASF152
	.byte	0xc
	.byte	0x7
	.value	0x350
	.long	0x1045
	.uleb128 0x15
	.string	"x"
	.byte	0x7
	.value	0x351
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x15
	.string	"y"
	.byte	0x7
	.value	0x351
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x15
	.string	"z"
	.byte	0x7
	.value	0x351
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.byte	0x0
	.uleb128 0x16
	.long	.LASF152
	.byte	0x7
	.value	0x352
	.long	0x1010
	.uleb128 0x11
	.long	.LASF153
	.byte	0x34
	.byte	0x7
	.value	0x35c
	.long	0x109b
	.uleb128 0x12
	.long	.LASF154
	.byte	0x7
	.value	0x35d
	.long	0x109b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF155
	.byte	0x7
	.value	0x35e
	.long	0x109b
	.byte	0x2
	.byte	0x23
	.uleb128 0x10
	.uleb128 0x12
	.long	.LASF156
	.byte	0x7
	.value	0x35f
	.long	0x109b
	.byte	0x2
	.byte	0x23
	.uleb128 0x20
	.uleb128 0x12
	.long	.LASF157
	.byte	0x7
	.value	0x360
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x30
	.byte	0x0
	.uleb128 0x8
	.long	0x596
	.long	0x10ab
	.uleb128 0x9
	.long	0x50
	.byte	0x3
	.byte	0x0
	.uleb128 0x16
	.long	.LASF153
	.byte	0x7
	.value	0x361
	.long	0x1051
	.uleb128 0x11
	.long	.LASF158
	.byte	0x18
	.byte	0x7
	.value	0x390
	.long	0x1113
	.uleb128 0x15
	.string	"x"
	.byte	0x7
	.value	0x391
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x15
	.string	"y"
	.byte	0x7
	.value	0x391
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x15
	.string	"z"
	.byte	0x7
	.value	0x391
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x15
	.string	"v"
	.byte	0x7
	.value	0x391
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x15
	.string	"w"
	.byte	0x7
	.value	0x391
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x10
	.uleb128 0x15
	.string	"u"
	.byte	0x7
	.value	0x391
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x14
	.byte	0x0
	.uleb128 0x16
	.long	.LASF158
	.byte	0x7
	.value	0x392
	.long	0x10b7
	.uleb128 0x11
	.long	.LASF159
	.byte	0x30
	.byte	0x7
	.value	0x395
	.long	0x11d5
	.uleb128 0x15
	.string	"x"
	.byte	0x7
	.value	0x396
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x15
	.string	"y"
	.byte	0x7
	.value	0x396
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x15
	.string	"z"
	.byte	0x7
	.value	0x396
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x15
	.string	"v"
	.byte	0x7
	.value	0x396
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x15
	.string	"w"
	.byte	0x7
	.value	0x396
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x10
	.uleb128 0x15
	.string	"u"
	.byte	0x7
	.value	0x396
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x14
	.uleb128 0x12
	.long	.LASF160
	.byte	0x7
	.value	0x397
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x18
	.uleb128 0x12
	.long	.LASF161
	.byte	0x7
	.value	0x397
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x1c
	.uleb128 0x12
	.long	.LASF162
	.byte	0x7
	.value	0x397
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x20
	.uleb128 0x12
	.long	.LASF163
	.byte	0x7
	.value	0x397
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x24
	.uleb128 0x12
	.long	.LASF164
	.byte	0x7
	.value	0x397
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x28
	.uleb128 0x12
	.long	.LASF165
	.byte	0x7
	.value	0x397
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x2c
	.byte	0x0
	.uleb128 0x16
	.long	.LASF159
	.byte	0x7
	.value	0x398
	.long	0x111f
	.uleb128 0x14
	.long	.LASF166
	.value	0x118
	.byte	0x7
	.value	0x39b
	.long	0x1253
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x39d
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x15
	.string	"x"
	.byte	0x7
	.value	0x39e
	.long	0x596
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.uleb128 0x15
	.string	"y"
	.byte	0x7
	.value	0x39e
	.long	0x596
	.byte	0x3
	.byte	0x23
	.uleb128 0x104
	.uleb128 0x15
	.string	"z"
	.byte	0x7
	.value	0x39e
	.long	0x596
	.byte	0x3
	.byte	0x23
	.uleb128 0x108
	.uleb128 0x15
	.string	"v"
	.byte	0x7
	.value	0x39e
	.long	0x596
	.byte	0x3
	.byte	0x23
	.uleb128 0x10c
	.uleb128 0x15
	.string	"w"
	.byte	0x7
	.value	0x39e
	.long	0x596
	.byte	0x3
	.byte	0x23
	.uleb128 0x110
	.uleb128 0x15
	.string	"u"
	.byte	0x7
	.value	0x39e
	.long	0x596
	.byte	0x3
	.byte	0x23
	.uleb128 0x114
	.byte	0x0
	.uleb128 0x16
	.long	.LASF166
	.byte	0x7
	.value	0x39f
	.long	0x11e1
	.uleb128 0x14
	.long	.LASF167
	.value	0x20d4
	.byte	0x7
	.value	0x3a2
	.long	0x128c
	.uleb128 0x12
	.long	.LASF108
	.byte	0x7
	.value	0x3a3
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF168
	.byte	0x7
	.value	0x3a4
	.long	0x128c
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.byte	0x0
	.uleb128 0x8
	.long	0x1253
	.long	0x129c
	.uleb128 0x9
	.long	0x50
	.byte	0x1d
	.byte	0x0
	.uleb128 0x16
	.long	.LASF167
	.byte	0x7
	.value	0x3a5
	.long	0x125f
	.uleb128 0x14
	.long	.LASF169
	.value	0x104
	.byte	0x7
	.value	0x3a8
	.long	0x12d6
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x3a9
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF170
	.byte	0x7
	.value	0x3aa
	.long	0x596
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.byte	0x0
	.uleb128 0x16
	.long	.LASF169
	.byte	0x7
	.value	0x3ab
	.long	0x12a8
	.uleb128 0x14
	.long	.LASF171
	.value	0x32cc
	.byte	0x7
	.value	0x3ae
	.long	0x130f
	.uleb128 0x12
	.long	.LASF108
	.byte	0x7
	.value	0x3af
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF172
	.byte	0x7
	.value	0x3b0
	.long	0x130f
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.byte	0x0
	.uleb128 0x8
	.long	0x12d6
	.long	0x131f
	.uleb128 0x9
	.long	0x50
	.byte	0x31
	.byte	0x0
	.uleb128 0x16
	.long	.LASF171
	.byte	0x7
	.value	0x3b1
	.long	0x12e2
	.uleb128 0x11
	.long	.LASF173
	.byte	0x18
	.byte	0x7
	.value	0x3ba
	.long	0x1387
	.uleb128 0x15
	.string	"a"
	.byte	0x7
	.value	0x3bb
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x15
	.string	"b"
	.byte	0x7
	.value	0x3bb
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x15
	.string	"c"
	.byte	0x7
	.value	0x3bb
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x15
	.string	"d"
	.byte	0x7
	.value	0x3bb
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x15
	.string	"e"
	.byte	0x7
	.value	0x3bb
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x10
	.uleb128 0x15
	.string	"f"
	.byte	0x7
	.value	0x3bb
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x14
	.byte	0x0
	.uleb128 0x16
	.long	.LASF173
	.byte	0x7
	.value	0x3bc
	.long	0x132b
	.uleb128 0x18
	.long	.LASF174
	.byte	0x18
	.byte	0x7
	.value	0x3bf
	.long	0x13b9
	.uleb128 0x19
	.long	.LASF107
	.byte	0x7
	.value	0x3c0
	.long	0x1387
	.uleb128 0x19
	.long	.LASF175
	.byte	0x7
	.value	0x3c1
	.long	0x1000
	.byte	0x0
	.uleb128 0x16
	.long	.LASF174
	.byte	0x7
	.value	0x3c2
	.long	0x1393
	.uleb128 0x11
	.long	.LASF176
	.byte	0x1c
	.byte	0x7
	.value	0x3c9
	.long	0x140f
	.uleb128 0x12
	.long	.LASF177
	.byte	0x7
	.value	0x3d3
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF178
	.byte	0x7
	.value	0x3d4
	.long	0x140f
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF170
	.byte	0x7
	.value	0x3d5
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x14
	.uleb128 0x15
	.string	"ABS"
	.byte	0x7
	.value	0x3d6
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x18
	.byte	0x0
	.uleb128 0x8
	.long	0x65
	.long	0x141f
	.uleb128 0x9
	.long	0x50
	.byte	0xf
	.byte	0x0
	.uleb128 0x16
	.long	.LASF176
	.byte	0x7
	.value	0x3d7
	.long	0x13c5
	.uleb128 0x14
	.long	.LASF179
	.value	0x8c0
	.byte	0x7
	.value	0x3da
	.long	0x147f
	.uleb128 0x15
	.string	"x"
	.byte	0x7
	.value	0x3db
	.long	0x147f
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x15
	.string	"y"
	.byte	0x7
	.value	0x3dc
	.long	0x147f
	.byte	0x3
	.byte	0x23
	.uleb128 0x1c0
	.uleb128 0x15
	.string	"z"
	.byte	0x7
	.value	0x3dd
	.long	0x147f
	.byte	0x3
	.byte	0x23
	.uleb128 0x380
	.uleb128 0x15
	.string	"v"
	.byte	0x7
	.value	0x3de
	.long	0x147f
	.byte	0x3
	.byte	0x23
	.uleb128 0x540
	.uleb128 0x15
	.string	"w"
	.byte	0x7
	.value	0x3df
	.long	0x147f
	.byte	0x3
	.byte	0x23
	.uleb128 0x700
	.byte	0x0
	.uleb128 0x8
	.long	0x141f
	.long	0x148f
	.uleb128 0x9
	.long	0x50
	.byte	0xf
	.byte	0x0
	.uleb128 0x16
	.long	.LASF179
	.byte	0x7
	.value	0x3e0
	.long	0x142b
	.uleb128 0x11
	.long	.LASF180
	.byte	0x20
	.byte	0x7
	.value	0x3e3
	.long	0x14c7
	.uleb128 0x12
	.long	.LASF181
	.byte	0x7
	.value	0x3f1
	.long	0xb0
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF182
	.byte	0x7
	.value	0x3f2
	.long	0x1000
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.byte	0x0
	.uleb128 0x16
	.long	.LASF180
	.byte	0x7
	.value	0x3f3
	.long	0x149b
	.uleb128 0x11
	.long	.LASF183
	.byte	0x20
	.byte	0x7
	.value	0x3f6
	.long	0x14ff
	.uleb128 0x12
	.long	.LASF181
	.byte	0x7
	.value	0x404
	.long	0xb0
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF182
	.byte	0x7
	.value	0x405
	.long	0x1000
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.byte	0x0
	.uleb128 0x16
	.long	.LASF183
	.byte	0x7
	.value	0x406
	.long	0x14d3
	.uleb128 0x14
	.long	.LASF184
	.value	0x2a94
	.byte	0x7
	.value	0x409
	.long	0x1635
	.uleb128 0x14
	.long	.LASF34
	.value	0x600
	.byte	0x7
	.value	0x40f
	.long	0x1587
	.uleb128 0x12
	.long	.LASF185
	.byte	0x7
	.value	0x410
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF186
	.byte	0x7
	.value	0x411
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.uleb128 0x12
	.long	.LASF187
	.byte	0x7
	.value	0x412
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x200
	.uleb128 0x12
	.long	.LASF188
	.byte	0x7
	.value	0x413
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x300
	.uleb128 0x12
	.long	.LASF189
	.byte	0x7
	.value	0x414
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x400
	.uleb128 0x12
	.long	.LASF190
	.byte	0x7
	.value	0x415
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x500
	.byte	0x0
	.uleb128 0x12
	.long	.LASF191
	.byte	0x7
	.value	0x40a
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF192
	.byte	0x7
	.value	0x40b
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.uleb128 0x12
	.long	.LASF193
	.byte	0x7
	.value	0x40c
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x104
	.uleb128 0x12
	.long	.LASF194
	.byte	0x7
	.value	0x40d
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x108
	.uleb128 0x15
	.string	"def"
	.byte	0x7
	.value	0x416
	.long	0x1519
	.byte	0x3
	.byte	0x23
	.uleb128 0x10c
	.uleb128 0x12
	.long	.LASF195
	.byte	0x7
	.value	0x417
	.long	0x1635
	.byte	0x3
	.byte	0x23
	.uleb128 0x70c
	.uleb128 0x12
	.long	.LASF196
	.byte	0x7
	.value	0x418
	.long	0x1635
	.byte	0x3
	.byte	0x23
	.uleb128 0x188c
	.uleb128 0x12
	.long	.LASF197
	.byte	0x7
	.value	0x419
	.long	0x1645
	.byte	0x3
	.byte	0x23
	.uleb128 0x2a0c
	.uleb128 0x15
	.string	"mv"
	.byte	0x7
	.value	0x41a
	.long	0x1655
	.byte	0x3
	.byte	0x23
	.uleb128 0x2a4c
	.uleb128 0x15
	.string	"ma"
	.byte	0x7
	.value	0x41b
	.long	0x1655
	.byte	0x3
	.byte	0x23
	.uleb128 0x2a60
	.uleb128 0x12
	.long	.LASF198
	.byte	0x7
	.value	0x41c
	.long	0x14ff
	.byte	0x3
	.byte	0x23
	.uleb128 0x2a74
	.byte	0x0
	.uleb128 0x8
	.long	0x148f
	.long	0x1645
	.uleb128 0x9
	.long	0x50
	.byte	0x1
	.byte	0x0
	.uleb128 0x8
	.long	0x14c7
	.long	0x1655
	.uleb128 0x9
	.long	0x50
	.byte	0x1
	.byte	0x0
	.uleb128 0x8
	.long	0x596
	.long	0x1665
	.uleb128 0x9
	.long	0x50
	.byte	0x4
	.byte	0x0
	.uleb128 0x16
	.long	.LASF184
	.byte	0x7
	.value	0x41d
	.long	0x150b
	.uleb128 0x17
	.long	.LASF199
	.long	0x6a8a4
	.byte	0x7
	.value	0x420
	.long	0x16c1
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x421
	.long	0x16c1
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF116
	.byte	0x7
	.value	0x422
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x80
	.uleb128 0x12
	.long	.LASF108
	.byte	0x7
	.value	0x423
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x180
	.uleb128 0x12
	.long	.LASF172
	.byte	0x7
	.value	0x424
	.long	0x16d1
	.byte	0x3
	.byte	0x23
	.uleb128 0x184
	.byte	0x0
	.uleb128 0x8
	.long	0x65
	.long	0x16d1
	.uleb128 0x9
	.long	0x50
	.byte	0x7f
	.byte	0x0
	.uleb128 0x8
	.long	0x1665
	.long	0x16e1
	.uleb128 0x9
	.long	0x50
	.byte	0x27
	.byte	0x0
	.uleb128 0x16
	.long	.LASF199
	.byte	0x7
	.value	0x425
	.long	0x1671
	.uleb128 0x14
	.long	.LASF200
	.value	0x324
	.byte	0x7
	.value	0x42c
	.long	0x1797
	.uleb128 0x12
	.long	.LASF98
	.byte	0x7
	.value	0x42d
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x42e
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.uleb128 0x12
	.long	.LASF116
	.byte	0x7
	.value	0x42f
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x200
	.uleb128 0x15
	.string	"dim"
	.byte	0x7
	.value	0x430
	.long	0x1045
	.byte	0x3
	.byte	0x23
	.uleb128 0x300
	.uleb128 0x15
	.string	"sy"
	.byte	0x7
	.value	0x431
	.long	0x596
	.byte	0x3
	.byte	0x23
	.uleb128 0x30c
	.uleb128 0x15
	.string	"gy"
	.byte	0x7
	.value	0x432
	.long	0x596
	.byte	0x3
	.byte	0x23
	.uleb128 0x310
	.uleb128 0x15
	.string	"my"
	.byte	0x7
	.value	0x433
	.long	0x596
	.byte	0x3
	.byte	0x23
	.uleb128 0x314
	.uleb128 0x15
	.string	"gx"
	.byte	0x7
	.value	0x434
	.long	0x596
	.byte	0x3
	.byte	0x23
	.uleb128 0x318
	.uleb128 0x12
	.long	.LASF201
	.byte	0x7
	.value	0x435
	.long	0x596
	.byte	0x3
	.byte	0x23
	.uleb128 0x31c
	.uleb128 0x12
	.long	.LASF202
	.byte	0x7
	.value	0x436
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x320
	.byte	0x0
	.uleb128 0x16
	.long	.LASF200
	.byte	0x7
	.value	0x437
	.long	0x16ed
	.uleb128 0x14
	.long	.LASF203
	.value	0x11c
	.byte	0x7
	.value	0x43a
	.long	0x17d0
	.uleb128 0x12
	.long	.LASF204
	.byte	0x7
	.value	0x43b
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x15
	.string	"wcp"
	.byte	0x7
	.value	0x43c
	.long	0x1253
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.byte	0x0
	.uleb128 0x16
	.long	.LASF203
	.byte	0x7
	.value	0x43d
	.long	0x17a3
	.uleb128 0x14
	.long	.LASF205
	.value	0xdfec
	.byte	0x7
	.value	0x440
	.long	0x184a
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x441
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF116
	.byte	0x7
	.value	0x442
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.uleb128 0x12
	.long	.LASF108
	.byte	0x7
	.value	0x443
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x200
	.uleb128 0x12
	.long	.LASF206
	.byte	0x7
	.value	0x444
	.long	0x596
	.byte	0x3
	.byte	0x23
	.uleb128 0x204
	.uleb128 0x12
	.long	.LASF207
	.byte	0x7
	.value	0x445
	.long	0x596
	.byte	0x3
	.byte	0x23
	.uleb128 0x208
	.uleb128 0x12
	.long	.LASF172
	.byte	0x7
	.value	0x446
	.long	0x184a
	.byte	0x3
	.byte	0x23
	.uleb128 0x20c
	.byte	0x0
	.uleb128 0x8
	.long	0x17d0
	.long	0x185a
	.uleb128 0x9
	.long	0x50
	.byte	0xc7
	.byte	0x0
	.uleb128 0x16
	.long	.LASF205
	.byte	0x7
	.value	0x447
	.long	0x17dc
	.uleb128 0x11
	.long	.LASF208
	.byte	0x18
	.byte	0x7
	.value	0x44e
	.long	0x18ce
	.uleb128 0x12
	.long	.LASF204
	.byte	0x7
	.value	0x44f
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF209
	.byte	0x7
	.value	0x450
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF210
	.byte	0x7
	.value	0x451
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x12
	.long	.LASF211
	.byte	0x7
	.value	0x452
	.long	0x18ce
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x12
	.long	.LASF212
	.byte	0x7
	.value	0x453
	.long	0x18ce
	.byte	0x2
	.byte	0x23
	.uleb128 0x10
	.uleb128 0x12
	.long	.LASF213
	.byte	0x7
	.value	0x454
	.long	0x18ce
	.byte	0x2
	.byte	0x23
	.uleb128 0x14
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x3b
	.uleb128 0x16
	.long	.LASF208
	.byte	0x7
	.value	0x455
	.long	0x1866
	.uleb128 0x14
	.long	.LASF214
	.value	0x214
	.byte	0x7
	.value	0x458
	.long	0x195e
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x459
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF116
	.byte	0x7
	.value	0x45a
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.uleb128 0x12
	.long	.LASF202
	.byte	0x7
	.value	0x45b
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x200
	.uleb128 0x12
	.long	.LASF215
	.byte	0x7
	.value	0x45c
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x204
	.uleb128 0x12
	.long	.LASF216
	.byte	0x7
	.value	0x45d
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x208
	.uleb128 0x12
	.long	.LASF108
	.byte	0x7
	.value	0x45e
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x20c
	.uleb128 0x12
	.long	.LASF217
	.byte	0x7
	.value	0x45f
	.long	0x195e
	.byte	0x3
	.byte	0x23
	.uleb128 0x210
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x18d4
	.uleb128 0x16
	.long	.LASF214
	.byte	0x7
	.value	0x460
	.long	0x18e0
	.uleb128 0x11
	.long	.LASF218
	.byte	0x30
	.byte	0x7
	.value	0x466
	.long	0x1a22
	.uleb128 0x12
	.long	.LASF219
	.byte	0x7
	.value	0x467
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF220
	.byte	0x7
	.value	0x468
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF221
	.byte	0x7
	.value	0x469
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x15
	.string	"x"
	.byte	0x7
	.value	0x46a
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x15
	.string	"y"
	.byte	0x7
	.value	0x46a
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x10
	.uleb128 0x15
	.string	"z"
	.byte	0x7
	.value	0x46a
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x14
	.uleb128 0x15
	.string	"v"
	.byte	0x7
	.value	0x46a
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x18
	.uleb128 0x15
	.string	"w"
	.byte	0x7
	.value	0x46a
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x1c
	.uleb128 0x15
	.string	"u"
	.byte	0x7
	.value	0x46a
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x20
	.uleb128 0x15
	.string	"dt"
	.byte	0x7
	.value	0x46b
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x24
	.uleb128 0x15
	.string	"t"
	.byte	0x7
	.value	0x46c
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x28
	.uleb128 0x15
	.string	"sp"
	.byte	0x7
	.value	0x46d
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x2c
	.byte	0x0
	.uleb128 0x16
	.long	.LASF218
	.byte	0x7
	.value	0x46e
	.long	0x1970
	.uleb128 0x11
	.long	.LASF222
	.byte	0x2c
	.byte	0x7
	.value	0x471
	.long	0x1ad2
	.uleb128 0x15
	.string	"i"
	.byte	0x7
	.value	0x472
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF223
	.byte	0x7
	.value	0x473
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x15
	.string	"x"
	.byte	0x7
	.value	0x474
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x15
	.string	"y"
	.byte	0x7
	.value	0x474
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x15
	.string	"z"
	.byte	0x7
	.value	0x474
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x10
	.uleb128 0x15
	.string	"v"
	.byte	0x7
	.value	0x474
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x14
	.uleb128 0x15
	.string	"w"
	.byte	0x7
	.value	0x474
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x18
	.uleb128 0x15
	.string	"u"
	.byte	0x7
	.value	0x474
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x1c
	.uleb128 0x15
	.string	"dt"
	.byte	0x7
	.value	0x475
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x20
	.uleb128 0x12
	.long	.LASF219
	.byte	0x7
	.value	0x476
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x24
	.uleb128 0x12
	.long	.LASF224
	.byte	0x7
	.value	0x477
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x28
	.byte	0x0
	.uleb128 0x16
	.long	.LASF222
	.byte	0x7
	.value	0x478
	.long	0x1a2e
	.uleb128 0x11
	.long	.LASF225
	.byte	0xc
	.byte	0x7
	.value	0x47b
	.long	0x1b17
	.uleb128 0x12
	.long	.LASF221
	.byte	0x7
	.value	0x47c
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x15
	.string	"i"
	.byte	0x7
	.value	0x47d
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF223
	.byte	0x7
	.value	0x47e
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.byte	0x0
	.uleb128 0x16
	.long	.LASF225
	.byte	0x7
	.value	0x47f
	.long	0x1ade
	.uleb128 0x6
	.byte	0x4
	.long	0x1a22
	.uleb128 0x14
	.long	.LASF226
	.value	0x635c
	.byte	0x7
	.value	0x49b
	.long	0x1c6a
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x49c
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x15
	.string	"id"
	.byte	0x7
	.value	0x49d
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.uleb128 0x12
	.long	.LASF227
	.byte	0x7
	.value	0x49e
	.long	0x2ba
	.byte	0x3
	.byte	0x23
	.uleb128 0x104
	.uleb128 0x15
	.string	"idx"
	.byte	0x7
	.value	0x49f
	.long	0x2ba
	.byte	0x3
	.byte	0x23
	.uleb128 0x108
	.uleb128 0x12
	.long	.LASF108
	.byte	0x7
	.value	0x4a0
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x10c
	.uleb128 0x12
	.long	.LASF228
	.byte	0x7
	.value	0x4a1
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x110
	.uleb128 0x12
	.long	.LASF229
	.byte	0x7
	.value	0x4a2
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x114
	.uleb128 0x12
	.long	.LASF193
	.byte	0x7
	.value	0x4a3
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x118
	.uleb128 0x12
	.long	.LASF230
	.byte	0x7
	.value	0x4a4
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x11c
	.uleb128 0x12
	.long	.LASF231
	.byte	0x7
	.value	0x4a5
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x120
	.uleb128 0x12
	.long	.LASF232
	.byte	0x7
	.value	0x4a6
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x124
	.uleb128 0x12
	.long	.LASF233
	.byte	0x7
	.value	0x4a7
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x128
	.uleb128 0x12
	.long	.LASF234
	.byte	0x7
	.value	0x4a8
	.long	0x596
	.byte	0x3
	.byte	0x23
	.uleb128 0x12c
	.uleb128 0x12
	.long	.LASF235
	.byte	0x7
	.value	0x4a9
	.long	0x596
	.byte	0x3
	.byte	0x23
	.uleb128 0x130
	.uleb128 0x12
	.long	.LASF236
	.byte	0x7
	.value	0x4aa
	.long	0x1c6a
	.byte	0x3
	.byte	0x23
	.uleb128 0x134
	.uleb128 0x12
	.long	.LASF237
	.byte	0x7
	.value	0x4ab
	.long	0x3b
	.byte	0x4
	.byte	0x23
	.uleb128 0x5ef4
	.uleb128 0x12
	.long	.LASF238
	.byte	0x7
	.value	0x4ac
	.long	0x1c7b
	.byte	0x4
	.byte	0x23
	.uleb128 0x5ef8
	.uleb128 0x12
	.long	.LASF239
	.byte	0x7
	.value	0x4ad
	.long	0x3b
	.byte	0x4
	.byte	0x23
	.uleb128 0x6268
	.uleb128 0x12
	.long	.LASF240
	.byte	0x7
	.value	0x4ae
	.long	0x1c8b
	.byte	0x4
	.byte	0x23
	.uleb128 0x626c
	.byte	0x0
	.uleb128 0x8
	.long	0x1a22
	.long	0x1c7b
	.uleb128 0x1a
	.long	0x50
	.value	0x1f3
	.byte	0x0
	.uleb128 0x8
	.long	0x1ad2
	.long	0x1c8b
	.uleb128 0x9
	.long	0x50
	.byte	0x13
	.byte	0x0
	.uleb128 0x8
	.long	0x1b17
	.long	0x1c9b
	.uleb128 0x9
	.long	0x50
	.byte	0x13
	.byte	0x0
	.uleb128 0x16
	.long	.LASF226
	.byte	0x7
	.value	0x4af
	.long	0x1b29
	.uleb128 0x6
	.byte	0x4
	.long	0x1c9b
	.uleb128 0x14
	.long	.LASF241
	.value	0x328
	.byte	0x7
	.value	0x4cd
	.long	0x1d2b
	.uleb128 0x12
	.long	.LASF168
	.byte	0x7
	.value	0x4ce
	.long	0x1253
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF242
	.byte	0x7
	.value	0x4cf
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x118
	.uleb128 0x12
	.long	.LASF243
	.byte	0x7
	.value	0x4d0
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x11c
	.uleb128 0x12
	.long	.LASF244
	.byte	0x7
	.value	0x4d1
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x120
	.uleb128 0x12
	.long	.LASF172
	.byte	0x7
	.value	0x4d2
	.long	0x1d2b
	.byte	0x3
	.byte	0x23
	.uleb128 0x220
	.uleb128 0x12
	.long	.LASF245
	.byte	0x7
	.value	0x4d3
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x224
	.uleb128 0x12
	.long	.LASF246
	.byte	0x7
	.value	0x4d4
	.long	0x1d31
	.byte	0x3
	.byte	0x23
	.uleb128 0x324
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x1797
	.uleb128 0x6
	.byte	0x4
	.long	0x185a
	.uleb128 0x16
	.long	.LASF241
	.byte	0x7
	.value	0x4d5
	.long	0x1cad
	.uleb128 0x14
	.long	.LASF247
	.value	0x65c
	.byte	0x7
	.value	0x4d8
	.long	0x1d9d
	.uleb128 0x12
	.long	.LASF192
	.byte	0x7
	.value	0x4d9
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF98
	.byte	0x7
	.value	0x4da
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF248
	.byte	0x7
	.value	0x4db
	.long	0x1d9d
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x12
	.long	.LASF249
	.byte	0x7
	.value	0x4dc
	.long	0x1d37
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x15
	.string	"to"
	.byte	0x7
	.value	0x4dd
	.long	0x1d37
	.byte	0x3
	.byte	0x23
	.uleb128 0x334
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x1665
	.uleb128 0x16
	.long	.LASF247
	.byte	0x7
	.value	0x4de
	.long	0x1d43
	.uleb128 0x14
	.long	.LASF250
	.value	0x764
	.byte	0x7
	.value	0x4e1
	.long	0x1dfd
	.uleb128 0x15
	.string	"key"
	.byte	0x7
	.value	0x4e2
	.long	0x1da3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF251
	.byte	0x7
	.value	0x4e3
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x65c
	.uleb128 0x12
	.long	.LASF252
	.byte	0x7
	.value	0x4e5
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x660
	.uleb128 0x12
	.long	.LASF253
	.byte	0x7
	.value	0x4e6
	.long	0x1e74
	.byte	0x3
	.byte	0x23
	.uleb128 0x760
	.byte	0x0
	.uleb128 0x11
	.long	.LASF254
	.byte	0x1c
	.byte	0x7
	.value	0x66e
	.long	0x1e74
	.uleb128 0x12
	.long	.LASF98
	.byte	0x7
	.value	0x66f
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF84
	.byte	0x7
	.value	0x670
	.long	0xd6
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF255
	.byte	0x7
	.value	0x671
	.long	0x1e74
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x12
	.long	.LASF256
	.byte	0x7
	.value	0x672
	.long	0x1e74
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x12
	.long	.LASF257
	.byte	0x7
	.value	0x673
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x10
	.uleb128 0x12
	.long	.LASF258
	.byte	0x7
	.value	0x674
	.long	0xd6
	.byte	0x2
	.byte	0x23
	.uleb128 0x14
	.uleb128 0x12
	.long	.LASF259
	.byte	0x7
	.value	0x675
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x18
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x1dfd
	.uleb128 0x16
	.long	.LASF250
	.byte	0x7
	.value	0x4e7
	.long	0x1daf
	.uleb128 0x14
	.long	.LASF260
	.value	0x6ac8
	.byte	0x7
	.value	0x4ea
	.long	0x1ed6
	.uleb128 0x12
	.long	.LASF261
	.byte	0x7
	.value	0x4eb
	.long	0x1e7a
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF262
	.byte	0x7
	.value	0x4ec
	.long	0x1c9b
	.byte	0x3
	.byte	0x23
	.uleb128 0x764
	.uleb128 0x12
	.long	.LASF263
	.byte	0x7
	.value	0x4ed
	.long	0x3b
	.byte	0x4
	.byte	0x23
	.uleb128 0x6ac0
	.uleb128 0x12
	.long	.LASF264
	.byte	0x7
	.value	0x4ee
	.long	0x1ed6
	.byte	0x4
	.byte	0x23
	.uleb128 0x6ac4
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x1e7a
	.uleb128 0x16
	.long	.LASF260
	.byte	0x7
	.value	0x4ef
	.long	0x1e86
	.uleb128 0x14
	.long	.LASF265
	.value	0x14c
	.byte	0x7
	.value	0x506
	.long	0x1f36
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x507
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF266
	.byte	0x7
	.value	0x508
	.long	0x1045
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.uleb128 0x12
	.long	.LASF267
	.byte	0x7
	.value	0x509
	.long	0x1045
	.byte	0x3
	.byte	0x23
	.uleb128 0x10c
	.uleb128 0x12
	.long	.LASF268
	.byte	0x7
	.value	0x50a
	.long	0x10ab
	.byte	0x3
	.byte	0x23
	.uleb128 0x118
	.byte	0x0
	.uleb128 0x16
	.long	.LASF265
	.byte	0x7
	.value	0x50b
	.long	0x1ee8
	.uleb128 0x14
	.long	.LASF269
	.value	0x894
	.byte	0x7
	.value	0x512
	.long	0x1fc0
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x513
	.long	0x16c1
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF117
	.byte	0x7
	.value	0x514
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x80
	.uleb128 0x12
	.long	.LASF270
	.byte	0x7
	.value	0x515
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x84
	.uleb128 0x12
	.long	.LASF271
	.byte	0x7
	.value	0x516
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x88
	.uleb128 0x12
	.long	.LASF272
	.byte	0x7
	.value	0x517
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x8c
	.uleb128 0x12
	.long	.LASF273
	.byte	0x7
	.value	0x518
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x90
	.uleb128 0x12
	.long	.LASF274
	.byte	0x7
	.value	0x519
	.long	0x1fc0
	.byte	0x3
	.byte	0x23
	.uleb128 0x94
	.byte	0x0
	.uleb128 0x8
	.long	0x65
	.long	0x1fd1
	.uleb128 0x1a
	.long	0x50
	.value	0x7ff
	.byte	0x0
	.uleb128 0x16
	.long	.LASF269
	.byte	0x7
	.value	0x51a
	.long	0x1f42
	.uleb128 0x14
	.long	.LASF275
	.value	0x19c
	.byte	0x7
	.value	0x51d
	.long	0x203a
	.uleb128 0x12
	.long	.LASF276
	.byte	0x7
	.value	0x51e
	.long	0x203a
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x51f
	.long	0x16c1
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF251
	.byte	0x7
	.value	0x520
	.long	0x16c1
	.byte	0x3
	.byte	0x23
	.uleb128 0x84
	.uleb128 0x12
	.long	.LASF277
	.byte	0x7
	.value	0x521
	.long	0x16c1
	.byte	0x3
	.byte	0x23
	.uleb128 0x104
	.uleb128 0x12
	.long	.LASF278
	.byte	0x7
	.value	0x522
	.long	0x133
	.byte	0x3
	.byte	0x23
	.uleb128 0x184
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x1fd1
	.uleb128 0x16
	.long	.LASF275
	.byte	0x7
	.value	0x523
	.long	0x1fdd
	.uleb128 0x14
	.long	.LASF279
	.value	0x110
	.byte	0x7
	.value	0x526
	.long	0x20b9
	.uleb128 0x12
	.long	.LASF276
	.byte	0x7
	.value	0x527
	.long	0x203a
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x528
	.long	0x16c1
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF280
	.byte	0x7
	.value	0x529
	.long	0x16c1
	.byte	0x3
	.byte	0x23
	.uleb128 0x84
	.uleb128 0x12
	.long	.LASF281
	.byte	0x7
	.value	0x52a
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x104
	.uleb128 0x12
	.long	.LASF84
	.byte	0x7
	.value	0x52b
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x108
	.uleb128 0x12
	.long	.LASF81
	.byte	0x7
	.value	0x52c
	.long	0x596
	.byte	0x3
	.byte	0x23
	.uleb128 0x10c
	.byte	0x0
	.uleb128 0x16
	.long	.LASF279
	.byte	0x7
	.value	0x52d
	.long	0x204c
	.uleb128 0x14
	.long	.LASF282
	.value	0x108
	.byte	0x7
	.value	0x53c
	.long	0x2146
	.uleb128 0x18
	.long	.LASF23
	.byte	0x4
	.byte	0x7
	.value	0x541
	.long	0x211d
	.uleb128 0x19
	.long	.LASF137
	.byte	0x7
	.value	0x542
	.long	0x2146
	.uleb128 0x19
	.long	.LASF283
	.byte	0x7
	.value	0x543
	.long	0x214c
	.uleb128 0x19
	.long	.LASF284
	.byte	0x7
	.value	0x544
	.long	0x2152
	.uleb128 0x19
	.long	.LASF285
	.byte	0x7
	.value	0x545
	.long	0x2158
	.uleb128 0x19
	.long	.LASF286
	.byte	0x7
	.value	0x546
	.long	0x215e
	.byte	0x0
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x53d
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF287
	.byte	0x7
	.value	0x53e
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.uleb128 0xf
	.long	0x20d3
	.byte	0x3
	.byte	0x23
	.uleb128 0x104
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0xc12
	.uleb128 0x6
	.byte	0x4
	.long	0x5b3
	.uleb128 0x6
	.byte	0x4
	.long	0xa57
	.uleb128 0x6
	.byte	0x4
	.long	0x848
	.uleb128 0x6
	.byte	0x4
	.long	0xe44
	.uleb128 0x16
	.long	.LASF282
	.byte	0x7
	.value	0x548
	.long	0x20c5
	.uleb128 0x11
	.long	.LASF288
	.byte	0xc
	.byte	0x7
	.value	0x54b
	.long	0x21ab
	.uleb128 0x12
	.long	.LASF98
	.byte	0x7
	.value	0x54c
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF84
	.byte	0x7
	.value	0x54d
	.long	0xd6
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF289
	.byte	0x7
	.value	0x54e
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.byte	0x0
	.uleb128 0x16
	.long	.LASF288
	.byte	0x7
	.value	0x54f
	.long	0x2170
	.uleb128 0x14
	.long	.LASF290
	.value	0x10c
	.byte	0x7
	.value	0x552
	.long	0x2205
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x553
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF291
	.byte	0x7
	.value	0x554
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.uleb128 0x12
	.long	.LASF292
	.byte	0x7
	.value	0x555
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x104
	.uleb128 0x15
	.string	"prg"
	.byte	0x7
	.value	0x556
	.long	0x2205
	.byte	0x3
	.byte	0x23
	.uleb128 0x108
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x21ab
	.uleb128 0x16
	.long	.LASF290
	.byte	0x7
	.value	0x557
	.long	0x21b7
	.uleb128 0x14
	.long	.LASF293
	.value	0x104
	.byte	0x7
	.value	0x55a
	.long	0x2245
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x55b
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF294
	.byte	0x7
	.value	0x55c
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.byte	0x0
	.uleb128 0x16
	.long	.LASF293
	.byte	0x7
	.value	0x55d
	.long	0x2217
	.uleb128 0x11
	.long	.LASF295
	.byte	0x44
	.byte	0x7
	.value	0x560
	.long	0x235e
	.uleb128 0x12
	.long	.LASF296
	.byte	0x7
	.value	0x561
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF297
	.byte	0x7
	.value	0x562
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF298
	.byte	0x7
	.value	0x563
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x12
	.long	.LASF299
	.byte	0x7
	.value	0x564
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x15
	.string	"sum"
	.byte	0x7
	.value	0x565
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x10
	.uleb128 0x12
	.long	.LASF300
	.byte	0x7
	.value	0x566
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x14
	.uleb128 0x12
	.long	.LASF108
	.byte	0x7
	.value	0x567
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x18
	.uleb128 0x15
	.string	"min"
	.byte	0x7
	.value	0x568
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x1c
	.uleb128 0x15
	.string	"max"
	.byte	0x7
	.value	0x569
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x20
	.uleb128 0x12
	.long	.LASF172
	.byte	0x7
	.value	0x56a
	.long	0x18ce
	.byte	0x2
	.byte	0x23
	.uleb128 0x24
	.uleb128 0x12
	.long	.LASF301
	.byte	0x7
	.value	0x56b
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x28
	.uleb128 0x12
	.long	.LASF302
	.byte	0x7
	.value	0x56c
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x2c
	.uleb128 0x12
	.long	.LASF303
	.byte	0x7
	.value	0x56d
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x30
	.uleb128 0x12
	.long	.LASF304
	.byte	0x7
	.value	0x56e
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x34
	.uleb128 0x12
	.long	.LASF305
	.byte	0x7
	.value	0x56f
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x38
	.uleb128 0x12
	.long	.LASF306
	.byte	0x7
	.value	0x570
	.long	0x235e
	.byte	0x2
	.byte	0x23
	.uleb128 0x3c
	.uleb128 0x12
	.long	.LASF307
	.byte	0x7
	.value	0x571
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x40
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x596
	.uleb128 0x16
	.long	.LASF295
	.byte	0x7
	.value	0x572
	.long	0x2251
	.uleb128 0x14
	.long	.LASF308
	.value	0x330
	.byte	0x7
	.value	0x575
	.long	0x246e
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x576
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF98
	.byte	0x7
	.value	0x577
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.uleb128 0x12
	.long	.LASF281
	.byte	0x7
	.value	0x578
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x104
	.uleb128 0x12
	.long	.LASF84
	.byte	0x7
	.value	0x579
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x108
	.uleb128 0x12
	.long	.LASF81
	.byte	0x7
	.value	0x57a
	.long	0x596
	.byte	0x3
	.byte	0x23
	.uleb128 0x10c
	.uleb128 0x12
	.long	.LASF309
	.byte	0x7
	.value	0x57b
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x110
	.uleb128 0x12
	.long	.LASF280
	.byte	0x7
	.value	0x57c
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x210
	.uleb128 0x12
	.long	.LASF178
	.byte	0x7
	.value	0x57e
	.long	0x246e
	.byte	0x3
	.byte	0x23
	.uleb128 0x310
	.uleb128 0x12
	.long	.LASF264
	.byte	0x7
	.value	0x57f
	.long	0x1ed6
	.byte	0x3
	.byte	0x23
	.uleb128 0x314
	.uleb128 0x12
	.long	.LASF168
	.byte	0x7
	.value	0x580
	.long	0x2474
	.byte	0x3
	.byte	0x23
	.uleb128 0x318
	.uleb128 0x12
	.long	.LASF172
	.byte	0x7
	.value	0x581
	.long	0x1d2b
	.byte	0x3
	.byte	0x23
	.uleb128 0x31c
	.uleb128 0x12
	.long	.LASF246
	.byte	0x7
	.value	0x582
	.long	0x1d31
	.byte	0x3
	.byte	0x23
	.uleb128 0x320
	.uleb128 0x12
	.long	.LASF310
	.byte	0x7
	.value	0x583
	.long	0x247a
	.byte	0x3
	.byte	0x23
	.uleb128 0x324
	.uleb128 0x12
	.long	.LASF311
	.byte	0x7
	.value	0x584
	.long	0x2480
	.byte	0x3
	.byte	0x23
	.uleb128 0x328
	.uleb128 0x12
	.long	.LASF312
	.byte	0x7
	.value	0x585
	.long	0x2486
	.byte	0x3
	.byte	0x23
	.uleb128 0x32c
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x2364
	.uleb128 0x6
	.byte	0x4
	.long	0x1253
	.uleb128 0x6
	.byte	0x4
	.long	0x1964
	.uleb128 0x6
	.byte	0x4
	.long	0x2370
	.uleb128 0x6
	.byte	0x4
	.long	0x20b9
	.uleb128 0x16
	.long	.LASF308
	.byte	0x7
	.value	0x586
	.long	0x2370
	.uleb128 0x14
	.long	.LASF313
	.value	0x204
	.byte	0x7
	.value	0x589
	.long	0x24d5
	.uleb128 0x12
	.long	.LASF314
	.byte	0x7
	.value	0x58a
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF315
	.byte	0x7
	.value	0x58b
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x58c
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x104
	.byte	0x0
	.uleb128 0x16
	.long	.LASF313
	.byte	0x7
	.value	0x58d
	.long	0x2498
	.uleb128 0x14
	.long	.LASF316
	.value	0x2b0
	.byte	0x7
	.value	0x590
	.long	0x26ad
	.uleb128 0x12
	.long	.LASF317
	.byte	0x7
	.value	0x591
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF98
	.byte	0x7
	.value	0x592
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF116
	.byte	0x7
	.value	0x593
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x594
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x108
	.uleb128 0x12
	.long	.LASF318
	.byte	0x7
	.value	0x597
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x208
	.uleb128 0x12
	.long	.LASF319
	.byte	0x7
	.value	0x599
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x20c
	.uleb128 0x12
	.long	.LASF320
	.byte	0x7
	.value	0x59a
	.long	0xde
	.byte	0x3
	.byte	0x23
	.uleb128 0x210
	.uleb128 0x12
	.long	.LASF321
	.byte	0x7
	.value	0x59c
	.long	0x2ba
	.byte	0x3
	.byte	0x23
	.uleb128 0x218
	.uleb128 0x12
	.long	.LASF322
	.byte	0x7
	.value	0x59d
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x21c
	.uleb128 0x12
	.long	.LASF323
	.byte	0x7
	.value	0x59e
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x220
	.uleb128 0x12
	.long	.LASF324
	.byte	0x7
	.value	0x59f
	.long	0x2ba
	.byte	0x3
	.byte	0x23
	.uleb128 0x224
	.uleb128 0x12
	.long	.LASF325
	.byte	0x7
	.value	0x5a0
	.long	0x1ef
	.byte	0x3
	.byte	0x23
	.uleb128 0x228
	.uleb128 0x12
	.long	.LASF326
	.byte	0x7
	.value	0x5a1
	.long	0x133
	.byte	0x3
	.byte	0x23
	.uleb128 0x258
	.uleb128 0x12
	.long	.LASF327
	.byte	0x7
	.value	0x5a2
	.long	0xde
	.byte	0x3
	.byte	0x23
	.uleb128 0x270
	.uleb128 0x12
	.long	.LASF328
	.byte	0x7
	.value	0x5a3
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x278
	.uleb128 0x12
	.long	.LASF329
	.byte	0x7
	.value	0x5a4
	.long	0x26ad
	.byte	0x3
	.byte	0x23
	.uleb128 0x27c
	.uleb128 0x12
	.long	.LASF330
	.byte	0x7
	.value	0x5a5
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x280
	.uleb128 0x12
	.long	.LASF251
	.byte	0x7
	.value	0x5a6
	.long	0x26b3
	.byte	0x3
	.byte	0x23
	.uleb128 0x284
	.uleb128 0x12
	.long	.LASF331
	.byte	0x7
	.value	0x5a7
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x288
	.uleb128 0x12
	.long	.LASF170
	.byte	0x7
	.value	0x5a8
	.long	0x26ad
	.byte	0x3
	.byte	0x23
	.uleb128 0x28c
	.uleb128 0x12
	.long	.LASF332
	.byte	0x7
	.value	0x5a9
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x290
	.uleb128 0x12
	.long	.LASF294
	.byte	0x7
	.value	0x5aa
	.long	0x26b9
	.byte	0x3
	.byte	0x23
	.uleb128 0x294
	.uleb128 0x12
	.long	.LASF333
	.byte	0x7
	.value	0x5ab
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x298
	.uleb128 0x12
	.long	.LASF334
	.byte	0x7
	.value	0x5ac
	.long	0x26bf
	.byte	0x3
	.byte	0x23
	.uleb128 0x29c
	.uleb128 0x12
	.long	.LASF335
	.byte	0x7
	.value	0x5ad
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x2a0
	.uleb128 0x12
	.long	.LASF336
	.byte	0x7
	.value	0x5ae
	.long	0x26bf
	.byte	0x3
	.byte	0x23
	.uleb128 0x2a4
	.uleb128 0x12
	.long	.LASF337
	.byte	0x7
	.value	0x5af
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x2a8
	.uleb128 0x12
	.long	.LASF280
	.byte	0x7
	.value	0x5b0
	.long	0x26c5
	.byte	0x3
	.byte	0x23
	.uleb128 0x2ac
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x248c
	.uleb128 0x6
	.byte	0x4
	.long	0x220b
	.uleb128 0x6
	.byte	0x4
	.long	0x2245
	.uleb128 0x6
	.byte	0x4
	.long	0x2164
	.uleb128 0x6
	.byte	0x4
	.long	0x24d5
	.uleb128 0x16
	.long	.LASF316
	.byte	0x7
	.value	0x5b1
	.long	0x24e1
	.uleb128 0x14
	.long	.LASF338
	.value	0x230
	.byte	0x7
	.value	0x5b7
	.long	0x2734
	.uleb128 0x12
	.long	.LASF339
	.byte	0x7
	.value	0x5b8
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF340
	.byte	0x7
	.value	0x5b9
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF341
	.byte	0x7
	.value	0x5ba
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x104
	.uleb128 0x12
	.long	.LASF342
	.byte	0x7
	.value	0x5bb
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x204
	.uleb128 0x12
	.long	.LASF343
	.byte	0x7
	.value	0x5bc
	.long	0x2734
	.byte	0x3
	.byte	0x23
	.uleb128 0x208
	.byte	0x0
	.uleb128 0x8
	.long	0x26ad
	.long	0x2744
	.uleb128 0x9
	.long	0x50
	.byte	0x9
	.byte	0x0
	.uleb128 0x16
	.long	.LASF338
	.byte	0x7
	.value	0x5bd
	.long	0x26d7
	.uleb128 0x14
	.long	.LASF344
	.value	0x4f18
	.byte	0x7
	.value	0x5c0
	.long	0x27ec
	.uleb128 0x12
	.long	.LASF98
	.byte	0x7
	.value	0x5c1
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF97
	.byte	0x7
	.value	0x5c2
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF99
	.byte	0x7
	.value	0x5c3
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x12
	.long	.LASF117
	.byte	0x7
	.value	0x5c4
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x108
	.uleb128 0x12
	.long	.LASF270
	.byte	0x7
	.value	0x5c5
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x10c
	.uleb128 0x12
	.long	.LASF273
	.byte	0x7
	.value	0x5c6
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x110
	.uleb128 0x12
	.long	.LASF274
	.byte	0x7
	.value	0x5c7
	.long	0x1fc0
	.byte	0x3
	.byte	0x23
	.uleb128 0x114
	.uleb128 0x12
	.long	.LASF345
	.byte	0x7
	.value	0x5c8
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x914
	.uleb128 0x12
	.long	.LASF346
	.byte	0x7
	.value	0x5c9
	.long	0x27ec
	.byte	0x3
	.byte	0x23
	.uleb128 0x918
	.byte	0x0
	.uleb128 0x8
	.long	0x2744
	.long	0x27fc
	.uleb128 0x9
	.long	0x50
	.byte	0x1f
	.byte	0x0
	.uleb128 0x16
	.long	.LASF344
	.byte	0x7
	.value	0x5ca
	.long	0x2750
	.uleb128 0x11
	.long	.LASF347
	.byte	0x10
	.byte	0x7
	.value	0x5cd
	.long	0x2852
	.uleb128 0x12
	.long	.LASF348
	.byte	0x7
	.value	0x5ce
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF349
	.byte	0x7
	.value	0x5cf
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF350
	.byte	0x7
	.value	0x5d0
	.long	0x2852
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x12
	.long	.LASF351
	.byte	0x7
	.value	0x5d1
	.long	0x2852
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x27fc
	.uleb128 0x16
	.long	.LASF347
	.byte	0x7
	.value	0x5d2
	.long	0x2808
	.uleb128 0x14
	.long	.LASF352
	.value	0x420
	.byte	0x7
	.value	0x5d8
	.long	0x28e1
	.uleb128 0x15
	.string	"cmd"
	.byte	0x7
	.value	0x5d9
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF172
	.byte	0x7
	.value	0x5da
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.uleb128 0x12
	.long	.LASF249
	.byte	0x7
	.value	0x5db
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x200
	.uleb128 0x15
	.string	"to"
	.byte	0x7
	.value	0x5dc
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x300
	.uleb128 0x12
	.long	.LASF204
	.byte	0x7
	.value	0x5dd
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x400
	.uleb128 0x15
	.string	"idx"
	.byte	0x7
	.value	0x5de
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x404
	.uleb128 0x15
	.string	"wcp"
	.byte	0x7
	.value	0x5df
	.long	0x1113
	.byte	0x3
	.byte	0x23
	.uleb128 0x408
	.byte	0x0
	.uleb128 0x16
	.long	.LASF352
	.byte	0x7
	.value	0x5e0
	.long	0x2864
	.uleb128 0x17
	.long	.LASF353
	.long	0x33a10
	.byte	0x7
	.value	0x5e9
	.long	0x295d
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x5ea
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF98
	.byte	0x7
	.value	0x5eb
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.uleb128 0x12
	.long	.LASF108
	.byte	0x7
	.value	0x5ed
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x104
	.uleb128 0x12
	.long	.LASF354
	.byte	0x7
	.value	0x5ee
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x108
	.uleb128 0x12
	.long	.LASF355
	.byte	0x7
	.value	0x5ef
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x10c
	.uleb128 0x12
	.long	.LASF172
	.byte	0x7
	.value	0x5f0
	.long	0x295d
	.byte	0x3
	.byte	0x23
	.uleb128 0x110
	.byte	0x0
	.uleb128 0x8
	.long	0x28e1
	.long	0x296d
	.uleb128 0x9
	.long	0x50
	.byte	0xc7
	.byte	0x0
	.uleb128 0x16
	.long	.LASF353
	.byte	0x7
	.value	0x5f1
	.long	0x28ed
	.uleb128 0x14
	.long	.LASF356
	.value	0xd50
	.byte	0x7
	.value	0x5f4
	.long	0x2baf
	.uleb128 0x14
	.long	.LASF34
	.value	0x118
	.byte	0x7
	.value	0x600
	.long	0x29ff
	.uleb128 0x12
	.long	.LASF357
	.byte	0x7
	.value	0x601
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF358
	.byte	0x7
	.value	0x602
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF359
	.byte	0x7
	.value	0x603
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x12
	.long	.LASF360
	.byte	0x7
	.value	0x604
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0x12
	.long	.LASF361
	.byte	0x7
	.value	0x605
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x10
	.uleb128 0x12
	.long	.LASF362
	.byte	0x7
	.value	0x606
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x14
	.uleb128 0x12
	.long	.LASF117
	.byte	0x7
	.value	0x607
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x18
	.byte	0x0
	.uleb128 0x12
	.long	.LASF363
	.byte	0x7
	.value	0x5f5
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF364
	.byte	0x7
	.value	0x5f6
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.uleb128 0x12
	.long	.LASF365
	.byte	0x7
	.value	0x5f7
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x200
	.uleb128 0x12
	.long	.LASF366
	.byte	0x7
	.value	0x5f8
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x300
	.uleb128 0x12
	.long	.LASF367
	.byte	0x7
	.value	0x5f9
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x400
	.uleb128 0x12
	.long	.LASF368
	.byte	0x7
	.value	0x5fa
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x500
	.uleb128 0x15
	.string	"nic"
	.byte	0x7
	.value	0x5fb
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x600
	.uleb128 0x12
	.long	.LASF252
	.byte	0x7
	.value	0x5fc
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x700
	.uleb128 0x12
	.long	.LASF369
	.byte	0x7
	.value	0x5fd
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x800
	.uleb128 0x15
	.string	"lag"
	.byte	0x7
	.value	0x5fe
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x804
	.uleb128 0x12
	.long	.LASF370
	.byte	0x7
	.value	0x608
	.long	0x2987
	.byte	0x3
	.byte	0x23
	.uleb128 0x808
	.uleb128 0x12
	.long	.LASF371
	.byte	0x7
	.value	0x609
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x920
	.uleb128 0x12
	.long	.LASF372
	.byte	0x7
	.value	0x60a
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0xa20
	.uleb128 0x12
	.long	.LASF373
	.byte	0x7
	.value	0x60b
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0xa24
	.uleb128 0x12
	.long	.LASF374
	.byte	0x7
	.value	0x60c
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0xa28
	.uleb128 0x12
	.long	.LASF375
	.byte	0x7
	.value	0x60d
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0xa2c
	.uleb128 0x12
	.long	.LASF376
	.byte	0x7
	.value	0x60e
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0xa30
	.uleb128 0x12
	.long	.LASF377
	.byte	0x7
	.value	0x60f
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0xa34
	.uleb128 0x12
	.long	.LASF202
	.byte	0x7
	.value	0x610
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0xa38
	.uleb128 0x12
	.long	.LASF378
	.byte	0x7
	.value	0x611
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0xb38
	.uleb128 0x12
	.long	.LASF379
	.byte	0x7
	.value	0x612
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0xc38
	.uleb128 0x12
	.long	.LASF380
	.byte	0x7
	.value	0x613
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0xc3c
	.uleb128 0x12
	.long	.LASF381
	.byte	0x7
	.value	0x614
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0xc40
	.uleb128 0x12
	.long	.LASF382
	.byte	0x7
	.value	0x615
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0xd40
	.uleb128 0x12
	.long	.LASF383
	.byte	0x7
	.value	0x616
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0xd44
	.uleb128 0x12
	.long	.LASF384
	.byte	0x7
	.value	0x617
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0xd48
	.uleb128 0x12
	.long	.LASF385
	.byte	0x7
	.value	0x618
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0xd4c
	.byte	0x0
	.uleb128 0x16
	.long	.LASF356
	.byte	0x7
	.value	0x619
	.long	0x2979
	.uleb128 0x14
	.long	.LASF386
	.value	0x118
	.byte	0x7
	.value	0x61e
	.long	0x2c2d
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x61f
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x15
	.string	"x"
	.byte	0x7
	.value	0x620
	.long	0x596
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.uleb128 0x15
	.string	"y"
	.byte	0x7
	.value	0x620
	.long	0x596
	.byte	0x3
	.byte	0x23
	.uleb128 0x104
	.uleb128 0x15
	.string	"z"
	.byte	0x7
	.value	0x620
	.long	0x596
	.byte	0x3
	.byte	0x23
	.uleb128 0x108
	.uleb128 0x15
	.string	"v"
	.byte	0x7
	.value	0x620
	.long	0x596
	.byte	0x3
	.byte	0x23
	.uleb128 0x10c
	.uleb128 0x15
	.string	"w"
	.byte	0x7
	.value	0x620
	.long	0x596
	.byte	0x3
	.byte	0x23
	.uleb128 0x110
	.uleb128 0x15
	.string	"u"
	.byte	0x7
	.value	0x620
	.long	0x596
	.byte	0x3
	.byte	0x23
	.uleb128 0x114
	.byte	0x0
	.uleb128 0x16
	.long	.LASF386
	.byte	0x7
	.value	0x621
	.long	0x2bbb
	.uleb128 0x14
	.long	.LASF387
	.value	0x114
	.byte	0x7
	.value	0x624
	.long	0x2c87
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x625
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x15
	.string	"dim"
	.byte	0x7
	.value	0x626
	.long	0x1045
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.uleb128 0x12
	.long	.LASF201
	.byte	0x7
	.value	0x627
	.long	0x596
	.byte	0x3
	.byte	0x23
	.uleb128 0x10c
	.uleb128 0x12
	.long	.LASF388
	.byte	0x7
	.value	0x628
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x110
	.byte	0x0
	.uleb128 0x16
	.long	.LASF387
	.byte	0x7
	.value	0x62c
	.long	0x2c39
	.uleb128 0x11
	.long	.LASF389
	.byte	0x38
	.byte	0x7
	.value	0x633
	.long	0x2cdd
	.uleb128 0x12
	.long	.LASF207
	.byte	0x7
	.value	0x634
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF390
	.byte	0x7
	.value	0x635
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF391
	.byte	0x7
	.value	0x636
	.long	0x2cdd
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x12
	.long	.LASF392
	.byte	0x7
	.value	0x637
	.long	0x2ced
	.byte	0x2
	.byte	0x23
	.uleb128 0x14
	.byte	0x0
	.uleb128 0x8
	.long	0x596
	.long	0x2ced
	.uleb128 0x9
	.long	0x50
	.byte	0x2
	.byte	0x0
	.uleb128 0x8
	.long	0x596
	.long	0x2d03
	.uleb128 0x9
	.long	0x50
	.byte	0x2
	.uleb128 0x9
	.long	0x50
	.byte	0x2
	.byte	0x0
	.uleb128 0x16
	.long	.LASF389
	.byte	0x7
	.value	0x638
	.long	0x2c93
	.uleb128 0x14
	.long	.LASF393
	.value	0x104
	.byte	0x7
	.value	0x63b
	.long	0x2d3c
	.uleb128 0x15
	.string	"idx"
	.byte	0x7
	.value	0x63c
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF394
	.byte	0x7
	.value	0x63d
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.byte	0x0
	.uleb128 0x16
	.long	.LASF393
	.byte	0x7
	.value	0x63e
	.long	0x2d0f
	.uleb128 0x17
	.long	.LASF395
	.long	0x3f8a4
	.byte	0x7
	.value	0x641
	.long	0x2d88
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x642
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF108
	.byte	0x7
	.value	0x643
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.uleb128 0x12
	.long	.LASF172
	.byte	0x7
	.value	0x644
	.long	0x2d88
	.byte	0x3
	.byte	0x23
	.uleb128 0x104
	.byte	0x0
	.uleb128 0x8
	.long	0x2d3c
	.long	0x2d99
	.uleb128 0x1a
	.long	0x50
	.value	0x3e7
	.byte	0x0
	.uleb128 0x16
	.long	.LASF395
	.byte	0x7
	.value	0x645
	.long	0x2d48
	.uleb128 0x17
	.long	.LASF396
	.long	0x17d3e0
	.byte	0x7
	.value	0x648
	.long	0x2de5
	.uleb128 0x12
	.long	.LASF397
	.byte	0x7
	.value	0x649
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF398
	.byte	0x7
	.value	0x64a
	.long	0x2de5
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF399
	.byte	0x7
	.value	0x64b
	.long	0x3b
	.byte	0x4
	.byte	0x23
	.uleb128 0x17d3dc
	.byte	0x0
	.uleb128 0x8
	.long	0x2d99
	.long	0x2df5
	.uleb128 0x9
	.long	0x50
	.byte	0x5
	.byte	0x0
	.uleb128 0x16
	.long	.LASF396
	.byte	0x7
	.value	0x64c
	.long	0x2da5
	.uleb128 0x14
	.long	.LASF400
	.value	0x204
	.byte	0x7
	.value	0x64f
	.long	0x2e3e
	.uleb128 0x15
	.string	"key"
	.byte	0x7
	.value	0x650
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF394
	.byte	0x7
	.value	0x651
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF401
	.byte	0x7
	.value	0x652
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x104
	.byte	0x0
	.uleb128 0x16
	.long	.LASF400
	.byte	0x7
	.value	0x653
	.long	0x2e01
	.uleb128 0x17
	.long	.LASF402
	.long	0x7e0a4
	.byte	0x7
	.value	0x656
	.long	0x2e8a
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x657
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF108
	.byte	0x7
	.value	0x658
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.uleb128 0x12
	.long	.LASF172
	.byte	0x7
	.value	0x659
	.long	0x2e8a
	.byte	0x3
	.byte	0x23
	.uleb128 0x104
	.byte	0x0
	.uleb128 0x8
	.long	0x2e3e
	.long	0x2e9b
	.uleb128 0x1a
	.long	0x50
	.value	0x3e7
	.byte	0x0
	.uleb128 0x16
	.long	.LASF402
	.byte	0x7
	.value	0x65a
	.long	0x2e4a
	.uleb128 0x17
	.long	.LASF403
	.long	0x2f43e0
	.byte	0x7
	.value	0x65d
	.long	0x2ee8
	.uleb128 0x12
	.long	.LASF404
	.byte	0x7
	.value	0x65e
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF405
	.byte	0x7
	.value	0x65f
	.long	0x2ee8
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0x12
	.long	.LASF406
	.byte	0x7
	.value	0x660
	.long	0x3b
	.byte	0x5
	.byte	0x23
	.uleb128 0x2f43dc
	.byte	0x0
	.uleb128 0x8
	.long	0x2e9b
	.long	0x2ef8
	.uleb128 0x9
	.long	0x50
	.byte	0x5
	.byte	0x0
	.uleb128 0x16
	.long	.LASF403
	.byte	0x7
	.value	0x661
	.long	0x2ea7
	.uleb128 0x14
	.long	.LASF407
	.value	0x100
	.byte	0x7
	.value	0x664
	.long	0x2f22
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x665
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.byte	0x0
	.uleb128 0x16
	.long	.LASF407
	.byte	0x7
	.value	0x666
	.long	0x2f04
	.uleb128 0x14
	.long	.LASF408
	.value	0xa04
	.byte	0x7
	.value	0x669
	.long	0x2f5b
	.uleb128 0x12
	.long	.LASF108
	.byte	0x7
	.value	0x66a
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF172
	.byte	0x7
	.value	0x66b
	.long	0x2f5b
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.byte	0x0
	.uleb128 0x8
	.long	0x2f22
	.long	0x2f6b
	.uleb128 0x9
	.long	0x50
	.byte	0x9
	.byte	0x0
	.uleb128 0x16
	.long	.LASF408
	.byte	0x7
	.value	0x66c
	.long	0x2f2e
	.uleb128 0x16
	.long	.LASF254
	.byte	0x7
	.value	0x676
	.long	0x1dfd
	.uleb128 0x14
	.long	.LASF409
	.value	0x5cd0
	.byte	0x7
	.value	0x679
	.long	0x3291
	.uleb128 0x12
	.long	.LASF410
	.byte	0x7
	.value	0x67a
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF411
	.byte	0x7
	.value	0x67b
	.long	0x596
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.uleb128 0x12
	.long	.LASF412
	.byte	0x7
	.value	0x67c
	.long	0x596
	.byte	0x3
	.byte	0x23
	.uleb128 0x104
	.uleb128 0x12
	.long	.LASF413
	.byte	0x7
	.value	0x67d
	.long	0x596
	.byte	0x3
	.byte	0x23
	.uleb128 0x108
	.uleb128 0x12
	.long	.LASF414
	.byte	0x7
	.value	0x67e
	.long	0x3291
	.byte	0x3
	.byte	0x23
	.uleb128 0x10c
	.uleb128 0x12
	.long	.LASF415
	.byte	0x7
	.value	0x67f
	.long	0x32a1
	.byte	0x3
	.byte	0x23
	.uleb128 0x224
	.uleb128 0x12
	.long	.LASF416
	.byte	0x7
	.value	0x680
	.long	0x13b9
	.byte	0x3
	.byte	0x23
	.uleb128 0x2cc
	.uleb128 0x12
	.long	.LASF417
	.byte	0x7
	.value	0x681
	.long	0x13b9
	.byte	0x3
	.byte	0x23
	.uleb128 0x2e4
	.uleb128 0x12
	.long	.LASF418
	.byte	0x7
	.value	0x682
	.long	0x13b9
	.byte	0x3
	.byte	0x23
	.uleb128 0x2fc
	.uleb128 0x12
	.long	.LASF419
	.byte	0x7
	.value	0x683
	.long	0x13b9
	.byte	0x3
	.byte	0x23
	.uleb128 0x314
	.uleb128 0x12
	.long	.LASF420
	.byte	0x7
	.value	0x684
	.long	0x13b9
	.byte	0x3
	.byte	0x23
	.uleb128 0x32c
	.uleb128 0x12
	.long	.LASF421
	.byte	0x7
	.value	0x685
	.long	0x13b9
	.byte	0x3
	.byte	0x23
	.uleb128 0x344
	.uleb128 0x12
	.long	.LASF422
	.byte	0x7
	.value	0x686
	.long	0x13b9
	.byte	0x3
	.byte	0x23
	.uleb128 0x35c
	.uleb128 0x12
	.long	.LASF423
	.byte	0x7
	.value	0x687
	.long	0x13b9
	.byte	0x3
	.byte	0x23
	.uleb128 0x374
	.uleb128 0x12
	.long	.LASF424
	.byte	0x7
	.value	0x688
	.long	0x13b9
	.byte	0x3
	.byte	0x23
	.uleb128 0x38c
	.uleb128 0x12
	.long	.LASF425
	.byte	0x7
	.value	0x68a
	.long	0x13b9
	.byte	0x3
	.byte	0x23
	.uleb128 0x3a4
	.uleb128 0x12
	.long	.LASF426
	.byte	0x7
	.value	0x68b
	.long	0x13b9
	.byte	0x3
	.byte	0x23
	.uleb128 0x3bc
	.uleb128 0x12
	.long	.LASF427
	.byte	0x7
	.value	0x68c
	.long	0x13b9
	.byte	0x3
	.byte	0x23
	.uleb128 0x3d4
	.uleb128 0x12
	.long	.LASF428
	.byte	0x7
	.value	0x68d
	.long	0x13b9
	.byte	0x3
	.byte	0x23
	.uleb128 0x3ec
	.uleb128 0x12
	.long	.LASF429
	.byte	0x7
	.value	0x68e
	.long	0x13b9
	.byte	0x3
	.byte	0x23
	.uleb128 0x404
	.uleb128 0x12
	.long	.LASF430
	.byte	0x7
	.value	0x68f
	.long	0x13b9
	.byte	0x3
	.byte	0x23
	.uleb128 0x41c
	.uleb128 0x12
	.long	.LASF431
	.byte	0x7
	.value	0x690
	.long	0x13b9
	.byte	0x3
	.byte	0x23
	.uleb128 0x434
	.uleb128 0x12
	.long	.LASF432
	.byte	0x7
	.value	0x691
	.long	0x13b9
	.byte	0x3
	.byte	0x23
	.uleb128 0x44c
	.uleb128 0x12
	.long	.LASF433
	.byte	0x7
	.value	0x692
	.long	0x13b9
	.byte	0x3
	.byte	0x23
	.uleb128 0x464
	.uleb128 0x12
	.long	.LASF434
	.byte	0x7
	.value	0x693
	.long	0x13b9
	.byte	0x3
	.byte	0x23
	.uleb128 0x47c
	.uleb128 0x12
	.long	.LASF435
	.byte	0x7
	.value	0x694
	.long	0x13b9
	.byte	0x3
	.byte	0x23
	.uleb128 0x494
	.uleb128 0x12
	.long	.LASF436
	.byte	0x7
	.value	0x695
	.long	0x13b9
	.byte	0x3
	.byte	0x23
	.uleb128 0x4ac
	.uleb128 0x12
	.long	.LASF437
	.byte	0x7
	.value	0x697
	.long	0x13b9
	.byte	0x3
	.byte	0x23
	.uleb128 0x4c4
	.uleb128 0x12
	.long	.LASF438
	.byte	0x7
	.value	0x698
	.long	0x13b9
	.byte	0x3
	.byte	0x23
	.uleb128 0x4dc
	.uleb128 0x12
	.long	.LASF439
	.byte	0x7
	.value	0x69a
	.long	0x1113
	.byte	0x3
	.byte	0x23
	.uleb128 0x4f4
	.uleb128 0x12
	.long	.LASF440
	.byte	0x7
	.value	0x69b
	.long	0x1113
	.byte	0x3
	.byte	0x23
	.uleb128 0x50c
	.uleb128 0x12
	.long	.LASF441
	.byte	0x7
	.value	0x69d
	.long	0x1113
	.byte	0x3
	.byte	0x23
	.uleb128 0x524
	.uleb128 0x12
	.long	.LASF442
	.byte	0x7
	.value	0x69f
	.long	0x1113
	.byte	0x3
	.byte	0x23
	.uleb128 0x53c
	.uleb128 0x12
	.long	.LASF443
	.byte	0x7
	.value	0x6a1
	.long	0x1387
	.byte	0x3
	.byte	0x23
	.uleb128 0x554
	.uleb128 0x12
	.long	.LASF444
	.byte	0x7
	.value	0x6a3
	.long	0x1387
	.byte	0x3
	.byte	0x23
	.uleb128 0x56c
	.uleb128 0x12
	.long	.LASF445
	.byte	0x7
	.value	0x6a5
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x584
	.uleb128 0x12
	.long	.LASF446
	.byte	0x7
	.value	0x6a6
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x588
	.uleb128 0x12
	.long	.LASF447
	.byte	0x7
	.value	0x6a7
	.long	0x32b1
	.byte	0x3
	.byte	0x23
	.uleb128 0x58c
	.uleb128 0x12
	.long	.LASF448
	.byte	0x7
	.value	0x6a9
	.long	0x1387
	.byte	0x3
	.byte	0x23
	.uleb128 0x8d4
	.uleb128 0x12
	.long	.LASF449
	.byte	0x7
	.value	0x6aa
	.long	0x1387
	.byte	0x3
	.byte	0x23
	.uleb128 0x8ec
	.uleb128 0x12
	.long	.LASF450
	.byte	0x7
	.value	0x6ab
	.long	0x13b9
	.byte	0x3
	.byte	0x23
	.uleb128 0x904
	.uleb128 0x12
	.long	.LASF451
	.byte	0x7
	.value	0x6ad
	.long	0x129c
	.byte	0x3
	.byte	0x23
	.uleb128 0x91c
	.uleb128 0x12
	.long	.LASF452
	.byte	0x7
	.value	0x6ae
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x29f0
	.uleb128 0x12
	.long	.LASF453
	.byte	0x7
	.value	0x6af
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x29f4
	.uleb128 0x12
	.long	.LASF454
	.byte	0x7
	.value	0x6b0
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x29f8
	.uleb128 0x12
	.long	.LASF455
	.byte	0x7
	.value	0x6b3
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x29fc
	.uleb128 0x12
	.long	.LASF233
	.byte	0x7
	.value	0x6b4
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x2a00
	.uleb128 0x12
	.long	.LASF456
	.byte	0x7
	.value	0x6b5
	.long	0x131f
	.byte	0x3
	.byte	0x23
	.uleb128 0x2a04
	.byte	0x0
	.uleb128 0x8
	.long	0x2d03
	.long	0x32a1
	.uleb128 0x9
	.long	0x50
	.byte	0x4
	.byte	0x0
	.uleb128 0x8
	.long	0x2d03
	.long	0x32b1
	.uleb128 0x9
	.long	0x50
	.byte	0x2
	.byte	0x0
	.uleb128 0x8
	.long	0x2c2d
	.long	0x32c1
	.uleb128 0x9
	.long	0x50
	.byte	0x2
	.byte	0x0
	.uleb128 0x16
	.long	.LASF409
	.byte	0x7
	.value	0x6b7
	.long	0x2f83
	.uleb128 0x14
	.long	.LASF457
	.value	0x5cd4
	.byte	0x7
	.value	0x6ba
	.long	0x32fa
	.uleb128 0x12
	.long	.LASF108
	.byte	0x7
	.value	0x6bb
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF366
	.byte	0x7
	.value	0x6bc
	.long	0x32fa
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.byte	0x0
	.uleb128 0x8
	.long	0x32c1
	.long	0x330a
	.uleb128 0x9
	.long	0x50
	.byte	0x0
	.byte	0x0
	.uleb128 0x16
	.long	.LASF457
	.byte	0x7
	.value	0x6bd
	.long	0x32cd
	.uleb128 0x17
	.long	.LASF458
	.long	0xa7f14
	.byte	0x7
	.value	0x6c0
	.long	0x3345
	.uleb128 0x12
	.long	.LASF108
	.byte	0x7
	.value	0x6c1
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF246
	.byte	0x7
	.value	0x6c2
	.long	0x3345
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.byte	0x0
	.uleb128 0x8
	.long	0x185a
	.long	0x3355
	.uleb128 0x9
	.long	0x50
	.byte	0xb
	.byte	0x0
	.uleb128 0x16
	.long	.LASF458
	.byte	0x7
	.value	0x6c3
	.long	0x3316
	.uleb128 0x11
	.long	.LASF459
	.byte	0x8
	.byte	0x7
	.value	0x6c6
	.long	0x338d
	.uleb128 0x12
	.long	.LASF108
	.byte	0x7
	.value	0x6c7
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF310
	.byte	0x7
	.value	0x6c8
	.long	0x247a
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.byte	0x0
	.uleb128 0x16
	.long	.LASF459
	.byte	0x7
	.value	0x6c9
	.long	0x3361
	.uleb128 0x14
	.long	.LASF460
	.value	0x1f6c
	.byte	0x7
	.value	0x6cc
	.long	0x33c6
	.uleb128 0x12
	.long	.LASF108
	.byte	0x7
	.value	0x6cd
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF172
	.byte	0x7
	.value	0x6ce
	.long	0x33c6
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.byte	0x0
	.uleb128 0x8
	.long	0x1797
	.long	0x33d6
	.uleb128 0x9
	.long	0x50
	.byte	0x9
	.byte	0x0
	.uleb128 0x16
	.long	.LASF460
	.byte	0x7
	.value	0x6cf
	.long	0x3399
	.uleb128 0x14
	.long	.LASF461
	.value	0x340
	.byte	0x7
	.value	0x6d2
	.long	0x340f
	.uleb128 0x12
	.long	.LASF108
	.byte	0x7
	.value	0x6d3
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF462
	.byte	0x7
	.value	0x6d4
	.long	0x340f
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.byte	0x0
	.uleb128 0x8
	.long	0x2c87
	.long	0x341f
	.uleb128 0x9
	.long	0x50
	.byte	0x2
	.byte	0x0
	.uleb128 0x16
	.long	.LASF461
	.byte	0x7
	.value	0x6d5
	.long	0x33e2
	.uleb128 0x14
	.long	.LASF463
	.value	0xcfc
	.byte	0x7
	.value	0x6d8
	.long	0x3458
	.uleb128 0x12
	.long	.LASF108
	.byte	0x7
	.value	0x6d9
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF464
	.byte	0x7
	.value	0x6da
	.long	0x3458
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.byte	0x0
	.uleb128 0x8
	.long	0x1f36
	.long	0x3468
	.uleb128 0x9
	.long	0x50
	.byte	0x9
	.byte	0x0
	.uleb128 0x16
	.long	.LASF463
	.byte	0x7
	.value	0x6db
	.long	0x342b
	.uleb128 0x17
	.long	.LASF465
	.long	0x2044a4
	.byte	0x7
	.value	0x6de
	.long	0x34a3
	.uleb128 0x12
	.long	.LASF108
	.byte	0x7
	.value	0x6df
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF466
	.byte	0x7
	.value	0x6e0
	.long	0x34a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.byte	0x0
	.uleb128 0x8
	.long	0x296d
	.long	0x34b3
	.uleb128 0x9
	.long	0x50
	.byte	0x9
	.byte	0x0
	.uleb128 0x16
	.long	.LASF465
	.byte	0x7
	.value	0x6e1
	.long	0x3474
	.uleb128 0x11
	.long	.LASF467
	.byte	0x8
	.byte	0x7
	.value	0x6e4
	.long	0x34eb
	.uleb128 0x12
	.long	.LASF108
	.byte	0x7
	.value	0x6e5
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF468
	.byte	0x7
	.value	0x6e6
	.long	0x34eb
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x26cb
	.uleb128 0x16
	.long	.LASF467
	.byte	0x7
	.value	0x6e7
	.long	0x34bf
	.uleb128 0x14
	.long	.LASF469
	.value	0xa0f4
	.byte	0x7
	.value	0x6ea
	.long	0x352a
	.uleb128 0x12
	.long	.LASF108
	.byte	0x7
	.value	0x6eb
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF470
	.byte	0x7
	.value	0x6ec
	.long	0x352a
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.byte	0x0
	.uleb128 0x8
	.long	0x2040
	.long	0x353a
	.uleb128 0x9
	.long	0x50
	.byte	0x63
	.byte	0x0
	.uleb128 0x16
	.long	.LASF469
	.byte	0x7
	.value	0x6ed
	.long	0x34fd
	.uleb128 0x14
	.long	.LASF471
	.value	0x6a44
	.byte	0x7
	.value	0x6f0
	.long	0x3573
	.uleb128 0x12
	.long	.LASF108
	.byte	0x7
	.value	0x6f1
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF472
	.byte	0x7
	.value	0x6f2
	.long	0x3573
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.byte	0x0
	.uleb128 0x8
	.long	0x20b9
	.long	0x3583
	.uleb128 0x9
	.long	0x50
	.byte	0x63
	.byte	0x0
	.uleb128 0x16
	.long	.LASF471
	.byte	0x7
	.value	0x6f3
	.long	0x3546
	.uleb128 0x14
	.long	.LASF473
	.value	0x2ae8
	.byte	0x7
	.value	0x6f6
	.long	0x35bc
	.uleb128 0x12
	.long	.LASF108
	.byte	0x7
	.value	0x6f7
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF276
	.byte	0x7
	.value	0x6f8
	.long	0x35bc
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.byte	0x0
	.uleb128 0x8
	.long	0x1fd1
	.long	0x35cc
	.uleb128 0x9
	.long	0x50
	.byte	0x4
	.byte	0x0
	.uleb128 0x16
	.long	.LASF473
	.byte	0x7
	.value	0x6f9
	.long	0x358f
	.uleb128 0x17
	.long	.LASF474
	.long	0x7af638
	.byte	0x7
	.value	0x6fc
	.long	0x3792
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x6fd
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF116
	.byte	0x7
	.value	0x6fe
	.long	0x5a3
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.uleb128 0x12
	.long	.LASF475
	.byte	0x7
	.value	0x6ff
	.long	0x2ef8
	.byte	0x3
	.byte	0x23
	.uleb128 0x200
	.uleb128 0x12
	.long	.LASF476
	.byte	0x7
	.value	0x700
	.long	0x330a
	.byte	0x5
	.byte	0x23
	.uleb128 0x2f45e0
	.uleb128 0x12
	.long	.LASF477
	.byte	0x7
	.value	0x701
	.long	0x3355
	.byte	0x5
	.byte	0x23
	.uleb128 0x2fa2b4
	.uleb128 0x12
	.long	.LASF478
	.byte	0x7
	.value	0x702
	.long	0x338d
	.byte	0x5
	.byte	0x23
	.uleb128 0x3a21c8
	.uleb128 0x12
	.long	.LASF479
	.byte	0x7
	.value	0x703
	.long	0x341f
	.byte	0x5
	.byte	0x23
	.uleb128 0x3a21d0
	.uleb128 0x12
	.long	.LASF217
	.byte	0x7
	.value	0x704
	.long	0x33d6
	.byte	0x5
	.byte	0x23
	.uleb128 0x3a2510
	.uleb128 0x12
	.long	.LASF480
	.byte	0x7
	.value	0x705
	.long	0x3468
	.byte	0x5
	.byte	0x23
	.uleb128 0x3a447c
	.uleb128 0x12
	.long	.LASF481
	.byte	0x7
	.value	0x706
	.long	0x34b3
	.byte	0x5
	.byte	0x23
	.uleb128 0x3a5178
	.uleb128 0x12
	.long	.LASF248
	.byte	0x7
	.value	0x707
	.long	0x16e1
	.byte	0x5
	.byte	0x23
	.uleb128 0x5a961c
	.uleb128 0x12
	.long	.LASF482
	.byte	0x7
	.value	0x708
	.long	0x34f1
	.byte	0x5
	.byte	0x23
	.uleb128 0x613ec0
	.uleb128 0x12
	.long	.LASF483
	.byte	0x7
	.value	0x709
	.long	0x353a
	.byte	0x5
	.byte	0x23
	.uleb128 0x613ec8
	.uleb128 0x12
	.long	.LASF484
	.byte	0x7
	.value	0x70a
	.long	0x3583
	.byte	0x5
	.byte	0x23
	.uleb128 0x61dfbc
	.uleb128 0x12
	.long	.LASF485
	.byte	0x7
	.value	0x70b
	.long	0x35cc
	.byte	0x5
	.byte	0x23
	.uleb128 0x624a00
	.uleb128 0x12
	.long	.LASF486
	.byte	0x7
	.value	0x70c
	.long	0x2858
	.byte	0x5
	.byte	0x23
	.uleb128 0x6274e8
	.uleb128 0x12
	.long	.LASF487
	.byte	0x7
	.value	0x70d
	.long	0xdf5
	.byte	0x5
	.byte	0x23
	.uleb128 0x6274f8
	.uleb128 0x12
	.long	.LASF488
	.byte	0x7
	.value	0x70e
	.long	0x796
	.byte	0x5
	.byte	0x23
	.uleb128 0x62c9a8
	.uleb128 0x12
	.long	.LASF489
	.byte	0x7
	.value	0x70f
	.long	0xb49
	.byte	0x5
	.byte	0x23
	.uleb128 0x62d434
	.uleb128 0x12
	.long	.LASF490
	.byte	0x7
	.value	0x710
	.long	0x9f0
	.byte	0x5
	.byte	0x23
	.uleb128 0x630994
	.uleb128 0x12
	.long	.LASF491
	.byte	0x7
	.value	0x711
	.long	0xfe4
	.byte	0x5
	.byte	0x23
	.uleb128 0x6312e8
	.uleb128 0x12
	.long	.LASF492
	.byte	0x7
	.value	0x712
	.long	0x2f6b
	.byte	0x5
	.byte	0x23
	.uleb128 0x631850
	.uleb128 0x12
	.long	.LASF493
	.byte	0x7
	.value	0x713
	.long	0x2df5
	.byte	0x5
	.byte	0x23
	.uleb128 0x632254
	.uleb128 0x12
	.long	.LASF494
	.byte	0x7
	.value	0x716
	.long	0x3792
	.byte	0x5
	.byte	0x23
	.uleb128 0x7af634
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x3798
	.uleb128 0x10
	.long	0x2f77
	.uleb128 0x16
	.long	.LASF474
	.byte	0x7
	.value	0x71d
	.long	0x35d8
	.uleb128 0x14
	.long	.LASF495
	.value	0x108
	.byte	0x7
	.value	0x7ba
	.long	0x37e7
	.uleb128 0x12
	.long	.LASF107
	.byte	0x7
	.value	0x7bb
	.long	0x5a3
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x15
	.string	"idx"
	.byte	0x7
	.value	0x7bc
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x100
	.uleb128 0x12
	.long	.LASF232
	.byte	0x7
	.value	0x7bc
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x104
	.byte	0x0
	.uleb128 0x14
	.long	.LASF496
	.value	0x6360
	.byte	0x7
	.value	0x7bf
	.long	0x3816
	.uleb128 0x12
	.long	.LASF497
	.byte	0x7
	.value	0x7c0
	.long	0x1c9b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x12
	.long	.LASF253
	.byte	0x7
	.value	0x7c1
	.long	0x1e74
	.byte	0x4
	.byte	0x23
	.uleb128 0x635c
	.byte	0x0
	.uleb128 0x16
	.long	.LASF496
	.byte	0x7
	.value	0x7c2
	.long	0x37e7
	.uleb128 0x11
	.long	.LASF498
	.byte	0x98
	.byte	0x7
	.value	0x7c4
	.long	0x3879
	.uleb128 0x15
	.string	"fp"
	.byte	0x7
	.value	0x7c5
	.long	0x1a22
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x15
	.string	"p"
	.byte	0x7
	.value	0x7c6
	.long	0x1a22
	.byte	0x2
	.byte	0x23
	.uleb128 0x30
	.uleb128 0x15
	.string	"pp"
	.byte	0x7
	.value	0x7c8
	.long	0x1a22
	.byte	0x2
	.byte	0x23
	.uleb128 0x60
	.uleb128 0x12
	.long	.LASF499
	.byte	0x7
	.value	0x7c9
	.long	0x3b
	.byte	0x3
	.byte	0x23
	.uleb128 0x90
	.uleb128 0x12
	.long	.LASF264
	.byte	0x7
	.value	0x7ca
	.long	0x3879
	.byte	0x3
	.byte	0x23
	.uleb128 0x94
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x3816
	.uleb128 0x16
	.long	.LASF498
	.byte	0x7
	.value	0x7cb
	.long	0x3822
	.uleb128 0x6
	.byte	0x4
	.long	0x2f77
	.uleb128 0xb
	.long	.LASF500
	.byte	0x20
	.byte	0x8
	.byte	0x24
	.long	0x390e
	.uleb128 0xc
	.long	.LASF98
	.byte	0x8
	.byte	0x25
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0xc
	.long	.LASF501
	.byte	0x8
	.byte	0x26
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x4
	.uleb128 0xc
	.long	.LASF502
	.byte	0x8
	.byte	0x27
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0xc
	.long	.LASF503
	.byte	0x8
	.byte	0x28
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0xc
	.uleb128 0xc
	.long	.LASF207
	.byte	0x8
	.byte	0x29
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x10
	.uleb128 0xc
	.long	.LASF504
	.byte	0x8
	.byte	0x2a
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x14
	.uleb128 0xc
	.long	.LASF223
	.byte	0x8
	.byte	0x2b
	.long	0x596
	.byte	0x2
	.byte	0x23
	.uleb128 0x18
	.uleb128 0xc
	.long	.LASF221
	.byte	0x8
	.byte	0x2c
	.long	0x3b
	.byte	0x2
	.byte	0x23
	.uleb128 0x1c
	.byte	0x0
	.uleb128 0x2
	.long	.LASF500
	.byte	0x8
	.byte	0x2d
	.long	0x3891
	.uleb128 0xb
	.long	.LASF505
	.byte	0x28
	.byte	0x9
	.byte	0x19
	.long	0x3962
	.uleb128 0x1b
	.string	"a"
	.byte	0x9
	.byte	0x1a
	.long	0x4f7
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x1b
	.string	"b"
	.byte	0x9
	.byte	0x1a
	.long	0x4f7
	.byte	0x2
	.byte	0x23
	.uleb128 0x8
	.uleb128 0x1b
	.string	"c"
	.byte	0x9
	.byte	0x1a
	.long	0x4f7
	.byte	0x2
	.byte	0x23
	.uleb128 0x10
	.uleb128 0x1b
	.string	"d"
	.byte	0x9
	.byte	0x1a
	.long	0x4f7
	.byte	0x2
	.byte	0x23
	.uleb128 0x18
	.uleb128 0x1b
	.string	"e"
	.byte	0x9
	.byte	0x1a
	.long	0x4f7
	.byte	0x2
	.byte	0x23
	.uleb128 0x20
	.byte	0x0
	.uleb128 0x2
	.long	.LASF505
	.byte	0x9
	.byte	0x1b
	.long	0x3919
	.uleb128 0xd
	.long	.LASF506
	.byte	0x28
	.byte	0x9
	.byte	0x1e
	.long	0x3990
	.uleb128 0xe
	.long	.LASF107
	.byte	0x9
	.byte	0x1f
	.long	0x3962
	.uleb128 0xe
	.long	.LASF175
	.byte	0x9
	.byte	0x20
	.long	0x3990
	.byte	0x0
	.uleb128 0x8
	.long	0x4f7
	.long	0x39a0
	.uleb128 0x9
	.long	0x50
	.byte	0x4
	.byte	0x0
	.uleb128 0x2
	.long	.LASF506
	.byte	0x9
	.byte	0x21
	.long	0x396d
	.uleb128 0x1c
	.long	.LASF507
	.value	0x190
	.byte	0x9
	.byte	0x25
	.long	0x39d6
	.uleb128 0x1b
	.string	"pos"
	.byte	0x9
	.byte	0x26
	.long	0x39d6
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x1b
	.string	"vel"
	.byte	0x9
	.byte	0x27
	.long	0x39d6
	.byte	0x3
	.byte	0x23
	.uleb128 0xc8
	.byte	0x0
	.uleb128 0x8
	.long	0x39a0
	.long	0x39e6
	.uleb128 0x9
	.long	0x50
	.byte	0x4
	.byte	0x0
	.uleb128 0x2
	.long	.LASF507
	.byte	0x9
	.byte	0x28
	.long	0x39ab
	.uleb128 0x1c
	.long	.LASF508
	.value	0x280
	.byte	0x9
	.byte	0x2b
	.long	0x3a36
	.uleb128 0x1b
	.string	"a0"
	.byte	0x9
	.byte	0x2c
	.long	0x3a36
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.uleb128 0x1b
	.string	"a1"
	.byte	0x9
	.byte	0x2d
	.long	0x3a36
	.byte	0x3
	.byte	0x23
	.uleb128 0xa0
	.uleb128 0x1b
	.string	"a2"
	.byte	0x9
	.byte	0x2e
	.long	0x3a36
	.byte	0x3
	.byte	0x23
	.uleb128 0x140
	.uleb128 0x1b
	.string	"a3"
	.byte	0x9
	.byte	0x2f
	.long	0x3a36
	.byte	0x3
	.byte	0x23
	.uleb128 0x1e0
	.byte	0x0
	.uleb128 0x8
	.long	0x39a0
	.long	0x3a46
	.uleb128 0x9
	.long	0x50
	.byte	0x3
	.byte	0x0
	.uleb128 0x2
	.long	.LASF508
	.byte	0x9
	.byte	0x30
	.long	0x39f1
	.uleb128 0x1d
	.long	.LASF763
	.value	0x490
	.byte	0x9
	.byte	0x33
	.long	0x3c83
	.uleb128 0x1e
	.long	.LASF509
	.byte	0x9
	.byte	0x35
	.long	0x39e6
	.byte	0x2
	.byte	0x23
	.uleb128 0x0
	.byte	0x3
	.uleb128 0x1e
	.long	.LASF510
	.byte	0x9
	.byte	0x36
	.long	0x39a0
	.byte	0x3
	.byte	0x23
	.uleb128 0x190
	.byte	0x3
	.uleb128 0x1e
	.long	.LASF511
	.byte	0x9
	.byte	0x37
	.long	0x39a0
	.byte	0x3
	.byte	0x23
	.uleb128 0x1b8
	.byte	0x3
	.uleb128 0x1e
	.long	.LASF512
	.byte	0x9
	.byte	0x38
	.long	0x3990
	.byte	0x3
	.byte	0x23
	.uleb128 0x1e0
	.byte	0x3
	.uleb128 0x1e
	.long	.LASF513
	.byte	0x9
	.byte	0x39
	.long	0x4f7
	.byte	0x3
	.byte	0x23
	.uleb128 0x208
	.byte	0x3
	.uleb128 0x1f
	.string	"kf"
	.byte	0x9
	.byte	0x3a
	.long	0x3a46
	.byte	0x3
	.byte	0x23
	.uleb128 0x210
	.byte	0x3
	.uleb128 0x20
	.byte	0x1
	.long	.LASF518
	.byte	0x9
	.byte	0x3b
	.long	.LASF520
	.byte	0x3
	.byte	0x1
	.long	0x3ae4
	.uleb128 0x21
	.long	0x3c83
	.byte	0x1
	.uleb128 0x22
	.long	0x3c89
	.uleb128 0x22
	.long	0x3c94
	.uleb128 0x22
	.long	0x3b
	.byte	0x0
	.uleb128 0x23
	.byte	0x1
	.long	.LASF514
	.byte	0x9
	.byte	0x3c
	.long	.LASF516
	.long	0x4f7
	.byte	0x3
	.byte	0x1
	.long	0x3b0b
	.uleb128 0x21
	.long	0x3c83
	.byte	0x1
	.uleb128 0x22
	.long	0x3c89
	.uleb128 0x22
	.long	0x3b
	.byte	0x0
	.uleb128 0x23
	.byte	0x1
	.long	.LASF515
	.byte	0x9
	.byte	0x3d
	.long	.LASF517
	.long	0x4f7
	.byte	0x3
	.byte	0x1
	.long	0x3b37
	.uleb128 0x21
	.long	0x3c83
	.byte	0x1
	.uleb128 0x22
	.long	0x3c89
	.uleb128 0x22
	.long	0x3c9a
	.uleb128 0x22
	.long	0x3b
	.byte	0x0
	.uleb128 0x20
	.byte	0x1
	.long	.LASF519
	.byte	0x9
	.byte	0x3e
	.long	.LASF521
	.byte	0x3
	.byte	0x1
	.long	0x3b50
	.uleb128 0x21
	.long	0x3c83
	.byte	0x1
	.byte	0x0
	.uleb128 0x24
	.byte	0x1
	.long	.LASF763
	.byte	0x9
	.byte	0x40
	.byte	0x1
	.long	0x3b82
	.uleb128 0x21
	.long	0x3c83
	.byte	0x1
	.uleb128 0x22
	.long	0x39a0
	.uleb128 0x22
	.long	0x39a0
	.uleb128 0x22
	.long	0x39a0
	.uleb128 0x22
	.long	0x39a0
	.uleb128 0x22
	.long	0x39a0
	.uleb128 0x22
	.long	0x39a0
	.byte	0x0
	.uleb128 0x25
	.byte	0x1
	.long	.LASF522
	.byte	0x9
	.byte	0x41
	.long	.LASF524
	.byte	0x1
	.long	0x3bb8
	.uleb128 0x21
	.long	0x3c83
	.byte	0x1
	.uleb128 0x22
	.long	0x39a0
	.uleb128 0x22
	.long	0x39a0
	.uleb128 0x22
	.long	0x39a0
	.uleb128 0x22
	.long	0x39a0
	.uleb128 0x22
	.long	0x39a0
	.uleb128 0x22
	.long	0x39a0
	.byte	0x0
	.uleb128 0x25
	.byte	0x1
	.long	.LASF523
	.byte	0x9
	.byte	0x42
	.long	.LASF525
	.byte	0x1
	.long	0x3bda
	.uleb128 0x21
	.long	0x3c83
	.byte	0x1
	.uleb128 0x22
	.long	0x39a0
	.uleb128 0x22
	.long	0x39a0
	.byte	0x0
	.uleb128 0x25
	.byte	0x1
	.long	.LASF526
	.byte	0x9
	.byte	0x43
	.long	.LASF527
	.byte	0x1
	.long	0x3bf2
	.uleb128 0x21
	.long	0x3c83
	.byte	0x1
	.byte	0x0
	.uleb128 0x25
	.byte	0x1
	.long	.LASF528
	.byte	0x9
	.byte	0x44
	.long	.LASF529
	.byte	0x1
	.long	0x3c14
	.uleb128 0x21
	.long	0x3c83
	.byte	0x1
	.uleb128 0x22
	.long	0x3ca0
	.uleb128 0x22
	.long	0x3ca6
	.byte	0x0
	.uleb128 0x26
	.byte	0x1
	.long	.LASF530
	.byte	0x9
	.byte	0x45
	.long	.LASF531
	.long	0x4f7
	.byte	0x1
	.long	0x3c3a
	.uleb128 0x21
	.long	0x3c83
	.byte	0x1
	.uleb128 0x22
	.long	0x3b
	.uleb128 0x22
	.long	0x4f7
	.byte	0x0
	.uleb128 0x26
	.byte	0x1
	.long	.LASF532
	.byte	0x9
	.byte	0x46
	.long	.LASF533
	.long	0x4f7
	.byte	0x1
	.long	0x3c60
	.uleb128 0x21
	.long	0x3c83
	.byte	0x1
	.uleb128 0x22
	.long	0x3b
	.uleb128 0x22
	.long	0x4f7
	.byte	0x0
	.uleb128 0x27
	.byte	0x1
	.long	.LASF534
	.byte	0x9
	.byte	0x47
	.long	.LASF535
	.long	0x4f7
	.byte	0x1
	.uleb128 0x21
	.long	0x3c83
	.byte	0x1
	.uleb128 0x22
	.long	0x3b
	.uleb128 0x22
	.long	0x4f7
	.byte	0x0
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x3a51
	.uleb128 0x28
	.byte	0x4
	.long	0x3c8f
	.uleb128 0x7
	.long	0x39e6
	.uleb128 0x28
	.byte	0x4
	.long	0x3a46
	.uleb128 0x6
	.byte	0x4
	.long	0x4f7
	.uleb128 0x28
	.byte	0x4
	.long	0x39e6
	.uleb128 0x28
	.byte	0x4
	.long	0x4f7
	.uleb128 0x29
	.byte	0x1
	.long	.LASF536
	.byte	0x1
	.byte	0x11
	.long	.LFB9
	.long	.LFE9
	.long	.LLST0
	.long	0x3d44
	.uleb128 0x2a
	.string	"wp"
	.byte	0x1
	.byte	0x11
	.long	0x3d44
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x2b
	.long	.LASF537
	.byte	0x1
	.byte	0x11
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x2a
	.string	"x"
	.byte	0x1
	.byte	0x12
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x2a
	.string	"y"
	.byte	0x1
	.byte	0x12
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 12
	.uleb128 0x2a
	.string	"z"
	.byte	0x1
	.byte	0x12
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 16
	.uleb128 0x2a
	.string	"v"
	.byte	0x1
	.byte	0x12
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 20
	.uleb128 0x2a
	.string	"w"
	.byte	0x1
	.byte	0x12
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 24
	.uleb128 0x2a
	.string	"u"
	.byte	0x1
	.byte	0x12
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 28
	.uleb128 0x2b
	.long	.LASF538
	.byte	0x1
	.byte	0x13
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 32
	.uleb128 0x2b
	.long	.LASF366
	.byte	0x1
	.byte	0x13
	.long	0x3d4a
	.byte	0x2
	.byte	0x91
	.sleb128 36
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x1113
	.uleb128 0x6
	.byte	0x4
	.long	0x32c1
	.uleb128 0x2c
	.byte	0x1
	.long	.LASF539
	.byte	0x1
	.byte	0x1e
	.long	0x388b
	.long	.LFB10
	.long	.LFE10
	.long	.LLST1
	.long	0x3f03
	.uleb128 0x2b
	.long	.LASF540
	.byte	0x1
	.byte	0x1e
	.long	0x388b
	.byte	0x3
	.byte	0x91
	.sleb128 -324
	.uleb128 0x2a
	.string	"x0"
	.byte	0x1
	.byte	0x1e
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x2a
	.string	"y0"
	.byte	0x1
	.byte	0x1e
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x2a
	.string	"z0"
	.byte	0x1
	.byte	0x1e
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 12
	.uleb128 0x2a
	.string	"v0"
	.byte	0x1
	.byte	0x1e
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 16
	.uleb128 0x2a
	.string	"w0"
	.byte	0x1
	.byte	0x1e
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 20
	.uleb128 0x2a
	.string	"u0"
	.byte	0x1
	.byte	0x1e
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 24
	.uleb128 0x2a
	.string	"x1"
	.byte	0x1
	.byte	0x1f
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 28
	.uleb128 0x2a
	.string	"y1"
	.byte	0x1
	.byte	0x1f
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 32
	.uleb128 0x2a
	.string	"z1"
	.byte	0x1
	.byte	0x1f
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 36
	.uleb128 0x2a
	.string	"v1"
	.byte	0x1
	.byte	0x1f
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 40
	.uleb128 0x2a
	.string	"w1"
	.byte	0x1
	.byte	0x1f
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 44
	.uleb128 0x2a
	.string	"u1"
	.byte	0x1
	.byte	0x1f
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 48
	.uleb128 0x2a
	.string	"nos"
	.byte	0x1
	.byte	0x20
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 52
	.uleb128 0x2b
	.long	.LASF289
	.byte	0x1
	.byte	0x20
	.long	0x18ce
	.byte	0x3
	.byte	0x91
	.sleb128 -328
	.uleb128 0x2b
	.long	.LASF541
	.byte	0x1
	.byte	0x20
	.long	0x5a
	.byte	0x3
	.byte	0x91
	.sleb128 -332
	.uleb128 0x2b
	.long	.LASF542
	.byte	0x1
	.byte	0x20
	.long	0x5a
	.byte	0x3
	.byte	0x91
	.sleb128 -336
	.uleb128 0x2d
	.long	.LBB2
	.long	.LBE2
	.uleb128 0x2e
	.string	"i"
	.byte	0x1
	.byte	0x22
	.long	0x3b
	.byte	0x3
	.byte	0x91
	.sleb128 -280
	.uleb128 0x2e
	.string	"l"
	.byte	0x1
	.byte	0x22
	.long	0x3b
	.byte	0x3
	.byte	0x91
	.sleb128 -284
	.uleb128 0x2f
	.long	.LASF543
	.byte	0x1
	.byte	0x22
	.long	0x3b
	.byte	0x3
	.byte	0x91
	.sleb128 -288
	.uleb128 0x2e
	.string	"s"
	.byte	0x1
	.byte	0x23
	.long	0x5a3
	.byte	0x3
	.byte	0x91
	.sleb128 -276
	.uleb128 0x2e
	.string	"xp"
	.byte	0x1
	.byte	0x24
	.long	0x596
	.byte	0x3
	.byte	0x91
	.sleb128 -292
	.uleb128 0x2e
	.string	"yp"
	.byte	0x1
	.byte	0x24
	.long	0x596
	.byte	0x3
	.byte	0x91
	.sleb128 -296
	.uleb128 0x2e
	.string	"zp"
	.byte	0x1
	.byte	0x24
	.long	0x596
	.byte	0x3
	.byte	0x91
	.sleb128 -300
	.uleb128 0x2e
	.string	"vp"
	.byte	0x1
	.byte	0x24
	.long	0x596
	.byte	0x3
	.byte	0x91
	.sleb128 -304
	.uleb128 0x2e
	.string	"wp"
	.byte	0x1
	.byte	0x24
	.long	0x596
	.byte	0x3
	.byte	0x91
	.sleb128 -308
	.uleb128 0x2e
	.string	"up"
	.byte	0x1
	.byte	0x24
	.long	0x596
	.byte	0x3
	.byte	0x91
	.sleb128 -312
	.uleb128 0x2e
	.string	"t"
	.byte	0x1
	.byte	0x24
	.long	0x596
	.byte	0x3
	.byte	0x91
	.sleb128 -316
	.uleb128 0x2f
	.long	.LASF544
	.byte	0x1
	.byte	0x24
	.long	0x596
	.byte	0x3
	.byte	0x91
	.sleb128 -320
	.byte	0x0
	.byte	0x0
	.uleb128 0x2c
	.byte	0x1
	.long	.LASF545
	.byte	0x1
	.byte	0x4d
	.long	0x388b
	.long	.LFB11
	.long	.LFE11
	.long	.LLST2
	.long	0x4078
	.uleb128 0x2b
	.long	.LASF540
	.byte	0x1
	.byte	0x4d
	.long	0x388b
	.byte	0x3
	.byte	0x91
	.sleb128 -356
	.uleb128 0x2a
	.string	"x0"
	.byte	0x1
	.byte	0x4d
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x2a
	.string	"y0"
	.byte	0x1
	.byte	0x4d
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x2a
	.string	"z0"
	.byte	0x1
	.byte	0x4d
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 12
	.uleb128 0x2a
	.string	"v0"
	.byte	0x1
	.byte	0x4d
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 16
	.uleb128 0x2a
	.string	"w0"
	.byte	0x1
	.byte	0x4d
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 20
	.uleb128 0x2a
	.string	"u0"
	.byte	0x1
	.byte	0x4d
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 24
	.uleb128 0x2b
	.long	.LASF546
	.byte	0x1
	.byte	0x4e
	.long	0x5a
	.byte	0x3
	.byte	0x91
	.sleb128 -360
	.uleb128 0x2a
	.string	"x1"
	.byte	0x1
	.byte	0x4e
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 32
	.uleb128 0x2a
	.string	"y1"
	.byte	0x1
	.byte	0x4e
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 36
	.uleb128 0x2a
	.string	"z1"
	.byte	0x1
	.byte	0x4e
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 40
	.uleb128 0x2a
	.string	"v1"
	.byte	0x1
	.byte	0x4e
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 44
	.uleb128 0x2a
	.string	"w1"
	.byte	0x1
	.byte	0x4e
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 48
	.uleb128 0x2a
	.string	"u1"
	.byte	0x1
	.byte	0x4e
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 52
	.uleb128 0x2b
	.long	.LASF547
	.byte	0x1
	.byte	0x4f
	.long	0x5a
	.byte	0x3
	.byte	0x91
	.sleb128 -364
	.uleb128 0x2b
	.long	.LASF366
	.byte	0x1
	.byte	0x4f
	.long	0x3d4a
	.byte	0x3
	.byte	0x91
	.sleb128 -368
	.uleb128 0x2a
	.string	"nos"
	.byte	0x1
	.byte	0x4f
	.long	0x3b
	.byte	0x3
	.byte	0x91
	.sleb128 64
	.uleb128 0x2b
	.long	.LASF289
	.byte	0x1
	.byte	0x4f
	.long	0x18ce
	.byte	0x3
	.byte	0x91
	.sleb128 -372
	.uleb128 0x2b
	.long	.LASF186
	.byte	0x1
	.byte	0x4f
	.long	0x5a
	.byte	0x3
	.byte	0x91
	.sleb128 -376
	.uleb128 0x2b
	.long	.LASF542
	.byte	0x1
	.byte	0x4f
	.long	0x5a
	.byte	0x3
	.byte	0x91
	.sleb128 -380
	.uleb128 0x2b
	.long	.LASF548
	.byte	0x1
	.byte	0x4f
	.long	0x3b
	.byte	0x3
	.byte	0x91
	.sleb128 80
	.uleb128 0x2d
	.long	.LBB3
	.long	.LBE3
	.uleb128 0x2e
	.string	"wp0"
	.byte	0x1
	.byte	0x51
	.long	0x1113
	.byte	0x3
	.byte	0x91
	.sleb128 -316
	.uleb128 0x2e
	.string	"wp1"
	.byte	0x1
	.byte	0x51
	.long	0x1113
	.byte	0x3
	.byte	0x91
	.sleb128 -340
	.uleb128 0x2e
	.string	"s"
	.byte	0x1
	.byte	0x52
	.long	0x5a3
	.byte	0x3
	.byte	0x91
	.sleb128 -292
	.byte	0x0
	.byte	0x0
	.uleb128 0x30
	.byte	0x1
	.long	.LASF549
	.byte	0x1
	.byte	0x7c
	.long	.LASF550
	.long	.LFB12
	.long	.LFE12
	.long	.LLST3
	.long	0x4193
	.uleb128 0x2b
	.long	.LASF366
	.byte	0x1
	.byte	0x7c
	.long	0x3d4a
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x2b
	.long	.LASF551
	.byte	0x1
	.byte	0x7c
	.long	0x1ca7
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x2b
	.long	.LASF552
	.byte	0x1
	.byte	0x7c
	.long	0x18ce
	.byte	0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x2a
	.string	"A"
	.byte	0x1
	.byte	0x7c
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 12
	.uleb128 0x2b
	.long	.LASF502
	.byte	0x1
	.byte	0x7c
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 16
	.uleb128 0x2b
	.long	.LASF503
	.byte	0x1
	.byte	0x7c
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 20
	.uleb128 0x2a
	.string	"L"
	.byte	0x1
	.byte	0x7c
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 24
	.uleb128 0x2a
	.string	"f"
	.byte	0x1
	.byte	0x7c
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 28
	.uleb128 0x2a
	.string	"T"
	.byte	0x1
	.byte	0x7c
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 32
	.uleb128 0x2a
	.string	"pos"
	.byte	0x1
	.byte	0x7c
	.long	0x3d44
	.byte	0x2
	.byte	0x91
	.sleb128 36
	.uleb128 0x2a
	.string	"nos"
	.byte	0x1
	.byte	0x7c
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 40
	.uleb128 0x2b
	.long	.LASF553
	.byte	0x1
	.byte	0x7c
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 44
	.uleb128 0x2b
	.long	.LASF221
	.byte	0x1
	.byte	0x7c
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 48
	.uleb128 0x2d
	.long	.LBB4
	.long	.LBE4
	.uleb128 0x2e
	.string	"out"
	.byte	0x1
	.byte	0x7e
	.long	0x1113
	.byte	0x2
	.byte	0x91
	.sleb128 -52
	.uleb128 0x2d
	.long	.LBB5
	.long	.LBE5
	.uleb128 0x2e
	.string	"i"
	.byte	0x1
	.byte	0x7f
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x2d
	.long	.LBB6
	.long	.LBE6
	.uleb128 0x2e
	.string	"t"
	.byte	0x1
	.byte	0x80
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x2e
	.string	"x"
	.byte	0x1
	.byte	0x81
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -28
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.uleb128 0x2c
	.byte	0x1
	.long	.LASF554
	.byte	0x1
	.byte	0x96
	.long	0x596
	.long	.LFB13
	.long	.LFE13
	.long	.LLST4
	.long	0x41c8
	.uleb128 0x2a
	.string	"L"
	.byte	0x1
	.byte	0x96
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x2a
	.string	"T"
	.byte	0x1
	.byte	0x96
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.byte	0x0
	.uleb128 0x30
	.byte	0x1
	.long	.LASF555
	.byte	0x1
	.byte	0xaa
	.long	.LASF556
	.long	.LFB14
	.long	.LFE14
	.long	.LLST5
	.long	0x42af
	.uleb128 0x2b
	.long	.LASF366
	.byte	0x1
	.byte	0xaa
	.long	0x3d4a
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x2b
	.long	.LASF551
	.byte	0x1
	.byte	0xaa
	.long	0x1ca7
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x2b
	.long	.LASF552
	.byte	0x1
	.byte	0xaa
	.long	0x18ce
	.byte	0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x2a
	.string	"L"
	.byte	0x1
	.byte	0xaa
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 12
	.uleb128 0x2a
	.string	"T"
	.byte	0x1
	.byte	0xaa
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 16
	.uleb128 0x2a
	.string	"pos"
	.byte	0x1
	.byte	0xaa
	.long	0x3d44
	.byte	0x2
	.byte	0x91
	.sleb128 20
	.uleb128 0x2a
	.string	"nos"
	.byte	0x1
	.byte	0xaa
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 24
	.uleb128 0x2b
	.long	.LASF553
	.byte	0x1
	.byte	0xaa
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 28
	.uleb128 0x2b
	.long	.LASF221
	.byte	0x1
	.byte	0xaa
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 32
	.uleb128 0x2d
	.long	.LBB7
	.long	.LBE7
	.uleb128 0x2e
	.string	"out"
	.byte	0x1
	.byte	0xac
	.long	0x1113
	.byte	0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x2d
	.long	.LBB8
	.long	.LBE8
	.uleb128 0x2e
	.string	"i"
	.byte	0x1
	.byte	0xad
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0x2d
	.long	.LBB9
	.long	.LBE9
	.uleb128 0x2e
	.string	"t"
	.byte	0x1
	.byte	0xae
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x2e
	.string	"x"
	.byte	0x1
	.byte	0xaf
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.uleb128 0x2c
	.byte	0x1
	.long	.LASF557
	.byte	0x1
	.byte	0xc4
	.long	0x596
	.long	.LFB15
	.long	.LFE15
	.long	.LLST6
	.long	0x42e4
	.uleb128 0x2a
	.string	"L"
	.byte	0x1
	.byte	0xc4
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x2a
	.string	"T"
	.byte	0x1
	.byte	0xc4
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.byte	0x0
	.uleb128 0x30
	.byte	0x1
	.long	.LASF558
	.byte	0x1
	.byte	0xc9
	.long	.LASF559
	.long	.LFB16
	.long	.LFE16
	.long	.LLST7
	.long	0x43cb
	.uleb128 0x2b
	.long	.LASF366
	.byte	0x1
	.byte	0xc9
	.long	0x3d4a
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x2b
	.long	.LASF551
	.byte	0x1
	.byte	0xc9
	.long	0x1ca7
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x2b
	.long	.LASF552
	.byte	0x1
	.byte	0xc9
	.long	0x18ce
	.byte	0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x2a
	.string	"L"
	.byte	0x1
	.byte	0xc9
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 12
	.uleb128 0x2a
	.string	"T"
	.byte	0x1
	.byte	0xc9
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 16
	.uleb128 0x2a
	.string	"pos"
	.byte	0x1
	.byte	0xc9
	.long	0x3d44
	.byte	0x2
	.byte	0x91
	.sleb128 20
	.uleb128 0x2a
	.string	"nos"
	.byte	0x1
	.byte	0xc9
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 24
	.uleb128 0x2b
	.long	.LASF553
	.byte	0x1
	.byte	0xc9
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 28
	.uleb128 0x2b
	.long	.LASF221
	.byte	0x1
	.byte	0xc9
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 32
	.uleb128 0x2d
	.long	.LBB10
	.long	.LBE10
	.uleb128 0x2e
	.string	"out"
	.byte	0x1
	.byte	0xcb
	.long	0x1113
	.byte	0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x2e
	.string	"A"
	.byte	0x1
	.byte	0xcc
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0x2d
	.long	.LBB11
	.long	.LBE11
	.uleb128 0x2e
	.string	"i"
	.byte	0x1
	.byte	0xcd
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x2d
	.long	.LBB12
	.long	.LBE12
	.uleb128 0x2e
	.string	"t"
	.byte	0x1
	.byte	0xce
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.uleb128 0x31
	.byte	0x1
	.long	.LASF564
	.byte	0x1
	.byte	0xe3
	.long	.LASF764
	.long	0x596
	.long	.LFB17
	.long	.LFE17
	.long	.LLST8
	.long	0x4404
	.uleb128 0x2a
	.string	"L"
	.byte	0x1
	.byte	0xe3
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x2a
	.string	"T"
	.byte	0x1
	.byte	0xe3
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.byte	0x0
	.uleb128 0x30
	.byte	0x1
	.long	.LASF560
	.byte	0x1
	.byte	0xf6
	.long	.LASF561
	.long	.LFB18
	.long	.LFE18
	.long	.LLST9
	.long	0x44eb
	.uleb128 0x2b
	.long	.LASF366
	.byte	0x1
	.byte	0xf6
	.long	0x3d4a
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x2b
	.long	.LASF551
	.byte	0x1
	.byte	0xf6
	.long	0x1ca7
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x2b
	.long	.LASF552
	.byte	0x1
	.byte	0xf6
	.long	0x18ce
	.byte	0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x2a
	.string	"L"
	.byte	0x1
	.byte	0xf6
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 12
	.uleb128 0x2a
	.string	"T"
	.byte	0x1
	.byte	0xf6
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 16
	.uleb128 0x2a
	.string	"pos"
	.byte	0x1
	.byte	0xf6
	.long	0x3d44
	.byte	0x2
	.byte	0x91
	.sleb128 20
	.uleb128 0x2a
	.string	"nos"
	.byte	0x1
	.byte	0xf6
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 24
	.uleb128 0x2b
	.long	.LASF553
	.byte	0x1
	.byte	0xf6
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 28
	.uleb128 0x2b
	.long	.LASF221
	.byte	0x1
	.byte	0xf6
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 32
	.uleb128 0x2d
	.long	.LBB13
	.long	.LBE13
	.uleb128 0x2e
	.string	"out"
	.byte	0x1
	.byte	0xf8
	.long	0x1113
	.byte	0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x2d
	.long	.LBB14
	.long	.LBE14
	.uleb128 0x2e
	.string	"i"
	.byte	0x1
	.byte	0xf9
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0x2d
	.long	.LBB15
	.long	.LBE15
	.uleb128 0x2e
	.string	"t"
	.byte	0x1
	.byte	0xfa
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x2e
	.string	"x"
	.byte	0x1
	.byte	0xfb
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.uleb128 0x32
	.byte	0x1
	.long	.LASF562
	.byte	0x1
	.value	0x110
	.long	0x596
	.long	.LFB19
	.long	.LFE19
	.long	.LLST10
	.long	0x4523
	.uleb128 0x33
	.string	"L"
	.byte	0x1
	.value	0x110
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x33
	.string	"T"
	.byte	0x1
	.value	0x110
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.byte	0x0
	.uleb128 0x34
	.byte	0x1
	.long	.LASF563
	.byte	0x1
	.value	0x115
	.long	.LASF765
	.long	.LFB20
	.long	.LFE20
	.long	.LLST11
	.long	0x4625
	.uleb128 0x35
	.long	.LASF366
	.byte	0x1
	.value	0x115
	.long	0x3d4a
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x35
	.long	.LASF551
	.byte	0x1
	.value	0x115
	.long	0x1ca7
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x35
	.long	.LASF552
	.byte	0x1
	.value	0x115
	.long	0x18ce
	.byte	0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x33
	.string	"L"
	.byte	0x1
	.value	0x115
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 12
	.uleb128 0x33
	.string	"T"
	.byte	0x1
	.value	0x115
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 16
	.uleb128 0x33
	.string	"pos"
	.byte	0x1
	.value	0x115
	.long	0x3d44
	.byte	0x2
	.byte	0x91
	.sleb128 20
	.uleb128 0x33
	.string	"nos"
	.byte	0x1
	.value	0x115
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 24
	.uleb128 0x35
	.long	.LASF553
	.byte	0x1
	.value	0x115
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 28
	.uleb128 0x35
	.long	.LASF221
	.byte	0x1
	.value	0x115
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 32
	.uleb128 0x2d
	.long	.LBB16
	.long	.LBE16
	.uleb128 0x36
	.string	"out"
	.byte	0x1
	.value	0x117
	.long	0x1113
	.byte	0x2
	.byte	0x91
	.sleb128 -52
	.uleb128 0x36
	.string	"A"
	.byte	0x1
	.value	0x118
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0x2d
	.long	.LBB17
	.long	.LBE17
	.uleb128 0x36
	.string	"i"
	.byte	0x1
	.value	0x119
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x2d
	.long	.LBB18
	.long	.LBE18
	.uleb128 0x36
	.string	"t"
	.byte	0x1
	.value	0x11a
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x36
	.string	"x"
	.byte	0x1
	.value	0x11b
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -28
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.uleb128 0x37
	.byte	0x1
	.long	.LASF565
	.byte	0x1
	.value	0x130
	.long	.LASF654
	.long	0x596
	.long	.LFB21
	.long	.LFE21
	.long	.LLST12
	.long	0x4661
	.uleb128 0x33
	.string	"L"
	.byte	0x1
	.value	0x130
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x33
	.string	"T"
	.byte	0x1
	.value	0x130
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.byte	0x0
	.uleb128 0x38
	.byte	0x1
	.long	.LASF566
	.byte	0x1
	.value	0x139
	.long	.LFB22
	.long	.LFE22
	.long	.LLST13
	.long	0x479c
	.uleb128 0x35
	.long	.LASF551
	.byte	0x1
	.value	0x139
	.long	0x1ca7
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x35
	.long	.LASF552
	.byte	0x1
	.value	0x139
	.long	0x18ce
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x33
	.string	"p1"
	.byte	0x1
	.value	0x139
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x33
	.string	"v1"
	.byte	0x1
	.value	0x139
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 12
	.uleb128 0x33
	.string	"a1"
	.byte	0x1
	.value	0x139
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 16
	.uleb128 0x33
	.string	"p2"
	.byte	0x1
	.value	0x139
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 20
	.uleb128 0x33
	.string	"v2"
	.byte	0x1
	.value	0x139
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 24
	.uleb128 0x33
	.string	"a2"
	.byte	0x1
	.value	0x139
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 28
	.uleb128 0x35
	.long	.LASF567
	.byte	0x1
	.value	0x139
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 32
	.uleb128 0x33
	.string	"nos"
	.byte	0x1
	.value	0x139
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 36
	.uleb128 0x35
	.long	.LASF553
	.byte	0x1
	.value	0x139
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 40
	.uleb128 0x35
	.long	.LASF366
	.byte	0x1
	.value	0x139
	.long	0x3d4a
	.byte	0x2
	.byte	0x91
	.sleb128 44
	.uleb128 0x35
	.long	.LASF221
	.byte	0x1
	.value	0x139
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 48
	.uleb128 0x35
	.long	.LASF568
	.byte	0x1
	.value	0x139
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 52
	.uleb128 0x2d
	.long	.LBB19
	.long	.LBE19
	.uleb128 0x36
	.string	"i"
	.byte	0x1
	.value	0x13b
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x36
	.string	"j"
	.byte	0x1
	.value	0x13b
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x36
	.string	"c"
	.byte	0x1
	.value	0x13c
	.long	0x47a2
	.byte	0x3
	.byte	0x91
	.sleb128 -212
	.uleb128 0x36
	.string	"bl"
	.byte	0x1
	.value	0x13d
	.long	0x13b9
	.byte	0x3
	.byte	0x91
	.sleb128 -68
	.uleb128 0x39
	.long	.Ldebug_ranges0+0x0
	.uleb128 0x36
	.string	"st"
	.byte	0x1
	.value	0x147
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -44
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x13b9
	.uleb128 0x8
	.long	0x13b9
	.long	0x47b2
	.uleb128 0x9
	.long	0x50
	.byte	0x5
	.byte	0x0
	.uleb128 0x32
	.byte	0x1
	.long	.LASF569
	.byte	0x1
	.value	0x15d
	.long	0x596
	.long	.LFB23
	.long	.LFE23
	.long	.LLST14
	.long	0x48c7
	.uleb128 0x33
	.string	"p1"
	.byte	0x1
	.value	0x15d
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x33
	.string	"v1"
	.byte	0x1
	.value	0x15d
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x33
	.string	"a1"
	.byte	0x1
	.value	0x15d
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x33
	.string	"p2"
	.byte	0x1
	.value	0x15d
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 12
	.uleb128 0x33
	.string	"v2"
	.byte	0x1
	.value	0x15d
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 16
	.uleb128 0x33
	.string	"a2"
	.byte	0x1
	.value	0x15d
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 20
	.uleb128 0x35
	.long	.LASF567
	.byte	0x1
	.value	0x15d
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 24
	.uleb128 0x33
	.string	"mv"
	.byte	0x1
	.value	0x15d
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 28
	.uleb128 0x2d
	.long	.LBB22
	.long	.LBE22
	.uleb128 0x36
	.string	"i"
	.byte	0x1
	.value	0x15f
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x36
	.string	"j"
	.byte	0x1
	.value	0x15f
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x36
	.string	"nos"
	.byte	0x1
	.value	0x160
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0x36
	.string	"c"
	.byte	0x1
	.value	0x161
	.long	0x48c7
	.byte	0x3
	.byte	0x91
	.sleb128 -204
	.uleb128 0x36
	.string	"bl"
	.byte	0x1
	.value	0x162
	.long	0x13b9
	.byte	0x2
	.byte	0x91
	.sleb128 -60
	.uleb128 0x3a
	.long	.LASF570
	.byte	0x1
	.value	0x163
	.long	0x13b9
	.byte	0x3
	.byte	0x91
	.sleb128 -84
	.uleb128 0x3a
	.long	.LASF571
	.byte	0x1
	.value	0x172
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x2d
	.long	.LBB23
	.long	.LBE23
	.uleb128 0x36
	.string	"st"
	.byte	0x1
	.value	0x16c
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -32
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.uleb128 0x8
	.long	0x13b9
	.long	0x48d7
	.uleb128 0x9
	.long	0x50
	.byte	0x4
	.byte	0x0
	.uleb128 0x32
	.byte	0x1
	.long	.LASF572
	.byte	0x1
	.value	0x17a
	.long	0x596
	.long	.LFB24
	.long	.LFE24
	.long	.LLST15
	.long	0x4a37
	.uleb128 0x33
	.string	"p1"
	.byte	0x1
	.value	0x17a
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x33
	.string	"v1"
	.byte	0x1
	.value	0x17a
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x33
	.string	"a1"
	.byte	0x1
	.value	0x17a
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x33
	.string	"p2"
	.byte	0x1
	.value	0x17a
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 12
	.uleb128 0x33
	.string	"v2"
	.byte	0x1
	.value	0x17a
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 16
	.uleb128 0x33
	.string	"a2"
	.byte	0x1
	.value	0x17a
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 20
	.uleb128 0x35
	.long	.LASF567
	.byte	0x1
	.value	0x17a
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 24
	.uleb128 0x33
	.string	"ma"
	.byte	0x1
	.value	0x17a
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 28
	.uleb128 0x2d
	.long	.LBB24
	.long	.LBE24
	.uleb128 0x36
	.string	"i"
	.byte	0x1
	.value	0x17c
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x36
	.string	"j"
	.byte	0x1
	.value	0x17c
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x36
	.string	"nos"
	.byte	0x1
	.value	0x17d
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0x3a
	.long	.LASF573
	.byte	0x1
	.value	0x17e
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x36
	.string	"c"
	.byte	0x1
	.value	0x17f
	.long	0x4a37
	.byte	0x3
	.byte	0x91
	.sleb128 -216
	.uleb128 0x36
	.string	"bl"
	.byte	0x1
	.value	0x180
	.long	0x13b9
	.byte	0x3
	.byte	0x91
	.sleb128 -72
	.uleb128 0x3a
	.long	.LASF570
	.byte	0x1
	.value	0x181
	.long	0x13b9
	.byte	0x3
	.byte	0x91
	.sleb128 -96
	.uleb128 0x3a
	.long	.LASF574
	.byte	0x1
	.value	0x183
	.long	0x13b9
	.byte	0x3
	.byte	0x91
	.sleb128 -120
	.uleb128 0x3a
	.long	.LASF575
	.byte	0x1
	.value	0x18a
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x3a
	.long	.LASF571
	.byte	0x1
	.value	0x1a6
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x3b
	.long	.LBB25
	.long	.LBE25
	.long	0x4a1d
	.uleb128 0x36
	.string	"st"
	.byte	0x1
	.value	0x18c
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -40
	.byte	0x0
	.uleb128 0x2d
	.long	.LBB26
	.long	.LBE26
	.uleb128 0x36
	.string	"st"
	.byte	0x1
	.value	0x19a
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -44
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.uleb128 0x8
	.long	0x13b9
	.long	0x4a47
	.uleb128 0x9
	.long	0x50
	.byte	0x3
	.byte	0x0
	.uleb128 0x38
	.byte	0x1
	.long	.LASF576
	.byte	0x1
	.value	0x1b5
	.long	.LFB25
	.long	.LFE25
	.long	.LLST16
	.long	0x4b84
	.uleb128 0x35
	.long	.LASF551
	.byte	0x1
	.value	0x1b5
	.long	0x1ca7
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x35
	.long	.LASF552
	.byte	0x1
	.value	0x1b5
	.long	0x18ce
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x33
	.string	"p1"
	.byte	0x1
	.value	0x1b5
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x33
	.string	"v1"
	.byte	0x1
	.value	0x1b5
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 12
	.uleb128 0x33
	.string	"p2"
	.byte	0x1
	.value	0x1b5
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 16
	.uleb128 0x33
	.string	"v2"
	.byte	0x1
	.value	0x1b5
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 20
	.uleb128 0x35
	.long	.LASF567
	.byte	0x1
	.value	0x1b5
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 24
	.uleb128 0x33
	.string	"nos"
	.byte	0x1
	.value	0x1b5
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 28
	.uleb128 0x35
	.long	.LASF553
	.byte	0x1
	.value	0x1b5
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 32
	.uleb128 0x35
	.long	.LASF366
	.byte	0x1
	.value	0x1b5
	.long	0x3d4a
	.byte	0x2
	.byte	0x91
	.sleb128 36
	.uleb128 0x35
	.long	.LASF221
	.byte	0x1
	.value	0x1b5
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 40
	.uleb128 0x35
	.long	.LASF568
	.byte	0x1
	.value	0x1b5
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 44
	.uleb128 0x2d
	.long	.LBB27
	.long	.LBE27
	.uleb128 0x36
	.string	"i"
	.byte	0x1
	.value	0x1b7
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x36
	.string	"j"
	.byte	0x1
	.value	0x1b7
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x36
	.string	"c"
	.byte	0x1
	.value	0x1b8
	.long	0x4a37
	.byte	0x3
	.byte	0x91
	.sleb128 -172
	.uleb128 0x36
	.string	"bl"
	.byte	0x1
	.value	0x1b9
	.long	0x13b9
	.byte	0x3
	.byte	0x91
	.sleb128 -76
	.uleb128 0x39
	.long	.Ldebug_ranges0+0x18
	.uleb128 0x36
	.string	"st"
	.byte	0x1
	.value	0x1c1
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -44
	.uleb128 0x36
	.string	"st2"
	.byte	0x1
	.value	0x1c2
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x36
	.string	"st3"
	.byte	0x1
	.value	0x1c2
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -52
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.uleb128 0x32
	.byte	0x1
	.long	.LASF577
	.byte	0x1
	.value	0x1db
	.long	0x596
	.long	.LFB26
	.long	.LFE26
	.long	.LLST17
	.long	0x4c6f
	.uleb128 0x33
	.string	"p1"
	.byte	0x1
	.value	0x1db
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x33
	.string	"v1"
	.byte	0x1
	.value	0x1db
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x33
	.string	"p2"
	.byte	0x1
	.value	0x1db
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x33
	.string	"v2"
	.byte	0x1
	.value	0x1db
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 12
	.uleb128 0x35
	.long	.LASF567
	.byte	0x1
	.value	0x1db
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 16
	.uleb128 0x33
	.string	"mv"
	.byte	0x1
	.value	0x1db
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 20
	.uleb128 0x2d
	.long	.LBB30
	.long	.LBE30
	.uleb128 0x36
	.string	"j"
	.byte	0x1
	.value	0x1dd
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x36
	.string	"c"
	.byte	0x1
	.value	0x1de
	.long	0x4a37
	.byte	0x3
	.byte	0x91
	.sleb128 -176
	.uleb128 0x36
	.string	"bl"
	.byte	0x1
	.value	0x1df
	.long	0x13b9
	.byte	0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0x3a
	.long	.LASF570
	.byte	0x1
	.value	0x1e0
	.long	0x13b9
	.byte	0x3
	.byte	0x91
	.sleb128 -80
	.uleb128 0x36
	.string	"st"
	.byte	0x1
	.value	0x1e7
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x3a
	.long	.LASF571
	.byte	0x1
	.value	0x1fb
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x2d
	.long	.LBB31
	.long	.LBE31
	.uleb128 0x36
	.string	"st"
	.byte	0x1
	.value	0x1f4
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -28
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.uleb128 0x32
	.byte	0x1
	.long	.LASF578
	.byte	0x1
	.value	0x204
	.long	0x596
	.long	.LFB27
	.long	.LFE27
	.long	.LLST18
	.long	0x4d42
	.uleb128 0x33
	.string	"p1"
	.byte	0x1
	.value	0x204
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x33
	.string	"v1"
	.byte	0x1
	.value	0x204
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x33
	.string	"p2"
	.byte	0x1
	.value	0x204
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x33
	.string	"v2"
	.byte	0x1
	.value	0x204
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 12
	.uleb128 0x35
	.long	.LASF567
	.byte	0x1
	.value	0x204
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 16
	.uleb128 0x33
	.string	"ma"
	.byte	0x1
	.value	0x204
	.long	0x479c
	.byte	0x2
	.byte	0x91
	.sleb128 20
	.uleb128 0x2d
	.long	.LBB32
	.long	.LBE32
	.uleb128 0x36
	.string	"j"
	.byte	0x1
	.value	0x206
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0x36
	.string	"c"
	.byte	0x1
	.value	0x207
	.long	0x4a37
	.byte	0x3
	.byte	0x91
	.sleb128 -168
	.uleb128 0x36
	.string	"bl"
	.byte	0x1
	.value	0x208
	.long	0x13b9
	.byte	0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x3a
	.long	.LASF570
	.byte	0x1
	.value	0x209
	.long	0x13b9
	.byte	0x3
	.byte	0x91
	.sleb128 -72
	.uleb128 0x36
	.string	"st"
	.byte	0x1
	.value	0x211
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x3a
	.long	.LASF571
	.byte	0x1
	.value	0x21d
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.byte	0x0
	.byte	0x0
	.uleb128 0x32
	.byte	0x1
	.long	.LASF579
	.byte	0x1
	.value	0x244
	.long	0x596
	.long	.LFB28
	.long	.LFE28
	.long	.LLST19
	.long	0x54bf
	.uleb128 0x35
	.long	.LASF366
	.byte	0x1
	.value	0x244
	.long	0x3d4a
	.byte	0x4
	.byte	0x91
	.sleb128 -26772
	.uleb128 0x35
	.long	.LASF551
	.byte	0x1
	.value	0x244
	.long	0x1ca7
	.byte	0x4
	.byte	0x91
	.sleb128 -26776
	.uleb128 0x35
	.long	.LASF580
	.byte	0x1
	.value	0x244
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x35
	.long	.LASF193
	.byte	0x1
	.value	0x244
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 12
	.uleb128 0x35
	.long	.LASF232
	.byte	0x1
	.value	0x244
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 16
	.uleb128 0x35
	.long	.LASF581
	.byte	0x1
	.value	0x244
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 20
	.uleb128 0x35
	.long	.LASF582
	.byte	0x1
	.value	0x244
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 24
	.uleb128 0x35
	.long	.LASF583
	.byte	0x1
	.value	0x244
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 28
	.uleb128 0x35
	.long	.LASF584
	.byte	0x1
	.value	0x244
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 32
	.uleb128 0x33
	.string	"mv"
	.byte	0x1
	.value	0x244
	.long	0x479c
	.byte	0x4
	.byte	0x91
	.sleb128 -26780
	.uleb128 0x33
	.string	"ma"
	.byte	0x1
	.value	0x244
	.long	0x479c
	.byte	0x4
	.byte	0x91
	.sleb128 -26784
	.uleb128 0x35
	.long	.LASF585
	.byte	0x1
	.value	0x244
	.long	0x3d44
	.byte	0x4
	.byte	0x91
	.sleb128 -26788
	.uleb128 0x35
	.long	.LASF586
	.byte	0x1
	.value	0x244
	.long	0x3d44
	.byte	0x4
	.byte	0x91
	.sleb128 -26792
	.uleb128 0x35
	.long	.LASF587
	.byte	0x1
	.value	0x244
	.long	0x3d44
	.byte	0x4
	.byte	0x91
	.sleb128 -26796
	.uleb128 0x35
	.long	.LASF588
	.byte	0x1
	.value	0x244
	.long	0x3d44
	.byte	0x4
	.byte	0x91
	.sleb128 -26800
	.uleb128 0x35
	.long	.LASF589
	.byte	0x1
	.value	0x244
	.long	0x54bf
	.byte	0x4
	.byte	0x91
	.sleb128 -26804
	.uleb128 0x35
	.long	.LASF590
	.byte	0x1
	.value	0x244
	.long	0x3d44
	.byte	0x4
	.byte	0x91
	.sleb128 -26808
	.uleb128 0x35
	.long	.LASF591
	.byte	0x1
	.value	0x244
	.long	0x54bf
	.byte	0x4
	.byte	0x91
	.sleb128 -26812
	.uleb128 0x35
	.long	.LASF592
	.byte	0x1
	.value	0x244
	.long	0x3d44
	.byte	0x4
	.byte	0x91
	.sleb128 -26816
	.uleb128 0x35
	.long	.LASF593
	.byte	0x1
	.value	0x244
	.long	0x54c5
	.byte	0x4
	.byte	0x91
	.sleb128 -26820
	.uleb128 0x35
	.long	.LASF594
	.byte	0x1
	.value	0x244
	.long	0x54c5
	.byte	0x4
	.byte	0x91
	.sleb128 -26824
	.uleb128 0x35
	.long	.LASF595
	.byte	0x1
	.value	0x244
	.long	0x3b
	.byte	0x3
	.byte	0x91
	.sleb128 84
	.uleb128 0x35
	.long	.LASF596
	.byte	0x1
	.value	0x244
	.long	0x596
	.byte	0x3
	.byte	0x91
	.sleb128 88
	.uleb128 0x2d
	.long	.LBB33
	.long	.LBE33
	.uleb128 0x3a
	.long	.LASF597
	.byte	0x1
	.value	0x246
	.long	0x32c1
	.byte	0x4
	.byte	0x91
	.sleb128 -23796
	.uleb128 0x3a
	.long	.LASF552
	.byte	0x1
	.value	0x249
	.long	0x3b
	.byte	0x4
	.byte	0x91
	.sleb128 -23800
	.uleb128 0x3a
	.long	.LASF598
	.byte	0x1
	.value	0x24a
	.long	0x18ce
	.byte	0x4
	.byte	0x91
	.sleb128 -23804
	.uleb128 0x3a
	.long	.LASF221
	.byte	0x1
	.value	0x24b
	.long	0x3b
	.byte	0x4
	.byte	0x91
	.sleb128 -23808
	.uleb128 0x3a
	.long	.LASF599
	.byte	0x1
	.value	0x24c
	.long	0x3b
	.byte	0x4
	.byte	0x91
	.sleb128 -23812
	.uleb128 0x3a
	.long	.LASF600
	.byte	0x1
	.value	0x24c
	.long	0x3b
	.byte	0x4
	.byte	0x91
	.sleb128 -23816
	.uleb128 0x3a
	.long	.LASF601
	.byte	0x1
	.value	0x24c
	.long	0x3b
	.byte	0x4
	.byte	0x91
	.sleb128 -23820
	.uleb128 0x3a
	.long	.LASF602
	.byte	0x1
	.value	0x24d
	.long	0x596
	.byte	0x4
	.byte	0x91
	.sleb128 -23824
	.uleb128 0x3a
	.long	.LASF603
	.byte	0x1
	.value	0x251
	.long	0x1113
	.byte	0x4
	.byte	0x91
	.sleb128 -23976
	.uleb128 0x3a
	.long	.LASF604
	.byte	0x1
	.value	0x251
	.long	0x1113
	.byte	0x4
	.byte	0x91
	.sleb128 -24000
	.uleb128 0x3a
	.long	.LASF605
	.byte	0x1
	.value	0x255
	.long	0x1113
	.byte	0x4
	.byte	0x91
	.sleb128 -24024
	.uleb128 0x3a
	.long	.LASF606
	.byte	0x1
	.value	0x255
	.long	0x1113
	.byte	0x4
	.byte	0x91
	.sleb128 -24048
	.uleb128 0x3a
	.long	.LASF607
	.byte	0x1
	.value	0x259
	.long	0x3b
	.byte	0x4
	.byte	0x91
	.sleb128 -23828
	.uleb128 0x3a
	.long	.LASF608
	.byte	0x1
	.value	0x26e
	.long	0x3b
	.byte	0x4
	.byte	0x91
	.sleb128 -23832
	.uleb128 0x3a
	.long	.LASF609
	.byte	0x1
	.value	0x28f
	.long	0x1387
	.byte	0x4
	.byte	0x91
	.sleb128 -24072
	.uleb128 0x3a
	.long	.LASF610
	.byte	0x1
	.value	0x28f
	.long	0x1387
	.byte	0x4
	.byte	0x91
	.sleb128 -24096
	.uleb128 0x3a
	.long	.LASF611
	.byte	0x1
	.value	0x290
	.long	0x1387
	.byte	0x4
	.byte	0x91
	.sleb128 -24120
	.uleb128 0x3a
	.long	.LASF612
	.byte	0x1
	.value	0x290
	.long	0x1387
	.byte	0x4
	.byte	0x91
	.sleb128 -24144
	.uleb128 0x3a
	.long	.LASF613
	.byte	0x1
	.value	0x291
	.long	0x1113
	.byte	0x4
	.byte	0x91
	.sleb128 -24168
	.uleb128 0x3a
	.long	.LASF614
	.byte	0x1
	.value	0x291
	.long	0x1113
	.byte	0x4
	.byte	0x91
	.sleb128 -24192
	.uleb128 0x3a
	.long	.LASF615
	.byte	0x1
	.value	0x292
	.long	0x1387
	.byte	0x4
	.byte	0x91
	.sleb128 -24216
	.uleb128 0x3a
	.long	.LASF616
	.byte	0x1
	.value	0x292
	.long	0x1387
	.byte	0x4
	.byte	0x91
	.sleb128 -24240
	.uleb128 0x3a
	.long	.LASF617
	.byte	0x1
	.value	0x2bd
	.long	0x1113
	.byte	0x4
	.byte	0x91
	.sleb128 -24264
	.uleb128 0x3a
	.long	.LASF618
	.byte	0x1
	.value	0x2be
	.long	0x1113
	.byte	0x4
	.byte	0x91
	.sleb128 -24288
	.uleb128 0x3a
	.long	.LASF619
	.byte	0x1
	.value	0x2cc
	.long	0x1113
	.byte	0x4
	.byte	0x91
	.sleb128 -24312
	.uleb128 0x3a
	.long	.LASF620
	.byte	0x1
	.value	0x2cc
	.long	0x1113
	.byte	0x4
	.byte	0x91
	.sleb128 -24336
	.uleb128 0x3a
	.long	.LASF621
	.byte	0x1
	.value	0x2cd
	.long	0x1387
	.byte	0x4
	.byte	0x91
	.sleb128 -24360
	.uleb128 0x3a
	.long	.LASF622
	.byte	0x1
	.value	0x2cd
	.long	0x1387
	.byte	0x4
	.byte	0x91
	.sleb128 -24384
	.uleb128 0x3a
	.long	.LASF623
	.byte	0x1
	.value	0x2ce
	.long	0x1387
	.byte	0x4
	.byte	0x91
	.sleb128 -24408
	.uleb128 0x3a
	.long	.LASF624
	.byte	0x1
	.value	0x2ce
	.long	0x1387
	.byte	0x4
	.byte	0x91
	.sleb128 -24432
	.uleb128 0x3a
	.long	.LASF625
	.byte	0x1
	.value	0x2cf
	.long	0x1387
	.byte	0x4
	.byte	0x91
	.sleb128 -24456
	.uleb128 0x3a
	.long	.LASF626
	.byte	0x1
	.value	0x2cf
	.long	0x1387
	.byte	0x4
	.byte	0x91
	.sleb128 -24480
	.uleb128 0x3a
	.long	.LASF627
	.byte	0x1
	.value	0x2fb
	.long	0x39a0
	.byte	0x4
	.byte	0x91
	.sleb128 -24832
	.uleb128 0x3a
	.long	.LASF628
	.byte	0x1
	.value	0x2fc
	.long	0x39a0
	.byte	0x4
	.byte	0x91
	.sleb128 -24872
	.uleb128 0x3a
	.long	.LASF629
	.byte	0x1
	.value	0x2fd
	.long	0x39a0
	.byte	0x4
	.byte	0x91
	.sleb128 -24912
	.uleb128 0x3a
	.long	.LASF630
	.byte	0x1
	.value	0x2fe
	.long	0x39a0
	.byte	0x4
	.byte	0x91
	.sleb128 -24952
	.uleb128 0x3a
	.long	.LASF631
	.byte	0x1
	.value	0x300
	.long	0x39a0
	.byte	0x4
	.byte	0x91
	.sleb128 -24992
	.uleb128 0x3a
	.long	.LASF632
	.byte	0x1
	.value	0x300
	.long	0x39a0
	.byte	0x4
	.byte	0x91
	.sleb128 -25032
	.uleb128 0x3a
	.long	.LASF633
	.byte	0x1
	.value	0x300
	.long	0x39a0
	.byte	0x4
	.byte	0x91
	.sleb128 -25072
	.uleb128 0x3a
	.long	.LASF634
	.byte	0x1
	.value	0x300
	.long	0x39a0
	.byte	0x4
	.byte	0x91
	.sleb128 -25112
	.uleb128 0x36
	.string	"mvd"
	.byte	0x1
	.value	0x354
	.long	0x39a0
	.byte	0x4
	.byte	0x91
	.sleb128 -25152
	.uleb128 0x36
	.string	"mad"
	.byte	0x1
	.value	0x355
	.long	0x39a0
	.byte	0x4
	.byte	0x91
	.sleb128 -25192
	.uleb128 0x36
	.string	"b"
	.byte	0x1
	.value	0x36d
	.long	0x3a51
	.byte	0x4
	.byte	0x91
	.sleb128 -26760
	.uleb128 0x3a
	.long	.LASF635
	.byte	0x1
	.value	0x36f
	.long	0x39e6
	.byte	0x4
	.byte	0x91
	.sleb128 -25592
	.uleb128 0x3a
	.long	.LASF512
	.byte	0x1
	.value	0x370
	.long	0x4f7
	.byte	0x4
	.byte	0x91
	.sleb128 -23944
	.uleb128 0x36
	.string	"opp"
	.byte	0x1
	.value	0x376
	.long	0x13b9
	.byte	0x4
	.byte	0x91
	.sleb128 -24504
	.uleb128 0x36
	.string	"opv"
	.byte	0x1
	.value	0x376
	.long	0x13b9
	.byte	0x4
	.byte	0x91
	.sleb128 -24528
	.uleb128 0x36
	.string	"opa"
	.byte	0x1
	.value	0x376
	.long	0x13b9
	.byte	0x4
	.byte	0x91
	.sleb128 -24552
	.uleb128 0x36
	.string	"tpp"
	.byte	0x1
	.value	0x377
	.long	0x13b9
	.byte	0x4
	.byte	0x91
	.sleb128 -24576
	.uleb128 0x36
	.string	"tpv"
	.byte	0x1
	.value	0x377
	.long	0x13b9
	.byte	0x4
	.byte	0x91
	.sleb128 -24600
	.uleb128 0x36
	.string	"tpa"
	.byte	0x1
	.value	0x377
	.long	0x13b9
	.byte	0x4
	.byte	0x91
	.sleb128 -24624
	.uleb128 0x3a
	.long	.LASF636
	.byte	0x1
	.value	0x3b0
	.long	0x596
	.byte	0x4
	.byte	0x91
	.sleb128 -23836
	.uleb128 0x3a
	.long	.LASF637
	.byte	0x1
	.value	0x3b1
	.long	0x596
	.byte	0x4
	.byte	0x91
	.sleb128 -23840
	.uleb128 0x36
	.string	"spp"
	.byte	0x1
	.value	0x3b3
	.long	0x13b9
	.byte	0x4
	.byte	0x91
	.sleb128 -24648
	.uleb128 0x36
	.string	"spv"
	.byte	0x1
	.value	0x3b3
	.long	0x13b9
	.byte	0x4
	.byte	0x91
	.sleb128 -24672
	.uleb128 0x36
	.string	"spa"
	.byte	0x1
	.value	0x3b3
	.long	0x13b9
	.byte	0x4
	.byte	0x91
	.sleb128 -24696
	.uleb128 0x36
	.string	"epp"
	.byte	0x1
	.value	0x3c3
	.long	0x13b9
	.byte	0x4
	.byte	0x91
	.sleb128 -24720
	.uleb128 0x36
	.string	"epv"
	.byte	0x1
	.value	0x3c3
	.long	0x13b9
	.byte	0x4
	.byte	0x91
	.sleb128 -24744
	.uleb128 0x36
	.string	"epa"
	.byte	0x1
	.value	0x3c3
	.long	0x13b9
	.byte	0x4
	.byte	0x91
	.sleb128 -24768
	.uleb128 0x3a
	.long	.LASF638
	.byte	0x1
	.value	0x3ca
	.long	0x596
	.byte	0x4
	.byte	0x91
	.sleb128 -23844
	.uleb128 0x3a
	.long	.LASF639
	.byte	0x1
	.value	0x438
	.long	0x3b
	.byte	0x4
	.byte	0x91
	.sleb128 -23904
	.uleb128 0x3a
	.long	.LASF640
	.byte	0x1
	.value	0x439
	.long	0x3b
	.byte	0x4
	.byte	0x91
	.sleb128 -23908
	.uleb128 0x3a
	.long	.LASF641
	.byte	0x1
	.value	0x43a
	.long	0x3b
	.byte	0x4
	.byte	0x91
	.sleb128 -23912
	.uleb128 0x3a
	.long	.LASF642
	.byte	0x1
	.value	0x43b
	.long	0x3b
	.byte	0x4
	.byte	0x91
	.sleb128 -23916
	.uleb128 0x3a
	.long	.LASF643
	.byte	0x1
	.value	0x43c
	.long	0x3b
	.byte	0x4
	.byte	0x91
	.sleb128 -23920
	.uleb128 0x3a
	.long	.LASF644
	.byte	0x1
	.value	0x43d
	.long	0x3b
	.byte	0x4
	.byte	0x91
	.sleb128 -23924
	.uleb128 0x36
	.string	"tj"
	.byte	0x1
	.value	0x471
	.long	0x1387
	.byte	0x4
	.byte	0x91
	.sleb128 -24792
	.uleb128 0x3b
	.long	.LBB34
	.long	.LBE34
	.long	0x53cf
	.uleb128 0x3a
	.long	.LASF645
	.byte	0x1
	.value	0x3d9
	.long	0x596
	.byte	0x4
	.byte	0x91
	.sleb128 -23848
	.uleb128 0x36
	.string	"p1"
	.byte	0x1
	.value	0x3da
	.long	0x596
	.byte	0x4
	.byte	0x91
	.sleb128 -23852
	.uleb128 0x36
	.string	"p3"
	.byte	0x1
	.value	0x3da
	.long	0x596
	.byte	0x4
	.byte	0x91
	.sleb128 -23856
	.uleb128 0x36
	.string	"p2"
	.byte	0x1
	.value	0x3db
	.long	0x596
	.byte	0x4
	.byte	0x91
	.sleb128 -23860
	.uleb128 0x3a
	.long	.LASF646
	.byte	0x1
	.value	0x3dd
	.long	0x596
	.byte	0x4
	.byte	0x91
	.sleb128 -23864
	.uleb128 0x3a
	.long	.LASF647
	.byte	0x1
	.value	0x3de
	.long	0x596
	.byte	0x4
	.byte	0x91
	.sleb128 -23868
	.uleb128 0x3a
	.long	.LASF648
	.byte	0x1
	.value	0x3de
	.long	0x596
	.byte	0x4
	.byte	0x91
	.sleb128 -23872
	.byte	0x0
	.uleb128 0x3b
	.long	.LBB35
	.long	.LBE35
	.long	0x5451
	.uleb128 0x3a
	.long	.LASF649
	.byte	0x1
	.value	0x3ff
	.long	0x596
	.byte	0x4
	.byte	0x91
	.sleb128 -23876
	.uleb128 0x36
	.string	"p1"
	.byte	0x1
	.value	0x400
	.long	0x596
	.byte	0x4
	.byte	0x91
	.sleb128 -23880
	.uleb128 0x36
	.string	"p3"
	.byte	0x1
	.value	0x400
	.long	0x596
	.byte	0x4
	.byte	0x91
	.sleb128 -23884
	.uleb128 0x36
	.string	"p2"
	.byte	0x1
	.value	0x401
	.long	0x596
	.byte	0x4
	.byte	0x91
	.sleb128 -23888
	.uleb128 0x3a
	.long	.LASF650
	.byte	0x1
	.value	0x403
	.long	0x596
	.byte	0x4
	.byte	0x91
	.sleb128 -23892
	.uleb128 0x3a
	.long	.LASF651
	.byte	0x1
	.value	0x403
	.long	0x596
	.byte	0x4
	.byte	0x91
	.sleb128 -23896
	.uleb128 0x3a
	.long	.LASF646
	.byte	0x1
	.value	0x404
	.long	0x596
	.byte	0x4
	.byte	0x91
	.sleb128 -23900
	.byte	0x0
	.uleb128 0x3b
	.long	.LBB36
	.long	.LBE36
	.long	0x5485
	.uleb128 0x36
	.string	"i"
	.byte	0x1
	.value	0x474
	.long	0x3b
	.byte	0x4
	.byte	0x91
	.sleb128 -23928
	.uleb128 0x39
	.long	.Ldebug_ranges0+0x30
	.uleb128 0x3a
	.long	.LASF652
	.byte	0x1
	.value	0x476
	.long	0x4f7
	.byte	0x4
	.byte	0x91
	.sleb128 -23952
	.byte	0x0
	.byte	0x0
	.uleb128 0x3b
	.long	.LBB39
	.long	.LBE39
	.long	0x54a4
	.uleb128 0x3a
	.long	.LASF568
	.byte	0x1
	.value	0x494
	.long	0x3b
	.byte	0x4
	.byte	0x91
	.sleb128 -23932
	.byte	0x0
	.uleb128 0x2d
	.long	.LBB40
	.long	.LBE40
	.uleb128 0x36
	.string	"i"
	.byte	0x1
	.value	0x4d7
	.long	0x3b
	.byte	0x4
	.byte	0x91
	.sleb128 -23936
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x11d5
	.uleb128 0x6
	.byte	0x4
	.long	0x390e
	.uleb128 0x37
	.byte	0x1
	.long	.LASF653
	.byte	0x1
	.value	0x4e6
	.long	.LASF655
	.long	0x4f7
	.long	.LFB29
	.long	.LFE29
	.long	.LLST20
	.long	0x5527
	.uleb128 0x33
	.string	"min"
	.byte	0x1
	.value	0x4e6
	.long	0x4f7
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x33
	.string	"max"
	.byte	0x1
	.value	0x4e6
	.long	0x4f7
	.byte	0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x2d
	.long	.LBB41
	.long	.LBE41
	.uleb128 0x3a
	.long	.LASF656
	.byte	0x1
	.value	0x4e8
	.long	0x5527
	.byte	0x5
	.byte	0x3
	.long	_ZZ7uniformddE4rmax
	.byte	0x0
	.byte	0x0
	.uleb128 0x7
	.long	0x4f7
	.uleb128 0x37
	.byte	0x1
	.long	.LASF657
	.byte	0x1
	.value	0x4ec
	.long	.LASF658
	.long	0x3b
	.long	.LFB30
	.long	.LFE30
	.long	.LLST21
	.long	0x555d
	.uleb128 0x33
	.string	"max"
	.byte	0x1
	.value	0x4ec
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.byte	0x0
	.uleb128 0x3c
	.byte	0x1
	.string	"VAD"
	.byte	0x1
	.value	0x4f1
	.long	.LASF766
	.long	.LFB31
	.long	.LFE31
	.long	.LLST22
	.long	0x5643
	.uleb128 0x33
	.string	"x1"
	.byte	0x1
	.value	0x4f1
	.long	0x4f7
	.byte	0x2
	.byte	0x91
	.sleb128 -64
	.uleb128 0x33
	.string	"x2"
	.byte	0x1
	.value	0x4f1
	.long	0x4f7
	.byte	0x3
	.byte	0x91
	.sleb128 -72
	.uleb128 0x33
	.string	"x3"
	.byte	0x1
	.value	0x4f1
	.long	0x4f7
	.byte	0x3
	.byte	0x91
	.sleb128 -80
	.uleb128 0x33
	.string	"y1"
	.byte	0x1
	.value	0x4f1
	.long	0x4f7
	.byte	0x3
	.byte	0x91
	.sleb128 -88
	.uleb128 0x33
	.string	"y2"
	.byte	0x1
	.value	0x4f1
	.long	0x4f7
	.byte	0x3
	.byte	0x91
	.sleb128 -96
	.uleb128 0x33
	.string	"y3"
	.byte	0x1
	.value	0x4f1
	.long	0x4f7
	.byte	0x3
	.byte	0x91
	.sleb128 -104
	.uleb128 0x33
	.string	"vel"
	.byte	0x1
	.value	0x4f1
	.long	0x3c9a
	.byte	0x2
	.byte	0x91
	.sleb128 48
	.uleb128 0x33
	.string	"acc"
	.byte	0x1
	.value	0x4f1
	.long	0x3c9a
	.byte	0x2
	.byte	0x91
	.sleb128 52
	.uleb128 0x2d
	.long	.LBB42
	.long	.LBE42
	.uleb128 0x36
	.string	"A"
	.byte	0x1
	.value	0x4f2
	.long	0x4f7
	.byte	0x2
	.byte	0x91
	.sleb128 -16
	.uleb128 0x36
	.string	"B"
	.byte	0x1
	.value	0x4f2
	.long	0x4f7
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x3a
	.long	.LASF659
	.byte	0x1
	.value	0x4f3
	.long	0x4f7
	.byte	0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x3a
	.long	.LASF660
	.byte	0x1
	.value	0x4f3
	.long	0x4f7
	.byte	0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x3a
	.long	.LASF661
	.byte	0x1
	.value	0x4f3
	.long	0x4f7
	.byte	0x2
	.byte	0x91
	.sleb128 -48
	.byte	0x0
	.byte	0x0
	.uleb128 0x38
	.byte	0x1
	.long	.LASF662
	.byte	0x1
	.value	0x4fd
	.long	.LFB32
	.long	.LFE32
	.long	.LLST23
	.long	0x5811
	.uleb128 0x35
	.long	.LASF366
	.byte	0x1
	.value	0x4fd
	.long	0x3d4a
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x35
	.long	.LASF551
	.byte	0x1
	.value	0x4fd
	.long	0x1ca7
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x35
	.long	.LASF219
	.byte	0x1
	.value	0x4fd
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x35
	.long	.LASF663
	.byte	0x1
	.value	0x4fd
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 12
	.uleb128 0x2d
	.long	.LBB43
	.long	.LBE43
	.uleb128 0x36
	.string	"i"
	.byte	0x1
	.value	0x501
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x36
	.string	"j"
	.byte	0x1
	.value	0x501
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x3a
	.long	.LASF664
	.byte	0x1
	.value	0x502
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -44
	.uleb128 0x36
	.string	"pos"
	.byte	0x1
	.value	0x503
	.long	0x5811
	.byte	0x4
	.byte	0x91
	.sleb128 -40440
	.uleb128 0x36
	.string	"vel"
	.byte	0x1
	.value	0x504
	.long	0x5811
	.byte	0x4
	.byte	0x91
	.sleb128 -80440
	.uleb128 0x36
	.string	"acc"
	.byte	0x1
	.value	0x505
	.long	0x5811
	.byte	0x4
	.byte	0x91
	.sleb128 -120440
	.uleb128 0x3a
	.long	.LASF665
	.byte	0x1
	.value	0x506
	.long	0x5811
	.byte	0x4
	.byte	0x91
	.sleb128 -160440
	.uleb128 0x3a
	.long	.LASF666
	.byte	0x1
	.value	0x507
	.long	0x4f7
	.byte	0x3
	.byte	0x91
	.sleb128 -80
	.uleb128 0x36
	.string	"t"
	.byte	0x1
	.value	0x548
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x3a
	.long	.LASF667
	.byte	0x1
	.value	0x549
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -52
	.uleb128 0x3a
	.long	.LASF668
	.byte	0x1
	.value	0x54a
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -56
	.uleb128 0x3a
	.long	.LASF669
	.byte	0x1
	.value	0x54a
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -60
	.uleb128 0x3a
	.long	.LASF670
	.byte	0x1
	.value	0x54b
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -64
	.uleb128 0x2d
	.long	.LBB44
	.long	.LBE44
	.uleb128 0x3a
	.long	.LASF671
	.byte	0x1
	.value	0x56b
	.long	0x39a0
	.byte	0x3
	.byte	0x91
	.sleb128 -120
	.uleb128 0x3a
	.long	.LASF660
	.byte	0x1
	.value	0x56b
	.long	0x39a0
	.byte	0x3
	.byte	0x91
	.sleb128 -160
	.uleb128 0x3a
	.long	.LASF661
	.byte	0x1
	.value	0x56b
	.long	0x39a0
	.byte	0x3
	.byte	0x91
	.sleb128 -200
	.uleb128 0x36
	.string	"tmp"
	.byte	0x1
	.value	0x56b
	.long	0x39a0
	.byte	0x3
	.byte	0x91
	.sleb128 -240
	.uleb128 0x3a
	.long	.LASF672
	.byte	0x1
	.value	0x56b
	.long	0x39a0
	.byte	0x3
	.byte	0x91
	.sleb128 -280
	.uleb128 0x3a
	.long	.LASF673
	.byte	0x1
	.value	0x56b
	.long	0x39a0
	.byte	0x3
	.byte	0x91
	.sleb128 -320
	.uleb128 0x3a
	.long	.LASF674
	.byte	0x1
	.value	0x56c
	.long	0x39a0
	.byte	0x3
	.byte	0x91
	.sleb128 -360
	.uleb128 0x3a
	.long	.LASF675
	.byte	0x1
	.value	0x56c
	.long	0x39a0
	.byte	0x3
	.byte	0x91
	.sleb128 -400
	.uleb128 0x3a
	.long	.LASF676
	.byte	0x1
	.value	0x56c
	.long	0x39a0
	.byte	0x3
	.byte	0x91
	.sleb128 -440
	.uleb128 0x36
	.string	"q"
	.byte	0x1
	.value	0x56d
	.long	0x3b
	.byte	0x3
	.byte	0x91
	.sleb128 -68
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.uleb128 0x8
	.long	0x39a0
	.long	0x5822
	.uleb128 0x1a
	.long	0x50
	.value	0x3e7
	.byte	0x0
	.uleb128 0x38
	.byte	0x1
	.long	.LASF677
	.byte	0x1
	.value	0x637
	.long	.LFB33
	.long	.LFE33
	.long	.LLST24
	.long	0x5884
	.uleb128 0x33
	.string	"wp"
	.byte	0x1
	.value	0x637
	.long	0x3d44
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x35
	.long	.LASF537
	.byte	0x1
	.value	0x637
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x33
	.string	"p"
	.byte	0x1
	.value	0x637
	.long	0x1b23
	.byte	0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x35
	.long	.LASF538
	.byte	0x1
	.value	0x637
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 12
	.uleb128 0x35
	.long	.LASF366
	.byte	0x1
	.value	0x637
	.long	0x3d4a
	.byte	0x2
	.byte	0x91
	.sleb128 16
	.byte	0x0
	.uleb128 0x38
	.byte	0x1
	.long	.LASF678
	.byte	0x1
	.value	0x641
	.long	.LFB34
	.long	.LFE34
	.long	.LLST25
	.long	0x58d7
	.uleb128 0x33
	.string	"wp"
	.byte	0x1
	.value	0x641
	.long	0x3d44
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x35
	.long	.LASF679
	.byte	0x1
	.value	0x641
	.long	0x2474
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x33
	.string	"p"
	.byte	0x1
	.value	0x641
	.long	0x3d44
	.byte	0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x33
	.string	"toF"
	.byte	0x1
	.value	0x641
	.long	0x2474
	.byte	0x2
	.byte	0x91
	.sleb128 12
	.byte	0x0
	.uleb128 0x38
	.byte	0x1
	.long	.LASF680
	.byte	0x1
	.value	0x64b
	.long	.LFB35
	.long	.LFE35
	.long	.LLST26
	.long	0x5a74
	.uleb128 0x35
	.long	.LASF366
	.byte	0x1
	.value	0x64b
	.long	0x3d4a
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x35
	.long	.LASF681
	.byte	0x1
	.value	0x64b
	.long	0x388b
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x2d
	.long	.LBB45
	.long	.LBE45
	.uleb128 0x3a
	.long	.LASF682
	.byte	0x1
	.value	0x64d
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x36
	.string	"wp0"
	.byte	0x1
	.value	0x64e
	.long	0x1113
	.byte	0x3
	.byte	0x91
	.sleb128 -76
	.uleb128 0x36
	.string	"wp1"
	.byte	0x1
	.value	0x64e
	.long	0x1113
	.byte	0x3
	.byte	0x91
	.sleb128 -100
	.uleb128 0x36
	.string	"wp2"
	.byte	0x1
	.value	0x64e
	.long	0x1113
	.byte	0x3
	.byte	0x91
	.sleb128 -124
	.uleb128 0x36
	.string	"wp3"
	.byte	0x1
	.value	0x64e
	.long	0x1113
	.byte	0x3
	.byte	0x91
	.sleb128 -148
	.uleb128 0x36
	.string	"wp4"
	.byte	0x1
	.value	0x64e
	.long	0x1113
	.byte	0x3
	.byte	0x91
	.sleb128 -172
	.uleb128 0x36
	.string	"wp5"
	.byte	0x1
	.value	0x64e
	.long	0x1113
	.byte	0x3
	.byte	0x91
	.sleb128 -196
	.uleb128 0x36
	.string	"wp6"
	.byte	0x1
	.value	0x64e
	.long	0x1113
	.byte	0x3
	.byte	0x91
	.sleb128 -220
	.uleb128 0x3a
	.long	.LASF683
	.byte	0x1
	.value	0x64f
	.long	0x1113
	.byte	0x3
	.byte	0x91
	.sleb128 -244
	.uleb128 0x36
	.string	"acc"
	.byte	0x1
	.value	0x650
	.long	0x1113
	.byte	0x3
	.byte	0x91
	.sleb128 -268
	.uleb128 0x36
	.string	"V0"
	.byte	0x1
	.value	0x650
	.long	0x1113
	.byte	0x3
	.byte	0x91
	.sleb128 -292
	.uleb128 0x36
	.string	"V1"
	.byte	0x1
	.value	0x650
	.long	0x1113
	.byte	0x3
	.byte	0x91
	.sleb128 -316
	.uleb128 0x36
	.string	"f1"
	.byte	0x1
	.value	0x650
	.long	0x1113
	.byte	0x3
	.byte	0x91
	.sleb128 -340
	.uleb128 0x36
	.string	"f2"
	.byte	0x1
	.value	0x650
	.long	0x1113
	.byte	0x3
	.byte	0x91
	.sleb128 -364
	.uleb128 0x36
	.string	"f3"
	.byte	0x1
	.value	0x650
	.long	0x1113
	.byte	0x3
	.byte	0x91
	.sleb128 -388
	.uleb128 0x36
	.string	"p0"
	.byte	0x1
	.value	0x651
	.long	0x5a74
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x36
	.string	"p1"
	.byte	0x1
	.value	0x651
	.long	0x5a74
	.byte	0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0x36
	.string	"p2"
	.byte	0x1
	.value	0x651
	.long	0x5a74
	.byte	0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x36
	.string	"p3"
	.byte	0x1
	.value	0x651
	.long	0x5a74
	.byte	0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x36
	.string	"p4"
	.byte	0x1
	.value	0x651
	.long	0x5a74
	.byte	0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x36
	.string	"p5"
	.byte	0x1
	.value	0x651
	.long	0x5a74
	.byte	0x2
	.byte	0x91
	.sleb128 -44
	.uleb128 0x36
	.string	"p6"
	.byte	0x1
	.value	0x651
	.long	0x5a74
	.byte	0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x3a
	.long	.LASF684
	.byte	0x1
	.value	0x652
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 -52
	.byte	0x0
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x387f
	.uleb128 0x38
	.byte	0x1
	.long	.LASF685
	.byte	0x1
	.value	0x6c2
	.long	.LFB36
	.long	.LFE36
	.long	.LLST27
	.long	0x5ae6
	.uleb128 0x35
	.long	.LASF366
	.byte	0x1
	.value	0x6c2
	.long	0x3d4a
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x35
	.long	.LASF681
	.byte	0x1
	.value	0x6c2
	.long	0x388b
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x33
	.string	"rx"
	.byte	0x1
	.value	0x6c2
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x33
	.string	"rz"
	.byte	0x1
	.value	0x6c2
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 12
	.uleb128 0x2d
	.long	.LBB46
	.long	.LBE46
	.uleb128 0x36
	.string	"p0"
	.byte	0x1
	.value	0x6c4
	.long	0x5a74
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.byte	0x0
	.byte	0x0
	.uleb128 0x38
	.byte	0x1
	.long	.LASF686
	.byte	0x1
	.value	0x6f9
	.long	.LFB37
	.long	.LFE37
	.long	.LLST28
	.long	0x5b72
	.uleb128 0x35
	.long	.LASF366
	.byte	0x1
	.value	0x6f9
	.long	0x3d4a
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x35
	.long	.LASF681
	.byte	0x1
	.value	0x6f9
	.long	0x388b
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x35
	.long	.LASF687
	.byte	0x1
	.value	0x6f9
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x35
	.long	.LASF688
	.byte	0x1
	.value	0x6f9
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 12
	.uleb128 0x35
	.long	.LASF689
	.byte	0x1
	.value	0x6f9
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 16
	.uleb128 0x35
	.long	.LASF690
	.byte	0x1
	.value	0x6f9
	.long	0x596
	.byte	0x2
	.byte	0x91
	.sleb128 20
	.uleb128 0x2d
	.long	.LBB47
	.long	.LBE47
	.uleb128 0x36
	.string	"p0"
	.byte	0x1
	.value	0x6fb
	.long	0x5a74
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.byte	0x0
	.byte	0x0
	.uleb128 0x32
	.byte	0x1
	.long	.LASF691
	.byte	0x1
	.value	0x71b
	.long	0x388b
	.long	.LFB38
	.long	.LFE38
	.long	.LLST29
	.long	0x5bf4
	.uleb128 0x35
	.long	.LASF540
	.byte	0x1
	.value	0x71b
	.long	0x388b
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x35
	.long	.LASF289
	.byte	0x1
	.value	0x71b
	.long	0x18ce
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x35
	.long	.LASF692
	.byte	0x1
	.value	0x71b
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x35
	.long	.LASF693
	.byte	0x1
	.value	0x71b
	.long	0x5a
	.byte	0x2
	.byte	0x91
	.sleb128 12
	.uleb128 0x35
	.long	.LASF232
	.byte	0x1
	.value	0x71b
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 16
	.uleb128 0x2d
	.long	.LBB48
	.long	.LBE48
	.uleb128 0x3a
	.long	.LASF466
	.byte	0x1
	.value	0x71d
	.long	0x5bf4
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.byte	0x0
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x296d
	.uleb128 0x38
	.byte	0x1
	.long	.LASF694
	.byte	0x1
	.value	0x73e
	.long	.LFB39
	.long	.LFE39
	.long	.LLST30
	.long	0x5ca5
	.uleb128 0x35
	.long	.LASF366
	.byte	0x1
	.value	0x73e
	.long	0x3d4a
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x35
	.long	.LASF540
	.byte	0x1
	.value	0x73e
	.long	0x388b
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x2d
	.long	.LBB49
	.long	.LBE49
	.uleb128 0x3a
	.long	.LASF695
	.byte	0x1
	.value	0x73f
	.long	0x388b
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x3a
	.long	.LASF693
	.byte	0x1
	.value	0x740
	.long	0x5a
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x3a
	.long	.LASF466
	.byte	0x1
	.value	0x741
	.long	0x5bf4
	.byte	0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0x3a
	.long	.LASF692
	.byte	0x1
	.value	0x742
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x3a
	.long	.LASF232
	.byte	0x1
	.value	0x743
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x3a
	.long	.LASF696
	.byte	0x1
	.value	0x744
	.long	0x5ca5
	.byte	0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x3a
	.long	.LASF551
	.byte	0x1
	.value	0x745
	.long	0x3879
	.byte	0x2
	.byte	0x91
	.sleb128 -44
	.byte	0x0
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x16e1
	.uleb128 0x32
	.byte	0x1
	.long	.LASF697
	.byte	0x1
	.value	0x757
	.long	0x388b
	.long	.LFB40
	.long	.LFE40
	.long	.LLST31
	.long	0x5d3c
	.uleb128 0x35
	.long	.LASF540
	.byte	0x1
	.value	0x757
	.long	0x388b
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x35
	.long	.LASF366
	.byte	0x1
	.value	0x758
	.long	0x3d4a
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x35
	.long	.LASF289
	.byte	0x1
	.value	0x759
	.long	0x18ce
	.byte	0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x35
	.long	.LASF698
	.byte	0x1
	.value	0x75a
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 12
	.uleb128 0x35
	.long	.LASF699
	.byte	0x1
	.value	0x75b
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 16
	.uleb128 0x35
	.long	.LASF693
	.byte	0x1
	.value	0x75c
	.long	0x5a
	.byte	0x2
	.byte	0x91
	.sleb128 20
	.uleb128 0x2d
	.long	.LBB50
	.long	.LBE50
	.uleb128 0x3a
	.long	.LASF466
	.byte	0x1
	.value	0x75e
	.long	0x5bf4
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.byte	0x0
	.byte	0x0
	.uleb128 0x32
	.byte	0x1
	.long	.LASF700
	.byte	0x1
	.value	0x763
	.long	0x388b
	.long	.LFB41
	.long	.LFE41
	.long	.LLST32
	.long	0x5df0
	.uleb128 0x35
	.long	.LASF366
	.byte	0x1
	.value	0x763
	.long	0x3d4a
	.byte	0x3
	.byte	0x91
	.sleb128 -548
	.uleb128 0x35
	.long	.LASF540
	.byte	0x1
	.value	0x763
	.long	0x388b
	.byte	0x3
	.byte	0x91
	.sleb128 -552
	.uleb128 0x35
	.long	.LASF289
	.byte	0x1
	.value	0x763
	.long	0x18ce
	.byte	0x3
	.byte	0x91
	.sleb128 -556
	.uleb128 0x35
	.long	.LASF692
	.byte	0x1
	.value	0x763
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 12
	.uleb128 0x35
	.long	.LASF693
	.byte	0x1
	.value	0x763
	.long	0x5a
	.byte	0x3
	.byte	0x91
	.sleb128 -560
	.uleb128 0x35
	.long	.LASF232
	.byte	0x1
	.value	0x763
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 20
	.uleb128 0x2d
	.long	.LBB51
	.long	.LBE51
	.uleb128 0x36
	.string	"s"
	.byte	0x1
	.value	0x765
	.long	0x5df0
	.byte	0x3
	.byte	0x91
	.sleb128 -532
	.uleb128 0x3a
	.long	.LASF701
	.byte	0x1
	.value	0x766
	.long	0x5e01
	.byte	0x3
	.byte	0x91
	.sleb128 -536
	.uleb128 0x3a
	.long	.LASF702
	.byte	0x1
	.value	0x767
	.long	0x5bf4
	.byte	0x3
	.byte	0x91
	.sleb128 -540
	.byte	0x0
	.byte	0x0
	.uleb128 0x8
	.long	0x65
	.long	0x5e01
	.uleb128 0x1a
	.long	0x50
	.value	0x1ff
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x28e1
	.uleb128 0x32
	.byte	0x1
	.long	.LASF703
	.byte	0x1
	.value	0x798
	.long	0x388b
	.long	.LFB42
	.long	.LFE42
	.long	.LLST33
	.long	0x5ebb
	.uleb128 0x35
	.long	.LASF366
	.byte	0x1
	.value	0x798
	.long	0x3d4a
	.byte	0x3
	.byte	0x91
	.sleb128 -548
	.uleb128 0x35
	.long	.LASF540
	.byte	0x1
	.value	0x798
	.long	0x388b
	.byte	0x3
	.byte	0x91
	.sleb128 -552
	.uleb128 0x35
	.long	.LASF289
	.byte	0x1
	.value	0x798
	.long	0x18ce
	.byte	0x3
	.byte	0x91
	.sleb128 -556
	.uleb128 0x35
	.long	.LASF692
	.byte	0x1
	.value	0x798
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 12
	.uleb128 0x35
	.long	.LASF693
	.byte	0x1
	.value	0x798
	.long	0x5a
	.byte	0x3
	.byte	0x91
	.sleb128 -560
	.uleb128 0x35
	.long	.LASF232
	.byte	0x1
	.value	0x798
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 20
	.uleb128 0x2d
	.long	.LBB52
	.long	.LBE52
	.uleb128 0x36
	.string	"s"
	.byte	0x1
	.value	0x79a
	.long	0x5df0
	.byte	0x3
	.byte	0x91
	.sleb128 -532
	.uleb128 0x3a
	.long	.LASF701
	.byte	0x1
	.value	0x79b
	.long	0x5e01
	.byte	0x3
	.byte	0x91
	.sleb128 -536
	.uleb128 0x3a
	.long	.LASF702
	.byte	0x1
	.value	0x79c
	.long	0x5bf4
	.byte	0x3
	.byte	0x91
	.sleb128 -540
	.byte	0x0
	.byte	0x0
	.uleb128 0x38
	.byte	0x1
	.long	.LASF704
	.byte	0x1
	.value	0x7d7
	.long	.LFB43
	.long	.LFE43
	.long	.LLST34
	.long	0x5fc0
	.uleb128 0x35
	.long	.LASF366
	.byte	0x1
	.value	0x7d7
	.long	0x3d4a
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x35
	.long	.LASF551
	.byte	0x1
	.value	0x7d7
	.long	0x1ca7
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x35
	.long	.LASF692
	.byte	0x1
	.value	0x7d7
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x35
	.long	.LASF693
	.byte	0x1
	.value	0x7d7
	.long	0x5a
	.byte	0x2
	.byte	0x91
	.sleb128 12
	.uleb128 0x35
	.long	.LASF232
	.byte	0x1
	.value	0x7d7
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 16
	.uleb128 0x35
	.long	.LASF696
	.byte	0x1
	.value	0x7d7
	.long	0x5ca5
	.byte	0x2
	.byte	0x91
	.sleb128 20
	.uleb128 0x2d
	.long	.LBB53
	.long	.LBE53
	.uleb128 0x3a
	.long	.LASF186
	.byte	0x1
	.value	0x7d9
	.long	0x2474
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x3a
	.long	.LASF185
	.byte	0x1
	.value	0x7d9
	.long	0x2474
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x3a
	.long	.LASF705
	.byte	0x1
	.value	0x7d9
	.long	0x2474
	.byte	0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0x3a
	.long	.LASF701
	.byte	0x1
	.value	0x7da
	.long	0x5e01
	.byte	0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x3a
	.long	.LASF702
	.byte	0x1
	.value	0x7db
	.long	0x5bf4
	.byte	0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x3a
	.long	.LASF706
	.byte	0x1
	.value	0x7dc
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -40
	.uleb128 0x3a
	.long	.LASF354
	.byte	0x1
	.value	0x7dd
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -44
	.uleb128 0x3a
	.long	.LASF204
	.byte	0x1
	.value	0x7e2
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -48
	.uleb128 0x3a
	.long	.LASF707
	.byte	0x1
	.value	0x7e3
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -52
	.byte	0x0
	.byte	0x0
	.uleb128 0x32
	.byte	0x1
	.long	.LASF708
	.byte	0x1
	.value	0x80c
	.long	0x3b
	.long	.LFB44
	.long	.LFE44
	.long	.LLST35
	.long	0x62a3
	.uleb128 0x35
	.long	.LASF366
	.byte	0x1
	.value	0x80d
	.long	0x3d4a
	.byte	0x3
	.byte	0x91
	.sleb128 -644
	.uleb128 0x35
	.long	.LASF551
	.byte	0x1
	.value	0x80e
	.long	0x1ca7
	.byte	0x3
	.byte	0x91
	.sleb128 -648
	.uleb128 0x35
	.long	.LASF709
	.byte	0x1
	.value	0x80f
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 8
	.uleb128 0x35
	.long	.LASF710
	.byte	0x1
	.value	0x810
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 12
	.uleb128 0x35
	.long	.LASF707
	.byte	0x1
	.value	0x811
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 16
	.uleb128 0x35
	.long	.LASF185
	.byte	0x1
	.value	0x812
	.long	0x2474
	.byte	0x3
	.byte	0x91
	.sleb128 -652
	.uleb128 0x35
	.long	.LASF186
	.byte	0x1
	.value	0x813
	.long	0x2474
	.byte	0x3
	.byte	0x91
	.sleb128 -656
	.uleb128 0x35
	.long	.LASF711
	.byte	0x1
	.value	0x814
	.long	0x5a
	.byte	0x3
	.byte	0x91
	.sleb128 -660
	.uleb128 0x35
	.long	.LASF712
	.byte	0x1
	.value	0x815
	.long	0x5a
	.byte	0x3
	.byte	0x91
	.sleb128 -664
	.uleb128 0x35
	.long	.LASF232
	.byte	0x1
	.value	0x816
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 36
	.uleb128 0x35
	.long	.LASF713
	.byte	0x1
	.value	0x817
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 40
	.uleb128 0x35
	.long	.LASF193
	.byte	0x1
	.value	0x818
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 44
	.uleb128 0x35
	.long	.LASF696
	.byte	0x1
	.value	0x819
	.long	0x5ca5
	.byte	0x3
	.byte	0x91
	.sleb128 -668
	.uleb128 0x2d
	.long	.LBB54
	.long	.LBE54
	.uleb128 0x3a
	.long	.LASF714
	.byte	0x1
	.value	0x81b
	.long	0x1d2b
	.byte	0x3
	.byte	0x91
	.sleb128 -316
	.uleb128 0x3a
	.long	.LASF715
	.byte	0x1
	.value	0x81b
	.long	0x1d2b
	.byte	0x3
	.byte	0x91
	.sleb128 -320
	.uleb128 0x3a
	.long	.LASF716
	.byte	0x1
	.value	0x81c
	.long	0x1253
	.byte	0x3
	.byte	0x91
	.sleb128 -308
	.uleb128 0x3a
	.long	.LASF717
	.byte	0x1
	.value	0x81d
	.long	0x1113
	.byte	0x3
	.byte	0x91
	.sleb128 -432
	.uleb128 0x3a
	.long	.LASF248
	.byte	0x1
	.value	0x81e
	.long	0x1d9d
	.byte	0x3
	.byte	0x91
	.sleb128 -324
	.uleb128 0x3a
	.long	.LASF595
	.byte	0x1
	.value	0x824
	.long	0x3b
	.byte	0x3
	.byte	0x91
	.sleb128 -328
	.uleb128 0x3a
	.long	.LASF718
	.byte	0x1
	.value	0x826
	.long	0x596
	.byte	0x3
	.byte	0x91
	.sleb128 -332
	.uleb128 0x3a
	.long	.LASF719
	.byte	0x1
	.value	0x827
	.long	0x596
	.byte	0x3
	.byte	0x91
	.sleb128 -336
	.uleb128 0x3a
	.long	.LASF720
	.byte	0x1
	.value	0x828
	.long	0x596
	.byte	0x3
	.byte	0x91
	.sleb128 -340
	.uleb128 0x3a
	.long	.LASF596
	.byte	0x1
	.value	0x829
	.long	0x596
	.byte	0x3
	.byte	0x91
	.sleb128 -344
	.uleb128 0x36
	.string	"b"
	.byte	0x1
	.value	0x832
	.long	0x596
	.byte	0x3
	.byte	0x91
	.sleb128 -348
	.uleb128 0x36
	.string	"f"
	.byte	0x1
	.value	0x832
	.long	0x596
	.byte	0x3
	.byte	0x91
	.sleb128 -352
	.uleb128 0x36
	.string	"p"
	.byte	0x1
	.value	0x832
	.long	0x596
	.byte	0x3
	.byte	0x91
	.sleb128 -356
	.uleb128 0x36
	.string	"g"
	.byte	0x1
	.value	0x832
	.long	0x596
	.byte	0x3
	.byte	0x91
	.sleb128 -360
	.uleb128 0x36
	.string	"l"
	.byte	0x1
	.value	0x832
	.long	0x596
	.byte	0x3
	.byte	0x91
	.sleb128 -364
	.uleb128 0x36
	.string	"h"
	.byte	0x1
	.value	0x832
	.long	0x596
	.byte	0x3
	.byte	0x91
	.sleb128 -368
	.uleb128 0x36
	.string	"t"
	.byte	0x1
	.value	0x832
	.long	0x596
	.byte	0x3
	.byte	0x91
	.sleb128 -372
	.uleb128 0x36
	.string	"r"
	.byte	0x1
	.value	0x832
	.long	0x596
	.byte	0x3
	.byte	0x91
	.sleb128 -376
	.uleb128 0x3a
	.long	.LASF721
	.byte	0x1
	.value	0x85e
	.long	0x2aa
	.byte	0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0x3a
	.long	.LASF722
	.byte	0x1
	.value	0x85f
	.long	0xd8
	.byte	0x3
	.byte	0x91
	.sleb128 -380
	.uleb128 0x3a
	.long	.LASF723
	.byte	0x1
	.value	0x860
	.long	0xd8
	.byte	0x3
	.byte	0x91
	.sleb128 -384
	.uleb128 0x3a
	.long	.LASF582
	.byte	0x1
	.value	0x8d2
	.long	0x596
	.byte	0x3
	.byte	0x91
	.sleb128 -388
	.uleb128 0x36
	.string	"mv"
	.byte	0x1
	.value	0x8d4
	.long	0x13b9
	.byte	0x3
	.byte	0x91
	.sleb128 -456
	.uleb128 0x36
	.string	"ma"
	.byte	0x1
	.value	0x8da
	.long	0x13b9
	.byte	0x3
	.byte	0x91
	.sleb128 -480
	.uleb128 0x3a
	.long	.LASF724
	.byte	0x1
	.value	0x8e2
	.long	0x62a3
	.byte	0x3
	.byte	0x91
	.sleb128 -560
	.uleb128 0x3a
	.long	.LASF725
	.byte	0x1
	.value	0x8e3
	.long	0xff0
	.byte	0x3
	.byte	0x91
	.sleb128 -640
	.uleb128 0x36
	.string	"sum"
	.byte	0x1
	.value	0x8e4
	.long	0x596
	.byte	0x3
	.byte	0x91
	.sleb128 -392
	.uleb128 0x3a
	.long	.LASF80
	.byte	0x1
	.value	0x8e4
	.long	0x596
	.byte	0x3
	.byte	0x91
	.sleb128 -396
	.uleb128 0x36
	.string	"i"
	.byte	0x1
	.value	0x8e5
	.long	0x3b
	.byte	0x3
	.byte	0x91
	.sleb128 -400
	.uleb128 0x36
	.string	"j"
	.byte	0x1
	.value	0x8e5
	.long	0x3b
	.byte	0x3
	.byte	0x91
	.sleb128 -404
	.uleb128 0x36
	.string	"k"
	.byte	0x1
	.value	0x8e5
	.long	0x3b
	.byte	0x3
	.byte	0x91
	.sleb128 -408
	.uleb128 0x2d
	.long	.LBB55
	.long	.LBE55
	.uleb128 0x36
	.string	"tab"
	.byte	0x1
	.value	0x906
	.long	0x65
	.byte	0x3
	.byte	0x91
	.sleb128 -309
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.uleb128 0x8
	.long	0x62b3
	.long	0x62b3
	.uleb128 0x9
	.long	0x50
	.byte	0x13
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x141f
	.uleb128 0x32
	.byte	0x1
	.long	.LASF726
	.byte	0x1
	.value	0x94f
	.long	0x3b
	.long	.LFB45
	.long	.LFE45
	.long	.LLST36
	.long	0x6359
	.uleb128 0x35
	.long	.LASF366
	.byte	0x1
	.value	0x94f
	.long	0x3d4a
	.byte	0x2
	.byte	0x91
	.sleb128 0
	.uleb128 0x35
	.long	.LASF264
	.byte	0x1
	.value	0x94f
	.long	0x6359
	.byte	0x2
	.byte	0x91
	.sleb128 4
	.uleb128 0x2d
	.long	.LBB56
	.long	.LBE56
	.uleb128 0x3a
	.long	.LASF727
	.byte	0x1
	.value	0x951
	.long	0x635f
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x3a
	.long	.LASF728
	.byte	0x1
	.value	0x952
	.long	0x635f
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x3a
	.long	.LASF185
	.byte	0x1
	.value	0x954
	.long	0x2474
	.byte	0x2
	.byte	0x91
	.sleb128 -28
	.uleb128 0x3a
	.long	.LASF186
	.byte	0x1
	.value	0x955
	.long	0x2474
	.byte	0x2
	.byte	0x91
	.sleb128 -32
	.uleb128 0x3a
	.long	.LASF729
	.byte	0x1
	.value	0x95a
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -36
	.uleb128 0x3a
	.long	.LASF730
	.byte	0x1
	.value	0x95b
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 -40
	.byte	0x0
	.byte	0x0
	.uleb128 0x6
	.byte	0x4
	.long	0x1edc
	.uleb128 0x6
	.byte	0x4
	.long	0x17d0
	.uleb128 0x32
	.byte	0x1
	.long	.LASF731
	.byte	0x1
	.value	0x98d
	.long	0x388b
	.long	.LFB46
	.long	.LFE46
	.long	.LLST37
	.long	0x6545
	.uleb128 0x35
	.long	.LASF540
	.byte	0x1
	.value	0x98d
	.long	0x388b
	.byte	0x3
	.byte	0x91
	.sleb128 -388
	.uleb128 0x35
	.long	.LASF366
	.byte	0x1
	.value	0x98e
	.long	0x3d4a
	.byte	0x3
	.byte	0x91
	.sleb128 -392
	.uleb128 0x35
	.long	.LASF289
	.byte	0x1
	.value	0x98f
	.long	0x18ce
	.byte	0x3
	.byte	0x91
	.sleb128 -396
	.uleb128 0x35
	.long	.LASF698
	.byte	0x1
	.value	0x990
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 12
	.uleb128 0x35
	.long	.LASF699
	.byte	0x1
	.value	0x991
	.long	0x3b
	.byte	0x2
	.byte	0x91
	.sleb128 16
	.uleb128 0x35
	.long	.LASF732
	.byte	0x1
	.value	0x992
	.long	0x5a
	.byte	0x3
	.byte	0x91
	.sleb128 -400
	.uleb128 0x2d
	.long	.LBB57
	.long	.LBE57
	.uleb128 0x36
	.string	"s"
	.byte	0x1
	.value	0x99e
	.long	0x5a3
	.byte	0x3
	.byte	0x91
	.sleb128 -292
	.uleb128 0x36
	.string	"i"
	.byte	0x1
	.value	0x99f
	.long	0x3b
	.byte	0x3
	.byte	0x91
	.sleb128 -296
	.uleb128 0x36
	.string	"id"
	.byte	0x1
	.value	0x99f
	.long	0x3b
	.byte	0x3
	.byte	0x91
	.sleb128 -300
	.uleb128 0x36
	.string	"iA"
	.byte	0x1
	.value	0x99f
	.long	0x3b
	.byte	0x3
	.byte	0x91
	.sleb128 -304
	.uleb128 0x3a
	.long	.LASF733
	.byte	0x1
	.value	0x99f
	.long	0x3b
	.byte	0x3
	.byte	0x91
	.sleb128 -308
	.uleb128 0x3a
	.long	.LASF734
	.byte	0x1
	.value	0x9a0
	.long	0x596
	.byte	0x3
	.byte	0x91
	.sleb128 -312
	.uleb128 0x3a
	.long	.LASF735
	.byte	0x1
	.value	0x9a0
	.long	0x596
	.byte	0x3
	.byte	0x91
	.sleb128 -316
	.uleb128 0x3a
	.long	.LASF701
	.byte	0x1
	.value	0x9a1
	.long	0x5e01
	.byte	0x3
	.byte	0x91
	.sleb128 -320
	.uleb128 0x3a
	.long	.LASF702
	.byte	0x1
	.value	0x9a2
	.long	0x5bf4
	.byte	0x3
	.byte	0x91
	.sleb128 -324
	.uleb128 0x3a
	.long	.LASF736
	.byte	0x1
	.value	0x9a3
	.long	0x3b
	.byte	0x3
	.byte	0x91
	.sleb128 -328
	.uleb128 0x3a
	.long	.LASF737
	.byte	0x1
	.value	0x9a3
	.long	0x3b
	.byte	0x3
	.byte	0x91
	.sleb128 -332
	.uleb128 0x3a
	.long	.LASF186
	.byte	0x1
	.value	0x9a4
	.long	0x2474
	.byte	0x3
	.byte	0x91
	.sleb128 -336
	.uleb128 0x3a
	.long	.LASF185
	.byte	0x1
	.value	0x9a4
	.long	0x2474
	.byte	0x3
	.byte	0x91
	.sleb128 -340
	.uleb128 0x3a
	.long	.LASF599
	.byte	0x1
	.value	0x9a5
	.long	0x3b
	.byte	0x3
	.byte	0x91
	.sleb128 -344
	.uleb128 0x3a
	.long	.LASF738
	.byte	0x1
	.value	0x9a6
	.long	0x388b
	.byte	0x3
	.byte	0x91
	.sleb128 -348
	.uleb128 0x3a
	.long	.LASF739
	.byte	0x1
	.value	0x9a6
	.long	0x388b
	.byte	0x3
	.byte	0x91
	.sleb128 -352
	.uleb128 0x3a
	.long	.LASF740
	.byte	0x1
	.value	0x9a6
	.long	0x388b
	.byte	0x3
	.byte	0x91
	.sleb128 -356
	.uleb128 0x3a
	.long	.LASF741
	.byte	0x1
	.value	0x9a6
	.long	0x388b
	.byte	0x3
	.byte	0x91
	.sleb128 -360
	.uleb128 0x3a
	.long	.LASF742
	.byte	0x1
	.value	0x9a6
	.long	0x388b
	.byte	0x3
	.byte	0x91
	.sleb128 -364
	.uleb128 0x3a
	.long	.LASF743
	.byte	0x1
	.value	0x9a6
	.long	0x388b
	.byte	0x3
	.byte	0x91
	.sleb128 -368
	.uleb128 0x3a
	.long	.LASF744
	.byte	0x1
	.value	0x9a6
	.long	0x388b
	.byte	0x3
	.byte	0x91
	.sleb128 -372
	.uleb128 0x3a
	.long	.LASF745
	.byte	0x1
	.value	0x9a6
	.long	0x388b
	.byte	0x3
	.byte	0x91
	.sleb128 -376
	.byte	0x0
	.byte	0x0
	.uleb128 0x3d
	.long	.LASF746
	.byte	0xa
	.byte	0x93
	.long	0x4c4
	.byte	0x1
	.byte	0x1
	.uleb128 0x3e
	.long	.LASF747
	.byte	0x7
	.value	0x886
	.long	0x6560
	.byte	0x1
	.byte	0x1
	.uleb128 0x6
	.byte	0x4
	.long	0x6566
	.uleb128 0x10
	.long	0x32c1
	.uleb128 0x3e
	.long	.LASF748
	.byte	0x7
	.value	0x887
	.long	0x6579
	.byte	0x1
	.byte	0x1
	.uleb128 0x6
	.byte	0x4
	.long	0x657f
	.uleb128 0x10
	.long	0x379d
	.uleb128 0x3f
	.long	.LASF749
	.byte	0x1
	.byte	0xf
	.long	0x1665
	.byte	0x1
	.byte	0x5
	.byte	0x3
	.long	coeff
	.uleb128 0x3d
	.long	.LASF750
	.byte	0xb
	.byte	0x11
	.long	0x2baf
	.byte	0x1
	.byte	0x1
	.uleb128 0x3f
	.long	.LASF698
	.byte	0x1
	.byte	0xe
	.long	0x3b
	.byte	0x1
	.byte	0x5
	.byte	0x3
	.long	layerHeightMM
	.uleb128 0x40
	.long	.LASF751
	.byte	0x1
	.value	0x802
	.long	0x11d5
	.byte	0x1
	.byte	0x5
	.byte	0x3
	.long	viavectpos1
	.uleb128 0x40
	.long	.LASF752
	.byte	0x1
	.value	0x803
	.long	0x1113
	.byte	0x1
	.byte	0x5
	.byte	0x3
	.long	viavecthast1
	.uleb128 0x40
	.long	.LASF753
	.byte	0x1
	.value	0x804
	.long	0x11d5
	.byte	0x1
	.byte	0x5
	.byte	0x3
	.long	viavectpos2
	.uleb128 0x40
	.long	.LASF754
	.byte	0x1
	.value	0x805
	.long	0x1113
	.byte	0x1
	.byte	0x5
	.byte	0x3
	.long	viavecthast2
	.uleb128 0x40
	.long	.LASF755
	.byte	0x1
	.value	0x806
	.long	0x4fe
	.byte	0x1
	.byte	0x5
	.byte	0x3
	.long	viavectabs1
	.uleb128 0x40
	.long	.LASF756
	.byte	0x1
	.value	0x807
	.long	0x4fe
	.byte	0x1
	.byte	0x5
	.byte	0x3
	.long	viavectabs2
	.uleb128 0x40
	.long	.LASF757
	.byte	0x1
	.value	0x808
	.long	0x1113
	.byte	0x1
	.byte	0x5
	.byte	0x3
	.long	toVector
	.uleb128 0x40
	.long	.LASF758
	.byte	0x1
	.value	0x808
	.long	0x1113
	.byte	0x1
	.byte	0x5
	.byte	0x3
	.long	fromVector
	.uleb128 0x40
	.long	.LASF593
	.byte	0x1
	.value	0x809
	.long	0x390e
	.byte	0x1
	.byte	0x5
	.byte	0x3
	.long	startmacro
	.uleb128 0x40
	.long	.LASF594
	.byte	0x1
	.value	0x80a
	.long	0x390e
	.byte	0x1
	.byte	0x5
	.byte	0x3
	.long	endmacro
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
	.uleb128 0x52
	.uleb128 0x1
	.uleb128 0x55
	.uleb128 0x6
	.uleb128 0x10
	.uleb128 0x6
	.byte	0x0
	.byte	0x0
	.uleb128 0x2
	.uleb128 0x16
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
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
	.uleb128 0xe
	.byte	0x0
	.byte	0x0
	.uleb128 0x4
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
	.uleb128 0x5
	.uleb128 0x24
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.byte	0x0
	.byte	0x0
	.uleb128 0x6
	.uleb128 0xf
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x7
	.uleb128 0x26
	.byte	0x0
	.uleb128 0x49
	.uleb128 0x13
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
	.uleb128 0xf
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.byte	0x0
	.byte	0x0
	.uleb128 0xb
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0xc
	.uleb128 0xd
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0xd
	.uleb128 0x17
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0xe
	.uleb128 0xd
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0xf
	.uleb128 0xd
	.byte	0x0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x10
	.uleb128 0x35
	.byte	0x0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x11
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x12
	.uleb128 0xd
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x13
	.uleb128 0x16
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.byte	0x0
	.byte	0x0
	.uleb128 0x14
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0x5
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x15
	.uleb128 0xd
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x16
	.uleb128 0x16
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x17
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0x6
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x18
	.uleb128 0x17
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x19
	.uleb128 0xd
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x1a
	.uleb128 0x21
	.byte	0x0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0x5
	.byte	0x0
	.byte	0x0
	.uleb128 0x1b
	.uleb128 0xd
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.uleb128 0x1c
	.uleb128 0x13
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0x5
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x1d
	.uleb128 0x2
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0x5
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x1e
	.uleb128 0xd
	.byte	0x0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xa
	.uleb128 0x32
	.uleb128 0xb
	.byte	0x0
	.byte	0x0
	.uleb128 0x1f
	.uleb128 0xd
	.byte	0x0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x38
	.uleb128 0xa
	.uleb128 0x32
	.uleb128 0xb
	.byte	0x0
	.byte	0x0
	.uleb128 0x20
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
	.uleb128 0x2007
	.uleb128 0xe
	.uleb128 0x32
	.uleb128 0xb
	.uleb128 0x3c
	.uleb128 0xc
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x21
	.uleb128 0x5
	.byte	0x0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x34
	.uleb128 0xc
	.byte	0x0
	.byte	0x0
	.uleb128 0x22
	.uleb128 0x5
	.byte	0x0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x23
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
	.uleb128 0x2007
	.uleb128 0xe
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x32
	.uleb128 0xb
	.uleb128 0x3c
	.uleb128 0xc
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x24
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
	.uleb128 0x3c
	.uleb128 0xc
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x25
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
	.uleb128 0x2007
	.uleb128 0xe
	.uleb128 0x3c
	.uleb128 0xc
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x26
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
	.uleb128 0x2007
	.uleb128 0xe
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0xc
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x27
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
	.uleb128 0x2007
	.uleb128 0xe
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3c
	.uleb128 0xc
	.byte	0x0
	.byte	0x0
	.uleb128 0x28
	.uleb128 0x10
	.byte	0x0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x29
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
	.uleb128 0x2a
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
	.uleb128 0x2b
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
	.uleb128 0x2c
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
	.uleb128 0x2d
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.byte	0x0
	.byte	0x0
	.uleb128 0x2e
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
	.uleb128 0x2f
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
	.uleb128 0x30
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
	.uleb128 0x2007
	.uleb128 0xe
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
	.uleb128 0x31
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
	.uleb128 0x2007
	.uleb128 0xe
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
	.uleb128 0x32
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
	.uleb128 0x33
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
	.uleb128 0x34
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
	.uleb128 0x2007
	.uleb128 0xe
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
	.uleb128 0x35
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
	.uleb128 0x36
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
	.uleb128 0x37
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
	.uleb128 0x2007
	.uleb128 0xe
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
	.uleb128 0x38
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
	.uleb128 0x39
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x55
	.uleb128 0x6
	.byte	0x0
	.byte	0x0
	.uleb128 0x3a
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
	.uleb128 0x3b
	.uleb128 0xb
	.byte	0x1
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x1
	.uleb128 0x13
	.byte	0x0
	.byte	0x0
	.uleb128 0x3c
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x2007
	.uleb128 0xe
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
	.uleb128 0x3d
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
	.uleb128 0x3c
	.uleb128 0xc
	.byte	0x0
	.byte	0x0
	.uleb128 0x3e
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
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3c
	.uleb128 0xc
	.byte	0x0
	.byte	0x0
	.uleb128 0x3f
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
	.uleb128 0x40
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
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x2
	.uleb128 0xa
	.byte	0x0
	.byte	0x0
	.byte	0x0
	.section	.debug_pubnames,"",@progbits
	.long	0x395
	.value	0x2
	.long	.Ldebug_info0
	.long	0x6674
	.long	0x3cac
	.string	"convert"
	.long	0x3d50
	.string	"split"
	.long	0x3f03
	.string	"convertsplit"
	.long	0x4078
	.string	"spiralMacro"
	.long	0x4193
	.string	"spiralspeed"
	.long	0x41c8
	.string	"uplineMacro"
	.long	0x42af
	.string	"uplinespeed"
	.long	0x42e4
	.string	"fastUplineMacro"
	.long	0x43cb
	.string	"fastuplinespeed"
	.long	0x4404
	.string	"downlineMacro"
	.long	0x44eb
	.string	"downlinespeed"
	.long	0x4523
	.string	"fastDownlineMacro"
	.long	0x4625
	.string	"fastdownlinespeed"
	.long	0x4661
	.string	"blendquintic"
	.long	0x47b2
	.string	"blendquinticmaxvel"
	.long	0x48d7
	.string	"blendquinticmaxacc"
	.long	0x4a47
	.string	"blendcubic"
	.long	0x4b84
	.string	"blendcubicmaxvel"
	.long	0x4c6f
	.string	"blendcubicmaxacc"
	.long	0x4d42
	.string	"trajopt"
	.long	0x54cb
	.string	"uniform"
	.long	0x552c
	.string	"randomindex"
	.long	0x555d
	.string	"VAD"
	.long	0x5643
	.string	"jerkMinimizer"
	.long	0x5822
	.string	"convertToFrame"
	.long	0x5884
	.string	"convertToFrame_vectorstyle"
	.long	0x58d7
	.string	"blendCorner3"
	.long	0x5a7a
	.string	"seekCorner"
	.long	0x5ae6
	.string	"seekCornerX"
	.long	0x5b72
	.string	"expandPath"
	.long	0x5bfa
	.string	"expandBopt"
	.long	0x5cab
	.string	"generateProgram"
	.long	0x5d3c
	.string	"expandPathGeneralBoptInHeader"
	.long	0x5e07
	.string	"expandPathGeneralBoptOutHeader"
	.long	0x5ebb
	.string	"expandPathBoptGeneral"
	.long	0x5fc0
	.string	"expandPathBoptGeneric"
	.long	0x62b9
	.string	"expandBoptLoader"
	.long	0x6365
	.string	"generateProgramNS"
	.long	0x6584
	.string	"coeff"
	.long	0x65a3
	.string	"layerHeightMM"
	.long	0x65b5
	.string	"viavectpos1"
	.long	0x65c8
	.string	"viavecthast1"
	.long	0x65db
	.string	"viavectpos2"
	.long	0x65ee
	.string	"viavecthast2"
	.long	0x6601
	.string	"viavectabs1"
	.long	0x6614
	.string	"viavectabs2"
	.long	0x6627
	.string	"toVector"
	.long	0x663a
	.string	"fromVector"
	.long	0x664d
	.string	"startmacro"
	.long	0x6660
	.string	"endmacro"
	.long	0x0
	.section	.debug_aranges,"",@progbits
	.long	0x44
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x4
	.byte	0x0
	.value	0x0
	.value	0x0
	.long	.Ltext0
	.long	.Letext0-.Ltext0
	.long	.LFB13
	.long	.LFE13-.LFB13
	.long	.LFB15
	.long	.LFE15-.LFB15
	.long	.LFB17
	.long	.LFE17-.LFB17
	.long	.LFB19
	.long	.LFE19-.LFB19
	.long	.LFB21
	.long	.LFE21-.LFB21
	.long	0x0
	.long	0x0
	.section	.debug_ranges,"",@progbits
.Ldebug_ranges0:
	.long	.LBB20
	.long	.LBE20
	.long	.LBB21
	.long	.LBE21
	.long	0x0
	.long	0x0
	.long	.LBB28
	.long	.LBE28
	.long	.LBB29
	.long	.LBE29
	.long	0x0
	.long	0x0
	.long	.LBB37
	.long	.LBE37
	.long	.LBB38
	.long	.LBE38
	.long	0x0
	.long	0x0
	.long	.Ltext0
	.long	.Letext0
	.long	.LFB9
	.long	.LFE9
	.long	.LFB10
	.long	.LFE10
	.long	.LFB11
	.long	.LFE11
	.long	.LFB12
	.long	.LFE12
	.long	.LFB13
	.long	.LFE13
	.long	.LFB14
	.long	.LFE14
	.long	.LFB15
	.long	.LFE15
	.long	.LFB16
	.long	.LFE16
	.long	.LFB17
	.long	.LFE17
	.long	.LFB18
	.long	.LFE18
	.long	.LFB19
	.long	.LFE19
	.long	.LFB20
	.long	.LFE20
	.long	.LFB21
	.long	.LFE21
	.long	.LFB22
	.long	.LFE22
	.long	.LFB23
	.long	.LFE23
	.long	.LFB24
	.long	.LFE24
	.long	.LFB25
	.long	.LFE25
	.long	.LFB26
	.long	.LFE26
	.long	.LFB27
	.long	.LFE27
	.long	.LFB28
	.long	.LFE28
	.long	.LFB29
	.long	.LFE29
	.long	.LFB30
	.long	.LFE30
	.long	.LFB31
	.long	.LFE31
	.long	.LFB32
	.long	.LFE32
	.long	.LFB33
	.long	.LFE33
	.long	.LFB34
	.long	.LFE34
	.long	.LFB35
	.long	.LFE35
	.long	.LFB36
	.long	.LFE36
	.long	.LFB37
	.long	.LFE37
	.long	.LFB38
	.long	.LFE38
	.long	.LFB39
	.long	.LFE39
	.long	.LFB40
	.long	.LFE40
	.long	.LFB41
	.long	.LFE41
	.long	.LFB42
	.long	.LFE42
	.long	.LFB43
	.long	.LFE43
	.long	.LFB44
	.long	.LFE44
	.long	.LFB45
	.long	.LFE45
	.long	.LFB46
	.long	.LFE46
	.long	0x0
	.long	0x0
	.section	.debug_str,"MS",@progbits,1
.LASF125:
	.string	"loadcell"
.LASF33:
	.string	"__align"
.LASF169:
	.string	"tmpnTimingItem"
.LASF491:
	.string	"icpcons"
.LASF71:
	.string	"_unused2"
.LASF707:
	.string	"pathidx"
.LASF57:
	.string	"_fileno"
.LASF22:
	.string	"__pthread_mutex_s"
.LASF517:
	.string	"_ZN4bane12findgradientERK8baneConfPdi"
.LASF263:
	.string	"bopted"
.LASF195:
	.string	"viapos"
.LASF199:
	.string	"tmpnBoptCoeff"
.LASF87:
	.string	"comskstruct"
.LASF682:
	.string	"frameIdx"
.LASF261:
	.string	"handle"
.LASF36:
	.string	"__total_seq"
.LASF454:
	.string	"m_simulateTRIO"
.LASF173:
	.string	"tmpnJoints"
.LASF325:
	.string	"change"
.LASF444:
	.string	"m_mpnhome"
.LASF229:
	.string	"samplesBetweenKeypoints"
.LASF579:
	.string	"trajopt"
.LASF486:
	.string	"udpagents"
.LASF572:
	.string	"blendquinticmaxacc"
.LASF603:
	.string	"toposloc"
.LASF400:
	.string	"tmpnLanguageLine"
.LASF723:
	.string	"eitem"
.LASF665:
	.string	"jerk"
.LASF497:
	.string	"tpathdef"
.LASF62:
	.string	"_shortbuf"
.LASF466:
	.string	"ppscript"
.LASF155:
	.string	"ambient"
.LASF514:
	.string	"findalpha"
.LASF138:
	.string	"tmpnDIO"
.LASF100:
	.string	"numOfModules"
.LASF545:
	.string	"convertsplit"
.LASF391:
	.string	"massDisplacement"
.LASF203:
	.string	"tmpnPatternItem"
.LASF506:
	.string	"tmpnJointsDUnion"
.LASF424:
	.string	"m_unit"
.LASF422:
	.string	"m_pulses"
.LASF156:
	.string	"specular"
.LASF528:
	.string	"getResult"
.LASF194:
	.string	"viatype"
.LASF377:
	.string	"startSpeed"
.LASF523:
	.string	"setLimits"
.LASF307:
	.string	"topval"
.LASF43:
	.string	"_flags"
.LASF255:
	.string	"next"
.LASF362:
	.string	"ctrltype"
.LASF207:
	.string	"length"
.LASF521:
	.string	"_ZN4bane14gradientMetodeEv"
.LASF551:
	.string	"ptrpath"
.LASF426:
	.string	"m_p_gain"
.LASF12:
	.string	"__off_t"
.LASF530:
	.string	"cubicpoly"
.LASF37:
	.string	"__wakeup_seq"
.LASF649:
	.string	"scaleout"
.LASF63:
	.string	"_lock"
.LASF290:
	.string	"tmpnStateMachineState"
.LASF371:
	.string	"scriptname"
.LASF512:
	.string	"alpha"
.LASF221:
	.string	"positionhint"
.LASF500:
	.string	"macroparamstruct"
.LASF273:
	.string	"sndbuf_idx"
.LASF758:
	.string	"fromVector"
.LASF323:
	.string	"new_istate"
.LASF219:
	.string	"tcpidx"
.LASF691:
	.string	"expandPath"
.LASF713:
	.string	"boptMode"
.LASF658:
	.string	"_Z11randomindexi"
.LASF439:
	.string	"m_min"
.LASF535:
	.string	"_ZN4bane11ddcubicpolyEid"
.LASF499:
	.string	"frameidx"
.LASF337:
	.string	"numlink"
.LASF38:
	.string	"__woken_seq"
.LASF133:
	.string	"mask"
.LASF101:
	.string	"iotab"
.LASF510:
	.string	"maxvels"
.LASF390:
	.string	"mass"
.LASF234:
	.string	"maxTime"
.LASF754:
	.string	"viavecthast2"
.LASF534:
	.string	"ddcubicpoly"
.LASF83:
	.string	"minor"
.LASF408:
	.string	"tmpnScripts"
.LASF370:
	.string	"touch"
.LASF188:
	.string	"toItem"
.LASF678:
	.string	"convertToFrame_vectorstyle"
.LASF39:
	.string	"__mutex"
.LASF540:
	.string	"ptrcmd"
.LASF121:
	.string	"ignoreError"
.LASF49:
	.string	"_IO_write_end"
.LASF433:
	.string	"m_decel"
.LASF610:
	.string	"tojoints"
.LASF267:
	.string	"transformation"
.LASF765:
	.string	"_Z17fastDownlineMacroP9tmpnRobotP11tmpnPathDefPiffP10tmpnVectoriii"
.LASF28:
	.string	"__owner"
.LASF698:
	.string	"layerHeightMM"
.LASF185:
	.string	"fromFrame"
.LASF88:
	.string	"module_name"
.LASF312:
	.string	"remote"
.LASF638:
	.string	"attime"
.LASF595:
	.string	"blendtype"
.LASF472:
	.string	"remotevalue"
.LASF684:
	.string	"arczy4"
.LASF627:
	.string	"startpos"
.LASF339:
	.string	"freq"
.LASF452:
	.string	"m_showPoint"
.LASF235:
	.string	"maxSpeed"
.LASF672:
	.string	"tmp2"
.LASF549:
	.string	"spiralMacro"
.LASF26:
	.string	"__lock"
.LASF95:
	.string	"odata"
.LASF655:
	.string	"_Z7uniformdd"
.LASF469:
	.string	"tmpnRemoteStateMachines"
.LASF215:
	.string	"selectedItem"
.LASF569:
	.string	"blendquinticmaxvel"
.LASF253:
	.string	"firstpoint"
.LASF397:
	.string	"numofStateTeksts"
.LASF360:
	.string	"calx"
.LASF361:
	.string	"caly"
.LASF389:
	.string	"tmpnLink"
.LASF652:
	.string	"thistime"
.LASF485:
	.string	"remotehosts"
.LASF625:
	.string	"via1veljoint"
.LASF686:
	.string	"seekCornerX"
.LASF464:
	.string	"accessory"
.LASF110:
	.string	"macConnect"
.LASF626:
	.string	"via2veljoint"
.LASF428:
	.string	"m_d_gain"
.LASF520:
	.string	"_ZN4bane11cubickoeffsERK8baneConfR6koeffsi"
.LASF349:
	.string	"clients_maxidx"
.LASF717:
	.string	"zero"
.LASF615:
	.string	"fromveljoint"
.LASF519:
	.string	"gradientMetode"
.LASF667:
	.string	"maxi"
.LASF40:
	.string	"__nwaiters"
.LASF674:
	.string	"best"
.LASF98:
	.string	"type"
.LASF480:
	.string	"accessories"
.LASF581:
	.string	"trajectorytype"
.LASF230:
	.string	"runbopt"
.LASF423:
	.string	"m_gearing"
.LASF102:
	.string	"highadr"
.LASF222:
	.string	"tmpnHPoint"
.LASF145:
	.string	"numOfInBits"
.LASF462:
	.string	"tool"
.LASF580:
	.string	"pathidnum"
.LASF438:
	.string	"m_lifeTimeGear"
.LASF636:
	.string	"acceldivisor"
.LASF324:
	.string	"stop"
.LASF192:
	.string	"mode"
.LASF724:
	.string	"pvia"
.LASF419:
	.string	"m_ratedRPM"
.LASF727:
	.string	"fromPatternItem"
.LASF31:
	.string	"__data"
.LASF209:
	.string	"maxpush"
.LASF56:
	.string	"_chain"
.LASF277:
	.string	"safe"
.LASF492:
	.string	"scripts"
.LASF227:
	.string	"seqnum"
.LASF180:
	.string	"tmpnBoptMacroItem"
.LASF313:
	.string	"tmpnStateMachineLink"
.LASF5:
	.string	"unsigned char"
.LASF363:
	.string	"plant"
.LASF646:
	.string	"dscale"
.LASF559:
	.string	"_Z15fastUplineMacroP9tmpnRobotP11tmpnPathDefPiffP10tmpnVectoriii"
.LASF249:
	.string	"from"
.LASF762:
	.string	"_IO_lock_t"
.LASF86:
	.string	"float"
.LASF197:
	.string	"macro"
.LASF468:
	.string	"statemachine"
.LASF633:
	.string	"slutposrad"
.LASF233:
	.string	"splineorder"
.LASF265:
	.string	"tmpnAccessory"
.LASF336:
	.string	"output"
.LASF588:
	.string	"tovel"
.LASF442:
	.string	"m_localTrans"
.LASF154:
	.string	"diffuse"
.LASF430:
	.string	"m_vff_gain"
.LASF166:
	.string	"tmpnFrame"
.LASF294:
	.string	"timeout"
.LASF165:
	.string	"absu"
.LASF554:
	.string	"spiralspeed"
.LASF590:
	.string	"via1vel"
.LASF217:
	.string	"items"
.LASF252:
	.string	"script"
.LASF29:
	.string	"__kind"
.LASF522:
	.string	"init"
.LASF296:
	.string	"maxsize"
.LASF213:
	.string	"pspeeds"
.LASF94:
	.string	"idata"
.LASF639:
	.string	"innos"
.LASF243:
	.string	"cLayer"
.LASF477:
	.string	"patterns"
.LASF17:
	.string	"tv_usec"
.LASF725:
	.string	"valvia"
.LASF405:
	.string	"language"
.LASF728:
	.string	"toPatternItem"
.LASF673:
	.string	"tmp3"
.LASF583:
	.string	"fromTCPidx"
.LASF338:
	.string	"tmpnUdpQuestionStruct"
.LASF505:
	.string	"tmpnJointsD"
.LASF99:
	.string	"ipaddr"
.LASF675:
	.string	"best2"
.LASF676:
	.string	"best3"
.LASF147:
	.string	"inconnect"
.LASF384:
	.string	"stmServerPort"
.LASF48:
	.string	"_IO_write_ptr"
.LASF281:
	.string	"subtype"
.LASF616:
	.string	"toveljoint"
.LASF115:
	.string	"tmpnMac"
.LASF183:
	.string	"tmpnBoptParamItem"
.LASF374:
	.string	"path_debug"
.LASF565:
	.string	"fastdownlinespeed"
.LASF718:
	.string	"maxlength"
.LASF232:
	.string	"loadgroup"
.LASF402:
	.string	"tmpnLanguage"
.LASF15:
	.string	"__suseconds_t"
.LASF272:
	.string	"repeat"
.LASF738:
	.string	"start0"
.LASF401:
	.string	"english"
.LASF280:
	.string	"link"
.LASF483:
	.string	"remotestatemachines"
.LASF316:
	.string	"tmpnStateMachine"
.LASF276:
	.string	"remotehost"
.LASF679:
	.string	"fromF"
.LASF467:
	.string	"tmpnStateMachines"
.LASF132:
	.string	"shift"
.LASF680:
	.string	"blendCorner3"
.LASF32:
	.string	"__size"
.LASF719:
	.string	"maxheight"
.LASF706:
	.string	"maxlayers"
.LASF345:
	.string	"maxqlines"
.LASF576:
	.string	"blendcubic"
.LASF196:
	.string	"viavel"
.LASF735:
	.string	"difw"
.LASF712:
	.string	"endItem"
.LASF392:
	.string	"inertia"
.LASF695:
	.string	"ppcmd"
.LASF591:
	.string	"via2pos"
.LASF81:
	.string	"fdata"
.LASF696:
	.string	"BoptCoeffs"
.LASF376:
	.string	"io_debug"
.LASF594:
	.string	"endmacro"
.LASF10:
	.string	"size_t"
.LASF306:
	.string	"fitem"
.LASF760:
	.string	"genscript.c"
.LASF27:
	.string	"__count"
.LASF358:
	.string	"offx"
.LASF359:
	.string	"offy"
.LASF445:
	.string	"m_state"
.LASF670:
	.string	"totjerk"
.LASF507:
	.string	"baneConf"
.LASF489:
	.string	"loadcells"
.LASF516:
	.string	"_ZN4bane9findalphaERK8baneConfi"
.LASF139:
	.string	"cleardioerror"
.LASF129:
	.string	"connectType"
.LASF123:
	.string	"fastmoxa"
.LASF91:
	.string	"numOfInWords"
.LASF311:
	.string	"linkvalue"
.LASF274:
	.string	"sndbuf"
.LASF52:
	.string	"_IO_save_base"
.LASF321:
	.string	"istate"
.LASF562:
	.string	"downlinespeed"
.LASF287:
	.string	"iotype"
.LASF584:
	.string	"toTCPidx"
.LASF471:
	.string	"tmpnRemoteValues"
.LASF685:
	.string	"seekCorner"
.LASF351:
	.string	"client"
.LASF720:
	.string	"minheight"
.LASF681:
	.string	"corner"
.LASF515:
	.string	"findgradient"
.LASF137:
	.string	"connect"
.LASF331:
	.string	"numvalue"
.LASF748:
	.string	"tworkcell"
.LASF66:
	.string	"__pad2"
.LASF134:
	.string	"text"
.LASF247:
	.string	"tmpnPathKey"
.LASF329:
	.string	"debugvalue"
.LASF697:
	.string	"generateProgram"
.LASF737:
	.string	"fromFrameIdx"
.LASF282:
	.string	"tmpnStateMachineIO"
.LASF369:
	.string	"workcellid"
.LASF124:
	.string	"tmpnLoadCells"
.LASF436:
	.string	"m_felimit"
.LASF298:
	.string	"newtablesize"
.LASF382:
	.string	"scriptExec"
.LASF118:
	.string	"numOfMotors"
.LASF700:
	.string	"expandPathGeneralBoptInHeader"
.LASF708:
	.string	"expandPathBoptGeneric"
.LASF620:
	.string	"via2delta"
.LASF231:
	.string	"spline"
.LASF189:
	.string	"fromPattern"
.LASF348:
	.string	"servers_maxidx"
.LASF293:
	.string	"tmpnStateMachineTimeout"
.LASF668:
	.string	"maxjerk"
.LASF170:
	.string	"value"
.LASF599:
	.string	"exectime"
.LASF135:
	.string	"stbstruct"
.LASF163:
	.string	"absv"
.LASF164:
	.string	"absw"
.LASF160:
	.string	"absx"
.LASF161:
	.string	"absy"
.LASF162:
	.string	"absz"
.LASF73:
	.string	"_next"
.LASF352:
	.string	"tmpnPPScriptItem"
.LASF714:
	.string	"thisitemstart"
.LASF184:
	.string	"tmpnBoptCoeffItem"
.LASF357:
	.string	"initialized"
.LASF198:
	.string	"params"
.LASF617:
	.string	"via1postot"
.LASF89:
	.string	"address"
.LASF398:
	.string	"stateteksts"
.LASF575:
	.string	"tick"
.LASF378:
	.string	"password"
.LASF136:
	.string	"typeStr"
.LASF558:
	.string	"fastUplineMacro"
.LASF271:
	.string	"alive"
.LASF664:
	.string	"tvar"
.LASF613:
	.string	"fromdelta"
.LASF753:
	.string	"viavectpos2"
.LASF181:
	.string	"integer"
.LASF644:
	.string	"totnos"
.LASF41:
	.string	"__broadcast_seq"
.LASF106:
	.string	"tmpnComSKs"
.LASF379:
	.string	"checkWeigher"
.LASF705:
	.string	"homeFrame"
.LASF21:
	.string	"__pthread_slist_t"
.LASF417:
	.string	"m_ratedRpmGear"
.LASF23:
	.string	"<anonymous union>"
.LASF432:
	.string	"m_accel"
.LASF353:
	.string	"tmpnPPScript"
.LASF537:
	.string	"fromIdx"
.LASF193:
	.string	"pathtype"
.LASF388:
	.string	"itemsperlift"
.LASF564:
	.string	"fastuplinespeed"
.LASF250:
	.string	"tmpnPathHandle"
.LASF543:
	.string	"lnos"
.LASF128:
	.string	"udata"
.LASF239:
	.string	"maxpidx"
.LASF410:
	.string	"m_name"
.LASF642:
	.string	"endmacronos"
.LASF487:
	.string	"dios"
.LASF214:
	.string	"tmpnCPPattern"
.LASF404:
	.string	"numoflanguages"
.LASF635:
	.string	"baneRes"
.LASF335:
	.string	"numoutput"
.LASF631:
	.string	"startposrad"
.LASF289:
	.string	"level"
.LASF386:
	.string	"tmpnTCP"
.LASF746:
	.string	"stderr"
.LASF179:
	.string	"tmpnBoptViaVector"
.LASF327:
	.string	"timer"
.LASF107:
	.string	"name"
.LASF536:
	.string	"convert"
.LASF341:
	.string	"responseformat"
.LASF315:
	.string	"localname"
.LASF74:
	.string	"_sbuf"
.LASF342:
	.string	"maxresponseval"
.LASF730:
	.string	"toLayer"
.LASF54:
	.string	"_IO_save_end"
.LASF663:
	.string	"jerkscale"
.LASF632:
	.string	"startvelrad"
.LASF20:
	.string	"__next"
.LASF541:
	.string	"framename"
.LASF429:
	.string	"m_ov_gain"
.LASF257:
	.string	"flag"
.LASF303:
	.string	"fsum"
.LASF14:
	.string	"__time_t"
.LASF373:
	.string	"mc_task_debug"
.LASF585:
	.string	"frompos"
.LASF434:
	.string	"m_creep"
.LASF228:
	.string	"numofsamples"
.LASF501:
	.string	"amplitude"
.LASF552:
	.string	"curidx"
.LASF766:
	.string	"_Z3VADddddddPdS_"
.LASF605:
	.string	"tovelloc"
.LASF319:
	.string	"delaystop"
.LASF236:
	.string	"keypoint"
.LASF104:
	.string	"adrcount"
.LASF218:
	.string	"tmpnKeyPoint"
.LASF260:
	.string	"tmpnPathItem"
.LASF372:
	.string	"simulateMC"
.LASF395:
	.string	"tmpnStateTeksts"
.LASF262:
	.string	"pathdef"
.LASF208:
	.string	"tmpnCPPatternItem"
.LASF3:
	.string	"short unsigned int"
.LASF284:
	.string	"loadcellconnect"
.LASF7:
	.string	"signed char"
.LASF634:
	.string	"slutvelrad"
.LASF330:
	.string	"numstate"
.LASF751:
	.string	"viavectpos1"
.LASF567:
	.string	"ttime"
.LASF479:
	.string	"tools"
.LASF151:
	.string	"icpcon"
.LASF116:
	.string	"filename"
.LASF709:
	.string	"cALayer"
.LASF148:
	.string	"outconnect"
.LASF461:
	.string	"tmpnTools"
.LASF732:
	.string	"ppscriptnameA"
.LASF733:
	.string	"bagsPrLayer"
.LASF598:
	.string	"pcuridx"
.LASF736:
	.string	"toFrameIdx"
.LASF508:
	.string	"koeffs"
.LASF328:
	.string	"timerstate"
.LASF495:
	.string	"PPSCRIPTSTRUCT"
.LASF548:
	.string	"endpoint"
.LASF488:
	.string	"comsks"
.LASF177:
	.string	"numofparams"
.LASF13:
	.string	"__off64_t"
.LASF108:
	.string	"maxidx"
.LASF375:
	.string	"statemachine_debug"
.LASF46:
	.string	"_IO_read_base"
.LASF460:
	.string	"tmpnItems"
.LASF64:
	.string	"_offset"
.LASF431:
	.string	"m_speed"
.LASF251:
	.string	"state"
.LASF51:
	.string	"_IO_buf_end"
.LASF310:
	.string	"cppattern"
.LASF210:
	.string	"gettime"
.LASF457:
	.string	"tmpnRobots"
.LASF144:
	.string	"dosetup"
.LASF334:
	.string	"input"
.LASF596:
	.string	"lockv"
.LASF254:
	.string	"COMMANDSTRUCT"
.LASF380:
	.string	"roboStacker"
.LASF721:
	.string	"noitemname"
.LASF70:
	.string	"_mode"
.LASF297:
	.string	"filter"
.LASF47:
	.string	"_IO_write_base"
.LASF582:
	.string	"samplerate"
.LASF383:
	.string	"new_trio_addr"
.LASF437:
	.string	"m_Trms"
.LASF561:
	.string	"_Z13downlineMacroP9tmpnRobotP11tmpnPathDefPiffP10tmpnVectoriii"
.LASF607:
	.string	"startmacrotime"
.LASF122:
	.string	"tmpnLoadCell"
.LASF34:
	.string	"<anonymous struct>"
.LASF550:
	.string	"_Z11spiralMacroP9tmpnRobotP11tmpnPathDefPiffffffP10tmpnVectoriii"
.LASF629:
	.string	"slutpos"
.LASF502:
	.string	"offsx"
.LASF286:
	.string	"icpconnect"
.LASF503:
	.string	"offsz"
.LASF556:
	.string	"_Z11uplineMacroP9tmpnRobotP11tmpnPathDefPiffP10tmpnVectoriii"
.LASF223:
	.string	"time"
.LASF394:
	.string	"tekst"
.LASF677:
	.string	"convertToFrame"
.LASF630:
	.string	"slutvel"
.LASF305:
	.string	"fmax"
.LASF1:
	.string	"long int"
.LASF657:
	.string	"randomindex"
.LASF149:
	.string	"tmpnICPcon"
.LASF96:
	.string	"tmpnComSK"
.LASF474:
	.string	"tmpnWorkcell"
.LASF532:
	.string	"dcubicpoly"
.LASF692:
	.string	"forceItem"
.LASF72:
	.string	"_IO_marker"
.LASF201:
	.string	"weight"
.LASF266:
	.string	"dimention"
.LASF687:
	.string	"rzminus"
.LASF237:
	.string	"maxhidx"
.LASF547:
	.string	"fromFrame1"
.LASF18:
	.string	"timeval"
.LASF451:
	.string	"m_frames"
.LASF609:
	.string	"fromjoints"
.LASF690:
	.string	"rxplus"
.LASF186:
	.string	"toFrame"
.LASF146:
	.string	"numOfOutBits"
.LASF654:
	.string	"_Z17fastdownlinespeedff"
.LASF19:
	.string	"__pthread_internal_slist"
.LASF158:
	.string	"tmpnVector"
.LASF418:
	.string	"m_ratedNmGear"
.LASF482:
	.string	"statemachines"
.LASF246:
	.string	"pattern"
.LASF568:
	.string	"last"
.LASF326:
	.string	"change_mtx"
.LASF387:
	.string	"tmpnTool"
.LASF478:
	.string	"cppatterns"
.LASF601:
	.string	"blendouttime"
.LASF484:
	.string	"remotevalues"
.LASF216:
	.string	"selectedPPP"
.LASF350:
	.string	"server"
.LASF694:
	.string	"expandBopt"
.LASF608:
	.string	"endmacrotime"
.LASF618:
	.string	"via2postot"
.LASF511:
	.string	"maxaccs"
.LASF526:
	.string	"optimer"
.LASF76:
	.string	"long double"
.LASF224:
	.string	"keypointidx"
.LASF346:
	.string	"qlines"
.LASF264:
	.string	"path"
.LASF200:
	.string	"tmpnItem"
.LASF171:
	.string	"tmpnTiming"
.LASF291:
	.string	"statenum"
.LASF332:
	.string	"numtimeout"
.LASF619:
	.string	"via1delta"
.LASF393:
	.string	"tmpnStateTekst"
.LASF6:
	.string	"long unsigned int"
.LASF354:
	.string	"itemsPrLayer"
.LASF653:
	.string	"uniform"
.LASF764:
	.string	"_Z15fastuplinespeedff"
.LASF411:
	.string	"m_gantryLength"
.LASF647:
	.string	"maxinacc"
.LASF365:
	.string	"location"
.LASF187:
	.string	"fromItem"
.LASF318:
	.string	"mcSignal"
.LASF761:
	.string	"/home/luz/Desktop/CP6000/code/libmpnrobot/libmpnrobot"
.LASF399:
	.string	"currentStateTekst"
.LASF441:
	.string	"m_worldPoint"
.LASF126:
	.string	"tmpnConnect"
.LASF662:
	.string	"jerkMinimizer"
.LASF4:
	.string	"char"
.LASF455:
	.string	"splinehint"
.LASF406:
	.string	"currentLanguage"
.LASF24:
	.string	"__spins"
.LASF178:
	.string	"table"
.LASF729:
	.string	"fromLayer"
.LASF225:
	.string	"tmpnPosHint"
.LASF447:
	.string	"m_tcp"
.LASF50:
	.string	"_IO_buf_base"
.LASF283:
	.string	"comskconnect"
.LASF30:
	.string	"__nusers"
.LASF688:
	.string	"rzplus"
.LASF241:
	.string	"tmpnPathKeyFrame"
.LASF493:
	.string	"statetekstlist"
.LASF456:
	.string	"timing"
.LASF244:
	.string	"itemName"
.LASF220:
	.string	"statehint"
.LASF45:
	.string	"_IO_read_end"
.LASF279:
	.string	"tmpnRemoteValue"
.LASF322:
	.string	"next_istate"
.LASF103:
	.string	"lowadr"
.LASF42:
	.string	"_IO_FILE"
.LASF182:
	.string	"floating"
.LASF119:
	.string	"tmpnMacs"
.LASF93:
	.string	"initdata"
.LASF527:
	.string	"_ZN4bane7optimerEv"
.LASF409:
	.string	"tmpnRobot"
.LASF546:
	.string	"fromFrame0"
.LASF238:
	.string	"hpoint"
.LASF268:
	.string	"material"
.LASF226:
	.string	"tmpnPathDef"
.LASF320:
	.string	"stoptimer"
.LASF704:
	.string	"expandPathBoptGeneral"
.LASF140:
	.string	"tmpnDIOs"
.LASF498:
	.string	"POINTSTRUCT"
.LASF645:
	.string	"scalein"
.LASF763:
	.string	"bane"
.LASF566:
	.string	"blendquintic"
.LASF176:
	.string	"tmpnBoptParamStruct"
.LASF473:
	.string	"tmpnRemoteHosts"
.LASF659:
	.string	"temp1"
.LASF660:
	.string	"temp2"
.LASF661:
	.string	"temp3"
.LASF648:
	.string	"maxinvel"
.LASF153:
	.string	"tmpnMaterial"
.LASF563:
	.string	"fastDownlineMacro"
.LASF624:
	.string	"via2posdeltajoint"
.LASF465:
	.string	"tmpnPPScripts"
.LASF553:
	.string	"TCPidx"
.LASF304:
	.string	"fmin"
.LASF174:
	.string	"tmpnJointsUnion"
.LASF65:
	.string	"__pad1"
.LASF67:
	.string	"__pad3"
.LASF68:
	.string	"__pad4"
.LASF69:
	.string	"__pad5"
.LASF560:
	.string	"downlineMacro"
.LASF446:
	.string	"m_tcpidx"
.LASF606:
	.string	"fromvelloc"
.LASF245:
	.string	"patternName"
.LASF611:
	.string	"fromdeltajoints"
.LASF612:
	.string	"todeltajoints"
.LASF157:
	.string	"shininess"
.LASF699:
	.string	"forceLayer"
.LASF55:
	.string	"_markers"
.LASF75:
	.string	"_pos"
.LASF509:
	.string	"controlpoints"
.LASF458:
	.string	"tmpnPatterns"
.LASF574:
	.string	"timemax"
.LASF295:
	.string	"tmpnStateMachineTable"
.LASF650:
	.string	"maxoutacc"
.LASF689:
	.string	"rxminus"
.LASF592:
	.string	"via2vel"
.LASF643:
	.string	"optsamples"
.LASF301:
	.string	"topsearchwidth"
.LASF347:
	.string	"tmpnUdpAgents"
.LASF299:
	.string	"curtablesize"
.LASF448:
	.string	"m_actuator"
.LASF292:
	.string	"maxprgidx"
.LASF77:
	.string	"double"
.LASF381:
	.string	"mainDialog"
.LASF463:
	.string	"tmpnAccessories"
.LASF111:
	.string	"bitmode"
.LASF191:
	.string	"pathName"
.LASF269:
	.string	"tmpnRemoteHost"
.LASF628:
	.string	"startvel"
.LASF525:
	.string	"_ZN4bane9setLimitsE16tmpnJointsDUnionS0_"
.LASF288:
	.string	"STMCOMMANDSTRUCT"
.LASF85:
	.string	"comment"
.LASF571:
	.string	"scale"
.LASF496:
	.string	"PATHSTRUCT"
.LASF84:
	.string	"data"
.LASF715:
	.string	"thisitemend"
.LASF513:
	.string	"alphatot"
.LASF453:
	.string	"m_snapToGrid"
.LASF172:
	.string	"item"
.LASF407:
	.string	"tmpnScript"
.LASF494:
	.string	"m_root"
.LASF449:
	.string	"m_joint"
.LASF597:
	.string	"temprobot"
.LASF570:
	.string	"blmax"
.LASF344:
	.string	"tmpnUdpAgentStruct"
.LASF206:
	.string	"width"
.LASF702:
	.string	"ppscriptA"
.LASF413:
	.string	"m_shoulderGearB"
.LASF113:
	.string	"userchange"
.LASF364:
	.string	"workcell"
.LASF368:
	.string	"mcIPaddr"
.LASF112:
	.string	"bitparent"
.LASF747:
	.string	"trobot"
.LASF79:
	.string	"fixdec"
.LASF731:
	.string	"generateProgramNS"
.LASF651:
	.string	"maxoutvel"
.LASF481:
	.string	"ppscripts"
.LASF578:
	.string	"blendcubicmaxacc"
.LASF435:
	.string	"m_jogspeed"
.LASF518:
	.string	"cubickoeffs"
.LASF270:
	.string	"sockfd"
.LASF752:
	.string	"viavecthast1"
.LASF587:
	.string	"topos"
.LASF656:
	.string	"rmax"
.LASF16:
	.string	"tv_sec"
.LASF539:
	.string	"split"
.LASF533:
	.string	"_ZN4bane10dcubicpolyEid"
.LASF9:
	.string	"long long unsigned int"
.LASF259:
	.string	"include"
.LASF60:
	.string	"_cur_column"
.LASF416:
	.string	"m_sign"
.LASF240:
	.string	"poshint"
.LASF142:
	.string	"bitpos"
.LASF701:
	.string	"moveItem"
.LASF757:
	.string	"toVector"
.LASF356:
	.string	"tmpnRSSystem"
.LASF120:
	.string	"loadcellConnect"
.LASF25:
	.string	"__list"
.LASF734:
	.string	"towerHight"
.LASF739:
	.string	"stop0"
.LASF555:
	.string	"uplineMacro"
.LASF403:
	.string	"tmpnLanguages"
.LASF524:
	.string	"_ZN4bane4initE16tmpnJointsDUnionS0_S0_S0_S0_S0_"
.LASF420:
	.string	"m_ratedNm"
.LASF127:
	.string	"sdata"
.LASF531:
	.string	"_ZN4bane9cubicpolyEid"
.LASF490:
	.string	"macs"
.LASF109:
	.string	"comsk"
.LASF204:
	.string	"layer"
.LASF722:
	.string	"sitem"
.LASF589:
	.string	"via1pos"
.LASF302:
	.string	"topidx"
.LASF671:
	.string	"temp"
.LASF97:
	.string	"simulate"
.LASF53:
	.string	"_IO_backup_base"
.LASF427:
	.string	"m_i_gain"
.LASF366:
	.string	"robot"
.LASF44:
	.string	"_IO_read_ptr"
.LASF425:
	.string	"m_units"
.LASF470:
	.string	"remotestatemachine"
.LASF749:
	.string	"coeff"
.LASF175:
	.string	"array"
.LASF622:
	.string	"via1posdeltajoint"
.LASF414:
	.string	"m_Link"
.LASF693:
	.string	"ppscriptname"
.LASF741:
	.string	"corner1"
.LASF742:
	.string	"corner2"
.LASF743:
	.string	"corner3"
.LASF744:
	.string	"corner4"
.LASF745:
	.string	"corner5"
.LASF285:
	.string	"macconnect"
.LASF412:
	.string	"m_legHeight"
.LASF475:
	.string	"languages"
.LASF82:
	.string	"major"
.LASF114:
	.string	"macstruct"
.LASF600:
	.string	"blendintime"
.LASF92:
	.string	"numOfOutWords"
.LASF159:
	.string	"tmpnDualVector"
.LASF750:
	.string	"rs_param"
.LASF59:
	.string	"_old_offset"
.LASF258:
	.string	"listitem"
.LASF544:
	.string	"stepsize"
.LASF300:
	.string	"sumcnt"
.LASF443:
	.string	"m_jointCalib"
.LASF577:
	.string	"blendcubicmaxvel"
.LASF538:
	.string	"toIdx"
.LASF602:
	.string	"retval"
.LASF637:
	.string	"accelmultiplicator"
.LASF415:
	.string	"m_State"
.LASF105:
	.string	"oarray"
.LASF355:
	.string	"layers"
.LASF2:
	.string	"long long int"
.LASF117:
	.string	"port"
.LASF80:
	.string	"factor"
.LASF58:
	.string	"_flags2"
.LASF190:
	.string	"toPattern"
.LASF150:
	.string	"tmpnICPcons"
.LASF205:
	.string	"tmpnPattern"
.LASF529:
	.string	"_ZN4bane9getResultER8baneConfRd"
.LASF385:
	.string	"mc_version"
.LASF202:
	.string	"user"
.LASF130:
	.string	"wordidx"
.LASF367:
	.string	"pcIPaddr"
.LASF614:
	.string	"todelta"
.LASF275:
	.string	"tmpnRemoteStateMachine"
.LASF586:
	.string	"fromvel"
.LASF340:
	.string	"questionformat"
.LASF343:
	.string	"responseval"
.LASF396:
	.string	"tmpnStateTekstList"
.LASF641:
	.string	"startmacronos"
.LASF35:
	.string	"__futex"
.LASF167:
	.string	"tmpnFrames"
.LASF504:
	.string	"frequency"
.LASF212:
	.string	"paccs"
.LASF308:
	.string	"tmpnStateMachineValue"
.LASF740:
	.string	"corner0"
.LASF711:
	.string	"startItem"
.LASF152:
	.string	"tmpnVectorXYZ"
.LASF90:
	.string	"numOfInitWords"
.LASF621:
	.string	"via1posjoint"
.LASF143:
	.string	"icpconstruct"
.LASF604:
	.string	"fromposloc"
.LASF623:
	.string	"via2posjoint"
.LASF317:
	.string	"version"
.LASF755:
	.string	"viavectabs1"
.LASF756:
	.string	"viavectabs2"
.LASF557:
	.string	"uplinespeed"
.LASF459:
	.string	"tmpnCPPatterns"
.LASF248:
	.string	"boptcoeff"
.LASF0:
	.string	"unsigned int"
.LASF141:
	.string	"tmpnICPConnect"
.LASF683:
	.string	"distanceBetweenPoints"
.LASF211:
	.string	"ppps"
.LASF640:
	.string	"outnos"
.LASF666:
	.string	"dummy"
.LASF759:
	.string	"GNU C++ 4.4.1"
.LASF309:
	.string	"linkname"
.LASF710:
	.string	"cBLayer"
.LASF573:
	.string	"finenos"
.LASF716:
	.string	"baseFrame"
.LASF8:
	.string	"short int"
.LASF421:
	.string	"m_maxForceNm"
.LASF242:
	.string	"cItem"
.LASF476:
	.string	"robots"
.LASF440:
	.string	"m_max"
.LASF256:
	.string	"prev"
.LASF61:
	.string	"_vtable_offset"
.LASF168:
	.string	"frame"
.LASF333:
	.string	"numinput"
.LASF131:
	.string	"bitidx"
.LASF726:
	.string	"expandBoptLoader"
.LASF703:
	.string	"expandPathGeneralBoptOutHeader"
.LASF450:
	.string	"m_staticForce"
.LASF542:
	.string	"tcpname"
.LASF278:
	.string	"remotelock"
.LASF593:
	.string	"startmacro"
.LASF314:
	.string	"stmidx"
.LASF11:
	.string	"__quad_t"
.LASF669:
	.string	"minjerk"
.LASF78:
	.string	"comskConnect"
	.ident	"GCC: (Ubuntu 4.4.1-4ubuntu9) 4.4.1"
	.section	.note.GNU-stack,"",@progbits
