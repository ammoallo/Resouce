			for(i=0; i<10; i++){
				player.pos.y-=4;
				DrawBox(0, 0, 640, 480, bgColor, TRUE);
				DrawRotaGraph2((int)player.pos.x, (int)player.pos.y, player.imageSize.width/2, player.imageSize.height/2, 1.0, 0.0, player.image, TRUE, player.isLeft);
				ScreenFlip();
			}
			for(i=0; i<10; i++){
				player.pos.y+=4;
				DrawBox(0, 0, 640, 480, bgColor, TRUE);
				DrawRotaGraph2((int)player.pos.x, (int)player.pos.y, player.imageSize.width/2, player.imageSize.height/2, 1.0, 0.0, player.image, TRUE, player.isLeft);
				ScreenFlip();
			}
