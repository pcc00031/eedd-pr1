#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Imagen.h"
#include "ContenedorImagenes.h"

using namespace std;

int static numMostrarImagenes = 5;

ContenedorImagenes cargarImagenes() {
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
    string etiquetas;
    int contador = 0;

    ContenedorImagenes imagenes = ContenedorImagenes(10000);

    is.open("../imagenes_v1.csv"); //carpeta de proyecto
    if (is.good()) {

        while (getline(is, fila)) {

            //¿Se ha leído una nueva fila?
            if (!fila.empty()) {
                columnas.str(fila);

                //formato de fila: id;email;nombre;tam;fecha;etiquetas

                getline(columnas, id, ';'); //leemos caracteres hasta encontrar y omitir ';'
                getline(columnas, email, ';');
                getline(columnas, nombre, ';');

                columnas >> tam;   //las secuencia numéricas se leen y trasforman directamente
                columnas.ignore(); //omitimos carácter ';' siguiente

                columnas >> dia;
                columnas.ignore();
                columnas >> mes;
                columnas.ignore();
                columnas >> anno;
                columnas.ignore();

                getline(columnas, etiquetas, ';');

                Imagen imagen = Imagen(id, email, nombre, tam, "no", etiquetas);
                imagenes.asigna(contador++, imagen);

                fila = "";
                columnas.clear();
            }
        }
        is.close();
    } else {
        cout << "Error de apertura en archivo" << endl;
    }
    return imagenes;
}

int main() {

    cout << "******* PRACTICA 1 *******" << endl << endl;

//    Instanciar un contenedor de imágenes con 10000 posiciones y almacenar en él las imágenes
//    contenidas en el fichero adjunto. Una vez leído el fichero, mostrar el nombre, la fecha y etiquetas
//    de las 50 primeras imágenes del contenedor

    cout << "******* Mostrando primeras imagenes cargadas *******" << endl << endl;
    clock_t t_ini = clock();
    ContenedorImagenes imagenes = cargarImagenes();
    for (int i = 0; i < numMostrarImagenes; i++) {
        cout << imagenes.recupera(i) << endl;
    }
    cout << "Tiempo primer apartado: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << endl << endl;

    cout << "******************************************************************************" << endl << endl;

//    Ordenar el contenedor al revés, es decir, de mayor a menor y mostrar la información de todas sus
//    imágenes

    cout << "******* Mostrando datos ordenados *******" << endl << endl;
    t_ini = clock();
    imagenes.ordenar();
    for (int i = 0; i < numMostrarImagenes; i++) {
        cout << imagenes.recupera(i) << endl;
    }
    cout << "Tiempo segundo apartado: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << endl << endl;

    cout << "******************************************************************************" << endl << endl;

//    Ordenar el contenedor de menor a mayor y mostrar los identificadores de las primeras 20
//    imágenes

    cout << "******* Mostrando datos ordenados desc. *******" << endl << endl;
    t_ini = clock();
    imagenes.ordenarRev();
    for (int i = 0; i < numMostrarImagenes; i++) {
        cout << imagenes.recupera(i) << endl;
    }
    cout << "Tiempo tercer apartado: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << endl << endl;

    cout << "******************************************************************************" << endl << endl;

//    Una vez ordenado el vector, buscar imágenes con algún identificador que se conozca que existe y
//    otro que no, mostrando su posición en el contenedor. Tener en cuenta que al buscar una imagen
//    esta puede no existir.

    cout << "******* Buscando imagenes existe / no existe *******" << endl << endl;
    t_ini = clock();
    cout << imagenes.recuperaPorID("249062483") << endl;
    cout << imagenes.recuperaPorID("12") << endl;
    cout << "Tiempo cuarto apartado: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << endl << endl;

    cout << "******************************************************************************" << endl << endl;

//    Los responsables de la aplicación consideran interesante que los usuarios puedan localizar las
//    imágenes comprendidas entre un periodo de tiempo. Recuperar las 20 primeras imágenes (podría
//    haber menos) del usuario magdalen_upton99@gmail.com durante el 2020 y almacenarlas en un
//    nuevo contenedor de imágenes, mostrando finalmente su contenido por pantalla.

    cout << "******* Mostrando imagenes de magdalen_upton99@gmail.com en 2020 *******" << endl << endl;
    imagenes.ordenar();
    t_ini = clock();
    ContenedorImagenes imagenesUsu = imagenes.buscarImagenesPorYearEmail("magdalen_upton99@gmail.com", "no");
    for (int i = 0; i < numMostrarImagenes; i++) {
        cout << imagenesUsu.recupera(i) << endl;
    }
    cout << "Tiempo quinto apartado: " << ((clock() - t_ini) / (float) CLOCKS_PER_SEC) << " segs." << endl << endl;

    cout << "******************************************************************************" << endl << endl;

    return 0;
}
