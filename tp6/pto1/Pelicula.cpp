#include "Pelicula.h"


//para que es esto?
int Pelicula::autoNumerico = 0;


//constructor por defecto
Pelicula::Pelicula(){
    codigo = 000;
    titulo = "";
    director = "";
    estreno = false;
    precioBase = 0.0;
    tipoPelicula = N;
}

//constructor con parametros
Pelicula::Pelicula(string Titulo, string Director, bool Estreno, float PrecioBase, produccion TipoPelicula){
    codigo = ++(autoNumerico);
    titulo = Titulo;
    director = Director;
    estreno = Estreno;
    precioBase = PrecioBase;
    tipoPelicula = TipoPelicula;
}

//constructor copia, si yo copio un objeto y lo cambio cambia el objeto original del q me copie?
Pelicula::Pelicula(const Pelicula& P){
    codigo = P.codigo;
    titulo = P.titulo;
    director = P.director;
    estreno = P.estreno;
    precioBase = P.precioBase;
    tipoPelicula = P.tipoPelicula;
}

int Pelicula::getAutoNumerico(){
    return autoNumerico;
}

void Pelicula::setDirector(string DirectorNuevo){
    director = DirectorNuevo;
}

void Pelicula::listarInformacion(){
    cout<<"Codigo: "<<codigo<<endl;
    cout<<"Titulo: "<<titulo<<endl;
    cout<<"Director: "<<director<<endl;
    cout<<"Estreno: "<<((estreno) ? "SI" : "NO")<<endl;
    cout<<"Produccion: "<<((tipoPelicula == N) ? "Nacional" : "Internacional")<<endl;
    cout<<"Precio base: "<<precioBase<<"\n"<<endl;
}

float Pelicula::calcularCosto(){
    float costo = precioBase;
    if(tipoPelicula == I){ //porque I y no "I"??, veo el enum pero porque asi? que tipo son? N, I?
        costo =  costo * 1.30;
    }
    else{
        if(estreno == false){
            costo = costo * 0.8;
        }
    }
    return costo;
}

Pelicula::~Pelicula(){
    codigo=0;
	titulo="";
	director="";
	estreno=false;
	precioBase=0.0;
	tipoPelicula=N;
}