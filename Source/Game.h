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

    static Game* GetInstance() { return _instance; }
private:
    //メンバ変数
    static Game* _instance;

    //移動してきた変数達---------
public:
    int DAMEGEframe = 0;
    int ENEMYkougekigazouA1lock = 0;
    int enemykougekigazou = 0;
    int enemyhanntoumei = 0;
    int enemyzannzoulock = 0;
    int ENEMYkougekigazouA1frame = 0;
    int ENEMYkougekigazouA2frame = 0;
    int ENEMYmovelock2 = 0;
    int  stayherelock = 0;
    int  stayherelock3 = 0;
    int playerHPhyouzi = 0;
    int playerHPsubunninnsiki = 0;
    int byougajyunnbann = 0;//主人公、敵、敵2、敵1の攻撃、敵2の攻撃を描画する初期の順番を制御するための変数。
    int enemystayhere = 0;
    int cc = 0;
    int stage1 = 0;//後ろ蹴りでバグをステージ1に移動しないようにするための変数。
    int stage2 = 0;//後ろ蹴りでバグをステージ1に移動しないようにするための変数。
    int LeftTrigger = 0;
    int RightTrigger = 0;
    int enemyidou = 0;
    int enemyidou2 = 0;
    int KENJYUUgazou = 0;
    int yokerarenai = 0;
    int yokerarenai2 = 0;
    int enemyidou3 = 0;
    int tosshin = 0, tosshin2 = 0, tosshin3 = 0;
    int enemybyougablock3 = 0;
    int attackframeA = 0;
    int enemyhanntoumei3 = 0;
    int talkend = 0;
    int DAMEGE = 0;
    int playerkonntororulock3 = 0;
    int enemyzannzoulock2 = 0;
    int enemyzannzoulock3 = 0;
    int stayhere = 0;
    int stayhere2 = 1;//敵2は消す。
    int stayhereLOCK = 0;
    int stayhere3 = 0;

    int mark = 0;
    int mark2 = 0;

    int enemygazoukesu = 0;
    int migimuki = 0;
    int hidarimuki = 0;
    int enemybyougablock = 0;
    int yokkerucouunt = 0;
    int kericount2 = 0;
    int Seenframe = 0;
    int bloodMove = 0;
    int Seenlock = 0;
    int Seen = 300;
    int playerImage2 = 0;
    int color = 0;
    int serekutobotanncount2 = 0;
    int heartpoint = 0;//ハートポイントが一定以上になれば彼を救える選択肢が登場する。
    int analognoizu = 0;
    int contorora = 0;

    int zannzoulock = 0;//瀕死状態の時はこいつはずっと1のままだがそれでいい。
    //int enemyzannzoulock = 0;//ステージ1の敵の方。//ステージ2の青い敵
    //※たまにあったバグっぽいのもenemyzannzoulockやenemyzannzoulock2やanotherenemyzannzoulockを勘違いして書いていたためだろう。
    //int enemyzannzoulock2 = 0;//ステージ2の攻撃する時の青い敵
    int anotherenemyzannzoulock = 0;//ステージ2の赤い敵


    int enemyzannzoulock22 = 0;

    int stayhereframe = 0;
    int stayhere2frame = 0;


    int enemyhirumaseframe = 0;
    int hinsikawanarilock = 0;
    float x = 0, y = 0, s = 0;
    float x2 = 0, y2 = 0, s2 = 0;
    int R1botannlock = 0;


    int playermovelock = 0;
    int playermovelock2 = 0;

    int stopCount2 = 0;
    int kougekidekinailock = 0;
    int enemyattackdekinai = 0;
    int enemyattackagein = 0;
    int enemyattackageinframe = 0;
    int KABURImark = 0;
    int KABURI = 0;
    int ENEMYkougekigazouA1 = 0;
    //int ENEMYkougekigazouA1frame = 0;
    int ENEMYkougekigazouA2 = 0;
    //int ENEMYkougekigazouA2frame = 0;

    int playerkonntororulock = 0;
    int playerkonntororulock2 = 0;
    //先行入力のための変数
    int attackframe = 0;
    int attackframe2 = 0;
    int attackframe3 = 0;
    int attackframe4 = 0;
    int attackframe5 = 0;
    int attackframe6 = 0;
    int attackframe7 = 0;
    int attackframe8 = 0;
    int attackframeB = 0;
    int nagurugazou = 0;
    int nagurugazou2 = 0;

    int attackhannbetu = 0;
    int attackhannbetu2 = 0;
    int hannilock = 0;
    int playerattackhanndou = 0;
    int yokeruX = 0;
    //敵2の情報
    int nextMoveTime2 = 0;
    const int MOVE_INTERVAL2 = 1000;

    int InputXframe = 0;
    int RIGHT = 0;
    int analoglock = 0;
    int preInputX = 0;

    int jyuuzikeysousa = 0;
    int jyuuzikeysousa2 = 0;
    int prenaihuframe = 0;

    int hirumaselockframe2 = 0;
    int enemy2hirumaseframe = 0;

    int ENEMYkougekigazouA2framelock = 0;
    int ENEMYkougekigazouA2frame2 = 0;

    int ENEMYkougekigazouB1 = 0;
    int ENEMYkougekigazouB1frame = 0;
    int ENEMYkougekigazouB1lock = 0;
    int ENEMYkougekigazouB2frame = 0;

    int enemy1HPhyouji = 0;
    int enemy2HPhyouji = 0;

    int settokutoumeika = 0;

    //主人公と敵のHP
    int playerHP = 600;
    int playerHPlock = 0;
    int enemyHP = 800;
    int enemyHPgage = 0;
    //敵二人の位置
    int enemyX1 = 0, enemyY1 = 0, enemyX2 = 0, enemyY2 = 0;
    int enemy1HP = 1500;
    int enemy2HP = 1200;
    int enemy3syutugenn = 0;
    //入力の確認のための変数
    int kougekimark = 0;
    int MAKR = 0;
    int LEFTmark = 0;
    int LEFTmarkA = 0;
    int LEFTmarkB = 0;
    int LEFTmarkC = 0;
    int LEFTmarkD = 0;
    int LEFTmarkE = 0;
    int LEFTmarkF = 0;
    int LEFTmarkG = 0;
    int LEFTmarkH = 0;
    int LEFTmarkI = 0;
    int LEFTmarkJ = 0;
    int LEFTmarkK = 0;


    int gameovercolor2 = 0;
    int countimu2 = 0;
    int countimucount2 = 0;
    int enemyzannzoulockframe1 = 0;
    int ENEMYkougekigazouC1frame = 0;
    int ENEMYkougekigazouC2frame = 0;
    int enemy1count = 0;
    int enemy2count = 0;
    int enemyzannzoulockBframe = 0;

    double bairituX = 0;
    float bairituY = 0;
    float bairituY2 = 0;
    //敵の攻撃を制御するための変数。
    int kougekiframe = 0;
    int ranndamukougeki = 0;

    int enemyhirumaseframelock = 0;
    int ranndamulock = 0;
    int ranndamulockframe = 0;
    //int ENEMYmovelock2 = 0;
    int ranndamulockframelock = 0;

    int stage[4][7][2];  // 盤上のマスの格子点の座標
    int pos[3][6][2];    // キャラ描画座標
    int i = 0;
    int j = 0;
    // !!!!雨を降らす演出
    int rain_power = 100;			// 量
    int rain_hairetsu[100][6] = {};	// 配列
    int rain_kakudo = 2;			// 入射角度量
    int rain_speed = 10;			// 速度

    // !!!!雪を降らす演出
    int snow_power = 100;			// 量
    int snow_hairetsu[100][6] = {};	// 配列
    int snow_kakudo = 10;			// 入射角度量
    double snow_speed = 0.3;		// 速度

    //initStageから下の変数

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
    int playerX = 1, playerY = 1;  // 俺の位置

    int enemyMove = 0;   // 敵の移動状態
      // 俺の移動状態//1～21で右に振り向きのプログラム①が終わり、22になったら足踏みする②を実行するようにする。
    int playerMove = 1;
    int lockonMove = 0;
    int sinnzouHandle = 0;



    //function_status = 1;//最初は1にして戦闘画面状態にする。

    int lock = 0;  // ロック状態

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
    int enemyImage = enemyGHandle[3];    // 敵 左向き 初期値でのenemyImageにenemyGHandle[3]が入ってるだけで、条件によってはenemyGHandle[3]も意外も入る。
    int playerImage = playerGHandle[0];   // 俺 右向き//★上で「int playerGHandle[8];  // 俺のグラフィックハンドル格納用配列」と定義して、
    //8個の画像をplayerImageにいれて都合のいい時に画像を表示する。playerImage = playerGHandle[0];として、上でint playerGHandle[8];と定義したこともあり
    //playerImageに入るのは8個のplayerGHandle[8]なのだろう。
    int testplayerImage = testplayerGHandle[0];   // 俺 右向き
    int lockImge = lockonHandle[2];
    int hartmarkImge = hartmarkhanndle[0];
    int bloodImage = bloodGHandle[0];
    int gimenHandle;

    int preplayerX = 1;//バトル開始での初期位置のplayerXとアドアタックタイムが0の時の以前のマスの値が入るplayerXが影響しない様に前もって初期位置と同じ1とした。あとは変数なのでその都度正しく変わるので問題ない。
    int after = 0;
    unsigned int count = 50;
    int count2 = 50;
    unsigned int count3 = 50;

    int Kcount = 50;//キック攻撃のゲージ
    int Kcount2 = 50;
    int Gcount = 100;//15発で数分で再びストックされる
    int Gcount2 = 13;

    int Gtime = 0;
    int Wcount = 100;
    int Wcount2 = 100;

    //int attackdamage = 0;//殴る際の攻撃判定として作った。
    int addattacktime = 301;//追加攻撃をするための変数//adoatakkutaimu 
    int addattackimage = 20;//描画するための追加アタックのためのゲージ
    int addplayerX = 0;
    int addplayerY = 0;
    //int addattacktimeEND = 0;//addattacktimeが終わった後の処理のためのモノ

    int zannzou = 0;//　攻撃してマスを移動するときのみ20にすればいいので、初期値は0とした。
    int frames = 0; // フレーム数
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

    //int enemyHP2 = 1
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


    int MGimg = 0;
    int countinue = 0;
    int countinuekeylock = 0;
    int playerHPframe = 0;//移動するときのマスの間を一瞬の残像を残すために作った変数。

    int  gameovercolor = 0;
    int gameovercolorlock = 0;

    int gameovercolor1 = 0;



    int tabaco = 0;
    int tabacocount = 0;

    int enemyattack3 = 0;
    int enemyattack4 = 1;
    int enemyattack5 = 1;

    int aframe = 0;
    int enemycountframeB = 0;
    int enemycountB = 0;
    int fortime = 0;
    int fortimeframe = 0;
    int enemyimagecount = 0;
    int addattacktimelock = 0;
    int super = 0;




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
    //int jyoicon = 1;
    int senntaku = 0;
    int gamenidou = 0;
    int hyouzi = 0;
    int Glock = 0;
    int MovieGraphHandle2;

    //inputmapperを考慮してのボタン配置、しかしL、R2に対応するボタンがない。
    const int PAD_DOWN = 0;
    const int PAD_LEFT = 1;
    const int PAD_RIGHT = 2;
    const int PAD_UP = 3;
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
    int zannzouAlock = 0;

    int preenemyX2 = 0, preenemyY2 = 0, nageX = 0, nageY = 0;
    int preenemyY2A = 0, preenemyX2A = 0;
    int nageXA = 0, nageYA = 0;
    int X = 0;
    int nageXAA = 0;


    int idoumaeplayerX = 0;//敵が目の前や周りにいて、敵に突っ込んで際に前のマスに戻るための変数。
    int idoumaeplayerY = 0;

    //敵に与えるダメージ量に関する変数
    int enemysabunHP = 0, enemydamegeHP = 0, enemyHPhyouji = 1;
    //int enemymove = 1;//敵が足踏みするようにするための変数
    int enemysabunHPA = 0;
    int damgesinndou = 0;
    int GenemysabunHP = 0;
    int KenemysabunHP = 0;
    int enemysabunHPB = 0;

    int tabakocount = 0;
    int tabakocount2 = 0;
    int tabakokirikae = 0;
    int tabakokaihukumark = 0;

    //BGMのための変数
    int sound3 = 0;
    int sound4 = 0;
    int BGMstart1 = 0;
    int BGM1 = 0;//たぶんtalk==0で何度も再生されてしまうので0の最初に流れているBGMはキー入力で止まっていると思いが、それ以外のBGMはtalkが0の時に再生されてそのままなのでまるでキーを押しても止まらないように見えたのだろう。
    int reBGM1 = 0;

    int sinnzoubyouga = 0;
    int toumeika = 0;
    //int stayherelock = 0;//if (stayhere == 1&& stayherelock == 0)の条件に引っ掛かり敵の座標が固定されない様にするために1にする。
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
    int tabakosound = 0;
    int damegi1sound = 0;
    int gardsound = 0;

    //ステージのBGMの再生のための変数
    int stage1sound = 0;

    //敵が動き出すまでの止まっている時間のための変数
    int enemystartmovetime = 0;


    int reSeen = 0;
    int talkbanngou = 0;


    int sennkounyuuryokulock = 0;
    int LEFTmarklock = 0;
    int RIGHTmarklock = 0;
    int attackframlock = 0;
    int sennkounyuuryokubunnki = 0;
    int sennkounyuuryokubunnki2 = 0;
    int sennkounyuuryokubunnki3 = 0;

    int sennkounyuuryokujyuujiki = 0;

    //ステージ1の関数を呼び出すための変数の場所
    int stage1PlayerDrawyobidasi = 0;

    //敵が大ダメージを負った際に怯むための変数
    int ememydontmovetime = 0;
    int ememydontmovetimeframe = 0;

    //攻撃するときの前の座標を記憶するための変数
    int kougekiroclmark = 0;
    int premasuframe = 0;
    int premasuframe2 = 0;

    //主人公が敵に攻撃するときの変数
    int syuzinnkouattack1 = 0;
    int preplayerY = 0;
    int lockdekinai = 0;
    //主人公の残像のための変数
    int zannzousaigo = 0;
    int zannzouAsaigo = 0;
    int zannzouBsaigo = 0;
    int zannzouCsaigo = 0;
    int R1lock = 0;

    //主人公の攻撃を表す画像を制御するための変数

    int playernaguruImage = 0;
    int playernaguruAGHandle[1];
    int playernaguruBGHandle[1];
    int Xbotannlock = 0;
    int playertabakoImage = 0;
    int  playertabakoAHandle[1];
    int  playertabakoBHandle[1];
    int  playertabakoCHandle[1];
    int  playertabakoDHandle[1];
    int playeridouAHandle[1];
    int playeridouImage = 0;
    double syuzinnkoubairitu = 5;
    int kasanarulockA = 0;
    int nimasuplayerX = 0;
    int  playeridouA3Handle[1];

    int playerKONNBO1AHandle[1];
    int playerKONNBO1AImage = 0;
    int KONNBO1A = 0;
    int playerKONNBO1BHandle[1];
    int playerKONNBO1BImage = 0;
    int KONNBO1B = 0;
    int KONNBO1Bframe = 0;//そのままで止まった画像を制限時間をつけて、描画されている時間の期間を決めた。
    int KONNBO1Aframe = 0;

    int ENEMYkougekiA1Handle[1];
    int ENEMYkougekiA2Handle[1];
    int ENEMYkougekiA1Image = 0;
    int ENEMYkougekiA2Image = 0;

    //int ENEMYkougekigazouA1lock = 0;

    int playeridouA2Image = 0;
    int playeridouA2Handle[1];
    int playeridouA4Handle[1];

    //会話のための変数
    int mozinoYziku = 0;
    int mozinoXziku = 0;
    int mozibyougaframe = 0;


    //ボタンをロックするための変数
    int botanlock = 0;//talk.hで会話画面から戦闘画面に進む際にボタンの入力ができないようにするための変数。
    int botanlockframe = 0;//talk.hで会話画面での電話に出るかでないかでの無音の期間のためのフレームのための変数。
    int tabakolock = 0;
    int kasanarulock = 0;
    int tabakogazoulock = 0;
    int Bbotannlock = 0;

    //文字の大きさを変える//文字の描画
    int mozisaizu = 0;
    int  mozigrateHandle[1];
    int  mozigrateImage = 0;

    //主人公のR1を押した後の移動のための変数
    int sennkounyuuryokujyuujikiframe = 0;
    int nomalidou = 0;
    int RIGHTbotannlock = 0;
    int zannzouD = 0;
    int suraidoidou = 0;
    //int suraidoidouframe = 0;

    int Cr = GetColor(255, 255, 255);
    int InputX, InputY;
    char String[64];

    int R1count = 0;
    int osippanasi = 0;
    int hirumaselock = 0;
    int R1countlock = 0;
    int R1attack = 0;
    int zannzouE = 0;
    int R1attackframe = 0;

    //当たり判定
    int enemyShotGraph = 0;
    int enemyShotW = 0, enemyShotH = 0;
    int lockmarkyokoidou = 0;
    int lockmarktateidou = 0;
    int lockmarkXzahyou = 0;
    int lockmarkYzahyou = 0;

    int suraidoidouframe1 = 0;
    int suraidoidouframe2 = 0;
    int zannzouF = 0;
    int kougekiKANOU = 0;
    int playerkougekiXzahyou = 0;
    int playerkougekiYzahyou = 0;
    int saveplayerX = 0;
    int saveplayerY = 0;

    int nagurucount = 0;
    int lockkakuninn = 0;
    int konnbokakuninn = 0;
    int save2playerX = 0;
    int save2playerY = 0;

    int nagurukasanaru = 0;
    int KONNBO1kasanaru = 0;
    int KONNBO2kasanaru = 0;

    int enemykougekilock = 0;
    int masusave = 0;

    int jyuuosenai = 0;

    XINPUT_STATE input;
    XINPUT_STATE input2;

    int Font00, Font01;
    int kaiwaHandle = 0;
    int SHOTHandle = 0;
    int SHOTbyouga = 0;
    int enemytalk = 0;

    int Time;
    int BGMlock = 0;
    int vioraHandle = 0;
    int K1Handle = 0;

    int  playerKONNBO1ANOIZU1Handle[1];
    int  playerKONNBO1ANOIZU2Handle[1];
    int  playerKONNBO1ANOIZU3Handle[1];
    int  playerKONNBO1ANOIZU4Handle[1];

    int  player1GHandle[1];
    int  player2GHandle[1];
    int  player3GHandle[1];
    int  player4GHandle[1];
    int  player5GHandle[1];

    int playerMove2 = 0;
    int playerMove3 = 0;
    int NOIZUlock = 0;
    int dennwaHandle = 0;
    int dennwalock = 0;




    int RED = GetColor(255, 0, 0);      // 緑の色コードを取得

    int talk = 0;
    int talkframe = 0;
    int talkframecount = 0;
    int start = 0;
    int battle = 0;

    int countchar = 0;
    int Green = GetColor(0, 255, 0);
    int Yellow = GetColor(255, 255, 0);
    int talkbunnkiA = 0;
    //int White = GetColor(255, 255, 255);

    int t = 0;
    const char* str[100] = { "A: At this rate, you will be killed by your son in the future!",
    "B: Let's stop the useless battle and talk.", "Y: Kill you!" ,
    "That child can't go against me! So you won't be killed!", "Annoying shut up!", "I'll kill you before you get killed!",
    "A: Again, you will be killed by your son in the future! !!", "B: I don't want to hurt you anymore. .. ..", "Y: Already good! If this happens, I will kill you in the future so as not to increase the sacrifice!",
    "I don't know, it's my own way!", "I want to hurt you more!Suffering!", "If you can kill me, do it! You can't beat them!",
    "A: Last. You will be killed by your son in the future.", "B: You are still in time now. Your life is at stake anymore.", "Y: I see. I want you to die." ,
    "Future yeah, it's a disgusting guy ... Already, I understand. You win.", "I don't want to worry about your life, but I'm tired. I'm surrendering.", " Oh, that's a reluctant guy. Do you really kill me? ",
    "A: I don't want to kill if possible ...", "B: To keep my son and future victims out. I can't help ... continue the fight." ,
        //ここからは大男二人に対する説得
        "A: I'm still in time! I will cooperate too! So give yourself up!",
        "B: Isn't it due to your weakness that you couldn't stand up to when you were abused?",
        "Y: After all, is it too late?",
        "It's even slower now! (I was shot on my right foot!)",
        "Shut up!(He struck the upset moment and shot his arm with a gun!)",
        "Ah! That's right! It's too late!",
        "A:Say it again! It's not too late yet! So give yourself up!!",
        "B:Do you really want such a future?",
        "Y:He can't hear my voice anymore ...",
        "Don't say the same thing over and over again! (I was shot further on my right foot!)",
        "I also met a partner who understands me!So this was good!",
        "Ah! That's right! I can't reach it anymore!!! It's all your fault! (My heart was hurt. HP decreased a little.)",

        "A:A woman who thinks of you wants your rehabilitation!",
        "B:If you self - confess now, you can change the future!",
        "Y:If you continue any longer, I have no choice but to kill ...",
        "Ugh! ,,,Noisy! Don't talk about her! (Maybe he still has a conscience to think of someone. The opponent's HP has dropped.)",
        "I have nothing to lose anymore.If I can kill you, that's fine. (The face of the man in blue was a little cloudy.)",
        "Oh! Has the engine finally started! Yes, you're the same murderer as I am!",

        "A:It's still in time now! Let's stop this fight for her too!",
        "B:I will cooperate too.So let's atone for yor sins!",
        "Y:It's a shame. It seems meaningless any more...",
        "For me, she is ... (a little more ... a little more.The opponent's HP has dropped.)",
        "What did you do? Nothing has changed anymore! .. (The face of the man in blue was a little cloudy.)",
        "I shot through his eyebrows ...",

        "A:Let's go back to her! She is waiting for you!!",
        "B:If you don't atone for your sins,I'll keep the woman who loves you away from you!I'm serious!",
        "...you...you are...What do you know about meeeeeeeeee!!!(Angry eyes stare at me,My legs are freezing, my HP has decreased a little.) ",
        "!? Stop it!Stop it!I...I don't want to lose her like my beloved donkey ...",

        "A:ask!She's waiting for you! Let's stop!",
        "B:I don't need to fight anymore.(I'm sorry to say terrible things. But this will change the future.)",
        "right.No more.Just say what you want to say even though you don't know anything.",
        "Oh, I'll pay for her ... I don't want to lose her.",

        //ハートポイントがたまらなかった場合のコメント。
        "A:Can I stop his runaway with her thoughts...?",
        "Everything is slow. I'll finish it!",

        "Bloody duo lying down.I was holding a pistol with blood.",
        "[I]Only by doing this could they be stopped...",
        "[I]This has changed the future.However, this cannot be said to have been「solved」.",
        "At that time, a sheriff rushed to the noise.",
        "I tried to leave the place in a hurry, but I couldn't move because I was injured.",
        "I was caught as it was.But at that moment I was sitting in front of my PC.",
        "I sought out information about the duo I killed.",
        "I found an article about a disappearing man and a dead duo.",
        "I couldn't find any other articles. Apparently, there have been no murders by them since then.",
        "As soon as I stroked my chest, I was wondering if this was really good.",
        "[I]Sometimes it can't be helped to make no more sacrifices....",
        "The only regret is that I couldn't live up to the expectations of the woman who thought of him and asked me.",
        ".........",
        //敵がわざと戦意喪失したかのように見せて主人公を撃った場合の未来。
        "[I]It seems that her voice has finally reached his heart.",
        "The next moment I heard a gunshot and I was lying down.",
        "[Rough-headed man in blue]Don't say anything sloppy without knowing anything about me and her!",
        "Apparently, his loss of fighting spirit was an act to create a gap for me.",
        "I think I made a mistake somewhere ... My consciousness is fading ...",
        "...........",
        //説得がうまくいった場合。
        "[Rough-headed man in blue]...I...I don't want to lose her. I want to see her.",
        "The man in blue said with tears.",
        "[Rough - headed man in blue]Until now, she hated women because of her mother's abuse. But she was different.",
        "[Rough - headed man in blue]Only she doesn't want to make her sad anymore. I want to atone for my sins.",
        "I put my pistol back on my waist.",
        "I made a small sacrifice due to my mistake in selection, but I was relieved that no more sacrifices would be made.",
        "The man in red also feels like he wants to atone for his sins with the blue man.",
        "These two are best friends. If you lead either one to the right path, both will naturally go in the right direction.",
        "I took them to the police station where the sheriff was.",
        "They told the truth of the case so farand admitted the charges.",
        "[I]This should make a big difference in the future.I'm really tired ...",
        "..........",
        "....................",
        "..............................",
        "I searched the net after them.",
        "The man in blue seems to be meeting her under police control.",
        "And he seems to be living under the police, cooperating in the incidentsand other incidents that happened.",
        "learned that just as the madness that people give to people changes people, the love that people give to people also changes people.",
        "When I smoke and relax ...",
        //電話の後
        "....Yes Hello"
    };//ここで文字を直接書いてるので、この文字のバイト数が各posmozi[]に入るだけ
    int frame[100] = { 10, 10, 10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
    10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
    10,10,10 };//次の一文字が出るまでのカウンタとして働いている、ここの数値を変えることで文字が一文字ずつ出るまでの間隔を設定できる。
    int posmozi[100];//文字のバイト数が入る箱を表している。
    int countS[100];//次の文字が出るまでのカウントするためのもの

    int fortimeframe3 = 0;
    int fortimeframe4 = 0;

    int z;//関数drawString外でも使えるように外にも定義を書いた。zの数値は関係なく、文字列が入った数列がif文により同じ変数zの時にframe[z]と同じになるまで+1されていったり、+2バイトor+1バイトされていくため、
    //文字が一文字ずつ入っていく、なんでzの変数に値を入れて動かす必要がないのだ。ちなみにfor (z = 0; z < 3; ++z)で書いてしまうとキーAを押した際のif文に関係なく関数drawStringの最初のzどこかに値が入っただけで繰り返しを開始してしまうため、今回のように同じ変数zの時にフレームを利用して描画するようにした。
    char c = str[z][posmozi[z]];//関数drawString外でも使えるように外にも定義を書いた。


    void drawString(int z, int x, int y, int color)
    {
        char c = str[z][posmozi[z]];//posmozi[z]
        if (countS[z] == 0 && c != '\0')
            posmozi[z] += IsDBCSLeadByte(c) ? 2 : 1;
        if (++countS[z] == frame[z]) countS[z] = 0;
        DrawFormatString(x, y, color, "%.*s", posmozi[z], str[z]);
        DrawFormatString(300, 300, RED, "countS[0]は%d", countS[0]);
    }

    const char* str2[100] = {
        "I got a call from someone.",
    "Press A to not answer the phone","Press B to answer the phone",
    "[I]Yes Hello.",
    "[The women]Ah ... Hello, is this the counseling office?",
    "[The women]I am a teacher at an elementary school in Blacksburg, Virginia.",
    "[The women]Actually,there is a child who is being abused. Since this is a countryside, there is no office where you can consult. So I called here.",
    "[The women]On the contrary, I heard rumors that he didn't come to school and abuse was getting worse day by day.",
    "[I]I understand the requirements. Then, please tell us your current age, date and date.",
    "[The women]Well, it's June 13, 1949, why is the age and date?",
    "[I]Don't worry, it's just for recording, so later...",
    "I hung up the handset.",
    "[I]Around 1950, during the Cold War, it would be less noticeableand more comfortable.",
    "～June 14, 1949 ～",
    "[I]...It's hot, I'm sure there should be a children's house around here...",
    "[I]It's a house made of that rugged tree.Excuse me!!",
    "A child's mother-like person emerged from a door made of tattered wood.",
    "Excuse me, I'm dressed as Tsugihagi with a piece of cloth that suits my battered house.",
    "[Mother of the child]What are you doing? I'm busy right now.Do it later.",
    "[I]Actually, I would like to get a call from a courageous woman and talk about your child. Is it OK?",
    "[Mother of the child]What did my kid do?",
    "[I]No, you did something to your child.I'm actually a person from the future.",
    "[Mother of the child]?? If it's a religion, you can't lose it! I'm busy.",
    "[I]If you continue to abuse your child.In the near future you will be killed by your child.And that is the first murder for a child.",
    "[I]And later became a famous mass murderer in the United States!",
    "[Mother of the child]Don't say weird things without evidence",
    "[I]There is evidence.In a future article, you've been (again) abusing your son a few days later in this era and hitting the floor!",
    "[I]And killing your child's beloved donkey broke your child's heart.After that you will be killed by your child.",
    "[I]Apparently the donkey wasn't dead (yet) and I was able to see at school that your son's body had no bruises or injuries that could have been struck on the floor.",
    "[I]I'm here to advise you and change the future. So I advise you. Stop the abuse of your child and don't kill his beloved donkey.",
    "[Mother of the child]I would not want!。",
    "[Mother of the child]That child is mine.I don't know if it's the future,and I don't know who will die.",
    "[I]understood. Now, fight you to defeat you and reduce future casualties as much as possible.",
    "[Mother of the child]I'm really messed up. Hey you! Bring enough hatchets to chop up this young man!",
    "A father - like person in a wheelchair appeared from the back of the door.He has no legs and the bandage is soaked with blood.",
    "[Fother of the child]I discipline this guy. I cooperate, so please step on my foot and look down on me later. Please?",
    "[Mother of the child]Is it your usual play again ? ,,,It's okay. When I kill this fucking kid, I'll step on you a lot and give you a swearing voice.",
    "[Fother of the child]Oh, I can't wait, I got excited and got up... Let's do it.. Let's do it!",
    "A mother of a child with a hatchet and a father of a child in a wheelchair attacked.",

    //ここからは母親を殺した場合の会話
    "[Fother of the child] I killed my wife! This murderer!",
    "Hearing the noise, the child came out of the rag and stared at his dead mother.",
    "The child doesn't cry, but on the contrary, seems to laugh a little as if he was freed from something.",
    "[Fother of the child] Hey! Don't approach him! It's the murderer who killed my wife!",
    "The child who heard it stared at me and said,「 Thank you. 」 ",
    "[child] I can't beat anymore, and my animals won't be killed. I can go to school!",
    "When the child's father heard it, he ran his wheelchair crazy, distorting his face with tears, and left.",
    "[I] Hopefully I didn't want to kill your mother, but if you grew up with your mother as it is, you're in the future.",
    "[I] kills your mother with your own hands, and then meets a woman who loves you, but you also kills that woman and becomes a mass murderer who killed more people.",
    "[I] If I could change such a dire future, the actions of the female teacher who courageously called me would be rewarded.",
    "[child] Did the teacher call you? What do you mean I'll be a mass killer in the future?",
    "[I] Yes, I got a call from my teacher. Besides that, I often heard stories of abuse from truck drivers passing here.",
    "[I] couldn't help just by looking at you, but their brave actions saved you. You can't save your life without someone to snuggle up you.",
    "[I] There is only such a future for murderers, so don't worry.",
    "[I] And you will be living with your teacher from today. From now on, you can walk a new future with your teacher and school friends.",
    "[child] Really !! Do I have to stay here anymore? Are you really free? I did it!",
    "[I] Let's go see the teacher ...",
    "[I] No, wait ... isn't this really a murderer? Isn't it better to kill him all at once for the future?",
    "Trust this child with the A button.",
    "Kill this child with the X button.",
    //殺さなかった場合のその後
    "I found a letter of unknown address for decades.",
    "[I] What? The content of this sentence is ...",
    "[I] ... I'm glad. In the future, it seems that I lived leisurely in a small general store and died.",
    "[I] The courage and actions of the people who live in that era will change the future ... I hope more people still have the courage and actions ...",
    "                                       HAPPY END ",
    //殺した場合の未来
    "[I] This has changed the future, but was this really good?",
    "[I] At least there shouldn't be any incidents in the future.",
    "[I] Maybe there was a future that could have been done without killing that child ... I ...",
    "                                       HAPPY END ?",
    };//ここで文字を直接書いてるので、この文字のバイト数が各posmozi[]に入るだけ
    int frame2[100] = { 10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10
    ,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10 };//次の一文字が出るまでのカウンタとして働いている、ここの数値を変えることで文字が一文字ずつ出るまでの間隔を設定できる。
    int posmozi2[100];//文字のバイト数が入る箱を表している。
    int countS2[100];//次の文字が出るまでのカウントするためのもの
    int timetravel = 0;
    int z2;//関数drawString外でも使えるように外にも定義を書いた。zの数値は関係なく、文字列が入った数列がif文により同じ変数zの時にframe[z]と同じになるまで+1されていったり、+2バイトor+1バイトされていくため、
    //文字が一文字ずつ入っていく、なんでzの変数に値を入れて動かす必要がないのだ。ちなみにfor (z = 0; z < 3; ++z)で書いてしまうとキーAを押した際のif文に関係なく関数drawStringの最初のzどこかに値が入っただけで繰り返しを開始してしまうため、今回のように同じ変数zの時にフレームを利用して描画するようにした。
    char c2 = str2[z2][posmozi2[z2]];//関数drawString外でも使えるように外にも定義を書いた。


    void kaiwadrawString(int z2, int x2, int y2, int color)
    {
        char c2 = str2[z2][posmozi2[z2]];//posmozi[z]
        if (countS2[z2] == 0 && c2 != '\0')
            posmozi2[z2] += IsDBCSLeadByte(c2) ? 2 : 1;
        if (++countS2[z2] == frame2[z2]) countS2[z2] = 0;
        DrawFormatString(x2, y2, color, "%.*s", posmozi2[z2], str2[z2]);
        DrawFormatString(300, 300, RED, "countS2[0]は%d", countS2[0]);
    }
    int settoku1Handle = 0;
    int settokuSeen = 0;

    int settokubunnki = 0;

    int enemy2Image = 0;
    int enemy2Handle[1];

    int enemy2AHandle[1];

    int nanameidouX = 0;
    int nanameidouY = 0;
    int migiidou = 0;


    int anarogupadsave = 0;
    int anarogupadsave2 = 0;
    int RightTriggersave = 0;
    int RightTriggerosenai = 0;
    int anaroguidoulock = 0;

    int nikairennzokuframe = 0;
    int nikairennzokuframe2 = 0;
    int anaroguBOX = 0;

    int masusaveframe = 0;
    int masusaveframe2 = 0;
    int masuidou1X = 0;
    int masuidou1Y = 0;
    int motonomasunimodoru = 0;
    int tabakosuenai = 0;
    int tuikamasuidou = 0;

    int nanameidouX2 = 0;
    int nanameidouY2 = 0;
    int tuikaidouframe = 0;



    int suraidobyouga = 0;
    int suraidobyouga2 = 0;

    int playerattackhanndou2 = 0;

    int kougeki1 = 0;
    int kasurikeri = 0;

    int suraidobyouga3 = 0;
    int tuikaidouframe2 = 0;
    int tuikamasuidou2 = 0;
    int nanameidouX3 = 0;
    int nanameidouY3 = 0;
    int R1lockframe = 0;
    int R1lockcount = 0;
    int settokugamenntyuunohaikeiHandle = 0;
    int kotoba = 0;
    int hirumaselockframe = 0;
    int settokubunnkiframe = 0;
    int serekutobotanncount = 0;
    int settokubunnkiframe2 = 0;


    int settokutoumeikaframe = 0;
    int sentougoHandle = 0;
    int kaburulock = 0;
    int countimu = 0;
    int countimucount = 0;
    int countimuHandle = 0;
    int enemystartmove = 0;

    int enemytalk1Handle = 0;
    int enemytalk2Handle = 0;
    int enemytalk2 = 0;
    int countimubotanlock = 0;
    int battlebackHandle = 0;
    int LEFTbotannlock = 0;
    int UPbotannlock = 0;
    int DOWNbotannlock = 0;
    int tabakosutterulock = 0;
    int countmark = 0;

    int ModelHandle = 0;
    int Rbotanosenaiframe = 0;
    int Rbotanosenailock = 0;
    int komanndomark = 0;
    int soundM = 0;

    int  playerattackhanndou3 = 0;
    int talkhaikei = 0;
    int botanlock2 = 0;

    int handle = 0;
    int  enemygameGHandle[1];
    int enemyzannzoulockframe = 0;
    int jimenGHandle = 0;
    int Rbotunframe = 0;
    int kougekikannkaku = 0;
    int kougekikannkakulock = 0;//かすり攻撃の攻撃間隔のための変数
    int nagurugazoulock = 0;
    int Gunkirikae = 0;
    int RightTriggerlock = 0;


    int tekinoKOUGEKITYUUhahyouzisinailock = 0;

    int syunnkannidou = 0;
    int overattacklock = 0;
    int KABURIBAAIWAKElock = 0;
    int enemyattackinglock = 0;

    int suraidoidoukaisi = 0;
    int suraidoidoukaisiA = 0;
    int GenemysabunHPA = 0;
    int sousakanou = 0;//敵を倒す瞬間まで操作できるようにするために必要な変数。//※だけどタバコだけは戦闘後も吸えるようにしておいた。
    int nextattack = 0;//同時攻撃を防ぐための変数。
    int hinnsiattack = 0;//瀕死状態でもスライド攻撃できるようにするための変数。

    int toenemyHPdamage = 0;
    int kasanaruURA = 0;
    int tabakokasanari = 0;
    int recoverycount = 0;
    int tabakomark = 0;
    int tabakobyouga = 0;
    int kaunntacount = 0;
    int enemyattaking = 0;
    int notattacklock = 0;

    int ENEMYkougeki = 0;
    int houseModel = 0;

    int anotherenemysabunHP = 0, anotherenemysabunHPA = 0, AKenemysabunHP = 0, AGenemysabunHP = 0, AenemysabunHPB = 0, AGenemysabunHPA = 0;



    int playerattackhanndouB = 0;
    int playerattackhanndou2B = 0;
    int playerattackhanndou3B = 0;

    int enemy2[3];
    int enemyImage2 = 0;

    int enemy3[3];
    int enemyImage3 = 0;

    int playerKENJYUUImage = 0;
    int playerKENJYUU[5];


    int playernaguruBGHandle2[1];
    int playernaguruBGHandle3[1];

    int playerHPsubun = 0;
    int playerMove4 = 0;

    int taitolHandle[1];
    int taitolred = 0;
    int taitoitoumeika2 = 0;
    int taitollock = 0;

    int STAGE2ENEMY2kougekiA1Handle[1];
    int STAGE2ENEMY2kougekiB1Handle[1];
    int ranndamukougeki2 = 0;
    int ranndamulock2 = 0;
    int STAGE2ENEMY1kougekiA1Handle[1];
    int STAGE2ENEMY1hirumiHandle[1];
    int STAGE2ENEMY2hirumiHandle[1];
    int STAGE2ENEMY1kougekiB1Handle[1];

    int ENEMYmovelock2A = 0;

    int stayherelock2 = 0;

    int enemy1KENJYUUHandle[2];
    int enemyKENJYUUcount = 0;
    int playerHPsubunlock = 0;

    //ナイフ攻撃
    int naihu = 0;
    int naihuframe = 0;
    int naihuframe2 = 0;
    int naihukougeki = 0;
    int latertime = 0;
    int naihuHandle[1];
    int naihu2Handle[1];

    int KATANA[1];
    int KATANA2[1];
    int KATANA3A[1];
    int KATANA3[1];

    int SOKUSI = 0;

    int kikkuhanntenn[1];

    int keriwaza = 0;

    int conbocount = 0;
    int conbocountframe = 0;
    int conbosound = 0;
    int conbocounttime = 0;
    int keriwazakougeki = 0;



    int fortimeframe2 = 0;

    const char* str3[100] = { "[Mother of the child]Hmm ... Hmm ... It's a reluctant guy ...",
    "[I](I wonder if this will change the future a little, but it was a pretty formidable.)",
    "[Father of the child]Oh, it's too bad.",
    "The child's father fell down with his wheelchair.",
    "Hearing the noise, the child came out of the rag shopand stared at the lying fatherand the exhausted mother with her face down.",
    "[Mother of the child]Don't show it! Don't go home!",
    "I was looking in the eyes of a child",
    "Is this really okay ? Isn't this child abused by his mother?",
    "However, child's mather would have been a little disciplined in this battle. I believe in this child's mother and go home?",
    "I talked to child.",
    "[I]This is all right. It seems that your mother also reflected.",
    "[child]Don't go home! At this rate, my donkey will be killed!",
    "Surely, can a person who has been abusive until now be cured just by disciplining him? Should I kill child's mother?",
    "A button: Does not kill the mother.",
    "X button : Kill the mother.",
    "[I]No, let's believe in child's mother ...",
    "[I]The teachers and truck drivers who think of you called me here.Well then, be fine.",
    "I left the place. The kid just stares at me ...",
    "...",
    "......",
    "～ Several decades later ～",
    "[Rough-headed man in blue]I was able to kill some people today.",
    "[Bearded 0man in red]I had sex with the corpse of a woman and it was a good harvest!",
    "[Bearded man in red],,, No, it's still not enough. I want to fuck with some more!",
    "[Rough-headed man in blue]You had better stop, it's already morning. go home.",
    "[Bearded man in red]I'm sorry. What? Then, please divide the woman you killed a little? Isn't it still warm ? ",
    "[Rough-headed man in blue]Oh, I understand.",
    "Another man appeared in front of the two men.",
    "[I]It's been a long time. Apparently it was a mistake to believe in your mother. I'm really sorry.",
    "The shabby-headed man in blue was familiar to him. He was surprised why it was as it was at that time.",
    "[Rough-headed man in blue]Oh, you!? Is it the man at that time? !! Why are you here???",
    "[I]A woman who thinks of you called me and asked for help. I was asked to stop you.",
    "[Rough-headed man in blue]Is that woman ? That woman has nothing to do with me!.",
    "[I]Even if it doesn't matter, you're still killing people and necrophilia.",
    "[Bearded man in red]That's right. That's right.Then you can't keep it alive",
    "[Rough-headed man in blue]Wait a minute, why didn't you help me at that time?",
    "[Rough-headed man in blue]At that time,I was immatureand small,and I had no choice but to listen to my mother.No one helped me.",
    "[Rough-headed man in blue]You said you came all the way with the help of others, but you believed in my mother and you went home.",
    "[I]I'm really sorry. I thought I should give every human a chance. It's my mistake.",
    "[I]So help for your rehabilitation. please. Can you stop murdering anymore?",
    "[Rough-headed man in blue]It's even slower now. For me, murder is the same as breathing. And",
    "[Rough-headed man in blue]The woman does not have to exist. So if find it, kill it all. In short, I did something good.",
    "[Bearded man in red]Hahaha, the current words are numb!!",
    "[Rough-headed man in blue]I'm not going to stop murdering. If you stop, I'll kill you too!",
    "[Rough-headed man in blue]The donkey was killed and I became lonely because you returned without stopping my mother afterwards",
    "[Rough-headed man in blue]But now I've met my companions who need each other. The result was good.",
    "[Rough-headed man in blue]However, if you killed my mother at that time, I wouldn't have been abused after that! I hate you! !!",
    "[Bearded man in red]That's exactly what he says! It's a waste that abandoned his partner!Let's kill it!",
    "I regret my choice.At that time, if I had just killed his mother, it wouldn't have happened.",
    "[I]all right. It's all my responsibility. Come on!",
    "Two big men attacked ...",

        //諦めて殺した場合。
        "[Bearded man in red]you!You often killed my buddy ...",
        "[I]I had no choice but to do this so as not to cause any further damage.I'm sorry.",
        "I don't have the power to change or save people ... I have a heavy head. I'm suffocating.Let's go home ...",
        "[Bearded man in red]Hey! Wait! Hey!!",
        "I tried to leave the place. However, it was the moment when i turned my back on the man in red.",
        "...I was lying ... Warm things overflow from my body ...",
        "The consciousness goes away ... Oh ... so far ...",
        "...............",
        "                                       BAD END ",
        "Would you like to start over from the scene of fighting the duo ? Or do you want to end it like this ? ",
        "Button A : Continue.",
        "Button X: It end.",
    };//ここで文字を直接書いてるので、この文字のバイト数が各posmozi[]に入るだけ
    int frame3[100] = { 10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
    10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,
    10,10,10,10,10 };//次の一文字が出るまでのカウンタとして働いている、ここの数値を変えることで文字が一文字ずつ出るまでの間隔を設定できる。
    int posmozi3[100];//文字のバイト数が入る箱を表している。
    int countS3[100];//次の文字が出るまでのカウントするためのもの

    int z3;//関数drawString外でも使えるように外にも定義を書いた。zの数値は関係なく、文字列が入った数列がif文により同じ変数zの時にframe[z]と同じになるまで+1されていったり、+2バイトor+1バイトされていくため、
    //文字が一文字ずつ入っていく、なんでzの変数に値を入れて動かす必要がないのだ。ちなみにfor (z = 0; z < 3; ++z)で書いてしまうとキーAを押した際のif文に関係なく関数drawStringの最初のzどこかに値が入っただけで繰り返しを開始してしまうため、今回のように同じ変数zの時にフレームを利用して描画するようにした。
    char c3 = str3[z3][posmozi3[z3]];//関数drawString外でも使えるように外にも定義を書いた。


    void kaiwadrawString3(int z3, int x3, int y3, int color)
    {
        char c3 = str3[z3][posmozi3[z3]];//posmozi[z]
        if (countS3[z3] == 0 && c3 != '\0')
            posmozi3[z3] += IsDBCSLeadByte(c3) ? 2 : 1;
        if (++countS3[z3] == frame3[z3]) countS3[z3] = 0;
        DrawFormatString(x3, y3, color, "%.*s", posmozi3[z3], str3[z3]);
        DrawFormatString(300, 300, RED, "countS3[0]は%d", countS3[0]);
    }

    int Seenlock2 = 0;

    int tuikaidouframe3 = 0, tuikamasuidou3 = 0, suraidobyouga4 = 0;
    int  nanameidouX4 = 0, nanameidouY4 = 0;
    int tuikaidouframe4 = 0, tuikamasuidou4 = 0, suraidobyouga5 = 0;
    int  nanameidouX5 = 0, nanameidouY5 = 0;
    int  playeridouA5Handle[1];
    int tuikaidouframe5 = 0, tuikamasuidou5 = 0, suraidobyouga6 = 0;
    int  nanameidouX6 = 0, nanameidouY6 = 0;
    int playergardGHandle[1];
    int gardframe = 0;

    int mozimark = 0;
    int douziosicount = 0;

    int playerdamegeGHandle[1];
    int enemy2damegeHandle[1];
    int enemy3damegeHandle[1];

    int old_trailerHandle = 0;
    int poleModel = 0;
    int enemydamegeHandle[1];
    int byouga = 0;

    //画像
    int dennwa = 0;
    int firudoModel = 0;
    int kericount = 0;
    int enemybyougablock2 = 0;
    int taitol2Handle[1];
    int taitolred2 = 0;
    int taitollock2 = 0;

    int Seenframe2 = 0;
    int end = 0;
    int kodomogif = 0;
    int kodomo = 0;

    //赤い四角
    int Red = 0; // 赤色の値を取得
    int Bule = 0;
    int redbrad = 0;
    int redbrad2 = 0;

    float ugokuX = 0;
    float ugokuX2 = 0;
    int Seenframe3 = 0;
    int Seenframe4 = 0;
    int kurumaisucount = 0;
    int sakebi = 0;
    int stage2frame = 0;


    int settokuSeen2 = 0;
    int playerboxX = 0;
    int playerboxY = 0;

    //int enemyhanntoumei = 0;
    int enemyhanntoumei2 = 0;
    int enemy1HPgage = 0;
    int enemy2HPgage = 0;

    int ranndamukougeki3 = 0;
    int ranndamukougeki4 = 0;
    int ranndamukougeki5 = 0;
    int stage2sound = 0;
    int  kaiwasound1 = 0;
    int  taitolsound = 0;
    int wakaresound = 0;
    int yokeru = 0;
    int yokeruframe = 0;
    int stage2haikeiHandle = 0;


    int killer = 0;
    int killerframe = 0;
    int taitolhaikeiHandle = 0;
    int taitolhaikei = 0;

    //戦闘ちゅうのBGM
    int ranndamuBGM = 0;
    int waraigoesound = 0;
    int waraigoesound2 = 0;
    int kodomokorositasound = 0;

    int settokubunnkiframe3 = 0;
    int daburukiller = 0;
    int killer2 = 0;
    int Seenlock3 = 0;


    int  enemylock = 0;
    //int marklock = 0;
    int lockmark2 = 0;
    int menyframe = 0;
    int dennwanaru = 0;
    int talkhaikei2 = 0;
    int dennwanaruframe = 0;
    int stage1haikeiHandle = 0;


    int RIGHTkey = 0;
    int LEFTkey = 0;
    int UPkey = 0;
    int DOWNkey = 0;
    int migiaruku = 0;
    int migiarukugazou[1];
    int migiaruku2gazou[1];
    int hidariaruku = 0;
    int hidariarukugazou[1];
    int hidariaruku2gazou[1];
    int sitaaruku = 0;
    int sitaarukugazou[1];
    int sitaaruku2gazou[1];

    int nanamekey = 0;
    int nanamearuku = 0;

    int uearuku = 0;
    int  uearukugazou[1];
    int  uearuku2gazou[1];
    int syuzinnkouyokeru = 0;
    int syuzinnkouyokeruframe = 0;
    int syuzinnkouyokerugazou[1];
    int syuzinnkouyokerugazou2[1];

    int syuzinnkouyokerulock = 0;
    int idoulock = 0;
    int kaitennmigiidou = 0;
    int kaitennhidariidou = 0;
    int migikomanndo = 0;
    int kaihilock = 0;
    int jyuukougeki = 0;
    int hidarikomanndo = 0;
    int yokkerucouunt2 = 0;

    int syuzinnkouyokerulock2 = 0;//下の条件でのnanameidouX1～3が0にならないように1にする。
    int syuzinnkouyokeru2 = 0;
    int syuzinnkouyokeruframe2 = 0;

    int huttobu = 0;
    int huttobuframe = 0;
    int enemysabunHPpoint = 0;
    int huttobu2 = 0;
    int huttobu2frame = 0;
    int enemy2sabunHPpoint = 0;


    int playerHandle2[3];
    int hidarimukiframe = 0;
    int kaitenn = 0;
    int kaitennframe = 0;
    int kaitenncount = 0;
    int kaitenn2 = 0;
    int kaitennframe2 = 0;
    int kaitenncountframe = 0;

    int  playeridouAhidariHandle[1];
    int  playeridouA4hidariHandle[1];
    int  playeridouA2hidariHandle[1];
    int  playeridouA3hidariHandle[1];
    int  playeridouA5hidariHandle[1];
    int kaitenncountframe2 = 0;
    int kaitenncount2 = 0;

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

    int MARK = 0;
    //int contorora = 0;

    int kaunntacount2 = 0;
    int marklock = 0;
    int mark2lock = 0;
    //int DAMEGEframe = 0;

    int toumeika2 = 0;
    int toumeika1 = 0;
    int enemygazoukesu1 = 0;
    int enemygazoukesu2 = 0;
    int killerlock = 0;

    int syuzinnkoutoumeika = 0;
    int syuzinnkoutoumeikalock = 0;
    int syuzinnkoutoumeikalock2 = 0;
    int gameovercolor2lock = 0;

    int enemyattackaizu = 0;
    int enemyattackaizu2 = 0;

    int Rbotun = 0;
    int DrawBoxbyouga = 0;
    int enemy2hirumaseframelock = 0;

    int  stage2damage = 0;

    int point = 0;
    int point2 = 0;
    int kakuninn = 0;
    int tyokusennkougeki = 0;

    int a, b, h, d, e = 0;
    int Gtimelock = 0;

    int rockon = 0;
    int lockFrame = 0;
    int enemyattackblock = 0;
    int anotherenemyattackblock = 0;
    int LEFTmark2 = 0;
    int  KATANA3B1[1];


private:  //自分のクラスでしか使えないもの

    void InitStage();
};