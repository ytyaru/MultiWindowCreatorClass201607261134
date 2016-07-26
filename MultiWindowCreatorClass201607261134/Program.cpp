#include <locale.h>
#include <windows.h>
#include <tchar.h>
#include <string>
using namespace std;

#include "WndProcMapper.h"
#include "WndProc1.h"
#include "WndProc2.h"
#include "WndProc3.h"

HWND hWnd;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInst, LPSTR lpszCmdLine, int nCmdShow)
{
	setlocale(LC_ALL, ".ACP");

	WndProc1 wndProc1;
	WndProcMapper::RegistWndClass(hInstance, (IWndProc*)&wndProc1);
	
	WndProc2 wndProc2;
	WndProcMapper::RegistWndClass(hInstance, (IWndProc*)&wndProc2);
	
	WndProc3 wndProc3;
	WndProcMapper::RegistWndClass(hInstance, (IWndProc*)&wndProc3);
	
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}
