//
// Created by alfon on 12/11/2020.
//

#include "Gen.h"
Gen::Gen() {
    this->edad = 1;
    this->informacionGenetica = new InformacionGenetica();
    this->intensidades = new Lista<Intensidad*>();
    this->intensidad = 0;
}

Gen::Gen(std::string cadenaDeBits, unsigned int cargaGenetica){
    this->edad = 1;
    this->informacionGenetica = new InformacionGenetica(cadenaDeBits);
    this->intensidades = new Lista<Intensidad*>();
    agregarIntensidad(cargaGenetica);
    this->intensidad = cargaGenetica;


}

unsigned int Gen::ObtenerEdadGen() {
    return this->edad;
}

void Gen::agregarIntensidad(unsigned int cargaGenetica){
    Intensidad* intensidadNueva = new Intensidad(cargaGenetica);
    this->intensidades->agregar(intensidadNueva);
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

unsigned int Gen::obtenerValorIntensidad(){
    Intensidad* intensidadValor = obtenerIntensidad();
    return intensidadValor->obtenerCantidadIntensidad();

}

unsigned int Gen::obtenerValorIntensidadPrincipal(){
return this->intensidad;
}

void Gen::liberarIntensidades() {
    while (!this->intensidades->estaVacia()) {
        Intensidad *unaIntensidad;
        unaIntensidad = this->intensidades->obtener(1);
        this->intensidades->remover(1);
        delete unaIntensidad;
    }
}

void Gen::cambiarIntensidadPrincipal(unsigned int intensidadNueva){
    this->intensidad = intensidadNueva;
   // liberarIntensidades();
    delete this->intensidades;
    this->intensidades = new Lista<Intensidad*>();
    agregarIntensidad(intensidadNueva);
}




Gen::~Gen() {
    //liberarIntensidades();
    delete this->intensidades;
    delete this->informacionGenetica;
}