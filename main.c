#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "algebra/algebra.h"
#include "notas/notas.h"
#include "tabla/tabla.h"
#include "utils/utils.h"

int main()
{
    char option;

    do
    {
        printf("Bienvenid@, este es el proyecto final de Bryant, Edixon y Jhon\n");
        printf("Eliga la opcion deseada para ver los programas\n\n");

        printf("1) Obtener mayor y menor numero de una tabla.\n");
        printf("2) Reordenar una lista de numeros\n");
        printf("3) Procesar las notas de un grupo de estudiantes\n\n");

        printf("Presione S para [S]alir\n\n");

        printf(">> ");
        scanf(" %c", &option);
        option = tolower(option);

        switch (option)
        {
        case '1':
            tabla();
            break;
        case '2':
            algebra();
            break;
        case '3':
            notas();
            break;
        case 's':
            continue;
        default:
            clear_console();
            printf("Opcion elegida no disponible");
            sleep(2);
            clear_console();
            fflush(stdin);
            break;
        }

    } while (option != 's');

    return 0;
}