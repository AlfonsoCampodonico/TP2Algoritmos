cmake_minimum_required(VERSION 3.16)
project(TP2Algoritmos)

set(CMAKE_CXX_STANDARD 17)

add_executable(TP2Algoritmos
        src/main.cpp
        src/Tablero.cpp src/Tablero.h
        src/Celula.cpp src/Celula.h
        src/Intensidad.cpp src/Intensidad.h
        src/InformacionGenetica.cpp src/InformacionGenetica.h
        src/InterfazUsuario.cpp src/InterfazUsuario.h
        src/JuegoDeLaVida.cpp src/JuegoDeLaVida.h
        src/Nodo.h
        src/Lista.h
        src/Informes.cpp src/Informes.h
        src/Gen.cpp src/Gen.h
        src/Bits.cpp src/Bits.h
        src/Colores.h src/Colores.cpp
        src/ImpresoraDeImagenes.cpp src/ImpresoraDeImagenes.h
        src/EasyBMP.cpp src/EasyBMP.h
        src/EasyBMP_BMP.h
        src/EasyBMP_DataStructures.h
        src/EasyBMP_VariousBMPutilities.h)
