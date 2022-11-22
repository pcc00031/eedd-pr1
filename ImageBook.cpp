#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "ImageBook.h"

ImageBook::ImageBook(const string &ficheroImagenes, const string &ficheroEtiquetas, const string &ficheroUsuarios) {
    cargarEtiquetas(ficheroEtiquetas);
    cout << "Carga de etiquetas finalizada" << endl;
    cargarUsuarios(ficheroUsuarios);
    cout << "Carga de usuarios finalizada" << endl;
    cargarImagenes(ficheroImagenes);
    cout << "Carga de imagenes terminada" << endl;
}

void ImageBook::cargarImagenes(const string &fichero) {
    images = vector<Imagen>(10000);
    ifstream is;
    stringstream columnas;
    string fila;

    string id;
    string email;
    string nombre;
    int tam = 0;
    int dia = 0;
    int mes = 0;
    int anno = 0;
    string etiqueta;
    int contador = 0;

    is.open("../" + fichero);
    if (is.good()) {

        while (getline(is, fila)) {
            if (!fila.empty()) {
                columnas.str(fila);

                getline(columnas, id, ';');
                getline(columnas, email, ';');
                getline(columnas, nombre, ';');

                columnas >> tam;
                columnas.ignore();

                columnas >> dia;
                columnas.ignore();
                columnas >> mes;
                columnas.ignore();
                columnas >> anno;
                columnas.ignore();

                getline(columnas, etiqueta, ',');

                deque<Etiqueta> etiquetaDeque = deque<Etiqueta>();
                Etiqueta etiquetaAux = Etiqueta(etiqueta);
                etiquetaDeque.push_back(etiquetaAux);
                auto i = labels.begin();
                while (i != labels.end()) {

                    // si existe la etiqueta correspondiente a esta imagen, insertamos
                    if (i->getNombre() == etiqueta) {
                        Imagen imagen = Imagen(id, nombre, tam, Fecha(dia, mes, anno), etiquetaDeque);
                        images.push_back(imagen);
                        contador++;
                        buscarUsuario(email)->insertarImagen(imagen);
                    }
                    ++i;
                }

                fila = "";
                columnas.clear();
            }
        }
        is.close();
    } else {
        cout << "Error de apertura en archivo" << endl;
    }
}

void ImageBook::cargarEtiquetas(const string &fichero) {
    ifstream is;
    stringstream columnas;
    string fila;

    string nombre;
    int contador = 0;

    is.open("../" + fichero);
    if (is.good()) {

        while (getline(is, fila)) {
            if (!fila.empty()) {
                columnas.str(fila);

                getline(columnas, nombre);

                Etiqueta etiqueta = Etiqueta(nombre);
                labels.push_back(etiqueta);

                fila = "";
                columnas.clear();
            }
        }
        is.close();
    } else {
        cout << "Error de apertura en archivo" << endl;
    }
}

void ImageBook::cargarUsuarios(const string &fichero) {
    ifstream is;
    stringstream columnas;
    string fila;

    string email;
    int contador = 0;

    is.open("../" + fichero);
    if (is.good()) {

        while (getline(is, fila)) {
            if (!fila.empty()) {
                columnas.str(fila);

                getline(columnas, email);

                Usuario usuario = Usuario(email);
                users.insert((pair<string, Usuario>(usuario.getEmail(), usuario)));

                fila = "";
                columnas.clear();
            }
        }
        is.close();
    } else {
        cout << "Error de apertura en archivo" << endl;
    }
}

list<Imagen> ImageBook::buscarImagEtiq(const string &etiqueta) {
    list<Imagen> lista = list<Imagen>();
    Etiqueta etiquetaAux = Etiqueta(etiqueta);
    auto i = images.begin();
    while (i != images.end()) {
        if (i->getEtiquetada().at(0) == etiquetaAux)
            lista.push_back(*i);
        ++i;
    }
    cout << "Total etiquetas: " << lista.size() << endl;
    auto j = lista.begin();
    while (j != lista.end()) {
        cout << *j << endl;
        ++j;
    }

    return lista;
}

Usuario *ImageBook::buscarUsuario(const string &email) {
    return &users.find(email)->second;
}

vector<Usuario *> ImageBook::buscarUsuarioEtiq(const string &etiqueta) {
    vector<Usuario *> usuEtiq = vector<Usuario *>();
    auto i = users.begin();
    while (i != users.end()) {
        if (i->second.buscarEtiq(etiqueta).size() > 0)
            usuEtiq.push_back(&i->second);
        ++i;
    }
    return usuEtiq;
}

Usuario *ImageBook::getMasActivos() {
    Usuario *masActivo;
    auto i = users.begin();
    while (i != users.end()) {
        if (i->second.getNumImages() > masActivo->getNumImages())
            masActivo = &i->second;
        ++i;
    }
    return masActivo;
}

vector<Usuario *> ImageBook::buscarUsuarioFechaImagen(const Fecha &fecha) {
    vector<Usuario *> usuarios = vector<Usuario *>();
    auto i = users.begin();
    while (i != users.end()) {
        if (!i->second.getImagenFecha(fecha).empty())
            usuarios.push_back(&i->second);
        ++i;
    }
    return usuarios;
}

