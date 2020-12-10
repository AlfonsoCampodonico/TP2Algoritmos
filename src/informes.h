/*
 * informes.h
 *
 *  Created on: 10 dic. 2020
 *      Author: usuario
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "Tablero.h"

class Informes{
	private:
		int cantidadTurnos;
		int celulasVivas;
		int celulasQueNacenEnElTurno;
		int celulasQueMuerenEnElTurno;
		int promedioNacimiento;
		int promedioMuertes;
		int juegoCongelado;

	public:
		/*
		 * Post: Crea un informe con todo inicializado en 0.
		 */
		Informes();

		/* Pre:-
		 * Post: Suma un turno al contador cantidadTurnos
		 */
		void sumarTurno();
		/* pre:-
		 * Post: suma un nacimiento
		 */
		void sumarNacimiento();
		/*Pre: -
		 * Post: Suma una muerte.
		 */
		void sumarMuerte();
		/*Pre:El tablero ya debe estar inicializado para analizarlo
		 * Post: Devuelve un int con la cantidad de celulas vivas que tiene el tablero
		 */
		int contabilizarCelulasVivas(Tablero* tablero);

		/*Pre: -
		 * Post: Analizara si el juego se congelo y sumará uno
		 */
		void seCongelo();
		/* Pre:cantidadTurnos debe ser mayor a 0
		 * Post: Promedia los nacimientos
		 */
		void promediarNacimiento();

		/* Pre: Cantidad de turnos debe ser mayor a 0
		 * Post: Promedia las muertes.
		 */
		void promediarMuertes();

		/* Pre:-
		 * Post Devuelve la cantidad de turnos
		 */
		unsigned int obtenerTurnos();

		/* Pre:-
		 * Post: Devuelve la cantidad de nacimientos
		 */
		unsigned int obtenerNacimientos();

		/* Pre:-
		 * Post: Devuelve la cantidad de muertes
		 */
		unsigned int obtenerMuertes();





};



#endif /* INFORMES_H_ */
