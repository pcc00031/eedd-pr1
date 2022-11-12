
#include "Imagen.h"

/**
 * Constructor parametrizado
 * @param id
 * @param email
 * @param nombre
 * @param tam
 * @param fecha
 * @param etiquetadas
 */
Imagen::Imagen(const string &id, const string &nombre, int tam, const Fecha &fecha, const Etiqueta &etiquetada) :
        id(id), nombre(nombre), tam(tam), fecha(fecha), etiquetada(etiquetada) {}

/**
 * Obtiene id de imagen
 * @return
 */
const string &Imagen::getId() const {
    return id;
}

/**
 * Establece email
 * @param id
 */
void Imagen::setId(const string &id) {
    Imagen::id = id;
}

/**
 * Obtiene nombre de imagen
 * @return
 */
const string &Imagen::getNombre() const {
    return nombre;
}

/**
 * Establece nombre
 * @param nombre
 */
void Imagen::setNombre(const string &nombre) {
    Imagen::nombre = nombre;
}

/**
 * Obtiene tamLog de imagen
 * @return
 */
int Imagen::getTam() const {
    return tam;
}

/**
 * Establece tamLog
 * @param tam
 */
void Imagen::setTam(int tam) {
    Imagen::tam = tam;
}

/**
 * Obtiene fecha de imagen
 * @return
 */
const Fecha &Imagen::getFecha() const {
    return fecha;
}

/**
 * Establece fecha
 * @param fecha
 */
void Imagen::setFecha(const Fecha &fecha) {
    Imagen::fecha = fecha;
}

/**
 * Obtiene etiquetas de imagen
 * @return
 */
const Etiqueta &Imagen::getEtiquetada() const {
    return etiquetada;
}

/**
 * Establece etiquetas
 * @param etiquetas
 */
void Imagen::setEtiquetada(const Etiqueta &etiquetada) {
    Imagen::etiquetada = etiquetada;
}

/** OPERADORES EN BASE A TAM **/

bool Imagen::operator<(const Imagen &rhs) const {
    return tam < rhs.tam;
}

bool Imagen::operator>(const Imagen &rhs) const {
    return rhs.tam < tam;
}

bool Imagen::operator<=(const Imagen &rhs) const {
    return rhs.tam >= tam;
}

bool Imagen::operator>=(const Imagen &rhs) const {
    return tam >= rhs.tam;
}

/**
 * Define como se muestra imagen por consola
 * @param os
 * @param imagen
 * @return
 */
ostream &operator<<(ostream &os, const Imagen &imagen) {
    os << "DATOS IMAGEN" << endl
       << "- id: " << imagen.id << endl
       << "- nombre: " << imagen.nombre << endl
       << "- tamLog: " << imagen.tam << endl
       << "- fecha: " << imagen.fecha << endl
       << imagen.etiquetada << endl;
    return os;
}

bool Imagen::operator==(const Imagen &rhs) const {
    return id == rhs.id &&
           nombre == rhs.nombre &&
           tam == rhs.tam &&
           fecha.mismoDia(fecha) &&
           etiquetada == rhs.etiquetada;
}

bool Imagen::operator!=(const Imagen &rhs) const {
    return !(rhs == *this);
}