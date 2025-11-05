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

void Vehiculo::registrarEvento(const string& descripcion) {
    bitacora.agregarEvento(descripcion);
}

void Vehiculo::mostrarBitacora() const {
    cout << "Bitácora del vehículo " << placa << ":" << endl;
    bitacora.mostrarEventos();
}
