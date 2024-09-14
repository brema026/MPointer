#ifndef MPOINTERGC_H
#define MPOINTERGC_H

#include <unordered_map>
#include <mutex>

class MPointerGC {
private:
    std::unordered_map<int, void*> pointers;
    int nextId;
    std::mutex mtx;

    // Constructor privado para Singleton
    MPointerGC();

public:
    // Singleton Instance
    static MPointerGC& getInstance();

    // Registrar un puntero y devolver su id
    int registerPointer(void* ptr);

    // Desregistrar un puntero cuando se destruye
    void deregisterPointer(int id);

    // Método para limpiar la memoria de los punteros si fuera necesario
    void clearAllPointers();

    // Evitar que se puedan copiar o mover
    MPointerGC(const MPointerGC&) = delete;
    MPointerGC& operator=(const MPointerGC&) = delete;
};

#endif // MPOINTERGC_H
