//
// Created by alfon on 12/2/2020.
//

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

Celula*** Tablero::obtenerEspacio(){
	return (this->espacio);
}


void Tablero::actualizarUnTablero(Informes* elInforme){
    for(unsigned int columna = 1; columna < this->contarColumnas() + 1; columna++){

        for(unsigned int fila = 1; fila < this->contarFilas() + 1; fila++){

            Celula* unaCelula = this->obtenerPosicionCelula(columna,fila);
            if(unaCelula->estaCasiViva()){
                unaCelula->revivirCelula();
                elInforme->sumarNacimiento();
            }
            else if(unaCelula->estaCasiMuerta()){
                unaCelula->matarCelula();
                elInforme->sumarMuerte();
            }
        }
    }
}
void Tablero::dictarVida(Informes* elInforme){

    for(unsigned int columna = 1; columna <= this->contarColumnas(); columna++){
        for(unsigned int fila = 1; fila <= this->contarFilas(); fila++){
            Celula* unaCelula = this->obtenerPosicionCelula(columna,fila);
            Lista<Gen*>* listaDeGenes = new Lista<Gen*>();
            unsigned int vecinasVivas = this->determinarCuantasVecinasVivas(columna, fila,listaDeGenes);

            if(unaCelula->estaViva() && vecinasVivas != 3 && vecinasVivas != 2){
                unaCelula->vaAMorir();
            }
            else if(unaCelula->estaMuerta() && vecinasVivas==3) {
                    unaCelula->vaAVivir();
                    unaCelula->obtenerListaGen()->agregar(*listaDeGenes);
                    unaCelula->completarTransferencia();
                    unaCelula->calcularIntensidad(elInforme);
                    unaCelula->mutar();

                }
            delete listaDeGenes;

        }
    }
}

unsigned  int Tablero::determinarCuantasVecinasVivas(unsigned int columna, unsigned int fila,Lista<Gen*>* listaDeGenes){

    unsigned int vecinasVivas{}, primeraFilaAAnalizar = fila - 1, ultimaFilaAAnalizar = fila + 1 ;

    for(unsigned int i = primeraFilaAAnalizar; i <= ultimaFilaAAnalizar; i++){

        unsigned int primeraColumnaAAnalizar = columna - 1, ultimaColumnaAAnalizar = columna + 1;

        for(unsigned int j = primeraColumnaAAnalizar; j <= ultimaColumnaAAnalizar; j++){

            bool esLaMismaCelula = ((fila != i) || (columna != j));

            if((existeEnElTablero(j, i))&&(esLaMismaCelula)){

                Celula* unaCelula = this->obtenerPosicionCelula(j,i);

                if(unaCelula->estaViva()||unaCelula->estaCasiMuerta()){
                    vecinasVivas++;
                    Lista<Gen*>* lista = unaCelula->obtenerListaGen();
                    listaDeGenes->agregar(*lista);
                }
            }
        }
    }
    return vecinasVivas;
}

bool Tablero::existeEnElTablero(unsigned int columna, unsigned int fila){
    bool esValidaLaFila = fila>0 && fila <= this->cantidadDeFilas;
    bool esValidaLaColumna = columna > 0 && columna <= this->cantidadDeColumnas;
    return esValidaLaFila && esValidaLaColumna;
}

Tablero::~Tablero() {
	for (int i = 0 ; i < contarFilas() ; i++){
		for (int j = 0 ; i < contarColumnas() ; j++){
			delete this-> espacio[i][j];
		}
	}
	for (int i = 0 ; i < contarColumnas() ; i++){
		delete[] this->espacio[i];
	}
    delete[] this->espacio;
}

