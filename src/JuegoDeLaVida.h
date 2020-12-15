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
    /* PRE:
     * POST: pide los recursos necesarios para generar los elementos de los componentes del juego.
     */
    JuegoDeLaVida();

    /* PRE: ruta del archivo inicial a procesar.
     * POST: TODO
     */
    void ingresarRutaDelArchivo(ifstream& archivo);

    /* PRE: TODO
     * POST: TODO
     */
    void procesarArchivo(ifstream& archivo);

    /* PRE: TODO
     * POST: TODO
     */
    void crearTablero(ifstream& archivo);

    /* PRE: TODO
     * POST: TODO
     */
    void agregarCelula(ifstream& archivo)

    /* PRE: TODO
     * POST: TODO
     */
    void anadirGen(ifstream& archivo,Celula* celula);

    /* PRE: TODO
     * POST: TODO
     */
    void jugar();
};

#endif //TP2ALGORITMOS_JUEGODELAVIDA_H
