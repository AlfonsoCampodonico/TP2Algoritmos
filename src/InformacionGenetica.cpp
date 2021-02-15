//
// Created by alfon on 12/7/2020.
//
#include <iostream>
#include "InformacionGenetica.h"

InformacionGenetica::InformacionGenetica(std::string bits) {
    this -> cadenaDeBits = bits;
    this -> tamano = contarBits();

}
InformacionGenetica::InformacionGenetica() {
    this ->cadenaDeBits = "0";
    this -> tamano = contarBits();
}

bool InformacionGenetica::esIgualA(InformacionGenetica *otra) {
    bool iguales{};
    if (this->cadenaDeBits == otra->cadenaDeBits){
        iguales = true;
    }
    return iguales;
}

void InformacionGenetica::combinarCon(InformacionGenetica *otra) {

    std::string nuevaCadena{}, nuevaOtraCadena{}, nuevaInformacionGenetica{};

    if (this->tamano > otra->tamano){
        nuevaOtraCadena = std::string(this->tamano - otra->tamano, '0') + otra->devolverCadena();
        nuevaCadena = this->cadenaDeBits;

    }
    else if (this->tamano < otra->tamano){
        nuevaOtraCadena = otra->cadenaDeBits;
        nuevaCadena = std::string((otra->tamano - this->tamano), '0') + this->devolverCadena();
    }
    else {
        nuevaOtraCadena = otra->cadenaDeBits;
        nuevaCadena = this->cadenaDeBits;
    }
    nuevaInformacionGenetica = nuevaCadena;
    for (unsigned int i = 1; i <= nuevaCadena.length(); i++) {
        if (nuevaOtraCadena[i-1] == nuevaCadena[i-1]){
            nuevaInformacionGenetica[i-1] = '0';
        }
        else{
            nuevaInformacionGenetica[i-1] = '1';
        }
    }
    cambiarInformacionGenetica(nuevaInformacionGenetica);
}

bool InformacionGenetica::estaEncendidoBit(unsigned int i) {
    bool encendido{};
    if (this->cadenaDeBits[i] == '1'){
        encendido = true;
    }
    return encendido;
}

unsigned int InformacionGenetica::contarBits() {
    return this->cadenaDeBits.size();
}

std::string InformacionGenetica::devolverCadena(){
    return this->cadenaDeBits;
}

void InformacionGenetica::cambiarInformacionGenetica(std::string nuevaCadena){
    this->cadenaDeBits = nuevaCadena;
    this->tamano = contarBits();
}
