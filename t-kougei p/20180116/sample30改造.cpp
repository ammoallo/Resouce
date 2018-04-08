#include "DxLib.h"
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	char keyBuf[256];
	float x = 320, y = 240, z = 0, r = 50;
	int diffuseColor[3], specularColor, image;
	VECTOR cameraPos = { 320, 800, -400 };
	VECTOR targetPos = { 320, 240, 0 };
	VECTOR up = { 0, 1, 0 };
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)
		return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);
	diffuseColor[0] = GetColor(255, 0, 0);
	diffuseColor[1] = GetColor(0, 255, 0);
	diffuseColor[2] = GetColor(0, 0, 255);
	specularColor = GetColor(255, 255, 255);
	image = LoadGraph(".\\media\\plane.bmp");
	while (ProcessMessage() == 0){
		GetHitKeyStateAll(keyBuf);
		if (keyBuf[KEY_INPUT_ESCAPE] == 1)
			break;
		if (keyBuf[KEY_INPUT_UP] == 1)
			cameraPos.y += 10;
		if (keyBuf[KEY_INPUT_DOWN] == 1)
			cameraPos.y -= 10;
		if (keyBuf[KEY_INPUT_LEFT] == 1)
			cameraPos.x -= 10;
		if (keyBuf[KEY_INPUT_RIGHT] == 1)
			cameraPos.x += 10;
		SetCameraPositionAndTargetAndUpVec(cameraPos, targetPos, up);
		ClearDrawScreen();
		DrawSphere3D(VGet(x, y, z - 200), r, 32, diffuseColor[0], specularColor, TRUE);
		DrawSphere3D(VGet(x, y, z), r, 32, diffuseColor[1], specularColor, TRUE);
		DrawSphere3D(VGet(x, y, z + 200), r, 32, diffuseColor[2], specularColor, TRUE);
		DrawBillboard3D(VGet(x, y, z), 0.5, 0.5, 300, 0.0, image, TRUE);
		ScreenFlip();
	}
	DxLib_End();
	return 0;
}
