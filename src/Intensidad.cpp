//
// Created by alfon on 12/7/2020.
//
#include "Intensidad.h"

Intensidad::Intensidad(unsigned int intensidad) {
    this->cargaGeneticaTotal = intensidad;
}

unsigned  Intensidad::obtenerCantidadIntensidad() {
    return this->cargaGeneticaTotal;
}
