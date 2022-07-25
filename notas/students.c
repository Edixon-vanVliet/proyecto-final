#include <stdlib.h>
#include <string.h>
#include "students.h"

void add_student(struct Students *students, char name[20], float *grades, int number_of_grades)
{
    struct Student *student = (struct Student *)malloc(sizeof(struct Student));

    strcpy(student->name, name);
    student->grades = (float *)malloc(number_of_grades * sizeof(float));
    student->next = NULL;

    for (int i = 0; i < number_of_grades; i++)
    {
        student->grades[i] = grades[i];
    }

    if (!students->head)
    {
        students->head = student;
        students->tail = student;
    }
    else
    {
        students->tail->next = student;
        students->tail = student;
    }

    students->count = students->count + 1;
}

void free_students(struct Students *students)
{
    struct Student *temp;

    students->count = 0;
    students->tail = NULL;

    while (students->head)
    {
        temp = students->head;
        students->head = students->head->next;

        free(temp);
    }
}