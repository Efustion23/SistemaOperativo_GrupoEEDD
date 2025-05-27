#include <iostream>
#include <string>
using namespace std;

// ====== ESTRUCTURA PARA PROCESOS ======
struct Proceso {
    int id;
    string nombre;
    int prioridad;
    Proceso* siguiente;
};

Proceso* cabeza = nullptr;

// ====== ESTRUCTURA PARA COLA DE PRIORIDAD (CPU) ======
struct NodoCola {
    Proceso* proceso;
    NodoCola* siguiente;
};

NodoCola* frente = nullptr;

asignarMemoria()
{
    cout << "Función para asignar memoria." << "\n";
    
}

liberarMemoria()
{
    cout << "Función para liberar memoria." << "\n";
    
}

mostrarEstadoMemoria()
{
    cout << "Función para mostrar el estado de la memoria." << "\n";
    
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

}

ejecutarProceso()
{
    cout << "Función para ejecutar un proceso." << "\n";

}

mostrarCola()
{
    cout << "Función para mostrar los procesos en cola." << "\n";

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
    cout << "Función para agregar un proceso." << "\n";

}

buscarProceso()
{
    cout << "Función para buscar un proceso." << "\n";

}

eliminarProceso()
{
    cout << "Función para eliminar un proceso." << "\n";

}

modificarPrioridad()
{
    cout << "Función para modificar la prioridad de un proceso." << "\n";

}

mostrarTodos()
{
    cout << "Función para mostrar todos los procesos." << "\n";

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
