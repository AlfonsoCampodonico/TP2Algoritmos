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


    void mostrarInformacionDelJuego(Informes *informes);
};

#endif //TP2ALGORITMOS_INTERFAZUSUARIO_H
