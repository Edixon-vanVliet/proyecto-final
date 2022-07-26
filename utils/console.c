#include <conio.h>
#include <stdio.h>
#include <unistd.h>
#include <windows.h>

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