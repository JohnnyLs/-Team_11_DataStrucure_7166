/***********************************************************************
 * Module:  Operador.cpp
 * Modified: Wednesday, February 09, 2021 19:31:50 PM
 * Purpose: Implementation of the class Nodo
 ***********************************************************************/

#include "Nodo.h"

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::Nodo()
// Purpose:    Implementation of Nodo::Nodo()
// Return:     
////////////////////////////////////////////////////////////////////////

Nodo::Nodo()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::~Nodo()
// Purpose:    Implementation of Nodo::~Nodo()
// Return:     
////////////////////////////////////////////////////////////////////////

Nodo::~Nodo()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::getLibro()
// Purpose:    Implementation of Nodo::getLibro()
// Return:     Libro
////////////////////////////////////////////////////////////////////////

Maquina Nodo::getMaquina(void)
{
   return maquina;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::setMaquina(Libro newMaquina)
// Purpose:    Implementation of Nodo::setMaquina()
// Parameters:
// - newMaquina
// Return:     void
////////////////////////////////////////////////////////////////////////

void Nodo::setMaquina(Maquina newMaquina)
{
   maquina = newMaquina;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::getAnterior()
// Purpose:    Implementation of Nodo::getAnterior()
// Return:     Nodo*
////////////////////////////////////////////////////////////////////////

Nodo* Nodo::getAnterior(void)
{
   return anterior;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::setAnterior(Nodo* newAnterior)
// Purpose:    Implementation of Nodo::setAnterior()
// Parameters:
// - newAnterior
// Return:     void
////////////////////////////////////////////////////////////////////////

void Nodo::setAnterior(Nodo* newAnterior)
{
   anterior = newAnterior;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::getSiguiente()
// Purpose:    Implementation of Nodo::getSiguiente()
// Return:     Nodo*
////////////////////////////////////////////////////////////////////////

Nodo* Nodo::getSiguiente(void)
{
   return siguiente;
}

////////////////////////////////////////////////////////////////////////
// Name:       Nodo::setSiguiente(Nodo* newSiguiente)
// Purpose:    Implementation of Nodo::setSiguiente()
// Parameters:
// - newSiguiente
// Return:     void
////////////////////////////////////////////////////////////////////////

void Nodo::setSiguiente(Nodo* newSiguiente)
{
   siguiente = newSiguiente;
}
