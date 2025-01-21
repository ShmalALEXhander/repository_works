;6.	Х= (А/ 2 + В) / 4 + С - 1
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
	sar ax,1
	mov bx,b
	add ax,bx
	sar ax,2
	mov cx,c
	add ax,cx
	dec ax
	mov x,ax
	
quit:	mov ax,4c00h 		
int 21h 			
code ends
end start
