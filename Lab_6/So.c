#include <stdio.h>
#include <Windows.h>
void main(){
	SetConsoleCP (1251);
	SetConsoleOutputCP (1251);
	//������ 4
/*
	printf("������� N => ");
	int n, i, a;
	a = 0;
	i = 0;
	scanf_s("%d", &n);
	if (n > 0) {
	do {
		a += 2;
		i++;
		printf("%d \n", a);
	} while (i < n);
	}
	else {
		printf("N ������ ���� �����-�� ���� �� \n");
	}*/
	//������ 5
	/*int a, n, i, chislo;
	i = 1;
	chislo = 0;
	printf("������� N => ");
	scanf_s("%d", &n);
	printf("������� A => ");
	scanf_s("%d", &a);
	do {
		if (i % a == 0) {
			printf("%d \n", i);
			
		}
		i++;
	} while (i <= n);*/

	//������ 6
	float a, d, a1;
	int n, i;
	printf("������ ���� �������������� ���������� = ");
	scanf_s("%f", &a);
	printf("���������� �� ");
	scanf_s("%f", &d);
	printf("����� ����� = ");
	scanf_s("%d", &n);
	a1 = a;
	i = 2;
	n += 2;
	do {
		a = a1 + (i - 1)*d;
		//printf("%f \n", a);
		i++;
	} while (i < n);
	float S = (a1 + a) * n * 1000000 /*/ 2*/;
	printf("����� ���� ����� = %2f \n", S);
	system("pause");
}