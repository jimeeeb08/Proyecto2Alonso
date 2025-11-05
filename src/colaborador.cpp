#include "colaborador.h"

Colaborador::Colaborador(int id, const string& nombre, const string& puesto) {
    this->id = id;
    this->nombre = nombre;
    this->puesto = puesto;
}

void Colaborador::aprobarSolicitud(SolicitudAlquiler* solicitud) {
    if (solicitud == nullptr) {
        cout << "No se puede aprobar: solicitud nula." << endl;
        return;
    }

    if (!solicitud->estaAprobada()) {
        solicitud->aprobar();
        cout << "Solicitud #" << solicitud->getIdSolicitud() << " aprobada por " << nombre << endl;
    } else {
        cout << "La solicitud #" << solicitud->getIdSolicitud() << " ya estaba aprobada." << endl;
    }
}

Contrato* Colaborador::generarContrato(SolicitudAlquiler* solicitud, int idContrato, float monto, const string& fechaEmision) {
    if (solicitud == nullptr || !solicitud->estaAprobada()) {
        cout << "No se puede generar contrato: la solicitud no está aprobada." << endl;
        return nullptr;
    }

    Contrato* contrato = new Contrato(idContrato, solicitud, monto, fechaEmision);
    cout << "Contrato #" << idContrato << " generado exitosamente por " << nombre << endl;
    return contrato;
}

void Colaborador::mostrarInfo() const {
    cout << "Colaborador #" << id << ": " << nombre << " (" << puesto << ")" << endl;
}
