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

	puts("������� ���-�� ��������� ������� A � B ����� ������:");

	while (scanf("%d %d", &size_A, &size_B) != 2 || size_A < 1 || size_B < 1)
	{
		while (getchar() != '\n');
		puts("�� ����� ���-�� �� ���, ��������� ����:");
	}

	arr_A = (int*)malloc(size_A * sizeof(int));
	arr_B = (int*)malloc(size_B * sizeof(int));

	printf("\n������ A:");

	for (int i = 0; i < size_A; i++)
	{
		arr_A[i] = rand() % (MAX - MIN + 1) + MIN;
		printf("\narr_A[%2d] = %d", i + 1, arr_A[i]);
	} 

	printf("\n\n������ B:");

	for (int i = 0; i < size_B; i++)
	{
		arr_B[i] = rand() % (MAX - MIN + 1) + MIN;
		printf("\narr_B[%2d] = %d", i + 1, arr_B[i]);
	}

	puts("\n\n����������:");
	puts("\n1 - ��������� �������������� �� ����������� ������� ������� ������� ���� ������������� ��������,\n���� �� ������� ���������� �� �����������, � ������ - �� ��������.");
	puts("2 - ����� ���������� �� �������� �������  ����� ������� ��������� � ������������� ������ ����������,\n������������ ������ ������.");
	puts("3 - ��������� ���������� �� ��������");
	puts("4 - ���������� ��������� �� �����������");
	puts("5 - ����� ���������� �� �������� ����������� ������������� ��������, \n���������� ������������� �������� ��������� ����� �������");
	puts("\n������� ����� ������������ ��� ����������:");

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