#include "DxLib.h"
#include "talk.h"
#include "Player/playerhensuuVr2.h"

#ifndef COUNTINE_H //二重include防止

#define COUNTINE_H

void countinuekannsuu() {

	// アナログノイズムービーを描画にします
	DrawExtendGraph(0, 0, 1770, 980, anarogunoizuGraphHandle, TRUE);

	DrawFormatString(100, 100, RED, "主人公は死んでしまった");
	DrawFormatString(100, 250, GetColor(255, 255, 255), "GAME COUNTINE?");
	talk = 3;
	DrawFormatString(100, 350, GetColor(255, 255, 255), "AボタンでCOUNTINE");
	//if (Key[KEY_INPUT_A] == 1) { talk = 3; }//キーAを押してもtalkが増えないように3のままになるようにした。
	if (countimubotanlock == 0) {
		if (Pad[PAD_1] == 1) {
			countimu = 1;

		}
	}
	if (countimu > 0) {
		++countimucount;

		// アナログノイズムービーを描画にします
		DrawExtendGraph(0, 0, 1770, 980, countimuHandle, TRUE);
	}
	if (countimu > 0 && countimu < 200) {
		playerkonntororulock = 1;
		
	}
	if (countimucount > 200) {
		ENEMYkougekigazouA1frame = 0;
		ENEMYkougekigazouA2frame = 0;
		playerkonntororulock = 0;
		gameovercolor = 0;//Seen=2に戻れるが、描画されたものはそのままなのでここでgameovercolorの値を0にしする必要がある。
		//255のままではtest.cpp(メインプログラムに書いてある)のif (gameovercolor >= 255)の条件に引っ掛かったままで、このif文が呼び出す関数countinuekannsuu()の
		//DrawExtendGraph(0, 0, 1770, 980, anarogunoizuGraphHandle, TRUE);が働いてしまい、ずっと描画されてしまうので、gameovercolorの値を0にしする必要がある。
		countimubotanlock = 1;
		playerHP = 600;
		enemyHP = 800;
		BGMlock = 1;//コンティニューする際に電話がならないように
		//imagecount = 0; enemyattack3 = 0; enemyimagecount = 0;//敵の攻撃をリセットしないと復活した際に途中攻撃が発生するのでここで書いておく。
		//imagecount2 = 0; enemyattack4 = 0; enemyimagecount2 = 0;
		//imagecount3 = 0; enemyattack5 = 0; enemyimagecount3 = 0;
		countimucount = 0;
		countimu = 0;
		//enemystartmove = 1;
		talk = 3;//talkが2の時にenemytalk2が繰り上がらないように。
		Seen = 2;
		stayhere3 = 0;//stayhereにおいてはstage1.hに続く。

		//死んだ後で復活した際に敵の攻撃を直前で食らわないようにここで元の位置に戻す。
		nanameidouX = 0;//元の位置に戻った後も主人公の描画にはnanameidouXやYを考慮しているため、0にする必要がある。
		nanameidouY = 0;
		nanameidouX2 = 0;
		nanameidouY2 = 0;
		nanameidouX3 = 0;
		nanameidouY3 = 0;
		migiidou = 0;
		motonomasunimodoru = 0;

		//★戦闘中を表すstgae1Player_Update.hとかで強制的にstayhereを1にすると死んだ直前で敵からの攻撃が止まったままになってしまい連続で攻撃を食らうような状態になってしまう。
		//なので戦闘中を表すヘッダファイルではないここに1と書けば、描画する部分のヘッダファイルに書いた★敵の初期位置のおかげで強制的に初期位置に戻されるので途中攻撃の連続で攻撃を受けないのだと思う。
		stayherelock = 0;
		snow = 1;
		enemyHPhyouji = 1;

		zannzoulock = 0;
		enemystayhere = 0;//書いている分に問題はないがバグのせいか、コンティニューするさいにenemystayhereが1のままになり敵が描画されないことがあるので、念のためにここで0に戻す。
		//説得するための関数の変数を初期に戻す。途中で死んだ場合説得の変数がそのままでコンティニュー後に再び説得できないので。
		serekutobotanncount = 0;
		settokuSeen = 0;
		settokubunnki = 0;
		settokubunnkiframe = 0;
		settokubunnkiframe2 = 0;

		playerHPlock = 0;
		syuzinnkoutoumeikalock = 0;
		
	}
	//★playerHPが1未満になっていたためゲームオーバーのままだった。
	//ゲームオーバーの条件が成り立つ条件を考えたほうが良かった。解決するために関数を呼んだが、関数にはplayerHPの初期値は含んでいないのでプレイヤーのHPが1未満で
	//ゲームオーバーのままだったのだろう。
	//if (Key[KEY_INPUT_N] == 1) {
	//	talk = 4; imagecount = 0; enemyattack3 = 0; enemyimagecount = 0;//敵の攻撃をリセットしないと復活した際に途中攻撃が発生するのでここで書いておく。
	//	imagecount2 = 0; enemyattack4 = 0; enemyimagecount2 = 0;
	//	imagecount3 = 0; enemyattack5 = 0; enemyimagecount3 = 0;
	//}//キーを条件として関数を呼んでもキーを押した一瞬しか描画されないので下のようにif文で変数の固定値でループするしかない。
	//if (talk == 4) { talkdrow2(); countinue = 0; }
	//キーNを押した場合はtalk.hの関数に飛ぶようにすればいい。

	
}

