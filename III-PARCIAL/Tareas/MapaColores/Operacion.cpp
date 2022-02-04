#include <iostream>
#include "Operacion.h"

void OperacionesMatriz::IngresarMatriz(int ad[][vertices],int nds, int arst)
{   
  int i,j,nodoi,nodof; 
  
  for(i=0;i < nds;i++)
   { for(j=0;j < nds;j++)
        { ad[i][j]=0;}
   }
   
  //Llenamos la  matriz
  for(i=0;i < arst;i++)  
   { cout << "\n\n\tArista " << i+1 << "\n";
     cout << "\tN. inicio: ";
     cin >> nodoi;
     cout << "\tN. termino: ";
     cin >> nodof;   
     
     ad[nodoi-1][nodof-1]=1;
     ad[nodof-1][nodoi-1]=1;
   } 
  
   //Matriz de Adyacencia    
  /* for(i=0;i < nds;i++)
     { for(j=0;j < nds;j++)
         ad[i][j]=ad[i][j]; 
     
      }*/
}

void OperacionesMatriz::BusquedaExhaustiva(int ad[][vertices],int nds)
{ 
  ver v[nds];
  int i,j,aux,zz,max=1;   

  //Etapa de  Coloracion
   for(i=0;i < nds;i++)
    {v[i].color=1;
     zz=0;
     aux=1;
     while(aux==1)
      {for(j=0;j < nds;j++)
         { if(ad[j][i]==1)
            {if(v[i].color==v[j].color)
               { zz=1;}
            }
         }
         if(zz==1)
           {aux=1;
            zz=0;
            v[i].color++;
           }
         else
            {aux=0;}
            if(v[i].color   >   max)
              { max=v[i].color;}
       }
     }

  cout << "\n\tAlgoritmo Busqueda Exhaustiva \n" << "\tmaxcolor= " << max << "\n";

  //Se imprime el  conjunto de  vertices  de  cada color    
  for(i=0;i < max;i++)
  {printf("\t  %c= { ",'a'+i);
    for(j=0;j < nds;j++)
     { if(v[j].color==i+1)
         cout << " " << j+1;        
     }
    cout << "  }\n";
  }

}
