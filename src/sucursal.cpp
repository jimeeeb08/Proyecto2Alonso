#include "sucursal.h"
#include <iostream>

Sucursal::Sucursal(const string& nombre, const string& ubicacion) {
    this->nombre = nombre;
    this->ubicacion = ubicacion;

    // Inicializar plantel con dimennsiones predeterminadas por el momento
    plantel = new Plantel(5, 5); // por ejemplo, 5 filas y 5 columnas
}

// AGREAGR DESTRUCTOR PARA LIBERAR MEMORIA LUEGO

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
