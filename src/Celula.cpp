//
// Created by alfon on 12/7/2020.
//
#include "Celula.h"

Celula::Celula(){
    this->condicion = MUERTA;
    this->informacionGenetica = new InformacionGenetica();
}


void Celula::revivirCelula(){
    this->condicion = VIVA;
}

void Celula::matarCelula(){
    this->condicion = MUERTA;
}

bool Celula::estaMuerta(){
    return (this->condicion==MUERTA);
}

bool Celula::estaViva(){
    return (this->condicion==VIVA);
}

Celula::~Celula(){
    delete this->informacionGenetica;
}