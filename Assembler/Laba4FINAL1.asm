data segment
 mass db 10h, 42h, 8, 1
 bit dw 0
data ends
code segment
assume cs: code, ds: data
start: 
    mov ax, data
    mov ds, ax ; Загрузить сегментный адрес данных
	
next:
    add bit, 5 
	mov ax, bit
	
	cmp ax, 6*8
	jge quit
	mov cl, 8
	div cl
	mov al, [mass + bx]
		
	mov bl, al ; позиция массива = 0
	mov cl, ah ; позиция элемента по разряду = 5
	dec cl
	mov ah, 80h
    shr ah, cl ; shl
	and al, ah ; на 5 по разряду сдвигаем в соответствии с заданием
	    cmp al, 0
		je no
		inc dx
        jmp next	
no: 
	jmp next
	quit:
	mov ax, 4C00h ; 
    int 21h ; 	
	
code ends 
end start