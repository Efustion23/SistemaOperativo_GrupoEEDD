#include <iostream>
#include <string>
#include <sstream> // Esto es para convertir string a int/float, en parte es importante
using namespace std;

struct Proceso {
    int id;
    string nombre;
    int prioridad;
    float memoriaMB;
};

// === LISTA ENLAZADA PARA PROCESOS ===
struct NodoProceso
{
    Proceso dato;
    NodoProceso* siguiente;
};
NodoProceso* cabeza = NULL;

// === COLA DE PRIORIDAD PARA CPU ===
struct NodoCola
{
    Proceso dato;
    NodoCola* siguiente;
};
NodoCola* frenteCPU = NULL;
NodoCola* finalCPU = NULL;

// === PILA PARA MEMORIA ===
struct NodoPila
{
    Proceso dato;
    NodoPila* siguiente;
};
NodoPila* topeMemoria = NULL;

// ====== FUNCIONES DE LA LISTA ======

bool existeProceso(int id)
{
    NodoProceso* actual = cabeza;
    
    while (actual != NULL)
	{
        if (actual->dato.id == id) return true;
        actual = actual->siguiente;
    }
    return false;
}

void agregarProceso() {
    Proceso nuevo;
    cout << "Ingrese ID del proceso: "; cin >> nuevo.id;
    if (existeProceso(nuevo.id))
	{
        cout << "Error: Ya existe un proceso con ese ID.\n";
        return;
    }
    cin.ignore();
    cout << "Ingrese nombre del proceso: "; getline(cin, nuevo.nombre);
    cout << "Ingrese prioridad (1-10): "; cin >> nuevo.prioridad;
    cout << "Ingrese memoria que usará el proceso (MB): "; cin >> nuevo.memoriaMB;

    NodoProceso* nodo = new NodoProceso;
    nodo->dato = nuevo;
    nodo->siguiente = NULL;

    if (cabeza == NULL) cabeza = nodo;
    else
	{
        NodoProceso* actual = cabeza;
        while (actual->siguiente != NULL) actual = actual->siguiente;
        actual->siguiente = nodo;
    }
    cout << "\n? Proceso agregado correctamente.\n";
}

void mostrarProcesos() {
    if (cabeza == NULL)
	{
        cout << "No hay procesos registrados.\n"; return;
    }
    cout << "\n=== LISTA DE PROCESOS ===\n";
    NodoProceso* actual = cabeza;
    while (actual != NULL)
	{
        cout << "ID: " << actual->dato.id
             << " | Nombre: " << actual->dato.nombre
             << " | Prioridad: " << actual->dato.prioridad
             << " | Memoria: " << actual->dato.memoriaMB << " MB\n";
        actual = actual->siguiente;
    }
}

void buscarProceso() {
    int id;
    cout << "Ingrese ID del proceso a buscar: "; cin >> id;
    NodoProceso* actual = cabeza;
    while (actual != NULL)
	{
        if (actual->dato.id == id)
		{
            cout << "\nProceso encontrado:\n";
            cout << "ID: " << actual->dato.id << "\nNombre: " << actual->dato.nombre
                 << "\nPrioridad: " << actual->dato.prioridad
                 << "\nMemoria: " << actual->dato.memoriaMB << " MB\n";
            return;
        }
        actual = actual->siguiente;
    }
    cout << "Proceso no encontrado.\n";
}

void eliminarProceso()
{
    int id;
    cout << "Ingrese ID del proceso a eliminar: "; cin >> id;
    NodoProceso* actual = cabeza;
    NodoProceso* anterior = NULL;
    while (actual != NULL && actual->dato.id != id)
	{
        anterior = actual;
        actual = actual->siguiente;
    }
    if (actual == NULL)
	{
        cout << "Proceso no encontrado.\n";
        return;
    }
    if (anterior == NULL) cabeza = actual->siguiente;
    else anterior->siguiente = actual->siguiente;
    delete actual;
    cout << "Proceso eliminado correctamente.\n";
}
void modificarPrioridad()
{
    int id, nuevaPrioridad;
    cout << "Ingrese ID del proceso: "; cin >> id;
    cout << "Ingrese nueva prioridad: "; cin >> nuevaPrioridad;
    NodoProceso* actual = cabeza;
    while (actual != NULL)
	{
        if (actual->dato.id == id)
		{
            actual->dato.prioridad = nuevaPrioridad;
            cout << "Prioridad actualizada.\n";
            return;
        }
        actual = actual->siguiente;
    }
    cout << "Proceso no encontrado.\n";
}


// ====== FUNCIONES PARA CPU (COLA DE PRIORIDAD) ======

void encolarProcesoCPU() {
    if (cpuLlena()) {
        cout << "Error: La cola de CPU está llena.\n";
        return;
    }
    
    int id;
    cout << "Ingrese ID del proceso a encolar: ";
    cin >> id;
    // Buscar el proceso en la lista
    int pos = -1;
    for (int i = 0; i < cantidadProcesos; i++) {
        if (listaProcesos[i].id == id) {
            pos = i;
            break;
        }
    }
    
    if (pos == -1) {
        cout << "Error: No existe un proceso con ese ID.\n";
        return;
    }
    
    // Insertar en la cola según prioridad (mayor prioridad primero)
    int i;
    for (i = finalCPU; i >= frenteCPU; i--) {
        if (listaProcesos[pos].prioridad > colaCPU[i].prioridad) {
            colaCPU[i+1] = colaCPU[i];
        } else {
            break;
        }
    }
    
    colaCPU[i+1] = listaProcesos[pos];
    finalCPU++;
    cantidadCPU++;
    
    cout << "Proceso encolado en CPU correctamente.\n";
}

