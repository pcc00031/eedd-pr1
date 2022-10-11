#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Imagen.h"
#include "VDinamico.h"
#include <ctime>

using namespace std;

int static numMostrarImagenes = 5;

/**
 * Carga imagenes desde un fichero y guarda en vector propio
 * @return
 */
VDinamico<Imagen> cargarImagenes() {
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

    VDinamico<Imagen> imagenes = VDinamico<Imagen>(10000);

    is.open("../imagenes_v1.csv"); //carpeta de proyecto
    if (is.good()) {

        while (getline(is, fila)) {

            //¿Se ha leído una nueva fila?
            if (!fila.empty()) {
                columnas.str(fila);

                //formato de fila: id;email;nombre;tamLog;fecha;etiquetas

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

                Imagen imagen = Imagen(id, email, nombre, tam, Fecha(dia, mes, anno), etiquetas);
                imagenes.insertar(imagen, contador++);

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

/**
 * @author Pedro Corpas Cuesta @pcc00031
 */
int main() {

    cout << "******* PRACTICA 1 *******" << endl << endl;

//    Instanciar un vector de imágenes con 10000 posiciones y almacenar en él las imágenes
//    contenidas en el fichero adjunto. Una vez leído el fichero, mostrar el nombre, la fecha y etiquetas
//    de las 50 primeras imágenes del vector

    cout << "******* Mostrando primeras imagenes cargadas *******" << endl << endl;
    clock_t t_ini = clock();
    VDinamico<Imagen> imagenes = cargarImagenes();
    for (int i = 0; i < numMostrarImagenes; i++) {
        cout << imagenes[i] << endl;
    }
    cout << "Tiempo primer apartado: " << (clock() - t_ini) << " ms." << endl << endl;

    cout << "******************************************************************************" << endl << endl;

//    Ordenar el vector al revés, es decir, de mayor a menor y mostrar la información de todas sus
//    imágenes

    cout << "******* Mostrando datos ordenados *******" << endl << endl;
    t_ini = clock();
    imagenes.ordenar();
    for (int i = 0; i < numMostrarImagenes; i++) {
        cout << imagenes[i] << endl;
        cout << imagenes[i] << endl;
    }
    cout << "Tiempo segundo apartado: " << (clock() - t_ini) << " ms." << endl << endl;

    cout << "******************************************************************************" << endl << endl;

//    Ordenar el vector de menor a mayor y mostrar los identificadores de las primeras 20
//    imágenes

    cout << "******* Mostrando datos ordenados desc. *******" << endl << endl;
    t_ini = clock();
    imagenes.ordenarRev();
    for (int i = 0; i < numMostrarImagenes; i++) {
        cout << imagenes[i] << endl;
    }
    cout << "Tiempo tercer apartado: " << (clock() - t_ini) << " ms." << endl << endl;

    cout << "******************************************************************************" << endl << endl;

//    Una vez ordenado el vector, buscar imágenes con los identificadores 346335905, 999930245,
//    165837, 486415569 y 61385551, mostrando su posición en el contenedor. Teniendo en cuenta que
//    pueden no existir.

    cout << "******* Buscando imagenes existe / no existe *******" << endl << endl;
    t_ini = clock();
    Imagen imagen = Imagen();
    imagen.setId("346335905");
    try {
        cout << imagenes[imagenes.busquedaBin(imagen)] << endl;
        imagen.setId("999930245");
        cout << imagenes[imagenes.busquedaBin(imagen)] << endl;
        imagen.setId("165837");
        cout << imagenes[imagenes.busquedaBin(imagen)] << endl;
        imagen.setId("486415569");
        cout << imagenes[imagenes.busquedaBin(imagen)] << endl;
        imagen.setId("61385551");
        cout << imagenes[imagenes.busquedaBin(imagen)] << endl;

    } catch (out_of_range e) {
        cerr << e.what() << endl;
    }
    cout << "Tiempo cuarto apartado: " << (clock() - t_ini) << " ms." << endl << endl;

    cout << "******************************************************************************" << endl << endl;

//    El usuario magdalen_upton99@gmail.com desea descargarse y eliminar sus imágenes del
//    sistema. Pasar y borrar todas sus fotos del vector dinámico a un nuevo vector dinámico específico
//    para enviárselas. Mostrar el tamaño lógico de ambos vectores y toda la información de las
//    primeras 10 imágenes que se le enviarán. Si se usan vectores auxiliares, deberán declararse como
//    VDinamico.

    cout << "******* Mostrando imagenes de magdalen_upton99@gmail.com *******" << endl << endl;
    t_ini = clock();
    VDinamico<Imagen> imagenesMagdalen = VDinamico<Imagen>();
    VDinamico<int> posiciones = VDinamico<int>();
    for (int i = 0; i < imagenes.getTamLog(); ++i) {
        if (imagenes[i].getEmail() == "magdalen_upton99@gmail.com") {
            imagenesMagdalen.insertar(imagenes[i]);
            imagenes.borrar(i);
        }
    }
    for (int i = 0; i < posiciones.getTamLog(); ++i) {
        imagenes.borrar(posiciones[i]);
    }
    for (int i = 0; i < numMostrarImagenes; i++) {
        cout << imagenesMagdalen[i] << endl;
    }

    cout << "Total imagenes Magdalen: " << imagenesMagdalen.getTamLog() << endl;
    cout << "Tam de vector una vez borradas: " << imagenes.getTamLog() << endl;
    cout << "Tiempo quinto apartado: " << (clock() - t_ini) << " ms." << endl << endl;

    cout << "******************************************************************************" << endl << endl;

    return 0;
}
