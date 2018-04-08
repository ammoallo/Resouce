#include "DxLib.h"
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	unsigned int scrollCount=0;
	int bgImg, destX[2], srcX[2], srcL[2], imgW, imgH, screenW=640, screenH=480;
	char keyBuf[256];
	ChangeWindowMode(TRUE);
	if(DxLib_Init()==-1)
		return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	bgImg=LoadGraph(".\\media\\img14h.png"); // ‰æ‘œ‚Í‰¡1280xc480
	GetGraphSize(bgImg, &imgW, &imgH);
	while(ProcessMessage()==0){
		GetHitKeyStateAll(keyBuf);
		if(keyBuf[KEY_INPUT_ESCAPE]==1)
			break;
		destX[0]=0;
		srcX[0]=scrollCount%imgW;
		srcL[0]=imgW-srcX[0];
		if(srcL[0]>screenW)
			srcL[0]=screenW;
		destX[1]=srcL[0];
		srcX[1]=0;
		srcL[1]=screenW-srcL[0];
		DrawRectGraph(destX[0], 0, srcX[0], 0, srcL[0], screenH, bgImg, FALSE, FALSE);
		DrawRectGraph(destX[1], 0, srcX[1], 0, srcL[1], screenH, bgImg, FALSE, FALSE);
		DrawFormatString(10, 10, GetColor(255, 255, 255), "destX[0]:%d, srcL[0]:%d, srcX[0]:%d", destX[0], srcL[0], srcX[0]);
		DrawFormatString(10, 40, GetColor(255, 255, 255), "destX[1]:%d, srcL[1]:%d, srcX[1]:%d", destX[1], srcL[1], srcX[1]);
		ScreenFlip();
		scrollCount++;
	}
	DxLib_End();
	return 0; 
}
