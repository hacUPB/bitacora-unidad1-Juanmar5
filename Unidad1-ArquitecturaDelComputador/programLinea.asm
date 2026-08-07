@i
M=0           

(LOOP)
@i
D=M
@32
D=D-A          // D = i - 32
@END
D;JGE          // si i >= 32, ya recorrimos toda la fila -> termina

@i
D=M
@SCREEN
A=D+A         
M=-1           // pinta esos 16 pixeles de negro

@i
M=M+1          // i++

@LOOP
0;JMP

(END)
@END
0;JMP