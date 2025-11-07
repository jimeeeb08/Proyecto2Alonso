#ifndef EMPRESA_H
#define EMPRESA_H

#include <string>
#include "sucursal.h"

using namespace std;

class Empresa {
private:
    string nombre;

    // Lista enlazada de sucursales 
    struct NodoSucursal {
        Sucursal* sucursal;
        NodoSucursal* siguiente;
    };
    NodoSucursal* cabezaSucursales;

public:
    Empresa(const string& nombre);
    ~Empresa();

    string getNombre() const;

    void agregarSucursal(const string& nombre, const string& ubicacion);
    void mostrarSucursales() const;

    // --- NUEVOS MÉTODOS ---
    // Devuelve la cantidad de sucursales
    int cantidadSucursales() const;

    // Obtener sucursal por índice (0-based). Retorna nullptr si no existe.
    Sucursal* obtenerSucursalPorIndice(int indice) const;

    // Buscar sucursal por nombre. Retorna nullptr si no existe.
    Sucursal* obtenerSucursalPorNombre(const string& nombreBuscado) const;

    // Mostrar información general de la empresa (nombre y cantidad de sucursales)
    void mostrarInformacion() const;
};

#endif
