#ifndef SOLICITUDALQUILER_H
#define SOLICITUDALQUILER_H

#include <string>
#include <iostream>
#include "cliente.h"
#include "vehiculo.h"

using namespace std;

class SolicitudAlquiler {
private:
    int idSolicitud;
    Cliente* cliente;          // puntero polimórfico (puede ser PersonaFisica o PersonaJuridica)
    Vehiculo* vehiculo;        // vehículo solicitado
    string fechaInicio;
    string fechaFin;
    string estado;             // "pendiente", "aprobada", "rechazada"
    bool aprobada = false;

public:
    SolicitudAlquiler();
    SolicitudAlquiler(int id, Cliente* cliente, Vehiculo* vehiculo,
                      const string& inicio, const string& fin, bool aprobada);

    ~SolicitudAlquiler();

    // Getters
    int getIdSolicitud() const;
    Cliente* getCliente() const;
    Vehiculo* getVehiculo() const;
    string getFechaInicio() const;
    string getFechaFin() const;
    string getEstado() const;

    // Setters
    void setEstado(const string& nuevoEstado);

    // Métodos funcionales
    void mostrarInfo() const;
    void aprobar();
    bool estaAprobada();
};

#endif
