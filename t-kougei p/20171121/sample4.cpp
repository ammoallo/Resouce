#include "DxLib.h"
#include <stdlib.h>
#include <time.h>
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	int x1, x2, y1, y2, r1, r2, d1, d2, d3, color[3];
	ChangeWindowMode(TRUE);
	if(DxLib_Init()==-1){
		return -1;
	}
	SetDrawScreen(DX_SCREEN_BACK);
	srand((unsigned int)time(NULL));
	color[0]=GetColor(255, 0, 0);
	color[1]=GetColor(0, 0, 255);
	color[2]=GetColor(255, 255, 255);
	r1=150;
	r2=150;
	x1=rand()%640;
	y1=rand()%480;
	x2=rand()%640;
	y2=rand()%480;
	d1=r1+r2;
	d2=x2-x1;
	d3=y2-y1;
	DrawCircle(x1, y1, r1, color[0], TRUE);
	DrawCircle(x2, y2, r2, color[1], TRUE);
	if(d1*d1>=d2*d2+d3*d3){
		DrawFormatString(0, 30, color[2], "当たりました");
	}else{
		DrawFormatString(0, 30, color[2], "当たっていません");
	}
	ScreenFlip();
	WaitKey();
	DxLib_End();
	return 0;
}
