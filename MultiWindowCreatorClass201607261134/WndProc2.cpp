#include "WndProc2.h"

WndProc2::WndProc2(void) {}
WndProc2::~WndProc2(void) {}

LRESULT CALLBACK WndProc2::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
    	case WM_CREATE:
			MessageBox(hWnd, _T("WndProc2::WndProc"), _T("WM_CREATE"), MB_OK);
    		break;
		case WM_KEYDOWN:
			MessageBox(hWnd, _T("WndProc2::WndProc"), _T("WM_KEYDOWN"), MB_OK);
			break;
		case WM_PAINT:
		{
			HDC hdc;
			PAINTSTRUCT ps;

			hdc = BeginPaint(hWnd , &ps);

			SetBkColor(hdc , RGB(0xFF , 0 , 0));
			TextOut(hdc , 10 , 10 , _T("WndProc2ですぞ。") , _tcslen( _T("WndProc2ですぞ。")));

			SetBkMode(hdc , TRANSPARENT);
			TextOut(hdc , 10 , 30, _T("WM_PAINTで実装。GDIにて描画。TextOut関数。") , _tcslen( _T("WM_PAINTで実装。GDIにて描画。TextOut関数。")));
			EndPaint(hWnd , &ps);
			return 0;
			break;
		}
		case WM_DESTROY:
			//PostQuitMessage(0);
			break;
		default:
			return(DefWindowProc(hWnd, uMsg, wParam, lParam));
	}
	return (0L);
}