@33
D=A
@16
M=D
@44
D=A
@17
M=D
@55
D=A
@18
M=D
@12
D=A
@19
M=D
@34
D=A
@20
M=D
@56
D=A
@21
M=D
@78
D=A
@22
M=D
@98
D=A
@23
M=D
@76
D=A
@24
M=D
@54
D=A
@25
M=D

@R14
M=0
@R13
M=0

(LOOP)
@R13
D=M
@10
D=D-A
@END
D;JGE     

@R13
D=M
@16
D=D+A      
@R15
M=D       

@R15
A=M        
D=M        

@R14
M=D+M      

@R13
M=M+1      

@LOOP
0;JMP

(END)
@END
0;JMP