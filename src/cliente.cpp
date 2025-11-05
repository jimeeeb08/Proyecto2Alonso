#include "cliente.h"
#include <iostream>

Cliente::Cliente() : id(""), nombre(""), telefono("") {}
Cliente::Cliente(const string& id, const string& nombre, const string& telefono)
    : id(id), nombre(nombre), telefono(telefono) {}

string Cliente::getId() const { return id; }
string Cliente::getNombre() const { return nombre; }
string Cliente::getTelefono() const { return telefono; }

void Cliente::mostrarInfo() const {
    cout << "ID: " << id
         << " | Nombre: " << nombre
         << " | Teléfono: " << telefono << endl;
}
