#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

#include <cstddef>
#include "Nodo.h"
#include "Iterador.h"

/* DECLARACION DE LA CLASE */

template<class T>
class ListaDEnlazada {
private:
    Nodo<T> *cabecera, *cola;
    int tam;

public:

    /* CONSTRUCTORES */

    ListaDEnlazada();

    ListaDEnlazada(const ListaDEnlazada &orig);

    virtual ~ListaDEnlazada();

    /* OPERADORES */

    ListaDEnlazada<T> &operator=(const ListaDEnlazada<T> &l);

    bool operator<(const ListaDEnlazada<T> &right) const;

    bool operator==(const ListaDEnlazada<T> &right) const;

    ListaDEnlazada operator+(const ListaDEnlazada &listaDEnlazada) const;

    /* METODOS */

    Iterador<T> iterador() const; // iterador al inicio

    // metodos de insercion
    void insertarInicio(T &dato);

    void insertarFinal(T &dato);

    void inserta(Iterador<T> &i, T &dato);

    void insertaOrdenado(T &dato);

    // metodos de borrado
    void borraInicio();

    void borraFinal();

    void borra(Iterador<T> &i);

    bool buscar(const T &dato, Iterador<T> &i);

    T &inicio(); // dato en cabecera
    T &final(); // dato en cola

    ListaDEnlazada concatena(const ListaDEnlazada &listaDEnlazada) const;

    /* GETTER */

    int getTam() const;

};

/* IMPLEMENTACION DE LA CLASE */

/* CONSTRUCTORES */

template<class T>
ListaDEnlazada<T>::ListaDEnlazada() : cabecera(0), cola(0), tam(0) {
}

/**
 * @brief Constructor copia
 * @param l
 * @return
 */
template<class T>
ListaDEnlazada<T>::ListaDEnlazada(const ListaDEnlazada &orig) {
    Nodo<T> *i = orig.cabecera;

    cabecera = cola = 0;
    tam = orig.tam;

    while (i) {
        Nodo<T> *nuevo;
        nuevo = new Nodo<T>(i->dato, nullptr);

        if (cabecera == nullptr)
            cabecera = nuevo;

        if (cola != nullptr)
            cola->sig = nuevo;

        cola = nuevo;
        i = i->sig;
    }

}

/* OPERADORES */

/**
 * @brief Operador de asignacion
 * @param l
 * @return
 */
template<class T>
ListaDEnlazada<T> &ListaDEnlazada<T>::operator=(const ListaDEnlazada<T> &l) {

    if (this != &l) {

        if (cabecera) {
            Nodo<T> *nodo = cabecera;
            while (nodo) {
                cabecera = cabecera->sig;
                delete nodo;
                nodo = cabecera;
            }
            cola = nullptr;
        }
        Nodo<T> *i = l.cabecera;

        this->cabecera = nullptr;
        this->cola = nullptr;
        tam = l.tam;

        while (i) {
            Nodo<T> *nuevo;
            nuevo = new Nodo<T>(i->dato, nullptr);

            if (cabecera == nullptr)
                cabecera = nuevo;

            if (cola != nullptr)
                cola->sig = nuevo;

            cola = nuevo;
            i = i->sig;
        }
    }
    return (*this);
}

template<class T>
bool ListaDEnlazada<T>::operator<(const ListaDEnlazada<T> &right) const {
    return right > *this;
}

template<class T>
bool ListaDEnlazada<T>::operator==(const ListaDEnlazada<T> &right) const {
    if (tam != right.tam)
        return false;

    Iterador<T> i = (*this).iterador();
    Iterador<T> it = right.iterador();

    while (!i.fin()) {
        if (i.dato() != it.dato())
            return false;
        i.siguiente();
        it.siguiente();
    }
    return true;
}

template<class T>
ListaDEnlazada<T> ListaDEnlazada<T>::operator+(const ListaDEnlazada<T> &listaDEnlazada) const {
    ListaDEnlazada<T> lista = ListaDEnlazada<T>();
    Iterador<T> i = (*this).iterador();

    while (!i.fin()) {
        lista.insertarFinal(i.dato());
        i.siguiente();
    }

    Iterador<T> it = listaDEnlazada.iterador();
    while (!it.fin()) {
        lista.insertarFinal(it.dato());
        it.siguiente();
    }
    return lista;
}
/* METODOS */

/**
 * @brief Iterador apuntando a cabecera
 * @return
 */
template<class T>
Iterador<T> ListaDEnlazada<T>::iterador() const {
    return Iterador<T>(cabecera);
}

/**
 * @brief Inserta en cabecera
 * @param dato
 */
template<class T>
void ListaDEnlazada<T>::insertarInicio(T &dato) {
    Nodo<T> *nuevo;
    nuevo = new Nodo<T>(dato, cabecera);
    if (cola == 0)
        cola = nuevo;
    tam++;
}

