* **
<h1 style="align-items: center; text-align: center; font-family: 'Segoe UI', serif; color: azure"> 
Universidad San Francisco de Quito</h1>
<h3 style="text-align: center; font-family: 'Segoe UI', serif; font-size: 12pt; color: azure"> 
Programacion Avanzada en C++</h3>
<h3 style="font-family: 'Segoe UI',serif; font-size: 12pt; text-align: center; color: azure"> 
Proyecto I - Cinco Clanes </h3>

* **
El presente proyecto trata de implementar los datos presentados en la hoja de información dle juego Cinco lanes en C++.
Para esto se trabaja con una serie de clases para representar un juego de cartas, el proceso de generación de valores
aleatorios para las cartas, jugabilidad y selección de casos y una correcta simulación del juego.
* **
<h6 style="font-family: 'Segoe UI', serif; font-size: 12pt; text-align: justify; color: azure"> Datos Generales <br></h6>
<ul style="list-style: lower-roman">
<li id="item_1" style="font-family: 'Segoe UI', serif">
Integrantes del Grupo:
<ul>
<li>
    Leonardo Olmedo (327960)
</li>
<li>
    Santiago Arellano (328370)
</li>
</ul>
</li>
<li id="item_2" style="font-family: 'Segoe UI', serif">
Fecha de inicio / Fecha de entrega
<ul>
<li>
    28/09/23
</li>
<li>
    05/09/23
</li>
</ul>
</li>
</ul>

* **
<h6 style="font-family: 'Segoe UI', serif; font-size: 12pt; text-align: justify; color: azure"> 
    Consideraciones e Instrucciones
</h6>

<ul style="list-style-type: upper-alpha">
<li>
Para las dimensionalidad de la consola, y lograr una estructura visual agradable aun cuando existen
limitaciones de la consola se utiliza un screen size de 120 pixeles,
<ul>
<li>
Cada espacio de texto tiene que tener maximo 120 caracteres horizontales de extension, para que no se salga
de los limites de la pagina de consola y se vea correctamete,
</li>
<li>
Las lineas de separacion entre objetos de consola se construyen con el simbolo "="
</li>
</ul>
</li>

<li id="1">
Estructura y Control de Versiones:
    <ul>
        <li>Para la organización de los archivos enviados en este trabajo se trabajará con Git para Windows y un repositorio
        online  en donde se podrá revisar los cambios y se tendrá un registro del trabajo realizado por cada miembro.
        </li>
        <li>
            De no contar con la capacidad para utilizar un sistema como Git, los archivos cambiados seran enviados a una 
            dirección de correo electrónico para su revision manual y posterior modificación en el sistema general
        </li>
        <li>
            Si bien se trabajara con una sola branch, se utilizara también pull requests como UNICO metodo para solicitar 
            revisiones o cambios en el código, el comando <span style="font-family: Consolas; font-weight: bold; text-align: center; 
                    align-content: center; align-self: center; display: flex; justify-content: center; -ms-flex-align: center"> git --commit -am o git --push </span> <br> solo se ejecutará luego de una revision del codigo.
        </li>
        <li>
        El trabajo se realizará dentro del ambiente de desarrollo de Clion de JetBrains por lo que si se utiliza otro 
        entorno es normal la presencia de archivos "inconsistentes" como la carpeta .idea
        </li>
    </ul>
</li>
<li>
    Escritura de Código y Coherencia Semántica 
<ul>
    <li>
    Dentro de todo el código del programa se mantendran dos condiciones inherentes y muy importantes para mantener la coherencia
    sintactica del proyecto. Se trabajará sin utilizar <br> <span style="font-family: Consolas; font-weight: bold; text-align: center; 
                    align-content: center; align-self: center; display: flex; justify-content: center; -ms-flex-align: center"> using namespace std;</span> <br> Por tanto
siempre se trabajará utilizando el namespace de donde proviene el código y función externa que se este utilizando. De esta forma evitamos errores al hacer un debloating de
<span style="font-family: Consolas; font-weight: bold; text-align: center; 
                    align-content: center; align-self: center; display: flex; justify-content: center; -ms-flex-align: center"> #include ... </span> <br>
