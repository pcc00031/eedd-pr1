

#ifndef PR1_USUARIO_H
#define PR1_USUARIO_H

#include <string>
#include <vector>
#include <map>
#include "Imagen.h"
#include "VDinamico.h"

using namespace std;

class Usuario {
private:
    string email;
    map<string, Imagen *> userImages;
public:
    Usuario();

    Usuario(const string &email);

    bool operator<(const Usuario &rhs) const;

    bool operator>(const Usuario &rhs) const;

    bool operator<=(const Usuario &rhs) const;

    bool operator>=(const Usuario &rhs) const;

    bool operator==(const Usuario &rhs) const;

    bool operator!=(const Usuario &rhs) const;

    VDinamico<Imagen> buscarEtiq(string etiqueta);

    int getNumImages();

    void insertarImagen(Imagen img);

    void anadirEtiquetaImagen(const string &id, const string &nombreEti);

    vector<Usuario *> buscarUsuariosEtiq(const string &nombreEti);

    bool esMasActivo();

    Imagen *getImagenMasAntigua();

    Imagen *getImagenMasReciente();

    const string &getEmail() const;

    friend ostream &operator<<(ostream &os, const Usuario &usuario);
};


#endif //PR1_USUARIO_H
