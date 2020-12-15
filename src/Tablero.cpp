//
// Created by alfon on 12/2/2020.
//
#include "Celula.h"
#include "Informes.h"
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

void Tablero::analizarCelula(Celula* celula,Informes* informes){
	if ((celula->obtenerCondicion() == MUERTA) && (celula->obtenerVecinasVivas() == 3)){
		celula->revivirCelula();
		informes->sumarNacimiento();
	}
	else if((celula->condicion == VIVA )&& (celula->obtenerVecinasVivas() != 2 || celula->obtenerVecinasVivas() != 3) ){
		celula->matarCelula();
		informes->sumarMuerte();
	}
}

Celula* Tablero::obtenerPosicionCelula(unsigned int numeroDeColumna, unsigned numeroDeFila){
    return this-> espacio[numeroDeColumna-1][numeroDeFila-1];
}

Celula*** Tablero::obtenerEspacio(){
	return (this->espacio);
}

void Tablero::contarVecinasVivas(){
	for (int x = 0 ; x < contarColumnas() ; x++){
	    for (int y = 0 ; y < contarFilas() ; y++){
	    	cantidadDeVecinasVivas(x,y);
	    }
	}
}

void Tablero::analizarCondicion(Informes* informes){
	for (int x = 0 ; x < contarColumnas() ; x++){
		for (int y = 0 ; y < contarFilas() ; y++){
			Celula* celula = (obtenerEspacio()[x][y]);
			analizarCelula(celula,informes);

		}
	}
}

void Tablero::cantidadDeVecinasVivas(int x, int y){
	Celula* celula = (this->espacio[x][y]);

	if ((celula->obtenerCondicion()) == VIVA && (x-1) != -1 && (y-1) != -1){
		celula->aumentarVecinasVivas();
	      }
	if ((celula->obtenerCondicion())== VIVA && (x+1) != contarFilas() && (y+1) != contarColumnas()){
        celula->aumentarVecinasVivas();
	    }
	if ((celula->obtenerCondicion())== VIVA && (y+1) != contarColumnas()){
        celula->aumentarVecinasVivas();
	    }
	if ((celula->obtenerCondicion())== VIVA && (y-1) != -1){
        celula->aumentarVecinasVivas();
	}
	if ((celula->obtenerCondicion())== VIVA && (x+1) != contarFilas()){
        celula->aumentarVecinasVivas();
	      }
	if ((celula->obtenerCondicion())== VIVA && (x-1) != -1){
        celula->aumentarVecinasVivas();
	        }
	if ((celula->obtenerCondicion())== VIVA && (x-1) != -1 && (y+1) != contarColumnas()){
        celula->aumentarVecinasVivas();
	        }
	if ((celula->obtenerCondicion())== VIVA && (x+1) != contarFilas() && (y-1) != -1){
        celula->aumentarVecinasVivas();
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

