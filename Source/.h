#include "DxLib.h"

#ifndef DEF_PLAYERHENNSUU_H //二重include防止

#define DEF_PLAYERHENNSUU_H

int stage[7][4][2];  // 盤上のマスの格子点の座標
int pos[6][3][2];    // キャラ描画座標
int i = 0;
int j = 0;
void init_stage()  // stage と pos を初期化する
{
	for (j = 0; j < 4; j++) {//jはx軸、iはy軸
		int w = (j-1.5) * 400, h = 300;//ステージの下の位置で決めた左を固定したままここで大きさを変える(左右へ伸びて大きくなる。)、高さは大きさを変える
		for (i = 7; --i >= 0; ) {
			stage[i][j][0] = w + 850, stage[i][j][1] = h + 260;//ステージの位置を変える、高さは位置を変える
			w = w * 8 / 10, h = h * 9 / 10;
		}
	}
	//ステージ上の中心の座標を表している。
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 3; j++) {
			pos[i][j][0] = (stage[i][j][0] + stage[i + 1][j + 1][0]) / 2 - 25;
			pos[i][j][1] = (stage[i][j][1] + stage[i + 1][j + 1][1]) / 2 - 65;
		}
}

int White;
int function_status;//戦闘画面中は1とするための変数function_statusの定義

int lockmark = 0;
int imagemove = 0;

int keyrock = 0;
int talkrock = 0;
int startmark = 0;

int moveA = 0;
int playerImageA = 0;
int imagecount = 0;

int ScreenMode = 0;
//int talk = 0;
int add = 0;
int NowTime = 0;
int ChangeTime = 0;

//init_stage(); // stage, pos の初期化
int enemyX = 4, enemyY = 1;   // 敵の位置
int playerX = 1, playerY = 4;  // 俺の位置

int enemyMove = 0;   // 敵の移動状態
  // 俺の移動状態//1～21で右に振り向きのプログラム①が終わり、22になったら足踏みする②を実行するようにする。
int playerMove = 1;
int lockonMove = 0;
int sinnzouHandle = 0;
int bloodMove = 0;
//function_status = 1;//最初は1にして戦闘画面状態にする。

int lock = 0;  // ロック状態

int lockonHandle[3];
int enemyGHandle[12];   // 敵のグラフィックハンドル格納用配列
int playerGHandle[3];  // 俺のグラフィックハンドル格納用配列
int kikennhanndle[12];
// 0-2:後ろ向き、3-5:右向き、6-8:前向き、9-11:左向き
int hartmarkhanndle[3];
int bloodGHandle[3];

int MovieGraphHandle;//背景のgifのための変数
int anarogunoizuGraphHandle;
//バトルのために読み込む画像
///void battle_Initialize() {

	///SetTransColor(255, 255, 255); // 読み込む画像の前にこいつを置くことで透明化できる。ループ内にも書いて正しく動くが毎回読み込むようになってしまうため処理が遅くなる。
	///LoadDivGraph("lockon.bmp", 3, 3, 1, 23, 23, lockonHandle);//なので、一度読み込むだけ画像は使えるし、処理を遅くしないためにループに入る前かつWinMainの中に書いた。
	///LoadDivGraph("charall.png", 12, 3, 4, 49, 66, enemyGHandle);
	///LoadDivGraph("playersyuzinnkou.bmp", 3, 3, 1, 20, 33, playerGHandle);
	///LoadDivGraph("kikenn.png", 12, 4, 3, 67, 66, kikennhanndle);
	// ムービーファイルをロードします。
	///MovieGraphHandle = LoadGraph("original.gif");
	// ムービーを再生状態にします
	///PlayMovieToGraph(MovieGraphHandle);
///}
int enemyImage = enemyGHandle[11];    // 敵 左向き
int playerImage = playerGHandle[0];   // 俺 右向き
int lockImge = lockonHandle[2];
int hartmarkImge = hartmarkhanndle[0];
int bloodImage = bloodGHandle[0];


int preplayerX = 1;//バトル開始での初期位置のplayerXとアドアタックタイムが0の時の以前のマスの値が入るplayerXが影響しない様に前もって初期位置と同じ1とした。あとは変数なのでその都度正しく変わるので問題ない。
int after = 0;
unsigned int count = 50;
int count2 = 50;
unsigned int count3 = 50;

