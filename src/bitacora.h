#ifndef BITACORA_H
#define BITACORA_H

#include <string>
#include <iostream>

using namespace std;

// Nodo para la lista enlazada de los eventos que se van a registrar en la bitacora 
struct NodoEvento {
    string descripcion;
    NodoEvento* siguiente;

    NodoEvento(const string& desc) : descripcion(desc), siguiente(nullptr) {}
};

// Clase Bitacora (lista enlazada simple)
class Bitacora {
private:
    NodoEvento* cabeza;

public:
    Bitacora();
    ~Bitacora();

    void agregarEvento(const string& descripcion);
    void mostrarEventos() const;
};

#endif
