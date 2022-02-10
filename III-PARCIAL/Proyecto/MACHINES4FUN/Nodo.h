/***********************************************************************
 * Module:  Operador.h
 * Author:  Alvaro Zuma, Johnny Loachamin
 * Modified: Wednesday, February 09, 2021 19:21:50 PM
 * Purpose: Declaration of the class Nodo
 ***********************************************************************/

#if !defined(__MACHINES4FUN_LISTA_DOBLE2_Nodo_h)
#define __MACHINES4FUN_LISTA_DOBLE2_Nodo_h

#include "Maquina.h"

class Nodo
{
public:
   Nodo();
   ~Nodo();
   Maquina getMaquina(void);
   void setMaquina(Maquina newMaquina);
   Nodo* getAnterior(void);
   void setAnterior(Nodo* newAnterior);
   Nodo* getSiguiente(void);
   void setSiguiente(Nodo* newSiguiente);

protected:
private:
   Maquina maquina;
   Nodo* anterior;
   Nodo* siguiente;


};

#endif