int Kcount = 50;//キック攻撃のゲージ
int Kcount2 = 50;
int Gcount = 15;//15発で数分で再びストックされる
int Gcount2 = 15;

int Gtime = 0;
int Wcount = 100;
int Wcount2 = 100;

int attackdamage = 0;//殴る際の攻撃判定として作った。
int addattacktime = 0;//追加攻撃をするための変数
int addattackimage = 20;//描画するための追加アタックのためのゲージ
int addplayerX = 0;
int addplayerY = 0;
//int addattacktimeEND = 0;//addattacktimeが終わった後の処理のためのモノ

int zannzou = 0;//　攻撃してマスを移動するときのみ20にすればいいので、初期値は0とした。
int  frames = 0; // フレーム数
int frames2 = 0;
int stopenemytime = 0;
int GcountZeroCounter = 0;
int GcountA = 0;

int preenemyX = 0, preenemyY = 0;
int rundumsave = 0;
int rundumsavetime = 0;
int enemyattacktime = 0;

int nomove = 0;
int posX = 0;

const int MOVE_INTERVAL = 1000; // 何ミリ秒ごとに移動処理をするか
int nextMoveTime = GetNowCount() + MOVE_INTERVAL; // 次回移動処理をする時刻
int stopCount = 0; // 動かないのがあと何回か

//入力の確認のための変数
int LEFTmark = 0;

//主人公と敵のHP
int playerHP = 1000;
int enemyHP = 1400;
//int enemyHP2 = 1;

int inotigoicount = 0;

int enemyattack = 0;
int enemyattackB = 0;

int kaont = 0;
int preenemyXX = 0;
int preenemyYY = 0;
int enemycount = 0;
int enemycountframe = 0;
int Lcount = 0;
int Lframe = 0;

int last = 0;

int GtimeA = 0;
int Xkey = 0;
int Gkey = 1;
int Gfunction_status = 0;
int MGcount = 200;
int MGcount2 = 200;
int MGframe = 0;
int MGcountA = 0;
int MGcountZeroCounter = 0;
int Grock = 0;
int reload = 0;
int MGtime = 0;
int MGcountW = 0;

int protect = 0;
int protectcount = 0;
int preframe = 0;
int preframeA = 0;
int preframeB = 0;
int preframeC = 0;

int stayhere = 0;
int MGimg = 0;
int countinue = 0;
int countinuekeylock = 0;
int playerHPframe = 0;//移動するときのマスの間を一瞬の残像を残すために作った変数。

int  gameovercolor = 0;
int gameovercolorlock = 0;

int gameovercolor1 = 0;
int playerHPlock = 0;

int mark = 0;
int mark2 = 0;

int tabaco = 0;
int tabacocount = 0;

int enemyattack3 = 0;
int enemyattack4 = 1;
int enemyattack5 = 1;
int a;
int b;
int d;//cは他の部分で定義されているので使えない
int aframe = 0;
int enemycountframeB = 0;
int enemycountB = 0;
int fortime = 0;
int fortimeframe = 0;
int enemyimagecount = 0;
int addattacktimelock = 0;
int super = 0;
int playermovelock = 0;

int playerzannzou = 0;

int enemymovelock = 1;
int imagecount2 = 0;
int imagecount3 = 0;
int enemyimagecount2 = 0;
int enemyimagecount3 = 0;

int randamumasuX = 0, randamumasuY = 0;
int kasokudo = 0, kasokudo2 = 0, kasokudo3 = 0, kasokudo4 = 0, kasokudo5 = 0, kasokudo6 = 0;
int preenemyX3 = 0, preenemyY3 = 0, preenemyX3A = 0, preenemyY3A = 0, preenemyX3B = 0, preenemyY3B = 0, preenemyX3C = 0, preenemyY3C = 0, preenemyX3D = 0, preenemyY3D = 0;
int randamuzahyoulock = 0, randamuzahyou = 0, randamuzahyoulockA = 0;
int randamumasuXcount = 0, randamumasuYcount = 0;
//int randamumasuXA = 0, randamumasuXB = 0;
int randamuzahyoukeisann = 0, randamuzahyoukeisannhiki = 0;
int randamumasuXA = 0, randamumasuYA = 0, randamumasuXB = 0, randamumasuYB = 0;
int randamulock = 0, randamulock2 = 0;
int bb = 0; int aa = 0;
int A = 0, B = 0;
int randamuzahyoulockB = 0, randamuzahyoukeisannhikiB = 0, randamuzahyouB = 0, randamuzahyoukeisannB = 0;
int randamuzahyoulockBA = 0, randammasucount = 0;
int randammasucountB = 0;
int randammasucountA = 0, randammasucountBA = 0, randamuzahyoulockBAA = 0;
int test = 0;
int stopenemy = 0;
int Y = 0;
int test2 = 0;


