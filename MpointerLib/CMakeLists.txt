cmake_minimum_required(VERSION 3.28)
project(MpointerLib)

set(CMAKE_CXX_STANDARD 26)

# Añadir directorio de los encabezados
include_directories(${CMAKE_SOURCE_DIR}/include)

# Crear la biblioteca estática
add_library(MPointerLib STATIC
        include/MPointer.tpp
        src/MPointerGC.cpp
)

# Especificar archivos de encabezado para la instalación
install(FILES include/MPointer.h include/MPointerGC.h DESTINATION include)