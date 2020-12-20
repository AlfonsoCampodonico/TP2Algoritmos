//
// Created by alfon on 12/7/2020.
//

#ifndef TP2ALGORITMOS_CELULA_H
#define TP2ALGORITMOS_CELULA_H

#include "Gen.h"
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
    /*Constructor de la Celula
     *
     *
     */
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


    /*Pre:
     * Post:
     */
    void setearGen(std::string informacionGenetica, unsigned int intensidad);
    /*Pre:
     * Post:
     */

    void vaAVivir();

    void vaAMorir();

    /* PRE: -.
     * POST: Indica si la celula esta casi viva.
     */
    bool estaCasiViva();

    /* PRE: -.
     * POST: Indica si la celula esta casi muerta.
     */
    bool estaCasiMuerta();

    Lista<Gen *> *obtenerListaGen();

    /* PRE: -.
     * POST: Libera la memoria pedida.
     */
    ~Celula();

    void liberarGenes();

    void completarTransferencia();

    void calcularIntensidad();

    void mutar();
};


#endif //TP2ALGORITMOS_CELULA_H
