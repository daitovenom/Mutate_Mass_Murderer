#include "Game.h"

Game* Game::_instance = NULL;

//�R���X�g���N�^ = �ŏ��ɏ���ɐ�ΌĂт������
Game::Game() {
	//������
	_instance = this;
	MovieGraphHandle = -1;


}

//�f�X�g���N�^ = �Ō�ɏ���ɐ�ΌĂт������
Game::~Game() {

}

bool Game::Init(){


	//�����֐��Ŏg�������摜���u�ԂɌĂԂ͎̂��Ԃ������邵�d���̂Ń��C���̒��Ɋ��ɃX�^���o���Ă����Ԃɂ���B
	SetTransColor(255, 255, 255); // �ǂݍ��މ摜�̑O�ɂ�����u�����Ƃœ������ł���B���[�v���ɂ������Đ���������������ǂݍ��ނ悤�ɂȂ��Ă��܂����ߏ������x���Ȃ�B

	// ���[�r�[�t�@�C�������[�h���܂�
	if (MovieGraphHandle = LoadGraph("180half_f.gif") == -1) {
		return false;
	}
	// ���[�r�[���Đ���Ԃɂ��܂�
	PlayMovieToGraph(MovieGraphHandle);
	// �^�C�g���ŏo�Ă��郀�[�r�[�t�@�C�������[�h���܂��B
	//taitolGraphHandle = LoadGraph("321000000_mmw227fw.gif");
	// �^�C�g���ŏo�Ă��郀�[�r�[���Đ���Ԃɂ��܂�
	PlayMovieToGraph(taitolGraphHandle);
	//�G���_���[�W���󂯂����̐S���̃��[�r�[�t�@�C�������[�h���܂��B
	sinnzouGraphHandle = LoadGraph("original.gif");
	// �G���_���[�W���󂯂����̐S���̃��[�r�[���Đ���Ԃɂ��܂�
	PlayMovieToGraph(sinnzouGraphHandle);

	// �Ⴠ�[�r�[�t�@�C�������[�h���܂��B
	snowGraphHandle = LoadGraph("20160103081928.gif");
	// �Ⴠ�[�r�[���Đ���Ԃɂ��܂�
	PlayMovieToGraph(snowGraphHandle);

	// �A�i���O�m�C�Y���[�r�[�t�@�C�������[�h���܂��B
	anarogunoizuGraphHandle = LoadGraph("MOSHED-2020-6-1-23-33-37.gif");
	// �A�i���O�m�C�Y���[�r�[���Đ���Ԃɂ��܂�
	PlayMovieToGraph(anarogunoizuGraphHandle);

	// �t�@�C�������[�h���܂��B
	gimenHandle = LoadGraph("photo0000-3903.bmp");
	PlayMovieToGraph(gimenHandle);

	// �t�@�C�������[�h���܂��B
	kodomogif = LoadGraph("kodomo.gif");
	PlayMovieToGraph(kodomogif);
	// �t�@�C�������[�h���܂��B
	 //kaiwaHandle = OpenMovieToGraph("MOSHED-2020-6-2-19-11-5.gif");

	//SeekMovieToGraph(kaiwaHandle, 0);
	//PlayMovieToGraph(kaiwaHandle);

	// �d�b�ɂł邩�ǂ����̃t�@�C�������[�h���܂��B
	dennwaHandle = LoadGraph("dennwasenntaku.gif");

	//��b�̃t�@�C�������[�h���܂��B
	enemytalk1Handle = LoadGraph("���̃r�f�I1.gif");
	//��b�̃t�@�C�������[�h���܂��B
	enemytalk2Handle = LoadGraph("enemytalk2.gif");

	dennwa = LoadGraph("21b667f1-88cb-4e41-9bdc-41351a55655b.gif");

	// �t�@�C�������[�h���܂��B
	SHOTHandle = LoadGraph("ENEMYGIF1.gif");
	PlayMovieToGraph(SHOTHandle);


	// ���B�I�������[�h���܂��B
	vioraHandle = LoadGraph("MOSHED-2020-6-2-19-37-21.gif");
	PlayMovieToGraph(vioraHandle);

	// �������̔w�i�����[�h���܂��B
	settokugamenntyuunohaikeiHandle = LoadGraph("settokugamenntyuunohaikei.gif");
	PlayMovieToGraph(settokugamenntyuunohaikeiHandle);

	// �I����1�����[�h���܂��B
	settoku1Handle = LoadGraph("settoku1.gif");

	// �퓬������[�h���܂��B
	sentougoHandle = LoadGraph("senntougonoOUT.gif");

	// �R���e�B�j���[��ʂ̔w�i�����[�h���܂��B
	countimuHandle = LoadGraph("MOSHED-2020-6-1-23-49-29.gif");
	PlayMovieToGraph(countimuHandle);

	//�퓬���̔w�i
	stage1haikeiHandle = LoadGraph("stage1.gif");
	PlayMovieToGraph(stage1haikeiHandle);

	//�퓬���̔w�i
	stage2haikeiHandle = LoadGraph("stage2haikei.gif");
	PlayMovieToGraph(stage2haikeiHandle);

	//�����t�̓d�b�f��
	dennwa = LoadGraph("dennwa2.gif");
	PlayMovieToGraph(dennwa);

	//�^�C�g���̔w�i�B
	taitolhaikeiHandle = LoadGraph("taitoruhaikei.gif");
	PlayMovieToGraph(taitolhaikeiHandle);

	LoadDivGraph("lockon.bmp", 3, 3, 1, 23, 23, lockonHandle);//�Ȃ̂ŁA��x�ǂݍ��ނ����摜�͎g���邵�A������x�����Ȃ����߂Ƀ��[�v�ɓ���O����WinMain�̒��ɏ������B
	LoadDivGraph("ENEMYVR1.bmp", 3, 3, 1, 18, 33, enemyGHandle);
	LoadDivGraph("ENEMY1.bmp", 1, 1, 1, 18, 33, enemygameGHandle);//���񂾓G�̉摜


	//�E����
	LoadDivGraph("Assets/image/playersyuzinnkoukuronuriKAIZOU6.bmp", 3, 3, 1, 20, 33, playerGHandle);

	//������
	LoadDivGraph("playersyuzinnkoukuronuriKAIZOU6a.bmp", 3, 3, 1, 20, 33, playerHandle2);


	LoadDivGraph("tuubyousyuzinnkou1bmp.bmp", 1, 1, 1, 35, 33, player1GHandle);
	LoadDivGraph("tuubyousyuzinnkou2bmp.bmp", 1, 1, 1, 35, 33, player2GHandle);
	LoadDivGraph("tuubyousyuzinnkou3bmp.bmp", 1, 1, 1, 35, 33, player3GHandle);
	LoadDivGraph("tuubyousyuzinnkou4bmp.bmp", 1, 1, 1, 35, 33, player4GHandle);
	LoadDivGraph("tuubyousyuzinnkou5bmp.bmp", 1, 1, 1, 35, 33, player5GHandle);

	//�U����H������Ƃ��̉摜�B
	LoadDivGraph("syuzinnkoukurau1KAI2.bmp", 1, 1, 1, 35, 33, playerdamegeGHandle);

	//��l���̃K�[�h���[�V����
	LoadDivGraph("syuzinnkougard.bmp", 1, 1, 1, 44, 33, playergardGHandle);

	//�^�C�g��
	LoadDivGraph("mmm2.bmp", 1, 1, 1, 92, 7, taitolHandle);
	LoadDivGraph("HANDOFDEATH2.bmp", 1, 1, 1, 90, 9, taitol2Handle);

	LoadDivGraph("syuzinnkoukuronuriA.bmp", 1, 1, 1, 44, 33, testplayerGHandle);
	LoadDivGraph("kikenn.png", 12, 4, 3, 62, 66, kikennhanndle);
	LoadDivGraph("hartmark.bmp", 3, 3, 1, 13, 10, hartmarkhanndle);
	LoadDivGraph("blood.bmp", 3, 3, 1, 13, 10, bloodGHandle);

	//�E��������
	LoadDivGraph("naguruAkuronuri.bmp", 1, 1, 1, 44, 33, playernaguruAGHandle);
	LoadDivGraph("naguruBkuronuri.bmp", 1, 1, 1, 44, 33, playernaguruBGHandle);
	LoadDivGraph("naguruBkuronuri2.bmp", 1, 1, 1, 44, 33, playernaguruBGHandle2);
	LoadDivGraph("naguruBkuronuri3.bmp", 1, 1, 1, 44, 33, playernaguruBGHandle3);

	//����������
	LoadDivGraph("naguruAkuronuriB.bmp", 1, 1, 1, 44, 33, playernaguruAGHandleB);
	LoadDivGraph("naguruBkuronuriB.bmp", 1, 1, 1, 44, 33, playernaguruBGHandleB);
	LoadDivGraph("naguruBkuronuri2B.bmp", 1, 1, 1, 44, 33, playernaguruBGHandle2B);
	LoadDivGraph("naguruBkuronuri3B.bmp", 1, 1, 1, 44, 33, playernaguruBGHandle3B);

	//��l���^�o�R
	LoadDivGraph("syuzinnkoutabakoA.bmp", 1, 1, 1, 22, 33, playertabakoAHandle);
	LoadDivGraph("syuzinnkoutabakoB.bmp", 1, 1, 1, 22, 33, playertabakoBHandle);
	LoadDivGraph("syuzinnkoutabakoC.bmp", 1, 1, 1, 22, 33, playertabakoCHandle);
	LoadDivGraph("syuzinnkoutabakoD.bmp", 1, 1, 1, 22, 33, playertabakoDHandle);//���������摜�̉��̑傫����26�����AsyuzinnkoutabakoA�`C�ɍ��킹��22�Ƃ����B22�Ƃ��Ă��؂����邱�Ƃ͂Ȃ��B


	//�E�����̏R��
	LoadDivGraph("syuzinnkouKONNBO1ANOIZU1.bmp", 1, 1, 1, 35, 33, playerKONNBO1AHandle);
	LoadDivGraph("syuzinnkouKONNBO1ANOIZU1.bmp", 1, 1, 1, 35, 33, playerKONNBO1ANOIZU1Handle);
	LoadDivGraph("syuzinnkouKONNBO1ANOIZU2.bmp", 1, 1, 1, 35, 33, playerKONNBO1ANOIZU2Handle);
	LoadDivGraph("syuzinnkouKONNBO1ANOIZU3.bmp", 1, 1, 1, 35, 33, playerKONNBO1ANOIZU3Handle);
	LoadDivGraph("syuzinnkouKONNBO1ANOIZU4.bmp", 1, 1, 1, 35, 33, playerKONNBO1ANOIZU4Handle);

	LoadDivGraph("syuzinnkouKONNBO1B.bmp", 1, 1, 1, 35, 33, playerKONNBO1BHandle);

	//�������̏R��
	LoadDivGraph("syuzinnkouKONNBO1ANOIZU1B.bmp", 1, 1, 1, 35, 33, playerKONNBO1AHandleB);
	LoadDivGraph("syuzinnkouKONNBO1ANOIZU1B.bmp", 1, 1, 1, 35, 33, playerKONNBO1ANOIZU1HandleB);
	LoadDivGraph("syuzinnkouKONNBO1ANOIZU2B.bmp", 1, 1, 1, 35, 33, playerKONNBO1ANOIZU2HandleB);
	LoadDivGraph("syuzinnkouKONNBO1ANOIZU3B.bmp", 1, 1, 1, 35, 33, playerKONNBO1ANOIZU3HandleB);
	LoadDivGraph("syuzinnkouKONNBO1ANOIZU4B.bmp", 1, 1, 1, 35, 33, playerKONNBO1ANOIZU4HandleB);

	LoadDivGraph("syuzinnkouKONNBO1BHANTEN.bmp", 1, 1, 1, 35, 33, playerKONNBO1BHandleB);

	//�X���C�h�ړ��̉摜�B
	LoadDivGraph("playersyuzinnkouidouA.bmp", 1, 1, 1, 22, 33, playeridouAHandle);
	LoadDivGraph("playersyuzinnkouidouA4.bmp", 1, 1, 1, 22, 33, playeridouA4Handle);
	LoadDivGraph("playersyuzinnkouidouA2.bmp", 1, 1, 1, 22, 33, playeridouA2Handle);
	LoadDivGraph("playersyuzinnkouidouA3.bmp", 1, 1, 1, 22, 33, playeridouA3Handle);
	LoadDivGraph("playersuraido5.bmp", 1, 1, 1, 22, 33, playeridouA5Handle);
	//�������̃X���C�h�ړ��̉摜�B
	LoadDivGraph("playersyuzinnkouidouAhidari.bmp", 1, 1, 1, 22, 33, playeridouAhidariHandle);
	LoadDivGraph("playersyuzinnkouidouA4hidari.bmp", 1, 1, 1, 22, 33, playeridouA4hidariHandle);
	LoadDivGraph("playersyuzinnkouidouA2hidari.bmp", 1, 1, 1, 22, 33, playeridouA2hidariHandle);
	LoadDivGraph("playersyuzinnkouidouA3hidari.bmp", 1, 1, 1, 22, 33, playeridouA3hidariHandle);
	LoadDivGraph("playersuraidohidari5.bmp", 1, 1, 1, 22, 33, playeridouA5hidariHandle);
	//LoadDivGraph("playersuraido4.bmp", 1, 1, 1, 22, 33, playeridouA4Handle);



	LoadDivGraph("enemystage2attack2anemy1KENJYUU.bmp", 2, 2, 1, 30, 45, enemy1KENJYUUHandle);

	//LoadDivGraph("enemystage2attack2anemy1KENJYUU.bmp", 2, 2, 1, 30, 45, enemy1KENJYUUhidariHandle);
	LoadDivGraph("naihuGAZOU1.bmp", 1, 1, 1, 30, 70, naihuHandle);

	LoadDivGraph("naihu2.bmp", 1, 1, 1, 30, 30, naihu2Handle);




	//��l���̌��e�U���̉摜
	LoadDivGraph("syuzinnkouJYUU.bmp", 5, 5, 1, 31, 35, playerKENJYUU);
	//��l���̌��e�U���̉摜
	LoadDivGraph("syuzinnkouJYUUhidarimuki.bmp", 5, 5, 1, 31, 35, playerKENJYUUhidari);

	//�U�����̕�����`�悷�邽�߂̓ǂݍ��݁B
	LoadDivGraph("Great!!.bmp", 1, 1, 1, 70, 30, mozigrateHandle);


	//�G�̍U���̉摜�̓ǂ݂��݁B

	LoadDivGraph("ENEMYkougekiA1.bmp", 1, 1, 1, 22, 33, ENEMYkougekiA1Handle);
	LoadDivGraph("ENEMYkougekiA2.bmp", 1, 1, 1, 36, 33, ENEMYkougekiA2Handle);

	LoadDivGraph("stage2enemy2attackA.bmp", 1, 1, 1, 30, 45, STAGE2ENEMY2kougekiA1Handle);
	LoadDivGraph("stage2ememy2B.bmp", 1, 1, 1, 45, 45, STAGE2ENEMY2kougekiB1Handle);

	LoadDivGraph("enemystage2attackanemy1.bmp", 1, 1, 1, 66, 45, STAGE2ENEMY1kougekiA1Handle);
	LoadDivGraph("enemystage2attack2anemy1.bmp", 1, 1, 1, 66, 45, STAGE2ENEMY1kougekiB1Handle);

	//�G1���_���[�W�𕉂����ۂ̉摜�B
	LoadDivGraph("enemydamegi.bmp", 1, 1, 1, 80, 33, enemydamegeHandle);

	//�G2���_���[�W�𕉂����ۂ̉摜�B
	LoadDivGraph("enemystage2damegi.bmp", 1, 1, 1, 66, 45, enemy2damegeHandle);

	//�G3���_���[�W�𕉂����ۂ̉摜�B
	LoadDivGraph("stage2ememy3damegi.bmp", 1, 1, 1, 45, 45, enemy3damegeHandle);


	LoadDivGraph("enemy2hirumi.bmp", 1, 1, 1, 30, 45, STAGE2ENEMY1hirumiHandle);

	LoadDivGraph("enemy3hirumi.bmp", 1, 1, 1, 30, 45, STAGE2ENEMY2hirumiHandle);

	LoadDivGraph("enemy2.bmp", 1, 1, 1, 35, 33, enemy2Handle);
	LoadDivGraph("enemy2A.bmp", 1, 1, 1, 35, 33, enemy2AHandle);

	LoadDivGraph("enemystage2KAI.bmp", 3, 3, 1, 22, 45, enemy2);
	LoadDivGraph("enemy2stage2KAI.bmp", 3, 3, 1, 22, 45, enemy3);


	//�E�������U��
	LoadDivGraph("syuzinnkouKATANA.bmp", 1, 1, 1, 30, 50, KATANA);
	LoadDivGraph("syuzinnkouKATANA2.bmp", 1, 1, 1, 40, 40, KATANA2);
	LoadDivGraph("syuzinnkouKATANA2.5.bmp", 1, 1, 1, 40, 40, KATANA3A);
	LoadDivGraph("syuzinnkouKATANA3.bmp", 1, 1, 1, 40, 40, KATANA3);

	//���������U��
	LoadDivGraph("syuzinnkouKATANAB.bmp", 1, 1, 1, 30, 50, KATANAB);
	LoadDivGraph("syuzinnkouKATANA2B.bmp", 1, 1, 1, 40, 40, KATANA2B);
	LoadDivGraph("syuzinnkouKATANA2.5B.bmp", 1, 1, 1, 40, 40, KATANA3B1);
	LoadDivGraph("syuzinnkouKATANA3B.bmp", 1, 1, 1, 40, 40, KATANA3B);

	LoadDivGraph("syuzinnkouKONNBO1BHANTEN.bmp", 1, 1, 1, 44, 33, kikkuhanntenn);

	//�E�ɕ���
	LoadDivGraph("migiaruku.bmp", 1, 1, 1, 35, 33, migiarukugazou);
	LoadDivGraph("migiaruku2.bmp", 1, 1, 1, 35, 33, migiaruku2gazou);
	//���ɕ���
	LoadDivGraph("hidariaruku.bmp", 1, 1, 1, 35, 33, hidariarukugazou);
	LoadDivGraph("hidariaruku2.bmp", 1, 1, 1, 35, 33, hidariaruku2gazou);
	//���ɕ���
	LoadDivGraph("sitaaruku.bmp", 1, 1, 1, 35, 33, sitaarukugazou);
	LoadDivGraph("sitaaruku2.bmp", 1, 1, 1, 35, 33, sitaaruku2gazou);

	//��ɕ���
	LoadDivGraph("uearuku.bmp", 1, 1, 1, 35, 33, uearukugazou);
	LoadDivGraph("uearuku2.bmp", 1, 1, 1, 35, 33, uearuku2gazou);

	//������摜
	LoadDivGraph("yokeru.bmp", 1, 1, 1, 30, 33, syuzinnkouyokerugazou);
	LoadDivGraph("yokeru2.bmp", 1, 1, 1, 30, 33, syuzinnkouyokerugazou2);
	// �X�e�[�W���f���̓ǂݍ���
	//stgModelHandle = MV1LoadModel("ColTestStage.mqo");

	//�ƃ��f���̓ǂ݂���
	houseModel = MV1LoadModel("cottage_fbx.mv1");

	//houseModel = MV1LoadModel("untitled.mv1");

	//�|�[���̃��f���̓ǂ݂���
	poleModel = MV1LoadModel("Power Pole.mv1");

	// �n�ʉ摜�̓ǂݍ���
	jimenGHandle = MV1LoadModel("Assets/Floor.mv1");

	// �Â��o�X�摜�̓ǂݍ���
	old_trailerHandle = MV1LoadModel("Assets/old_trailer_fbx.mv1");

	// �Â��o�X�摜�̓ǂݍ���
	firudoModel = MV1LoadModel("electricbox.mv1");


	//BGM
	//ChangeVolumeSoundMem(140, waraigoesound);//���̊֐��ɂ���ĉ����̃{�����[����ݒ�ł���B
	//waraigoesound = LoadSoundMem("waraigoe.mp3");

	//ChangeVolumeSoundMem(140, waraigoesound2);//���̊֐��ɂ���ĉ����̃{�����[����ݒ�ł���B
	//waraigoesound2 = LoadSoundMem("���쌠�t���[ ���p���p�\ �� �y���ʉ��z�@�΂����@�吨�@��̑O�̃A�����J�̃R���f�B�̂悤�ȁA�킴�Ƃ炵���΂���.mp4");

	//ChangeVolumeSoundMem(140, kodomokorositasound);//���̊֐��ɂ���ĉ����̃{�����[����ݒ�ł���B
	//kodomokorositasound = LoadSoundMem("�X�������ȁ@��i�V�Q�̂Q  �h���H���U�[�N.mp4");

	//jimenGHandle = LoadGraph("KabeTex.bmp", 0);	// !!!!�ǉ�
	// �E�C���h�E�̃T�C�Y���蓮�ł͂ł����A���E�C���h�E�̃T�C�Y�ɍ��킹�Ċg������Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// ��ʃT�C�Y�͍ő��780*680�ɂ��Ă���


	// �ŏ��� 640x480 �ɂ��Ă���

	//SetWindowSize(980, 980);
	///battle_Initialize();//�o�g���̂��߂ɓǂݍ��މ摜

	InitStage(); // stage, pos �̏�����

	return true;
}

