
#include <algorithm>
#include "ContenedorImagenes.h"

/**
 * Constructor parametrizado
 * @param tamMax
 */
ContenedorImagenes::ContenedorImagenes(unsigned int tamMax) : tam(tamMax) {
    this->imagenes = new Imagen[this->tam];
}

/**
 * Constructor por defecto
 */
ContenedorImagenes::ContenedorImagenes() : tam(100) {
    this->imagenes = new Imagen[this->tam];
}

/**
 * Inserta una imagen en una determinada posicion
 * @param pos
 * @param imagen
 */
void ContenedorImagenes::asigna(unsigned int pos, const Imagen& imagen) {
    if (pos < 0 || pos > this->tam)
        throw out_of_range("La posición indicada esta fuera del rango");
    this->imagenes[pos] = imagen;
}

/**
 * Ordena imagenes por tam
 */
void ContenedorImagenes::ordenar() {
    sort(this->imagenes, this->imagenes + this->tam);
}

/**
 * Ordena reversivamente imagenes por tam
 */
void ContenedorImagenes::ordenarRev() {
    sort(this->imagenes, this->imagenes + this->tam, greater<Imagen>());
}

/**
 * Recupera imagen por posicion
 * @param pos
 * @return
 */
Imagen &ContenedorImagenes::recupera(unsigned int pos) {
    if (pos < 0 || pos > this->tam)
        throw out_of_range("La posicion indicada esta fuera del rango");

    return this->imagenes[pos];
}

/**
 * Obtiene el tam del contenedor
 * @return
 */
int ContenedorImagenes::getTam() const {
    return tam;
}

/**
 * Encuentra imagenes en base a year e email
 * @param email
 * @param fecha
 * @return nuevo contenedor
 */
ContenedorImagenes ContenedorImagenes::buscarImagenesPorYearEmail(const string& email, int anno) {
    ContenedorImagenes contenedor = ContenedorImagenes(20);
    Imagen imagen;
    int contador = 0;
    for (int i = 0; i < this->tam; i++) {
        imagen = imagenes[i];
        if (imagen.getEmail() == email && imagen.getFecha().verAnio() == anno && contador <= 20)
            contenedor.imagenes[contador++] = imagen;
    }
    cout << "Total imagenes: " << contador << endl << endl;
    return contenedor;
}

/**
 * Recupera imagen por id
 * @param id
 * @return
 */
Imagen &ContenedorImagenes::recuperaPorID(const string& id) {
    Imagen *imagen = new Imagen();
    for (int i = 0; i < this->tam; i++) {
        if (imagenes[i].getId() == id) {
            cout << "Se ha encontrado la imagen con id: " + id << endl;
            return imagenes[i];
        }
    }
    cout << "No se ha encontrado la imagen con id: " + id << endl;
    return *imagen;
}

/**
 * Destructor, libera memoria
 */
ContenedorImagenes::~ContenedorImagenes() {
    delete this->imagenes;
}
