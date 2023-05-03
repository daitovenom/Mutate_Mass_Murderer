#include "Game.h"

Game* Game::_instance = NULL;

//コンストラクタ = 最初に勝手に絶対呼びだされる
Game::Game() {
	//初期化
	_instance = this;
	MovieGraphHandle = -1;


}

//デストラクタ = 最後に勝手に絶対呼びだされる
Game::~Game() {

}

bool Game::Init(){


	//↓★関数で使いたい画像を瞬間に呼ぶのは時間がかかるし重いのでメインの中に既にスタンバっている状態にする。
	SetTransColor(255, 255, 255); // 読み込む画像の前にこいつを置くことで透明化できる。ループ内にも書いて正しく動くが毎回読み込むようになってしまうため処理が遅くなる。

	// ムービーファイルをロードします
	if (MovieGraphHandle = LoadGraph("180half_f.gif") == -1) {
		return false;
	}
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
	LoadDivGraph("Assets/image/playersyuzinnkoukuronuriKAIZOU6.bmp", 3, 3, 1, 20, 33, playerGHandle);

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

	InitStage(); // stage, pos の初期化

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


void Game ::InitStage()  // stage と pos を初期化する//ステージ2の121行目のプログラムにより、ここで作られた「点」が「線」になっている、
{
	for (j = 0; j < 7; j++) {
		int w = (j - 3) * 230, h = 280;//ステージの下の位置で決めた左を固定したままここで大きさを変える(左右へ伸びて大きくなる。)、高さは大きさを変える
		for (i = 4; --i >= 0; ) {
			stage[i][j][0] = w + 750, stage[i][j][1] = h + 230;//ステージの位置を変える、高さは位置を変える
			w = w * 7.8 / 10, h = h * 9 / 10;
		}
	}
	//ステージ上の中心の座標を表している。
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++) {
			pos[i][j][0] = (stage[i][j][0] + stage[i + 1][j + 1][0]) / 2 - 25;
			pos[i][j][1] = (stage[i][j][1] + stage[i + 1][j + 1][1]) / 2 - 65;
		}
	}


	// !!!!雨の演出
	for (int rain = 0; rain < rain_power; rain++)
	{
		int l = GetRand(50) + 10;	// 雨線の長さ
		rain_hairetsu[rain][0] = GetRand(1470);	// 始点X
		rain_hairetsu[rain][1] = -GetRand(780);	// 始点Y
		rain_hairetsu[rain][2] = rain_hairetsu[rain][0] + l * 1;	// 終点X
		rain_hairetsu[rain][3] = rain_hairetsu[rain][1] - l * rain_kakudo;	// 終点Y
		rain_hairetsu[rain][4] = 0;	// X移動変化量
		rain_hairetsu[rain][5] = 0;	// Y移動変化量
	}

	// !!!!雪の演出
	for (int snow = 0; snow < snow_power; snow++)
	{
		snow_hairetsu[snow][0] = GetRand(1470);	// X位置
		snow_hairetsu[snow][1] = -GetRand(780);	// Y位置
		snow_hairetsu[snow][2] = 0;	// X移動変化量
		snow_hairetsu[snow][3] = 0;	// Y移動変化量
		int rand = 0;
		if (GetRand(1))
		{
			rand = GetRand(3);	// X方向
		}
		else {
			rand = -GetRand(3);	// -X方向
		}
		snow_hairetsu[snow][4] = rand;	// X移動方向量
		snow_hairetsu[snow][5] = GetRand(5);	// 雪の大きさ
	}
}
