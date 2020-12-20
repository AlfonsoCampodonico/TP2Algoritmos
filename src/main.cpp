//
// Created by alfon on 11/28/2020.
//
#include <iostream>
using namespace  std;
#include "JuegoDeLaVida.h"
int main () {
    JuegoDeLaVida* elJuegoDeLaVida;
    elJuegoDeLaVida = new JuegoDeLaVida();
    elJuegoDeLaVida->jugarElJuegoDeLaVida();
    delete elJuegoDeLaVida;
    return 0;
}