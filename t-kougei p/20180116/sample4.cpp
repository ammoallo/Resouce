#include "DxLib.h"
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	char keyBuf[256];
	float x=320, y=240, z=0, r=50;
	int diffuseColor[3], specularColor, model[2];
	VECTOR cameraPos={0, 240, -400};
	VECTOR targetPos={0, 0, 1};
	VECTOR up={0, 1, 0};
	ChangeWindowMode(TRUE);
	if(DxLib_Init()==-1)
		return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	diffuseColor[0]=GetColor(255, 0, 0);
	diffuseColor[1]=GetColor(0, 255, 0);
	diffuseColor[2]=GetColor(0, 0, 255);
	specularColor=GetColor(255, 255, 255);
	model[0]=MV1LoadModel(".\\media\\cow.x");
	model[1]=MV1LoadModel(".\\media\\cat.x");
	while(ProcessMessage()==0){
		GetHitKeyStateAll(keyBuf);
		if (keyBuf[KEY_INPUT_ESCAPE])
			break;
		if(keyBuf[KEY_INPUT_UP]==1)
			cameraPos.y+=20;
		if(keyBuf[KEY_INPUT_DOWN]==1)
			cameraPos.y-=20;
		if(keyBuf[KEY_INPUT_RIGHT]==1)
			cameraPos.x+=20;
		if(keyBuf[KEY_INPUT_LEFT]==1)
			cameraPos.x-=20;
		SetCameraPositionAndTargetAndUpVec(cameraPos, targetPos, up);
		ClearDrawScreen();
		MV1SetPosition(model[0], VGet(100, 0, 0));
		MV1SetPosition(model[1], VGet(-100, 0, 0));
		DrawSphere3D(VGet(0, 0, -200), r, 32, diffuseColor[0], specularColor, TRUE);
		DrawSphere3D(VGet(0, 0, 0), r, 32, diffuseColor[1], specularColor, TRUE);
		DrawSphere3D(VGet(0, 0, 200), r, 32, diffuseColor[2], specularColor, TRUE);
		MV1DrawModel(model[0]);
		MV1DrawModel(model[1]);
		ScreenFlip();
	}
	DxLib_End();
	return 0; 
}
