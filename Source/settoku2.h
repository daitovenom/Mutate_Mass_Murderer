

#ifndef DEF_settoku2_H //��dinclude�h�~

#define DEF_settoku2_H

void settoku5() {
	SetFontSize(16);
	if (serekutobotanncount2 == 0) {
		DrawFormatString(25, 150, GetColor(255, 255, 0), "You can persuade the first time with the select button.");
		//�U�����ɃZ���N�g����ƃo�O��playerkonntororulock�̒l��0�̂܂܂ɂȂ�̂� motonomasunimodoru��0�A�U�����I�������ɉ�����悤�ɂ����B
		if (Pad[PAD_7] == 1 && motonomasunimodoru == 0 && zannzou == 0 && zannzouA == 0 && zannzouB == 0 && zannzouC == 0) {
			settokuSeen = 1;//�������邽�߂̃V�[���ֈړ�����B
			stayhere = 1;//�G�̓������~�߂�
			stayhere2 = 1;
			R1botannlock = 1;
			playerkonntororulock3 = 1;//��l���̑�����~�߂�B
		}
		if (settokuSeen == 1) {
			//�G�̍U�����W���X�g�q�b�g���Ĉȉ�2�̕ϐ���0�ɂȂ��������̂��߂ɂ����ōĂтP�ɂ���B
			stayhere = 1;//�G�̓������~�߂�
			stayhere2 = 1;
			//A�{�^����������
			//PlayMovieToGraph(settokugamenntyuunohaikeiHandle);
			//DrawExtendGraph(0, 0, 870, 780, settokugamenntyuunohaikeiHandle, FALSE);
			drawString(20, 100, 600, Cr);
			drawString(21, 100, 630, Cr);
			drawString(22, 100, 660, Cr);
			//A�{�^��
			if (Pad[PAD_1] == 1) {
				settokubunnki = 1;
			}

			//B�{�^����������
			if (Pad[PAD_2] == 1) {
				settokubunnki = 2;
			}
			//Y�{�^����������
			if (Pad[PAD_4] == 1) {
				settokubunnki = 3;
			}
		}
		if (settokubunnki == 1) {
			settokuSeen = 0;
			drawString(23, 100, 600, RED);
			settokubunnkiframe = 1;
			if (settokubunnkiframe2 > 0 && settokubunnkiframe2 < 2) {
				playerHPsubun =  101;//���������ꂽ�B//��HP�̒�`��float�ɂ��āA400�t���[����100�ɂȂ�悤��0.25�Ƃ����B�����A�`��֐���float���g���Ȃ��̂ł�߂�B
			}
		}
		if (settokubunnki == 2) {
			settokuSeen = 0;
			drawString(24, 100, 600, RED);
			settokubunnkiframe = 1;
			if (settokubunnkiframe2 > 0 && settokubunnkiframe2 < 2) {
				enemysabunHP =  100;
				Gcount = Gcount - 1;
			}
		}
		if (settokubunnki == 3) {
			settokuSeen = 0;
			drawString(25, 100, 600, RED);
			settokubunnkiframe = 1;
		}
		if (settokubunnkiframe > 0) {
			playerkonntororulock3 = 1;//��l���̑�����~�߂�B//�W���X�g�U����0�ɂȂ�Ƃ�������̂ŁB
			++settokubunnkiframe2;
		}
		if (settokubunnkiframe2 > 1000) {
			serekutobotanncount2 = 1;//��������������ڂ̐������o�Ȃ��悤�ɁB
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 0;//�G�̓������~�߂�
			stayhere2 = 0;//�G�̓������~�߂�
			playerkonntororulock3 = 0;//��l���̑�����~�߂�B
			R1botannlock = 0;
			settokubunnki = 0;
			//�G���U����H������ۂ�stayhereframe�������Ȃ��Ă��܂��̂ŁA�����ŋ����I��0�ɂ���B
			stayhereframe = 0;
			ranndamulock = 0;//�Ăѕ����U���ł���悤��0�ɂ���B
			enemyzannzoulockframe1 = 0;
			enemyzannzoulock2 = 0;
			stayhere = 0;
		}
	}
}

