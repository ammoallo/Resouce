BOOL CollisionDetection(struct POINT2DF circleCenter, int r, struct POINT2DF segStart, struct POINT2DF segEnd)
{
	float dsq;
	BOOL hitFlag;
	VECTOR2DF v[3];

	v[0].x=circleCenter.x-segStart.x; v[0].y=circleCenter.y-segStart.y; // �~�̒��S�Ɛ����̎n�_�����ԃx�N�g��
	v[1].x=segEnd.x-segStart.x; v[1].y=segEnd.y-segStart.y; // �ǃx�N�g��
	v[2].x=circleCenter.x-segEnd.x; v[2].y=circleCenter.y-segEnd.y;  // �~�̒��S�Ɛ����̏I�_�����ԃx�N�g��

	dsq=(v[0].x*v[1].y-v[0].y*v[1].x)*(v[0].x*v[1].y-v[0].y*v[1].x)/(v[1].x*v[1].x+v[1].y*v[1].y);

	if(dsq>r*r)
		// r���͂��Ă��Ȃ�
		return FALSE;
	else{
		hitFlag=TRUE; // ���������Ɖ��肵�A�������Ă��Ȃ����Ƃ��m�F������FALSE�ɂ���
		if(v[0].x*v[1].x+v[0].y*v[1].y>0){
			// theta1�͉s�p
			if(v[2].x*(-v[1].x)+v[2].y*(-v[1].y)<0){
				// theta2�͓݊p
				hitFlag=FALSE;
			}
		}else{
			// theta1�͓݊p
			hitFlag=FALSE;
		}

		return hitFlag;
	}
}