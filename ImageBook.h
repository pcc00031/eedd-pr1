#include "VDinamico.h"
#include "ListaDEnlazada.h"
#include "Imagen.h"
#include "AVL.h"
#include "Usuario.h"

#ifndef PR1_IMAGEBOOK_H
#define PR1_IMAGEBOOK_H

#include <iostream>

using namespace std;

class ImageBook {
private:
    VDinamico<Imagen> images;
    ListaDEnlazada<Etiqueta> labels;
    AVL<Usuario> users;

public:
    ImageBook() = default;

    ImageBook(const string &ficheroImagenes, const string &ficheroEtiquetas, const string &ficheroUsuarios);

    void cargarUsuarios(const string &fichero);

    void cargarImagenes(const string &fichero);

    void cargarEtiquetas(const string &fichero);

    void mostrarImagenes(int total);

    void mostrarEtiquetas(int total);

    ListaDEnlazada<Imagen> buscarImagEtiq(const string &etiqueta);

    Usuario* buscarUsuario(string email);

    VDinamico<Usuario*> buscarUsuarioEtiq(string etiqueta);
//
    VDinamico<Usuario*> getMasActivos();

    Etiqueta& etiquetaMasRepetida();
};


#endif //PR1_IMAGEBOOK_H
