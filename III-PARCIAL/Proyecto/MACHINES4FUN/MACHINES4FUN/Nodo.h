/******************  Universidad de las Fuerzas Armadas ESPE  ************************
 *				Carrera: Software													 *							 *
 *				Fecha de creacion: 04/02/2022										 *
 *				Fecha de modificación: 10/02/2022									 *
 *************************************************************************************/

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

