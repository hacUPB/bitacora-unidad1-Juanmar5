## Sesión 2. Modelo Hack y ciclo fetch-decode-execute

### Actividad 2: Ciclo fetch-decode-execute

El siguiente programa está escrito en el lenguaje ensamblador del computador Hack. Este computador no es un computador comercial, sino un computador didáctico que te permitirá acercarte a los conceptos fundamentales de manera amigable.

Analiza el siguiente programa (está en lenguaje ensamblador).

```nasm
			@1
			D=A
			@2
			D=D+A
			@16
			M=D
(END)
			@END
			0;JMP
```

**¿Qué crees que haga este programa?**

Para responder a esta pregunta vamos a analizarlo paso a paso usando un simulador de la CPU Hack que está **aquí**.

Para ejecutar este programa la CPU realiza un **ciclo** constante llamado Fetch-Decode-Execute.

El ciclo Fetch-Decode-Execute describe cómo la CPU ejecuta instrucciones de un programa. Aquí está explicado de forma breve y simple:

**Fetch (buscar):** la CPU obtiene (lee) la siguiente instrucción desde la memoria. El contador de programa (PC) indica dónde se encuentra esa instrucción en la memoria ROM.

**Decode (decodificar):** la CPU interpreta la instrucción que acaba de leer. Esto significa entender qué operación debe realizarse y qué datos o recursos necesita.

**Execute (ejecutar):** la CPU realiza la operación indicada. Por ejemplo, puede ser una operación matemática, mover datos entre registros, o acceder a la memoria.

Este ciclo se repite continuamente mientras la computadora esté encendida, procesando instrucciones una tras otra. Es la base del funcionamiento de cualquier procesador.

## 🧐**🧪✍️ Experimento**

Ahora es tu turno. Crea un archivo llamado `program.asm` y copia el código del programa anterior. Ejecuta el programa en el simulador de la CPU Hack y observa cómo se comporta. ¿Qué sucede? ¿Qué valor se almacena en la dirección de memoria 16? ¿Por qué crees que es ese valor? ¿Qué instrucciones se ejecutan en cada ciclo Fetch-Decode-Execute? ¿Qué cambios observas en el contenido de la memoria y los registros? ¿Qué instrucciones se ejecutan en cada ciclo Fetch-Decode-Execute?

## 🧐**🧪✍️ Experimento**

Escribe un programa en lenguaje ensablador que sume los números 5 y 10, y almacene el resultado en la dirección de memoria 20. Utiliza el simulador de la CPU Hack para ejecutar tu programa y verifica que el resultado es correcto.

## 📤**Bitácora**

Reporta tus observaciones para cada experimento en tu bitácora de aprendizaje.
¿Qué diferencia hay entre los datos almacenados en la memoria ROM y en la RAM?


### Actividad 3: Explorando la arquitectura del computador Hack

Ahora vamos a analizar juntos el siguiente programa. Este programa tendrá todos los conceptos que vamos investigar en la siguiente fase de la unidad de manera más profunda. En qué nos enfocaremos:

- Las partes del computador Hack.
- El modelo de programación de la CPU.
- La diferencia entre memoria RAM y registros.
- Los tipos de instrucciones del lenguaje ensamblador.
- Cómo leo el teclado y muestro en pantalla.
- Cómo implemento un bucle.
- Cómo implemento una condición.
- ¿Qué es la ALU y qué operaciones realiza?

En **“este”** enlace está la documentación del computador Hack.

```nasm
@SCREEN
D=A
@i
M=D

(READKEYBOARD)
@KBD
D=M
@KEYPRESSED
D;JNE
@i
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

(KEYPRESSED)
@i
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
```

## 🧐**🧪✍️ Experimento:** Ahora experimenta.

Crea un archivo llamado `program.asm` y copia el código del programa anterior. Ejecuta paso a paso el programa en el **simulador** así:

