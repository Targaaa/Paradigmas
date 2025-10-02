#ifndef PELICULA_H
#define PELICULA_H
#include <stdio.h>
#include <iostream>
using namespace std;

enum produccion {N,I};

class Pelicula{
    //para que es el autonumerico y porque static, todos tendran el mismo numero?
    static int autoNumerico;
    int codigo;
    string titulo;
    string director;
    bool estreno;
    float precioBase;
    produccion tipoPelicula;

    public:
    //Constructor por defecto 
    Pelicula();
    //Constructor por parametros, porque no va codigo? veo la implemetnacion que hace ++ y usa el autonumerico, como funciona?
    Pelicula(string, string, bool, float, produccion);
    //Constructor copia
    Pelicula(const Pelicula& p);

    //Destructor
    ~Pelicula();
    static int getAutoNumerico();
    void setDirector(string);
    void listarInformacion();
    float calcularCosto();
};


#endif