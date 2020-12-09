//
// Created by alfon on 11/28/2020.
//
#include <iostream>
using namespace  std;
#include "JuegoDeLaVida.h"
int main () {
    JuegoDeLaVida* elJuegoDeLaVida;
    elJuegoDeLaVida = new JuegoDeLaVida();
    elJuegoDeLaVida->jugar();
    delete elJuegoDeLaVida;
    return 0;
}