void settoku6() {
	SetFontSize(16);
	if (serekutobotanncount2 == 1) {
		DrawFormatString(25, 150, GetColor(255, 255, 0), "You can persuade the Second time with the select button.");
		//�U�����ɃZ���N�g����ƃo�O��playerkonntororulock�̒l��0�̂܂܂ɂȂ�̂� motonomasunimodoru��0�A�U�����I�������ɉ�����悤�ɂ����B
		if (Pad[PAD_7] == 1 && motonomasunimodoru == 0 && zannzou == 0 && zannzouA == 0 && zannzouB == 0 && zannzouC == 0) {
			settokuSeen = 1;//�������邽�߂̃V�[���ֈړ�����B
			stayhere = 1;//�G�̓������~�߂�
			stayhere2 = 1;
			playerkonntororulock3 = 1;//��l���̑�����~�߂�B
			R1botannlock = 1;
		}
		if (settokuSeen == 1) {
			stayhere = 1;//�G�̓������~�߂�
			stayhere2 = 1;
			//A�{�^����������
			//PlayMovieToGraph(settokugamenntyuunohaikeiHandle);
			//DrawExtendGraph(0, 0, 870, 780, settokugamenntyuunohaikeiHandle, FALSE);
			drawString(26, 100, 600, Cr);
			drawString(27, 100, 630, Cr);
			drawString(28, 100, 660, Cr);
			//A�{�^��
			if (Pad[PAD_1] == 1) {
				settokubunnki = 1;
			}

			//B�{�^����������
			if (Pad[PAD_2] == 1) {
				settokubunnki = 2;
			}
			//Y�{�^����������
			if (Pad[PAD_4] == 1) {
				settokubunnki = 3;
			}
		}
		if (settokubunnki == 1) {
			settokuSeen = 0;
			drawString(29, 100, 600, RED);
			settokubunnkiframe = 1;
			if (settokubunnkiframe2 > 0 && settokubunnkiframe2 < 2) {
				playerHPsubun = 61;//���������ꂽ�B//��HP�̒�`��float�ɂ��āA400�t���[����100�ɂȂ�悤��0.25�Ƃ����B�����A�`��֐���float���g���Ȃ��̂ł�߂�B
			}
		}
		if (settokubunnki == 2) {
			settokuSeen = 0;
			drawString(30, 100, 600, RED);
			settokubunnkiframe = 1;
			if (settokubunnkiframe2 > 0 && settokubunnkiframe2 < 2) {
				//enemy1HP = enemy1HP + 100;
			}
		}
		if (settokubunnki == 3) {
			settokuSeen = 0;
			drawString(31, 100, 600, RED);
			settokubunnkiframe = 1;
			if (settokubunnkiframe2 > 0 && settokubunnkiframe2 < 2) {
				playerHPsubun = 101;//���������ꂽ�B//��HP�̒�`��float�ɂ��āA400�t���[����100�ɂȂ�悤��0.25�Ƃ����B�����A�`��֐���float���g���Ȃ��̂ł�߂�B
			}
		}
		if (settokubunnkiframe > 0) {
			playerkonntororulock3 = 1;//��l���̑�����~�߂�B
			++settokubunnkiframe2;
		}
		if (settokubunnkiframe2 > 1500) {
			serekutobotanncount2 = 2;//��������������ڂ̐������o�Ȃ��悤�ɁB
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 1;//�G�̓������~�߂�
			stayhere2 = 1;//�G�̓������~�߂�
			playerkonntororulock3 = 0;//��l���̑�����~�߂�B
			R1botannlock = 0;
			settokubunnki = 0;
			//�G���U����H������ۂ�stayhereframe�������Ȃ��Ă��܂��̂ŁA�����ŋ����I��0�ɂ���B
			stayhereframe = 0;
			ranndamulock = 0;//�Ăѕ����U���ł���悤��0�ɂ���B
			enemyzannzoulockframe1 = 0;
			enemyzannzoulock2 = 0;
			stayhere = 0;
		}
	}
}

