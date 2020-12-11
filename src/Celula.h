//
// Created by alfon on 12/7/2020.
//

#ifndef TP2ALGORITMOS_CELULA_H
#define TP2ALGORITMOS_CELULA_H

//#include "Tablero.h"
#include "Gen.h"
#include "InformacionGenetica.h"

enum EstadoDeLaCelula {
    MUERTA,
    VIVA
};

/* Unidad basica que compone un organismo.
 * Su condicion esta representada por un tipo de valor enumerado que puede variar entre:
 * 	 MUERTA: una celula sin vida.
 *	 VIVA: una celula con vida.
 */
class Celula{

private:

/* Es la posicion x de la celula
	 *
	 */
	int x;
	/*
	 * Es la posicion y de la celula
	 */
	int y;
	InformacionGenetica* informacion;
	int vecinasVivas;
    EstadoDeLaCelula condicion;
    Gen* gen;


public:

    /* Pre: -.
     * Post: Se inicializa una celula con la condicion MUERTA y su posicion X y su posicion Y.
     *
     */
    Celula(int x,int y);

    Celula();

    /* Pre: -
     * Post: Analizara la celula para ver si se cumplen las condiciones para seguir viva o muerta.
     */
    void analizarCelula();

    /* Pre: Que el estado de la celula este muerta
     * Post: La celula pasa a estar viva.
     */
    void revivirCelula();

    /* PRE: Que el estado de la celula este viva.
     * POST: La celula pasa a estar muerta.
     */
    void matarCelula();

    /* PRE: -.
     * POST: Indica si la celula esta muerta.
     */
    bool estaMuerta();

    /* PRE: -.
     * POST: Indica si la celula esta viva.
     */
    bool estaViva();
    /*Pre:-
     * Post: Devuelve el estado de la celula
     */
    EstadoDeLaCelula obtenerCondicion();

    /*Pre: Que la posicion X y Y de la celula sea la correcta y este dentro de los rangos [1,MAX]
     * Post: Calcula la cantidad de celulas vecinas vivas
     */

    //void CantidadDeVecinasVivas(int x, int y,Tablero* tablero);

    /* Pre:-
     * Post devuelve la cantidad de celulas vecinas vivas que tiene la celula
     */
    //unsigned int obtenerVecinasVivas();

    /* PRE: -.
     * POST: Libera la memoria pedida.
     */
    ~Celula();

};


#endif //TP2ALGORITMOS_CELULA_H
