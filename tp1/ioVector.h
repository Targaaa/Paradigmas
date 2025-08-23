#ifndef IOVECTOR_H
#define IOVECTOR_H

#include <iostream>
#include "Vector.h"
using namespace std;

ostream& operator<<(ostream& salida, Vector V){
    salida << "[";
    for (unsigned int i = 0; i < V.max; i++)
    {
        if (i+1 == V.max)
        {
            salida << V.elementos[i];
        }
        else{
            salida << V.elementos[i] << ",";
        }
    }
    salida << "]";
    return salida;
}

/*istream& operator>>(istream& entrada, Vector &V){
    entrada.getline(V.elementos,V.max);
    return entrada;
}*/

#endif