void countinuekannsuu2() {

	// アナログノイズムービーを描画にします
	DrawExtendGraph(0, 0, 1770, 980, anarogunoizuGraphHandle, TRUE);

	DrawFormatString(100, 100, RED, "主人公は死んでしまった");
	DrawFormatString(100, 250, GetColor(255, 255, 255), "GAME COUNTINE?");
	//talk = 3;
	DrawFormatString(100, 350, GetColor(255, 255, 255), "AボタンでCOUNTINE");
	//if (Key[KEY_INPUT_A] == 1) { talk = 3; }//キーAを押してもtalkが増えないように3のままになるようにした。
	if (countimubotanlock == 0) {
		if (Pad[PAD_1] == 1) {
			countimu = 1;

		}
	}
	if (countimu > 0) {
		++countimucount;

		// アナログノイズムービーを描画にします
		DrawExtendGraph(0, 0, 1770, 980, countimuHandle, TRUE);
	}
	if (countimu > 0 && countimu < 200) {
		playerkonntororulock = 1;
	}
	if (countimucount > 200) {
		ENEMYkougekigazouA1frame = 0;
		ENEMYkougekigazouA2frame = 0;
		playerkonntororulock = 0;
		gameovercolor2 = 0;//Seen=2に戻れるが、描画されたものはそのままなのでここでgameovercolorの値を0にしする必要がある。
		//255のままではtest.cpp(メインプログラムに書いてある)のif (gameovercolor >= 255)の条件に引っ掛かったままで、このif文が呼び出す関数countinuekannsuu()の
		//DrawExtendGraph(0, 0, 1770, 980, anarogunoizuGraphHandle, TRUE);が働いてしまい、ずっと描画されてしまうので、gameovercolorの値を0にしする必要がある。
		countimubotanlock = 1;
		playerHP = 600;
		enemy1HP = 1500;
		enemy2HP = 1200;
		BGMlock = 1;//コンティニューする際に電話がならないように
		//imagecount = 0; enemyattack3 = 0; enemyimagecount = 0;//敵の攻撃をリセットしないと復活した際に途中攻撃が発生するのでここで書いておく。
		//imagecount2 = 0; enemyattack4 = 0; enemyimagecount2 = 0;
		//imagecount3 = 0; enemyattack5 = 0; enemyimagecount3 = 0;
		countimucount = 0;
		countimu = 0;
		//enemystartmove = 1;
		//talk = 3;//talkが2の時にenemytalk2が繰り上がらないように。
		Seen = 300;
		//stayhere = 0;//stayhereにおいてはstage1.hに続く。

		//死んだ後で復活した際に敵の攻撃を直前で食らわないようにここで元の位置に戻す。
		nanameidouX = 0;//元の位置に戻った後も主人公の描画にはnanameidouXやYを考慮しているため、0にする必要がある。
		nanameidouY = 0;
		nanameidouX2 = 0;
		nanameidouY2 = 0;
		nanameidouX3 = 0;
		nanameidouY3 = 0;
		migiidou = 0;
		motonomasunimodoru = 0;

		//★戦闘中を表すstgae1Player_Update.hとかで強制的にstayhereを1にすると死んだ直前で敵からの攻撃が止まったままになってしまい連続で攻撃を食らうような状態になってしまう。
		//なので戦闘中を表すヘッダファイルではないここに1と書けば、描画する部分のヘッダファイルに書いた★敵の初期位置のおかげで強制的に初期位置に戻されるので途中攻撃の連続で攻撃を受けないのだと思う。
		stayherelock3 = 0;
		snow = 1;
		enemyHPhyouji = 1;

		zannzoulock = 0;
		enemystayhere = 0;//書いている分に問題はないがバグのせいか、コンティニューするさいにenemystayhereが1のままになり敵が描画されないことがあるので、念のためにここで0に戻す。
		//説得するための関数の変数を初期に戻す。途中で死んだ場合説得の変数がそのままでコンティニュー後に再び説得できないので。
		serekutobotanncount = 0;
		settokuSeen = 0;
		settokubunnki = 0;
		settokubunnkiframe = 0;
		settokubunnkiframe2 = 0;
		playerHPlock = 0;

		stayhere = 0;
		stayhere2 = 0;
		playerkonntororulock3 = 0;
		
		aa = 0;
		bb = 0;

		syuzinnkoutoumeikalock2 = 0;
		playerX = 1;
		playerY = 1;

		enemyX1 = 4;
		enemyY1 = 1;

		//enemyX2 = 5;
		//enemyY2 = 2;

		playerHPhyouzi = 0;
	}
	//★playerHPが1未満になっていたためゲームオーバーのままだった。
	//ゲームオーバーの条件が成り立つ条件を考えたほうが良かった。解決するために関数を呼んだが、関数にはplayerHPの初期値は含んでいないのでプレイヤーのHPが1未満で
	//ゲームオーバーのままだったのだろう。
	//if (Key[KEY_INPUT_N] == 1) {
	//	talk = 4; imagecount = 0; enemyattack3 = 0; enemyimagecount = 0;//敵の攻撃をリセットしないと復活した際に途中攻撃が発生するのでここで書いておく。
	//	imagecount2 = 0; enemyattack4 = 0; enemyimagecount2 = 0;
	//	imagecount3 = 0; enemyattack5 = 0; enemyimagecount3 = 0;
	//}//キーを条件として関数を呼んでもキーを押した一瞬しか描画されないので下のようにif文で変数の固定値でループするしかない。
	//if (talk == 4) { talkdrow2(); countinue = 0; }
	//キーNを押した場合はtalk.hの関数に飛ぶようにすればいい。
}

#endif