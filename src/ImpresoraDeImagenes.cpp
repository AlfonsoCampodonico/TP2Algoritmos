//
// Created by alfon on 2/6/2021.
//

#include "ImpresoraDeImagenes.h"
#include <iostream>
using namespace std;

ImpresoraDeImagenes::ImpresoraDeImagenes(){
    this->tamanodeUnaCelula = 30;
    this->tamanoPunto = 30;
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
    for(unsigned int columna = 0; columna < unTablero->contarColumnas();columna++){
        for(unsigned int fila = 0; fila < unTablero->contarFilas();fila++){

            unsigned int desdeX = ((columna)*this->tamanodeUnaCelula);
            unsigned int desdeY = ((fila)*this->tamanodeUnaCelula);
            Colores* colorDeUnaCelula;
            colorDeUnaCelula = unTablero->obtenerPosicionCelula(columna+1, fila+1)->obtenerColor();
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
        for(unsigned int y = ((this->tamanodeUnaCelula)-1); y < (alto); y+= this->tamanodeUnaCelula){
            unaImagen->asignar(x, y, colorDeLineas);
        }
    }
}

void ImpresoraDeImagenes::dibujarLineasVerticales(Bits *unaImagen, unsigned int ancho, unsigned int alto,
                                                  Colores *colorDeLineas)  {
    for(unsigned int x = ((this->tamanodeUnaCelula)-1); x < (ancho); x+= this->tamanodeUnaCelula){
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
    dibujarCuadricula(imagen,ancho,alto);
    dibujarContenidoMapa(unSeguimiento, imagen);
    imagen->escribir(nombre);
    delete imagen;
}


void ImpresoraDeImagenes::dibujarContenidoMapa(Seguimiento* unSeguimiento, Bits* imagen){

    Lista<GenSeguimiento*>* listaGenPorTurno =  unSeguimiento->devolverListaAcumulado();
    unsigned int posicionX = 1, ejeX = listaGenPorTurno->contarElementos()
                              , ejeY = unSeguimiento->devolverMayorAcumulado();
    Colores *** espacio = new Colores**[ejeX]();
    cout << "eje x tamanio: "<< ejeX<<endl;
    cout << "eje y tamanio: "<< ejeY << endl;
    for(unsigned int i = 0; i < ejeX; i++){
        espacio[i] = new Colores*[ejeY]();
    }
    for(unsigned int x = 0; x < ejeX; x++){

        for(unsigned int j = 0; j<ejeY; j++){

            espacio[x][j] = new Colores(0,0,0);
        }

    }
    recorrerListaGenesSeguimiento(listaGenPorTurno, posicionX, espacio);
    dibujarCartesiano(unSeguimiento, imagen, espacio,ejeX,ejeY);
    borrarTablero(unSeguimiento, espacio,ejeX,ejeY);
}

void ImpresoraDeImagenes::recorrerListaGenesSeguimiento(Lista<GenSeguimiento *> *listaGenPorTurno, unsigned int posicionX,
                                                   Colores ***espacio)  {
	listaGenPorTurno->iniciarCursor();
    while (listaGenPorTurno->avanzarCursor()){
        GenSeguimiento* genporTurno = listaGenPorTurno->obtenerCursor();
        unsigned int posicionY = genporTurno->devolverCargaAcumuladaTurno();
        if (posicionY != 0){
        	posicionY --;
        }
        Colores* color = espacio[posicionX-1][posicionY];
        color->asignarAzul(200);
        posicionX++;
    }
}

void ImpresoraDeImagenes::dibujarCartesiano(Seguimiento *unSeguimiento, Bits *imagen, Colores ** *espacio,unsigned int ejeX,unsigned int ejeY) {
    for(unsigned int columna = 1; columna < ejeX; columna++){
        for(unsigned int fila = 1; fila < ejeY;fila++){
            unsigned int desdeX = ((columna-1) * tamanoPunto);
            unsigned int desdeY = ((fila-1) * tamanoPunto);
            Colores* colorDeUnaCelula;
            colorDeUnaCelula = espacio[columna-1][fila-1];
            dibujarUnPuntoMapa(colorDeUnaCelula, imagen, desdeX, desdeY);
        }
    }
}

void ImpresoraDeImagenes::dibujarFondo(Bits* unaImagen, unsigned int ancho, unsigned int alto){

    Colores* colorDeFondo = new Colores(0, 0, 0);
        for(unsigned int x = 1; x <= ancho; x++){
            for(unsigned int y = 1; y <= alto; y++){
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

void ImpresoraDeImagenes::borrarTablero(Seguimiento *unSeguimiento, Colores ***espacio,unsigned int ejeX,unsigned int ejeY)  {
		for (int i = 0 ; i < ejeX; i++){
            for (int j = 0 ; j < ejeY; j++){
                delete espacio[i][j];
            }
        }
        for (int x = 0 ; x < ejeX; x++){
        	delete[] espacio[x];
        }
        delete[] espacio;
    }
