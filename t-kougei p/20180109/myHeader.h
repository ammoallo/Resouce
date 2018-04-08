#include "DxLib.h"

// インクルードガード
#ifndef __MY_HEADER_H_
#define __MY_HEADER_H_

struct POINT2D{
	int x;
	int y;
};
struct POINT2DF{
	float x;
	float y;
};
struct VECTOR2DF{
	float x;
	float y;
};
struct MYRECT{
	int width;
	int height;
};

BOOL CollisionDetection(struct POINT2DF circleCenter, int r, struct POINT2DF segStart, struct POINT2DF segEnd);

#endif
