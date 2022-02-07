#include "Operaciones.h"
#include<iostream>
using namespace std;

int Operaciones::llenar(int fil, int indice) {
    if (fil == 1)
        return 1;
    if (indice == 0 || indice == fil - 1)
        return 1;
    else
        return llenar(fil - 1, indice - 1) + llenar(fil - 1, indice);
}

void Operaciones::espacio(int n) {
    if (n > 0) {
        cout << " ";
        espacio(n - 1);
    }
    else cout << "";
}
void Operaciones::imprimir(int pos, int fil,int n, int esp, bool band) {

    if (fil <= n) {
        if (band == true) {
            espacio(esp);
            band = false;
        }
        cout << llenar(fil, pos) << " ";
        if (pos < fil - 1)
            imprimir(pos + 1, fil, n, esp, band);
        else {
            cout << endl;
            band = true;
            imprimir(0, fil + 1, n, esp - 1, band);
        }
    }
    else {
        cout << endl;
        band = true;
    }
}
void Operaciones::triangulo(int fill){
    imprimir(0, 1, fill,fill, true);
}