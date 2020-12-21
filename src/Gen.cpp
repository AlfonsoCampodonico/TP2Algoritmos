//
// Created by alfon on 12/11/2020.
//

#include "Gen.h"
Gen::Gen() {
    this->edad = 1;

    this->informacionGenetica= new InformacionGenetica();
    this->intensidades = new Lista<Intensidad*>();
}

Gen::Gen(std::string cadenaDeBits, unsigned int cargaGenetica){
    this->edad = 1;
    this->informacionGenetica = new InformacionGenetica(cadenaDeBits);
    this->intensidades = new Lista<Intensidad*>();
    Intensidad* intensidadNueva = new Intensidad(cargaGenetica);
    this->intensidades->agregar(intensidadNueva);
}

unsigned int Gen::ObtenerEdadGen() {
    return this->edad;
}

void Gen::anadirEdadGen() {
    unsigned int edadDelGen = ObtenerEdadGen();
    this->edad = edadDelGen++;
}

InformacionGenetica* Gen::obtenerInformacioGeneticaDelGen(){
    return this->informacionGenetica;
}


Lista<Intensidad*>* Gen::obtenerIntensidades(){
    return this->intensidades;
}

Intensidad* Gen::obtenerIntensidad(){
    return this->intensidades->obtener(1);
}



Gen::~Gen() {
    delete this->informacionGenetica;
    delete this->intensidades;
}