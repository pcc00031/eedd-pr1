//
// Created by Pedro on 12/11/2022.
//

#include "Usuario.h"


Usuario::Usuario() {
    userImages = VDinamico<Imagen>();
}

Usuario::Usuario(const string &email) : email(email) {
    userImages = VDinamico<Imagen>();
}

VDinamico<Imagen> Usuario::buscarEtiq(string etiqueta) {
    VDinamico<Imagen> etiquetas = VDinamico<Imagen>();
    for (int i = 0; i < userImages.getTamLog(); ++i) {
        if (userImages[i].getEtiquetada().getNombre() == etiqueta) {
            etiquetas.insertar(userImages[i]);
        }
    }
    return etiquetas;
}

int Usuario::getNumImages() {
    return userImages.getTamLog();
}

void Usuario::insertarImagen(Imagen img) {
    userImages.insertar(img);
}

const string &Usuario::getEmail() const {
    return email;
}

bool Usuario::operator<(const Usuario &rhs) const {
    return email < rhs.email;
}

bool Usuario::operator>(const Usuario &rhs) const {
    return rhs < *this;
}

bool Usuario::operator<=(const Usuario &rhs) const {
    return !(rhs < *this);
}

bool Usuario::operator>=(const Usuario &rhs) const {
    return !(*this < rhs);
}

bool Usuario::operator==(const Usuario &rhs) const {
    return email == rhs.email;
}

bool Usuario::operator!=(const Usuario &rhs) const {
    return !(rhs == *this);
}


ostream &operator<<(ostream &os, const Usuario &usuario) {
    os << "DATOS USUARIO" << endl
       << "- email: " << usuario.email << endl
       << "- total imagenes: " << usuario.userImages.getTamLog() << endl;
    return os;
}