#include "DxLib.h"

#define PI    3.1415926535897932384626433832795f

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    SetGraphMode(1470, 780, 32);      // ウィンドウの大きさを指定
    ChangeWindowMode(TRUE);             // 全画面ではなくウインドウを使用
    SetWindowSizeExtendRate(1.0f);
   
    SetDrawScreen(DX_SCREEN_BACK);     // 裏画面を使用する設定
    int GHandle;
    int x = 0;
    int y = 0;
    if (DxLib_Init() == -1)    // ＤＸライブラリ初期化処理
    {
        return -1;    // エラーが起きたら直ちに終了
    }
    while (ProcessMessage() == 0) {
        //画面クリア
        ClearDrawScreen();

        ++x;
        
        // test1.bmpの読み込み
        GHandle = LoadGraph("charall.png");

        // 読みこんだグラフィックを回転描画
        DrawRotaGraph(320, 240, 1.5f, (PI / 2) - x/12, GHandle, TRUE);
        // 裏画面の内容を表画面に
        ScreenFlip();
    }
   
   

    WaitKey();        // 結果を見るためにキー待ち(『WaitKey』を使用)

    DxLib_End();        // ＤＸライブラリ使用の終了処理

    return 0;        // ソフトの終了
}
