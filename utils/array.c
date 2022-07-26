#include <stdio.h>

#include "array.h"

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