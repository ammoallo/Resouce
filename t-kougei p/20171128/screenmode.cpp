#include "DxLib.h"
struct POINT2D{
	int x;
	int y;
};
// POINT2D�ł͂Ȃ�
struct SIZE2D{
	int width;
	int height;
};
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
	SIZE2D screenOld;
	const SIZE2D screenNew={800, 600};
	int bitNumOld;
	const int bitNumNew=32;
	int retVal, textColor;
	POINT2D messagePos={10, 200};
	char message[100];
	ChangeWindowMode(TRUE);
	if(DxLib_Init()==-1)
		return -1;
	SetDrawScreen(DX_SCREEN_BACK);
	GetScreenState(&screenOld.width, &screenOld.height, &bitNumOld);
	// SetGraphMode��DxLib_Init()�̑O�ɌĂԂƏ�����ԕύX
	retVal=SetGraphMode(screenNew.width, screenNew.height, bitNumNew);
	if(retVal==DX_CHANGESCREEN_OK){
		sprintf_s(message, 100, "�ݒ�ł��܂����B�ύX�O�Fw=%d�Ah=%d�@�ύX��Fw=%d�Ah=%d",
			screenOld.width, screenOld.height, screenNew.width, screenNew.height);
	}else{
		sprintf_s(message, 100, "�ݒ�Ɏ��s���܂����B�ύX�O�Fw=%d�Ah=%d�@�ύX��Fw=%d�Ah=%d",
			screenOld.width, screenOld.height, screenNew.width, screenNew.height);
	}
	textColor=GetColor(255, 255, 255);
	DrawString(messagePos.x, messagePos.y, message, textColor);
	ScreenFlip();
	WaitKey();
	DxLib_End();
	return 0; 
}
