#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	int r=20, color;
	char keyBuf[256], message[2][100];
	const int messageLen=100;
	struct POINT2D pos;
	struct POINT2DF mousePos, segmentStartPos={500, 80}, segmentEndPos={200, 400};
	struct MYRECT screen={640, 480};
	
	ChangeWindowMode(TRUE);
	if(DxLib_Init()==-1)
		return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	SetMouseDispFlag(TRUE);
	color=GetColor(0, 0, 255);
   	
	while(ProcessMessage()==0){
		GetHitKeyStateAll(keyBuf);
		if(keyBuf[KEY_INPUT_ESCAPE]==1)
			break;

		GetMousePoint(&(pos.x), &(pos.y));
		if(pos.x<r)
			pos.x=r;
		else if(pos.x>screen.width-r)
			pos.x=screen.width-r;
		if(pos.y<r)
			pos.y=r;
		else if(pos.y>screen.height-r)
			pos.y=screen.height-r;

		sprintf_s(message[0], messageLen, "�}�E�X�ʒu�F(%3d,%3d)", pos.x, pos.y);
		mousePos.x=(float)pos.x; mousePos.y=(float)pos.y; // �����蔻��p��float�^�ɕϊ�
   		
   		// �����œ����蔻��
		if(CollisionDetection(mousePos, r, segmentStartPos, segmentEndPos))
			sprintf_s(message[1], messageLen, "������܂���");
		else
			sprintf_s(message[1], messageLen, "�������Ă��܂���");

		// �ȉ��͕`��
		DrawBox(0, 0, screen.width, screen.height, GetColor(160, 160, 160), TRUE);
		DrawCircle(pos.x, pos.y, r, color, TRUE);
		DrawLine((int)segmentStartPos.x, (int)segmentStartPos.y, (int)segmentEndPos.x, (int)segmentEndPos.y, GetColor(255, 0, 0));
		DrawFormatString((int)segmentStartPos.x, (int)segmentStartPos.y, GetColor(0, 0, 0), "(%d,%d)", (int)segmentStartPos.x, (int)segmentStartPos.y);
		DrawFormatString((int)segmentEndPos.x, (int)segmentEndPos.y, GetColor(0, 0, 0), "(%d,%d)", (int)segmentEndPos.x, (int)segmentEndPos.y);
		DrawString(10, 10, message[0], GetColor(0, 0, 0));
		DrawString(10, 40, message[1], GetColor(0, 0, 0));

		ScreenFlip();
	}
	DxLib_End();
	return 0;
}