void settoku7() {
	SetFontSize(16);
	if (serekutobotanncount2 == 2) {
		DrawFormatString(25, 150, GetColor(255, 255, 0), "You can persuade the Second time with the select button.");
		//�U�����ɃZ���N�g����ƃo�O��playerkonntororulock�̒l��0�̂܂܂ɂȂ�̂� motonomasunimodoru��0�A�U�����I�������ɉ�����悤�ɂ����B
		if (Pad[PAD_7] == 1 && motonomasunimodoru == 0 && zannzou == 0 && zannzouA == 0 && zannzouB == 0 && zannzouC == 0) {
			settokuSeen = 1;//�������邽�߂̃V�[���ֈړ�����B
			stayhere = 1;//�G�̓������~�߂�
			stayhere2 = 1;
			playerkonntororulock3 = 1;//��l���̑�����~�߂�B
			R1botannlock = 1;
		}
		if (settokuSeen == 1) {
			stayhere = 1;//�G�̓������~�߂�
			stayhere2 = 1;
			//A�{�^����������
			//PlayMovieToGraph(settokugamenntyuunohaikeiHandle);
			//DrawExtendGraph(0, 0, 870, 780, settokugamenntyuunohaikeiHandle, FALSE);
			drawString(32, 100, 600, Cr);
			drawString(33, 100, 630, Cr);
			drawString(34, 100, 660, Cr);
			//A�{�^��
			if (Pad[PAD_1] == 1) {
				settokubunnki = 1;
			}

			//B�{�^����������
			if (Pad[PAD_2] == 1) {
				settokubunnki = 2;
			}
			//Y�{�^����������
			if (Pad[PAD_4] == 1) {
				settokubunnki = 3;
			}
		}
		if (settokubunnki == 1) {
			settokuSeen = 0;
			drawString(35, 100, 600, RED);
			settokubunnkiframe = 1;
			if (settokubunnkiframe2 > 0 && settokubunnkiframe2 < 2) {
				enemysabunHP = 300;
				heartpoint = 1;
			}
		}
		if (settokubunnki == 2) {
			settokuSeen = 0;
			drawString(36, 100, 600, RED);
			settokubunnkiframe = 1;
			
		}
		if (settokubunnki == 3) {
			settokuSeen = 0;
			drawString(37, 100, 600, RED);
			settokubunnkiframe = 1;
		}
		if (settokubunnkiframe > 0) {
			playerkonntororulock3 = 1;//��l���̑�����~�߂�B
			++settokubunnkiframe2;
		}
		if (settokubunnkiframe2 > 1500) {//�R�����g�������̂ł�������1500�ɂ���B
			serekutobotanncount2 = 3;//��������������ڂ̐������o�Ȃ��悤�ɁB
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 1;//�G�̓������~�߂�
			stayhere2 = 1;//�G�̓������~�߂�
			playerkonntororulock3 = 0;//��l���̑�����~�߂�B//���܂ɐ����ɓ��钼�O�ɍU������settokubunnkiframe2��400�𒴂���O�ɂ�����0�ɂȂ邱�Ƃ����邪�A����΂���͖ʓ|�Ȃ̂ł���ł����B
			R1botannlock = 0;
			settokubunnki = 0;
			//�G���U����H������ۂ�stayhereframe�������Ȃ��Ă��܂��̂ŁA�����ŋ����I��0�ɂ���B
			stayhereframe = 0;
			ranndamulock = 0;//�Ăѕ����U���ł���悤��0�ɂ���B
			enemyzannzoulockframe1 = 0;
			enemyzannzoulock2 = 0;
			stayhere = 0;
		}
	}
}

