
#include <algorithm>
#include "ContenedorImagenes.h"

ContenedorImagenes::ContenedorImagenes(unsigned int tamMax) : tam(tamMax) {
    this->imagenes = new Imagen[this->tam];
}

ContenedorImagenes::ContenedorImagenes() : tam(100) {
    this->imagenes = new Imagen[this->tam];
}

void ContenedorImagenes::asigna(unsigned int pos, Imagen imagen) {
    if (pos < 0 || pos > this->tam)
        throw out_of_range("La posición indicada esta fuera del rango");
    this->imagenes[pos] = imagen;
}

void ContenedorImagenes::ordenar() {
    sort(this->imagenes, this->imagenes + this->tam);
}

void ContenedorImagenes::ordenarRev() {
    sort(this->imagenes, this->imagenes + this->tam, greater<Imagen>());
}

Imagen &ContenedorImagenes::recupera(unsigned int pos) {
    if (pos < 0 || pos > this->tam)
        throw out_of_range("La posicion indicada esta fuera del rango");

    return this->imagenes[pos];
}

int ContenedorImagenes::getTam() const {
    return tam;
}

ContenedorImagenes ContenedorImagenes::buscarImagenesPorYearEmail(string email, string fecha) {
    ContenedorImagenes contenedor = ContenedorImagenes(20);
    Imagen imagen;
    int contador = 0;
    for (int i = 0; i < this->tam; i++) {
        imagen = imagenes[i];
        if (imagen.getEmail() == email && imagen.getFecha() == fecha && contador <= 20)
            contenedor.imagenes[contador++] = imagen;
    }
    cout << "Total imagenes: " << contador << endl << endl;
    return contenedor;
}

Imagen &ContenedorImagenes::recuperaPorID(string id) {
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

ContenedorImagenes::~ContenedorImagenes() {
    delete this->imagenes;
}
