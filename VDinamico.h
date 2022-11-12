
#ifndef PR1_VDINAMICO_H
#define PR1_VDINAMICO_H

#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

template<class T>
class VDinamico {

private:
    int tamLog;
    int tamaf;
    T *v;

public:
    VDinamico();

    explicit VDinamico(unsigned int tamLog);

    VDinamico(const VDinamico<T> &origen);

    VDinamico<T>(const VDinamico<T> &origen, unsigned int posicionInicial, unsigned int numElementos);

    virtual ~VDinamico();

    VDinamico &operator=(const VDinamico<T> &orig);

    T &operator[](unsigned int pos);

    void insertar(const T &dato, unsigned int pos = UINT_MAX);

    T borrar(unsigned int pos = UINT_MAX);

    unsigned int busquedaBin(T &dato);

    void ordenar();

    void ordenarRev();

    unsigned int getTamLog() const;

};

/* IMPLEMENTACION DE LA CLASE */
/* CONSTRUCTORES */

/**
 * @brief Constructor por defecto
 */
template<class T>
VDinamico<T>::VDinamico() : tamaf(1), tamLog(0) {
    v = new T[tamaf];

};

/**
 * @brief Constructor parametrizado
 * @post Inicializa un VDinamico, el tamaño lógico será proporcionado por el usuario y el
 * físico será la potencia de 2 siguiente a este tamanio lógico
 * @param tam
 */
template<class T>
VDinamico<T>::VDinamico(unsigned int tamLog) : tamLog(0) {
    int potencia = 1;
    while (tamLog > potencia) {
        potencia = potencia * 2;
    }
    tamaf = potencia;
    v = new T[tamaf];
};

/**
 * @brief Constructor copia
 * @post Crea una copia de
 * @param orig
 */
template<class T>
VDinamico<T>::VDinamico(const VDinamico<T> &origen) : tamLog(origen.tamLog) {
    v = new T[tamaf = origen.tamaf];
    for (int i = 0; i < tamLog; ++i)
        v[i] = origen.v[i];
}

/**
 * @brief Constructor copia parcial
 * @post Crea una copia parcial
 * @param orig
 * @param inicio
 * @param num
 */
template<class T>
VDinamico<T>::VDinamico(const VDinamico<T> &origen, unsigned int posicionInicial, unsigned int numElementos) :
        VDinamico<T>::VDinamico(numElementos) {
    if (posicionInicial >= origen.tamLog || posicionInicial + numElementos > origen.tamLog)
        throw std::out_of_range("{VDinamico::operator[]} El parametro insertado está fuera de rango");
    for (int i = 0; i < numElementos; i++) {
        this->v[i] = origen.v[posicionInicial];
        posicionInicial++;
    }
}

/**
 * @brief Operador de asignación
 * @post Sobrecarga del operador de asignación
 * @param right
 */
template<class T>
VDinamico<T> &VDinamico<T>::operator=(const VDinamico<T> &orig) {
    if (this != &orig) {
        delete[] v;
        tamLog = orig.tamLog;
        tamaf = orig.tamaf;
        v = new T[tamaf];
        for (int i = 0; i < tamLog; i++) {
            v[i] = orig.v[i];
        }
    }
    return *this;
}

/**
 * @brief Operador []
 * @post Sobrecarga del operador []
 * @param pos
 */
template<class T>
T &VDinamico<T>::operator[](unsigned pos) {
    if (pos < 0 || pos >= tamaf)
        throw out_of_range("La posicion es incorrecta");
    return v[pos];
}

/**
 * @brief Insertar
 * @post Inserta un dato en la posición indicada, sino se indica el dato,
 * la inserción será realizada al final del vector
 * @tparam T
 * @param dato
 * @param pos
 */
template<class T>
void VDinamico<T>::insertar(const T &dato, unsigned int pos) {
    if (pos == UINT_MAX) {
        if (tamLog == tamaf) {
            T *datoAux;
            datoAux = new T[tamaf = tamaf * 2];
            for (int i = 0; i < tamLog; i++)
                datoAux[i] = v[i];
            delete[]v;
            v = datoAux;
        }
        pos = tamLog;
        v[pos] = dato;
        tamLog++;
    } else {
        if (pos == tamLog) {
            if (tamLog == tamaf) {
                T *datoAux;
                datoAux = new T[tamaf = tamaf * 2];
                for (unsigned int i = 0; i < tamLog; i++)
                    datoAux[i] = v[i];
                delete[]v;
                v = datoAux;
            }
            v[tamLog] = dato;
            tamLog++;
        } else {
            if (tamLog == tamaf) {
                T *auxiliar;
                auxiliar = new T[tamaf = tamaf * 2];
                for (int i = 0; i < tamLog; i++)
                    auxiliar[i] = v[i];
                delete[]v;
                v = auxiliar;
            }
            int t = tamLog - 1;
            for (t; t >= pos; t--) {
                v[t + 1] = v[t];
            }
            v[pos] = dato;
            tamLog++;
        }
    }
}

/**
 * @brief Borrar
 * @post Borra un dato de la posicion, sino se indica el dato, se borrará el último elemento del v
 * @param unsigned int pos
 * @return elemento borrado
 */
template<class T>
T VDinamico<T>::borrar(unsigned pos) {
    T valorAux;
    if (tamLog == 0) {
        throw length_error("No se puede borrar el v porque esta vacio");
    }
    if (pos == UINT_MAX) {
        if (tamLog * 3 < tamaf) {
            tamaf = tamaf / 2;
            T *auxiliar = new T[tamaf];
            for (int i = 0; i < tamLog; ++i)
                auxiliar[i] = v[i];
            delete[]v;
            v = auxiliar;
        }
        valorAux = v[tamLog - 1];
        return valorAux;
    }

    if (pos >= tamLog) {
        throw out_of_range("La posicion es incorrecta");
    }
    if (tamLog * 3 < tamaf) {
        tamaf = tamaf / 2;
        T *auxiliar = new T[tamaf];
        for (int i = 0; i < tamLog; ++i)
            auxiliar[i] = v[i];
        delete[]v;
        v = auxiliar;
    }
    tamLog--;
    return valorAux;
}

/**
 * @brief funcion para devolver el tamanio logico
 * @return devuelve el tamanio logico
 */
template<class T>
unsigned int VDinamico<T>::getTamLog() const {
    return tamLog;
}

/**
 * @brief Busqueda binaria
 * @post Busca un dato en el v utilizando búsqueda binaria o dicotómica y devolviendo
   la posición del dato.
 * @param dato
 * @return posicion del elemento
 */
template<class T>
unsigned int VDinamico<T>::busquedaBin(T &dato) {
    int inferior = 0, superior = tamLog - 1, mitad;
    while (inferior <= superior) {
        mitad = (superior + inferior) / 2;
        if (v[mitad] == dato) {
            return mitad;
        } else {
            if (v[mitad] < dato) {
                inferior = mitad + 1;
            } else {
                superior = mitad - 1;
            }
        }
    }
    cerr << dato << endl << "no encontrado" << endl;
    return -1;
}

/**
 * @brief Función para ordenar un v
 * @post Ordena el v atendiendo a la prioridad del objeto
 */
template<class T>
void VDinamico<T>::ordenar() {
    sort(v, v + tamLog);
}

/**
 * @brief Ordena un v al contrario
 */
template<typename T>
void VDinamico<T>::ordenarRev() {
    std::sort(v, v + tamLog, greater<T>());
}

/**
 * @brief Destructor
 */
template<class T>
VDinamico<T>::~VDinamico() {
    delete[] v;
}

#endif //PR1_VDINAMICO_H
