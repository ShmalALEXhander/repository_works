; 22. �= - ( - (� + 2�) * 5� - 27)
data segment
a dw 10
b dw 24
c dw 30
x dw ?
data ends
assume cs:code, ds:data
code segment
start:
  mov ax, data 
  mov ds, ax
  
  mov cx, c
  mov ax, a
  sal ax, 1
  add ax, cx ;(C+2A)
  mov bx, b
  mov dx, bx
  sal bx, 2
  add bx, dx ;(5*B)
  mul ax, bx  ;  
  add ax, 27 ;

  
  mov ax, 4C00h 	; 
 		int 21h		; 
code ends
end START