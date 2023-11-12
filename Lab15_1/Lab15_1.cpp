// Lab15_1.cpp : Определяет точку входа для приложения.
//

#include "stdafx.h"
#include "Lab15_1.h"
#include "Images2.h"

#define MAX_LOADSTRING 100
#define name1 1
#define name2 2
#define name3 3
int k = 1;
int X = -100, Y = -100, W = 80, H = 80;
int X2 = 0, Y2 = 0;


int time = 0;
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
    LoadStringW(hInstance, IDC_LAB151, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB151));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB151));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB151);
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
void DrawNumbers(HDC hdc) {
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(1, 1, 1));
	SelectObject(hdc, pen);
	int x, y = 0, k, i = 1;
	do {
		x = 0; k = i;
		do {
			MoveToEx(hdc, 10 + x, 10 + y, NULL);
			LineTo(hdc, 10 + x, 2 + y);
			k--; x += 5;
		} while (k > 0);
		y += 250;
		i++; 
	} while (i < 4);
	int x2, y2 = 0, k2, i2 = 1;
	do {
		x2 = 720; k2 = i2 + 3;
		do {
			MoveToEx(hdc, 10 + x2, 10 + y2, NULL);
			LineTo(hdc, 10 + x2, 2 + y2);
			k2--; x2 += 5;
		} while (k2 > 0);
		y2 += 250;
		i2++;
	} while (i2 < 4);
	DeleteObject(pen);
}
void Draw(HDC hdc, int cx, int cy) {

	HPEN pen2, pen3; HBRUSH brush;
	pen2 = CreatePen(PS_SOLID, 2, RGB(100, 100, 100));
	pen3 = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	brush = CreateSolidBrush(RGB(100, 100, 100));
	SelectObject(hdc, pen2); SelectObject(hdc, brush);
	Ellipse(hdc, 0 + cx, 0 + cy, 80 + cx, 80 + cy);
	SelectObject(hdc, pen3);
	Ellipse(hdc, 60 + cx, 20 + cy, 80 + cx, 40 + cy);
	DeleteObject(pen2); DeleteObject(pen3); DeleteObject(brush);
}
void Fire(HDC hdc, int cx, int cy) {
	HPEN pen4 = CreatePen(PS_SOLID, 30, RGB(255, 0, 0));
	SelectObject(hdc, pen4);
	MoveToEx(hdc, X + W + cx, Y + H-54 + cy, NULL); 
	LineTo(hdc, X2 + cx, Y2 + cy);
	DeleteObject(pen4);
}
void onFire(HDC hdc) {
	Fire(hdc, 0, 0);
}
struct Image {
	int x;
	int y;
	int vx;
	int vy;
};
struct Image im1 = { 0, 50, 10, 0 }; //квадрат
//nomer2
typedef struct Image IMAGE;
IMAGE im2 = { 700, 300, -20, 0 }; //треугольник
IMAGE im3 = { 50, 500, 0, 10};    //скрепка
IMAGE im4 = { 800, 300, 0, -10};  //флаг
IMAGE im5 = { 800, 600, 0, 0};    //корона

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
	case WM_KEYDOWN: {
		switch (wParam)
		{
		case VK_LEFT:
			X -= 10;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_RIGHT:
			X += 10;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_UP:
			Y -= 10;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_DOWN:
			Y += 10;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		}
	}
		break;
	case WM_LBUTTONDOWN:
	{
		WORD xPos, yPos;
		xPos = LOWORD(lParam); yPos = HIWORD(lParam);
		k = 1; X2 = xPos; Y2 = yPos;
		InvalidateRect(hWnd, NULL, TRUE);
	}
	break;
	case WM_CREATE:
		SetTimer(hWnd, name1, 1, NULL);
		SetTimer(hWnd, name2, 10000, NULL);
		SetTimer(hWnd, name3, 500, NULL);
		break;
	case WM_TIMER: {
		if (wParam == name1) {
			im1.x += im1.vx;
			im3.y += im3.vy;
			InvalidateRect(hWnd, NULL, TRUE);
		}
		if (wParam == name2) {
			im2.x += im2.vx;
			
			InvalidateRect(hWnd, NULL, TRUE);
		}
		if (wParam == name3) {
			im4.y += im4.vy;
			int dx5 = rand() % 50 + 1000;
			int dy5 = rand() % 50 + 600;
			im5.x = dx5; im5.y = dy5;
			k = 0;
			InvalidateRect(hWnd, NULL, TRUE);
		}
		if (im1.x >= 700) im1.x = 1;
		if (im2.x <= 0) im2.x = 700;
		if (im3.y >= 800) im3.y = 400;
		if (im4.y <= 0) im4.y = 300;

	}
		break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
			DrawNumbers(hdc);
			Images0(hdc, im1.x, im1.y, RGB(255, 255, 0)); //1
			
			DrawTriangle(hdc, im2.x, im2.y, RGB(255, 0, 255));//2
           
			clip(hdc, im3.x, im3.y, RGB(0, 255, 255)); //3

			Flag(hdc, im4.x, im4.y, RGB(25, 25, 25)); //4

			krown(hdc, im5.x, im5.y, RGB(25, 255, 0));//5
			
			Draw(hdc, X, Y);  
			if (k == 1) onFire(hdc);



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
