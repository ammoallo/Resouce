#include "DxLib.h"
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	int image, width, height;
	char keyBuf[256];
	double rad=0.0, scale=1.0, drad=0.1, dscale=0.1;
	ChangeWindowMode(TRUE);
	if(DxLib_Init()==-1)
		return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	image=LoadGraph(".\\media\\pacman.bmp");
	while(ProcessMessage()==0){
		GetHitKeyStateAll(keyBuf);
		if(keyBuf[KEY_INPUT_ESCAPE]==1)
			break;
		if(keyBuf[KEY_INPUT_RIGHT]==1)
			scale+=dscale;
		if(keyBuf[KEY_INPUT_LEFT]==1)
			scale-=dscale;
		if(keyBuf[KEY_INPUT_DOWN]==1)
			rad+=drad;
		if(keyBuf[KEY_INPUT_UP]==1)
			rad-=drad;
		if(keyBuf[KEY_INPUT_R]==1){
			rad=0.0;
			scale=1.0;
		}
		GetGraphSize(image, &width, &height);
		DrawBox(0, 0, 640, 480, GetColor(0, 128, 0), TRUE);
		DrawRotaGraph2(320, 240, width/2, height/2, scale, rad, image, TRUE);
		ScreenFlip();
	}
	DxLib_End();
	return 0; 
}
