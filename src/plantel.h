#ifndef PLANTEL_H
#define PLANTEL_H

#include "espacio.h"
#include "vehiculo.h"
#include <iostream>
#include <string>

using namespace std;

// Plantel representa una matriz de espacios 
class Plantel {
private:
    int filas;
    int columnas;
    Espacio** matriz; // matriz dinámica de punteros a Espacio

public:
    Plantel(int filas, int columnas, Espacio** matriz);
    ~Plantel();

    void mostrarMatriz() const;

    // funciones para gestionar espacios
    Espacio* obtenerEspacio(const string& codigo);  // buscar espacio por código
    void ocuparEspacio(const string& codigo, Vehiculo* vehiculo); // marcar espacio como ocupado con un vehiculo
    void liberarEspacio(const string& codigo); // liberar espacio
    void mostrarEstadoGeneral() const; // resumen de ocupación
    Vehiculo* buscarVehiculo(const string& placa) const;
};

#endif
