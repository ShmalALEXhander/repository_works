data segment
IN_STR db 80, ?, 82 dub(?) ; 
data ends
code segment
assume cs:code, ds:data
   mov ax, data 
   mov ds, ax
   
   lea dx, IN_STR
   inc dx
   mov bl,[dx] ; в bl лежит число символов введённой str
   cmp bl, al
   jg then


   then: 
   add al, 3
   add dx, al
   mov [dx], 24h
   mov ah, 09h
   lea dx, IN_STR
   add dx, 2
   int 21h
   
QUIT: 	mov ax, 4C00h 	; Код завершения 0
 		int 21h		; Выход в DOS
code ends
end START
;1 байт - макс колво символов длина реально в