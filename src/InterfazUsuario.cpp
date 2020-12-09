//
// Created by alfon on 12/9/2020.
//


#include "InterfazUsuario.h"
InterfazUsuario::InterfazUsuario(){

}

void InterfazUsuario::enviarMensajeInicioJuego(){

    cout << "Bienvenido al 'Juego de la Vida Recargado v1.0'." << endl;
}

void InterfazUsuario::pedirRutaDeUnArchivo(){
    cout << endl;
    cout << "Por favor agrega la ruta del archivo a continuacion"<< endl;
    cout << "Nombre archivo:"
}

void InterfazUsuario::mostrarArchivoInexistente(){
    cout << endl;
    cout << "El archivo no existe! Favor verificar." << endl;
}