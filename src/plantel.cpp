#include "plantel.h"
#include "espacio.h"
#include "vehiculo.h"
using namespace std;

Plantel::Plantel(int filas, int columnas, Espacio** matriz) {
    this->filas = filas;
    this->columnas = columnas;

    // Crear matriz dinámica correctamente sobre el atributo de la clase
    this->matriz = new Espacio*[filas];
    for (int i = 0; i < filas; i++) {
        this->matriz[i] = new Espacio[columnas];
        for (int j = 0; j < columnas; j++) {
            string codigo = "F" + to_string(i + 1) + "C" + to_string(j + 1);
            this->matriz[i][j] = Espacio(codigo);
        }
    }
}

Plantel::~Plantel() {
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

void Plantel::mostrarMatriz() const {
    cout << "\n--- Plantel (" << filas << "x" << columnas << ") ---" << endl;
    if (!matriz) {
    cout << "Error: matriz no inicializada.\n";
    return;
}
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j].estaOcupado())
                cout << "[X] ";
            else
                cout << "[ ] ";
        }
        cout << endl;
    }
}

// Buscar espacio por código
Espacio* Plantel::obtenerEspacio(const string& codigo) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j].getCodigo() == codigo) {
                return &matriz[i][j];
            }
        }
    }
    return nullptr; // no encontrado
}


void Plantel::ocuparEspacio(const std::string& codigo, Vehiculo* vehiculo) {
    Espacio* espacio = obtenerEspacio(codigo);
    if (espacio) {
        espacio->asignarVehiculo(vehiculo);                // usa el método correcto
        std::cout << "Espacio " << codigo
                  << " ocupado por vehículo " << vehiculo->getPlaca()
                  << std::endl;
    } else {
        std::cout << "Espacio no encontrado: " << codigo << std::endl;
    }
}


// Liberar espacio
void Plantel::liberarEspacio(const string& codigo) {
    Espacio* espacio = obtenerEspacio(codigo);
    if (espacio) {
        espacio->liberar();
        cout << "Espacio " << codigo << " liberado." << endl;
    } else {
        cout << "Espacio no encontrado: " << codigo << endl;
    }
}

// Mostrar resumen de ocupación
void Plantel::mostrarEstadoGeneral() const {
    int ocupados = 0, libres = 0;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j].estaOcupado())
                ocupados++;
            else
                libres++;
        }
    }

    cout << "\nEstado general del plantel:" << endl;
    cout << "Espacios ocupados: " << ocupados << endl;
    cout << "Espacios libres: " << libres << endl;
}

Vehiculo* Plantel::buscarVehiculo(const string& placa) const {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            Espacio* espacio = &matriz[i][j];
            if (espacio && espacio->estaOcupado()) {
                Vehiculo* v = espacio->getVehiculo();
                if (v && v->getPlaca() == placa) {
                    return v; // Encontrado
                }
            }
        }
    }
    return nullptr; // No encontrado
}


