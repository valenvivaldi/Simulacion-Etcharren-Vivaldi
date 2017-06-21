
Autores:Valentin Vivaldi y Leandro Javier Etcharren

formalismo utilizado:cml-devs

--------------------------------------------------------------------------------------------------------------------------------------------------------------

El archivo Cinta.txt contiene la especificacion de un devs que representa
un cinta por la cual ingresan objetos por el inicio y  nal de una recta de longitud l respectivamente. El objeto que ingresa ya sea por 
la derecha o izquierda, trae como información su peso, y el mismo se desplaza intentando llegar al otro extremo. Cada objeto trae como informacion
su peso.
Cuando se produce una colision el objeto que continua sobre la recta (objeto vencedor) es aquel cuya distancia recorrida multiplicada por su peso 
es mayor. El objeto vencedor continua pero con un peso disminuido según la funcion pesoNuevo . El objeto derrotado 
desaparece de la recta y en caso de empate desaparecen los dos.
Los objetos viajan a una velocidad contante Vc.
Cuando ocurre una colision el sistema saca una salida con la informacion de quien gano, el peso con el que quedo el objeto que gano y la distancia
rrecorrida por este en ese instante. Esta informacion puede ser utilizada para generar distintos tipos de estrategias por el jugador
Si un objeto llega al otro extremo de la cinta el sistema saca una salida con la informacion del player al que pertenece el objete (LLegoJugador en caso
de que el objeto sea del jugador y llego pc en caso de que el objeto sea de Pc)
Pueden haber sobre la recta varios objetos viajando en el mismo sentido. 

----------------------------------------------------------------------------------------------------------------------------------------------------------------

Detalles a considerar

La principal decision que se realizo es llevar el tiempo de ejecucion en el estado y el las colas llevar el peso y el tiempo de arribo de cada 
objeto. Con estos datos mas la velocidad de la cinta podemos  calcular la distacia recorrida de cada objeto en un momento dado. Esto
nos ahorra el tener las colas actualizando las distancias recorridas.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------

