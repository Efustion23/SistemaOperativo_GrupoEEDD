#include <iostream>
#include <string>
using namespace std;
const int MAX = 50;

// ====== ESTRUCTURAS DE DATOS ======

// Estructura para representar un proceso
struct Proceso {
    int id;
    string nombre;
    int prioridad;
};

// ====== ESTRUCTURA PARA COLA (CPU) ======
struct NodoCola {
    Proceso* proceso;
    NodoCola* siguiente;
};

// Variables para la lista de procesos
Proceso listaProcesos[MAX];
int cantidadProcesos = 0;

// Variables para la cola de CPU (planificador)
Proceso colaCPU[MAX];
int frenteCPU = 0;
    int finalCPU = -1;
int cantidadCPU = 0;

// Variables para la pila de memoria
Proceso pilaMemoria[MAX];
int topeMemoria = -1;

// ====== FUNCIONES PARA PROCESOS (LISTA) ======

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



// ====== ESTRUCTURA PARA PILA (MEMORIA) ======
struct BloqueMemoria {
    int idProceso;
    BloqueMemoria* siguiente;
};
asignarMemoria()
{
   int id;
    cout << "Ingrese el ID del proceso: ";
    cin >> id;
    BloqueMemoria* nuevo = new BloqueMemoria;
    nuevo->idProceso = id;
    nuevo->siguiente = cima;
    cima = nuevo;
    cout << "Memoria asignada al proceso " << id << endl;
}

liberarMemoria()
{
    if (cima == nullptr) {
        cout << "No hay memoria que liberar.\n";
        return;
    }
    BloqueMemoria* temp = cima;
    cima = cima->siguiente;
    cout << "Memoria liberada del proceso " << temp->idProceso << endl;
    delete temp;
    
}

mostrarEstadoMemoria()
{
   if (cima == nullptr) {
        cout << "No hay bloques de memoria asignados.\n";
        return;
    }
    BloqueMemoria* actual = cima;
    while (actual != nullptr) {
        cout << "Proceso: " << actual->idProceso << endl;
        actual = actual->siguiente;
    }
    
}


int gestionarMemoria()
{
    cout << "Función para gestionar memoria." << "\n";
    int op3;

    do
    {
        cout << "\n================================" << "\n";
        cout << "\tMENU DE OPCIONES" << "\n";
        cout << "================================" << "\n";
        cout << "1. Asignar Memoria" << "\n";
        cout << "2. Liberar Memoria" << "\n";
        cout << "3. Mostrar Estado de Memoria" << "\n";
        cout << "4. Volver al menú principal" << "\n";
        cout << "================================" << "\n";
        cout << "Seleccione una opción: ";
        cin >> op3;
        switch (op3)
        {
        case 1:
            cout << "Usted ha seleccionado la opción 1: Asignar Memoria" << "\n";
            asignarMemoria();
            break;
        case 2:
            cout << "Usted ha seleccionado la opción 2: Liberar Memoria" << "\n";
            liberarMemoria();
            break;
        case 3:
            cout << "Usted ha seleccionado la opción 3: Mostrar Memoria Asignada" << "\n";
            mostrarEstadoMemoria();
            break;
        case 4:
            cout << "Volviendo al menú principal..." << "\n";
            main();
            break;
        default:  
            cout << "Opción no válida, por favor intente de nuevo." << "\n";
        }
        

    } while (op3 != 4);
    
    return 0;
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
