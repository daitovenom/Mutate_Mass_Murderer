#include <time.h>

void Player_Update2() {
	//gpUpdateKey();  // �L�[�̓��͏�Ԃ��擾
	ranndamuBGM = GetRand(4000);
	if (ranndamuBGM == 1) {
		ChangeVolumeSoundMem(140, waraigoesound);//���̊֐��ɂ���ĉ����̃{�����[����ݒ�ł���B
		waraigoesound = LoadSoundMem("waraigoe.mp3");
		PlaySoundMem(waraigoesound, DX_PLAYTYPE_BACK, FALSE);
		ranndamuBGM = 0;
	}
	else if (ranndamuBGM == 10) {
		ChangeVolumeSoundMem(140, waraigoesound2);//���̊֐��ɂ���ĉ����̃{�����[����ݒ�ł���B
		waraigoesound2 = LoadSoundMem("���쌠�t���[ ���p���p�\ �� �y���ʉ��z�@�΂����@�吨�@��̑O�̃A�����J�̃R���f�B�̂悤�ȁA�킴�Ƃ炵���΂���.mp4");
		PlaySoundMem(waraigoesound2, DX_PLAYTYPE_BACK, FALSE);
		ranndamuBGM = 0;
	}

	//���R���e�B�j���[���Ă��r������BGM���Đ�����悤�ɐ퓬����start == 2�̎��̂Ɏc����sound3�Ɠ����֐������āAPlaySoundMem�̑�O������FALSE�Ƃ����B
	//�������������������Ŏ�l�����|���ꂽ������y���~�܂Ȃ������B
	//ChangeVolumeSoundMem(160, stage2sound);//���̊֐��ɂ���ĉ����̃{�����[����ݒ�ł���B
	//PlaySoundMem(stage2sound, DX_PLAYTYPE_BACK, FALSE);

	//���������ɒʏ��Ԃ̎�l���̓������~�܂�Ȃ��悤�ɂ����ɏ������B�G���������B
	//�E����
	if (playerHP > 0) {//����l�����U�����Ă���Œ��ɒʏ��Ԃ�m����Ԃł̉摜���`�悳��Ȃ��悤��playerHPlock������B�Ȃ�playerHPlock�Ȃ�Ė��O�ɂ����̂��͂킩��Ȃ��B
		hinnsiattack = 0;//�񕜂����ۂ�0�ɂȂ�悤�ɂ���B
		KABURI = 0;//��HP��200�ȏ�̎��͒ʏ��Ԃ̏d�Ȃ��L���ɂ��邽�߂�0�ɂ���B
		//zannzoulock = 0;//�m����Ԃ���^�o�R�񕜂ŉ񕜂����ۂɍĂь��̉摜�ɖ߂��悤�ɂ�����0�ɂ���B
		tabakomark = 23939;
		if (playerMove == 1) {//1�t���[���ŏ������I��点�邽��if�̌��else if���g�����B//�t���[���������Ă�playerMove++�������Ȃ���1���オ��Ȃ��BplayerMove++���t���[����60�񃋁[�v���邷��Ƃ���ɏ������Ƃňȉ��̂悤�ɏ����đ����݂��Ă���摜���`�����B
			playerMove2++;//60�t���[���̒��ŁA����if�ŏ���(playerMove > 0)���^�ł��邽��playerMove++���u�t���[���v�Ɓu�������v�ɂ��J��Ԃ�playerMove++���āA

			if (playerMove2 == 20)//�ȑO�̕���ے肵�Ȃ�else if�����ɂ��邽��playerMove�̏��������p��playerMove == 20�ƂȂ�܂ŌJ��Ԃ�playerMove++�������B���ɂ�else if������̂œ��l�A�A�A
			{
				playerImage = playerGHandle[1];
			}
			else if (playerMove2 == 40)//�������Ƃ��ď�������=��==�Ə������B//else if�ɂ��playerMove��20�𒴂���(20�̏ꍇ��ے肵)30�̏ꍇ��\���B
			{
				playerImage = playerGHandle[2];
			}
			else if (playerMove2 == 60)//30�܂ŏオ�������̂�40�ɏオ�������AplayerGHandle[4]�ɂȂ�Bif���̘A���ł͕��@�̃��[���őO�̕���ے肷�邽�ߘA���I�ɉ摜�����ꂸ�����݂ł��Ȃ��A�Ȃ̂�else if�ɂ����̂��B
			{
				playerImage = playerGHandle[1];
			}
			else if (playerMove2 == 80) {//���ɏ����Ă���悤��60�t���[���Ȃ��ɔ[�߂Ȃ��Ƃ����Ȃ����߁A50�܂ŏオ�����Ƃ���ŏI����Ă���B���Ƃ���60 * 4�Ə�����
				playerImage = playerGHandle[0];//��ɏ����Ă邱�Ƃɂ͌�肪����A60�t���[����1s�Ȃ����A�����Ă������B
			}
			else if (playerMove2 == 100) {//���ɏ����Ă���悤��60�t���[���Ȃ��ɔ[�߂Ȃ��Ƃ����Ȃ����߁A50�܂ŏオ�����Ƃ���ŏI����Ă���B���Ƃ���60 * 4�Ə�����
				playerMove2 = 1;
			}


		}
	}

	//��l��������
	if (hidarimuki == 1) {
		++hidarimukiframe;
		//playerImage2 = lockonHandle[0];//���lockonMove == 10��lockonHandle[0]�������p���ŉ��ɏ������`��֐��ɓ��邽�߁A�����ɂ͊֐��ɓ�����񂾂�����̂��B
		//���̎��̏��lockonMove == 10��lockonHandle[0]�ȊO�̈����p���ꂽ�Ƃ������̎��̓G�̍��W�Ȃǂ��֐��ɓ���B�֐������߂���̂�����̂ŁA�֐��ɕK�v�Ȃ��𑵂̂���B
	}
	if (hidarimukiframe == 20) {
		playerImage2 = playerHandle2[1];

	}
	if (hidarimukiframe == 40) {
		playerImage2 = playerHandle2[2];


	}
	if (hidarimukiframe == 60) {
		playerImage2 = playerHandle2[1];
	}
	if (hidarimukiframe == 80) {
		playerImage2 = playerHandle2[0];
	}
	if (hidarimukiframe == 100) {
		hidarimukiframe = 0;
	}



	//�G�̒ʏ��Ԃ̓����𐧌䂷�镔���B
	if (enemyMove >= 0 && ++enemyMove < 100) {//pc��60�t���[���ň�����邽��enemyMove��61�ȏゾ��enemyGHandle[8]�����f���ꂸ���̂܂܂ňړ����I���B�Ȃ̂�enemyMove��60�ȉ��łȂ��Ă͂Ȃ�Ȃ�
		enemyImage3 = enemy3[0];//60�ɂȂ�O�ɉ摜11��`�悷��悤�ɂ��Ȃ���΂Ȃ�Ȃ����߁A60��菬����40�t���[���ɂ����B
	}
	if (enemyMove > 100 && enemyMove < 200) {//pc��60�t���[���ň�����邽��enemyMove��61�ȏゾ��enemyGHandle[8]�����f���ꂸ���̂܂܂ňړ����I���B�Ȃ̂�enemyMove��60�ȉ��łȂ��Ă͂Ȃ�Ȃ�
		enemyImage3 = enemy3[1];//60�ɂȂ�O�ɉ摜11��`�悷��悤�ɂ��Ȃ���΂Ȃ�Ȃ����߁A60��菬����40�t���[���ɂ����B
	}
	if (enemyMove > 200 && enemyMove < 300) {//pc��60�t���[���ň�����邽��enemyMove��61�ȏゾ��enemyGHandle[8]�����f���ꂸ���̂܂܂ňړ����I���B�Ȃ̂�enemyMove��60�ȉ��łȂ��Ă͂Ȃ�Ȃ�
		enemyImage3 = enemy3[2];//60�ɂȂ�O�ɉ摜11��`�悷��悤�ɂ��Ȃ���΂Ȃ�Ȃ����߁A60��菬����40�t���[���ɂ����B
	}
	if (enemyMove > 300) {
		enemyMove = 0;
	}

	//�G�̒ʏ��Ԃ̓����𐧌䂷�镔���B
	if (enemyMove >= 0 && ++enemyMove < 80) {//pc��60�t���[���ň�����邽��enemyMove��61�ȏゾ��enemyGHandle[8]�����f���ꂸ���̂܂܂ňړ����I���B�Ȃ̂�enemyMove��60�ȉ��łȂ��Ă͂Ȃ�Ȃ�
		enemyImage2 = enemy2[0];//60�ɂȂ�O�ɉ摜11��`�悷��悤�ɂ��Ȃ���΂Ȃ�Ȃ����߁A60��菬����40�t���[���ɂ����B
	}
	if (enemyMove > 80 && enemyMove < 160) {//pc��60�t���[���ň�����邽��enemyMove��61�ȏゾ��enemyGHandle[8]�����f���ꂸ���̂܂܂ňړ����I���B�Ȃ̂�enemyMove��60�ȉ��łȂ��Ă͂Ȃ�Ȃ�
		enemyImage2 = enemy2[1];//60�ɂȂ�O�ɉ摜11��`�悷��悤�ɂ��Ȃ���΂Ȃ�Ȃ����߁A60��菬����40�t���[���ɂ����B
	}
	if (enemyMove > 160 && enemyMove < 240) {//pc��60�t���[���ň�����邽��enemyMove��61�ȏゾ��enemyGHandle[8]�����f���ꂸ���̂܂܂ňړ����I���B�Ȃ̂�enemyMove��60�ȉ��łȂ��Ă͂Ȃ�Ȃ�
		enemyImage2 = enemy2[2];//60�ɂȂ�O�ɉ摜11��`�悷��悤�ɂ��Ȃ���΂Ȃ�Ȃ����߁A60��菬����40�t���[���ɂ����B
	}
	if (enemyMove > 240) {
		enemyMove = 0;
	}


	//playerkonntororulock��R2�ł̃��b�N���Ă��邩���Ă��Ȃ������߂������䂷�邽�߂̕ϐ��Bplayerkonntororulock3�͐�������R2�������Ă��܂�����
	//�����Ȃ��悤�ɂ��邽�߂ɍ�����ϐ��Bplayerkonntororulock2�͓��ɂȂ��Ă������B
	if (playerkonntororulock3 == 0) {
		//playerMove = 1;
		//�������͐퓬���̃L�[�������Ȃ��悤�ɂ��邽�߂̃��b�N��݂����B
		if (playerkonntororulock == 0) {
			if (playerkonntororulock2 == 0) {
				gpUpdateKey();

				if (CheckHitKey(KEY_INPUT_Z) != 0) {
					++s;
				}

				//�K�[�h
				if (CheckHitKey(KEY_INPUT_B) != 0) {
					--s;
				}
				//�K�[�h
				if (CheckHitKey(KEY_INPUT_A) != 0) {
					++y;
				}
				//�K�[�h
				if (CheckHitKey(KEY_INPUT_S) != 0) {
					--y;
				}
				//�K�[�h
				if (CheckHitKey(KEY_INPUT_Q) != 0) {
					++x;
				}
				//�K�[�h
				if (CheckHitKey(KEY_INPUT_W) != 0) {
					--x;
				}

				if (CheckHitKey(KEY_INPUT_C) != 0) {
					s2 = s2 + 0.01;
				}

				//�K�[�h
				if (CheckHitKey(KEY_INPUT_V) != 0) {
					s2 = s2 - 0.01;
				}
				//�K�[�h
				if (CheckHitKey(KEY_INPUT_D) != 0) {
					y2 = y2 + 0.01;
				}
				//�K�[�h
				if (CheckHitKey(KEY_INPUT_F) != 0) {
					y2 = y2 - 0.01;
				}
				//�K�[�h
				if (CheckHitKey(KEY_INPUT_E) != 0) {
					x2 = x2 + 0.01;
				}
				//�K�[�h
				if (CheckHitKey(KEY_INPUT_R) != 0) {
					x2 = x2 - 0.01;
				}



				/*if (motonomasunimodoru == 0) {//������w�n�̒��Ȃ�U����H����Ă����̏�Ɏ~�܂�ړ����Ȃ���
					//�����̐w�n�ɂ���ۂ͍U�����ꂽ�ۂɗ������܂܈ړ��ł��Ă��܂��̂ŏ�����t�����킦���B
					if (jyuuzikeysousa2 == 0 && kaihilock == 0) {
						if (jyuuzikeysousa == 0) {
							if (playermovelock == 0 && playermovelock2 == 0) {
								if (stage[0][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 160 &&
									stage[3][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 160 &&
									stage[0][3][0] > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 55 &&
									stage[3][3][0] > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 55 &&
									stage[0][0][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 45 &&
									stage[3][0][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&//����
									stage[0][3][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 45 &&
									stage[3][3][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65
									)
								{
									if (RIGHTbotannlock == 0) {
										if (
											(PrevPadState & PAD_INPUT_RIGHT && nextattack == 0) != 0  //�O��͉�����Ă���
											&&  //����
											(CurrPadState & PAD_INPUT_RIGHT && nextattack == 0) != 0  //����͉�����Ă���
											) {
											RIGHTkey = 1;
										}
										else
											if (
												(PrevPadState & PAD_INPUT_RIGHT && nextattack == 0) == 0  //�O��͉�����Ă��Ȃ�
												&&  //����
												(CurrPadState & PAD_INPUT_RIGHT && nextattack == 0) == 0  //����͉�����Ă��Ȃ�
												) {
												RIGHTkey = 0;
											}

									} //playerMove = 1;������Ɖ��ɏ�����playerMove��葫���݂���playerMove�������Ə����l��1�ł��̂܂ܑ����݂���̂Œx����������̂ł́H
									if (LEFTbotannlock == 0) {
										if (
											(PrevPadState & PAD_INPUT_LEFT && nextattack == 0) != 0  //�O��͉�����Ă���
											&&  //����
											(CurrPadState & PAD_INPUT_LEFT && nextattack == 0) != 0  //����͉�����Ă���
											) {
											LEFTkey = 1;
										}
										else
											if (
												(PrevPadState & PAD_INPUT_LEFT && nextattack == 0) == 0  //�O��͉�����Ă��Ȃ�
												&&  //����
												(CurrPadState & PAD_INPUT_LEFT && nextattack == 0) == 0  //����͉�����Ă��Ȃ�
												) {
												LEFTkey = 0;
											}

									}
									if (UPbotannlock == 0) {
										if (
											(PrevPadState & PAD_INPUT_UP && nextattack == 0) != 0  //�O��͉�����Ă���
											&&  //����
											(CurrPadState & PAD_INPUT_UP && nextattack == 0) != 0  //����͉�����Ă���
											) {
											UPkey = 1;
										}
										else
											if (
												(PrevPadState & PAD_INPUT_UP && nextattack == 0) == 0  //�O��͉�����Ă��Ȃ�
												&&  //����
												(CurrPadState & PAD_INPUT_UP && nextattack == 0) == 0  //����͉�����Ă��Ȃ�
												) {
												UPkey = 0;
											}
									}
									if (DOWNbotannlock == 0) {
										if (
											(PrevPadState & PAD_INPUT_DOWN && nextattack == 0) != 0  //�O��͉�����Ă���
											&&  //����
											(CurrPadState & PAD_INPUT_DOWN && nextattack == 0) != 0  //����͉�����Ă���
											) {
											DOWNkey = 1;
										}
										else
											if (
												(PrevPadState & PAD_INPUT_DOWN && nextattack == 0) == 0  //�O��͉�����Ă��Ȃ�
												&&  //����
												(CurrPadState & PAD_INPUT_DOWN && nextattack == 0) == 0  //����͉�����Ă��Ȃ�
												) {
												DOWNkey = 0;
											}

										if (RIGHTkey == 1) {
											pos[playerY][playerX][0] = pos[playerY][playerX][0] + 3;
										}
										else if (LEFTkey == 1) {
											pos[playerY][playerX][0] = pos[playerY][playerX][0] - 3;
										}
										else if (UPkey == 1) {
											pos[playerY][playerX][1] = pos[playerY][playerX][1] - 1;//�������̎������ɂȂ��Ă��邽�߁B
										}
										else if (DOWNkey == 1) {
											pos[playerY][playerX][1] = pos[playerY][playerX][1] + 1;
										}

										//�͈͊O�ɗ�������W��߂����Ƃɂ���B
										if (pos[playerY][playerX][0] > 680) {
											pos[playerY][playerX][0] = 680;
										}
										if (pos[playerY][playerX][0] < 265) {
											pos[playerY][playerX][0] = 265;
										}
										if (pos[playerY][playerX][1] < 390) {
											pos[playerY][playerX][1] = 390;
										}
										if (pos[playerY][playerX][1] > 440) {
											pos[playerY][playerX][1] = 440;
										}
									}
								}
							}
						}
					}
				}*/
			}

			//���ʏ퉣��ƘA������̃v���O�����B
		//��if (Pad[PAD_6] == 1 && kougekilock == 0&&kougekiroclmark == 0&&enemyY == playerY)�̒��ɏ�����
		//Pad[PAD_6] == 1��������Ă���Ԃ݂̂����������Ȃ��̂őO�̏��������������Ȃ��Ă�kougekilock�̒l������Ηǂ��悤�ɂ����B
			if (kougekikannkakulock == 0) {
				if (kougekidekinailock == 1) {
					if (attackframe == 0) {

						if (migimuki == 1) {
							if (Pad[PAD_2] == 1 && kougekilock == 1 && kougekiKANOU == 2 && sousakanou == 0 && nextattack == 0 &&
								motonomasunimodoru > 0 && Pad[PAD_6] == 0 && Pad[PAD_LEFT] == 0) {
								lock = 0;//�ړ��{�^���������Ȃ��悤�ɁB
								//LEFTmark = 9;
								R1lock = 1;//�ēx�����Ă�Œ���R1�������āA�U�����̍��W��ۑ����Ȃ����߂�1�Ƃ����B
								enemysabunHP = 5;
								stayherelock = 1;//���G��HP�\�����������߂ɕK�v�ȕϐ��B
								//addattacktime = 300;//��s���͂ŃR���{�����܂������̂��߂̃A�h�A�^�b�N�^�C���B
								++attackframe;
								nagurusound = LoadSoundMem("���鉹.mp3");
								//PlaySoundMem(nagurusound, DX_PLAYTYPE_BACK);
								nagurugazou = 1;
								//kougekiKANOU = 0;
								sinnzoubyouga = 1;
								//�ǉ��ŉ���Ƃ��ɃR���{�̉摜��������悤�ɁB
								//KONNBO1A = 1;
								//KONNBO1B = 0;
								zannzoulock = 1;
								//++nagurucount;
								//pos[playerY][playerX][0] = pos[playerY][playerX][0] + 30;
								//pos[playerY][playerX][1] = playerkougekiYzahyou;
								konnbokakuninn = 1;
								nagurukasanaru = 1;

								enemykougekilock = 1;

								tabakolock = 1;//���b�N���̓^�o�R���z���Ȃ��悤��1�ɂ���B

								playerHPlock = 1;//�L�b�N����Ƃ��Ƀ_���[�W�𕉂�����Ԃ̉摜��`�悵�Ȃ����߂̕��B
								//nanameidouX = nanameidouX + 5;
								playerattackhanndou = playerattackhanndou + 10;//������������Ԃ̂ł͂Ȃ��A�G��������Ԃ��߂̔����Ȃ̂Ŏ����̕`�敔���̈�ɂ͏����Ȃ�
								sinnzoubyouga = 1;//�����Ԃ���`�悷�邽�߂̕ϐ��B
								motonomasunimodoru = motonomasunimodoru + 40;//�U�����ɍU�������������玞�Ԃ����т�
								//�������ɂ���Ƃ��܂ɑ�����180�ɂȂ����Ƃ���if����0�ɂȂ��Ă��܂��̂ő����ł͂Ȃ��萔�ɂ����B
								nextattack = 1;//�U���̓���������h�����߂̕ϐ��B
								//�������܂ɑ������艜�ɓ˂���΂����Ƃ�����B����Ȏ��͂����R1�������Ēǂ������Ēǉ��U������Ƃ����B
								notattacklock = 1;
								enemyattaking = 1;
								//nanameidouX = nanameidouX + 8;
								//playerattackhanndou = playerattackhanndou + 5;//�G�����ɐi��
								//if (GetRand(10) < 4) {
								//	playerattackhanndou2 = playerattackhanndou2 + 30;//�ǂ��Ɉړ����邩�킩��Ȃ��悤�ɂ��ăM�����u���������߂ă}���l������h���B
								//	playerattackhanndou3 = playerattackhanndou3 + 5;// playerattackhanndou3��Y���ɐ�����΂����߂̕ϐ��B
								//}

								//�R���{
								++conbocount;
								//�����ĉ���ƃo�O�œG�̍U������C�Ɏ󂯂đ������邱�Ƃ�����̂ň��̋�Ԃł̍U���Ƃ���B
								//�L�b�N�Ⓛ�Ɠ����ϐ��Ŏg����Γ��������ɂ��U���Ȃǂ���苭���ł���Ǝv���B
								//++kougekikannkaku;
								kakuninn = 14;
								enemyzannzoulockframe1 = 1;//����̃_���[�W��H������ۂ̋��݂������ɖ߂�����
								stayhereframe = 1;

								enemysabunHPpoint = enemysabunHPpoint + 10;//�G�𐁂���΂����߂ɕK�v�ȃ|�C���g
								bloodMove = 1;
							}
							if (Pad[PAD_2] == 1 && kougekilock == 1 && kougekiKANOU == 3 && sousakanou == 0 && nextattack == 0 &&
								motonomasunimodoru > 0 && Pad[PAD_6] == 0 && Pad[PAD_LEFT] == 0) {
								lock = 0;//�ړ��{�^���������Ȃ��悤�ɁB
								//LEFTmark = 9;
								R1lock = 1;//�ēx�����Ă�Œ���R1�������āA�U�����̍��W��ۑ����Ȃ����߂�1�Ƃ����B
								anotherenemysabunHP = 5;
								stayherelock = 1;//���G��HP�\�����������߂ɕK�v�ȕϐ��B
								//addattacktime = 300;//��s���͂ŃR���{�����܂������̂��߂̃A�h�A�^�b�N�^�C���B
								++attackframe;
								nagurusound = LoadSoundMem("���鉹.mp3");
								//PlaySoundMem(nagurusound, DX_PLAYTYPE_BACK);
								nagurugazou = 1;
								//kougekiKANOU = 0;
								sinnzoubyouga = 1;
								//�ǉ��ŉ���Ƃ��ɃR���{�̉摜��������悤�ɁB
								//KONNBO1A = 1;
								//KONNBO1B = 0;
								zannzoulock = 1;
								//++nagurucount;
								//pos[playerY][playerX][0] = playerkougekiXzahyou - 100;
								//pos[playerY][playerX][1] = playerkougekiYzahyou;
								konnbokakuninn = 1;
								nagurukasanaru = 1;

								enemykougekilock = 1;

								tabakolock = 1;//���b�N���̓^�o�R���z���Ȃ��悤��1�ɂ���B

								playerHPlock = 1;//�L�b�N����Ƃ��Ƀ_���[�W�𕉂�����Ԃ̉摜��`�悵�Ȃ����߂̕��B

								//playerattackhanndou = playerattackhanndou + 10;//������������Ԃ̂ł͂Ȃ��A�G��������Ԃ��߂̔����Ȃ̂Ŏ����̕`�敔���̈�ɂ͏����Ȃ�
								sinnzoubyouga = 1;//�����Ԃ���`�悷�邽�߂̕ϐ��B
								motonomasunimodoru = motonomasunimodoru + 40;//�U�����ɍU�������������玞�Ԃ����т�
								//nanameidouX = nanameidouX + 5;
								playerattackhanndouB = playerattackhanndouB + 10;
								//�������ɂ���Ƃ��܂ɑ�����180�ɂȂ����Ƃ���if����0�ɂȂ��Ă��܂��̂ő����ł͂Ȃ��萔�ɂ����B
								nextattack = 1;//�U���̓���������h�����߂̕ϐ��B
								//�������܂ɑ������艜�ɓ˂���΂����Ƃ�����B����Ȏ��͂����R1�������Ēǂ������Ēǉ��U������Ƃ����B
								notattacklock = 1;
								enemyattaking = 1;
								//if (GetRand(10) < 4) {
								//	playerattackhanndou2B = playerattackhanndou2B + 30;//�ǂ��Ɉړ����邩�킩��Ȃ��悤�ɂ��ăM�����u���������߂ă}���l������h���B
								//	playerattackhanndou3B = playerattackhanndou3B + 25;// playerattackhanndou3��Y���ɐ�����΂����߂̕ϐ��B
								//}
								//�R���{
								++conbocount;
								//�����ĉ���ƃo�O�œG�̍U������C�Ɏ󂯂đ������邱�Ƃ�����̂ň��̋�Ԃł̍U���Ƃ���B
								//�L�b�N�Ⓛ�Ɠ����ϐ��Ŏg����Γ��������ɂ��U���Ȃǂ���苭���ł���Ǝv���B
								//++kougekikannkaku;
								enemyzannzoulockBframe = 1;
								stayhere2frame = 1;
								enemy2sabunHPpoint = enemy2sabunHPpoint + 10;
								bloodMove = 1;
							}
						}


						else if (hidarimuki == 1) {
							if (Pad[PAD_2] == 1 && kougekilock == 1 && kougekiKANOU == 2 && sousakanou == 0 && nextattack == 0 &&
								motonomasunimodoru > 0 && Pad[PAD_6] == 0 && Pad[PAD_LEFT] == 0) {
								lock = 0;//�ړ��{�^���������Ȃ��悤�ɁB
								//LEFTmark = 9;
								R1lock = 1;//�ēx�����Ă�Œ���R1�������āA�U�����̍��W��ۑ����Ȃ����߂�1�Ƃ����B
								enemysabunHP = 5;
								stayherelock = 1;//���G��HP�\�����������߂ɕK�v�ȕϐ��B
								//addattacktime = 300;//��s���͂ŃR���{�����܂������̂��߂̃A�h�A�^�b�N�^�C���B
								++attackframe;
								nagurusound = LoadSoundMem("���鉹.mp3");
								//PlaySoundMem(nagurusound, DX_PLAYTYPE_BACK);
								nagurugazou = 1;
								//kougekiKANOU = 0;
								sinnzoubyouga = 1;
								//�ǉ��ŉ���Ƃ��ɃR���{�̉摜��������悤�ɁB
								//KONNBO1A = 1;
								//KONNBO1B = 0;
								zannzoulock = 1;
								//++nagurucount;
								//pos[playerY][playerX][0] = pos[playerY][playerX][0] + 30;
								//pos[playerY][playerX][1] = playerkougekiYzahyou;
								konnbokakuninn = 1;
								nagurukasanaru = 1;

								enemykougekilock = 1;

								tabakolock = 1;//���b�N���̓^�o�R���z���Ȃ��悤��1�ɂ���B

								playerHPlock = 1;//�L�b�N����Ƃ��Ƀ_���[�W�𕉂�����Ԃ̉摜��`�悵�Ȃ����߂̕��B
								//nanameidouX = nanameidouX + 5;
								playerattackhanndou = playerattackhanndou - 10;//������������Ԃ̂ł͂Ȃ��A�G��������Ԃ��߂̔����Ȃ̂Ŏ����̕`�敔���̈�ɂ͏����Ȃ�
								sinnzoubyouga = 1;//�����Ԃ���`�悷�邽�߂̕ϐ��B
								motonomasunimodoru = motonomasunimodoru + 40;//�U�����ɍU�������������玞�Ԃ����т�
								//�������ɂ���Ƃ��܂ɑ�����180�ɂȂ����Ƃ���if����0�ɂȂ��Ă��܂��̂ő����ł͂Ȃ��萔�ɂ����B
								nextattack = 1;//�U���̓���������h�����߂̕ϐ��B
								//�������܂ɑ������艜�ɓ˂���΂����Ƃ�����B����Ȏ��͂����R1�������Ēǂ������Ēǉ��U������Ƃ����B
								notattacklock = 1;
								enemyattaking = 1;
								//nanameidouX = nanameidouX + 8;
								//playerattackhanndou = playerattackhanndou + 5;//�G�����ɐi��
								//if (GetRand(10) < 4) {
								//	playerattackhanndou2 = playerattackhanndou2 + 30;//�ǂ��Ɉړ����邩�킩��Ȃ��悤�ɂ��ăM�����u���������߂ă}���l������h���B
								//	playerattackhanndou3 = playerattackhanndou3 + 5;// playerattackhanndou3��Y���ɐ�����΂����߂̕ϐ��B
								//}

								//�R���{
								++conbocount;
								//�����ĉ���ƃo�O�œG�̍U������C�Ɏ󂯂đ������邱�Ƃ�����̂ň��̋�Ԃł̍U���Ƃ���B
								//�L�b�N�Ⓛ�Ɠ����ϐ��Ŏg����Γ��������ɂ��U���Ȃǂ���苭���ł���Ǝv���B

								kakuninn = 17;//++kougekikannkaku;
								enemyzannzoulockframe1 = 1;//����̃_���[�W��H������ۂ̋��݂������ɖ߂�����
								stayhereframe = 1;

								enemysabunHPpoint = enemysabunHPpoint + 10;//�G�𐁂���΂����߂ɕK�v�ȃ|�C���g
								bloodMove = 1;
							}
							if (Pad[PAD_2] == 1 && kougekilock == 1 && kougekiKANOU == 3 && sousakanou == 0 && nextattack == 0 &&
								motonomasunimodoru > 0 && Pad[PAD_6] == 0 && Pad[PAD_LEFT] == 0) {
								lock = 0;//�ړ��{�^���������Ȃ��悤�ɁB
								//LEFTmark = 9;
								R1lock = 1;//�ēx�����Ă�Œ���R1�������āA�U�����̍��W��ۑ����Ȃ����߂�1�Ƃ����B
								anotherenemysabunHP = 5;
								stayherelock = 1;//���G��HP�\�����������߂ɕK�v�ȕϐ��B
								//addattacktime = 300;//��s���͂ŃR���{�����܂������̂��߂̃A�h�A�^�b�N�^�C���B
								++attackframe;
								nagurusound = LoadSoundMem("���鉹.mp3");
								//PlaySoundMem(nagurusound, DX_PLAYTYPE_BACK);
								nagurugazou = 1;
								//kougekiKANOU = 0;
								sinnzoubyouga = 1;
								//�ǉ��ŉ���Ƃ��ɃR���{�̉摜��������悤�ɁB
								//KONNBO1A = 1;
								//KONNBO1B = 0;
								zannzoulock = 1;
								//++nagurucount;
								//pos[playerY][playerX][0] = playerkougekiXzahyou - 100;
								//pos[playerY][playerX][1] = playerkougekiYzahyou;
								konnbokakuninn = 1;
								nagurukasanaru = 1;

								enemykougekilock = 1;

								tabakolock = 1;//���b�N���̓^�o�R���z���Ȃ��悤��1�ɂ���B

								playerHPlock = 1;//�L�b�N����Ƃ��Ƀ_���[�W�𕉂�����Ԃ̉摜��`�悵�Ȃ����߂̕��B

								//playerattackhanndou = playerattackhanndou + 10;//������������Ԃ̂ł͂Ȃ��A�G��������Ԃ��߂̔����Ȃ̂Ŏ����̕`�敔���̈�ɂ͏����Ȃ�
								sinnzoubyouga = 1;//�����Ԃ���`�悷�邽�߂̕ϐ��B
								motonomasunimodoru = motonomasunimodoru + 40;//�U�����ɍU�������������玞�Ԃ����т�
								//nanameidouX = nanameidouX + 5;
								playerattackhanndouB = playerattackhanndouB - 10;
								//�������ɂ���Ƃ��܂ɑ�����180�ɂȂ����Ƃ���if����0�ɂȂ��Ă��܂��̂ő����ł͂Ȃ��萔�ɂ����B
								nextattack = 1;//�U���̓���������h�����߂̕ϐ��B
								//�������܂ɑ������艜�ɓ˂���΂����Ƃ�����B����Ȏ��͂����R1�������Ēǂ������Ēǉ��U������Ƃ����B
								notattacklock = 1;
								enemyattaking = 1;
								//if (GetRand(10) < 4) {
								//	playerattackhanndou2B = playerattackhanndou2B + 30;//�ǂ��Ɉړ����邩�킩��Ȃ��悤�ɂ��ăM�����u���������߂ă}���l������h���B
								//	playerattackhanndou3B = playerattackhanndou3B + 25;// playerattackhanndou3��Y���ɐ�����΂����߂̕ϐ��B
								//}
								//�R���{
								++conbocount;
								//�����ĉ���ƃo�O�œG�̍U������C�Ɏ󂯂đ������邱�Ƃ�����̂ň��̋�Ԃł̍U���Ƃ���B
								//�L�b�N�Ⓛ�Ɠ����ϐ��Ŏg����Γ��������ɂ��U���Ȃǂ���苭���ł���Ǝv���B
								//++kougekikannkaku;
								enemyzannzoulockBframe = 1;
								stayhere2frame = 1;
								enemy2sabunHPpoint = enemy2sabunHPpoint + 10;
								bloodMove = 1;
							}
						}

					}//1���傫�����͌J��オ��A30��菬�����Ԃ�{}������B
					//attackframeA��1�̌�Ɉꔭ�ڂ̍U�����I��邱�Ƃł�����0�ɂȂ��Ă��܂��A���������b�N�ł����A�Ăщ���U�������Ă����B
					//���܂Ɏ��Ԃ̉e���Ő������������Ƃ��������B
					if (attackframe > 0 && ++attackframe < 80) {
						if (attackframe > 35 && attackframe < 80) {//�����̊ԂɃ{�^���������ƘA���U���Ɉڂ�B
							//�ŏ��̉���ƈꏏ��atatackframe�͗����オ�邽�߁A�ꔭ�ڂ̍U�����\�����ꂽ�キ�炢�̃t���[������
							//�񔭖ڂ�`�悵�����̂ŁA60����ɂ����B

							//�G1�ɑ΂���A���ŉ��镔���B
							if (Pad[PAD_2] == 1 && kougekiKANOU == 2 && sousakanou == 0 && nextattack == 0 && attackframeA == 0) {
								attackframeA = 1;//�A���œ񔭖ڂ̉���R���{���o���Ȃ��悤�ɂ��邽�߂̕ϐ��B
								nagurugazou = 0;
								++nagurugazou2;
							}

							//�G2�ɑ΂��ĘA���ŉ��镔��
							if (Pad[PAD_2] == 1 && kougekiKANOU == 3 && sousakanou == 0 && nextattack == 0 && attackframeA == 0) {
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

					//���� && kougekilock == 1&& kougekiKANOU == 1��R1�������Ȃ��ꍇ�̎��͏�ɏ������悤��
					//R1lock��0�ɂȂ�̂ŁA�R���{���o���Ȃ��̂ő��̕ϐ�konnbokakuninn���g�����B
					//�ŏ�����R���{�o�Ȃ��ꍇ��R1lock��1�̂܂܂Ȃ̂ł��̂܂܃L�b�N�ł���B
				//Y�{�^������̃R���{�����߂邽�߂�Y�{�^������͂��镔��//�L�b�N����{�^��
					//���ǂ����t���[����kougekiKANOU�͈̔͂Ń_���[�W���^������̂ŁA����ƃt���[���グ�̌��͈�ł����B
					if (Pad[PAD_4] == 1 && kougekilock == 1 && enemysabunHP == 0 && sousakanou == 0 && nextattack == 0) {//enemysabunHP��0�ƂȂ�Ƃ��ɉ�����悤�ɂ����̂ŉ��邪������Ă��Ȃ��Ƃ��ɃL�b�N���ł���悤�ɂ����B
					   //R1�ł̈ړ�����playermovelock��1�ɂ��Ă�̂ł�����playermovelock=1�������Ȃ��Ă����B
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
						sennkounyuuryokubunnki = 1;
						kougekilock = 1;////��s���͂ŃR���{�����܂������Ɍ�쓮��X�{�^���������Ă����邪�łȂ��悤�ɑ��̒l�ɂ���B
						zannzoulock = 1;

						KONNBO1A = 1;


						nagurukasanaru = 0;
						KONNBO1kasanaru = 1;

						enemykougekilock = 1;

						playerHPlock = 1;//�L�b�N����Ƃ��Ƀ_���[�W�𕉂�����Ԃ̉摜��`�悵�Ȃ����߂̕��B
						nextattack = 1;
						//motonomasunimodoru = 160;//�R���{�����܂�ƈ��̒l�ɂȂ�悤�ɂ����B

					}

					if (sennkounyuuryokubunnki == 1) {
						++attackframe2;
						//LEFTmark = 114;
					}

					//����Ɖ���attackframe�͈̔͂����邪�A��̂͒ʏ�U���ł̍ŏ��̉���̃t���[���A
					//�����͑���̖ڂ̑O�Ɉړ�������̉���if�����l�����������ł�attackframe�Ȃ̂�attackframe�͈̔͂�����Ă���킯�ł͂Ȃ��̂Ŗ��Ȃ��B
					//��s���͂̍U���ݒ�//���b�N�̒��ɏ����ƃ��b�N�{�^������������u����attackframe�̒l���オ��Ȃ��̂ł����ɏ������B
					//if (kougekilock == 1 && kougekiKANOU == 2) {
						//attackframe1�`3�Ɋւ��āA�U�����͓����Ȃ��l�ɏ������Battackframe1�͏�̕���if���̒��ɏ������B
					//	if (attackframe > 0 && attackframe <= 150) {
					//		playermovelock = 1;
					//	}
					//	if (attackframe2 > 0 && attackframe2 <= 150) {
					//		playermovelock = 1;
					//	}
					//	if (attackframe3 > 0 && attackframe3 <= 150) {
					//		playermovelock = 1;
					//	}
					//}
					//++attackframe;
					//���ȑO��kougekiKANOU�������ɍ��������߁A�G���痣��Ă���ۂ�kougekiKANOU��0�ƂȂ�Aattackframe2�̒l�����r���[�ɂȂ��Ă��܂��A�X���C�h�̉��ړ�
					//�����ŏ���ɏR��U�����o�Ă��܂����B


					if (attackframe2 > 0 && attackframe2 < 40 && kougekiKANOU == 2) {//����if (attackframe2 > 0 && attackframe2 < 15)�Ɣ��Ȃ��悤�ɂ���B
						if (migimuki == 1) {
							if (Pad[PAD_RIGHT] == 1) {//�����̕��͍��͂����Ŕ������Ȃ��悤�ɏ����x�߂�9�ɂ��āA���ɒx�߂ɍ��͂͂����ŉE�����͂���Ă��������Ȃ��悤��15�Ƃ����B
								//LEFTmark = 514;
								//KONNBO1A = 0;//����グ�鎞�ɁA�R��O�̉摜��`�悵�Ȃ��悤�ɁB
								enemysabunHPA = 10;//�ŏ��̕��ʂ̉���̍U����X�{�^�����������Ƃ̃R���{���Ȃ邽��
								//LEFTmark = 114514;//�`��p�ɍ������s���͂̊m�F�p�̕ϐ�
								LEFTmarklock = 1;//��s���͂��Ăтł���悤�ɂ���ɂ�X�{�^���ő�������邽�߂ɁA������1�Ƃ��āA�ǉ��̕���LEFTmarklock = 0�Ƃ����B
								//addattacktime = 300;
								attackframe = 0;//�U����ɒǉ���������Ȃ��Ă�1�Ƃ��Ă�����0���傫���̂ŃR���{���Ȃ���B�ǉ�����ō��R���{���q���Ă������B
								stayherelock = 1;//�G��HP���������߂ɕK�v�ȕϐ�
								//sennkounyuuryokubunnki = 1;//��if�����sennkounyuuryokubunnki==1�̎��łȂ��Ƃ�����if���͓����Ȃ��̂ŁAsennkounyuuryokubunnki��0�̎��͑O��if���̏����ɍ���Ȃ��̂�attackframe2���ł����Ă�����2�̍U���ł��Ȃ��͓̂��R�ł���B
								attackframe2 = 0;//��s���͂̕����sennkounyuuryokubunnki2�ɍs���Ȃ������ꍇ��attackframe2�̒l��0�ɂȂ�悤�ɏ������B
								naguru2sound = LoadSoundMem("damage01.m4a");
								//PlaySoundMem(naguru2sound, DX_PLAYTYPE_BACK);
								//sennkounyuuryokubunnki3 = 0;//�����̐�s���͂����������ۂ͑����ĉ���3���łȂ��悤�ɂ����̕ϐ���0�ɂ���B
								//attackframe3 = 150;//����s���͂����������ۂ͑����ĉ���3���łȂ��悤�ɉ���3�Ɉ����|����Ȃ��悤�ȕϐ��̒l�ɂ���B
								//sennkounyuuryokubunnki = 0;
								kougekilock = 1;//�R���{���͂����������ۂɍĂуR���{�����߂����ۂɏ��Y�{�^����if����ʉ߂ł���悤��
								//kougekilock�̒l��1�ɂ���B

								KONNBO1A = 0;//�O�̏R��O�̉摜���������߂̕��B
								KONNBO1B = 1;//�R��グ��̉摜��`�悷�邽�߂̂���

								sennkounyuuryokubunnki = 0;
								KONNBO1kasanaru = 0;
								KONNBO2kasanaru = 1;
								sinnzoubyouga = 1;//�����Ԃ���`�悷�邽�߂̕ϐ��B
								motonomasunimodoru = motonomasunimodoru + 30;//�U�����ɍU�������������玞�Ԃ����т�
								playerattackhanndou = playerattackhanndou + 15;
								//nanameidouX = nanameidouX + 15;//���A���ŏR���ɂ��Ă��A����40���Ƃ����ƏR����̂ŁA�r���ō����o�āA
								//�͈͂�2����0�ɂȂ�悤��30�Ƃ���B
								//playerattackhanndou3 = playerattackhanndou3 + 30;
								enemyattaking = 1;
								//�������܂ɑ������艜�ɓ˂���΂����Ƃ�����B����Ȏ��͂����R1�������Ēǂ������Ēǉ��U������Ƃ����B
								if (GetRand(10) < 4) {
									playerattackhanndou2 = playerattackhanndou2 + 20;
									playerattackhanndou3 = playerattackhanndou3 + 10;// playerattackhanndou3��Y���ɐ�����΂����߂̕ϐ��B
								}
								kakuninn = 19;//�R���{
								++conbocount;
								enemyzannzoulockframe1 = 1;//����̃_���[�W��H������ۂ̋��݂������ɖ߂�����
								stayhereframe = 1;

								enemysabunHPpoint = enemysabunHPpoint + 20;
								bloodMove = 1;
							}
						}

						else if (hidarimuki == 1) {
							if (Pad[PAD_LEFT] == 1) {//�����̕��͍��͂����Ŕ������Ȃ��悤�ɏ����x�߂�9�ɂ��āA���ɒx�߂ɍ��͂͂����ŉE�����͂���Ă��������Ȃ��悤��15�Ƃ����B
								//LEFTmark = 514;
								//KONNBO1A = 0;//����グ�鎞�ɁA�R��O�̉摜��`�悵�Ȃ��悤�ɁB
								enemysabunHPA = 10;//�ŏ��̕��ʂ̉���̍U����X�{�^�����������Ƃ̃R���{���Ȃ邽��
								//LEFTmark = 114514;//�`��p�ɍ������s���͂̊m�F�p�̕ϐ�
								LEFTmarklock = 1;//��s���͂��Ăтł���悤�ɂ���ɂ�X�{�^���ő�������邽�߂ɁA������1�Ƃ��āA�ǉ��̕���LEFTmarklock = 0�Ƃ����B
								//addattacktime = 300;
								attackframe = 0;//�U����ɒǉ���������Ȃ��Ă�1�Ƃ��Ă�����0���傫���̂ŃR���{���Ȃ���B�ǉ�����ō��R���{���q���Ă������B
								stayherelock = 1;//�G��HP���������߂ɕK�v�ȕϐ�
								//sennkounyuuryokubunnki = 1;//��if�����sennkounyuuryokubunnki==1�̎��łȂ��Ƃ�����if���͓����Ȃ��̂ŁAsennkounyuuryokubunnki��0�̎��͑O��if���̏����ɍ���Ȃ��̂�attackframe2���ł����Ă�����2�̍U���ł��Ȃ��͓̂��R�ł���B
								attackframe2 = 0;//��s���͂̕����sennkounyuuryokubunnki2�ɍs���Ȃ������ꍇ��attackframe2�̒l��0�ɂȂ�悤�ɏ������B
								naguru2sound = LoadSoundMem("damage01.m4a");
								//PlaySoundMem(naguru2sound, DX_PLAYTYPE_BACK);
								//sennkounyuuryokubunnki3 = 0;//�����̐�s���͂����������ۂ͑����ĉ���3���łȂ��悤�ɂ����̕ϐ���0�ɂ���B
								//attackframe3 = 150;//����s���͂����������ۂ͑����ĉ���3���łȂ��悤�ɉ���3�Ɉ����|����Ȃ��悤�ȕϐ��̒l�ɂ���B
								//sennkounyuuryokubunnki = 0;
								kougekilock = 1;//�R���{���͂����������ۂɍĂуR���{�����߂����ۂɏ��Y�{�^����if����ʉ߂ł���悤��
								//kougekilock�̒l��1�ɂ���B

								KONNBO1A = 0;//�O�̏R��O�̉摜���������߂̕��B
								KONNBO1B = 1;//�R��グ��̉摜��`�悷�邽�߂̂���

								sennkounyuuryokubunnki = 0;
								KONNBO1kasanaru = 0;
								KONNBO2kasanaru = 1;
								sinnzoubyouga = 1;//�����Ԃ���`�悷�邽�߂̕ϐ��B
								motonomasunimodoru = motonomasunimodoru + 30;//�U�����ɍU�������������玞�Ԃ����т�
								playerattackhanndou = playerattackhanndou - 15;
								//nanameidouX = nanameidouX + 15;//���A���ŏR���ɂ��Ă��A����40���Ƃ����ƏR����̂ŁA�r���ō����o�āA
								//�͈͂�2����0�ɂȂ�悤��30�Ƃ���B
								//playerattackhanndou3 = playerattackhanndou3 + 30;
								enemyattaking = 1;
								//�������܂ɑ������艜�ɓ˂���΂����Ƃ�����B����Ȏ��͂����R1�������Ēǂ������Ēǉ��U������Ƃ����B
								if (GetRand(10) < 4) {
									playerattackhanndou2 = playerattackhanndou2 - 20;
									playerattackhanndou3 = playerattackhanndou3 - 10;// playerattackhanndou3��Y���ɐ�����΂����߂̕ϐ��B
								}
								//�R���{
								kakuninn = 20;
								++conbocount;
								enemyzannzoulockframe1 = 1;//����̃_���[�W��H������ۂ̋��݂������ɖ߂�����
								stayhereframe = 1;

								enemysabunHPpoint = enemysabunHPpoint + 20;
								bloodMove = 1;
							}
						}
						//sennkounyuuryokubunnki3 = 0;
						//attackframe3 = 0;//����2�o�[�W�������������Œl�����̂܂܂��ƉE�������������ŉ���o�[�W����3���ł��Ă��܂��̂ŁB
						//������2�ɕ��򂵂��ꍇ�͉���3�̏������ׂ�0�ɂ���B
						//attackframe = 0;//����2�������������邩�͕ʂɂ��̃t���[���̎��Ɉ�U0�ɂ����X�{�^������̃R���{���Ȃ���₷���B
					}





					if (attackframe2 > 0 && attackframe2 < 40 && kougekiKANOU == 3) {//����if (attackframe2 > 0 && attackframe2 < 15)�Ɣ��Ȃ��悤�ɂ���B
					   //A�{�^��
						if (migimuki == 1) {
							if (Pad[PAD_RIGHT] == 1) {//�����̕��͍��͂����Ŕ������Ȃ��悤�ɏ����x�߂�9�ɂ��āA���ɒx�߂ɍ��͂͂����ŉE�����͂���Ă��������Ȃ��悤��15�Ƃ����B
								//LEFTmark = 514;
								//KONNBO1A = 0;//����グ�鎞�ɁA�R��O�̉摜��`�悵�Ȃ��悤�ɁB
								anotherenemysabunHPA = 10;//�ŏ��̕��ʂ̉���̍U����X�{�^�����������Ƃ̃R���{���Ȃ邽��
								//LEFTmark = 114514;//�`��p�ɍ������s���͂̊m�F�p�̕ϐ�
								LEFTmarklock = 1;//��s���͂��Ăтł���悤�ɂ���ɂ�X�{�^���ő�������邽�߂ɁA������1�Ƃ��āA�ǉ��̕���LEFTmarklock = 0�Ƃ����B
								//addattacktime = 300;
								attackframe = 0;//�U����ɒǉ���������Ȃ��Ă�1�Ƃ��Ă�����0���傫���̂ŃR���{���Ȃ���B�ǉ�����ō��R���{���q���Ă������B
								stayherelock = 1;//�G��HP���������߂ɕK�v�ȕϐ�
								//sennkounyuuryokubunnki = 1;//��if�����sennkounyuuryokubunnki==1�̎��łȂ��Ƃ�����if���͓����Ȃ��̂ŁAsennkounyuuryokubunnki��0�̎��͑O��if���̏����ɍ���Ȃ��̂�attackframe2���ł����Ă�����2�̍U���ł��Ȃ��͓̂��R�ł���B
								attackframe2 = 0;//��s���͂̕����sennkounyuuryokubunnki2�ɍs���Ȃ������ꍇ��attackframe2�̒l��0�ɂȂ�悤�ɏ������B
								//naguru2sound = LoadSoundMem("damage01.m4a");
								//PlaySoundMem(naguru2sound, DX_PLAYTYPE_BACK);
								//sennkounyuuryokubunnki3 = 0;//�����̐�s���͂����������ۂ͑����ĉ���3���łȂ��悤�ɂ����̕ϐ���0�ɂ���B
								//attackframe3 = 150;//����s���͂����������ۂ͑����ĉ���3���łȂ��悤�ɉ���3�Ɉ����|����Ȃ��悤�ȕϐ��̒l�ɂ���B

								kougekilock = 1;//�R���{���͂����������ۂɍĂуR���{�����߂����ۂɏ��Y�{�^����if����ʉ߂ł���悤��
								//kougekilock�̒l��1�ɂ���B

								KONNBO1A = 0;//�O�̏R��O�̉摜���������߂̕��B
								KONNBO1B = 1;//�R��グ��̉摜��`�悷�邽�߂̂���
								//sennkounyuuryokubunnki = 0;
								sennkounyuuryokubunnki = 0;

								KONNBO1kasanaru = 0;
								KONNBO2kasanaru = 1;
								sinnzoubyouga = 1;//�����Ԃ���`�悷�邽�߂̕ϐ��B
								motonomasunimodoru = motonomasunimodoru + 30;//�U�����ɍU�������������玞�Ԃ����т�
								//nanameidouX = nanameidouX + 15;
								playerattackhanndouB = playerattackhanndouB + 15;
								//playerattackhanndou3B = playerattackhanndou3B + 30;
								enemyattaking = 1;
								//�������܂ɑ������艜�ɓ˂���΂����Ƃ�����B����Ȏ��͂����R1�������Ēǂ������Ēǉ��U������Ƃ����B
								if (GetRand(10) < 4) {
									playerattackhanndou2B = playerattackhanndou2B + 20;
									playerattackhanndou3B = playerattackhanndou3B + 10;// playerattackhanndou3��Y���ɐ�����΂����߂̕ϐ��B
								}
								//�R���{
								++conbocount;
								enemyzannzoulockBframe = 1;//����̃_���[�W��H������ۂ̋��݂������ɖ߂�����
								stayhere2frame = 1;

								enemy2sabunHPpoint = enemy2sabunHPpoint + 20;
							}
							bloodMove = 1;
						}
						else if (hidarimuki == 1) {
							if (Pad[PAD_LEFT] == 1) {//�����̕��͍��͂����Ŕ������Ȃ��悤�ɏ����x�߂�9�ɂ��āA���ɒx�߂ɍ��͂͂����ŉE�����͂���Ă��������Ȃ��悤��15�Ƃ����B
								//LEFTmark = 514;
								//KONNBO1A = 0;//����グ�鎞�ɁA�R��O�̉摜��`�悵�Ȃ��悤�ɁB
								anotherenemysabunHPA = 10;//�ŏ��̕��ʂ̉���̍U����X�{�^�����������Ƃ̃R���{���Ȃ邽��
								//LEFTmark = 114514;//�`��p�ɍ������s���͂̊m�F�p�̕ϐ�
								LEFTmarklock = 1;//��s���͂��Ăтł���悤�ɂ���ɂ�X�{�^���ő�������邽�߂ɁA������1�Ƃ��āA�ǉ��̕���LEFTmarklock = 0�Ƃ����B
								//addattacktime = 300;
								attackframe = 0;//�U����ɒǉ���������Ȃ��Ă�1�Ƃ��Ă�����0���傫���̂ŃR���{���Ȃ���B�ǉ�����ō��R���{���q���Ă������B
								stayherelock = 1;//�G��HP���������߂ɕK�v�ȕϐ�
								//sennkounyuuryokubunnki = 1;//��if�����sennkounyuuryokubunnki==1�̎��łȂ��Ƃ�����if���͓����Ȃ��̂ŁAsennkounyuuryokubunnki��0�̎��͑O��if���̏����ɍ���Ȃ��̂�attackframe2���ł����Ă�����2�̍U���ł��Ȃ��͓̂��R�ł���B
								attackframe2 = 0;//��s���͂̕����sennkounyuuryokubunnki2�ɍs���Ȃ������ꍇ��attackframe2�̒l��0�ɂȂ�悤�ɏ������B
								//naguru2sound = LoadSoundMem("damage01.m4a");
								//PlaySoundMem(naguru2sound, DX_PLAYTYPE_BACK);
								//sennkounyuuryokubunnki3 = 0;//�����̐�s���͂����������ۂ͑����ĉ���3���łȂ��悤�ɂ����̕ϐ���0�ɂ���B
								//attackframe3 = 150;//����s���͂����������ۂ͑����ĉ���3���łȂ��悤�ɉ���3�Ɉ����|����Ȃ��悤�ȕϐ��̒l�ɂ���B

								kougekilock = 1;//�R���{���͂����������ۂɍĂуR���{�����߂����ۂɏ��Y�{�^����if����ʉ߂ł���悤��
								//kougekilock�̒l��1�ɂ���B
								
								KONNBO1A = 0;//�O�̏R��O�̉摜���������߂̕��B
								KONNBO1B = 1;//�R��グ��̉摜��`�悷�邽�߂̂���
								//sennkounyuuryokubunnki = 0;
								sennkounyuuryokubunnki = 0;

								KONNBO1kasanaru = 0;
								KONNBO2kasanaru = 1;
								sinnzoubyouga = 1;//�����Ԃ���`�悷�邽�߂̕ϐ��B
								motonomasunimodoru = motonomasunimodoru + 30;//�U�����ɍU�������������玞�Ԃ����т�
								//nanameidouX = nanameidouX + 15;
								playerattackhanndouB = playerattackhanndouB - 15;
								//playerattackhanndou3B = playerattackhanndou3B + 30;
								enemyattaking = 1;
								//�������܂ɑ������艜�ɓ˂���΂����Ƃ�����B����Ȏ��͂����R1�������Ēǂ������Ēǉ��U������Ƃ����B
								if (GetRand(10) < 4) {
									playerattackhanndou2B = playerattackhanndou2B - 20;
									playerattackhanndou3B = playerattackhanndou3B - 10;// playerattackhanndou3��Y���ɐ�����΂����߂̕ϐ��B
								}
								//�R���{
								++conbocount;
								enemyzannzoulockBframe = 1;//����̃_���[�W��H������ۂ̋��݂������ɖ߂�����
								stayhere2frame = 1;

								enemy2sabunHPpoint = enemy2sabunHPpoint + 20;
								bloodMove = 1;
							}
						}
						//sennkounyuuryokubunnki3 = 0;
						//attackframe3 = 0;//����2�o�[�W�������������Œl�����̂܂܂��ƉE�������������ŉ���o�[�W����3���ł��Ă��܂��̂ŁB
						//������2�ɕ��򂵂��ꍇ�͉���3�̏������ׂ�0�ɂ���B
						//attackframe = 0;//����2�������������邩�͕ʂɂ��̃t���[���̎��Ɉ�U0�ɂ����X�{�^������̃R���{���Ȃ���₷���B



					//�����̐�s���͂ɐ�������Ɖ���o�[�W����3�ɑ����B
					//�������̃t���[�������傤�ǂ����B

					}



					//���U���̍ۂ�A�{�^���̃v���O�����B
					if (Pad[PAD_1] == 1 && motonomasunimodoru > 0 && nextattack == 0) {
						//zannzoulock = 1;
						KONNBO1Aframe = 0;//������0�ɂ��邱�Ƃŕ`��̃L�b�N������O�̉摜��`��ł��Ȃ悤�ɂ����B
						KONNBO1Bframe = 0;
						KONNBO1A = 0;//�ʂ̃R���{�ɐi�񂾂��߁A�l��0�ɂ���B//���ӁA�܂��摜�����Ă��Ȃ��̂ŉ����\������Ȃ��B
						KONNBO1B = 0;//�ʂ̃R���{�ɐi�񂾂��߁A�l��0�ɂ���B//���ӁA�܂��摜�����Ă��Ȃ��̂ŉ����\������Ȃ��B
						sennkounyuuryokubunnki3 = 1;//�����̐�s���͂ɐ�������Ɖ���o�[�W����3�ɑ����B
				//		LEFTmark = 2;//�m�F�̂��߂ɁB
				//		addattacktime = 300;//���R���{�̂Ȃ��Ƃ��āA����3�̃R���{������ȉ߂���̂�����̂ŁB
						//��addattacktime = 50�ł͒Z���ē��͂���������attackframe3���オ���Ă�addattacktime��0�ɂȂ��Ă��܂����̃}�X�ɖ߂��Ă��܂�����3���o���Ȃ������B
						sennkounyuuryokubunnki = 0;//����2�ɍs���Ȃ��l�ɂ��邽�߁B
						attackframe2 = 0;//����3�ɍs�����ۂɁAattackframe2��0�ɂȂ�悤�ɂ���B���R���{�̍ۂ͂ق��̃t���[���͊֌W�Ȃ��̂�0�ɂ���B
						attackframe3 = 1;
						nextattack = 1;
						nagurukasanaru = 0;
						KONNBO1kasanaru = 0;
						KONNBO2kasanaru = 0;
					}


					if (sennkounyuuryokubunnki3 == 1) {
						++attackframe3;//�����ƒl���オ���Ă���A
						//attackframe2 = 0;//�����̉���2�Ɉ����|����A����3����͂���ۂɉ���2���łȂ��悤�ɂ���B
						//attackframe3�̃t���[�����ɉE���͂���������Ή���3�o�[�W�������ł���B
						attackframe2 = 0;//�����ł̃A�^�b�N�t���[��2�͉���3�ɂ͊֌W�Ȃ��̂�0�ɂ���B
						//�����ɖ��͂Ȃ��B�����������Ă�attackframe3��300�ɍs���O�ɍ��̓��͂�attackframe3��0?�ɂȂ��Ă����B
						//�����OK�B
					}

					if (migimuki == 1) {
						if (attackframe3 > 5 && attackframe3 < 100) {//attackframe3>0����ɂ���ƑO�̍��ɂ͂����������ŉE���͂����Ă��܂��ŏ��̃t���[���͈̔͂ɔ������邱�ƂŁA�ȒP�ɃR���{���o����̂ŁA���ɂ͂����������ł͔������Ȃ��l�ɔ͈͂�attackframe3>20����ɂ����B����œ��͂��덷���Ȃ�����o�����B
							if (Pad[PAD_LEFT] == 1) {
								++attackframe4;
							}
						}
						//if (attackframe5 > 0 && ++attackframe5 > 0) {
						if (attackframe4 > 50 && attackframe4 < 110) {
							if (Pad[PAD_RIGHT] == 1) {
								//�G1�ւ̓��̍U���B
								if (kougekiKANOU == 2) {//���̃R���{�͂��ɂ������߁A�����ɔ͈͂������Ă���v���O�����̕��������B
									point2 = 100;
									playerHPlock = 1;
									RIGHTmarklock = 1;
									//attackframe2 = 0;
									enemysabunHPB = 100;
									lockmark = 1;
									sinnzoubyouga = 1;
									LEFTmark2 = 890;
									//addattacktime = addattacktime + 100;
									//attackframe = 1;//�ǉ��̉���U�����ł���悤�ɂ�����1�ɖ߂��B
									attackframe3 = 0;//�ǉ��̉���U�����ł���悤�ɂ�����0�ɖ߂��B
									attackframe4 = 0;
									++attackframe5;
									kougekilock = 1;
									stayherelock = 1;//�G��HP���������߂ɕK�v�ȕϐ�
									sennkounyuuryokubunnki3 = 0;//�Ăщ���2�Ȃǂ��ł���悤�ɂ��邽�߂ɂ�����0�ɂ���B
									naguru3sound = LoadSoundMem("damage03.m4a");
									PlaySoundMem(naguru3sound, DX_PLAYTYPE_BACK);
									//++attackframe4;
									//sennkounyuuryokubunnki = 0;//���ǉ��̉���U�����ł���悤�ɁB�ǉ�����Ɍq����ƁA�Ăщ���2�≣��3���ł��邽�߁B
									playerattackhanndou = playerattackhanndou + 5;

									kakuninn = 20;//ememydontmovetime = 1;
									//�R���{
									++conbocount;
									enemyzannzoulockframe1 = 1;//����̃_���[�W��H������ۂ̋��݂������ɖ߂�����
									stayhereframe = 1;
									nextattack = 0;
									enemysabunHPpoint = enemysabunHPpoint + 50;
									bloodMove = 1;
									StartJoypadVibration(DX_INPUT_PAD1, 2000, 150);
								}
							}
						}
					}
					else if (hidarimuki == 1) {
						if (attackframe3 > 5 && attackframe3 < 100) {//attackframe3>0����ɂ���ƑO�̍��ɂ͂����������ŉE���͂����Ă��܂��ŏ��̃t���[���͈̔͂ɔ������邱�ƂŁA�ȒP�ɃR���{���o����̂ŁA���ɂ͂����������ł͔������Ȃ��l�ɔ͈͂�attackframe3>20����ɂ����B����œ��͂��덷���Ȃ�����o�����B
							if (Pad[PAD_RIGHT] == 1) {
								++attackframe4;
							}
						}
						//if (attackframe5 > 0 && ++attackframe5 > 0) {
						//���������͏��������܂ł𒷂߂ɂ����B
						if (attackframe4 > 50 && attackframe4 < 110) {
							if (Pad[PAD_LEFT] == 1) {
								if (kougekiKANOU == 2) {//���̃R���{�͂��ɂ������߁A�����ɔ͈͂������Ă���v���O�����̕��������B
									playerHPlock = 1;
									RIGHTmarklock = 1;
									//attackframe2 = 0;
									enemysabunHPB = 100;
									lockmark = 1;
									sinnzoubyouga = 1;
									//addattacktime = addattacktime + 100;
									//attackframe = 1;//�ǉ��̉���U�����ł���悤�ɂ�����1�ɖ߂��B
									attackframe3 = 0;//�ǉ��̉���U�����ł���悤�ɂ�����0�ɖ߂��B
									attackframe4 = 0;
									++attackframe5;
									kougekilock = 1;
									stayherelock = 1;//�G��HP���������߂ɕK�v�ȕϐ�
									sennkounyuuryokubunnki3 = 0;//�Ăщ���2�Ȃǂ��ł���悤�ɂ��邽�߂ɂ�����0�ɂ���B
									naguru3sound = LoadSoundMem("damage03.m4a");
									PlaySoundMem(naguru3sound, DX_PLAYTYPE_BACK);
									//++attackframe4;
									//sennkounyuuryokubunnki = 0;//���ǉ��̉���U�����ł���悤�ɁB�ǉ�����Ɍq����ƁA�Ăщ���2�≣��3���ł��邽�߁B
									playerattackhanndou = playerattackhanndou - 5;
									kakuninn = 21;
									//ememydontmovetime = 1;
									//�R���{
									++conbocount;
									enemyzannzoulockframe1 = 1;//����̃_���[�W��H������ۂ̋��݂������ɖ߂�����
									stayhereframe = 1;
									nextattack = 0;
									enemysabunHPpoint = enemysabunHPpoint + 50;
									bloodMove = 1;
								}
							}
						}
					}
					//}
					//�G2�ɑ΂���E�����̓��U���B
					if (migimuki == 1) {
						if (attackframe3 > 5 && attackframe3 < 100) {//attackframe3>0����ɂ���ƑO�̍��ɂ͂����������ŉE���͂����Ă��܂��ŏ��̃t���[���͈̔͂ɔ������邱�ƂŁA�ȒP�ɃR���{���o����̂ŁA���ɂ͂����������ł͔������Ȃ��l�ɔ͈͂�attackframe3>20����ɂ����B����œ��͂��덷���Ȃ�����o�����B
							if (Pad[PAD_LEFT] == 1) {
								++attackframe4;
							}
						}
						//else if(attackframe3 > 20 && attackframe3 < 40 && kougekiKANOU == 3) {//attackframe3>0����ɂ���ƑO�̍��ɂ͂����������ŉE���͂����Ă��܂��ŏ��̃t���[���͈̔͂ɔ������邱�ƂŁA�ȒP�ɃR���{���o����̂ŁA���ɂ͂����������ł͔������Ȃ��l�ɔ͈͂�attackframe3>20����ɂ����B����œ��͂��덷���Ȃ�����o�����B
						//	if (Pad[PAD_LEFT] == 1) {
						//		++gardframe;
						//	}
						//}
						//if (attackframe5 > 0 && ++attackframe5 > 0) {
						if (attackframe4 > 50 && attackframe4 < 110) {
							if (Pad[PAD_RIGHT] == 1) {
								if (kougekiKANOU == 3) {//���̃R���{�͂��ɂ������߁A�����ɔ͈͂������Ă���v���O�����̕��������B
									point = 123;
									playerHPlock = 1;
									RIGHTmarklock = 1;
									//attackframe2 = 0;
									AenemysabunHPB = 100;
									lockmark = 1;
									sinnzoubyouga = 1;
									attackframe3 = 0;//�ǉ��̉���U�����ł���悤�ɂ�����0�ɖ߂��B
									attackframe4 = 0;
									++attackframe5;
									kougekilock = 1;
									stayherelock = 1;//�G��HP���������߂ɕK�v�ȕϐ�
									sennkounyuuryokubunnki3 = 0;//�Ăщ���2�Ȃǂ��ł���悤�ɂ��邽�߂ɂ�����0�ɂ���B
									naguru3sound = LoadSoundMem("damage03.m4a");
									PlaySoundMem(naguru3sound, DX_PLAYTYPE_BACK);
									//++attackframe4;
									sennkounyuuryokubunnki = 0;//���ǉ��̉���U�����ł���悤�ɁB�ǉ�����Ɍq����ƁA�Ăщ���2�≣��3���ł��邽�߁B
									//ememydontmovetime = 1;
									playerattackhanndouB = playerattackhanndouB + 5;
									//�R���{
									++conbocount;
									enemyzannzoulockBframe = 1;//����̃_���[�W��H������ۂ̋��݂������ɖ߂�����
									stayhere2frame = 1;
									nextattack = 0;
									enemy2sabunHPpoint = enemy2sabunHPpoint + 50;//����𐁂���΂����߂̕��B
									bloodMove = 1;
								}
							}
						}
					}

					else if (hidarimuki == 1) {
						if (attackframe3 > 5 && attackframe3 < 100) {//attackframe3>0����ɂ���ƑO�̍��ɂ͂����������ŉE���͂����Ă��܂��ŏ��̃t���[���͈̔͂ɔ������邱�ƂŁA�ȒP�ɃR���{���o����̂ŁA���ɂ͂����������ł͔������Ȃ��l�ɔ͈͂�attackframe3>20����ɂ����B����œ��͂��덷���Ȃ�����o�����B
							if (Pad[PAD_RIGHT] == 1) {
								++attackframe4;
							}
						}
						//else if(attackframe3 > 20 && attackframe3 < 40 && kougekiKANOU == 3) {//attackframe3>0����ɂ���ƑO�̍��ɂ͂����������ŉE���͂����Ă��܂��ŏ��̃t���[���͈̔͂ɔ������邱�ƂŁA�ȒP�ɃR���{���o����̂ŁA���ɂ͂����������ł͔������Ȃ��l�ɔ͈͂�attackframe3>20����ɂ����B����œ��͂��덷���Ȃ�����o�����B
						//	if (Pad[PAD_LEFT] == 1) {
						//		++gardframe;
						//	}
						//}
						//if (attackframe5 > 0 && ++attackframe5 > 0) {
						if (attackframe4 > 50 && attackframe4 < 110) {
							if (Pad[PAD_LEFT] == 1) {
								if (kougekiKANOU == 3) {//���̃R���{�͂��ɂ������߁A�����ɔ͈͂������Ă���v���O�����̕��������B
									playerHPlock = 1;
									RIGHTmarklock = 1;
									//attackframe2 = 0;
									AenemysabunHPB = 100;
									lockmark = 1;
									sinnzoubyouga = 1;
									attackframe3 = 0;//�ǉ��̉���U���ł���悤�ɂ�����0�ɖ߂��B
									attackframe4 = 0;
									++attackframe5;
									kougekilock = 1;
									stayherelock = 1;//�G��HP���������߂ɕK�v�ȕϐ�
									sennkounyuuryokubunnki3 = 0;//�Ăщ���2�Ȃǂ��ł���悤�ɂ��邽�߂ɂ�����0�ɂ���B
									naguru3sound = LoadSoundMem("damage03.m4a");
									PlaySoundMem(naguru3sound, DX_PLAYTYPE_BACK);
									//++attackframe4;
									sennkounyuuryokubunnki = 0;//���ǉ��̉���U�����ł���悤�ɁB�ǉ�����Ɍq����ƁA�Ăщ���2�≣��3���ł��邽�߁B
									//ememydontmovetime = 1;
									playerattackhanndouB = playerattackhanndouB - 5;
									//�R���{
									++conbocount;
									enemyzannzoulockBframe = 1;//����̃_���[�W��H������ۂ̋��݂������ɖ߂�����
									stayhere2frame = 1;
									nextattack = 0;
									enemy2sabunHPpoint = enemy2sabunHPpoint + 50;
									bloodMove = 1;
								}
							}
						}
					}
					//}

						//if (gardframe > 0 && ++gardframe < 100 && kougekiKANOU == 3) {

						//}
						//if (gardframe > 100) {
						//	gardframe = 0;
						//}
				}

			}

		}


		//R2�������Ȃ��ꍇ�B
		/*if (input.RightTrigger == 0) {
			if (RightTriggerlock == 0) { playermovelock = 0; }
			lock = 0;
			lockmarkyokoidou = 0;
			lockmarktateidou = 0;
			jyuuzikeysousa2 = 0;
			playerkonntororulock = 0;
		}*/


		//�L�b�N�̃R���{���o���Ȃ������ꍇ�͂��ׂ�0�ɖ߂�B//�ȑO��kougekiKANOU�̒l�������ɓ���Ă������߁A���̏����̎��łȂ���
		//sennkounyuuryokubunnki��0�ɂȂ炸�A1�̂܂܂ł��������߁A�ړ��̐�́u���v�̃R�}���h�ɂ���ăL�b�N���o�Ă��܂��Ă����B
		if (attackframe2 > 40) {
			sennkounyuuryokubunnki = 0;
			attackframe2 = 0;
			playerHPlock = 0;
			kougekiKANOU = 0;
			zannzoulock = 0;
			nextattack = 0;//�L�b�N��ɍĂуL�b�N�ł���悤�ɁB
			kasurikeri = 0;//�����蔻��ł̃L�b�N��������0�ɂ���B
		}
		if (attackframe2 > 0 && ++attackframe2 > 40 && kougekiKANOU == 0) {
			attackframe2 = 0;
		}
		if (attackframe3 > 60) {
			sennkounyuuryokubunnki3 = 0;
			attackframe3 = 0;
			zannzoulock = 0;
			playerHPlock = 0;
			kougekiKANOU = 0;
			nextattack = 0;//�L�b�N��ɍĂуL�b�N�ł���悤�ɁB
		}
		if (attackframe3 > 0 && ++attackframe3 > 60 && kougekiKANOU == 0) {
			attackframe3 = 0;
		}
		if (attackframe4 > 120) {
			attackframe4 = 0;
			zannzoulock = 0;
			playerHPlock = 0;
			nextattack = 0;
			//playermovelock = 0;//�O�̂��߂ɁB//�G�ɍU�����ꂽ�ۂɎ�l���̍U�����~�ނ悤��
			//attackframe4��50�ɂȂ�悤�ɏ��������߁A�����ɂ��Ă��܂��A�X���C�h���Ȃ̂�playermovelock�ɂȂ�A�ʏ�ړ����삪�łĂ��܂��A
			//�}�X�ɋA���Ă������Ƀo�O��̂ŁA�����ɂ͏����Ȃ��B
		}//������������kougekiKANOU��0�̎��Ƀt���[�������܂�A�딭���邩������Ȃ��̂ł�����0�̏ꍇ�������Ēu���B
		if (attackframe4 > 0 && ++attackframe4 > 110 && kougekiKANOU == 0) {
			attackframe4 = 0;
			zannzoulock = 0;
		}
		if (attackframe5 > 50) {
			attackframe5 = 0;
			zannzoulock = 0;
			playerHPlock = 0;
		}
		if (attackframe5 > 0 && ++attackframe5 > 50 && kougekiKANOU == 0) {
			attackframe5 = 0;
		}

		//�L�b�N�̌딭��h�����߂̕����B
		if (motonomasunimodoru == 0) {
			if (attackframe2 > 0) {
				attackframe2 = 0;
				sennkounyuuryokubunnki = 0;
			}
		}



		//�e���g�����U��
		if (Gunkirikae == 0) {
			if (Gfunction_status == 0) {

				if (pos[enemyY1][enemyX1][1] + 20 + playerattackhanndou3 >= pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 &&
					pos[enemyY1][enemyX1][1] - 20 + playerattackhanndou3 <= pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
					) {
					tyokusennkougeki = 1;

				}
				else if (pos[enemyY2][enemyX2][1] + 20 + playerattackhanndou3B >= pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 &&
					pos[enemyY2][enemyX2][1] - 20 + playerattackhanndou3B <= pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
					) {
					tyokusennkougeki = 2;


				}






				if (jyuuosenai == 0) {
					// Gkey == 1�͂���Ȃ��悤�Ɏv����B//Pad[PAD_6] == 1��R1�{�^��
					//����lock��0�̎��Ə����Ă��邽�߁A���b�N�}�[�N�Ō��ꍇ�ƍ��ʉ��ł��Ă���B
					if (Pad[PAD_3] == 1 && Gcount >= 1 && Gtime == 0 && Gkey == 1 && Pad[PAD_5] == 0 &&
						Pad[PAD_6] == 0 && lock == 0 && sousakanou == 0 && nextattack == 0)
					{//�u�E�v�͍������ꂽ
					  //�u�E�v�������ꂽ�Ƃ��̏���
						zannzoulock = 1;
						Gtime = 1; //�e�������Ă���̌o�ߎ��Ԃ�1�ɂ���
						Gcount = Gcount - 1; //�c�e����-1����
						//playerImage = playerGHandle[0];	//�^���ʂ̏�Ԃɂ���
						//sound2 = LoadSoundMem("�^�C�g���̏e��.mp3");
						//PlaySoundMem(sound2, DX_PLAYTYPE_NORMAL);
						sound2 = LoadSoundMem("�^�C�g���̏e��.mp3");
						//PlaySoundMem(sound2, DX_PLAYTYPE_BACK);
						StartJoypadVibration(DX_INPUT_PAD1, 2800, 200);
						PlaySoundMem(sound2, DX_PLAYTYPE_BACK);

						++SHOTbyouga;

						nextattack = 1;
						playerHPlock = 1;
						//nanameidouX = nanameidouX - 0;
						tabakosuenai = 1;//�����Ƀ^�o�R���z���Ȃ��悤�ɁB

						//<���d�v��>
						//���G�͏�Ɉړ����Ă��邽�߃_���[�W��^�������G��Y�̎��̏����g��Ȃ��ƈӖ����Ȃ��A
						//�e�̓_���[�W��^�������G��Y����_���Ă���̂�����B
						//Y���͓G1�ɂ��āA��l���ƓG1������Y���W�ɂ���B
						//X������l�����G2���G1�̏��ɏ�����Ă���B//����l�����G2�ɑ������čU������̂�Y�����G1�ł��邽�߁A�������B
					/*if (migimuki == 1 && pos[enemyY1][enemyX1][1] + 20 + playerattackhanndou3 >= pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 &&
						pos[enemyY1][enemyX1][1] - 20 + playerattackhanndou3 <= pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
						&& pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 >= pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 - 15
						&& pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 >= pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B
						&& pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 <= pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B
						)
					{

						kougekiKANOU = 10;
						GenemysabunHP = 40;
						point = 130;

					}*/



						


























					//������������͉E�����̓G1��Y���ƓG2��Y���̎�l�����G1�Ƀ_���[�W��^���镔���ɂȂ�B
						//����if���͓G1��G2���܂����ōU�����ă��A�ђʂ��Ăӂ���̓G�ɍU�����Ȃ��悤�ɂ�����A����Y���ɂӂ���G�����鎞��
						//��l���̌��������̓G�����ɍU���𓖂Ă��悤�ɂ��邽�߂̃v���O�����ł���B




						int a = pos[enemyY1][enemyX1][1] + playerattackhanndou3;
						int b = pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3;

						int c = pos[enemyY1][enemyX1][0]
							+ playerattackhanndou + playerattackhanndou2 + playerattackhanndou3;
						int d = pos[playerY][playerX][0]
							+ nanameidouX + migiidou + nanameidouX2 + nanameidouX3;
						int e = pos[enemyY2][enemyX2][0]
							+ playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B;

						if (a + 15 >= b && a - 15 <= b) {
							tyokusennkougeki = 1;
							if (tyokusennkougeki == 1) {
								if (c >= d - 15 && c <= e && d <= e ||
									c >= d - 15 && c >= e && d >= e ||
									c >= d - 15 && c >= e && d <= e ||
									c >= d - 15 && c >= e && d >= e) {

									kougekiKANOU = 10;
									GenemysabunHP = 40;
									point = 123;
								}
							}
						}
						a = pos[enemyY2][enemyX2][1] + playerattackhanndou3B;
						if (a + 15 >= b && a - 15 <= b) {
							tyokusennkougeki = 2;
							if (tyokusennkougeki == 2) {
								if (c >= d - 15 && c >= e && d <= e ||
									c <= d - 15 && c <= e && d <= e ||
									c >= d - 15 && c <= e && d <= e ||
									c <= d - 15 && c <= e && d >= e) {

									kougekiKANOU = 10;
									AGenemysabunHP = 40;
									point = 123;
								}
							}
						}
						else {
							tyokusennkougeki = 0;
						}











						

					}
					//������̃��b�N���Ȃ��ŏe�����v���O�����Ɠ����悤�ȏ������Ɣ���Ă��܂��A�������������Ȃ��̂ŏ�����ς����B
					//�����b�N����1�Ƃ������߁A//�U�����肻�̈�(�e�ɂ��U������)���ǂ��Ȃ邩�킩�炸�A�G�����Ȃ��Ƃ���ɂ��e�����Ă��B
					//�����āAhannilock == 2�ł��ǂ����̏ꍇ�������Ă��Ȃ��̂ŉ��̂悤��if���Ŕ͈͂������B�łȂ��Ɣ͈͂Ɋ֌W�Ȃ�
					//�����������ő����HP�������Ă��܂��B
					if (lock == 1) {
						if (Pad[PAD_3] == 1 && Gcount >= 1 && Gtime == 0 && sousakanou == 0 && nextattack == 0)
						{//�u�E�v�͍������ꂽ
						  //�u�E�v�������ꂽ�Ƃ��̏���
							Gtime = 1; //�e�������Ă���̌o�ߎ��Ԃ�1�ɂ���
							Gcount = Gcount - 1; //�c�e����-1����
							//playerImage = playerGHandle[0];	//�^���ʂ̏�Ԃɂ���
							//LEFTmark = 989;
							//sound2 = LoadSoundMem("�^�C�g���̏e��.mp3");
							//PlaySoundMem(sound2, DX_PLAYTYPE_BACK);
							StartJoypadVibration(DX_INPUT_PAD1, 2800, 200);
							nextattack = 1;
							playerHPlock = 1;
							jyuuzikeysousa2 = 1;
							if (kougekiKANOU == 1) {
								kakuninn = 24;
								GenemysabunHP = 50;
								R1attackframe = 0;
								//�R���{
								++conbocount;//if (Pad[PAD_3] == 1 && Gcount >= 1 && Gtime == 0 && sousakanou == 0 && nextattack == 0)���l�����Ă��邽�߈�C�ɑ������A�ł��ē��������������J�E���g�����B
								enemyzannzoulockframe1 = 1;
								stayhereframe = 1;
								enemysabunHPpoint = enemysabunHPpoint + 5;
							}
							if (kougekiKANOU == 4) {
								AGenemysabunHP = 50;
								R1attackframe = 0;
								//�R���{
								++conbocount;
								enemyzannzoulockBframe = 1;
								stayhere2frame = 1;
								enemy2sabunHPpoint = enemy2sabunHPpoint + 5;
							}
							else if (kougekiKANOU == 0) {
								GenemysabunHP = 0;
								R1attackframe = 0;
							}
						}
					}

				}


				if (Gtime > 0) { //�e�������Ă���̌o�ߎ��Ԃ�0���傫���ꍇ�̂�
					++Gtime; //�e�������Ă���̌o�ߎ��Ԃ�+1����
					//jyuuosenai = 1;
					// = 90911;
					KENJYUUgazou = 1;
					if (Gtime == 20) { //�e�������Ă���P�b( 60 )�o�߂�����
					//playerImage = playerGHandle[0]; //���������̏�Ԃɂ���
					}
					if (Gtime == 40) { //�e�������Ă���Q�b( 120 )�o�߂�����
						//playerImage = playerGHandle[0];	//�E�������̏�Ԃɖ߂�
						Gtime = 0; //�e�������Ă���̌o�ߎ��Ԃ�0�ɖ߂�
						//jyuuosenai = 0;
						DrawExtendGraph(0, 0, 1770, 980, SHOTHandle, FALSE);
						playerattackhanndou = 0;
						playerattackhanndouB = 0;
						nanameidouX = 0;
						nextattack = 0;
						KENJYUUgazou = 1;
						zannzoulock = 0;
						playerHPlock = 0;

						R1lock = 0;


					}
				}

				///if (Gcount <= 0) { Gcount = 0; }//�����ɂ����Gcount�����̒l�ɐi�܂��ɂ���B
				if (Gcount <= 0) {	//�e�̒e�̐���0�ȉ���������
					Gcount = 0;
					GcountA = 1;//�����[�h����`�悷�邽�߂ɍ�����ϐ�
					++GcountZeroCounter;	//�w�e�̒e��0�ɂȂ��Ă���o�߂����t���[�������J�E���g����ϐ��x��+1����
					if (GcountZeroCounter >= 2000) {	//�e�̒e��0�ɂȂ��Ă���o�߂����t���[������15�b( 60 �~ 15 )�o�߂�����
						Gcount = 13;	//�e�̒e�̐���15�ɑ��₷
						GcountZeroCounter = 0;	//����̃J�E���g�����̂��߂Ɂw�e�̒e��0�ɂȂ��Ă���o�߂����t���[�������J�E���g����ϐ��x��0�ɂ���
						GcountA = 0;
					}
				}
			}//if (Gfunction_status == 0)��{}�ł���B



		}




		//�^�o�R��
		//�������܂܂ł͂����Ɖ񕜂���̂ŕϐ�tabakokirikae������B
		if (motonomasunimodoru == 0) {//�����U���Ɣ��̂ł����ŏ�����t�����B
			if (tabakosuenai == 0) {
				if (tabakolock == 0 && lock == 0 && masusave == 0) {
					if (
						(PrevPadState & PAD_INPUT_1 && nextattack == 0) != 0  //�O��͉�����Ă���
						&&  //����
						(CurrPadState & PAD_INPUT_1 && nextattack == 0) != 0  //����͉�����Ă���
						)
					{
						tabakocount = 1;
						R1lock = 1;//���e�R���{�̂��߂ɉ�����1�ɂ���B
						playermovelock2 = 1;
						playerHPlock = 1;
						nextattack = 1;

						//�v���C���[��HP��������̐��l�ȉ��ɐ�������_���[�W���󂯂��ʏ��Ԃ̉摜�ɑ���B
						//if (playerHP < 400) {
						//	playerHPlock = 1;
						//}
						if (playerY == enemyY - 1 && playerX == enemyX) {
							kasanarulockA = 1;
							tabakosutterulock = 1;
						}
						if (playerY == enemyY + 1 && playerX == enemyX) {
							kasanarulockA = 2;

						}
					}

					//B�{�^�����������ۂ�1�ɏオ��̂ŁA��������B�{�^���𗣂����ۂɒʏ�`��ɂ����ق����ړ�����zannzoulock�ɉe�������Ȃ��̂ł���ł����B
					if (tabakocount > 0) {

						//playerHPlock = 0;
						if (
							(PrevPadState & PAD_INPUT_1) == 0  //�O��͉�����Ă��Ȃ�
							&&  //����
							(CurrPadState & PAD_INPUT_1) == 0  //����͉�����Ă��Ȃ�
							)
						{
							tabakocount = 0;
							tabakocount2 = 0;

							tabakokirikae = 0;
							zannzoulock = 0;//�r���Ń{�^���̓��͂��r�؂ꂽ���l���̉摜�����ɖ߂�B
							kasanarulock = 0;//�G�Əd�Ȃ��ēr���ŋz���̂���߂Ă��G�ɏ㏑������Ȃ��悤�ɁB
							//tabakogazoulock = 0;//�r���Ń{�^���̓��͂��r�؂�Ă��^�o�R���z���摜���`�悳���悤��0�ɂ���B
							R1lock = 0;
							playerHPlock = 0;//if (tabakocount > 0)�̎��ɁAPAD_INPUT_1��������Ă��Ȃ��Ƃ��͂�����0�ɂ���B
							tabakosutterulock = 0;
							playermovelock2 = 0;
							nextattack = 0;
						}
					}
				}


				if (tabakocount > 0) {
					++tabakocount2;
					zannzoulock = 1;//�U���摜���łĂ�Ƃ��͒ʏ�̉摜�������̂Œl��1�ɕύX����B

				}
				if (tabakocount2 > 0 && tabakocount2 < 200) {
					playerHPlock = 1;
				}
				if (tabakocount2 == 1) {
					tabakosound = LoadSoundMem("Hit01-1.mp3");
					PlaySoundMem(tabakosound, DX_PLAYTYPE_BACK);
				}
				if (tabakocount2 > 200) {
					playerHP = playerHP + 50;
					tabakocount = 0;
					tabakocount2 = 0;
					tabakokirikae = 1;
					tabakokaihukumark = 1;
					zannzoulock = 0;
					kasanarulock = 0;
					tabakogazoulock = 0;
					playermovelock = 0;
					R1lock = 0;
					playerHPlock = 0;
					tabakosutterulock = 0;
					nextattack = 0;
				}

			}
		}
		//�����܂ł���l���̍U���̃v���O�����B




















		//�G����_���[�W���󂯂��ۂɓG�����ފ��Ԃ������������B
		//if (ememydontmovetime == 1) {
		//	++ememydontmovetimeframe;
		//	stayhere = 1;
		//}
		//if (ememydontmovetimeframe > 500) {
		//	ememydontmovetime = 0;
		//	ememydontmovetimeframe = 0;
		//	stayhere = 0;
		//}

		//R����x�����ꂽ��Ńt���[���𗘗p���ă��[�v�����邽�߂�if����V�����O�ɏ������̂��B
		//���G�̈ړ���������������pre2enemyX = enemyX;��t�������āA�ȑO�ɏ���������Y���W�ɂ�������̎��ɑO��X���W��pre2enemyX�ɓ���Ȃ��Ə�����
		//��l���������Ȃ��ꍇ�͂��̏������甲���Ȃ����߁A�ȑO�Ɠ������W�̃f�[�^�̂܂܂Ȃ̂�if (enemyX != pre2enemyX)�̏�����ʂ�Ȃ������B
		//�Ȃ̂Ł��ɏ������悤�ɓ���Y���W�ȊO�ł͂Ȃ��G���ړ������X���W���X�V�����悤�ɏ�����enemyX != pre2enemyX�̏�����ʂ�̂œG�̈ړ���`����������pre2enemyX = enemyX;��t���������B
		//���Ȃ݂ɁAif (Pad[PAD_6] == 1�̒��ɏ������ۂ�Pad[PAD_6] == 1�͈�u���������Ȃ��̂ŏ���enemyX != pre2enemyX�ɂ͈�u�����ʂ�Ȃ��̂ł܂�ŏ������ʂ��Ă��Ȃ��l�Ɍ������B










		//������l�ɓG�Ɋւ��Ẵ_���[�W

		//�Ƃ肠�����A�U���̍Œ����オ��悤��if (addattacktime == 501){}�̊O��if�����o�����B


		//�L�[L���������܂ܕʂ̃L�[�������ƕ��킪�؂�ւ��



		//�G�̍U����ړ��Ȃǂ̕����B
		if (stayhere == 0) {// �G�̈ړ�
			int t = GetNowCount();
			//pre2enemyX = enemyX;//�����ɏ��������Ƃŕϐ�pre2enemyX�ɓG��X���W������B
			if (t >= nextMoveTime) { // �w��̎��Ԃ��o������(1s���Ƃ�)
				nextMoveTime = t + MOVE_INTERVAL; // ����ړ����������鎞��
				if (stopCount > 0) { // ��~���̂Ƃ�
					stopCount--; // �~�܂��Ă���c�莞��(��)�����炷
				}

				else { // 9�}�X��̂����ꂩ�̃p�l���Ɉړ�������
					int cy = enemyY1, cx = enemyX1;
					do {
						enemyidou2 = GetRand(10);
						if (enemyidou2 > 2) {
							enemyY1 = GetRand(2);
							enemyX1 = GetRand(2) + 3;

							//�ړ������猳�̃}�X�ɖ߂�悤�ɂ���B
							playerattackhanndou = 0;
							playerattackhanndou2 = 0;
							playerattackhanndou3 = 0;
							enemyKENJYUUcount = 0;
							//kericount = 0;
							//yokkerucouunt = 0;
						}
						//���̏�Ɏ~�܂�m��
						if (GetRand(10) < 5) { // ���܂�(70%�̊m����)
							stopCount = GetRand(1); // ���b��(0�b��)���̏�Ɏ~�܂�
						}
						//�G�̈ړ���Ɏ�l���������ꍇ�͍ēx�ړ����I�Ԃ悤�ɂ�����B
						if (cy == playerY && cx == playerX) {
							enemyY1 = GetRand(2);
							enemyX1 = GetRand(2) + 3;
						}
						//��l�̓G��������̏|��ɂ������΂Ȃ��悤�ɂ��邽�߂̕����B
						//�Ȃ���Y���W���������W�̎��̓t���[�Y����̂ł����œ������W�ɂȂ�Ȃ��悤�ɂ���B
						else if (pos[enemyY1][enemyX1][1] == pos[enemyY2][enemyX2][1]) {
							enemyY1 = GetRand(2);
							enemyX1 = GetRand(2) + 3;
							enemyY2 = GetRand(2);
							enemyX2 = GetRand(2) + 3;
						}


					} while (enemyX1 == cx && enemyY1 == cy ||
						enemyX1 == playerX && enemyY1 == playerY);

					//enemyImage = enemyGHandle[10];

				}

				
				if (ranndamulock == 0) {
					ranndamukougeki = GetRand(5);//���m���̊Ԋu���������ƓG�`�悳��Ȃ��o�O���N����̂ŏ���ł����B
					
				}
				
			
				//�E����̉���U��
				if (ranndamukougeki == 1 or ranndamukougeki == 3) {//GetRand(30) < 30�Ƃ���ƍU������r���ł�߂���A�J�E���^��2�𒴂��ďオ���Ă��܂����肷��B
					ranndamulock = 1;//�͈͂��d�Ȃ�Ƃ�������l���ƓG�̈ʒu���ς��悤�ɂ����B�𖳌��ɂ��邽�߂�1�ɂ����B
					++enemyattack;
					enemyzannzoulock2 = 1;//��enemyzannzoulock = 1;�Ə����Ă�������U���摜�Ɠ����ɒʏ��Ԃ��`�悳��Ă����B��������enemyzannzoulock2 = 1;�ł���
					//���܂܂ł����Ɠ��������ۂ��������̂͌���ēG1�̍U���摜��`�悷�邽�߂�
					//if����zannzoulock�������Ă�����A
					//���̑��̍U�����̂����Ƃ���zannzoulock�������ĐF��ȏ��ɏ����Ă���enemyzannzoulock�����܂���ɓ����Ă������炾�낤�B
					//�v��enemyzannzoulock�͊ԈႢ�ŁA��������enemyzannzoulock2�ł��邽�߁B
					
					ENEMYkougekigazouA2frame = 0;//�������Ń����_����if���ɂ��0�ɖ߂邱�Ƃ�30�̂܂܂�����
					//���߂Ă̓G�̍U���������_����0�ɂȂ��Ă�if���ɂ��l���オ��̂Ŗ��Ȃ��G�͍U���ł���B

					//���G���U�����鎞�͐Ԃ��G�̍U�����~�߂Ă����B
					stayhere2 = 1;
					if (enemyattack > 0 && enemyattack < 2) {//if (enemyattack == 1)�͕ʂɂ���Ȃ��B
						preenemyX = pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 100;
						preenemyY = pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5;
						++enemycount;
						ENEMYkougekigazouA1 = 1;
						kasanarulock = 1;//���d�Ȃ�摜�Ɋւ��Ẵv���O�����ɂ��ʏ��Ԃ̓G���`�悳��Ȃ��悤�ɁA�����Œl��1�ɂ���B
						enemyattack = 0;
					}
				}
				//������̉���U��
				else if (ranndamukougeki == 2 or ranndamukougeki == 4) {//GetRand(30) < 30�Ƃ���ƍU������r���ł�߂���A�J�E���^��2�𒴂��ďオ���Ă��܂����肷��B
					ranndamulock = 1;//�͈͂��d�Ȃ�Ƃ�������l���ƓG�̈ʒu���ς��悤�ɂ����B�𖳌��ɂ��邽�߂�1�ɂ����B
					++enemyattack;
					enemyzannzoulock2 = 1;
					ENEMYkougekigazouA2frame = 0;//�������Ń����_����if���ɂ��0�ɖ߂邱�Ƃ�30�̂܂܂�����
					//���߂Ă̓G�̍U���������_����0�ɂȂ��Ă�if���ɂ��l���オ��̂Ŗ��Ȃ��G�͍U���ł���B

					//���G���U�����鎞�͐Ԃ��G�̍U�����~�߂Ă����B
					stayhere2 = 1;
					if (enemyattack > 0 && enemyattack < 2) {//if (enemyattack == 1)�͕ʂɂ���Ȃ��B
						preenemyX = pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 100;
						preenemyY = pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5;
						++enemycount;
						ENEMYkougekigazouA1 = 1;
						kasanarulock = 1;//���d�Ȃ�摜�Ɋւ��Ẵv���O�����ɂ��ʏ��Ԃ̓G���`�悳��Ȃ��悤�ɁA�����Œl��1�ɂ���B
						enemyattack = 0;
					}
				}


				//�G1�̏e�U��
				else if (ranndamukougeki == 3) {
					if (stage[0][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
						stage[0][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
						stage[1][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
						stage[1][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
						stage[0][0][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
						stage[1][0][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
						stage[0][6][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
						stage[1][6][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65
						//or stage[0][6][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + 65
						) {
						ranndamulock = 1;
						ranndamukougeki3 = 1;
						if (ranndamukougeki3 == 1) {
							enemy1HPhyouji = 0;
							enemyzannzoulock2 = 1;
							++enemyKENJYUUcount;
							ranndamulock = 1;
							a = 3;
							//���G���U�����鎞�͐Ԃ��G�̍U�����~�߂Ă����B
							stayhere2 = 1;
							// �����łR�b�܂�
							//WaitTimer(50);
						}
					}
				}
				else if (ranndamukougeki == 4) {
					if (stage[1][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
						stage[1][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
						stage[2][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
						stage[2][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
						stage[1][0][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
						stage[2][0][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
						stage[1][6][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
						stage[2][6][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65
						&& ranndamulock == 0
						) {
						ranndamulock = 1;
						ranndamukougeki4 = 1;
						if (ranndamukougeki4 == 1) {

							enemy1HPhyouji = 0;
							enemyzannzoulock2 = 1;
							++enemyKENJYUUcount;
							ranndamulock = 1;
							a = 6;
							//���G���U�����鎞�͐Ԃ��G�̍U�����~�߂Ă����B
							stayhere2 = 1;
							// �����łR�b�܂�
							//WaitTimer(50);
						}
					}
				}
				else if (ranndamukougeki == 5) {
					if (stage[2][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
						stage[2][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
						stage[3][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
						stage[3][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
						stage[2][0][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&//�@
						stage[3][0][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&//�A
						stage[2][6][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
						stage[3][6][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65//�����������Ă��ꕔ�����ω����Ȃ��z�͏o����B
						&& ranndamulock == 0
						) {
						ranndamulock = 1;
						ranndamukougeki5 = 1;
						if (ranndamukougeki5 == 1) {

							enemy1HPhyouji = 0;
							enemyzannzoulock2 = 1;
							++enemyKENJYUUcount;
							ranndamulock = 1;
							a = 9;
							//���G���U�����鎞�͐Ԃ��G�̍U�����~�߂Ă����B
							stayhere2 = 1;
							// �����łR�b�܂�
							//WaitTimer(50);
						}
					}
				}








				if (ENEMYkougekigazouA1 == 1) {
					ENEMYkougekigazouA1frame = 1;
					//ENEMYkougekigazouA1lock = 1;
					pos[enemyY1][enemyX1][0] = preenemyX;
					pos[enemyY1][enemyX1][1] = preenemyY;
					enemyattack = 0;
					ENEMYkougekigazouA1lock = 1;
					//LEFTmark = 100;

				}

			}

			//���ɏ����ɂ��Ă�if (enemycount == 0)�̏ꍇ�������Ȃ�������G���ڂ̑O�ɗ����A0�̏ꍇ�̏��������������������悤���B�U���ȊO�͖ڂ̑O�ɗ���悤�ȃR�[�h�͏����Ă��Ȃ����B
			//�܂��A�u0�̎��̏ꍇ�������Ă��Ȃ��̂ŕs���R�ȓ������N���Ă��܂����v�Ƃ������Ƃ��l������B
			//if (frames < 500) { frames = 0; }


		}


		//�G�̍U����ړ��Ȃǂ̕����B
			/*if (stayhere2 == 0) {// �G�̈ړ�
				int t = GetNowCount();
				//pre2enemyX = enemyX;//�����ɏ��������Ƃŕϐ�pre2enemyX�ɓG��X���W������B
				if (t >= nextMoveTime2) { // �w��̎��Ԃ��o������(1s���Ƃ�)
					nextMoveTime2 = t + MOVE_INTERVAL2; // ����ړ����������鎞��
					if (stopCount2 > 0) { // ��~���̂Ƃ�
						stopCount2--; // �~�܂��Ă���c�莞��(��)�����炷
					}

					else { // 9�}�X��̂����ꂩ�̃p�l���Ɉړ�������
						int cy = enemyY2, cx = enemyX2;
						do {
							enemyidou3 = GetRand(10);//enemyidou3��5���傫�����Ɉړ�����B
							if (enemyidou3 > 5) {
								enemyY2 = GetRand(2);
								enemyX2 = GetRand(2) + 3;
								//�ړ������猳�̃}�X�ɖ߂�悤�ɂ���B
								//DAMEGE = 0;
								playerattackhanndouB = 0;
								playerattackhanndou2B = 0;
								playerattackhanndou3B = 0;
								playerkonntororulock3 = 0;
								playerkonntororulock = 0;
								playerkonntororulock2 = 0;
								//kericount = 0;
								//yokkerucouunt = 0;
							}
							//���̏�Ɏ~�܂�m��
							if (GetRand(10) < 8) { // ���܂�(70%�̊m����)
								stopCount2 = GetRand(6); // ���b��(0�b��)���̏�Ɏ~�܂�
							}
							//�G�̈ړ���Ɏ�l���������ꍇ�͍ēx�ړ����I�Ԃ悤�ɂ�����B
							if (cy == playerY && cx == playerX) {

								enemyY2 = GetRand(2);
								enemyX2 = GetRand(2) + 3;
							}
							//��l�̓G��������̏|��ɂ������΂Ȃ��悤�ɂ��邽�߂̕����B
							else if (pos[enemyY1][enemyX1][1] == pos[enemyY2][enemyX2][1]) {
								enemyY1 = GetRand(2);
								enemyX1 = GetRand(2) + 3;
								enemyY2 = GetRand(2);
								enemyX2 = GetRand(2) + 3;
							}



						} while (enemyX1 == cx && enemyY1 == cy ||
							enemyX1 == playerX && enemyY1 == playerY);

						//enemyImage = enemyGHandle[10];

					}


					//�G2�̍U��
					//����ڂ̊m���̕ϓ��͒x�����߁A�U�����I���������ʏ��Ԃɏd�Ȃ����U���摜���o�Ă��Ă��܂��B
						//�Ȃ̂ŁA�m���̕ϓ��̑���������l�̓G�̍U�����Ă���Œ���if (stayhere == 0 && stayhere2 == 0)
						//�ɂ��m���������Ă�������l�ɉe�����o�Ȃ��悤�ɂ��āA������l�̍U�����I������キ�炢��
						//������l�̊m�����ς���Ă��邭�炢�̒��x�Ȃ̂ōU���摜���d�Ȃ邱�Ƃ͂Ȃ��B
						//���ɂ�����l���A���U�����Ă��Ă��A������l�̓G���U�����Ă��Ȃ��Ԃ�if (stayhere == 0 && stayhere2 == 0)
						//�ɂ�肱����ʂ邱�Ƃ͂Ȃ����ߍU���摜���d�Ȃ邱�Ƃ͂Ȃ��B
					if (ranndamulock2 == 0) {
						ranndamukougeki2 = GetRand(10);

					}
					//�G2�������U�����ƃt���[�Y���邱�Ƃ�����̂ŁA�G2���G1�Ɠ����m���̊֐������L����B
					if (ranndamukougeki2 == 2) {//GetRand(30) < 30�Ƃ���ƍU������r���ł�߂���A�J�E���^��2�𒴂��ďオ���Ă��܂����肷��B
						ranndamulock2 = 1;//�͈͂��d�Ȃ�Ƃ�������l���ƓG�̈ʒu���ς��悤�ɂ����B�𖳌��ɂ��邽�߂�1�ɂ����B
						++enemyattackB;
						anotherenemyzannzoulock = 1;
						//kaburulock = 1;//���肪�ڂ̑O�ɂ��Ă����ݍ��߂�悤�ɁB
						//randamulock = 1;//�ߋ����U�����͓����U�������Ȃ��悤�ɒl��1�ɂ���B
						ENEMYkougekigazouB2frame = 0;//�������Ń����_����if���ɂ��0�ɖ߂邱�Ƃ�30�̂܂܂�����
						//tekinoKOUGEKITYUUhahyouzisinailock = 1;//�G�̍U�����͏d�Ȃ�v���O�����𖳌��ɂ���B
						//enemygazoukesu = 1; //if (playerHPlock == 0 && playerHP <= 200)�ł̓G�̉摜���ꎞ�I�ɏ����B
						//ENEMYkougekigazouA2frame��0�ɖ߂�A�r���ōU�����~�܂邱�Ƃ͂Ȃ��Ȃ����B
						//���̉����@�Ƃ��Ă�if (ENEMYkougekigazouA1lock == 1 &&ENEMYkougekigazouA1frame == 0)
						//�̕�����++ENEMYkougekigazouA2frame�ł͂Ȃ�ENEMYkougekigazouA2frame=�ƌŒ�ɂ���΂�����
						//�V�����ϐ��������Ă߂�ǂ������Ȃ�̂�++�Ƃ��āA�����̃����_���ϐ��ɂ��0�ɂ��邱�Ƃŉ��������B
						//���߂Ă̓G�̍U���������_����0�ɂȂ��Ă�if���ɂ��l���オ��̂Ŗ��Ȃ��G�͍U���ł���B

						//�Ԃ��G���U�����鎞�͐��G�̍U�����~�߂Ă����B
						stayhere = 1;
						if (enemyattackB > 0 && enemyattackB < 2) {//if (enemyattack == 1)�͕ʂɂ���Ȃ��B
							preenemyX2 = pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + +nanameidouX4 + nanameidouX5 + 100;
							preenemyY2 = pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5;
							++enemycount;
							ENEMYkougekigazouB1 = 1;

							kasanarulock = 1;//���d�Ȃ�摜�Ɋւ��Ẵv���O�����ɂ��ʏ��Ԃ̓G���`�悳��Ȃ��悤�ɁA�����Œl��1�ɂ���B
							enemyattackB = 0;
						}
					}



					if (ENEMYkougekigazouB1 == 1) {
						ENEMYkougekigazouB1frame = 1;
						//ENEMYkougekigazouA1lock = 1;
						pos[enemyY2][enemyX2][0] = preenemyX2;
						pos[enemyY2][enemyX2][1] = preenemyY2;
						enemyattackB = 0;

						//LEFTmark = 739;
					}
				}
			}*/

			//���ɏ����ɂ��Ă�if (enemycount == 0)�̏ꍇ�������Ȃ�������G���ڂ̑O�ɗ����A0�̏ꍇ�̏��������������������悤���B�U���ȊO�͖ڂ̑O�ɗ���悤�ȃR�[�h�͏����Ă��Ȃ����B
			//�܂��A�u0�̎��̏ꍇ�������Ă��Ȃ��̂ŕs���R�ȓ������N���Ă��܂����v�Ƃ������Ƃ��l������B
			//if (frames < 500) { frames = 0; }




		//���[�v���ɏ�����enemyMove�ɂ���enemyMove��0���傫����40�𒴂�����o�p�̒��g�����s�B
		//enemyMove��0���傫���Ȃ��+1����āA40���傫�����l�ɂȂ�Η����̏����𖞂����̂�+�P�����B40���傫�����l�ɂȂ�����G�̉摜���ς��B
		//enemyMove��40���+�P����đ傫���Ȃ邽�߂�++enemyMove > 40









			// ���͏�Ԃ��擾//��if (input.RightTrigger == 255)���g����ŕK�v

		GetJoypadXInputState(DX_INPUT_PAD1, &input);
		//��stgae2Player_Update.h��if���̍\����if(playerkonntororulock == 0){}�̒���if (R1lock == 0){}�������Ă��Ȃ����������B
		if (R1lock == 0) {


			//R2�ő_���Ă̏e�U���B
			if (input.RightTrigger == 255)
			{
				playerkonntororulock = 1;
				jyuuzikeysousa2 = 1;
				suraidoidou = 1;
				
				//playermovelock = 1;//��kougekilock�I�ȓz�͍U���������łȂ��ƒl��1�ɂȂ炸�A���s����ƒl��0�̂܂܂�

				//R1attack = 1;
				lock = 1;//�`��̂���
				++lockonMove;//�`��֐��Ɏg���C���[�W�𑗂邽�߂̕ϐ�
				//R1lock = 1;//�A�������ł��Ȃ��悤�ɃA�h�A�^�b�N�^�C����0�ɂȂ�܂ł�1�̂܂܂ɂ���B
				kougekilock = 1;
				//�G�̖ڂ̑O�ɂ��邪�A����E�̓��͂������Ƒ���̑O�ɂ��������b�N�}�[�N������Ȃ��o�O���N����̂ňȉ��̂悤�ɏ����Ēu���B
				//2�}�X�ړ����āA����̖ڂ̑O�ɏo�����B
					// �E�G�C�g�������܂��A���܂葬���`�悷��Ɖ�ʂ����������ł�
				//WaitTimer(17);
				//�G�Əd�Ȃ����ۂ�HP������B
					// preplayerX�������Ă��܂ɂ�₱�����Ȃ�Ƃ������ςɂȂ�̂ł����̓_���[�W������H�炤�����ɂ���B
				hannilock = 2;
				//Gunkirikae = 1;//���b�N���͏e���؂�ւ����Ȃ��悤�ɂ���B
				// 
				// 
				//�e�̐؂�ւ��̍Œ��͏e�͌��ĂȂ��B
				if (Pad[PAD_5] == 1)
				{//�u�l�p�v�͍������ꂽ
				  //�u�l�p�v�������ꂽ�Ƃ��̏���
					Gunkirikae = 1;
					Lcount = 1;
					//LEFTmark = 133;

				}
			}

			//R2�������Ȃ��ꍇ�B
			if (input.RightTrigger == 0) {
				if (RightTriggerlock == 0) { playermovelock = 0; }
				lock = 0;
				lockmarkyokoidou = 0;
				lockmarktateidou = 0;
				jyuuzikeysousa2 = 0;
				playerkonntororulock = 0;
			}

		}




		//���b�N�}�[�N
		if (lockonMove == 10) {
			lockImge = lockonHandle[0];//���lockonMove == 10��lockonHandle[0]�������p���ŉ��ɏ������`��֐��ɓ��邽�߁A�����ɂ͊֐��ɓ�����񂾂�����̂��B
			//���̎��̏��lockonMove == 10��lockonHandle[0]�ȊO�̈����p���ꂽ�Ƃ������̎��̓G�̍��W�Ȃǂ��֐��ɓ���B�֐������߂���̂�����̂ŁA�֐��ɕK�v�Ȃ��𑵂̂���B
		}
		else if (lockonMove == 20) {
			lockImge = lockonHandle[1];

		}
		else if (lockonMove == 30) {
			lockImge = lockonHandle[2];


		}
		else if (lockonMove == 40) {
			lockImge = lockonHandle[1];
			lockonMove = 1;
		}



		if (lock == 1) {
			if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT) == 0) { //�L�[����͂���ȊO�ɂ���������ɑ����摜��؂�ւ��đ����݂���悤�ɂ��邽�߂ɏ����l�ɂ�1�͂��邪�L�[�ɂ�playerMove=1����������A�L�[����������ǂ��������������邽�߂�playerX++�������Ă���B
				lockmarkyokoidou = lockmarkyokoidou + 4;

			} //playerMove = 1;������Ɖ��ɏ�����playerMove��葫���݂���playerMove�������Ə����l��1�ł��̂܂ܑ����݂���̂Œx����������̂ł́H
			if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT) == 0) {//�L�[��playerMove=1�������Ə����l��1���������L�[�ɏ�����playerMove��1���s�����ߑ��������݂ɍs�����߁A�~�܂��Ă��瑫���݂ɍs���܂ł̊Ԃɂ��������ς���摜playerGHandle[2]����u�ł��邽�߁A������ς���̂�����������̂ł́H�����݂𑬂�����悤�ɂ������߁B
				lockmarkyokoidou = lockmarkyokoidou - 4;
			}
			if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_UP) == 0) {
				lockmarktateidou = lockmarktateidou - 3;
			}
			if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_DOWN) == 0) {
				lockmarktateidou = lockmarktateidou + 3;
			}
			//LEFTmark = 19;

		}
		//���U����H���Ȃ��悤�ɂ��邽�߂̃J�E���^�[�̕����B
		if (DAMEGE == 1) {
			++DAMEGEframe;
		}
		if (DAMEGEframe > 300) {
			DAMEGEframe = 0;
			playerHPsubun = 0;
			DAMEGE = 0;//�d�v�������ōU�����J�E���^�[���Ă�0�ɂȂ�̂ŁA�ĂэU�������Ă��U����H�炤�B
		}
		//�R���e�B�j���[���Ă���G�������܂ł̊��Ԃ̂��߂̕����B
		//�������I��stayhere��1�ɂ���Ǝ��񂾒��O�œG����̍U�����~�܂����܂܂ɂȂ��Ă��܂��A���ōU����H�炤�悤�ȏ�ԂɂȂ��Ă��܂��B
		//�Ȃ̂�stayhere�͏����B

		//������ȉ��͕`�悷�邽�߂̃v���O����
		//ClearDrawScreen();  // ����ʂ�
	}


}
//#endif
//if (kasokudo = 49) { A = 4; }
//if (function_status == 0) {//function_status = 0�̎��̓��j���[��ʂ�function_status��1�̎��͐퓬��ʂƂ����B
//
