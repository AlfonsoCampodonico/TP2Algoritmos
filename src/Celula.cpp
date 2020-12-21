
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
        bool esIgual{};

        if (nuevaLista->estaVacia() ){
            nuevaLista->agregar(genActual);
        }
        else {
            nuevaLista->iniciarCursor();
            unsigned int tamanoLista = nuevaLista->contarElementos();
            unsigned int recorrido = 0;
            unsigned int verificar = 0;
            while (nuevaLista->avanzarCursor()
                                        && (recorrido<tamanoLista)
                                        && (!esIgual)) {
                Gen *genNuevo = nuevaLista->obtenerCursor();
                esIgual = genActual->obtenerInformacioGeneticaDelGen()
                                ->esIgualA(genNuevo->obtenerInformacioGeneticaDelGen());
                Lista<Intensidad*>* listaIntensidades = genNuevo->obtenerIntensidades();
                if(esIgual){
                    Intensidad * intensidadActual = genActual->obtenerIntensidad();

                    listaIntensidades->agregar(intensidadActual);

                }
                else{
                    verificar++;
                }
                recorrido++;
                if (verificar == tamanoLista){
                    nuevaLista->agregar(genActual);
                }

            }




        }

    }
    delete this->genes;
    this->genes = nuevaLista;

}

void Celula::calcularIntensidad(Informes* informes){
    Lista<Gen*>* listaGenes = this->genes;
    listaGenes->iniciarCursor();

    while (listaGenes->avanzarCursor()) {

        Gen *genActual = listaGenes->obtenerCursor();
        Lista<Intensidad*>* listaIntensidades = genActual->obtenerIntensidades();
        unsigned  int cantidadDeCargas= listaIntensidades->contarElementos();
        if (cantidadDeCargas == 3){
            Intensidad* cargaUno = listaIntensidades->obtener(1);
            Intensidad* cargaDos = listaIntensidades->obtener(2);
            Intensidad* cargaTres = listaIntensidades->obtener(3);

            if (cargaUno->estaActiva() || cargaDos->estaActiva() || cargaTres->estaActiva()){

                if ((cargaDos->obtenerCantidadIntensidad() >= cargaUno->obtenerCantidadIntensidad())
                && (cargaDos->obtenerCantidadIntensidad() >= cargaTres->obtenerCantidadIntensidad())){
                    listaIntensidades->asignar(cargaDos,1);
                }
                else{
                    listaIntensidades->asignar(cargaTres,1);
                }

                listaIntensidades->remover(2); listaIntensidades->remover(3);

            }
            else{

                unsigned  int turnos = informes->obtenerTurnos();
                unsigned int edadGen = genActual->ObtenerEdadGen();
                unsigned int nuevaIntensidad = ((edadGen/turnos )* 100) +1;
                cargaUno->cambiarIntensidad(nuevaIntensidad);
                listaIntensidades->remover(2); listaIntensidades->remover(3);
            }

        }
        else if(cantidadDeCargas == 2){
            Intensidad* cargaUno = listaIntensidades->obtener(1);
            Intensidad* cargaDos = listaIntensidades->obtener(2);
            if (cargaUno->estaActiva() && cargaDos->estaActiva()){
                unsigned int cantidadIntensidadUno = cargaUno->obtenerCantidadIntensidad();
                unsigned int cantidadIntensidadDos = cargaDos->obtenerCantidadIntensidad();
                unsigned int promedio = (cantidadIntensidadUno+cantidadIntensidadDos) /2;
                cargaUno->cambiarIntensidad(promedio);
            }
            else if(cargaDos->estaActiva()){
                cargaUno->cambiarIntensidad(cargaDos->obtenerCantidadIntensidad());
            }
            else{
                unsigned  int turnos = informes->obtenerTurnos();
                unsigned int edadGen = genActual->ObtenerEdadGen();
                unsigned int nuevaIntensidad = ((edadGen/turnos )* 100) +1;
                cargaUno->cambiarIntensidad(nuevaIntensidad);
            }
            listaIntensidades->remover(2);
        }
        else{
            Intensidad* carga = listaIntensidades->obtener(1);
            carga->cambiarIntensidad(0);
        }

    }
}

void Celula::mutar(){
    Lista<Gen*>* listaGenes = this->genes;
    listaGenes->iniciarCursor();
    Gen* nuevoGen = new Gen();
    bool encontreUnoParaMutar{};
    while (listaGenes->avanzarCursor() && !encontreUnoParaMutar) {

        Gen *genActual = listaGenes->obtenerCursor();
        Intensidad* intensidadFinal = genActual->obtenerIntensidad();
        if(intensidadFinal == 0){
            std::string nuevaCadena = genActual->
                                        obtenerInformacioGeneticaDelGen()->
                                            devolverCadena();
            nuevoGen->
                obtenerInformacioGeneticaDelGen()->
                    cambiarInformacionGenetica(nuevaCadena);

            encontreUnoParaMutar = true;
            /*nuevoGen->obtenerInformacioGeneticaDelGen()
            ->combinarCon(genActual->obtenerInformacioGeneticaDelGen());*/
        }
    }
    listaGenes->iniciarCursor();
    while (listaGenes->avanzarCursor() ) {

        Gen *genActual = listaGenes->obtenerCursor();
        Intensidad *intensidadFinal = genActual->obtenerIntensidad();
        InformacionGenetica *informacionGeneticaFinal = genActual->
                obtenerInformacioGeneticaDelGen();
        if (intensidadFinal == 0
            && !informacionGeneticaFinal->
                esIgualA(nuevoGen->obtenerInformacioGeneticaDelGen())) {

            nuevoGen->obtenerInformacioGeneticaDelGen()
                    ->combinarCon(genActual->obtenerInformacioGeneticaDelGen());
        }
    }


    if(nuevoGen->obtenerInformacioGeneticaDelGen()->devolverCadena()!="0"){
        listaGenes->agregar(nuevoGen);
    }
    else{
        delete nuevoGen;
    }

}


Celula::~Celula(){

    delete this->genes;

}
