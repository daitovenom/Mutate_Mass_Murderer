

#ifndef DEF_syuzinnkouKENJYUU_H //��dinclude�h�~

#define DEF_syuzinnkouKENJYUU_H



void KENJYUU() {
	
	if (migimuki == 1) {
		if (Gtime == 5) {
			playerHPlock = 1;//��l����HP��200�ȉ��̎���1�ɂȂ邱�Ƃŏe�����摜���m����Ԃ̉摜�ɏ㏑������Ȃ��B
			zannzoulock = 1;
			point = 45;
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

	//playerkonntororulock == 0 �������Ă������G�����b�N�}�[�N����Ǝ�l���������Ȃ��Ȃ邽�߃��b�N�I����Ԃŏe��`��ł��Ȃ������B
	//�Ȃ̂œG�����b�N�I�����Ă���̌��U���ɂ�playerkonntororulock=1�Ƃ������`��̏�����playerkonntororulock�����Ȃ������B
	//�܂��Aplayerkonntororulock == 1�Ƃ�����������������@�����邪�����̓V���v���Ȃق��������̂ŏ����Ȃ������B

	// playerHPsubun�ɂ��Ă͓G����U�����󂯂��ۂ͏e�摜���`�悳��Ȃ��悤�ɂ��邽�߂� playerHPsubun == 0�Ƃ����B
	if (Gtime > 0 && playerHPsubun == 0 &&  playerHP > 0) {
		
		DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 - 13 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerKENJYUUImage, TRUE);
	}
}

#endif