- Carga el programa en el simulador.
- Antes de ejecutar cada instrucción vas a predecir qué crees que va a suceder. Es muy importante que hagas esto, de esta manera tu mismo puedes saber si estás entendiendo el programa.
- Luego, ejecuta la instrucción y observa el resultado.
- Si te equivocas, reflexiona sobre por qué tu predicción no fue correcta.

## 📤 **Bitácora**

Reporta en tu bitácora de aprendizaje:

- Identifica una instrucción que use la ALU y explica qué hace.
- ¿Para qué sirve el registro PC?
- ¿Cuál es la diferencia entre @i y @READKEYBOARD?
- Describe qué se necesita para leer el teclado y mostrar información en la pantalla.
- Identifica un bucle en el programa y explica su funcionamiento.
- Identifica una condición en el programa y explica su funcionamiento.

### Actividad 4: Control de flujo con saltos

Vamos a resolver juntos este problema:

Escribe un programa que compare el valor almacenado en la dirección de memoria 5 con el valor 10. Si el valor es menor que 10, guarda el valor 1 en la dirección 7. Si el valor es mayor o igual a 10, guarda el valor 0 en la dirección 7.

## 📤 **Bitácora**

- Escribe tu mismo el programa.
- Simula paso a paso. Recuerda la metodología: predice, ejecuta, observa y reflexiona.

## Sesión 4. Memoria mapeada, pantalla, teclado y programas interactivos simples

### Actividad 5: Implementando un ciclo simple

Vamos a resolver juntos este problema:

“Crea un programa que use un ciclo para sumar los números del 1 al 5 y guarde el resultado en la dirección de memoria 12.”

## 📤 **Bitácora**

- Escribe tu mismo el programa.
- Simula paso a paso. Recuerda la metodología: predice, ejecuta, observa y reflexiona.

### Actividad integrada: Dibujando un punto en la pantalla

Vamos a resolver juntos este problema:

La pantalla del computador Hack se controla a través de un mapa de memoria que comienza en la dirección 16384 (SCREEN). Cada bit en este mapa de memoria representa un pixel en la pantalla (1 = negro, 0 = blanco). Escribe un programa que dibuje un punto negro en la esquina superior izquierda de la pantalla. (Recuerda que la esquina superior izquierda corresponde al primer bit del primer word en la dirección SCREEN).

Traduce este programa a lenguaje C++ para que relaciones cómo los conceptos de alto nivel se traducen a bajo nivel.

## 📤 **Bitácora**

- Escribe tu mismo ambos programas.
- Simula paso a paso el programa en ensamblador. Recuerda la metodología: predice, ejecuta, observa y reflexiona.

### Actividad integrada: Dibujando una línea horizontal

Vamos a resolver juntos este problema:

Modifica el programa anterior para que dibuje una línea horizontal negra de 16 pixeles de largo en la esquina superior izquierda de la pantalla. (Recuerda que cada word en la memoria representa 16 pixeles).

Traduce este programa a lenguaje C++ para que relaciones cómo los conceptos de alto nivel se traducen a bajo nivel.

## 📤 **Bitácora**

- Escribe tu mismo los programas.
- Simula paso a paso el programa ensamblador. Recuerda la metodología: predice, ejecuta, observa y reflexiona.

### Actividad integrada: Entrada salida interactiva

Modifica el programa de la actividad anterior de tal manera que puedas mover la línea horizontal de derecha a izquierda usando las teclas **d** e **i** respectivamente. Tu programa no tiene que verificar si la línea se sale de la pantalla.

Traduce este programa a lenguaje C++ para que relaciones cómo los conceptos de alto nivel se traducen a bajo nivel.

## 📤 **Bitácora**

- Escribe los programas.
- Simula paso a paso en lenguaje ensamblador. Recuerda la metodología: predice, ejecuta, observa y reflexiona.

https://confusion-snapper-025.notion.site/Sesiones-3-y-4-39ce8161b2a18018a926c17f32c49926