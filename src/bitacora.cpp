#include "bitacora.h"

Bitacora::Bitacora() {
    cabeza = nullptr;
}

Bitacora::~Bitacora() {
    NodoEvento* actual = cabeza;
    while (actual != nullptr) {
        NodoEvento* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
}

void Bitacora::agregarEvento(const string& descripcion) {
    NodoEvento* nuevo = new NodoEvento(descripcion);

    if (!cabeza) {
        cabeza = nuevo;
    } else {
        NodoEvento* temp = cabeza;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }
}

void Bitacora::mostrarEventos() const {
    if (!cabeza) {
        cout << "  (Sin eventos registrados)" << endl;
        return;
    }

    NodoEvento* temp = cabeza;
    int contador = 1;
    while (temp != nullptr) {
        cout << "  Evento " << contador++ << ": " << temp->descripcion << endl;
        temp = temp->siguiente;
    }
}
