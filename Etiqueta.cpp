#include "Etiqueta.h"

/**
* Constructor parametrizado
*/
Etiqueta::Etiqueta(const string &nombre) :
        nombre(nombre) {
}

bool Etiqueta::operator==(const Etiqueta &rhs) const {
    return nombre == rhs.nombre;
}

ostream &operator<<(ostream &os, const Etiqueta &etiqueta) {
    os << "- etiqueta: " << etiqueta.nombre << endl;
    return os;
}

const string &Etiqueta::getNombre() const {
    return nombre;
}

bool Etiqueta::operator<(const Etiqueta &rhs) const {
    return nombre < rhs.nombre;
}

bool Etiqueta::operator>(const Etiqueta &rhs) const {
    return rhs.nombre < nombre;
}

bool Etiqueta::operator<=(const Etiqueta &rhs) const {
    return !(rhs.nombre < nombre);
}

bool Etiqueta::operator>=(const Etiqueta &rhs) const {
    return !(nombre < rhs.nombre);
}

