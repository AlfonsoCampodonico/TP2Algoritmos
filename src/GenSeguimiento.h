//
// Created by alfon on 2/6/2021.
//

#ifndef TP2ALGORITMOS_GENSEGUIMIENTO_H
#define TP2ALGORITMOS_GENSEGUIMIENTO_H


class GenSeguimiento {
private:


    unsigned int cargaAcumuladaTurno;
    unsigned int turno;
public:

    /* PRE: Recibe un entero con la carga acumulada y el turno en que se cargo
     * POST: Genera un Gen de seguimiento para agregar a una lista de seguimiento
     */
    GenSeguimiento(unsigned int cargaAcumulada, unsigned int turno);


    /* PRE:
     * POST: Devuelve la cantidad de carga Acumulada en un gen en un turno
     */
    unsigned int devolverCargaAcumuladaTurno();

    /* PRE:
     * POST: Devuelve el turno cuando fue cargada
     */
    unsigned int devolverTurnoCarga();
};


#endif //TP2ALGORITMOS_GENSEGUIMIENTO_H