En este sentido, el código tiene que ser legible, limpio y conciso con los includes y los namespaces que en realidad necesita. Asi evitamos un archivo compilado muy
grande. <br> <br>
</li>
<li>
Con respecto a la escritura de nombres de funciones y variables, se trabajara con el conocido snake case, a modo de ejemplo
<span style="font-family: Consolas; font-weight: bold; text-align: center; 
                    align-content: center; align-self: center; display: flex; justify-content: center; -ms-flex-align: center"> unsigned int int_var_with_snake_case{0};</span> <br>
Asi, aunque los nombres parezcan largos, se puede leer mucho más fácil que un nombre utilizando el Camel Case. </li>
<li>
    Las revisiones de escritura y claridad del codigo seran cuasi diarias, y rigurosas por tanto se solicita un poco de empeño en mantener el orden y asi evitar reviews innecesarias 
</li>
</ul>
</li>
<li>
Al trabajar con piezas de codigo que manejen datos externos, siempre tenemos que tener en cuenta que puede entrar un dato
mal, y saber que hacer con estos datos es muy importante. En un caso muy especifico veamos el caso de retornar el numero de 
columnas por fila en el teatro

```c++
unsigned int retornar_numero_de_asientos_basado_en_numero_de_fila(unsigned int numero_de_fila)
{
    try
    {
        if (numero_de_fila > 0 && numero_de_fila < 9)
            {
            return this->numero_de_columnas_por_fila[numero_de_fila];
            }
        else 
            {
            throw std::invalid_argument("Error code 0x001 - Parametros "
                                        "Ingresados Incorrectos - Numero de Fila Invalido");
            }
    }
    catch (std::invalid_argument &error)
    {
        std::cerr << "Error en la Funcion retornar_numero_de_asientos_"
                     "basado_en_numero_de_fila(unsigned int numero_de_fila)\n";
        std::cerr << error.what() << std::endl;
    }
}
```
La pieza de codigo anterior es una de las cosas mas importantes de este documento, ya que demuestra como se trabajara
en el caso de que existan errores al ingreso de datos, el programa no debe fallar, no debe detenerse, debe defenderse de
cada intento de abuso por el usuario y por eso usamos un bloque try-catch. <br>
La excepcion que alzamos, std::invalid_argument() es una excepcion externa en C++ que nos permite inidicar con
mayor claridad que ha habido un error por los parametros sin necesidad de escribir nosotros todo el mensaje.

<br> Asimismo dentro de este programa se trabajaran con diferentes estandares de error: <br>
<ul style=" list-style: lower-roman">
<li>
 <span style="font-weight: bolder"> Error Code 0x001 [Raised] - ... : </span> representan errores de argumentos, errores criticos que no permiten el correcto 
funcionamiento del programa</li>
<li>
 <span style="font-weight: bolder"> Error Code 0x002 [Raised] - ... : </span> repesentan errores en funciones que dependen de otras
si se espera que pueda haber errores con el retorno de alguna otra funcion interdependiente, marcar aquel error con este nombre</li>
<li>
 <span style="font-weight: bolder"> Error Code 0x003 [Raised ] - ... : </span> representan errores en constructores, si se espera que pueda haber errores en constructores, alzar 0x001
y 0x003 juntos con su respectivo mensaje de error</li>
</ul>
</li>
</ul>

* **
<h6 style=" font-family: 'Segoe UI', serif; font-size: 14pt; color: azure"> Especificaciones tecnincas de la clase Logica Basica</h6>

<ul style="font-family: 'Segoe UI', serif; list-style: upper-alpha">
<li>
    La clase Logica basica, es una clase base de la que van a depender las implementaciones de las funciones para el juego, 
los usuarios y en general toda la representacion logica del sistema. <br> Los valores que cuentan esta clase son de la mayor importancia, por tanto
es recomendable tener en cuenta la organización y la claridad en el nombramiento de variables.
</li>
<br>
<li>
    Para los casos de prueba, se deben realizar aproximadamente 40 corridas de tarjetas para evaluar que este no resulte en un problema, si bien
el juego con 3 jugadores no deberia de utilizar todas las cartas sino solamente 24 (ya que cada jugador requiere maximo ocho) sabmos que tenemos que ser capaces
de generar 40 y tener constancia de que ya han sido utilizadas para poder tener control sobre la ejecucion.
<ul>
<br>
<li>
Como el juego cuenta con cinco clanes, o cinco modelos y solo se pueden tener ocho tarjetas por clan, podemos notar que tenemos que 
generar un arreglo con 40 valores enumerados desde el 1 hasta al 40 pero con indices del 0 al 40.
<br>
</li>
<li>
Ademas notamos que requerimos de tener un algoritmo que en lugar de hacer modulo 12 como seria lo normal con una baraja completa, lo que significa
que utilizaremos un modulo 5 y una division para cinco para encontrar tanto el valor y la posicion correspondiente.</li>
<br>
<li>
Por otro lado, la mezcla de las cuarenta cartas no causara ningun problema porque estas al ser divididas para el valor 5 sabemos que podemos tener cartas entre 0,1,2,3,4 
lo que nos devuelve el palo en el que se encuentra si asumimos un orden especifico:

