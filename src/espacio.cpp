#include "espacio.h"

using namespace std;

Espacio::Espacio() {
    // Se inicializa como desocupado y sin código
    ocupado = false;
    codigo = "";
    vehiculo = nullptr;
}

// Constructor que inicializa cada espacio 
Espacio::Espacio(const string& codigo) {
    this->codigo = codigo;
    ocupado = false;
}

bool Espacio::estaOcupado() const {
    return ocupado;
}

void Espacio::ocupar() {
    ocupado = true;
}

void Espacio::liberar() {
    ocupado = false;
    vehiculo = nullptr;
}

string Espacio::getCodigo() const {
    return codigo;
}

// Vehículo
void Espacio::asignarVehiculo(Vehiculo* v) {
    if (!ocupado) {
        vehiculo = v;
        ocupar();
        cout << "Vehículo asignado al espacio " << codigo << endl;
    } else {
    cout << "No se puede asignar vehículo, ya que está ocupado. Espacio " << codigo << " ya está ocupado." << endl;
    }
}

void Espacio::removerVehiculo() {
    if (ocupado && vehiculo != nullptr) {
        cout << "Removiendo vehículo del espacio " << codigo << " " << vehiculo->getPlaca() << endl;
        liberar();
        cout << "Vehículo removido del espacio " << codigo << endl;
    } else {
        cout << "espacio ya está libre, no se ocupa remover ningún vehículo" << codigo << endl;
    }
}

Vehiculo* Espacio::getVehiculo() const {
    return vehiculo;
}


