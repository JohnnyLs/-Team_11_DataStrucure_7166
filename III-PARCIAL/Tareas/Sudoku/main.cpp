/******************  Universidad de las Fuerzas Armadas ESPE  ************************
 *				Carrera: Software													 *
 *				Autores: Loachamin Johnny, Zumba ALvaro								 *
 *				Fecha de creacion: 11/02/2022										 *
 *				Fecha de modificación: 13/02/2022									 *
 *************************************************************************************/
#include "Operaciones.h"
#include"Operaciones.cpp"
#include<iostream>
using namespace std;
int main() {
    Operaciones op;
    int **matriz;
    matriz = op.resolver(matriz);
	system("pause");
    op.tablero(matriz);
    return 0;
}

