//
// Created by alfon on 12/7/2020.
//

#ifndef TP2ALGORITMOS_CELULA_H
#define TP2ALGORITMOS_CELULA_H

#include "Gen.h"
#include "InformacionGenetica.h"
#include "Lista.h"

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
    Lista<Gen*>* genes;


public:

    /* Pre: -.
     * Post: Se inicializa una celula con la condicion MUERTA y su posicion X y su posicion Y.
     *
     */
    Celula(int x,int y);

    Celula();


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

    int obtenerX();

    int obtenerY();

    /* Pre:-
     * Post devuelve la cantidad de celulas vecinas vivas que tiene la celula
     */
    unsigned int obtenerVecinasVivas();

    /* PRE: -.
     * POST: Libera la memoria pedida.
     */
    ~Celula();

    /*Pre:
     * Post:
     */
    void setearGen(std::string informacionGenetica, unsigned int intensidad);
    /*Pre:
     * Post:
     */
    void aumentarVecinasVivas();
};


#endif //TP2ALGORITMOS_CELULA_H
