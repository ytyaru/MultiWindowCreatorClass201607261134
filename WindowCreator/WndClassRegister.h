#pragma once
#pragma comment(lib, "Rpcrt4.lib")
#include <windows.h>
#include <tchar.h>
#include <string>
#include "WndProcMapper.h"
using namespace std;

class WndClassRegister
{
public:
	WndClassRegister(void);
	~WndClassRegister(void);
	basic_string<TCHAR> Regist(HINSTANCE hInstance);
private:
	basic_string<TCHAR> GetUuid();
};
