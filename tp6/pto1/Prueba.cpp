#include "Pelicula.h"
#include <iostream>
using namespace std;

int main(){
    //constructor por defecto
    Pelicula p; 
    Pelicula p1(p); //constructor copia de p
    Pelicula p2 ("Cars","Targa",true,15000,N); //constructor por parametros
    Pelicula p3 = p2; //otra implementacion de constructor copia en el main
   // Pelicula p4 = ("Cars","Targa",true,15000,N);  // no entiendo el ejemplo X d = 20 --X :: X(X(20)) 

    p.listarInformacion();
    p1.listarInformacion();
    p2.listarInformacion();
    p3.listarInformacion();
    
    p3.setDirector("Jose");

    p3.listarInformacion(); //se cambio el director pero codigo sigue siendo el mismo al copiarlo, tiene sentido?

    	cout<<"Costo de la Pelicula: $"<<p3.calcularCosto()<<endl;

    p3.~Pelicula();
    
    p3.listarInformacion();
    return 0;
}