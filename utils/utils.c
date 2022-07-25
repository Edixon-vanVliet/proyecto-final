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
