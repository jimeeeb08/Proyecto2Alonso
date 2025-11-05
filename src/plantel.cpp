#include "plantel.h"
using namespace std;

Plantel::Plantel(int filas, int columnas) {
    this->filas = filas;
    this->columnas = columnas;

    // Crear matriz dinámica
    matriz = new Espacio*[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new Espacio[columnas];
        for (int j = 0; j < columnas; j++) {
            string codigo = "F" + to_string(i+1) + "C" + to_string(j+1); // generacion de codigo
            matriz[i][j] = Espacio(codigo);
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
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            std::cout << "[" << matriz[i][j].getCodigo() << "]";
        }
        cout << endl;
    }
}
