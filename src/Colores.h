/*
 * Colores.h
 *
 *  Created on: 8 feb. 2021
 *      Author: usuario
 */

#ifndef COLORES_H_
#define COLORES_H_
#include "EasyBMP.h"
class Color{

	private:
		RGBApixel* paletaDeColores;
	public:
		Color();
		void Negro();
		void Amarillo();
		void Verde();
		~Color();
};




#endif /* COLORES_H_ */
