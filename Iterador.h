
#ifndef PR1_ITERADOR_H
#define PR1_ITERADOR_H

#include "NodoL.h"

template<class T>
class Iterador {
private:
    NodoL <T> *nod;

public:

    Iterador(NodoL <T> *aNodo);

    NodoL <T> *nodo;

    bool fin();

    void siguiente();

    T &dato();
};

template<class T>
Iterador<T>::Iterador(NodoL <T> *aNodo) : nodo(aNodo) {
}

template<class T>
bool Iterador<T>::fin() {
    return nodo == 0;
}

template<class T>
void Iterador<T>::siguiente() {
    nodo = nodo->sig;
}

template<class T>
T &Iterador<T>::dato() {
    return nodo->dato;
}

#endif //PR1_ITERADOR_H
