#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "notas.h"
#include "students.h"
#include "../utils/utils.h"

#define GRADE_SPACE 7

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
void print_header();
void print_grades();
void print_extra_spaces();
float calculate_student_median(struct Student *student);
float calculate_median(float *array, int size);

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
            print_header();
            print_grades();
            break;
        case 's':
            free_students(&students);
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

void print_header()
{
    printf("Nombre               | Calificaciones");
    print_character(' ', number_of_grades * GRADE_SPACE - 15);
    printf(" | Media\n");
    print_character('-', number_of_grades * GRADE_SPACE + (number_of_grades > 1 ? 31 : 39));
    printf("\n\n");
}

void print_grades()
{
    struct Student *current = students.head;
    int position = 0, total_grades = students.count * number_of_grades;
    float grades[total_grades];

    for (int i = 0; i < students.count; i++)
    {
        printf("%-20s |", current->name);

        for (int j = 0; j < number_of_grades; j++)
        {
            float grade = current->grades[j];

            printf("%7.2f", grade);
            grades[position] = grade;

            position++;
        }

        print_extra_spaces();

        printf(" | %6.2f\n", calculate_student_median(current));

        current = current->next;
    }

    printf("\n\n%26s %6.2f\n", "Media de la clase:", calculate_median(grades, total_grades));
    printf("Nota mas alta de la clase: %6.2f\n", grades[total_grades - 1]);
    printf("Nota mas baja de la clase: %6.2f\n\n", grades[0]);

    printf("Presione cualquier tecla para continuar.");
    pause_console();
}

void print_extra_spaces()
{
    switch (number_of_grades)
    {
    case 1:
        print_character(' ', 8);
        break;
    case 2:
        print_character(' ', 1);
        break;
    default:
        break;
    }
}

float calculate_student_median(struct Student *student)
{
    float grades[number_of_grades];
    memcpy(grades, student->grades, number_of_grades * sizeof(int));

    return calculate_median(student->grades, number_of_grades);
}

float calculate_median(float *array, int size)
{
    sort_array(array, size);
    float middle = size / 2;

    return size % 2 == 0
               ? (array[(int)middle - 1] + array[(int)middle]) / 2
               : array[(int)ceil(middle)];
}