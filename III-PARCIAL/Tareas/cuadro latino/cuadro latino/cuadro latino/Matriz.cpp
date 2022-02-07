#include "Matriz.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;
int** Matriz::get_matriz() {
	return mat;
}

void Matriz::set_matriz(int** m1) {
	mat = m1;
}
int** segmentar(int d) {
	int** mat, i;
	mat = (int**)malloc(d * sizeof(int*));
	for (i = 0; i < d; i++) {
		*(mat + i) = (int*)malloc(d * sizeof(int));
	}
	return mat;
}
void encerar(int** mat, int d) {
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			*(*(mat + i) + j) = 0;
		}
	}
	return;
}
void ingresar(int** mat, int d) {
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			scanf("%i", &(*(*(mat + i) + j)));
		}
	}
}
void imprimir(int** mat, int d) {
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			printf("%d", *(*(mat + i) + j));
			printf("%*s", j + 5, "");
		}
		printf("\n");
	}
}
void procesar(int** m1, int** m2, int** mr, int d) {
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			for (int h = 0; h < d; h++) {
				*(*(mr + i) + j) = *(*(mr + i) + j) + (*(*(m1 + i) + h)) * (*(*(m2 + h) + j));
			}
		}
	}
}
