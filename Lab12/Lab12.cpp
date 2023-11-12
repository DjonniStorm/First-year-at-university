// Lab12.cpp : Определяет точку входа для приложения.
//

#include "stdafx.h"
#include "Lab12.h"

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
    LoadStringW(hInstance, IDC_LAB12, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB12));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB12));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB12);
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
void Number3(HDC hdc, int cx, int cy) {//ромб
	HPEN hPen;
	hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, hPen);
	POINT p[5] = {
		cx,       cy - 20,
		cx + 20,  cy,
		cx,       cy + 20,
		cx - 20,  cy,
		cx,       cy - 20
	};
	Polyline(hdc, p, 5);
	DeleteObject(hPen);
}
void Number4(HDC hdc, int cx, int cy) { //стрелка
	HPEN hPen2;
	hPen2 = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, hPen2);
	POINT number4[5] = { {0 + cx, 0 + cy}, {10 + cx, 10 + cy}, {20 + cx, 0 + cy},
	{10 + cx, 20 + cy}, {0 + cx, 0 + cy} };
	Polyline(hdc, number4, 5);
	DeleteObject(hPen2);
}
void Numbers4(HDC hdc) {
	typedef int chisla;
	chisla x = 20, y = 20, i = 10;
	do {
		Number4(hdc, x, y);
		i--;
		x += 40;
	} while (i > 0);
}

void Number5(HDC hdc, int cx, int cy) {//флажок
	HPEN hPen3;
	hPen3 = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, hPen3);
	POINT number5[6] = { {0 + cx, 20 + cy}, {0 + cx, 0 + cy}, {20 + cx, 0 + cy},
	{10 + cx, 5 + cy}, {20 + cx, 10 + cy}, {0 + cx, 10 + cy}
	};
	Polyline(hdc, number5, 6);
	DeleteObject(hPen3);
}
void Numbers5(HDC hdc) {
	typedef int chisla2;
	chisla2 x = 20, y = 20, i = 10, k = 4, zero1, zero2;
	zero1 = x; zero2 = i;
	do {
		x = zero1;
		i = zero2;
		do {
			Number5(hdc, x, y);
			i--;
			x += 40;
		} while (i > 0);
		k--;
		y += 40;
	} while (k > 0);
}

void Number6(HDC hdc, int cx, int cy) {//корона
	HPEN hPen4;
	hPen4 = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	SelectObject(hdc, hPen4);
	POINT number6[6] = { {0 + cx, 0 + cy}, {10 + cx, 10 + cy},
	{20 + cx, 0 + cy}, {20 + cx, 20 + cy}, {0 + cx, 20 + cy},
	{0 + cx, 0 + cy}
	};
	Polyline(hdc, number6, 6);
	DeleteObject(hPen4);
}
void Numbers6(HDC hdc) {
	typedef int chisla3;
	chisla3 x = 20, y = 20, i = 10;
	do {
		Number6(hdc, x, y);
		i--;
		x += 40;
	} while (i > 0);

}
void Number7(HDC hdc, int cx, int cy) { //скрепка
	HPEN hPen5;
	hPen5 = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
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
void Numbers7(HDC hdc) {
	typedef int chisla4;
	chisla4 x = 20, y = 20, i = 10, k = 4, zero1, zero2;
	zero1 = x; zero2 = i;
	do {
		x = zero1;
		i = zero2;
		do {
			Number7(hdc, x, y);
			i--;
			x += 40;
		} while (i > 0);
		k--;
		y += 40;
	} while (k > 0);
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
			
			//Number3(hdc, 50, 50);
			//Numbers4(hdc); //стрелочки
			//Numbers5(hdc); //флажки
			//Numbers6(hdc); //короны
			//Numbers7(hdc); //скрепки

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
