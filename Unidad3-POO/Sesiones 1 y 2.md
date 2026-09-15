# Programación Orientada a Objetos

## Sesión 1: Investigación

### Actividad 1: diagnóstico inicial

#### Parte 1: recordando conceptos (C#)

1. ¿Qué es el encapsulamiento para ti?
- Es como "esconder" los datos de una clase pa que nadie de afuera los pueda tocar directamente, solo se pueda acceder por métodos o propiedades que yo defina. Me ha servido con una clase CuentaBancaria donde el saldo era private, así nadie le podía poner un valor negativo directo, solo a través de un método Depositar() que sí validaba.

2. ¿Qué es la herencia? ¿Por qué usarla?
- Es cuando una clase "hija" toma los atributos y métodos de una clase "padre", pa no repetir código. Ejemplo: una clase Animal con Comer(), y de ahí heredan Perro y Gato, que ya tienen Comer() gratis.

3. ¿Qué es el polimorfismo?
- Que un mismo método se comporte distinto dependiendo de qué objeto lo llame. Llamo Dibujar() y según si es Círculo o Rectángulo hace algo diferente, aunque yo lo llame "igual" desde afuera.

#### Parte 2: análisis de código (C#)

**Encapsulamiento:**
- La línea `private string nombre;` junto con `public string Nombre { get; protected set; }` es un ejemplo claro el campo está oculto y solo se accede por la propiedad.
- nombre es private y Nombre es public pa evitar que cualquiera desde afuera le cambie el valor sin control. El set es protected, así solo las clases hijas lo modifican, nadie más puede hacer figura.Nombre = "otra cosa" desde afuera. Esto evita que se dañe la consistencia del objeto.

**Herencia:**
- Se ve en `public class Circulo : Figura`.
- Además de Radio, un Circulo también tiene el campo Nombre (heredado de Figura), y el método Dibujar() sobreescrito.

**Polimorfismo:**
- Hipótesis: el programa guarda para cada objeto cuál es su tipo real (Circulo o Rectangulo), y al llamar fig.Dibujar() busca en tiempo de ejecución cuál versión usar, no en tiempo de compilación.

#### Parte 3: hipótesis sobre implementación

1. Memoria y herencia
- Yo creo que en memoria quedan los 3 datos uno detrás de otro en un mismo bloque: primero lo de Figura (Nombre), y después lo propio de Rectangulo (Base y Altura).

2. El mecanismo del polimorfismo
- Creo es que existe una "tabla" por cada tipo de objeto que le dice al programa qué función usar. Cuando se llama fig.Dibujar(), en tiempo de ejecución revisa esa tabla y llama la función correcta.

3. La barrera del encapsulamiento
- Yo pienso que eso se revisa en tiempo de compilación, porque si uno pone ac.privateVar = 30 el programa ni compila, marca error antes de correr. No es una protección que exista mientras corre, es una regla que chequea el compilador antes.

### Actividad 2: Aplicación (openFrameworks)

## 1. Partícula "base"

Existe una clase `Particle` que es como el molde genérico: dice que toda partícula debe poder actualizarse (`update`), dibujarse (`draw`) y saber si ya murió (`isDead`). De ahí se desprenden las dos familias de partículas:

- **`RisingParticle`** → el cohete que sube.
- **`ExplosionParticle`** → las chispitas que salen cuando el cohete explota, y de esta salen 3 sabores: `CircularExplosion`, `RandomExplosion` y `StarExplosion`.

Es básicamente herencia + polimorfismo

## 2. El cohete sube

Cuando uno hace clic (o le da espacio), se crea un `RisingParticle` que:

- Nace abajo, más o menos en el centro de la pantalla
- Le calculan hacia dónde tiene que ir (un puntico random arriba) y le meten velocidad en esa dirección
- Le ponen un color al azar (por eso salen de mil colores)
- Tiene un tiempo de vida random entre 1.5 y 3.5 segundos

Mientras sube, se le va aplicando como gravedad, entonces se va frenando poco a poco — simula que va perdiendo impulso. Cuando llega como al 15% de la altura de la pantalla (o se le acaba el tiempo), explota

## 3. La explosión

El programa:

1. Escoge al azar uno de los 3 tipos de explosión (circular, random o estrella)
2. Crea entre 20 y 30 partículas nuevas de ese tipo, todas naciendo justo donde explotó el cohete y con su mismo color
3. Borra el cohete original (con `delete`)

Cada tipo de explosión se mueve distinto:

- **Circular** → se reparten parejito en forma de círculo
- **Random** → cada una sale para donde le da la gana
- **Star (estrella)** → sale en direcciones tipo circular pero además se dibuja como una estrella de 5 picos usando trigonometría

Las chispitas de la explosión no tienen gravedad, solo van en línea recta y se van desvaneciendo (el alpha del color baja de 255 a 0 poquito a poquito) hasta que se mueren y se eliminan del vector.

La tecla `s` guarda un screenshot.


## Sesión 2

### Actividad 3: experimentos con el depurador

- Actividad 100% experimental, no hay nada que responder de antemano — el objeto solo existe en memoria mientras la app corre.
- Falta: correr en depuración, buscar la instancia de ofApp en el depurador, anotar hipótesis antes de ver el resultado, capturar.
- Falta: buscar un objeto CircularExplosion (breakpoint dentro del if (explosionType == 0) en ofApp.cpp), expandirlo hasta ver ExplosionParticle → Particle → _vtable, capturar.
- Falta: repetir con StarExplosion y comparar las dos tablas.
- _vtable es una tabla de punteros a las funciones virtuales de esa clase — cada objeto con métodos virtual guarda un puntero a esta tabla como su primer campo.
- La relación con el polimorfismo: cuando se llama particles[i]->update(), el programa va a la _vtable del objeto y ahí encuentra el puntero a la función correcta según el tipo real.
- En el ejemplo de C# con IAnimal pasa algo parecido por debajo: cada objeto tiene su propia tabla de métodos, y al llamar animal.HacerSonido() el runtime busca ahí cuál implementación usar según el tipo real, no el tipo declarado.

### Actividad 4: encapsulamiento

**Experimento 1 — descomentar protectedVar y privateVar:**
- No compila, error tipo "no se puede acceder a protectedVar/privateVar porque es protegido/privado en este contexto". protected solo permite acceso desde la clase o sus hijas, private solo desde la misma clase.

**Experimento 2 — obj.secret1 directo:**
- Error de compilación, mismo motivo: secret1 es private, no se puede acceder desde main() directo, solo por printMembers().

**Experimento 3 — reinterpret_cast pa saltarse el encapsulamiento:**
- Este sí compila y corre sin error, y sí logra mostrar los valores privados.
- Conclusión: el encapsulamiento en C++ es una protección que existe solo en tiempo de compilación. En memoria, un objeto privado no tiene ninguna protección física — los datos están ahí uno detrás de otro como cualquier dato. Con punteros y calculando bien las direcciones, se puede leer sin problema.

**¿Qué es el encapsulamiento y por qué es importante?**
- Para mi es una forma de decirle al compilador "esto es solo mío, nadie de afuera lo toca directo". Es importante porque evita errores — si cualquiera pudiera cambiar cualquier campo, sería fácil dejar un objeto en estado inválido (saldo negativo, radio negativo). Pero es una ayuda del compilador pa escribir código correcto, no una seguridad real a nivel de memoria.

- Falta: compilar y correr los 3 programas, capturar el error de compilación al descomentar las líneas prohibidas, y capturar la salida del programa con reinterpret_cast mostrando los valores privados.