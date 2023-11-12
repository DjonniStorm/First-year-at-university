// Lab_9.cpp : Определяет точку входа для приложения.
//
#include "stdafx.h"
#include "Lab_9.h"

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
    LoadStringW(hInstance, IDC_LAB9, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB9));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB9));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB9);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}
void DrawVW(HDC hdc, int x, int y) {
	HBRUSH backBrush, frontBrush;
	backBrush = CreateSolidBrush(RGB(82, 94, 255));
	HPEN pen1, pen2;
	pen1 = CreatePen(PS_SOLID, 2, RGB(82, 94, 255));
	SelectObject(hdc, backBrush);
	SelectObject(hdc, pen1);
	Ellipse(hdc, 50 + x, 200 + y, 150 + x, 100 + y);
	frontBrush = CreateSolidBrush(RGB(223, 223, 223));
	pen2 = CreatePen(PS_SOLID, 2, RGB(223, 223, 223));
	SelectObject(hdc, frontBrush);
	SelectObject(hdc, pen2);
	Ellipse(hdc, 56 + x, 194 + y, 144 + x, 106 + y);
	SelectObject(hdc, backBrush);
	SelectObject(hdc, pen1);
	Ellipse(hdc, 64  + x, 186 + y, 136 + x, 114 + y);
	SelectObject(hdc, frontBrush);
	SelectObject(hdc, pen2);
	POINT points1[8] = { 75 + x, 120 + y,
	90 + x, 145 + y,
	110 + x, 145 + y,
	125 + x, 120 + y,
	112 + x, 115 + y, //
	100 + x, 138 + y,
	88 + x, 115 + y,
	75 + x, 120 + y
	};
	Polygon(hdc, points1, 8);
	POINT points2[12] = { 62 + x, 128 + y,
		82 + x, 160 + y,
		90 + x, 150 + y,
		110 + x, 150 + y,
		118 + x, 160 + y,
		138 + x, 128 + y,
		140 + x, 140 + y,//
		116 + x, 183 + y,//
		100 + x, 155 + y,
		86 + x, 183 + y,
		60 + x, 140 + y,
		62 + x, 128 + y
	};
	Polygon(hdc, points2, 12);
}
void DrawVW1(HDC hdc) { //крестик
	DrawVW(hdc, 10, 10);
	DrawVW(hdc, 10, 310);
	DrawVW(hdc, 310, 10);
	DrawVW(hdc, 310, 310);
	DrawVW(hdc, 160, 160);
}
void DrawVW2(HDC hdc) { //в ряд
	int x10 = 0, y10 = 10, i = 0;
	do {
		DrawVW(hdc, x10, y10);
		i++;
		x10 += 103;

	} while (i < 5);
}
void DrawVW3(HDC hdc) {
	DrawVW(hdc, 0, -100 );
	DrawVW(hdc, 0, 103 - 100);
	DrawVW(hdc, 0, 206 - 100);
	DrawVW(hdc, 0, 309 - 100);
	DrawVW(hdc, 0, 412 - 100);
}
void DrawVW4(HDC hdc) {
	DrawVW(hdc, 0, 0);
	DrawVW(hdc, 103, 103);
	DrawVW(hdc, 206, 206);
	DrawVW(hdc, 309, 309);
	DrawVW(hdc, 412, 412);
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
			//DrawWW(hdc);
			DrawVW1(hdc);
			DrawVW2(hdc);
			DrawVW3(hdc);
			DrawVW4(hdc);
			

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
