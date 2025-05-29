#include <iostream>
#include <string>
using namespace std;

struct Proceso
{
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

// === FUNCIONES DE LA LISTA ===
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

void agregarProceso()
{
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
    cout << "\n Proceso agregado correctamente.\n";
}
void mostrarProcesos()
{
    if (cabeza==NULL)
    {
	    cout<< "No hay procesos registrados.\n";return;
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

void buscarProceso()
{
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

// === FUNCIONES DE COLA (CPU) ===
void encolarProcesoCPU()
{
    int id;
    cout << "Ingrese ID del proceso a encolar: "; cin >> id;
    NodoProceso* actual = cabeza;
    while (actual != NULL && actual->dato.id != id) actual = actual->siguiente;
    if (actual == NULL)
    {
        cout << "Error: No existe un proceso con ese ID.\n"; return;
    }
    NodoCola* nuevo = new NodoCola;
    nuevo->dato = actual->dato;
    nuevo->siguiente = NULL;

    if (frenteCPU == NULL || nuevo->dato.prioridad > frenteCPU->dato.prioridad)
    {
        nuevo->siguiente = frenteCPU;
        frenteCPU = nuevo;
        if (finalCPU == NULL) finalCPU = nuevo;
    }
    else
    {
        NodoCola* temp = frenteCPU;
        while (temp->siguiente != NULL && temp->siguiente->dato.prioridad >= nuevo->dato.prioridad)
            temp = temp->siguiente;
        nuevo->siguiente = temp->siguiente;
        temp->siguiente = nuevo;
        if (nuevo->siguiente == NULL) finalCPU = nuevo;
    }
    cout << "Proceso encolado correctamente.\n";
}

void ejecutarProcesoCPU()
{
    if (frenteCPU == NULL)
    {
        cout << "Error: No hay procesos en la cola.\n"; return;
    }
    NodoCola* temp = frenteCPU;
    cout << "Ejecutando proceso: " << temp->dato.nombre << " (ID: " << temp->dato.id << ")\n";
    frenteCPU = frenteCPU->siguiente;
    if (frenteCPU == NULL) finalCPU = NULL;
    delete temp;
}

void mostrarColaCPU()
{
    if (frenteCPU == NULL)
    {
        cout << "Cola vacía.\n"; return;
    }
    cout << "\n=== COLA DE CPU ===\n";
    NodoCola* actual = frenteCPU;
    while (actual != NULL)
    {
        cout << "ID: " << actual->dato.id << " | Nombre: " << actual->dato.nombre
             << " | Prioridad: " << actual->dato.prioridad << "\n";
        actual = actual->siguiente;
    }
}

// === FUNCIONES DE PILA (MEMORIA) ===
void asignarMemoria()
{
    int id;
    cout << "Ingrese ID del proceso a asignar memoria: "; cin >> id;
    NodoProceso* actual = cabeza;
    while (actual != NULL && actual->dato.id != id) actual = actual->siguiente;
    if (actual == NULL)
	{
        cout << "Proceso no encontrado.\n"; return;
    }
    NodoPila* nuevo = new NodoPila;
    nuevo->dato = actual->dato;
    nuevo->siguiente = topeMemoria;
    topeMemoria = nuevo;
    cout << "Memoria asignada al proceso correctamente.\n";
}

void liberarMemoria()
{
    if (topeMemoria == NULL)
	{
        cout << "No hay memoria para liberar.\n"; return;
    }
    NodoPila* temp = topeMemoria;
    cout << "Liberando memoria de: " << temp->dato.nombre << " (" << temp->dato.memoriaMB << " MB)\n";
    topeMemoria = topeMemoria->siguiente;
    delete temp;
}

void mostrarMemoria()
{
    if (topeMemoria == NULL)
	{
        cout << "Memoria vacía.\n"; return;
    }
    cout << "\n=== PILA DE MEMORIA ===\n";
    NodoPila* actual = topeMemoria;
    while (actual != NULL)
	{
        cout << "ID: " << actual->dato.id
             << " | Nombre: " << actual->dato.nombre
             << " | Memoria: " << actual->dato.memoriaMB << " MB\n";
        actual = actual->siguiente;
    }
}

void mostrarMemoriaTotal()
{
    float total = 0.0;
    NodoPila* actual = topeMemoria;
    while (actual != NULL)
	{
        total += actual->dato.memoriaMB;
        actual = actual->siguiente;
    }
    cout << "\n -----> Memoria total usada: " << total << " MB\n";
}

// === MENÚS ===
void menuProcesos()
{
    int op;
    do
	{
        cout << "\n+--------------------------------+\n";
        cout << "|        GESTION DE PROCESOS     |\n";
        cout << "|--------------------------------|\n";
        cout << "| 1. Agregar Proceso             |\n";
        cout << "| 2. Mostrar Procesos            |\n";
        cout << "| 3. Buscar Proceso por Id       |\n";
        cout << "| 4. Eliminar Proceso            |\n";
        cout << "| 5. Modificar Prioridad         |\n";
        cout << "| 6. Volver                      |\n";
        cout << "+--------------------------------+\n";
        cout << "Opcion: "; cin >> op;
        
        switch (op)
		{
            case 1: agregarProceso(); break;
            case 2: mostrarProcesos(); break;
            case 3: buscarProceso(); break;
            case 4: eliminarProceso(); break;
            case 5: modificarPrioridad(); break;
            
        }
    } while (op != 6);
}

void menuCPU()
{
    int op;
    do
	{
        cout << "\n+--------------------------------+\n";
        cout << "|         GESTION DE CPU         |\n";
        cout << "|--------------------------------|\n";
        cout << "| 1. Encolar Proceso             |\n";
        cout << "| 2. Ejecutar Proceso            |\n";
        cout << "| 3. Mostrar Cola                |\n";
        cout << "| 4. Volver                      |\n";
        cout << "+--------------------------------+\n";
        cout << "Opcion: "; cin >> op;
        switch (op)
		{
            case 1: encolarProcesoCPU(); break;
            case 2: ejecutarProcesoCPU(); break;
            case 3: mostrarColaCPU(); break;
        }
    } while (op != 4);
}

void menuMemoria()
{
    int op;
    do
	{
        cout << "\n+--------------------------------+\n";
        cout << "|       GESTION DE MEMORIA       |\n";
        cout << "|--------------------------------|\n";
        cout << "| 1. Asignar Memoria             |\n";
        cout << "| 2. Liberar Memoria             |\n";
        cout << "| 3. Mostrar Memoria             |\n";
        cout << "| 4. Ver Memoria Total           |\n";
        cout << "| 5. Volver                      |\n";
        cout << "+--------------------------------+\n";
        
        cout << "Opcion: "; cin >> op;
        
        switch (op)
		{
            case 1: asignarMemoria(); break;
            case 2: liberarMemoria(); break;
            case 3: mostrarMemoria(); break;
            case 4: mostrarMemoriaTotal(); break;
        }
    } while (op != 5);
}

int main()
{
    setlocale(LC_CTYPE, "Spanish");
    int opcion;
    do
	{
        cout << "\n-------------------------------------\n";
        cout << "     SISTEMA DE GESTION DE PROCESOS  \n";
        cout << "-------------------------------------\n";
        cout << "1. Gestion de Procesos\n";
        cout << "2. Gestion de CPU\n";
        cout << "3. Gestion de Memoria\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        switch (opcion)
		{
            case 1: menuProcesos(); break;
            case 2: menuCPU(); break;
            case 3: menuMemoria(); break;
            case 4: cout << "Saliendo del programa...\n"; break;
            default: cout << "Opción no válida.\n";
        }
    } while (opcion != 4);
    return 0;
}
