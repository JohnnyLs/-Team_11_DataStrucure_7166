#include "Cuadro.h"
#include "Matriz.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void Cuadro::cuadroLatino(Matriz matriz)
{
	int** matA = matrix.getMatriz();
	for (int i = 0; i < matrix.getD(); i++)
	{
		for (int j = 0; j < matrix.getD(); j++)
		{
			if (i == 0)
			{
				matA[i][j] = j + 1;
			}
			else
			{
				if (matA[i - 1][j] < matrix.get())
				{
					matA[i][j] = matA[i - 1][j] + 1;
				}
				else
				{
					matA[i][j] = 1;
				}
			}
		}
	}

}
