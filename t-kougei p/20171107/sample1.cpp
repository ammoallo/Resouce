#include "DxLib.h"
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	ChangeWindowMode(TRUE);
	if(DxLib_Init()==-1){
		return -1;
	}
	printfDx("Hello World");
	ScreenFlip();
	WaitKey();
	DxLib_End();
	return 0;
}
