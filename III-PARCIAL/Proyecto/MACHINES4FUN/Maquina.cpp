/***********************************************************************
 * Module:  Maquina.cpp
 * Author:  Alvaro Zuma, Johnny Loachamin
 * Modified: Sunday, February 07, 2021 8:55:50 PM
 * Purpose: Implementation of the class Maquina
 ***********************************************************************/

#include "Maquina.h"

////////////////////////////////////////////////////////////////////////
// Name:       Maquina::Maquina()
// Purpose:    Implementation of Maquina::Maquina()
// Return:
////////////////////////////////////////////////////////////////////////

Maquina::Maquina()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Maquina::~Maquina()
// Purpose:    Implementation of Maquina::~Maquina()
// Return:
////////////////////////////////////////////////////////////////////////

Maquina::~Maquina()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Maquina::getIdMaquina()
// Purpose:    Implementation of Maquina::getIdMaquina()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Maquina::getIdMaquina(void)
{
   return idMaquina;
}

////////////////////////////////////////////////////////////////////////
// Name:       Maquina::setIdMaquina(int newIdMaquina)
// Purpose:    Implementation of Maquina::setIdMaquina()
// Parameters:
// - newIdMaquina
// Return:     void
////////////////////////////////////////////////////////////////////////

void Maquina::setIdMaquina(int newIdMaquina)
{
   idMaquina = newIdMaquina;
}

////////////////////////////////////////////////////////////////////////
// Name:       Maquina::getNombreMaquina()
// Purpose:    Implementation of Maquina::getNombreMaquina()
// Return:     std::string
////////////////////////////////////////////////////////////////////////

std::string Maquina::getNombreMaquina(void)
{
   return nombreMaquina;
}

////////////////////////////////////////////////////////////////////////
// Name:       Maquina::setNombreMaquina(std::string newNombreMaquina)
// Purpose:    Implementation of Maquina::setNombreMaquina()
// Parameters:
// - newNombreMaquina
// Return:     void
////////////////////////////////////////////////////////////////////////

void Maquina::setNombreMaquina(std::string newNombreMaquina)
{
   nombreMaquina = newNombreMaquina;
}

////////////////////////////////////////////////////////////////////////
// Name:       Maquina::getMaquina()
// Purpose:    Implementation of Maquina::getOperador()
// Return:     Operador
////////////////////////////////////////////////////////////////////////

Autor Maquina::getOperador(void)
{
   return operador;
}

////////////////////////////////////////////////////////////////////////
// Name:       Maquina::setOperador(Operador newOperdor)
// Purpose:    Implementation of Maquina::setMaquina()
// Parameters:
// - newOperador
// Return:     void
////////////////////////////////////////////////////////////////////////

void Maquina::setOperador(Operador newOperador)
{
   operador = newOperador;
}

////////////////////////////////////////////////////////////////////////
// Name:       Maquina::getPais()
// Purpose:    Implementation of Maquina::getPais()
// Return:     Pais
////////////////////////////////////////////////////////////////////////

Pais Maquina::getPais(void)
{
   return pais;
}

////////////////////////////////////////////////////////////////////////
// Name:       Libro::setPais(Pais newPais)
// Purpose:    Implementation of Maquina::setPais()
// Parameters:
// - newPais
// Return:     void
////////////////////////////////////////////////////////////////////////

void Maquina::setPais(Pais newPais)
{
   pais = newPais;
}

////////////////////////////////////////////////////////////////////////
// Name:       Maquina::getFabrica()
// Purpose:    Implementation of Maquina::getFabrica()
// Return:     Fabrica
////////////////////////////////////////////////////////////////////////

Fabrica Maquina::getFabrica(void)
{
   return fabrica;
}

////////////////////////////////////////////////////////////////////////
// Name:       Maquina::setFabrica(Fabrica newFabrical)
// Purpose:    Implementation of Maquina::setFabrica()
// Parameters:
// - newFabrica
// Return:     void
////////////////////////////////////////////////////////////////////////

void Maquina::setFabrica(Fabrica newFabrica)
{
   fabrica = newFabrica;
}

