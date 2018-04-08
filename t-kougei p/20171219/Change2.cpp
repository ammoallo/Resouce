BOOL CollisionDetection(struct POINT2DF circleCenter, int r, struct POINT2DF segStart, struct POINT2DF segEnd)
{
	float dsq;
	BOOL hitFlag;
	VECTOR2DF v[3];

	v[0].x=circleCenter.x-segStart.x; v[0].y=circleCenter.y-segStart.y; // 円の中心と線分の始点を結ぶベクトル
	v[1].x=segEnd.x-segStart.x; v[1].y=segEnd.y-segStart.y; // 壁ベクトル
	v[2].x=circleCenter.x-segEnd.x; v[2].y=circleCenter.y-segEnd.y;  // 円の中心と線分の終点を結ぶベクトル

	dsq=(v[0].x*v[1].y-v[0].y*v[1].x)*(v[0].x*v[1].y-v[0].y*v[1].x)/(v[1].x*v[1].x+v[1].y*v[1].y);

	if(dsq>r*r)
		// rが届いていない
		return FALSE;
	else{
		hitFlag=TRUE; // 当たったと仮定し、当たっていないことが確認されればFALSEにする
		if(v[0].x*v[1].x+v[0].y*v[1].y>0){
			// theta1は鋭角
			if(v[2].x*(-v[1].x)+v[2].y*(-v[1].y)<0){
				// theta2は鈍角
				hitFlag=FALSE;
			}
		}else{
			// theta1は鈍角
			hitFlag=FALSE;
		}

		return hitFlag;
	}
}