bool Game::Input() {


	return true;
}

bool Game::Update() {


	return true;
}

bool Game::Draw() {


	return true;
}


void Game ::InitStage()  // stage �� pos ������������//�X�e�[�W2��121�s�ڂ̃v���O�����ɂ��A�����ō��ꂽ�u�_�v���u���v�ɂȂ��Ă���A
{
	for (j = 0; j < 7; j++) {
		int w = (j - 3) * 230, h = 280;//�X�e�[�W�̉��̈ʒu�Ō��߂������Œ肵���܂܂����ő傫����ς���(���E�֐L�тđ傫���Ȃ�B)�A�����͑傫����ς���
		for (i = 4; --i >= 0; ) {
			stage[i][j][0] = w + 750, stage[i][j][1] = h + 230;//�X�e�[�W�̈ʒu��ς���A�����͈ʒu��ς���
			w = w * 7.8 / 10, h = h * 9 / 10;
		}
	}
	//�X�e�[�W��̒��S�̍��W��\���Ă���B
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++) {
			pos[i][j][0] = (stage[i][j][0] + stage[i + 1][j + 1][0]) / 2 - 25;
			pos[i][j][1] = (stage[i][j][1] + stage[i + 1][j + 1][1]) / 2 - 65;
		}
	}


	// !!!!�J�̉��o
	for (int rain = 0; rain < rain_power; rain++)
	{
		int l = GetRand(50) + 10;	// �J���̒���
		rain_hairetsu[rain][0] = GetRand(1470);	// �n�_X
		rain_hairetsu[rain][1] = -GetRand(780);	// �n�_Y
		rain_hairetsu[rain][2] = rain_hairetsu[rain][0] + l * 1;	// �I�_X
		rain_hairetsu[rain][3] = rain_hairetsu[rain][1] - l * rain_kakudo;	// �I�_Y
		rain_hairetsu[rain][4] = 0;	// X�ړ��ω���
		rain_hairetsu[rain][5] = 0;	// Y�ړ��ω���
	}

	// !!!!��̉��o
	for (int snow = 0; snow < snow_power; snow++)
	{
		snow_hairetsu[snow][0] = GetRand(1470);	// X�ʒu
		snow_hairetsu[snow][1] = -GetRand(780);	// Y�ʒu
		snow_hairetsu[snow][2] = 0;	// X�ړ��ω���
		snow_hairetsu[snow][3] = 0;	// Y�ړ��ω���
		int rand = 0;
		if (GetRand(1))
		{
			rand = GetRand(3);	// X����
		}
		else {
			rand = -GetRand(3);	// -X����
		}
		snow_hairetsu[snow][4] = rand;	// X�ړ�������
		snow_hairetsu[snow][5] = GetRand(5);	// ��̑傫��
	}
}
