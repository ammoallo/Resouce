#include "DxLib.h"
struct POINT2D{
	int x;
	int y;
};
struct VECTOR2D{
	int x;
	int y;
};
struct CHARADATA{
	struct VECTOR2D move;
	struct POINT2D pos;
	int r;
	int color;
	BOOL life;
};
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	char keyBuf[256];
	struct CHARADATA shot;
	ChangeWindowMode(TRUE);
	if(DxLib_Init()==-1)
		return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	shot.pos.x=320;
	shot.pos.y=240;
	shot.move.x=5;
	shot.move.y=0;
	shot.r=4;
	shot.color=GetColor(255, 255, 255);
	while(ProcessMessage()==0){
		GetHitKeyStateAll(keyBuf);
		if(keyBuf[KEY_INPUT_ESCAPE]==1)
			break;
		DrawBox(0, 0, 640, 480, GetColor(0, 0, 0), TRUE);
		shot.pos.x+=shot.move.x;
		// ¡“x‚Í-shot.r
		if(shot.pos.x>640-shot.r || shot.pos.x < shot.r)
		;
		// ª‚É1s‘‚¢‚Ä‰i‹v‚É”½ŽË‚·‚é‚æ‚¤‚É‚µ‚È‚³‚¢
		
		DrawCircle(shot.pos.x, shot.pos.y, shot.r, shot.color, TRUE);
		ScreenFlip();
	}
	DxLib_End();
	return 0; 
}
