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
    VIVA,
    CASIMUERTA,
    CASIVIVA
};

/* Unidad basica que compone un organismo.
 * Su condicion esta representada por un tipo de valor enumerado que puede variar entre:
 * 	 MUERTA: una celula sin vida.
 *	 VIVA: una celula con vida.
 */
class Celula{

private:
    EstadoDeLaCelula condicion;
    Lista<Gen*>* genes;
public:


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

    void vaAVivir();

    void vaAMorir();

    bool estaCasiViva();

    bool estaCasiMuerta();

    Lista<Gen *> *obtenerListaGen();
};


#endif //TP2ALGORITMOS_CELULA_H
