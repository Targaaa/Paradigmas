#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

typedef int item;

struct Vector {
    item* elementos;
    unsigned int max;
};

Vector crearVector (int n = 10);
Vector insertar(Vector V,unsigned int p, item x);
int capacidad(Vector V);
item& elemento(Vector V,unsigned int x);
Vector borrar(Vector V, int p);
Vector borrar(Vector V);
Vector destruir(Vector V);
bool operator==(Vector V1, Vector V2);
//operaciones auxiliares
bool reservarMemoria(Vector &V, unsigned int n);
bool redimensionar(Vector &V, unsigned int n);


#endif 