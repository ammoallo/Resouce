// ¶‰EˆÚ“®{ZƒL[‚Ì˜AË‘Îô{ƒWƒƒƒ“ƒv{d—Í{‚’¼R—Í
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
	BOOL onGround;
};
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	const float dt=(float)1/60;
	const struct VECTOR2DF moveVec={320, 240};
	const struct VECTOR2DF jumpVec={0, -400};
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
	player.onGround=FALSE;
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
			strcpy_s(message, 100, "Z‚ğ‰Ÿ‚µ‚½"); // ‚±‚±‚ÉƒWƒƒƒ“ƒv‚Ìˆ—‚ğÀ‘•‚·‚ê‚Î‚æ‚¢
			player.onGround=FALSE;
			inerVec=jumpVec;
		}else
			strcpy_s(message, 100, "Z‚ğ‰Ÿ‚µ‚Ä‚¢‚È‚¢");
		keyZOld=keyZNow;
		if(!player.onGround){
			inerVec.x+=gravVec.x; inerVec.y+=gravVec.y;
		}
		player.pos.x+=inerVec.x*dt; player.pos.y+=inerVec.y*dt;
		if(player.pos.y>400){
			player.pos.y=400;
			player.onGround=TRUE;
			inerVec.x=0;
			inerVec.y=0;
		}
		// •`‰æŒn‚Ìˆ—
		DrawBox(0, 0, 640, 480, bgColor, TRUE);
		DrawRotaGraph2((int)player.pos.x, (int)player.pos.y, player.imageSize.width/2, player.imageSize.height/2, 1.0, 0.0, player.image, TRUE, player.isLeft);
		DrawString(10, 10, message, txtColor);
		ScreenFlip();
	}
	DxLib_End();
	return 0; 
}
