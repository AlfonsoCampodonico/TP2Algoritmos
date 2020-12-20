//
// Created by alfon on 12/7/2020.
//

#ifndef TP2ALGORITMOS_INTENSIDAD_H
#define TP2ALGORITMOS_INTENSIDAD_H

/*
 * Es la  intensidad con la que un gen está presente en una célula determinada.
 * La intensidad se expresa como un número entero en el rango: [0,100]
 */

class Intensidad{

private:

    unsigned  int cargaGeneticaTotal;

public:

    /* Pre: -.
     * Post: Intensidad de una carga Genetica.
     */
    Intensidad(unsigned  int intensidad);

    /* Pre: -.
     * Post: devuelve la cantidad de carga genetica.
     */
    unsigned  int obtenerCantidadIntensidad();

    void cambiarIntensidad(unsigned int carga);

    bool estaActiva();
};
#endif //TP2ALGORITMOS_INTENSIDAD_H
