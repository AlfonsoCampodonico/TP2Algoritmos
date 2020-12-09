//
// Created by alfon on 12/7/2020.
//

#ifndef TP2ALGORITMOS_CELULA_H
#define TP2ALGORITMOS_CELULA_H

#include "InformacionGenetica.h"

enum EstadoDeLaCelula {
    MUERTA,
    VIVA
};

/* Unidad basica que compone un organismo.
 * Su condicion esta representada por un tipo de dato enumerado que puede variar entre:
 * 	 MUERTA: una celula sin vida.
 *	 VIVA: una celula con vida.
 */
class Celula{

private:
    EstadoDeLaCelula condicion;
    InformacionGenetica* informacionGenetica;

public:

    /* Pre: -.
     * Post: Se inicializa una celula con la condicion MUERTA
     *
     */
    Celula();

    /* Pre: Que el estado de la cedula este muerta
     * Post: La celula pasa a estar viva.
     */
    void revivirCelula();

    /* PRE: Que el estado de la cedula este viva.
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

    /* PRE: -.
     * POST: Libera la memoria pedida.
     */
    ~Celula();
};


#endif //TP2ALGORITMOS_CELULA_H
