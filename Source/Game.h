/*
     ���̏�����
     ���̃N���X�̒��ӓ_
*/
#pragma once
#include "dxlib.h"

class Game {
public:  //�O����Ăяo�������
    Game();
    ~Game();

    bool Init();  //��������Load
    bool Input();  //���͊֌W
    bool Update();  //���t���[���Ăяo�����
    bool Draw();

  
private:
    

    //�ړ����Ă����ϐ��B---------
public:
   

    int stage[4][7][2];  // �Տ�̃}�X�̊i�q�_�̍��W
    int pos[3][6][2];    // �L�����`����W
    // !!!!�J���~�炷���o
    int rain_power;			// ��
    int rain_hairetsu[100][6];	// �z��
    int rain_kakudo;			// ���ˊp�x��
    int rain_speed;			// ���x

    // !!!!����~�炷���o
    int snow_power;			// ��
    int snow_hairetsu[100][6];	// �z��
    int snow_kakudo;			// ���ˊp�x��
    double snow_speed;		// ���x

    //initStage���牺�̕ϐ�

    int White;
    int function_status;//�퓬��ʒ���1�Ƃ��邽�߂̕ϐ�function_status�̒�`

   

    int lockonHandle[3];
    int enemyGHandle[4];   // �G�̃O���t�B�b�N�n���h���i�[�p�z��
    int playerGHandle[8];  // ���̃O���t�B�b�N�n���h���i�[�p�z��
    int kikennhanndle[12];
    // 0-2:�������A3-5:�E�����A6-8:�O�����A9-11:������
    int hartmarkhanndle[3];
    int bloodGHandle[3];
    int MovieGraphHandle;//�w�i��gif�̂��߂̕ϐ�
    int anarogunoizuGraphHandle;
    int testplayerGHandle[1];
   
    int enemyImage;    // �G ������ �����l�ł�enemyImage��enemyGHandle[3]�������Ă邾���ŁA�����ɂ���Ă�enemyGHandle[3]���ӊO������B
    int playerImage;   // �� �E����//����Łuint playerGHandle[8];  // ���̃O���t�B�b�N�n���h���i�[�p�z��v�ƒ�`���āA
  
    int testplayerImage;   // �� �E����
    int lockImge;
    int hartmarkImge;
    int bloodImage;
    int gimenHandle;

    
    int taitolGraphHandle;
    int taitoitoumeika;
    int sinnzouGraphHandle;
    int sinnzoutoumeika;
    int snowGraphHandle;
   
   
    //��l���̍U����\���摜�𐧌䂷�邽�߂̕ϐ�

    int playernaguruImage;
    int playernaguruAGHandle[1];
    int playernaguruBGHandle[1];
    int playertabakoImage;
    int playertabakoAHandle[1];
    int playertabakoBHandle[1];
    int playertabakoCHandle[1];
    int playertabakoDHandle[1];
    int playeridouAHandle[1];
    int playeridouImage;
    int playeridouA3Handle[1];
    int playerKONNBO1AHandle[1];
    int playerKONNBO1AImage;
    int KONNBO1A;
    int playerKONNBO1BHandle[1];
    int playerKONNBO1BImage;
    int ENEMYkougekiA1Handle[1];
    int ENEMYkougekiA2Handle[1];
    int ENEMYkougekiA1Image;
    int ENEMYkougekiA2Image;
    int playeridouA2Image;
    int playeridouA2Handle[1];
    int playeridouA4Handle[1];
    int mozigrateHandle[1];
    int kaiwaHandle;
    int SHOTHandle;
    int vioraHandle;
    int K1Handle;
    int playerKONNBO1ANOIZU1Handle[1];
    int playerKONNBO1ANOIZU2Handle[1];
    int playerKONNBO1ANOIZU3Handle[1];
    int playerKONNBO1ANOIZU4Handle[1];
    int player1GHandle[1];
    int player2GHandle[1];
    int player3GHandle[1];
    int player4GHandle[1];
    int player5GHandle[1];
    int dennwaHandle;
    int RED;      // �ԐF�R�[�h���擾
    int settoku1Handle;
    int enemy2Image;
    int enemy2Handle[1];
    int enemy2AHandle[1];
    int settokugamenntyuunohaikeiHandle;
    int sentougoHandle;
    int countimuHandle;
    int enemytalk1Handle;
    int enemytalk2Handle;
    int ModelHandle;
    int handle;
    int enemygameGHandle[1];
    int jimenGHandle;
    int houseModel;
    int enemy2[3];
    int enemyImage2;
    int enemy3[3];
    int enemyImage3;
    int playerKENJYUUImage;
    int playerKENJYUU[5];
    int playernaguruBGHandle2[1];
    int playernaguruBGHandle3[1];
    int taitolHandle[1];
    int STAGE2ENEMY2kougekiA1Handle[1];
    int STAGE2ENEMY2kougekiB1Handle[1];
    int STAGE2ENEMY1kougekiA1Handle[1];
    int STAGE2ENEMY1hirumiHandle[1];
    int STAGE2ENEMY2hirumiHandle[1];
    int STAGE2ENEMY1kougekiB1Handle[1];
    int enemy1KENJYUUHandle[2];
    int KATANA[1];
    int KATANA2[1];
    int KATANA3A[1];
    int KATANA3[1];
    int kikkuhanntenn[1];
    int playeridouA5Handle[1];
    int playergardGHandle[1];
    int playerdamegeGHandle[1];
    int enemy2damegeHandle[1];
    int enemy3damegeHandle[1];
    int old_trailerHandle;
    int poleModel;
    int enemydamegeHandle[1];
    int byouga;

    //�摜
    int dennwa;
    int firudoModel;
    int taitol2Handle[1];
    int kodomogif;
    int stage2haikeiHandle;
    int taitolhaikeiHandle;
    int stage1haikeiHandle;
    int migiarukugazou[1];
    int migiaruku2gazou[1];
    int hidariarukugazou[1];
    int hidariaruku2gazou[1];
    int sitaarukugazou[1];
    int sitaaruku2gazou[1];
    int uearukugazou[1];
    int uearuku2gazou[1];
    int syuzinnkouyokerugazou[1];
    int syuzinnkouyokerugazou2[1];
    int playerHandle2[3];
    int playeridouAhidariHandle[1];
    int playeridouA4hidariHandle[1];
    int playeridouA2hidariHandle[1];
    int playeridouA3hidariHandle[1];
    int playeridouA5hidariHandle[1];
    int playerKENJYUUhidari[5];
    int playernaguruAGHandleB[1];
    int playernaguruBGHandleB[1];
    int playernaguruBGHandle2B[1];
    int playernaguruBGHandle3B[1];
    int playerKONNBO1AHandleB[1];
    int playerKONNBO1ANOIZU1HandleB[1];
    int playerKONNBO1ANOIZU2HandleB[1];
    int playerKONNBO1ANOIZU3HandleB[1];
    int playerKONNBO1ANOIZU4HandleB[1];
    int playerKONNBO1BHandleB[1];
    int KATANAB[1];
    int KATANA2B[1];
    int KATANA3B[1];
    int KATANA3B1[1];


private:  //�����̃N���X�ł����g���Ȃ�����

    void InitStage();
};