
#ifndef PR1_CONTENEDORIMAGENES_H
#define PR1_CONTENEDORIMAGENES_H

#include <iostream>
#include <vector>
#include "Imagen.h"

using namespace std;

class ContenedorImagenes {
private:
    Imagen *imagenes;
    int tam;

public:
    ContenedorImagenes(unsigned int tamMax);

    ContenedorImagenes();

    int getTam() const;

    virtual ~ContenedorImagenes();

    void asigna(unsigned int pos, Imagen imagen);

    Imagen &recupera(unsigned int pos);

    Imagen &recuperaPorID(string id);

    void ordenar();

    void ordenarRev();

    ContenedorImagenes buscarImagenesPorYearEmail(string email, int anno);
};

#endif //PR1_CONTENEDORIMAGENES_H
