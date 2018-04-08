#include "DxLib.h"
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	float x=320, y=240, z=0, r=50;
	int diffuseColor, specularColor, image;
	ChangeWindowMode(TRUE);
	if(DxLib_Init()==-1)
		return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	diffuseColor=GetColor(255, 0, 0);
	specularColor=GetColor(255, 255, 255);
	image=LoadGraph(".\\media\\plane.bmp");
	for(x=0; x<640; x+=2){
		ClearDrawScreen();
		DrawSphere3D(VGet(320, y, z), r, 32, diffuseColor, specularColor, TRUE);
		DrawBillboard3D(VGet(x, y, z), 0.5, 0.5, 300, 0.0, image, TRUE);
		ScreenFlip();
		if(ProcessMessage()==-1)
			break;
	}
	WaitKey();
	DxLib_End();
	return 0; 
}
