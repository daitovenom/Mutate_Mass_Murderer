

#ifndef DEF_kasurikougeki_H //��dinclude�h�~

#define DEF_kasurikougeki_H

void kasurikougeki() {
	if (kougekikannkakulock == 0) {
		if (playerkonntororulock == 0) {
			if (attackframe == 0) {

				if (migimuki == 1) {
					if (Pad[PAD_2] == 1 && sousakanou == 0 && nextattack == 0 && kougekiKANOU == 0 && Pad[PAD_6] == 0) {
						
						lock = 0;//�ړ��{�^���������Ȃ��悤�ɁB
						//LEFTmark = 9;
						R1lock = 1;//�ēx�����Ă�Œ���R1�������āA�U�����̍��W��ۑ����Ȃ����߂�1�Ƃ����B
						//enemysabunHP = 20;
						stayherelock = 1;//���G��HP�\�����������߂ɕK�v�ȕϐ��B
						//addattacktime = 300;//��s���͂ŃR���{�����܂������̂��߂̃A�h�A�^�b�N�^�C���B
						++attackframe;
						//nagurusound = LoadSoundMem("���鉹.mp3");
						//PlaySoundMem(nagurusound, DX_PLAYTYPE_BACK);
						nagurugazou = 1;
						//kougekiKANOU = 1;
						//�ǉ��ŉ���Ƃ��ɃR���{�̉摜��������悤�ɁB
						//KONNBO1A = 1;
						//KONNBO1B = 0;
						//zannzoulock = 0;
						//++nagurucount;
						//pos[playerY][playerX][0] = playerkougekiXzahyou - 100;
						//pos[playerY][playerX][1] = playerkougekiYzahyou;
						konnbokakuninn = 1;
						nagurukasanaru = 1;

						enemykougekilock = 1;

						playerHPlock = 1;//����Ƃ��Ƀ_���[�W�𕉂�����Ԃ̉摜��`�悵�Ȃ����߂̕��B

						tabakolock = 1;//���b�N���̓^�o�R���z���Ȃ��悤��1�ɂ���B

						//playerattackhanndou = playerattackhanndou + 10;

						//motonomasunimodoru = 10;//�R���{�����܂�ƈ��̒l�ɂȂ�悤�ɂ����B

						//if (GetRand(10) < 8) {
						//	playerattackhanndou2 = playerattackhanndou2 + 60;
						//}
						//playerHPlock = 1;//�U�����̓_���[�W��ǂ�����Ԃ̉摜��`�悵�Ȃ��悤�ɂ��邽�߂�1�Ƃ���B
						zannzoulock = 1;
						nextattack = 1;
					}
				}
				else if (hidarimuki == 1) {
					if (Pad[PAD_2] == 1 && sousakanou == 0 && nextattack == 0 && kougekiKANOU == 0 && Pad[PAD_6] == 0) {

						lock = 0;//�ړ��{�^���������Ȃ��悤�ɁB
						//LEFTmark = 9;
						R1lock = 1;//�ēx�����Ă�Œ���R1�������āA�U�����̍��W��ۑ����Ȃ����߂�1�Ƃ����B
						//enemysabunHP = 20;
						stayherelock = 1;//���G��HP�\�����������߂ɕK�v�ȕϐ��B
						//addattacktime = 300;//��s���͂ŃR���{�����܂������̂��߂̃A�h�A�^�b�N�^�C���B
						++attackframe;
						//nagurusound = LoadSoundMem("���鉹.mp3");
						//PlaySoundMem(nagurusound, DX_PLAYTYPE_BACK);
						nagurugazou = 1;
						//kougekiKANOU = 1;
						//�ǉ��ŉ���Ƃ��ɃR���{�̉摜��������悤�ɁB
						//KONNBO1A = 1;
						//KONNBO1B = 0;
						//zannzoulock = 0;
						//++nagurucount;
						//pos[playerY][playerX][0] = playerkougekiXzahyou - 100;
						//pos[playerY][playerX][1] = playerkougekiYzahyou;
						konnbokakuninn = 1;
						nagurukasanaru = 1;

						enemykougekilock = 1;

						playerHPlock = 1;//����Ƃ��Ƀ_���[�W�𕉂�����Ԃ̉摜��`�悵�Ȃ����߂̕��B

						tabakolock = 1;//���b�N���̓^�o�R���z���Ȃ��悤��1�ɂ���B

						//playerattackhanndou = playerattackhanndou + 10;

						//motonomasunimodoru = 10;//�R���{�����܂�ƈ��̒l�ɂȂ�悤�ɂ����B

						//if (GetRand(10) < 8) {
						//	playerattackhanndou2 = playerattackhanndou2 + 60;
						//}
						//playerHPlock = 1;//�U�����̓_���[�W��ǂ�����Ԃ̉摜��`�悵�Ȃ��悤�ɂ��邽�߂�1�Ƃ���B
						zannzoulock = 1;
						nextattack = 1;
					}
				}




			}
			//�A���ŉ���ꍇ�̃v���O�����B//1���傫�����͌J��オ��A30��菬�����Ԃ�{}������B
			if (attackframe > 0 && ++attackframe < 80) {
				if (attackframe > 35 && attackframe < 80) {//���̊ԂɃ{�^���������ƘA���U���Ɉڂ�B
					if (Pad[PAD_2] == 1 && sousakanou == 0 && nextattack == 0 && attackframeA == 0 && kougekiKANOU == 0) {
						attackframeA = 1;
						nagurugazou = 0;
						++nagurugazou2;
					}
				}
			}
			if (attackframe > 80) {//�R���{�����܂�Ȃ������ꍇ�ő������ɖ߂�ƁA���ɃR���{�����܂����ۂɂ����̃t���[����50�Ƃ�����
				//�R���{���I�������ɏ�̃{�^�����܂������Ă��܂��A��i�ڂ̋Z���A���ŏo�Ă��Ă��܂��B
				//�Ȃ̂ł����ł̓R���{�����܂�����ɂ��������������邱�ƂŘA���œ�i�ڂ̍U�����A���łł��Ȃ��悤�ɂ����B
				//�܂����邢�́A��̃t���[���������ƒZ������100�ł͂Ȃ��A50�Ƃ��ɂ��Ă������ł��邩������Ȃ��B
				//�����ł��邪�A50�͒Z�����邽�ߘA���������̂�������炱��ł����B
				attackframe = 0;
				attackframeA = 0;
			}





			if (migimuki == 1) {
				//����U���̉摜�����������B//���z��̂܂܂ł͒l���ۂĂȂ����߁AlockImge = lockonHandle[1]�̂悤Image�ł܂Ƃ߂ď����Ȃ��Ƃ����Ȃ��̂����B
				if (nagurugazou > 0) {//�`��֐��ɂ��̂܂�playernaguruAGHandle[0]���Ԃ�����ŏ�����==�̎������`�悳��Ȃ��B
					//���`��֐����g����==�̕��@�ŏ����Ă��������Aif (nagurugazou>0&& nagurugazou<20)�Ɣ͈͂ŏ������ق�����������Ȃ��B
					++nagurugazou;
					//zannzoulock = 1;//�U���摜���łĂ�Ƃ��͒ʏ�̉摜�������̂Œl��1�ɕύX����B
					tabakolock = 1;//�������钆�̓^�o�R���z������A��l���������Ă��Ȃ��ۂ��`�悳���悤�ɂ��邽�߂ɂ�����tabakokirikae��1�ɂ���B
					DrawRotaGraph(pos[playerY][playerX][0] + 20 + (70) + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playernaguruImage, TRUE);
					tabakosutterulock = 1;


					Xbotannlock = 1;//�{�^���̘A�ł�����ƌ����Ԃ��̉摜�ɓ��B����O�ɉ摜���؂�ւ��̂ŁA�A�łł��Ȃ��悤�ɂ��邽�߂̕ϐ��B
				}if (nagurugazou > 0 && nagurugazou < 20) {//����t���[���͂��ꂭ�炢�ł���
					playernaguruImage = playernaguruAGHandle[0];
					//StartJoypadVibration(DX_INPUT_PAD1, 400, 200);
				}
				if (nagurugazou > 20 && nagurugazou < 35) {
					playernaguruImage = playernaguruBGHandle[0];
				}
				if (nagurugazou2 > 0) {
					nagurugazou = 0;//�񔭖ڂ�łƂ��͈ꔭ�ڂ��`�悳��Ȃ��悤�ɏ����B
					playerHPlock = 1;
					++nagurugazou2;
					zannzoulock = 1;//�U���摜���łĂ�Ƃ��͒ʏ�̉摜�������̂Œl��1�ɕύX����B
					tabakolock = 1;//�������钆�̓^�o�R���z������A��l���������Ă��Ȃ��ۂ��`�悳���悤�ɂ��邽�߂ɂ�����tabakokirikae��1�ɂ���B

					//�����͂���Ȃ�if (nagurugazou2 > 0 && nagurugazou2 < 30)�ŏ����Ă���̂�
					//DrawRotaGraph(pos[playerY][playerX][0] + 20 + (70) + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playernaguruImage, TRUE);
					tabakosutterulock = 1;

				}

				//�{�f�[�u���[�̕`��B
				if (nagurugazou2 > 0 && nagurugazou2 < 30) {
					playernaguruImage = playernaguruBGHandle2[0];
					DrawRotaGraph(pos[playerY][playerX][0] + 20 + (70) + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playernaguruImage, TRUE);


				}
				if (nagurugazou2 > 30 && nagurugazou2 < 60) {

					if (nagurugazou2 > 58 && nagurugazou2 < 60)
					{
						//enemysabunHP = 20;
					}//����̓񔭖ڂ̍U��


					playernaguruImage = playernaguruBGHandle3[0];
					DrawRotaGraph(pos[playerY][playerX][0] + 20 + (70) + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playernaguruImage, TRUE);


				}

				//�X�e�[�W1�̘V�k�ƃX�e�[�W2�̂ӂ���������鉣��v���O�����̑���//
				if (nagurugazou > 35) {
					nagurugazou = 0;
					zannzoulock = 0;
					Xbotannlock = 0;
					tabakolock = 0;
					playerHPlock = 0;
					//playermovelock = 0;//�o�O�΍�̂��߂ɂ�����0�ɂ���B
					tabakosutterulock = 0;
					nextattack = 0;//������0�ɂȂ��Ă��邽�߃A�b�p�[�ł�if����0�ŗǂ��̂��B
					//if (playerHP < 400) {
					//	playerHPlock = 0;//HP�����Ȃ��ۂɌ��̈ʒu�ɖ߂�ۂɃ_���[�W����̒ʏ��Ԃɖ߂�B
					//}
					//kougekikannkaku = 0;
					attackframeA = 0;//�@
				}
				if (nagurugazou2 > 60) {
					attackframe = 0;//��attackframe��80�𒴂���O�ɓ񔭖ڂ̃p���`��0�ɂȂ��Ă��܂��AattackframeA��1�̂܂܂ɂȂ�̂�
					//��̇@��0�ɂ���B
					nagurugazou = 0;
					nagurugazou2 = 0;
					zannzoulock = 0;
					Xbotannlock = 0;
					tabakolock = 0;
					playerHPlock = 0;
					//playermovelock = 0;//�o�O�΍�̂��߂ɂ�����0�ɂ���B
					tabakosutterulock = 0;
					nextattack = 0;

				}

				//�X�e�[�W2�̒j��l�ɑ΂���񔭖ڂ̂����鉣��U��//

				//��l�ڂւ̉���U��
				if (kougekiKANOU == 2 && stage2damage == 1) {
					if (nagurugazou2 > 58 && nagurugazou2 < 60) {
						//nagurusound = LoadSoundMem("���鉹.mp3");
						//PlaySoundMem(nagurusound, DX_PLAYTYPE_BACK);
						//nanameidouX = nanameidouX + 20;
						enemysabunHP = 30;
						playerHPlock = 0;
						playerattackhanndou = playerattackhanndou + 30;//�G�����ɐi��
						enemyzannzoulockframe1 = 1;//����̃_���[�W��H������ۂ̋��݂������ɖ߂�����
						stayhereframe = 1;
						bloodMove = 1;
						kakuninn = 1;
					}
				}//������l�ւ̉���U���B
				if (kougekiKANOU == 3 && stage2damage == 1) {
					if (nagurugazou2 > 58 && nagurugazou2 < 60) {
						//nagurusound = LoadSoundMem("���鉹.mp3");
						//PlaySoundMem(nagurusound, DX_PLAYTYPE_BACK);
						//nanameidouX = nanameidouX + 20;
						anotherenemysabunHP = 30;
						playerHPlock = 0;
						playerattackhanndouB = playerattackhanndouB + 30;//�G�����ɐi��
						enemyzannzoulockBframe = 1;//����̃_���[�W��H������ۂ̋��݂������ɖ߂�����
						stayhere2frame = 1;
						bloodMove = 1;
					}
				}



			}


			//�X�e�[�W1�̘V�k�Ɛ����̓G�ƐԂ����̓G�ɑ΂��鍶�����Ƀ{�f�[�u���[����U��//
			if (hidarimuki == 1) {
				//����U���̉摜�����������B//���z��̂܂܂ł͒l���ۂĂȂ����߁AlockImge = lockonHandle[1]�̂悤Image�ł܂Ƃ߂ď����Ȃ��Ƃ����Ȃ��̂����B
				if (nagurugazou > 0) {//�`��֐��ɂ��̂܂�playernaguruAGHandle[0]���Ԃ�����ŏ�����==�̎������`�悳��Ȃ��B
					//���`��֐����g����==�̕��@�ŏ����Ă��������Aif (nagurugazou>0&& nagurugazou<20)�Ɣ͈͂ŏ������ق�����������Ȃ��B
					++nagurugazou;
					//zannzoulock = 1;//�U���摜���łĂ�Ƃ��͒ʏ�̉摜�������̂Œl��1�ɕύX����B
					tabakolock = 1;//�������钆�̓^�o�R���z������A��l���������Ă��Ȃ��ۂ��`�悳���悤�ɂ��邽�߂ɂ�����tabakokirikae��1�ɂ���B
					DrawRotaGraph(pos[playerY][playerX][0] + 20 + (30) + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playernaguruImage, TRUE);
					tabakosutterulock = 1;
					point = 12;

					Xbotannlock = 1;//�{�^���̘A�ł�����ƌ����Ԃ��̉摜�ɓ��B����O�ɉ摜���؂�ւ��̂ŁA�A�łł��Ȃ��悤�ɂ��邽�߂̕ϐ��B
				}if (nagurugazou > 0 && nagurugazou < 20) {//����t���[���͂��ꂭ�炢�ł���
					playernaguruImage = playernaguruAGHandleB[0];
					//StartJoypadVibration(DX_INPUT_PAD1, 400, 200);
				}
				if (nagurugazou > 20 && nagurugazou < 35) {
					playernaguruImage = playernaguruBGHandleB[0];
				}
				if (nagurugazou2 > 0) {
					nagurugazou = 0;//�񔭖ڂ�łƂ��͈ꔭ�ڂ��`�悳��Ȃ��悤�ɏ����B
					playerHPlock = 1;
					++nagurugazou2;//��������U���̌�ɂ����ŉ��邪�オ���Ă��܂����炩����U���Ȃ̂Ƀ_���[�W���͂����Ă��܂��H
					zannzoulock = 1;//�U���摜���łĂ�Ƃ��͒ʏ�̉摜�������̂Œl��1�ɕύX����B
					tabakolock = 1;//�������钆�̓^�o�R���z������A��l���������Ă��Ȃ��ۂ��`�悳���悤�ɂ��邽�߂ɂ�����tabakokirikae��1�ɂ���B

					//�����͂���Ȃ�if (nagurugazou2 > 0 && nagurugazou2 < 30)�ŏ����Ă���̂�
					//DrawRotaGraph(pos[playerY][playerX][0] + 20 + (30) + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playernaguruImage, TRUE);
					tabakosutterulock = 1;

				}
				if (nagurugazou2 > 0 && nagurugazou2 < 30) {
					playernaguruImage = playernaguruBGHandle2B[0];
					DrawRotaGraph(pos[playerY][playerX][0] + 20 + (30) + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playernaguruImage, TRUE);


				}
				if (nagurugazou2 > 30 && nagurugazou2 < 60) {
					if (nagurugazou2 > 58 && nagurugazou2 < 60)
					{
						//enemysabunHP = 20;//�����ł����肩����U���ŏオ����nagurugazou2�ɂ�蔽������
						//������U���Ȃ̂Ƀ_���[�W��^���Ă��܂��Ă����B
						point2 = 18;
					}//����̓񔭖ڂ̍U��

					playernaguruImage = playernaguruBGHandle3B[0];
					DrawRotaGraph(pos[playerY][playerX][0] + 20 + (30) + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playernaguruImage, TRUE);

					
				}
				if (kougekiKANOU == 2) {
					if (nagurugazou2 > 58 && nagurugazou2 < 60) {
						//nagurusound = LoadSoundMem("���鉹.mp3");
						//PlaySoundMem(nagurusound, DX_PLAYTYPE_BACK);
						//nanameidouX = nanameidouX + 20;
						//enemysabunHP = 30;
						playerHPlock = 0;
						playerattackhanndou = playerattackhanndou - 30;//�G�����ɐi��
						enemyzannzoulockframe1 = 1;//����̃_���[�W��H������ۂ̋��݂������ɖ߂�����
						stayhereframe = 1;
						bloodMove = 1;
						kakuninn = 2;
					}
				}
				if (nagurugazou > 35) {
					nagurugazou = 0;
					zannzoulock = 0;
					Xbotannlock = 0;
					tabakolock = 0;
					playerHPlock = 0;
					//playermovelock = 0;//�o�O�΍�̂��߂ɂ�����0�ɂ���B
					tabakosutterulock = 0;
					nextattack = 0;//������0�ɂȂ��Ă��邽�߃A�b�p�[�ł�if����0�ŗǂ��̂��B
					//if (playerHP < 400) {
					//	playerHPlock = 0;//HP�����Ȃ��ۂɌ��̈ʒu�ɖ߂�ۂɃ_���[�W����̒ʏ��Ԃɖ߂�B
					//}
					//kougekikannkaku = 0;
					attackframeA = 0;//�@
				}
				if (nagurugazou2 > 60) {
					nagurugazou = 0;
					attackframe = 0;//��attackframe��80�𒴂���O�ɓ񔭖ڂ̃p���`��0�ɂȂ��Ă��܂��AattackframeA��1�̂܂܂ɂȂ�̂�
					//��̇@��0�ɂ���B
					nagurugazou = 0;
					nagurugazou2 = 0;
					//������motonomasunimodoru ��0�ɂȂ�u�Ԃɉ�������Ă����zannzoulock�͂P�̂܂܂ɂȂ��Ă��܂��̂ŁA�����ŋ����I��0�ɂ���B
					//if (motonomasunimodoru == 0) {
					//	zannzoulock = 0;
					//}
					Xbotannlock = 0;
					tabakolock = 0;
					playerHPlock = 0;
					//playermovelock = 0;//�o�O�΍�̂��߂ɂ�����0�ɂ���B
					tabakosutterulock = 0;
					nextattack = 0;
					zannzoulock = 0;
				}
				if (nagurugazou2 > 35 && nagurugazou2 < 60) {
					zannzoulock = 1;
				}

			}



















			//���� && kougekilock == 1&& kougekiKANOU == 1��R1�������Ȃ��ꍇ�̎��͏�ɏ������悤��
			//R1lock��0�ɂȂ�̂ŁA�R���{���o���Ȃ��̂ő��̕ϐ�konnbokakuninn���g�����B
			//�ŏ�����R���{�o�Ȃ��ꍇ��R1lock��1�̂܂܂Ȃ̂ł��̂܂܃L�b�N�ł���B
			//Y�{�^������̃R���{�����߂邽�߂�Y�{�^������͂��镔��
			
				if (Pad[PAD_4] == 1 && sousakanou == 0 && nextattack == 0 && kougekiKANOU == 0) {
					R1lock = 1;
					lock = 0;//���b�N�}�[�N�������A�����b�N�}�[�N���ړ����āA�U������O�ɂȂ�U���{�^���������Ă���̂ɍU���ł��Ȃ�
					//���Ƃ�����邽�߂�0�ɂ��āAif (lock == 1)�������Ȃ���ɂ���B
					//pos[playerY][playerX][0] = playerkougekiXzahyou - 100;
					//pos[playerY][playerX][1] = playerkougekiYzahyou;
					//LEFTmark = 1000;
					//lockmark = 1;
					//lockonMove = 1;//�A�^�b�N���鎞�@���b�N�I���̉摜��������悤�ɒl��0�ɂ���B
					stayherelock = 1;//���G��HP�\�����������߂ɕK�v�ȕϐ��B
					//addattacktime = 300;//��s���͂ŃR���{�����܂������̂��߂̃A�h�A�^�b�N�^�C���B
					attackframe = 0;//�R���{�֕��򂷂�ۂɉ���Ȃǂ��łȂ��悤�ɃA�^�b�N�t���[��1��0�ɂ���B
					//sennkounyuuryokubunnki = 1;
					kougekilock = 1;////��s���͂ŃR���{�����܂������Ɍ�쓮��X�{�^���������Ă����邪�łȂ��悤�ɑ��̒l�ɂ���B
					zannzoulock = 1;

					KONNBO1A = 1;

					//kougekiKANOU = 1;

					nagurukasanaru = 0;
					KONNBO1kasanaru = 1;

					enemykougekilock = 1;

					playerHPlock = 1;//�L�b�N����Ƃ��Ƀ_���[�W�𕉂�����Ԃ̉摜��`�悵�Ȃ����߂̕��B
					playermovelock = 1;//������1�ɂ��Ȃ��ƃL�b�N�U���̉E�R�}���h�ƉE�ړ������Ⴂ���ĉE�Ɉړ����Ȃ���̃L�b�N�ɂȂ�̂ł�����1�ɂ��āA
					//�E�ړ��ł̃R���g���[���̉e�����󂯂Ȃ��悤�ɂ���B
					//motonomasunimodoru = 10;//�R���{�����܂�ƈ��̒l�ɂȂ�悤�ɂ����B
					kasurikeri = 1;
					nextattack = 1;
				}
			
			
			if (kasurikeri == 1 && kougekiKANOU == 0 && motonomasunimodoru > 0) {
				++attackframe2;
				//LEFTmark = 114;
				//�����̐�s���͂ɐ�������Ɖ���o�[�W����3�ɑ����B
				//�������̃t���[�������傤�ǂ����B



			}

			if (migimuki == 1) {
				if (attackframe2 > 0 && attackframe2 < 40 && kougekiKANOU == 0) {//����if (attackframe2 > 0 && attackframe2 < 15)�Ɣ��Ȃ��悤�ɂ���B
					if (Pad[PAD_RIGHT] == 1) {//�����̕��͍��͂����Ŕ������Ȃ��悤�ɏ����x�߂�9�ɂ��āA���ɒx�߂ɍ��͂͂����ŉE�����͂���Ă��������Ȃ��悤��15�Ƃ����B
						//LEFTmark = 514;
						//KONNBO1A = 0;//����グ�鎞�ɁA�R��O�̉摜��`�悵�Ȃ��悤�ɁB
						//enemysabunHPA = 70;//�ŏ��̕��ʂ̉���̍U����X�{�^�����������Ƃ̃R���{���Ȃ邽��
						//LEFTmark = 114514;//�`��p�ɍ������s���͂̊m�F�p�̕ϐ�
						LEFTmarklock = 1;//��s���͂��Ăтł���悤�ɂ���ɂ�X�{�^���ő�������邽�߂ɁA������1�Ƃ��āA�ǉ��̕���LEFTmarklock = 0�Ƃ����B
						//addattacktime = 300;
						attackframe = 0;//�U����ɒǉ���������Ȃ��Ă�1�Ƃ��Ă�����0���傫���̂ŃR���{���Ȃ���B�ǉ�����ō��R���{���q���Ă������B
						stayherelock = 1;//�G��HP���������߂ɕK�v�ȕϐ�
						//sennkounyuuryokubunnki = 1;//��if�����sennkounyuuryokubunnki==1�̎��łȂ��Ƃ�����if���͓����Ȃ��̂ŁAsennkounyuuryokubunnki��0�̎��͑O��if���̏����ɍ���Ȃ��̂�attackframe2���ł����Ă�����2�̍U���ł��Ȃ��͓̂��R�ł���B
						//attackframe2 = 0;//��s���͂̕����sennkounyuuryokubunnki2�ɍs���Ȃ������ꍇ��attackframe2�̒l��0�ɂȂ�悤�ɏ������B
						//naguru2sound = LoadSoundMem("damage01.m4a");
						//PlaySoundMem(naguru2sound, DX_PLAYTYPE_BACK);
						//sennkounyuuryokubunnki3 = 0;//�����̐�s���͂����������ۂ͑����ĉ���3���łȂ��悤�ɂ����̕ϐ���0�ɂ���B
						//attackframe3 = 150;//����s���͂����������ۂ͑����ĉ���3���łȂ��悤�ɉ���3�Ɉ����|����Ȃ��悤�ȕϐ��̒l�ɂ���B

						//kougekilock = 1;//�R���{���͂����������ۂɍĂуR���{�����߂����ۂɏ��Y�{�^����if����ʉ߂ł���悤��
						//kougekilock�̒l��1�ɂ���B

						KONNBO1A = 0;//�O�̏R��O�̉摜���������߂̕��B
						KONNBO1B = 1;//�R��グ��̉摜��`�悷�邽�߂̂���


						KONNBO1kasanaru = 0;
						KONNBO2kasanaru = 1;

						//motonomasunimodoru = 10;//�R���{�����܂�ƈ��̒l�ɂȂ�悤�ɂ����B
						//playerattackhanndou = playerattackhanndou + 30;
						//playermovelock = 0;

						attackframe2 = 0;
						kasurikeri = 0;
						//++attackframe3;
					}
					//sennkounyuuryokubunnki3 = 0;
					//attackframe3 = 0;//����2�o�[�W�������������Œl�����̂܂܂��ƉE�������������ŉ���o�[�W����3���ł��Ă��܂��̂ŁB
					//������2�ɕ��򂵂��ꍇ�͉���3�̏������ׂ�0�ɂ���B
					//attackframe = 0;//����2�������������邩�͕ʂɂ��̃t���[���̎��Ɉ�U0�ɂ����X�{�^������̃R���{���Ȃ���₷���B
				}

			}
			else if (hidarimuki == 1) {
				if (attackframe2 > 0 && attackframe2 < 40 && kougekiKANOU == 0) {//����if (attackframe2 > 0 && attackframe2 < 15)�Ɣ��Ȃ��悤�ɂ���B
					if (Pad[PAD_LEFT] == 1) {//�����̕��͍��͂����Ŕ������Ȃ��悤�ɏ����x�߂�9�ɂ��āA���ɒx�߂ɍ��͂͂����ŉE�����͂���Ă��������Ȃ��悤��15�Ƃ����B
						//LEFTmark = 514;
						//KONNBO1A = 0;//����グ�鎞�ɁA�R��O�̉摜��`�悵�Ȃ��悤�ɁB
						//enemysabunHPA = 70;//�ŏ��̕��ʂ̉���̍U����X�{�^�����������Ƃ̃R���{���Ȃ邽��
						//LEFTmark = 114514;//�`��p�ɍ������s���͂̊m�F�p�̕ϐ�
						LEFTmarklock = 1;//��s���͂��Ăтł���悤�ɂ���ɂ�X�{�^���ő�������邽�߂ɁA������1�Ƃ��āA�ǉ��̕���LEFTmarklock = 0�Ƃ����B
						//addattacktime = 300;
						attackframe = 0;//�U����ɒǉ���������Ȃ��Ă�1�Ƃ��Ă�����0���傫���̂ŃR���{���Ȃ���B�ǉ�����ō��R���{���q���Ă������B
						stayherelock = 1;//�G��HP���������߂ɕK�v�ȕϐ�
						//sennkounyuuryokubunnki = 1;//��if�����sennkounyuuryokubunnki==1�̎��łȂ��Ƃ�����if���͓����Ȃ��̂ŁAsennkounyuuryokubunnki��0�̎��͑O��if���̏����ɍ���Ȃ��̂�attackframe2���ł����Ă�����2�̍U���ł��Ȃ��͓̂��R�ł���B
						//attackframe2 = 0;//��s���͂̕����sennkounyuuryokubunnki2�ɍs���Ȃ������ꍇ��attackframe2�̒l��0�ɂȂ�悤�ɏ������B
						//naguru2sound = LoadSoundMem("damage01.m4a");
						//PlaySoundMem(naguru2sound, DX_PLAYTYPE_BACK);
						//sennkounyuuryokubunnki3 = 0;//�����̐�s���͂����������ۂ͑����ĉ���3���łȂ��悤�ɂ����̕ϐ���0�ɂ���B
						//attackframe3 = 150;//����s���͂����������ۂ͑����ĉ���3���łȂ��悤�ɉ���3�Ɉ����|����Ȃ��悤�ȕϐ��̒l�ɂ���B

						//kougekilock = 1;//�R���{���͂����������ۂɍĂуR���{�����߂����ۂɏ��Y�{�^����if����ʉ߂ł���悤��
						//kougekilock�̒l��1�ɂ���B

						KONNBO1A = 0;//�O�̏R��O�̉摜���������߂̕��B
						KONNBO1B = 1;//�R��グ��̉摜��`�悷�邽�߂̂���


						KONNBO1kasanaru = 0;
						KONNBO2kasanaru = 1;

						//motonomasunimodoru = 10;//�R���{�����܂�ƈ��̒l�ɂȂ�悤�ɂ����B
						//playerattackhanndou = playerattackhanndou + 30;
						//playermovelock = 0;

						attackframe2 = 0;
						kasurikeri = 0;
						//++attackframe3;
					}
					//sennkounyuuryokubunnki3 = 0;
					//attackframe3 = 0;//����2�o�[�W�������������Œl�����̂܂܂��ƉE�������������ŉ���o�[�W����3���ł��Ă��܂��̂ŁB
					//������2�ɕ��򂵂��ꍇ�͉���3�̏������ׂ�0�ɂ���B
					//attackframe = 0;//����2�������������邩�͕ʂɂ��̃t���[���̎��Ɉ�U0�ɂ����X�{�^������̃R���{���Ȃ���₷���B
				}

			}


			if (Pad[PAD_1] == 1 && motonomasunimodoru > 0 && kougekiKANOU == 0) {
				//zannzoulock = 1;
				//KONNBO1Aframe1 = 0;//������0�ɂ��邱�Ƃŕ`��̃L�b�N������O�̉摜��`��ł��Ȃ悤�ɂ����B
				KONNBO1A = 0;//�ʂ̃R���{�ɐi�񂾂��߁A�l��0�ɂ���B//���ӁA�܂��摜�����Ă��Ȃ��̂ŉ����\������Ȃ��B
				KONNBO1Aframe = 0;//������0�ɂ��邱�Ƃŕ`��̃L�b�N������O�̉摜��`��ł��Ȃ悤�ɂ����B
				KONNBO1Bframe = 0;
				//KONNBO1B = 0;//�ʂ̃R���{�ɐi�񂾂��߁A�l��0�ɂ���B//���ӁA�܂��摜�����Ă��Ȃ��̂ŉ����\������Ȃ��B
				sennkounyuuryokubunnki3 = 1;//�����̐�s���͂ɐ�������Ɖ���o�[�W����3�ɑ����B
				LEFTmark = 2;//�m�F�̂��߂ɁB
		//		addattacktime = 300;//���R���{�̂Ȃ��Ƃ��āA����3�̃R���{������ȉ߂���̂�����̂ŁB
				//��addattacktime = 50�ł͒Z���ē��͂���������attackframe3���オ���Ă�addattacktime��0�ɂȂ��Ă��܂����̃}�X�ɖ߂��Ă��܂�����3���o���Ȃ������B
				//sennkounyuuryokubunnki = 0;//����2�ɍs���Ȃ��l�ɂ��邽�߁B
				attackframe2 = 0;//����3�ɍs�����ۂɁAattackframe2��0�ɂȂ�悤�ɂ���B���R���{�̍ۂ͂ق��̃t���[���͊֌W�Ȃ��̂�0�ɂ���B
				attackframe3 = 1;

				nagurukasanaru = 0;
				KONNBO1kasanaru = 0;
				//	KONN0BO2kasanaru = 0;
				playerHPlock = 1;
			}


			if (sennkounyuuryokubunnki3 == 1 && kougekiKANOU == 0) {
				++attackframe3;//�����ƒl���オ���Ă���A
				//attackframe2 = 0;//�����̉���2�Ɉ����|����A����3����͂���ۂɉ���2���łȂ��悤�ɂ���B
				//attackframe3�̃t���[�����ɉE���͂���������Ή���3�o�[�W�������ł���B
				attackframe2 = 0;//�����ł̃A�^�b�N�t���[��2�͉���3�ɂ͊֌W�Ȃ��̂�0�ɂ���B
				//�����ɖ��͂Ȃ��B�����������Ă�attackframe3��300�ɍs���O�ɍ��̓��͂�attackframe3��0?�ɂȂ��Ă����B
				//�����OK�B
				playerHPlock = 1;

			}


			//��U��̓��̉摜�ł͂Ȃ��Z���o�������ł̃t���[�����B
			if (attackframe3 > 5 && attackframe3 < 100 && kougekiKANOU == 0) {//attackframe3>0����ɂ���ƑO�̍��ɂ͂����������ŉE���͂����Ă��܂��ŏ��̃t���[���͈̔͂ɔ������邱�ƂŁA�ȒP�ɃR���{���o����̂ŁA���ɂ͂����������ł͔������Ȃ��l�ɔ͈͂�attackframe3>20����ɂ����B����œ��͂��덷���Ȃ�����o�����B
				if (Pad[PAD_LEFT] == 1) {
					++attackframe4;
				}
			}

			if (attackframe4 > 0 && attackframe4 < 110 && kougekiKANOU == 0) {//attackframe3>0����ɂ���ƑO�̍��ɂ͂����������ŉE���͂����Ă��܂��ŏ��̃t���[���͈̔͂ɔ������邱�ƂŁA�ȒP�ɃR���{���o����̂ŁA���ɂ͂����������ł͔������Ȃ��l�ɔ͈͂�attackframe3>20����ɂ����B����œ��͂��덷���Ȃ�����o�����B
				if (Pad[PAD_RIGHT] == 1) {
					
					RIGHTmarklock = 1;
					//attackframe2 = 0;
					//enemysabunHPB = 300;
					lockmark = 1;
					//sinnzoubyouga = 1;
					//addattacktime = 300;
					//attackframe = 1;//�ǉ��̉���U�����ł���悤�ɂ�����1�ɖ߂��B
					attackframe3 = 0;//�ǉ��̉���U�����ł���悤�ɂ�����0�ɖ߂��B
					//attackframe4 = 0;
					++attackframe5;
					kougekilock = 1;
					stayherelock = 1;//�G��HP���������߂ɕK�v�ȕϐ�
					sennkounyuuryokubunnki3 = 0;//�Ăщ���2�Ȃǂ��ł���悤�ɂ��邽�߂ɂ�����0�ɂ���B
					//naguru3sound = LoadSoundMem("damage03.m4a");
					//PlaySoundMem(naguru3sound, DX_PLAYTYPE_BACK);
					//++attackframe4;
					//sennkounyuuryokubunnki = 0;//���ǉ��̉���U�����ł���悤�ɁB�ǉ�����Ɍq����ƁA�Ăщ���2�≣��3���ł��邽�߁B
					//ememydontmovetime = 1;
				}
			}
		}

	

	}
	//�U���͈͊O�ł̂����蔻��ł̍U���Ԋu�B
	//����5�t���[�����Ȃ�U���ł���B
	//if (kougekikannkaku2 > 0 && ++kougekikannkaku2 < 100) {
	//	playerkonntororulock = 1;//30�t���[���𒴂���܂ł͍U���ł��Ȃ��B//���̎��_��playerkonntororulock��1�ɂȂ�̂Ńv���C���[�h���E�C���O�w�b�_
	//	//�̏����ɍ��킸�A�c�����b�N���@�\���Ȃ��A�Ȃ̂ł����Ŏc�����b�N�����������B
	//	zannzoulock = 0;


	//}
	//if (kougekikannkaku2 > 100) {
	//	kougekikannkaku2 = 0;
	//}
}
#endif