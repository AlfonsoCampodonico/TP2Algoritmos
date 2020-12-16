
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
bool Celula::estaViva(){
    return (this->condicion == VIVA);
}
void Celula::matarCelula(){
    this->condicion = MUERTA;
}
bool Celula::estaMuerta(){
    return (this->condicion == MUERTA);
}
void Celula::vaAMorir(){
    this->condicion = CASIMUERTA;
}
bool Celula::estaCasiMuerta(){
    return (this->condicion == CASIMUERTA);
}

void Celula::vaAVivir(){
    this->condicion = CASIVIVA;
}

bool Celula::estaCasiViva(){
    return (this->condicion == CASIVIVA);
}





EstadoDeLaCelula Celula::obtenerCondicion(){
	return (this->condicion);
}

Lista<Gen*>* Celula::obtenerListaGen(){
    return this->genes;
}

Celula::~Celula(){

    delete[] this->genes;

}
