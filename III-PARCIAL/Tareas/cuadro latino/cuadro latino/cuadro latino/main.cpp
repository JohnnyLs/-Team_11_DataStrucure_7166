/***********************************************************************
            UFA-ESPE
            SOFTWARE
            Autores: Chasiluisa Santiago, Chicango George,
                Gualotu�a Omar, Loacham�n Johnny, Zumba Alvaro
            Fecha de creaci�n: 01/06/2021
            Fecha de modificaci�n: 05/06/2021
 ***********************************************************************/

#include <iostream>
#include "Matriz.h"
using namespace std;
int main()
{

    int tamanio;
    do {
        cout << "Ingrese el tamanio de la matriz: ";
        cin >> tamanio;
        if (tamanio <= 0 || tamanio <= 1) {

            cout << "Numero incorrecto" << endl;
        }

    } while (tamanio <= 1);
    Matrix<int>* matriz = new Matrix<int>(tamanio, tamanio);
    matriz->reservarMemoria();
    int k = tamanio;
    int m = 0;
    int p = 0;
    int l = 0;
    for (int i = 0; i < tamanio; i++)
    {
        if (i == 0)
            for (int j = 0; j < tamanio; j++) {
                matriz->setValue(i, j, j + 1);
            }
        else {
            for (int j = k + 1; j <= tamanio; j++) {
                matriz->setValue(i, l, j);
                l++;
            }
            for (int m = 0; m < tamanio - p; m++) {
                matriz->setValue(i, l, m + 1);
                l++;
            }
        }
        k = k - 1;
        p = p + 1;
        cout << "\n";
        l = 0;
    }
    for (int i = 0; i < matriz->getRows(); i++) {
        for (int j = 0; j < matriz->getColumns(); j++) {
            cout << matriz->getValue(i, j) << " ";
        }
        cout << endl;
    }
    delete matriz;
    return 0;
}
