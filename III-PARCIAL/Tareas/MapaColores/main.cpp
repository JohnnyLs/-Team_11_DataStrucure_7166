#include  <cstdlib> 
#include  <iostream> 
#include  <conio.h> 
#include  <windows.h> 
#define vertices 500
#define nodos 300
#include "Operacion.cpp"
using namespace std;

int main(int argc, char *argv[])
{
  int i,j,cant_nodos,cant_aristas,ad[vertices][vertices];
  char s,N,n;
  do{  
  cout << "\n\t\tALGORITMO DE BUSQUEDA EXHAUSTIVA PARA EL COLOREADO DE MAPAS\n";  
  cout << "\t\t--------------------------------------------------\n"; 

  cout << "\n\n\t Ingrese Datos \n"; 
  cout << "\n\t Numero de Nodos: ";
  cin >> cant_nodos;
  cout << "\t Aristas: ";
  cin >> cant_aristas;  
  OperacionesMatriz ope;
  //Aqui se  crea la matriz de  adyacencia
  ope.IngresarMatriz(ad,cant_nodos,cant_aristas);//,ad);
  //Mostrar Matriz de Adyacencia
  /* cout <  < "\n\t";
   for(i=0;i < nds;i++)
     { for(j=0;j < nds;j++)
         ad[i][j]=ad[i][j]; 
        cout <  < "\n\t";
      }
  */    
  //Se colorea vertice  a  vertice en  el  orden inicial
  ope.BusquedaExhaustiva(ad,cant_nodos);//,ad);  
 cout << "\n\tSi desea continuar presione cualquier tecla \n\tSi no escriba 'n' o 'N': ";
 s=getch();
 system("cls");
  }while(s!='N' && s!='n');
 cout << "Hasta Luego!!!!";
 Sleep(1600);
 exit(0);    
  
 cout << "\n\n";
 system("PAUSE");
}
