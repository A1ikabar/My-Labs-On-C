/*9. Написать программу вычисления площади боковой поверхности куба и площади поверхности сферы, описанной около него. Длина ребра куба задается пользователем*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <stdbool.h>
#define M_PI		3.14159265358979323846	/* pi */

int main()
    {
    float a,R,sq,S;
    int wrchoose, choose, cn = 1;
    FILE *S1, *S2;
    double x, y;
    do 
    {   
        system ("cls");
        printf("Input '1' to choose CUBE or input '2' to choose SPHERE: ");
        scanf ("%d", &choose);     
            if (choose == 1)
            {               
                printf("Enter the side of cube: ");
                scanf("%lf", &x);
                S1 = fopen("S1.txt", "w");
                fprintf(S1, "%lf", x);
                fclose(S1);
                S1 = fopen("S1.txt", "r");
                S2 = fopen("S2.txt", "w");
                fscanf(S1, "%lf", &y);
                y = pow(y,3);
                printf ("S of cube: %lf", y);
                fclose(S1);
                fprintf(S2, "%lf\n", y);
                fclose(S2);
            }
             if (choose == 2)
            {
                 printf ("Enter the side of the cube to find its diagonal: " );
                 scanf("%lf", &x);
                 S1 = fopen("S1.txt", "w");
                 fprintf(S1, "%lf", x);
                 fclose(S1);
                 S1 = fopen("S1.txt", "r");
                 S2 = fopen("S2.txt", "w");
                 fscanf(S1, "%lf", &y);
                 y = 4*M_PI*pow(sqrt(pow(y,2)*3)/2,2);
                 printf("S of sphere: %lf\n", y);
                 fclose(S1);
                 fprintf(S2, "%lf\n", y);
                 fclose(S2);
            }
            if (!(choose == 1) && !(choose == 2)) 
                printf ("Incorrect data entered");
                   
        cn = 2;       
        printf("\nIf you want to continue enter '1' else programm will be finished: ");
        scanf ("%d", &cn);
    } while (cn == 1);
    return 0;
    }