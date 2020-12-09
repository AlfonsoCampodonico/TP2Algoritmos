//
// Created by alfon on 12/9/2020.
//

#include "JuegoDeLaVida.h"

using namespace std;

JuegoDeLaVida::JuegoDeLaVida(){
    unsigned  int fila, columna;
    this->elTablero = new Tablero(fila,columna);
    this->consola = new InterfazUsuario;
}

void JuegoDeLaVida::jugar(){
    this->consola->enviarMensajeInicioJuego();
    ifstream archivoInicial;
    ingresarRutaDelArchivo(archivoInicial);
    procesarArchivo(archivoInicial);
    
}

void JuegoDeLaVida::ingresarRutaDelArchivo(ifstream& archivo){
    string nombreArchivo;
    bool salirDelBucle = false;
    do
    {
        this->consola->pedirRutaDeUnArchivo();
        cin >> nombreArchivo;
        cin.ignore(256,'\n');

        archivo.open(nombreArchivo.c_str());

        salirDelBucle = archivo.is_open();
        if(!salirDelBucle)
        {
            this->consola-> mostrarArchivoInexistente();
        }

    }while(salirDelBucle == false);
}

void JuegoDeLaVida::procesarArchivo(std::ifstream& nombreArchivo){
    string tipoDeCarga;
    while(!nombreArchivo.eof()){
        nombreArchivo >> tipoDeCarga;

        if(tipoDeCarga.compare("Tablero") == 0){
            crearTablero(nombreArchivo);
        }
        if(tipoDeCarga.compare("Celula") == 0){
            agregarCelula(nombreArchivo);
        }

    }
    nombreArchivo.close();
}

void JuegoDeLaVida::crearTablero(ifstream& archivo){

    unsigned int ancho, alto;
    archivo >> ancho;
    archivo >> alto;
    Tablero* nuevoTablero;
    nuevoTablero = new Tablero(ancho, alto);
    this->elTablero = nuevoTablero;
}

void JuegoDeLaVida::agregarCelula(ifstream& archivo){
    unsigned int posicionX, posicionY,informacionGenetica,intensidad;
    Tablero* unTablero = this->elTablero;

    archivo  >> posicionX;
    archivo  >> posicionY;




}
