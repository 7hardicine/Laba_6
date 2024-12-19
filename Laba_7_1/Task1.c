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

	srand(time(NULL));

	// Объявляем размеры массивов A и B
	int size_A, size_B;

	// Ввод количества элементов массива A и B
	puts("Введите кол-во элементов массива A и B через пробел:");
	while (scanf("%d %d", &size_A, &size_B) != 2 || size_A < 1 || size_B < 1)
	{
		while (getchar() != '\n');
		puts("Вы ввели что-то не так, повторите ввод:");
	}

	// Объявляем массивы A и B
	int* arr_A = (int*)malloc(size_A * sizeof(int));
	int* arr_B = (int*)malloc(size_B * sizeof(int));

	// Заполнение массива A случайными числами
	printf("\nМассив A:");
	for (int i = 0; i < size_A; i++)
	{
		arr_A[i] = rand() % (MAX - MIN + 1) + MIN;
		printf("\narr_A[%2d] = %d", i + 1, arr_A[i]);
	} 

	// Заполнение массива B случайными числами
	printf("\n\nМассив B:");
	for (int i = 0; i < size_B; i++)
	{
		arr_B[i] = rand() % (MAX - MIN + 1) + MIN;
		printf("\narr_B[%2d] = %d", i + 1, arr_B[i]);
	}

	// Выбор для пользователя
	puts("\n\nСортировки:");
	puts("\n1 - Получение упорядоченного по возрастанию массива методом слияния двух упорядоченных массивов,\nодин из которых упорядочен по возрастанию, а другой - по убыванию.");
	puts("2 - Метод сортировки по убыванию обменом  рядом стоящих элементов с фиксированным числом просмотров,\nнаправленных справа налево.");
	puts("3 - Шейкерная сортировка по убыванию");
	puts("4 - Сортировка расчёской по возрастанию");
	puts("5 - Метод сортировки по убыванию извлечением максимального элемента, \nизвлечение максимального элемента проводить слева направо");
	puts("\nВведите номер интересующей вас сортировки:");

	// Считываем номер выбранного способа сортировки
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
		// Объявляем необходимые переменные для сортировки расчёской
		int temp, step_A, step_B, flag = 1;
		step_A = size_A - 1;
		step_B = size_B - 1;

		// Сортировка расчёской массива А от меньшего к большему (начало)
		while (step_A > 1) 
		{
			for (int i = 0; i + step_A < size_A; i++)
			{
				if (arr_A[i] < arr_A[i + step_A])
				{
					temp = arr_A[i];
					arr_A[i] = arr_A[i + step_A];
					arr_A[i + step_A] = temp;
				}
				step_A /= K;
			}
		}

		// Сортировка расчёской массива А от меньшего к большему (конец)
		while (flag) 
		{
			flag = 0;
			for (int i = 0; i < size_A - 1; i++)
			{
				if (arr_A[i] > arr_A[i + 1])
				{
					temp = arr_A[i];
					arr_A[i] = arr_A[i + 1];
					arr_A[i + 1] = temp;
					flag = 1;
				}
			}
		}

		// Сортировка расчёской массива B от большего к меньшему (начало)
		while (step_B > 1)
		{
			for (int i = 0; i + step_B < size_B; i++)
			{
				if (arr_B[i] > arr_B[i + step_B])
				{
					temp = arr_B[i];
					arr_B[i] = arr_B[i + step_B];
					arr_B[i + step_B] = temp;
				}
				step_B /= K;
			}
		}

		flag++;

		// Сортировка расёской массива B от большего к меньшему (конец)
		while (flag)
		{
			flag = 0;
			for (int i = 0; i < size_B - 1; i++)
			{
				if (arr_B[i] < arr_B[i + 1])
				{
					temp = arr_B[i];
					arr_B[i] = arr_B[i + 1];
					arr_B[i + 1] = temp;
					flag = 1;
				}
			}
		}

		// Вывод отсортированного массива A
		puts("\nОтсортированный массив A:");
		for (int i = 0; i < size_A; i++)
		{
			printf("arr_A[%2d] = %d\n", i + 1, arr_A[i]);
		}

		// Вывод отсортированного массива B
		puts("\nОтсортированный массив B:");
		for (int i = 0; i < size_B; i++)
		{
			printf("arr_B[%2d] = %d\n", i + 1, arr_B[i]);
		}

		// Объявляем новый массив
		int* arr_C = (int*)malloc((size_B + size_A) * sizeof(int));

		// Объявляем переменные для сортировки слиянием
		int i = 0, j = size_B - 1;

		// Выполняем сортировку слиянием
		for (int l = 0; l < size_A + size_B; l++)
		{
			if (i < size_A)
			{
				if (j >= 0)
				{
					if (arr_A[i] <= arr_B[j])
					{
						arr_C[l] = arr_A[i];
						i++;
					}
					else
					{
						arr_C[l] = arr_B[j];
						j--;
					}
				}
				else
				{
					arr_C[l] = arr_A[i];
					i++;
				}
			}
			else
			{
				arr_C[l] = arr_B[j];
				j--;
			}
		}

		puts("\nМассив C, образованный слиянием массивов A и B:");
		for (int i = 0; i < size_A + size_B; i++)
		{
			printf("arr_C[%2d] = %d\n", i + 1, arr_C[i]);
		}

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