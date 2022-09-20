//
// Created by pedro.corpas on 20/09/2022.
//

#include "Imagen.h"

Imagen::Imagen(const string &id, const string &email, const string &nombre, int tam, const string &fecha,
               const string &etiquetas) : id(id), email(email), nombre(nombre), tam(tam), fecha(fecha),
                                          etiquetas(etiquetas) {}

Imagen::Imagen() {}

Imagen::~Imagen() {

}

const string &Imagen::getId() const {
    return id;
}

void Imagen::setId(const string &id) {
    Imagen::id = id;
}

const string &Imagen::getEmail() const {
    return email;
}

void Imagen::setEmail(const string &email) {
    Imagen::email = email;
}

const string &Imagen::getNombre() const {
    return nombre;
}

void Imagen::setNombre(const string &nombre) {
    Imagen::nombre = nombre;
}

int Imagen::getTam() const {
    return tam;
}

void Imagen::setTam(int tam) {
    Imagen::tam = tam;
}

const string &Imagen::getFecha() const {
    return fecha;
}

void Imagen::setFecha(const string &fecha) {
    Imagen::fecha = fecha;
}

const string &Imagen::getEtiquetas() const {
    return etiquetas;
}

void Imagen::setEtiquetas(const string &etiquetas) {
    Imagen::etiquetas = etiquetas;
}

bool Imagen::operator==(const Imagen &rhs) const {
    return id == rhs.id &&
           email == rhs.email &&
           nombre == rhs.nombre &&
           tam == rhs.tam &&
           fecha == rhs.fecha &&
           etiquetas == rhs.etiquetas;
}

bool Imagen::operator!=(const Imagen &rhs) const {
    return !(rhs == *this);
}
