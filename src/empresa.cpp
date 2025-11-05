#include "empresa.h"
#include <iostream>

using namespace std;

Empresa::Empresa(const string& nombre) {
    this->nombre = nombre;
    cabezaSucursales = nullptr;
}

Empresa::~Empresa() {
    // Liberar memoria de la lista enlazada de sucursales 
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
    NodoSucursal* nuevoNodo = new NodoSucursal{nuevaSucursal, cabezaSucursales};
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
    while (actual != nullptr) {
        cout << "Sucursal: " << actual->sucursal->getNombre()
             << ", Ubicación: " << actual->sucursal->getUbicacion() << endl;
        actual = actual->siguiente;
    }
}
