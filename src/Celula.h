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

    /* PRE:Recibe una lista de intensidades para completar la transferencia de genes, en caso de que los 3 genes
     * esten activos, tambien recibe la cantidad de turnos y el gen actual que se esta transfiriendo
     * POST:Modifica la intensidad del gen si las tres células vecinas tienen
     * el mismo gen depeendiendo de la carga genetica de esos genes,el máximo
     * de las cargas genéticas de esos genes, si al menos una delas cargas está activada, o
     * el promedio de turnos que ese gen tiene de vida más uno, en caso de
     * que todas las cargas estén desactivadas (edad del gen / cantidad de turnos * 100 + 1).
     */
    void casoTresActiva(Lista<Intensidad *> *listaIntensidades, Gen *genActual, unsigned int turnos);

    /* PRE:Recibe una lista de intensidades para completar la transferencia de genes, en caso de que dos genes
     * esten activos, tambien recibe la cantidad de turnos y el gen actual que se esta transfiriendo
     * POST:Dependiendo cuantas esten activas usa ,el promedio de las cargas genéticas de esos genes, si ambas cargas
     * genéticas están activadas, la carga genética de aquella célula que la tenga activada, o
     * el promedio de turnos que ese gen tiene de vida más uno, en caso de
     * que ambas cargas están desactivadas (edad del gen / cantidad de turnos * 100 + 1).
     */
    void casoDosActiva(Lista<Intensidad *> *listaIntensidades, Gen *genActual, unsigned int turnos);

    /* PRE: -.
     * POST: Genera la mutacion de celulas en base a las celulas que no tienen carga genetica activa.
     */
    void generarMutacion();

    /* PRE:
     * POST: Obtiene el color de una celula
     */
    Colores *obtenerColor();
};


#endif //TP2ALGORITMOS_CELULA_H
