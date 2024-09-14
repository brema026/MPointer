#ifndef MPOINTER_H
#define MPOINTER_H

#include "MPointerGC.h"
#include <iostream>

template <typename T>
class MPointer {
private:
    T* ptr;
    int id;

    // Constructor privado para uso interno en New()
    MPointer();

public:
    // Método estático para crear una nueva instancia de MPointer
    static MPointer<T> New();

    // Sobrecarga del operador *
    T& operator*();

    // Sobrecarga del operador &
    T* operator&();

    // Sobrecarga del operador de asignación
    MPointer<T>& operator=(const MPointer<T>& other);

    // Sobrecarga del operador de asignación para tipos internos
    MPointer<T>& operator=(const T& value);

    // Destructor
    ~MPointer();

    // Método para limpiar el contenido del puntero
    void clear();
};

#include "MPointer.tpp"

#endif // MPOINTER_H
