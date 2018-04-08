#define _CRT_SECURE_NO_WARNINGS
#include "DxLib.h"
struct POINT2D {
	int x;
	int y;
};
struct SIZE2D {
	int width;
	int height;
};
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	const SIZE2D screen = { 800, 600 };
	const SIZE2D singleImgSize = { 410, 512 };
	const int refleshRate = 60;
	const int bitNum = 32;
	unsigned int loopCount = 0;
	POINT2D pos = { 200, 40 };
	char keyBuf[256];
	int img[6], backColor, index;
	int animFps = 6;
	ChangeWindowMode(TRUE);
	SetGraphMode(screen.width, screen.height, bitNum);
	if (DxLib_Init() == -1)
		return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	SetTransColor(200, 200, 200);
	backColor = GetColor(0, 0, 128);
	LoadDivGraph(".\\media\\run.png", 6, 6, 1, singleImgSize.width, singleImgSize.height, img);
	while (ProcessMessage() == 0) {
		GetHitKeyStateAll(keyBuf);
		if (keyBuf[KEY_INPUT_ESCAPE] == 1)
			break;
		index = (loopCount / (refleshRate / animFps)) % 6;
		DrawBox(0, 0, screen.width, screen.height, backColor, TRUE);
		DrawGraph(pos.x, pos.y, img[index], TRUE);
		ScreenFlip();
		loopCount++;
	}
	DxLib_End();
	return 0;
}
