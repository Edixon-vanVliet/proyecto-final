#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <unistd.h>
#include <windows.h>

void clear_console()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause_console()
{
#ifdef _WIN32
    getch();
#else
    getchar();
#endif
}

void sleep_console(int seconds)
{
#ifdef _WIN32
    Sleep(seconds * 1000);
#else
    sleep(seconds);
#endif
}

void print_character(char character, int times)
{
    for (int i = 0; i < times; i++)
    {
        printf("%c", character);
    }
}

void sort_array(float *array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}