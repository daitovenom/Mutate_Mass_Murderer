

#ifndef DEF_syuzinnkouKENJYUU_H //“ñdinclude–hŽ~

#define DEF_syuzinnkouKENJYUU_H



void KENJYUU() {
	
	if (migimuki == 1) {
		if (Gtime == 5) {
			playerHPlock = 1;//ŽålŒö‚ÌHP‚ª200ˆÈ‰º‚ÌŽž‚É1‚É‚È‚é‚±‚Æ‚Åe‚ðŒ‚‚Â‰æ‘œ‚ª•mŽ€ó‘Ô‚Ì‰æ‘œ‚Éã‘‚«‚³‚ê‚È‚¢B
			zannzoulock = 1;
			point = 45;
			playerKENJYUUImage = playerKENJYUU[0]; //¶‰¡Œü‚«‚Ìó‘Ô‚É‚·‚é
		}
		if (Gtime == 10) {
			playerKENJYUUImage = playerKENJYUU[1]; //¶‰¡Œü‚«‚Ìó‘Ô‚É‚·‚é
		}
		if (Gtime == 15) {
			playerKENJYUUImage = playerKENJYUU[2]; //¶‰¡Œü‚«‚Ìó‘Ô‚É‚·‚é
		}
		if (Gtime == 20) {
			playerKENJYUUImage = playerKENJYUU[3]; //¶‰¡Œü‚«‚Ìó‘Ô‚É‚·‚é
		}
		if (Gtime == 30) {
			playerKENJYUUImage = playerKENJYUU[4]; //¶‰¡Œü‚«‚Ìó‘Ô‚É‚·‚é
			playerHPlock = 0;

		}
	}

	if (hidarimuki == 1) {
		if (Gtime == 5) {
			playerHPlock = 1;//ŽålŒö‚ÌHP‚ª200ˆÈ‰º‚ÌŽž‚É1‚É‚È‚é‚±‚Æ‚Åe‚ðŒ‚‚Â‰æ‘œ‚ª•mŽ€ó‘Ô‚Ì‰æ‘œ‚Éã‘‚«‚³‚ê‚È‚¢B
			zannzoulock = 1;
			playerKENJYUUImage = playerKENJYUUhidari[0]; //¶‰¡Œü‚«‚Ìó‘Ô‚É‚·‚é
		}
		if (Gtime == 10) {
			playerKENJYUUImage = playerKENJYUUhidari[1]; //¶‰¡Œü‚«‚Ìó‘Ô‚É‚·‚é
		}
		if (Gtime == 15) {
			playerKENJYUUImage = playerKENJYUUhidari[2]; //¶‰¡Œü‚«‚Ìó‘Ô‚É‚·‚é
		}
		if (Gtime == 20) {
			playerKENJYUUImage = playerKENJYUUhidari[3]; //¶‰¡Œü‚«‚Ìó‘Ô‚É‚·‚é
		}
		if (Gtime == 30) {
			playerKENJYUUImage = playerKENJYUUhidari[4]; //¶‰¡Œü‚«‚Ìó‘Ô‚É‚·‚é
			playerHPlock = 0;

		}
	}

	if (Gtime >= 39) {
		
		Gtime = 0; //e‚ðŒ‚‚Á‚Ä‚©‚ç‚ÌŒo‰ßŽžŠÔ‚ð0‚É–ß‚·
		//DrawExtendGraph(0, 0, 1770, 980, SHOTHandle, FALSE);
		
		//nanameidouX = 0;šŒã‚ë‚É­‚µ‰º‚ª‚Á‚Ä‚¢‚½Œ´ˆöB
		nextattack = 0;
		KENJYUUgazou = 0;
		zannzoulock = 0;
		//playerHPlock = 0;
		tabakosuenai = 0;
	}

	//playerkonntororulock == 0 ‚à“ü‚Á‚Ä‚¢‚½‚ª“G‚ðƒƒbƒNƒ}[ƒN‚·‚é‚ÆŽålŒö‚ª“®‚¯‚È‚­‚È‚é‚½‚ßƒƒbƒNƒIƒ“ó‘Ô‚Åe‚ð•`‰æ‚Å‚«‚È‚©‚Á‚½B
	//‚È‚Ì‚Å“G‚ðƒƒbƒNƒIƒ“‚µ‚Ä‚©‚ç‚ÌŒ‚‚ÂUŒ‚‚É‚Íplayerkonntororulock=1‚Æ‚µ‚½‚ª•`‰æ‚ÌðŒ‚Éplayerkonntororulock‚ð“ü‚ê‚È‚©‚Á‚½B
	//‚Ü‚ Aplayerkonntororulock == 1‚Æ‚¢‚¤ðŒ‚ð‰Á‚¦‚é•û–@‚à‚ ‚é‚ªðŒ‚ÍƒVƒ“ƒvƒ‹‚È‚Ù‚¤‚ª‚¢‚¢‚Ì‚Å‘‚©‚È‚ ‚Á‚½B

	// playerHPsubun‚É‚Â‚¢‚Ä‚Í“G‚©‚çUŒ‚‚ðŽó‚¯‚½Û‚Íe‰æ‘œ‚ª•`‰æ‚³‚ê‚È‚¢‚æ‚¤‚É‚·‚é‚½‚ß‚É playerHPsubun == 0‚Æ‚µ‚½B
	if (Gtime > 0 && playerHPsubun == 0 &&  playerHP > 0) {
		
		DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 - 13 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerKENJYUUImage, TRUE);
	}
}

#endif