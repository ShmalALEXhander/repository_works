;19.Найти среднее арифметическое чисел больших 10. Массив слов.
data segment
mass db 10, 20, 0, -7, 0, 0, 15, 40, 97, 22, 271, 52, 12 
data ends
code segment
assume cs: code, ds: data
start: 
mov ax, data  
mov ds, ax 	
mov cx, 13
lea bx, mass

revr:
mov ax, [bx]
cmp ax, 10
jge then
inc bx
loop revr

mov ax, 4c00h
int 21h 	

then:
add dx,ax
inc si
int bx
loop revr

mov ax, 4c00h 	
int 21h 
	
code ends
end start