#include <stdio.h>
#include <Windows.h>

#define SuperMassiv 10
int a[SuperMassiv];

void number1_1() {
	for (int i = 0; i < SuperMassiv; i++) { a[i] = 0; }
	for (int i = 0; i < SuperMassiv; i++) { scanf_s("%d", &a[i]); }
}
void number1_2() {
	for (int i = 0; i < SuperMassiv; i++) { if (a[i] % 2 != 0)a[i] *= 10; }
}
void number1_3() {
	int min; min = a[0];
	for (int i = 1; i < SuperMassiv; i++) { if (a[i] < min) min = a[i]; }
	printf("min = %d", min);
}
void number2() {
	int k = 0;
	for (int i = 0; i < SuperMassiv; i++) { if (a[i] > 10)k++; }
	printf("больше 10 = %d", k);
}
void number3() {
	for (int i = 0; i < SuperMassiv; i++) {
		if (a[9 - i] % 2 == 0) {
			a[9 - i] *= 2;
			break;
		}
	}
}
void zero() {
	for (int i = 0; i < SuperMassiv; i++) { printf("%d  ", a[i]); }
}
int indexofmin(){
	int min, index = 0; min = a[0];
	for (int i = 1; i < SuperMassiv; i++) { if (a[i] < min) index = i; }
	return index;
}
void number4() {
	int index = indexofmin(), k = 0;
	for (int i = 0; i < SuperMassiv; i++) {
		if (a[i] % 2 == 0 && i < index) {
			k += 1;
		}
	}
	printf("%d", k);
}
void number5() {
	int index = indexofmin();
	for (int i = 0; i < SuperMassiv; i++) {
		if (a[i] % 2 != 0 && i > index) {
			a[i] *= 10;
		}
	}
}
int indexofmax() {
	int max_index = 0, max; max = a[0];
	for (int i = 1; i < SuperMassiv; i++) {
		if (max < a[i]) {
			max = a[i]; max_index = i;
		}
	}
	return max_index;
}
void number6() {
	int index = indexofmin(), max_index = indexofmax();
	int chislo, max, min;
	for (int i = 0; i < SuperMassiv; i++) {
		if (a[i] == a[index]) min = a[i];
		if (a[i] == a[max_index]) max = a[i];
	}
	for (int i = 0; i < SuperMassiv; i++) {
		if (a[i] == a[max_index]) a[i] = min;
		if (a[i] == a[index]) a[i] = max;
	}
}
void number7() {
	for (int i = 0; i < SuperMassiv; i++) { if (a[i] % 2 == 0) a[i] *= -1; }
}
void number8() {
	for (int i = 0; i < SuperMassiv; i++) { if (a[i] < 4) a[i] = 4; }
}
//void number9() {
//	int min = indexofmin(), max = indexofmax();
//	for (int i = 0; i < SuperMassiv; i++) {
//		if (min < max) {
//			while (i > min && i < max) {
//				a[i] *= 10;
//			}
//		}
//		if (max > min) {
//			while (i > max && i < min) {
//				a[i] *= 10;
//			}
//		}
//	}
//}
void main() {
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	int n;
	printf("Введите массив\n");
	for (int i = 0; i < SuperMassiv; i++) { scanf_s("%d", &a[i]); }
	do {
		printf("\n");
		printf(" 1 - обнулить и ввести\n");
		printf(" 2 - нечётные * 10\n");
		printf(" 3 - min\n");
		printf(" 4 - подсчитать больше 10\n");
		printf(" 5 - увеличить крайнюю справа чётную\n");
		printf(" 6 - вывести\n");
		printf(" 7 - номер 4, где кол-во чётных левее минимального\n");
		printf(" 8 - увеличить в 10 раз нечётные правее минимального\n");
		printf(" 9 - поменять max и min\n");
		printf("10 - чётные становятся отрицательными\n");
		printf("11 - меньше 4 становятся 4\n");
		printf("\n");
		scanf_s("%d", &n);
		switch (n)
		{
		case 1:
			number1_1();
			break;
		case 2:
			number1_2();
			break;
		case 3:
			number1_3();
			break;
		case 4:
			number2();
			break;
		case 5:
			number3();
			break;
		case 6:
			zero();
			break;
		case 7:
			number4();
			break;
		case 8:
			number5();
			break;
		case 9:
			number6();
			break;
		case 10:
			number7();
			break;
		case 11:
			number8();
			break;
		default:
			return;
		}
	} while (1);
}