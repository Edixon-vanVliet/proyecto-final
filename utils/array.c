#include <stdio.h>

#include "array.h"

int get_array_size()
{
    int array_size;

    printf("Cuantos numeros desea introducir?\n\n");
    printf(">> ");
    scanf("%d", &array_size);

    return array_size;
}

void print_array(char *message, int *array, int size)
{
    printf("%s", message);

    for (int i = 0; i < size; i++)
    {
        printf("%d", array[i]);

        if (i != size - 1)
        {
            printf(", ");
        }
        else
        {
            printf("\n");
        }
    }
}

void sort_array(void *array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            int *left = &((int *)array)[i];
            int *right = &((int *)array)[j];

            if (*left > *right)
            {
                int temp = *left;
                *left = *right;
                *right = temp;
            }
        }
    }
}