/***********************************************************************
 * Module:  ListaDobleCircular.cpp
 * Author:  Alvaro Zuma, Johnny Loachamin
 * Modified: Wednesday, February 09, 2021 23:31:00 PM
 * Purpose: Implementation of the class ListaDobleCircular
 ***********************************************************************/

#include "ListaDobleCircular.h"
#include<stdlib.h>
#include <fstream>

////////////////////////////////////////////////////////////////////////
// Name:       ListaDobleCircular::vacia()
// Purpose:    Implementation of ListaDobleCircular::vacia()
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool ListaDobleCircular::vacia(void)
{
   if(primero==NULL && ultimo==NULL){
        return true;
   }else{
       return false;
   }
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaDobleCircular::insertarInicio(Maquina newMaquina)
// Purpose:    Implementation of ListaDobleCircular::insertarInicio()
// Parameters:
// - newMaquina
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaDobleCircular::insertarInicio(Maquina newMaquina)
{
    Nodo* nuevo=new Nodo();
    nuevo->setMaquina(newMaquina);
    if(vacia()){
        primero=nuevo;
        ultimo=nuevo;
        primero->setSiguiente(primero);
        primero->setAnterior(ultimo);
   }else{
        primero->setAnterior(nuevo);
        nuevo->setAnterior(ultimo);
        nuevo->setSiguiente(primero);
        primero=nuevo;
        ultimo->setSiguiente(primero);
   }
   crearTxt(nuevo);
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaDobleCircular::insertarFinal(Maquina newMaquina)
// Purpose:    Implementation of ListaDobleCircular::insertarFinal()
// Parameters:
// - newMaquina
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaDobleCircular::insertarFinal(Maquina newMaquina)
{
    Nodo* nuevo=new Nodo();
    nuevo->setMaquina(newMaquina);
    if(vacia()){
        primero=nuevo;
        ultimo=nuevo;
        primero->setSiguiente(primero);
        primero->setAnterior(ultimo);
   }else{
       ultimo->setSiguiente(nuevo);
       nuevo->setAnterior(ultimo);
       nuevo->setSiguiente(primero);
       ultimo=nuevo;
       primero->setAnterior(ultimo);
   }
   crearTxt(nuevo);
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaDobleCircular::insertarPosicion(int newPosicion, Maquina newMaquina)
// Purpose:    Implementation of ListaDobleCircular::insertarPosicion()
// Parameters:
// - newPosicion
// - newMaquina
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaDobleCircular::insertarPosicion(int newPosicion, Maquina newMaquina)
{
    Nodo* aux =primero;
    int cont=0;

    if(tamanioLista()>=newPosicion){
        while(cont!=newPosicion){
            aux=aux->getSiguiente();
            cont++;
        }
        Nodo* aux2=aux->getAnterior();
        Nodo* nuevo=new Nodo();
        nuevo->setMaquina(newMaquina);

        aux2->setSiguiente(nuevo);
        nuevo->setAnterior(aux2);
        nuevo->setSiguiente(aux);
        aux->setAnterior(nuevo);
        crearTxt(nuevo);
    }else{
        std::cout<<"LA POSICION ES MAYOR AL TAMAÑO DE LA LISTA\n";
    }

}

////////////////////////////////////////////////////////////////////////
// Name:       ListaDobleCircular::buscarPosicionMaquinaId(int idMaquina)
// Purpose:    Implementation of ListaDobleCircular::buscarPosicionMaquinaId()
// Parameters:
// - idMaquina
// Return:     int
////////////////////////////////////////////////////////////////////////

int ListaDobleCircular::buscarPosicionMaquinaId(int idMaquina)
{
   int contador=0;
   if(!vacia()){
       Nodo* aux=primero;

        do{
            if(idMaquina==aux->getMaquina().getIdMaquina()){
                return contador;
            }
            aux=aux->getSiguiente();
            contador++;
        }while(aux!=primero);
   }
    return -1;
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaDobleCircular::modificarPorId(int idMaquina)
// Purpose:    Implementation of ListaDobleCircular::modificarPorId()
// Parameters:
// - idMaquina
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaDobleCircular::modificarPorId(int idMaquina,Maquina maquina)
{
    Nodo* aux =primero;
    Nodo* modificar = new Nodo();
    modificar->setMaquina(maquina);
    int posicion=buscarPosicionMaquinaId(idMaquina);
    int cont=0;
    bool bandera=true;
    if(posicion!=-1 && !vacia()){

        while(cont!=posicion){
            aux=aux->getSiguiente();
            cont++;
        }
    }else{
        bandera=false;
    }

    if(bandera){
            if(cont==0){/** CUANDO EN LA LISTA SOLO EXISTA UN NODO EN LA LISTA */
                primero=NULL;
                ultimo=NULL;
                insertarInicio(maquina);
            }else{

                Nodo* aux2=aux->getAnterior();
                Nodo* aux3=aux->getSiguiente();
                aux2->setSiguiente(modificar);
                modificar->setAnterior(aux2);
                modificar->setSiguiente(aux3);
                aux3->setAnterior(modificar);
            }
        std::cout<<"MAQUINA MODIFICADA\n";
        imprimirNodo(modificar);
        free(aux);

    }else{
        std::cout<<"NO EXISTE ID PARA MODIFICAR\n";
    }
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaDobleCircular::eliminar(int id)
// Purpose:    Implementation of ListaDobleCircular::eliminar()
// Parameters:
// - id
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaDobleCircular::eliminar(int idLibro)
{
    Nodo* aux =primero;
    int posicion=buscarPosicionMaquinaId(idLibro);
    int cont=0;
    bool bandera=true;
    if(posicion!=-1 && !vacia()){

        while(cont!=posicion){
            aux=aux->getSiguiente();
            cont++;
        }
    }else{
        bandera=false;
    }

    if(bandera){
            if(cont==0){/** CUANDO EN LA LISTA SOLO EXISTA UN NODO EN LA LISTA */
                primero=NULL;
                ultimo=NULL;
            }
            if(cont==1){/** CUANDO EN LA LISTA SOLO EXISTAN DOS NODOS EN LA LISTA*/
                primero=aux->getAnterior();
                ultimo=aux->getAnterior();
                primero->setSiguiente(primero);
                primero->setAnterior(ultimo);

            }else{/** CUANDO EN LA LISTA EXISTAN MAS DE DOS NODO EN LA LISTA*/

                Nodo* aux2=aux->getAnterior();
                Nodo* aux3=aux->getSiguiente();
                aux2->setSiguiente(aux3);
                aux3->setAnterior(aux2);
            }
        std::cout<<"MAQUINA ELIMINADA\n";
        imprimirNodo(aux);
        free(aux);

    }else{
        std::cout<<"NO EXISTE ID PARA ELIMINAR\n";
    }

}

////////////////////////////////////////////////////////////////////////
// Name:       ListaDobleCircular::imprimir()
// Purpose:    Implementation of ListaDobleCircular::imprimir()
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaDobleCircular::imprimir(void)
{
    Nodo* aux=primero;
    if(!vacia()){

        do{
		    std::cout<<"////////////////////////////////////////////////////////////////////////"<<std::endl;
		    std::cout<<"  IDENTI MAQUINA: "<<aux->getMaquina().getIdMaquina()<<std::endl;
		    std::cout<<"  NOMBRE MAQUINA: "<<aux->getMaquina().getNombreMaquina()<<std::endl;
		    std::cout<<"  IDENTI OPERADOR: "<<aux->getMaquina().getOperador().getPersona().getId()<<std::endl;
		    std::cout<<"  NOMBRE OPERADOR: "<<aux->getMaquina().getOperador().getPersona().getNombre();
		    std::cout<<" "<<aux->getMaquina().getOperador().getPersona().getApellido()<<std::endl;
		    std::cout<<"  CORREO OPERADOR: "<<aux->getMaquina().getOperador().getPersona().getCorreo()<<std::endl;
		    std::cout<<"  IDENTI. PAIS : "<<aux->getMaquina().getPais().getIdPais()<<std::endl;
		    std::cout<<"  NOMBRE  PAIS : "<<aux->getMaquina().getPais().getNombrePais()<<std::endl;
		    std::cout<<"  NACIONALIDAD : "<<aux->getMaquina().getPais().getNacionalidad()<<std::endl;
		    std::cout<<"  NUMERO DE SECCION: "<<aux->getMaquina().getOperador().getNumSeccion()<<std::endl;
		    std::cout<<"  IDENTI FABRICA: "<<aux->getMaquina().getFabrica().getIdFabrica()<<std::endl;
		    std::cout<<"  NOMBRE FABRICA: "<<aux->getMaquina().getFabrica().getNombreFabrica()<<std::endl;
		    std::cout<<"  CONTAC FABRICA: "<<aux->getMaquina().getFabrica().getContactoFabrica()<<std::endl;
		    std::cout<<"////////////////////////////////////////////////////////////////////////"<<std::endl<<std::endl;

            aux=aux->getSiguiente();
        }while(aux!=primero);
    }else{
        std::cout<<"LISTA DOBLE VACIA\n";
    }
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaDobleCircular::imprimirNodo(Nodo* nodo)
// Purpose:    Implementation of ListaDobleCircular::imprimirNodo()
// Parameters:
// - nodo
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaDobleCircular::imprimirNodo(Nodo* nodo)
{

    std::cout<<"////////////////////////////////////////////////////////////////////////"<<std::endl;
    std::cout<<"  IDENTI MAQUINA: "<<nodo->getMaquina().getIdMaquina()<<std::endl;
    std::cout<<"  NOMBRE MAQUINA: "<<nodo->getMaquina().getNombreMaquina()<<std::endl;
    std::cout<<"  IDENTI OPERADOR: "<<nodo->getMaquina().getOperador().getPersona().getId()<<std::endl;
    std::cout<<"  NOMBRE OPERADOR: "<<nodo->getMaquina().getOperador().getPersona().getNombre();
    std::cout<<" "<<nodo->getMaquina().getOperador().getPersona().getApellido()<<std::endl;
    std::cout<<"  CORREO OPERADOR: "<<nodo->getMaquina().getOperador().getPersona().getCorreo()<<std::endl;
    std::cout<<"  IDENTI. PAIS : "<<nodo->getMaquina().getPais().getIdPais()<<std::endl;
    std::cout<<"  NOMBRE  PAIS : "<<nodo->getMaquina().getPais().getNombrePais()<<std::endl;
    std::cout<<"  NACIONALIDAD : "<<nodo->getMaquina().getPais().getNacionalidad()<<std::endl;
    std::cout<<"  NUMERO DE SECCION: "<<nodo->getMaquina().getOperador().getNumSeccion()<<std::endl;
    std::cout<<"  IDENTI FABRICA: "<<nodo->getMaquina().getFabrica().getIdFabrica()<<std::endl;
    std::cout<<"  NOMBRE FABRICA: "<<nodo->getMaquina().getFabrica().getNombreFabrica()<<std::endl;
    std::cout<<"  CONTAC FABRICA: "<<nodo->getMaquina().getFabrica().getContactoFabrica()<<std::endl;
    std::cout<<"////////////////////////////////////////////////////////////////////////"<<std::endl<<std::endl;
}

////////////////////////////////////////////////////////////////////////
// Name:       ListaDobleCircular::tamanioLista()
// Purpose:    Implementation of ListaDobleCircular::tamanioLista()
// Return:     int
////////////////////////////////////////////////////////////////////////

int ListaDobleCircular::tamanioLista(void)
{
    int cont=0;
    if(!vacia()){
        Nodo* aux=primero;
        do{
            aux=aux->getSiguiente();
            cont++;
        }while(aux!=primero);
    }
    return cont;
}

////////////////////////////////////////////////////////////////////////
// Name:       Persona::crearTxt(Nodo* nodo)
// Purpose:    Implementation of Persona::crearTxt()
// Parameters:
// - nodo
// Return:     void
////////////////////////////////////////////////////////////////////////

void ListaDobleCircular::crearTxt(Nodo* nodo)
{
    std::fstream enter;
	enter.open("MACHINE4FUN.txt", std::fstream::app);
    enter<<"////////////////////////////////////////////////////////////////////////"<<std::endl;
    enter<<"  IDENTI MAQUINA: "<<nodo->getMaquina().getIdMaquina()<<std::endl;
    enter<<"  NOMBRE MAQUINA: "<<nodo->getMaquina().getNombreMaquina()<<std::endl;
    enter<<"  IDENTI OPERADOR: "<<nodo->getMaquina().getOperador().getPersona().getId()<<std::endl;
    enter<<"  NOMBRE OPERADOR: "<<nodo->getMaquina().getOperador().getPersona().getNombre();
    enter<<" "<<nodo->getMaquina().getOperador().getPersona().getApellido()<<std::endl;
    enter<<"  CORREO OPERADOR: "<<nodo->getMaquina().getOperador().getPersona().getCorreo()<<std::endl;
    enter<<"  IDENTI. PAIS : "<<nodo->getMaquina().getPais().getIdPais()<<std::endl;
    enter<<"  NOMBRE  PAIS : "<<nodo->getMaquina().getPais().getNombrePais()<<std::endl;
    enter<<"  NACIONALIDAD : "<<nodo->getMaquina().getPais().getNacionalidad()<<std::endl;
    enter<<"  NUMERO DE SECCION: "<<nodo->getMaquina().getOperador().getNumSeccion()<<std::endl;
    enter<<"  IDENTI FABRICA: "<<nodo->getMaquina().getFabrica().getIdFabrica()<<std::endl;
    enter<<"  NOMBRE FABRICA: "<<nodo->getMaquina().getFabrica().getNombreFabrica()<<std::endl;
    enter<<"  CONTAC FABRICA: "<<nodo->getMaquina().getFabrica().getContactoFabrica()<<std::endl;
    enter<<"////////////////////////////////////////////////////////////////////////"<<std::endl;
}

