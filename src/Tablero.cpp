//
// Created by alfon on 12/2/2020.
//
#include "Celula.h"
#include "Tablero.h"
using namespace std;

Tablero::Tablero( unsigned int cantidadDeColumnas, unsigned int cantidadDeFilas){


    this-> cantidadDeFilas = cantidadDeFilas;
    this-> cantidadDeColumnas = cantidadDeColumnas;
    this-> espacio = new Celula**[cantidadDeColumnas];
    for(unsigned int i = 0; i<cantidadDeColumnas; i++){
        this-> espacio[i] = new Celula*[cantidadDeFilas];
    }
    for(unsigned int x = 0; x < cantidadDeColumnas; x++){
        for(unsigned int j = 0; j<cantidadDeFilas; j++){
            Celula* celulaNueva = new Celula();
            this-> espacio[x][j] = celulaNueva;
        }
    }
}

unsigned int Tablero::contarColumnas(){

    return this->cantidadDeColumnas;
}

unsigned int Tablero::contarFilas(){

    return this->cantidadDeFilas;
}

Celula* Tablero::obtenerPosicionCelula(unsigned int numeroDeColumna, unsigned numeroDeFila){
    return this-> espacio[numeroDeColumna-1][numeroDeFila-1];
}

void Tablero::contarVecinasVivas(){
	for (int x = 0 ; x < contarColumnas() ; x++){
	    for (int y = 0 ; y < contarFilas() ; y++){
	    	cantidadDeVecinasVivas(x,y);
	    }
	}
}

void Tablero::analizarCondicion(){
	for (int x = 0 ; x < contarColumnas() ; x++){
		for (int y = 0 ; y < contarFilas() ; y++){
			Celula* celula = (this-> espacio[x][y]);
			celula->analizarCelula();
		}
	}
}

void Tablero::cantidadDeVecinasVivas(int x, int y){
	Celula* celula = (this->espacio[x][y]);

	if ((celula->obtenerCondicion()) == VIVA && (x-1) != -1 && (y-1) != -1){
		celula->vecinasVivas ++;
	      }
	if ((celula->obtenerCondicion())== VIVA && (x+1) != contarFilas() && (y+1) != contarColumnas()){
		celula->vecinasVivas ++;
	    }
	if ((celula->obtenerCondicion())== VIVA && (y+1) != contarColumnas()){
	    celula->vecinasVivas ++;
	    }
	if ((celula->obtenerCondicion())== VIVA && (y-1) != -1){
		celula->vecinasVivas ++;
	}
	if ((celula->obtenerCondicion())== VIVA && (x+1) != contarFilas()){
		celula->vecinasVivas ++;
	      }
	if ((celula->obtenerCondicion())== VIVA && (x-1) != -1){
		celula->vecinasVivas ++;
	        }
	if ((celula->obtenerCondicion())== VIVA && (x-1) != -1 && (y+1) != contarColumnas()){
		celula->vecinasVivas ++;
	        }
	if ((celula->obtenerCondicion())== VIVA && (x+1) != contarFilas() && (y-1) != -1){
		celula->vecinasVivas ++;
	        }
	}



Tablero::~Tablero() {
	for (int i = 0 ; i < contarFilas() ; i++){
		for (int j = 0 ; i < contarColumnas() ; j++){
			delete[] (this-> espacio[i][j]);
		}
	}
	for (int i = 0 ; i < contarColumnas() ; i++){
		delete[] this->espacio[i];
	}
}

