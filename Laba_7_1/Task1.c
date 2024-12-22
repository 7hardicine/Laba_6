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

	// ���������� ������� A ���������� �������
	puts("������ A:");
	for (int i = 0; i < size_A; i++)
	{
		*(arr_A + i) = rand() % (MAX - MIN + 1) + MIN;
		printf("arr_A[%2d] = %d\n", i + 1, *(arr_A + i));
	} 

	// ����
	puts("\n����������:\n");
	puts("1 - ������� ���� ��������, ���� �� ������� ���������� �� �����������, � ������ - �� ��������.");
	puts("2 - �����������  �� �������� � ������������� ����������� ����������, ������������ ������ ������.");
	puts("3 - ��������� ���������� �� ��������");
	puts("4 - ���������� ��������� �� �����������");
	puts("5 - ���������� ������� ������������� �������� ����� �������\n");
	puts("������� ����� ������������ ��� ����������:");

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

		// ���������� ������� B ���������� �������
		puts("\n������ B:");
		for (int i = 0; i < size_B; i++)
		{
			*(arr_B + i) = rand() % (MAX - MIN + 1) + MIN;
			printf("arr_B[%2d] = %d\n", i + 1, *(arr_B + i));
		}

		// ��������� ����������� ���������� ��� ���������� ���������
		int temp, step_A, step_B, flag = 1;
		step_A = size_A - 1;
		step_B = size_B - 1;

		// ���������� ��������� ������� � �� �������� � �������� (������)
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

		// ���������� ��������� ������� � �� �������� � �������� (�����)
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

		// ���������� ��������� ������� B �� �������� � �������� (������)
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

		// ���������� ��������� ������� � �� �������� � �������� (�����)
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

		// ����� ���������������� ������� A
		puts("\n��������������� ������ A:");
		for (int i = 0; i < size_A; i++)
		{
			printf("arr_A[%2d] = %d\n", i + 1, *(arr_A + i));
		}

		// ����� ���������������� ������� B
		puts("\n��������������� ������ B:");
		for (int i = 0; i < size_B; i++)
		{
			printf("arr_B[%2d] = %d\n", i + 1, *(arr_B + i));
		}

		// ��������� ����� ������
		int* arr_C = (int*)malloc((size_B + size_A) * sizeof(int));

		// ��������� ���������� ��� ���������� ��������
		int j = size_B - 1;
		int i = 0;

		// ��������� ���������� ��������
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

		// ������� ������ C
		puts("\n������ C, ������������ �������� �������� A � B:");
		for (int i = 0; i < size_A + size_B; i++)
		{
			printf("arr_C[%2d] = %d\n", i + 1, *(arr_C + i));
		}

		free(arr_C);

		break;
	}
	case 2:
	{
		// ��������� ����������� ����������
		int temp;

		// ����������� ���������� �� �������� ������ ������
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

		// ����� ���������������� ������� A
		puts("\n��������������� ������ A:");
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

		// ��������� ���������� �� ��������
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

		// ����� ���������������� ������� A
		puts("\n��������������� ������ A:");
		for (int i = 0; i < size_A; i++)
		{
			printf("arr_A[%2d] = %d\n", i + 1, *(arr_A + i));
		}

		free(arr_A);

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

		// ���������� ��������� ������� � �� �������� � �������� (�����)
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

		// ����� ���������������� ������� A
		puts("\n��������������� ������ A:");
		for (int i = 0; i < size_A; i++)
		{
			printf("arr_A[%2d] = %d\n", i + 1, *(arr_A + i));
		}

		free(arr_A);

		break;
	}
	default:
	{
		// ��������� ����������� ����������
		int temp;

		// ���������� �������, �������� ������������ ������� ����� �������
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

		// ����� ���������������� ������� A
		puts("\n��������������� ������ A:");
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