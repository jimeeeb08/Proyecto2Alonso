#ifndef SUCURSAL_H
#define SUCURSAL_H

#include <string>
#include "plantel.h"

using namespace std;


class Sucursal {
private:
    string nombre;
    string ubicacion;
    Plantel* plantel; // Cada sucursal cuenta con un plantel

public:
    Sucursal(const string& nombre, const string& ubicacion);
    string getNombre() const;
    string getUbicacion() const;

    void mostrarPlantel() const;
};

#endif
