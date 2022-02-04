#pragma once
#include <iostream>
#define vertices 500
#define nodos 300
using namespace std;

struct  orden{
int  grado; //representa el numero  de conexiones
int  color; // representa el valor del numero
int  n;  //representa el numero  de vertice 
};
typedef struct  orden ver;
int B[nodos];//,ad[vertices][vertices];


class OperacionesMatriz{
	
	public:
		OperecionesMatriz();
		void IngresarMatriz(int ad[][vertices],int nds, int arst);
		void BusquedaExhaustiva(int ad[][vertices],int nds);
}
