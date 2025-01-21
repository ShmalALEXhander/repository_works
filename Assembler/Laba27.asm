;7.	Х= - (С + 2А + 4В + В)
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
  add ax, cx
  mov bx, b
  add ax, bx
  sal bx, 2
  add ax, bx
  mov dx, ax
  mov ax, 0
  sub ax, dx  ;nec - преобразование в дополнительный код
  mov x, ax  
  
  mov ax, 4C00h 	; Код завершения 0
 		int 21h		; Выход в DOS
code ends
end START

