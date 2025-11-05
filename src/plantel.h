#ifndef PLANTEL_H
#define PLANTEL_H

#include "espacio.h"
#include <iostream>

using namespace std;

// Plantel represneta una matriz de espacios 
class Plantel {
private:
    int filas;
    int columnas;
    Espacio** matriz; // matriz dinámica de punteros a Espacio

public:
    Plantel(int filas, int columnas);
    ~Plantel();

    void mostrarMatriz() const;
};

#endif
