
#include "informes.h"

Informes::Informes(){

	this->cantidadTurnos = 0;
	this-> celulasVivas = 0;
	this-> celulasQueNacenEnElTurno = 0;
	this-> celulasQueMuerenEnElTurno = 0;
	this-> promedioNacimiento = 0;
	this->promedioMuertes = 0;
	this->juegoCongelado = 0;
}

unsigned int Informes::obtenerTurnos(){
	return (this->cantidadTurnos);
}

unsigned int Informes::obtenerMuertes(){
	return (this->celulasQueMuerenEnElTurno);
}

unsigned int Informes::obtenerNacimientos(){
	return (this->celulasQueNacenEnElTurno);
}

void Informes::sumarTurno(){
	this->cantidadTurnos++;
}

void Informes::sumarNacimiento(){
	this->celulasQueNacenEnElTurno++;
}

void Informes::sumarMuerte(){
	this-> celulasQueMuerenEnElTurno++;
}

void Informes::promediarNacimiento(){
	this->promedioNacimiento = (float)obtenerNacimientos()/(float)obtenerTurnos();
}

void Informes::promediarMuertes(){
	this->promedioMuertes = (float)obtenerMuertes() / (float)obtenerTurnos();
}


