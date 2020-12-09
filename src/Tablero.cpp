//
// Created by alfon on 12/2/2020.
//

#include "Tablero.h"
using namespace std;

Tablero::Tablero( unsigned int cantidadDeColumnas, unsigned int cantidadDeFilas){

    this->cantidadDeFilas = cantidadDeFilas;
    this->cantidadDeColumnas = cantidadDeColumnas;
}


unsigned int Tablero::contarColumnas(){

    return this->cantidadDeColumnas;
}

unsigned int Tablero::contarFilas(){

    return this->cantidadDeFilas;
}


unsigned int Tablero::obtenerCantidadDeVecinasVivas(unsigned int numeroDeColumna, unsigned int numeroDeFila){
}



Tablero::~Tablero() {


}