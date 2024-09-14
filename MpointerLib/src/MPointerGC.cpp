#include "MPointerGC.h"

#include "MPointer.h"

// Constructor privado
MPointerGC::MPointerGC() : nextId(0) {}

// Obtener la instancia Singleton
MPointerGC& MPointerGC::getInstance() {
    static MPointerGC instance;
    return instance;
}

// Registrar un puntero y devolver su id
int MPointerGC::registerPointer(void* ptr) {
    std::lock_guard<std::mutex> lock(mtx);
    int id = nextId++;
    pointers[id] = ptr;
    return id;
}

// Desregistrar un puntero cuando se destruye
void MPointerGC::deregisterPointer(int id) {
    std::lock_guard<std::mutex> lock(mtx);
    pointers.erase(id);
}

// Limpiar todos los punteros registrados (si es necesario)
void MPointerGC::clearAllPointers() {
    std::lock_guard<std::mutex> lock(mtx);
    for (auto& entry : pointers) {
        if (entry.second) {
            // Implementación para limpiar los punteros si fuera necesario
            MPointer<int>* mpointer = static_cast<MPointer<int>*>(entry.second);
            mpointer->clear();
        }
    }
}
