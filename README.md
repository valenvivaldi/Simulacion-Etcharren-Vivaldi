
Autores: Valentin Vivaldi y Leandro Javier Etcharren

formalismo utilizado:cml-devs

--------------------------------------------------------------------------------------------------------------------------------------------------------------

El archivo Cinta.txt contiene la especificacion de un devs que representa
una cinta por la cual ingresan objetos por el inicio y  final de una recta de longitud l respectivamente. El objeto que ingresa ya sea por 
la derecha o izquierda, trae como información su peso, y el mismo se desplaza intentando llegar al otro extremo.
Cuando se produce una colision el objeto que continua sobre la cinta (objeto vencedor) es aquel cuya distancia recorrida multiplicada por su peso 
es mayor. El objeto vencedor continua pero con un peso disminuido según la funcion pesoNuevo. El objeto derrotado 
desaparece de la cinta y en caso de empate desaparecen los dos.
Los objetos viajan a una velocidad contante Vc.
Cuando ocurre una colision el sistema saca una salida con la informacion de quien gano, el peso con el que quedo el objeto que gano y la distancia
rrecorrida por este en ese instante. Esta informacion puede ser utilizada para generar distintos tipos de estrategias por el jugador
Si un objeto llega al otro extremo de la cinta el sistema saca una salida con la informacion del player al que pertenece el objeto (LLegoJugador en caso
de que el objeto sea del jugador y llego pc en caso de que el objeto sea de Pc)
Pueden haber sobre la recta varios objetos viajando en el mismo sentido. 

----------------------------------------------------------------------------------------------------------------------------------------------------------------

Detalles a considerar sobre la implementacion:

La principal decision que se realizo es llevar el tiempo de ejecucion en el estado y en las colas llevar el peso y el tiempo de arribo de cada 
objeto. Con estos datos mas la velocidad de la cinta podemos  calcular la distancia recorrida de cada objeto en un momento dado. Esto
nos ahorra el tener que ir actualizando las colas con las distancias recorridas.

A la hora la implementacion en powerdevs, se decidio  agrupar los distintos criterios de generacion en 2 atomicos de generador distintos, segun si 
recibian, o no, una retroalimentacion (feedback) proveniente de la cinta. De esta manera, el atomico "generator" contiene condificadas las estrategias 0,1,2 y 3 (siendo la 0 la estrategia de PC) 
y el atomico "feedbackgenerator" el que contenga codificada las estrategias 4,5,6 y 7. 

Ambos generadores reciben como parametro una semilla de la generacion de pesos y de interarrivos,  y tambien reciben como parametro la estrategia que tiene que utilizar el mismo. En el caso de las 
estrategias que no requieran generaro tiempos de interarrivos, la semilla se usara en la seleccion aleatoria de un elemento, segun lo requiera la estrategia.

Se confeccionarion Distintas librerias para alojar las funciones utilizadas en por la cinta (Library.h) y los generadores (NumberGenLibrary.h). Asi como tambien, se ubicaron las constantes de las distribuciones
de las distintas estrategias en una libreria llamada "strategies.h".

La carpeta "modelosproyecto", contiene dos proyectos .pdm, uno utilizando el generador de playerhuman sin feedback (generator.h) y otro utilizando la generacion con feedback (feedbackgenerator.h)

-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Requerimientos de instalacion:
- Sistema operativos Linux (recomendable Ubuntu 14.04).
- Instalar powerdevs (ultima version disponible: 2.4).
- Tener compilador de c++ actualizado(se utilizan librerias de c++11).

Instalacion:
- Copiar carpeta "atomicosproyectos" dentro de la carpeta /home/USERNAME/powerdevs/atomics.
- Copiar carpeta "modeloproyecto" dentro de la carpeta /home/USERNAME/powerdevs/examples. 
(reemplazar USERNAME con el nombre de usuario)

Ejecucion:
- abrir powerdevs.
- abrir proyecto "proyecto.pdf" (estrategias:1,2,3)o "proyectoFeedback.pdm"(estrategias:4,5,6,7), segun la estrategia a utilizar por playerhuman .
- modificar parametros y semillas  en los atomicos (si se desean utilizar sin semillas, generando una generacion aleatoria, poner las semillas en 0).
- Ejecutar simulacion.

Modificacion:
- Para modificar valores de las distribuciones de las estrategias, se pueden modificar en el archivo "strategies.h".

-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Semillas utilizadas para Metricas y analisis de estrategias

Semilla nro: 1
seed Peso PC: 209652397
seed Intearrivo PC 398764592
seed Peso Jugador 924231286
seed Intearrivo Jugador 1478610113


Semilla nro: 2
seed Peso PC: 441365316
seed Intearrivo PC 1537364732
seed Peso Jugador 192771780
seed Intearrivo Jugador 1491434856


Semilla nro: 3
seed Peso PC: 1819583498
seed Intearrivo PC 530702036
seed Peso Jugador 626610454
seed Intearrivo Jugador 1650906867


Semilla nro: 4
seed Peso PC: 1879422757
seed Intearrivo PC 1277901400
seed Peso Jugador 1682652231
seed Intearrivo Jugador 243580377

Corrida nro: 5
seed Peso PC: 1991416409
seed Intearrivo PC 1171049869
seed Peso Jugador 1646868795
seed Intearrivo Jugador 2051556034


Links:

Hoja de calculo con estadisticos de las corridas:
https://docs.google.com/spreadsheets/d/1yM3mydp4G_287xeEKn-x_JRXC-pgtHnYd27chdpC7fw/edit?usp=sharing

Informe de conclusiones:
https://docs.google.com/document/d/1AzN_0CEdL8tE0pOwzgHaoCrLgCyxWYvQ7ItxU6vCrdo/edit?usp=sharing
-----------------------------------------------------------------------------------------------------------------------------------------------------------------