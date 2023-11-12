#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>



void number1() {
	int a[1000], n;
	float sr = 0, sum = 0;
	//берём файл
	FILE* fin = fopen("D:\\txtfor19lab\\in1.txt", "rt");
	if (fin == NULL) {
		printf("\nфайл не найден\n"); return;
	}
	fscanf(fin, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &a[i]); sum += a[i];
	}
	fclose(fin);
	//закрыли 
	sr = sum / n;
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > sr) {
			k++;
		}
	}
	//посчитали, save
	FILE* fout = fopen("D:\\txtfor19lab\\out1.txt", "wt");
	if (fout == NULL) {
		printf("\nфайл не найден\n"); return;
	}
	fprintf(fout, "%d \n", k);
	for (int i = 0; i < n; i++) {
		if (a[i] > sr) {
			fprintf(fout, "%d ", a[i]);
		}
	}
	fclose(fout);
	printf("\nготово\n");
}
void number2() {
	int *pa, n;
	float sr = 0, sum = 0;
	//берём файл
	FILE* fin = fopen("D:\\txtfor19lab\\in1.txt", "rt");
	if (fin == NULL) {
		printf("\nфайл не найден\n"); return;
	}
	fscanf(fin, "%d", &n);
	pa = (int*)malloc(sizeof(int) * n);//какой-то обряд странный
	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &pa[i]); sum += pa[i];
	}
	fclose(fin);
	sr = sum / n;
	int k = 0;
	for (int i = 0; i < n; i++) { if (pa[i] > sr) k++; }
	FILE* fout = fopen("D:\\txtfor19lab\\out1.txt", "wt");
	if (fout == NULL) {
		printf("\nфайл не найден\n"); return;
	}
	fprintf(fout, "%d \n", k);
	for (int i = 0; i < n; i++) {
		if (pa[i] > sr) {
			fprintf(fout, "%d ", pa[i]);
		}
	}
	fclose(fout);
	free(pa);
	printf("\nготово\n");
}
void number3() {
	int *massiv, n;
	float sr = 0, sum = 0;
	FILE* fin = fopen("D:\\txtfor19lab\\in3.txt", "rt");
	if (fin == NULL) {
		printf("\nфайл не найден\n"); return;
	}
	fscanf(fin, "%d", &n);
	massiv = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &massiv[i]); sum += massiv[i];
	}
	fclose(fin);
	sr = sum / n;
	int k = 0;
	for (int i = 0; i < n; i++) { if (massiv[i] > 0 && massiv[i] < sr) k++; }
	FILE* fout = fopen("D:\\txtfor19lab\\out3.txt", "wt");
	if (fout == NULL) {
		printf("\nфайл не найден\n"); return;
	}
	fprintf(fout, "%d \n", k);
	for (int i = 0; i < n; i++) {
		if (massiv[i] > 0 && massiv[i] < sr) {
			fprintf(fout, "%d ", massiv[i]);
		}
	}
	fclose(fout);
	free(massiv);
	printf("\nготово\n");
}
void number4() {
	int *massiv2, n;
	float diff = 0; diff += 2. / 3.; //printf("%.2f", diff);
	FILE* fin = fopen("D:\\txtfor19lab\\in4.txt", "rt");
	if (fin == NULL) {
		printf("\nфайл не найден\n"); return;
	}
	fscanf(fin, "%d", &n);
	massiv2 = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &massiv2[i]);
	}
	fclose(fin);
	//sr = sum / n;
	int k = 0;
	float max = massiv2[0];
	for (int i = 1; i < n; i++) { 
		if (max < massiv2[i]) max = massiv2[i];
	}
	for (int i = 0; i < n; i++) {
		if (massiv2[i] >= diff * max) {
			k++;
		}
	}
	FILE* fout = fopen("D:\\txtfor19lab\\out4.txt", "wt");
	if (fout == NULL) {
		printf("\nфайл не найден\n"); return;
	}
	fprintf(fout, "%d \n", k);
	for (int i = 0; i < n; i++) {
		if (massiv2[i] >= diff * max) {
			fprintf(fout, "%d ", massiv2[i]);
		}
	}
	fclose(fout);
	free(massiv2);
	printf("\nготово\n");
	
}
void main() {
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	int number;
	do {
		printf("\n");
		printf("1 - оценки выше среднего \n");
		printf("2 - номер 1, но через динамический массив\n");
		printf("3 - температура выше нуля, но ниже среднего\n");
		printf("4 - о доходах\n");
		printf("\nномер - ");
		scanf_s("%d", &number);
		switch (number)
		{
		case 1:
			number1();
			break;
		case 2:
			number2();
			break;
		case 3:
			number3();
			break;
		case 4:
			number4();
			break;
		default:
			break;
		}
	} while (1);
}