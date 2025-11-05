#ifndef SUCURSAL_H
#define SUCURSAL_H

#include <string>

class Sucursal {
private:
    std::string nombre;
    std::string ubicacion;

public:
    Sucursal(const std::string& nombre, const std::string& ubicacion);
    std::string getNombre() const;
    std::string getUbicacion() const;
};

#endif
