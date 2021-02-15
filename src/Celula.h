//
// Created by alfon on 12/7/2020.
//

#ifndef TP2ALGORITMOS_CELULA_H
#define TP2ALGORITMOS_CELULA_H

#include "Gen.h"
#include "Lista.h"
#include "Informes.h"
#include "Colores.h"
class Informes;

enum EstadoDeLaCelula {
    MUERTA,
    VIVA,
    CASIMUERTA,
    CASIVIVA
};

/* Unidad basica que compone un organismo.
 * Su condicion esta representada por un tipo de valor enumerado que puede variar entre:
 * 	 MUERTA: una celula sin vida.
 *	 VIVA: una celula con vida.
 *	 CASIMUERTA: esta proxima a morir.
 *	 CASI VIVA: esta proxima a vivir.
 * La celula ademas posee colores, ya sea negra para muerte, o azul para viva.
 */
class Celula{

private:
    EstadoDeLaCelula condicion;
    Lista<Gen*>* genes;
    Colores* color;

public:
    /*Constructor de la Celula
     *
     *
     */
    Celula();

    /* Pre: Que el estado de la celula este muerta
     * Post: La celula pasa a estar viva.
     */
    void revivirCelula();

    /* PRE: Que el estado de la celula este viva.
     * POST: La celula pasa a estar muerta.
     */
    void matarCelula();

    /* PRE: -.
     * POST: Indica si la celula esta muerta.
     */
    bool estaMuerta();

    /* PRE: -.
     * POST: Indica si la celula esta viva.
     */
    bool estaViva();


    /* PRE: cadena de caracteres de informacionGenetica la cual se introduce desde un archivo
     * y un entero de intensidad. Tambien la celula necesita de estar viva para tener un gen.
     * POST: Modifica el gen de una celula para asignarle su informacion genetica y intensidad.
     */
    void setearGen(std::string informacionGenetica, unsigned int intensidad);


    /* PRE: -.
     * POST: Cambia el estado de la celula a CASIVIVA
     */
    void vaAVivir();

    /* PRE: -.
     * POST: Cambia el estado de la celula a CASIMUERTA
     */
    void vaAMorir();

    /* PRE: -.
     * POST: Indica si la celula esta casi viva.
     */
    bool estaCasiViva();

    /* PRE: -.
     * POST: Indica si la celula esta casi muerta.
     */
    bool estaCasiMuerta();

    /* PRE: -.
     * POST: Devuelve la lista de Genes que puede tener una celula
     */
    Lista<Gen *> *obtenerListaGen();

    /* PRE: -.
     * POST: Libera la memoria pedida.
     */
    ~Celula();

    /* PRE: -.
     * POST: Vuelve unico a la informacion genetica de los genes al momento de nacer la celula
     */
    void completarTransferencia();

    /* PRE: -.
     * POST: Calcula la intensidad de los nuevos genes de las celulas padres
     */
    void calcularIntensidad(Informes* informes);


    /* PRE: -.
     * POST: Libera los recursos pedidos por la lista de Genes
     */
    void liberarGenes();

    /* PRE:
     * POST:
     */
    void casoTresActiva(Lista<Intensidad *> *listaIntensidades, Gen *genActual, unsigned int turnos);

    /* PRE:
     * POST:
     */
    void casoDosActiva(Lista<Intensidad *> *listaIntensidades, Gen *genActual, unsigned int turnos);

    /* PRE: -.
     * POST: Genera la mutacion de celulas en base a las celulas que no tienen carga genetica activa.
     */
    void generarMutacion();

    /* PRE:
     * POST:
     */
    Colores *obtenerColor();
};


#endif //TP2ALGORITMOS_CELULA_H
