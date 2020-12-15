//
// Created by alfon on 12/9/2020.
//

#ifndef TP2ALGORITMOS_JUEGODELAVIDA_H
#define TP2ALGORITMOS_JUEGODELAVIDA_H
#include "InterfazUsuario.h"
#include "Tablero.h"
#include "Informes.h"
#include <iostream>
#include <fstream>


class JuegoDeLaVida {
private:
    InterfazUsuario* consola;
    Tablero* elTablero;
    Informes* informes;
public:
    JuegoDeLaVida();
    void ingresarRutaDelArchivo(ifstream& archivo);
    void procesarArchivo(ifstream& archivo);
    void crearTablero(ifstream& archivo);
    void agregarCelula(ifstream& archivo);
    void anadirGen(ifstream& archivo,Celula* celula);
    void jugar();
};

#endif //TP2ALGORITMOS_JUEGODELAVIDA_H
