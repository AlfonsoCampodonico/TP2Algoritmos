//
// Created by alfon on 12/10/2020.
//

#ifndef TP2ALGORITMOS_LISTA_H
#define TP2ALGORITMOS_LISTA_H
#include "Nodo.h"

/*
 * Una Lista es una colección dinámica de elementos dispuestos en una secuencia.
 *
 * Define operaciones para agregar, remover, acceder y cambiar elementos
 * en cualquier posición.
 *
 * Tiene un cursor que permite recorrer todos los elementos secuencialmente.
 *
 */
template<class T> class Lista {

private:

    Nodo<T>* primer;

    unsigned int tamano;

    Nodo<T>* cursor;

public:

    /*
     * post: Lista vacía.
     */
    Lista();

    /*
     * post: Lista que tiene los mismos elementos que otraLista.
     *       La instancia resulta en una copia de otraLista.
     */
    Lista(Lista<T>& otraLista);

    /*
     * post: indica si la Lista tiene algún elemento.
     */
    bool estaVacia();

    /*
     * post: devuelve la cantidad de elementos que tiene la Lista.
     */
    unsigned int contarElementos();

    /*
     * post: agrega el elemento al final de la Lista, en la posición:
     *       contarElementos() + 1.
     */
    void agregar(T elemento);

    /*
     * pre : posición pertenece al intervalo: [1, contarElementos() + 1]
     * post: agrega el elemento en la posición indicada.
     *
     */
    void agregar(T elemento, unsigned int posicion);

    /*
     * post: agrega todos los elementos de otraLista
     *       a partir de la posición contarElementos() + 1.
     */
    void agregar(Lista<T> &otraLista);

    /*
     * pre : posición pertenece al intervalo: [1, contarElementos()]
     * post: devuelve el elemento en la posición indicada.
     */
    T obtener(unsigned int posicion);

    /*
     * pre : posicioó pertenece al intervalo: [1, contarElementos()]
     * post: cambia el elemento en la posición indicada por el
     *       elemento dado.
     */
    void asignar(T elemento, unsigned int posicion);

    /*
     * pre : posición pertenece al intervalo: [1, contarElementos()]
     * post: remueve de la Lista el elemento en la posición indicada.
     */
    void remover(unsigned int posicion);

    /*
     * post: deja el cursor de la Lista preparado para hacer un nuevo
     *       recorrido sobre sus elementos.
     */
    void iniciarCursor();

    /*
     * pre : se ha iniciado un recorrido (invocando el método
     *       iniciarCursor()) y desde entonces no se han agregado o
     *       removido elementos de la Lista.
     * post: mueve el cursor y lo posiciona en el siguiente elemento
     *       del recorrido.
     *       El valor de retorno indica si el cursor quedó posicionado
     *       sobre un elemento o no (en caso de que la Lista esté vacía o
     *       no existan más elementos por recorrer.)
     */
    bool avanzarCursor();

    /*
     * pre : el cursor está posicionado sobre un elemento de la Lista,
     *       (fue invocado el método avanzarCursor() y devolvió true)
     * post: devuelve el elemento en la posición del cursor.
     *
     */
    T obtenerCursor();

    /*
     * post: libera los recursos asociados a la Lista.
     */
    ~Lista();

private:

    /*
     * pre : posición pertenece al intervalo: [1, contarElementos()]
     * post: devuelve el nodo en la posición indicada.
     */
    Nodo<T>* obtenerNodo(unsigned int posicion); // NOTA: primitiva PRIVADA
};

template<class T> Lista<T>::Lista() {

    this->primer = NULL;
    this->tamano = 0;
    this->cursor = NULL;
}

template<class T> Lista<T>::Lista(Lista<T>& otraLista) {

    this->primer = NULL;
    this->tamano = 0;
    this->cursor = NULL;

    /* copia los elementos de otraLista */
    this->agregar(otraLista);
}

template<class T> bool Lista<T>::estaVacia() {

    return (this->tamano == 0);
}

template<class T> unsigned int Lista<T>::contarElementos() {

    return this->tamano;
}

template<class T> void Lista<T>::agregar(T elemento) {

    this->agregar(elemento, this->tamano + 1);
}

template<class T> void Lista<T>::agregar(T elemento, unsigned int posicion) {

    if ((posicion > 0) && (posicion <= this->tamano + 1)) {

        Nodo<T>* nuevo = new Nodo<T>(elemento);

        if (posicion == 1) {

            nuevo->cambiarSiguiente(this->primer);
            this->primer = nuevo;

        } else {

            Nodo<T>* anterior = this->obtenerNodo(posicion - 1);
            nuevo->cambiarSiguiente(anterior->obtenerSiguiente());
            anterior->cambiarSiguiente(nuevo);
        }

        this->tamano++;

        /* cualquier recorrido actual queda invalidado */
        this->iniciarCursor();
    }

}

template<class T> void Lista<T>::agregar(Lista<T> &otraLista) {

    otraLista.iniciarCursor();
    while (otraLista.avanzarCursor()) {
        this->agregar(otraLista.obtenerCursor());
    }
}

template<class T> T Lista<T>::obtener(unsigned int posicion) {

    T elemento;

    if ((posicion > 0) && (posicion <= this->tamano)) {

        elemento = this->obtenerNodo(posicion)->obtenerDato();
    }

    return elemento;
}

template<class T> void Lista<T>::asignar(T elemento, unsigned int posicion) {

    if ((posicion > 0) && (posicion <= this->tamano)) {

        this->obtenerNodo(posicion)->cambiarDato(elemento);
    }
}

template<class T> void Lista<T>::remover(unsigned int posicion) {

    if ((posicion > 0) && (posicion <= this->tamano)) {

        Nodo<T>* removido;

        if (posicion == 1) {

            removido = this->primer;
            this->primer = removido->obtenerSiguiente();

        } else {

            Nodo<T>* anterior = this->obtenerNodo(posicion - 1);
            removido = anterior->obtenerSiguiente();
            anterior->cambiarSiguiente(removido->obtenerSiguiente());
        }

        delete removido;
        this->tamano--;

        /* cualquier recorrido actual queda invalidado */
        this->iniciarCursor();
    }
}

template<class T> void Lista<T>::iniciarCursor() {

    this->cursor = NULL;
}

template<class T> bool Lista<T>::avanzarCursor() {

    if (this->cursor == NULL) {

        this->cursor = this->primer;

    } else {

        this->cursor = this->cursor->obtenerSiguiente();
    }

    /* pudo avanzar si el cursor ahora apunta a un nodo */
    return (this->cursor != NULL);
}

template<class T> T Lista<T>::obtenerCursor() {

    T elemento;

    if (this->cursor != NULL) {

        elemento = this->cursor->obtenerDato();
    }

    return elemento;
}

template<class T> Lista<T>::~Lista() {
    while (!estaVacia()) {
        remover(1);
    }
}

template<class T> Nodo<T>* Lista<T>::obtenerNodo(unsigned int posicion) {

    Nodo<T>* actual = this->primer;
    for (unsigned int i = 1; i < posicion; i++) {

        actual = actual->obtenerSiguiente();
    }

    return actual;
}
#endif //TP2ALGORITMOS_LISTA_H
