// 左右移動＋Zキーの連射対策＋ジャンプ＋重力
#include "DxLib.h"
struct SIZE2D{
	int width;
	int height;
};
struct POINT2DF{
	float x;
	float y;
};
struct VECTOR2DF{
	float x;
	float y;
};
struct CHARADATA{
	int image;
	struct SIZE2D imageSize;
	struct POINT2DF pos;
	BOOL isLeft;
};
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	const float dt=(float)1/60;
	const struct VECTOR2DF moveVec={320, 240};
	const struct VECTOR2DF jumpVec={0, -240};
	const struct VECTOR2DF gravVec={0, 20};
	struct VECTOR2DF inerVec={0, 0};
	int keyZNow, keyZOld, txtColor, bgColor;
	char keyBuf[256], message[100];
	struct CHARADATA player;
	ChangeWindowMode(TRUE);
	if(DxLib_Init() == -1)
		return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	player.image=LoadGraph(".\\media\\pacman.bmp");
	player.isLeft=TRUE;
	GetGraphSize(player.image, &player.imageSize.width, &player.imageSize.height);
	player.pos.x=320; player.pos.y=240;
	txtColor=GetColor(255, 255, 255);
	bgColor=GetColor(64, 128, 128);
	while(ProcessMessage()==0){
		GetHitKeyStateAll(keyBuf);
		if(keyBuf[KEY_INPUT_ESCAPE]==1)
			break;
		if(keyBuf[KEY_INPUT_RIGHT]==1){
			player.pos.x+=moveVec.x*dt;
			player.isLeft=FALSE;
		}
		if(keyBuf[KEY_INPUT_LEFT]==1){
			player.pos.x-=moveVec.x*dt;
			player.isLeft=TRUE;
		}
		if(keyBuf[KEY_INPUT_Z]==1)
			keyZNow=1;
		else
			keyZNow=0;
		if(keyZNow==1 && keyZOld==0){
			strcpy_s(message, 100, "Zを押した"); // ここにジャンプの処理を実装すればよい
			inerVec=jumpVec;
		}else
			strcpy_s(message, 100, "Zを押していない");
		keyZOld=keyZNow;
		inerVec.x+=gravVec.x; inerVec.y+=gravVec.y;
		player.pos.x+=inerVec.x*dt; player.pos.y+=inerVec.y*dt;
		// 描画系の処理
		DrawBox(0, 0, 640, 480, bgColor, TRUE);
		DrawRotaGraph2((int)player.pos.x, (int)player.pos.y, player.imageSize.width/2, player.imageSize.height/2, 1.0, 0.0, player.image, TRUE, player.isLeft);
		DrawString(10, 10, message, txtColor);
		ScreenFlip();
	}
	DxLib_End();
	return 0; 
}
