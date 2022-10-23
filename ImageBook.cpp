#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "ImageBook.h"

ImageBook::ImageBook(const string &ficheroImagenes, const string &ficheroEtiquetas) {
    cargarEtiquetas(ficheroEtiquetas);
    cargarImagenes(ficheroImagenes);
}

void ImageBook::cargarImagenes(const string &fichero) {
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

                Etiqueta etiquetaAux = Etiqueta(etiqueta);
                Iterador<Etiqueta> i = labels.iterador();
                labels.buscar(etiquetaAux, i);

                // si existe la etiqueta correspondiente a esta imagen, insertamos
                if (i.dato().getNombre() == etiqueta) {
                    Imagen imagen = Imagen(id, email, nombre, tam, Fecha(dia, mes, anno), etiquetaAux);
                    images.insertar(imagen, contador++);
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
                labels.insertarFinal(etiqueta);

                fila = "";
                columnas.clear();
            }
        }
        is.close();
    } else {
        cout << "Error de apertura en archivo" << endl;
    }
}

void ImageBook::mostrarImagenes(int total) {
    cout << "Total imagenes: " << images.getTamLog() << endl;
    for (int i = 0; i < total; ++i) {
        cout << images[i] << endl;
    }
}

void ImageBook::mostrarEtiquetas(int total) {
    Iterador<Etiqueta> i = labels.iterador();
    int cont = 0;
    cout << "Total etiquetas: " << labels.getTam() << endl;
    while (cont < total) {
        cout << i.dato() << endl;
        i.siguiente();
        cont++;
    }
}

ListaDEnlazada<Imagen> ImageBook::buscarImagEtiq(const string &etiqueta) {
    ListaDEnlazada<Imagen> lista = ListaDEnlazada<Imagen>();
    Etiqueta etiquetaAux = Etiqueta(etiqueta);
    for (int i = 0; i < images.getTamLog(); ++i) {
        if (images[i].getEtiquetada() == etiquetaAux)
            lista.insertarFinal(images[i]);
    }
    cout << "Total etiquetas: " << lista.getTam() << endl;
    Iterador<Imagen> i = lista.iterador();
    while (!i.fin()) {
        cout << i.dato() << endl;
        i.siguiente();
    }

    return lista;
}

Etiqueta &ImageBook::etiquetaMasRepetida() {

    Etiqueta etiquetaMasRepetida = labels.inicio();
    int total = 0;
    Iterador<Etiqueta> it = labels.iterador();
    while (!it.fin()) {
        int totalRepetida = 0;
        Etiqueta etiqueta = it.dato();
        for (int i = 0; i < images.getTamLog(); ++i) {
            if (images[i].getEtiquetada() == etiqueta)
                totalRepetida++;
        }
        if (totalRepetida > total) {
            total = totalRepetida;
            etiquetaMasRepetida = etiqueta;
        }
        it.siguiente();
    }

    cout << etiquetaMasRepetida << " es la mas repetida (" << total << ")" << endl;
    return etiquetaMasRepetida;

}