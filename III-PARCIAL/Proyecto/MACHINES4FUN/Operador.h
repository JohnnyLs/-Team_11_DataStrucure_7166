/***********************************************************************
 * Module:  Operador.h
 * Author:  Alvaro Zuma, Johnny Loachamin
 * Modified: Tuesday, February 08, 2021 18:21:50 PM
 * Purpose: Declaration of the class Operador
 ***********************************************************************/

#if !defined(__MACHINES4FUN_LISTA_DOBLE2_Operador_h)
#define __MACHINES4FUN_LISTA_DOBLE2_Operador_h

#include "Persona.h"

class Operador
{
public:
   Operador();
   ~Operador();
   Persona getPersona(void);
   void setPersona(Persona newPersona);
   int getNumSeccion(void);
   void setNumSeccion(int newNumSeccion);

protected:
private:
   Persona persona;
   int numSeccion;


};

#endif