```c++
    //? Asumimos 0 -> Luna; 1-> Sol; 2-> Agua; 3-> Cruz; 4-> Espada;
```

Asimismo asumimos en base a la posicion los signos que se deben de presentar, ya que el nombre de la tarjeta lo podemos
generar nosotros, podemos ademas generar una estructura similar que contenga nombre, peso y clan en base a los numeros anteriores, todo esto se maneja una misma funcion anidada en 
Logica Basica
```c++
struct tarjeta_jugada
        {
            unsigned int valor_de_carta{2}; //(entre 1 y 8)
            std::string nombre_de_la_carta{" 2 de Clan Luna "}; //(Ejemplo para el caso de Luna
            unsigned int clan_de_la_carta{0}; //(almacenamos el clan como otro entero que puede ser leido  por cualqueir funcion)
            
        };
```
</li>
</ul>

</li>

<li>
En el caso de la revision de que las tarjetas fueron o no fueron jugadas, trabajaremos con un metodo de redundancia triple,
en el cual habra chequeos diversos a lo largo de la generacion y adicionales antes de retornar algun valor. <br> Para esto trabajamos con un sistema de analisis de 
tarjetas basado en el tipo de tarjeta, es decir el peso de la tarjeta, y la posicion para evaluar si las tarjetas correspondientes a este peso, 
en todas las situaciones posibles ya han salido o si se trata de que no han salido todas pero si la que se busca. De esta forma tenemos 
un control fuerte sobre las tarjetas que enviamos.
</li>

<li>
Como se puede apreciar en el archivo de implementacion, se trabajo con bastantes metodos de las librerias std::random y 
std::algorithm, los cuales facilitaron el mezclar y el generar indices aleatorios para trabajar con las tarjetas.
<br> Con respecto a las tarjetas, se trabajo con una representacion en forma de matrix, de ocho filas por cinco columnas para 
representar las posibles combinaciones de las tarjetas en el juego. En base a esta representacion se disenaron los atributos constantes,
para manejar la cantidad de tarjetas, los indices que aparecieron y constantes de la logica del juego como son cantidad de 
tarjetas por tipo y cantidad de tipos de tarjetas.
</li>

<li>
El retorno de la clase se realizo uilizando el struct presentado anteriormente en esta seccion, el cual nos permite desglozar 
dentro del programa principal valores para anadir a la clase Jugador, proxima a ser implementada. De esta forma podemos desglozar
tanto: <span style="font-family: Consolas, sans-serif; color: aqua"> nombre de tarjeta, valor de tarjeta, y tipo de tarjeta </span> datos con los que
se puede trabajar para llevar contadores especificos para cada instancia de la clase jugador.
</li>
</ul>

* ** 

<h6 style=" font-family: 'Segoe UI', serif; font-size: 14pt; color: azure"> Especificaciones de la clase Jugador </h6>

<ul style="font-family: 'Segoe UI',sans-serif; list-style: upper-alpha">

<li>
Para la clase del jugador, debemos tener en cuenta que existen una sola forma de ganar en este juego 
<span style=" font-family: Consolas, sans-serif; color: aqua">: mayor puntaje: </span> para esto debemos de tener una de las 
cuatro combinaciones posibles en algun momento de la partida, si tenemos esto podemos decir que sacamos mas puntaje en base
a las cartas que sacamos, o mejor dicho, que la clase logica basica nos entrega.

<br>
Los casos son los siguientes:
<br>
<ul style="list-style: lower-roman">
    <li>
        Si se tiene tres o mas cartas de un mismo valor, entonces cada carta cuenta por siete puntos,
    </li>
    <li>
        Si se tiene tres o mas cartas del mismo clan, entonces cada carta vale cinco puntos,
    </li>
    <li>
        Si se tiene tres o mas cartas de diferentes valores pero consecutivos cada carta vale tres,
    </li>
