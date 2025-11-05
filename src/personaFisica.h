#ifndef PERSONAFISICA_H
#define PERSONAFISICA_H

#include "cliente.h"
#include <string>
#include <iostream>

using namespace std;

class PersonaFisica : public Cliente {
private:
    string licencia;  // número de licencia de conducir

public:
    PersonaFisica();
    PersonaFisica(const string& id, const string& nombre, const string& telefono, const string& licencia);
    ~PersonaFisica();

    string getLicencia() const;
    void setLicencia(const string& licencia);

    // Implementaciones virtuales 
    string tipoCliente() const override;
    void mostrarInfo() const override;
};

#endif
