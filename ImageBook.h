#include "VDinamico.h"
#include "ListaDEnlazada.h"
#include "Imagen.h"
#include "AVL.h"
#include "Usuario.h"

#ifndef PR1_IMAGEBOOK_H
#define PR1_IMAGEBOOK_H

#include <iostream>
#include <list>

using namespace std;

class ImageBook {
private:
    vector<Imagen> images;
    list<Etiqueta> labels;
    map<string, Usuario> users;

public:
    ImageBook() = default;

    ImageBook(const string &ficheroImagenes, const string &ficheroEtiquetas, const string &ficheroUsuarios);

    void cargarUsuarios(const string &fichero);

    void cargarImagenes(const string &fichero);

    void cargarEtiquetas(const string &fichero);

    list<Imagen> buscarImagEtiq(const string &etiqueta);

    Imagen* buscarImag(const string &idImagen);

    Usuario* buscarUsuario(const string& email);

    vector<Usuario*> buscarUsuarioEtiq(const string& etiqueta);

    Usuario* getMasActivos();

    vector<Usuario*> buscarUsuarioFechaImagen(const Fecha &fecha);

    Etiqueta* buscarEtiqueta(const string& nombre);

};


#endif //PR1_IMAGEBOOK_H
