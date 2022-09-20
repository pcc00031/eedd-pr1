#ifndef PR1_IMAGEN_H
#define PR1_IMAGEN_H

#include <iostream>

using namespace std;

class Imagen {
private:
    string id;
    string email;
    string nombre;
    int tam;
    string fecha;
    string etiquetas;

public:
    Imagen();

    Imagen(const string &id, const string &email, const string &nombre, int tam, const string &fecha,
           const string &etiquetas);

    virtual ~Imagen();

    const string &getId() const;

    void setId(const string &id);

    const string &getEmail() const;

    void setEmail(const string &email);

    const string &getNombre() const;

    void setNombre(const string &nombre);

    int getTam() const;

    void setTam(int tam);

    const string &getFecha() const;

    void setFecha(const string &fecha);

    const string &getEtiquetas() const;

    void setEtiquetas(const string &etiquetas);

    bool operator==(const Imagen &rhs) const;

    bool operator!=(const Imagen &rhs) const;
};


#endif //PR1_IMAGEN_H
