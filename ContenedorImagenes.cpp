//
// Created by pedro.corpas on 20/09/2022.
//

#include "ContenedorImagenes.h"

ContenedorImagenes::ContenedorImagenes(unsigned int tamMax) : tam(tamMax) {}

ContenedorImagenes::ContenedorImagenes(): tam(100) {}

void ContenedorImagenes::asigna(unsigned int pos) {
    // outofrange si pos no valida
}

void ContenedorImagenes::ordenar() {

}

Imagen &ContenedorImagenes::recupera(unsigned int pos) {
    return <#initializer#>;
}

ContenedorImagenes::~ContenedorImagenes() {

}

int ContenedorImagenes::getTam() const {
    return tam;
}
