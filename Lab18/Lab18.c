#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>



void number1() {
	int a, b, c;
	int p;
	printf("����� 1\n");
	scanf_s("%d%d%d", &a, &b, &c);
	printf("\n�� �����: %d, %d, %d\n", a, b, c);
	p = a * b * c;
	printf("\np = %d\n", p);
}
void number2() {
	int a, b, c;
	int p; int k = 0;
	printf("����� 2\n");
	FILE* fin = fopen("D:\\txtfor18lab\\in2.txt", "rt");
	if (fin == NULL) {
		printf("������� ���� �� ������");
		return;
	}
	fscanf(fin, "%d%d%d", &a, &b, &c);
	fclose(fin);
	printf("�� �����: %d, %d, %d", a, b, c);
	p = a * b * c;
	printf("\np = %d\n", p);
	FILE* fout;
	fout = fopen("D:\\txtfor18lab\\out2.txt", "wt");
	if (fout == NULL) {
		printf("�������� ���� �� ��������\n");
		return;
	}
	fprintf(fout, "p = %d", p);
	fclose(fout);
}
void number3() {
	int a1, a2, a3, a4, a5;
	printf("\n����� 3\n");
	printf("������� 5 ����� �����\n");
	scanf_s("%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5);
	printf("\n�� �����: %d %d %d %d %d", a1, a2, a3, a4, a5);
	printf("\np = %d", a1 * a2 * a3 * a4 * a5);

}
void number4() {
	int a1, a2, a3, a4, a5, p;
	FILE* fin = fopen("D:\\txtfor18lab\\in4.txt", "rt");
	if (fin == NULL) {
		printf("\n���� �� ������\n");
		return;
	}
	fscanf(fin, "%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5);
	if (a1 == -858993460) { printf("\n�� �� ����� ��������\n"); return; }
	fclose(fin);
	printf("�� �����: %d  %d  %d  %d  %d", a1, a2, a3, a4, a5);
	p = a1 + a2 + a3 + a4 + a5;
	printf("\np = %d", p);
	FILE* fout = fopen("D:\\txtfor18lab\\out4.txt", "wt");
	if (fout == NULL) {
		printf("\n�������� ���� �� ��������\n"); return;
	}
	fprintf(fout, "p = %d", p);
	fclose(fout);
}
void number5() {
	printf("����� 5");
#define N 20
	int a[N], n;
	float sr = 0;
	FILE* fin = fopen("D:\\txtfor18lab\\in5.txt", "rt");
	if (fin == NULL) {
		printf("\n������� ���� �� ������\n"); return;
	}
	fscanf(fin, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &a[i]); sr += a[i];
	}
	fclose(fin);
	sr /= n;
	printf("\n������� �������������� = %f\n", sr);
	for (int i = 0; i < n; i++) { if (a[i] > sr) a[i] *= 10; }
	FILE* fout = fopen("D:\\txtfor18lab\\out5.txt", "wt");
	if (fout == NULL) {
		printf("\n�������� ���� �� ��������\n"); return;
	}
	for (int i = 0; i < n; i++) {
		fprintf(fout, "%d ", a[i]);
	}
	fclose(fout);


}
void number6() {
	int a[20], n;
	float sr = 0;
	FILE* fin = fopen("D:\\txtfor18lab\\in6.txt", "rt");
	if (fin == NULL) {
		printf("\n������� ���� �� ������\n");
		return;
	}
	fscanf(fin, "%d", &n);
	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &a[i]); sr += a[i];
	}
	fclose(fin);
	printf("\n�� �����: ");
	for (int i = 0; i < n; i++) { printf("%d ", a[i]); }
	sr /= n;
	for (int i = 0; i < n; i++) {
		if (a[i] < sr && a[i] % 2 == 0) {
			a[i] /= 2;
		}
	}
	FILE* fout = fopen("D:\\txtfor18lab\\out6.txt", "wt");
	if (fout == NULL) {
		printf("\n�������� ���� �� ������\n");
		return;
	}
	for (int i = 0; i < n; i++){
		fprintf(fout, "%d ", a[i]);
	}
	fclose(fout);
}
void number7() {
	//printf("%d", 3 < 2 ? 1 : 0);
#define C 20
	int a[C], n;
	FILE* fin = fopen("D:\\txtfor18lab\\in'n'out.txt", "rt");
	if (fin == NULL) { printf("\n���� �� ������\n"); return; }
	fscanf(fin, "%d", &n); if (n > C || n <= 0) return;
	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &a[i]);
	}
	fclose(fin);
	int elementindex; int l = 0;
	printf("������� ������� ����� \n");
	scanf_s("%d", &elementindex);
	int b[20];
	for (int i = 0; i < n; i++) {
		if (i < elementindex - 1) {
			b[i] = a[i];
		}
		if (i == elementindex - 1) { continue; }
		if (i > elementindex - 1) {
			b[i - 1] = a[i];
		}
		l++;
	}
	n = l;
	for (int i = 0; i < n; i++) {
		a[i] = b[i];
	}
	FILE* fout = fopen("D:\\txtfor18lab\\in'n'out.txt", "wt"); //outfor7andmore
	if (fin == NULL) { printf("\n���� �� ������\n"); return; }
	fprintf(fout, "\n");
	for (int i = 0; i < n; i++) {
		fprintf(fout, "%d ", a[i]);
	}
	fclose(fout);
}
void number8() {
#define D 20
	int a[D], n;
	int element, elementindex;
	FILE* fin = fopen("D:\\txtfor18lab\\in'n'out.txt", "rt");
	if (fin == NULL) { printf("\n���� �� ������\n"); return; }
	fscanf(fin, "%d", &n); if (n > D || n <= 0) return;
	for (int i = 0; i < n; i++) {
		fscanf(fin, "%d", &a[i]);
	}
	fclose(fin);

	printf("�� ����� ����� ��������? ");
	scanf_s("%d", &elementindex);
	if (elementindex < 0 || elementindex > n + 1)return;
	printf("����� = ");
	scanf_s("%d", &element);
	int b[20];
	for (int i = 0; i < n; i++) {
		b[i] = a[i];
	}
	n++;
	for (int i = 0; i < n; i++) {
		if (i < elementindex - 1) {
			a[i] = b[i];
		}
		if (i == elementindex - 1) {
			a[i] = element;
		}
		if (i > elementindex - 1) {
			a[i] = b[i - 1];
		}
	}
	FILE* fout = fopen("D:\\txtfor18lab\\in'n'out.txt", "wt"); //outfor7andmore
	if (fin == NULL) { printf("\n���� �� ������\n"); return; }
	fprintf(fout, "\n");
	for (int i = 0; i < n; i++) {
		fprintf(fout, "%d ", a[i]);
	}
	fclose(fout);
}

void main()
{
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	

	int number;
	do {
		printf("\n1 - ��������� 3-�              \n");
		printf("2 - ������ �����, �� � ������ \n");
		printf("3 - ������������ 5            \n");
		printf("4 - ����� 5 ����� ����        \n");
		printf("5 - ������ �������� ��������������� ���������� �� 10\n");
		printf("6 - ������ � ������ ��. ������� �������\n");
		printf("________________________________________\n");
		printf("��� � ���. 17 ���� ����� \n");
		printf("7 - ������� ������� �������\n");
		printf("8 - �������� �������\n");
		printf("\n����� = ");
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
		case 5:
			number5();
			break;
		case 6:
			number6();
			break;
		case 7:
			number7();
			break;
		case 8:
			number8();
			break;
		default:
			break;
		}

	} while (1);
}