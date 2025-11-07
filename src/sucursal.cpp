#include "sucursal.h"
#include "personaJuridica.h"
#include "personaFisica.h"
#include "vehiculo.h"
#include "solicitudAlquiler.h"
#include "cliente.h"
#include <iostream>

using namespace std;

Sucursal::Sucursal(const string& nombre, const string& ubicacion) {
    this->nombre = nombre;
    this->ubicacion = ubicacion;

    // Inicializar plantel con dimensiones y un espacio predeterminado
    plantel = new Plantel(5, 5, nullptr); // Aquí se puede personalizar la matriz si se desea
}

Sucursal::~Sucursal() {
    if (plantel) {
        delete plantel;
        plantel = nullptr;
    }
}

string Sucursal::getNombre() const {
    return nombre;
}

string Sucursal::getUbicacion() const {
    return ubicacion;
}

void Sucursal::mostrarPlantel() const {
    cout << "Plantel de la sucursal " << nombre << " en " << ubicacion << ":" << endl;
    plantel->mostrarMatriz();
}


void Sucursal::mostrarInformacion() const {
    cout << "\n--- Información de la Sucursal ---" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Ubicación: " << ubicacion << endl;
    if (plantel) {
        plantel->mostrarEstadoGeneral();
    }
}

Plantel* Sucursal::getPlantel() const {
    return plantel;
}

void Sucursal::registrarCliente() {
    if (numClientes >= 20) {
        cout << "No se pueden registrar más clientes." << endl;
        return;
    }

    int tipo;
    cout << "\n--- Registro de Cliente ---\n";
    cout << "1. Cliente físico\n";
    cout << "2. Cliente jurídico\n";
    cout << "Seleccione tipo: ";
    cin >> tipo;
    cin.ignore();

    string nombre, id;
    cout << "Nombre del cliente: ";
    getline(cin, nombre);
    cout << "ID o cédula: ";
    getline(cin, id);
    // Teléfono
    string telefono;
    cout << "Ingrese el número de teléfono: ";
    getline(cin, telefono);

    if (tipo == 1) {
        string licencia;
        cout << "Ingrese el número de licencia: ";
        getline(cin, licencia);
        clientes[numClientes++] = new PersonaFisica(id, nombre, telefono, licencia);
    } 
    else if (tipo == 2) {
        string representante;
        cout << "Ingrese el nombre del representante legal: ";
        getline(cin, representante);
        clientes[numClientes++] = new PersonaJuridica(id, nombre, telefono, representante);
    } 
    else {
        cout << "Tipo inválido." << endl;
        return;
    }

    cout << "Cliente registrado correctamente.\n";
}

void Sucursal::registrarSolicitud() {
    if (numSolicitudes >= 50) {
        cout << "No se pueden registrar más solicitudes." << endl;
        return;
    }

    int idSolicitud;
string idCliente, placaVehiculo;
string fechaInicio, fechaFin;

cout << "Ingrese ID de la solicitud: ";
cin >> idSolicitud;

cout << "Ingrese ID del cliente: ";
cin >> idCliente;

Cliente* cliente = buscarCliente(idCliente);
if (!cliente) {
    cout << "Cliente no encontrado.\n";
    return;
}

cout << "Ingrese placa del vehículo: ";
cin >> placaVehiculo;

Vehiculo* vehiculo = buscarVehiculo(placaVehiculo);
if (!vehiculo) {
    cout << "Vehículo no encontrado.\n";
    return;
}

cout << "Ingrese fecha de inicio (dd/mm/aaaa): ";
cin >> fechaInicio;
cout << "Ingrese fecha de fin (dd/mm/aaaa): ";
cin >> fechaFin;

// Crear y registrar la solicitud
solicitudes[numSolicitudes++] = new SolicitudAlquiler(
    idSolicitud, cliente, vehiculo, fechaInicio, fechaFin, false
);

cout << "Solicitud registrada correctamente.\n";
}

void Sucursal::mostrarBitacora() const {
    cout << "\n--- Bitácora de Solicitudes ---\n";
    for (int i = 0; i < numSolicitudes; i++) {
        solicitudes[i]->mostrarInfo();
        cout << "------------------------\n";
    }
}

Vehiculo* Sucursal::buscarVehiculo(const string& placa) const {
    if (!plantel) return nullptr;
    return plantel->buscarVehiculo(placa);
}


Cliente* Sucursal::buscarCliente(const string& id) const {
    for (int i = 0; i < numClientes; i++) {
        if (clientes[i]->getId() == id) {
            return clientes[i];
        }
    }
    return nullptr; // No se encontró
}
