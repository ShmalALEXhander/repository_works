;3.	Х= 7А - 2В - 100 + С
data segment 		
a dw 20
b dw 20
c dw 14
x dw ?
data ends				
code segment			
assume cs: code, ds: data
start:
    mov ax,data		
	mov ds,ax 
	mov ax,a
	mov dx,ax
	sal ax,3
	sub ax,dx
	mov bx,b
	sal bx,1
	sub ax,bx
	sub ax,100
	mov cx,c
	add ax,cx
	
	mov x,ax
	
quit:	mov ax,4c00h 		
int 21h 			
code ends
end start