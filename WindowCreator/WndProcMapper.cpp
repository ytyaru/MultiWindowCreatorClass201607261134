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
		0,							// �g���E�B���h�E�X�^�C��
		className.c_str(),			// class��
		_T("WndProcMapper::RegistWndClass�Ő������ꂽWindow�ł��B"),		// �^�C�g��
		WS_OVERLAPPEDWINDOW,		// Style
		CW_USEDEFAULT,				// X
		CW_USEDEFAULT,				// Y
		CW_USEDEFAULT,				// Width
		CW_USEDEFAULT,				// Height
		NULL,						// �e�E�B���h�E�܂��̓I�[�i�[�E�B���h�E�̃n���h��
		NULL,						// ���j���[�n���h���܂��͎q�E�B���h�E ID
		hInstance,					// �A�v���P�[�V�����C���X�^���X�̃n���h��
		NULL						// �E�B���h�E�쐬�f�[�^
	);
	if (NULL == hWnd) { throw "CreateWindow�֐������s�����B"; }
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
	
	// Window�́~�{�^������ or Alt+F4
	// ��WM_DESTROY
	// ��WM_NCDESTROY(130, 0x0082)
	if (uMsg == WM_NCDESTROY) {
		m_mapWndProcByClassName.erase(className);
		m_mapWndProc.erase(hWnd);
	}
	
	// �v���Z�X�I���i�SIWndProc�p���N���X���Ȃ��Ȃ����j
	if( 0 == m_mapWndProcByClassName.size() ) { PostQuitMessage(0); }

	return res;
}
