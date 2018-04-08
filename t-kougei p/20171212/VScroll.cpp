#include "DxLib.h"
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	unsigned int scrollCount;
	int bgImg, destY[2], srcY[2], srcL[2], imgW, imgH, screenW=640, screenH=480;
	char keyBuf[256];
	ChangeWindowMode(TRUE);
	if(DxLib_Init()==-1)
		return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	bgImg=LoadGraph(".\\media\\img14v.png");
	GetGraphSize(bgImg, &imgW, &imgH);
	//scrollCount=screenH;
	scrollCount=0;
	while(ProcessMessage()==0){
		GetHitKeyStateAll(keyBuf);
		if(keyBuf[KEY_INPUT_ESCAPE]==1)
			break;
		destY[0]=0;
		srcL[0]=scrollCount%imgH;
		srcY[0]=imgH-srcL[0];
		if(srcL[0]>screenH)
			srcL[0]=screenH;
		destY[1]=srcL[0];
		srcL[1]=screenH-srcL[0];
		srcY[1]=0;
		DrawRectGraph(0, destY[0], 0, srcY[0], screenW, srcL[0], bgImg, FALSE, FALSE);
		DrawRectGraph(0, destY[1], 0, srcY[1], screenW, srcL[1], bgImg, FALSE, FALSE);
		DrawFormatString(10, 10, GetColor(255, 255, 255), "destY[0]:%d, srcL[0]:%d, srcY[0]:%d", destY[0], srcL[0], srcY[0]);
		DrawFormatString(10, 40, GetColor(255, 255, 255), "destY[1]:%d, srcL[1]:%d, srcY[1]:%d", destY[1], srcL[1], srcY[1]);
		ScreenFlip();
		scrollCount++;
	}
	DxLib_End();
	return 0; 
}
