//
// Created by alfon on 2/6/2021.
//

#ifndef TP2ALGORITMOS_IMPRESORADEIMAGENES_H
#define TP2ALGORITMOS_IMPRESORADEIMAGENES_H
#include "Lista.h"
#include "Tablero.h"
#include "Bits.h"
#include "Seguimiento.h"
#include <string>
#include <sstream>
#include <iostream>

/*
 * Se encarga de generar un archivo .BMP que representa un tablero con los elementos
 * que lo componen durante una partida del Juego de la Vida.
 */
class ImpresoraDeImagenes {

private:
    unsigned int tamanodeUnaCelula;
    unsigned int tamanoPunto;

public:
    /* PRE: -.
     * POST: crea una Impresora de imagenes, la cual se encarga de generar archivos
     * que representen al tablero
     */
    ImpresoraDeImagenes();


    /* Pre: Requiere de un tablero y un numero de turno para dibujar
     * Post: Crea una imagen de unTablero y la guarda como formato .BMP.
     */
    void dibujarUnTablero(Tablero* unTablero, unsigned int numeroDeTurno);

    /* Pre: Requiere de un seguimiento para dibujar el mapa cartesiano
     * Post: Crea una imagen de un mapa cartesiano a partir de unseguimiento y la guarda como formato .BMP.
     */
    void dibujarMapaCartesiano(Seguimiento *unSeguimiento);

private:

    /* Pre: unTablero es un tablero inicializado;
     * Post: Dibuja dentro de imagen todos los elementos que conforman el tablero.
     */
    void dibujarContenidoDelTablero(Tablero* unTablero, Bits* imagen);

    /* Pre: unaImagen es un mapa de bits
     * Post: dibuja una cuadricula en el mapa de bits
     */
    void dibujarCuadricula(Bits* unaImagen, unsigned int ancho, unsigned int alto);

    /* Pre: colorDeCelula es el color de la celula
     * POST: dibuja un cuadrado en el mapa de bits
     */
    void dibujarUnaCelula(Colores* colorDeCelula, Bits* imagen, unsigned int pixelX, unsigned int pixelY);

    /* pre: dibuja en el mapa de bits desde posiciones X e Y
 * post: Dibuja una seccion rectangular en la imagen determinada.
 */
    void dibujarEnAnchoYalto(Colores* unColor, Bits* imagen, unsigned int desdeX,
                             unsigned int hastaX, unsigned int desdeY, unsigned int hastaY);

    /* PRE:unaImagen es un mapa de bits
     * POST: Dibuja las lineas verticales de la cuadricula
     */
    void dibujarLineasVerticales(Bits *unaImagen, unsigned int ancho, unsigned int alto, Colores *colorDeLineas);

    /* PRE:unaImagen es un mapa de bits
     * POST:Dibuja las lineas horizontales de la cuadricula
     */
    void dibujarLineasHorizontales(Bits *unaImagen, unsigned int ancho, unsigned int alto, Colores *colorDeLineas) ;

    /* PRE: unSeguimiento es el seguimiento del gen
     * POST: dibuja el contenido del mapa cartesiano
     */
    void dibujarContenidoMapa(Seguimiento* unSeguimiento, Bits *imagen);


    /* PRE:unaImagen es un mapa de bits
     * POST: Dibuja el fondo del mapa cartesiano
     */
    void dibujarFondo(Bits *unaImagen, unsigned int ancho, unsigned int alto);

    /* PRE: colorMapa es un color para dibujar el punto
     * POST: Dibuja la intensidad acumulada de un gen como un punto en el mapa cartesiano
     */
    void dibujarUnPuntoMapa(Colores *colorMapa, Bits *imagen, unsigned int pixelX, unsigned int pixelY);

    /* PRE:
     * POST: Borra el tablero temporal para el mapa cartesiano
     */
    void borrarTablero(Seguimiento *unSeguimiento, Colores ***espacio,unsigned int ejeX,unsigned int ejeY);

    /* PRE:
     * POST: Dibuja el mapa cartesiano
     */
    void dibujarCartesiano(Seguimiento *unSeguimiento, Bits *imagen, Colores ** *espacio,unsigned int ejeX,unsigned int ejeY);

    /* PRE:
     * POST: Recorre una lista de Gen PorTurno
     */
    void
    recorrerListaGenesSeguimiento(Lista<GenSeguimiento *> *listaGenPorTurno, unsigned int posicionX,
                                  Colores ***espacio);
};
#endif //TP2ALGORITMOS_IMPRESORADEIMAGENES_H
