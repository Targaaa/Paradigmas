#include <iostream>
#include "Cuenta.h"
using namespace std;

void Cuenta::inicializar(int num, long int titular, double monto){
    numero = num;
    dniTitular = titular;
    saldo = monto;
};

bool Cuenta::depositar(double monto){
    saldo += monto;
    return true;
};

bool Cuenta::extraer(double monto){
    if(monto <= saldo){
        saldo -= monto;
        return true;
    }else{
        return false;
    }
}

double Cuenta::getSaldo(){
    return saldo;
}

void Cuenta::mostrarInformacion(){
    cout<<this->numero<<endl;
    cout<<this->dniTitular<<endl;
    cout<<this->saldo<<endl;
}

bool transferir(Cuenta *c1, Cuenta *c2, double monto){
    if(c1->getSaldo() >= monto){
        c1->extraer(monto);
        c2->depositar(monto);
        cout<<"Se pudo tranferir correctamente"<<endl;
        return true;
    }else{
        cout<<"no tiene dinero suficiente en la cuenta"<<endl;
        return false;
    }
}

