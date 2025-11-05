#ifndef EMPRESA_H
#define EMPRESA_H

#include <string>
#include "sucursal.h"

using namespace std;

class Empresa {
private:
    string nombre;

    // Lista enlazada de sucursales 
    struct NodoSucursal {
        Sucursal* sucursal;
        NodoSucursal* siguiente;
    };
    NodoSucursal* cabezaSucursales;

public:
    Empresa(const string& nombre);
    ~Empresa();

    string getNombre() const;

    void agregarSucursal(const string& nombre, const string& ubicacion);
    void mostrarSucursales() const;
};

#endif
