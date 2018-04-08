#include "DxLib.h"
struct POINT2D{ // 座標を表す
    int x;
    int y;
};
struct VECTOR2D{ // 移動量を表す
    int x;
    int y;
};
struct CHARADATA{
    struct VECTOR2D move;
    struct POINT2D pos;
    int r;
    int color;
    int life; // 寿命という概念を導入、1なら生存、0なら消滅
};
int WINAPI WinMain(HINSTANCE hI, HINSTANCE hP, LPSTR lpC, int nC)
{
    char keyBuf[256];
    struct CHARADATA shot;
    ChangeWindowMode(TRUE);
    if(DxLib_Init() == -1)
        return -1;
    SetDrawScreen(DX_SCREEN_BACK);
	
	// ここから追加

    DxLib_End();
    return 0; 
}
