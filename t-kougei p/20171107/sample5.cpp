#include "DxLib.h"
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	int color;
	ChangeWindowMode(TRUE);
	if(DxLib_Init()==-1){
		return -1;
	}
	SetFontSize(100);
	ChangeFont("���C���I");
	color=GetColor(255, 255, 255);
	DrawFormatString(0, 240, color, "�v���O������bII");
	ScreenFlip();
	WaitKey();
	DxLib_End();
	return 0;
}
