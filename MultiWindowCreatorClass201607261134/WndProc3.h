#pragma once
#include "IWndProc.h"

class WndProc3 : public IWndProc
{
public:
	WndProc3(void);
	~WndProc3(void);
	LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};
