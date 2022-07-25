#include <stdio.h>
#include "tabla.h"

// Escribir un programa que pida por teclado una serie de números enteros, los
// almacene en una tabla alocada dinámicamente, escriba por pantalla de manera
// alocada todos los números introducidos indicando además cuál es el mayor y el
// menor.

void tabla()
{
    int mayor = 0;
    int menor = 0;
    int numeros[100];
    int cantidadNumeros = 0;
    printf("Cuantos numeros desea introducir? ");
    scanf("%d", &cantidadNumeros);
    for (int i = 0; i < cantidadNumeros; i++)
    {
        printf("\nCual es valor numero #%d ", i + 1);
        scanf("%d", &numeros[i]);
        if (i == 0)
        {

            mayor = numeros[i];
            menor = numeros[i];
        }
        else if (numeros[i] < menor)
        {

            menor = numeros[i];
        }


        else if (numeros[i] > mayor)
        {
            mayor = numeros[i];
        }
    }
    printf("\nEl numero menor introducido es: %i ", menor);
    printf("\nEl numero mayor introducido es: %i \n", mayor);

    for (int i = 0; i < cantidadNumeros; i++)
    {
        printf("%d,", numeros[i]);
    }
    printf("\n");
}