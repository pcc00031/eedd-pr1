
#include "Imagen.h"

/**
 * Constructor parametrizado
 * @param id
 * @param email
 * @param nombre
 * @param tam
 * @param fecha
 * @param etiquetas
 */
Imagen::Imagen(const string &id, const string &email, const string &nombre, int tam, const Fecha &fecha,
               const string &etiquetas) : id(id), email(email), nombre(nombre), tam(tam), fecha(fecha),
                                          etiquetas(etiquetas) {}
/**
 * Constructor por defecto
 */
Imagen::~Imagen() {

}

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
 * Obtiene email de imagen
 * @return
 */
const string &Imagen::getEmail() const {
    return email;
}

/**
 * Establece email
 * @param email
 */
void Imagen::setEmail(const string &email) {
    Imagen::email = email;
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
 * Obtiene tam de imagen
 * @return
 */
int Imagen::getTam() const {
    return tam;
}

/**
 * Establece tam
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
const string &Imagen::getEtiquetas() const {
    return etiquetas;
}

/**
 * Establece etiquetas
 * @param etiquetas
 */
void Imagen::setEtiquetas(const string &etiquetas) {
    Imagen::etiquetas = etiquetas;
}

/** OPERADORES EN BASE A TAM **/

bool Imagen::operator<(const Imagen &rhs) const {
    return tam < rhs.tam;
}

bool Imagen::operator>(const Imagen &rhs) const {
    return rhs.tam < tam;
}

bool Imagen::operator<=(const Imagen &rhs) const {
    return !(rhs.tam < tam);
}

bool Imagen::operator>=(const Imagen &rhs) const {
    return !(tam < rhs.tam);
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
       << "- email: " << imagen.email << endl
       << "- nombre: " << imagen.nombre << endl
       << "- tam: " << imagen.tam << endl
       << "- fecha: " << imagen.fecha << endl
       << "- etiquetas: " << imagen.etiquetas << endl;
    return os;
}

bool Imagen::operator==(const Imagen &rhs) const {
    return id == rhs.id &&
           email == rhs.email &&
           nombre == rhs.nombre &&
           tam == rhs.tam &&
           fecha.mismoDia(fecha) &&
           etiquetas == rhs.etiquetas;
}

bool Imagen::operator!=(const Imagen &rhs) const {
    return !(rhs == *this);
}
