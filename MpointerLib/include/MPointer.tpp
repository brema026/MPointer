#include "MPointer.h"

// Constructor privado para el método estático New()
template <typename T>
MPointer<T>::MPointer() {
    ptr = new T;  // Reservar memoria para el tipo T
    id = MPointerGC::getInstance().registerPointer(this);  // Registrar en GC
}

// Método estático para crear un nuevo MPointer
template <typename T>
MPointer<T> MPointer<T>::New() {
    return MPointer<T>();
}

// Sobrecarga del operador *
template <typename T>
T& MPointer<T>::operator*() {
    return *ptr;
}

// Sobrecarga del operador &
template <typename T>
T* MPointer<T>::operator&() {
    return ptr;
}

// Sobrecarga del operador de asignación entre MPointers
template <typename T>
MPointer<T>& MPointer<T>::operator=(const MPointer<T>& other) {
    if (this != &other) {
        this->ptr = other.ptr;
        this->id = other.id;
    }
    return *this;
}

// Sobrecarga del operador de asignación para valores internos
template <typename T>
MPointer<T>& MPointer<T>::operator=(const T& value) {
    *ptr = value;
    return *this;
}

// Destructor que llama a clear y desregistra el puntero del GC
template <typename T>
MPointer<T>::~MPointer() {
    MPointerGC::getInstance().deregisterPointer(id);
    clear();
}

// Método clear para limpiar el contenido del puntero en lugar de eliminarlo
template <typename T>
void MPointer<T>::clear() {
    if (ptr) {
        *ptr = T();  // Establecer el valor por defecto del tipo T
    }
}
