//
// Created by alfon on 2/6/2021.
//

#include "ImpresoraDeImagenes.h"

using namespace std;

ImpresoraDeImagenes::ImpresoraDeImagenes(){
    this->tamanodeUnaCelula = 30;
    this->tamanoPunto = 4;
}

void ImpresoraDeImagenes::dibujarUnTablero(Tablero* unTablero, unsigned int numeroDeTurno){
    unsigned int ancho = (unTablero->contarColumnas()*this->tamanodeUnaCelula);
    unsigned int alto = (unTablero->contarFilas()*this->tamanodeUnaCelula);
    Bits* imagen = new Bits(ancho, alto);
    dibujarCuadricula(imagen, ancho, alto);
    dibujarContenidoDelTablero(unTablero, imagen);
    string nombre = "0000000"+static_cast<ostringstream*>(&(ostringstream() << numeroDeTurno))->str();
    imagen->escribir(nombre);
    delete imagen;
}

void ImpresoraDeImagenes::dibujarContenidoDelTablero(Tablero* unTablero, Bits* imagen){
    for(unsigned int columna = 1; columna < unTablero->contarColumnas();columna++){
        for(unsigned int fila = 1; fila < unTablero->contarFilas();fila++){

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
    dibujarLineasVerticales(unaImagen, ancho, alto, colorDeLineas);
    dibujarLineasHorizontales(unaImagen, ancho, alto, colorDeLineas);

    delete colorDeLineas;
}

void ImpresoraDeImagenes::dibujarLineasHorizontales(Bits *unaImagen, unsigned int ancho, unsigned int alto,
                                                    Colores *colorDeLineas)  {
    for(unsigned int x = 0; x < ancho; x++){
        for(unsigned int y = (tamanodeUnaCelula - 1); y < (alto); y+= tamanodeUnaCelula){
            unaImagen->asignar(x, y, colorDeLineas);
        }
    }
}

void ImpresoraDeImagenes::dibujarLineasVerticales(Bits *unaImagen, unsigned int ancho, unsigned int alto,
                                                  Colores *colorDeLineas)  {
    for(unsigned int x = (tamanodeUnaCelula - 1); x < (ancho); x+= tamanodeUnaCelula){
        for(unsigned int y = 0; y<alto; y++){
            unaImagen->asignar(x, y, colorDeLineas);
        }
    }
}

void ImpresoraDeImagenes::dibujarUnaCelula(Colores* colorDeCelula, Bits* imagen, unsigned int pixelX,
                                           unsigned int pixelY){
    unsigned int hastaX = (pixelX+this->tamanodeUnaCelula)-2;
    unsigned int hastaY = (pixelY+this->tamanodeUnaCelula)-2;
    dibujarEnAnchoYalto(colorDeCelula, imagen, pixelX, hastaX, pixelY, hastaY);
}



void ImpresoraDeImagenes::dibujarEnAnchoYalto(Colores* unColor, Bits* imagen, unsigned int desdeX,
                                              unsigned int hastaX, unsigned int desdeY, unsigned int hastaY){
    for(unsigned int x = desdeX; x <= hastaX; x++){
        for(unsigned int y = desdeY; y <= hastaY; y++){
            imagen->asignar(x, y, unColor);
        }
    }
}

void ImpresoraDeImagenes::dibujarMapaCartesiano(Seguimiento* unSeguimiento){
    unsigned int ancho = (unSeguimiento->devolverListaAcumulado()->contarElementos()*this->tamanoPunto);
    unsigned int alto = (unSeguimiento->devolverMayorAcumulado()*this->tamanoPunto);
    Bits* imagen = new Bits(ancho, alto);
    string nombre = "gen-"+unSeguimiento->devolverCadenaGen()+"-"+
            to_string(unSeguimiento->devolverTurnoInicio())+"-"+
            to_string(unSeguimiento->devolverTurnoFin());
    dibujarFondo(imagen,ancho,alto);
    dibujarContenidoMapa(unSeguimiento, imagen);
    imagen->escribir(nombre);
    delete imagen;
}


void ImpresoraDeImagenes::dibujarContenidoMapa(Seguimiento* unSeguimiento, Bits* imagen){


    Lista<GenSeguimiento*>* listaGenPorTurno =  unSeguimiento->devolverListaAcumulado();
    listaGenPorTurno->iniciarCursor();
    unsigned int posicionX = 0;
    while (listaGenPorTurno->avanzarCursor()){
        GenSeguimiento* genporTurno = listaGenPorTurno->obtenerCursor();
        unsigned int posicionY = genporTurno->devolverTurnoCarga();
        unsigned int desdeX = (posicionX*this->tamanoPunto);
        unsigned int desdeY = (posicionY*this->tamanoPunto);
        Colores* colorMapa = new Colores(0, 0, 255);
        dibujarUnPuntoMapa(colorMapa, imagen, desdeX, desdeY);
        delete colorMapa;
        posicionX++;
    }

}

void ImpresoraDeImagenes::dibujarFondo(Bits* unaImagen, unsigned int ancho, unsigned int alto){

    Colores* colorDeFondo = new Colores(0, 0, 0);
        for(unsigned int x = 0; x <= ancho; x++){
            for(unsigned int y = 0; y <= alto; y++){
                unaImagen->asignar(x, y, colorDeFondo);
            }
        }
    delete colorDeFondo;
}

void ImpresoraDeImagenes::dibujarUnPuntoMapa(Colores* colorMapa, Bits* imagen, unsigned int pixelX,
                                           unsigned int pixelY){
    unsigned int hastaX = (pixelX+this->tamanoPunto)-2;
    unsigned int hastaY = (pixelY+this->tamanoPunto)-2;
    dibujarEnAnchoYalto(colorMapa, imagen, pixelX, hastaX, pixelY, hastaY);
}