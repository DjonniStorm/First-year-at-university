// Lab13.cpp : Определяет точку входа для приложения.
//

#include "stdafx.h"
#include "Lab13.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB13, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB13));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB13));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB13);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}
void DrawTriangle(HDC hdc, int cx, int cy, COLORREF color) {
	HPEN pen1;
	pen1 = CreatePen(PS_SOLID, 2, color);
	SelectObject(hdc, pen1);
	POINT triangle[4] = { {10 + cx, 0 + cy}, {20 + cx, 20 + cy},
	{0 + cx, 20 + cy}, {10 + cx, 0 + cy}
	};
	Polyline(hdc, triangle, 4);
	DeleteObject(pen1);
}
void Number3(HDC hdc) {//сверзу вниз
	typedef int chislo;
	chislo x = 20, y = 20, i = 0;
	do {
		DrawTriangle(hdc, x, y, RGB(0, 255, 0));
		y += 40;
		i++;
	} while (i < 6);
}
void Number4(HDC hdc) {//в ряд
	typedef int chislo;
	chislo x = 20, y = 20, i = 0;
	do {
		DrawTriangle(hdc, x, y, RGB(255, 0, 0));
		x += 40;
		i++;
	} while (i < 6);
}
void Number5(HDC hdc) {//много рядов
	typedef int chislo2;
	chislo2 x, y = 20, i = 0, j = 0;
	do {
		x = 20;
		j = 0;
		do {
			DrawTriangle(hdc, x, y, RGB(255, 255, 0));
			x += 40;
			j++;
		} while (j < 8);
		y += 40;
		i++;
	} while (i < 6);
}
void Number6(HDC hdc) {//меняет цвет (немножко)
	typedef int chislo3; typedef  unsigned char chislo4;
	chislo3 x = 100, y= 20, i = 0;
	chislo4 g = 0;
	do {
		DrawTriangle(hdc, x, y, RGB(0, g, 0));
		y += 40;
		g += 40;
		i++;
	} while (i < 6);
}
void Number7(HDC hdc) {//в ряд и цвет
	typedef int chislo5; typedef  unsigned char chislo6;
	chislo5 x = 10, y = 20, i = 0;
	chislo6 g = 0;
	do {
		DrawTriangle(hdc, x, y, RGB(g, 0, 0));
		x += 40; g += 30; i++;
	} while (i < 8);
}
void Number8(HDC hdc) {
	typedef int chislo7; typedef  unsigned char chislo8;
	chislo7 x, y = 20, i = 0, j = 0;
	chislo8 g = 0, r;
	do {
		x = 20;
		j = 0;
		r = 0;
		do {
			DrawTriangle(hdc, x, y, RGB(r, g, 0));
			x += 40;
			r += 36;
			j++;
		} while (j < 8);
		y += 40;
		g += 51;
		i++;
	} while (i < 6);
}



//из лр12:
void clip(HDC hdc, int cx, int cy, COLORREF color) { //скрепка
	HPEN hPen5;
	hPen5 = CreatePen(PS_SOLID, 2, color);
	SelectObject(hdc, hPen5);
	POINT number7[13] = { {10 + cx, 0 + cy}, {0 + cx, 10 + cy},
	{0 + cx, 20 + cy}, {10 + cx, 20 + cy}, {20 + cx, 10 + cy},
	{20 + cx, 0 + cy}, {15 + cx, 0 + cy}, {5 + cx, 10 + cy},
	{5 + cx, 15 + cy}, {10 + cx, 15 + cy}, {15 + cx, 10 + cy},
	{15 + cx, 5 + cy}, {10 + cx, 10 + cy}
	};
	Polyline(hdc, number7, 13);
	DeleteObject(hPen5);
}
void clips(HDC hdc) {
	typedef int chisla9; typedef unsigned char chisla10;
	chisla9 x = 20, y = 20, i = 10, k = 4;
	chisla10 g = 0, r = 0;
	do {
		x = 20;
		i = 10;
		r = 0;
		do {
			clip(hdc, x, y, RGB(r, g, 0));
			i--; r += 20;
			x += 40;
		} while (i > 0);
		k--;
		y += 40;
		g += 20;
	} while (k > 0);
}
void Flag(HDC hdc, int cx, int cy, COLORREF color) {//флажок
	HPEN hPen3;
	hPen3 = CreatePen(PS_SOLID, 2, color);
	SelectObject(hdc, hPen3);
	POINT number5[6] = { {0 + cx, 20 + cy}, {0 + cx, 0 + cy}, {20 + cx, 0 + cy},
	{10 + cx, 5 + cy}, {20 + cx, 10 + cy}, {0 + cx, 10 + cy}
	};
	Polyline(hdc, number5, 6);
	DeleteObject(hPen3);
}
void Flags(HDC hdc) {
	typedef int chisla11; typedef unsigned char chisla12;
	chisla11 x = 20, y = 20, i = 10, k = 4;
	chisla12 r = 0, g = 0, b = 0;
	do {
		x = 20; i = 10;
		do {
			Flag(hdc, x, y, RGB(r, g, b));
			i--;
			x += 40;
			g += 20; b += 20;
		} while (i > 0);
		k--;
		y += 40;
		r += 40;
	} while (k > 0);
}
void krown(HDC hdc, int cx, int cy, COLORREF color) {//корона
	HPEN hPen4;
	hPen4 = CreatePen(PS_SOLID, 2, color);
	SelectObject(hdc, hPen4);
	POINT number6[6] = { {0 + cx, 0 + cy}, {10 + cx, 10 + cy},
	{20 + cx, 0 + cy}, {20 + cx, 20 + cy}, {0 + cx, 20 + cy},
	{0 + cx, 0 + cy}
	};
	Polyline(hdc, number6, 6);
	DeleteObject(hPen4);
}
void krowns(HDC hdc) {
	typedef int chisla13; typedef unsigned char chisla14;
	chisla13 x = 20, y = 20, i = 10;
	chisla14 d = 255/*, e = 0*/;
	do {
		krown(hdc, x, y, RGB(d, 255-d, 0));
		i--;
		x += 40;
		d -= 20;
		//e += 20;
	} while (i > 0);

}



//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
			//Number3(hdc); //зелёные треугольники вертикально
			//Number4(hdc); //красные треугольники горизонтально
			//Number5(hdc); //жёлтые треугольники
			//Number6(hdc); //треугольники вертикально с градиентом
			//Number7(hdc); //треугольники в ряд с градиентом
			//Number8(hdc); //красиво
			//clips(hdc); //скрепка меняет цвет
			//Flags(hdc); //флаги меняют цвет
			krowns(hdc); //короны меняют цвет
			EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
