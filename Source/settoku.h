

#ifndef DEF_settoku_H //��dinclude�h�~

#define DEF_settoku_H




void settoku1() {

	if (serekutobotanncount == 0) {
		DrawFormatString(25, 150, GetColor(255, 255, 0), "You can persuade the first time with the select button.");
		//�U�����ɃZ���N�g����ƃo�O��playerkonntororulock�̒l��0�̂܂܂ɂȂ�̂� motonomasunimodoru��0�A�U�����I�������ɉ�����悤�ɂ����B
		if (Pad[PAD_7] == 1 && motonomasunimodoru == 0) {
			settokuSeen = 1;//�������邽�߂̃V�[���ֈړ�����B
			stayhere = 1;//�G�̓������~�߂�
			playerkonntororulock = 1;//��l���̑�����~�߂�B
			R1botannlock = 1;
		}
		if (settokuSeen == 1) {
			stayhere = 1;//�G�̓������~�߂�
			playerkonntororulock = 1;//��l���̑�����~�߂�B
			//A�{�^����������
			//PlayMovieToGraph(settokugamenntyuunohaikeiHandle);
			//DrawExtendGraph(0, 0, 870, 780, settokugamenntyuunohaikeiHandle, FALSE);
			drawString(0, 100, 600, Cr);
			drawString(1, 100, 630, Cr);
			drawString(2, 100, 660, Cr);
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
			drawString(3, 100, 600, RED);
			settokubunnkiframe = 1;
		}
		if (settokubunnki == 2) {
			settokuSeen = 0;
			drawString(4, 100, 600, RED);
			settokubunnkiframe = 1;
		}
		if (settokubunnki == 3) {
			settokuSeen = 0;
			drawString(5, 100, 600, RED);
			settokubunnkiframe = 1;
		}
		if (settokubunnkiframe > 0) {
			++settokubunnkiframe2;
		}
		if (settokubunnkiframe2 > 600) {
			serekutobotanncount = 1;//��������������ڂ̐������o�Ȃ��悤�ɁB
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 0;//�G�̓������~�߂�
			playerkonntororulock = 0;//��l���̑�����~�߂�B
			R1botannlock = 0;
			settokubunnki = 0;
		}
	}
}


void settoku2() {

	if (serekutobotanncount == 1) {
		DrawFormatString(25, 150, GetColor(255, 255, 0), "You can persuade the Second time with the select button.");
		//�U�����ɃZ���N�g����ƃo�O��playerkonntororulock�̒l��0�̂܂܂ɂȂ�̂� motonomasunimodoru��0�A�U�����I�������ɉ�����悤�ɂ����B
		if (Pad[PAD_7] == 1 && motonomasunimodoru == 0) {
			settokuSeen = 1;//�������邽�߂̃V�[���ֈړ�����B
			stayhere = 1;//�G�̓������~�߂�
			playerkonntororulock = 1;//��l���̑�����~�߂�B
			R1botannlock = 1;
		}
		if (settokuSeen == 1) {
			stayhere = 1;//�G�̓������~�߂�
			playerkonntororulock = 1;//��l���̑�����~�߂�B
			//A�{�^����������
			//PlayMovieToGraph(settokugamenntyuunohaikeiHandle);
			//DrawExtendGraph(0, 0, 870, 780, settokugamenntyuunohaikeiHandle, FALSE);
			drawString(6, 100, 600, Cr);
			drawString(7, 100, 630, Cr);
			drawString(8, 100, 660, Cr);
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
			drawString(9, 100, 600, RED);
			settokubunnkiframe = 1;
		}
		if (settokubunnki == 2) {
			settokuSeen = 0;
			drawString(10, 100, 600, RED);
			settokubunnkiframe = 1;
		}
		if (settokubunnki == 3) {
			settokuSeen = 0;
			drawString(11, 100, 600, RED);
			settokubunnkiframe = 1;
		}
		if (settokubunnkiframe > 0) {
			++settokubunnkiframe2;
		}
		if (settokubunnkiframe2 > 600) {
			serekutobotanncount = 2;//��������������ڂ̐������o�Ȃ��悤�ɁB
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 0;//�G�̓������~�߂�
			playerkonntororulock = 0;//��l���̑�����~�߂�B
			R1botannlock = 0;
			settokubunnki = 0;
		}
	}

}

