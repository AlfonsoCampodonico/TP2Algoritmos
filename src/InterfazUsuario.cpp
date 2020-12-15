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

void InterfazUsuario::mostrarFinDelJuegoDeLaVida(){
    cout << endl;
    cout << "          " << endl;
    cout << "FIN";
}

void InterfazUsuario::mostrarCongelado() {
    cout << endl;
    cout << "El juego se congelo, no van a seguir naciendo o muriendo celulas!" << endl;
}

void InterfazUsuario::mostrarMenuDeJuegoDeLaVida(){
    cout << endl;
    cout << "Menu Juego de la Vida 1.0 Recargado" << endl;
    cout << "1. Ejecutar un turno" << endl;
    cout << "2. Reiniciar" << endl;
    cout << "3. Terminar" << endl << endl;
}

void InterfazUsuario::mostrarQueNoEsUnNumeroValido(){
    cout << endl;
    cout << "Favor elegir un valor correcto del Menu" << endl;

}
