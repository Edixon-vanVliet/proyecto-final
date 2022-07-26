#include <stdio.h>
#include <stdlib.h>

#include "algebra.h"
#include "../utils/array.h"
#include "../utils/console.h"

// Hacer un programa que reordene una lista de números en una secuencia de
// valores algebraicos en forma Ascendente (de menor a mayor) en valor absoluto,
// y, de menor a mayor algebraicamente con signo, utilizando una
// formación (matrices) unidimensional de enteros.

int array_size;

void get_numbers(int *numbers, int *absolute_numbers);

void algebra()
{
    array_size = get_array_size("Cuantos numeros desea introducir?");

    int numbers[array_size], absolute_numbers[array_size];

    get_numbers(numbers, absolute_numbers);

    sort_array(numbers, array_size);
    sort_array(absolute_numbers, array_size);

    print_array("Secuencia ordenada con signo: ", numbers, array_size);
    print_array("Secuencia ordenada sin signo: ", absolute_numbers, array_size);

    printf("\nPresione cualquier tecla para continuar.");
    pause_console();
}

void get_numbers(int *numbers, int *absolute_numbers)
{
    for (int i = 0; i < array_size; i++)
    {
        clear_console();
        printf("Cual es valor numero #%d\n\n", i + 1);
        printf(">> ");
        scanf("%d", &numbers[i]);

        absolute_numbers[i] = abs(numbers[i]);
    }

    clear_console();
}