#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
#include <iostream>
using namespace std;

class Vehiculo {
private:
    string placa;
    string tipo;

public:
    Vehiculo();
    Vehiculo(const string& placa, const string& tipo);

    string getPlaca() const;
    string getTipo() const;
    void mostrarInfo() const;
};

#endif
