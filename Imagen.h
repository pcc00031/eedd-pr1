#ifndef PR1_IMAGEN_H
#define PR1_IMAGEN_H

#include <iostream>
#include "fecha.h"
#include "Etiqueta.h"
#include <deque>

using namespace std;

class Imagen {
private:
    string id;
    string nombre;
    int tam = 0;
    Fecha fecha = Fecha();
    deque<Etiqueta> etiquetada;

public:
    Imagen() = default;

    Imagen(const string &id, const string &nombre,int tam, const Fecha &fecha, const deque<Etiqueta> &etiquetada);

    virtual ~Imagen() = default;

    const string &getId() const;

    void setId(const string &id);

    const string &getEmail() const;

    void setEmail(const string &email);

    const string &getNombre() const;

    void setNombre(const string &nombre);

    int getTam() const;

    void setTam(int tam);

    const Fecha &getFecha() const;

    void setFecha(const Fecha &fecha);

    const deque<Etiqueta> &getEtiquetada() const;

    void setEtiquetada(const Etiqueta &etiquetada);

    bool operator==(const Imagen &rhs) const;

    bool operator!=(const Imagen &rhs) const;

    bool operator<(const Imagen &rhs) const;

    bool operator>(const Imagen &rhs) const;

    bool operator<=(const Imagen &rhs) const;

    bool operator>=(const Imagen &rhs) const;

    friend ostream &operator<<(ostream &os, const Imagen &imagen);

    void anadirEtiqueta(Etiqueta &etiqueta);

};


#endif //PR1_IMAGEN_H
