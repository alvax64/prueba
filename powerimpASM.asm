;nasm -f elf64 powerimpASM.asm -o powerimpASM.o

global powerimpASM
	section .text
	
powerimpASM:
	mov 	r8,		rdi			; r8 <- x
	mov 	r9,		r8

	mov 	rax,	0
	mov 	r10,	2
	mov 	rax,	rsi			; rax <- N
	mov 	r11,	rsi			; guardo N en r11 para ver si es par	
	mul 	r10
	inc 	rax
	mov 	r10,	rax			; r10 <- 2N+1

	mov 	r12,	1			; r12 será contador
	xorps 	xmm0,	xmm0
	xorps 	xmm1,	xmm1
	xorps 	xmm2,	xmm2
	xorps 	xmm3,	xmm3

	cvtsi2ss xmm0,	r8			; xmm0 <- x
	cvtsi2ss xmm1,	r9			; xmm1 será pot
	cvtsi2ss xmm2,	r12
	cvtsi2ss xmm3,	r12
	
chequeo_impar:	
	mov 	rax,	r11			; rax <- N
	mov 	rdx, 	0
	mov 	r15,	2
	div 	r15
	cmp 	rdx,	0			;¿N%2=0?
	je		bucle				
	mov 	r11, 	-1
	cvtsi2ss xmm3,	r11			; si N impar entonces xmm3 <- -1


bucle:	
	cmp r12, r10
	je end		
	mulps 	xmm1,	xmm0		; pot <- pot*(x)
	inc r12
	jmp bucle

end:
	mulps 	xmm1,	xmm3		; si N impar entonces xmm1 <- -xmm1
	movss	xmm0,	xmm1
	ret