#include "DxLib.h"
struct POINT2D{
	int x;
	int y;
};
// POINT2Dではない
struct SIZE2D{
	int width;
	int height;
};
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	SIZE2D screenOld;
	const SIZE2D screenNew={800, 600};
	int bitNumOld;
	const int bitNumNew=32;
	int retVal, textColor;
	POINT2D messagePos={10, 200};
	char message[100];
	ChangeWindowMode(TRUE);
	if(DxLib_Init()==-1)
		return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	GetScreenState(&screenOld.width, &screenOld.height, &bitNumOld);
	// SetGraphModeをDxLib_Init()の前に呼ぶと初期状態変更
	retVal=SetGraphMode(screenNew.width, screenNew.height, bitNumNew);
	if(retVal==DX_CHANGESCREEN_OK){
		sprintf_s(message, 100, "設定できました。変更前：w=%d、h=%d　変更後：w=%d、h=%d",
			screenOld.width, screenOld.height, screenNew.width, screenNew.height);
	}else{
		sprintf_s(message, 100, "設定に失敗しました。変更前：w=%d、h=%d　変更後：w=%d、h=%d",
			screenOld.width, screenOld.height, screenNew.width, screenNew.height);
	}
	textColor=GetColor(255, 255, 255);
	DrawString(messagePos.x, messagePos.y, message, textColor);
	ScreenFlip();
	WaitKey();
	DxLib_End();
	return 0; 
}
