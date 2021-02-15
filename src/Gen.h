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

    /*Constructor de un Gen, crea un Gen con una lista de intensadidades vacia
     * y una informacion genetica que contiene una cadena de caracteres de bits

     */
    Gen();

    /* PRE: A partir de datos cargados desde un archivo, recibe una cadenaDeBits
     * y una cargaGenetica
     * POST: Crea un Gen con Informacion Genetica y Carga Genetica
     */
    Gen(std::string cadenaDeBits, unsigned int cargaGenetica);

    /* PRE: -.
     * POST: Devuelve a edad del Gen
     */
    unsigned int ObtenerEdadGen();

    /* PRE: -.
     * POST: Le suma 1 a la edad del Gen
     */
    void anadirEdadGen();

    /* PRE: -.
     * POST: Devuelve la Informacion Genetica de un Gen
     */
    InformacionGenetica * obtenerInformacioGeneticaDelGen();


    /* PRE: -.
     * POST: Devvuelve la lista de Intensidades de un Gen
     * a la hora de la transferencia
     */
    Lista<Intensidad *> *obtenerIntensidades();

    /* PRE: -.
     * POST: Devuelve la Intensidad de un Gen
     */
    Intensidad *obtenerIntensidad();

    /* PRE: -.
     * POST: Libera los recursos tomados por el Gen
     */
    ~Gen();


    /* PRE: -.
     * POST: Libera los recursos tomados en la lista de intensidad que posee el gen
     */
    void liberarIntensidades();

    /* PRE: Tiene que estar vivo el gen
     * POST: Agrega una intensidad a la lista de intensidad
     */
    void agregarIntensidad(unsigned int cargaGenetica);

    /* PRE:
     * POST:
     */
    unsigned int obtenerValorIntensidad();

    /* PRE:
     * POST:
     */
    unsigned int obtenerValorIntensidadPrincipal();

    /* PRE:
     * POST:
     */
    void cambiarIntensidadPrincipal(unsigned int intensidadNueva);
};
#endif //TP2ALGORITMOS_GEN_H
