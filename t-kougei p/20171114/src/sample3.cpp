#include "DxLib.h"
#include <stdlib.h>
#include <time.h>
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	int i, r=2, x[30], y[30];
	int image, planeX, planeY=240;
	ChangeWindowMode(TRUE);
	if(DxLib_Init()==-1)
		return -1;
	srand((unsigned int)time(NULL));
	image=LoadGraph(".\\media\\plane.png");
	for(i=0; i<30; i++){
		x[i]=rand()%640;
		y[i]=rand()%480;
	}
	for(planeX=0; planeX<640; planeX+=2){
		ClearDrawScreen();
		for(i=0; i<30; i++){
			DrawCircle(x[i], y[i], r, GetColor(255, 255, 0), TRUE);
		}
		DrawGraph(planeX, planeY, image, TRUE);
		ScreenFlip();
	}
	WaitKey();
	DxLib_End();
	return 0; 
}
