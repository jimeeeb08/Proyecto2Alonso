#include "sucursal.h"

Sucursal::Sucursal(const std::string& nombre, const std::string& ubicacion) {
    this->nombre = nombre;
    this->ubicacion = ubicacion;
}

std::string Sucursal::getNombre() const {
    return nombre;
}

std::string Sucursal::getUbicacion() const {
    return ubicacion;
}
