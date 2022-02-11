/******************  Universidad de las Fuerzas Armadas ESPE  ************************
 *				Carrera: Software													 *
 *				Autores: Loachamin Johnny, Zumba ALvaro								 *
 *				Fecha de creacion: 05/02/2022										 *
 *				Fecha de modificación: 10/02/2022									 *
 *************************************************************************************/

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <fstream>

#include "Ingreso.h"
#include "ListaDobleCircular.h"
#include "Maquina.h"
#include "Operador.h"
#include "Persona.h"
#include "Pais.h"
#include "Fabrica.h"

#define ARRIBA     72
#define ABAJO      80
#define ENTER      13


void gotoxy(short posicionx, short posiciony);
void menu();
void machine4fun(int opcion,ListaDobleCircular *lista,int &idMaquina);
Maquina ingresarMaquina(int &id);
Operador ingresarOperador();
Persona ingresarPersona();
Pais ingresarPais();
Fabrica ingresarFabrica();

using namespace std;

int main()
{

    fstream enter;

    ListaDobleCircular *lista=new ListaDobleCircular();
	int posX = 4;
	int posY = 6;
	int posMaxY=12;
	bool bandera = true;
	int idMaquina=1;

    enter.open("MACHINE4FUN.txt", fstream::out);
	enter << "Lista de maquinas" << endl;
	

	do{
		system("cls");
		std::cout << "\n\t MACHINE4FUN ";
		menu();
		gotoxy(posX, posY);
		cout << "=>";
			switch (_getch())
			{
			case ARRIBA:
				posY--;
				if (posY < 6) {
					posY = posMaxY;
				}
				break;
			case ABAJO:
				posY++;
				if (posY > posMaxY) {
					posY = 6;
				}
				break;

			case ENTER:
				if (posY == posMaxY) {
					bandera = false;
				}
				else {
					machine4fun(posY,lista, idMaquina);
				}
				break;
			}
	} while (bandera);

	enter.close();
	
	return 0;
}

void gotoxy(short posicionx, short posiciony) {
	COORD coordenadaPosicion = { posicionx, posiciony };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordenadaPosicion);
}


void menu() {
	int posX = 7;
	int posY = 6;
	gotoxy(posX, posY++);cout << "INGRESAR MAQUINA INICIO";
	gotoxy(posX, posY++);cout << "INGRESAR MAQUINA FINAL";
	gotoxy(posX, posY++);cout << "INGRESAR MAQUIN POR POSICION";
	gotoxy(posX, posY++);cout << "MODIFICAR POR ID";
	gotoxy(posX, posY++);cout << "ELIMINAR POR ID";
	gotoxy(posX, posY++);cout << "IMPRIMIR";
	gotoxy(posX, posY++);cout << "SALIR";

}
void machine4fun(int opcion, ListaDobleCircular* lista, int &idMaquina) {

    Ingreso leer;
    bool bandera;
	system("cls");

	int idModificar=0;
	int aux;
	switch (opcion)
	{
	case 6:
	    //INGRESO AL INICIO
	    cout << "\tINGRESO MAQUINA AL INICIO\n\n";
	    lista->insertarInicio(ingresarMaquina(idMaquina));
		break;
	case 7:
	    //INGRESO AL FINAL
	    cout << "\n\tINGRESO MAQUINA AL FINAL\n\n";
	    lista->insertarFinal(ingresarMaquina(idMaquina));
		break;
    case 8:
	    //INGRESO AL POSICION
	    cout << "\n\tINGRESO MAQUINA POR POSICION\n\n";

	    lista->insertarPosicion(1,ingresarMaquina(idMaquina));
		break;
    case 9:
	    //MODIFICAR
	    cout << "\n\tMODIFICAR POR ID\n\n";
	    do{
            bandera=false;
            idModificar=atoi(leer.ingresoNumero("  Ingrese el ID:"));
            if(lista->buscarPosicionMaquinaId(idModificar)==-1){
                cout<<" ID NO ENCOTRADO\n";
                cout<<" ENTER para ingresar o ESC para salir\n";
                switch(getch()){
                case 13:
                        bandera=true;
                        break;
                }
            }
	    }while(bandera);
	    aux=idModificar;
        lista->modificarPorId(aux,ingresarMaquina(idModificar));
		break;
    case 10:
	    //ELIMINAR
	    cout << "\n\tELIMINAR POR ID\n\n";
	    do{
            bandera=false;
            idModificar=atoi(leer.ingresoNumero("  Ingrese el ID:"));
            if(lista->buscarPosicionMaquinaId(idModificar)==-1){
                cout<<"\n ID NO ENCOTRADO\n";
                cout<<" ENTER para ingresar o ESC para salir\n";
                switch(getch()){
                case 13:
                        bandera=true;
                        break;
                }
            }
	    }while(bandera);
        lista->eliminar(idModificar);
	    break;
    case 11:
	    //IMPRIMIR
	    cout << "\n\tIMPRESION DE DATOS\n\n";
	    lista->imprimir();
		break;
	default:
		break;
	}

	system("pause");

}

Maquina ingresarMaquina(int &id){
    Ingreso leer;
    Maquina maquina;

    cout<<"\nINGRESE LOS DATOS\n";
    cout<<"  ID de la Maquina: "<<id<<endl;
    maquina.setIdMaquina(id);
    maquina.setNombreMaquina(leer.ingresoCadena("  Nombre de la Maquina:"));
	cout<<endl;

    Operador operador=ingresarOperador();
    Fabrica fabrica=ingresarFabrica();
    Pais pais=ingresarPais();

    maquina.setOperador(operador);
    maquina.setFabrica(fabrica);
    maquina.setPais(pais);
    id++;
    return maquina;
}

Operador ingresarOperador(){
    Operador operador;
    Ingreso leer;
    cout<<"\nDATOS OPERADOR\n";
    Persona persona=ingresarPersona();
    operador.setPersona(persona);
    operador.setNumSeccion(atoi(leer.ingresoNumero("  Num Seccion:")));cout<<endl;

    return operador;
}

Persona ingresarPersona(){
    Persona persona;
    Ingreso leer;
    persona.setId(leer.ingresoNumero("  Cedula:"));cout<<endl;
    persona.setNombre(leer.ingresoCadena("  Nombre:"));cout<<endl;
    persona.setApellido(leer.ingresoCadena("  Apellido:"));cout<<endl;
    persona.setCorreo(leer.ingresoCorreo("  Correo:"));cout<<endl;

    return persona;
}

Pais ingresarPais(){
    Pais pais;
    Ingreso leer;
    cout<<"\nDATOS DEL PAIS\n";
    pais.setIdPais(atoi(leer.ingresoNumero("  Id del Pais:")));cout<<endl;
    pais.setNombrePais(leer.ingresoCadena("  Nombre del Pais:"));cout<<endl;
    pais.setNacionalidad(leer.ingresoCadena("  Nacionalidad: "));cout<<endl;

    return pais;
}

Fabrica ingresarFabrica(){
    Fabrica fabrica;
    Ingreso leer;
    cout<<"\nDATOS DE LA FABRICA\n";
    fabrica.setIdFabrica(atoi(leer.ingresoNumero("  ID FABRICA")));cout<<endl;
    fabrica.setNombreFabrica(leer.ingresoCadena("  Nombre:"));cout<<endl;
    fabrica.setContactoFabrica(leer.ingresoNumero("  Telefono:"));cout<<endl;

    return fabrica;
}

