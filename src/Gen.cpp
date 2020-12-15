//
// Created by alfon on 12/11/2020.
//

#include "Gen.h"
Gen::Gen() {
    this->edad = 1;
    this->intensidad=0;
    this->informacionGenetica=NULL;
}

Gen::Gen(std::string cadenaDeBits, unsigned int cargaGenetica){
    this->edad = 1;
    this->informacionGenetica = new InformacionGenetica(cadenaDeBits);
    this->intensidad = cargaGenetica;
}

unsigned int Gen::ObtenerEdadGen() {
    return this->edad;
}

void Gen::anadirEdadGen() {
    this->edad++;
}