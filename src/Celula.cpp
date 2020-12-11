
#include "Celula.h"
//#include "Tablero.h"
Celula::Celula(int x,int y){
	this-> x = x;
	this-> y = y;
    this->condicion = MUERTA;
    this->gen = new Gen();
    this-> vecinasVivas = 0;
}

Celula::Celula() {
    this->condicion = MUERTA;
    this->gen = new Gen();
}
/*void Celula::analizarCelula(){
	if ((this->condicion == MUERTA) && (obtenerVecinasVivas() == 3)){
		revivirCelula();
	}
	else if((this-> condicion == VIVA )&& (obtenerVecinasVivas() != 2 || obtenerVecinasVivas() != 3) ){
		matarCelula();
	}
}

void Celula::revivirCelula(){
    this->condicion = VIVA;
}
 void Celula::CantidadDeVecinasVivas(int x , int y,Tablero* tablero){

	if ((this->obtenerCondicion()) == VIVA && (x-1) != -1 && (y-1) != -1){
	    this->vecinasVivas ++;
	      }
	if ((this->obtenerCondicion())== VIVA && (x+1) != tablero->contarFilas() && (y+1) != tablero->contarColumnas()){
	      this->vecinasVivas ++;
	    }
	if ((this->obtenerCondicion())== VIVA && (y+1) != tablero->contarColumnas()){
	    this->vecinasVivas ++;
	    }
	if ((this->obtenerCondicion())== VIVA && (y-1) != -1){
		this->vecinasVivas ++;
	}
	if ((this->obtenerCondicion())== VIVA && (x+1) != tablero->contarFilas()){
		this->vecinasVivas ++;
	      }
	if ((this->obtenerCondicion())== VIVA && (x-1) != -1){
		this->vecinasVivas ++;
	        }
	if ((this->obtenerCondicion())== VIVA && (x-1) != -1 && (y+1) != tablero->contarColumnas()){
		this->vecinasVivas ++;
	        }
	if ((this->obtenerCondicion())== VIVA && (x+1) != tablero->contarFilas() && (y-1) != -1){
		this->vecinasVivas ++;
	        }
	}
*/
void Celula::matarCelula(){
    this->condicion = MUERTA;
}

bool Celula::estaMuerta(){
    return (this->condicion==MUERTA);
}

bool Celula::estaViva(){
    return (this->condicion==VIVA);
}

/*unsigned int Celula::obtenerVecinasVivas(){
	return (this->vecinasVivas);
}*/

EstadoDeLaCelula Celula::obtenerCondicion(){
	return (this->condicion);
}
Celula::~Celula(){
    delete this->gen;
}