int kakudo = 0, kakudo2 = 0, kakudo3 = 0, kakudo4 = 0;
int kakudoA = 0, kakudoB = 0, kakudoC = 0, kakudoD = 0;

int enemyattacklock = 0, enemyattacklock2 = 0;
int kaihimark = 0;

int C;

int keybord = 0;
int jyoicon = 1;
int senntaku = 0;
int gamenidou = 0;
int hyouzi = 0;
int Glock = 0;
int MovieGraphHandle2;

//inputmapperを考慮してのボタン配置、しかしL、R2に対応するボタンがない。
const int PAD_DOWN = 0;
const int PAD_LEFT = 1;
const int PAD_RIGHT = 2;
const int PAD_UP =3;
const int PAD_1 = 4;//Aボタン
const int PAD_2 = 5;//Bボタン
const int PAD_3 = 6;//Xボタン
const int PAD_4 = 7;//Y角ボタン
const int PAD_5 = 8;//L1ボタン
const int PAD_6 = 9;//R1ボタン
const int PAD_7 = 10;//左ポーズボタン
const int PAD_8 = 11;//右ポーズボタン
const int PAD_11 = 12;//左スティックボタン
const int PAD_12 = 13;//右スティックボタン

//const int PAD_13 = 4;//左スティックボタン

int zannzouA = 0, zannzouB = 0, zannzouC = 0;
int zannzouAlock = 0, zannzoulock = 0;

int preenemyX2 = 0, preenemyY2 = 0, nageX = 0, nageY = 0;
int preenemyY2A = 0, preenemyX2A = 0;
int nageXA = 0, nageYA = 0;
int X = 0;
int nageXAA = 0;

int enemystayhere = 0;
int idoumaeplayerX = 0;//敵が目の前や周りにいて、敵に突っ込んで際に前のマスに戻るための変数。
int idoumaeplayerY = 0;

//敵に与えるダメージ量に関する変数
int enemysabunHP = 0, enemydamegeHP = 0, enemyHPhyouji = 1;
int enemymove = 1;//敵が足踏みするようにするための変数
int enemysabunHPA = 0;
int damgesinndou = 0;
int GenemysabunHP = 0;
int KenemysabunHP = 0;
int enemysabunHPB = 0;

int tabakocount = 0;
int tabakocount2 = 0;
int tabakokirikae = 0;
int tabakokaihukumark = 0;
int sound3 = 0;
int BGMstart1 = 0;

int sinnzoubyouga = 0;
int toumeika = 0;
int stayherelock = 0;//if (stayhere == 1&& stayherelock == 0)の条件に引っ掛かり敵の座標が固定されない様にするために1にする。
int taitolGraphHandle = 0;
int taitoitoumeika = 0;
int sinnzouGraphHandle = 0;
int sinnzoutoumeika = 0;
int sinnzougazoulock = 0;
int snowGraphHandle = 0;
int snow = 0;

int enemymigi = 0;
int addattacktimelock2 = 0;
int addattacktimelock3 = 0;
int addattacktimecharge = 0;

int enemysabunHP2 = 0;

int kougekilock = 0;
int pre2enemyY = 0;
int pre2enemyX = 0;

//効果音の変数
int nagurusound = 0;
int naguru2sound = 0;
int naguru3sound = 0;

//ステージのBGMの再生のための変数
int stage1sound = 0;

//敵が動き出すまでの止まっている時間のための変数
int enemystartmovetime = 0;


int reSeen = 0;
int talkbanngou = 0;

//先行入力のための変数
int attackframe = 0;
int attackframe2 = 0;
int attackframe3 = 0;
int sennkounyuuryokulock = 0;
int LEFTmarklock = 0;
int RIGHTmarklock = 0;
int attackframlock = 0;
int sennkounyuuryokubunnki = 0;
int sennkounyuuryokubunnki2 = 0;
int sennkounyuuryokubunnki3 = 0;

//ステージ1の関数を呼び出すための変数の場所
int stage1PlayerDrawyobidasi = 0;
#endif