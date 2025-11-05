#include "personaJuridica.h"
#include <iostream>

int main() {
    PersonaJuridica empresa("3-101-456789", "AutoAlquiler S.A.", "2222-3333", "Carlos Mora");

    cout << "Tipo de cliente: " << empresa.tipoCliente() << endl;
    empresa.mostrarInfo();

    return 0;
}