void ejecutarProcesoCPU() {
    if (cpuVacia()) {
        cout << "Error: No hay procesos en la cola de CPU.\n";
        return;
    }
    
    cout << "Ejecutando proceso:\n";
    cout << "ID: " << colaCPU[frenteCPU].id 
         << " | Nombre: " << colaCPU[frenteCPU].nombre 
         << " | Prioridad: " << colaCPU[frenteCPU].prioridad << "\n";
    
    // Mover todos los procesos hacia adelante
    for (int i = frenteCPU; i < finalCPU; i++) {
        colaCPU[i] = colaCPU[i+1];
    }
    
    finalCPU--;
    cantidadCPU--;
}

void mostrarColaCPU() {
    if (cpuVacia()) {
        cout << "La cola de CPU está vacía.\n";
        return;
    }

    cout << "\n=== COLA DE CPU (Orden de ejecución) ===\n";
    for (int i = frenteCPU; i <= finalCPU; i++) {
        cout << "ID: " << colaCPU[i].id 
             << " | Nombre: " << colaCPU[i].nombre 
             << " | Prioridad: " << colaCPU[i].prioridad << "\n";
    }
}


// ====== FUNCIONES PARA MEMORIA (PILA) ======

bool memoriaLlena() {
    return topeMemoria == MAX - 1;
}

bool memoriaVacia() {
    return topeMemoria == -1;
}

void asignarMemoria() {
    if (memoriaLlena()) {
        cout << "Error: No hay más memoria disponible.\n";
        return;
    }
    
    int id;
    cout << "Ingrese ID del proceso a asignar memoria: ";
    cin >> id;
    
    // Buscar el proceso en la lista
    int pos = -1;
    for (int i = 0; i < cantidadProcesos; i++) {
        if (listaProcesos[i].id == id) {
            pos = i;
            break;
        }
    }
    
    if (pos == -1) {
        cout << "Error: No existe un proceso con ese ID.\n";
        return;
    }
    
    // Asignar memoria (push en la pila)
    topeMemoria++;
    pilaMemoria[topeMemoria] = listaProcesos[pos];
    
    cout << "Memoria asignada al proceso " << id << " correctamente.\n";
}

void liberarMemoria() {
    if (memoriaVacia()) {
        cout << "Error: No hay memoria asignada para liberar.\n";
        return;
    }
    
    cout << "Liberando memoria del proceso:\n";
    cout << "ID: " << pilaMemoria[topeMemoria].id 
         << " | Nombre: " << pilaMemoria[topeMemoria].nombre << "\n";
    
    topeMemoria--;
}

void mostrarMemoria() {
    if (memoriaVacia()) {
        cout << "No hay memoria asignada actualmente.\n";
        return;
    }
    
    cout << "\n=== ESTADO DE LA MEMORIA (LIFO) ===\n";
    for (int i = topeMemoria; i >= 0; i--) {
        cout << "ID: " << pilaMemoria[i].id 
             << " | Nombre: " << pilaMemoria[i].nombre 
             << " | Prioridad: " << pilaMemoria[i].prioridad << "\n";
    }
}

// ====== MENÚ PRINCIPAL ======

void menuProcesos() {
    int opcion;
    do {
        cout << "\n=== GESTION DE PROCESOS ===\n";
        cout << "1. Agregar proceso\n";
        cout << "2. Mostrar todos los procesos\n";
        cout << "3. Buscar proceso por ID\n";
        cout << "4. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1: agregarProceso(); break;
            case 2: mostrarProcesos(); break;
            case 3: buscarProceso(); break;
            case 4: break;
            default: cout << "Opción no válida.\n";
        }
    } while (opcion != 4);
}

void menuCPU() {
    int opcion;
    do {
        cout << "\n=== GESTION DE CPU ===\n";
        cout << "1. Encolar proceso\n";
        cout << "2. Ejecutar siguiente proceso\n";
        cout << "3. Mostrar cola de CPU\n";
        cout << "4. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1: encolarProcesoCPU(); break;
            case 2: ejecutarProcesoCPU(); break;
            case 3: mostrarColaCPU(); break;
            case 4: break;
            default: cout << "Opción no válida.\n";
        }
    } while (opcion != 4);
}

void menuMemoria() {
    int opcion;
    do {
        cout << "\n=== GESTION DE MEMORIA ===\n";
        cout << "1. Asignar memoria a proceso\n";
        cout << "2. Liberar memoria\n";
        cout << "3. Mostrar estado de memoria\n";
        cout << "4. Volver al menú principal\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1: asignarMemoria(); break;
            case 2: liberarMemoria(); break;
            case 3: mostrarMemoria(); break;
            case 4: break;
            default: cout << "Opción no válida.\n";
        }
    } while (opcion != 4);
}


int main() {
    int opcion;
    
    do {
        cout << "\n=== SISTEMA DE GESTION DE PROCESOS ===\n";
        cout << "1. Gestionar procesos\n";
        cout << "2. Gestionar CPU\n";
        cout << "3. Gestionar memoria\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1: menuProcesos(); break;
            case 2: menuCPU(); break;
            case 3: menuMemoria(); break;
            case 4: cout << "Saliendo del sistema...\n"; break;
            default: cout << "Opción no válida.\n";
        }
    } while (opcion != 4);
    
    return 0;
}
