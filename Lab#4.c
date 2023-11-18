#include <stdio.h>
#include <stdlib.h>
#include <locale.h>// Для языковых настроек

//Структура, которая описывает информацию о стране
typedef struct {
    char country[50];
    char capital[50];
    char language[50];
    char money[50];
    double square;
} Country;

int i;

/*Функция, которая запрашивает информацию о стране у пользователя
и заполняет поля структуры country значениями, введенными пользователем*/
void fillCountryData(Country* nation) {

	setlocale(LC_ALL,""); 
	
	// -> выбор элемента по указателю (позволяет получать доступ к элементам в структурах и объединениях)
    printf("Enter country name: ");
    scanf("%s", nation->country);
    
    printf("Enter the capital of the country: ");
    scanf("%s", nation->capital);
    
    printf("Enter the national language: ");
    scanf("%s", nation->language);
    
    printf("Enter currency: ");
    scanf("%s", nation->money);
    
    printf("Enter the area of country: ");
    scanf("%lf", &nation->square);
}

//Функция, которая записывает информацию о странах из массива структур nations в файл "countries.txt" 
void writeCountriesToFile(const Country* nations, int size) {
	setlocale(LC_ALL,""); 
    FILE* file = fopen("countries.txt", "w");
    if (file == NULL) {
        printf("Failed to open file!\n");
        return;
    }

    for (i = 0; i < size; i++) {
        fprintf(file, "%s ", nations[i].country);
        fprintf(file, "%s ", nations[i].capital);
        fprintf(file, "%s ", nations[i].language);
        fprintf(file, "%s ", nations[i].money);
        fprintf(file, "%lf ", nations[i].square);
    }
    fclose(file);
}

/*Функция, которая считывает информацию о странах из файла "countries.txt"
и сохраняет ее в массиве структур nations*/
void readCountriesFromFile(Country* nations, int size) {
	setlocale(LC_ALL,""); 
    FILE* file = fopen("countries.txt", "r");
    if (file == NULL) {
        printf("Failed to open file!\n");
        return;
    }
    
    for (i = 0; i < size; i++) {
        fscanf(file, "%s", nations[i].country);
        fscanf(file, "%s", nations[i].capital);
        fscanf(file, "%s", nations[i].language);
        fscanf(file, "%s", nations[i].money);
        fscanf(file, "%lf", &nations[i].square);
    }
    fclose(file);
}

//Функция для вывода информации об странах, чья площадь меньше средней площади всех стран
void printCountriesBySquare(const Country* nations, int size, double averageArea) {
	setlocale(LC_ALL,""); 
    printf("\nCountry information %s:\n");
    for (i = 0; i < size; i++){																																			 
        if (nations[i].square < averageArea) {
            printCountry(&nations[i]);           
        }
    }
}

//Функция, котрая выводит информацию о стране на экран
void printCountry(const Country* nation) {
	setlocale(LC_ALL,""); 
    printf("The name of the country: %s\n", nation->country);
    printf("The capital of country: %s\n", nation->capital);
    printf("Official language: %s\n", nation->language);
    printf("Currency unit: %s\n", nation->money);
    printf("Country area: %lf\n", nation->square);
}


int main() {
    system ("cls");
	setlocale(LC_ALL,""); 
    int size = 5;
    double totalArea;

    // Выделение памяти для массива структур
    Country* nations = (Country*)malloc(size * sizeof(Country));
    
    int choice;
    printf("Select a source to fill in the data:\n");
    printf("1 - reading from file\n");
    printf("2 - keyboard input\n");
    printf("Enter the action number: ");
    scanf("%d", &choice);
    
    if (choice == 1) { // чтение из файла
        readCountriesFromFile(nations, size);

    } else if (choice == 2) { //ввод с клавиатуры
        for (i = 0; i < size; i++) {
            printf("\nEnter country details %d:\n", i + 1);
            fillCountryData(&nations[i]);
        }
        
        writeCountriesToFile(nations, size);
    } else { //выход
        printf("Incorrect choice!\n");
    }
    
    for (i = 0; i < size; i++){
        totalArea += nations[i].square;
    }
    double averageArea = totalArea / size;
    printCountriesBySquare(nations, size, averageArea);

    // Освобождение выделенной памяти
    free(nations);
    
    return 0;
}
