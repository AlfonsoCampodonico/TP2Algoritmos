//
// Created by alfon on 12/9/2020.
//
#include "JuegoDeLaVida.h"
#include "Celula.h"
#include "Informes.h"
// /mnt/c/Users/alfon/Documents/GithubFIUBA/TP2Algoritmos/prueba
using namespace std;

JuegoDeLaVida::JuegoDeLaVida(){
    this->elTablero = new Tablero(0,0);
    this->consola = new InterfazUsuario();
    this-> informes = new Informes();
}

void JuegoDeLaVida::jugarElJuegoDeLaVida(){

    this->consola->enviarMensajeInicioJuego();
    ifstream archivoInicial;
    ingresarRutaDelArchivo(archivoInicial);
    procesarArchivo(archivoInicial);
    bool terminaElJuegoDeLaVida{};
    do{
        comenzarElJuegoDeLaVida(terminaElJuegoDeLaVida);
    }while(!terminaElJuegoDeLaVida);
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

        if(tipoDeCarga.compare("tablero") == 0){
            crearTablero(nombreArchivo);
        }
        if(tipoDeCarga.compare("celula") == 0){
            agregarCelula(nombreArchivo);
        }

    }
    nombreArchivo.close();
}

void JuegoDeLaVida::crearTablero(ifstream& archivo){

    unsigned int ancho{}, alto{};
    archivo >> ancho;
    archivo >> alto;
    Tablero* nuevoTablero;
    nuevoTablero = new Tablero(ancho, alto);
    delete this->elTablero;
    this->elTablero = nuevoTablero;
}

void JuegoDeLaVida::agregarCelula(ifstream& archivo){
    unsigned int posicionX{}, posicionY{};
    std::string ejecucion{};
    Tablero* unTablero = this->elTablero;
    Celula* laCelula;

    archivo  >> posicionX;
    archivo  >> posicionY;

    laCelula = unTablero->obtenerPosicionCelula(posicionX,posicionY);
    laCelula ->revivirCelula();

    while(!ejecucion.compare("fin")==0){
        archivo >> ejecucion;

        if(ejecucion.compare("gen") == 0){
            anadirGen(archivo,laCelula);
        }
    }
}

void JuegoDeLaVida::anadirGen(ifstream& archivo,Celula* celula){
    std::string informacionGenetica{};
    unsigned int intensidad{};

    archivo  >> informacionGenetica;
    archivo  >> intensidad;

    celula->setearGen(informacionGenetica, intensidad);


}

void JuegoDeLaVida::comenzarElJuegoDeLaVida(bool &terminaElJuegoDeLaVida){
    bool reiniciarElJuegoDeLaVida {};
    do{
        unsigned int numeroUsuario = elegirUnaAccionDelMenuDeJuego();
        reiniciarElJuegoDeLaVida = (numeroUsuario == 2);
        terminaElJuegoDeLaVida = (numeroUsuario == 3);
        realizarAccionElegida(numeroUsuario);
    }while((!terminaElJuegoDeLaVida) && (!reiniciarElJuegoDeLaVida));
}


unsigned int JuegoDeLaVida::elegirUnaAccionDelMenuDeJuego(){
    unsigned int valorIngresado;
    bool esUnValorValido = false;
    do{
        this->consola->mostrarMenuDeJuegoDeLaVida();
        cin >> valorIngresado;
        esUnValorValido = !((valorIngresado <= 0) || (valorIngresado > 3));
        if(!esUnValorValido){
            this->consola->mostrarQueNoEsUnNumeroValido();
        }
    }while(!esUnValorValido);
    return valorIngresado;
}

void JuegoDeLaVida::realizarAccionElegida(unsigned int numeroElegido){
    switch(numeroElegido){
        case 1:
            if(!this->informes->estaCongelado()){
                ejecutarTurno();
            }
            else{
                this->consola->mostrarCongelado();
            }
            break;
        case 2:
            reiniciarElJuegoDeLaVida();
            break;
        case 3:
            this->consola->mostrarFinDelJuegoDeLaVida();
            break;
    }
}

void JuegoDeLaVida::ejecutarTurno(){

    this->informes->resetearInformeTurno();
    this->elTablero->dictarVida(this->informes);
    this->elTablero->actualizarUnTablero(this->informes);
    this->informes->actualizarInformeTurno(this->elTablero);
    this->consola->mostrarInformeDelJuego(this->informes);
}

void JuegoDeLaVida::reiniciarElJuegoDeLaVida(){
    delete this->elTablero;
    this->informes->reiniciarInforme();
    ifstream nuevoArchivoInicial;
    ingresarRutaDelArchivo(nuevoArchivoInicial);
    procesarArchivo(nuevoArchivoInicial);
}



JuegoDeLaVida::~JuegoDeLaVida(){
    delete this->informes;
    delete this->consola;
    delete this->elTablero;
}