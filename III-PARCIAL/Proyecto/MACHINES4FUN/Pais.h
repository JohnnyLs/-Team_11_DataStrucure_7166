/***********************************************************************
 * Module:  Pais.h
 * Author:  Alvaro Zuma, Johnny Loachamin
 * Modified: Wednesday, February 09, 2021 20:11:09 PM
 * Purpose: Declaration of the class Pais
 ***********************************************************************/

#include<iostream>

#if !defined(__MACHINES4FUN_LISTA_DOBLE2_Pais_h)
#define __MACHINES4FUN_LISTA_DOBLE2_Pais_h

class Pais
{
public:
   Pais();
   ~Pais();
   int getIdPais(void);
   void setIdPais(int newIdPais);
   std::string getNombrePais(void);
   void setNombrePais(std::string newNombrePais);
   std::string getNacionalidad(void);
   void setNacionalidad(std::string newNacionalidad);

protected:
private:
   int idPais;
   std::string nombrePais;
   std::string nacionalidad;


};

#endif

