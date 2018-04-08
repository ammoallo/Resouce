#include "DxLib.h"
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	int image[2], planeX=320, planeY=240, dx=1, dy=1;
	char keyBuf[256];
	ChangeWindowMode(TRUE);
	if(DxLib_Init()==-1)
		return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	image[0]=LoadGraph(".\\media\\sample1.bmp");
	image[1]=LoadGraph(".\\media\\plane.png");
	while(1){
		GetHitKeyStateAll(keyBuf);
		if(keyBuf[KEY_INPUT_RIGHT]==1)
			planeX+=dx;
		if(keyBuf[KEY_INPUT_LEFT]==1)
			planeX-=dx;
		DrawGraph(0, 0, image[0], FALSE); // ClearDrawScreen()の代わりとも言える
		DrawGraph(planeX, planeY, image[1], TRUE);
		ScreenFlip();
		// 実行時間の長いループでは必ず書くこと！！
		if(ProcessMessage()==-1)
			break;
	}
	DxLib_End();
	return 0; 
}
