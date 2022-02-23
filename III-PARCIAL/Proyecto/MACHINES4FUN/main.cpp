/******************  Universidad de las Fuerzas Armadas ESPE  ************************
 *				Carrera: Software													 *
 *				Autores: Loachamin Johnny, Zumba ALvaro								 *
 *				Fecha de creacion: 05/02/2022										 *
 *				Fecha de modificación: 23/02/2022									 *
 *************************************************************************************/

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <thread>
#include <chrono>


#include "Ingreso.h"
#include "ListaDobleCircular.h"
#include "Maquina.h"
#include "Operador.h"
#include "Persona.h"
#include "Pais.h"
#include "Fabrica.h"
#include "md5.h"

#define MAX 3
#define MIN 0

#define ARRIBA     72
#define ABAJO      80
#define ENTER      13
#define MENSAJE    "Universidad de las Fuerzas Armadas ESPE"


void gotoxy(short posicionx, short posiciony);
void menu();
void machine4fun(int opcion,ListaDobleCircular *lista,int &idMaquina);
void machine4funLogin(int opcion, ListaDobleCircular* lista, int &idMaquina);
Maquina ingresarMaquina(int &id);
Operador ingresarOperador();
Persona ingresarPersona();
Pais ingresarPais();
Fabrica ingresarFabrica();

using namespace std;


void marquesina()
{
    int a=0, b=56, c=0, n=0;
	char t[50] =MENSAJE;
	std::cout << "\t\t\t\tBIENVENIDO A MACHINES4FUN!!!\n";
	do
	{
		for (a=1;a<=56;a++){//56 es el tamaño del la pantalla para su recorrido de ida
			gotoxy(a,2);
			cout<<t;
			gotoxy(a-1,2);
			cout<<" ";
			Sleep (20);//Velocidad de la marquesina ida
		}
		for (b=56;b>=1;b--){////56 es el tamaño del la pantalla para su recorrido de vuelta
			gotoxy(b,2);
			cout<<t;
			gotoxy(b+39,2);
			cout<<" ";
			Sleep (20);//Velocidad de la marquesina vuelta
		}
		c=c+1;
	}while (c<3);//Aqui pueden controlar cuantas veces quieren que se ejecute su marquesina
	gotoxy(30,15);//Esta es la ubicación final para acceder al sistema
}

void menuLogin() {
	
	
	int posX = 7;
	int posY = 6;
	system("cls");
	
	//	gotoxy(10,4);
	cout << "\n\t\t\t\tBIENVENIDO A MACHINES4FUN!!!\n";
	cout << "\n----------------------------\n" << endl;

	gotoxy(posX, posY++);cout << " Ingresar como Usuario" << endl;
	gotoxy(posX, posY++);cout << " Registrarse" << endl;
	gotoxy(posX, posY++);cout << " Salir del Programa." << endl;
	cout << "\n----------------------------\n\n" << endl;

}
 

//CONSTANTES
const char FINCAD = char(0);
const int MAXCAD = 20;

const char SP = ' ';
char contrasena;
int i;
int contador=0;
//TIPOS
typedef char TCadena[MAXCAD+1]; // MAXCAD caracteres + FINCAD
struct Persona_R
{
TCadena PASS;
};

// CABECERA DE PROCEDIMIENTOS Y FUNCIONES
void pausa();
void finalizar_programa();
void borrar_pantalla();
void Ingresar_PASS(Persona_R &p);
void confirmar_PASS(Persona_R &p);
// Algoritmos de Manejo de Ficheros de Texto
void insertarPersonaTXT(TCadena nombreFichero, Persona_R p);
void EscribePersonaFicheroTXT(ofstream &fichero, Persona_R p);
void verificar_existencia_fichero(TCadena nombreFichero);
void verificar_existencia_de_usuario(TCadena nombreFichero);
void verificar_contrasena(TCadena nombreFichero,Persona_R &password);

