//
// Created by alfon on 12/9/2020.
//

#ifndef TP2ALGORITMOS_JUEGODELAVIDA_H
#define TP2ALGORITMOS_JUEGODELAVIDA_H
#include "InterfazUsuario.h"
#include "Tablero.h"
#include "Informes.h"
#include "ImpresoraDeImagenes.h"
#include "Seguimiento.h"
#include <iostream>
#include <fstream>


class JuegoDeLaVida {
private:
    InterfazUsuario* consola;
    Tablero* elTablero;
    Informes* informes;
    ImpresoraDeImagenes* impresora;
    Seguimiento* seguimiento;

public:
    /* PRE:
     * POST: pide los recursos necesarios para generar los elementos de los componentes del juego.
     */
    JuegoDeLaVida();

    /* PRE: ruta del archivo inicial a procesar.
     * POST: Abre la ruta de un archivo para su procesamiento, en caso de que sea erronea la ruta
     *  pide al usuario volver aa ingresar hasta tener una ruta valida.
     */
    void ingresarRutaDelArchivo(ifstream& archivo);

    /* PRE: ruta del archivo inicial a procesar.
     * POST: Recorre el archivo buscando palabras clave de identificacion para cargar las estructuras.
     */
    void procesarArchivo(ifstream& archivo);

    /* PRE: ruta del archivo inicial a procesar.
     * POST: Crea el tablero de juego a partir de los valores indicados en el archivo.
     */
    void crearTablero(ifstream& archivo);

    /* PRE: ruta del archivo inicial a procesar.
     * POST: Agrega celulas vivas en el tablero a partir de los valores indicados en el archivo.
     */
    void agregarCelula(ifstream& archivo);

    /* PRE: ruta del archivo inicial a procesar.
     * POST: Agrega genes con carga y informacion genetica en las celulas
     * a partir de los valores indicados en el archivo.
     */
    void anadirGen(ifstream& archivo,Celula* celula);

    /* PRE: Que exista un tablero
     * POST: Realiza la accion de jugar el juego de la vida
     */
    void jugarElJuegoDeLaVida();

    /* PRE:
     * POST: Realiza la accion de comenzar a jugar ElJuegoDeLaVida
     */
    void comenzarElJuegoDeLaVida(bool &terminaElJuegoDeLaVida);

    /* PRE:
     * POST: Realiza la logica para elegir una accion en el Menu
     * del juego de la vida 1.0 Recargado
     */
    unsigned int elegirUnaAccionDelMenuDeJuego();

    /* PRE: un numero introducido por el usuario del 1 al 3.
     * POST: Realiza la accion indicada por el usuario
     */
    void realizarAccionElegida(unsigned int numeroElegido);

    /* PRE:
     * POST: Ejecuta un turno en el juego de la vida
     */
    void ejecutarTurno();

    /* PRE:
     * POST: Reinicia el juego liberando el tablero y informe para volver a comenzar.
     */
    void reiniciarElJuegoDeLaVida();

    /* PRE:
     * POST: Libera los recursos pedidos por el juego de la vida
     */
    ~JuegoDeLaVida();

    /* PRE: un numero introducido por el usuario del 1 al 4.
     * POST: Realiza la accion indicada por el usuario
     */
    void realizarAccionElegida(unsigned int numeroElegido, bool &seguimiento);

    /* PRE:
     * POST: Comienza el seguimiento de un gen
     */
    void comenzarSeguimiento(bool &seguimiento);


};

#endif //TP2ALGORITMOS_JUEGODELAVIDA_H
