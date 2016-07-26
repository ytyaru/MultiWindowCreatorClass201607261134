#pragma once
#include <windows.h>
#include <tchar.h>
#include <string>
#include <map>
#include "WndClassRegister.h"
#include "IWndProc.h"
using namespace std;

class WndProcMapper
{
public:
	WndProcMapper(void);
	~WndProcMapper(void);
	static void RegistWndClass(HINSTANCE hInstance, IWndProc* wndProc);
	static LRESULT CALLBACK BaseWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
private:
	static map<basic_string<TCHAR>, IWndProc*> m_mapWndProcByClassName;
	static map<HWND, IWndProc*> m_mapWndProc;
};
