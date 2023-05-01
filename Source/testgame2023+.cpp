#include "DxLib.h"
#include "key.h"
#include "stgae1Player_Update.h"
#include "talk.h"
#include "Player/playerhensuuVr2.h"
#include "taitol.h"
#include "countine.h"
#include "stage1Player_Draw.h"
#include "stgae2Player_Update.h"
#include "stage2Player_Draw.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>



#pragma warning(disable: 4996)


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int nCmdShow)
{
	typedef struct {
		int Seen;
	}SaveData_t;
	
	SetGraphMode(1470, 780, 32);      // ウィンドウの大きさを指定
	ChangeWindowMode(TRUE);             // 全画面ではなくウインドウを使用
	SetWindowSizeExtendRate(1.0f);
	if (DxLib_Init() == -1) return -1;  // ＤＸライブラリ初期化処理
	SetDrawScreen(DX_SCREEN_BACK);     // 裏画面を使用する設定


	//↓★関数で使いたい画像を瞬間に呼ぶのは時間がかかるし重いのでメインの中に既にスタンバっている状態にする。
	SetTransColor(255, 255, 255); // 読み込む画像の前にこいつを置くことで透明化できる。ループ内にも書いて正しく動くが毎回読み込むようになってしまうため処理が遅くなる。

	// ムービーファイルをロードします。
	MovieGraphHandle = LoadGraph("180half_f.gif");
	// ムービーを再生状態にします
	PlayMovieToGraph(MovieGraphHandle);
	// タイトルで出てくるムービーファイルをロードします。
	//taitolGraphHandle = LoadGraph("321000000_mmw227fw.gif");
	// タイトルで出てくるムービーを再生状態にします
	PlayMovieToGraph(taitolGraphHandle);
	//敵がダメージを受けた時の心臓のムービーファイルをロードします。
	sinnzouGraphHandle = LoadGraph("original.gif");
	// 敵がダメージを受けた時の心臓のムービーを再生状態にします
	PlayMovieToGraph(sinnzouGraphHandle);

	// 雪ムービーファイルをロードします。
	snowGraphHandle = LoadGraph("20160103081928.gif");
	// 雪ムービーを再生状態にします
	PlayMovieToGraph(snowGraphHandle);

	// アナログノイズムービーファイルをロードします。
	anarogunoizuGraphHandle = LoadGraph("MOSHED-2020-6-1-23-33-37.gif");
	// アナログノイズムービーを再生状態にします
	PlayMovieToGraph(anarogunoizuGraphHandle);

	// ファイルをロードします。
	gimenHandle = LoadGraph("photo0000-3903.bmp");
	PlayMovieToGraph(gimenHandle);

	// ファイルをロードします。
	kodomogif = LoadGraph("kodomo.gif");
	PlayMovieToGraph(kodomogif);
	// ファイルをロードします。
	 //kaiwaHandle = OpenMovieToGraph("MOSHED-2020-6-2-19-11-5.gif");

	//SeekMovieToGraph(kaiwaHandle, 0);
	//PlayMovieToGraph(kaiwaHandle);

	// 電話にでるかどうかのファイルをロードします。
	dennwaHandle = LoadGraph("dennwasenntaku.gif");

	//会話のファイルをロードします。
	enemytalk1Handle = LoadGraph("私のビデオ1.gif");
	//会話のファイルをロードします。
	enemytalk2Handle = LoadGraph("enemytalk2.gif");

	dennwa = LoadGraph("21b667f1-88cb-4e41-9bdc-41351a55655b.gif");

	// ファイルをロードします。
	SHOTHandle = LoadGraph("ENEMYGIF1.gif");
	PlayMovieToGraph(SHOTHandle);


	// ヴィオラをロードします。
	vioraHandle = LoadGraph("MOSHED-2020-6-2-19-37-21.gif");
	PlayMovieToGraph(vioraHandle);

	// 説得中の背景をロードします。
	settokugamenntyuunohaikeiHandle = LoadGraph("settokugamenntyuunohaikei.gif");
	PlayMovieToGraph(settokugamenntyuunohaikeiHandle);

	// 選択し1をロードします。
	settoku1Handle = LoadGraph("settoku1.gif");

	// 戦闘後をロードします。
	sentougoHandle = LoadGraph("senntougonoOUT.gif");

	// コンティニュー画面の背景をロードします。
	countimuHandle = LoadGraph("MOSHED-2020-6-1-23-49-29.gif");
	PlayMovieToGraph(countimuHandle);

	//戦闘中の背景
	stage1haikeiHandle = LoadGraph("stage1.gif");
	PlayMovieToGraph(stage1haikeiHandle);

	//戦闘中の背景
	stage2haikeiHandle = LoadGraph("stage2haikei.gif");
	PlayMovieToGraph(stage2haikeiHandle);

	//女教師の電話映像
	dennwa = LoadGraph("dennwa2.gif");
	PlayMovieToGraph(dennwa);

	//タイトルの背景。
	taitolhaikeiHandle = LoadGraph("taitoruhaikei.gif");
	PlayMovieToGraph(taitolhaikeiHandle);

	LoadDivGraph("lockon.bmp", 3, 3, 1, 23, 23, lockonHandle);//なので、一度読み込むだけ画像は使えるし、処理を遅くしないためにループに入る前かつWinMainの中に書いた。
	LoadDivGraph("ENEMYVR1.bmp", 3, 3, 1, 18, 33, enemyGHandle);
	LoadDivGraph("ENEMY1.bmp", 1, 1, 1, 18, 33, enemygameGHandle);//怯んだ敵の画像


	//右向き
	LoadDivGraph("playersyuzinnkoukuronuriKAIZOU6.bmp", 3, 3, 1, 20, 33, playerGHandle);

	//左向き
	LoadDivGraph("playersyuzinnkoukuronuriKAIZOU6a.bmp", 3, 3, 1, 20, 33, playerHandle2);


	LoadDivGraph("tuubyousyuzinnkou1bmp.bmp", 1, 1, 1, 35, 33, player1GHandle);
	LoadDivGraph("tuubyousyuzinnkou2bmp.bmp", 1, 1, 1, 35, 33, player2GHandle);
	LoadDivGraph("tuubyousyuzinnkou3bmp.bmp", 1, 1, 1, 35, 33, player3GHandle);
	LoadDivGraph("tuubyousyuzinnkou4bmp.bmp", 1, 1, 1, 35, 33, player4GHandle);
	LoadDivGraph("tuubyousyuzinnkou5bmp.bmp", 1, 1, 1, 35, 33, player5GHandle);

	//攻撃を食らったときの画像。
	LoadDivGraph("syuzinnkoukurau1KAI2.bmp", 1, 1, 1, 35, 33, playerdamegeGHandle);

	//主人公のガードモーション
	LoadDivGraph("syuzinnkougard.bmp", 1, 1, 1, 44, 33, playergardGHandle);

	//タイトル
	LoadDivGraph("mmm2.bmp", 1, 1, 1, 92, 7, taitolHandle);
	LoadDivGraph("HANDOFDEATH2.bmp", 1, 1, 1, 90, 9, taitol2Handle);

	LoadDivGraph("syuzinnkoukuronuriA.bmp", 1, 1, 1, 44, 33, testplayerGHandle);
	LoadDivGraph("kikenn.png", 12, 4, 3, 62, 66, kikennhanndle);
	LoadDivGraph("hartmark.bmp", 3, 3, 1, 13, 10, hartmarkhanndle);
	LoadDivGraph("blood.bmp", 3, 3, 1, 13, 10, bloodGHandle);

	//右向き殴る
	LoadDivGraph("naguruAkuronuri.bmp", 1, 1, 1, 44, 33, playernaguruAGHandle);
	LoadDivGraph("naguruBkuronuri.bmp", 1, 1, 1, 44, 33, playernaguruBGHandle);
	LoadDivGraph("naguruBkuronuri2.bmp", 1, 1, 1, 44, 33, playernaguruBGHandle2);
	LoadDivGraph("naguruBkuronuri3.bmp", 1, 1, 1, 44, 33, playernaguruBGHandle3);

	//左向き殴る
	LoadDivGraph("naguruAkuronuriB.bmp", 1, 1, 1, 44, 33, playernaguruAGHandleB);
	LoadDivGraph("naguruBkuronuriB.bmp", 1, 1, 1, 44, 33, playernaguruBGHandleB);
	LoadDivGraph("naguruBkuronuri2B.bmp", 1, 1, 1, 44, 33, playernaguruBGHandle2B);
	LoadDivGraph("naguruBkuronuri3B.bmp", 1, 1, 1, 44, 33, playernaguruBGHandle3B);

	//主人公タバコ
	LoadDivGraph("syuzinnkoutabakoA.bmp", 1, 1, 1, 22, 33, playertabakoAHandle);
	LoadDivGraph("syuzinnkoutabakoB.bmp", 1, 1, 1, 22, 33, playertabakoBHandle);
	LoadDivGraph("syuzinnkoutabakoC.bmp", 1, 1, 1, 22, 33, playertabakoCHandle);
	LoadDivGraph("syuzinnkoutabakoD.bmp", 1, 1, 1, 22, 33, playertabakoDHandle);//こいつだけ画像の横の大きさは26だが、syuzinnkoutabakoA～Cに合わせて22とした。22としても切り取られることはない。


	//右向きの蹴る
	LoadDivGraph("syuzinnkouKONNBO1ANOIZU1.bmp", 1, 1, 1, 35, 33, playerKONNBO1AHandle);
	LoadDivGraph("syuzinnkouKONNBO1ANOIZU1.bmp", 1, 1, 1, 35, 33, playerKONNBO1ANOIZU1Handle);
	LoadDivGraph("syuzinnkouKONNBO1ANOIZU2.bmp", 1, 1, 1, 35, 33, playerKONNBO1ANOIZU2Handle);
	LoadDivGraph("syuzinnkouKONNBO1ANOIZU3.bmp", 1, 1, 1, 35, 33, playerKONNBO1ANOIZU3Handle);
	LoadDivGraph("syuzinnkouKONNBO1ANOIZU4.bmp", 1, 1, 1, 35, 33, playerKONNBO1ANOIZU4Handle);

	LoadDivGraph("syuzinnkouKONNBO1B.bmp", 1, 1, 1, 35, 33, playerKONNBO1BHandle);

	//左向きの蹴る
	LoadDivGraph("syuzinnkouKONNBO1ANOIZU1B.bmp", 1, 1, 1, 35, 33, playerKONNBO1AHandleB);
	LoadDivGraph("syuzinnkouKONNBO1ANOIZU1B.bmp", 1, 1, 1, 35, 33, playerKONNBO1ANOIZU1HandleB);
	LoadDivGraph("syuzinnkouKONNBO1ANOIZU2B.bmp", 1, 1, 1, 35, 33, playerKONNBO1ANOIZU2HandleB);
	LoadDivGraph("syuzinnkouKONNBO1ANOIZU3B.bmp", 1, 1, 1, 35, 33, playerKONNBO1ANOIZU3HandleB);
	LoadDivGraph("syuzinnkouKONNBO1ANOIZU4B.bmp", 1, 1, 1, 35, 33, playerKONNBO1ANOIZU4HandleB);

	LoadDivGraph("syuzinnkouKONNBO1BHANTEN.bmp", 1, 1, 1, 35, 33, playerKONNBO1BHandleB);

	//スライド移動の画像。
	LoadDivGraph("playersyuzinnkouidouA.bmp", 1, 1, 1, 22, 33, playeridouAHandle);
	LoadDivGraph("playersyuzinnkouidouA4.bmp", 1, 1, 1, 22, 33, playeridouA4Handle);
	LoadDivGraph("playersyuzinnkouidouA2.bmp", 1, 1, 1, 22, 33, playeridouA2Handle);
	LoadDivGraph("playersyuzinnkouidouA3.bmp", 1, 1, 1, 22, 33, playeridouA3Handle);
	LoadDivGraph("playersuraido5.bmp", 1, 1, 1, 22, 33, playeridouA5Handle);
	//左向きのスライド移動の画像。
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




	//主人公の拳銃攻撃の画像
	LoadDivGraph("syuzinnkouJYUU.bmp", 5, 5, 1, 31, 35, playerKENJYUU);
	//主人公の拳銃攻撃の画像
	LoadDivGraph("syuzinnkouJYUUhidarimuki.bmp", 5, 5, 1, 31, 35, playerKENJYUUhidari);

	//攻撃中の文字を描画するための読み込み。
	LoadDivGraph("Great!!.bmp", 1, 1, 1, 70, 30, mozigrateHandle);


	//敵の攻撃の画像の読みこみ。

	LoadDivGraph("ENEMYkougekiA1.bmp", 1, 1, 1, 22, 33, ENEMYkougekiA1Handle);
	LoadDivGraph("ENEMYkougekiA2.bmp", 1, 1, 1, 36, 33, ENEMYkougekiA2Handle);

	LoadDivGraph("stage2enemy2attackA.bmp", 1, 1, 1, 30, 45, STAGE2ENEMY2kougekiA1Handle);
	LoadDivGraph("stage2ememy2B.bmp", 1, 1, 1, 45, 45, STAGE2ENEMY2kougekiB1Handle);

	LoadDivGraph("enemystage2attackanemy1.bmp", 1, 1, 1, 66, 45, STAGE2ENEMY1kougekiA1Handle);
	LoadDivGraph("enemystage2attack2anemy1.bmp", 1, 1, 1, 66, 45, STAGE2ENEMY1kougekiB1Handle);

	//敵1がダメージを負った際の画像。
	LoadDivGraph("enemydamegi.bmp", 1, 1, 1, 80, 33, enemydamegeHandle);

	//敵2がダメージを負った際の画像。
	LoadDivGraph("enemystage2damegi.bmp", 1, 1, 1, 66, 45, enemy2damegeHandle);

	//敵3がダメージを負った際の画像。
	LoadDivGraph("stage2ememy3damegi.bmp", 1, 1, 1, 45, 45, enemy3damegeHandle);


	LoadDivGraph("enemy2hirumi.bmp", 1, 1, 1, 30, 45, STAGE2ENEMY1hirumiHandle);

	LoadDivGraph("enemy3hirumi.bmp", 1, 1, 1, 30, 45, STAGE2ENEMY2hirumiHandle);

	LoadDivGraph("enemy2.bmp", 1, 1, 1, 35, 33, enemy2Handle);
	LoadDivGraph("enemy2A.bmp", 1, 1, 1, 35, 33, enemy2AHandle);

	LoadDivGraph("enemystage2KAI.bmp", 3, 3, 1, 22, 45, enemy2);
	LoadDivGraph("enemy2stage2KAI.bmp", 3, 3, 1, 22, 45, enemy3);


	//右向き刀攻撃
	LoadDivGraph("syuzinnkouKATANA.bmp", 1, 1, 1, 30, 50, KATANA);
	LoadDivGraph("syuzinnkouKATANA2.bmp", 1, 1, 1, 40, 40, KATANA2);
	LoadDivGraph("syuzinnkouKATANA2.5.bmp", 1, 1, 1, 40, 40, KATANA3A);
	LoadDivGraph("syuzinnkouKATANA3.bmp", 1, 1, 1, 40, 40, KATANA3);

	//左向き刀攻撃
	LoadDivGraph("syuzinnkouKATANAB.bmp", 1, 1, 1, 30, 50, KATANAB);
	LoadDivGraph("syuzinnkouKATANA2B.bmp", 1, 1, 1, 40, 40, KATANA2B);
	LoadDivGraph("syuzinnkouKATANA2.5B.bmp", 1, 1, 1, 40, 40, KATANA3B1);
	LoadDivGraph("syuzinnkouKATANA3B.bmp", 1, 1, 1, 40, 40, KATANA3B); 

	LoadDivGraph("syuzinnkouKONNBO1BHANTEN.bmp", 1, 1, 1, 44, 33, kikkuhanntenn);

	//右に歩く
	LoadDivGraph("migiaruku.bmp", 1, 1, 1, 35, 33, migiarukugazou);
	LoadDivGraph("migiaruku2.bmp", 1, 1, 1, 35, 33, migiaruku2gazou);
	//左に歩く
	LoadDivGraph("hidariaruku.bmp", 1, 1, 1, 35, 33, hidariarukugazou);
	LoadDivGraph("hidariaruku2.bmp", 1, 1, 1, 35, 33, hidariaruku2gazou);
	//下に歩く
	LoadDivGraph("sitaaruku.bmp", 1, 1, 1, 35, 33, sitaarukugazou);
	LoadDivGraph("sitaaruku2.bmp", 1, 1, 1, 35, 33, sitaaruku2gazou);

	//上に歩く
	LoadDivGraph("uearuku.bmp", 1, 1, 1, 35, 33, uearukugazou);
	LoadDivGraph("uearuku2.bmp", 1, 1, 1, 35, 33, uearuku2gazou);

	//避ける画像
	LoadDivGraph("yokeru.bmp", 1, 1, 1, 30, 33, syuzinnkouyokerugazou);
	LoadDivGraph("yokeru2.bmp", 1, 1, 1, 30, 33, syuzinnkouyokerugazou2);
	// ステージモデルの読み込み
	//stgModelHandle = MV1LoadModel("ColTestStage.mqo");

	//家モデルの読みこみ
	houseModel = MV1LoadModel("cottage_fbx.mv1");

	//houseModel = MV1LoadModel("untitled.mv1");

	//ポールのモデルの読みこみ
	poleModel = MV1LoadModel("Power Pole.mv1");

	// 地面画像の読み込み
	jimenGHandle = MV1LoadModel("Assets/Floor.mv1");

	// 古いバス画像の読み込み
	old_trailerHandle = MV1LoadModel("Assets/old_trailer_fbx.mv1");

	// 古いバス画像の読み込み
	firudoModel = MV1LoadModel("electricbox.mv1");


	//BGM
	//ChangeVolumeSoundMem(140, waraigoesound);//この関数によって音声のボリュームを設定できる。
	//waraigoesound = LoadSoundMem("waraigoe.mp3");

	//ChangeVolumeSoundMem(140, waraigoesound2);//この関数によって音声のボリュームを設定できる。
	//waraigoesound2 = LoadSoundMem("著作権フリー 商用利用可能 な 【効果音】　笑い声　大勢　一昔前のアメリカのコメディのような、わざとらしい笑い声.mp4");

	//ChangeVolumeSoundMem(140, kodomokorositasound);//この関数によって音声のボリュームを設定できる。
	//kodomokorositasound = LoadSoundMem("スラヴ舞曲　作品７２の２  ドヴォルザーク.mp4");

	//jimenGHandle = LoadGraph("KabeTex.bmp", 0);	// !!!!追加
	// ウインドウのサイズを手動ではできず、且つウインドウのサイズに合わせて拡大もしないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// 画面サイズは最大の780*680にしておく


	// 最初は 640x480 にしておく

	//SetWindowSize(980, 980);
	///battle_Initialize();//バトルのために読み込む画像

	init_stage(); // stage, pos の初期化

	while (ProcessMessage() == 0) {
		//★以下の二つのパッドキーのための関数はどの時でも使えるようにメインの中に書き込んだ。
		gpUpdateKey();
		UpdatePadState();  //パッド状態の調査
		gpUpdatePad();
		
		contorora = GetJoypadInputState(DX_INPUT_KEY_PAD1);// キー入力取得

		//☆会話の文字を一文字ずつ表示するためのプログラム。
		//if (++t == 60 * 9) { t = 60 * 9; } // 6秒ごとにリセット

		if (startmark >= 2 && ++startmark > 50) {//taitolh.hの関数がtaitol()が終わった後はこのwhileの部分から消えるので値が増えていかない、なのでここに直接書いた。
			Seen = 1; startmark = 0;
			//if (Key[KEY_INPUT_A] == 1) {
				//Seen = 0;
			//}
		}

		if (++t == 6 * 60) {
			t = 0;
		}



		if (Seen == 3) {
			Player_Update();


			//init_stage();
		//	if (enemyHP < 1) { Seen = 1; }//敵のHPが0になるとSeenを0にしたことから関数Player_Update()から離れる。なので画面はメインのプログラムに返ってくる。
			//if (playerHP < 0 || playerHP == 0) {
			//	playerHP = 0;  ++playerHPframe;//これでplayerHPframeが1だけ繰り上がる。固定ではないので次のif文に進める。
			//}
		}
		//if (playerHPframe > 0 && playerHPframe > 100) { Seen = 1; countinue = 1; playerHPframe = 0; }
		//↓多分、if (start > 0 && ++start < 200)と同じ原因で上がるべき条件の時に上がらないのと同じでうまく機能していない
		//自分と敵がある一定の時間は初期値の位置に居続けるようにするために書いた。こいつがないと開始よりも前に敵が移動してきたりする。

		//これより以下は描画するためのプログラム
		ClearDrawScreen();  // 裏画面を
		if (tai == 1 && talk >= 0 && Seen >= 0) { taitol(); }//条件はなくてもいいが条件があればセーブしてtalkやSeenの変数がどんな値でもセーブの変数とtalkやSeenの変数からタイトルが評し出来る。

		if (Seen == 1) { talkdrow(); }
		if (Seen == 2) {


			sound3 = LoadSoundMem("モーツァルト：アダージョ ロ短調 K.5402.mp4");
			playerX = 1;
			playerY = 1;
			Seen = 3;
		}
		if (Seen == 3) {

			stage1 = 1;
			BGM1 = 0;//念のためにここで0にしておく。
			//DrawFormatString(900, 1200, GetColor(255, 205, 0), "pos: %d %d %d %d\n", pos[1][4][0] - 14, pos[1][4][1] - 66, pos[1][4][0] + 64, pos[1][4][1] + 66);
			gameovercolorlock = 0;//主人公が死んでしまったを消すための変数
			stage1PlayerDraw();


			if (preframe > 0 && ++preframe < 9)preframe = 9;
			if (preframeA > 0 && ++preframeA < 9)preframeA = 9;
			if (preframeB > 0 && ++preframeB < 9)preframeB = 9;
			if (preframeC > 0 && ++preframeC < 9)preframeC = 9;



		}
		

		if (Seen == 999 && stage1 == 1) {//たまにバグるのでstage1 == 1も入れる。
			if (migimuki == 1) {
				++attackframe7;
				DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] - 25 + playerattackhanndou3, bairituY, 0, playerKONNBO1BHandle[0], TRUE);
				DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] - 25 + playerattackhanndou3, bairituY, 0, enemyImage, TRUE);
				if (attackframe7 > 48 && attackframe7 < 50) {
					playerattackhanndou = playerattackhanndou + 100;
					//motonomasunimodoru = motonomasunimodoru + 60;
					enemysabunHP = 50;
					zannzoulock = 0;
					keriwaza = 0;
					attackframe5 = 0;
					attackframe6 = 0;

					//	Seen = 301;
				}
				//蹴った後のSeenの値を変えるためにここに書いている。
				if (Seen == 999 && stage1 == 1) {
					if (attackframe7 > 50) {
						zannzoulock = 0;
						Seen = 2;
						nextattack = 0;
						//migimuki = 1;
						//hidarimuki = 0;
					}
				}
			}
			else if (hidarimuki == 1) {
				++attackframe7;
				DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] - 25 + playerattackhanndou3, bairituY, 0, kikkuhanntenn[0], TRUE);
				DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] - 25 + playerattackhanndou3, bairituY, 0, enemyImage, TRUE);
				if (attackframe7 > 48 && attackframe7 < 50) {
					playerattackhanndou = playerattackhanndou - 100;
					//motonomasunimodoru = motonomasunimodoru + 60;
					enemysabunHP = 50;
					zannzoulock = 0;
					keriwaza = 0;
					attackframe5 = 0;
					attackframe6 = 0;

					//	Seen = 301;
				}
				//蹴った後のSeenの値を変えるためにここに書いている。
				if (Seen == 999 && stage1 == 1) {
					if (attackframe7 > 50) {
						zannzoulock = 0;
						Seen = 2;
						nextattack = 0;
						//migimuki = 1;
						//hidarimuki = 0;
					}
				}
			}
		}


		//if (Seen == 2) { void game_clear(); }
		//DrawFormatString(1, 750, GetColor(255, 255, 0), "★★Rbotanosenaiframeは%d,tuikaidouframeは%d,hannilockは%d,playermovelock は%d,playermovelock2は%d", Rbotanosenaiframe, tuikaidouframe, hannilock, playermovelock, playermovelock2);
		//DrawFormatString(100, 150, GetColor(255, 255, 0), "playerattackhanndouは%d,playerattackhanndou2は%d,enemyhirumaseframelockは%d", playerattackhanndou, playerattackhanndou2, enemyhirumaseframelock);
		//DrawFormatString(1, 400, GetColor(255, 255, 0), "zannzoulockは%d,playermovelockは%d", zannzoulock,playermovelock);
		//DrawFormatString(0, 540, GetColor(255, 105, 0), "saveplayerXは%d,saveplayerYは%d,pos[playerY][playerX][0]は%d,pos[playerY][playerX][1]は%d", saveplayerX, saveplayerY, pos[playerY][playerX][0], pos[playerY][playerX][1]);
		//DrawFormatString(0, 540, GetColor(255, 105, 0), " 主人公のYの位置playerYは%d,playerXは%d,★★nanameidouXは%d,migiidouは%d,nanameidouX2は%d, nanameidouX3%d, pos[playerY][playerX][0]は%d, pos[playerY][playerX][1]は%d", playerY,playerX, nanameidouX, migiidou, nanameidouX2, nanameidouX3, pos[playerY][playerX][0], pos[playerY][playerX][1]);

		//DrawFormatString(0, 350, GetColor(255, 145, 30),
		//	"★★stage[2][6][1]は%d,stage[0][0][1]は%d, stage[0][6][0]は%d,stage[0][6][1]は%d,stage[1][0][0]は%d,stage[1][0][1]は%d,InputYは%d,InputXは%d,MGtimeは%d,MGframeは%d,Gkeyは%d",
		//	stage[2][6][1], stage[0][0][1], stage[0][6][0], stage[0][6][1], stage[1][0][0], stage[1][0][1], InputY, InputX, MGtime, MGframe, Gkey);
		//DrawFormatString(1, 570, GetColor(255, 255, 0),
		//	"motonomasunimodoruは%d,playerattackhanndou2は%d,playerattackhanndou%d", motonomasunimodoru, playerattackhanndou2, playerattackhanndou, tuikaidouframe);
		//DrawFormatString(1, 250, GetColor(255, 255, 0), 
		//	"nanameidouYは%d,nanameidouY2は%d,nanameidouY3は%d,ENEMYkougekigazouA2frame2は%d,ranndamukougekiは%d,KABURImarkは%d", nanameidouY, nanameidouY2, nanameidouY3, ENEMYkougekigazouA2frame2, ranndamukougeki, KABURImark);
		DrawFormatString(1, 530, GetColor(255, 255, 0),
			"★playerkonntororulock★は%d,lockは%d,R1lockは%d", 
			playerkonntororulock,lock, R1lock);
		DrawFormatString(1, 570, GetColor(255, 255, 77),
			"playerkonntororulockは%d,playermovelockは%d、InputXは%d,playerkonntororulockは%d, fortimeframe2は%d",
			playerkonntororulock, playermovelock, InputX, playerkonntororulock, fortimeframe2);
		DrawFormatString(1, 600, GetColor(255, 25, 0),
			"★★kougekidekinailockは%d,marklockは%d,enemyzannzoulockframe1は%d,x2は%f,y2は%f,z2は%f",
			kougekidekinailock, marklock, enemyzannzoulockframe1, x2, y2, s2);
		DrawFormatString(1, 760, GetColor(255, 255, 0),
			"anotherenemysabunHPは%d,InputYは%d, kougekilockは%d, enemysabunHPBは%d,GenemysabunHPは%d, GenemysabunHPA は%d,GenemysabunHPABは%d",
			anotherenemysabunHP, InputY, kougekilock, enemysabunHPB, GenemysabunHP, GenemysabunHPA);

		
		//敵を殺した場合の画面に続く
		if (mark == 0 && enemyHP < 1) {

			ENEMYkougekigazouA2frame = 0;
			stayhere = 1;
			ENEMYmovelock2 = 0;
			enemyzannzoulock = 1;
			//stayherelock = 1;
			//enemystayhere = 1;
			BGMlock = 0;
			sinnzoubyouga = 0;//倒した後は血が出ないようにする。
			ranndamulock = 1;//範囲が重なるときだけ主人公と敵の位置が変わるようにした。を無効にするために1にする。
			//★player.hでのif (enemystayhere == 0)の時に描画される敵を消すためにenemystayhereの値を上に書いたように1にして、下で新しい敵を描画して徐々に消していくようにした。なのでif (enemystayhere == 0)とif(toumeika >0)ではif分の条件が違うので違う描画(関数)である。
			enemygazoukesu = 1;//if (playerHPlock == 0 && playerHP <= 200)での普段はenemygazoukesuは0での敵の描画を消すため倒すと1にするようにした。
			talkend = 0;
		}
		if (enemygazoukesu == 1) {
			++toumeika;
		}
		if (toumeika > 40) {//★toumeikaが0より大きくなっている間だけ敵を消したいので{}でまとめた。以前のif (mark == 0 && enemyHP < 1)では{}の中の描き方に関係なく、if (mark == 0 && enemyHP < 1)の条件に当てはまるものがすべて透明化してしまうので
			//if(toumeika >0)のように透明化したいもののみが透明化するように限定的にif(toumeika >0)の条件が働いている間だけ{}の働きがあるようにした。
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - 2 * toumeika);		//ブレンドモードをα(128/255)に設定

			DrawExtendGraph(pos[enemyY][enemyX][0] + 14 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] + playerattackhanndou3 - 66, pos[enemyY][enemyX][0] + 32 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] + playerattackhanndou3 + 99, enemydamegeHandle[0], TRUE);
		}

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをリセット（他の画像が薄くならないようにするため）	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - toumeika);		//ブレンドモードをα(128/255)に設定
		if (toumeika > 150) {
			Seen = 8;//Seenの値を8にする。初期値に戻すとタイトル画面に戻ってしまうため。
			talk = 3; enemyHP = 0; mark = 1;
			enemymovelock = 1;//これで敵は攻撃してこなくなる
			//StopSoundMem(sound3);//★戦闘BGMを止めるための関数//★止めるというよりはBGMを途中位置でとめて、再び途中位置から再生するための関数。
			toumeika = 0;
			enemygazoukesu = 0;
		}

		//コンティニュー画面
		//if (countinue == 1) {
			//countinuekannsuu();
		//}
		//if (enemyHP > 0 && enemyHP < 100) { Seen = 0; inotigoi();}//中断した敵のHPを基に戻して
		//if (enemyHP < 0) { enemyHP = 0; }

		//主人公が死んだ後の色の発生、ちなみに上のif (playerHP <0|| playerHP==0)の部分も主人公のHPに関してのプログラムにより関数が呼ばれる。
		if (playerHP <= 0 && Seen == 3 && syuzinnkoutoumeikalock == 0) {
			playerHP = 0;
			zannzoulock = 1;
			playerkonntororulock = 1;
			countimubotanlock = 0;
			// 再生を止めます
			StopSoundMem(sound3);
			playerHPlock = 1;
			//Seen = 100;//死んだ瞬間に説得しても分岐などの文字が描画されないように
			++playerHPframe;
			stayhere3 = 1;//敵の動きを止める。
			ENEMYkougekigazouA1frame = 0;//敵の動きを止めたまではいいが、コンティニューして戦闘に戻った瞬間に
			//値はそのままであるため主人公に攻撃したままの状態が続いてしまい即死してしまう。それを避けるために攻撃する際の変数そのものの値も0にする。
			ENEMYkougekigazouA2frame = 0;
			++syuzinnkoutoumeika;
			//enemybyougablock3 = 1;
			///DrawBox(0, 0, 1770, 1580, GetColor(gameovercolor, 0, 0), TRUE);// 画面全体を希望の色で塗りつぶす}//プレイヤーが死んだ場合の描画
			///if (gameovercolor > 160) { gameovercolor = 160; gameovercolorlock = 1; playerHP = 1; }
			///DrawFormatString(100, 300, GetColor(255, 255, 0), "gameovercolorは%d", gameovercolor);
			if (syuzinnkoutoumeika > 0 && ++syuzinnkoutoumeika < 100) {//★toumeikaが0より大きくなっている間だけ敵を消したいので{}でまとめた。以前のif (mark == 0 && enemyHP < 1)では{}の中の描き方に関係なく、if (mark == 0 && enemyHP < 1)の条件に当てはまるものがすべて透明化してしまうので
			//if(toumeika >0)のように透明化したいもののみが透明化するように限定的にif(toumeika >0)の条件が働いている間だけ{}の働きがあるようにした。
				//stayhere3 = 1;
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - 2 * syuzinnkoutoumeika);		//ブレンドモードをα(128/255)に設定

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerdamegeGHandle[0], TRUE);  // 俺キャラの描画
			}

			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをリセット（他の画像が薄くならないようにするため）	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - toumeika);		//ブレンドモードをα(128/255)に設定

			if (syuzinnkoutoumeika > 100) {
				//stayhere = 1;//★敵が攻撃した後にsyahereが0になるので、ここで再度1にする。
				syuzinnkoutoumeika = 0;
				gameovercolor = 1;
				syuzinnkoutoumeikalock = 1;
				//nanameidouX = nanameidouX - 1000;
			}

		}
		if (gameovercolor > 0 && ++gameovercolor < 255) {//★toumeikaが0より大きくなっている間だけ敵を消したいので{}でまとめた。以前のif (mark == 0 && enemyHP < 1)では{}の中の描き方に関係なく、if (mark == 0 && enemyHP < 1)の条件に当てはまるものがすべて透明化してしまうので
			//stayhere = 1;
			//playerkonntororulock = 1;		//if(toumeika >0)のように透明化したいもののみが透明化するように限定的にif(toumeika >0)の条件が働いている間だけ{}の働きがあるようにした。
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0 + 1 * gameovercolor);		//ブレンドモードをα(128/255)に設定

			DrawExtendGraph(0, 0, 1770, 980, anarogunoizuGraphHandle, TRUE);
		}

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);		//ブレンドモードをリセット（他の画像が薄くならないようにするため）	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - toumeika);		//ブレンドモードをα(128/255)に設定

		//主人公がゲームオーバーになった後のコンティニュー画面に続く
		if (gameovercolor >= 255) {
			//talkdrow2();//上のif (playerHP <0|| playerHP==0)の部分も主人公のHPに関してのプログラムにより関数が呼ばれる。
			gameovercolor = 255;

			Seen = 100;//死んだ瞬間に説得しても分岐などの文字が描画されないように
			if (Seen == 100) {
				countinuekannsuu();
			}
		}

		if (reSeen == 1) {
			talk = 0;
			talkbanngou = 1;//呼び出した時にtalkの2が入るように、ここにtalk = 2と書いた。
			void talkdrow();
			gameovercolor = 0;//Seen=2に戻れるが、描画されたものはそのままなのでここでgameovercolorの値を0にしする必要がある。
			//255のままではtest.cpp(メインプログラムに書いてある)のif (gameovercolor >= 255)の条件に引っ掛かったままで、このif文が呼び出す関数countinuekannsuu()の
			//DrawExtendGraph(0, 0, 1770, 980, anarogunoizuGraphHandle, TRUE);が働いてしまい、ずっと描画されてしまうので、gameovercolorの値を0にしする必要がある。
			playerHP = 100;
			imagecount = 0; enemyattack3 = 0; enemyimagecount = 0;//敵の攻撃をリセットしないと復活した際に途中攻撃が発生するのでここで書いておく。
			imagecount2 = 0; enemyattack4 = 0; enemyimagecount2 = 0;
			imagecount3 = 0; enemyattack5 = 0; enemyimagecount3 = 0;

		}
		//if (enemyHP2 < 1) { enemyHP2 = 0;}
		//if (Seen == 3) {
		//settokutalk();//ここに関数をいれる。
		//if (Key[KEY_INPUT_N] == 1) {
		//	Seen = 2;
		//}
	//}
	//if (Seen == 4) {
	//	DrawFormatString(100, 400, RED, "2回目の説得失敗"); if (Key[KEY_INPUT_N] == 1) {
	//		Seen = 2;
	//	}
	//}
	//if (Seen == 6) { bunnkiA(); }

	//敵の説得に成功した場合。
		if (analognoizu == 1 && Seen == 2) {
			StopSoundMem(sound3);//★BGMを途中で止めるための関数
			++fortimeframe2;
			if (fortimeframe2 > 0) {//★toumeikaが0より大きくなっている間だけ敵を消したいので{}でまとめた。以前のif (mark == 0 && enemyHP < 1)では{}の中の描き方に関係なく、if (mark == 0 && enemyHP < 1)の条件に当てはまるものがすべて透明化してしまうので
				//if(toumeika >0)のように透明化したいもののみが透明化するように限定的にif(toumeika >0)の条件が働いている間だけ{}の働きがあるようにした。
				//fortimeframe2 = fortimeframe2 / 5;
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, fortimeframe2 / 5);		//ブレンドモードをα(128/255)に設定

				DrawExtendGraph(0, 0, 1770, 980, settokugamenntyuunohaikeiHandle, TRUE);
			}

			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);		//ブレンドモードをリセット（他の画像が薄くならないようにするため）	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - toumeika);		//ブレンドモードをα(128/255)に設定

		}
		if (fortimeframe2 >= 1300) {
			mark = 2;
			fortimeframe2 = 0;
			Seen = 101;
			Seenlock2 = 1;

		}
		if (Seenlock2 == 1) {
			if (Pad[PAD_2] == 1) {
				++Seen;
			}
		}
		if (Seen == 101) {

			kaiwadrawString3(0, 100, 600, RED);//しぶといやつだ

		}
		if (Seen == 102) {
			kaiwadrawString3(1, 100, 600, RED);//
		}
		if (Seen == 103) {
			kaiwadrawString3(2, 100, 600, RED);//
		}
		if (Seen == 104) {
			kaiwadrawString3(3, 100, 600, RED);//
		}
		if (Seen == 105) {
			kaiwadrawString3(4, 100, 600, RED);//
			kodomo = 2;
		}
		//ここから子供の画像が出てくる。
		if (kodomo == 2) {
			PlayMovieToGraph(kodomogif);
			DrawExtendGraph(242, 0, 1127, 580, kodomogif, FALSE);
		}
		if (Seen == 106) {
			kaiwadrawString3(5, 100, 600, RED);//
		}
		if (Seen == 107) {
			kaiwadrawString3(6, 100, 600, RED);//
		}
		if (Seen == 108) {
			kaiwadrawString3(7, 100, 600, RED);//
		}
		if (Seen == 109) {
			kaiwadrawString3(8, 100, 600, RED);//
		}
		if (Seen == 110) {
			kaiwadrawString3(9, 100, 600, RED);//
		}
		if (Seen == 111) {
			kaiwadrawString3(10, 100, 600, RED);//
		}
		if (Seen == 112) {
			kaiwadrawString3(11, 100, 600, RED);//
		}
		if (Seen == 113) {
			kaiwadrawString3(12, 100, 600, RED);//
		}
		if (Seen == 114) {
			Seenlock2 = 0;
			kaiwadrawString3(13, 100, 600, RED);//Aボタンで子供を信じて殺さない
			kaiwadrawString3(14, 100, 700, RED);//Xボタンで子供を殺す
			//母親を信じた場合//A
			if (Pad[PAD_1] == 1) {
				Seen = 116;//そのまま虐待され子どもが大人になった場合に続く
				Seenlock2 = 1;
				kodomo = 0;
			}
			//母親を殺した場合//Seen11に続く//X
			if (Pad[PAD_3] == 1) {
				sound2 = LoadSoundMem("タイトルの銃声.mp3");
				PlaySoundMem(sound2, DX_PLAYTYPE_NORMAL);
				++Seenframe3;
				Seen = 115;

			}
		}
		if (Seenframe3 > 0 && ++Seenframe3 > 300) {
			Seenframe3 = 0;
			Seen = 11;
			Seenlock = 1;
		}
		//相手を殺した場合の画面
		if (mark == 1 && enemyHP <= 0) {
			++fortimeframe;
			stage1 = 0;
		}
		if (fortimeframe > 50) {
			DrawFormatString(100, 200, GetColor(255, 255, 255), "She is Dead.");
			talk = 0;
		}
		if (fortimeframe >= 300) {
			mark = 2;
			fortimeframe = 0;
			Seen = 9;
			Seenlock = 1;
		}
		if (Seenlock == 1) {
			if (Pad[PAD_2] == 1) {
				++Seen;
			}
		}
		if (Seen == 9) {
			kaiwadrawString(39, 100, 600, RED);//俺の妻を殺しやがったな！この人殺しめ！

		}
		if (Seen == 10) {
			kodomo = 1;
			kaiwadrawString(40, 100, 600, RED);//子供が外にやってくる。

		}
		//ここから子供の画像が出てくる。
		if (kodomo == 1) {
			PlayMovieToGraph(kodomogif);
			DrawExtendGraph(242, 0, 1127, 580, kodomogif, FALSE);
		}
		if (Seen == 11) {
			kaiwadrawString(41, 100, 600, RED);//俺の妻を殺しやがったな！この人殺しめ！
		}
		if (Seen == 12) {
			kaiwadrawString(42, 100, 600, RED);//俺の妻を殺しやがったな！この人殺しめ！

		}
		if (Seen == 13) {
			kaiwadrawString(43, 100, 600, RED);//俺の妻を殺しやがったな！この人殺しめ！

		}
		if (Seen == 14) {
			kaiwadrawString(44, 100, 600, RED);//俺の妻を殺しやがったな！この人殺しめ！

		}
		if (Seen == 15) {
			kaiwadrawString(45, 100, 600, RED);//俺の妻を殺しやがったな！この人殺しめ！

		}
		if (Seen == 16) {
			kaiwadrawString(46, 100, 600, RED);//俺の妻を殺しやがったな！この人殺しめ！

		}
		if (Seen == 17) {
			kaiwadrawString(47, 100, 600, RED);//俺の妻を殺しやがったな！この人殺しめ！

		}
		if (Seen == 18) {
			kaiwadrawString(48, 100, 600, RED);//俺の妻を殺しやがったな！この人殺しめ！

		}
		if (Seen == 19) {
			kaiwadrawString(49, 100, 600, RED);//俺の妻を殺しやがったな！この人殺しめ！

		}
		if (Seen == 20) {
			kaiwadrawString(50, 100, 600, RED);//俺の妻を殺しやがったな！この人殺しめ！

		}
		if (Seen == 21) {
			kaiwadrawString(51, 100, 600, RED);//俺の妻を殺しやがったな！この人殺しめ！

		}
		if (Seen == 22) {
			kaiwadrawString(52, 100, 600, RED);//将来殺人鬼になるってどういうこと？

		}
		if (Seen == 23) {
			kaiwadrawString(53, 100, 600, RED);//将来殺人鬼になるってどういうこと？

		}
		if (Seen == 24) {
			kaiwadrawString(54, 100, 600, RED);//将来殺人鬼になるってどういうこと？

		}
		if (Seen == 25) {
			kaiwadrawString(55, 100, 600, RED);//将来殺人鬼になるってどういうこと？

		}
		if (Seen == 26) {
			kaiwadrawString(56, 100, 600, RED);//いや、これでいいのか？

		}
		if (Seen == 27) {
			Seenlock = 0;
			kaiwadrawString(57, 100, 600, RED);//Aボタンで子供を信じて殺さない
			kaiwadrawString(58, 100, 700, RED);//Xボタンで子供を殺す
			//子供を信じた場合//A
			if (Pad[PAD_1] == 1) {
				++Seenframe;
				kodomo = 0;
				Seen = 28;
				Seenlock = 1;
				stage1 = 0;
			}
			//子供を殺した場合//
			if (Pad[PAD_3] == 1) {
				sound2 = LoadSoundMem("タイトルの銃声.mp3");
				PlaySoundMem(sound2, DX_PLAYTYPE_NORMAL);
				++Seenframe2;
				Seen = 50;
				kodomo = 0;
				++redbrad;
				Seenlock = 1;
				stage1 = 0;
			}
		}
		if (redbrad > 0) {
			++redbrad;
			redbrad2 = redbrad / 2;
			Red = GetColor(redbrad2, 0, 0);
			DrawBox(242, 0, 1127, 580, Red, TRUE);   // 四角形を描画(塗りつぶし))

		} //真っ赤のままでキープするための部分。
		if (redbrad2 >= 255) {
			redbrad = 0;
			redbrad2 = 255;
			Red = GetColor(redbrad2, 0, 0);
			DrawBox(242, 0, 1127, 580, Red, TRUE);   // 四角形を描画(塗りつぶし))
		}
		if (Seenframe > 0) {
			++Seenframe;
		}
		if (Seenframe2 > 0) {
			++Seenframe2;
		}
		if (Seenframe2 > 10 && Seenframe2 < 12) {
			kodomokorositasound = LoadSoundMem("スラヴ舞曲　作品７２の２  ドヴォルザーク.mp4");
			PlaySoundMem(kodomokorositasound, DX_PLAYTYPE_BACK);
		}
		//子供を殺さなかった場合の未来
		if (Seenframe > 300) {
			Seenframe = 300;
		}
		if (Seenframe == 300) {
			kaiwadrawString(59, 100, 600, RED);//数十年前から宛先不明の手紙が届いた。

		}
		if (Seen == 29) {
			Seenframe = 0;
			kaiwadrawString(60, 100, 600, RED);//数十年前から宛先不明の手紙が届いた。
		}
		if (Seen == 30) {
			kaiwadrawString(61, 100, 600, RED);//嬉しい。
		}
		if (Seen == 31) {
			kaiwadrawString(62, 100, 600, RED);//数十年前から宛先不明の手紙が届いた。
		}
		if (Seen == 32) {
			kaiwadrawString(63, 100, 600, RED);//数十年前から宛先不明の手紙が届いた。
		}
		if (Seen == 33) {
			Seen = 0;
		}
		//殺した場合の未来
		if (Seenframe2 > 300) {
			Seenframe2 = 300;
		}
		if (Seenframe2 == 300) {
			kaiwadrawString(64, 100, 600, RED);

		}
		if (Seen == 51) {
			Seenframe2 = 0;
			kaiwadrawString(65, 100, 600, RED);

		}
		if (Seen == 52) {
			Seenframe2 = 0;
			kaiwadrawString(66, 100, 600, RED);

		}
		if (Seen == 53) {
			Seenframe2 = 0;
			kaiwadrawString(67, 100, 600, RED);
		}
		if (Seen == 54) {
			StopSoundMem(kodomokorositasound);//★BGMを途中で止めるための関数
			Red = 0;//ここで念のために0にしておく。
			redbrad2 = 0;
			Seen = 0;
		}





		//母親を殺さ無かった後の未来
		if (Seen == 116) {
			kaiwadrawString3(15, 100, 600, RED);//いや、母親を信じよう。
		}
		if (Seen == 117) {
			kaiwadrawString3(16, 100, 600, RED);//いや、母親を信じよう。
		}
		if (Seen == 118) {
			kaiwadrawString3(17, 100, 600, RED);//いや、母親を信じよう。
		}
		if (Seen == 119) {
			kaiwadrawString3(18, 100, 600, RED);//いや、母親を信じよう。
		}
		if (Seen == 120) {
			kaiwadrawString3(19, 100, 600, RED);//いや、母親を信じよう。
			++Seenframe4;
			Seenlock2 = 0;
		}
		if (Seenframe4 > 0 && ++Seenframe4 > 500) {
			Seenframe4 = 0;
			Seenlock2 = 1;
			Seen = 121;
		}
		if (Seen == 121) {
			kaiwadrawString3(20, 100, 600, RED);//数年後
		}
		if (Seen == 122) {
			kaiwadrawString3(21, 100, 600, RED);//青い服の男
		}
		if (Seen == 123) {
			kaiwadrawString3(22, 100, 600, RED);//赤い服の男
		}
		if (Seen == 124) {
			kaiwadrawString3(23, 100, 600, RED);//赤い服の男
		}
		if (Seen == 125) {
			kaiwadrawString3(24, 100, 600, RED);//赤い服の男
		}
		if (Seen == 126) {
			kaiwadrawString3(25, 100, 600, RED);//赤い服の男残念だぁ
		}
		if (Seen == 127) {
			kaiwadrawString3(26, 100, 600, RED);//赤い服の男残念だぁ
		}
		if (Seen == 128) {
			kaiwadrawString3(27, 100, 600, RED);//赤い服の男残念だぁ
		}if (Seen == 129) {
			kaiwadrawString3(28, 100, 600, RED);//赤い服の男残念だぁ
		}if (Seen == 130) {
			kaiwadrawString3(29, 100, 600, RED);//赤い服の男残念だぁ
		}if (Seen == 131) {
			kaiwadrawString3(30, 100, 600, RED);//赤い服の男残念だぁ
		}if (Seen == 132) {
			kaiwadrawString3(31, 100, 600, RED);//赤い服の男残念だぁ
		}if (Seen == 133) {
			kaiwadrawString3(32, 100, 600, RED);//赤い服の男残念だぁ
		}if (Seen == 134) {
			kaiwadrawString3(33, 100, 600, RED);//赤い服の男残念だぁ
		}if (Seen == 135) {
			kaiwadrawString3(34, 100, 600, RED);//赤い服の男残念だぁ
		}if (Seen == 136) {
			kaiwadrawString3(35, 100, 600, RED);//赤い服の男残念だぁ
		}if (Seen == 137) {
			kaiwadrawString3(36, 100, 600, RED);//赤い服の男残念だぁ
		}if (Seen == 138) {
			kaiwadrawString3(37, 100, 600, RED);//赤い服の男残念だぁ
		}if (Seen == 139) {
			kaiwadrawString3(38, 100, 600, RED);//赤い服の男残念だぁ
		}if (Seen == 140) {
			kaiwadrawString3(39, 100, 600, RED);//赤い服の男残念だぁ
		}if (Seen == 141) {
			kaiwadrawString3(40, 100, 600, RED);//赤い服の男残念だぁ
		}if (Seen == 142) {
			kaiwadrawString3(41, 100, 600, RED);//赤い服の男残念だぁ
		}if (Seen == 143) {
			kaiwadrawString3(42, 100, 600, RED);//赤い服の男残念だぁ
		}if (Seen == 144) {
			kaiwadrawString3(43, 100, 600, RED);//止めるならお前も殺す！
		}
		if (Seen == 145) {
			kaiwadrawString3(44, 100, 600, RED);//止めるならお前も殺す！
		}if (Seen == 146) {
			kaiwadrawString3(45, 100, 600, RED);//止めるならお前も殺す！
		}if (Seen == 147) {
			kaiwadrawString3(46, 100, 600, RED);//止めるならお前も殺す！
		}if (Seen == 148) {
			kaiwadrawString3(47, 100, 600, RED);//止めるならお前も殺す！
		}if (Seen == 149) {
			kaiwadrawString3(48, 100, 600, RED);//止めるならお前も殺す！
		}if (Seen == 150) {
			kaiwadrawString3(49, 100, 600, RED);//止めるならお前も殺す！
		}if (Seen == 151) {
			kaiwadrawString3(50, 100, 600, RED);//二人の大男が襲ってきた。
			++stage2frame;
			Seenlock2 = 0;
		}

		if (stage2frame > 300) {
			stage2frame = 0;
			Seen = 300;
		}



		if (Seen == 300) {
			stage1 = 0;//後ろ蹴りでバグをステージ1に移動しないようにするための変数。
			//mark = 2;////クリア後の画面に続くif (mark == 0 && enemyHP < 1)に引っ掛からないようにここで2にした。
			//Seen = 300のif (stayhere == 1 && stayherelock == 1 && stayhere2 == 1 && stayherelock2 == 1)に戻る際に
			//いきなり敵が攻撃してこないようにとして、四つの変数を1にしている。
			stage2 = 1;
			stayhere = 1;
			stayhere2 = 1;
			stayherelock3 = 1;
			stayherelock2 = 1;
			enemybyougablock = 0;
			enemybyougablock2 = 0;
			ranndamulock = 0;
			ranndamulock2 = 0;//ここを0にして置いたらなぜかバトル開始の時の左上に赤い服の敵が描画されなくなった。
			enemyzannzoulock2 = 0;
			anotherenemyzannzoulock = 0;
			enemyhirumaseframe = 0;
			enemystayhere = 0;


			playerHP = 600;
			enemy1HP = 1500;
			enemy2HP = 1200;
			mark = 0;
			mark2 = 0;
			lockmark = 0;
			lockmark2 = 0;
			enemy1HPhyouji = 0;
			enemy2HPhyouji = 0;
			Seen = 301;
			serekutobotanncount2 = 0;
			enemyhanntoumei = 0;
			enemyhanntoumei2 = 0;
			enemyzannzoulockframe1 = 0;//攻撃し過ぎでこの変数の値が1のままで会話に進みコンティニューと同時に敵が点滅するので、ここで0にする。
			enemyzannzoulockBframe = 0;
			heartpoint = 0;//ハートポイントが一定以上になれば彼を救える選択肢が登場する。
			killer = 0;
			playerkonntororulock3 = 0;//ここで主人公を再び操作できるようにする。
			sousakanou = 0;
			migimuki = 1;
			stage2sound = LoadSoundMem("危機.mp3");//アルビノーニ：《弦楽とオルガンのためのアダージョ》 ト短調2.mp4
			stage2damage = 1;

		}GetJoypadXInputState(DX_INPUT_PAD1, &input);

		if (Seen == 301) {
			
			syuzinkoukougekigazou();
			//pos[enemyY1][enemyX1][0] = 596;
			//pos[enemyY1][enemyX1][1] = 404;
			//pos[enemyY2][enemyX2][0] = 596;
			//pos[enemyY2][enemyX2][1] = 404;
			stage2PlayerDraw();//この関数の中にPlayer_Update2()の中身を入れた。
			Player_Update2();
			//DrawFormatString(0, 540, GetColor(255, 105, 0), " 主人公のYの位置playerYは%d,playerXは%d,★★nanameidouXは%d,migiidouは%d,nanameidouX2は%d, nanameidouX3%d, pos[playerY][playerX][0]は%d, pos[playerY][playerX][1]は%d", playerY, playerX, nanameidouX, migiidou, nanameidouX2, nanameidouX3, pos[playerY][playerX][0], pos[playerY][playerX][1]);

			//DrawFormatString(0, 350, GetColor(255, 145, 30),
			//	"★★stage[2][6][1]は%d,stage[0][0][1]は%d, stage[1][6][1]は%d,stage[2][6][1]は%d,stage[1][0][0]は%d,stage[1][0][1]は%d,InputYは%d,InputXは%d,MGtimeは%d,MGframeは%d,Gkeyは%d",
			//	stage[2][6][1], stage[0][0][1], stage[1][6][1], stage[2][6][1], stage[1][0][0], stage[1][0][1], InputY, InputX, MGtime, MGframe, Gkey);
			//DrawFormatString(1, 800, GetColor(255, 255, 0),
			//	"AGenemysabunHPA は%d,enemyzannzoulockBframe%d,nextattackは%d", AGenemysabunHPA, enemyzannzoulockBframe,nextattack);
			DrawFormatString(1, 630, GetColor(255, 255, 0),
				"kougekikannkakulockは%d,playerkonntororulockは%d,kougekidekinailockは%d,attackframe は%d,KABURImarkは%d", 
				kougekikannkakulock, playerkonntororulock, kougekidekinailock, attackframe, KABURImark);
			//DrawFormatString(1, 630, GetColor(255, 255, 0),
			//	"pos[enemyY1][enemyX1][0]は%d,pos[enemyY1][enemyX1][1]は%d,pos[enemyY2][enemyX2][0]は%d,pos[enemyY2][enemyX2][0]は%d,playerMoveは%d,hinsikawanarilockは%d,tekinoKOUGEKITYUUhahyouzisinailockは%d,playermovelockは%d,kasanarulockAは%d", pos[playerY][playerX][0], pos[playerY][playerX][1], pos[enemyY2][enemyX2][0], pos[enemyY2][enemyX2][1], playerMove, hinsikawanarilock, tekinoKOUGEKITYUUhahyouzisinailock, playermovelock, kasanarulockA);
			DrawFormatString(1, 680, GetColor(255, 255, 77),
				"★LEFTmarkは%d,migimukiは%d,kougekidekinailockは%d",
				LEFTmark, migimuki, kougekidekinailock);

			DrawFormatString(1, 720, GetColor(255, 255, 0),
				"ENEMYkougekigazouA1frameは%d,ENEMYkougekigazouA2frameは%d,playerHPsubunは%d,attackframeは%d, kougekilocは%d", 
				ENEMYkougekigazouA1frame, ENEMYkougekigazouA2frame, playerHPsubun, attackframe, kougekilock);

			DrawFormatString(1, 740, GetColor(255, 25, 0),
				"★★enemyzannzoulockは%d,enemyzannzoulock2は%d,LEFTmarkは%d,LEFTmark2は%d", 
				enemyzannzoulock, enemyzannzoulock2, LEFTmark, LEFTmark2);
			// 右トリガーの情報を描画
			DrawFormatString(0, 0, GetColor(255, 255, 255), "zannzoulock %d", zannzoulock);



		}
		if (playerHP <= 0 && Seen == 301 && syuzinnkoutoumeikalock2 == 0) {
			playerHPhyouzi = 1;//
			playerHP = 0;
			playerkonntororulock3 = 1;//攻撃を食らった後ではplayerkonntororulockが1になった後0になり、死んだ後も少し動けてしまうので
									  //ここで新しい変数を使う。
			playerkonntororulock = 1;//死んだ後動けないように
			countimubotanlock = 0;
			// 再生を止めます
			StopSoundMem(stage2sound);
			//playerHPlock = 1;
			zannzoulock = 1;
			++playerHPframe;
			stayhere = 1;//敵の動きを止める。
			stayhere2 = 1;//敵の動きを止める。
			ENEMYkougekigazouA1frame = 0;//敵の動きを止めたまではいいが、コンティニューして戦闘に戻った瞬間に
			//値はそのままであるため主人公に攻撃したままの状態が続いてしまい即死してしまう。それを避けるために攻撃する際の変数そのものの値も0にする。
			ENEMYkougekigazouA2frame = 0;

			++syuzinnkoutoumeika;

			///DrawBox(0, 0, 1770, 1580, GetColor(gameovercolor, 0, 0), TRUE);// 画面全体を希望の色で塗りつぶす}//プレイヤーが死んだ場合の描画
			///if (gameovercolor > 160) { gameovercolor = 160; gameovercolorlock = 1; playerHP = 1; }
			///DrawFormatString(100, 300, GetColor(255, 255, 0), "gameovercolorは%d", gameovercolor);
			if (syuzinnkoutoumeika > 0 && syuzinnkoutoumeika < 100) {//★toumeikaが0より大きくなっている間だけ敵を消したいので{}でまとめた。以前のif (mark == 0 && enemyHP < 1)では{}の中の描き方に関係なく、if (mark == 0 && enemyHP < 1)の条件に当てはまるものがすべて透明化してしまうので
			//if(toumeika >0)のように透明化したいもののみが透明化するように限定的にif(toumeika >0)の条件が働いている間だけ{}の働きがあるようにした。
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - 2 * syuzinnkoutoumeika);		//ブレンドモードをα(128/255)に設定

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerdamegeGHandle[0], TRUE);  // 俺キャラの描画
			}

			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをリセット（他の画像が薄くならないようにするため）	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - toumeika);		//ブレンドモードをα(128/255)に設定

			if (syuzinnkoutoumeika > 100) {
				stayhere = 1;//★敵が攻撃した後にsyahereが0になるので、ここで再度1にする。
				stayhere2 = 1;
				syuzinnkoutoumeikalock2 = 1;
				syuzinnkoutoumeika = 0;
				gameovercolor2 = 1;
				//nanameidouX = nanameidouX - 1000;
			}

		}
		if (gameovercolor2 > 0 && ++gameovercolor2 < 255) {//★toumeikaが0より大きくなっている間だけ敵を消したいので{}でまとめた。以前のif (mark == 0 && enemyHP < 1)では{}の中の描き方に関係なく、if (mark == 0 && enemyHP < 1)の条件に当てはまるものがすべて透明化してしまうので
				//if(toumeika >0)のように透明化したいもののみが透明化するように限定的にif(toumeika >0)の条件が働いている間だけ{}の働きがあるようにした。
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 0 + 1 * gameovercolor2);		//ブレンドモードをα(128/255)に設定

			DrawExtendGraph(0, 0, 1770, 980, anarogunoizuGraphHandle, TRUE);
		}

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);		//ブレンドモードをリセット（他の画像が薄くならないようにするため）	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - toumeika);		//ブレンドモードをα(128/255)に設定

		//主人公がゲームオーバーになった後のコンティニュー画面に続く
		if (gameovercolor2 >= 255) {
			//Seen = 200;//死んだ瞬間に説得しても分岐などの文字が描画されないように
			//talkdrow2();//上のif (playerHP <0|| playerHP==0)の部分も主人公のHPに関してのプログラムにより関数が呼ばれる。
			gameovercolor2 = 255;
			Seen = 200;//死んだ瞬間に説得しても分岐などの文字が描画されないように
			if (Seen == 200) {
				countinuekannsuu2();
			}
		}

		//敵1を殺した場合。
		if (mark == 0 && enemy1HP < 1 && marklock == 0) {//★marklockは関係なく、mark=1がif文の中のさらにif (toumeika > 60)
			killer = 1;//★敵1を先に倒してしまった場合の変数。
			//に書いて合ったため、途中でmarkが1になってしまい、ここのif (toumeika > 60)を含むif文が作用しないのでkillerは0のままで
			//バグったためかenemybyougablockも0のままであった。
			enemybyougablock = 1;//if (stayhere == 1 && stayherelock == 1 && stayhere2 == 1 && stayherelock2 == 1)が反応しないようにするための変数。
			//stayhere = 1;
			stayherelock3 = 1;//下の★の場合も考えてここで敵のHPが描画されないように1にする。
			enemy1HPhyouji = 1;
			//enemystayhere = 1;//敵1を消すため
		//	stayherelock = 1;
			//enemy1HP = 0;
			//★★攻撃が当たるとなぜかまた処理するためか表れるので、座標自体を遠くにして描画されても築かないようにする。
			//多分、敵が透明化するときの斑点が原因だろう。
			//pos[enemyY1][enemyX1][0] = pos[enemyY1][enemyX1][0] + 3000;
			//ENEMYkougekigazouA1frame = 0;
			//ENEMYkougekigazouA2frame = 0;//ENEMYkougekigazouA2frameが0だったため、
			//ENEMYmovelock2 = 0;
			//enemyzannzoulock = 1;
			//この怯ませフレームを書くと敵が死んだあとは一切描画されない。
			//enemyhirumaseframe = 200;//念のため。//	怯んだ際に、自分も反動で下がるようにしたため、ここで1にするとif (enemyhirumaseframe > 0 && ++enemyhirumaseframe < 180)により
			//繰り上がりに入ってしまい反動が繰り返され下がってしまうので、こいつは書かない。
			//enemyhirumaseframe = 200に関して、enemyhirumaseframeは0ではなくなっていたため敵1は描画されずに綺麗に消えていたのだ。

			//enemystayhere = 1;//念のため。
			//enemystayhere = 1;
			//BGMlock = 0;
			sinnzoubyouga = 0;//倒した後は血が出ないようにする。
			ranndamulock = 1;//範囲が重なるときだけ主人公と敵の位置が変わるようにした。を無効にするために1にする。
			//★player.hでのif (enemystayhere == 0)の時に描画される敵を消すためにenemystayhereの値を上に書いたように1にして、下で新しい敵を描画して徐々に消していくようにした。なのでif (enemystayhere == 0)とif(toumeika >0)ではif分の条件が違うので違う描画(関数)である。
			enemygazoukesu1 = 1;//if (playerHPlock == 0 && playerHP <= 200)での普段はenemygazoukesuは0での敵の描画を消すため倒すと1にするようにした。
			enemy1HPhyouji = 0;
			ranndamulock = 1;
			ranndamukougeki = 0;
			stayhere = 1;

		}

		if (enemygazoukesu1 == 1) {
			++toumeika1;
		}
		if (toumeika1 > 40) {//★toumeikaが0より大きくなっている間だけ敵を消したいので{}でまとめた。以前のif (mark == 0 && enemyHP < 1)では{}の中の描き方に関係なく、if (mark == 0 && enemyHP < 1)の条件に当てはまるものがすべて透明化してしまうので
			//if(toumeika >0)のように透明化したいもののみが透明化するように限定的にif(toumeika >0)の条件が働いている間だけ{}の働きがあるようにした。
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - 2 * toumeika1);		//ブレンドモードをα(128/255)に設定

			DrawExtendGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] - 160, pos[enemyY1][enemyX1][0] + playerattackhanndou3 + 70 + playerattackhanndou + playerattackhanndou2, pos[enemyY1][enemyX1][1] + playerattackhanndou3 + 66, enemy2damegeHandle[0], TRUE);
		}

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをリセット（他の画像が薄くならないようにするため）	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - toumeika);		//ブレンドモードをα(128/255)に設定
		if (toumeika1 > 150) {
			mark = 1;
			toumeika1 = 0;
			enemygazoukesu1 = 0;
			marklock = 1;//★toumeikaが繰り上がらないようにするための変数。
			//★★攻撃が当たるとなぜかまた処理するためか表れるので、座標自体を遠くにして描画されても築かないようにする。
		//多分、敵が透明化するときの斑点が原因だろう。
			playerattackhanndou = 3000;
			pos[enemyY1][enemyX1][0] = pos[enemyY1][enemyX1][0] + playerattackhanndou;
			//★9マス上のいずれかのパネルに移動させる部分にplayerattackhanndou = 0を書いたり、enemyY1やenemyX1に数値がランダムに入るため
			//たまに3000くらい離れて消えることはあっても 9マス上のいずれかのパネルに移動させるによりすぐにマス目上に帰ってきたため
			//あまり気にならなかったが、主人公の攻撃が終わってL3を押すとplayerattackhanndouが0になるように変えた、かつ
			//pos[enemyY1][enemyX1][0] = pos[enemyY1][enemyX1][0] + 3000の時は敵がステージに少しの間消えていたりしたりフリーズする時があったりしたため、
			//playerattackhanndou = 3000として、3000が消えるようにした。まあ、pos[enemyY1][enemyX1][0] = pos[enemyY1][enemyX1][0] + 3000の時は
			//改良前のpos[enemyY1][enemyX1][0]自体にランダムに数値が入るため+3000でなく
			//ステージ上の座標にいることもあるのだろう。
			//killer = 1;//諦めて青い服の男を殺した場合。に続く。

		}



		//敵2を殺した場合。
		if (mark2 == 0 && enemy2HP < 1 && mark2lock == 0) {
			killer = 1;
			killerlock = 1;//★★敵両方を倒す場合のためにkiller=1に行かないようにするための変数。3や5の倍数での奴はif文で組んではいるが数字が15などの時「被る」ことがある
			//ためここでは採用できない。最初に敵1を倒す場合と、敵1を最後に倒す場合が被る(倍数で言う15みたいなものであるため)ことがあるためだ。
			//なので被らないようにkillerlockという新しい変数を作った。
			enemybyougablock2 = 1;

			enemy2HP = 0;
			//stayherelock2 = 1;//下の★の場合も考えてここで敵2が描画されないように1にする。

			//ENEMYmovelock2 = 0;
			anotherenemyzannzoulock = 1;
			//enemy2hirumaseframe = 200;//★ここが200とか書いてしまっていたせいで、描画するヘッダ2の2122に引っ掛かり敵が死んだ後も移動したり
			//描画されたり、死ぬ瞬間に描画されたりしていた。
			ENEMYkougekigazouB1frame = 0;//念のためにここを付け足しても良い。
			ENEMYkougekigazouB2frame = 0;//フレームが37フレームの時にカウンターが入ると敵の攻撃が一瞬だけ描画されてしまうので、ここで0にする。

			//enemystayhere = 1;
			//BGMlock = 0;
			sinnzoubyouga = 0;//倒した後は血が出ないようにする。
			ranndamulock2 = 1;//範囲が重なるときだけ主人公と敵の位置が変わるようにした。を無効にするために1にする。
			//★player.hでのif (enemystayhere == 0)の時に描画される敵を消すためにenemystayhereの値を上に書いたように1にして、下で新しい敵を描画して徐々に消していくようにした。なのでif (enemystayhere == 0)とif(toumeika >0)ではif分の条件が違うので違う描画(関数)である。
			enemygazoukesu2 = 1;//if (playerHPlock == 0 && playerHP <= 200)での普段はenemygazoukesuは0での敵の描画を消すため倒すと1にするようにした。
			enemy2HPhyouji = 1;
			ranndamulock2 = 1;
			ranndamukougeki2 = 0;
			stayhere2 = 1;
			stage2damage = 0;
		}
		if (enemygazoukesu2 == 1) {
			++toumeika2;
		}
		if (toumeika2 > 40) {//★toumeikaが0より大きくなっている間だけ敵を消したいので{}でまとめた。以前のif (mark == 0 && enemyHP < 1)では{}の中の描き方に関係なく、if (mark == 0 && enemyHP < 1)の条件に当てはまるものがすべて透明化してしまうので
			//if(toumeika >0)のように透明化したいもののみが透明化するように限定的にif(toumeika >0)の条件が働いている間だけ{}の働きがあるようにした。
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - 2 * toumeika2);		//ブレンドモードをα(128/255)に設定

			DrawExtendGraph(pos[enemyY2][enemyX2][0] - 9 + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 140, pos[enemyY2][enemyX2][0] + 84 + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B, pos[enemyY2][enemyX2][1] + playerattackhanndou3B + 45, enemy3damegeHandle[0], TRUE);
		}

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをリセット（他の画像が薄くならないようにするため）	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - toumeika);		//ブレンドモードをα(128/255)に設定
		if (toumeika2 > 150) {
			mark2 = 1;//★if文の条件に合うようにここは消した。エネミー2が消えまたままであるように。

			toumeika2 = 0;
			enemygazoukesu2 = 0;
			mark2lock = 1;

			//★★攻撃が当たるとなぜかまた処理するためか表れるので、座標自体を遠くにして描画されても築かないようにする。
			//多分、敵が透明化するときの斑点が原因だろう。
			playerattackhanndouB = 3000;
			pos[enemyY2][enemyX2][0] = pos[enemyY2][enemyX2][0] + playerattackhanndouB;

		}


		//二人殺した場合で初めてBGMが止まる。//選択肢により、殺す選択肢もあるが、あえて二人とも殺す場合をこことする。
		if (mark == 1 && enemy1HP < 1 && mark2 == 1 && enemy2HP < 1 && killer == 1) {
			//★赤い敵を先に倒して、killerを2にして、その後で青い敵も倒した場合はここに進む。
			//enemybyougablock = 1;//初期状態の敵の二人が描画されないように。
			sousakanou = 1;//両方殺してから主人公の動きが止まる。
			BGMlock = 0;
			// 再生を止めます
			StopSoundMem(stage2sound);
			Seen = 302;
			stage2 = 0;
			stage2damage = 0;
		}

		//後ろから蹴り上げる時の部分。//主人公の攻撃画像の方にこれを書きたい場合syuzinkoukougekigazou()を書けばいいが、
		//stage2Player_Draw.hにもsyuzinkoukougekigazou()を書いてしまっているため、高速で処理が終わり相手にダメージを与えられない
		//なのでsyuzinkoukougekigazou()とは関係なく、attackframe7の値が来たらwhileで描画できるここに書いた。
		//ただ、stage2Player_Draw.hにこれを書いても、stage2Player_Draw.hはSeenが301として固定されたプログラムなので
		//Seenが1000に変ってしまうと固定でのバグが起きて一瞬Seen == 1000になりattackframe7が23とかになる。
		//そのためSeenが固定されていないここに書いたのだ。
		//★stage2PlayerDraw()はSeenが301での関数なので、その関数の中で1000になられるのは固定してしまったゆえに困るため、
		//stage2PlayerDraw()の関数の中身でSeenを1000に変えて、ここに来るようにしたため書いた通りに動くのではないかと考えている。
		//syuzinkoukougekigazou()はstage2PlayerDraw()の中にあるけどstage2PlayerDraw()みたいに固定されてないから上に
		//書いた感じでも大丈夫だったとか？//どうやらsyuzinkoukougekigazou()をSeen301に入れてみて実験したが仮説は正しいようだ。
		//後ろから蹴り上げる時の部分。//
		if (Seen == 1000 && stage2 == 1) {
			if (hidarimuki == 1) {
				++attackframe7;
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] - 25 + playerattackhanndou3, bairituY, 0, kikkuhanntenn[0], TRUE);
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] - 25 + playerattackhanndou3, bairituY, 0, enemyImage2, TRUE);
				if (attackframe7 > 48 && attackframe7 < 50) {
					playerattackhanndou = playerattackhanndou - 100;
					motonomasunimodoru = motonomasunimodoru + 60;
					enemysabunHP = 50;
					zannzoulock = 0;
					keriwaza = 0;
					attackframe5 = 0;
					attackframe6 = 0;
					enemyzannzoulockframe = 1;//相手のダメージを食らった際の怯みを初期に戻すため
					stayhere2frame = 1;
					//Seen = 301;
					bloodMove = 1;
				}
				//蹴った後のSeenの値を変えるためにここに書いている。
				if (Seen == 1000 && stage2 == 1) {
					if (attackframe7 > 50) {
						zannzoulock = 0;
						Seen = 301;
						nextattack = 0;

					}
				}
			}
		}


		if (Seen == 1001 && stage2 == 1) {
			if (hidarimuki == 1) {
				++attackframe7;
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B, pos[enemyY2][enemyX2][1] - 25 + playerattackhanndou3B, bairituY2, 0, kikkuhanntenn[0], TRUE);
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B, pos[enemyY2][enemyX2][1] - 25 + playerattackhanndou3B, bairituY2, 0, enemyImage3, TRUE);
				if (attackframe7 > 48 && attackframe7 < 50) {
					playerattackhanndouB = playerattackhanndouB - 100;
					motonomasunimodoru = motonomasunimodoru + 60;
					anotherenemysabunHP = 50;
					zannzoulock = 0;
					keriwaza = 0;
					attackframe5 = 0;
					attackframe6 = 0;
					enemyzannzoulockBframe = 1;//相手のダメージを食らった際の怯みを初期に戻すため
					stayhere2frame = 1;
					//Seen = 301;
					bloodMove = 1;
				}
				//蹴った後のSeenの値を変えるためにここに書いている。
				if (Seen == 1001 && stage2 == 1) {
					if (attackframe7 > 50) {
						zannzoulock = 0;
						Seen = 301;
						nextattack = 0;
						
					}
				}
			}
		}


		if (Seen == 1000 && stage2 == 1) {
			if (migimuki == 1) {
				++attackframe7;
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] - 25 + playerattackhanndou3, bairituY, 0, playerKONNBO1BHandle[0], TRUE);
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] - 25 + playerattackhanndou3, bairituY, 0, enemyImage2, TRUE);
				if (attackframe7 > 48 && attackframe7 < 50) {
					playerattackhanndou = playerattackhanndou + 100;
					motonomasunimodoru = motonomasunimodoru + 60;
					enemysabunHP = 50;
					zannzoulock = 0;
					keriwaza = 0;
					attackframe5 = 0;
					attackframe6 = 0;
					enemyzannzoulockframe1 = 1;//相手のダメージを食らった際の怯みを初期に戻すため
					stayhereframe = 1;
					kakuninn = 79;
					//	Seen = 301;
				}
				//蹴った後のSeenの値を変えるためにここに書いている。
				if (Seen == 1000 && stage2 == 1) {
					if (attackframe7 > 50) {
						zannzoulock = 0;
						Seen = 301;
						nextattack = 0;
						//migimuki = 0;
						//hidarimuki = 1;
					}
				}
			}
		}
		//後ろから蹴り上げる時の部分。
		if (Seen == 1001 && stage2 == 1) {
			if (migimuki == 1) {
				++attackframe7;
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B, pos[enemyY2][enemyX2][1] - 25 + playerattackhanndou3B, bairituY2, 0, playerKONNBO1BHandle[0], TRUE);
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B, pos[enemyY2][enemyX2][1] - 25 + playerattackhanndou3B, bairituY2, 0, enemyImage3, TRUE);
				if (attackframe7 > 48 && attackframe7 < 50) {
					playerattackhanndouB = playerattackhanndouB + 100;
					motonomasunimodoru = motonomasunimodoru + 60;
					anotherenemysabunHP = 50;
					zannzoulock = 0;
					keriwaza = 0;
					attackframe5 = 0;
					attackframe6 = 0;
					enemyzannzoulockBframe = 1;//相手のダメージを食らった際の怯みを初期に戻すため
					stayhere2frame = 1;
					//Seen = 301;
				}
				//蹴った後のSeenの値を変えるためにここに書いている。
				if (Seen == 1001 && stage2 == 1) {
					if (attackframe7 > 50) {
						zannzoulock = 0;
						Seen = 301;
						nextattack = 0;
					}
				}
			}
		}

		//else {
		//	if (Seen == 1002) {
		//		++attackframe7;
		//	}
		//}



		//諦めて青い服の男を殺した場合。
		if (killerlock == 0) {
			if (killer == 1) {
				stage2 = 0;
				StopSoundMem(stage2sound);
				++killerframe;
				mark = 1;//★killerが1になり、再びkillerframeが上がらないように
				stage2damage = 0;
			}
		}
		if (killerframe > 400) {
			killer = 0;
			killerframe = 0;
			Seen = 800;
		}
		if (Seen == 800) {
			kaiwadrawString3(51, 100, 600, RED);//お前！お前よくも俺の相棒を殺したな
			Seenlock2 = 1;
		}
		if (Seen == 801) {
			kaiwadrawString3(52, 100, 600, RED);//お前！お前よくも俺の相棒を殺したな
		}
		if (Seen == 802) {
			kaiwadrawString3(53, 100, 600, RED);//お前！お前よくも俺の相棒を殺したな
		}if (Seen == 803) {
			kaiwadrawString3(54, 100, 600, RED);//お前！お前よくも俺の相棒を殺したな
		}if (Seen == 804) {
			kaiwadrawString3(55, 100, 600, RED);//お前！お前よくも俺の相棒を殺したな
		}if (Seen == 805) {
			kaiwadrawString3(56, 100, 600, RED);//お前！お前よくも俺の相棒を殺したな
		}if (Seen == 806) {
			kaiwadrawString3(57, 100, 600, RED);//お前！お前よくも俺の相棒を殺したな
		}if (Seen == 807) {
			kaiwadrawString3(58, 100, 600, RED);//お前！お前よくも俺の相棒を殺したな
		}if (Seen == 808) {
			kaiwadrawString3(59, 100, 600, RED);//お前！お前よくも俺の相棒を殺したな
		}if (Seen == 809) {
			kaiwadrawString3(60, 100, 600, RED);//コンティニューか、続けるか？
			kaiwadrawString3(61, 100, 650, RED);//Aでコンティニュー
			kaiwadrawString3(62, 100, 700, RED);//Xでやめる
			Seenlock2 = 0;
			//コンティニューする。//A
			if (Pad[PAD_1] == 1) {
				Seen = 300;
				enemyhanntoumei = 0;
				enemyhanntoumei2 = 0;
				killerlock = 0;
			}
			//メニュー画面に戻る//X
			if (Pad[PAD_3] == 1) {
				Seen = 0;
			}
		}




		//敵との戦闘は終わるが、撃たれる。
		if (analognoizu == 2 && Seen == 301 && settokubunnki == 1) {
			stage2 = 0;
			++fortimeframe3;
			stage2damage = 0;
			if (fortimeframe3 > 0) {//★toumeikaが0より大きくなっている間だけ敵を消したいので{}でまとめた。以前のif (mark == 0 && enemyHP < 1)では{}の中の描き方に関係なく、if (mark == 0 && enemyHP < 1)の条件に当てはまるものがすべて透明化してしまうので
				//if(toumeika >0)のように透明化したいもののみが透明化するように限定的にif(toumeika >0)の条件が働いている間だけ{}の働きがあるようにした。
				//fortimeframe2 = fortimeframe2 / 5;
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, fortimeframe3 / 3);		//ブレンドモードをα(128/255)に設定

				DrawExtendGraph(0, 0, 1770, 980, settokugamenntyuunohaikeiHandle, TRUE);
			}

			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);		//ブレンドモードをリセット（他の画像が薄くならないようにするため）	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - toumeika);		//ブレンドモードをα(128/255)に設定

		}
		if (fortimeframe3 > 1300) {
			fortimeframe3 = 0;
			Seenlock2 = 1;
			analognoizu = 0;
			Seen = 2000;
			StopSoundMem(stage2sound);
		}
		if (Seen == 2000) {
			drawString(67, 100, 600, RED);
		}if (Seen == 2001) {
			drawString(68, 100, 600, RED);
		}if (Seen == 2002) {
			drawString(69, 100, 600, RED);
		}if (Seen == 2003) {
			drawString(70, 100, 600, RED);
		}if (Seen == 2004) {
			drawString(71, 100, 600, RED);
		}if (Seen == 2005) {
			drawString(72, 100, 600, RED);
		}
		if (Seen == 2006) {
			kaiwadrawString3(60, 100, 600, RED);//コンティニューか、続けるか？
			kaiwadrawString3(61, 100, 650, RED);//Aでコンティニュー
			kaiwadrawString3(62, 100, 700, RED);//Xでやめる
			Seenlock2 = 0;
			//コンティニューする。//A
			if (Pad[PAD_1] == 1) {
				killerlock = 0;
				enemyhanntoumei = 0;
				enemyhanntoumei2 = 0;
				Seen = 300;
			}
			//メニュー画面に戻る//X
			if (Pad[PAD_3] == 1) {
				Seen = 0;
			}
		}


		//敵1の説得に成功した場合。//最終回
		if (analognoizu == 2 && Seen == 301 && settokubunnki == 2) {
			++fortimeframe4;
			stage2damage = 0;
			if (fortimeframe4 > 0) {//★toumeikaが0より大きくなっている間だけ敵を消したいので{}でまとめた。以前のif (mark == 0 && enemyHP < 1)では{}の中の描き方に関係なく、if (mark == 0 && enemyHP < 1)の条件に当てはまるものがすべて透明化してしまうので
				//if(toumeika >0)のように透明化したいもののみが透明化するように限定的にif(toumeika >0)の条件が働いている間だけ{}の働きがあるようにした。
				//fortimeframe2 = fortimeframe2 / 5;
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, fortimeframe4 / 3);		//ブレンドモードをα(128/255)に設定

				DrawExtendGraph(0, 0, 1770, 980, settokugamenntyuunohaikeiHandle, TRUE);
			}

			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);		//ブレンドモードをリセット（他の画像が薄くならないようにするため）	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - toumeika);		//ブレンドモードをα(128/255)に設定

		}
		if (fortimeframe4 >= 1300) {
			//mark = 2;
			fortimeframe4 = 0;
			Seen = 3000;
			Seenlock2 = 1;
			StopSoundMem(stage2sound);
		}

		if (Seen == 3000) {
			drawString(73, 100, 600, RED);
		}if (Seen == 3001) {
			drawString(74, 100, 600, RED);
		}if (Seen == 3002) {
			drawString(75, 100, 600, RED);
		}if (Seen == 3003) {
			drawString(76, 100, 600, RED);
		}if (Seen == 3004) {
			drawString(77, 100, 600, RED);
		}if (Seen == 3005) {
			drawString(78, 100, 600, RED);
		}if (Seen == 3006) {
			drawString(79, 100, 600, RED);
		}if (Seen == 3007) {
			drawString(80, 100, 600, RED);
		}if (Seen == 3008) {
			drawString(81, 100, 600, RED);
		}if (Seen == 3009) {
			drawString(82, 100, 600, RED);
		}if (Seen == 3010) {
			drawString(83, 100, 600, RED);
		}if (Seen == 3011) {
			drawString(84, 100, 600, RED);
		}if (Seen == 3012) {
			drawString(85, 100, 600, RED);
		}if (Seen == 3013) {
			drawString(86, 100, 600, RED);
		}if (Seen == 3014) {
			drawString(87, 100, 600, RED);
		}if (Seen == 3015) {
			drawString(88, 100, 600, RED);
		}if (Seen == 3016) {
			drawString(89, 100, 600, RED);
		}if (Seen == 3017) {
			drawString(90, 100, 600, RED);
		}if (Seen == 3018) {
			drawString(91, 100, 600, RED);//タバコを吸ってリラックスしていると...。
			dennwanaru = 1;
			stage2 = 0;
		}
		if (dennwanaru > 0) {
			++dennwanaruframe;
		}
		if (dennwanaruframe >= 500) {
			if (BGMlock == 0) { ++BGM1; Seenlock2 = 0; Seen = 3019; dennwanaru = 0; dennwanaruframe = 500; }
			//★talkが0の時でBGMを再生させようとしていた時はtalkが0の時にBGMを一回ではなく、仕様的に何度も再生していたため、最初に再生されていたBGMはキーで止まったが
			//それ以外のBGMは止まらなかったので、キー入力をしてもまるで止まっていないように見えた。
			//解決法はBGMが一回しか流れないように値が変動するか、瞬間的にボタンを押した瞬間だけ1になるような値の時にBGMを再生させるしかないので
			//常に増える変数BGM1の値が10の時にBGMを再生しることで一回しか再生されないので、その一回再生されたBGMを後は止めればいいだけとなった。
			if (BGM1 == 10 && reBGM1 == 0) {
				sound4 = LoadSoundMem("Rotary_Phone-Ringtone01-1.mp3");
				ChangeVolumeSoundMem(180, sound4);//この関数によって音声のボリュームを設定できる。
				PlaySoundMem(sound4, DX_PLAYTYPE_BACK);
				dennwalock = 1;
			}
			if (BGM1 > 0) {
				++mozibyougaframe;
			}
			//if (botanlock == 0) {
			//	if (Pad[PAD_2] == 1) {
			//		++talk;
			//	}
			//}
			//if(mozibyougaframe > 0 &&mozibyougaframe<270)の間はボタンが押せないようにbotanlockの値を0にしておく。
			if (talk == 0 && mozibyougaframe > 270) {
				BGM1 = 11;//繰り上がったりしても電話の音が鳴らないように11にした。//まあ値が増え続けても問題はないが念のために11にしておく。

				//DrawString(200, 400, "Bボタンで電話に出る", RED);
				//DrawString(200, 500, "Aボタンで電話に出ない", RED);
			}
			//電話に出ない場合。再び電話が数フレーム後に掛かってくる。
			if (botanlock2 == 0) {
				if (Pad[PAD_1] == 1) {
					StopSoundMem(sound4);//★BGMを途中で止めるための関数
					reBGM1 = 1;//再びBGM1を流すまでの期間のフレームを決めるための変数。
					mozibyougaframe = 0;//電話に出るかでないかの文字描画を消すために。
					botanlock = 1;//選択肢によってボタンが押せないようにするために。
					talkhaikei2 = 2;//一旦他の背景に移る。
				}
			}
			//再び電話がかかってくるまでの無音の期間。
			//この期間が長いとBGM1が10を超えてからreBGMが0になり書いた通りに動いてくれない。
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
				talkhaikei2 = 0;//背景が戻る。

			}
			//reBGM1の最初の書き方でもいいが、文字を描画に少し時間がかかったので、改良すればうまくいくと思ったがあまり変わらなかった。
			if (reBGM1 == 190) {
				posmozi2[0] = posmozi2[1] = posmozi2[2] = 0;//0,1,2の3つの文章が再び描画される。
			}
			if (botanlockframe > 0) {
				botanlock = 0;//再びBGMを流すまで無音でボタンも押せなくしていたので、再び流すまでの変数が200に成ったらボタンを押せるようにする。
				botanlock2 = 0;//再びBGMを流すまで無音でボタンも押せなくしていたので、再び流すまでの変数が200に成ったらボタンを押せるようにする。
				botanlockframe = 0;
				//talkhaikei = 1;
			}

			if (talkhaikei2 == 0 && dennwalock == 1) {
				// 描画する文字列のサイズを設定
				//SetFontSize(28);
				kaiwadrawString(0, 100, 500, Cr);//電話がかかってきた
				kaiwadrawString(1, 100, 600, RED);//電話に出る
				kaiwadrawString(2, 100, 700, RED);//電話に出ない
				//PlayMovieToGraph(dennwaHandle);
				//DrawExtendGraph(0, 0, 870, 780, dennwaHandle, FALSE);
				//電話に出る
				if (Pad[PAD_2] == 1) {
					talkhaikei2 = 1;
					//kaiwasound1 = LoadSoundMem("チャイコフスキー『10月・秋の歌』（楽譜付き）.mp4");
					//ChangeVolumeSoundMem(120, kaiwasound1);//この関数によって音声のボリュームを設定できる。
					//PlaySoundMem(kaiwasound1, DX_PLAYTYPE_BACK);
					StopSoundMem(sound4);//★BGMを途中で止めるための関数
				}
				//電話に出ない
				if (Pad[PAD_1] == 1) {
					talkhaikei2 = 0;
				}
			}
		}
		if (talkhaikei2 == 1) {
			talkhaikei2 = 0;
			BGM1 = 0;
			dennwalock = 0;
			//botanlock = 0;//再びBGMを流すまで無音でボタンも押せなくしていたので、再び流すまでの変数が200に成ったらボタンを押せるようにする。
			//botanlock2 = 0;//再びBGMを流すまで無音でボタンも押せなくしていたので、再び流すまでの変数が200に成ったらボタンを押せるようにする。
			//botanlockframe = 0;
			dennwanaruframe = 0;
			BGMlock = 0;
			reBGM1 = 0;//再びBGM1を流すまでの期間のフレームを決めるための変数。
			mozibyougaframe = 0;//電話に出るかでないかの文字描画を消すために。
			Seen = 0;//電話を取るとタイトルに戻る。
		}







		//二人とも殺した場合。
		if (Seen == 302) {
			lockmark = 1;
			lockmark2 = 1;
			mark = 0;//上のif (mark == 1 && enemy1HP < 1 && mark2 == 1 && enemy2HP < 1)に当てはまらないように0にする。
			mark2 = 0;//上に同じく。
			enemy1HP = 0;
			enemy2HP = 0;
			++daburukiller;
		}
		if (daburukiller > 300) {
			daburukiller = 300;
			Seenlock2 = 1;
			Seen = 303;
		}
		if (Seen == 303) {

			drawString(54, 100, 600, RED);
		}
		if (Seen == 304) {
			drawString(55, 100, 600, RED);
		}
		if (Seen == 305) {
			drawString(56, 100, 600, RED);
		}
		if (Seen == 306) {
			drawString(57, 100, 600, RED);
		}if (Seen == 307) {
			drawString(58, 100, 600, RED);
		}if (Seen == 308) {
			drawString(59, 100, 600, RED);
		}if (Seen == 309) {
			drawString(60, 100, 600, RED);
		}if (Seen == 310) {
			drawString(61, 100, 600, RED);
		}if (Seen == 311) {
			drawString(62, 100, 600, RED);
		}if (Seen == 312) {
			drawString(63, 100, 600, RED);
		}if (Seen == 313) {
			drawString(64, 100, 600, RED);
		}if (Seen == 314) {
			drawString(65, 100, 600, RED);
		}
		if (Seen == 315) {
			drawString(66, 100, 600, RED);
		}
		if (Seen == 316) {
			kaiwadrawString3(60, 100, 600, RED);//コンティニューか、続けるか？
			kaiwadrawString3(61, 100, 650, RED);//Aでコンティニュー
			kaiwadrawString3(62, 100, 700, RED);//Xでやめる
			Seenlock2 = 0;
			//コンティニューする。//A
			if (Pad[PAD_1] == 1) {
				killerlock = 0;
				enemyhanntoumei = 0;
				enemyhanntoumei2 = 0;
				Seen = 300;
			}
			//メニュー画面に戻る//X
			if (Pad[PAD_3] == 1) {
				Seen = 0;
			}
		}


		//ステージ1でのポーズ画面。
		if (Pad[PAD_8] == 1 && Seen == 2) {
			Seen = 500;

		}
		if (Seen == 500) {
			DrawFormatString(20, 120, GetColor(255, 255, 0), "★Rightward or LEFTward  + R1 + Analog pad + B = punch");
			DrawFormatString(20, 140, GetColor(255, 255, 0), "★R1 + Analog pad + B + B = Continuous punch");
			DrawFormatString(20, 160, GetColor(255, 255, 0), "★Rightward + R1 + Analog pad + Y + → LEFTward + R1 + Analog pad + Y + ← or = kick");
			DrawFormatString(20, 180, GetColor(255, 255, 0), "★Rightward + R1 + Analog pad + A + ← + → or LEFTward + R1 + Analog pad + A + → + ← = sword");
			DrawFormatString(20, 200, GetColor(255, 255, 0), "★Rightward or LEFTward + R1 + Analog pad + (at the same time R1 + B) + R1 + Analog pad + (at the same time R1 + B) = Kick from behind");
			DrawFormatString(20, 220, GetColor(255, 255, 0), "★Rightward or LEFTward + X = Handgun");
			DrawFormatString(20, 240, GetColor(255, 255, 0), "★A = Recover with cigarettes");
			DrawFormatString(20, 260, GetColor(255, 255, 0), "★If you want to quickly return to the original position after sliding with R1 and the analog pad,");
			DrawFormatString(20, 280, GetColor(255, 255, 0), "you can return to the original position by pressing the analog pad on the left.");
			DrawFormatString(20, 300, GetColor(255, 255, 0), "★Cause a certain amount of damage to the enemy and display the persuasive menu with the SHARE button.");
			DrawFormatString(20, 320, GetColor(255, 255, 0), "★Persuade them well and save heartpoints to lead a better future.");
			DrawFormatString(20, 340, GetColor(255, 255, 0), "★You can avoid the attack by pressing R2 and pressing the right or left of the analog pad.※However, it cannot be avoided at the right or left edge.So");
			DrawFormatString(20, 360, GetColor(255, 255, 0), "In such a case, you can avoid the enemy's attack by sliding movement with R1 and analog pad..");
			DrawFormatString(20, 380, GetColor(255, 255, 0), "★press the A button at the right time when the opponent attacks, you can dodge the attack.");

			DrawFormatString(20, 400, GetColor(255, 255, 0), "★You can scare the enemy by pressing A at the right time when the enemy attacks.");


			//DrawFormatString(1, 720, GetColor(255, 255, 0),
			//	"markは%d,mark2は%d,ranndamukougeki2は%d,ranndamulock2は%d,settokubunnkiframe2は%d,nanameidouY5は%d,nanameidouY3は%d", mark, mark2, ranndamukougeki2, ranndamulock2, settokubunnkiframe2, nanameidouY5, nanameidouY3);

			++menyframe;
		}
		if (Seen == 500 && menyframe > 100) {
			if (Pad[PAD_8] == 1) {
				menyframe = 0;
				Seen = 2;
			}
		}


		//ステージ2でのポーズ画面。
		if (Pad[PAD_8] == 1 && Seen == 301) {
			Seen = 400;
			mark = 1;//念のため。
			mark2 = 1;
		}
		if (Seen == 400) {
			DrawFormatString(20, 120, GetColor(255, 255, 0), "★R1 + Analog pad + B = punch");
			DrawFormatString(20, 140, GetColor(255, 255, 0), "★R1 + Analog pad + B + B = Continuous punch");
			DrawFormatString(20, 160, GetColor(255, 255, 0), "★R1 + Analog pad + Y + → = kick");
			DrawFormatString(20, 180, GetColor(255, 255, 0), "★R1 + Analog pad + A + ← + → = sword");
			DrawFormatString(20, 200, GetColor(255, 255, 0), "★R1 + Analog pad + (at the same time R1 + B) = Kick from behind");
			DrawFormatString(20, 220, GetColor(255, 255, 0), "★In a stopped state and R2 + Analog pad + X or X = Handgun");
			DrawFormatString(20, 240, GetColor(255, 255, 0), "★A = Recover with cigarettes");
			DrawFormatString(20, 260, GetColor(255, 255, 0), "★If you want to quickly return to the original position after sliding with R1 and the analog pad,");
			DrawFormatString(20, 280, GetColor(255, 255, 0), "you can return to the original position by pressing the analog pad on the left.");
			DrawFormatString(20, 300, GetColor(255, 255, 0), "★Cause a certain amount of damage to the enemy and display the persuasive menu with the SHARE button.");
			DrawFormatString(20, 320, GetColor(255, 255, 0), "★Persuade them well and save heartpoints to lead a better future.");
			DrawFormatString(20, 340, GetColor(255, 255, 0), "★You can avoid the attack by pressing R2 and pressing the right or left of the analog pad.※However, it cannot be avoided at the right or left edge.So");
			DrawFormatString(20, 360, GetColor(255, 255, 0), "In such a case, you can avoid the enemy's attack by sliding movement with R1 and analog pad.");
			DrawFormatString(20, 380, GetColor(255, 255, 0), "★press the A button at the right time when the opponent attacks, you can dodge the attack.");

			DrawFormatString(20, 400, GetColor(255, 255, 0), "★You can scare the enemy by pressing A at the right time when the enemy attacks.");
			DrawFormatString(20, 420, GetColor(255, 255, 0), "★The controller vibrates as the enemy shoots a gun.Avoid it as it is a signal that the enemy will fire.");

			DrawFormatString(20, 440, GetColor(255, 255, 0), "★★IMPORTANT:If you want to take a counter when the enemy attacks, you can counter the enemy's attack by pressing");
			DrawFormatString(20, 460, GetColor(255, 255, 0), "the A button and Tilt the analog pad toward the vibrating side.");

			//DrawFormatString(1, 720, GetColor(255, 255, 0),
			//	"markは%d,mark2は%d,ranndamukougeki2は%d,ranndamulock2は%d,settokubunnkiframe2は%d,nanameidouY5は%d,nanameidouY3は%d", mark, mark2, ranndamukougeki2, ranndamulock2, settokubunnkiframe2, nanameidouY5, nanameidouY3);

			++menyframe;
		}
		if (Seen == 400 && menyframe > 100) {
			if (Pad[PAD_8] == 1) {
				menyframe = 0;
				Seen = 301;
			}
		}
		ScreenFlip();  // 裏画面を表画面に反映
	}



	DxLib_End();  // ＤＸライブラリ使用の終了処理
	return 0;  // ソフトの終了 

}