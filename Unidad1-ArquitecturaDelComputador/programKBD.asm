@SCREEN
D=A
@i
M=D //i=16384

(READKEYBOARD)
@KBD
D=M
@KEYPRESSED
D;JNE // si valor en D /=/ 0 salta a KEYPRESSED (se tocó una tecla)
@i //al no presionarse tecla, realiza este bucle
D=M
@SCREEN
D=D-A
@READKEYBOARD
D;JLE
@i
M=M-1
A=M
M=0
@READKEYBOARD
0;JMP

(KEYPRESSED) // Toma cualquier tecla porque basta con que sea diferente de cero
@i //Al presionar tecla, realiza este bucle
D=M
@KBD
D=D-A
@READKEYBOARD
D;JGE
@i
A=M
M=-1
@i
M=M+1
@READKEYBOARD
0;JMP
