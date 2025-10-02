#include "Vector.h"
#include <iostream>
using namespace std;

bool Vector::reservarMemoria(int n){
    elementos = new item[n];
    if(elementos == NULL){
        cout<<"Error no se pudo reservar memoria";
        return false;
    }else{
        for(unsigned int i=0;i<n;i++)
			this->elementos[i] = 9999;
        return true;
        }
}

bool Vector::redimensionar(int n){
    if(n > max){
        item *nuevo = new item[n];
        if(nuevo != NULL){
            for (int i = 0; i < max; i++)
            {
                nuevo[i] = elementos[i];
            }
            for (int i = max; i < n; i++)
            {
                nuevo[i] = 9999;
            }
            max = n;
            delete[] elementos;
            elementos = nuevo;
            return true;
        }
    }
    return false;
}

Vector::Vector(int n){
    if(!reservarMemoria(n))
	    max=0;
	else
		max = n;
}

Vector::Vector(Vector &v){
    if(!reservarMemoria(v.max)){
		max=0;
		cout<<"ERROR - NO SE PUDO REALIZAR CORRECTAMENTE LA COPIA"<<endl;
    }
	else{
        max = v.max;
        for(unsigned int i=0;i<this->max;i++)
			this->elementos[i] = v.elementos[i];
    }
}


bool Vector::insertar(int p, item x){
    if(p <= max || redimensionar(p)){
        elementos[p-1] = x;
        return true;
    }                                    //esta bien?
    return false;
}

int Vector::capacidad(){
    return max;
}

item& Vector::elemento(int x){
    if(0 < x && x <= max){
        return elementos[x-1]; //pues empieza en 0
    }
    else
		return elementos[0];
}

bool Vector::borrar(int p){
    if(0 < p && p <= max){
        elementos[p-1] = 9999;
        return true;
    }
    return false;
}

void Vector::borrar(){
    for (int i = 0; i < max; i++)
    {
        elementos[i] = 9999;
    }
}

Vector::~Vector(){
    delete[] elementos;
    max = 0;
}

bool Vector::operator==(Vector &V){ 
    if(max != V.max){
        return false;
    }else{
        int i = 0;
        while (i < max)
        {
            if(elementos[i] != V.elementos[i])
                return false;
            i++;
        }
    }
    return true;
}