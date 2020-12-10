//
// Created by alfon on 12/2/2020.
//

#ifndef TABLERO_H_
#define TABLERO_H_
#include <string>
#include "Celula.h"
/*
 * Matriz bidimensional que sera la encargada de contener los elementos del juego.
 */
class Tablero {

private:

    unsigned int cantidadDeFilas;
    unsigned int cantidadDeColumnas;
    int* tablero;
    Celula* espacio;


public:
    /*
     * Pre: cantidadDeFilas y cantidadDeColumnas son mayores a 0.
     * POST: crea un tablero con las dimensiones indicadas.
     */
    Tablero(unsigned int cantidadDeColumnas, unsigned int cantidadDeFilas);

    /* POST: devuelve la cantidad de columnas del tablero */
    unsigned int contarColumnas();

    /* Pre:-
     * Post: Devuelve el tablero.
     */
    int obtenerTablero();

    /* POST: devuelve la cantidad de filas del tablero */
    unsigned int contarFilas();


    /* PRE: 'numeroDeColumna' pertenece al intervalo (0, contarColumnas()]
     * y 'numeroDeFila' pertenece al intervalo (0, contarFilas()]
     * POST: Devuelve la cantidad de vecinas vivas de la parcela ubicada en ( numeroDeColumna, numeroDeFila)
     */
    unsigned int obtenerCantidadDeVecinasVivas(unsigned int numeroDeColumna, unsigned int numeroDeFila);



    /* POST: libera los recursos utilizados */
    ~Tablero();
};

#endif /* TABLERO_H_ */
