#include "solicitudAlquiler.h"
#include <iostream>

SolicitudAlquiler::SolicitudAlquiler()
    : idSolicitud(0), cliente(nullptr), vehiculo(nullptr),
      fechaInicio(""), fechaFin(""), estado("pendiente") {}

SolicitudAlquiler::SolicitudAlquiler(int id, Cliente* cliente, Vehiculo* vehiculo,
                                     const string& inicio, const string& fin)
    : idSolicitud(id), cliente(cliente), vehiculo(vehiculo),
      fechaInicio(inicio), fechaFin(fin), estado("pendiente") {}

SolicitudAlquiler::~SolicitudAlquiler() {}

int SolicitudAlquiler::getIdSolicitud() const { return idSolicitud; }
Cliente* SolicitudAlquiler::getCliente() const { return cliente; }
Vehiculo* SolicitudAlquiler::getVehiculo() const { return vehiculo; }
string SolicitudAlquiler::getFechaInicio() const { return fechaInicio; }
string SolicitudAlquiler::getFechaFin() const { return fechaFin; }
string SolicitudAlquiler::getEstado() const { return estado; }

void SolicitudAlquiler::setEstado(const string& nuevoEstado) {
    estado = nuevoEstado;
}

void SolicitudAlquiler::mostrarInfo() const {
    cout << "\n--- Solicitud de Alquiler ---" << endl;
    cout << "ID Solicitud: " << idSolicitud << endl;
    cout << "Cliente: " << cliente->getNombre() << " (" << cliente->tipoCliente() << ")" << endl;
    cout << "Vehículo: " << vehiculo->getPlaca() << " - Tipo: " << vehiculo->getTipo() << endl;
    cout << "Fecha inicio: " << fechaInicio << " | Fecha fin: " << fechaFin << endl;
    cout << "Estado: " << estado << endl;
}
