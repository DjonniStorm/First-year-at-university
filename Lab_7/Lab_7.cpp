// Lab_7.cpp : Определяет точку входа для приложения.
//

#include "stdafx.h"
#include "Lab_7.h"

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
    LoadStringW(hInstance, IDC_LAB7, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB7));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB7));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB7);
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
			//Домик
			HPEN hPen = CreatePen(PS_SOLID, 2, RGB(224, 162, 36));
			SelectObject(hdc, hPen);
			MoveToEx(hdc, 150, 350, NULL);
			LineTo(hdc, 275, 250);
			LineTo(hdc, 400, 350);
			LineTo(hdc, 338, 300);
			hPen = CreatePen(PS_SOLID, 2, RGB(33, 31, 28)); //дымовая труба
			SelectObject(hdc, hPen);
			LineTo(hdc, 338, 285);
			LineTo(hdc, 350, 285);
			LineTo(hdc, 350, 310);
			MoveToEx(hdc, 400, 350, NULL);
			hPen = CreatePen(PS_SOLID, 2, RGB(224, 162, 36));
			SelectObject(hdc, hPen);
			LineTo(hdc, 150, 350);
			LineTo(hdc, 150, 550);
			LineTo(hdc, 400, 550);
			LineTo(hdc, 400, 350);
			MoveToEx(hdc, 225, 400, NULL);
			LineTo(hdc, 325, 400);
			LineTo(hdc, 325, 475);
			LineTo(hdc, 225, 475);
			LineTo(hdc, 225, 400);
			MoveToEx(hdc, 275, 400, NULL);
			LineTo(hdc, 275, 475);
			MoveToEx(hdc, 325, 425, NULL);
			LineTo(hdc, 275, 425);
			//Ёлочка справа
			hPen = CreatePen(PS_SOLID, 2, RGB(38, 148, 34));
			SelectObject(hdc, hPen);
			MoveToEx(hdc, 450, 550, NULL);
			LineTo(hdc, 600, 550);
			LineTo(hdc, 525, 450);
			LineTo(hdc, 575, 450);
			LineTo(hdc, 525, 400);
			LineTo(hdc, 550, 400);
			LineTo(hdc, 525, 375);
			LineTo(hdc, 500, 400);
			LineTo(hdc, 525, 400);
			LineTo(hdc, 475, 450);
			LineTo(hdc, 525, 450);
			LineTo(hdc, 450, 550);
			//дз
			//ноемр 1 (красный куст)
			HPEN hPen1 = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
			SelectObject(hdc, hPen1);
			int x1 = 400, y1 = 150, x2 = 500, y2 = 250;
			do {
				MoveToEx(hdc, x1, y1, NULL);
				LineTo(hdc, x2, y2);
				x1 += 2;
			} while (x1 <= 600);
			DeleteObject(hPen);
			//номер 2 (зелёный куст)
			
			HPEN hPen2 = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
			SelectObject(hdc, hPen2);
			int x3 = 0, y3 = 250, x4 = 100, y4 = 250, x5 = 200, y5 = 250;
			do {
				MoveToEx(hdc, x3, y3, NULL);
				LineTo(hdc, x4, y4);
				x3 += 10;
				y3 -= 10;
			} while (x3 <= x4);
			do {
				MoveToEx(hdc, x5, y5, NULL);
				LineTo(hdc, x4, y4);
				x5 -= 10;
				y5 -= 10;
			} while (x5 >= x4);
			//задача 4
			//забор
			HPEN hPen4 = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
			SelectObject(hdc, hPen4);
			int x10 = 150, y10 = 0/*, x11 = 150*/, y11= 100;
			do {
				MoveToEx(hdc, x10, y10, NULL);
				LineTo(hdc, x10, y11);
				x10 += 25;
			} while (x10 <= 500);
			//задача 5
			int x20 = 0, y20 = 600, x21 = 10, y21 = 600,
				x22 = 10, y22 = 605, x23 = 0, y23 = 605,
				x24 = 0, y24 = 600;
			
			do {
				do {
					MoveToEx(hdc, x20, y20, NULL);
					LineTo(hdc, x21, y21);
					LineTo(hdc, x22, y22);
					LineTo(hdc, x23, y23);
					LineTo(hdc, x24, y24);
					x20 += 10; x21 += 10; x22 += 10; x23 += 10; x24 += 10;
				} while (x20 <=1000);
				x20 = 0; x21 = 10; x22 = 10; x23 = 0; x24 = 0;
				y20 += 5; y21 += 5; y22 += 5; y23 += 5; y24 += 5;
			} while (y22 <= 800);

			//задача какая-то
			HPEN hPen5 = CreatePen(PS_SOLID, 2, RGB(153, 76, 0));
			SelectObject(hdc, hPen5);
			int x30 = 800, y30 = 400, y31 = 500;
			do {//та которая нижняя
				MoveToEx(hdc, x30, y30, NULL);
				LineTo(hdc, x30, y31);
				x30 += 20; y30 += 20; y31 -= 20;
			} while (x30 <= 1000);
			int x40 = 600, y40 = 200, y41 = 300;
			do {//та которая верхняя
				MoveToEx(hdc, x40, y40, NULL);
				LineTo(hdc, x40, y41);
				x40 += 10; y40 -= 20; y41 += 20;

			} while (x40 <= 680);
			int x50 = 1400, y50 = 200, x51 = 1400, y51 = 600;
			do {//самая правая 
				MoveToEx(hdc, x50, y50, NULL);
				LineTo(hdc, x51, y51);
				x50 -= 20; y50 += 10; x51 += 20; y51 -= 10;
			} while (x51 <= 1600);
			int x60 = 700, y60 = 300, x61 = 1200, y61 = 50;
			do {//средняя верхняя
				MoveToEx(hdc, x60, y60, NULL);
				LineTo(hdc, x61, y61);
				x60 += 40; y61 += 20;
			} while (x60 <= 1100);


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
