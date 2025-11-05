#ifndef COLABORADOR_H
#define COLABORADOR_H

#include <string>
#include <iostream>
#include "solicitudAlquiler.h"
#include "contrato.h"

using namespace std;

class Colaborador {
private:
    int id;
    string nombre;
    string puesto;

public:
    Colaborador(int id, const string& nombre, const string& puesto);

    // Acciones principales
    void aprobarSolicitud(SolicitudAlquiler* solicitud);
    Contrato* generarContrato(SolicitudAlquiler* solicitud, int idContrato, float monto, const string& fechaEmision);

    // Getters
    int getId() const { 
        return id; 
    }
    string getNombre() const { 
        return nombre; 
    }
    string getPuesto() const { 
        return puesto; 
    }

    // Mostrar información
    void mostrarInfo() const;
};

#endif
