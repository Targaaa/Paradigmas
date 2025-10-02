
#include "Vector.h"
#include <iostream>
using namespace std;

int main() {
    Vector v1, v2;

    cout << "=== Crear vectores ===" << endl;
    v1.crearVector(5);
    v2.crearVector(5);

    cout << "Capacidad v1: " << v1.capacidad() << endl;
    cout << "Capacidad v2: " << v2.capacidad() << endl;

    cout << "\n=== Insertar elementos en v1 ===" << endl;
    v1.insertar(0, 10);
    v1.insertar(1, 20);
    v1.insertar(2, 30);

    for (int i = 1; i <= v1.capacidad(); i++) {
        cout << "v1[" << i << "] = " << v1.elemento(i) << endl;
    }

    cout << "\n=== Redimensionar v1 a 8 ===" << endl;
    v1.redimensionar(8);
    cout << "Nueva capacidad: " << v1.capacidad() << endl;
    for (int i = 1; i <= v1.capacidad(); i++) {
        cout << "v1[" << i << "] = " << v1.elemento(i) << endl;
    }

    cout << "\n=== Borrar posición 2 en v1 ===" << endl;
    v1.borrar(2);
    for (int i = 1; i <= v1.capacidad(); i++) {
        cout << "v1[" << i << "] = " << v1.elemento(i) << endl;
    }

    cout << "\n=== Comparar v1 y v2 ===" << endl;
    if (v1 == v2) {
        cout << "v1 y v2 son iguales." << endl;
    } else {
        cout << "v1 y v2 son distintos." << endl;
    }

    cout << "\n=== Destruir v1 ===" << endl;
    v1.destruir();
    cout << "Capacidad v1: " << v1.capacidad() << endl;

    return 0;
}
