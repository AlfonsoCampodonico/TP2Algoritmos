//
// Created by alfon on 2/6/2021.
//

#include "ImpresoraDeImagenes.h"
#include <string>
#include <sstream>

using namespace std;

ImpresoraDeImagenes::ImpresoraDeImagenes(){
    this->tamanodeUnaCelula = 30;
}

void ImpresoraDeImagenes::dibujarUnTablero(Tablero* unTablero, unsigned int numeroDeTurno){
    unsigned int ancho = (unTablero->contarFilas()*this->tamanodeUnaCelula);
    unsigned int alto = (unTablero->contarColumnas()*this->tamanodeUnaCelula);
    Bits* imagen = new Bits(ancho, alto);
    dibujarCuadricula(imagen, ancho, alto);
    dibujarContenidoDelTablero(unTablero, imagen);
    string nombre = "Turno"+static_cast<ostringstream*>(&(ostringstream() << numeroDeTurno))->str();
    imagen->escribir(nombre);
    delete imagen;
}

void ImpresoraDeImagenes::dibujarContenidoDelTablero(Tablero* unTablero, Bits* imagen){
    for(unsigned int columna = 1; columna<=unTablero->contarColumnas();columna++){
        for(unsigned int fila = 1; fila<=unTablero->contarFilas();fila++){

            unsigned int desdeX = ((columna-1)*this->tamanodeUnaCelula);
            unsigned int desdeY = ((fila-1)*this->tamanodeUnaCelula);
            Colores* colorDeUnaCelula;
            colorDeUnaCelula = unTablero->obtenerPosicionCelula(columna, fila)->obtenerColor();
            dibujarUnaCelula(colorDeUnaCelula, imagen, desdeX, desdeY);
        }
    }
}

void ImpresoraDeImagenes::dibujarCuadricula(Bits* unaImagen, unsigned int ancho, unsigned int alto){

    Colores* colorDeLineas = new Colores(0, 0, 0);
    //Dibuja Lineas verticales.
    for(unsigned int x = (this->tamanodeUnaCelula - 1); x < (ancho); x+=this->tamanodeUnaCelula){
        for(unsigned int y = 0; y<alto; y++){
            unaImagen->asignar(x, y, colorDeLineas);
        }
    }
    //Dibuja Lineas Hotizontales.
    for(unsigned int x = 0; x<ancho; x++){
        for(unsigned int y = (this->tamanodeUnaCelula - 1); y < (alto); y+=this->tamanodeUnaCelula){
            unaImagen->asignar(x, y, colorDeLineas);
        }
    }
    delete colorDeLineas;
}

void ImpresoraDeImagenes::dibujarUnaCelula(Colores* colorDeCelula, Bits* imagen, unsigned int pixelX,
                                           unsigned int pixelY){
    unsigned int hastaX = (pixelX+this->tamanodeUnaCelula) - 2;
    unsigned int hastaY = (pixelY+this->tamanodeUnaCelula) - 2;
    dibujarEnAnchoYalto(colorDeCelula, imagen, pixelX, hastaX, pixelY, hastaY);
}



void ImpresoraDeImagenes::dibujarEnAnchoYalto(Colores* unColor, Bits* imagen, unsigned int desdeX,
                                              unsigned int hastaX, unsigned int desdeY, unsigned int hastaY){
    for(unsigned int x = desdeX; x<=hastaX; x++){
        for(unsigned int y = desdeY; y<=hastaY; y++){
            imagen->asignar(x, y, unColor);
        }
    }
}
