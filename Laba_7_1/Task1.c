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

	// ��������� ������� ������� A
	int size_A;

	// ���� ���������� ��������� ������� A
	puts("������� ���-�� ��������� ������� A:");
	while (scanf("%d", &size_A) != 1 || size_A < 1)
	{
		while (getchar() != '\n');
		puts("�� ����� ���-�� �� ���, ��������� ����:");
	}

	// ��������� ������ A � ������������ �����
	int* arr_A = (int*)malloc(size_A * sizeof(int));
	int* arr_A_orig = arr_A;

	// ���������� ������� A ���������� �������
	printf("\n������ A:");
	for (int i = 0; i < size_A; arr_A++, i++)
	{
		*arr_A = rand() % (MAX - MIN + 1) + MIN;
		printf("\narr_A[%2d] = %d", i + 1, *arr_A);
	} 

	arr_A = arr_A_orig;

	// ����
	puts("\n\n����������:");
	puts("\n1 - ��������� �������������� �� ����������� ������� ������� ������� ���� ������������� ��������,\n���� �� ������� ���������� �� �����������, � ������ - �� ��������.");
	puts("2 - ����� ���������� �� �������� �������  ����� ������� ��������� � ������������� ������ ����������,\n������������ ������ ������.");
	puts("3 - ��������� ���������� �� ��������");
	puts("4 - ���������� ��������� �� �����������");
	puts("5 - ����� ���������� �� �������� ����������� ������������� ��������,\n���������� ������������� �������� ��������� ����� �������");
	puts("\n������� ����� ������������ ��� ����������:");

	// ��������� ����� ���������� ������� ����������
	int sort;
	while (scanf("%d", &sort) != 1 || sort > 5 || sort < 1)
	{
		while (getchar() != '\n');
		puts("�� ����� ���-�� �� ���, ��������� ����:");
	}

	switch (sort)
	{
	case 1:
	{
		// ��������� ������ ������� B
		int size_B;

		// ���� ���������� ��������� ������� B
		puts("\n������� ���-�� ��������� ������� B:");
		while (scanf("%d", &size_B) != 1 || size_B < 1)
		{
			while (getchar() != '\n');
			puts("�� ����� ���-�� �� ���, ��������� ����:");
		}

		// ��������� ������ B � ������������ �����
		int* arr_B = (int*)malloc(size_B * sizeof(int));
		int* arr_B_orig = arr_B;

		// ���������� ������� B ���������� �������
		puts("\n������ B:");
		for (int i = 0; i < size_B; arr_B++, i++)
		{
			*arr_B = rand() % (MAX - MIN + 1) + MIN;
			printf("arr_B[%2d] = %d\n", i + 1, *arr_B);
		}

		// ��������� ����������� ���������� ��� ���������� ���������
		int temp, step_A, step_B, flag = 1;
		step_A = size_A - 1;
		step_B = size_B - 1;

		// ���������� ��������� ������� � �� �������� � �������� (������)
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

		// ���������� ��������� ������� � �� �������� � �������� (�����)
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

		// ���������� ��������� ������� B �� �������� � �������� (������)
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

		// ���������� ��������� ������� � �� �������� � �������� (�����)
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

		// ����� ���������������� ������� A
		puts("\n��������������� ������ A:");
		for (int i = 0; i < size_A; arr_A++, i++)
		{
			printf("arr_A[%2d] = %d\n", i + 1, *arr_A);
		}

		// ����� ���������������� ������� B
		puts("\n��������������� ������ B:");
		for (int i = 0; i < size_B; arr_B++, i++)
		{
			printf("arr_B[%2d] = %d\n", i + 1, *arr_B);
		}

		// ��������� ����� ������
		int* arr_C = (int*)malloc((size_B + size_A) * sizeof(int));
		int* arr_C_orig = arr_C;

		// ��������� ���������� ��� ���������� ��������
		arr_B = arr_B_orig + size_B - 1;
		arr_A = arr_A_orig;

		// ��������� ���������� ��������
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

		// ������� ������ C
		puts("\n������ C, ������������ �������� �������� A � B:");
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
		// ���� ������ ����������
		break;
	}
	case 3:
	{
		// ���� ������ ����������
		break;
	}
	case 4:
	{
		// ��������� ����������� ���������� ��� ���������� ���������
		int temp, step_A, flag = 1;
		step_A = size_A - 1;

		// ���������� ��������� ������� � �� �������� � �������� (������)
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

		// ���������� ��������� ������� � �� �������� � �������� (�����)
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

		// ����� ���������������� ������� A
		puts("\n��������������� ������ A:");
		for (int i = 0; i < size_A; i++)
		{
			printf("arr_A[%2d] = %d\n", i + 1, arr_A[i]);
		}

		break;
	}
	default:
	{
		// ���� ����� ����������
		break;
	}
	}

	system("pause");
}