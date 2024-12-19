#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <locale.h>
#define MIN -45
#define MAX 45
#define K 1.2473309

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int* arr_A;
	int* arr_B;
	int size_A, size_B;

	puts("Введите кол-во элементов массива A и B через пробел:");

	while (scanf("%d %d", &size_A, &size_B) != 2 || size_A < 1 || size_B < 1)
	{
		while (getchar() != '\n');
		puts("Вы ввели что-то не так, повторите ввод:");
	}

	arr_A = (int*)malloc(size_A * sizeof(int));
	arr_B = (int*)malloc(size_B * sizeof(int));

	printf("\nмассив A:");

	for (int i = 0; i < size_A; i++)
	{
		arr_A[i] = rand() % (MAX - MIN + 1) + MIN;
		printf("\narr_A[%2d] = %d", i + 1, arr_A[i]);
	} 

	printf("\n\nмассив B:");

	for (int i = 0; i < size_B; i++)
	{
		arr_B[i] = rand() % (MAX - MIN + 1) + MIN;
		printf("\narr_B[%2d] = %d", i + 1, arr_B[i]);
	}

	puts("\n\nСортировки:");
	puts("\n1 - Получение упорядоченного по возрастанию массива методом слияния двух упорядоченных массивов,\nодин из которых упорядочен по возрастанию, а другой - по убыванию.");
	puts("2 - Метод сортировки по убыванию обменом  рядом стоящих элементов с фиксированным числом просмотров,\nнаправленных справа налево.");
	puts("3 - Шейкерная сортировка по убыванию");
	puts("4 - Сортировка расчёской по возрастанию");
	puts("5 - Метод сортировки по убыванию извлечением максимального элемента, \nизвлечение максимального элемента проводить слева направо");
	puts("\nВведите номер интересующей вас сортировки:");

	int sort;

	while (scanf("%d", &sort) != 1 || sort > 5 || sort < 1)
	{
		while (getchar() != '\n');
		puts("Вы ввели что-то не так, повторите ввод:");
	}

	switch (sort)
	{
	case 1:
	{
		
		break;
	}
	case 2:
	{
		// Типо вторая сортировка
		break;
	}
	case 3:
	{
		// Типо третья сортировка
		break;
	}
	case 4:
	{
		// Типо четвертая сортировка
		break;
	}
	default:
	{
		// Типо пятая сортировка
		break;
	}
	}

	system("pause");
}