//
// Created by alfon on 2/6/2021.
//

#ifndef TP2ALGORITMOS_IMPRESORADEIMAGENES_H
#define TP2ALGORITMOS_IMPRESORADEIMAGENES_H
#include "Lista.h"
#include "Tablero.h"
#include "Bits.h"

/*
 * Se encarga de generar un archivo .BMP que representa un tablero con los elementos
 * que lo componen durante una partida del Juego de la Vida.
 */
class ImpresoraDeImagenes {

private:
    unsigned int tamanodeUnaCelula;

public:
    /* PRE: -.
     * POST: crea una Impresora de imagenes, la cual se encarga de generar archivos
     * que representen al tablero
     */
    ImpresoraDeImagenes();


    /* Pre: unTablero es un tablero inicializado y numeroDeTurno >0;
     * Post: Crea una imagen de unTablero y la guarda como formato .BMP.
     */
    void dibujarUnTablero(Tablero* unTablero, unsigned int numeroDeTurno);

private:

    /* Pre: unTablero es un tablero inicializado;
     * Post: Dibuja dentro de imagen todos los elementos que conforman el tablero.
     */
    void dibujarContenidoDelTablero(Tablero* unTablero, Bits* imagen);

    /* Pre: unaImagen es un mapa de bits inicializado, ancho>0, alto>0.
     * Post: dibuja en unaImagen una cuadricula.
     */
    void dibujarCuadricula(Bits* unaImagen, unsigned int ancho, unsigned int alto);

    /* Pre: pixelX y pixelY representan un pixel de imagen.
     * POST: dibuja la parcela ubicada en (pixelX, pixelY).
     */
    void dibujarUnaCelula(Colores* colorDeCelula, Bits* imagen, unsigned int pixelX, unsigned int pixelY);

    /* pre: desdeX>=0, hastaX>=0,  desdeY>=0, hastaY>=0.
 * post: Dibuja una seccion rectangular en la imagen determinada.
 */
    void dibujarEnAnchoYalto(Colores* unColor, Bits* imagen, unsigned int desdeX,
                             unsigned int hastaX, unsigned int desdeY, unsigned int hastaY);
};
#endif //TP2ALGORITMOS_IMPRESORADEIMAGENES_H
