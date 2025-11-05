#include <iostream>
#include "empresa.h"

int main() {
    Empresa miEmpresa("Rent A Car CR");

    std::cout << "Sistema Rent a Car iniciado correctamente." << std::endl;
    std::cout << "Nombre de la empresa: " << miEmpresa.getNombre() << std::endl;

    miEmpresa.agregarSucursal("Sucursal Central", "San José");
    miEmpresa.agregarSucursal("Sucursal Alajuela", "Alajuela");     
    miEmpresa.agregarSucursal("Sucursal Heredia", "Heredia");

    cout << "Sucursales de la empresa:" << std::endl;
    miEmpresa.mostrarSucursales();

    return 0;
}
