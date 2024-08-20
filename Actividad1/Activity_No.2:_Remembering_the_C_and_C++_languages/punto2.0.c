#include <stdio.h>

typedef struct Student
{
    float a1;
    float a2;
    float a3;
    float p1;
    float p2;
    float p3;
} Student;

float prom(Student *s)
{
    float prom = 0;
    prom += s->a1 * 0.05;
    prom += s->a2 * 0.15;
    prom += s->a3 * 0.15;
    prom += s->p1 * 0.25;
    prom += s->p2 * 0.2;
    prom += s->p3 * 0.2;
    return prom;
}

int main()
{
    printf("Punto 2\nDigite las notas en este orden a1, a2, a3, p1, p2, p3\n");
    Student s;
    scanf("%f %f %f %f %f %f", &s.a1, &s.a2, &s.a3, &s.p1, &s.p2, &s.p3);
    printf("su nota definita es %0.2f", prom(&s));
    return 0;
}