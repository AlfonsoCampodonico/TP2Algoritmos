//
// Created by alfon on 12/2/2020.
//

#ifndef TABLERO_H_
#define TABLERO_H_

#include <string>
#include "Celula.h"
#include "Informes.h"

class Informes;
/*
 * Matriz bidimensional que sera la encargada de contener los elementos del juego.
 */
class Tablero {

private:

    unsigned int cantidadDeFilas;
    unsigned int cantidadDeColumnas;
    Celula*** espacio;


public:
    /*
     * Pre: cantidadDeFilas y cantidadDeColumnas son mayores a 0.
     * POST: crea un tablero con las dimensiones indicadas.
     */
    Tablero(unsigned int cantidadDeColumnas, unsigned int cantidadDeFilas);

    /* POST: devuelve la cantidad de columnas del tablero */
    unsigned int contarColumnas();

    /* Pre:-
     * Post: Devuelve el tablero.
     */
    Tablero obtenerTablero();

    /* POST: devuelve la cantidad de filas del tablero */
    unsigned int contarFilas();

    /*Pre: Tener un tablero inicializado
     * Post: Si se cumplen las condiciones, cambia la condicion de la celula
     */
    void analizarCondicion(Informes *informes);

    /*Pre:Se debe pasar un objeto a puntero del tipo Celula y las posiciones de la celula
     * Post: Se fija si las vecinas de la celula estan vivas y las cuenta.
     */
    void cantidadDeVecinasVivas(int x, int y);

    /*Pre: TODO
     * Post: TODO
     */

    Celula ***obtenerEspacio();

    /* PRE: Tener un tablero inicializado
     * POST: Recorre todo el tablero para contar las vecinas vivas de cada celula
     */

    void contarVecinasVivas();

    /*PRE: TODO
     * Post:TODO
     */
    void analizarCelula(Celula *celula, Informes *informes);

    /* PRE:TODO
     * POST:TODO
     */
    Celula *obtenerPosicionCelula(unsigned int numeroDeColumna, unsigned numeroDeFila);


    /* POST: libera los recursos utilizados */

    ~Tablero();

    void determinarVida(Informes *informes, Tablero* otroTablero);

    Celula ***clonarCelulas();

    Celula ***clonarCelulas(Celula ***espacio);

    void actualizarUnTablero(Informes *elInforme);

    void dictarVida();

    bool existeEnElTablero(unsigned int columna, unsigned int fila);

    unsigned int determinarCuantasVecinasVivas(unsigned int columna, unsigned int fila);
};

#endif /* TABLERO_H_ */
