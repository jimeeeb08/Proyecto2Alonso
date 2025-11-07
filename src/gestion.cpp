#include "gestion.h"

Gestion::Gestion() {
    listaClientes = nullptr;
    listaColaboradores = nullptr;
    listaVehiculos = nullptr;
    listaSolicitudes = nullptr;
}

Gestion::~Gestion() {
    // Liberar memoria de todas las listas
    NodoCliente* c = listaClientes;
    while (c) {
        NodoCliente* temp = c;
        c = c->siguiente;
        delete temp->cliente;
        delete temp;
    }

    NodoColaborador* col = listaColaboradores;
    while (col) {
        NodoColaborador* temp = col;
        col = col->siguiente;
        delete temp->colaborador;
        delete temp;
    }

    NodoVehiculo* v = listaVehiculos;
    while (v) {
        NodoVehiculo* temp = v;
        v = v->siguiente;
        delete temp->vehiculo;
        delete temp;
    }

    NodoSolicitud* s = listaSolicitudes;
    while (s) {
        NodoSolicitud* temp = s;
        s = s->siguiente;
        delete temp->solicitud;
        delete temp;
    }
}

// ---------------- CLIENTES ----------------
void Gestion::registrarCliente(Cliente* cliente) {
    NodoCliente* nuevo = new NodoCliente{cliente, listaClientes};
    listaClientes = nuevo;
    registrarEnBitacora("Cliente registrado: " + cliente->getNombre());
}

void Gestion::listarClientes() const {
    cout << "\n--- Clientes registrados ---\n";
    NodoCliente* actual = listaClientes;
    while (actual) {
        cout << "- " << actual->cliente->getNombre() << endl;
        actual = actual->siguiente;
    }
}

// ---------------- COLABORADORES ----------------
void Gestion::registrarColaborador(Colaborador* colaborador) {
    NodoColaborador* nuevo = new NodoColaborador{colaborador, listaColaboradores};
    listaColaboradores = nuevo;
    registrarEnBitacora("Colaborador registrado: " + colaborador->getNombre());
}

void Gestion::listarColaboradores() const {
    cout << "\n--- Colaboradores registrados ---\n";
    NodoColaborador* actual = listaColaboradores;
    while (actual) {
        cout << "- " << actual->colaborador->getNombre() << endl;
        actual = actual->siguiente;
    }
}

// ---------------- VEHÍCULOS ----------------
void Gestion::registrarVehiculo(Vehiculo* vehiculo) {
    NodoVehiculo* nuevo = new NodoVehiculo{vehiculo, listaVehiculos};
    listaVehiculos = nuevo;
    registrarEnBitacora("Vehículo agregado: " + vehiculo->getTipo());
}

void Gestion::listarVehiculos() const {
    cout << "\n--- Vehículos registrados ---\n";
    NodoVehiculo* actual = listaVehiculos;
    while (actual) {
        cout << "- " << actual->vehiculo->getTipo() << endl;
        actual = actual->siguiente;
    }
}

// ---------------- SOLICITUDES ----------------
void Gestion::registrarSolicitud(SolicitudAlquiler* solicitud) {
    NodoSolicitud* nuevo = new NodoSolicitud{solicitud, listaSolicitudes};
    listaSolicitudes = nuevo;
    registrarEnBitacora("Nueva solicitud #" + to_string(solicitud->getIdSolicitud()));
}

void Gestion::listarSolicitudes() const {
    cout << "\n--- Solicitudes ---\n";
    NodoSolicitud* actual = listaSolicitudes;
    while (actual) {
        cout << "- Solicitud #" << actual->solicitud->getIdSolicitud()
             << " (" << actual->solicitud->getEstado() << ")" << endl;
        actual = actual->siguiente;
    }
}

SolicitudAlquiler* Gestion::buscarSolicitud(int id) {
    NodoSolicitud* actual = listaSolicitudes;
    while (actual) {
        if (actual->solicitud->getIdSolicitud() == id) return actual->solicitud;
        actual = actual->siguiente;
    }
    return nullptr;
}

// ---------------- BITÁCORA ----------------
void Gestion::registrarEnBitacora(const string& evento) {
    bitacora.agregarEvento(evento);
}

void Gestion::mostrarBitacora() const {
    bitacora.mostrarEventos();
}
