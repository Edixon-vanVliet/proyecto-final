#include <stdio.h>

#include "tabla.h"
#include "../utils/array.h"
#include "../utils/console.h"

// Escribir un programa que pida por teclado una serie de números enteros, los
// almacene en una tabla alocada dinámicamente, escriba por pantalla de manera
// alocada todos los números introducidos indicando además cuál es el mayor y el
// menor.

int array_size;

void obtain_numbers(int *min, int *max, int *numbers);
void print_numbers(int *min, int *max, int *numbers);

void tabla()
{
    array_size = get_array_size("Cuantos numeros desea introducir?");

    int min, max, numbers[array_size];

    obtain_numbers(&min, &max, numbers);
    print_numbers(&min, &max, numbers);
}

void obtain_numbers(int *min, int *max, int *numbers)
{
    for (int i = 0; i < array_size; i++)
    {
        clear_console();
        printf("Cual es valor numero #%d\n\n", i + 1);
        printf(">> ");
        scanf("%d", &numbers[i]);

        if (i == 0)
        {
            *max = numbers[i];
            *min = numbers[i];
        }
        else if (numbers[i] < *min)
        {
            *min = numbers[i];
        }
        else if (numbers[i] > *max)
        {
            *max = numbers[i];
        }
    }

    clear_console();
}

void print_numbers(int *min, int *max, int *numbers)
{
    printf("El menor numero introducido es: %i\n", *min);
    printf("El mayor numero introducido es: %i\n", *max);
    print_array("   La secuencia introducida es: ", numbers, array_size);
    printf("\n");

    printf("Presione cualquier tecla para continuar.");
    pause_console();
}
