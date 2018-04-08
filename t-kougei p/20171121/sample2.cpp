#include "DxLib.h"
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	int sound, color;
	ChangeWindowMode(TRUE);
	if(DxLib_Init()==-1){
		return -1;
	}
	SetDrawScreen(DX_SCREEN_BACK);
	color=GetColor(255, 255, 255);
	sound=LoadSoundMem(".\\media\\chimes.wav");
	PlaySoundMem(sound, DX_PLAYTYPE_NORMAL);
	DrawFormatString(100, 50, color, "çƒê∂Ç™äÆóπÇµÇ‹ÇµÇΩÅB");
	ScreenFlip();
	WaitKey();
	DxLib_End();
	return 0; 
}
