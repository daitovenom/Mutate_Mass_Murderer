#include "DxLib.h"
#include "key.h"
#pragma warning(disable: 4996)

//#include "taitolh.h"
#ifndef DEF_talk_H //二重include防止

#define DEF_talk_H



void syokiiti() {
	int enemyX = 4, enemyY = 1;   // 敵の位置
	int playerX = 1, playerY = 1;  // 俺の位置

}

void talkdrow() {
	//talkhaikei = 1;
	if (BGMlock == 0) { ++BGM1; }
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
	if (botanlock == 0) {
		if (Pad[PAD_2] == 1) {
			++talk;
		}
	}
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
			talkhaikei = 2;//一旦他の背景に移る。
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
		talkhaikei = 0;//背景が戻る。

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

	if (talkhaikei == 0 && dennwalock == 1 && talkend == 0) {
		// 描画する文字列のサイズを設定
		//SetFontSize(28);
		kaiwadrawString(0, 100, 500, Cr);//電話がかかってきた
		kaiwadrawString(1, 100, 600, RED);//電話に出る
		kaiwadrawString(2, 100, 700, RED);//電話に出ない
		//PlayMovieToGraph(dennwaHandle);
		//DrawExtendGraph(0, 0, 870, 780, dennwaHandle, FALSE);
		//電話に出る
		if (Pad[PAD_2] == 1) {
			talkhaikei = 1;
			kaiwasound1 = LoadSoundMem("チャイコフスキー『10月・秋の歌』（楽譜付き）.mp4");
			ChangeVolumeSoundMem(120, kaiwasound1);//この関数によって音声のボリュームを設定できる。
			PlaySoundMem(kaiwasound1, DX_PLAYTYPE_BACK);
		}
		//電話に出ない
		if (Pad[PAD_1] == 1) {
			talkhaikei = 0;
		}
	}
	if (talkhaikei == 1) {
		botanlock2 = 1;
		StopSoundMem(sound4);//★BGMを途中で止めるための関数
		 // 文字列の描画
		mozibyougaframe = 0;
		BGM1 = 11;//繰り上がったりしても電話の音が鳴らないように11にした。//まあ値が増え続けても問題はないが念のために11にしておく。
		//DrawString(100,400, "(主人公)", RED);
		//if (talk == 0 && posmozi[0] == 9) { if (Pad[PAD_2] == 1) { talk=1; } }//talkdorwの時にstr1.drawStringが呼ばれているのでこの中身のものも実行されても大丈夫なのでは？
		//上のif文if (talk == 0 && posmozi[0] == 9)がなくても文字は描画できるif (talk == 0) でdrawString(0, 100, 500, Green);が{}に書いてあれば、
		//というのも関数drawString自体の一番目のzとした引数の値が文字列の入る箱の番号を表すように作ったためだ。 間違っていた前のプログラムではposmozi[0] == 9と書いていたためposmozi[0]は10であったためif文を通らなかったのだろう。
		//drawString(0, 100, 500, RED);//引数は上に作った関数より文字列の入る箱の番号、x軸、y軸と色である。

			// ムービーを再生状態にします
		//PlayMovieToGraph(vioraHandle);
		//PlayMovieToGraph(enemytalk1Handle);
		//++enemytalk;

		DrawExtendGraph(242, 0, 1127, 580, dennwa, FALSE);
		PlayMovieToGraph(dennwa);
		//DrawExtendGraph(242, 0, 1127, 580, enemytalk1Handle, FALSE);
		// 画面左上に再生時間を描画します
		//DrawFormatString(0, 0, GetColor(255, 255, 255), "Time:%d", TellMovieToGraph(enemytalk1Handle));
		if (talk == 1) {
			kaiwadrawString(3, 100, 600, RED);//はい、もしもし
		}
	}

	if (talk == 2) {
		kaiwadrawString(4, 100, 600, RED);//あ、、、、もしもし、こちら相談所でしょうか？

	}
	if (talk == 3) {
		kaiwadrawString(5, 100, 600, RED);//私は教師です。

	}
	if (talk == 4) {
		kaiwadrawString(6, 100, 600, RED);//家庭に相談した。

	}
	if (talk == 5) {
		kaiwadrawString(7, 100, 600, RED);//日に日に虐待もひどくなっています。

	}
	if (talk == 6) {
		kaiwadrawString(8, 100, 600, RED);//日に日に虐待もひどくなっています。

	}
	if (talk == 7) {
		kaiwadrawString(9, 100, 600, RED);//日に日に虐待もひどくなっています。

	}
	if (talk == 8) {
		kaiwadrawString(10, 100, 600, RED);//日に日に虐待もひどくなっています。

	}
	if (talk == 9) {
		kaiwadrawString(11, 100, 600, RED);//受話器を置いた

	}
	if (talk == 10) {
		kaiwadrawString(12, 100, 600, RED);//受話器を置いた
		++timetravel;
		botanlock = 1;
		StopSoundMem(kaiwasound1);//★BGMを途中で止めるための関数
		talkhaikei = 0;//女性教師の画像を消す。
		talkend = 1;//電話を出るか出ないかの文字をを描画しないための変数。

	}
	if (timetravel > 400) {
		talk == 11;
		timetravel = 400;
		botanlock = 0;

	}
	if (talk == 11 && timetravel == 400) {
		kaiwadrawString(13, 100, 600, RED);//1949年

	}
	if (talk == 12) {
		kaiwadrawString(14, 100, 600, RED);//家を探す

	}
	if (talk == 13) {
		kaiwadrawString(15, 100, 600, RED);//家見つかる

	}
	if (talk == 14) {
		kaiwadrawString(16, 100, 600, RED);//ドアが開く

	}
	if (talk == 15) {
		kaiwadrawString(17, 100, 600, RED);//母親の服装

	}
	if (talk == 16) {
		kaiwadrawString(18, 100, 600, RED);//母親登場

	}
	if (talk == 17) {
		kaiwadrawString(19, 100, 600, RED);//母親登場

	}
	if (talk == 18) {
		kaiwadrawString(20, 100, 600, RED);//母親登場

	}
	if (talk == 19) {
		kaiwadrawString(21, 100, 600, RED);//母親登場

	}
	if (talk == 20) {
		kaiwadrawString(22, 100, 600, RED);//母親登場

	}
	if (talk == 21) {
		kaiwadrawString(23, 100, 600, RED);//母親登場

	}
	if (talk == 22) {
		kaiwadrawString(24, 100, 600, RED);//母親登場

	}
	if (talk == 23) {
		kaiwadrawString(25, 100, 600, RED);//母親登場

	}
	if (talk == 24) {
		kaiwadrawString(26, 100, 600, RED);//母親登場

	}
	if (talk == 25) {
		kaiwadrawString(27, 100, 600, RED);//母親登場

	}
	if (talk == 26) {
		kaiwadrawString(28, 100, 600, RED);//母親登場

	}
	if (talk == 27) {
		kaiwadrawString(29, 100, 600, RED);//母親登場

	}
	if (talk == 28) {
		kaiwadrawString(30, 100, 600, RED);//母親登場

	}
	if (talk == 29) {
		kaiwadrawString(31, 100, 600, RED);//未来のことなんて知ったこっちゃない。

	}
	if (talk == 30) {
		kaiwadrawString(32, 100, 600, RED);//未来のことなんて知ったこっちゃない。

	}
	if (talk == 31) {
		kaiwadrawString(33, 100, 600, RED);//未来のことなんて知ったこっちゃない。

	}
	if (talk == 32) {
		kaiwadrawString(34, 100, 600, RED);//未来のことなんて知ったこっちゃない。

	}
	if (talk == 33) {
		kaiwadrawString(35, 100, 600, RED);//未来のことなんて知ったこっちゃない。

	}
	if (talk == 34) {
		kaiwadrawString(36, 100, 600, RED);//未来のことなんて知ったこっちゃない。

	}
	if (talk == 35) {
		kaiwadrawString(37, 100, 600, RED);//未来のことなんて知ったこっちゃない。

	}
	if (talk == 36) {
		kaiwadrawString(38, 100, 600, RED);//未来のことなんて知ったこっちゃない。

	}

	//if (enemytalk == 3150) {
	//	talk = 2;//talkが1の時にenemytalkが繰り上がらないように。
	//	enemytalk = 3150;
	//}
	if (talk == 37) {
		PlayMovieToGraph(enemytalk2Handle);

		DrawExtendGraph(242, 0, 1127, 780, enemytalk2Handle, FALSE);
		++enemytalk2;
	}
	if (enemytalk2 == 100) {
		mark = 1;//★★★talkが3の時はキーAが押せないように変数で条件を付けた。編集前は上のif (Key[KEY_INPUT_A] == 1)と被ってしまって重複したためかうまく機能しなかった。
		//stayhereを使ってのプログラムもあったが、関数の外のメインにあったためかif (Key[KEY_INPUT_A] == 1)が働かなかったのか、一定のままだった。しかし出来れば関数内でまとめたいので左のように書いた。
		//BGMstart1 = 1;

			//DrawFormatString(300, 300, RED, "battle startします");
		//syokiiti();//
		//enemymovelock = 1;//この間は敵が動かないようにenemymovelockを1にしたplayer2.hの敵の攻撃や移動の部分より
		 //キーAを押してもAがtalkが増えないように書いた。Player_Update()はSeen = 1により呼ばれるのでtalkの値に関係がないように書いたのでtalkの値に関係ない。なのでtalkが上がってもif (start == 200)により戦闘画面は出てこない。


		//ChangeVolumeSoundMem(100, sound3);//この関数によって音声のボリュームを設定できる。
		//PlaySoundMem(sound3, DX_PLAYTYPE_LOOP, FALSE);
	}
	//一瞬敵が動くためスタートして戦闘画面がでてから上のif文の変数startのあまりのフレーム経ったらenemymovelock = 0になるように直した。
	if (enemytalk2 > 200) {
		talk = 4;//talkが2の時にenemytalk2が繰り上がらないように。
		Seen = 2; stayhere = 1;//stayhereにおいてはstage1.hに続く。
		mark = 0; //まだ解決していない　init_stage();は自分と敵の初期化のための関数だが、
		stayherelock = 0; snow = 1;
		enemyHPhyouji = 1;
		botanlock = 0;
		enemytalk2 = 200;
		//こいつがうまく働かないせいで敵が動き回っている状態でバトルが開始するのだろう。しかしvoid Player_Update()の中にはinit_stage()は書いている。
	}
	//戦闘開始前にボタンを押して会話画面に戻らないようにするための部分
	if (enemytalk > 0 && enemytalk < 2900) {
		botanlock = 1;
	}
	if (enemytalk2 > 0 && enemytalk2 < 500) {
		botanlock = 1;
	}
	return;
}

#endif