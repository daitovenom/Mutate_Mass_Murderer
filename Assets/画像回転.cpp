#include "DxLib.h"

#define PI    3.1415926535897932384626433832795f

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    SetGraphMode(1470, 780, 32);      // �E�B���h�E�̑傫�����w��
    ChangeWindowMode(TRUE);             // �S��ʂł͂Ȃ��E�C���h�E���g�p
    SetWindowSizeExtendRate(1.0f);
   
    SetDrawScreen(DX_SCREEN_BACK);     // ����ʂ��g�p����ݒ�
    int GHandle;
    int x = 0;
    int y = 0;
    if (DxLib_Init() == -1)    // �c�w���C�u��������������
    {
        return -1;    // �G���[���N�����璼���ɏI��
    }
    while (ProcessMessage() == 0) {
        //��ʃN���A
        ClearDrawScreen();

        ++x;
        
        // test1.bmp�̓ǂݍ���
        GHandle = LoadGraph("charall.png");

        // �ǂ݂��񂾃O���t�B�b�N����]�`��
        DrawRotaGraph(320, 240, 1.5f, (PI / 2) - x/12, GHandle, TRUE);
        // ����ʂ̓��e��\��ʂ�
        ScreenFlip();
    }
   
   

    WaitKey();        // ���ʂ����邽�߂ɃL�[�҂�(�wWaitKey�x���g�p)

    DxLib_End();        // �c�w���C�u�����g�p�̏I������

    return 0;        // �\�t�g�̏I��
}
