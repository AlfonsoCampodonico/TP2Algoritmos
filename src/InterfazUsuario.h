//
// Created by alfon on 12/9/2020.
//

#ifndef TP2ALGORITMOS_INTERFAZUSUARIO_H
#define TP2ALGORITMOS_INTERFAZUSUARIO_H
#include <string>
#include <iostream>
#include "Informes.h"
using namespace  std;
/*
 * La 'InterfazUsuario' se encarga de mostrar mensajes al usuario por consola
 */
class InterfazUsuario {

public:

    InterfazUsuario();

    /* PRE: -.
     * POST:Muestra un mensaje de inicio del juego de la vida.
     */
    void enviarMensajeInicioJuego();

    /* PRE: -.
     * POST: Muestra un mensaje por consola para pedir la ruta de un archivo
     */
    void pedirRutaDeUnArchivo();

    /* PRE: -.
     * POST: Muestra  un mensaje por consola para indicar que el archivo no existe
     */
    void mostrarArchivoInexistente();

    /* PRE: -.
     * POST: Muestra por consola el final del Juego de la vida
     */
    void mostrarFinDelJuegoDeLaVida();

    /* PRE: -.
     * POST: Muestra por consola si el juego de la vida se encuentra congelado
     */
    void mostrarCongelado();

    /* PRE: -.
     * POST: Muestra por consola el menu del juego de la vida
     */
    void mostrarMenuDeJuegoDeLaVida();

    /* PRE: -.
     * POST: Muestra por consola al usuario de que el numero introducio no es valido
     */
    void mostrarQueNoEsUnNumeroValido();

    /* PRE: -.
     * POST: Muestra el informe del juego
     */
    void mostrarInformeDelJuego(Informes *informes);

    /* PRE: -.
     * POST: Muestra el mensaje de pedido de Seguimiento del Gen
     */
    void mostrarPedidoSeguimientoGen();
};

#endif //TP2ALGORITMOS_INTERFAZUSUARIO_H
