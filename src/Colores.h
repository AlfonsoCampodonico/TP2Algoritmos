/*
 * Colores.h
 *
 *  Created on: 8 feb. 2021
 *      Author: usuario
 */


#ifndef COLORES_H_
#define COLORES_H_

#include "EasyBMP.h"

class Colores {

private:

    RGBApixel* colores;

public:

    /* PRE: rojo, verde y azul son enteros entre 0 y 255.
     * Post: genera un color del modelo RGB.
     */
    Colores(ebmpBYTE rojo, ebmpBYTE verde, ebmpBYTE azul);

    /* Pre: -.
     * POST: devuelve la cantidad de rojo.
     */
    ebmpBYTE obtenerRojo();

    /* Pre: -.
     * POST: devuelve la cantidad de verde.
     */
    ebmpBYTE obtenerVerde();

    /* Pre: -.
     * POST: devuelve la cantidad de azul.
     */
    ebmpBYTE obtenerAzul();

    /* PRE: 'nuevoRojo' es un entero entre 0 y 255.
     * POST: asigna una nueva cantidad de rojo.
     */
    void asignarRojo(ebmpBYTE nuevoRojo);

    /* PRE: 'nuevoVerde' es un entero entre 0 y 255.
     * POST: asigna una nueva cantidad de verde.
     */
    void asignarVerde(ebmpBYTE nuevoVerde);

    /* PRE: 'nuevoAzul' es un entero entre 0 y 255.
     * POST: asigna una nueva cantidad de azul.
     */
    void asignarAzul(ebmpBYTE nuevoAzul);

    /* Pre: -.
     * POST: devuelve un RGBApixel con los colores asociados.
     */
    RGBApixel obtenerPixel();

    /* POST: libera los recursos utilizados */
    ~Colores();

};






#endif /* COLORES_H_ */
