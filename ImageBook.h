#include "VDinamico.h"
#include "ListaDEnlazada.h"
#include "Imagen.h"

#ifndef PR1_IMAGEBOOK_H
#define PR1_IMAGEBOOK_H

#include <iostream>

using namespace std;

class ImageBook {
private:
    VDinamico<Imagen> images;
    ListaDEnlazada<Etiqueta> labels;

public:
    ImageBook() = default;

    ImageBook(const string &ficheroImagenes, const string &ficheroEtiquetas);

    void cargarImagenes(const string &fichero);

    void cargarEtiquetas(const string &fichero);

    void mostrarImagenes(int total);

    void mostrarEtiquetas(int total);

    ListaDEnlazada<Imagen> buscarImagEtiq(const string &etiqueta);

    Etiqueta& etiquetaMasRepetida();
};


#endif //PR1_IMAGEBOOK_H
