#include <iostream>
#include <string>
using namespace std;
const int MAX = 50;

struct Proceso {
    int id;
    string nombre;
    int prioridad;
};

Proceso listaProcesos[MAX];
int cantidadProcesos = 0;

Proceso colaCPU[MAX];
int frenteCPU = 0;
    int finalCPU = -1;
int cantidadCPU = 0;

Proceso pilaMemoria[MAX];
int topeMemoria = -1;

bool listaProcesosLlena() {
    return cantidadProcesos == MAX;
}

void agregarProceso() {
    if (listaProcesosLlena()) {
        cout << "Error: No se pueden agregar más procesos. Límite alcanzado.\n";
        return;
    }

    Proceso nuevo;
    cout << "Ingrese ID del proceso: ";
    cin >> nuevo.id;
    
    // Verificar si el ID ya existe
    for (int i = 0; i < cantidadProcesos; i++) {
        if (listaProcesos[i].id == nuevo.id) {
            cout << "Error: Ya existe un proceso con ese ID.\n";
            return;
        }
    }
    
    cin.ignore(); // Limpiar el buffer
    cout << "Ingrese nombre del proceso: ";
    getline(cin, nuevo.nombre);
    
    cout << "Ingrese prioridad (1-10, donde 10 es mayor prioridad): ";
    cin >> nuevo.prioridad;
    
    // Agregar el proceso al final de la lista
    listaProcesos[cantidadProcesos] = nuevo;
    cantidadProcesos++;
    
    cout << "Proceso agregado correctamente.\n";
}

void mostrarProcesos() {
    if (cantidadProcesos == 0) {
        cout << "No hay procesos registrados.\n";
        return;
    }
    
    cout << "\n=== LISTA DE PROCESOS ===\n";
    for (int i = 0; i < cantidadProcesos; i++) {
        cout << "ID: " << listaProcesos[i].id 
             << " | Nombre: " << listaProcesos[i].nombre 
             << " | Prioridad: " << listaProcesos[i].prioridad << "\n";
    }
}

void buscarProceso() {
    int id;
    cout << "Ingrese ID del proceso a buscar: ";
    cin >> id;
    
    for (int i = 0; i < cantidadProcesos; i++) {
        if (listaProcesos[i].id == id) {
            cout << "\nProceso encontrado:\n";
            cout << "ID: " << listaProcesos[i].id 
                 << "\nNombre: " << listaProcesos[i].nombre 
                 << "\nPrioridad: " << listaProcesos[i].prioridad << "\n";
            return;
        }
    }
    
    cout << "Proceso no encontrado.\n";
}

// ====== FUNCIONES PARA CPU (COLA DE PRIORIDAD) ======

bool cpuLlena() {
    return cantidadCPU == MAX;
}

bool cpuVacia() {
    return cantidadCPU == 0;
}

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

encolarProceso()
{
    cout << "Función para encolar un proceso." << "\n";
     int id;
    cout << "Ingrese el ID del proceso a encolar: ";
    cin >> id;

    Proceso* actual = cabeza;
    while (actual != nullptr && actual->id != id) {
        actual = actual->siguiente;
    }
    if (actual == nullptr) {
        cout << "Proceso no encontrado.\n";
        return;
    }
    NodoCola* nuevo = new NodoCola;
    nuevo->proceso = actual;
    nuevo->siguiente = nullptr;

    if (frente == nullptr) {
        frente = fin = nuevo;
    } else {
        fin->siguiente = nuevo;
        fin = nuevo;
    }
    cout << "Proceso encolado.\n";
}

}

ejecutarProceso()
{
    cout << "Función para ejecutar un proceso." << "\n";
     if (frente == nullptr) {
        cout << "No hay procesos en la cola.\n";
        return;
    }
    NodoCola* temp = frente;
    frente = frente->siguiente;
    cout << "Ejecutando proceso ID: " << temp->proceso->id << ", Nombre: " << temp->proceso->nombre << endl;
    delete temp;
    if (frente == nullptr) fin = nullptr;

}

