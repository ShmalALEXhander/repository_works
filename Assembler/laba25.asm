;12.	Х = 6 (А - 2В + С / 4) + 10
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
	mov bx,b
	
	sal bx,1
	sub ax,bx
	mov cx,c
	sar cx,2
	add ax,cx
	mov dx,ax ;(А - 2В + С / 4)
	sal dx,1
	sal ax,2
	add ax,dx
	add ax,10
	mov x,ax
	
quit:	mov ax,4c00h 		
int 21h 			
code ends
end start