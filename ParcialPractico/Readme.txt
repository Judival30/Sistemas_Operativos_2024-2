
Este simulador permite visualizar la ejecución de una gestor de procesos de cola multinivel
en donde el usuario puede ingresar n colas, y m procesos, y observar las estaditicas de
rendimiento de la ejecución. Las politicas permitas para las colas son Round Robin y FCFS

Input:
La entrada comienza con un entero Q, este entero representa la cantidad de colas que tendrá
la cola multivel, las siguiente Q lineas poseeran un identificador, ya sea RR (round robin) o
FCFS el cual representará la politica para esa cola, en el caso de RR lo acompañará un entero q,
que representa el quamtum.

Consecutivamente estará un string T, que será el identificador de la cola multinivel, ya sea
MLQ o MLFQ.

Por ultimo, un entero P, que será el numero de procesos que se quieren llevar a cabo, las siguientes
P lineas tendra, un string ID, y tres enteros, at, bt, y qid respectivamente, qid representa en cual
cola estará el proceso para el caso de MLQ.

Output:
El output serán 3 diagramas, el primero una tabla que contendrá el proceso cronologico de la ejecución
en el cual se podrán ver que proceso esta siendo ejecutado, el tiempo actual, y cual cola. En segundo
lugar el diagrama de Grand, que muestra una linea de tiempo de las ejecuciones. Por ultimo, la tabla
en donde se podran observar las estadisticas: wt, rt, ct y tat, donde culmina mostrando los resultados
promedios

