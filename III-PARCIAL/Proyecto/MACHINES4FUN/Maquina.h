/***********************************************************************
 * Module:  Maquina.h
 * Author:  Alvaro Zuma, Johnny Loachamin
 * Modified: Saturday, February 06, 2021 8:55:50 PM
 * Purpose: Declaration of the class Maquina
 ***********************************************************************/

#if !defined(__MACHINES4FUN_LISTA_DOBLE2_Maquina_h)
#define __MACHINES4FUN_LISTA_DOBLE2_Maquina_h



#include "Operador.h"
#include "Pais.h"
#include "Fabrica.h"

class Maquina
{
public:
   Maquina();
   ~Maquina();
   int getIdMaquina(void);
   void setIdMaquina(int newIdMaquina);
   std::string getNombreMaquina(void);
   void setNombreMaquina(std::string newNombreMaquina);
   Operador getOperador(void);
   void setOperador(Operador newOperador);
   Pais getPais(void);
   void setPais(Pais newPais);
   Fabrica getFabrica(void);
   void setFabrica(Fabrica newFabrica);

protected:
private:
   int idMaquina;
   std::string nombreMaquina;
   Operador operador;
   Pais pais;
   Fabrica fabrica;


};
#endif