int main()
{
	int posX = 4;
	int posY = 6;
	int posMaxY=8;
	ListaDobleCircular *lista=new ListaDobleCircular();
	bool bandera = true;
	int idMaquina=1;
    
	setlocale(LC_CTYPE, "Spanish");
	Persona_R p;;
	Persona_R password;;
	char opcion;
	int num;
	bool fin,encontrado;
	TCadena nombre_usuario_registrado;
	
	thread th(marquesina);
	
	Sleep(5);
do
{
	menuLogin();
	gotoxy(posX, posY);
		cout << "=>";
			switch (_getch())
			{
			case ARRIBA:
				gotoxy(5,posY);
				cout<<" ";
				gotoxy(4,posY);
				cout<<" ";
				posY--;
				if (posY < 6) {
					posY = posMaxY;
				}
				
				break;
			case ABAJO:
				gotoxy(5,posY);
				cout<<" ";
				gotoxy(4,posY);
				cout<<" ";
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
					machine4funLogin(posY,lista, idMaquina);
				}
				break;
			}
	} while (bandera);
	

    /*do
    {
        printf( "\n   Introduzca opción (1-3): ", 162 );
        fflush( stdin );
		scanf( "%c", &opcion );
    } while ( opcion < '1' || opcion > '3' );
    */    
    switch ( opcion )
    {
	    case '1':   Sleep(1000);//Tiempo de espera para entrar al submenu
					system("cls");
					cout << "\t\t\t\tBIENVENIDO AL MACHINE4FUN!!!\n";
					cout<<"\n LOGIN!!! \n"<<endl;
					cout << "\nDigite su Nombre de Usuario:     ";//INGRESAR COMO USUARIO
					cin >> nombre_usuario_registrado;
					verificar_existencia_fichero(nombre_usuario_registrado);
					//confirmar_PASS(password);
					verificar_contrasena(nombre_usuario_registrado,password);
					Sleep(1000);borrar_pantalla();main();
					break;

        case '2':	Sleep(1000);
					system("CLS");
					cout << "\t\t\t\tBIENVENIDO AL MACHINE4FUN!!!\n";
					cout<<"\n REGISTRO DE USUARIOS!!! \n"<<endl;
					cout << "\nEscriba su Nuevo Nombre de Usuario:    ";//REGISTRO
					cin >> nombre_usuario_registrado;
					verificar_existencia_de_usuario(nombre_usuario_registrado);
					Ingresar_PASS(p);
					insertarPersonaTXT(nombre_usuario_registrado,p);
					Sleep(1000);borrar_pantalla();main();
					break;

        case '3':   Sleep(1000);
					system("CLS");
					cout << "\nGracias por utilizar nuestro sistema:    ";
        			Sleep(1000);
        			finalizar_programa();
        			break;
     }

//} while ( bandera );
	//
	return 0;
}

void gotoxy(short posicionx, short posiciony) {
	COORD coordenadaPosicion = { posicionx, posiciony };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordenadaPosicion);
}

