#include "DxLib.h"
struct POINT2D{
	int x;
	int y;
};
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	const int screenW=640;
	const int screenH=480;
	const struct POINT2D messagePos={100, 200};
	int count=0, backColor, textColor;
	char keyBuf[256], message[40];
	ChangeWindowMode(TRUE);
	if(DxLib_Init()==-1)
		return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	backColor=GetColor(0, 0, 128);
	textColor=GetColor(255, 255, 255);
	SetFontSize(60);
	ChangeFont("ÉÅÉCÉäÉI");
	while(ProcessMessage()!=-1){
		GetHitKeyStateAll(keyBuf);
		if(keyBuf[KEY_INPUT_ESCAPE]==1)
			break;
		if(keyBuf[KEY_INPUT_Z]==1)
			count++;
		if(keyBuf[KEY_INPUT_X]==1)
			count=0;
		sprintf_s(message, 40, "%d", count);
		DrawBox(0, 0, screenW, screenH, backColor, TRUE);
		DrawString(messagePos.x, messagePos.y, message, textColor);
		ScreenFlip();
	}
	DxLib_End();
	return 0; 
}
