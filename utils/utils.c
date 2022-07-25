#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

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
