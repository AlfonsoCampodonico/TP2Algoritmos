//
// Created by alfon on 12/9/2020.
//
#include "JuegoDeLaVida.h"
#include "Celula.h"
#include "Informes.h"
// /mnt/c/Users/alfon/Documents/GithubFIUBA/TP2Algoritmos/prueba
using namespace std;

JuegoDeLaVida::JuegoDeLaVida(){
    unsigned  int fila, columna;
    //this->elTablero = new Tablero();
    this->consola = new InterfazUsuario();
    this-> informes = new Informes();
}

void JuegoDeLaVida::jugar(){

    this->consola->enviarMensajeInicioJuego();
    ifstream archivoInicial;
    ingresarRutaDelArchivo(archivoInicial);
    procesarArchivo(archivoInicial);
    Informes* informe = (this->informes);
    Tablero* tablero = (this-> elTablero);
    while(){
    	int turno = 0;
    	cout << "1-Jugar un turno.." << endl;
    	cout << "2- Reiniciar turno" << endl;
    	cout << "3- Finalizar juego." << endl;
    	cout << "Ingrese la opcion correcta: " << endl;
    	cin >> turno;

    	if (turno == 1){
    		informe->resetearMuertesTurno();
    		informe->resetearNacimientosTurno();
    		informe->resetearVivas();
    		informe->sumarTurno();
    		tablero-> contarVecinasVivas();
    		tablero-> analizarCondicion(informe);


    	}
    }

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
