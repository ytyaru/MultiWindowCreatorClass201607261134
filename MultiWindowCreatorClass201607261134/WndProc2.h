#pragma once
#include "IWndProc.h"

class WndProc2 : public IWndProc
{
public:
	WndProc2(void);
	~WndProc2(void);
	LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};
