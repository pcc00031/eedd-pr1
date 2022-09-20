//
// Created by pedro.corpas on 20/09/2022.
//

#ifndef PR1_CONTENEDORIMAGENES_H
#define PR1_CONTENEDORIMAGENES_H

#include <iostream>
#include <vector>
#include "Imagen.h"

using namespace std;

class ContenedorImagenes {
private:
    vector<Imagen> imagenes;
    int tam;

public:
    ContenedorImagenes(unsigned int tamMax);

    ContenedorImagenes();

    int getTam() const;

    virtual ~ContenedorImagenes();

    void asigna(unsigned int pos);

    Imagen &recupera(unsigned int pos);

    void ordenar();
};


#endif //PR1_CONTENEDORIMAGENES_H
