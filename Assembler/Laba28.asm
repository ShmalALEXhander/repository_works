;25. � = 5� + 2� - B / 4 + 131
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
  
  mov ax, a
  mov dx, ax
  sal ax, 2
  add ax, dx
  mov bx ,b  
  mov dx, bx ; �������������
  sal bx, 1
  add ax, bx
  mov bx, dx
  sar bx, 2
  sub ax, bx
  add ax, 131
  mov x, ax

  
  mov ax, 4C00h 	; ��� ���������� 0
 		int 21h		; ����� � DOS
code ends
end START