int mainSec(){
	// Do other things...
	borrar_pantalla();
    // Makes the main thread wait for the new thread to finish execution, therefore blocks its own execution.
    //t1.join();
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
		menu();
		gotoxy(posX, posY);
		cout << "=>";
			switch (_getch())
			{
			case ARRIBA:
				gotoxy(5,posY);
				cout<<" ";
				gotoxy(4,posY);
				cout<<" ";
				posY--;
				if (posY < 6) {
					posY = posMaxY;
				}
				
				break;
			case ABAJO:
				gotoxy(5,posY);
				cout<<" ";
				gotoxy(4,posY);
				cout<<" ";
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
}


void menu() {
	int posX = 7;
	int posY = 6;
	system("cls");
	cout << "\t\t\t\tBIENVENIDO AL MACHINE4FUN!!!\n";
	cout<<"\n \t\t!!!SISTEMA DE ADMINISTRACIÓN DE MAQUINARIA!!! \n"<<endl;
	gotoxy(posX, posY++);cout << "INGRESAR MAQUINA AL INICIO";
	gotoxy(posX, posY++);cout << "INGRESAR MAQUINA Al FINAL";
	gotoxy(posX, posY++);cout << "INGRESAR MAQUINA POR POSICION";
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
	    cout << "\tINGRESAR LA MAQUINA AL INICIO\n\n";
	    lista->insertarInicio(ingresarMaquina(idMaquina));
		break;
	case 7:
	    //INGRESO AL FINAL
	    cout << "\n\tINGRESAR LA MAQUINA AL FINAL\n\n";
	    lista->insertarFinal(ingresarMaquina(idMaquina));
		break;
    case 8:
	    //INGRESO AL POSICION
	    cout << "\n\tINGRESO MAQUINA POR POSICION\n\n";

	    lista->insertarPosicion(1,ingresarMaquina(idMaquina));
		break;
    case 9:
	    //MODIFICAR
	    cout << "\n\tMODIFICAR MAQUINA POR ID\n\n";
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
		main();
		break;
	}

	system("pause");

}
void machine4funLogin(int opciones, ListaDobleCircular* lista, int &idMaquina)
 {
 	Persona_R p;;
	Persona_R password;;
	char opcion;
	int num;
	bool fin,encontrado;
	TCadena nombre_usuario_registrado;

    Ingreso leer;
    bool bandera;
	system("cls");

	int idModificar=0;
	int aux;
	switch (opciones)
	{
	case 6:
	    //INGRESO AL INICIO
	    Sleep(1000);//Tiempo de espera para entrar al submenu
					system("cls");
					cout << "\t\t\t\tBIENVENIDO AL MACHINE4FUN!!!\n";
					cout<<"\n LOGIN!!! \n"<<endl;
					cout << "\nDigite su Nombre de Usuario:     ";//INGRESAR COMO USUARIO
					cin >> nombre_usuario_registrado;
					verificar_existencia_fichero(nombre_usuario_registrado);
					//confirmar_PASS(password);
					verificar_contrasena(nombre_usuario_registrado,password);
					Sleep(1000);borrar_pantalla();main();
		break;
	case 7:
	    Sleep(1000);
					system("CLS");
					cout << "\t\t\t\tBIENVENIDO AL MACHINE4FUN!!!\n";
					cout<<"\n REGISTRO DE USUARIOS!!! \n"<<endl;
					cout << "\nEscriba su Nuevo Nombre de Usuario:    ";//REGISTRO
					cin >> nombre_usuario_registrado;
					verificar_existencia_de_usuario(nombre_usuario_registrado);
					Ingresar_PASS(p);
					insertarPersonaTXT(nombre_usuario_registrado,p);
					Sleep(1000);borrar_pantalla();main();
		break;
	default:
		main();
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
    fflush(stdin);
    Persona persona=ingresarPersona();
    operador.setPersona(persona);
    operador.setNumSeccion(atoi(leer.ingresoNumero("  Num Seccion:")));cout<<endl;
	fflush(stdin);
    return operador;
}

Persona ingresarPersona(){
    Persona persona;
    Ingreso leer;
    fflush(stdin);
    persona.setId(leer.ingresoNumero("  Codigo de operador: #"));cout<<endl;
    persona.setNombre(leer.ingresoCadena("  Nombre:"));cout<<endl;
    persona.setApellido(leer.ingresoCadena("  Apellido:"));cout<<endl;
    persona.setCorreo(leer.ingresoCorreo("  Correo:"));cout<<endl;
	fflush(stdin);
    return persona;
}

Pais ingresarPais(){
    Pais pais;
    Ingreso leer;
    fflush(stdin);
    cout<<"\nDATOS DEL PAIS\n";
    pais.setIdPais(atoi(leer.ingresoNumero("  Id del Pais:")));cout<<endl;
    pais.setNombrePais(leer.ingresoCadena("  Nombre del Pais:"));cout<<endl;
    pais.setNacionalidad(leer.ingresoCadena("  Nacionalidad: "));cout<<endl;
	fflush(stdin);
    return pais;
}

Fabrica ingresarFabrica(){
    Fabrica fabrica;
    Ingreso leer;
    cout<<"\nDATOS DE LA FABRICA\n";
    fflush(stdin);
    fabrica.setIdFabrica(atoi(leer.ingresoNumero("  ID FABRICA:")));cout<<endl;
    fabrica.setNombreFabrica(leer.ingresoCadena("  Nombre:"));cout<<endl;
    fabrica.setContactoFabrica(leer.ingresoNumero("  Telefono:"));cout<<endl;
	fflush(stdin);
    return fabrica;
}

// IMPLEMENTACIÓN DE PROCEDIMIENTOS Y FUNCIONES
void finalizar_programa()
{
borrar_pantalla();     
printf("El Programa se cerrara en un momento"); Sleep(2000);
exit(0);
}
void pausa()
{
system("PAUSE");
}
void borrar_pantalla()
{
system("cls");
}
void Ingresar_PASS(Persona_R &p)
{
cout << "Escriba su Nuevo PASS:                 " ;
cin >> p.PASS;
cout<<"\nSE HA REGISTRADO CORRECTAMENTE"<<endl; Sleep(2500); 
}
void confirmar_PASS(Persona_R &password)
{
cout << "Escriba su PASS:                 " ;
cin >> password.PASS;
}

// Algoritmos de Manejo de Ficheros de Texto
void insertarPersonaTXT(TCadena nombreFichero, Persona_R p)
{
ofstream out;
out.open(nombreFichero,ios::app);
// Abro el fichero para añadir
if (out.bad()){
// El fichero no existe ... lo creo
out.open(nombreFichero);}	
EscribePersonaFicheroTXT(out,p);
out.close();
}

void EscribePersonaFicheroTXT(ofstream &fichero, Persona_R p)
{
fichero << md5(p.PASS) << SP;
}

void verificar_existencia_fichero(TCadena nombreFichero)
{
	    ifstream archivo(nombreFichero); 
    if (!archivo)
    {    
          cout<<"\nNombre de Usuario INCORRECTO.....INTENTELO DE NUEVO\n"<<endl; Sleep(1500); borrar_pantalla();main();  
    }
             else 
             {
              cout<<"\nNombre de Usuario CORRECTO..!!!\n"<<endl;Sleep(1000);     
              } 
}

void verificar_existencia_de_usuario(TCadena nombreFichero)
{
    ifstream archivo(nombreFichero); 
    if (!archivo)
    {
             cout<<"\nNombre de Usuario DISPONIBLE\n"<<endl;Sleep(2500);
             }
             else 
             {
             cout<<"\n Este Nombre de Usuario ya Existe.....INTENTELO DE NUEVO"<<endl; Sleep(1500); borrar_pantalla();main();      
             }   
}

void verificar_contrasena(TCadena nombreFichero,Persona_R &password)
{
	string cadena;
	string contrase;
	gotoxy(10,6);
	cout << "Escriba su PASS:                 " ;
	cin >> password.PASS;
	ifstream fichero(nombreFichero,ios::in);	   
	   while(!fichero.eof()) {                 
	      fichero >> cadena;   
	  }
	  if(cadena!=md5(password.PASS)){
	  cout<<"\n PASS es INCORRECTO.....INTENTELO DE NUEVO\n"<<endl;Sleep(1000);
	  fichero.close();}
	  
	if(cadena==md5(password.PASS)){
	cout<<"\n Su PASS es CORRECTA..!!! \n"<<endl; Sleep(1000);
	mainSec();
	}
}

