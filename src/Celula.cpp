
#include "Celula.h"
#include "Tablero.h"
#include "InformacionGenetica.h"


Celula::Celula(int x,int y){
	this-> x = x;
	this-> y = y;
    this->condicion = MUERTA;
    this->informacion = new InformacionGenetica();
    this-> genes = new Lista<Gen*>();
    this-> vecinasVivas = 0;
}

Celula::Celula() {
    this->condicion = MUERTA;
    this-> genes = new Lista<Gen*>();
}

int Celula::obtenerY(){
	return (this->y);
}

int Celula::obtenerX(){
	return (this-> x);
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

unsigned int Celula::obtenerVecinasVivas(){
	return (this->vecinasVivas);
}

EstadoDeLaCelula Celula::obtenerCondicion(){
	return (this->condicion);
}

void Celula::aumentarVecinasVivas() {
    this->vecinasVivas++;
}

Celula::~Celula(){

    delete this->informacion;
    delete[] this->genes;

}
