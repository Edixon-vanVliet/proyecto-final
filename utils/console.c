#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "console.h"

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
    fflush(stdin);

#ifdef _WIN32
    getch();
#else
    getchar();
#endif
}

void sleep_console(int seconds)
{
    fflush(stdout);

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