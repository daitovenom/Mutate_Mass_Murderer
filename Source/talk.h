#include "DxLib.h"
#include "key.h"
#pragma warning(disable: 4996)

//#include "taitolh.h"
#ifndef DEF_talk_H //��dinclude�h�~

#define DEF_talk_H



void syokiiti() {
	int enemyX = 4, enemyY = 1;   // �G�̈ʒu
	int playerX = 1, playerY = 1;  // ���̈ʒu

}

void talkdrow() {
	//talkhaikei = 1;
	if (BGMlock == 0) { ++BGM1; }
	//��talk��0�̎���BGM���Đ������悤�Ƃ��Ă�������talk��0�̎���BGM�����ł͂Ȃ��A�d�l�I�ɉ��x���Đ����Ă������߁A�ŏ��ɍĐ�����Ă���BGM�̓L�[�Ŏ~�܂�����
	//����ȊO��BGM�͎~�܂�Ȃ������̂ŁA�L�[���͂����Ă��܂�Ŏ~�܂��Ă��Ȃ��悤�Ɍ������B
	//�����@��BGM����񂵂�����Ȃ��悤�ɒl���ϓ����邩�A�u�ԓI�Ƀ{�^�����������u�Ԃ���1�ɂȂ�悤�Ȓl�̎���BGM���Đ������邵���Ȃ��̂�
	//��ɑ�����ϐ�BGM1�̒l��10�̎���BGM���Đ����邱�Ƃň�񂵂��Đ�����Ȃ��̂ŁA���̈��Đ����ꂽBGM����͎~�߂�΂��������ƂȂ����B
	if (BGM1 == 10 && reBGM1 == 0) {
		sound4 = LoadSoundMem("Rotary_Phone-Ringtone01-1.mp3");
		ChangeVolumeSoundMem(180, sound4);//���̊֐��ɂ���ĉ����̃{�����[����ݒ�ł���B
		PlaySoundMem(sound4, DX_PLAYTYPE_BACK);
		dennwalock = 1;
	}
	if (BGM1 > 0) {
		++mozibyougaframe;
	}
	if (botanlock == 0) {
		if (Pad[PAD_2] == 1) {
			++talk;
		}
	}
	//if(mozibyougaframe > 0 &&mozibyougaframe<270)�̊Ԃ̓{�^���������Ȃ��悤��botanlock�̒l��0�ɂ��Ă����B
	if (talk == 0 && mozibyougaframe > 270) {
		BGM1 = 11;//�J��オ�����肵�Ă��d�b�̉�����Ȃ��悤��11�ɂ����B//�܂��l�����������Ă����͂Ȃ����O�̂��߂�11�ɂ��Ă����B

		//DrawString(200, 400, "B�{�^���œd�b�ɏo��", RED);
		//DrawString(200, 500, "A�{�^���œd�b�ɏo�Ȃ�", RED);
	}
	//�d�b�ɏo�Ȃ��ꍇ�B�Ăѓd�b�����t���[����Ɋ|�����Ă���B
	if (botanlock2 == 0) {
		if (Pad[PAD_1] == 1) {
			StopSoundMem(sound4);//��BGM��r���Ŏ~�߂邽�߂̊֐�
			reBGM1 = 1;//�Ă�BGM1�𗬂��܂ł̊��Ԃ̃t���[�������߂邽�߂̕ϐ��B
			mozibyougaframe = 0;//�d�b�ɏo�邩�łȂ����̕����`����������߂ɁB
			botanlock = 1;//�I�����ɂ���ă{�^���������Ȃ��悤�ɂ��邽�߂ɁB
			talkhaikei = 2;//��U���̔w�i�Ɉڂ�B
		}
	}
	//�Ăѓd�b���������Ă���܂ł̖����̊��ԁB
	//���̊��Ԃ�������BGM1��10�𒴂��Ă���reBGM��0�ɂȂ菑�����ʂ�ɓ����Ă���Ȃ��B
	if (reBGM1 > 0 && ++reBGM1 < 200) {
		BGM1 = 0;
		botanlock = 1;
		botanlock2 = 1;
	}
	if (reBGM1 > 200) {
		reBGM1 = 0;
		botanlock = 0;
		botanlock2 = 0;
		botanlockframe = 1;
		talkhaikei = 0;//�w�i���߂�B

	}
	//reBGM1�̍ŏ��̏������ł��������A������`��ɏ������Ԃ����������̂ŁA���ǂ���΂��܂������Ǝv���������܂�ς��Ȃ������B
	if (reBGM1 == 190) {
		posmozi2[0] = posmozi2[1] = posmozi2[2] = 0;//0,1,2��3�̕��͂��Ăѕ`�悳���B
	}
	if (botanlockframe > 0) {
		botanlock = 0;//�Ă�BGM�𗬂��܂Ŗ����Ń{�^���������Ȃ����Ă����̂ŁA�Ăї����܂ł̕ϐ���200�ɐ�������{�^����������悤�ɂ���B
		botanlock2 = 0;//�Ă�BGM�𗬂��܂Ŗ����Ń{�^���������Ȃ����Ă����̂ŁA�Ăї����܂ł̕ϐ���200�ɐ�������{�^����������悤�ɂ���B
		botanlockframe = 0;
		//talkhaikei = 1;
	}

	if (talkhaikei == 0 && dennwalock == 1 && talkend == 0) {
		// �`�悷�镶����̃T�C�Y��ݒ�
		//SetFontSize(28);
		kaiwadrawString(0, 100, 500, Cr);//�d�b���������Ă���
		kaiwadrawString(1, 100, 600, RED);//�d�b�ɏo��
		kaiwadrawString(2, 100, 700, RED);//�d�b�ɏo�Ȃ�
		//PlayMovieToGraph(dennwaHandle);
		//DrawExtendGraph(0, 0, 870, 780, dennwaHandle, FALSE);
		//�d�b�ɏo��
		if (Pad[PAD_2] == 1) {
			talkhaikei = 1;
			kaiwasound1 = LoadSoundMem("�`���C�R�t�X�L�[�w10���E�H�̉́x�i�y���t���j.mp4");
			ChangeVolumeSoundMem(120, kaiwasound1);//���̊֐��ɂ���ĉ����̃{�����[����ݒ�ł���B
			PlaySoundMem(kaiwasound1, DX_PLAYTYPE_BACK);
		}
		//�d�b�ɏo�Ȃ�
		if (Pad[PAD_1] == 1) {
			talkhaikei = 0;
		}
	}
	if (talkhaikei == 1) {
		botanlock2 = 1;
		StopSoundMem(sound4);//��BGM��r���Ŏ~�߂邽�߂̊֐�
		 // ������̕`��
		mozibyougaframe = 0;
		BGM1 = 11;//�J��オ�����肵�Ă��d�b�̉�����Ȃ��悤��11�ɂ����B//�܂��l�����������Ă����͂Ȃ����O�̂��߂�11�ɂ��Ă����B
		//DrawString(100,400, "(��l��)", RED);
		//if (talk == 0 && posmozi[0] == 9) { if (Pad[PAD_2] == 1) { talk=1; } }//talkdorw�̎���str1.drawString���Ă΂�Ă���̂ł��̒��g�̂��̂����s����Ă����v�Ȃ̂ł́H
		//���if��if (talk == 0 && posmozi[0] == 9)���Ȃ��Ă������͕`��ł���if (talk == 0) ��drawString(0, 100, 500, Green);��{}�ɏ����Ă���΁A
		//�Ƃ����̂��֐�drawString���̂̈�Ԗڂ�z�Ƃ��������̒l��������̓��锠�̔ԍ���\���悤�ɍ�������߂��B �Ԉ���Ă����O�̃v���O�����ł�posmozi[0] == 9�Ə����Ă�������posmozi[0]��10�ł���������if����ʂ�Ȃ������̂��낤�B
		//drawString(0, 100, 500, RED);//�����͏�ɍ�����֐���蕶����̓��锠�̔ԍ��Ax���Ay���ƐF�ł���B

			// ���[�r�[���Đ���Ԃɂ��܂�
		//PlayMovieToGraph(vioraHandle);
		//PlayMovieToGraph(enemytalk1Handle);
		//++enemytalk;

		DrawExtendGraph(242, 0, 1127, 580, dennwa, FALSE);
		PlayMovieToGraph(dennwa);
		//DrawExtendGraph(242, 0, 1127, 580, enemytalk1Handle, FALSE);
		// ��ʍ���ɍĐ����Ԃ�`�悵�܂�
		//DrawFormatString(0, 0, GetColor(255, 255, 255), "Time:%d", TellMovieToGraph(enemytalk1Handle));
		if (talk == 1) {
			kaiwadrawString(3, 100, 600, RED);//�͂��A��������
		}
	}

	if (talk == 2) {
		kaiwadrawString(4, 100, 600, RED);//���A�A�A�A���������A�����瑊�k���ł��傤���H

	}
	if (talk == 3) {
		kaiwadrawString(5, 100, 600, RED);//���͋��t�ł��B

	}
	if (talk == 4) {
		kaiwadrawString(6, 100, 600, RED);//�ƒ�ɑ��k�����B

	}
	if (talk == 5) {
		kaiwadrawString(7, 100, 600, RED);//���ɓ��ɋs�҂��Ђǂ��Ȃ��Ă��܂��B

	}
	if (talk == 6) {
		kaiwadrawString(8, 100, 600, RED);//���ɓ��ɋs�҂��Ђǂ��Ȃ��Ă��܂��B

	}
	if (talk == 7) {
		kaiwadrawString(9, 100, 600, RED);//���ɓ��ɋs�҂��Ђǂ��Ȃ��Ă��܂��B

	}
	if (talk == 8) {
		kaiwadrawString(10, 100, 600, RED);//���ɓ��ɋs�҂��Ђǂ��Ȃ��Ă��܂��B

	}
	if (talk == 9) {
		kaiwadrawString(11, 100, 600, RED);//��b���u����

	}
	if (talk == 10) {
		kaiwadrawString(12, 100, 600, RED);//��b���u����
		++timetravel;
		botanlock = 1;
		StopSoundMem(kaiwasound1);//��BGM��r���Ŏ~�߂邽�߂̊֐�
		talkhaikei = 0;//�������t�̉摜�������B
		talkend = 1;//�d�b���o�邩�o�Ȃ����̕�������`�悵�Ȃ����߂̕ϐ��B

	}
	if (timetravel > 400) {
		talk == 11;
		timetravel = 400;
		botanlock = 0;

	}
	if (talk == 11 && timetravel == 400) {
		kaiwadrawString(13, 100, 600, RED);//1949�N

	}
	if (talk == 12) {
		kaiwadrawString(14, 100, 600, RED);//�Ƃ�T��

	}
	if (talk == 13) {
		kaiwadrawString(15, 100, 600, RED);//�ƌ�����

	}
	if (talk == 14) {
		kaiwadrawString(16, 100, 600, RED);//�h�A���J��

	}
	if (talk == 15) {
		kaiwadrawString(17, 100, 600, RED);//��e�̕���

	}
	if (talk == 16) {
		kaiwadrawString(18, 100, 600, RED);//��e�o��

	}
	if (talk == 17) {
		kaiwadrawString(19, 100, 600, RED);//��e�o��

	}
	if (talk == 18) {
		kaiwadrawString(20, 100, 600, RED);//��e�o��

	}
	if (talk == 19) {
		kaiwadrawString(21, 100, 600, RED);//��e�o��

	}
	if (talk == 20) {
		kaiwadrawString(22, 100, 600, RED);//��e�o��

	}
	if (talk == 21) {
		kaiwadrawString(23, 100, 600, RED);//��e�o��

	}
	if (talk == 22) {
		kaiwadrawString(24, 100, 600, RED);//��e�o��

	}
	if (talk == 23) {
		kaiwadrawString(25, 100, 600, RED);//��e�o��

	}
	if (talk == 24) {
		kaiwadrawString(26, 100, 600, RED);//��e�o��

	}
	if (talk == 25) {
		kaiwadrawString(27, 100, 600, RED);//��e�o��

	}
	if (talk == 26) {
		kaiwadrawString(28, 100, 600, RED);//��e�o��

	}
	if (talk == 27) {
		kaiwadrawString(29, 100, 600, RED);//��e�o��

	}
	if (talk == 28) {
		kaiwadrawString(30, 100, 600, RED);//��e�o��

	}
	if (talk == 29) {
		kaiwadrawString(31, 100, 600, RED);//�����̂��ƂȂ�Ēm������������Ȃ��B

	}
	if (talk == 30) {
		kaiwadrawString(32, 100, 600, RED);//�����̂��ƂȂ�Ēm������������Ȃ��B

	}
	if (talk == 31) {
		kaiwadrawString(33, 100, 600, RED);//�����̂��ƂȂ�Ēm������������Ȃ��B

	}
	if (talk == 32) {
		kaiwadrawString(34, 100, 600, RED);//�����̂��ƂȂ�Ēm������������Ȃ��B

	}
	if (talk == 33) {
		kaiwadrawString(35, 100, 600, RED);//�����̂��ƂȂ�Ēm������������Ȃ��B

	}
	if (talk == 34) {
		kaiwadrawString(36, 100, 600, RED);//�����̂��ƂȂ�Ēm������������Ȃ��B

	}
	if (talk == 35) {
		kaiwadrawString(37, 100, 600, RED);//�����̂��ƂȂ�Ēm������������Ȃ��B

	}
	if (talk == 36) {
		kaiwadrawString(38, 100, 600, RED);//�����̂��ƂȂ�Ēm������������Ȃ��B

	}

	//if (enemytalk == 3150) {
	//	talk = 2;//talk��1�̎���enemytalk���J��オ��Ȃ��悤�ɁB
	//	enemytalk = 3150;
	//}
	if (talk == 37) {
		PlayMovieToGraph(enemytalk2Handle);

		DrawExtendGraph(242, 0, 1127, 780, enemytalk2Handle, FALSE);
		++enemytalk2;
	}
	if (enemytalk2 == 100) {
		mark = 1;//������talk��3�̎��̓L�[A�������Ȃ��悤�ɕϐ��ŏ�����t�����B�ҏW�O�͏��if (Key[KEY_INPUT_A] == 1)�Ɣ���Ă��܂��ďd���������߂����܂��@�\���Ȃ������B
		//stayhere���g���Ẵv���O���������������A�֐��̊O�̃��C���ɂ��������߂�if (Key[KEY_INPUT_A] == 1)�������Ȃ������̂��A���̂܂܂������B�������o����Ί֐����ł܂Ƃ߂����̂ō��̂悤�ɏ������B
		//BGMstart1 = 1;

			//DrawFormatString(300, 300, RED, "battle start���܂�");
		//syokiiti();//
		//enemymovelock = 1;//���̊Ԃ͓G�������Ȃ��悤��enemymovelock��1�ɂ���player2.h�̓G�̍U����ړ��̕������
		 //�L�[A�������Ă�A��talk�������Ȃ��悤�ɏ������BPlayer_Update()��Seen = 1�ɂ��Ă΂��̂�talk�̒l�Ɋ֌W���Ȃ��悤�ɏ������̂�talk�̒l�Ɋ֌W�Ȃ��B�Ȃ̂�talk���オ���Ă�if (start == 200)�ɂ��퓬��ʂ͏o�Ă��Ȃ��B


		//ChangeVolumeSoundMem(100, sound3);//���̊֐��ɂ���ĉ����̃{�����[����ݒ�ł���B
		//PlaySoundMem(sound3, DX_PLAYTYPE_LOOP, FALSE);
	}
	//��u�G���������߃X�^�[�g���Đ퓬��ʂ��łĂ�����if���̕ϐ�start�̂��܂�̃t���[���o������enemymovelock = 0�ɂȂ�悤�ɒ������B
	if (enemytalk2 > 200) {
		talk = 4;//talk��2�̎���enemytalk2���J��オ��Ȃ��悤�ɁB
		Seen = 2; stayhere = 1;//stayhere�ɂ����Ă�stage1.h�ɑ����B
		mark = 0; //�܂��������Ă��Ȃ��@init_stage();�͎����ƓG�̏������̂��߂̊֐������A
		stayherelock = 0; snow = 1;
		enemyHPhyouji = 1;
		botanlock = 0;
		enemytalk2 = 200;
		//���������܂������Ȃ������œG����������Ă����ԂŃo�g�����J�n����̂��낤�B������void Player_Update()�̒��ɂ�init_stage()�͏����Ă���B
	}
	//�퓬�J�n�O�Ƀ{�^���������ĉ�b��ʂɖ߂�Ȃ��悤�ɂ��邽�߂̕���
	if (enemytalk > 0 && enemytalk < 2900) {
		botanlock = 1;
	}
	if (enemytalk2 > 0 && enemytalk2 < 500) {
		botanlock = 1;
	}
	return;
}

#endif