void settoku8() {
	SetFontSize(16);
	if (serekutobotanncount2 == 3) {
		DrawFormatString(25, 150, GetColor(255, 255, 0), "You can persuade the Fourth time with the select button.");
		//�U�����ɃZ���N�g����ƃo�O��playerkonntororulock�̒l��0�̂܂܂ɂȂ�̂� motonomasunimodoru��0�A�U�����I�������ɉ�����悤�ɂ����B
		if (Pad[PAD_7] == 1 && motonomasunimodoru == 0 && zannzou == 0 && zannzouA == 0 && zannzouB == 0 && zannzouC == 0) {
			settokuSeen = 1;//�������邽�߂̃V�[���ֈړ�����B
			stayhere = 1;//�G�̓������~�߂�
			stayhere2 = 1;
			playerkonntororulock3 = 1;//��l���̑�����~�߂�B
			R1botannlock = 1;
		}
		if (settokuSeen == 1) {
			stayhere = 1;//�G�̓������~�߂�
			stayhere2 = 1;
			//A�{�^����������
			//PlayMovieToGraph(settokugamenntyuunohaikeiHandle);
			//DrawExtendGraph(0, 0, 870, 780, settokugamenntyuunohaikeiHandle, FALSE);
			drawString(38, 100, 600, Cr);
			drawString(39, 100, 630, Cr);
			drawString(40, 100, 660, Cr);
			//A�{�^��
			if (Pad[PAD_1] == 1) {
				settokubunnki = 1;
			}

			//B�{�^����������
			if (Pad[PAD_2] == 1) {
				settokubunnki = 2;
			}
			//Y�{�^����������
			if (Pad[PAD_4] == 1) {
				settokubunnki = 3;
			}
		}
		if (settokubunnki == 1) {
			settokuSeen = 0;
			drawString(41, 100, 600, RED);
			settokubunnkiframe = 1;
			if (settokubunnkiframe2 > 0 && settokubunnkiframe2 < 2) {
				enemysabunHP = 50;
				heartpoint = 2;
			}
		}
		if (settokubunnki == 2) {
			settokuSeen = 0;
			drawString(42, 100, 600, RED);
			settokubunnkiframe = 1;

		}
		//���߂ēG���E���B
		if (settokubunnki == 3) {
			settokuSeen = 0;
			drawString(43, 100, 600, RED);
			settokubunnkiframe3 = 1;
		}
		if (settokubunnkiframe > 0) {
			playerkonntororulock3 = 1;//��l���̑�����~�߂�B
			++settokubunnkiframe2;
		}
		if (settokubunnkiframe3 > 0) {
			++settokubunnkiframe3;
		}
		if (settokubunnkiframe3 > 200) {
			settokubunnki = 0;
			settokubunnkiframe3 = 0;
			enemy1HP = 0;//���߂��B�����̒j���E�����Btest2.cpp��killer == 1�ɑ����B
			killer = 1;
		}
		if (settokubunnkiframe2 > 1500) {
			serekutobotanncount2 = 4;//��������������ڂ̐������o�Ȃ��悤�ɁB
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 1;//�G�̓������~�߂�
			stayhere2 = 1;//�G�̓������~�߂�
			playerkonntororulock3 = 0;//��l���̑�����~�߂�B//���܂ɐ����ɓ��钼�O�ɍU������settokubunnkiframe2��400�𒴂���O�ɂ�����0�ɂȂ邱�Ƃ����邪�A����΂���͖ʓ|�Ȃ̂ł���ł����B
			R1botannlock = 0;
			settokubunnki = 0;
			//�G���U����H������ۂ�stayhereframe�������Ȃ��Ă��܂��̂ŁA�����ŋ����I��0�ɂ���B
			stayhereframe = 0;
			ranndamulock = 0;//�Ăѕ����U���ł���悤��0�ɂ���B
			enemyzannzoulockframe1 = 0;
			enemyzannzoulock2 = 0;
			stayhere = 0;
		}
	}
}


