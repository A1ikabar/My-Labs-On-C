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
    for(i = 0; i < n; i++)
    {
        printf("a[%d] = ",i);
        scanf("%d", &a[i]);
    }
    *num = n;
    return a;
}

void MassNum(int *a, int n)
{
  int maxminpos;
  for (int i = 0; i < n; i++)
    {
      int maxmin;
      if (a[i] < maxmin){
        maxmin = a[i];
        maxminpos = i;      
      }
    }
  return maxminpos;
}

/*void Chng(int *a, int n, int maxminpos)
{
  int i;
  int maxminpos = MassNum;
  for (i = 0; i < n; i++){
    printf("%d",a[i]);
    for (maxminpos; maxminpos<n; maxminpos++){
      int pos = maxminpos;
      if (pos % 2 == 0){
          a[maxminpos] = 1;
      }
    }
  }
}*/

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
    printf("The smallest mass is on: ");   
    MassNum(a,n);
    //Chng(a,n,MassNum);
    output(a,n);
    free(a);
    getch();
    return 0;
}



/*
int main()
{
  int *a;  // указатель на массив
  int i, n, maxminpos, maxmin;
  system("cls");
  printf("Enter size of mass: ");
  scanf("%d", &n);
  // Выделение памяти
  a = (int*)malloc(n * sizeof(int));
  // Ввод элементов массива
  for (i = 0; i<n; i++)
  {
    printf("[%d] = ", i);
    scanf("%d", &a[i]);
    minposit(a,n);
    if (a[i] < maxmin){
        maxmin = a[i];
        maxminpos = i;      
    }
  }
  
  // Вывод элементов массива
  for (i = 0; i < n; i++){
    printf("%d",a[i]);
    for (maxminpos; maxminpos<n; maxminpos++){
      int pos = maxminpos;
      if (pos % 2 == 0){
          a[maxminpos] = 1;
      }
    }
  }

  return 0;
}
*/
