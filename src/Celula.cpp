
#include "Celula.h"



Celula::Celula() {
    this-> condicion = MUERTA;
    this-> genes = new Lista<Gen*>();
}

void Celula::setearGen(std::string informacionGenetica, unsigned int intensidad) {
    Gen* unGen = new Gen(informacionGenetica, intensidad);
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


void Celula::completarTransferencia(){
    Lista<Gen*>* listaGenes = this->genes;
    Lista<Gen*>* nuevaLista = new Lista<Gen*>();
    listaGenes->iniciarCursor();

    while (listaGenes->avanzarCursor()) {

        Gen* genActual = listaGenes->obtenerCursor();
        bool esIgual = false;

        if (nuevaLista->estaVacia() ){
            nuevaLista->agregar(genActual);
        }
        else {
            nuevaLista->iniciarCursor();
            unsigned int tamanoLista = nuevaLista->contarElementos();
            unsigned int recorrido = 0;
            unsigned int verificar = 0;
            while (nuevaLista->avanzarCursor()
                                        && (recorrido<tamanoLista)) {
                Gen *genNuevo = nuevaLista->obtenerCursor();
                esIgual = genActual->obtenerInformacioGeneticaDelGen()
                                ->esIgualA(genNuevo->obtenerInformacioGeneticaDelGen());
                recorrido++;
                if(esIgual){
                    genNuevo->agregarIntensidad(genActual->obtenerValorIntensidad());
                }
                else{
                    verificar++;
                }
                if (verificar == tamanoLista){
                    nuevaLista->agregar(genActual);
                }
            }
        }

    }
    delete listaGenes;
    this->genes = nuevaLista;

}

void Celula::calcularIntensidad(Informes* informes){
    Lista<Gen*>* listaGenes = this->genes;
    listaGenes->iniciarCursor();
    unsigned int cantidadTurnos = informes->obtenerTurnos();

    //Recorro la lista de genes que tiene la celula
    while (listaGenes->avanzarCursor()) {

        //Obtengo un Gen para analizar
        Gen *genActual = listaGenes->obtenerCursor();
        Lista<Intensidad*>* listaIntensidades = genActual->obtenerIntensidades();
        unsigned  int cantidadDeCargas= listaIntensidades->contarElementos();

        //Si La cantidad es 3 pasa a la funcion de 3 cargas
        if (cantidadDeCargas == 3){

            casoTresActiva(listaIntensidades,genActual,cantidadTurnos);

        }
        else if(cantidadDeCargas == 2){

            casoDosActiva(listaIntensidades,genActual,cantidadTurnos);
        }

        else{
            genActual->cambiarIntensidadPrincipal(0);
        }

    }
}

void Celula::casoTresActiva(Lista<Intensidad*>* listaIntensidades, Gen* genActual,unsigned int turnos){
    Intensidad* cargaUno = listaIntensidades->obtener(1);
    Intensidad* cargaDos = listaIntensidades->obtener(2);
    Intensidad* cargaTres = listaIntensidades->obtener(3);


    if (cargaUno->estaActiva() || cargaDos->estaActiva() || cargaTres->estaActiva()){

        if ((cargaDos->obtenerCantidadIntensidad() >= cargaUno->obtenerCantidadIntensidad())
            && (cargaDos->obtenerCantidadIntensidad() >= cargaTres->obtenerCantidadIntensidad())){

            genActual->cambiarIntensidadPrincipal(cargaDos->obtenerCantidadIntensidad());

        }
        else{
            genActual->cambiarIntensidadPrincipal(cargaTres->obtenerCantidadIntensidad());
        }
    }
    else{
        unsigned int edadGen = genActual->ObtenerEdadGen();
        unsigned int nuevaIntensidad = ((edadGen/turnos)* 100) +1;
        genActual->cambiarIntensidadPrincipal(nuevaIntensidad);

}}

void Celula::casoDosActiva(Lista<Intensidad*>* listaIntensidades, Gen* genActual,unsigned int turnos){
    Intensidad* cargaUno = listaIntensidades->obtener(1);
    Intensidad* cargaDos = listaIntensidades->obtener(2);
    if (cargaUno->estaActiva() && cargaDos->estaActiva()){
        unsigned int cantidadIntensidadUno = cargaUno->obtenerCantidadIntensidad();
        unsigned int cantidadIntensidadDos = cargaDos->obtenerCantidadIntensidad();
        unsigned int promedio = (cantidadIntensidadUno+cantidadIntensidadDos) /2;
        genActual->cambiarIntensidadPrincipal(promedio);
    }
    else if(cargaUno->estaActiva()){
        genActual->cambiarIntensidadPrincipal(cargaUno->obtenerCantidadIntensidad());
    }
    else if (cargaDos->estaActiva()){
        genActual->cambiarIntensidadPrincipal(cargaDos->obtenerCantidadIntensidad());
    }
    else{
        unsigned int edadGen = genActual->ObtenerEdadGen();
        unsigned int nuevaIntensidad = ((edadGen/turnos)* 100) +1;
        genActual->cambiarIntensidadPrincipal(nuevaIntensidad);
    }

}



void Celula::generarMutacion(){
    Lista<Gen*>* listaGenes = this->genes;
    listaGenes->iniciarCursor();
    Lista<Gen*>* listaParaMezclar = new Lista<Gen*>();
    while (listaGenes->avanzarCursor()) {
        Gen *genActual = listaGenes->obtenerCursor();
        if ( genActual->obtenerValorIntensidadPrincipal() == 0){

            std::string cadenaDeBits = genActual->obtenerInformacioGeneticaDelGen()->devolverCadena();
            Gen *genNuevoParaMezclar = new Gen(cadenaDeBits,genActual->obtenerValorIntensidadPrincipal());
            listaParaMezclar->agregar(genNuevoParaMezclar);
        }
    }
    if (listaParaMezclar->contarElementos() > 1){
        listaParaMezclar->iniciarCursor();listaParaMezclar->avanzarCursor();
        Gen* primerGen = listaParaMezclar->obtenerCursor();
        std::string cadenaDeBits = primerGen->obtenerInformacioGeneticaDelGen()->devolverCadena();
        Gen *genNuevo = new Gen(cadenaDeBits,primerGen->obtenerValorIntensidadPrincipal());

        while (listaParaMezclar->avanzarCursor()){
            Gen* GenSiguiente =listaParaMezclar->obtenerCursor();
            genNuevo->obtenerInformacioGeneticaDelGen()
                    ->combinarCon(GenSiguiente->obtenerInformacioGeneticaDelGen());


        }
        listaGenes->agregar(genNuevo);
    }

    while(!listaParaMezclar->estaVacia()){
            Gen* unGen;
            unGen = listaParaMezclar->obtener(1);
            listaParaMezclar->remover(1);
            delete unGen;
        }
    delete listaParaMezclar;

}

void Celula::liberarGenes() {
    while(!this->genes->estaVacia()){
        Gen* unGen;
        unGen = this->genes->obtener(1);
        this->genes->remover(1);
        delete unGen;

    }
}

Celula::~Celula(){
    //liberarGenes();
    delete this->genes;

}
