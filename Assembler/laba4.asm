data segment
 mass db 10h, 42h, 8, 1
 ; 123, 234, 55, 66, 107, 208
 bit dw 5
data ends
code segment
assume cs: code, ds: data
start: 
    mov ax, data
    mov ds, ax ;
 
    mov bx, 0
    mov dx, 0
    mov ax, 0
    mov bit, bx
beg:
        mov ax, bit
        mov bl, 8
        div bl                      
        mov bl, al
    mov al, [mass + bx] ; 
    
    mov cl, ah 
	dec	cl
    shr al, cl  ; 
 
    and al, 1 ; 
        cmp al, 0
        je no
        inc dx
no:             
        mov ax, 5
        add ax, bit
        mov bit, ax
 
        cmp ax, 6*8 ;
        jl beg
 
quit: 
    mov ax, 4C00h ; 
    int 21h ;
 code ends 
 end start