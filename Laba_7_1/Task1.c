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

	// ��������� ������� �������� A � B
	int size_A, size_B;

	// ���� ���������� ��������� ������� A � B
	puts("������� ���-�� ��������� ������� A � B ����� ������:");
	while (scanf("%d %d", &size_A, &size_B) != 2 || size_A < 1 || size_B < 1)
	{
		while (getchar() != '\n');
		puts("�� ����� ���-�� �� ���, ��������� ����:");
	}

	// ��������� ������� A � B
	int* arr_A = (int*)malloc(size_A * sizeof(int));
	int* arr_B = (int*)malloc(size_B * sizeof(int));

	// ���������� ������� A ���������� �������
	printf("\n������ A:");
	for (int i = 0; i < size_A; i++)
	{
		arr_A[i] = rand() % (MAX - MIN + 1) + MIN;
		printf("\narr_A[%2d] = %d", i + 1, arr_A[i]);
	} 

	// ���������� ������� B ���������� �������
	printf("\n\n������ B:");
	for (int i = 0; i < size_B; i++)
	{
		arr_B[i] = rand() % (MAX - MIN + 1) + MIN;
		printf("\narr_B[%2d] = %d", i + 1, arr_B[i]);
	}

	// ����� ��� ������������
	puts("\n\n����������:");
	puts("\n1 - ��������� �������������� �� ����������� ������� ������� ������� ���� ������������� ��������,\n���� �� ������� ���������� �� �����������, � ������ - �� ��������.");
	puts("2 - ����� ���������� �� �������� �������  ����� ������� ��������� � ������������� ������ ����������,\n������������ ������ ������.");
	puts("3 - ��������� ���������� �� ��������");
	puts("4 - ���������� ��������� �� �����������");
	puts("5 - ����� ���������� �� �������� ����������� ������������� ��������, \n���������� ������������� �������� ��������� ����� �������");
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
		// ��������� ����������� ���������� ��� ���������� ���������
		int temp, step_A, step_B, flag = 1;
		step_A = size_A - 1;
		step_B = size_B - 1;

		// ���������� ��������� ������� � �� �������� � �������� (������)
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

		// ���������� ��������� ������� � �� �������� � �������� (�����)
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

		// ���������� ��������� ������� B �� �������� � �������� (������)
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

		// ���������� ������� ������� B �� �������� � �������� (�����)
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

		// ����� ���������������� ������� A
		puts("\n��������������� ������ A:");
		for (int i = 0; i < size_A; i++)
		{
			printf("arr_A[%2d] = %d\n", i + 1, arr_A[i]);
		}

		// ����� ���������������� ������� B
		puts("\n��������������� ������ B:");
		for (int i = 0; i < size_B; i++)
		{
			printf("arr_B[%2d] = %d\n", i + 1, arr_B[i]);
		}

		// ��������� ����� ������
		int* arr_C = (int*)malloc((size_B + size_A) * sizeof(int));

		// ��������� ���������� ��� ���������� ��������
		int i = 0, j = size_B - 1;

		// ��������� ���������� ��������
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

		puts("\n������ C, ������������ �������� �������� A � B:");
		for (int i = 0; i < size_A + size_B; i++)
		{
			printf("arr_C[%2d] = %d\n", i + 1, arr_C[i]);
		}

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
		// ���� ��������� ����������
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