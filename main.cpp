#include <iostream>
#include <sstream>
#include "Imagen.h"
#include "VDinamico.h"
#include "ImageBook.h"
#include <ctime>

using namespace std;

int static numMostrar = 10;

/**
 * @author Pedro Corpas Cuesta @pcc00031
 */
int main() {

    cout << "******* PRACTICA 2 *******" << endl << endl;

//    Instanciar la clase ImageBook

    clock_t t_ini = clock();
    cout << "******* Instanciando ImageBook *******" << endl << endl;
    ImageBook imageBook = ImageBook("imagenes_v1.csv", "etiquetas.txt");
    imageBook.mostrarImagenes(numMostrar);
    imageBook.mostrarEtiquetas(numMostrar);

    cout << "Tiempo primer apartado: " << (clock() - t_ini) << " ms." << endl << endl;

    cout << "******************************************************************************" << endl << endl;

//    Devolver y mostrar por pantalla todas aquellas imágenes (id, usuario) con la etiqueta “playa”
//    y posteriormente las que tengan la etiqueta “comida”.

    t_ini = clock();
    cout << "******* Mostrando imagenes con etiqueta playa *******" << endl << endl;
    ListaDEnlazada<Imagen> imagenesEtiquetaPlaya = imageBook.buscarImagEtiq("playa");

    cout << "******* Mostrando imagenes con etiqueta comida *******" << endl << endl;
    ListaDEnlazada<Imagen> imagenesEtiquetaComida = imageBook.buscarImagEtiq("comida");

    cout << "Tiempo segundo apartado: " << (clock() - t_ini) << " ms." << endl << endl;

    cout << "******************************************************************************" << endl << endl;

//    Unir ambas listas resultantes en una nueva lista resultado usando la función concatenar,
//    comprobando que el resultado es idéntico usando el operator+.

    cout << "******* Uniendo ambas listas anteriores *******" << endl << endl;


    cout << "Tiempo tercer apartado: " << (clock() - t_ini) << " ms." << endl << endl;

    cout << "******************************************************************************" << endl << endl;

//    Devolver cuál de las etiquetas es la más repetida usando el mismo procedimiento anterior.
//    Para ello iterar sobre todas las etiquetas para posteriormente buscarlas.

    cout << "******* Buscando etiqueta mas repetida *******" << endl << endl;
    t_ini = clock();

    imageBook.etiquetaMasRepetida();

    cout << "Tiempo cuarto apartado: " << (clock() - t_ini) << " ms." << endl << endl;

    cout << "******************************************************************************" << endl << endl;

    return 0;
}