</ul>
<br>
Basados en estos casos podemos notar que requerimos de tener en cuenta diferentes contadores, una posible implemetacion de esta
clase podria contener algo como lo siguiente:

```c++
#include ...
class pUno_Clase_Jugador
        {
            private:
            //? Contadores para cada tipo de carta
            std::array<std::array<int,5>,8> holder_matriz_para_tarjetas_por_fila_y_columna
            //? Contadores para cartas y puntos del jugador
            int cantidad_de_puntos_jugador{0};
            int cantidad_de_cartas_jugador{0};
            //? Arreglo extra para la impresion de los nombres de cada tarjeta
            std::vector<std::string> holder_para_nombres_de_tarjetas_del_jugador{};
        };

```
Lo bonito de esta solucion al problema es que al decir nosotrso que solamente requerimos una matrix de dos dimensiones 
sabemos que todos los casos se pueden revisar en las mismas, Por ejemplo para el primer caso de cartas con el mismo valor, 
basta con revisar columna por columna si la suma de los valores con un 1 es mayor que 3. Si esto se cumple
entonces decimos que la primera regla se cumple y sumamos el valor de 7 * cantidad de cartas del mismo valor.

<br>
Para el segundo caso, si nosotros hacemos la misma suma pero por columnas entonces tenemos la cantidad de cartas del mismo clan
en la columan y solo hacemos el numero total de cartas por 5 para obtener el puntaje. 

<br>
Para el ultimo caso, podemos implementar un algoritmo de busqueda sencillo que trabaje alrededor de la matriz,y  que se mueva
principalmente por el camino de las columnas, asi, independientemente del clan que sean se encontraran cartas consecutivas
si se encuentran en estas columnas. Asimismo, podriamos incluso utilizar el algoritmo del caso dos y ampliarlo hasta cierto 
punto para que corra para toda la matriz.
</li> 
<li>
Debido a la complejidad de los metodos, es mucho mas factible organizarlos dentro de la misma clase y no delegarlos a  otra,
de esta forma podemos asegurarnos de no necesitar de variables staticas sino simplemente de variables locales a cada objeto. Los metodos
pueden estar organizados independientemente, pero para calcular el puntaje total, seria muy conveniente hacer un metodo general que llame a los 
secudarios y asigne al parametro principal el resultado de las sumas parciales.

</li>

<li>
Con el motivo de mantener el orden con la llamada de las funciones, se decidio adjuntar todos los metodos de calculo de valores
dentro de un mismo metodo en la clase de cada jugador. Ya que los metoos para calcular el total de puntos por caso son 
protected, no tenemos que tener miedo de accesso publico por el usuario a esos metodos y asi nos aseguramos de una correcta
ejecucion del codigi.
<br>
En base a esto, el puntaje va a ser retornado como un solo valor luego de la llamada de esta funcion.
</li>

</ul>

* ** 

<h6 style=" font-family: 'Segoe UI', serif; font-size: 14pt; color: azure"> Especificaciones del archivo principal y funciones generales para programa principal</h6>

<ul style="font-family: 'Segoe UI',sans-serif; list-style: upper-alpha">

Consideremos el proceso del juego en general. Para este paso debemos de tener  en cuenta la necesidad de incorporar todas
las clases que hemos creado: nuestra clase jugador y nuestra clase logica basica. Como sabemos la clase 
logica basica cuenta con la funcionalidad general de todo el juego y es la base del servicio de "dealer" que 
necesita el juego. Por tanto para la clase logica basica tenemos las siguientes especificaciones para las funcoines y su 
trabajo en el main del juego
<ul style="list-style: inherit; font-family: Consolas; color: antiquewhite">
    <li> Un solo objeto de esta clase puede estar presente en todo momento durante el juego.</li>
    <li> Los metodos de funcionamiento para el programa principal deben recibir una referencia al objeto de esta clase</li>
</ul>

Si ahora tomamos en cuenta los requerimientos de la clase jugador, sabemos que para el programa principal se debe de poder
trabajar con n cantidad de jugadores. Por tanto, necesitaremos de un vector de jugadoresl y por lo tanto
<ul style="font-family: Consolas, sans-serif; list-style: inherit; color: antiquewhite">
    <li> Un solo vector para la lista jugador debe ser creado, por esto los jugadores no deben tener constructores que recepten datos</li>
    <li> Para enviar informacion a los metodos exteriores al main se debe enviar una referencia al objeto vector que contiene a los jugadores</li>
