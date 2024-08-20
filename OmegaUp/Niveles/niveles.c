#include <stdio.h>
#include <stdint.h>

int multiplicacionDigitos(int numero) {
    int producto = 1;
    while (numero > 0) {
        int digito = numero % 10;
        producto *= digito;        
        numero /= 10;             
    }
    return producto;
}

int sumaCuadrados(int numero){
  int suma = 0;
  while (numero > 0){
    int digito = numero % 10;
    suma += digito*digito;
    numero /= 10;
  }
  return suma;
}

int main() {
  int niveles;
  scanf("%d", &niveles);
  //fflush(stdin);
  while ((niveles--)>0) {
    int i, aux_1=0, aux_2=0;
    int rango_x, rango_y;
    scanf("\n%d %d", &rango_x, &rango_y);
    //fflush(stdin);
    for(i= rango_x; i<=rango_y; i++){
      if(multiplicacionDigitos(i)>sumaCuadrados(i)){
        aux_1++;
      }else if(multiplicacionDigitos(i)<sumaCuadrados(i)) {
        aux_2++;
      }
    //return 0;
    }
    printf("\n%d %d", aux_1, aux_2);

    // TODO: fixme.
  }

  return 0;
}
