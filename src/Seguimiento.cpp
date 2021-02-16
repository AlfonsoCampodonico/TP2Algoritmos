//
// Created by alfon on 2/6/2021.
//

#include "Seguimiento.h"


Seguimiento::Seguimiento() {
    this->informacionGeneticaDelGen = "";
    this->turnoDeComienzo = 1;
    this->turnoDeFinalizacion = 1;
    this->listadoPorTurno = new Lista<GenSeguimiento*>();
    this->mayorAcumulado = 1;

}


void Seguimiento::modificarTurnoInicio(unsigned int turnoInicio){
    this->turnoDeComienzo = turnoInicio;
}

void Seguimiento::modificarTurnoFin(unsigned int turnoFin){
    this->turnoDeFinalizacion = turnoFin;
}

void Seguimiento::agregarTurnoAGen(unsigned int cargaAcumulada, unsigned int turno){
    GenSeguimiento* nuevoTurno = new GenSeguimiento(cargaAcumulada,turno);
    this->listadoPorTurno->agregar(nuevoTurno);
    if (cargaAcumulada > this->mayorAcumulado){
        this->mayorAcumulado = cargaAcumulada;
    }
}

void Seguimiento::buscarTablero(Tablero* unTablero, unsigned int turno){
    unsigned int acumulado = 0;
    for(unsigned int columna = 1; columna <= unTablero->contarColumnas(); columna++){

        for(unsigned int fila = 1; fila <= unTablero->contarFilas(); fila++){

            Lista<Gen*>* unaListaGenes = unTablero->obtenerPosicionCelula(columna,fila)->obtenerListaGen();
            unaListaGenes->iniciarCursor();

            while (unaListaGenes->avanzarCursor()) {
                Gen* unGen =   unaListaGenes->obtenerCursor();
                if(unGen->
                    obtenerInformacioGeneticaDelGen()->
                        devolverCadena() == this->informacionGeneticaDelGen){

                            acumulado += unGen->obtenerValorIntensidad() ;
                      }
            }
        }

    }

    this->agregarTurnoAGen(acumulado,turno);
}

Lista<GenSeguimiento*>* Seguimiento::devolverListaAcumulado(){
    return this->listadoPorTurno;
}

unsigned int Seguimiento::devolverTurnoInicio(){
    return this->turnoDeComienzo;
}

unsigned int Seguimiento::devolverTurnoFin(){
    return this->turnoDeComienzo;
}

std::string Seguimiento::devolverCadenaGen(){
    return this->informacionGeneticaDelGen;
}

unsigned int Seguimiento::devolverMayorAcumulado(){
    return this->mayorAcumulado;
}

void Seguimiento::modificarInformacionGenetica(std::string informacionGenetica){
    this->informacionGeneticaDelGen = informacionGenetica;
}