//
// Created by alfon on 12/2/2020.
//

#include "Tablero.h"
#include "Tablero.h"
using namespace std;

Tablero::Tablero( unsigned int cantidadDeColumnas, unsigned int cantidadDeFilas){


    this->cantidadDeFilas = cantidadDeFilas;
    this->cantidadDeColumnas = cantidadDeColumnas;
    this-> tablero = new int [cantidadDeFilas][cantidadDeColumnas];
    for (int x = 0 ; x < (contarFilas()) ; x++){
    	for (int y = 0 ; y < (contarColumnas()) ; y++){
    		Celula* celula;
        	celula = new Celula(x,y);
        	this->tablero[x][y] = celula;
        }
    }

}


unsigned int Tablero::contarColumnas(){

    return this->cantidadDeColumnas;
}

unsigned int Tablero::contarFilas(){

    return this->cantidadDeFilas;
}

int Tablero::obtenerTablero(){
	return (this->tablero);
}



Tablero::~Tablero() {


}
