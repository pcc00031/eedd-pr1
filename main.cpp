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

    cout << "******* PRACTICA 3 *******" << endl << endl;

    //    Instanciar la clase ImageBook

    cout << "******* Instanciando ImageBook *******" << endl;
    ImageBook imageBook = ImageBook(
            "imagenes_v1.csv",
            "etiquetas.txt",
            "usuarios.txt");

    cout << endl << "******************************************************************************" << endl << endl;

    //    El usuario noelia30@hotmail.com quiere incluir la etiqueta “playa” en una de sus imágenes
    //    cuyo id es 625722993.

    Usuario *usuario = imageBook.buscarUsuario("noelia30@hotmail.com");

    usuario->anadirEtiquetaImagen("625722993", "playa");
    vector<Imagen> imagenes = usuario->buscarEtiq("playa");

    for (int i = 0; i < imagenes.size(); ++i) {
        if (imagenes[i].getId() == "625722993")
            cout << imagenes[i] << endl;
    }

    cout  << endl<< "******************************************************************************" << endl << endl;

    //    El usuario kenny_ohara73@yahoo.com quiere modificar la última imagen que ha subido.
    //    Encontrar dicha imagen y añadirle la etiqueta “viernes”.

    usuario = imageBook.buscarUsuario("kenny_ohara73@yahoo.com");

    Imagen *imagen = usuario->getImagenMasReciente();
    usuario->anadirEtiquetaImagen(imagen->getId(), "viernes");
    imagenes = usuario->buscarEtiq("viernes");

    cout << usuario->getImagenMasReciente() << endl;

    cout << endl << "******************************************************************************" << endl << endl;

    //    El usuario elton.botsford@yahoo.com quiere conocer a todos los usuarios con los que
    //    comparte la etiqueta “arroz”. Mostrar el número de usuarios obtenido y su email.

    usuario = imageBook.buscarUsuario("elton.botsford@yahoo.com");

    vector<Usuario *> usuarios = usuario->buscarUsuariosEtiq("arroz");

    cout << "Total usuarios con los que elton.botsford comparte la etiqueta arroz: " << usuarios.size() << endl << endl;
    for (int i = 0; i < usuarios.size(); ++i) {
        cout << usuarios[i]->getEmail() << endl;
    }

    cout << endl << "******************************************************************************" << endl << endl;

    //    Buscar a los usuarios que publicaron una imagen el día 7/9/2021 y mostrar sus datos. De entre
    //    todos los usuarios, mostrar quién ha publicado más imágenes.

    usuarios = imageBook.buscarUsuarioFechaImagen(Fecha(7, 9, 2021));
    cout << "Usuarios que publicaron el dia 7/9/2021" << endl;
    for (int i = 0; i < usuarios.size(); ++i) {
        cout << usuarios[i] << endl;
    }

    cout << endl << "******************************************************************************" << endl << endl;

    //    Comprobar si el usuario chesley.gerlach@hotmail.com es el más activo de la red social.

    cout << "El usuario mas activo es: " << endl << imageBook.getMasActivos() << endl;

    cout << "******************************************************************************" << endl << endl;

    return 0;
}
