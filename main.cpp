#include <iostream>
#include <sstream>
#include "Imagen.h"
#include "VDinamico.h"
#include "ImageBook.h"
#include "AVL.h"
#include <ctime>

using namespace std;

int static numMostrar = 10;

/**
 * @author Pedro Corpas Cuesta @pcc00031
 */
int main() {

    cout << "******* PRACTICA 2 *******" << endl << endl;

    // Prueba de AVL

    AVL<int> pruebaAVL = AVL<int>();
    int millon = 1000000;
    for (int i = 0; i < millon; ++i) {
        int aleatorio = rand() % millon + 1;
        pruebaAVL.inserta(aleatorio);
    }
    cout << "La altura del arbol de prueba es: " << pruebaAVL.altura() << endl;

    //    Instanciar la clase ImageBook

    clock_t t_ini = clock();
    cout << "******* Instanciando ImageBook *******" << endl << endl;
    ImageBook imageBook = ImageBook(
            "imagenes_v1.csv",
            "etiquetas.txt",
            "usuarios.txt");

    cout << endl << "******************************************************************************" << endl << endl;

    //    Buscar y mostrar la información de las imágenes de estos usuarios (si es que existen):
    //    eliza39@yahoo.com, betty95@hotmail.com, betty95@hotmail.com, victor6@gmail.com y manolete@gmail.com.

    cout << "******* Devolviendo los usuarios con el email solicitado *******" << endl << endl;
    Usuario *usuario;
    try {
        usuario = imageBook.buscarUsuario("eliza39@yahoo.com");
        cout << *usuario << endl;
        usuario = imageBook.buscarUsuario("betty95@hotmail.com");
        cout << *usuario << endl;
        usuario = imageBook.buscarUsuario("betty95@hotmail.com");
        cout << *usuario << endl;
        usuario = imageBook.buscarUsuario("victor6@gmail.com");
        cout << *usuario << endl;
        usuario = imageBook.buscarUsuario("manolete@gmail.com");
        cout << *usuario << endl;
    } catch (invalid_argument &e) {
        cerr << e.what() << endl;
    }
    cout << endl << "******************************************************************************" << endl << endl;

    //    Devolver y mostrar por pantalla todos aquellos usuarios que hayan publicado alguna imagen
    //    con la etiqueta “playa” y posteriormente los que hayan publicado con la etiqueta “comida”

    cout << "******* Devolviendo los usuarios con etiqueta playa *******" << endl << endl;
    VDinamico<Usuario *> playa = imageBook.buscarUsuarioEtiq("playa");
    for (int i = 0; i < playa.getTamLog(); ++i) {
        cout << playa[i]->getEmail() << endl;
    }

    cout << endl << "******* Devolviendo los usuarios con etiqueta comida *******" << endl << endl;
    VDinamico<Usuario *> comida = imageBook.buscarUsuarioEtiq("comida");
    for (int i = 0; i < comida.getTamLog(); ++i) {
        cout << comida[i]->getEmail() << endl;
    }

    cout << endl << "******************************************************************************" << endl << endl;

    //    Devolver el/los usuarios más activos en la red porque hayan publicado más imágenes.

    cout << "******* Devolviendo los usuarios mas activos *******" << endl << endl;
    VDinamico<Usuario *> masActivos = imageBook.getMasActivos();
    for (int i = 0; i < masActivos.getTamLog(); ++i) {
        cout << *masActivos[i] << endl;
    }

    cout << endl << "******************************************************************************" << endl << endl;

    return 0;
}
