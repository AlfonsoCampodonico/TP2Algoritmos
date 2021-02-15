//
// Created by alfon on 2/14/2021.
//

#ifndef TP2ALGORITMOS_BITS_H
#define TP2ALGORITMOS_BITS_H

#include "EasyBMP.h"
#include "Colores.h"
#include <string>

class Bits {

private:

    BMP* imagen;
    unsigned int alto;
    unsigned int ancho;

public:

    /* PRE:
     * POST: crea una imagen totalmente blanca de ancho x alto pixeles.
     * 		 El origen de coordenadas se encuentra en el extremo superior
     * 		 izquierdo de la imagen.
     */
    Bits(unsigned int ancho, unsigned int alto);

    /* PRE:
     * POST: asigna al pixel ubicado en (pixelX, pixelY) el color indicado.
     */
    void asignar(unsigned int pixelX, unsigned int pixelY, Colores* nuevoColor);

    /* PRE:
     * POST: genera un archivo de imagen con extension .bmp"
    */
    void escribir(std::string nombreDelArchivo);

    /* PRE:
     * POST: libera los recursos utilizados.
     */
    ~Bits();

};

#endif //TP2ALGORITMOS_BITS_H
