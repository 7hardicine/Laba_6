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

	// Объявляем размеры массива A
	int size_A;

	// Ввод количества элементов массива A
	puts("Введите кол-во элементов массива A:");
	while (scanf("%d", &size_A) != 1 || size_A < 1)
	{
		while (getchar() != '\n');
		puts("Вы ввели что-то не так, повторите ввод:");
	}

	// Объявляем массив A и оригинальный адрес
	int* arr_A = (int*)malloc(size_A * sizeof(int));
	int* arr_A_orig = arr_A;

	// Заполнение массива A случайными числами
	printf("\nМассив A:");
	for (int i = 0; i < size_A; arr_A++, i++)
	{
		*arr_A = rand() % (MAX - MIN + 1) + MIN;
		printf("\narr_A[%2d] = %d", i + 1, *arr_A);
	} 

	arr_A = arr_A_orig;

	// Меню
	puts("\n\nСортировки:");
	puts("\n1 - Получение упорядоченного по возрастанию массива методом слияния двух упорядоченных массивов,\nодин из которых упорядочен по возрастанию, а другой - по убыванию.");
	puts("2 - Метод сортировки по убыванию обменом  рядом стоящих элементов с фиксированным числом просмотров,\nнаправленных справа налево.");
	puts("3 - Шейкерная сортировка по убыванию");
	puts("4 - Сортировка расчёской по возрастанию");
	puts("5 - Метод сортировки по убыванию извлечением максимального элемента,\nизвлечение максимального элемента проводить слева направо");
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
		// Объявляем размер массива B
		int size_B;

		// Ввод количества элементов массива B
		puts("\nВведите кол-во элементов массива B:");
		while (scanf("%d", &size_B) != 1 || size_B < 1)
		{
			while (getchar() != '\n');
			puts("Вы ввели что-то не так, повторите ввод:");
		}

		// Объявляем массив B и оригинальный адрес
		int* arr_B = (int*)malloc(size_B * sizeof(int));
		int* arr_B_orig = arr_B;

		// Заполнение массива B случайными числами
		puts("\nМассив B:");
		for (int i = 0; i < size_B; arr_B++, i++)
		{
			*arr_B = rand() % (MAX - MIN + 1) + MIN;
			printf("arr_B[%2d] = %d\n", i + 1, *arr_B);
		}

		// Объявляем необходимые переменные для сортировки расчёской
		int temp, step_A, step_B, flag = 1;
		step_A = size_A - 1;
		step_B = size_B - 1;

		// Сортировка расчёской массива А от меньшего к большему (начало)
		while (step_A > 1) 
		{
			for (int i = 0; i < size_A; arr_A++, i++)
			{
				if (*arr_A < *(arr_A + step_A))
				{
					temp = *arr_A;
					*arr_A = *(arr_A + step_A);
					*(arr_A + step_A) = temp;
				}
				step_A /= K;
			}
			arr_A = arr_A_orig;
		}

		// Сортировка расчёской массива А от меньшего к большему (конец)
		while (flag) 
		{
			flag = 0;
			for (int i = 0; i < size_A - 1; arr_A++, i++)
			{
				if (*arr_A > *(arr_A + 1))
				{
					temp = *arr_A;
					*arr_A = *(arr_A + 1);
					*(arr_A + 1) = temp;
					flag = 1;
				}
			}
			arr_A = arr_A_orig;
		}

		// Сортировка расчёской массива B от большего к меньшему (начало)
		while (step_B > 1)
		{
			for (int i = 0; i < size_B; arr_B++, i++)
			{
				if (*arr_B > *(arr_B + step_B))
				{
					temp = *arr_B;
					*arr_B = *(arr_B + step_B);
					*(arr_B + step_B) = temp;
				}
				step_B /= K;
			}
			arr_B = arr_B_orig;
		}

		flag++;

		// Сортировка расчёской массива А от меньшего к большему (конец)
		while (flag)
		{
			flag = 0;
			for (int i = 0; i < size_B - 1; arr_B++, i++)
			{
				if (*arr_B < *(arr_B + 1))
				{
					temp = *arr_B;
					*arr_B = *(arr_B + 1);
					*(arr_B + 1) = temp;
					flag = 1;
				}
			}
			arr_B = arr_B_orig;
		}

		// Вывод отсортированного массива A
		puts("\nОтсортированный массив A:");
		for (int i = 0; i < size_A; arr_A++, i++)
		{
			printf("arr_A[%2d] = %d\n", i + 1, *arr_A);
		}

		// Вывод отсортированного массива B
		puts("\nОтсортированный массив B:");
		for (int i = 0; i < size_B; arr_B++, i++)
		{
			printf("arr_B[%2d] = %d\n", i + 1, *arr_B);
		}

		// Объявляем новый массив
		int* arr_C = (int*)malloc((size_B + size_A) * sizeof(int));
		int* arr_C_orig = arr_C;

		// Объявляем переменные для сортировки слиянием
		arr_B = arr_B_orig + size_B - 1;
		arr_A = arr_A_orig;

		// Выполняем сортировку слиянием
		for (arr_C; arr_C < arr_C_orig + size_A + size_B; arr_C++)
		{
			if (arr_A < arr_A_orig + size_A)
			{
				if (arr_B >= arr_B_orig)
				{
					if (*arr_A <= *arr_B)
					{
						*arr_C = *arr_A;
						arr_A++;
					}
					else
					{
						*arr_C = *arr_B;
						arr_B--;
					}
				}
				else
				{
					*arr_C = *arr_A;
					arr_A++;
				}
			}
			else
			{
				*arr_C = *arr_B;
				arr_B--;
			}
		}

		arr_A = arr_A_orig;
		free(arr_A);
		arr_B = arr_B_orig;
		free(arr_B);

		arr_C = arr_C_orig;

		// Выводим массив C
		puts("\nМассив C, образованный слиянием массивов A и B:");
		for (int i = 0; i < size_A + size_B; arr_C++, i++)
		{
			printf("arr_C[%2d] = %d\n", i + 1, *arr_C);
		}

		arr_C = arr_C_orig;
		free(arr_C);

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
		// Объявляем необходимые переменные для сортировки расчёской
		int temp, step_A, flag = 1;
		step_A = size_A - 1;

		// Сортировка расчёской массива А от меньшего к большему (начало)
		while (step_A > 1)
		{
			for (int i = 0; i < size_A; arr_A++, i++)
			{
				if (*arr_A < *(arr_A + step_A))
				{
					temp = *arr_A;
					*arr_A = *(arr_A + step_A);
					*(arr_A + step_A) = temp;
				}
				step_A /= K;
			}
			arr_A = arr_A_orig;
		}

		// Сортировка расчёской массива А от меньшего к большему (конец)
		while (flag)
		{
			flag = 0;
			for (int i = 0; i < size_A - 1; arr_A++, i++)
			{
				if (*arr_A > *(arr_A + 1))
				{
					temp = *arr_A;
					*arr_A = *(arr_A + 1);
					*(arr_A + 1) = temp;
					flag = 1;
				}
			}
			arr_A = arr_A_orig;
		}

		// Вывод отсортированного массива A
		puts("\nОтсортированный массив A:");
		for (int i = 0; i < size_A; i++)
		{
			printf("arr_A[%2d] = %d\n", i + 1, arr_A[i]);
		}

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