#ifndef ESPACIO_H
#define ESPACIO_H

#include <string>

using namespace std;

class Espacio {
private:
    bool ocupado; // Indica si hay un vehículo
    string codigo; // Identificador de espacio (por ejemplo, A1, A2, B1...)

public:
    Espacio();
    Espacio(const std::string& codigo);
    // No se necesita destructor ya que el espacio solo se vacia
    bool estaOcupado() const;
    void ocupar();
    void liberar();
    string getCodigo() const;
};

#endif
