Se presenta el juego Siete y Medio en el que el principal componente es un
mazo de 40 cartas españolas, para lo cual se usa un array de tamaño 40
(mazo[40]), el cual contiene números del 0 al 39. Cada número representa una carta
y estas se mezclan gracias a un ciclo for que utilizamos para reasignar cada
elemento dentro del array mazo[40] en posiciones aleatorias e irrepetibles.
Al comenzar el programa se pide al usuario que ingrese la cantidad de
jugadores que van a participar y cuántas rondas quieren jugar. Para verificar que las
cantidades estén dentro de los rangos permitidos, utilizamos un bloque if que, en el
caso de que la condición no se cumpla, le avisa al usuario y le permite ingresar un
nuevo valor. Una vez estos datos son obtenidos, el juego inicia.
Empieza el jugador 1, se le muestra su primera carta y el valor de esta,
además del monto de dinero que tiene disponible para apostar. A continuación, se le
solicita que ingrese el valor de su apuesta (entre 100 y 1500). Si ingresa una
cantidad que no se encuentra en ese rango, se muestra un aviso de error y se le
pide que lo ingrese nuevamente.
A partir de este momento, el jugador 1 debe hacer su primera elección
teniendo en cuenta el valor de la primera carta que le tocó. Puede elegir la opción 1,
que es pedir una carta más y volver a evaluar su situación, o la opción 2, que es
plantarse. En caso de elegir esta última, su turno en la ronda finaliza y debe esperar
al final de esta para comparar el puntaje que haya acumulado con el de la banca.
Si opta por la opción 1, se le entrega una nueva carta y se le muestra el
puntaje acumulado de las cartas que recibió hasta ese momento.
Desde que un jugador pide que se le dé una segunda carta, empiezan a
correr dos posibilidades nuevas: llegar a 7.5 y ganar, o conseguir un número mayor
a 7.5 y perder. Si pasa alguna de estas dos posibilidades, se le informa al jugador su
situación y comienza el siguiente turno. Si no se da ninguna, el jugador puede seguir
solicitando cartas tantas veces como quiera.
Esta situación se va a repetir hasta que todos los jugadores hayan
completado su primera mano y luego será el turno de la banca.
La banca tiene su propio algoritmo por lo que va tomando decisiones de
manera automática dependiendo de las cartas que se le otorguen. El algoritmo hace
que la banca siga pidiendo cartas hasta que llegue a un valor acumulado igual o
mayor a seis, y en este momento se planta.
Llegados a este punto, una vez que la banca termina de jugar, se muestra
una lista con todos los puntajes obtenidos durante la ronda, y otra con las apuestas
que realizaron los jugadores. Además, se muestra lo que pasó con cada jugador en
relación con la banca, a continuación enumeramos todas las posibilidades que se
pueden dar en este momento:
1. Si el jugador y la banca superan los 7.5, ambos pierden pero la banca
se lleva la apuesta.
2. Si el jugador supera los 7.5 y la banca no, la banca gana.
3. Si la banca supera los 7.5 y el jugador no, el jugador gana.
4. Si el jugador y la banca se plantan antes de llegar a 7.5, gana quien
esté más próximo a él.
5. En cualquier caso que el jugador y la banca tengan el mismo puntaje
acumulado, la banca se lleva la apuesta.
6. Si el jugador llega a 7.5 y la banca no, el jugador gana.
Además, el juego cuenta con una serie de premios que son otorgados
cuando un jugador alcanza el objetivo de llegar a 7.5:
•Premio 1: si gana con 7 y figura, se le suma el 50% de lo apostado.
•Premio 2: si gana con 7 y figura del mismo palo, se le suma el 75% de lo
apostado.
•Premio 3: si gana con un 7 de oro y un rey, se le suma el 100% de lo
apostado.
•Premio 4: si gana con 3 o más cartas, se le suma el 25% de lo apostado.
Para terminar la ronda, se indican los montos actualizados de cada jugador y
de la banca. En el caso de haber ganado, se le suman las ganancias y de haber
pedido, se restan las pérdidas.
Al momento de comenzar una nueva ronda, se mezcla el mazo y todas las
cartas vuelven a estar a disposición.
Este procedimiento se repite en cada ronda hasta llegar al final de la última, y
en este momento se muestran algunas estadísticas generales del juego como el
participante que más dinero ganó, cuál fue la apuesta máxima, si los jugadores en
conjunto tuvieron más pérdidas o ganancias, cuántos jugadores consiguieron llegar
a 7.5 con 7 y una figura, y un top 5 de los números de cartas que salieron más
veces a lo largo de la partida.
Macros utilizadas:
APUESTA_MAX: Su valor es 1500 y representa el monto máximo que tiene
permitido apostar cada jugador.
APUESTA_MIN: Su valor es 100 y representa el monto mínimo que tiene permitido
apostar cada jugador.
DINEROINICIAL: Su valor es 5000 y representa el monto inicial del jugador al
empezar la partida.
DINEROBANCA: Su valor es 100000 y representa el monto inicial de la banca al
empezar la partida.
Variables más importantes:
JUGADORES: Al inicio del programa se le solicita al usuario que ingrese la cantidad
de jugadores, ese valor será guardado en la variable JUGADORES y será utilizado
durante el resto del programa en múltiples arrays y funciones.
RONDAS: Esta variable es igual a la cantidad de rondas ingresadas por el usuario
al inicio del programa.
posmazo: Esta variable hace referencia a la posición actual del mazo, la cual irá
variando conforme los jugadores y la banca soliciten cartas y avancen las rondas.
njugador: Esta variable hace referencia al jugador actual, la misma es usada en
múltiples ciclos for y funciones.
nc: El valor de esta variable es devuelta por la función mostrarcarta(). La variable es
usada para hacer referencia al elemento correspondiente del puntero cartanum
cuando se le debe mostrar la carta al jugador.
pc: El valor de esta variable es devuelta por la función mostrarcarta(). La variable es
usada para hacer referencia al elemento correspondiente del puntero cartapalo
cuando se le debe mostrar la carta al jugador.
vc: El valor de esta variable es devuelta por la función mostrarvalor(). La variable es
usada para hacer referencia el elemento correspondiente del array flotante valores
cuando haya que obtener el valor de la carta solicitada por el jugador.
Arrays más importantes:
mazo: Contiene 40 elementos, cada elemento es un número del 0 al 39 que no se
repiten, están mezclados de forma aleatoria y representan cada carta. La decena
del elemento determina el palo de la carta, por lo tanto los valores entre 0 y 9
corresponden a Basto, entre 10 y 19 a Copa, entre 20 y 29 a Espada, y entre 30 y
39 a Oro. La unidad del elemento representa el número de la carta. Por lo tanto:
0 es Uno
1 es Dos
2 es Tres
3 es Cuatro
4 es Cinco
5 es Seis
6 es Siete
7 es Diez
8 es Once
9 es Doce
cartanum: Es un puntero el cual contiene en su interior la primera parte del texto
que se le muestra al jugador cuando recibe una carta. La posición 0 contiene
“ANCHO de”, la 1 contiene “DOS de” y así hasta llegar a “DOCE de”.
cartapalo: Contiene en su interior la segunda parte del texto que se le muestra al
jugador cuando recibe una carta. La posición 0 contiene “BASTO”, la 1 contiene
“COPA”, la 2 contiene “ESPADA” y la 3 contiene “ORO”.
valores: Contiene en su interior los valores numéricos de cada carta, desde el 1
hasta el 7 para las cartas generales, y 0.5 para las figuras.
montos: Representa el dinero de cada jugador durante la partida. Inicialmente cada
elemento es igual a DINEROINICIAL (es decir 5000) ya que ese es el valor que
dispone cada jugador al empezar a jugar. El último elemento del array corresponde
al dinero de la banca, el cual empieza siendo igual a DINEROBANCA (es decir
100000). Estos montos se irán actualizando conforme la partida avance, ya que
dependen de la cantidad de dinero que se apueste en cada ronda y de si el jugador
gane o pierda.
apuestas: Contiene las apuestas hechas por cada jugador en cada ronda. Es decir
que al terminar la ronda, los valores que contenía serán sobreescritos por la nueva
apuesta ingresada en la ronda actual. El valor ingresado debe ser menor o igual a
APUESTA_MAX (es decir 1500) y mayor o igual a APUESTA_MIN (es decir 100).
jugpunt: Posiblemente el array más importante de todos. Se encarga de guardar el
puntaje acumulado por las cartas de cada jugador y de la banca en cada ronda.
Estos valores se guardan en la posición del array correspondiente a cada jugador y
a la banca. Inicialmente, sus elementos son iguales al valor de la primera carta que
reciben los jugadores, estos valores se irán actualizando conforme los jugadores y
la banca soliciten más cartas.
Aclaración general sobre los arrays montos, apuestas y jugpunt: El tamaño de
estos arrays será igual a la cantidad de jugadores ingresada por el usuario + 1, es
decir que es igual a JUGADORES +1. La posición 0 estará reservada para el
jugador 1, la posición 1 para el jugador 2 y así sucesivamente hasta que cada
posición le corresponda a cada jugador. La posición final está reservada para la
banca y en el programa usamos la variable JUGADORES para hacer referencia a la
misma.
Funciones más importantes:
main: es la función principal del programa. Desde ella se van llamando a otras
funciones y es la encargada de enlazarlas con el resto del código dentro de ella para
que el programa funcione de manera correcta. Está compuesta mayormente por
bloques for que recorren distintos arrays y variables para abarcar todas las
situaciones que se presentan a lo largo del juego.
mostrarcarta: utiliza los parámetros de tipo int posmazo, nc, pc y mazo[40]. Está
compuesta por dos ciclos for. El primero se encarga de mostrar el número de la
carta utilizando el módulo de cada uno de los valores de mazo[posmazo], mientras
que el segundo muestra el palo de la carta a partir de el rango en el que se
encuentra ubicada, es decir que si la carta está entre 0 y 9 es de Basto, entre 10 y
19 es Copa, entre 20 y 29, Espada, y entre 30 y 39, Oro.
mostrarvalor: utiliza los parámetros de tipo int posmazo, vc, mazo[40]. Está
compuesta por un ciclo for que, a medida que avanza, le va asignando los valores a
cada una de las cartas, utilizando el módulo de cada uno de los valores de
mazo[posmazo].
Programado por Nicolás Quijano