</ul>

De esta forma cuando nosotros implementemos nuestras funcioens nunca generaremos copias extras y aseguramos una mejor validacion de datos y 
rapidez para la aplicacion. Por otro lado tenemos que considerar el procesod de ingreso de datos, si bien nosotros podemos intentar y hacer que el usuario,
por medio de mensajes, ingrese valores **corectos**. Nosotros sabemos como programadores que esto es muy probable que no pase y el usuario tenga errores en los datos.

Por esta razon, asumimos el reto de en cada control de ingreso de datos del usuario, redactar controles while y try and except blocks
que nos permitan detener cualquier intento malicioso del usuario. Si bien es cierto que un bloque try and except nunca va a ser accedido por el simple hecho de que 
el while del ingreso de datos no lo va a permitir, nunca esta mal tener un backup para la seguridad del programa.

En base a estas reglas podriamos intentar escribir una aproximacion al menu general que tiene que ver el usuario y una llamada a las funciones
generales (en construccion) que contendra el programa

```c++
unsigned int user_input{0};
do 
    {
        //? Impresion de Menus
        helper_function_one_imprimir_linea_separadora_120_chars(); // Crea una linea de 120 chars
        helper_function_one_imprimir_titulo_120_chars("Menu Principal"); //Imprime titulo organizado
        std::cout << "1. Jugar una Partida. "
                     "\n2. Revisar Estadisticas por Jugador."
                     "\n3. Cambiar el Numero de Jugadores."
                     "\n4. Cambiar el Nombre de los Jugadores."
                     "\n5. Salir del Juego.\n";
        //? Validacion hasta que el dato sea el correto, es decir hasta que ingrese un etero
        while (std::cout << "Opcion Elegida: " &&
               !(std::cin >> user_input)){
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Valor invalido, por favor asegurese de ingresar un entero.\n";
        }
        //? Difurcacion de casos por tipo de opcion del menu
        switch(user_input)
        {
            case 1: 
                {
                    helper_menu_functions_opcion_uno_jugar_partida
                    (std::vector<pUno_Jugador_Clase>& jugadores_placeholder, 
                     pUno_Logica_Basica_Class logica_basica_placeholder&);
                    break;
                }
            case 2:
                {
                    helper_menu_functions_opcion_dos_revisar_estadisticas
                    (std::vector<pUno_Jugador_Clase>& jugadores_placeholder,
                     pUno_Logica_Basica_Class logica_basica_placeholder&);
                    break;
                }
            case 3:
                {
                    helper_menu_functions_opcion_tres_cambiar_numero_jugadores
                    (std::vector<pUno_Jugador_Clase> & Jugadores_placeholder);
                    break;
                }
            case 4:
                {
                    helper_menu_functions_opcion_cuatro_cambiar_nombres_jugadores
                    (std::vector<pUno_Jugador_Clase> & Jugadores_placeholder);
                    break;
                }
            case 5: 
                {
                    helper_function_one_imprimir_titulo_120_chars("Gracias por jugar!");
                    break;
                }
            default:
                {
                    std::cout << 
                    "Error Code 0x001 [Raised] - Opcion de menu Invalida, favor intentelo de nuevo"  
                    << std::endl;
                    break;
                }
        }
    }
    while( user_option != 5)
```

En base al snippet de codigo presentado anteriormente, podemos ntoar que necesitamos de varias secciones de codigo 
importantes, como lo son el primer control para la validacion de entrada de datos. Ademas de esto
para la misma seccion y el control sobre el dato ingresado por el ususario notamos que en el switch existe un caso default para evaluar si es que en realidad el ususario no
solo ingreso un numero sino que si tambien ingreso un numero correcto.

A continuacion de esto entramos a un swithc statement en el cual se detallan las funciones para cada caso y vemos que existen tres de estas que vana  ser muy complicadas de implementar y 
requeriran mayor esfuerzo, la primera funcion requiere manejar casos de anadir tarjetas, el mayor de los puntajes de los usuarios, etc, todo sin saber el numero exacto por tanto para cada caso
se trabajara con vectores que permitan controlar el flujo del juego.

Las funciones para cambio de nombre y cambio de numero de jugadores tienen un poco de complejidad porque debemos preguntar al usuario los jugadores a eliminar, y los jugadores a cambiar el nombre.
Ademas que esto debe usar un metodo pushback y una impresion de nombres de los jugadores en un formato agradable para identificar posiciones en el arreglo.

