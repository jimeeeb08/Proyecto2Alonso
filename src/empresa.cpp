#include "empresa.h"
#include <iostream>

using namespace std;

Empresa::Empresa(const string& nombre) {
    this->nombre = nombre;
    cabezaSucursales = nullptr;
}

Empresa::~Empresa() {
    NodoSucursal* actual = cabezaSucursales;
    while (actual != nullptr) {
        NodoSucursal* siguiente = actual->siguiente;
        delete actual->sucursal;
        delete actual;
        actual = siguiente;
    }
}

string Empresa::getNombre() const {
    return nombre;
}

void Empresa::agregarSucursal(const string& nombre, const string& ubicacion) {
    cout << "Agregando sucursal: " << nombre << " en " << ubicacion << endl;
     
    Sucursal* nuevaSucursal = new Sucursal(nombre, ubicacion);
    NodoSucursal* nuevoNodo = new NodoSucursal;
    nuevoNodo->sucursal = nuevaSucursal;
    nuevoNodo->siguiente = nullptr;

    if (cabezaSucursales == nullptr) {
        cabezaSucursales = nuevoNodo;
    } else {
        NodoSucursal* actual = cabezaSucursales;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
    }
}

void Empresa::mostrarSucursales() const {
    NodoSucursal* actual = cabezaSucursales;
    int index = 0;
    if (!actual) {
        cout << "No hay sucursales registradas." << endl;
        return;
    }
    while (actual != nullptr) {
        cout << "[" << index << "] Sucursal: " << actual->sucursal->getNombre()
             << ", Ubicación: " << actual->sucursal->getUbicacion() << endl;
        actual = actual->siguiente;
        index++;
    }
}

// ---------------- NUEVOS MÉTODOS ----------------

int Empresa::cantidadSucursales() const {
    int count = 0;
    NodoSucursal* actual = cabezaSucursales;
    while (actual != nullptr) {
        count++;
        actual = actual->siguiente;
    }
    return count;
}

Sucursal* Empresa::obtenerSucursalPorIndice(int indice) const {
    if (indice < 0) return nullptr;
    int i = 0;
    NodoSucursal* actual = cabezaSucursales;
    while (actual != nullptr) {
        if (i == indice) return actual->sucursal;
        actual = actual->siguiente;
        i++;
    }
    return nullptr;
}

Sucursal* Empresa::obtenerSucursalPorNombre(const string& nombreBuscado) const {
    NodoSucursal* actual = cabezaSucursales;
    while (actual != nullptr) {
        if (actual->sucursal->getNombre() == nombreBuscado) return actual->sucursal;
        actual = actual->siguiente;
    }
    return nullptr;
}

void Empresa::mostrarInformacion() const {
    cout << "\n=== Información de la Empresa ===" << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Cantidad de sucursales: " << cantidadSucursales() << endl;
}
