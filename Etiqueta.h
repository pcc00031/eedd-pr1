
#ifndef PR1_ETIQUETA_H
#define PR1_ETIQUETA_H

#include <iostream>

using namespace std;

class Etiqueta {
private:
    string nombre;

public:
    Etiqueta() = default;

    explicit Etiqueta(const string &nombre);

    bool operator==(const Etiqueta &rhs) const;

    bool operator<(const Etiqueta &rhs) const;

    bool operator>(const Etiqueta &rhs) const;

    bool operator<=(const Etiqueta &rhs) const;

    bool operator>=(const Etiqueta &rhs) const;

    friend ostream &operator<<(ostream &os, const Etiqueta &etiqueta);

    virtual ~Etiqueta() = default;

    const string &getNombre() const;
};


#endif //PR1_ETIQUETA_H
