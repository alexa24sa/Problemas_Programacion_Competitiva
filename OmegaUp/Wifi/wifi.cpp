//Problema Wifi
#include <iostream>
//#include <utiliity>
using namespace std;



int mapa[1024][1024];


/*
    Modificación: 1
    Consulta: 1024 * 1024 = 1,048,576 =  1x10^6

    seg: 2,000,000,000 dos mil millones operaciones por segundo
    seg: 2x10^9
    
    cantidad de consultas: 65,000 = 6x10^4

    1x10^6 (6x10^6) = 6x10^10 -- tiempo por fuerza bruta
*/

/*
    reducir el problema a un problema más pequeño
    tendremos que usar un vector:
     1 2 3 4 5 6 7 8 9 
    [0 0 4 5 0 0 2 0 0]
    [0 4 4 9 9 9 11 11 11]
    
    0 - 6: 9 dispositivos
    0 - 9: 11 dispositivos
    2 - 7: 11 - 4: 7 dispositivos 
*/


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin.precision(10);
    
    int n, operaciones, fila1, columna1, fila2, columna2, i, disp;
    
    cin>>n;
    
    do{
      cin>>operaciones;
      if(operaciones == 1){
          cin>>fila1>>columna1>>disp;
          for(i = columna1; i<n; i++){
              mapa[fila1][i]+=disp;
              
          }
      }
          
          if(operaciones ==2){
              cin>>fila1>> columna1>>fila2>>columna2;
              if(fila1 > fila2){
                  swap(fila1, fila2);
              }
              if(columna1> columna2){
                  swap(columna1,columna2);
              }
              
              disp = 0;
              if(fila1==0){
                  for(i=fila1; i<fila2; i++){
                      disp += mapa[i][columna2];
                  }
              }else{
                  for(i=fila1; i<fila2; i++){
                      disp += mapa[i][columna2] - mapa[i][columna1-1];
              }
              
              cout << disp << "\n";
          }
      }
      
    } while(operaciones!=3);
} 
   
