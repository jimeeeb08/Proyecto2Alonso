#ifndef SUCURSAL_H
#define SUCURSAL_H

#include <string>
#include "plantel.h"
#include "cliente.h"
#include "solicitudAlquiler.h"

using namespace std;

class Sucursal {
private:
    string nombre;
    string ubicacion;
    Plantel* plantel; // Cada sucursal cuenta con un plantel
    Cliente* clientes[20]; // Cada sucursal puede tener un cliente asociado
    int numClientes = 0;
    SolicitudAlquiler* solicitudes[50]; // Cada sucursal puede tener múltiples solicitudes
    int numSolicitudes = 0;

public:
    Sucursal(const string& nombre, const string& ubicacion);
    ~Sucursal(); // liberará plantel

    string getNombre() const;
    string getUbicacion() const;

    void mostrarPlantel() const;

    // métodos para gestionar clientes y solicitudes (pendiente de implementar)
    void mostrarInformacion() const; // imprime nombre, ubicacion y estado del plantel
    Plantel* getPlantel() const;     // getter para acceder al plantel desde main

    void registrarCliente();         
    void registrarSolicitud();       
    void mostrarBitacora() const; 
    Vehiculo* buscarVehiculo(const string& placa) const;
    Cliente* buscarCliente(const string& id) const;    
};

#endif
