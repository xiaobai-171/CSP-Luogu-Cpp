data segment
    x dw -1
    y dw 0
    z dw 720
    v dw 1
    SUM1 dw ?
    SUM2 dw ?
data ends
stack segment
stack ends
code segment
    assume ds:data, cs:code
start:
    mov bx, x
    mov ax, y
    imul bx
    mov bx, z
    add ax, bx
    adc dx, 0
    mov bx, 02bch
    sub ax, bx
    sbb dx, 0
    mov bx, ax
    mov cx, dx
    mov ax, v
    cwd
    sub ax, bx
    sbb dx, cx
    idiv x
    mov SUM1, ax
    mov SUM2, dx
    mov ah, 4ch
    int 21h
code ends
    end start