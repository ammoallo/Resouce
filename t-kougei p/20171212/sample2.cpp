#include "DxLib.h"
struct POINT2DF{float x; float y;};
struct VECTOR2DF{float x; float y;};
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	const float dt=(float)1/60; // 60とは何を表す？そして60も定数にすべき
	const struct VECTOR2DF moveVec={160, 120}; // 1秒あたりの移動速度[ピクセル]
	struct POINT2DF pos={320, 240};
	int image, width, height, start, now;
	char keyBuf[256], text[100];
	ChangeWindowMode(TRUE);
	if(DxLib_Init()==-1)
		return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	image=LoadGraph(".\\media\\pacman.bmp");
	GetGraphSize(image, &width, &height);
	start=GetNowCount();
	while(ProcessMessage()==0){
		now=GetNowCount();
		GetHitKeyStateAll(keyBuf);
		if(keyBuf[KEY_INPUT_ESCAPE]==1)
			break;
		if(keyBuf[KEY_INPUT_RIGHT]==1)
			pos.x+=moveVec.x*dt;
		if(keyBuf[KEY_INPUT_LEFT]==1)
			pos.x-=moveVec.x*dt;
		if(keyBuf[KEY_INPUT_DOWN]==1)
			pos.y+=moveVec.y*dt;
		if(keyBuf[KEY_INPUT_UP]==1)
			pos.y-=moveVec.y*dt;
		sprintf_s(text, 100, "%d秒経過", (now-start)/1000);
		DrawBox(0, 0, 640, 480, GetColor(0, 128, 0), TRUE);
		DrawRotaGraph2((int)pos.x, (int)pos.y, width/2, height/2, 1.0, 0.0, image, TRUE);
		DrawString(50, 20, text, GetColor(255, 255, 255));
		ScreenFlip();
	}
	DxLib_End();
	return 0; 
}