void settoku3() {

	if (serekutobotanncount == 2) {
		DrawFormatString(25, 150, GetColor(255, 255, 0), "You can persuade the Third time with the select button.");
		//�U�����ɃZ���N�g����ƃo�O��playerkonntororulock�̒l��0�̂܂܂ɂȂ�̂� motonomasunimodoru��0�A�U�����I�������ɉ�����悤�ɂ����B
		if (Pad[PAD_7] == 1 && motonomasunimodoru == 0) {
			settokuSeen = 1;//�������邽�߂̃V�[���ֈړ�����B
			stayhere = 1;//�G�̓������~�߂�
			playerkonntororulock = 1;//��l���̑�����~�߂�B
			R1botannlock = 1;
		}
		if (settokuSeen == 1) {
			stayhere = 1;//�G�̓������~�߂�
			playerkonntororulock = 1;//��l���̑�����~�߂�B
			//A�{�^����������
			//PlayMovieToGraph(settokugamenntyuunohaikeiHandle);
			//DrawExtendGraph(0, 0, 870, 780, settokugamenntyuunohaikeiHandle, FALSE);
			drawString(12, 100, 600, Cr);
			drawString(13, 100, 630, Cr);
			drawString(14, 100, 660, Cr);
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
			drawString(15, 100, 600, RED);
			settokubunnkiframe = 1;
		}
		if (settokubunnki == 2) {
			settokuSeen = 0;
			drawString(16, 100, 600, RED);
			settokubunnkiframe = 1;
		}
		if (settokubunnki == 3) {
			settokuSeen = 0;
			drawString(17, 100, 600, RED);
			settokubunnkiframe = 1;
		}
		if (settokubunnkiframe > 0) {
			++settokubunnkiframe2;
		}
		//���肪���������Ƃ���W�J�֐i�ށB
		if (settokubunnkiframe2 > 1000&& settokubunnki == 1) {
			serekutobotanncount = 3;//��������������ڂ̐������o�Ȃ��悤�ɁB
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 1;//�G�̓������~�߂�
			playerkonntororulock = 1;//��l���̑�����~�߂�B
			R1botannlock = 0;
			settokubunnki = 0;
			settokutoumeika = 1;//Seen 11�ɐi�ނ��߂ɕK�v�ȕϐ��B
			analognoizu = 1;
			//Seen = 100;
			
		}
		if (settokubunnkiframe2 > 1000 && settokubunnki == 2) {
			serekutobotanncount = 3;//��������������ڂ̐������o�Ȃ��悤�ɁB
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 1;//�G�̓������~�߂�
			playerkonntororulock = 1;//��l���̑�����~�߂�B
			R1botannlock = 0;
			settokubunnki = 0;
			settokutoumeika = 1;//Seen 11�ɐi�ނ��߂ɕK�v�ȕϐ��B
			analognoizu = 1;
		}
		//������E���W�J�B�Ȃ̂�serekutobotanncount�̒l��4�ɕύX����B
		//������E���W�J�����A���̑I���ɂ��settoku4�ɐi�݁A�{���ɎE�����ǂ�����2���Ŕ��f����B
		if (settokubunnkiframe2 > 1000 && settokubunnki == 3) {
			serekutobotanncount = 4;//��������������ڂ̐������o�Ȃ��悤�ɁB
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 0;//�G�̓������~�߂�
			playerkonntororulock = 0;//��l���̑�����~�߂�B
			settokubunnki = 0;
		}
	}
	
}

void settoku4() {

	if (serekutobotanncount == 4) {
		DrawFormatString(25, 150, GetColor(255, 255, 0), "You can persuade the last time with the select button.");
		//�U�����ɃZ���N�g����ƃo�O��playerkonntororulock�̒l��0�̂܂܂ɂȂ�̂� motonomasunimodoru��0�A�U�����I�������ɉ�����悤�ɂ����B
		if (Pad[PAD_7] == 1 && motonomasunimodoru == 0) {
			settokuSeen = 1;//�������邽�߂̃V�[���ֈړ�����B
			stayhere = 1;//�G�̓������~�߂�
			playerkonntororulock = 1;//��l���̑�����~�߂�B
			R1botannlock = 1;
		}
		if (settokuSeen == 1) {
			stayhere = 1;//�G�̓������~�߂�
			playerkonntororulock = 1;//��l���̑�����~�߂�B
			//A�{�^����������
			//PlayMovieToGraph(settokugamenntyuunohaikeiHandle);
			//DrawExtendGraph(0, 0, 870, 780, settokugamenntyuunohaikeiHandle, FALSE);
			drawString(18, 100, 600, Cr);
			drawString(19, 100, 630, Cr);
			//A�{�^��
			if (Pad[PAD_1] == 1) {
				settokuSeen = 0;
				settokubunnki = 1;
				settokubunnkiframe = 1;
			}

			//B�{�^����������
			if (Pad[PAD_2] == 1) {
				settokuSeen = 0;
				settokubunnki = 2;
				settokubunnkiframe = 1;
			}
		}
		if (settokubunnkiframe > 0) {
			++settokubunnkiframe2;
		}
		//�o����ΎE�������Ȃ��B�ƂȂ�A���Ȕ��f�����Q�[���I�[�o�[�ցB
		if (settokubunnkiframe2 > 600 && settokubunnki == 1) {
			serekutobotanncount = 5;//��������������ڂ̐������o�Ȃ��悤�ɁB
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 1;//�G�̓������~�߂����߂�
			playerkonntororulock = 0;//��l���̑�����~�߂����߂�B
			R1botannlock = 0;
			settokubunnki = 0;
			settokutoumeika = 1;//Seen 11�ɐi�ނ��߂ɕK�v�ȕϐ��B
		}//�G���E�����ƂŐV���Ȗ����ɑ����B
		if (settokubunnkiframe2 > 600 && settokubunnki == 2) {
			serekutobotanncount = 5;//��������������ڂ̐������o�Ȃ��悤�ɁB
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 1;//�G�̓������~�߂�
			playerkonntororulock = 0;//��l���̑�����~�߂�B
			R1botannlock = 0;
			settokubunnki = 0;
			
		}
		
	}

}





#endif