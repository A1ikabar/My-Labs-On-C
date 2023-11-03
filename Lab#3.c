//Задан массив из k чисел. Заменить единицами все положительные элементы, имеющие четный порядковый номер и идущие после
//минимального элемента массива.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int* input(int *num)
{
    int i,n;
    printf("Input number of elements: ");
    scanf("%d",&n);
    int * a = malloc(n*sizeof(int));
    if (a==NULL) 
    printf ("The required memory is not allocated!");
    for(i = 0; i < n; i++)
    {
      printf("a[%d] = ",i);
      scanf("%d", &a[i]);
    }
    *num = n;
    return a;
}

int* MassNum(int *a, int n)
{
  int maxminpos,maxmin;
  for (int i = 0; i < n; i++)
    {
      if (a[i] < maxmin){
        printf("Join | ");
        maxmin = a[i];
        maxminpos = i;      
      }
    }
    printf("%d | ",maxminpos);
  return (maxminpos);
}

void Chng(int *a, int n, int maxminpos)
{
  int i;
  printf("%d <- Got from MassNum ",maxminpos);
  for (i = 0; i < n; i++){
    for (maxminpos; maxminpos<n; maxminpos++){
      int pos = maxminpos;
      if (pos % 2 == 0){
        a[maxminpos] = 1;
      }
    }
  }
}

void output(int *a, int n)
{
  int i;
  for(i = 0; i < n; i++)
  {
    printf("\na[%d] = %d",i, a[i]);
  }
}

int main() {
  system("cls");
  int n;
  int *a = input(&n);
  printf("Least mass is on: ");   
  int *b = MassNum(a,n);
  Chng(a,n,b);
  output(a,n);
  free(a);
  getch();
  return 0;
}
