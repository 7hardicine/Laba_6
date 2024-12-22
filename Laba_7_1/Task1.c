#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <locale.h>
#include <time.h>
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

	// Заполнение массива A случайными числами
	puts("Массив A:");
	for (int i = 0; i < size_A; i++)
	{
		*(arr_A + i) = rand() % (MAX - MIN + 1) + MIN;
		printf("arr_A[%2d] = %d\n", i + 1, *(arr_A + i));
	} 

	// Меню
	puts("\nСортировки:\n");
	puts("1 - Слияние двух массивов, один из которых упорядочен по возрастанию, а другой - по убыванию.");
	puts("2 - Пузырьковая  по убыванию с фиксированным количеством просмотров, направленных справа налево.");
	puts("3 - Шейкерная сортировка по убыванию");
	puts("4 - Сортировка расчёской по возрастанию");
	puts("5 - Сортировка выбором максимального элемента слева направо\n");
	puts("Введите номер интересующей вас сортировки:");

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

		// Заполнение массива B случайными числами
		puts("\nМассив B:");
		for (int i = 0; i < size_B; i++)
		{
			*(arr_B + i) = rand() % (MAX - MIN + 1) + MIN;
			printf("arr_B[%2d] = %d\n", i + 1, *(arr_B + i));
		}

		// Объявляем необходимые переменные для сортировки расчёской
		int temp, step_A, step_B, flag = 1;
		step_A = size_A - 1;
		step_B = size_B - 1;

		// Сортировка расчёской массива А от меньшего к большему (начало)
		while (step_A > 1) 
		{
			for (int i = 0; i < size_A; i++)
			{
				if (*(arr_A + i) < *(arr_A + i + step_A))
				{
					temp = *(arr_A + i);
					*(arr_A + i) = *(arr_A + step_A + i);
					*(arr_A + step_A + i) = temp;
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
				if (*(arr_A + i) > *(arr_A + i + 1))
				{
					temp = *(arr_A + i);
					*(arr_A + i) = *(arr_A + i + 1);
					*(arr_A + i + 1) = temp;
					flag = 1;
				}
			}
		}

		// Сортировка расчёской массива B от большего к меньшему (начало)
		while (step_B > 1)
		{
			for (int i = 0; i < size_B; i++)
			{
				if (*(arr_B + i) > *(arr_B + i + step_B))
				{
					temp = *(arr_B + i);
					*(arr_B + i) = *(arr_B + i + step_B);
					*(arr_B + i + step_B) = temp;
				}
				step_B /= K;
			}
		}

		flag++;

		// Сортировка расчёской массива А от меньшего к большему (конец)
		while (flag)
		{
			flag = 0;
			for (int i = 0; i < size_B - 1; i++)
			{
				if (*(arr_B + i) < *(arr_B + i + 1))
				{
					temp = *(arr_B + i);
					*(arr_B + i) = *(arr_B + i + 1);
					*(arr_B + i + 1) = temp;
					flag = 1;
				}
			}
		}

		// Вывод отсортированного массива A
		puts("\nОтсортированный массив A:");
		for (int i = 0; i < size_A; i++)
		{
			printf("arr_A[%2d] = %d\n", i + 1, *(arr_A + i));
		}

		// Вывод отсортированного массива B
		puts("\nОтсортированный массив B:");
		for (int i = 0; i < size_B; i++)
		{
			printf("arr_B[%2d] = %d\n", i + 1, *(arr_B + i));
		}

		// Объявляем новый массив
		int* arr_C = (int*)malloc((size_B + size_A) * sizeof(int));

		// Объявляем переменные для сортировки слиянием
		int j = size_B - 1;
		int i = 0;

		// Выполняем сортировку слиянием
		for (int l = 0; l < size_A + size_B; l++)
		{
			if (i < size_A)
			{
				if (j >= 0)
				{
					if (*(arr_A + i) <= *(arr_B + j))
					{
						*(arr_C + l) = *(arr_A + i);
						i++;
					}
					else
					{
						*(arr_C + l) = *(arr_B + j);
						j--;
					}
				}
				else
				{
					*(arr_C + l) = *(arr_A + i);
					i++;
				}
			}
			else
			{
				*(arr_C + l) = *(arr_B + j);
				j--;
			}
		}

		free(arr_A);
		free(arr_B);

		// Выводим массив C
		puts("\nМассив C, образованный слиянием массивов A и B:");
		for (int i = 0; i < size_A + size_B; i++)
		{
			printf("arr_C[%2d] = %d\n", i + 1, *(arr_C + i));
		}

		free(arr_C);

		break;
	}
	case 2:
	{
		// Объявляем необходимые переменные
		int temp;

		// Пузырьковая сортировка по убыванию справа налево
		for (int j = 0; j < size_A; j++)
		{
			for (int i = size_A; i > j; i--)
			{
				if (*(arr_A + i - 1) < *(arr_A + i))
				{
					temp = *(arr_A + i - 1);
					*(arr_A + i - 1) = *(arr_A + i);
					*(arr_A + i) = temp;
				}
			}
		}

		// Вывод отсортированного массива A
		puts("\nОтсортированный массив A:");
		for (int i = 0; i < size_A; i++)
		{
			printf("arr_A[%2d] = %d\n", i + 1, *(arr_A + i));
		}

		free(arr_A);

		break;
	}
	case 3:
	{
		int left = 0;
		int right = size_A - 1;
		int flag = 1;
		int temp;

		// Шейкерная сортировка по убыванию
		while ((left < right) && (flag = 1))
		{
			flag = 0;
			for (int i = left; i < right; i++)
			{
				if (*(arr_A + i) < *(arr_A + i + 1))
				{
					temp = *(arr_A + i);
					*(arr_A + i) = *(arr_A + i + 1);
					*(arr_A + i + 1) = temp;
					flag = 1;
				}
			}
			right--;
			for (int i = right; i > left; i--)
			{
				if (*(arr_A + i - 1) < *(arr_A + i))
				{
					temp = *(arr_A + i);
					*(arr_A + i) = *(arr_A + i - 1);
					*(arr_A + i - 1) = temp;
					flag = 1;
				}
			}
			left++;
		}

		// Вывод отсортированного массива A
		puts("\nОтсортированный массив A:");
		for (int i = 0; i < size_A; i++)
		{
			printf("arr_A[%2d] = %d\n", i + 1, *(arr_A + i));
		}

		free(arr_A);

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
			for (int i = 0; i < size_A; i++)
			{
				if (*(arr_A + i) < *(arr_A + i + step_A))
				{
					temp = *(arr_A + i);
					*(arr_A + i) = *(arr_A + i + step_A);
					*(arr_A + i + step_A) = temp;
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
				if (*(arr_A + i) > *(arr_A + i + 1))
				{
					temp = *(arr_A + i);
					*(arr_A + i) = *(arr_A + i + 1);
					*(arr_A + i + 1) = temp;
					flag = 1;
				}
			}
		}

		// Вывод отсортированного массива A
		puts("\nОтсортированный массив A:");
		for (int i = 0; i < size_A; i++)
		{
			printf("arr_A[%2d] = %d\n", i + 1, *(arr_A + i));
		}

		free(arr_A);

		break;
	}
	default:
	{
		// Объявляем необходимые переменные
		int temp;

		// Сортировка выбором, извлекая максимальный элемент слева направо
		for (int i = 0; i < size_A; i++)
		{
			int max = i;
			for (int j = i + 1; j < size_A; j++)
			{
				if (*(arr_A + j) > *(arr_A + max))
				{
					max = j;
				}
			}
			temp = *(arr_A + i);
			*(arr_A + i) = *(arr_A + max);
			*(arr_A + max) = temp;
		}

		// Вывод отсортированного массива A
		puts("\nОтсортированный массив A:");
		for (int i = 0; i < size_A; i++)
		{
			printf("arr_A[%2d] = %d\n", i + 1, *(arr_A + i));
		}

		free(arr_A);

		break;
	}
	}

	system("pause");
}