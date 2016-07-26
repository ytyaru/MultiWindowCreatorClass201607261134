#include "WndProc3.h"

WndProc3::WndProc3(void) {}
WndProc3::~WndProc3(void) {}

LRESULT CALLBACK WndProc3::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
    	case WM_CREATE:
			SetWindowLong(hWnd, GWL_EXSTYLE, GetWindowLong(hWnd, GWL_EXSTYLE) | WS_EX_LAYERED);
			SetLayeredWindowAttributes(hWnd, RGB(255, 0, 0), 128, LWA_ALPHA);
			////SetWindowLong(hWnd, GWL_EXSTYLE, SomeValue);
			////SetWindowLong(hWnd, GWL_STYLE, SomeValue);
			////SetWindowLong(hWnd, GWL_WNDPROC, SomeWndProc); // NG�BWndProcMapper::BaseWndProc��ݒ肵�Ă���B�ύX������_���B
			////SetWindowLong(hWnd, GWL_HINSTANCE, SomeHInstance); // ����Ȃ��Ƃ���K�v����H
			////SetWindowLong(hWnd, GWL_ID, SomeId); // Window��ID ���ĉ��H
			////SetWindowLong(hWnd, GWL_USERDATA, SomeData);
			SetWindowText(hWnd, _T("WndProc3��Window�B�^�C�g���┼��������WM_CREATE�Őݒ肵���B"));
			MessageBox(hWnd, _T("WndProc3::WndProc"), _T("WM_CREATE"), MB_OK);
    		break;
		case WM_KEYDOWN:
			MessageBox(hWnd, _T("WndProc3::WndProc"), _T("WM_KEYDOWN"), MB_OK);
			break;
		case WM_PAINT:
		{
			HDC hdc;
			PAINTSTRUCT ps;

			hdc = BeginPaint(hWnd , &ps);
			
			SelectObject(hdc , GetStockObject(BLACK_BRUSH));
			Rectangle(hdc , 0 , 0 , GetSystemMetrics(SM_CXSCREEN) , GetSystemMetrics(SM_CYSCREEN));
			
			SetTextColor(hdc, RGB(255 , 255 , 255));
			SetBkMode(hdc , TRANSPARENT);
			TextOut(hdc , 10 , 30, _T("����Window�ōőO�ʁB") , _tcslen( _T("����Window�ōőO�ʁB")));

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