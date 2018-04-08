#include "DxLib.h"
struct POINT2D{
	int x;
	int y;
};
struct SIZE2D{
	int width;
	int height;
};
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	const SIZE2D screen={800, 600};
	const SIZE2D singleImgSize={410, 512};
	const int bitNum=32;
	POINT2D pos={200, 40};
	char keyBuf[256];
	int img[6], backColor;
	unsigned int count=0;	// unsignedÇÕèdóv
	ChangeWindowMode(TRUE);
	SetGraphMode(screen.width, screen.height, bitNum);
	if(DxLib_Init()==-1)
		return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	SetTransColor(200, 200, 200);
	backColor=GetColor(0, 0, 128);
	LoadDivGraph(".\\media\\run.png", 6, 6, 1, singleImgSize.width, singleImgSize.height, img);
	while(ProcessMessage()!=-1){
		GetHitKeyStateAll(keyBuf);
		if(keyBuf[KEY_INPUT_ESCAPE]==1)
			break;
		DrawBox(0, 0, screen.width, screen.height, backColor, TRUE);
		DrawGraph(pos.x, pos.y, img[count%6], TRUE);
		ScreenFlip();
		count++;
	}
	DxLib_End();
	return 0; 
}
