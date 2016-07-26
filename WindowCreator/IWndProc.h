#pragma once
#include <windows.h>
#include <tchar.h>
#include <string>

class IWndProc
{
public:
	virtual LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;
};
