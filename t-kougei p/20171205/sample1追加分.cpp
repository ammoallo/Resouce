	shot.life=FALSE;
	while(ProcessMessage()==0){
		GetHitKeyStateAll(keyBuf);
		if(keyBuf[KEY_INPUT_ESCAPE]==1)
			break;
		if(keyBuf[KEY_INPUT_Z]==1){
			if(!shot.life){  // shot.life==0と同義
				shot.life=TRUE;
				shot.pos.x=320;
				shot.pos.y=240;
				shot.move.x=3;
				shot.r=4;
				shot.color=GetColor(255, 255, 255);
			}
		}
		DrawBox(0, 0, 640, 480, GetColor(0, 0, 0), TRUE);
		if(shot.life){
			shot.pos.x+=shot.move.x;
			if(shot.pos.x>640+shot.r)  // +shot.rの符号に注意、-ではない
				shot.life=FALSE;
			else
				DrawCircle(shot.pos.x, shot.pos.y, shot.r, shot.color, TRUE);
		}
		ScreenFlip();
	}
