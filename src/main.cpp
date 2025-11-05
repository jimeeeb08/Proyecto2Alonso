#include "personaFisica.h"
#include <iostream>

int main() {
    PersonaFisica p1("123456789", "Jimena Bejarano", "8888-8888", "L-4567CR");

    cout << "Tipo de cliente: " << p1.tipoCliente() << endl;
    p1.mostrarInfo();

    return 0;
}
