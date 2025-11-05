#include "personaFisica.h"
#include <iostream>

PersonaFisica::PersonaFisica() : Cliente(), licencia("") {}

PersonaFisica::PersonaFisica(const string& id, const string& nombre, const string& telefono, const string& licencia)
    : Cliente(id, nombre, telefono), licencia(licencia) {}

PersonaFisica::~PersonaFisica() {}

string PersonaFisica::getLicencia() const { return licencia; }

void PersonaFisica::setLicencia(const string& licencia) {
    this->licencia = licencia;
}

string PersonaFisica::tipoCliente() const {
    return "Persona Física";
}

void PersonaFisica::mostrarInfo() const {
    cout << "[Persona Física]" << endl;
    Cliente::mostrarInfo();
    cout << "Licencia: " << licencia << endl;
}
