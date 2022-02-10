/***********************************************************************
 * Module:  ListaDobleCircular.h
 * Author:  Alvaro Zuma, Johnny Loachamin
 * Modified: Wednesday, February 09, 2021 22:51:10 PM
 * Purpose: Declaration of the class ListaDobleCircular
 ***********************************************************************/

#if !defined(__MACHINE4FUN_LISTA_DOBLE2_ListaDobleCircular_h)
#define __MACHINE4FUN_LISTA_DOBLE2_ListaDobleCircular_h

#include "Nodo.h"
#include "Maquina.h"

class ListaDobleCircular
{
public:
   bool vacia(void);
   void insertarInicio(Maquina newMaquina);
   void insertarFinal(Maquina newMaquina);
   void insertarPosicion(int newPosicion, Maquina newMaquina);
   int buscarPosicionMaquinaId(int idMaquina);
   void modificarPorId(int idMaquina, Maquina maquina);
   void eliminar(int id);
   void imprimir(void);
   void imprimirNodo(Nodo* nodo);
   int tamanioLista(void);
   void crearTxt(Nodo* nodo);

protected:
private:
   Nodo* primero;
   Nodo* ultimo;


};

#endif

