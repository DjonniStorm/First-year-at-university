// Lab14.cpp : Определяет точку входа для приложения.
//

#include "stdafx.h"
#include "Lab14.h"
#include "Images.h"
#define MAX_LOADSTRING 100

int image_x = 0;
int image_y = 0;
int model = 0;
int image_n = 0;
int image_m = 0;
unsigned char r = 255, g = 255, b = 255;
//int t = 0;
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
    LoadStringW(hInstance, IDC_LAB14, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB14));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB14));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB14);
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
	case WM_KEYDOWN:
		switch (wParam) 
		{
		case VK_LEFT:
			image_x -= 10;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_RIGHT:
			image_x += 10;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_SPACE:
			model += 1;
			if (model > 4)
				model = 0;
			break;
		case VK_UP:
			image_y -= 10;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_DOWN:
			image_y += 10;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_PRIOR: //page up
			r += 20;
			InvalidateRect(hWnd, NULL, TRUE);
		case VK_NEXT: //page down
			g += 20;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case VK_END: //end
			b += 20;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 0x49: //I
			image_n += 1;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 0x4f: //O
			image_n -= 1;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 0x55: //U
			image_m += 1;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		case 0x4e: //N
			image_m -= 1;
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		}
		break;
	case WM_LBUTTONDOWN:
	{
		WORD xPos, yPos;
		xPos = LOWORD(lParam);
		yPos = HIWORD(lParam);

		image_x = xPos;
		image_y = yPos;
		InvalidateRect(hWnd, NULL, TRUE);
	}
	break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Добавьте сюда любой код прорисовки, использующий HDC...
			typedef int chislo; chislo zero1, zero2, zero3, zero4 = 0;
			zero1 = image_m;
			zero2 = image_n;
			do {
				image_m = zero1;
				zero3 = 0;
				do {
					if (model == 0)
						Images0(hdc, image_x + zero3, image_y + zero4, RGB(r, g, b));
					if (model == 1)
						DrawTriangle(hdc, image_x + zero3, image_y + zero4, RGB(r, g, b));
					if (model == 2) 
						clip(hdc, image_x + zero3, image_y + zero4, RGB(r, g, b));
					if (model == 3) 
						Flag(hdc, image_x + zero3, image_y + zero4, RGB(r, g, b));
					if (model == 4) 
						krown(hdc, image_x + zero3, image_y + zero4, RGB(r, g, b));
					
					zero3 += 50;
					image_m -= 1;
				} while (image_m > 0);
				zero4 += 50;
				image_n -= 1;
			} while (image_n > 0);
			image_n = zero2;
			image_m = zero1;
			//InvalidateRect(hWnd, NULL, TRUE);
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
