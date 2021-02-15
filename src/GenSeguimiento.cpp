//
// Created by alfon on 2/15/2021.
//

#include "GenSeguimiento.h"
GenSeguimiento::GenSeguimiento(unsigned int cargaAcumulada, unsigned int turno) {
    this->cargaAcumuladaTurno = cargaAcumulada;
    this->turno = turno;

}

unsigned int GenSeguimiento::devolverCargaAcumuladaTurno() {
    return this->cargaAcumuladaTurno;
}
unsigned  int  GenSeguimiento::devolverTurnoCarga(){
    return this->turno;
}