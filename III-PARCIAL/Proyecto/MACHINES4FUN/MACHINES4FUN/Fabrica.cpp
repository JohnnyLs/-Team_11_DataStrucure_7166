/***********************************************************************
 * Module:  Fabrica.cpp
 * Modified: Sunday, Febraury 8, 2022 17:59:40 PM
 * Purpose: Implementation of the class Fabrica
 ***********************************************************************/

#include "Fabrica.h"

////////////////////////////////////////////////////////////////////////
// Name:       Fabrica::Fabrica()
// Purpose:    Implementation of Fabrical::Fabrica()
// Return:     
////////////////////////////////////////////////////////////////////////

Fabrica::Fabrica()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Fabrica::~Fabrica()
// Purpose:    Implementation of Fabrica::~Fabrica()
// Return:     
////////////////////////////////////////////////////////////////////////

Fabrica::~Fabrica()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Fabrica::getIdFabrica()
// Purpose:    Implementation of Fabrical::getIdFabrica()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Fabrica::getIdFabrica(void)
{
   return idFabrica;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fabrica::setIdFabrica(int newIdFabrica)
// Purpose:    Implementation of Fabrica::setIdFabrica()
// Parameters:
// - newIdFabrica
// Return:     void
////////////////////////////////////////////////////////////////////////

void Fabrica::setIdFabrica(int newIdFabrica)
{
   idFabrica = newIdFabrica;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fabrica::getNombreFabrica()
// Purpose:    Implementation of Fabrica::getNombreFabrica()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Fabrica::getNombreFabrica(void)
{
   return nombreFabrica;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fabrica::setNombreFabrica(std::string newNombreFabrica)
// Purpose:    Implementation of Fabrica::setNombreFabrica()
// Parameters:
// - newNombreFabrica
// Return:     void
////////////////////////////////////////////////////////////////////////

void Fabrica::setNombreFabrica(std::string newNombreFabrica)
{
   nombreFabrica = newNombreFabrica;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fabrica::getContactoFabrica()
// Purpose:    Implementation of Fabrica::getContactoFabrica()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Fabrica::getContactoFabrica(void)
{
   return contactoFabrica;
}

////////////////////////////////////////////////////////////////////////
// Name:       Fabrica::setContactoFabrica(std::string newContactoFabrica)
// Purpose:    Implementation of Fabrica::setContactoFabrica()
// Parameters:
// - newContactoFabrica
// Return:     void
////////////////////////////////////////////////////////////////////////

void Fabrica::setContactoFabrica(std::string newContactoFabrica)
{
   contactoFabrica = newContactoFabrica;
}
