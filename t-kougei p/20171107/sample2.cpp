#include "DxLib.h"
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	int color;
	ChangeWindowMode(TRUE);
	if(DxLib_Init()==-1){
		return -1;
	}
	color=GetColor(255, 255, 255);
	DrawFormatString(0, 0, color, "Hello World");
	ScreenFlip();
	WaitKey();
	DxLib_End();
	return 0;
}
