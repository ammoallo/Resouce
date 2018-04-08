#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	int color, start, end, interval;
	char keyBuf[256], message[100];
	
	ChangeWindowMode(TRUE);
	if(DxLib_Init()==-1){
		return -1;
	}
	SetDrawScreen(DX_SCREEN_BACK);
	color=GetColor(255, 255, 255);

	DrawFormatString(0, 0, color, "�J�n���܂��B�����L�[�������Ă��������B");
	ScreenFlip();
	WaitKey();

	start=GetNowCount();

	DrawFormatString(0, 20, color, "�J�n���܂����B�C����������ESC�L�[�������Ă��������B");
	ScreenFlip();

   	while(ProcessMessage()!=-1){
		GetHitKeyStateAll(keyBuf);
		if(keyBuf[KEY_INPUT_ESCAPE]==1){
			end=GetNowCount();
			break;
		}
	}
	
	interval=end-start;
	
	sprintf_s(message, "%.3f�b�o�߂��܂����B", interval/1000.0);
	DrawFormatString(0, 40, color, message);
	ScreenFlip();

	WaitKey();
	DxLib_End();
	return 0;
}
