//
// Created by Pedro on 12/11/2022.
//

#include "Usuario.h"


Usuario::Usuario() {
    userImages = map<string, Imagen *>();
}

Usuario::Usuario(const string &email) : email(email) {
    userImages = map<string, Imagen *>();
}

VDinamico<Imagen> Usuario::buscarEtiq(string etiqueta) {
    VDinamico<Imagen> etiquetas = VDinamico<Imagen>();
    for (int i = 0; i < userImages.size(); ++i) {
        if (userImages..getEtiquetada().getNombre() == etiqueta) {
            etiquetas.insertar(userImages[i]);
        }
    }
    return etiquetas;
}

int Usuario::getNumImages() {
    return userImages.size();
}

void Usuario::insertarImagen(Imagen img) {
    std::pair<string, Imagen *> imagen = pair<string, Imagen *>(img.getId(), &img);
    userImages.insert(imagen);
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
       << "- total imagenes: " << usuario.userImages.size() << endl;
    return os;
}

void Usuario::anadirEtiquetaImagen(const std::string &id, const std::string &nombreEti) {
    Imagen *imagen = userImages.find(id)->second;
    Etiqueta etiqueta = Etiqueta(nombreEti);
    imagen->anadirEtiqueta(etiqueta);
}

vector<Usuario *> Usuario::buscarUsuariosEtiq(const std::string &nombreEti) {
    map<string, Imagen *>::iterator i;
    vector<Usuario *> usuarios = vector<Usuario *>();
    for (i = userImages.begin(); i != userImages.end(); i++) {
        for (int j = 0; j < i->second->getEtiquetada().size(); ++j) {
            if (i->second->getEtiquetada()[j].getNombre() == nombreEti) {
                usuarios.push_back((this));
            }
        }
    }
    return usuarios;
}

bool Usuario::esMasActivo() {}