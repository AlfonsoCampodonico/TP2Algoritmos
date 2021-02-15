//
// Created by alfon on 2/6/2021.
//

#ifndef TP2ALGORITMOS_SEGUIMIENTO_H
#define TP2ALGORITMOS_SEGUIMIENTO_H


#include <string>
#include "Lista.h"
#include "GenSeguimiento.h"
#include "Tablero.h"
class Seguimiento {
private:
    std::string informacionGeneticaDelGen;
    unsigned int turnoDeComienzo;
    unsigned int turnoDeFinalizacion;
    Lista<GenSeguimiento*>* listadoPorTurno;
    unsigned int mayorAcumulado;
public:

    /* PRE:
     * POST: Genera un seguimiento de un Gen
     */
    Seguimiento();

    /* PRE:turnoInicio es un entero que indica cuando comenzo el seguimiento
     * POST: Modifica el turno de inicio del seguimiento
     */
    void modificarTurnoInicio(unsigned int turnoInicio);

    /* PRE:turnoFin es un entero que indica cuando termina el seguimiento
     * POST: Modifica el turno de finalizacion del seguimiento
     */
    void modificarTurnoFin(unsigned int turnoFin);

    /* PRE:
    * POST: agrega una carga acumulada al gen que se le esta haciendo el seguimiento
    */
    void agregarTurnoAGen(unsigned int cargaAcumulada, unsigned int turno);

    /* PRE: Recibe un tablero con celulas vivas
    * POST: recorre el tablero para buscar los genes que son iguales y sumar la carga genetica de ellos
    */
    void buscarTablero(Tablero *unTablero, unsigned int turno);

    /* PRE:
    * POST: devuelve la lista de Acumulado del Gen de seguimiento
    */
    Lista<GenSeguimiento *> *devolverListaAcumulado();

    /* PRE:
    * POST: Devuelve el turno de inicio del seguimiento
    */
    unsigned int devolverTurnoInicio();

    /* PRE:
    * POST: Devuelve el turno de finalizacion del seguimiento
    */
    unsigned int devolverTurnoFin();

    /* PRE:
    * POST: Devuelve la cadena de caracteres de informacion genetica que se le esta haciendo
     * el seguimiento
    */
    std::string devolverCadenaGen();

    /* PRE:
     * POST: devuelve el mayor valor de intensidad acumulada del gen que se le esta haciendo
     * el seguimiento
     */
    unsigned int devolverMayorAcumulado();

    /* PRE:  recibe una cadena de caracteres para modificar
    * POST: Cambia la cadena de caracteres  de informacion genetica que se le esta haciendo
    * el seguimiento
    */
    void modificarInformacionGenetica(std::string informacionGenetica);
};



#endif //TP2ALGORITMOS_SEGUIMIENTO_H
