
#include "Celula.h"
#include "Tablero.h"
#include "InformacionGenetica.h"


Celula::Celula() {
    this-> condicion = MUERTA;
    this-> genes = new Lista<Gen*>();
}


void Celula::setearGen(std::string informacionGenetica, unsigned int intensidad) {
    Gen* unGen;
    unGen = new Gen(informacionGenetica, intensidad);
    this->genes->agregar(unGen);
}


void Celula::revivirCelula(){
    this->condicion = VIVA;
}


void Celula::matarCelula(){
    this->condicion = MUERTA;
}

bool Celula::estaMuerta(){
    return (this->condicion == MUERTA);
}

bool Celula::estaViva(){
    return (this->condicion == VIVA);
}


EstadoDeLaCelula Celula::obtenerCondicion(){
	return (this->condicion);
}


Celula::~Celula(){

    delete this->informacion;
    delete[] this->genes;

}
