#include "Operaciones.h"
#include<iostream>
using namespace std;

int Operaciones::factorial(int n)
{
    int f = 1;
    for (int i = 1; i <= n; i++)
        f = f*i;
    return f;
}

int Operaciones::combinacion(int n, int k)
{
    return (factorial(n)/(factorial(k)*(factorial(n - k))));
}

