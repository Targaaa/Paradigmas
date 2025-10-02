#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
using namespace std;

typedef int item;

class Vector{
    int max;
    item *elementos;
    //metodos privados falta hacer redimensionar
    item* reservarMemoria(int n);
    
    public:
    bool redimensionar(int n);
    void crearVector(int = 10);
    bool insertar(int p, item x);
    int capacidad();
    item& elemento(int x);
    bool borrar(int p);
    void borrar();
    bool destruir();
    bool operator==(Vector &V);
};











#endif