#include "vehiculo.h"

Vehiculo::Vehiculo() : placa(""), tipo("") {}

Vehiculo::Vehiculo(const string& placa, const string& tipo)
    : placa(placa), tipo(tipo) {}

string Vehiculo::getPlaca() const {
    return placa;
}

string Vehiculo::getTipo() const {
    return tipo;
}

void Vehiculo::mostrarInfo() const {
    cout << "Vehículo [" << tipo << "] - Placa: " << placa << endl;
}
