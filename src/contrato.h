#ifndef CONTRATO_H
#define CONTRATO_H

#include <string>
#include <iostream>
#include "solicitudAlquiler.h"  
using namespace std;

class Contrato {
private:
    int id;
    SolicitudAlquiler* solicitud;  // Solicitud que genera el contrato 
    float monto;
    string fechaEmision;
    bool activo;

public:
    Contrato(int id, SolicitudAlquiler* solicitud, float monto, const string& fechaEmision);

    void cerrarContrato();
    bool estaActivo() const;

    void mostrarDetalles() const;

    // Getters
    int getId() const { return id; }
    float getMonto() const { return monto; }
    string getFechaEmision() const { return fechaEmision; }
};

#endif
