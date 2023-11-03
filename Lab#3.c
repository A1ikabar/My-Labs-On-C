//Задан массив из k чисел. Заменить единицами все положительные элементы, имеющие четный порядковый номер и идущие после
//минимального элемента массива.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void minposit(int a[], int n){
  int maxminpos, maxmin;
  int tek = n;
  for (int i = 0; i < n; i++){
    if (a[i] < maxmin){
      maxminpos = i;
    }
    massvis(maxminpos, a, tek);
  }
}

void massvis(int maxminpos, int a[], int n)
{
  for (int i = 0; i < n; i++){
    printf("%d",a[i]);
    for (maxminpos; maxminpos<n; maxminpos++){
      int pos = maxminpos;
      if (pos % 2 == 0){
        a[maxminpos] = 1;
      }
    }
  }
}

int main()
{
  int *a;  // указатель на массив
  int i, n;
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
    /*if (a[i] < maxmin){
        maxmin = a[i];
        maxminpos = i;      
    }*/
  }
  
  // Вывод элементов массива
  /*for (i = 0; i < n; i++){
    printf("%d",a[i]);
    for (maxminpos; maxminpos<n; maxminpos++){
      int pos = maxminpos;
      if (pos % 2 == 0){
          a[maxminpos] = 1;
      }
    }
  }*/

  massvis;
  return 0;
}