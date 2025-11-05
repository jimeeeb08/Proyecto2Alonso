#include <iostream>
#include "vehiculo.h"
#include "espacio.h"

using namespace std;
int main() {
    cout << "=== Prueba de integración Vehículo en Espacio ===" << endl;

    // Crear un espacio
    Espacio e1("A1");

    // Crear un vehículo
    Vehiculo v1("ABC123", "Carro");

    // Asignarlo al espacio
    e1.asignarVehiculo(&v1);

    // Mostrar información
    if (e1.estaOcupado()) {
        cout << "Espacio " << e1.getCodigo() << " está ocupado por ";
        e1.getVehiculo()->mostrarInfo();
    }

    // Liberar el espacio
    e1.removerVehiculo();

    return 0;
}



// #include "empresa.h"


// int main() {
//     Empresa miEmpresa("Rent A Car CR");

//     std::cout << "Sistema Rent a Car iniciado correctamente." << std::endl;
//     std::cout << "Nombre de la empresa: " << miEmpresa.getNombre() << std::endl;

//     miEmpresa.agregarSucursal("Sucursal Central", "San José");
//     miEmpresa.agregarSucursal("Sucursal Alajuela", "Alajuela");     
//     miEmpresa.mostrarSucursales();

//     cout << "\n Mostrando plantel de primera sucursal" << endl;
//     Sucursal suc ("Sucursal Central", "San José");
//     suc.mostrarPlantel();

//     return 0;
// }
