#ifndef STUDENTS_DOT_H
#define STUDENTS_DOT_H

struct Student
{
    char name[20];
    struct Student *next;
    float *grades;
};

#endif