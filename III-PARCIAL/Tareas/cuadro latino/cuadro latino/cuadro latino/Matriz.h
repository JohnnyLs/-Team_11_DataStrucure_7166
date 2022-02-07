#pragma once
class Matriz
{
private:
	int d;
	int** mat;
public:
	Matriz() = default;
	int getD();
	int setD();
	int** getMtriz();
	void setMatriz(int**);
	int** segmentar(int);
	void encerar(int);
	void ingresar(int**, int);
	void imprimir(int**, int);
	void procesar(int**, int**, int**, int)
};
