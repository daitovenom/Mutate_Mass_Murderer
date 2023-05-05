/*
     何の処理か
     このクラスの注意点
*/
#pragma once
#include "dxlib.h"

class Game {
public:  //外から呼び出せるもの
    Game();
    ~Game();

    bool Init();  //初期化とLoad
    bool Input();  //入力関係
    bool Update();  //毎フレーム呼び出される
    bool Draw();

  
private:
    

    //移動してきた変数達---------
public:
   

    int stage[4][7][2];  // 盤上のマスの格子点の座標
    int pos[3][6][2];    // キャラ描画座標
    // !!!!雨を降らす演出
    int rain_power;			// 量
    int rain_hairetsu[100][6];	// 配列
    int rain_kakudo;			// 入射角度量
    int rain_speed;			// 速度

    // !!!!雪を降らす演出
    int snow_power;			// 量
    int snow_hairetsu[100][6];	// 配列
    int snow_kakudo;			// 入射角度量
    double snow_speed;		// 速度

    //initStageから下の変数

    int White;
    int function_status;//戦闘画面中は1とするための変数function_statusの定義

   

    int lockonHandle[3];
    int enemyGHandle[4];   // 敵のグラフィックハンドル格納用配列
    int playerGHandle[8];  // 俺のグラフィックハンドル格納用配列
    int kikennhanndle[12];
    // 0-2:後ろ向き、3-5:右向き、6-8:前向き、9-11:左向き
    int hartmarkhanndle[3];
    int bloodGHandle[3];
    int MovieGraphHandle;//背景のgifのための変数
    int anarogunoizuGraphHandle;
    int testplayerGHandle[1];
   
    int enemyImage;    // 敵 左向き 初期値でのenemyImageにenemyGHandle[3]が入ってるだけで、条件によってはenemyGHandle[3]も意外も入る。
    int playerImage;   // 俺 右向き//★上で「int playerGHandle[8];  // 俺のグラフィックハンドル格納用配列」と定義して、
  
    int testplayerImage;   // 俺 右向き
    int lockImge;
    int hartmarkImge;
    int bloodImage;
    int gimenHandle;

    
    int taitolGraphHandle;
    int taitoitoumeika;
    int sinnzouGraphHandle;
    int sinnzoutoumeika;
    int snowGraphHandle;
   
   
    //主人公の攻撃を表す画像を制御するための変数

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
    int RED;      // 赤色コードを取得
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

    //画像
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


private:  //自分のクラスでしか使えないもの

    void InitStage();
};