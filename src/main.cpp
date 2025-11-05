#include "contrato.h"
#include "personaFisica.h"
#include "vehiculo.h"
#include "solicitudAlquiler.h"
#include <iostream>

int main() {
    Cliente* cliente = new PersonaFisica("123", "Jimena Bejarano", "23333333", "LIC123456");
    Vehiculo* v1 = new Vehiculo("ABC123", "Sedán");

    SolicitudAlquiler* s1 = new SolicitudAlquiler(1, cliente, v1, "2025-11-05", "2025-11-10");
    s1->getEstado();

    Contrato c1(1, s1, 35000.0, "2025-11-04");
    c1.mostrarDetalles();

    c1.cerrarContrato();
    c1.mostrarDetalles();

    delete cliente;
    delete v1;
    delete s1;
    return 0;
}
