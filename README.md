# SistemaOperativo_GrupoEEDD
#El proyecto “Sistema de Gestión de Procesos” busca simular, de manera sencilla y didáctica, el funcionamiento de un administrador de tareas como el de Windows. Este tipo de sistema permite visualizar y gestionar procesos en ejecución, mostrando información clave como el uso de CPU, memoria, disco y red, así como realizar operaciones básicas como agregar, eliminar o modificar procesos. En este caso, la simulación se desarrollará con fines educativos, permitiendo aplicar estructuras de datos dinámicas como listas enlazadas, pilas y colas en un contexto práctico.
El problema principal consiste en diseñar un sistema que gestione procesos dinámicamente, permitiendo su registro, planificación por prioridad y simulación del uso de memoria. La lista enlazada servirá para almacenar y recorrer los procesos activos, la cola de prioridad para planificar su ejecución según urgencia, y la pila para simular la asignación y liberación de bloques de memoria. Estas estructuras serán implementadas desde cero en C++, reforzando el entendimiento de su lógica interna y su aplicación en la solución de problemas reales.
Además de los aspectos técnicos, el proyecto promueve el trabajo en equipo y la organización de tareas, ya que será desarrollado en grupos colaborativos. También se requiere implementar una interfaz por consola para facilitar la interacción del usuario, así como mecanismos para guardar y cargar el estado del sistema. De esta forma, el proyecto no solo refuerza conocimientos sobre estructuras de datos, sino que también desarrolla competencias clave como la resolución de problemas y la colaboración efectiva.

Nuestra estructura:

Lista
La lista se utiliza para almacenar todos los procesos que han sido registrados por el usuario. Esta estructura permite recorrer los elementos de forma secuencial y es especialmente útil cuando se requiere acceder, modificar o eliminar un proceso específico con base en su ID. Su estructura enlazada permite un crecimiento dinámico, lo que la hace eficiente para la inserción y eliminación de procesos sin necesidad de reorganizar toda la estructura.
Funciones principales:
agregarProceso(): Inserta un nuevo proceso al final de la lista si el ID no está repetido.
buscarProceso(): Recorre la lista para encontrar y devolver el nodo cuyo ID coincida.
eliminarProceso(): Busca el nodo por ID y lo elimina ajustando los punteros.
modificarPrioridad(): Cambia la prioridad del proceso cuyo ID se indique.
mostrarTodos(): Recorre la lista e imprime los datos de todos los procesos registrados.
Esta estructura permite gestionar de forma eficiente los procesos activos y realizar operaciones específicas sin depender de estructuras estáticas.
Cola
La cola se implementa para simular el planificador de la CPU. Es una cola de prioridad que permite almacenar procesos en orden según su prioridad: los de mayor prioridad se colocan primero. Esto simula la manera en que un sistema operativo selecciona el siguiente proceso a ejecutar.
Funciones principales:
encolarProceso(): Inserta un proceso en la posición adecuada dentro de la cola, según su prioridad (mayor prioridad al frente).
ejecutarProceso(): Elimina y devuelve el proceso que está al frente de la cola, simulando su ejecución.
mostrarCola(): Recorre e imprime el contenido de la cola en orden de ejecución.
Esta estructura refleja un comportamiento real del sistema operativo en la asignación del CPU, donde se prioriza la atención a tareas críticas.
Pila
La pila se usa para gestionar los bloques de memoria asignados a los procesos. Opera bajo la lógica LIFO (Last In, First Out), es decir, el último bloque asignado es el primero en ser liberado. Esta estrategia representa la asignación temporal de memoria en muchos sistemas, como el uso de la pila de llamadas.
Funciones principales:
asignarMemoria(): Crea un nuevo bloque de memoria para un proceso específico y lo apila en la cima.
liberarMemoria(): Elimina el bloque que está en la cima de la pila, liberando memoria para otros procesos.
mostrarEstadoMemoria(): Recorre la pila desde el tope hacia abajo mostrando el estado actual de la asignación de memoria.
El uso de una pila permite simular de forma realista la asignación temporal de memoria en ejecuciones anidadas o recursivas, como funciones o tareas dependientes.
