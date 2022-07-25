#include <stdio.h>
#include "algebra.h"

// Hacer un programa que reordene una lista de números en una secuencia de
// valores algebraicos en forma Ascendente (de menor a mayor) en valor absoluto,
// y, de menor a mayor algebraicamente con signo, utilizando una
// formación (matrices) unidimensional de enteros.

void algebra()
{
    int matriz[100];

    int cantidad_numeros;
    printf("Cuantos numeros quieres ordenar?\n");
    scanf("%d", &cantidad_numeros);

    for (int i = 0; i < cantidad_numeros; i++)
    {
        int x = 0;

        printf("Inserte un numero:\n");
        scanf("%d", &x);

        if (x < 0)
        {
            matriz[i] = x * -1;
        }
        else
        {
            matriz[i] = x;
        }
    }

    int i, element, j;
    for (i = 1; i < cantidad_numeros; i++)
    {
        element = matriz[i];
        j = i - 1;
        while (j >= 0 && matriz[j] > element)
        {
            matriz[j + 1] = matriz[j];
            j = j - 1;
        }
        matriz[j + 1] = element;
    }

    printf("\nLista ordenada:\n");
    for (int i = 0; i < cantidad_numeros; i++)
    {
        printf("%d\n", matriz[i]);
    }
}