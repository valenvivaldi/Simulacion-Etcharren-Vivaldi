
Autores:Valentin Vivaldi y Leandro Javier Etcharren

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

Detalles a considerar

La principal decision que se realizo es llevar el tiempo de ejecucion en el estado y en las colas llevar el peso y el tiempo de arribo de cada 
objeto. Con estos datos mas la velocidad de la cinta podemos  calcular la distancia recorrida de cada objeto en un momento dado. Esto
nos ahorra el tener que ir actualizando las colas con las distancias recorridas.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------

Semillas utilizadas para Metricas y analisis de estrategias

Corrida nro: 1
seed Peso PC: 209652397
seed Intearrivo PC 398764592
seed Peso Jugador 924231286
seed Intearrivo Jugador 1478610113


Corrida nro: 2
seed Peso PC: 441365316
seed Intearrivo PC 1537364732
seed Peso Jugador 192771780
seed Intearrivo Jugador 1491434856


Corrida nro: 3
seed Peso PC: 1819583498
seed Intearrivo PC 530702036
seed Peso Jugador 626610454
seed Intearrivo Jugador 1650906867


Corrida nro: 4
seed Peso PC: 1879422757
seed Intearrivo PC 1277901400
seed Peso Jugador 1682652231
seed Intearrivo Jugador 243580377

Corrida nro: 5
seed Peso PC: 1991416409
seed Intearrivo PC 1171049869
seed Peso Jugador 1646868795
seed Intearrivo Jugador 2051556034

-----------------------------------------------------------------------------------------------------------------------------------------------------------------