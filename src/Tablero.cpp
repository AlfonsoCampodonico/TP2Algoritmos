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


void  Tablero::determinarVida(Informes* informes,Tablero* otroTablero) {
    Celula*** tableroAnterior = otroTablero->obtenerEspacio();
    bool estaEnElTablero{};
    int filas = this->contarFilas();
    int columnas = this->contarColumnas();
    for (int a = 0; a < columnas; a++){

        for (int b = 0; b < filas; b++){

            int estaVivo = 0;
            for (int c = -1; c <= 1; c++){

                for (int d = -1; d <= 1; d++){

                    /*Si uno de los dos pivotes (c y d) es diferente de 0,
                     * y la suma de la posicion del array
                    *para a y para b es mayor o igual que cero*/
                    estaEnElTablero = ((columnas > a + c)
                                        && (a + c >= 0)
                                        && (filas > b+d)
                                        && (b+d >= 0)
                                        );

                    if ((c != 0 || d != 0)
                        && estaEnElTablero
                        &&(tableroAnterior[a+c][b+d]->estaViva())){
                        estaVivo++;
                    }
                }
            }
            if ((estaVivo < 2) && (this->espacio[a][b]->estaViva())){

                informes->sumarMuerte();
                this->espacio[a][b]->matarCelula();
                informes->sumarMuertesTotales();


            }
            else if (estaVivo == 3 && (this->espacio[a][b]->estaMuerta())){
                this->espacio[a][b]->revivirCelula();
                informes->sumarNacimiento();
                informes->sumarNacimientosTotales();
                //Todo Transferencia

            }
            else if (estaVivo > 3 && (this->espacio[a][b]->estaViva())){
                this->espacio[a][b]->matarCelula();
                informes->sumarMuertesTotales();


            }
        }
    }
}

Celula*** Tablero::clonarCelulas(Celula*** espacio){
    Celula*** nuevoEspacio = new Celula**[cantidadDeColumnas];
    for(unsigned int i = 0; i<cantidadDeColumnas; i++){
        nuevoEspacio[i] = new Celula*[cantidadDeFilas];
    }
    for(unsigned int x = 0; x < cantidadDeColumnas; x++){
        for(unsigned int j = 0; j<cantidadDeFilas; j++){
            *nuevoEspacio[x][j] = *espacio[x][j];
        }
    }
    return nuevoEspacio;
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
    delete[] this->espacio;
}