mostrarCola()
{
    cout << "Función para mostrar los procesos en cola." << "\n";
    if (frente == nullptr) {
        cout << "Cola vacía.\n";
        return;
    }
    NodoCola* actual = frente;
    while (actual != nullptr) {
        cout << "ID: " << actual->proceso->id << ", Nombre: " << actual->proceso->nombre << endl;
        actual = actual->siguiente;
    }

}

int gestionarCPU()
{
    cout << "Función para gestionar CPU." << "\n";
    int op2;

    do
    {
        cout << "\n================================" << "\n";
        cout << "\tMENU DE OPCIONES" << "\n";
        cout << "================================" << "\n";
        cout << "1. Encolar Proceso" << "\n";
        cout << "2. Ejecutar Proceso" << "\n";
        cout << "3. Mostrar Procesos en Cola" << "\n";
        cout << "4. Volver al menú principal" << "\n";
        cout << "================================" << "\n";
        cout << "Seleccione una opción: ";
        cin >> op2;
        switch (op2)
        {
        case 1:
            cout << "Usted ha seleccionado la opción 1: Encolar Proceso" << "\n";
            encolarProceso();
            break;
        case 2:
            cout << "Usted ha seleccionado la opción 2: Ejecutar Proceso" << "\n";
            ejecutarProceso();
            break;
        case 3:
            cout << "Usted ha seleccionado la opción 3: Mostrar Procesos en Cola" << "\n";
            mostrarCola();
            break;
        case 4:
            cout << "Volviendo al menú principal..." << "\n";
            main();
            break;
        default:  
            cout << "Opción no válida, por favor intente de nuevo." << "\n";
        }
        

    } while (opcion != 4);
    
    return 0;
}

agregarProceso()
{
   int id, prioridad;
    string nombre;
    cout << "Ingrese ID: "; cin >> id;
    cout << "Ingrese nombre: "; cin.ignore(); getline(cin, nombre);
    cout << "Ingrese prioridad: "; cin >> prioridad;

    Proceso* actual = cabeza;
    while (actual != nullptr) {
        if (actual->id == id) {
            cout << "ID ya existe.\n";
            return;
        }
        actual = actual->siguiente;
    }

    Proceso* nuevo = new Proceso;
    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->prioridad = prioridad;
    nuevo->siguiente = nullptr;

    if (cabeza == nullptr) cabeza = nuevo;
    else {
        actual = cabeza;
        while (actual->siguiente != nullptr) actual = actual->siguiente;
        actual->siguiente = nuevo;
    }
    cout << "Proceso agregado.\n";
}

buscarProceso()
{
    cout << "Función para buscar un proceso." << "\n";
     int id;
    cout << "Ingrese ID del proceso a buscar: "; cin >> id;
    Proceso* actual = cabeza;
    while (actual != nullptr) {
        if (actual->id == id) {
            cout << "Nombre: " << actual->nombre << ", Prioridad: " << actual->prioridad << endl;
            return;
        }
        actual = actual->siguiente;
    }
    cout << "Proceso no encontrado.\n";

}

eliminarProceso()
{
    cout << "Función para eliminar un proceso." << "\n";
    int id;
    cout << "Ingrese ID del proceso a eliminar: "; cin >> id;
    if (cabeza == nullptr) return;
    if (cabeza->id == id) {
        Proceso* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
        cout << "Proceso eliminado.\n";
        return;
    }
    Proceso* actual = cabeza;
    while (actual->siguiente != nullptr && actual->siguiente->id != id) {
        actual = actual->siguiente;
    }
    if (actual->siguiente != nullptr) {
        Proceso* temp = actual->siguiente;
        actual->siguiente = temp->siguiente;
        delete temp;
        cout << "Proceso eliminado.\n";
    } else {
        cout << "Proceso no encontrado.\n";
    }

}

