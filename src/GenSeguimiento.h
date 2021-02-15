//
// Created by alfon on 2/15/2021.
//

#ifndef TP2ALGORITMOS_GENSEGUIMIENTO_H
#define TP2ALGORITMOS_GENSEGUIMIENTO_H


class GenSeguimiento {
private:


    unsigned int cargaAcumuladaTurno;
    unsigned int turno;
public:
    GenSeguimiento();
    GenSeguimiento(unsigned int cargaAcumulada, unsigned int turno);
    unsigned int devolverCargaAcumuladaTurno();
    unsigned int devolverTurnoCarga();
};


#endif //TP2ALGORITMOS_GENSEGUIMIENTO_H
