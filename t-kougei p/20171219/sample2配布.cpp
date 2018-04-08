#include "DxLib.h"
#include <math.h>
struct SIZE2D{
	int width;
	int height;
};
struct POINT2DF{
	float x;
	float y;
};
struct CHARADATA{
	struct POINT2DF p;
	int r;
	int color;
};
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	const float dt = (float)1 / 60;
	const float rad2deg = (float)3.1415926 / 180;
	const struct SIZE2D screenSize = { 640, 480 };
	struct CHARADATA enemy;
	int textColor, bgColor;
	unsigned int deg = 0, dDeg = 3, r = 200;
	char keyBuf[256];
	float rad;
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)
		return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	enemy.r = 30;
	enemy.color = GetColor(0, 0, 255);
	textColor = GetColor(255, 255, 255);
	bgColor = GetColor(0, 128, 64);
	while (ProcessMessage() == 0){
		GetHitKeyStateAll(keyBuf);
		if (keyBuf[KEY_INPUT_ESCAPE] == 1)
			break;
		rad = (deg % 360)*rad2deg; // radが1フレームごとに変化する
		enemy.p.x = 0; // 物体を公転させるには右辺をどうする？
		enemy.p.y = 0; // 物体を公転させるには右辺をどうする？
		deg += dDeg;
		DrawBox(0, 0, screenSize.width, screenSize.height, bgColor, TRUE);
		DrawCircle((int)enemy.p.x, (int)enemy.p.y, enemy.r, enemy.color, TRUE);
		ScreenFlip();
	}
	DxLib_End();
	return 0;
}
