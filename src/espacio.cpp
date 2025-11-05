#include "espacio.h"

using namespace std;

Espacio::Espacio() {
    // Se inicializa como desocupado y sin código
    ocupado = false;
    codigo = "";
}

// Constructor que inicializa cada espacio 
Espacio::Espacio(const std::string& codigo) {
    this->codigo = codigo;
    ocupado = false;
}

bool Espacio::estaOcupado() const {
    return ocupado;
}

void Espacio::ocupar() {
    ocupado = true;
}

void Espacio::liberar() {
    ocupado = false;
}

string Espacio::getCodigo() const {
    return codigo;
}
