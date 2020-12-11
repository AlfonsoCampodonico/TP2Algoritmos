//
// Created by alfon on 12/2/2020.
//

#include "Tablero.h"
#include "Tablero.h"
using namespace std;

Tablero::Tablero( unsigned int cantidadDeColumnas, unsigned int cantidadDeFilas){


    this->cantidadDeFilas = cantidadDeFilas;
    this->cantidadDeColumnas = cantidadDeColumnas;
    this->espacio = new Celula**[cantidadDeColumnas];
    for(unsigned int i = 0; i<cantidadDeColumnas; i++){
        this->espacio[i] = new Celula*[cantidadDeFilas];
    }
    for(unsigned int i = 0; i<cantidadDeColumnas; i++){
        for(unsigned int j = 0; j<cantidadDeFilas; j++){
            Celula* celulaNueva = new Celula();
            this->espacio[i][j] = celulaNueva;
        }
    }
        }





unsigned int Tablero::contarColumnas(){

    return this->cantidadDeColumnas;
}

unsigned int Tablero::contarFilas(){

    return this->cantidadDeFilas;
}




Tablero::~Tablero() {


}