Luego de haber terminado la implementacion de las funciones para el menu principal, es clave analizar el desempeno y complejidad
de construccion que se ha presentado a lo largo de su desarrollo. Principalmente un problema fue la falta de direccion por 
parte de las indicaciones del proyecto en algunos puntos claves de desarrollo del juego durante empates con diferentes valores o 
con valores iguales a cero. Por tanto, el desarrollo de una función que realice el chequeo para este tipo de casos fue arduo
y requirio implementar varios niveles de complejidad extra en las funciones del juego. 

<ul>
    <li> Por citar un ejemplo, en la funcion general del caso 1, para jugar la partida, necesitamos implementar cuatro diferentes
niveles de seguridad para las tarjetas y para el chequeo de datos, una de las funciones mas complejas de todo el juego y que gracias a un exhaustivo
decoupling de secciones repetidas a helper_functions se logro reducir y trabajar acorde a lo especificado.</li>
<li> En otra instancia, como fue para el chequeo de los valores del arreglo de puntos para cada usuario, la dificultad principal fue el hacer que una misma funcion 
se encargue de realizar todo chequeo necesario, si son iguales, si son valores de cero, si son diferentes, o si hay un ganador. Esto se cumplio gracias a un prtotipo de funcion lineal, una aproximacion a la funcion de Kadane para 
transversar arreglos. <br>

Para esto se aplico un chequeo lineal de cada valor y se guarda tanto el indice como el valor del resultado mas alto. Si bien
estos valores ya los conoce la aplicacion, el return de valores nos permite trabajar directamente dentro del arreglo de jugadores y modificar los valores del ganador.
</li>
<li> Adicionalmente, hubo un nivel de complejidad adicional impuesto en las funciones para anadir cartas al usuario, ya que este debia de por funcionar y darse cuenta de que se han acabo las cartas, 
algo que mas o menos nunca puede pasar, ya que el juego es deterministico y sabemos que alguien en algun momento va  a ganar. Y ademas se implemento un chequeo booleano, proveninente de esta funcion para
notar cambios en la distribucion de cartas, y afrontar el retorno de una senal de baraja vacia de mejor manera.

</li>
</ul>
</ul>

* ** 
<h6 style=" font-family: 'Segoe UI', serif; font-size: 14pt; color: azure"> Comentarios Finales sobre Implementacion </h6>

<ul style="font-family: 'Segoe UI', serif; list-style: upper-alpha; color: antiquewhite">
<li>
    La implementacion de un juego de cartas se trabaja mejor con metodos de control anidados, generacion aleatoria con funciones
deterministicas y matematicas como las del 

```c++
#include <algorithm>
#include <random>
```

Estas funciones nos permiten generar valores que sabemos que seran aleatorios, sin tener que preocuparnos por valores repetidos, 
valores incoherentes o valores similares en cada iteracion. Los valores generados a traves de la libreria random y aplicados con
algorithm son excelentes para promover una generacion de valores correctos y aleatorios, mejores que lo que hace ctime. 
</li>

<li> EL decouppling the metodos es muy util para trabajar con programas multiarchivos, asimismo, el trabajar con un proyecto multiarchivos, facilita el
desarrollo en paralelo y la extesion horizontal y vertical del programa con mas facilidad. Al no depender directamente de metodos compuestos y funciones de 200+ lineas, el programa
tiene flexibilidad y no presenta varios puntos de falla a a causa de una funcion incorrecta. Al crear varias funciones podemos manejar errores e inputs de mejor manera, valiendonos de los codigos de error que se alnzan,
en cada metodo y funcion del programa. Asimismo, la expansion del programa en una serie de archivos, y clases individuales podemos expandir el codigo
para asi tener mas opotunidades de expansion vertical y horizontal, al ser capaces de anadir multiples funcionalidades, sabiendo que los metodos son seguros y su implementacion es concreta. 

</li>

<li> Los codigos de errores planteados originalmente en este archivo fueron de gran ayuda para el debugging de la aplicacion, al saber exactamente de que metodose alzo la exepcion, y los valores del parametro danado, nos permiten
revisar los envios y facilitan el proceso de debugging al usar un debugger com el que viene en el entorno de Clion que permite revisar llamadas hasta al thread del cpu y revisar que dato fue el del problema.
</li>
</ul>





