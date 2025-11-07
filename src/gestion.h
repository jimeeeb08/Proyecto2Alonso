#ifndef GESTION_H
#define GESTION_H

#include <iostream>
#include "cliente.h"
#include "personaFisica.h"
#include "personaJuridica.h"
#include "colaborador.h"
#include "vehiculo.h"
#include "solicitudAlquiler.h"
#include "bitacora.h"

using namespace std;

// Clase de gestión principal
class Gestion {
private:
    //  Nodos de las listas enlazadas 
    struct NodoCliente {
        Cliente* cliente;
        NodoCliente* siguiente;
    };
    struct NodoColaborador {
        Colaborador* colaborador;
        NodoColaborador* siguiente;
    };
    struct NodoVehiculo {
        Vehiculo* vehiculo;
        NodoVehiculo* siguiente;
    };
    struct NodoSolicitud {
        SolicitudAlquiler* solicitud;
        NodoSolicitud* siguiente;
    };

    //  Cabeceras de listas 
    NodoCliente* listaClientes;
    NodoColaborador* listaColaboradores;
    NodoVehiculo* listaVehiculos;
    NodoSolicitud* listaSolicitudes;

    Bitacora bitacora;

public:
    Gestion();
    ~Gestion();

    //  CLIENTES 
    void registrarCliente(Cliente* cliente);
    void listarClientes() const;

    //  COLABORADORES 
    void registrarColaborador(Colaborador* colaborador);
    void listarColaboradores() const;

    //  VEHÍCULOS 
    void registrarVehiculo(Vehiculo* vehiculo);
    void listarVehiculos() const;

    //  SOLICITUDES 
    void registrarSolicitud(SolicitudAlquiler* solicitud);
    void listarSolicitudes() const;
    SolicitudAlquiler* buscarSolicitud(int id);

    //  BITÁCORA 
    void registrarEnBitacora(const string& evento);
    void mostrarBitacora() const;
};

#endif
