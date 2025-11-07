#include <iostream>
#include <string>
#include "empresa.h"      // Incluye definición de Empresa y Sucursal
#include "sucursal.h"
#include "colaborador.h"
#include "cliente.h"
#include "solicitudAlquiler.h"
#include "vehiculo.h"
#include "gestion.h"
#include "plantel.h"

using namespace std;

void menuSucursal(Sucursal* sucursal); // Declaración adelantada

// Menú de sucursales (ver, agregar, entrar)
void menuSucursales(Empresa* empresa) {
    int opcion = 0;

    do {
        cout << "\n===== MENÚ DE SUCURSALES =====" << endl;
        cout << "1. Ver sucursales existentes" << endl;
        cout << "2. Agregar nueva sucursal" << endl;
        cout << "3. Entrar a una sucursal" << endl;
        cout << "4. Volver al menú principal" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: {
                empresa->mostrarSucursales();
                break;
            }
            case 2: {
                string nombre, ubicacion;
                cout << "Ingrese nombre de la sucursal: ";
                getline(cin, nombre);
                cout << "Ingrese ubicación: ";
                getline(cin, ubicacion);
                empresa->agregarSucursal(nombre, ubicacion);
                break;
            }
            case 3: {
                empresa->mostrarSucursales();
                string nombreBuscado;
                cout << "Ingrese el nombre de la sucursal a la que desea entrar: ";
                getline(cin, nombreBuscado); // Se usa para buscar por nombre
                Sucursal* sucursal = empresa->obtenerSucursalPorNombre(nombreBuscado);
                if (sucursal) {
                    menuSucursal(sucursal);
                } else {
                    cout << "Sucursal no encontrada." << endl;
                }
                break;
            }
            case 4:
                cout << "Regresando al menú principal..." << endl;
                break;
            default:
                cout << "Opción no válida, intente de nuevo." << endl;
        }
    } while (opcion != 4);
}

// Menú dentro de una sucursal específica
void menuSucursal(Sucursal* sucursal) {
    int opcion = 0;
    do {
        cout << "\n===== SUCURSAL: " << sucursal->getNombre() << " =====" << endl;
        cout << "1. Ver plantel" << endl;
        cout << "2. Registrar cliente" << endl;
        cout << "3. Registrar solicitud" << endl;
        cout << "4. Ver bitácora o solicitudes" << endl;
        cout << "5. Volver al menú de sucursales" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                sucursal->mostrarPlantel();
                break;
            case 2:
                cout << "Función registrar cliente" << endl;
                sucursal->registrarCliente();
                break;
            case 3:
                cout << "Función registrar solicitud" << endl;
                sucursal->registrarSolicitud();
                break;
            case 4:
                cout << "Función ver bitácora" << endl;
                sucursal->mostrarBitacora();
                break;
            case 5:
                cout << "Regresando al menú de sucursales..." << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
        }
    } while (opcion != 5);
}

// Menú principal
int main() {
    Empresa empresa("RentaFácil");
    int opcion = 0;

    do {
        cout << "\n===== SISTEMA DE ALQUILER DE VEHÍCULOS =====" << endl;
        cout << "1. Menú de sucursales" << endl;
        cout << "2. Información general de la empresa" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                menuSucursales(&empresa);
                break;
            case 2:
                empresa.mostrarInformacion();
                break;
            case 3:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
        }
    } while (opcion != 3);

    return 0;
}
