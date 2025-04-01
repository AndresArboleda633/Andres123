//Dylan Andres Arboleda Ferrin//Dennis Dariana Riascos
#include  // Incluye la biblioteca para entrada/salida estándar
#include   // Incluye la biblioteca para manipulación de cadenas

using namespace std; // Permite usar el espacio de nombres estándar

// Definición de la estructura nodo
struct nodo {
    int id; // ID del producto
    char nombre[30]; // Nombre del producto (máximo 29 caracteres + '\0')
    nodo *sig; // Puntero al siguiente nodo
};

// Inicialización de punteros
nodo cab = NULL, aux, *aux2; // cab es la cabeza de la lista, aux y aux2 son nodos auxiliares


### 2. Función para registrar un producto

cpp
void registrar() {
    aux = (nodo*) malloc(sizeof(nodo)); // Reserva memoria para un nuevo nodo
    cout << "Ingrese ID del prod…
[4:56 p. m., 27/3/2025] Andrés Arboleda🖤: Control de los ID repetidos
[4:10 p. m., 28/3/2025] Andrés Arboleda🖤: https://unipacificoeduco-my.sharepoint.com/:b:/g/personal/glucio_unipacifico_edu_co/EWPxOsGmyRdDs1R_TqhhjMMBsq_hJIXowinVrzsain1KOA
[2:27 p. m., 31/3/2025] Andrés Arboleda🖤: #include <iostream>
#include <cstring>

using namespace std;

struct Cliente {
    int codigo;
    char nombre[30];
    int edad;
    char sexo;
    char razon[50];
    Cliente* siguiente;
};

Cliente* cola = NULL;
Cliente* historial = NULL;
Cliente* temporal = NULL;
Cliente* auxiliar = NULL;

void insertarCliente() {
    temporal = new Cliente();
    
    cout << "Ingrese el código del cliente: ";
    cin >> temporal->codigo;
    cin.ignore();
    cout << "Nombre: ";
    cin.getline(temporal->nombre, 30);
    cout << "Edad: ";
    cin >> temporal->edad;
    cout << "Sexo (M/F): ";
    cin >> temporal->sexo;
    temporal->sexo = toupper(temporal->sexo);
    cin.ignore();
    cout << "Razón de la llamada: ";
    cin.getline(temporal->razon, 50);
    
    temporal->siguiente = NULL;
    
    if (!cola) {
        cola = temporal;
    } else {
        auxiliar = cola;
        while (auxiliar->siguiente) {
            auxiliar = auxiliar->siguiente;
        }
        auxiliar->siguiente = temporal;
    }
    
    cout << "Cliente añadido con éxito!" << endl;
}

void listarClientes() {
    auxiliar = cola;
    if (!auxiliar) {
        cout << "No hay clientes en espera." << endl;
        return;
    }

    cout << "\nClientes en espera:" << endl;
    while (auxiliar) {
        cout << "Código: " << auxiliar->codigo << endl;
        cout << " | Nombre: " << auxiliar->nombre << endl;
        cout << " | Edad: " << auxiliar->edad << endl;
        cout << " | Sexo: " << auxiliar->sexo << endl;
        cout << " | Razón: " << auxiliar->razon << endl;
        auxiliar = auxiliar->siguiente;
    }
}

void contarClientes() {
    int contador = 0;
    auxiliar = cola;
    while (auxiliar) {
        contador++;
        auxiliar = auxiliar->siguiente;
    }
    cout << "Clientes en espera: " << contador << endl;
}

void registrarEnHistorial(Cliente* cliente) {
    cliente->siguiente = historial;
    historial = cliente;
}

void procesarCliente() {
    if (!cola) {
        cout << "No hay clientes para atender." << endl;
        return;
    }

    temporal = cola;
    cola = cola->siguiente;

    if (temporal->edad < 18) {
        cout << "No se puede atender a menores de edad." << endl;
        temporal->siguiente = cola;
        cola = temporal;
        return;
    }

    registrarEnHistorial(temporal);
    
    cout << "Cliente atendido: " << temporal->nombre << endl;
}

void mostrarHistorial() {
    auxiliar = historial;
    if (!auxiliar) {
        cout << "No hay historial de atenciones." << endl;
        return;
    }

    cout << "\nHistorial de atenciones:" << endl;
    while (auxiliar) {
        cout << "Código: " << auxiliar->codigo << " | Nombre: " << auxiliar->nombre
             << " | Edad: " << auxiliar->edad << " | Sexo: " << auxiliar->sexo
             << " | Razón: " << auxiliar->razon << endl;
        auxiliar = auxiliar->siguiente;
    }
}

void revertirAtencion() {
    if (!historial) {
        cout << "No hay atenciones previas para revertir." << endl;
        return;
    }

    temporal = historial;
    historial = historial->siguiente;
    temporal->siguiente = cola;
    cola = temporal;

    cout << "Se ha revertido la última atención." << endl;
}

int main() {
    int opcion;
    do {
        cout << "\nMENU" << endl;
        cout << "1. Añadir cliente a la cola" << endl;
        cout << "2. Ver clientes en espera" << endl;
        cout << "3. Contar clientes en espera" << endl;
        cout << "4. Atender al siguiente cliente" << endl;
        cout << "5. Ver historial de atenciones" << endl;
        cout << "6. Revertir última atención" << endl;
        cout << "7. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1: insertarCliente(); break;
            case 2: listarClientes(); break;
            case 3: contarClientes(); break;
            case 4: procesarCliente(); break;
            case 5: mostrarHistorial(); break;
            case 6: revertirAtencion(); break;
            case 7: cout << "Saliendo del sistema..." << endl; break;
            default: cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while (opcion != 7);
    
    return 0;
}