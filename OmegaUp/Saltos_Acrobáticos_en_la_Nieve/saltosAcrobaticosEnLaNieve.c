#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*bool esPrimo(int numero){
  int esPrimo;
  if((numero % 2==0 || numero % 3==0  || numero % 5==0) && (numero != 2 ||numero != 3 ||numero != 5)){
    if(numero == 2 ||numero == 3 ||numero == 5){
        esPrimo = true;
        return esPrimo;
    }
    esPrimo = false;
  } else if(numero == 2 ||numero == 3 ||numero == 5){
    esPrimo = true;
  } else{
    esPrimo = true;
  }
  return esPrimo;
}*/

/*bool esPrimo(int numero) {
	if (numero <= 1) return false;
	if (numero == 2 || numero == 3 || numero == 5 || numero == 7) return true;
	if (numero % 2 == 0 || numero % 3 == 0 || numero % 5 == 0 || numero % 7 == 0) return false;
	return true;
}*/

bool esPrimo(int numero) {
    if (numero <= 1) return false;
    if (numero == 2 || numero == 3) return true;
    if (numero % 2 == 0 || numero % 3 == 0) return false;
    for (int i = 5; i * i <= numero; i += 6) {
        if (numero % i == 0 || numero % (i + 2) == 0) return false;
    }
    return true;
}

void encontrarMaximaSuma(int casos[], int n, int indice, int sumaActual, int* sumaMax) {
    if (indice == n) { // Caso base: hemos recorrido todos los elementos
        if (esPrimo(sumaActual) && sumaActual > *sumaMax) {
            *sumaMax = sumaActual; // Actualizamos la suma máxima si es un número primo
        }
        return;
    }

    // Exploramos dos opciones:
    // 1. Incluir el elemento actual en la suma
    encontrarMaximaSuma(casos, n, indice + 1, sumaActual + casos[indice], sumaMax);

    // 2. No incluir el elemento actual en la suma
    encontrarMaximaSuma(casos, n, indice + 1, sumaActual, sumaMax);
    /*las opciones anteriores generarán un arbol de opciones posibles, el algoritmo
    únicamente terminaría cuando el valor del índice sea igual al del valor de la n, lo que 
    nos generaría un arbol binario, ya que cada que se toma una decisión, hay otras dos posibles
    opciones, la opción 1 de incluir el valor y la opción 2 de no incluir el valor, pero cada
    que se explorán cada una de las posibles opciones, se almacenan entre cada pasada recursiva
    de las posibles opciones 
    Podemos visualizarlo así para un arreglo que contenga {1,2,3}:
                                     (raíz)
                                   |
                           [suma = 0, índice = 0]
                                /       \
                               /         \
              Incluir 1 (suma = 1)       No incluir 1 (suma = 0)
                            /   \                   /   \
                           /     \                 /     \
         Incluir 2 (suma = 3)  No incluir 2  Incluir 2  No incluir 2
                        /  \              /  \            /   \
                       /    \            /    \          /     \
Incluir 3 (suma = 6)  No incluir 3  Incluir 3  No incluir 3  Incluir 3  No incluir 3


Cada camino desde la raíz hasta una hoja representa una combinación específica de los elementos del arreglo:

Camino Izquierdo Completo (Incluir todo):

Incluye 1 → Incluye 2 → Incluye 3 → Suma = 1 + 2 + 3 = 6
Camino Izquierdo Parcial (No incluir el último):

Incluye 1 → Incluye 2 → No incluye 3 → Suma = 1 + 2 = 3
Otros Caminos:

Incluye 1 → No incluye 2 → Incluye 3 → Suma = 1 + 3 = 4
Incluye 1 → No incluye 2 → No incluye 3 → Suma = 1
No incluye 1 → Incluye 2 → Incluye 3 → Suma = 2 + 3 = 5
No incluye 1 → Incluye 2 → No incluye 3 → Suma = 2
No incluye 1 → No incluye 2 → Incluye 3 → Suma = 3
No incluye 1 → No incluye 2 → No incluye 3 → Suma = 0

        */
}

int main() {
	int saltos=0;
	int sumaActual=0, aux=0;
	scanf("%d", &saltos);
	int originalSaltos = saltos;
	//printf("\nnum originalSaltos: %d", originalSaltos);
	int casos[20];
	//printf("\ntam arr caso: %ld\n", sizeof(casos));
	for (int i = 0; i < saltos; i++) {
		scanf("%d", &casos[i]);
		//aux = casos[i];
		//suma += aux;
	}

    int primo;
    int sumaMax = 0;
    encontrarMaximaSuma(casos, saltos, 0, 0, &sumaMax);

    printf("%d\n", sumaMax);

	/*primo=esPrimo(sumaMax);
	if(primo==true) {
		printf("\n%d", sumaMax);
	} else {
		printf("\n%d", sumaMax);
	}*/



	return 0;
}
