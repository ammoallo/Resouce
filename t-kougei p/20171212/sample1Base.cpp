// ’e‚Æ“G‚ÍÁ–Å‚µ‚È‚¢
#include "DxLib.h"
struct POINT2D{ int x; int y; };
struct VECTOR2D{ int x; int y; };
struct CHARADATA{
	struct VECTOR2D move;
	struct POINT2D pos;
	int r;
	int color;
	BOOL life;
};
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	int d[3];
	char keyBuf[256], keyZNow, keyZOld;
	struct CHARADATA shot, obst, player;
	BOOL hitFlag;
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)
		return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	shot.life = FALSE;
	obst.pos.x = 550;	obst.pos.y = 320;	obst.r = 30; obst.color = GetColor(255, 0, 0);
	obst.life = TRUE;
	player.pos.x = 320; player.pos.y = 240;
	keyZOld = 0;
	while (ProcessMessage() == 0){
		GetHitKeyStateAll(keyBuf);
		if (keyBuf[KEY_INPUT_ESCAPE] == 1)
			break;
		if (keyBuf[KEY_INPUT_UP] == 1)
			player.pos.y -= 3;
		if (keyBuf[KEY_INPUT_DOWN] == 1)
			player.pos.y += 3;
		if (keyBuf[KEY_INPUT_LEFT] == 1)
			player.pos.x -= 3;
		if (keyBuf[KEY_INPUT_RIGHT] == 1)
			player.pos.x += 3;
		if (keyBuf[KEY_INPUT_Z] == 1)
			keyZNow = 1;
		else
			keyZNow = 0;
		if (keyZNow == 1 && keyZOld == 0){
			if (!shot.life){
				shot.life = TRUE;
				shot.pos.x = player.pos.x;
				shot.pos.y = player.pos.y;
				shot.move.x = 3;
				shot.r = 4;
				shot.color = GetColor(255, 255, 255);
			}
		}
		hitFlag = FALSE;
		DrawBox(0, 0, 640, 480, GetColor(0, 0, 0), TRUE);
		DrawLine(player.pos.x, player.pos.y - 20, player.pos.x, player.pos.y + 20, GetColor(0, 255, 255), 2);
		DrawLine(player.pos.x - 20, player.pos.y, player.pos.x + 20, player.pos.y, GetColor(0, 255, 255), 2);
		if (shot.life){
			shot.pos.x += shot.move.x;
			if (shot.pos.x>640 + shot.r)
				shot.life = FALSE;
			else
				DrawCircle(shot.pos.x, shot.pos.y, shot.r, shot.color, TRUE);
			d[0] = obst.pos.x - shot.pos.x; d[1] = obst.pos.y - shot.pos.y; d[2] = obst.r + shot.r;
			if (d[0] * d[0] + d[1] * d[1]<d[2] * d[2])
				hitFlag = TRUE;
		}
		DrawCircle(obst.pos.x, obst.pos.y, obst.r, obst.color, TRUE);
		if (hitFlag)
			DrawFormatString(10, 10, GetColor(255, 255, 255), "“–‚½‚Á‚½");
		else
			DrawFormatString(10, 10, GetColor(255, 255, 255), "“–‚½‚Á‚Ä‚¢‚È‚¢");
		ScreenFlip();
		keyZOld = keyZNow;
	}
	DxLib_End();
	return 0;
}
