;14.Найти полусумму наибольшего и наименьшего чисел. Массив байт.
data segment
   mass db 10, 20, 0, -7, 0, 0, 15, 40, 97, 22, 271, 52, 12
   max 0
   min FFFFh
data ends
assume cs:code
code segment
start:

   mov ax, data 
   mov ds, ax
   mov cx, 13*2 ; в виду проходящего двойного цикла
   lea bx, mass
   
revr:
   mov ax, [bx]
   cmp ax, max
   jg thenMax
   cmp ax, min
   jl thenMin
   

thenMax:
   mov max, ax
   inc bx
   loop revr
thenMin:
   mov min, ax
   inc bx
   loop revr


   mov ax, 4C00h    
   int 21h  
 
code ends
end start