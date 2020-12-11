//
// Created by alfon on 12/7/2020.
//

#include "InformacionGenetica.h"

InformacionGenetica::InformacionGenetica(std::string bits) {
    this -> cadenaDeBits = bits;
    this -> tamano = contarBits();

}
InformacionGenetica::InformacionGenetica() {
    this ->cadenaDeBits = "0";
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
        nuevaOtraCadena = std::string(this->tamano - otra->tamano, '0') + otra->cadenaDeBits;
        nuevaCadena = this->cadenaDeBits;

    }
    else if (this->tamano < otra->tamano){
        nuevaOtraCadena = otra->cadenaDeBits;
        nuevaCadena = std::string(otra->tamano - this->tamano, '0') + this->cadenaDeBits;
    }
    else {
        nuevaOtraCadena = otra->cadenaDeBits;
        nuevaCadena = this->cadenaDeBits;
    }

    nuevaInformacionGenetica = nuevaCadena;
    for (unsigned int i = 0; i < nuevaCadena.size(); i++) {

        if (nuevaOtraCadena[i] == nuevaCadena[i]){
            nuevaInformacionGenetica[i] = '0';
        }
        else{
            nuevaInformacionGenetica[1] = '1';
        }

    }

    this->cadenaDeBits = nuevaInformacionGenetica;

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


