
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <stdbool.h>
#define M_PI 3.14159265358979323846 /* pi */
int main ()
{
float a,R,sq,S;
int choose, cn = 1;
do
{
    system ("cls");
    printf("Input '1' to choose CUBE or input '2' to choose SPHERE: ");
    scanf ("%d", &choose);
    if (choose == 1)
{
    printf("Enter the side of cube: ");
    scanf("%f", &a);
    sq = pow(a,3); //площадь куба
    printf("square of cube: %f", sq);
}
if (choose == 2)
{
    printf ("enter the side of the cube to find its diagonal: " );
    scanf ("%f", &a);
    R = sqrt(pow(a,2)*3)/2; // диагональ куба является диаметром описанной сферы
    S = 4*M_PI*pow(R,2);
    printf("S of sphere: %f\n", S);
}
if ((!choose == 1) && !(choose == 2))
    printf ("Incorrect data entered");
    cn = 2;
    printf("\nIf you want to continue enter '1' else programm will be finished: ");
    scanf ("%d", &cn);
}  while (cn == 1);
return 0;
}
