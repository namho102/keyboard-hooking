#include "stdafx.h"
#include <Windows.h>
#include <iostream>
using namespace std;


LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{	
	
	//	cout << wParam << endl;
//	cout << lParam << endl;
	
	
	BOOL fEatKeystroke = FALSE;

	if ((nCode == HC_ACTION)) { //It's always true???

		//cout<<wParam<<endl;

		if (wParam == WM_SYSKEYUP) {
			cout << "SystemKey up" << endl;
		} else if (wParam == WM_KEYUP) {
			//cout << "Key up" << endl;
			PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;

			switch (p->vkCode)
				case VK_RETURN: cout << " -enter" << endl;
			
			//cout << p->vkCode << endl;
			char c = p->vkCode;
			//cout << c << endl;
			//cout << toascii(p->vkCode)<<endl;
			cout << c;
		}
	}
	
	return(fEatKeystroke ? 1 : CallNextHookEx(NULL, nCode, wParam, lParam));;
}



/*
LRESULT  CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{	
	cout << 'wtf';
	char ch;
//	if (((DWORD)lParam & 0x40000000) && (HC_ACTION == nCode))
	if ((HC_ACTION == nCode))
	{
		cout << 'wtf';
		if ((wParam == VK_SPACE) || (wParam == VK_RETURN) || (wParam >= 0x2f) && (wParam <= 0x100))
		{
			if (wParam == VK_RETURN)
			{
				ch = '\n';
				cout << ch << endl;
			}
			else
			{
				BYTE ks[256];
				GetKeyboardState(ks);

				WORD w;
				UINT scan = 0;
				ToAscii(wParam, scan, ks, &w, 0);
				ch = char(w);
				cout << ch << endl;
			}

		}
	}

	LRESULT RetVal = CallNextHookEx(NULL, nCode, wParam, lParam);
	return 0;
	return  RetVal;

}

*/

int main()
{
	// Install the low-level keyboard & mouse hooks
	HHOOK hhkLowLevelKybd = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, 0, 0);

	MSG msg;
	while (!GetMessage(&msg, NULL, NULL, NULL)) {    //this while loop keeps the hook
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	/*
	HHOOK hhkLowLevelKybd = SetWindowsHookEx(WH_KEYBOARD, KeyboardProc, 0, 0);

	MSG msg;
	while (!GetMessage(&msg, NULL, NULL, NULL)) {    //this while loop keeps the hook
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	*/
	
	return(0);
}