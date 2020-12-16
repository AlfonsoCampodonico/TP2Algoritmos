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
 * Matriz bidimensional que sera la encargada de contener el espacio del juego.
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

    /* Pre:
     * POST: devuelve la cantidad de columnas del tablero
     * */
    unsigned int contarColumnas();

    /* Pre:
     * Post: Devuelve el tablero.
     */
    Tablero obtenerTablero();

    /* Pre:
     * POST: devuelve la cantidad de filas del tablero
     */
    unsigned int contarFilas();

    /* Pre:
     * Post: Devuelve el espacio (matriz bidemensional conformado por celulas)
     */
    Celula ***obtenerEspacio();

    /* PRE:  Parametros de posicion de la columna y la fila.
     * POST: Devuelve una celula que esta contenida en el espacio del tablero)
     */
    Celula *obtenerPosicionCelula(unsigned int numeroDeColumna, unsigned numeroDeFila);

    /* PRE:
     * POST: Recorre el espacio del tablero modificando la condicion de la celula para viva o muerta
     *       y actualiza el informe
     */
    void actualizarUnTablero(Informes *elInforme);

    /* PRE:
     * POST: Recorre el espacio del tablero indicando que celula va a morir o vivir en el turno
     */
    void dictarVida();

    /* PRE: Parametros de posicion de la columna y la fila.
     * POST: Indica si la posicion indicada existe o no en el Tablero
     */
    bool existeEnElTablero(unsigned int columna, unsigned int fila);

    /* PRE: Parametros de posicion de la columna y la fila.
     * POST: Devuelve la cantidad de celulas vecinas a la posicion indica que se encuentran con
     *       condicion de VIVA.
     */
    unsigned int determinarCuantasVecinasVivas(unsigned int columna, unsigned int fila);

    /* PRE:
    * POST: libera los recursos utilizados
    */
    ~Tablero();
};

#endif /* TABLERO_H_ */
