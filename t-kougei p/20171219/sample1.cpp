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
	struct POINT2DF pos;
	struct VECTOR2DF v;
	int r;
	int color;
	BOOL life;
	int hitTime;
};
BOOL  CollisionDetection(struct POINT2DF pa, int ra, struct POINT2DF pb, int rb)
{
	float d[3];
	d[0] = (float)(ra + rb); d[1] = (float)(pb.x - pa.x); d[2] = (float)(pb.y - pa.y);
	if (d[0] * d[0] >= d[1] * d[1] + d[2] * d[2])
		return TRUE;
	else
		return FALSE;
}
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	const struct SIZE2D screen = { 640, 480 };
	const struct SIZE2D bombSize = { 128, 128 };
	const float dt = (float)1 / 60;
	const int bombAnimNum = 16;
	const int animFPS = 8; // �����摜��1�b�Ԃ�8���A�j���[�V����
	int bgColor;
	char keyBuf[256];
	int* bomb;
	unsigned int bombCount = 0;
	struct CHARADATA enemy, player;
	bomb = (int *)malloc(bombAnimNum*sizeof(int));
	player.pos.x = (float)(screen.width / 2);
	player.pos.y = (float)(screen.height / 2);
	player.r = 20;
	player.color = GetColor(0, 255, 255);
	player.v.x = 160;
	player.v.y = 120;
	enemy.pos.x = 500;
	enemy.pos.y = (float)(screen.height / 2);
	enemy.r = 40;
	enemy.color = GetColor(0, 0, 128);
	enemy.life = TRUE; // �G�̎���
	enemy.hitTime = -1; // �G���e�ɓ�����������
	bgColor = GetColor(0, 128, 64);
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1)
		return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	// bomb.bmp�͉�8���A�c2���A�v16���̉摜
	LoadDivGraph(".\\media\\bomb.bmp", bombAnimNum, 8, 2, bombSize.width, bombSize.height, bomb);
	while (ProcessMessage() == 0){
		GetHitKeyStateAll(keyBuf);
		if (keyBuf[KEY_INPUT_ESCAPE] == 1)
			break;
		if (keyBuf[KEY_INPUT_RIGHT] == 1)
			player.pos.x += player.v.x*dt;
		if (keyBuf[KEY_INPUT_LEFT] == 1)
			player.pos.x -= player.v.x*dt;
		if (keyBuf[KEY_INPUT_UP] == 1)
			player.pos.y -= player.v.y*dt;
		if (keyBuf[KEY_INPUT_DOWN] == 1)
			player.pos.y += player.v.y*dt;
		// �����蔻����s���͓̂G�̎���������Ƃ� ���� �G�t�F�N�g�Đ������Ă��Ȃ��Ƃ�
		// �G�̎����������Ă��G�t�F�N�g�Đ����͓����蔻����s��Ȃ�
		if(enemy.life && enemy.hitTime==-1 && CollisionDetection(player.pos, player.r, enemy.pos, enemy.r)){
			// ������̏ꍇ�͓��������������L��
			// �G�̎��������ł���̂͒e�ɓ��������Ƃ��ł͂Ȃ��A�G�t�F�N�g�Đ�������
			enemy.hitTime=GetNowCount();
		}
		if (enemy.hitTime>0){
			// animFPS=8�Ƃ���ƁA�e�����ł��Ă���125ms���Ƃɕ\������G�t�F�N�g�̃R�}�ԍ���������
			bombCount = ((GetNowCount() - enemy.hitTime) / (1000 / animFPS));
			if (bombCount >= bombAnimNum){
				enemy.life = FALSE;
				enemy.hitTime = -1;
			}
		}
		DrawBox(0, 0, screen.width, screen.height, bgColor, TRUE);
		DrawCircle((int)player.pos.x, (int)player.pos.y, player.r, player.color, FALSE);
		if (enemy.life){
			if (enemy.hitTime == -1) // �G�͌��S
				DrawCircle((int)enemy.pos.x, (int)enemy.pos.y, enemy.r, enemy.color, TRUE);
			else // �G�̎����͎c���Ă��邪�A�G��\������̂ł͂Ȃ��G�t�F�N�g��\��
				DrawGraph((int)enemy.pos.x - bombSize.width / 2, (int)enemy.pos.y - bombSize.height / 2, bomb[bombCount], TRUE);
		}
		ScreenFlip();
	}
	free(bomb);
	DxLib_End();
	return 0;
}
