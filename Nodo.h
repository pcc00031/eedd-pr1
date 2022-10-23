
#ifndef ITERADOR_H
#define ITERADOR_H

template<class T>
class Nodo {
public:
    // Atributos
    T dato;
    Nodo *sig;

    // Constructor

    Nodo(T &aDato, Nodo *aSig = 0) :
            dato(aDato), sig(aSig) {
    }

    // Constructor copia

    Nodo(const Nodo<T> &orig) :
            dato(orig.dato), sig(orig.sig) {
    }

    // Operador de asignacion

    Nodo<T> &operator=(const Nodo<T> &right) {
        if (this == &right)
            return *this;
        this->sig = right.sig;
        this->dato = right.dato;
        return *this;
    }
};

#endif /* ITERADOR_H */