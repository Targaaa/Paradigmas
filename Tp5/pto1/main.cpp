#include "Cuenta.h"
#include <iostream>
using namespace std;

int main(){
    Cuenta c1;
    Cuenta c2;

    c1.inicializar(1,20,250);
    c2.inicializar(2,21,251);

    c1.mostrarInformacion();
    c2.mostrarInformacion();

    transferir(&c1,&c2, 100);

    c1.mostrarInformacion();
    c2.mostrarInformacion();

    return 0;
}