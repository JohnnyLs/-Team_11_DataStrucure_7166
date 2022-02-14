#include"Operaciones.h"
#include<iostream>

using namespace std;

int** Operaciones::inicialiar(int dim) {
    matriz = (int**) malloc(sizeof (int *)*dim);
    for (int i = 0; i < dim; i++) {
        *(matriz + i) = (int*) malloc(sizeof (int*)*dim);
    }
    return matriz;
}

void Operaciones::tablero(int **matriz) {
    cout << "\n sudoku"<<endl;
    for (int i = 0; i < 9; i++) {
        cout<<"\n";
        if (i == 3 || i == 6) {
            cout <<"----------------------------"<<endl;
        }
        for (int j = 0; j < 9; j++) {
            if (j == 3 || j == 6) {
                cout<<"|";
            }
            cout << " " << *(*(matriz + i) + j) << " ";
        }
    }
}


int** Operaciones::resolver(int **matriz) {
    srand(time(NULL));
    do {
        contador2 = 0;
        matriz = inicialiar(10);
        //Enceramos la matriz
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                *(*(matriz + i) + j) = 0;
                contador = 0;
                do {
                    aleatorio = rand() % 9 + 1;
                    detener = validar(aleatorio, 9, i, j, matriz);
                    contador++;
                    if (contador > 18) {
                        i = 9;
                        j = 9;
                    }
                } while (detener == 1);
                *(*(matriz + i) + j) = aleatorio;
                //Aumenta el numero de 1 en 1 hasta llegar a 81 para terminar el ciclo do-while
                contador2++;
            }
        }
    } while (contador2 != 81);
    return matriz;
}

/* controla que los numeros no se repitan por fila y columna
*/
int Operaciones::validar(int numero, int dim, int contador, int contador2, int **matriz) {
    detener = 0;
    for (int i = 0; (i<dim && detener == 0); i++) {
        //Se va desplazando y comprueba si el espacio en donde está ubicado es igual al numero aleatorio generado tanto en fila como columna
        if (*(*(matriz + contador) + i) == numero || *(*(matriz + i) + contador2) == numero) {
            detener = 1;
        }
    }
    return detener;
}


