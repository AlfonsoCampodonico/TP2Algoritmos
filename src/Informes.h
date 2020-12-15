/*
 * informes.h
 *
 *  Created on: 10 dic. 2020
 *      Author: usuario
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "Celula.h"



class Informes{
	private:
		int cantidadTurnos;
		int celulasVivas;
		int nacimientosTurnos;
		int nacimientosTotales;
		int muertesTurnos;
		int muertesTotales;
		int promedioNacimiento;
		int promedioMuertes;
		int juegoCongelado;
        int nacimientos;
        int muertes;

	public:
		/*
		 * Post: Crea un informe con to do inicializado en 0.
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
		void contarCelulasVivas();

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
		 * Post: Devuelve la cantidad de nacimientos en el ultimo turno
		 */
		unsigned int obtenerNacimientosTurno();

		/* Pre:-
		 * Post: Devuelve la cantidad de muertes en el ultimo turno
		 */
		unsigned int obtenerMuertesTurno();

		/*Post: Suma una celula viva
		 *
		 */
		void sumarViva();
		/*Pre:-
		 * Post: Devuelve si el juego está congelado o no
		 */
		bool estaCongelado();

		void resetearMuertesTurno();

		void resetearNacimientosTurno();

		void resetearTurnos();

		void resetearVivas();

		void resetearNacimientosTotales();

		void resetearMuertesTotales();

		void sumarNacimientosTotales();

		void sumarMuertesTotales();


    int obtenerMuertesTotales();

    int obtenerNacimientosTotales();

    void resetearMuertes();
};



#endif /* INFORMES_H_ */
