#include <stdio.h>
#include <Windows.h>
void main(){
	SetConsoleCP (1251);
	SetConsoleOutputCP (1251);
	//задача 4
/*
	printf("Введите N => ");
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
		printf("N должно быть каким-то хотя бы \n");
	}*/
	//Задача 5
	/*int a, n, i, chislo;
	i = 1;
	chislo = 0;
	printf("Введите N => ");
	scanf_s("%d", &n);
	printf("Введите A => ");
	scanf_s("%d", &a);
	do {
		if (i % a == 0) {
			printf("%d \n", i);
			
		}
		i++;
	} while (i <= n);*/

	//Задача 6
	float a, d, a1;
	int n, i;
	printf("Первый член арифметической прогрессии = ");
	scanf_s("%f", &a);
	printf("Прибавлять по ");
	scanf_s("%f", &d);
	printf("Чисел нужно = ");
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
	printf("Сумма этих чисел = %2f \n", S);
	system("pause");
}