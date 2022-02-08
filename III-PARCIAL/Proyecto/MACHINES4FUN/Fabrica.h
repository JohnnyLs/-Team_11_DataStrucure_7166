/***********************************************************************
 * Module:  Fabrica.h
 * Author:  Alvaro Zuma, Johnny Loachamin
 * Modified: Sunday, Febraury 6, 2022 8:55:50 PM
 * Purpose: Declaration of the class Fabrica
 ***********************************************************************/

#include<iostream>

#if !defined(__BIBLIOTECA_LISTA_DOBLE2_Editorial_h)
#define __BIBLIOTECA_LISTA_DOBLE2_Editorial_h

class Editorial
{
public:
   Fabrica();
   ~Fabrica();
   int getIdFabrica(void);
   void setIdFabrica(int newIdFabrica);
   std::string getNombreFabrica(void);
   void setNombreFabrica(std::string newNombreFabrica);
   std::string getContactoFabrica(void);
   void setContactoFabrica(std::string newContactoFabrica);

protected:
private:
   int idFabrica;
   std::string nombreFabrica;
   std::string contactoFabrica;


};

#endif
