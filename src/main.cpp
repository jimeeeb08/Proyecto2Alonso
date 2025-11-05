#include <iostream>
#include "empresa.h"

int main() {
    Empresa miEmpresa("Rent A Car CR");

    std::cout << "Sistema Rent a Car iniciado correctamente." << std::endl;
    std::cout << "Nombre de la empresa: " << miEmpresa.getNombre() << std::endl;

    miEmpresa.agregarSucursal("Sucursal Central", "San José");
    miEmpresa.agregarSucursal("Sucursal Alajuela", "Alajuela");     
    miEmpresa.mostrarSucursales();

    cout << "\n Mostrando plantel de primera sucursal" << endl;
    Sucursal suc ("Sucursal Central", "San José");
    suc.mostrarPlantel();

    return 0;
}
