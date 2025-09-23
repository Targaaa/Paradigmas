#ifndef AUTO_H
#define AUTO_H
#include <iostream>
#include "Fecha.h"
using namespace std;

class Auto{
    string patente;
    string marca;
    int modelo;
    Fecha vencimientoVTV;
    string titular;
    int capacidad;
    float precioAlquiler;
    public:
    string obtenerPatente();
    string obtenerTitular();
    bool VtvVencida();
    void mostrarInfo();
    int antiguedad();
    float costoAlquiler();
};


#endif