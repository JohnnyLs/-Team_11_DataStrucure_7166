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
    int n= 0;
    int i, j;
    setlocale(LC_ALL, "spanish");
    cout << "ingrese el numero de filas: ";
    cin >> n;

    for (int i = n-1; i >=0 ; i--) 
    {
        //Triangulo de pascal invertido
        for (j = 0; j <= n - i; j++)
            cout << " ";
        //imprime la combinacion de i y j
        for (j = 0; j <= i; j++)
            cout << op.combinacion(i, j) << " ";
        cout << endl;
    }  
    return 0;
}
