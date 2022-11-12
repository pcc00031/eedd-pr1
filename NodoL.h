
#ifndef ITERADOR_H
#define ITERADOR_H

template<class T>
class NodoL {
public:
    // Atributos
    T dato;
    NodoL *sig;

    // Constructor

    NodoL(T &aDato, NodoL *aSig = 0) :
            dato(aDato), sig(aSig) {
    }

    // Constructor copia

    NodoL(const NodoL<T> &orig) :
            dato(orig.dato), sig(orig.sig) {
    }

    // Operador de asignacion

    NodoL<T> &operator=(const NodoL<T> &right) {
        if (this == &right)
            return *this;
        this->sig = right.sig;
        this->dato = right.dato;
        return *this;
    }
};

#endif /* ITERADOR_H */