void settoku9() {
	SetFontSize(16);
	if (serekutobotanncount2 == 4) {
		DrawFormatString(25, 150, GetColor(255, 255, 0), "You can persuade the five time with the select button.");
		//�U�����ɃZ���N�g����ƃo�O��playerkonntororulock�̒l��0�̂܂܂ɂȂ�̂� motonomasunimodoru��0�A�U�����I�������ɉ�����悤�ɂ����B
		if (Pad[PAD_7] == 1 && motonomasunimodoru == 0 && zannzou == 0 && zannzouA == 0 && zannzouB == 0 && zannzouC == 0) {
			settokuSeen = 1;//�������邽�߂̃V�[���ֈړ�����B
			stayhere = 1;//�G�̓������~�߂�
			stayhere2 = 1;
			playerkonntororulock3 = 1;//��l���̑�����~�߂�B
			R1botannlock = 1;
		}
		if (settokuSeen == 1) {
			stayhere = 1;//�G�̓������~�߂�
			stayhere2 = 1;
			//A�{�^����������
			//PlayMovieToGraph(settokugamenntyuunohaikeiHandle);
			//DrawExtendGraph(0, 0, 870, 780, settokugamenntyuunohaikeiHandle, FALSE);
			drawString(44, 100, 600, Cr);
			drawString(45, 100, 630, Cr);
			//drawString(40, 100, 700, Cr);
			//A�{�^��
			if (Pad[PAD_1] == 1) {
				settokubunnki = 1;
			}

			//B�{�^����������
			if (Pad[PAD_2] == 1) {
				settokubunnki = 2;
			}
			//Y�{�^����������
			//if (Pad[PAD_4] == 1) {
			//	settokubunnki = 3;
			//}
		}
		//�ޏ����҂��Ă�I�ޏ��̂��߂ɂ��߂��������I�@�{��̖ڂ��ɂ݂���ꂽ�B
		if (settokubunnki == 1) {
			settokuSeen = 0;
			drawString(46, 100, 600, RED);
			settokubunnkiframe = 1;
			if (settokubunnkiframe2 > 0 && settokubunnkiframe2 < 2) {
				playerHPsubun = 51;//�v���O�����̓s����{1��������B
			}
		}
		//�߂�����Ȃ��Ȃ�ޏ������O���牓������I�@���ށI��߂Ă���I
		if (settokubunnki == 2) {
			settokuSeen = 0;
			drawString(47, 100, 600, RED);
			settokubunnkiframe = 1;
			heartpoint = 3;
		}
		if (settokubunnkiframe > 0) {
			playerkonntororulock3 = 1;//��l���̑�����~�߂�B
			++settokubunnkiframe2;
		}
		if (settokubunnkiframe2 > 1500) {
			serekutobotanncount2 = 5;//��������������ڂ̐������o�Ȃ��悤�ɁB
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 1;//�G�̓������~�߂�
			stayhere2 = 1;//�G�̓������~�߂�
			playerkonntororulock3 = 0;//��l���̑�����~�߂�B//���܂ɐ����ɓ��钼�O�ɍU������settokubunnkiframe2��400�𒴂���O�ɂ�����0�ɂȂ邱�Ƃ����邪�A����΂���͖ʓ|�Ȃ̂ł���ł����B
			R1botannlock = 0;
			settokubunnki = 0;
			//�G���U����H������ۂ�stayhereframe�������Ȃ��Ă��܂��̂ŁA�����ŋ����I��0�ɂ���B
			stayhereframe = 0;
			ranndamulock = 0;//�Ăѕ����U���ł���悤��0�ɂ���B
			enemyzannzoulockframe1 = 0;
			enemyzannzoulock2 = 0;
			stayhere = 0;
		}
	}
}

//�n�[�g�|�C���g�����܂����ꍇ�̍Ō�̑I�����B
void settoku10() {
	SetFontSize(16);
	if (serekutobotanncount2 == 5) {
		DrawFormatString(25, 150, GetColor(255, 255, 0), "You can persuade the last time with the select button.");
		//�U�����ɃZ���N�g����ƃo�O��playerkonntororulock�̒l��0�̂܂܂ɂȂ�̂� motonomasunimodoru��0�A�U�����I�������ɉ�����悤�ɂ����B
		if (Pad[PAD_7] == 1 && motonomasunimodoru == 0 && zannzou == 0 && zannzouA == 0 && zannzouB == 0 && zannzouC == 0) {
			settokuSeen = 1;//�������邽�߂̃V�[���ֈړ�����B
			stayhere = 1;//�G�̓������~�߂�
			stayhere2 = 1;
			playerkonntororulock3 = 1;//��l���̑�����~�߂�B
			R1botannlock = 1;
		}
		if (settokuSeen == 1) {
			stayhere = 1;//�G�̓������~�߂�
			stayhere2 = 1;
			//A�{�^����������
			//PlayMovieToGraph(settokugamenntyuunohaikeiHandle);
			//DrawExtendGraph(0, 0, 870, 780, settokugamenntyuunohaikeiHandle, FALSE);
			drawString(48, 100, 600, Cr);
			drawString(49, 100, 630, Cr);
			//drawString(40, 100, 700, Cr);
			//A�{�^��
			if (Pad[PAD_1] == 1) {
				settokubunnki = 1;
			}

			//B�{�^����������
			if (Pad[PAD_2] == 1) {
				settokubunnki = 2;
			}
			//Y�{�^����������
			//if (Pad[PAD_4] == 1) {
			//	settokubunnki = 3;
			//}
		}
		//�ޏ����҂��Ă���I�@�����m��Ȃ������Ɍ����₪���āA���������키�̂���߂�
		if (settokubunnki == 1) {
			settokuSeen = 0;
			drawString(50, 100, 600, RED);
			settokubunnkiframe = 1;
			//analognoizu = 1;//test2.cpp�֐i�ށB
		}
		//�����키�K�v�͂Ȃ��悤���B�@�����~�Q���B
		if (settokubunnki == 2) {
			settokuSeen = 0;
			drawString(51, 100, 600, RED);
			settokubunnkiframe = 1;
			//analognoizu = 1;//test2.cpp�֐i�ށB

		}
		if (settokubunnkiframe > 0 && settokubunnki == 1) {
			playerkonntororulock3 = 1;//��l���̑�����~�߂�B
			R1botannlock = 1;//������1�ɂ��āA�X���C�h�ړ��ł��Ȃ��悤�ɂ���B
			++settokubunnkiframe2;
		}
		if (settokubunnkiframe > 0 && settokubunnki == 2) {
			playerkonntororulock3 = 1;//��l���̑�����~�߂�B
			R1botannlock = 1;//������1�ɂ��āA�X���C�h�ړ��ł��Ȃ��悤�ɂ���B
			++settokubunnkiframe3;
		}
		if (settokubunnkiframe2 > 1000) {
			serekutobotanncount2 = 6;//��������������ڂ̐������o�Ȃ��悤�ɁB
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 1;//�G�̓������~�߂�
			stayhere2 = 1;//�G�̓������~�߂�
			analognoizu = 2;//test2.cpp�֐i�ށB
		}
		if (settokubunnkiframe3 > 1000) {
			serekutobotanncount2 = 6;//��������������ڂ̐������o�Ȃ��悤�ɁB
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 1;//�G�̓������~�߂�
			stayhere2 = 1;//�G�̓������~�߂�
			analognoizu = 2;//test2.cpp�֐i�ށB
		}
	}
}

