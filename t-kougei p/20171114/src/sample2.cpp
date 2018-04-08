#include "DxLib.h"
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	int image[2];
	ChangeWindowMode(TRUE);
	if(DxLib_Init()==-1)
		return -1;
	image[0]=LoadGraph(".\\media\\img27.jpg");
	image[1]=LoadGraph(".\\media\\plane.png");
	DrawExtendGraph(0, 0, 640, 480, image[0], FALSE);
	DrawGraph(0, 0, image[1], FALSE);
	ScreenFlip(); // åƒÇ‘èÍèäÇ…íçà”
	WaitKey();
	DxLib_End();
	return 0; 
}
