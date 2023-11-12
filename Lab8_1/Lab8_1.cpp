// Lab8_1.cpp : Определяет точку входа для приложения.
//

#include "stdafx.h"
#include "Lab8_1.h"
#include <time.h>
#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна
int BusWheelX = 240, BusWheelY = 1;
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
    LoadStringW(hInstance, IDC_LAB81, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB81));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB81));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB81);
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
void DrawHome(HDC hdc) {
	//Домик
	HPEN hPen;
	hPen = CreatePen(PS_SOLID, 2, RGB(224, 162, 36));
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
	DeleteObject(hPen);
}
void DrawCar(HDC hdc) {
	/*const POINT*/
	// TODO: Добавьте сюда любой код прорисовки, использующий HDC...
	//создание кисточек
	HPEN hPen1, hPen2, hPen3, hPen7;
	hPen1 = CreatePen(PS_SOLID, 2, RGB(0, 0, 204));
	hPen2 = CreatePen(PS_SOLID, 5, RGB(0, 153, 0));
	hPen3 = CreatePen(PS_SOLID, 5, RGB(204, 0, 204)); //фиолетовый
	hPen7 = CreatePen(PS_SOLID, 3, RGB(246, 1, 1));
	HBRUSH hBrush1, hBrush2, hBrush3;
	hBrush1 = CreateSolidBrush(RGB(246, 1, 1));
	hBrush2 = CreateHatchBrush(HS_FDIAGONAL, RGB(0, 153, 0));
	hBrush3 = CreateHatchBrush(HS_BDIAGONAL, RGB(204, 0, 204)); //фиолетовый
	
	//рисунок
	//машинка
			//MoveToEx(hdc, 300, 200, NULL);
	SelectObject(hdc, hBrush1);
	SelectObject(hdc, hPen7);
	RECT rect{ 50, 200, 300, 250 };
	FillRect(hdc, &rect, hBrush1);
	MoveToEx(hdc, 100, 200, NULL);
	SelectObject(hdc, hPen1);
	LineTo(hdc, 150, 150);
	LineTo(hdc, 250, 150);
	LineTo(hdc, 300, 200);
	//DeleteObject(hPen7);
	//колесо левое
	SelectObject(hdc, hBrush2);
	SelectObject(hdc, hPen2);
	//Arc(hdc, 75, 225, 125, 275, 100, 150, 100, 150);
	Ellipse(hdc, 75, 225, 125, 275);
	DeleteObject(hPen2);
	DeleteObject(hBrush2);
	//колесо правое
	SelectObject(hdc, hBrush3);
	SelectObject(hdc, hPen3);
	//Arc(hdc, 225, 225, 275, 275, 150, 250, 150, 250);
	//DeleteObject(hPen3);
	//DeleteObject(hBrush3);
	Ellipse(hdc, 225, 225, 275, 275);
	DeleteObject(hBrush1); DeleteObject(hBrush2); DeleteObject(hBrush3);
	DeleteObject(hPen1); DeleteObject(hPen2); DeleteObject(hPen3); DeleteObject(hPen7);
	/*DeleteObject(points);*/
}
void DrawTree(HDC hdc) {
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
	DeleteObject(hPen2);
}
void DrawSnegovik(HDC hdc) {
	POINT points[5] = { { 395, 145 }, {429, 145}, { 417, 110}, {405, 110}, {395, 145} },
		points1[4] = { {410, 165},{430, 169}, {410, 172}, {410, 165} };
	HBRUSH hBrush4, hBrush5, hBrush6;
	hBrush4 = CreateSolidBrush(RGB(223, 211, 211));
	hBrush5 = CreateSolidBrush(RGB(125, 113, 108));
	hBrush6 = CreateSolidBrush(RGB(225, 128, 0));
	HPEN hPen4, hPen5, hPen6, hPen8;
	hPen4 = CreatePen(PS_SOLID, 1, RGB(166, 164, 164)); //для тела снеговика
	hPen5 = CreatePen(PS_SOLID, 3, RGB(239, 89, 35));
	hPen6 = CreatePen(PS_SOLID, 3, RGB(125, 113, 108));
	//hPen7 = CreatePen(PS_SOLID, 3, RGB(246, 1, 1));
	hPen8 = CreatePen(PS_SOLID, 2, RGB(1, 1, 1)); //везде, где чёрный
	SelectObject(hdc, hBrush4);
	SelectObject(hdc, hPen4);
	Ellipse(hdc, 375, 300, 450, 225);
	Ellipse(hdc, 380, 240, 445, 175);
	Ellipse(hdc, 385, 190, 440, 138);
	//DeleteObject(hPen4);
	DeleteObject(hBrush4);
	//пуговицы
	SelectObject(hdc, hPen5);
	Ellipse(hdc, 408, 260, 420, 250);
	//Arc(hdc, 408, 260, 420, 250, 400, 250, 400, 250);
	Arc(hdc, 408, 235, 420, 225, 400, 250, 400, 250);
	Arc(hdc, 408, 210, 420, 200, 400, 250, 400, 250);
	DeleteObject(hPen5);
	//голова
	SelectObject(hdc, hPen6);
	SelectObject(hdc, hBrush5);
	Polygon(hdc, points, 5);
	DeleteObject(hPen6);
	DeleteObject(hBrush5);
	SelectObject(hdc, hPen8);
	Arc(hdc, 403, 160, 406, 159, 400, 160, 400, 160);
	Arc(hdc, 420, 160, 423, 159, 420, 160, 420, 160);
	SelectObject(hdc, hBrush6);
	Polygon(hdc, points1, 4);
	//руки
	MoveToEx(hdc, 380, 210, NULL);
	LineTo(hdc, 360, 240);
	MoveToEx(hdc, 444, 210, NULL);
	LineTo(hdc, 464, 240);
	DeleteObject(hBrush4); DeleteObject(hBrush5); DeleteObject(hBrush6); 
	DeleteObject(hPen4); DeleteObject(hPen5); DeleteObject(hPen6); DeleteObject(hPen8);
	DeleteObject(points); DeleteObject(points1);

}
void DrawBus(HDC hdc) {
	HBRUSH hBrush7, hBrush8, hBrush9, hBrush10;
	hBrush7 = CreateSolidBrush(RGB(233, 218, 9));
	hBrush8 = CreateSolidBrush(RGB(1, 1, 1));
	hBrush9 = CreateSolidBrush(RGB(51, 153, 225));
	hBrush10 = CreateHatchBrush(HS_DIAGCROSS, RGB(128, 128, 128));
	HPEN hPen9, hPen10;
	hPen9 = CreatePen(PS_SOLID, 20, RGB(1, 1, 1));
	hPen10 = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	SelectObject(hdc, hPen10);
	SelectObject(hdc, hBrush7);
	RoundRect(hdc, 550, 250, 905, 95, 50, 50); //кузов
	SelectObject(hdc, hBrush8);
	RoundRect(hdc, 560, 170, 770, 110, 8, 8);
	DeleteObject(hBrush8);
	SelectObject(hdc, hBrush9);
	RoundRect(hdc, 560, 170, 630, 110, 8, 8); //окно слева
	RoundRect(hdc, 640, 170, 710, 110, 8, 8); //центр
	RoundRect(hdc, 720, 170, 790, 110, 8, 8); //справа
	RoundRect(hdc, 800, 170, 904, 110, 10, 10);


	SelectObject(hdc, hBrush7);
	Rectangle(hdc, 780, 250, 820, 110); //дверь
	SelectObject(hdc, hBrush9);
	Rectangle(hdc, 782, 200, 818, 112);
	DeleteObject(hBrush7);
	Arc(hdc, 570, 300, 670, 200, 800, 130, 570, 235);
	SelectObject(hdc, hBrush10);
	SelectObject(hdc, hPen9);
	Ellipse(hdc, 595, 230, 645, 280); //колёса
	//Ellipse(hdc, 835, 230, 885, 280);
	DeleteObject(hBrush7); DeleteObject(hBrush8); DeleteObject(hBrush9); DeleteObject(hBrush10);
	DeleteObject(hPen9); DeleteObject(hPen10);
}
void DrawWheel(HDC hdc, int cx, int cy) {
	HBRUSH hBrush10;
	hBrush10 = CreateHatchBrush(HS_DIAGCROSS, RGB(128, 128, 128));
	HPEN hPen9;
	hPen9 = CreatePen(PS_SOLID, 20, RGB(1, 1, 1));
	SelectObject(hdc, hBrush10);
	SelectObject(hdc, hPen9);
	Ellipse(hdc, 595 + cx, 230 + cy, 645+cx, 280+cy); //колёса
	//Ellipse(hdc, 835+cx, 230+cy, 885+cx, 280+cy);
	DeleteObject(hBrush10);
	DeleteObject(hPen9);

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
	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_LEFT:
			BusWheelX -= 10;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_RIGHT:
			BusWheelX += 10;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		}
		break;
	}
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
			DrawHome(hdc);
			DrawCar(hdc);
			DrawTree(hdc);
			DrawBus(hdc);
			DrawWheel(hdc, BusWheelX, BusWheelY);
			DrawSnegovik(hdc);
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
