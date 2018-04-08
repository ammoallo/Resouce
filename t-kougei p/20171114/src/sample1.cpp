#include "DxLib.h"
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	int image;
	ChangeWindowMode(TRUE);
	if(DxLib_Init()==-1)
		return -1;
	image=LoadGraph(".\\Media\\sample1.bmp");
	DrawGraph(0, 0, image, FALSE);
	ScreenFlip();
	WaitKey();
	DxLib_End();
	return 0; 
}
