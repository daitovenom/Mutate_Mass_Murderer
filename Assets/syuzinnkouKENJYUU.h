

#ifndef DEF_syuzinnkouKENJYUU_H //��dinclude�h�~

#define DEF_syuzinnkouKENJYUU_H



void KENJYUU() {
	//LEFTmark = 44444;
	if (migimuki == 1) {
		if (Gtime == 5) {
			playerHPlock = 1;//��l����HP��200�ȉ��̎���1�ɂȂ邱�Ƃŏe�����摜���m����Ԃ̉摜�ɏ㏑������Ȃ��B
			zannzoulock = 1;
			playerKENJYUUImage = playerKENJYUU[0]; //���������̏�Ԃɂ���
		}
		if (Gtime == 10) {
			playerKENJYUUImage = playerKENJYUU[1]; //���������̏�Ԃɂ���
		}
		if (Gtime == 15) {
			playerKENJYUUImage = playerKENJYUU[2]; //���������̏�Ԃɂ���
		}
		if (Gtime == 20) {
			playerKENJYUUImage = playerKENJYUU[3]; //���������̏�Ԃɂ���
		}
		if (Gtime == 30) {
			playerKENJYUUImage = playerKENJYUU[4]; //���������̏�Ԃɂ���
			playerHPlock = 0;

		}
	}

	if (hidarimuki == 1) {
		if (Gtime == 5) {
			playerHPlock = 1;//��l����HP��200�ȉ��̎���1�ɂȂ邱�Ƃŏe�����摜���m����Ԃ̉摜�ɏ㏑������Ȃ��B
			zannzoulock = 1;
			playerKENJYUUImage = playerKENJYUUhidari[0]; //���������̏�Ԃɂ���
		}
		if (Gtime == 10) {
			playerKENJYUUImage = playerKENJYUUhidari[1]; //���������̏�Ԃɂ���
		}
		if (Gtime == 15) {
			playerKENJYUUImage = playerKENJYUUhidari[2]; //���������̏�Ԃɂ���
		}
		if (Gtime == 20) {
			playerKENJYUUImage = playerKENJYUUhidari[3]; //���������̏�Ԃɂ���
		}
		if (Gtime == 30) {
			playerKENJYUUImage = playerKENJYUUhidari[4]; //���������̏�Ԃɂ���
			playerHPlock = 0;

		}
	}

	if (Gtime >= 39) {
		
		Gtime = 0; //�e�������Ă���̌o�ߎ��Ԃ�0�ɖ߂�
		//DrawExtendGraph(0, 0, 1770, 980, SHOTHandle, FALSE);
		
		//nanameidouX = 0;�����ɏ����������Ă��������B
		nextattack = 0;
		KENJYUUgazou = 0;
		zannzoulock = 0;
		//playerHPlock = 0;
		tabakosuenai = 0;
	}
	if (Gtime > 0 && playerHPsubun == 0 && playerkonntororulock == 0 && playerHP > 0) {
		
		DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 - 13 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerKENJYUUImage, TRUE);
	}
}

#endif