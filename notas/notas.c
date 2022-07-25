#include <stdio.h>
#include "notas.h"

// Escribir un programa interactivo en C para procesar las notas de un grupo de
// estudiantes. Empezar especificando  el número de notas para cada estudiante.
// Luego introducir el nombre de cada estudiante y las notas de los exámenes.
// Calcular la nota media  para cada estudiante y una media general de la clase
// (o sea,  una media de las medias de los estudiantes). Escribir la media de
// la clase, seguida  por el nombre, las notas individuales de los exámenes y la
//  media para cada estudiante.

int number_of_grades;
void get_number_of_grades();
void notas()
{
    get_number_of_grades();
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
}