//�n�[�g�|�C���g�����܂�Ȃ������ꍇ�̍Ō�̑I�����B
void settoku11() {
	SetFontSize(16);
	if (serekutobotanncount2 == 5) {
		DrawFormatString(25, 150, GetColor(255, 255, 0), "�Z���N�g�{�^���ōŌ�̐����ɓ��邱�Ƃ��o���܂��B");
		//�U�����ɃZ���N�g����ƃo�O��playerkonntororulock�̒l��0�̂܂܂ɂȂ�̂� motonomasunimodoru��0�A�U�����I�������ɉ�����悤�ɂ����B
		if (Pad[PAD_7] == 1 && motonomasunimodoru == 0 && zannzou == 0 && zannzouA == 0 && zannzouB == 0 && zannzouC == 0) {
			settokuSeen = 1;//�������邽�߂̃V�[���ֈړ�����B
			stayhere = 1;//�G�̓������~�߂�
			stayhere2 = 1;
			playerkonntororulock3 = 1;//��l���̑�����~�߂�B
			R1botannlock = 1;
		}
		if (settokuSeen == 1) {
			stayhere = 1;//�G�̓������~�߂�
			stayhere2 = 1;
			//A�{�^����������
			//PlayMovieToGraph(settokugamenntyuunohaikeiHandle);
			//DrawExtendGraph(0, 0, 870, 780, settokugamenntyuunohaikeiHandle, FALSE);
			drawString(52, 100, 600, Cr);
			//drawString(40, 100, 700, Cr);
			//A�{�^��
			if (Pad[PAD_1] == 1) {
				settokubunnki = 1;
			}

		}
		//�ǂ����E�������Ȃ��悤���B
		if (settokubunnki == 1) {
			settokuSeen = 0;
			drawString(53, 100, 600, RED);
			settokubunnkiframe = 1;
		}
		
		if (settokubunnkiframe > 0) {
			playerkonntororulock3 = 1;//��l���̑�����~�߂�B
			++settokubunnkiframe2;
		}
		if (settokubunnkiframe2 > 1000) {
			serekutobotanncount2 = 6;//��������������ڂ̐������o�Ȃ��悤�ɁB
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 1;//�G�̓������~�߂�
			stayhere2 = 1;//�G�̓������~�߂�
			playerkonntororulock3 = 1;//��l���̑�����~�߂�B//���܂ɐ����ɓ��钼�O�ɍU������settokubunnkiframe2��400�𒴂���O�ɂ�����0�ɂȂ邱�Ƃ����邪�A����΂���͖ʓ|�Ȃ̂ł���ł����B
			settokubunnki = 0;
			//�G���U����H������ۂ�stayhereframe�������Ȃ��Ă��܂��̂ŁA�����ŋ����I��0�ɂ���B
			stayhereframe = 0;
			ranndamulock = 0;//�Ăѕ����U���ł���悤��0�ɂ���B
			enemyzannzoulockframe1 = 0;
			enemyzannzoulock2 = 0;
			stayhere = 0;

		}
	}
}


#endif