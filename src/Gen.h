//
// Created by alfon on 12/11/2020.
//

#ifndef TP2ALGORITMOS_GEN_H
#define TP2ALGORITMOS_GEN_H

#include "InformacionGenetica.h"
#include "Intensidad.h"
#include "Lista.h"
class Gen{
private:
    unsigned  int edad;
    InformacionGenetica* informacionGenetica;
    Lista<Intensidad*>* intensidades;
    unsigned int intensidad;
public:

    /* Pre: -
     * Post:
     */
    Gen();

    /* Pre:
     * Post:
     */
    Gen(std::string cadenaDeBits, unsigned int cargaGenetica);

    /* Pre: -
     * Post:
     */
    unsigned int ObtenerEdadGen();

    /* Pre: -
     * Post:
     */
    void anadirEdadGen();

    InformacionGenetica * obtenerInformacioGeneticaDelGen();

    bool estaActivoElGen();

    ~Gen();

    Lista<Intensidad *> *obtenerIntensidades();

    Intensidad *obtenerIntensidad();
};
#endif //TP2ALGORITMOS_GEN_H
