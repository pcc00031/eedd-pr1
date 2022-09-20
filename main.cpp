#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Imagen.h"
#include "ContenedorImagenes.h"

void algo() {
    std::ifstream is;
    std::stringstream columnas;
    std::string fila;

    std::string id;
    std::string email;
    std::string nombre;
    int tam = 0;
    int dia = 0;
    int mes = 0;
    int anno = 0;
    std::string etiquetas;

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
                // agregar contenedor //fixme
                // imagenes.

                fila = "";
                columnas.clear();
            }
        }
        is.close();
    } else {
        std::cout << "Error de apertura en archivo" << std::endl;
    }
}

int main() {
    algo();
//    Instanciar un contenedor de imágenes con 10000 posiciones y almacenar en él las imágenes
//    contenidas en el fichero adjunto. Una vez leído el fichero, mostrar el nombre, la fecha y etiquetas
//    de las 50 primeras imágenes del contenedor



//    Ordenar el contenedor al revés, es decir, de mayor a menor y mostrar la información de todas sus
//    imágenes



//    Ordenar el contenedor de menor a mayor y mostrar los identificadores de las primeras 20
//    imágenes



//    Una vez ordenado el vector, buscar imágenes con algún identificador que se conozca que existe y
//    otro que no, mostrando su posición en el contenedor. Tener en cuenta que al buscar una imagen
//    esta puede no existir.



//    Los responsables de la aplicación consideran interesante que los usuarios puedan localizar las
//    imágenes comprendidas entre un periodo de tiempo. Recuperar las 20 primeras imágenes (podría
//    haber menos) del usuario magdalen_upton99@gmail.com durante el 2020 y almacenarlas en un
//    nuevo contenedor de imágenes, mostrando finalmente su contenido por pantalla.



//    Aquellos que hagáis las prácticas por parejas tendréis que estudiar los tiempos de los cuatro
//    apartados anteriores. Para el resto es opcional.

    return 0;
}
