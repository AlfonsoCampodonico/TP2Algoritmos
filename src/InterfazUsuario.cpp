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
    cout << "Nombre archivo:";
}

void InterfazUsuario::mostrarArchivoInexistente(){
    cout << endl;
    cout << "El archivo no existe! Por favor verificar." << endl;
}


void InterfazUsuario::mostrarInformacionDelJuego(Informes* informes) {
    cout << endl;
    //cout << "Celulas vivas: " << informes->contarCelulasVivas() << endl;
    //cout << "Nacimientos: " << informes->obtenerNacimientos() << endl;
}
