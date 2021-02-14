//
// Created by alfon on 2/6/2021.
//

#include "Bits.h"

using namespace std;

Bits::Bits(unsigned int ancho, unsigned int alto){
    this->imagen = new BMP;
    this->alto = alto;
    this->ancho = ancho;
    this->imagen->SetSize(ancho, alto);
    this->imagen->SetBitDepth(24);
}

void Bits::asignar(unsigned int pixelX, unsigned int pixelY, Color* nuevoColor){
    this->imagen->SetPixel(pixelX, pixelY, nuevoColor->obtenerPixel());
}

void Bits::escribir(string nombreDelArchivo){
    string nombre = (nombreDelArchivo+".BMP");
    this->imagen->WriteToFile(nombre.c_str());
}

Bits::~Bits() {
    delete this->imagen;
}
