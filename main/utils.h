#include"..\counter\Counter.h"
#include<windows.h>
#pragma once




void lockWindowSize(const HWND &hWnd)
{

	RECT newRect;
	GetClientRect(hWnd, &newRect);
	SetWindowPos(hWnd, NULL, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);

}




