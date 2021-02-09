/*
 * informes.h
 *
 *  Created on: 10 dic. 2020
 *      Author: usuario
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "Celula.h"
#include "Tablero.h"
#include "EasyBMP.h"
class Celula;
class Tablero;
class BMP;
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
		void contarCelulasVivas(Tablero* tablero);


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

        /* Pre:
         * Post: devuelve a 0 el valor de muertes por turno
         */
		void resetearMuertesTurno();

        /* Pre:
         * Post: devuelve a 0 el valor de nacimientos por turno
         */
		void resetearNacimientosTurno();

        /* Pre:
         * Post: devuelve a 0 el valor de celulas vivas en el tablero
         */
		void resetearVivas();

        /* Pre:
         * Post: devuelve a 0 el valor de cantidad de turnos
         */
        void resetearTurnos();

        /* Pre:
         * Post: suma el valor de nacimientos en el turno al acumulado de nacimientos totales
         */
		void sumarNacimientosTotales();

        /* Pre:
         * Post: suma el valor de muertes en el turno al acumulado de muertes totales
         */
		void sumarMuertesTotales();

        /*Pre:
        * Post: Devuelve la cantidad de muertes totales */
		int obtenerMuertesTotales();

        /*Pre:
         * Post: Devuelve la cantidad de nacimientos totales */
		int obtenerNacimientosTotales();



        /*Pre:
         * Post: Devuelve el promedio de nacimientos del turno */
        float obtenerPromedioNacimiento();

        /*Pre:
        * Post: Devuelve el promedio de muertes del turno */
        float obtenerPromedioMuertes();

        /*Pre:
         * Post: Devuelve la cantidad de celulas vivas en un turno */
        unsigned int obtenerCelulasVivas();

        /*Pre:
         * Post: Devuelve a 0 los datos de turnos
         * */
        void resetearInformeTurno();

        /*Pre: recibe un tablero para actualizar la informacion de un gen
         * Post: Actualiza la informacion en el informe despues de ejecutar un turno
         */
        void actualizarInformeTurno(Tablero *tablero);

        /*Pre: recibe una listaGenes de una celula en especifica
         * Post: Actualiza la edad de los genes sumandole 1
         *
         */
        void actualizarEdadGen(Lista<Gen *> *listaGenes);

        /*PRE:
         * POST Reinicia el informe
         * */
        void reiniciarInforme();
        /* Pre: Se le debe pasar un tablero  como parametro
         * Post: Imprime una foto del tablero en formato bmp
         */
        void imprimirBmpTablero(Tablero* tablero);
};



#endif /* INFORMES_H_ */
