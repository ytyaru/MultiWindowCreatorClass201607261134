#include "WndProcMapper.h"

map<basic_string<TCHAR>, IWndProc*> WndProcMapper::m_mapWndProcByClassName;
map<HWND, IWndProc*> WndProcMapper::m_mapWndProc;

WndProcMapper::WndProcMapper(void) {}
WndProcMapper::~WndProcMapper(void) {}

void WndProcMapper::RegistWndClass(HINSTANCE hInstance, IWndProc* wndProc)
{
	WndClassRegister WndClsReg;
	basic_string<TCHAR> className = WndClsReg.Regist(hInstance);
	m_mapWndProcByClassName.insert( map<basic_string<TCHAR>, IWndProc*>::value_type( className, wndProc ) );

	HWND hWnd = CreateWindowEx(
		0,							// 拡張ウィンドウスタイル
		className.c_str(),			// class名
		_T("WndProcMapper::RegistWndClassで生成されたWindowです。"),		// タイトル
		WS_OVERLAPPEDWINDOW,		// Style
		CW_USEDEFAULT,				// X
		CW_USEDEFAULT,				// Y
		CW_USEDEFAULT,				// Width
		CW_USEDEFAULT,				// Height
		NULL,						// 親ウィンドウまたはオーナーウィンドウのハンドル
		NULL,						// メニューハンドルまたは子ウィンドウ ID
		hInstance,					// アプリケーションインスタンスのハンドル
		NULL						// ウィンドウ作成データ
	);
	if (NULL == hWnd) { throw "CreateWindow関数が失敗した。"; }
	m_mapWndProc.insert( map<HWND, IWndProc*>::value_type( hWnd, wndProc ) );

	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);
}
LRESULT CALLBACK WndProcMapper::BaseWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	TCHAR className[1024];
	memset(className, '\0', 1024);
	GetClassName(hWnd, className, 1024);
	LRESULT res = m_mapWndProcByClassName[className]->WndProc(hWnd, uMsg, wParam, lParam);
	
	// Windowの×ボタン押下 or Alt+F4
	// →WM_DESTROY
	// →WM_NCDESTROY(130, 0x0082)
	if (uMsg == WM_NCDESTROY) {
		m_mapWndProcByClassName.erase(className);
		m_mapWndProc.erase(hWnd);
	}
	
	// プロセス終了（全IWndProc継承クラスがなくなった）
	if( 0 == m_mapWndProcByClassName.size() ) { PostQuitMessage(0); }

	return res;
}
