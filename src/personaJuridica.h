#ifndef PERSONAJURIDICA_H
#define PERSONAJURIDICA_H

#include "cliente.h"
#include <string>
#include <iostream>

using namespace std;

class PersonaJuridica : public Cliente {
private:
    string representanteLegal;  // nombre del representante de la empresa

public:
    PersonaJuridica();
    PersonaJuridica(const string& id, const string& nombre, const string& telefono, const string& representante);
    ~PersonaJuridica();

    string getRepresentante() const;
    void setRepresentante(const string& representante);

    string tipoCliente() const override;
    void mostrarInfo() const override;
};

#endif
