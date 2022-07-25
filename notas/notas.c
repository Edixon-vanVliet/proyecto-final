#include <ctype.h>
#include <stdio.h>
#include "notas.h"
#include "students.h"
#include "../utils/utils.h"

// Escribir un programa interactivo en C para procesar las notas de un grupo de
// estudiantes. Empezar especificando  el número de notas para cada estudiante.
// Luego introducir el nombre de cada estudiante y las notas de los exámenes.
// Calcular la nota media  para cada estudiante y una media general de la clase
// (o sea,  una media de las medias de los estudiantes). Escribir la media de
// la clase, seguida  por el nombre, las notas individuales de los exámenes y la
//  media para cada estudiante.

int number_of_grades;
struct Students students;

void get_number_of_grades();
void show_menu();
void manage_student();

void notas()
{
    get_number_of_grades();

    show_menu();
}

void get_number_of_grades()
{
    do
    {
        printf("Hola. Aqui puedes manejar las notas de los estudiantes.\n");
        printf("Primero especifica la cantidad de notas por cada estudiante.\n\n");

        printf(">> ");
        scanf(" %u", &number_of_grades);
    } while (number_of_grades <= 0);
}

void show_menu()
{
    char option;

    do
    {
        clear_console();

        printf("Hola. Aqui puedes manejar las notas de los estudiantes.\n\n");
        printf("1) Agregar estudiante\n");
        printf("2) Calcular Media de los estudiantes\n\n");

        printf("Presione S para [S]alir\n\n");

        printf(">> ");
        scanf(" %c", &option);
        option = tolower(option);

        clear_console();

        switch (option)
        {
        case '1':
            manage_student();
            break;
        case '2':
            break;
        case 's':
            continue;
        default:
            printf("Opcion elegida no disponible");
            sleep_console(2);
            clear_console();
            fflush(stdin);

            break;
        }
    } while (option != 's');
}

void manage_student()
{
    char name[20];
    float grades[number_of_grades];

    printf("Escriba el nombre del estudiante:\n\n");

    printf(">> ");
    scanf("%19s", name);

    for (int i = 0; i < number_of_grades; i++)
    {
        do
        {
            clear_console();

            printf("Introduzca la nota #%d\n\n", i + 1);
            scanf(" %f", &grades[i]);

            if (grades[i] < 0 || grades[i] > 100)
            {
                printf("\nLa nota debe de ser:\n");
                printf("1) Mayor o igual a 0\n");
                printf("2) Menor o igual a 100\n\n");

                printf("Presione cualquier tecla para continuar.");
                pause_console();
            }
        } while (grades[i] < 0 || grades[i] > 100);
    }

    add_student(&students, name, grades, number_of_grades);
}
