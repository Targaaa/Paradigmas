#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
using namespace std;

typedef int item;

class Vector{
    int max;
    item *elementos;

    //metodos privados falta hacer redimensionar
    bool reservarMemoria(int n);
	bool redimensionar(int n);

    public:
    //constructor con parametros por defecto? uno se llama por parametros el de sobrecarga, como es?
    Vector(int = 10);
    //constructor copia para contarPares
    Vector(Vector &v);
    bool insertar(int p, item x);
    int capacidad();
    item& elemento(int x);
    bool borrar(int p);
    void borrar();
    bool operator==(Vector &V);
    
    //bool destruir();
    ~Vector();
};











#endif