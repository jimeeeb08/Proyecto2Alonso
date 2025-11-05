#include "personaJuridica.h"
#include <iostream>

PersonaJuridica::PersonaJuridica() : Cliente(), representanteLegal("") {}

PersonaJuridica::PersonaJuridica(const string& id, const string& nombre, const string& telefono, const string& representante)
    : Cliente(id, nombre, telefono), representanteLegal(representante) {}

PersonaJuridica::~PersonaJuridica() {}

string PersonaJuridica::getRepresentante() const {
    return representanteLegal;
}

void PersonaJuridica::setRepresentante(const string& representante) {
    representanteLegal = representante;
}

string PersonaJuridica::tipoCliente() const {
    return "Persona Jurídica";
}

void PersonaJuridica::mostrarInfo() const {
    cout << "[Persona Jurídica]" << endl;
    Cliente::mostrarInfo();
    cout << "Representante Legal: " << representanteLegal << endl;
}
