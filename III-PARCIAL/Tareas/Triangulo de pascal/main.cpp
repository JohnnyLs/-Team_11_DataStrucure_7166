/******************  Universidad de las Fuerzas Armadas ESPE  ************************
 *				Carrera: Software													 *
 *				Autores: Loachamin Johnny, Zumba ALvaro								 *
 *				Fecha de creacion: 05/02/2022										 *
 *				Fecha de modificación: 07/02/2022									 *
 *************************************************************************************/
#include <iostream>
#include "Operaciones.h"
#include <stdio.h>
using namespace std;
int main()
{
    Operaciones op;
    int fill= 0;
    setlocale(LC_ALL, "spanish");
    while (fill< 1) {
        cout << "Ingrese el número de filas:";
        cin >> fill;
    }
    op.triangulo(fill);
}
