#include <iostream>
#include <string>
using namespace std;

asignarMemoria()
{
    cout << "Funci�n para asignar memoria." << "\n";
    
}

liberarMemoria()
{
    cout << "Funci�n para liberar memoria." << "\n";
    
}

mostrarEstadoMemoria()
{
    cout << "Funci�n para mostrar el estado de la memoria." << "\n";
    
}


int gestionarMemoria()
{
    cout << "Funci�n para gestionar memoria." << "\n";
    int op3;

    do
    {
        cout << "\n================================" << "\n";
        cout << "\tMENU DE OPCIONES" << "\n";
        cout << "================================" << "\n";
        cout << "1. Asignar Memoria" << "\n";
        cout << "2. Liberar Memoria" << "\n";
        cout << "3. Mostrar Estado de Memoria" << "\n";
        cout << "4. Volver al men� principal" << "\n";
        cout << "================================" << "\n";
        cout << "Seleccione una opci�n: ";
        cin >> op3;
        switch (op3)
        {
        case 1:
            cout << "Usted ha seleccionado la opci�n 1: Asignar Memoria" << "\n";
            asignarMemoria();
            break;
        case 2:
            cout << "Usted ha seleccionado la opci�n 2: Liberar Memoria" << "\n";
            liberarMemoria();
            break;
        case 3:
            cout << "Usted ha seleccionado la opci�n 3: Mostrar Memoria Asignada" << "\n";
            mostrarEstadoMemoria();
            break;
        case 4:
            cout << "Volviendo al men� principal..." << "\n";
            main();
            break;
        default:  
            cout << "Opci�n no v�lida, por favor intente de nuevo." << "\n";
        }
        

    } while (op3 != 4);
    
    return 0;
}

encolarProceso()
{
    cout << "Funci�n para encolar un proceso." << "\n";

}

ejecutarProceso()
{
    cout << "Funci�n para ejecutar un proceso." << "\n";

}

mostrarCola()
{
    cout << "Funci�n para mostrar los procesos en cola." << "\n";

}

int gestionarCPU()
{
    cout << "Funci�n para gestionar CPU." << "\n";
    int op2;

    do
    {
        cout << "\n================================" << "\n";
        cout << "\tMENU DE OPCIONES" << "\n";
        cout << "================================" << "\n";
        cout << "1. Encolar Proceso" << "\n";
        cout << "2. Ejecutar Proceso" << "\n";
        cout << "3. Mostrar Procesos en Cola" << "\n";
        cout << "4. Volver al men� principal" << "\n";
        cout << "================================" << "\n";
        cout << "Seleccione una opci�n: ";
        cin >> op2;
        switch (op2)
        {
        case 1:
            cout << "Usted ha seleccionado la opci�n 1: Encolar Proceso" << "\n";
            encolarProceso();
            break;
        case 2:
            cout << "Usted ha seleccionado la opci�n 2: Ejecutar Proceso" << "\n";
            ejecutarProceso();
            break;
        case 3:
            cout << "Usted ha seleccionado la opci�n 3: Mostrar Procesos en Cola" << "\n";
            mostrarCola();
            break;
        case 4:
            cout << "Volviendo al men� principal..." << "\n";
            main();
            break;
        default:  
            cout << "Opci�n no v�lida, por favor intente de nuevo." << "\n";
        }
        

    } while (opcion != 4);
    
    return 0;
}

agregarProceso()
{
    cout << "Funci�n para agregar un proceso." << "\n";

}

buscarProceso()
{
    cout << "Funci�n para buscar un proceso." << "\n";

}

eliminarProceso()
{
    cout << "Funci�n para eliminar un proceso." << "\n";

}

modificarPrioridad()
{
    cout << "Funci�n para modificar la prioridad de un proceso." << "\n";

}

mostrarTodos()
{
    cout << "Funci�n para mostrar todos los procesos." << "\n";

}

int gestionarProcesos()
{
    cout << "Funci�n para gestionar procesos." << "\n";

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
        cout << "6. Volver al men� principal" << "\n";
        cout << "================================" << "\n";

        cout << "Seleccione una opci�n: ";
        cin >> op1;

        switch(op1) {
            case 1:
                cout << "Usted ha seleccionado la opci�n 1: Crear Proceso" << "\n";
                agregarProceso();
                break;
            case 2:
                cout << "Usted ha seleccionado la opci�n 2: Listar Procesos" << "\n";
                buscarProceso();
                break;
            case 3:
                cout << "Usted ha seleccionado la opci�n 3: Eliminar Proceso" << "\n";
                eliminarProceso();
                break;
            case 4:
                cout << "Usted ha seleccionado la opci�n 4: Modificar Prioridad" << "\n";
                modificarPrioridad();
                break;

            case 5:
                cout << "Usted ha seleccionado la opci�n 5: Mostrar Procesos" << "\n";
                mostrarTodos();
                break;
            case 6:
                cout << "Volviendo al men� principal..." << "\n";
                main();
                break;
            default:
                cout << "Opci�n no v�lida, por favor intente de nuevo." << "\n";
        }
    }while (opcion != 6);

    return 0;
}

int main() {
    int opcion;

    do 
    {
        // Mostramos el men� para que el usuario elija una acci�n
        cout << "\n================================" << "\n";
        cout << "\tSea Bienvenido" << "\n";
        cout << "================================" << "\n";
        cout << "Sistema de Gesti�n de Datos" << "\n"; 
        cout << "\n================================" << "\n";
        cout << "\tMENU DE OPCIONES" << "\n";
        cout << "================================" << "\n";
        cout << "1. Gestionar Procesos" << "\n";
        cout << "2. Gestionar CPU" << "\n";
        cout << "3. Gestionar Memoria" << "\n";
        cout << "4. Salir" << "\n";
        cout << "================================" << "\n";

        cout << "Seleccione una opci�n: ";
        cin >> opcion;

        // Ejecutamos la opci�n seleccionada
        switch(opcion) {
            case 1:
                cout << "Usted ha seleccionado la opci�n 1: Gestionar Procesos" << "\n";
                gestionarProcesos();
                break;
            case 2:
                cout << "Usted ha seleccionado la opci�n 2: Gestionar CPU" << "\n";
                gestionarCPU();
                break;
            case 3:
                cout << "Usted ha seleccionado la opci�n 3: Gestionar Memoria" << "\n";
                gestionarMemoria();
                break;
            case 4:
                cout << "Usted ha seleccionado la opci�n 4: Salir" << "\n";
                cout << "Saliendo del sistema..." << "\n";
                break;
            default:
                cout << "Opci�n no v�lida, por favor intente de nuevo." << "\n";
        }

    } while (opcion != 4);  

    return 0;
}
