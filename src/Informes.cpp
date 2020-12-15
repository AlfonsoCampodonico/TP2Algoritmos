
#include "Informes.h"
#include "Tablero.h"


Informes::Informes(){

	this->cantidadTurnos = 0;
	this-> celulasVivas = 0;
	this-> nacimientosTurnos = 0;
	this-> nacimientosTotales = 0;
	this-> muertesTurnos = 0;
	this-> muertesTotales = 0;
	this-> promedioNacimiento = 0;
	this->promedioMuertes = 0;
	this->juegoCongelado = 0;
}

unsigned int Informes::obtenerTurnos(){
	return (this->cantidadTurnos);
}



void Informes::resetearVivas(){
	(this->celulasVivas) = 0;
}

void Informes::resetearTurnos(){
	(this->cantidadTurnos) = 0;
}

unsigned int Informes::obtenerMuertesTurno(){
	return (this->muertesTurnos);
}

unsigned int Informes::obtenerNacimientosTurno(){
	return (this->nacimientosTurnos);
}
//TODO
int Informes::obtenerNacimientosTotales(){
	return (this-> nacimientosTotales);
}

int Informes::obtenerMuertesTotales() {
    return (this->muertesTotales);
}

void Informes::resetearNacimientosTurno(){
	(this-> nacimientos) = 0;
}

void Informes::resetearMuertes(){
	(this-> muertes) = 0;
}


void Informes::sumarViva(){
	this->celulasVivas++;
}

void Informes::sumarTurno(){
	this->cantidadTurnos++;
}

void Informes::sumarNacimiento(){
	this->nacimientosTurnos++;
}

void Informes::sumarNacimientosTotales(){
	this->nacimientosTotales += obtenerNacimientosTurno();
}

void Informes::sumarMuertesTotales(){
	this-> muertesTotales += obtenerMuertesTurno();
}


void Informes::sumarMuerte(){
	this-> muertesTurnos++;
}

void Informes::promediarNacimiento(){
	this->promedioNacimiento = (float)obtenerNacimientosTotales()/(float)obtenerTurnos();
}

void Informes::promediarMuertes(){
	this->promedioMuertes = (float)obtenerMuertesTotales() / (float)obtenerTurnos();
}

void Informes::contarCelulasVivas(Tablero* tablero){

	for (int x = 0 ; x < tablero->contarFilas() ; x++){
		for (int y = 0 ; y < tablero->contarColumnas() ; y++){
			Celula* celula = (tablero->obtenerEspacio())[x][y];
			if ((celula->obtenerCondicion()) == VIVA){
					sumarViva();
			}
		}
	}
}

bool Informes::estaCongelado(){
	bool congelado = false;
	if ((obtenerNacimientosTurno() == 0) && (obtenerMuertesTurno() == 0)){
		this-> juegoCongelado++;
		congelado = ((this->juegoCongelado) == 2);
		}
	else {
		this->juegoCongelado = 0;
	}
	return congelado;
}
