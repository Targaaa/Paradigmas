//============================================================================
// PARADIGMAS DE PROGRAMACION - 2025
// Vector.h
//============================================================================

#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
using namespace std;

// TIPIFICACION ADT VECTOR(ITEM)
typedef int item;
const item indef = 9999;
struct Vector {
	item *elementos;
	unsigned int max;
};

// OPERACIONES ADT VECTOR(ITEM)

//Operaciones Auxiliares
bool reservarMemoria(Vector &V, unsigned int n);
bool redimensionar(Vector &V, unsigned int n);

//Operaciones propias del ADT VECTOR(ITEM)
Vector crearVector(unsigned int n=10);
Vector insertar(Vector V, unsigned int p, item x);
unsigned int capacidad(Vector V);
item& elemento(Vector V, unsigned int x);
Vector borrar(Vector V, unsigned int p);
Vector borrar(Vector V);
Vector destruir(Vector V);

//Sobrecarga del operador == como operacion propia del ADT VECTOR(ITEM)
bool operator==(Vector V1, Vector V2);

#endif /* VECTOR_H_ */
