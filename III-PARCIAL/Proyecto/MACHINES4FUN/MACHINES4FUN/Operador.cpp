/***********************************************************************
 * Module:  Operador.h
 * Modified: Tuesday, February 08, 2021 18:30:00 PM
 * Purpose: Declaration of the class Operador
 ***********************************************************************/

#include "Operador.h"

////////////////////////////////////////////////////////////////////////
// Name:       Operador::Operador()
// Purpose:    Implementation of Operador::Operador()
// Return:     
////////////////////////////////////////////////////////////////////////

Operador::Operador()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Operador::~Operador()
// Purpose:    Implementation of Operador::~Operador()
// Return:     
////////////////////////////////////////////////////////////////////////

Operador::~Operador()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Operador::getPersona()
// Purpose:    Implementation of Operador::getPersona()
// Return:     Persona
////////////////////////////////////////////////////////////////////////

Persona Operador::getPersona(void)
{
   return persona;
}

////////////////////////////////////////////////////////////////////////
// Name:       Operador::setPersona(Persona newPersona)
// Purpose:    Implementation of Operador::setPersona()
// Parameters:
// - newPersona
// Return:     void
////////////////////////////////////////////////////////////////////////

void Operador::setPersona(Persona newPersona)
{
   persona = newPersona;
}

////////////////////////////////////////////////////////////////////////
// Name:       Operador::getNumSeccion()
// Purpose:    Implementation of Operador::getNumSeccion()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Operador::getNumSeccion(void)
{
   return numSeccion;
}

////////////////////////////////////////////////////////////////////////
// Name:       Operador::setNumSeccion(int newNumSeccion)
// Purpose:    Implementation of Operador::setNumSeccion()
// Parameters:
// - newNumSeccion
// Return:     void
////////////////////////////////////////////////////////////////////////

void Operador::setNumSeccion(int newNumSeccion)
{
   numSeccion = newNumSeccion;
}
