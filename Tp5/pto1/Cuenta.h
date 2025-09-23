#ifndef CUENTA_H
#define CUENTA_H
#include <iostream>
using namespace std;

class Cuenta{

    int numero;
    long int dniTitular;
    double saldo;

    public: 
    void inicializar(int num, long int titular, double monto);
    bool depositar(double monto);
    bool extraer(double monto);
    double getSaldo();
    void mostrarInformacion();
};

bool transferir(Cuenta *c1, Cuenta *c2, double monto);

#endif