#include "DxLib.h"
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	int i, color;
	ChangeWindowMode(TRUE);
	if(DxLib_Init()==-1){
		return -1;
	}
	color=GetColor(255, 255, 255);
	for(i=0; i<640; i++){
		DrawFormatString(i, 0, color, "プログラム基礎II");
	}
	ScreenFlip();
	WaitKey();
	DxLib_End();
	return 0;
}
