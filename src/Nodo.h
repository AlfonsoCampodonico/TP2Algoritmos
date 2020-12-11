//
// Created by alfon on 12/10/2020.
//
#ifndef NULL
#define  NULL 0
#endif
#ifndef TP2ALGORITMOS_NODO_H
#define TP2ALGORITMOS_NODO_H
template<class T> class Nodo {
private:

    T valor;
    Nodo<T>* siguiente;

public:
    /*
     * POST: el Nodo resulta inicializado con el valor dado y sin un Nodo siguiente.
     */
    Nodo(T valor) {

        this->valor = valor;
        this->siguiente = NULL;
    }

    /*
     * POST: devuelve el valor del valor.
     */
    T obtenerDato() {
        return this->valor;
    }

    /*
     * POST: cambia el valor del valor.
     */
    void cambiarDato(T nuevoDato) {
        this->valor = nuevoDato;
    }

    /*
     * POST: devuelve el siguiente Nodo.
     */
    Nodo<T>* obtenerSiguiente() {
        return this->siguiente;
    }

    /*
     * POST: cambia el siguiente Nodo por nuevoSiguiente.
     */
    void cambiarSiguiente(Nodo<T>* nuevoSiguiente) {
        this->siguiente = nuevoSiguiente;
    }
};

#endif //TP2ALGORITMOS_NODO_H
