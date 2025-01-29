.model small,c
.data
action      db 0
msg1        db 13,10,'Press Esc to exit',13,10,'$'
 
.stack 256
.code
 
start
    mov ax,@data        
    mov ds,ax
    mov ah,9        
    lea dx,msg1     
    int 21h         
    mov ax,351ch        
    int 21h
    mov word  ptr  csOld1c,BX  
    mov word  ptr  csOld1c+2,ES
    mov ax,251ch        
    push ds         
    push cs
    pop ds          
    mov dx,offset  New1cObrab   
    int 21h             
    pop ds          
    mov ax,3
    int 10h         
    mov ax,0b800h
    mov es,ax       
    mov ah,15       
    xor di,di       
    mov al,0        
    mov cx,2000     
l1 stosw           
    inc al          
    loop l1                 
l2 cmp action,-1       
    jz ex           
    cmp action,1        
    jz left         
    cmp action,2        
    jz right        
    jmp l2          
left   mov bx,0
l4 mov dx,es[bx]
    mov cx,79
l3 mov ax,es[bx+2]
    mov es[bx],ax
    add bx,2
    loop l3
    mov es[bx],dx
    add bx,2
    cmp bx,4000
    jb l4
    mov action,0        
    jmp l2          
right  mov bx,0        
l14add bx,792
    mov dx,es[bx]
    mov cx,79
l13    mov ax,es[bx-2]
    mov es[bx],ax      
    sub bx,2        
    loop l13        
    mov es[bx],dx
    add bx,160      
    cmp bx,4000
    jb l14      
    mov action,0        
    jmp l2          
    
ex mov ax,251ch        
    lds dx,csold1c     
    int 21h         
    mov ax,4c00h    
    int 21h
 
Old1c   dd        
 
New1cObrab  proc        
    pushf           
    call    dword   ptr CS[Old1c]  
    push ax
    push ds
    mov ax,@data
    mov ds,ax       
    in al,60h
    cmp al,1 ; Esc
    jne @
    mov action, -1
@  cmp al,2 ; '1'
    jne @@
    mov action, 1
@@ cmp al,3 ; '2'
    jne @@@
    mov action, 2
@@@pop ds
    pop ax
    iret
New1cObrab  endp
end start