/******************************************************************
*            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE              *
* CARRERA: Ingenieria de Software                                 *
* MATERIA: Estructura de Datos                                    *
******************************************************************/
#pragma once
#include <time.h>
#include <stdlib.h>

class Operaciones {
	public:
	    int** inicialiar(int);
	    void tablero(int**);
	    int** resolver(int**);
	    int validar(int, int, int, int, int**);
	private:
	    int **matriz;
	    int detener;
	    int aleatorio;
	    int contador;
	    int contador2;
};


