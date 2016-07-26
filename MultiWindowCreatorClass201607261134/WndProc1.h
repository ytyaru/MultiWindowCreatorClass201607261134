#pragma once
#include "IWndProc.h"

class WndProc1 : public IWndProc
{
public:
	WndProc1(void);
	~WndProc1(void);
	LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};
