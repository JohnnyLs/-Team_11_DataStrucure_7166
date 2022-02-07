#include <iostream>
#include "Cuadro.h"
#include "Matriz.h"


using namespace std;

int main()
{
	int d;

	do
	{
		d=("\nIngrese la dimension del cuadro: ");
	} while (dimension < 1 || dimension % 2 == 0);

	Matriz mat(d);
	CLatino cuadroLatino;

	mat.segmentar(d);
	mat.encerar(d);

	cuadroLatino.cuadroLatino(mat);

	mat.imprimir(d);

	return 0;

}
