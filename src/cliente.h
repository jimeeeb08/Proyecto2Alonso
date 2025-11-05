#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <iostream>

using namespace std;

class Cliente {
protected:
    string id;       // cédula o número jurídico
    string nombre;   
    string telefono;

public:
    Cliente();
    Cliente(const string& id, const string& nombre, const string& telefono);
    virtual ~Cliente() {}

    // Métodos getters
    string getId() const;
    string getNombre() const;
    string getTelefono() const;

    // Métodos virtuales (para sobrescribir en las subclases), heredados
    virtual string tipoCliente() const = 0;
    virtual void mostrarInfo() const;
};

#endif
