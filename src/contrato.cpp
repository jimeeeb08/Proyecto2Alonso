#include "contrato.h"

Contrato::Contrato(int id, SolicitudAlquiler* solicitud, float monto, const string& fechaEmision) {
    this->id = id;
    this->solicitud = solicitud;
    this->monto = monto;
    this->fechaEmision = fechaEmision;
    this->activo = true;
}

void Contrato::cerrarContrato() {
    if (activo) {
        activo = false;
        cout << "Contrato #" << id << " cerrado correctamente." << endl;
    } else {
        cout << "El contrato #" << id << " ya estaba cerrado." << endl;
    }
}

bool Contrato::estaActivo() const {
    return activo;
}

void Contrato::mostrarDetalles() const {
    cout << "\n--- Detalles del Contrato ---" << endl;
    cout << "ID Contrato: " << id << endl;
    cout << "Monto: $" << monto << endl;
    cout << "Fecha de emisión: " << fechaEmision << endl;
    cout << "Estado: " << (activo ? "Activo" : "Cerrado") << endl;

    if (solicitud != nullptr) {
        cout << "\nSolicitud asociada:" << endl;
        solicitud->mostrarInfo();
    } else {
        cout << "(Sin solicitud asociada)" << endl;
    }
}
