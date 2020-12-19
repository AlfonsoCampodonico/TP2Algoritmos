
#include "Celula.h"
#include "Tablero.h"
#include "InformacionGenetica.h"


Celula::Celula() {
    this-> condicion = MUERTA;
    this-> genes = new Lista<Gen*>();
}

void Celula::setearGen(std::string informacionGenetica, unsigned int intensidad) {
    Gen* unGen;
    unGen = new Gen(informacionGenetica, intensidad);
    this->genes->agregar(unGen);
}

void Celula::revivirCelula(){
    this->condicion = VIVA;
}
bool Celula::estaViva(){
    return (this->condicion == VIVA);
}
void Celula::matarCelula(){
    this->condicion = MUERTA;
    liberarGenes();
}
bool Celula::estaMuerta(){
    return (this->condicion == MUERTA);
}
void Celula::vaAMorir(){
    this->condicion = CASIMUERTA;
}
bool Celula::estaCasiMuerta(){
    return (this->condicion == CASIMUERTA);
}

void Celula::vaAVivir(){
    this->condicion = CASIVIVA;
}

bool Celula::estaCasiViva(){
    return (this->condicion == CASIVIVA);
}

Lista<Gen*>* Celula::obtenerListaGen(){
    return this->genes;
}

void Celula::liberarGenes(){
    while(!this->genes->estaVacia()){
        Gen* unGen = this->genes->obtener(1);
        this->genes->remover(1);
        delete unGen;
    }
}

void Celula::completarTransferencia(){
    Lista<Gen*>* listaGenes = this->genes;
    Lista<Gen*>* nuevaLista = new Lista<Gen*>();
    bool esIgual{};
    listaGenes->iniciarCursor();

    while (listaGenes->avanzarCursor()) {

        Gen* genActual = listaGenes->obtenerCursor();
        bool esIgual{};
        if (nuevaLista->estaVacia() ){
            nuevaLista->agregar(genActual);
        }
        else {
            nuevaLista->iniciarCursor();
            unsigned int tamanoLista = nuevaLista->contarElementos();
            unsigned int recorrido = 0;
            while (nuevaLista->avanzarCursor() && (recorrido<tamanoLista) ) {
                Gen *genNuevo = nuevaLista->obtenerCursor();
                esIgual = genActual->obtenerInformacioGeneticaDelGen()
                                ->esIgualA(genNuevo->obtenerInformacioGeneticaDelGen());
                if(esIgual){
                    //genNuevo
                    recorrido++;
                }
                else{
                 nuevaLista->agregar(genActual);
                 recorrido++;

                }
            }

        }

    }

}

Celula::~Celula(){

    delete[] this->genes;

}
