//
// Created by alfon on 12/7/2020.
//

#ifndef TP2ALGORITMOS_INFORMACIONGENETICA_H
#define TP2ALGORITMOS_INFORMACIONGENETICA_H

#include <string>

/* La Informacion Genetica está conformada por una secuencia de bits.
* Un bit es la mínima expresión de información, que puede tomar dos únicos valores posibles: 0/1,
* apagado/encendido o desactivado/activado.
*/
class InformacionGenetica {

private:
    std::string cadenaDeBits;
    unsigned int tamano;


public:
    /*
     * pre : 'bits' es una secuencia de 1 y 0.
     * post: la instancia creada representa la información dada en 'bits'.
     */
    InformacionGenetica(std::string bits);

    /* post: la instancia creada representa la información dada por un bit: 0.
     */
    InformacionGenetica();

    /* post : indica si la instancia y 'otra'
     * representan la misma secuencia de
     * bits, es decir si son iguales.
     */
    bool esIgualA(InformacionGenetica* otra);

    /* post: combina la secuencia de bits de la instancia con la secuencia bits de
     * 'otra', aplicando un XOR bit a bit.
     */
    void combinarCon(InformacionGenetica* otra);

    /* post: indica si el valor del 'i'-ésimo bit es 1, numerándolos de derecha a
     * izquierda a partir de 1.
     */
    bool estaEncendidoBit(unsigned int i);

    /* post: devuelve cantidad de bits que tiene
     * la instancia.
    */
     unsigned int contarBits();

    /* PRE: -.
    * POST: Devuelve la cadena de bits de la Informacion Genetica
    */
    std::string devolverCadena();

    /* PRE: Una cadena de bits nueva
     * POST: A partir de una nueva cadena de bits, reemplaza la anterior
     */
    void cambiarInformacionGenetica(std::string nuevaCadena);
};
#endif //TP2ALGORITMOS_INFORMACIONGENETICA_H
