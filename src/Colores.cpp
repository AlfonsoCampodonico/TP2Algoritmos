
#include "Colores.h"
#include "EasyBMP.h"

Colores::Colores(ebmpBYTE rojo, ebmpBYTE verde, ebmpBYTE azul){
    this->colores = new RGBApixel;
    this->colores->Red = rojo;
    this->colores->Green = verde;
    this->colores->Blue = azul;
}

ebmpBYTE Colores::obtenerRojo(){

    return this->colores->Red;
}

ebmpBYTE Colores::obtenerVerde(){

    return this->colores->Green;
}

ebmpBYTE Colores::obtenerAzul(){

    return this->colores->Blue;
}

void Colores::asignarRojo(ebmpBYTE nuevoRojo){

    this->colores->Red = nuevoRojo;
}

void Colores::asignarVerde(ebmpBYTE nuevoVerde){

    this->colores->Green = nuevoVerde;
}

void Colores::asignarAzul(ebmpBYTE nuevoAzul){

    this->colores->Blue = nuevoAzul;
}

RGBApixel Colores::obtenerPixel(){

    return *(this->colores);
}


Colores::~Colores() {
    delete this->colores;
}




