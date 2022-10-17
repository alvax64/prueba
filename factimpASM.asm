;nasm -f elf64 factimpASM.asm -o factimpASM.o

global factimpASM
	section .text
factimpASM:
	xor 	rax,	rax
	mov 	r8,		2			; r8 <- 2
	mov 	rax,	rdi			; rax <- N		
	mul 	r8					; rax <- N*2
	inc 	rax					; rax <- 2N+1
	mov 	r8,		rax			; r8 <- 2N+1, 
	mov 	r9,		1			; r9 <- 1
	mov 	r10,	1			; r9 <- 1
	xorps 	xmm0,	xmm0		; xmm0 <- 0
	xorps 	xmm1,	xmm1		; xmm1 <- 0
	xorps 	xmm2,	xmm2		; xmm2 <- 0

	cvtsi2ss xmm0,	r9			; xmm0 <- 1
	cvtsi2ss xmm2,	r10			; xmm2 <- 1 (fact)
bucle:	
	cmp r10, r8
	je end		
	cvtsi2ss xmm1,	r10			; xmm1 <- (i)
	addps	xmm1,	xmm0		; xmm1 <- i+1
	mulps 	xmm2,	xmm1		; fact <- fact*(i+1)
	inc r10
	jmp bucle
end:
	movss	xmm0,	xmm2
	ret