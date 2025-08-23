#include "Vector.h"
#include <iostream>

Vector crearVector(int n){
    Vector V;  //creo vector v
    V.elementos = nullptr; //nullptr es el puntero nulo moderno
    reservarMemoria(V, n); //funcion donde mando vector V con los n espacios que necesito
    V.max = n;       //debo asignarle valor a max
    return V;           
}

bool reservarMemoria(Vector &V, unsigned int n){
    V.elementos = new item[n];            //reserva el espacio para n elementos
    for (unsigned int i = 0; i < n; i++)            //setea los elementos a indefinido
    {
        V.elementos[i] = 9999;
    }
    return true;
}

bool redimensionar(Vector &V, unsigned int n){
    item* nuevos = new item[n];    //puntero al inicio de un arreglo de n elementos tipo item

    //unsigned int aux = (n < V.max) ? n : V.max; // es para dimensionar sea mas grande o mas chico
    for (unsigned int i = 0; i < V.max; i++)       //copio los elementos
    {
        nuevos[i] = V.elementos[i];         //asigno 1 a 1
    }
    for (unsigned int i = V.max; i < n;i++)
    {
        nuevos[i] = 9999;
    }
    
    delete[] V.elementos;     //libera memoria del viejo vector
    V.elementos = nuevos;     //V.elementos apunta a la nueva reserva de memoria
    V.max = n;              //nuevo tamaño 
    return true;            //no se borra delete nuevo porque es una variable local de la funcion, al salir de la funcion desaparece
}


Vector insertar(Vector V,unsigned int p, item x){
    if(p > V.max){              //la posicion es mayor que el tamaño del vector?
        redimensionar(V, p+1);       //caso afirmativo redimensiono, sino no es p+1 porque el indice empieza en 0
    } 
    V.elementos[p] = x;
    return V;
}


int capacidad(Vector V){
    return V.max;               //capacidad del vector
}

item& elemento(Vector V,unsigned int x){
    if (x < V.max)
    {
        return V.elementos[x-1];
    }else return V.elementos[0]; //devuelve referencias? 
}

Vector borrar(Vector V){
        for (unsigned int i = 0; i < V.max; i++)
        {
            V.elementos[i] = 9999;
        }
    return V;
}

Vector borrar(Vector V, int p){
    V.elementos[p] = 9999;
    return V;
}

Vector destruir(Vector V){
    delete[] V.elementos;
    V.elementos = nullptr;
    return V;
}

bool operator==(Vector V1, Vector V2){
    if (V1.elementos == nullptr && V2.elementos == nullptr) {
        return true;                                 
    }
    if (V1.elementos == nullptr || V2.elementos == nullptr) {
        return false;                                 
    }
    if (V1.max != V2.max){   
        return false;
    }  
    for (unsigned int i = 0; i < V1.max; i++)    //estan todos los casos?, nulos tambien?
    {
        if (V1.elementos[i] != V2.elementos[i])
        {
            return false;
        }
    }
    return true;
}

