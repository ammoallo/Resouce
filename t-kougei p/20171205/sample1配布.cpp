#include "DxLib.h"
struct POINT2D{ // ���W��\��
    int x;
    int y;
};
struct VECTOR2D{ // �ړ��ʂ�\��
    int x;
    int y;
};
struct CHARADATA{
    struct VECTOR2D move;
    struct POINT2D pos;
    int r;
    int color;
    int life; // �����Ƃ����T�O�𓱓��A1�Ȃ琶���A0�Ȃ����
};
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
    char keyBuf[256];
    struct CHARADATA shot;
    ChangeWindowMode(TRUE);
    if(DxLib_Init() == -1)
        return -1;
    SetDrawScreen(DX_SCREEN_BACK);
	
	// ��������ǉ�

    DxLib_End();
    return 0; 
}
