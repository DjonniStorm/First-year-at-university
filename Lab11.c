#include <stdio.h>
#include <Windows.h>

//����� 1
void number1() {
	int n, m, i = 1, chislo;
	printf("������� n � m => ");
	scanf_s("%d %d", &n, &m);
	chislo = m;
	if (n <= 9 && m <= 9 && m>=0 && n>=0) {
		do {
			int x = 1;
			x += 10 * i;
			do {
				printf("%d ", x);
				x += 1;
				m--;
			} while (m > 0);
			printf("\n");
			i++;
			n--;
			m = chislo;
		} while (n > 0);
	}
	else {
		printf("N � M ������ ���� ������, ���� ����� 9 � >= 0\n");
	}
	
}
//����� 2
void number2() {
	int n = 10, m = 10, i = 1;
	//scanf_s("%d%d", &n, &m);
	int  chislo, k = 1;
	chislo = m;
	do {
		int chislo2 = 0;
		chislo2 += k;
		do {
			printf("  %2d ", chislo2*i);
			i++; m--;
		} while (m > 0);
		printf("\n");
		n--;
		m = chislo;
		k++; i = 1;
	} while (n > 0);
}
//����� 3
void number3() {
	int a, b, i, k;
	printf("�� ������ ����� => ");
	scanf_s("%d", &k);
	i = 1;
	b = 0;
	do {
		a = 1;
		b += i;
		do {
			printf(" %d ", a);
			a += 1;
			b--;
		} while (b > 0);
		printf("\n");
		i++;
	} while (i <= k);
}



void main() 
{
	int n;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	do {
		printf(" ________________________________________\n");
		printf("|                                        |\n");
		printf("|  1 ����� - �������                     |\n");
		printf("|  2 ����� - ������� ��������� (�� 100)  |\n");
		printf("|  3 ����� - ������� �� �����            |\n");
		printf("|________________________________________|\n");
		printf("����� ������ => ");
		scanf_s("%d", &n);
		switch (n) {
		case 1:
			number1();
			break;
		case 2:
			number2();
			break;
		case 3:
			number3();
			break;
		case 0:
			return;
		}
	} while (n != 0);

}