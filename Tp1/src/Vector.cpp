//============================================================================
// PARADIGMAS DE PROGRAMACION - 2025
// Vector.cpp
//============================================================================

#include <iostream>
#include "Vector.h"

using namespace std;

// OPERACIONES ADT VECTOR(ITEM)

//Operaciones Auxiliares
bool reservarMemoria(Vector &V, unsigned int n){
	V.elementos = new item[n];
	if(V.elementos == NULL){
		return false;
	}
	else{
		V.max = n;
		for(unsigned int i=0;i<n;i++)
			V.elementos[i] = indef;
		return true;
	}
}

bool redimensionar(Vector &V, unsigned int n){
	if(n > V.max){
		item *nuevo = new item[n];
		if(nuevo != NULL){
			for(unsigned int i=0;i<V.max;i++)
				nuevo[i] = V.elementos[i];
			for(unsigned int i=V.max; i<n;i++)
				nuevo[i] = indef;
			V.max = n;
			delete[] V.elementos;
			V.elementos = nuevo;
			return true;
		}
	}
	return false;
}

//Operaciones propias del ADT VECTOR(ITEM)
Vector crearVector(unsigned int n){
	Vector V;
	if(!reservarMemoria(V, n))
		V.max=0;
	return V;
}

Vector insertar(Vector V, unsigned int p, item x){
	if(0 < p && p <= V.max || redimensionar(V, p)){
		V.elementos[p-1] = x;
	}
	return V;
}

unsigned int capacidad(Vector V){
	return V.max;
}

item& elemento(Vector V, unsigned int p){
	if(0 < p && p <= V.max)
		return V.elementos[p-1];
	else
		return V.elementos[0];
}

Vector borrar(Vector V, unsigned int p){
	if(0 < p && p <= V.max)
		V.elementos[p-1] = indef;
	return V;
}

Vector borrar(Vector V){
	for(unsigned int i=0;i<V.max;i++)
		V.elementos[i] = indef;
	return V;
}

Vector destruir(Vector V){
	delete[] V.elementos;
	V.max = 0;
	return V;
}

//Sobrecarga del operador == como operacion propia del ADT VECTOR(ITEM)
bool operator==(Vector V1, Vector V2){
	unsigned int i=0;
	if(V1.max == V2.max){
		while(i<V1.max && V1.elementos[i] == V2.elementos[i])
			i++;
		return i==V1.max;
	}else
		return false;
}



