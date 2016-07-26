#include "WndProc1.h"

WndProc1::WndProc1(void) {}
WndProc1::~WndProc1(void) {}

LRESULT CALLBACK WndProc1::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
    	case WM_CREATE:
    		MessageBox(hWnd, _T("WndProc1::WndProc"), _T("WM_CREATE"), MB_OK);
    		break;
		case WM_KEYDOWN:
			MessageBox(hWnd, _T("WndProc1::WndProc"), _T("WM_KEYDOWN"), MB_OK);
			break;
		case WM_DESTROY:
			//PostQuitMessage(0);
			break;
		default:
			return(DefWindowProc(hWnd, uMsg, wParam, lParam));
	}
	return (0L);
}