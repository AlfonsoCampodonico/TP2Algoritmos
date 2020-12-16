
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
	(this-> nacimientosTurnos) = 0;
}

void Informes::resetearMuertesTurno(){
	(this-> muertesTurnos) = 0;
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

float Informes::obtenerPromedioNacimiento(){
    return this->promedioNacimiento;
}

float Informes::obtenerPromedioMuertes(){
    return this->promedioMuertes;
}
void Informes::contarCelulasVivas(Tablero* tablero){

    for(unsigned int columna = 1; columna <= tablero->contarColumnas(); columna++){
        for(unsigned int fila = 1; fila <= tablero->contarFilas(); fila++){

            Celula* unaCelula = tablero->obtenerPosicionCelula(columna,fila);

            if(unaCelula->estaViva()){
                sumarViva();
            }


        }
    }
}
unsigned int Informes::obtenerCelulasVivas(){
    return this->celulasVivas;
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

void Informes::resetearInformeTurno() {
    this->resetearNacimientosTurno();
    this->resetearMuertesTurno();
    this->resetearVivas();
}

void Informes::actualizarInformeTurno(Tablero* tablero){
    this->sumarTurno();
    this->contarCelulasVivas(tablero);
    this->sumarMuertesTotales();
    this->sumarNacimientosTotales();
    this->promediarNacimiento();
    this->promediarMuertes();
}

