#include "Vector.h"
#include <iostream>
using namespace std;

item* Vector::reservarMemoria(int n){
    item *reserva = new item[n];
    if(reserva == NULL){
        cout<<"Error no se pudo reservar memoria";
    } 
    return reserva;
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

void Vector::crearVector(int n){
    max = n > 0 ? n : 10;
    elementos = reservarMemoria(max);
}

bool Vector::insertar(int p, item x){
    if(p+1 < max){
        elementos[p] = x;
        return true;
    }
    return false;
}

int Vector::capacidad(){
    return max;
}

item& Vector::elemento(int x){
    if(0 < x && x <= max){
        return elementos[x-1]; //pues empieza en 0
    }
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

bool Vector::destruir(){
    delete[] elementos;
    max = 0;
    return true;
}

bool Vector::operator==(Vector &V){ 
    if(max != V.max){
        return false;
    }else{
        int i = 0;
        while (i <= max)
        {
            if(elementos[i] != V.elementos[i])
                return false;
            i++;
        }
    }
    return true;
}