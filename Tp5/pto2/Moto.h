#ifndef MOTO_H
#define MOTO_H
#include <iostream>
#include "Fecha.h"
using namespace std;

class Moto{
    string patente;
    string marca;
    string titular;
    int cilindrada;
    float precioAlquiler;
    public:
    string obtenerPatente();
    string obtenerTitular();
    int obtenerCilindrada();
    void mostrarInfo();
    int antiguedad();
    float costoAlquiler();
};


#endif