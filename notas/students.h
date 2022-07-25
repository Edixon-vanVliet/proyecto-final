#ifndef STUDENTS_DOT_H
#define STUDENTS_DOT_H

struct Student
{
    char name[20];
    struct Student *next;
    float *grades;
};

struct Students
{
    struct Student *head;
    struct Student *tail;

    int count;
};

void add_student(struct Students *students, char name[20], float *grades, int number_of_grades);
void free_students(struct Students *students);

#endif