modificarPrioridad()
{
    cout << "Función para modificar la prioridad de un proceso." << "\n";
     int id, nuevaPrioridad;
    cout << "Ingrese ID del proceso: "; cin >> id;
    Proceso* actual = cabeza;
    while (actual != nullptr) {
        if (actual->id == id) {
            cout << "Ingrese nueva prioridad: "; cin >> nuevaPrioridad;
            actual->prioridad = nuevaPrioridad;
            cout << "Prioridad actualizada.\n";
            return;
        }
        actual = actual->siguiente;
    }
    cout << "Proceso no encontrado.\n";

}

mostrarTodos()
{
    cout << "Función para mostrar todos los procesos." << "\n";
    if (cabeza == nullptr) {
        cout << "No hay procesos registrados.\n";
        return;
    }
    Proceso* actual = cabeza;
    while (actual != nullptr) {
        cout << "ID: " << actual->id << ", Nombre: " << actual->nombre << ", Prioridad: " << actual->prioridad << endl;
        actual = actual->siguiente;
    }

}

int gestionarProcesos()
{
    cout << "Función para gestionar procesos." << "\n";
    

    int op1;

    do
    {
        cout << "\n================================" << "\n";
        cout << "\tMENU DE OPCIONES" << "\n";
        cout << "================================" << "\n";
        cout << "1. Agregar Proceso" << "\n";
        cout << "2. Buscar Proceso" << "\n";
        cout << "3. Eliminar Proceso" << "\n";
        cout << "4. Modificar Prioridad" << "\n";
        cout << "5. Mostrar Procesos" << "\n";
        cout << "6. Volver al menú principal" << "\n";
        cout << "================================" << "\n";

        cout << "Seleccione una opción: ";
        cin >> op1;

        switch(op1) {
            case 1:
                cout << "Usted ha seleccionado la opción 1: Crear Proceso" << "\n";
                agregarProceso();
                break;
            case 2:
                cout << "Usted ha seleccionado la opción 2: Listar Procesos" << "\n";
                buscarProceso();
                break;
            case 3:
                cout << "Usted ha seleccionado la opción 3: Eliminar Proceso" << "\n";
                eliminarProceso();
                break;
            case 4:
                cout << "Usted ha seleccionado la opción 4: Modificar Prioridad" << "\n";
                modificarPrioridad();
                break;

            case 5:
                cout << "Usted ha seleccionado la opción 5: Mostrar Procesos" << "\n";
                mostrarTodos();
                break;
            case 6:
                cout << "Volviendo al menú principal..." << "\n";
                main();
                break;
            default:
                cout << "Opción no válida, por favor intente de nuevo." << "\n";
        }
    }while (opcion != 6);

    return 0;
}

int main() {
    int opcion;

    do 
    {
        // Mostramos el menú para que el usuario elija una acción
        cout << "\n================================" << "\n";
        cout << "\tSea Bienvenido" << "\n";
        cout << "================================" << "\n";
        cout << "Sistema de Gestión de Datos" << "\n"; 
        cout << "\n================================" << "\n";
        cout << "\tMENU DE OPCIONES" << "\n";
        cout << "================================" << "\n";
        cout << "1. Gestionar Procesos" << "\n";
        cout << "2. Gestionar CPU" << "\n";
        cout << "3. Gestionar Memoria" << "\n";
        cout << "4. Salir" << "\n";
        cout << "================================" << "\n";

        cout << "Seleccione una opción: ";
        cin >> opcion;

        // Ejecutamos la opción seleccionada
        switch(opcion) {
            case 1:
                cout << "Usted ha seleccionado la opción 1: Gestionar Procesos" << "\n";
                gestionarProcesos();
                break;
            case 2:
                cout << "Usted ha seleccionado la opción 2: Gestionar CPU" << "\n";
                gestionarCPU();
                break;
            case 3:
                cout << "Usted ha seleccionado la opción 3: Gestionar Memoria" << "\n";
                gestionarMemoria();
                break;
            case 4:
                cout << "Usted ha seleccionado la opción 4: Salir" << "\n";
                cout << "Saliendo del sistema..." << "\n";
                break;
            default:
                cout << "Opción no válida, por favor intente de nuevo." << "\n";
        }

    } while (opcion != 4);  

    return 0;
}
