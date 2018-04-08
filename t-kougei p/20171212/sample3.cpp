#include "DxLib.h"
#include <stdlib.h>
#include <time.h>
struct POINT2DF{float x; float y;};
struct VECTOR2DF{float x; float y;};
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	const float dt=(float)1/60;
	const int r=30;
	struct POINT2DF pos[2];
	struct VECTOR2DF vec, moveVec;
	int i, color[2], start, now;
	char keyBuf[256], text[100];
	srand((unsigned int)time(NULL));
	ChangeWindowMode(TRUE);
	if(DxLib_Init()==-1)
		return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	pos[0].x=(float)(rand()%640); pos[0].y=(float)(rand()%480);
	pos[1].x=(float)(rand()%640); pos[1].y=(float)(rand()%480);
	color[0]=GetColor(255, 0, 0); color[1]=GetColor(0, 0, 255);
	// â~1Ç™â~0Ç…å¸Ç©Ç¡ÇƒìÆÇ≠
	vec.x=pos[0].x-pos[1].x; vec.y=pos[0].y-pos[1].y;
	// 3ïbÇ≈ìûíBÇ∑ÇÈë¨ìxÇ…ê›íË
	moveVec.x=vec.x/3; moveVec.y=vec.y/3;
	start=GetNowCount();
	while(ProcessMessage()==0){
		now=GetNowCount();
		GetHitKeyStateAll(keyBuf);
		if(keyBuf[KEY_INPUT_ESCAPE]==1)
			break;
		pos[1].x+=moveVec.x*dt; pos[1].y+=moveVec.y*dt;
		sprintf_s(text, 100, "%dïbåoâﬂ", (now-start)/1000);
		DrawBox(0, 0, 640, 480, GetColor(0, 128, 0), TRUE);
		for(i=0; i<2; i++)
			DrawCircle((int)pos[i].x, (int)pos[i].y, r, color[i], TRUE);
		DrawString(50, 20, text, GetColor(255, 255, 255));
		ScreenFlip();
	}
	DxLib_End();
	return 0; 
}
