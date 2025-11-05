#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include <iostream>
#include "bitacora.h"

using namespace std;

class Vehiculo {
private:
    string placa;
    string tipo;
    Bitacora bitacora; // cada vehículo tiene su propia bitácora

public:
    Vehiculo();
    Vehiculo(const string& placa, const string& tipo);

    string getPlaca() const;
    string getTipo() const;
    void mostrarInfo() const;

    // Métodos para la bitácora
    void registrarEvento(const string& descripcion);
    void mostrarBitacora() const;
    
};

#endif
