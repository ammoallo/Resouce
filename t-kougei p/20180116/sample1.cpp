#include "DxLib.h"
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	float x=320, y=240, z=0, r=50;
	int diffuseColor, specularColor;
	ChangeWindowMode(TRUE);
	if(DxLib_Init()==-1)
		return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	diffuseColor=GetColor(255, 0, 0);
	specularColor=GetColor(255, 255, 255);
	ClearDrawScreen();
	DrawSphere3D(VGet(x, y, z), r, 32, diffuseColor, specularColor, TRUE);
	ScreenFlip();
	WaitKey();
	DxLib_End();
	return 0; 
}