/**
 * @brief Inserta en cola
 * @param dato
 */
template<class T>
void ListaDEnlazada<T>::insertarFinal(T &dato) {

    Nodo<T> *nuevo;
    nuevo = new Nodo<T>(dato, 0);

    if (cabecera == 0)
        cabecera = nuevo;
    if (cola != 0)
        cola->sig = nuevo;
    cola = nuevo;
    tam++;
}

/**
 * @brief Inserta apuntando a un iterador
 * @param i
 * @param dato
 */
template<class T>
void ListaDEnlazada<T>::inserta(Iterador<T> &i, T &dato) {
    // sin implementar
}

/**
 * @brief Inserta un elemento de forma ordenada
 * @param dato
 */
template<class T>
void ListaDEnlazada<T>::insertaOrdenado(T &dato) {
    Nodo<T> *nuevo;
    nuevo = new Nodo<T>(dato, 0);
    Nodo<T> *act;

    if (cabecera == NULL || (cabecera)->dato >= nuevo->dato) {
        nuevo->sig = cabecera;
        cabecera = nuevo;
    } else {
        act = cabecera;
        while (act->sig != NULL &&
               act->sig->dato < nuevo->dato) {
            act = act->sig;
        }
        nuevo->sig = act->sig;
        act->sig = nuevo;
    }
    tam++;
}

/**
 * @brief Borra el elemento de la cabecera
 */
template<class T>
void ListaDEnlazada<T>::borraInicio() {
    if (cabecera != 0) {
        --tam;
        Nodo<T> *borrado = cabecera;
        cabecera = cabecera->sig;
        delete borrado;

        if (cabecera == 0) {
            cola = 0;
        }

    }
}

/**
 * @brief Borra el elemento de la cola
 */
template<class T>
void ListaDEnlazada<T>::borraFinal() {

    Nodo<T> *anterior = 0;
    if (cabecera != cola) {
        --tam;
        anterior = cabecera;
        while (anterior->sig != cola)
            anterior = anterior->sig;

        delete cola;
        cola = anterior;
        if (anterior != 0) {
            anterior->sig = 0;
        } else {
            cabecera = 0;
        }
    }
}

/**
 * @brief Borra un elemento que apunta al iterador
 * @param del
 */
template<class T>
void ListaDEnlazada<T>::borra(Iterador<T> &i) {
    Nodo<T> *anterior = 0;
    if (!i.fin()) {
        --tam;
        if (i.nodo == cabecera) {
            borraInicio();
            i.nodo = cabecera;
            return;
        }
        if (i.nodo == cola) {
            borraFinal();
            return;
        }

        anterior = cabecera;
        while (anterior->sig != i.nodo) {
            anterior = anterior->sig;
        }
        anterior->sig = i.nodo->sig;
        anterior = i.nodo;
        i.nodo = i.nodo->sig;
        delete anterior;
    }
}

/**
 * @brief Busca una palabra dentro de la lista
 * @param dato
 * @param i
 * @return
 */
template<class T>
bool ListaDEnlazada<T>::buscar(const T &dato, Iterador<T> &i) {

    Nodo<T> *aux;
    aux = cabecera;
    while (aux) {
        if (aux->dato == dato) {
            Iterador<T> k(aux);
            i = k;
            return true;
        }
        aux = aux->sig;
    }
    return false;
}

/**
 * @brief Dato en cabecera
 * @return
 */
template<class T>
T &ListaDEnlazada<T>::inicio() {
    return cabecera->dato;
}

/**
 * @brief Dato en cola
 * @return
 */
template<class T>
T &ListaDEnlazada<T>::final() {
    return cola->dato;
}

/**
 * @brief Concatena dos listas
 * @param listaDEnlazada
 * @return
 */
template<class T>
ListaDEnlazada<T> ListaDEnlazada<T>::concatena(const ListaDEnlazada<T> &listaDEnlazada) const {
    ListaDEnlazada<T> lista = ListaDEnlazada<T>();
    Iterador<T> i = (*this).iterador();

    while (!i.fin()) {
        lista.insertarFinal(i.dato());
        i.siguiente();
    }

    Iterador<T> it = listaDEnlazada.iterador();
    while (!it.fin()) {
        lista.insertarFinal(it.dato());
        it.siguiente();
    }
    return lista;
}

/* GETTERS Y SETTERS */

template<class T>
int ListaDEnlazada<T>::getTam() const {
    return tam;
}

/* DESTRUCTOR*/

template<class T>
ListaDEnlazada<T>::~ListaDEnlazada() {
    Nodo<T> *siguiente;
    while (cabecera != NULL) {
        siguiente = cabecera->sig;
        free(cabecera);
        cabecera = siguiente;
    }
    cabecera = NULL;
}

#endif /* LISTAENLAZADA_H */
