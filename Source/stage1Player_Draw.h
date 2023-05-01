#include "Player/playerhensuuVr2.h"
#include "sennkounyuuryokujyuujiki.h"
#include "syuzinnkouKOUGEKI.h"
#include "settoku.h"
#include "suraidoidoubyouga.h"
#include "kasurikougeki.h"
#include "syuzinnkouDAMEGIjyoutai.h"
#include "syuzinkoukougekigazou.h"
#include "syuzinnkouKENJYUU.h"
#include "aruku.h"

#ifndef DEF_STAGE1PLAYER_DRAW_H //二重include防止

#define DEF_STAGE1PLAYER_DRAW_H
//★★ヘッダファイルと関数について。
//多分、関数stage1PlayerDraw()を呼ぶ際にここにもstage1.hを書くとstage1.hに書いてある関数stage1PlayerDraw()を呼んでしまい、二重になるため、
//このヘッダファイルにはstage1.hを書くとエラーが出る。それ以外のヘッダファイルは書く意味はないが、もし書いたとしてもエラーにはならないだろう。


void stage1PlayerDraw() {


	if (gamenidou == 0) {
		
		
		DrawExtendGraph(0, 0, 1470, 480, stage1haikeiHandle, FALSE);



		// ムービー映像を、背景を画面いっぱいに描画します
		//DrawExtendGraph(327, 348, 1173, 100, MovieGraphHandle, FALSE);

		//雪の降る演出のための部分
		//if (snow == 1) {
		//	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 70);		//ブレンドモードをα(128/255)に設定
		//	DrawExtendGraph(0, 0, 1770, 980, snowGraphHandle, FALSE);
		//}
		//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをリセット（他の画像が薄くならないようにするため）	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - toumeika);		//ブレンドモードをα(128/255)に設定




			//画面に映る位置に３Ｄモデルを移動
		MV1SetPosition(houseModel, VGet(-300, 100, 4500.f));
		//第二引数の回転角度をセット
		MV1SetRotationXYZ(houseModel, VGet(0, 100.0, 00.0f));//縦向きの角度、横向きの角度、全体を回す的な角度//整数だと調節が難しいので、小数点で調節する。
		// ３Ｄモデルの描画
		MV1DrawModel(houseModel);
		// モデルハンドルの削除
		//MV1DeleteModel(houseModel);

				//画面に映る位置に３Ｄモデルを移動
		MV1SetPosition(jimenGHandle, VGet(741, 375, -526));
		//第二引数の回転角度をセット
		MV1SetRotationXYZ(jimenGHandle, VGet(0, 1.56999, 0));//縦向きの角度、横向きの角度、全体を回す的な角度//整数だと調節が難しいので、小数点で調節する。

		// ３Ｄモデルの描画
		MV1DrawModel(jimenGHandle);
		// モデルハンドルの削除

		// ウエイトをかけます、あまり速く描画すると画面がちらつくからです
		WaitTimer(0);//この部分の数値を上げると敵の攻撃が遅くなる。
		// ステージの描画 　★function_status == 0の場合ではないし、0か1の二択しかため、function_statusの初期値は1であるためif (function_status == 0)は除外されelseの方が描画される。
		int stageColor = GetColor(160, 64, 64);
		int stageColor2 = GetColor(50, 164, 164);
		//DrawLine(stage[0][0][0], stage[0][0][1],
		//	stage[0][6][0], stage[0][6][1], stageColor, 10);
		//DrawLine(stage[0][3][0], stage[0][3][1],
		//	stage[0][6][0], stage[0][6][1], stageColor2, 10);
		for (int i = 0; i < 4; i++)
			DrawLine(stage[i][0][0], stage[i][0][1],
				stage[i][6][0], stage[i][6][1], stageColor, 3);//座標stage[0][0][0],stage[0][0][1]から縦の方に座標stage[0][6][0],stage[0][6][1]の間の線を引く
		for (int i = 0; i < 4; i++)
			DrawLine(stage[i][3][0], stage[i][3][1],
				stage[i][6][0], stage[i][6][1], stageColor2, 3);//座標stage[0][0][0],stage[0][0][1]から縦の方に座標stage[0][6][0],stage[0][6][1]の間の線を引く

		for (int j = 0; j < 4; j++)
			DrawLine(stage[0][j][0], stage[0][j][1],
				stage[3][j][0], stage[3][j][1], stageColor, 3);//stage[0][0][0],stage[0][0][1]から横の方に座標stage[3][0][0],stage[3][0][1]の間の線を引く

		for (int j = 4; j < 7; j++)
			DrawLine(stage[0][j][0], stage[0][j][1],
				stage[3][j][0], stage[3][j][1], stageColor2, 3);//stage[0][0][0],stage[0][0][1]から横の方に座標stage[3][0][0],stage[3][0][1]の間の線を引く
		//ステージの一番下の両方の太い線の部分のプログラム。
		DrawLine(stage[3][0][0], stage[3][0][1] + 13,
			stage[3][3][0], stage[3][3][1] + 13, stageColor, 10);
		DrawLine(stage[3][3][0], stage[3][3][1] + 13,
			stage[3][6][0], stage[3][6][1] + 13, stageColor2, 10);
		//ステージの中心の太い線の部分のプログラム。
		DrawLine(stage[0][3][0] - 3, stage[0][3][1],
			stage[3][3][0] - 3, stage[3][3][1], stageColor, 3);
		DrawLine(stage[0][3][0] + 3, stage[0][3][1],
			stage[3][3][0] + 3, stage[3][3][1], stageColor2, 3);


		if (nomalidou == 0) {

			//右コマンドの残像//原因はif (zannzou < 1) {zannzou = 0; zannzoulock = 0;}の部分でした。if (zannzou == 1) {zannzou = 0; zannzoulock = 0;}
			if (zannzou <= 30 && zannzou > 0) { //★残像を出すためにRキーでAを押したら変数zannzouが20になり、zannouの変数が0より大きいならば—1をしていき、その間だけ画像を描画する。
				--zannzou;

				//移動中はR1が押せないようにする。
				R1botannlock = 1;
				//X軸のzannzouの分母を大きくすると減速する
				DrawRotaGraph(pos[playerY][playerX][0] + 20 - 20 * zannzou / 5, pos[playerY][playerX][1], bairituX, 0, playeridouAHandle[0], TRUE);

				R1lock = 1;

				//ロックボタンが押せないようにこの期間はR1lock = 1;として。



				//移動中にR1を押すとzannzouの変数が1になりにバグが応じて主人公が消えてしまうことがある。
				//なので移動中はR1を押しても反応しないようにする。
			//	lockdekinai = 1;//R1が押せないように条件外の変数の値にする。
				//一様↑に書いたように移動中はlockdekinaiを1にしてR1を押しても敵の前に行かないにしても
				//ロックオンできないようにしたはずなのだが、なぜかロックオンマークがでてしまうので下のif (Pad[PAD_6] == 1)も付け足した。
				//移動中にR1を押してもロックマークが出ないようにするためのもの。
				//★★いやこれで正しいif (Pad[PAD_6] == 1 && playerY == enemyY&& enemyX== pre2enemyX&& lockdekinai == 0)
				//は相手が以前と同じマスにいた際にロックマークがつくとしたため、そして、新しく作った移動中でロックした場合は
				//書いていなかったため、下のif文を新しく書き加える必要があった。要は、zannzouが0の時のことを考えていなかったため自分が
				//消えるバグが起きたと言っていたがそれは違った。
				//もともと書いた長いif文とif (zannzou <= 30 && zannzou > 0)によりzannzouが0の時はlockdekinaiが1になるので
				//zannzouが0の時でも正しく動く。しかし、移動中にR1をした場合のことを書いていなかったため、
				//移動中にR1を押すと自分が消えるバグが起きてしまったのだ。なので下に新しくif文を追加したのだ。よってlockdekinai = 1;の意味はない。
				//if (Pad[PAD_6] == 1) {
					//lockmark = 1;
					//lockonMove = 1;//アタックする時　ロックオンの画像が消えるように値を0にする。
					//zannzou = 0;//i★f (zannzou <= 30 && zannzou > 0)の条件を通って再び主人公が描画されるので、その条件を通過しないように
					//zannzou = 0と書いてしまうと主人公が敵の目の前に飛んだ後に消えてしまう。
					//R1lock = 1;
					//enemyXは敵のX座標ではないので敵をR1で狙った後は正確な座標ではなく、
					//pos[enemyY][enemyX][0]やpos[enemyY][enemyX][1]に含まれる比喩の座標なので、目の前に敵がいなくても、ほかの場所に敵がいても
					//pos[2][3][0]のpos[2][3][0]のenemyXが同じ値であるため、値がそのままなので敵が目の前にいなくても
					//残ったままのenemyXの3の値により、その値を参考にしてしまい敵がいなくてもR1を押すと主人公が勝手に動いてしまう。
					//もともとのR1からのXボタンでのコンボの時はlockが1の時にlockが解除されるのでロックを掛けた瞬間の敵のマスしか参考にしないので
					//考えた通りに動く。
					//★ん？もともとの奴はif (Pad[PAD_6] == 1 && playerY == enemyY&& enemyX== pre2enemyX)
					//により敵のX座標はpre2enemyXによりわかり、Y座標はif文で判定しているため正しく動くのだろう。
					//↑にかいたif文によりlockが1になり、そのロックした瞬間の敵のX座標の値がpre2enemyXに入り、
					//playerX = enemyX - 1;により代入され、敵の前のマスが確保され、同じY座標の時のみにlockできるようにしたため
					//比喩だけでありながら正確な敵の目の前に現れるのだ。
					//ここでは敵の比喩の座標は使えないのでステージiとjをすべて個々の異なる変数にするのは大変なので
					//pos[enemyY][enemyX][0]== pos[0][0][0]&& pos[enemyY][enemyX][1] == pos[0][0][1]のように書く。
					//このやり方も大変だが変数を新しく増やすよりはマシ。
					//いや、比喩でも正確なものがあるのでenemyXとenemyYを扱って新しく作る。

					//こいつがなり立つときのif文に&&enemyY == playerYを加えないと、どのYの列でもR1を押せば主人公の座標に
					//
					//preplayerX = playerX; // 元の位置を保持
					//preplayerY = enemyY;
					//playerX = enemyX - 1; // 俺は敵の眼前へ//敵の位置から-1して自分がいるときの位置にいた場合。
					//addplayerX = pos[playerY][preplayerX][0]; //アドアタックタイム中で相手の目の前に移動した後のマスを保存するための変数
					//addplayerY = pos[playerY][preplayerX][1];
					//addattacktime = 180;
					//premasuframe;
					//殴る部分
					//++attackframe;
					//敵の目の前にいるが、左や右の入力が速いと相手の前にいくがロックマークが現れないバグが起こるので以下のように書いて置く。
					//if (enemyY == playerY && playerX == enemyX - 1) {
						//zannzou = 50;
					//	lockmark = 1;
					//	lockonMove = 1;//何枚かのロックオンマークをフレームで描画してロックオンマークが動くようにするための変数。
					//	lock = 1;//ロックオンした際に左上にlockという文字を描画するための変数。
					//	sinnzoubyouga = 1;
					//	kougekilock = 1;
					//	LEFTmark = 4545;

						//if (Pad[PAD_6] == 1) {
						//	kougekiroclmark = 1;//R1を押しても前の座標を記憶しないように
						//}



				//	}
				//}
			}//移動した一瞬に元の位置に自分を描画したい、しかしうまく機能していない。
			///★多分一瞬過ぎるのであえてcount < 8と範囲を付けることでほんの一瞬だが残像が見えるようにした。
			///攻撃してcountが50に溜まるまでの期間を利用した。
			if (zannzou <= 25 && zannzou > 0) {
				DrawRotaGraph(pos[playerY][playerX][0] + 20 - 14 * zannzou / (20), pos[playerY][playerX][1], bairituX, 0, playeridouAHandle[0], TRUE);
			}
			if (zannzou <= 21 && zannzou > 0) {
				DrawRotaGraph(pos[playerY][playerX][0] + 20 - 10 * zannzou / (20), pos[playerY][playerX][1], bairituX, 0, playeridouAHandle[0], TRUE);
			}
			if (zannzou <= 18 && zannzou > 0) {
				DrawRotaGraph(pos[playerY][playerX][0] + 20 - 6 * zannzou / (20), pos[playerY][playerX][1], bairituX, 0, playeridouAHandle[0], TRUE);
			}
			if (zannzou <= 16 && zannzou > 0) {
				DrawRotaGraph(pos[playerY][playerX][0] + 20 - 1 * zannzou / (20), pos[playerY][playerX][1], bairituX, 0, playeridouAHandle[0], TRUE);
			}
			if (zannzou <= 6 && zannzou > 0) {
				DrawRotaGraph(pos[playerY][playerX][0] + 20 - zannzou / 20, pos[playerY][playerX][1], bairituX, 0, playeridouAHandle[0], TRUE);
				zannzousaigo = 1;
			}
			//★移動中のフレームの0の部分でif (zannzou < 0)がif (zannzou <= 6 && zannzou > 0)の中にあったためジャスト0での定義があいまいで
			//移動中でのロックが描画されたり、バグで相手の目の前に行く際に消えていたのだろう。なのでジャスト0での定義をちゃんとするために
			//if (zannzou <= 30 && zannzou > 0)の時にzannzouが減るのではなく、if (zannzou <= 30 && --zannzou > 0)として
			//if文が終わった後もzannzouが減り、外に出したif (zannzou < 0)が反応するようにした。
			//★if (zannzou <= 30 && --zannzou > 0)と書くと左の値を最初に優先するので変数の定義では0なのでzannzouが30以下である。なので実行と同時に
			//変数の値は減らされる。右に書かれた --zannzou > 0の優先順位は低いため値は優先順位の高いzannzou <= 30により
			//引かれていき0より大きくはならない。
			//★ちなみにif (zannzou > 0&&--zannzou <= 15)と逆に描いた場合はzannzou > 0を優先するので0より大きく15より小さいならば引いていき
			//zannzouC > 0が優先されるためzannzouの値は0より小さくはならない。
			if (zannzousaigo == 1) {
				zannzoulock = 0;
				lockdekinai = 0;
				zannzousaigo = 0;
				zannzou = 0;
				R1lock = 0;
				R1botannlock = 0;
				playerkonntororulock = 0;

			}

			//移動する際の前のマスに残像を残す(右移動の場合)
			//if (zannzou <= 30 && zannzou > 20) { 
				//DrawRotaGraph(pos[playerY][preplayerX][0], pos[playerY][playerX][1], 2.0, 0, playerImage, TRUE);

			//}
		}


		//左コマンドの残像
		if (zannzouA <= 30 && zannzouA > 0) { //★残像を出すためにRキーでAを押したら変数zannzouが20になり、zannouの変数が0より大きいならば?1をしていき、その間だけ画像を描画する。
			--zannzouA;
			//R1lock = 1;
			zannzoulock = 1;
			//playerkonntororulock = 1;
			DrawRotaGraph(pos[playerY][playerX][0] + 20 + 18 * zannzouA / 20, pos[playerY][playerX][1], bairituX, 0, playeridouAHandle[0], TRUE);

			//移動中にR1を押すとzannzouの変数が1になりにバグが応じて主人公が消えてしまうことがある。
			//なので移動中はR1を押しても反応しないようにする。
			//lockdekinai = 1;//R1が押せないように条件外の変数の値にする。

		}//移動した一瞬に元の位置に自分を描画したい、しかしうまく機能していない。
		///★多分一瞬過ぎるのであえてcount < 8と範囲を付けることでほんの一瞬だが残像が見えるようにした。
		///攻撃してcountが50に溜まるまでの期間を利用した。
		if (zannzouA <= 25 && zannzouA > 0) {
			DrawRotaGraph(pos[playerY][playerX][0] + 20 - 14 * zannzouA / (20), pos[playerY][playerX][1], bairituX, 0, playeridouAHandle[0], TRUE);
		}
		if (zannzouA <= 21 && zannzouA > 0) {
			DrawRotaGraph(pos[playerY][playerX][0] + 20 - 10 * zannzouA / (20), pos[playerY][playerX][1], bairituX, 0, playeridouAHandle[0], TRUE);
		}
		if (zannzouA <= 18 && zannzouA > 0) {
			DrawRotaGraph(pos[playerY][playerX][0] + 20 - 6 * zannzouA / (20), pos[playerY][playerX][1], bairituX, 0, playeridouAHandle[0], TRUE);
		}
		if (zannzouA <= 16 && zannzouA > 0) {
			DrawRotaGraph(pos[playerY][playerX][0] + 20 - 1 * zannzouA / (20), pos[playerY][playerX][1], bairituX, 0, playeridouAHandle[0], TRUE);
		}
		if (zannzouA <= 6 && zannzouA > 0) {
			//DrawRotaGraph(pos[playerY][playerX][0] + 20 - zannzouA / 20, pos[playerY][playerX][1], 5.0, 0, playeridouAHandle[0], TRUE);
			zannzouAsaigo = 1;
		}

		if (zannzouAsaigo == 1) {
			zannzoulock = 0;
			lockdekinai = 0;
			zannzouAsaigo = 0;
			zannzouA = 0;
			R1lock = 0;
			R1botannlock = 0;
			playerkonntororulock = 0;
		}

		//下コマンドの残像
		//★最初の方は画像の倍率を2にして、後は通常と同じ5倍にして、若干画像を移動方向に少しずらし、かつX方向は下に移動する際は少し前に出る感じでずらしてステップを踏むように移動させた。上の場合は下バージョンの逆を行った。
		if (zannzouB <= 15 && zannzouB > 0) { //★残像を出すためにRキーでAを押したら変数zannzouが20になり、zannouの変数が0より大きいならば—1をしていき、その間だけ画像を描画する。
			--zannzouB;
			DrawRotaGraph(pos[playerY][playerX][0] + 30 + 3 * zannzouB / 2, pos[playerY][playerX][1] - 5 * zannzouB, 2.0, 0, playerGHandle[0], TRUE);
			//移動中にR1を押すとzannzouの変数が1になりにバグが応じて主人公が消えてしまうことがある。
			//なので移動中はR1を押しても反応しないようにする。
			//lockdekinai = 1;//R1が押せないように条件外の変数の値にする。

		}
		if (zannzouB <= 13 && zannzouB > 0) {
			DrawRotaGraph(pos[playerY][playerX][0] + 30 + 3 * zannzouB / 2.5, pos[playerY][playerX][1] - 5 * zannzouB / 1.5, 5, 0, playerGHandle[0], TRUE);
		}
		if (zannzouB <= 11 && zannzouB > 0) {
			DrawRotaGraph(pos[playerY][playerX][0] + 30 + 3 * zannzouB / 3, pos[playerY][playerX][1] - 5 * zannzouB / 2, 5, 0, playerGHandle[0], TRUE);
		}
		if (zannzouB <= 9 && zannzouB > 0) {
			DrawRotaGraph(pos[playerY][playerX][0] + 30 + 3 * zannzouB / 3.5, pos[playerY][playerX][1] - 5 * zannzouB / 2.5, 5, 0, playerGHandle[0], TRUE);
		}
		if (zannzouB <= 7 && zannzouB > 0) {
			DrawRotaGraph(pos[playerY][playerX][0] + 30 + 3 * zannzouB / 4, pos[playerY][playerX][1] - 5 * zannzouB / 3, 5, 0, playerGHandle[0], TRUE);
		}
		if (zannzouB <= 3 && zannzouB > 0) {
			DrawRotaGraph(pos[playerY][playerX][0] + 30 + 2 * zannzouB / 4.5, pos[playerY][playerX][1] - 5 * zannzouB / 3.5, 5, 0, playerGHandle[0], TRUE);
			zannzouBsaigo = 1;
		}
		if (zannzouBsaigo == 1) {
			zannzoulock = 0;
			lockdekinai = 0;
			zannzouBsaigo = 0;
			zannzouB = 0;
			R1lock = 0;
			R1botannlock = 0;
			playerkonntororulock = 0;
		}

		//★敵の初期位置
		//敵が開始直後にいきなり動かない様にするためのプログラム。
		//★この部分は戦闘開始の瞬間ではすでに敵が動いてしまい、中心にいないので開始して数フレームの間は真ん中に固定した。そのほうが戦闘がきれいに始まる・
		if (enemybyougablock3 == 0) {
			if (stayhere3 == 1 && stayherelock == 0) {//↓if (stayhere == 1&& stayherelock == 0)とした理由。
		   //stayhere == 1だけでは敵を倒した際に敵を動かなくするためにstayhereが1になるため、ここで引っ掛かり、敵は動かないで消えるが、同時にここに書いた
		   //固定の座標の敵が再び描画されてしまう。なのでif (stayhere == 1&& stayherelock == 0)と書いた。敵のHPが0より小さくなった際の下に書いた
		   //if文より、敵が動かないようにstayhereは1としたがstayherelockが0のままだとif(stayhere == 1 && stayherelock == 0)に引っ掛かり固定された敵が描画
		   //されるのでここに引っ掛からない様にstayhereの値を1にした。
				++enemystayhere;
			}
			//}
			// !! 50になっている値を150へ変更しました

			if (enemystayhere > 0 && enemystayhere < 60) {
				//stayherelock = 0;//★battle start中にボタンを押しまくったりするとstayherelockが1になりフenemystayhere
				//が繰り上がらなくなり敵の値が止まり、動かないままになるので
				//この期間中は何が起きてもstayherelockが0のままになるようにここに書いた。
				//enemyImage = enemyGHandle[0];
				enemyImage = enemyGHandle[0];
				DrawRotaGraph(pos[1][4][0], pos[1][4][1], bairituY, 0, enemyImage, TRUE);
				////DrawExtendGraph(pos[1][4][0]-15 , pos[1][4][1] - 66, pos[1][4][0] + 40, pos[1][4][1] + 66, enemyImage, TRUE);
				//DrawExtendGraph(pos[1][4][0] - 14, pos[1][4][1] - 66, pos[1][4][0] + 64, pos[1][4][1] + 66, enemyGHandle[11], TRUE);でもよい。その場合は前のenemyImage = enemyGHandle[11];はいらない
			}
			if (enemystayhere > 60) {
				enemystayhere = 0;
				stayhere3 = 0;
				//enemymovelock = 0;
				stayherelock = 0;//★if (stayhere == 1&& stayherelock == 0)の条件に引っ掛かり条件の{}の働きが出てこないようにstayherelockの値を1にした。
				//★enemybyougablock3でブロックしているので、stayherelockは0でも大丈夫。
				enemybyougablock3 = 1;
			}
		}

		syuzinkoukougekigazou();//★この関数に含まれる部分と下の重なりの部分で敵に被っても違和感のないようにタバコが吸える。

			//タバコ回復の描画の部分//敵に重なる際にこっちに移動するようにtabakokasanariという変数を作った。
		if (tabakokasanari == 1) {
			if (tabakocount2 > 0) {
				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, playertabakoImage, TRUE);
			}
			if (tabakocount2 > 0 && tabakocount2 < 50)
			{
				playertabakoImage = playertabakoAHandle[0];
			}
			if (tabakocount2 > 50 && tabakocount2 < 100)
			{
				playertabakoImage = playertabakoBHandle[0];
			}
			if (tabakocount2 > 100 && tabakocount2 < 150)
			{
				playertabakoImage = playertabakoCHandle[0];
			}
			if (tabakocount2 > 150 && tabakocount2 < 200)
			{
				playertabakoImage = playertabakoDHandle[0];
			}
		}
		//敵を描画
		if (enemyzannzoulock == 0 && enemyhirumaseframe == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
			//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
			//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。
			if (enemystayhere == 0) {
				//LEFTmark = 1234;
				DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] + playerattackhanndou3, bairituY, 0, enemyImage, TRUE);
			}
		}


		arukukannsuu();
		//主人公を描画
		//DrawExtendGraph(pos[playerY][playerX][0] - 14, pos[playerY][playerX][1] - 66, pos[playerY][playerX][0] + 64, pos[playerY][playerX][1] + 66, playerImage, TRUE);
		//↓回転させる関数の方で5.5倍にした奴。
		//★スライド移動中での左右反転の部分
		if (motonomasunimodoru > 0) {
			if (migimuki == 1 && zannzoulock == 0) {
				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage, TRUE);

			}
			//試しのドット画像を使った部分
			//LoadGraphScreen(pos[playerY][playerX][0]-50, pos[playerY][playerX][1]-100, "image2 (1).jpeg", TRUE); // 画像を描画する

			//歩く画像のための関数。
			//if (lock == 0 && kaitenn == 0) { arukukannsuu(); }//R2でのロック中は表示されない。

			//主人公の拳銃の画像を描画するための関数。
			//if (playerHP > 0 && InputX == 0 && InputY == 0) { KENJYUU(); }//銃を撃ってるときに主人公が死んだ際に消えるように。

			if (hidarimuki == 1 && zannzoulock == 0) {
				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage2, TRUE);
				LEFT = 1212;
			}
		}
		//★スライド外の時の主人公の画像。
		//マス移動での主人公の描画
		//主人公を描画
			//DrawExtendGraph(pos[playerY][playerX][0] - 14, pos[playerY][playerX][1] - 66, pos[playerY][playerX][0] + 64, pos[playerY][playerX][1] + 66, playerImage, TRUE);
			//↓回転させる関数の方で5.5倍にした奴。
		if (zannzoulock == 0 && migimuki == 1 && Gtime == 0) {
			DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage, TRUE);
		}
		//試しのドット画像を使った部分
		//LoadGraphScreen(pos[playerY][playerX][0]-50, pos[playerY][playerX][1]-100, "image2 (1).jpeg", TRUE); // 画像を描画する

		//syuzinnkouDAMEGE();



		KENJYUU();



		
		//if (yokerarenai == 0) {
		//	if (contorora == !(PAD_INPUT_4 | PAD_INPUT_2) && yokkerucouunt > 0) {
		//		yokkerucouunt = 0;
		//		nextattack = 0;
		//	}
		//}
		//上のコマンドの残像//このままでいい。
		if (zannzouC > 0 && zannzouC <= 15) { //★残像を出すためにRキーでAを押したら変数zannzouが20になり、zannouの変数が0より大きいならば—1をしていき、その間だけ画像を描画する。
			--zannzouC;
			DrawRotaGraph(pos[playerY][playerX][0] + 30 - 3 * zannzouC / 5, pos[playerY][playerX][1] - 1 * zannzouC / 4, 2.0, 0, playerGHandle[0], TRUE);
			//移動中にR1を押すとzannzouの変数が1になりにバグが応じて主人公が消えてしまうことがある。
			//なので移動中はR1を押しても反応しないようにする。
			//lockdekinai = 1;//R1が押せないように条件外の変数の値にする。

		}
		if (zannzouC <= 3 && zannzouC > 0) {
			DrawRotaGraph(pos[playerY][playerX][0] + 30 - 3 * zannzouC / 4.5, pos[playerY][playerX][1] + 1 * zannzouC / 3.5, 2.0, 0, playerGHandle[0], TRUE);
			zannzouCsaigo = 1;
		}
		if (zannzouC <= 7 && zannzouC > 0) {
			DrawRotaGraph(pos[playerY][playerX][0] + 30 - 3 * zannzouC / 4, pos[playerY][playerX][1] + 1 * zannzouC / 3, 5.0, 0, playerGHandle[0], TRUE);
		}
		if (zannzouC <= 9 && zannzouC > 0) {
			DrawRotaGraph(pos[playerY][playerX][0] + 30 - 3 * zannzouC / 3.5, pos[playerY][playerX][1] + 1 * zannzouC / 2.5, 5.0, 0, playerGHandle[0], TRUE);
		}
		if (zannzouC <= 11 && zannzouC > 0) {
			DrawRotaGraph(pos[playerY][playerX][0] + 30 - 3 * zannzouC / 3, pos[playerY][playerX][1] + 1 * zannzouC / 2, 5.0, 0, playerGHandle[0], TRUE);
		}
		if (zannzouC <= 13 && zannzouC > 0) {
			DrawRotaGraph(pos[playerY][playerX][0] + 30 - 3 * zannzouC / 2.5, pos[playerY][playerX][1] + 1 * zannzouC / 1.5, 5.0, 0, playerGHandle[0], TRUE);
		}
		if (zannzouCsaigo == 1) {
			zannzoulock = 0;
			lockdekinai = 0;
			zannzouCsaigo = 0;
			zannzouC = 0;
			R1lock = 0;
			R1botannlock = 0;
			playerkonntororulock = 0;
		}

		//通常状態で重なる場合の描画の順番におけるプログラム
		//if (playerX == enemyX && playerY == enemyY - 1) {
		//	zannzoulock = 1;
		//	if (tabakosutterulock == 0) {
		//		DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, 5, 0, playerImage, TRUE);
		//	}DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1], 4, 0, enemyImage, TRUE);

		//}

		//範囲が重なるときだけ主人公と敵の位置が変わるようにした。
		//主人公が攻撃しないでマス移動のみをする際の敵と主人公の重なり具合。
		if (KABURI == 0) {
			if (ranndamulock == 0) {//この数値で丁度いい//ランダムロックは重ならないためではなく敵の攻撃中は重なりがないようにするための物である。
				if (pos[enemyY][enemyX][0] + 200 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
					pos[enemyY][enemyX][0] - 200 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3
					&& pos[enemyY][enemyX][1] + playerattackhanndou3 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3) {
					//if (tabakosutterulock == 0) {
					KABURImark = 111;
					//攻撃するときは1にしてるので、ここでさらにわざわざ1にしなくてもよい。それにif (ranndamulock == 0)の条件より攻撃する先は
					//ここを通らないのでここでは描画されない。
					//enemyzannzoulock = 1;//通常状態の敵を消して、こっちの画像にする。

					//こいつがここにあったため、タバコ回復中に静止した通常状態の画像が描画されてしまっていた。
					//なので上の主人公と同じ条件としてif (zannzoulock == 0)を加えた。
					if (enemyattaking == 1 && ranndamukougeki == 0 && motonomasunimodoru == 0 && enemyhirumaseframe == 0 && enemyzannzoulock == 0) {//通常状態での攻撃する瞬間に1になるので、通常状態でも正しく並ぶようにここに書いた。
						//LEFTmark = 5423;
						DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] + playerattackhanndou3, bairituY, 0, enemyImage, TRUE);
					}
					if (zannzoulock == 0 && motonomasunimodoru == 0) {
						KABURImark = 34345;
						DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, playerImage, TRUE);
					}
					if (enemyattaking == 0 && ranndamukougeki == 0 && motonomasunimodoru == 0 && enemyhirumaseframe == 0 && enemyzannzoulock == 0) {//ranndamukougeki==0は敵が攻撃してこない時なので、かつして来ないときは描画しない。
						LEFTmark = 789;
						DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] + playerattackhanndou3, bairituY, 0, enemyImage, TRUE);
					}//}
				}//★pos[enemyY][enemyX][1] になぜか100を足しているときは二つの場合で範囲が被っていため正しく動かなかったのだろう。試しに20では大丈夫だった。が、このままでいい。
				else if (pos[enemyY][enemyX][0] + 200 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
					pos[enemyY][enemyX][0] - 200 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
					//pos[enemyY][enemyX][1] + 150 + playerattackhanndou3 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
					pos[enemyY][enemyX][1] + playerattackhanndou3 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
					//pos[enemyY][enemyX][0] + 30 < pos[playerY][playerX][0] + 20 + playerattackhanndou + nanameidouX + migiidou&&
					//★元々は-150だったが、敵の攻撃範囲と近いと動かなくなるバグがあるのでXの方は-100にした、-120でもいいかもしれないが試していない。

					) {
					//if (tabakosutterulock == 0) {
					KABURImark = 222;
					kasanaruURA = 1;//敵が奥にいて右に移動する場合に必要な変数。
					//enemyzannzoulock = 1;//通常状態の敵を消して、こっちの画像にする。
					if (enemyattaking == 0 && ranndamukougeki == 0 && motonomasunimodoru == 0 && enemyhirumaseframe == 0 && enemyzannzoulock == 0) {
						LEFTmark = 223;
						DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] + playerattackhanndou3, bairituY, 0, enemyImage, TRUE);
					}
					if (zannzoulock == 0 && motonomasunimodoru == 0) {
						LEFTmark = 225;
						DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, playerImage, TRUE);
					}//}
					if (enemyattaking == 1 && ranndamukougeki == 0 && motonomasunimodoru == 0 && enemyhirumaseframe == 0 && enemyzannzoulock == 0) {
						LEFTmark = 228;
						//&& enemyhirumaseframe == 0を付け足すことでカウンター攻撃での通常状態の敵が描画されないようにした。
						DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] + playerattackhanndou3, bairituY, 0, enemyImage, TRUE);
					}
					//右コマンドの残像//敵が奥にいる際の移動描画//原因はif (zannzou < 1) {zannzou = 0; zannzoulock = 0;}の部分でした。if (zannzou == 1) {zannzou = 0; zannzoulock = 0;}
					if (kasanaruURA == 1) {
						if (zannzou <= 30 && zannzou > 0) { //★残像を出すためにRキーでAを押したら変数zannzouが20になり、zannouの変数が0より大きいならば—1をしていき、その間だけ画像を描画する。
							--zannzou;

							//移動中はR1が押せないようにする。
							R1botannlock = 1;
							//X軸のzannzouの分母を大きくすると減速する
							DrawRotaGraph(pos[playerY][playerX][0] + 20 - 20 * zannzou / 5, pos[playerY][playerX][1], bairituX, 0, playeridouAHandle[0], TRUE);

							R1lock = 1;

						}
						if (zannzou <= 25 && zannzou > 0) {
							DrawRotaGraph(pos[playerY][playerX][0] + 20 - 14 * zannzou / (20), pos[playerY][playerX][1], bairituX, 0, playeridouAHandle[0], TRUE);
						}
						if (zannzou <= 21 && zannzou > 0) {
							DrawRotaGraph(pos[playerY][playerX][0] + 20 - 10 * zannzou / (20), pos[playerY][playerX][1], bairituX, 0, playeridouAHandle[0], TRUE);
						}
						if (zannzou <= 18 && zannzou > 0) {
							DrawRotaGraph(pos[playerY][playerX][0] + 20 - 6 * zannzou / (20), pos[playerY][playerX][1], bairituX, 0, playeridouAHandle[0], TRUE);
						}
						if (zannzou <= 16 && zannzou > 0) {
							DrawRotaGraph(pos[playerY][playerX][0] + 20 - 1 * zannzou / (20), pos[playerY][playerX][1], bairituX, 0, playeridouAHandle[0], TRUE);
						}
						if (zannzou <= 6 && zannzou > 0) {
							DrawRotaGraph(pos[playerY][playerX][0] + 20 - zannzou / 20, pos[playerY][playerX][1], bairituX, 0, playeridouAHandle[0], TRUE);
							zannzousaigo = 1;
						}
						if (zannzousaigo == 1) {
							zannzoulock = 0;
							lockdekinai = 0;
							zannzousaigo = 0;
							zannzou = 0;
							R1lock = 0;
							R1botannlock = 0;
							kasanaruURA = 0;
							playerkonntororulock = 0;
						}
					}
				}

				//else {
				//	DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] + playerattackhanndou3, 4, 0, enemyImage, TRUE);
				//	DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, 5, 0, playerImage, TRUE);
				//}
			}
		}

		// 敵のグラフィックのサイズをえる
		//GetGraphSize(enemyShotGraph, &enemyShotW, &enemyShotH);


		///if (start >= 150 && ++start >= 160) {

			///enemymovelock = 0;
			///start = 0;
			//battle_Initialize();
		///}


	//R1を押した際のスライド移動を制御する関数。//主人公の奥にあるように見せたいためここに主人公描画の前に配置する。
		//if (suraidoidou == 1) {
		//	suraidoidoukannsuu();
		//}

		//スライド移動意外の時だけ投げる攻撃が当たる。
		if (motonomasunimodoru == 0) {

			//投げ攻撃
			if (aa == 2) {
				A = 2;
				stopenemy = 1;
				randamulock2 = 1;//もう一つの投げが動かないように。
				randamulock = 1;//ランダム関数が影響しないためのロック//投げる攻撃中に敵が近接攻撃しないように。
			}
			if (A == 2) {
				aa = 0;//if (a == 2)が働き、if (A == 2)の文が働き3つの画像が同時に描画されるバグを防ぐためにaを0にした。

				preenemyX3 = pos[enemyY][enemyX][0] - 20;//移動前の座標を保存する、敵の座標を保存
				preenemyY3 = pos[enemyY][enemyX][1] - 90;//これで手で投げているように見える
				++A;
			}
			if (A == 3) {
				++kakudoA;
				if (kakudoA % 3 == 2) {
					++kakudoB;
				}
				++kasokudo;
				//preenemyX3 = preenemyX3 - kasokudo;//実験用
				preenemyX3A = preenemyX3 - kasokudo;//座標に+1後のモノをpreenemyX3Aとした
				preenemyX3B = preenemyX3 - preenemyX3A;//後と前(固定された座標)を引いて、その差分をpreenemyX3Bとした
				test = preenemyX3B * 18;
				Y = -(test ^ 2);
				preenemyY3A = preenemyY3 + Y;
				//DrawGraph(preenemyX3A - 20 * kasokudo, preenemyY3A + 2 * kasokudo, kikennhanndle[1], true);
			//敵が奥から物を投げる時の部分。投げるものの大きさが変わるようにする部分。
				if (bairituY == 4.6) {
					DrawRotaGraph(preenemyX3A - 20 * kasokudo, preenemyY3A + 2 * kasokudo, 1.0, 0 - kakudoB, kikennhanndle[1], TRUE);
					DrawRotaGraph(preenemyX3A - 10 * kasokudo, preenemyY3A + 4 * kasokudo, 1.0, 0 - kakudoB, kikennhanndle[1], TRUE);
					DrawRotaGraph(preenemyX3A - 15 * kasokudo, preenemyY3A + 3 * kasokudo, 1.0, 0 - kakudoB, kikennhanndle[1], TRUE);
				}
				if (bairituY == 5) {
					DrawRotaGraph(preenemyX3A - 20 * kasokudo, preenemyY3A + 2 * kasokudo, 1.5, 0 - kakudoB, kikennhanndle[1], TRUE);
					DrawRotaGraph(preenemyX3A - 10 * kasokudo, preenemyY3A + 4 * kasokudo, 1.5, 0 - kakudoB, kikennhanndle[1], TRUE);
					DrawRotaGraph(preenemyX3A - 15 * kasokudo, preenemyY3A + 3 * kasokudo, 1.5, 0 - kakudoB, kikennhanndle[1], TRUE);
				}
				if (bairituY == 5.4) {
					DrawRotaGraph(preenemyX3A - 20 * kasokudo, preenemyY3A + 2 * kasokudo, 2.0, 0 - kakudoB, kikennhanndle[1], TRUE);
					DrawRotaGraph(preenemyX3A - 10 * kasokudo, preenemyY3A + 4 * kasokudo, 2.0, 0 - kakudoB, kikennhanndle[1], TRUE);
					DrawRotaGraph(preenemyX3A - 15 * kasokudo, preenemyY3A + 3 * kasokudo, 2.0, 0 - kakudoB, kikennhanndle[1], TRUE);
				}
			}
			if (kasokudo > 15) {
				kasokudo = 15;
				A = 4;
				randamuzahyoulockA = 0;
				kakudoA = 0;
				kakudoB = 0;
			}
			if (randamuzahyoulockA == 0) {
				if (A == 4) {
					randamumasuX = 0, randamumasuY = GetRand(2);
					randamumasuXA = 1, randamumasuYA = GetRand(2);
					randamumasuXB = 2, randamumasuYB = GetRand(2);
					pos[randamumasuY][randamumasuX][0], pos[randamumasuY][randamumasuX][1];
					//DrawGraph(pos[randamumasuY][randamumasuX][0], pos[randamumasuY][randamumasuX][1], kikennhanndle[1], true);
					++randamuzahyou;
					randamuzahyoukeisann = 1;
				}
			}
			if (randamuzahyoukeisann == 1) {
				++kakudo;
				if (kakudo % 3 == 2) {
					++kakudo2;
				}
				++randamuzahyoukeisannhiki;
				if (randamumasuX == 0 && randamumasuY == 0) {
					DrawRotaGraph(pos[randamumasuY][randamumasuX][0] + 140 - 4 * randamuzahyoukeisannhiki, pos[randamumasuY][randamumasuX][1] - 200 + 8 * randamuzahyoukeisannhiki, 1.0, 0 - kakudo2, kikennhanndle[1], TRUE);
				}
				if (randamumasuX == 0 && randamumasuY == 1) {
					DrawRotaGraph(pos[randamumasuY][randamumasuX][0] + 140 - 4 * randamuzahyoukeisannhiki, pos[randamumasuY][randamumasuX][1] - 200 + 8 * randamuzahyoukeisannhiki, 1.5, 0 - kakudo2, kikennhanndle[1], TRUE);
				}
				if (randamumasuX == 0 && randamumasuY == 2) {
					DrawRotaGraph(pos[randamumasuY][randamumasuX][0] + 140 - 4 * randamuzahyoukeisannhiki, pos[randamumasuY][randamumasuX][1] - 200 + 8 * randamuzahyoukeisannhiki, 2, 0 - kakudo2, kikennhanndle[1], TRUE);
				}
				if (randamumasuXA == 1 && randamumasuYA == 0) {
					DrawRotaGraph(pos[randamumasuYA][randamumasuXA][0] + 140 - 4 * randamuzahyoukeisannhiki, pos[randamumasuYA][randamumasuXA][1] - 200 + 8 * randamuzahyoukeisannhiki, 1, 0 - kakudo2, kikennhanndle[1], TRUE);
				}
				if (randamumasuXA == 1 && randamumasuYA == 1) {
					DrawRotaGraph(pos[randamumasuYA][randamumasuXA][0] + 140 - 4 * randamuzahyoukeisannhiki, pos[randamumasuYA][randamumasuXA][1] - 200 + 8 * randamuzahyoukeisannhiki, 1.5, 0 - kakudo2, kikennhanndle[1], TRUE);
				}
				if (randamumasuXA == 1 && randamumasuYA == 2) {
					DrawRotaGraph(pos[randamumasuYA][randamumasuXA][0] + 140 - 4 * randamuzahyoukeisannhiki, pos[randamumasuYA][randamumasuXA][1] - 200 + 8 * randamuzahyoukeisannhiki, 2, 0 - kakudo2, kikennhanndle[1], TRUE);

				}
				if (randamumasuXB == 2 && randamumasuYB == 0) {
					DrawRotaGraph(pos[randamumasuYB][randamumasuXB][0] + 140 - 4 * randamuzahyoukeisannhiki, pos[randamumasuYB][randamumasuXB][1] - 200 + 8 * randamuzahyoukeisannhiki, 1, 0 - kakudo2, kikennhanndle[1], TRUE);
				}
				if (randamumasuXB == 2 && randamumasuYB == 1) {
					DrawRotaGraph(pos[randamumasuYB][randamumasuXB][0] + 140 - 4 * randamuzahyoukeisannhiki, pos[randamumasuYB][randamumasuXB][1] - 200 + 8 * randamuzahyoukeisannhiki, 1.5, 0 - kakudo2, kikennhanndle[1], TRUE);
				}

				if (randamumasuXB == 2 && randamumasuYB == 2) {
					DrawRotaGraph(pos[randamumasuYB][randamumasuXB][0] + 140 - 4 * randamuzahyoukeisannhiki, pos[randamumasuYB][randamumasuXB][1] - 200 + 8 * randamuzahyoukeisannhiki, 2, 0 - kakudo2, kikennhanndle[1], TRUE);
				}

			}
			if (randamuzahyoukeisannhiki > 24) {
				randamuzahyoukeisann = 0;
				kakudo = 0;
				kakudo2 = 0;
			}
			//if (randamuzahyou > 40 && randamuzahyou < 60) {
				//DrawGraph(preenemyX3 - 500, preenemyY3-200, kikennhanndle[1], true);
			//}
			if (randamuzahyou > 0 && ++randamuzahyou > 20) {
				randamuzahyoulock = 1;
				randamuzahyou = 0;//randamuzahyouが0より大きいとrandamuzahyoulock = 1のままで描画が消えないので、25より大きくなったら0にする。
				//A = 5;
			}
			if (randamuzahyou > 0 && randamuzahyou < 20) {
				randamuzahyoulockA = 1;//上のif(A==4)が働かないようにするために書いた。
			}
			if (randamuzahyoulock == 1) {
				if (randamumasuX == 0 && randamumasuY == 0) {
					A = 5; randammasucountA = 1;
					//DrawGraph(pos[randamumasuY][randamumasuX][0], pos[randamumasuY][randamumasuX][1], kikennhanndle[1], true);
					DrawRotaGraph(pos[randamumasuY][randamumasuX][0], pos[randamumasuY][randamumasuX][1], 1, 0, kikennhanndle[1], TRUE);

					if (pos[randamumasuY][randamumasuX][0] == pos[playerY][playerX][0] && pos[randamumasuY][randamumasuX][1] == pos[playerY][playerX][1]) {
						//下に書いてある50フレーム中のrandammasucountBA > 0 && randammasucountBA < 2の間だけダメージが当たるようにした。なので書いたままのダメージが入る。
						if (randammasucountBA > 0 && randammasucountBA < 2) {
							playerHPsubun = 51;
							damgesinndou = 1;
						}
					}
				}
				if (randamumasuX == 0 && randamumasuY == 1) {
					A = 5; randammasucountA = 1;
					//DrawGraph(pos[randamumasuY][randamumasuX][0], pos[randamumasuY][randamumasuX][1], kikennhanndle[1], true);
					DrawRotaGraph(pos[randamumasuY][randamumasuX][0], pos[randamumasuY][randamumasuX][1], 1.5, 0, kikennhanndle[1], TRUE);

					if (pos[randamumasuY][randamumasuX][0] == pos[playerY][playerX][0] && pos[randamumasuY][randamumasuX][1] == pos[playerY][playerX][1]) {
						if (randammasucountBA > 0 && randammasucountBA < 2) {
							playerHPsubun = 51;
							damgesinndou = 1;
						}
					}
				}
				if (randamumasuX == 0 && randamumasuY == 2) {
					A = 5; randammasucountA = 1;
					//DrawGraph(pos[randamumasuY][randamumasuX][0], pos[randamumasuY][randamumasuX][1], kikennhanndle[1], true);
					DrawRotaGraph(pos[randamumasuY][randamumasuX][0], pos[randamumasuY][randamumasuX][1], 2, 0, kikennhanndle[1], TRUE);

					if (pos[randamumasuY][randamumasuX][0] == pos[playerY][playerX][0] && pos[randamumasuY][randamumasuX][1] == pos[playerY][playerX][1]) {
						if (randammasucountBA > 0 && randammasucountBA < 2) {
							playerHPsubun = 51;
							damgesinndou = 1;
						}
					}
				}
				if (randamumasuXA == 1 && randamumasuYA == 0) {
					A = 5; randammasucountA = 1;
					//DrawGraph(pos[randamumasuYA][randamumasuXA][0], pos[randamumasuYA][randamumasuXA][1], kikennhanndle[1], true);
					DrawRotaGraph(pos[randamumasuYA][randamumasuXA][0], pos[randamumasuYA][randamumasuXA][1], 1, 0, kikennhanndle[1], TRUE);

					if (pos[randamumasuYA][randamumasuXA][0] == pos[playerY][playerX][0] && pos[randamumasuYA][randamumasuXA][1] == pos[playerY][playerX][1]) {
						if (randammasucountBA > 0 && randammasucountBA < 2) {
							playerHPsubun = 51;
							damgesinndou = 1;
						}
					}
				}
				if (randamumasuXA == 1 && randamumasuYA == 1) {
					A = 5; randammasucountA = 1;
					//DrawGraph(pos[randamumasuYA][randamumasuXA][0], pos[randamumasuYA][randamumasuXA][1], kikennhanndle[1], true);
					DrawRotaGraph(pos[randamumasuYA][randamumasuXA][0], pos[randamumasuYA][randamumasuXA][1], 1.5, 0, kikennhanndle[1], TRUE);

					if (pos[randamumasuYA][randamumasuXA][0] == pos[playerY][playerX][0] && pos[randamumasuYA][randamumasuXA][1] == pos[playerY][playerX][1]) {
						if (randammasucountBA > 0 && randammasucountBA < 2) {
							playerHPsubun = 51;
							damgesinndou = 1;
						}
					}
				}
				if (randamumasuXA == 1 && randamumasuYA == 2) {
					A = 5; randammasucountA = 1;
					//DrawGraph(pos[randamumasuYA][randamumasuXA][0], pos[randamumasuYA][randamumasuXA][1], kikennhanndle[1], true);
					DrawRotaGraph(pos[randamumasuYA][randamumasuXA][0], pos[randamumasuYA][randamumasuXA][1], 2, 0, kikennhanndle[1], TRUE);

					if (pos[randamumasuYA][randamumasuXA][0] == pos[playerY][playerX][0] && pos[randamumasuYA][randamumasuXA][1] == pos[playerY][playerX][1]) {
						if (randammasucountBA > 0 && randammasucountBA < 2) {
							playerHPsubun = 51;
							damgesinndou = 1;
						}
					}
				}
				if (randamumasuXB == 2 && randamumasuYB == 0) {
					A = 5; randammasucountA = 1;
					//DrawGraph(pos[randamumasuYB][randamumasuXB][0], pos[randamumasuYB][randamumasuXB][1], kikennhanndle[1], true);
					DrawRotaGraph(pos[randamumasuYB][randamumasuXB][0], pos[randamumasuYB][randamumasuXB][1], 1, 0, kikennhanndle[1], TRUE);

					if (pos[randamumasuYB][randamumasuXB][0] == pos[playerY][playerX][0] && pos[randamumasuYB][randamumasuXB][1] == pos[playerY][playerX][1]) {
						if (randammasucountBA > 0 && randammasucountBA < 2) {
							playerHPsubun = 51;
							damgesinndou = 1;
						}
					}
				}
				if (randamumasuXB == 2 && randamumasuYB == 1) {
					A = 5; randammasucountA = 1;
					//DrawGraph(pos[randamumasuYB][randamumasuXB][0], pos[randamumasuYB][randamumasuXB][1], kikennhanndle[1], true);
					DrawRotaGraph(pos[randamumasuYB][randamumasuXB][0], pos[randamumasuYB][randamumasuXB][1], 1.5, 0, kikennhanndle[1], TRUE);

					if (pos[randamumasuYB][randamumasuXB][0] == pos[playerY][playerX][0] && pos[randamumasuYB][randamumasuXB][1] == pos[playerY][playerX][1]) {
						if (randammasucountBA > 0 && randammasucountBA < 2) {
							playerHPsubun = 51;
							damgesinndou = 1;
						}
					}
				}
				if (randamumasuXB == 2 && randamumasuYB == 2) {
					A = 5; randammasucountA = 1;
					//DrawGraph(pos[randamumasuYB][randamumasuXB][0], pos[randamumasuYB][randamumasuXB][1], kikennhanndle[1], true);
					DrawRotaGraph(pos[randamumasuYB][randamumasuXB][0], pos[randamumasuYB][randamumasuXB][1], 2, 0, kikennhanndle[1], TRUE);

					if (pos[randamumasuYB][randamumasuXB][0] == pos[playerY][playerX][0] && pos[randamumasuYB][randamumasuXB][1] == pos[playerY][playerX][1]) {
						if (randammasucountBA > 0 && randammasucountBA < 2) {
							playerHPsubun = 51;
							damgesinndou = 1;
						}
					}
				}
			}
			if (randammasucountA > 0) {
				++randammasucountBA;
				//randamuzahyouB = 0;
			}
			//マスに落ちたアイテム
			if (randammasucountBA > 0 && randammasucountBA > 15) {
				randamuzahyoulock = 0;
				//randamulock = 0;
			}
			if (randammasucountBA > 15) {
				randammasucountBA = 0;
				randammasucountA = 0;
				A = 0;
				stopenemy = 0;
				test = 0;
				Y = 0;
				randamuzahyoulockA = 0;
				randamuzahyoukeisann = 0;
				kasokudo = 0;
				randamuzahyoukeisannhiki = 0;//上がったままのこいつを0にすることでAが4の時の問題が解決した。
				randamumasuY = 0;
				randamumasuYA = 0;
				randamumasuYB = 0;
				randamulock = 0;
				randamulock2 = 0;
			}

			//もう一つの投げの攻撃
			if (bb == 3) {
				B = 2;
				stopenemy = 1;
				randamulock2 = 1;//ランダム関数が影響しないためのロック
				randamulock = 1;//もう一つが動かないように。
			}
			if (B == 2) {
				bb = 0;//if (a == 2)が働き、if (A == 2)の文が働き3つの画像が同時に描画されるバグを防ぐためにaを0にした。

				preenemyX3 = pos[enemyY][enemyX][0] - 20;//移動前の座標を保存する、敵の座標を保存
				preenemyY3 = pos[enemyY][enemyX][1] - 90;//これで手で投げているように見える
				++B;
			}
			if (B == 3) {
				++kakudoC;
				if (kakudoC % 3 == 2) {
					++kakudoD;
				}
				++kasokudo2;
				//preenemyX3 = preenemyX3 - kasokudo;//実験用
				preenemyX3A = preenemyX3 - kasokudo2;//座標に+1後のモノをpreenemyX3Aとした
				preenemyX3B = preenemyX3 - preenemyX3A;//後と前(固定された座標)を引いて、その差分をpreenemyX3Bとした
				test = preenemyX3B * 18;
				Y = -(test ^ 2);
				preenemyY3A = preenemyY3 + Y;
				//DrawGraph(preenemyX3A - 20 * kasokudo2, preenemyY3A + 2 * kasokudo2, kikennhanndle[1], true);
				//DrawRotaGraph(preenemyX3A - 20 * kasokudo2, preenemyY3A + 2 * kasokudo2, 1.0, 0 - kakudoD, kikennhanndle[1], TRUE);
				if (bairituY == 4.6) {
					DrawRotaGraph(preenemyX3A - 10 * kasokudo2, preenemyY3A + 4 * kasokudo2, 1.0, 0 - kakudoD, kikennhanndle[1], TRUE);
					DrawRotaGraph(preenemyX3A - 15 * kasokudo2, preenemyY3A + 3 * kasokudo2, 1.0, 0 - kakudoD, kikennhanndle[1], TRUE);
					DrawRotaGraph(preenemyX3A - 20 * kasokudo2, preenemyY3A + 2 * kasokudo2, 1.0, 0 - kakudoD, kikennhanndle[1], TRUE);
				}
				if (bairituY == 5) {
					DrawRotaGraph(preenemyX3A - 10 * kasokudo2, preenemyY3A + 4 * kasokudo2, 1.5, 0 - kakudoD, kikennhanndle[1], TRUE);
					DrawRotaGraph(preenemyX3A - 15 * kasokudo2, preenemyY3A + 3 * kasokudo2, 1.5, 0 - kakudoD, kikennhanndle[1], TRUE);
					DrawRotaGraph(preenemyX3A - 20 * kasokudo2, preenemyY3A + 2 * kasokudo2, 1.5, 0 - kakudoD, kikennhanndle[1], TRUE);
				}
				if (bairituY == 5.4) {
					DrawRotaGraph(preenemyX3A - 10 * kasokudo2, preenemyY3A + 4 * kasokudo2, 2.0, 0 - kakudoD, kikennhanndle[1], TRUE);
					DrawRotaGraph(preenemyX3A - 15 * kasokudo2, preenemyY3A + 3 * kasokudo2, 2.0, 0 - kakudoD, kikennhanndle[1], TRUE);
					DrawRotaGraph(preenemyX3A - 20 * kasokudo2, preenemyY3A + 2 * kasokudo2, 2.0, 0 - kakudoD, kikennhanndle[1], TRUE);
				}

			}
			if (kasokudo2 > 15) {
				kasokudo2 = 15;
				B = 4;
				kakudoC = 0;
				kakudoD = 0;
			}
			if (randamuzahyoulockB == 0) {
				if (B == 4) {
					randamumasuX = GetRand(2), randamumasuY = 0;
					randamumasuXA = GetRand(2), randamumasuYA = 1;
					randamumasuXB = GetRand(2), randamumasuYB = 2;
					pos[randamumasuY][randamumasuX][0], pos[randamumasuY][randamumasuX][1];
					//DrawGraph(pos[randamumasuY][randamumasuX][0], pos[randamumasuY][randamumasuX][1], kikennhanndle[1], true);
					++randamuzahyouB;
					randamuzahyoukeisannB = 1;
				}
			}
			if (randamuzahyoukeisannB == 1) {
				++kakudo3;
				if (kakudo3 % 3 == 2) {
					++kakudo4;
				}
				++randamuzahyoukeisannhikiB;


				if (randamumasuX == 0 && randamumasuY == 0) {
					DrawRotaGraph(pos[randamumasuY][randamumasuX][0] + 140 - 4 * randamuzahyoukeisannhikiB, pos[randamumasuY][randamumasuX][1] - 200 + 8 * randamuzahyoukeisannhikiB, 1.0, 0 - kakudo4, kikennhanndle[1], TRUE);
				}
				if (randamumasuX == 1 && randamumasuY == 0) {
					DrawRotaGraph(pos[randamumasuY][randamumasuX][0] + 140 - 4 * randamuzahyoukeisannhikiB, pos[randamumasuY][randamumasuX][1] - 200 + 8 * randamuzahyoukeisannhikiB, 1, 0 - kakudo4, kikennhanndle[1], TRUE);
				}
				if (randamumasuX == 2 && randamumasuY == 0) {
					DrawRotaGraph(pos[randamumasuY][randamumasuX][0] + 140 - 4 * randamuzahyoukeisannhikiB, pos[randamumasuY][randamumasuX][1] - 200 + 8 * randamuzahyoukeisannhikiB, 1, 0 - kakudo4, kikennhanndle[1], TRUE);
				}
				if (randamumasuXA == 0 && randamumasuYA == 1) {
					DrawRotaGraph(pos[randamumasuYA][randamumasuXA][0] + 140 - 4 * randamuzahyoukeisannhikiB, pos[randamumasuYA][randamumasuXA][1] - 200 + 8 * randamuzahyoukeisannhikiB, 1.5, 0 - kakudo4, kikennhanndle[1], TRUE);
				}
				if (randamumasuXA == 1 && randamumasuYA == 1) {
					DrawRotaGraph(pos[randamumasuYA][randamumasuXA][0] + 140 - 4 * randamuzahyoukeisannhikiB, pos[randamumasuYA][randamumasuXA][1] - 200 + 8 * randamuzahyoukeisannhikiB, 1.5, 0 - kakudo4, kikennhanndle[1], TRUE);
				}
				if (randamumasuXA == 2 && randamumasuYA == 1) {
					DrawRotaGraph(pos[randamumasuYA][randamumasuXA][0] + 140 - 4 * randamuzahyoukeisannhikiB, pos[randamumasuYA][randamumasuXA][1] - 200 + 8 * randamuzahyoukeisannhikiB, 1.5, 0 - kakudo4, kikennhanndle[1], TRUE);

				}
				if (randamumasuXB == 0 && randamumasuYB == 2) {
					DrawRotaGraph(pos[randamumasuYB][randamumasuXB][0] + 140 - 4 * randamuzahyoukeisannhikiB, pos[randamumasuYB][randamumasuXB][1] - 200 + 8 * randamuzahyoukeisannhikiB, 2, 0 - kakudo4, kikennhanndle[1], TRUE);
				}
				if (randamumasuXB == 1 && randamumasuYB == 2) {
					DrawRotaGraph(pos[randamumasuYB][randamumasuXB][0] + 140 - 4 * randamuzahyoukeisannhikiB, pos[randamumasuYB][randamumasuXB][1] - 200 + 8 * randamuzahyoukeisannhikiB, 2.0, 0 - kakudo4, kikennhanndle[1], TRUE);
				}

				if (randamumasuXB == 2 && randamumasuYB == 2) {
					DrawRotaGraph(pos[randamumasuYB][randamumasuXB][0] + 140 - 4 * randamuzahyoukeisannhikiB, pos[randamumasuYB][randamumasuXB][1] - 200 + 8 * randamuzahyoukeisannhikiB, 2.0, 0 - kakudo4, kikennhanndle[1], TRUE);
				}
			}
			if (randamuzahyoukeisannhikiB > 24) {
				randamuzahyoukeisannB = 0;
				kakudo3 = 0;
				kakudo4 = 0;
			}
			//if (randamuzahyou > 40 && randamuzahyou < 60) {
				//DrawGraph(preenemyX3 - 500, preenemyY3-200, kikennhanndle[1], true);
			//}
			if (randamuzahyouB > 0 && ++randamuzahyouB > 20) {
				randamuzahyoulockBA = 1;
				//A = 5;
				randamuzahyouB = 0;
			}
			if (randamuzahyouB > 0 && randamuzahyouB < 20) {
				randamuzahyoulockB = 1;
			}
			if (randamuzahyoulockBA == 1) {
				if (randamumasuX == 0 && randamumasuY == 0) {
					B = 5;
					DrawRotaGraph(pos[randamumasuY][randamumasuX][0], pos[randamumasuY][randamumasuX][1], 1, 0, kikennhanndle[1], TRUE);
					if (pos[randamumasuY][randamumasuX][0] == pos[playerY][playerX][0] && pos[randamumasuY][randamumasuX][1] == pos[playerY][playerX][1]) {
						if (randammasucountB > 0 && randammasucountB < 2) {
							playerHPsubun = 51;
							damgesinndou = 1;
						}
					}
				}
				if (randamumasuX == 1 && randamumasuY == 0) {
					B = 5; randammasucount = 1;
					DrawRotaGraph(pos[randamumasuY][randamumasuX][0], pos[randamumasuY][randamumasuX][1], 1, 0, kikennhanndle[1], TRUE);
					if (pos[randamumasuY][randamumasuX][0] == pos[playerY][playerX][0] && pos[randamumasuY][randamumasuX][1] == pos[playerY][playerX][1]) {
						if (randammasucountB > 0 && randammasucountB < 2) {
							playerHPsubun = 51;
							damgesinndou = 1;
						}
					}
				}
				if (randamumasuX == 2 && randamumasuY == 0) {
					B = 5; randammasucount = 1;
					DrawRotaGraph(pos[randamumasuY][randamumasuX][0], pos[randamumasuY][randamumasuX][1], 1, 0, kikennhanndle[1], TRUE);
					if (pos[randamumasuY][randamumasuX][0] == pos[playerY][playerX][0] && pos[randamumasuY][randamumasuX][1] == pos[playerY][playerX][1]) {
						if (randammasucountB > 0 && randammasucountB < 2) {
							playerHPsubun = 51;
							damgesinndou = 1;
						}
					}
				}
				if (randamumasuXA == 0 && randamumasuYA == 1) {
					B = 5; randammasucount = 1;
					DrawRotaGraph(pos[randamumasuYA][randamumasuXA][0], pos[randamumasuYA][randamumasuXA][1], 1.5, 0, kikennhanndle[1], TRUE);
					if (pos[randamumasuYA][randamumasuXA][0] == pos[playerY][playerX][0] && pos[randamumasuYA][randamumasuXA][1] == pos[playerY][playerX][1]) {
						if (randammasucountB > 0 && randammasucountB < 2) {
							playerHPsubun = 51;
							damgesinndou = 1;
						}
					}
				}
				if (randamumasuXA == 1 && randamumasuYA == 1) {
					B = 5; randammasucount = 1;
					DrawRotaGraph(pos[randamumasuYA][randamumasuXA][0], pos[randamumasuYA][randamumasuXA][1], 1.5, 0, kikennhanndle[1], TRUE);
					if (pos[randamumasuYA][randamumasuXA][0] == pos[playerY][playerX][0] && pos[randamumasuYA][randamumasuXA][1] == pos[playerY][playerX][1]) {
						if (randammasucountB > 0 && randammasucountB < 2) {
							playerHPsubun = 51;
							damgesinndou = 1;
						}
					}
				}
				if (randamumasuXA == 2 && randamumasuYA == 1) {
					B = 5; randammasucount = 1;
					DrawRotaGraph(pos[randamumasuYA][randamumasuXA][0], pos[randamumasuYA][randamumasuXA][1], 1.5, 0, kikennhanndle[1], TRUE);
					if (pos[randamumasuYA][randamumasuXA][0] == pos[playerY][playerX][0] && pos[randamumasuYA][randamumasuXA][1] == pos[playerY][playerX][1]) {
						if (randammasucountB > 0 && randammasucountB < 2) {
							playerHPsubun = 51;
							damgesinndou = 1;
						}
					}
				}
				if (randamumasuXB == 0 && randamumasuYB == 2) {
					B = 5; randammasucount = 1;
					DrawRotaGraph(pos[randamumasuYB][randamumasuXB][0], pos[randamumasuYB][randamumasuXB][1], 2, 0, kikennhanndle[1], TRUE);
					if (pos[randamumasuYB][randamumasuXB][0] == pos[playerY][playerX][0] && pos[randamumasuYB][randamumasuXB][1] == pos[playerY][playerX][1]) {
						if (randammasucountB > 0 && randammasucountB < 2) {
							playerHPsubun = 51;
							damgesinndou = 1;
						}
					}
				}
				if (randamumasuXB == 1 && randamumasuYB == 2) {
					B = 5; randammasucount = 1;
					DrawRotaGraph(pos[randamumasuYB][randamumasuXB][0], pos[randamumasuYB][randamumasuXB][1], 2, 0, kikennhanndle[1], TRUE);
					if (pos[randamumasuYB][randamumasuXB][0] == pos[playerY][playerX][0] && pos[randamumasuYB][randamumasuXB][1] == pos[playerY][playerX][1]) {
						if (randammasucountB > 0 && randammasucountB < 2) {
							playerHPsubun = 51;
							damgesinndou = 1;
						}
					}
				}
				if (randamumasuXB == 2 && randamumasuYB == 2) {
					B = 5; randammasucount = 1;
					DrawRotaGraph(pos[randamumasuYB][randamumasuXB][0], pos[randamumasuYB][randamumasuXB][1], 2, 0, kikennhanndle[1], TRUE);
					if (pos[randamumasuYB][randamumasuXB][0] == pos[playerY][playerX][0] && pos[randamumasuYB][randamumasuXB][1] == pos[playerY][playerX][1]) {
						if (randammasucountB > 0 && randammasucountB < 2) {
							playerHPsubun = 51;
							damgesinndou = 1;
						}
					}
				}
			}
			if (randammasucount > 0) {
				++randammasucountB;
				//randamuzahyouB = 0;
			}
			//マスに落ちたアイテム
			if (randammasucountB > 0 && randammasucountB > 15) {
				randamuzahyoulockBA = 0;
				//randamulock = 0;
			}
			if (randammasucountB > 15) {
				//☆とりあえず、変数の残り値によってバグではないがプログラム通りとは言え複雑な変な動きが出るので、ここで値をすべて0にする。
				randammasucount = 0;
				randammasucountB = 0;
				B = 0;
				stopenemy = 0;
				kasokudo2 = 0;
				randamuzahyoukeisannhikiB = 0;
				randamuzahyoukeisannB = 0;
				Y = 0;
				randamuzahyoulockB = 0;
				test = 0;
				ranndamukougeki = 0;
				randamumasuX = 0;
				randamumasuXA = 0;
				randamumasuXB = 0;
				randamulock = 0;
				randamulock2 = 0;
			}


			//投げ道具が降ってくるこの間だけ危険マークを描画する。
			if (randamuzahyoukeisannhiki > 0 && randamuzahyoukeisannhiki < 7) {
				++kaihimark;
			}
			if (randamuzahyoukeisannhikiB > 0 && randamuzahyoukeisannhikiB < 7) {
				++kaihimark;
			}
			//投げ攻撃が来る部分にマークが出る
			if (kaihimark > 0 && ++kaihimark < 7) {

				if (bairituY == 4.6) {
					DrawRotaGraph(pos[randamumasuY][randamumasuX][0] + 30, pos[randamumasuY][randamumasuX][1] + 30, 1.0, 0, kikennhanndle[3], TRUE);
				}
				if (bairituY == 5.0) {
					DrawRotaGraph(pos[randamumasuYA][randamumasuXA][0] + 30, pos[randamumasuYA][randamumasuXA][1] + 30, 1.5, 0, kikennhanndle[3], TRUE);
				}
				if (bairituY == 5.4) {
					DrawRotaGraph(pos[randamumasuYB][randamumasuXB][0] + 30, pos[randamumasuYB][randamumasuXB][1] + 30, 2.0, 0, kikennhanndle[3], TRUE);
				}
				DrawRotaGraph(500, 2000, 1.0, 0, randamuzahyoukeisannhikiB, TRUE);
			}
			if (kaihimark > 7) {
				kaihimark = 0;
			}
		}
		//if (damgesinndou == 1){ StartJoypadVibration(DX_INPUT_PAD1, 10, 2); }


		//敵のHPの描画
		//敵のHPが0になった際に攻撃をやめるようにstayhereを1にする。test.cppに書いた。

		//DrawFormatString(10, 70, GetColor(255, 0, 0), "playerHP%d", playerHP);


		if (enemyHPhyouji == 1) { DrawFormatString(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] + playerattackhanndou3 - 100, GetColor(255, 0, 0), "enemyHP%d", enemyHP); }

		

		//敵がやられた際にHPが消えて、敵の動きが止まるように書いた。
		if (enemysabunHP >= enemyHP && stayherelock == 1 || KenemysabunHP >= enemyHP && stayherelock == 1 || GenemysabunHP >= enemyHP && stayherelock == 1 || enemysabunHPA >= enemyHP && stayherelock == 1 || enemysabunHPB >= enemyHP && stayherelock == 1) {
			enemybyougablock3 = 1;//初期画像がでないように。
			enemyzannzoulock = 1;
			//enemybyougablock = 1;
			//playerkonntororulock = 1;//敵を倒した後は操作できないように1にする。
			//enemyzannzoulock = 1;
			sousakanou = 1;//★この変数のおかげで敵を倒した後に主人公は消えずに描画される。
			//overattacklock = 1;
			//playerkonntororulock = 0;//敵を倒したら攻撃できないようにするための変数。
			enemyHPhyouji = 0; //敵のHPの表記を消す
			stayhere3 = 1;//攻撃をやめる、また初期位置と被らないために1ではなく、2とした。
			stayherelock = 1;//0のままだと初期位置の敵の画像が出てしまうので、ここで1にする。
			mark = 0;//★しかし、ダメージが多いとフレーム処理が長いため敵が1で消えるがtest2.cppで再び現れて消えるため、あまりいい消え方ではない
			//なのでenemystayhere = 1ではなく、markを1として、すぐにtest2.cppに移動して、消えるようにした。消えた後でenemystayhereを一とした。
			enemyHP = 0;
			ENEMYkougekigazouA1lock = 0;//敵が攻撃する際に値が繰り上がったままだと敵の攻撃が描画されるので、ここで0にする。
			ENEMYkougekigazouA2frame = 0;
			//enemystayhere = 1;//敵を描画しないために値を1にした。またif (enemystayhere > 1 && enemystayhere < 50) の条件に引っ掛かり固定した敵が出てこない様にenemystayhere > 1と変更した。
			//敵を倒した際に敵が徐々に消えていく原理について。//
			//kougekilock = 0;//攻撃のフレームの問題でフレームの上がっている間はkougekilockは0にならないため、敵が消えるのに一瞬描画されたりと変な感じになるので0にした。
			Gtime = 0;
			enemyhanntoumei3 = 1;
		}
		else if (enemyHP == 0 && stayherelock == 1) {//★敵のHPと攻撃が同じ数値の時は＞の条件に入っていなかったのでここで付け足した。それにより同じ値の時でも相手のHPが消えるようにできた
			enemybyougablock3 = 1;//初期画像が出ないように。
			enemyzannzoulock = 1;
			//enemybyougablock = 1;									 //enemyzannzoulock = 1;
			sousakanou = 1;//★この変数のおかげで敵を倒した後に主人公は消えずに描画される。									 
			//playerkonntororulock = 1;//敵を倒した後は操作できないように1にする。
			enemyHPhyouji = 0; //敵のHPの表記を消す
			stayhere3 = 1;//攻撃をやめる
			stayherelock = 1;//0のままだと初期位置の敵の画像が出てしまうので、ここで1にする。
			mark = 0;
			enemyHP = 0;
			//enemystayhere = 1;//敵を描画しないために値を1にした。またif (enemystayhere > 1 && enemystayhere < 50) の条件に引っ掛かり固定した敵が出てこない様にenemystayhere > 1と変更した。
			//敵を倒した際に敵が徐々に消えていく原理について。//
			ENEMYkougekigazouA1lock = 0;
			ENEMYkougekigazouA2frame = 0;
			Gtime = 0;
			enemyhanntoumei3 = 1;
		}

		//DrawFormatString(50, 400, GetColor(255, 0, 0), "%d/%d", Kcount, Kcount2);

		//DrawFormatString(150, 400, GetColor(255, 0, 0), "%d/%d", Wcount, Wcount2);
		//DrawFormatString(250, 650, GetColor(255, 100, 100), "framesは%d", frames);



		//DrawFormatString(50, 500, GetColor(255, 0, 0), "%d", addattackimage);//★addattacktimeが攻撃に続けば500になるし、それ以外では初期値より0なのでずっと下がっているわけではない
		//if (addattacktime <= 300 && addattacktime > 0) {
		//	--addattacktime;
			//DrawFormatString(50, 450, GetColor(255, 0, 0), "addattacktime%d", addattacktime);
		//}//ロックオンして攻撃するまでの間のみ出てくる。
//★上限や下限はないが、変数の値をセットすることで切り替えることはできる。今回はそれを活用して変数の値を一時的に固定したり変えたりしている。

		//DrawFormatString(50, 470, GetColor(255, 0, 0), "確認addattacktime%d", addattacktime);
		///DrawFormatString(50, 500, GetColor(255, 0, 0), "stopenemytime%d", stopenemytime);
		///DrawFormatString(50, 570, GetColor(255, 150, 170), "function_statusは%d", function_status);
		//DrawFormatString(50, 585, GetColor(255, 0, 0), "Gtime%d", Gtime);
		///DrawFormatString(150, 585, GetColor(255, 0, 0), "GtimeA%d", GtimeA);




		//if (GcountA == 0) {
		//	DrawFormatString(200, 600, GetColor(255, 0, 0), "グロッグ射撃可能");
		//	DrawFormatString(50, 600, GetColor(255, 0, 0), "Gcount%d/Gcount%d", Gcount, Gcount2);
		//}

		//if (MGcountA == 0) {
		//	DrawFormatString(250, 650, GetColor(255, 0, 0), "マシンガン射撃可能");
		//	DrawFormatString(50, 650, GetColor(255, 0, 0), "MGcount%d/MGcount%d", MGcount, MGcount2);
		//}
		//if (MGcountA == 1) {
			//被らないようにするとなるとGfunction_status == 0の時にMGcountAを0にしても勝手にリロードされる。
			//被らないような新しい変数を良いすればいいかもしれないが、誤作動とかを考えると何の武器を選んでいるか把握できた方がいいかもしれない。
			//DrawFormatString(200, 650, GetColor(255, 255, 0), "マシンガンリロード中");
		//}


		//if (Gfunction_status == 1 && MGcountA == 0) {
		//	DrawFormatString(250, 650, GetColor(255, 255, 0), "マシンガン射撃可能");
		//	DrawFormatString(50, 650, GetColor(255, 255, 0), "MGcount%d/MGcount%d", MGcount, MGcount2);
		//}

		//DrawFormatString(200, 500, GetColor(255, 0, 0), "敵が攻撃してくるまでenemyattackは%dでenemyattackBは%d", enemyattack, enemyattackB);
		//DrawFormatString(50, 620, GetColor(255, 0, 0), "protectは%d、protectcountは%d", protect, protectcount);
		//DrawFormatString(290, 630, GetColor(255, 0, 0), "enemycountframeは%d,enemycount%d", enemycountframe, enemycount);
		//DrawFormatString(100, 150, GetColor(255, 0, 100), "enemycount%d", enemycount);
		//DrawFormatString(320, 540, GetColor(255, 0, 0), "Gkeyは%d,Gfunction_statusは%d,Grockは%d,reloadは%d", Gkey, Gfunction_status, Grock, reload);
		//DrawFormatString(320, 560, GetColor(255, 0, 0), "GcountAは%d,MGcountAは%d", GcountA, MGcountA);
		//DrawFormatString(320, 580, GetColor(255, 0, 0), "lockは%d,lockonMoveは%d,zannzouは%d", lock, lockonMove, zannzou);
		//DrawFormatString(200, 680, GetColor(255, 0, 0), "a%d,nageXは%d,randamulockは%d,preenemyX2は%d, preenemyY2は%d", a, nageX, randamulock, preenemyX2, preenemyY2);
		//DrawFormatString(200, 740, GetColor(255, 0, 0), "nageXAは%d,preenemyX2Aは%d,preenemyY2Aは%d,Xは%d", nageXA, preenemyX2A, preenemyY2A,X);
		//DrawFormatString(0, 700, GetColor(255, 12, 160), "→ENEMYkougekigazouA1frameは%d,enemyattackは%d,ENEMYkougekigazouA2frameは%d,pos[playerY][playerX][1]は%d", ENEMYkougekigazouA1frame, enemyattack, ENEMYkougekigazouA2frame, pos[playerY][playerX][1]);
		//DrawFormatString(0, 750, GetColor(255, 90, 160), "→ENEMYkougekigazouA2frameは%d,pos[playerY][playerX][1]は%d",ENEMYkougekigazouA2frame, pos[playerY][playerX][1]);

		//DrawFormatString(0, 850, GetColor(255, 0, 0), "kasokudoは%d,kasokudo2は%d,kasokudo3は%d,Yは%d", kasokudo, kasokudo2, kasokudo3, Y);
		//DrawFormatString(100, 900, GetColor(255, 0, 0), "固定preenemyX3は%d,後preenemyX3Aは%d,差分preenemyX3Bは%d", preenemyX3, preenemyX3A, preenemyX3B);
		//DrawFormatString(100, 950, GetColor(255, 0, 0), "高さpreenemyY3Aは%d,randamumasuXは%d,randamumasuYは%d", preenemyY3A, randamumasuX, randamumasuY);
		//	DrawFormatString(100, 1000, GetColor(255, 0, 0), "randamumasuXは%d,randamumasuYは%d", randamumasuX,randamumasuY);
		//DrawFormatString(0, 100, GetColor(255, 0, 0), "attackframe3は%d,★R1lockは%d,premasuframeは%d,premasuframe2は%d", attackframe3, R1lock, premasuframe, premasuframe2);
		//DrawFormatString(0, 50, GetColor(255, 0, 0), "nagurugazouは%d,zannzoulockは%d,zannzouは%d,zannzouAは%d,zannzouBは%d,zannzouCは%d,randammasucountBは%d,aaは%d", nagurugazou, zannzoulock, zannzou, zannzouA, zannzouB, zannzouC, randammasucountB, aa);
		//DrawFormatString(0, 200, GetColor(25, 98, 12), "attackframe2は%d,sennkounyuuryokubunnki2は%d,sennkounyuuryokubunnkiは%d", attackframe2, sennkounyuuryokubunnki2, sennkounyuuryokubunnki);

		//背景をピシッと張るためにステージの座標を描画した部分。
		//DrawFormatString(100, 450, GetColor(5, 111, 44), "stage[0][0][0]は%d,stage[0][0][1]は%d,stage[0][7][0]は%d", stage[0][0][0], stage[0][0][1], stage[0][6][0]);
		//DrawFormatString(200, 900, GetColor(255, 0, 0), "addattacktimeは%d", addattacktime);
		//DrawFormatString(150, 900, GetColor(255, 130, 100), "bloodMoveは%d、sinnzoubyougaは%d", bloodMove, sinnzoubyouga);

		//DrawFormatString(100, 1150, GetColor(255, 0, 0), "startは%d、Seenは%d,enemymovelockは%d,enemystayhereは%d", start, Seen, enemymovelock, enemystayhere);
		//DrawFormatString(0, 200, GetColor(255, 0, 0), "nomalidouは%d、sennkounyuuryokujyuujikiframeは%d", nomalidou, sennkounyuuryokujyuujikiframe);

		//DrawFormatString(100, 550, GetColor(255, 154, 230), "lockdekinaiは%d、kougekilockは%d,R1lockは%d", lockdekinai, kougekilock, R1lock);
		//DrawFormatString(200, 700, GetColor(255, 54, 200), "lockmarkは%d,pos[enemyY][enemyX][1]は%d", lockmark, pos[enemyY][enemyX][1]);
		//DrawFormatString(200, 370, GetColor(255, 54, 230), "注目　stayherelockは%d、enemystayhereは%d,kougekilockは%d", stayherelock, enemystayhere, kougekilock);

	}

	//一列に突進する攻撃の描画
	//一番上の列の攻撃
	if (a == 1) {
		enemyattack3 = 1;
		posX = 0;
		//DrawGraph(pos[0][5][0] + 30, pos[0][5][1], playerGHandle[1], true);//左上ちょっと左に画像をセット
		++imagecount;//imagecount = 1としていたが、これで再び8以外の時も再び8が来ても途中で消えたりしないようにした。
		++enemyimagecount;

	}
	if (a == 2) {
		enemyattack3 = 1;
		posX = 1;
		//DrawGraph(pos[0][5][0] + 30, pos[0][5][1], playerGHandle[1], true);//左上ちょっと左に画像をセット
		++imagecount;//imagecount = 1としていたが、これで再び8以外の時も再び8が来ても途中で消えたりしないようにした。
		++enemyimagecount;

	}
	if (a == 5) {
		enemyattack3 = 1;
		posX = 2;
		//DrawGraph(pos[0][5][0] + 30, pos[0][5][1], playerGHandle[1], true);//左上ちょっと左に画像をセット
		++imagecount;//imagecount = 1としていたが、これで再び8以外の時も再び8が来ても途中で消えたりしないようにした。
		++enemyimagecount;

	}
	// !! 原因
	// 敵の突進の動作を作っていると思われる次のプログラムにあるpos[i][j][0]が原因と思われます。
	// pos[i][j][0] = pos[posX][5][0] + 300 - 40 * imagecount
	//
	// playerhennsuu.hにあるinit_stage()内のはじめの2重forで終了したグローバル変数i, jに着目しました。
	// このとき、i=-1, j=7という値がpos[-1][7][0]というように入るのですが、pos配列はplayerhennsuu.hによると、[3][6][2]で定義されています。
	// 定義外の配列データを参照しようとした結果、内部的にオーバーフロー起こし、
	// 主人公が陣地の左上真ん中の位置に移動すると消えてしまったり、突進してくる相手と一緒に横に移動してしまうバグが起きていたと思われます。
	//int tosshin = 0, tosshin2 = 0, tosshin3 = 0;	// !! 新たにtosshinを定義しました
	//★pos[i][j][0]の定義の範囲を超える距離（pos[posX][5][0] + 300 - 30 * imagecount）を代入したことで、最初に定めたpos[i][j][0]の定義では扱え切れずにバグを起こした。
	//なので特に範囲のない新しい変数tosshinを作り使ったことでどんな距離（pos[posX][5][0] + 300 - 30 * imagecount）でも範囲なく扱えるようにした。
	// !! 以下、pos[i][j][0]をtosshinに変更しました
	if (imagecount > 0 && imagecount < 200) {
		tosshin = pos[posX][5][0] + 300 - 10 * imagecount;
		//if (pos[i][j][0]) {
		//DrawBox(pos[playerY][playerX][0] + 10 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3
		//	, pos[playerY][playerX][1] + 15 + nanameidouY + nanameidouY2 + nanameidouY3
		//	, pos[playerY][playerX][0] - 10 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3
		//	, pos[playerY][playerX][1] - 15 + nanameidouY + nanameidouY2 + nanameidouY3
		//	, Bule, TRUE);   // 四角形を描画(塗りつぶし))

		//DrawBox(pos[posX][0][0] + 150 
		//	, pos[posX][0][1]+ 20
		//	, pos[posX][0][0] - 150 
		//	, pos[posX][0][1]- 20
		//	, Red, TRUE);
			//DrawExtendGraph(pos[enemyY][enemyX][0] - 14, pos[enemyY][enemyX][1] - 66, pos[enemyY][enemyX][0] + 64, pos[enemyY][enemyX][1] + 66, enemyImage, TRUE);
		//}
		//フレームを使わないとダメージが加算で結構なダメージになるので、あえてフレームを利用する。
		if (imagecount >= 98 && imagecount < 99) {
			if (pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3
		> pos[posX][5][0] - 150 &&
				pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3
				< pos[posX][5][0] + 150 &&

				pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
				> pos[posX][5][1] - 20 &&
				pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
				< pos[posX][5][1] + 20)
				playerHPsubun = 51;
		}
		else if (imagecount >= 103 && imagecount < 104) {
			if (pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3
		> pos[posX][4][0] - 150 &&
				pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3
				< pos[posX][4][0] + 150 &&

				pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
				> pos[posX][4][1] - 20 &&
				pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
				< pos[posX][4][1] + 20)
				playerHPsubun = 51;
		}
		else if (imagecount >= 118 && imagecount < 119) {
			if (pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3
		> pos[posX][3][0] - 150 &&
				pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3
				< pos[posX][3][0] + 150 &&

				pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
				> pos[posX][3][1] - 20 &&
				pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
				< pos[posX][3][1] + 20)
				playerHPsubun = 51;
		}
		else if (imagecount >= 123 && imagecount < 124) {
			if (pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3
		> pos[posX][2][0] - 150 &&
				pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3
				< pos[posX][2][0] + 150 &&

				pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
				> pos[posX][2][1] - 20 &&
				pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
				< pos[posX][2][1] + 20)
				playerHPsubun = 51;
		}
		else if (imagecount >= 128 && imagecount < 129) {
			if (pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3
		> pos[posX][1][0] - 150 &&
				pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3
				< pos[posX][1][0] + 150 &&

				pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
				> pos[posX][1][1] - 20 &&
				pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
				< pos[posX][1][1] + 20)
				playerHPsubun = 51;
		}
		else if (imagecount >= 135 && imagecount < 136) {
			if (pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3
		> pos[posX][0][0] - 150 &&
				pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3
				< pos[posX][0][0] + 150 &&

				pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
				> pos[posX][0][1] - 20 &&
				pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
				< pos[posX][0][1] + 20)
				playerHPsubun = 51;
		}
		//最後まで進んだらenemyattack3が0に戻り、再びランダム関数が動くようにした。
	}
	if (enemyimagecount > 0 && enemyimagecount < 20) {
		DrawRotaGraph(pos[posX][5][0] + 500 - 10 * imagecount, pos[posX][5][1], 5.0, 0, enemy2Handle[0], TRUE);
		//	DrawExtendGraph(pos[i][j][0] - 14 + 700, pos[posX][5][1] - 66, pos[i][j][0] + 64 + 700, pos[posX][5][1] + 66, playerGHandle[1], true);//拡大した物
	}
	if (enemyimagecount > 20 && enemyimagecount < 40) {
		DrawRotaGraph(pos[posX][5][0] + 500 - 10 * imagecount, pos[posX][5][1], 5.0, 0, enemy2AHandle[0], TRUE);
		//DrawExtendGraph(pos[i][j][0] - 14 + 700, pos[posX][5][1] - 66, pos[i][j][0] + 64 + 700, pos[posX][5][1] + 66, playerGHandle[7], true);//拡大した物
	}



	if (enemyimagecount > 40) { enemyimagecount = 1; }
	if (a == !1 || a == !2 || a == !5) { imagecount = 0; enemyattack3 = 0; enemyimagecount = 0; }//確率で8を選んでいる間も仮に0になっても++により増えてしまい一周だけ描画されてしまうので8意外になったら0にするようにすれば描画する座標は関係なくなるので一瞬の描画関係なくなる。
	//仮に8が続いてもa ==!8より座標とは関係ない様に書いてあるので一瞬描画されるようなことはない。
	if (a == 8 || a == 3 || a == 4 || a == 6 || a == 7 || a == 9 || a == 10) {
		imagecount = 0; enemyimagecount = 0;
	}//これを付け足したらほぼ必ず0になる。
	if (imagecount > 300) { imagecount = 0; enemyattack3 = 0; enemyimagecount = 0; a = 0; kurumaisucount = 0; }//上のだけでは分岐ゆえに無反応な時があるのでこいつも書いておく。
	//☆8が他の数値になるよりも長ければ中途半端に8の時の変数が反応しないので60より大きくした。仮に50とかだったら一瞬だけ描画され消えるような問題が起きてしまだろう。
	//★if (imagecount > 60)のカッコに a = 0を加えるとランダムで同じ値が連続することでその列をずっと走り、途中で消えたりすることなく
	//ちゃんと走りぬくようになり、かつランダムで連続が続かないので程よい攻撃をしてくる。
	//一列に突進する攻撃の描画
	//真ん中の列の攻撃





	if (playerkonntororulock == 0) {
		//回復を表す♡マーク
		if (tabakokaihukumark > 0) {//1フレームで処理を終わらせるためifの後はelse ifを使った。//フレームがあってもplayerMove++を書かないと1ずつ上がらない。playerMove++をフレームの60回ループするするところに書くことで以下のように書いて足踏みしている画像が描けた。
			tabakokaihukumark++;//60フレームの中で、このifで条件(playerMove > 0)が真であるためplayerMove++を「フレーム」と「条件式」により繰り返しplayerMove++して、
			if (tabakokaihukumark > 0 && tabakokaihukumark < 20)//以前の文を否定しないelse ifが次にあるためplayerMoveの情報を引き継ぎplayerMove == 20となるまで繰り返しplayerMove++をした。次にもelse ifがあるので同様、、、
			{

				//DrawExtendGraph(pos[playerY][playerX][0], pos[playerY][playerX][1] - 200, pos[playerY][playerX][0] + 60, pos[playerY][playerX][1] - 100, hartmarkhanndle[0], TRUE);
				//DrawFormatString(pos[playerY][playerX][0] + 60, pos[playerY][playerX][1] - 200, GetColor(255, 0, 0), "与えたダメージは%d", toenemyHPdamage);
				DrawRotaGraph(pos[playerY][playerX][0] + 25, pos[playerY][playerX][1] - 150, bairituX, 0, hartmarkhanndle[0], TRUE);

			}
			if (tabakokaihukumark > 20 && tabakokaihukumark < 40)//条件式として書くため=は==と書いた。//else ifによりplayerMoveが20を超えて(20の場合を否定し)30の場合を表す。
			{

				//DrawExtendGraph(pos[playerY][playerX][0], pos[playerY][playerX][1] - 200, pos[playerY][playerX][0] + 60, pos[playerY][playerX][1] - 100, hartmarkhanndle[1], TRUE);
				DrawRotaGraph(pos[playerY][playerX][0] + 25, pos[playerY][playerX][1] - 150, bairituX, 0, hartmarkhanndle[1], TRUE);

			}
			if (tabakokaihukumark > 40 && tabakokaihukumark < 60) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた
				//上に書いてることには誤りがある、60フレームで1sなだけ、超えてもいい。
				//DrawExtendGraph(pos[playerY][playerX][0], pos[playerY][playerX][1] - 200, pos[playerY][playerX][0] + 60, pos[playerY][playerX][1] - 100, hartmarkhanndle[2], TRUE);
				DrawRotaGraph(pos[playerY][playerX][0] + 25, pos[playerY][playerX][1] - 150, bairituX, 0, hartmarkhanndle[2], TRUE);

				tabakokaihukumark = 0;//
			}

		}

		//敵にダメージが入ると心臓のギフが描画されるようにして、次第に薄くなって消えるプログラム
		//if (sinnzoubyouga == 1) {
		//	sinnzougazoulock = 1;
		//}
		//if (sinnzougazoulock == 1) {
		//	++sinnzoutoumeika;

		//	if (sinnzoutoumeika > 0) {
		//		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 70 - sinnzoutoumeika);		//ブレンドモードをα(128/255)に設定
		//		DrawExtendGraph(0, 0, 1770, 980, sinnzouGraphHandle, FALSE);
		//	}
		//	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをリセット（他の画像が薄くならないようにするため）	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - toumeika);		//ブレンドモードをα(128/255)に設定
		//}
		//if (sinnzoutoumeika > 100)
		//{
		//	sinnzoutoumeika = 0;
		//	sinnzougazoulock = 0;
		//	sinnzoubyouga = 0;
		//}

		//敵に攻撃した時の敵から出る血の描画のための部分。
		if (bloodMove > 0) {//1フレームで処理を終わらせるためifの後はelse ifを使った。//フレームがあってもplayerMove++を書かないと1ずつ上がらない。playerMove++をフレームの60回ループするするところに書くことで以下のように書いて足踏みしている画像が描けた。
			bloodMove++;//60フレームの中で、このifで条件(playerMove > 0)が真であるためplayerMove++を「フレーム」と「条件式」により繰り返しplayerMove++して、
			sinnzoubyouga = 1;
			if (bloodMove == 10)//以前の文を否定しないelse ifが次にあるためplayerMoveの情報を引き継ぎplayerMove == 20となるまで繰り返しplayerMove++をした。次にもelse ifがあるので同様、、、
			{
				bloodImage = bloodGHandle[0];
			}
			else if (bloodMove == 30)//条件式として書くため=は==と書いた。//else ifによりplayerMoveが20を超えて(20の場合を否定し)30の場合を表す。
			{
				bloodImage = bloodGHandle[1];
			}
			else if (bloodMove == 60)//30まで上がったものが40に上がった時、playerGHandle[4]になる。if文の連続では文法のルールで前の文を否定するため連続的に画像が流れず足踏みできない、なのでelse ifにしたのだ。
			{
				bloodImage = bloodGHandle[2];
				bloodMove = 0;//
				sinnzoubyouga = 0;//sinnzoubyougaが0より大きい時はbloodMoveが繰り返すので心臓の描画を消すのを利用してbloodの描画を繰り返さないようにした。っていうか心臓の描画もいらないかもしれない。

			}

		}
		//敵がダメージを受けると血が噴き出す。sinnzoutoumeikaの上がる値を利用する。
		if (sinnzoubyouga > 0) {
			//++bloodMove;
			//enemystayhere = 0;//たぶんここで敵の通常の動きを消して、やられたときの動きと血しぶきにする。
			//++enemymigi;
			DrawExtendGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 14 + (20), pos[enemyY][enemyX][1] - (30) + playerattackhanndou3, pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 64 + (30), pos[enemyY][enemyX][1] + playerattackhanndou3, bloodImage, TRUE);

		}
	}
	if (playerkonntororulock == 0) {


		//タバコ回復の描画の部分
		if (tabakokasanari == 0) {
			if (tabakocount2 > 0) {
				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, playertabakoImage, TRUE);
			}
			if (tabakocount2 > 0 && tabakocount2 < 50)
			{
				playertabakoImage = playertabakoAHandle[0];
			}
			if (tabakocount2 > 50 && tabakocount2 < 100)
			{
				playertabakoImage = playertabakoBHandle[0];
			}
			if (tabakocount2 > 100 && tabakocount2 < 150)
			{
				playertabakoImage = playertabakoCHandle[0];
			}
			if (tabakocount2 > 150 && tabakocount2 < 200)
			{
				playertabakoImage = playertabakoDHandle[0];
			}
		}
		if (pos[enemyY][enemyX][0] + 200 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
			pos[enemyY][enemyX][0] - 200 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3
			&& pos[enemyY][enemyX][1] + playerattackhanndou3 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3) {
			tabakokasanari = 1;
		}
		else {
			tabakokasanari = 0;
		}

		//★★敵と重なり描画されていしまう問題の解決の方法。
		//他のタバコを吸うプログラムで通常状態の主人公が描画されないようにzannzoulockが1になり、
		//playertabakoImageに値が入るようになっているので以下のように書くだけでいいのだ。その前の時はタバコを吸う画像は最後に書いていたので
		//敵を越してタバコを吸う画像を描画してしまっていた。しかし、そのタバコを吸う画像を超えて、if文で敵の画像を改めて描画したので
		//敵を超えることなく、書いた通りに描画された。


	}



	//物理的なダメージ判定のための範囲の確認の描画。
	//DrawBox(pos[enemyY][enemyX][0] - 30 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] + playerattackhanndou3 - 25,
	//	pos[enemyY][enemyX][0] + 30 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] + playerattackhanndou3 + 25, RED, FALSE);


	//銃のダメージ判定のための範囲の確認の描画。
	//DrawBox(pos[enemyY][enemyX][0] - 30, pos[enemyY][enemyX][1] - 25,
	//	pos[enemyY][enemyX][0] + 30, pos[enemyY][enemyX][1] + 25, White, FALSE);


	//攻撃判定その一(銃による攻撃判定)
	if (hannilock == 2) {
		if (pos[enemyY][enemyX][0] - 30 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 < lockmarkXzahyou && pos[enemyY][enemyX][0] + 30 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 > lockmarkXzahyou
			&& pos[enemyY][enemyX][1] - 25 + playerattackhanndou3 < lockmarkYzahyou && pos[enemyY][enemyX][1] + 25 + playerattackhanndou3 > lockmarkYzahyou)
		{


			//LEFTmark = 556;
			kougekiKANOU = 1;
			//playerkougekiXzahyou = lockmarkXzahyou;
			//playerkougekiYzahyou = lockmarkYzahyou;

		}
		else {

			kougekiKANOU = 0;
			//lockmarkXzahyou = lockmarkXzahyou - 100;
			//lockmarkYzahyou = 0;
		}
	}

	//攻撃中の重なる判定
	//if (pos[enemyY][enemyX][0] > pos[playerY][playerX][0]) {
	//	if (nagurukasanaru == 1) {
	//		//LEFTmark = 4632;
	//		zannzoulock = 1;
	//		enemyzannzoulock = 1;
	//		//enemystayhere = 1;//★if文の書き方によりenemyzannzoulockが1の時点でこいつは0でも1でも関係なく敵は消える。
//
//			//DrawRotaGraph(pos[enemyY][enemyX][0], pos[enemyY][enemyX][1], 4, 0, enemyImage, TRUE);
	//		DrawRotaGraph(pos[playerY][playerX][0] + 20 + (130), pos[playerY][playerX][1] - 13, 5, 0, playernaguruImage, TRUE);
	//
		//}


	//	if (KONNBO1kasanaru == 1) {
			//KONNBO1Aframe1 = 0;
			//LEFTmark = 32;
	//		zannzoulock = 1;
	//		enemyzannzoulock = 1;
			//enemystayhere = 1;//★if文の書き方によりenemyzannzoulockが1の時点でこいつは0でも1でも関係なく敵は消える。

	//		DrawRotaGraph(pos[enemyY][enemyX][0], pos[enemyY][enemyX][1], 4, 0, enemyImage, TRUE);
	//		DrawRotaGraph(pos[playerY][playerX][0], pos[playerY][playerX][1], 5, 0, playerKONNBO1AHandle[0], TRUE);

	//	}
	//	if (KONNBO2kasanaru == 1) {
			//LEFTmark = 7777;
			//KONNBO1B = 0;
		//	zannzoulock = 1;
		//	enemyzannzoulock = 1;
			//enemystayhere = 1;//★if文の書き方によりenemyzannzoulockが1の時点でこいつは0でも1でも関係なく敵は消える。

		//	DrawRotaGraph(pos[enemyY][enemyX][0], pos[enemyY][enemyX][1], 4, 0, enemyImage, TRUE);
		//	DrawRotaGraph(pos[playerY][playerX][0], pos[playerY][playerX][1], 5, 0, playerKONNBO1BHandle[0], TRUE);
		//}

	//}




	//if (SHOTbyouga > 0 ) { //銃を撃ってから２秒( 120 )経過したら
	//	++SHOTbyouga;
	//}
	//if (SHOTbyouga == 1) {
	//	
	//	PlayMovieToGraph(SHOTHandle);
	//	LEFTmark = 456;
	//}
	//if (SHOTbyouga > 1&& SHOTbyouga< 100) {
	//	DrawExtendGraph(pos[playerY][playerX][0] +100, pos[playerY][playerX][1] - 80, 
	//		pos[playerY][playerX][0] + 200, pos[playerY][playerX][1]-60, SHOTHandle, FALSE);

	//}
	//if (SHOTbyouga > 100) {
	//	LEFTmark = 121;
	//	SHOTbyouga = 0;
	//}

	//主人公を描画するための値の部分、ここで描画する関数に渡す引数の値を変えたりして主人公が動いたりしている。
		//★playerImageに値を入れる以前に静画の主人公が描画されていて、その描画している関数に値を代入して画像を切り替えている。
		//仮に画像が切り替わらなくても消えることはない、そしてif文は4つに分けているため、一方を通りわけではないので==書いても
		//瞬間瞬間に消えることはない。まあ、playerImageに値を入れる以前に静画の主人公が描画されているというのが大きいが。

	//if文のみは切り替わるがelse ifは前のif文の情報を継ぐので前の画像が残る。あとはif文の富豪次第でスムーズになる。＞とかはずっと描画
	//するとかで＝＝よりも重くなるのかもしれない。しかしifを使った後でelse ifなら＞や==でいいが、ただのifを使う場合はその一瞬しか描画されないのでずっと描画するならば＞とかの方がいい。
	//ただplayerImageでまとめておかないとその関数を呼んだ一瞬しか描画されないのでelse ifを使うならば関数が呼び出された後のことも考えplayerImageなど
	//に画像の情報をまとめておき、要は、関数自体はずっと呼ばれている状態なのでplayerImageを取り換えるだけなのでelse ifで＞と同じような一瞬ではなくずっと描画される働きになる。
	//関数のみを使ってのif elseは関数自体がその時にしか呼ばれないので一瞬しか描画されない。


	//if (playerHPlock == 0 && playerHP > 200) {//★主人公が攻撃している最中に通常状態や瀕死状態での画像が描画されないようにplayerHPlockがある。なぜplayerHPlockなんて名前にしたのかはわからない。
	//	hinnsiattack = 0;//回復した際に0になるようにする。
	//	KABURI = 0;//★HPが200以上の時は通常状態の重なりを有効にするために0にする。
		//zannzoulock = 0;//瀕死状態からタバコ回復で回復した際に再び元の画像に戻れるようにここで0にする。
		//tabakomark = 23939;
	if (playerMove == 1) {//1フレームで処理を終わらせるためifの後はelse ifを使った。//フレームがあってもplayerMove++を書かないと1ずつ上がらない。playerMove++をフレームの60回ループするするところに書くことで以下のように書いて足踏みしている画像が描けた。
		playerMove2++;//60フレームの中で、このifで条件(playerMove > 0)が真であるためplayerMove++を「フレーム」と「条件式」により繰り返しplayerMove++して、

		if (playerMove2 == 20)//以前の文を否定しないelse ifが次にあるためplayerMoveの情報を引き継ぎplayerMove == 20となるまで繰り返しplayerMove++をした。次にもelse ifがあるので同様、、、
		{
			playerImage = playerGHandle[1];
		}
		else if (playerMove2 == 40)//条件式として書くため=は==と書いた。//else ifによりplayerMoveが20を超えて(20の場合を否定し)30の場合を表す。
		{
			playerImage = playerGHandle[2];
		}
		else if (playerMove2 == 60)//30まで上がったものが40に上がった時、playerGHandle[4]になる。if文の連続では文法のルールで前の文を否定するため連続的に画像が流れず足踏みできない、なのでelse ifにしたのだ。
		{
			playerImage = playerGHandle[1];
		}
		else if (playerMove2 == 80) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた
			playerImage = playerGHandle[0];//上に書いてることには誤りがある、60フレームで1sなだけ、超えてもいい。
		}
		else if (playerMove2 == 100) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた
			playerMove2 = 1;
		}


	}
	//}


	if (KABURIBAAIWAKElock == 0) {
		//★一番上に書いた敵の画像が先に書いてあるので、ここで敵の画像を書かなくて良い。順番が逆の場合の上だけに画像の順番を変えるために敵の画像を書いた。

	}



	//ここは問題ない。//主人公が敵よりも低いY軸にいる時の描画する部分である。
	if (pos[enemyY][enemyX][0] + 100 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
		pos[enemyY][enemyX][0] - 100 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3
		&& pos[enemyY][enemyX][1] + playerattackhanndou3 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3) {


	}
	else {
		KABURIBAAIWAKElock = 0;
		kasanaruURA = 0;
		//KABURI = 0;
	}

	//ダメージを負った状態で敵が奥にいる際のスライドが前に描画されるようにするための部分。
	if (pos[enemyY][enemyX][0] + 200 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
		pos[enemyY][enemyX][0] - 200 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3
		&& pos[enemyY][enemyX][1] + playerattackhanndou3 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3) {
		kasanaruURA = 1;
		//右コマンドの残像//敵が奥にいる際の移動描画//原因はif (zannzou < 1) {zannzou = 0; zannzoulock = 0;}の部分でした。if (zannzou == 1) {zannzou = 0; zannzoulock = 0;}
		if (kasanaruURA == 1) {
			if (zannzou <= 30 && zannzou > 0) { //★残像を出すためにRキーでAを押したら変数zannzouが20になり、zannouの変数が0より大きいならば—1をしていき、その間だけ画像を描画する。
				--zannzou;

				//移動中はR1が押せないようにする。
				R1botannlock = 1;
				//X軸のzannzouの分母を大きくすると減速する
				DrawRotaGraph(pos[playerY][playerX][0] + 20 - 20 * zannzou / 5, pos[playerY][playerX][1], bairituX, 0, playeridouAHandle[0], TRUE);

				R1lock = 1;

			}
			if (zannzou <= 25 && zannzou > 0) {
				DrawRotaGraph(pos[playerY][playerX][0] + 20 - 14 * zannzou / (20), pos[playerY][playerX][1], bairituX, 0, playeridouAHandle[0], TRUE);
			}
			if (zannzou <= 21 && zannzou > 0) {
				DrawRotaGraph(pos[playerY][playerX][0] + 20 - 10 * zannzou / (20), pos[playerY][playerX][1], bairituX, 0, playeridouAHandle[0], TRUE);
			}
			if (zannzou <= 18 && zannzou > 0) {
				DrawRotaGraph(pos[playerY][playerX][0] + 20 - 6 * zannzou / (20), pos[playerY][playerX][1], bairituX, 0, playeridouAHandle[0], TRUE);
			}
			if (zannzou <= 16 && zannzou > 0) {
				DrawRotaGraph(pos[playerY][playerX][0] + 20 - 1 * zannzou / (20), pos[playerY][playerX][1], bairituX, 0, playeridouAHandle[0], TRUE);
			}
			if (zannzou <= 6 && zannzou > 0) {
				DrawRotaGraph(pos[playerY][playerX][0] + 20 - zannzou / 20, pos[playerY][playerX][1], bairituX, 0, playeridouAHandle[0], TRUE);
				zannzousaigo = 1;
			}
			if (zannzousaigo == 1) {
				zannzoulock = 0;
				lockdekinai = 0;
				zannzousaigo = 0;
				zannzou = 0;
				R1lock = 0;
				R1botannlock = 0;
				kasanaruURA = 0;
				playerkonntororulock = 0;
			}
		}
	}

	// 入力状態を取得
	//GetJoypadXInputState(DX_INPUT_PAD1, &input);

	//Color = GetColor(255, 255, 255);
	//DrawFormatString(0, 0, RED, "LeftTrigger:%d RightTrigger:%d",
	//	input.LeftTrigger, input.RightTrigger);


	//R1を押してから攻撃する。
	//説得中はスライド移動できない。//今★★書いてある数値が今のところ一番ちょうどいい。
	if (playerkonntororulock == 0) {
		if (keriwaza == 0) {
			//R1を押してからのスライド移動からの攻撃。
			if (R1botannlock == 0) {
				//移動中にスライド移動できないようにzannzoulockはここで0の時にしか押せないようにした。//殴るやキックと同時のボタンでスライドしないように。
				if (Pad[PAD_6] == 1 && zannzoulock == 0 && zannzou == 0 && zannzouA == 0 && zannzouB == 0 && zannzouC == 0
					&& playerkonntororulock == 0) {
					//★走りながらでもスライド攻撃できるようにした。
					RightTriggerlock = 1;//★R2でのロックが解けた後でスライド中にアナログパッドで移動しないようにするための変数。
					kaburulock = 1;
					//LEFTmark = 321321;
					kougekidekinailock = 0;
					playermovelock = 1;//攻撃する際に移動キーと同じに押してしまうと基に戻るときのマスが変になるので、攻撃する瞬間と終わるまでは操作できないように1にする。
					masusaveframe = 1;
					saveplayerX = pos[playerY][playerX][0];
					saveplayerY = pos[playerY][playerX][1];
					//tabakosuenai = 1;//★タバコを吸わないための新しい変数。if (input.RightTrigger == 0)でlockは常に0と置いたので、ここで1にしても意味がない。
					enemyattackdekinai = 1;
					zannzoulock = 1;
					hannilock = 1;
					motonomasunimodoru = 500;
					Rbotunframe = 1;

					suraidoidoukaisi = 1;
					nextattack = 1;
					attackframe2 = 0;//たまに誤発するのでここで0にする。どうせのちにコマンドでattackframe2の数値が増えるので大丈夫。
					Gunkirikae = 0;//★歩いた後に止まれば0になるが、そのままスライドした場合は1のままであるのでここで0にする。

					rockon = 1;
				}
			}
			if (Rbotunframe > 0) {
				++Rbotunframe;
			}
			if (enemyattackdekinai == 1) {
				--motonomasunimodoru;
			}
			if (masusaveframe > 0 && ++masusaveframe < 15) {//15で固定する
				//playermovelock = 1;
				if (((GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_1) == 0))
					// パッド１の入力を取得
					GetJoypadAnalogInput(&InputX, &InputY, DX_INPUT_KEY_PAD1);
				++suraidobyouga;
				if (migimuki == 1) {
					suraidoidoubyouga();
				}
				if (hidarimuki == 1) {
					suraidohidariidoubyouga();
				}
				if (InputY < 0) {
					migimuki = 1;
					hidarimuki = 0;
					nanameidouY = InputY / 36;
					//右上斜め移動に関する部分
					if (InputX > 0) {
						//nanameidouX = InputX / 4;//これで固定。斜め奥に差し込む感じでアナログパッドを傾ける
						//if (InputX > 800 && InputX < 1000) {
						//	nanameidouX = InputX / 3.7;//これで固定。斜め奥に差し込む感じでアナログパッドを傾ける
						//}
						if (InputX > 0 && InputX < 1000) {
							nanameidouX = InputX / 5;//これで固定。斜め奥に差し込む感じでアナログパッドを傾ける
						}
					}
					//左上斜め移動に関する部分
					else if (InputX < 0) {
						komanndomark = 112;
						migimuki = 0;
						hidarimuki = 1;
						nanameidouX = InputX / 7;

					}
				}
				if (InputY > 0) {
					nanameidouY = InputY / 30;
					//右下斜め移動に関する部分
					if (InputX > 0) {
						nanameidouX = InputX / 7;//元々は4で固定していたが
						migimuki = 1;
						hidarimuki = 0;
					}
					//左下斜め移動に関する部分
					else if (InputX < 0) {
						nanameidouX = InputX / 7;
						migimuki = 0;
						hidarimuki = 1;
					}

				}//Yが1000でXが0より大きい時に一気に進むこともあるので
				else if (InputY > 0 && InputY == 1000) {
					//右下斜め移動に関する部分
					if (InputX > 0) {
						nanameidouX2 = InputX / 7;
						migimuki = 1;
						hidarimuki = 0;
					}
				}

				//横に直進する部分
				else if (InputX > 0 && InputY == 0) {
					nanameidouX = InputX / 8;//一回目だけあえて短くした。
					migimuki = 1;
					hidarimuki = 0;
				}
				//後ろに下がる
				else if (InputX < 0 && InputY == 0) {
					nanameidouX = InputX / 7;
					migimuki = 0;
					hidarimuki = 1;
				}

				countmark = 1;

			}
			//if (masusaveframe > 13 && masusaveframe < 15 &&
			//	pos[enemyY1][enemyX1][0] + 70 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
			//	pos[enemyY1][enemyX1][0] - 60 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3< pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
			//	pos[enemyY1][enemyX1][1] + 20 + playerattackhanndou3 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 &&
			//	pos[enemyY1][enemyX1][1] - 20 + playerattackhanndou3 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
				//pos[enemyY][enemyX][0] + 30 < pos[playerY][playerX][0] + 20 + playerattackhanndou + nanameidouX + migiidou&&
				//★元々は-150だったが、敵の攻撃範囲と近いと動かなくなるバグがあるのでXの方は-100にした、-120でもいいかもしれないが試していない。

			//	) {
			//	LEFTmark = 122221;
				//if (masusaveframe > 10 && masusaveframe < 13) {
			//	playerattackhanndou = playerattackhanndou + 30;
				//}
			//}
			if (masusaveframe > 15) {
				masusaveframe = 0;
				//++masusaveframe2;
				masusaveframe2 = 1;
				++tuikaidouframe;
				R1botannlock = 1;
				zannzoulock = 0;
				nextattack = 0;
				InputX = 0;//スライド後も銃を撃てるように。
				InputY = 0;
			}
			if (tuikaidouframe > 0) {
				++tuikaidouframe;
			}

			if (masusaveframe2 > 0) {
				//playermovelock = 1;

				//★二度目のRの時に一回目のRと重なり一回押しただけで二回分のRを進まないように、5フレーム経ってから二回目のRを押せるようにした。
				//if (tuikaidouframe > 40) {//100くらいが長すぎずちょうどいいかもしれない。//しかし遅すぎるので40とかでもいいかも10とか。
				if (Pad[PAD_6] == 1) {//その分、アドアタックタイム的なものは短くする。//あまり短いと一回目のスライド移動中に二回目に切り替わってしまいバグが起きるので30とか40の方がいいかも。
					//★の説明は解決には至らない。原因はスライド移動を2回した後で元のマスに戻った後に
					//tuikaidouframe2が1のままだったため、アドアタックタイム的なものが0になっても
					//tuikaidouframe2が1のままであるため、if (tuikaidouframe2 > 0)が反応してしまい、
					//一気に進んでしまっていた。ちなみに、一気に進んだ後に追加でスライド移動が二回出来た原因は、
					//一気に進んだと同時にifの条件文if (Pad[PAD_6] == 1&& zannzoulock == 0)により
					//一回目のスライドも通常通りに動くため、
					//一気に3回分進んだ後（同時に一回目のスライドも通常通りに動き）の、カッコに続く
					//二回目のスライドと三回目のスライド分も動いたのだ。
					tuikaidouframe = 0;
					tuikamasuidou = 1;
					//masusaveframe = 0;
					zannzoulock = 1;
					//LEFTmark = 114;
					countmark = 2;
					masusaveframe2 = 0;
					nextattack = 1;
				}

				//}
			}
			//★150くらいにしないと一回目のスライドで攻撃した後で2回目のスライドをする際にtuikamasuidouが0になってしまい二回目のRを押してもスライド移動しない。
			//if (tuikaidouframe > 170) {//二回目のR1を押さなかった場合に勝手に0になるようにする。
			//	tuikaidouframe = 0;//ここで0にしていた方がへんてこなバグなどが起きにくくなる。要は必要でないときは0のままの方がいい。
				//motonomasunimodoru = 260;
			//}
			if (tuikamasuidou > 0 && ++tuikamasuidou < 15) {//二回目以降は15にする。
				if (((GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_1) == 0))
					// パッド１の入力を取得
					GetJoypadAnalogInput(&InputX, &InputY, DX_INPUT_KEY_PAD1);
				++suraidobyouga2;
				if (migimuki == 1) {
					suraidoidoubyouga2();
				}
				if (hidarimuki == 1) {
					suraidohidariidoubyouga2();
				}
				if (InputY < 0) {
					//上移動
					nanameidouY2 = InputY / 36;
					//右上斜め移動に関する部分
					if (InputX > 0) {
						nanameidouX2 = InputX / 6;//二回目以降は距離を少し短くする。
						migimuki = 1;
						hidarimuki = 0;
					}
					//左上斜め移動に関する部分
					else if (InputX < 0) {
						komanndomark = 112;
						nanameidouX2 = InputX / 6;
						migimuki = 0;
						hidarimuki = 1;

					}

				}
				if (InputY > 0) {
					//下移動
					nanameidouY2 = InputY / 36;
					//右下斜め移動に関する部分
					if (InputX > 0) {
						nanameidouX2 = InputX / 6;
						migimuki = 1;
						hidarimuki = 0;
					}
					//左下斜め移動に関する部分
					else if (InputX < 0) {
						nanameidouX2 = InputX / 6;
						migimuki = 0;
						hidarimuki = 1;
					}
				}//Yが1000でXが0より大きい時に一気に進むこともあるので
				else if (InputY > 0 && InputY == 1000) {
					//右下斜め移動に関する部分
					if (InputX > 0) {
						nanameidouX2 = InputX / 6;
						migimuki = 1;
						hidarimuki = 0;
					}
				}

				//横に直進する部分
				else if (InputX > 0 && InputY == 0) {
					nanameidouX2 = InputX / 8;
					migimuki = 1;
					hidarimuki = 0;
				}
				//後ろに下がる
				else if (InputX < 0 && InputY == 0) {
					nanameidouX2 = InputX / 7;
					migimuki = 0;
					hidarimuki = 1;
				}


				//LEFTmark = 9877;
				masuidou1X = masuidou1X + nanameidouX2;
				masuidou1Y = masuidou1Y + nanameidouY2;
				countmark = 2;
			}
			//if (tuikamasuidou > 13 && tuikamasuidou < 15 &&
			//	pos[enemyY1][enemyX1][0] + 70 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
			//	pos[enemyY1][enemyX1][0] - 60 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
			//	pos[enemyY1][enemyX1][1] + 20 + playerattackhanndou3 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 &&
			//	pos[enemyY1][enemyX1][1] - 20 + playerattackhanndou3 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
			//	//pos[enemyY][enemyX][0] + 30 < pos[playerY][playerX][0] + 20 + playerattackhanndou + nanameidouX + migiidou&&
			//	//★元々は-150だったが、敵の攻撃範囲と近いと動かなくなるバグがあるのでXの方は-100にした、-120でもいいかもしれないが試していない。

			//	) {
			//	LEFTmark = 122221;
				//if (masusaveframe > 10 && masusaveframe < 13) {
			//	playerattackhanndou = playerattackhanndou + 30;
				//}
			//}
			if (tuikamasuidou > 15) {
				tuikamasuidou = 0;
				zannzoulock = 0;
				tuikaidouframe2 = 1;
				nextattack = 0;
				InputX = 0;//スライド後も銃を撃てるように。
				InputY = 0;
			}

			if (tuikaidouframe2 > 0)//★tuikamasuidou2が最後に0にならないとここで反応して一気にカウントが3に上がることが発生してしまうのでは？
			{
				//++motonomasunimodoru;
				if (Pad[PAD_6] == 1) {
					tuikamasuidou2 = 1;
					//masusaveframe = 0;
					zannzoulock = 1;
					countmark = 3;
					nextattack = 1;
					tuikaidouframe2 = 0;
				}
			}
			if (tuikamasuidou2 > 0 && ++tuikamasuidou2 < 15) {
				if (((GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_1) == 0))
					// パッド１の入力を取得
					GetJoypadAnalogInput(&InputX, &InputY, DX_INPUT_KEY_PAD1);
				++suraidobyouga3;
				if (migimuki == 1) {
					suraidoidoubyouga3();
				}
				if (hidarimuki == 1) {
					suraidohidariidoubyouga3();
				}
				if (InputY < 0) {
					nanameidouY3 = InputY / 36;
					//右上斜め移動に関する部分
					if (InputX > 0) {
						nanameidouX3 = InputX / 6;
						migimuki = 1;
						hidarimuki = 0;
					}
					//左上斜め移動に関する部分
					else if (InputX < 0) {
						komanndomark = 112;
						nanameidouX3 = InputX / 6;
						migimuki = 0;
						hidarimuki = 1;
					}
				}
				if (InputY > 0) {
					nanameidouY3 = InputY / 36;
					//右下斜め移動に関する部分
					if (InputX > 0) {
						nanameidouX3 = InputX / 6;
						migimuki = 1;
						hidarimuki = 0;
					}
					//左下斜め移動に関する部分
					else if (InputX < 0) {
						nanameidouX3 = InputX / 6;
						migimuki = 0;
						hidarimuki = 1;
					}
				}
				//Yが1000でXが0より大きい時に一気に進むこともあるので
				else if (InputY > 0 && InputY == 1000) {
					//右下斜め移動に関する部分
					if (InputX > 0) {
						nanameidouX2 = InputX / 6;
						migimuki = 1;
						hidarimuki = 0;
					}
				}

				//横に直進する部分
				else if (InputX > 0 && InputY == 0) {
					nanameidouX3 = InputX / 8;
					migimuki = 1;
					hidarimuki = 0;
				}
				//後ろに下がる
				else if (InputX < 0 && InputY == 0) {
					nanameidouX3 = InputX / 7;
					migimuki = 0;
					hidarimuki = 1;
				}

				//LEFTmark = 9877;
				masuidou1X = masuidou1X + nanameidouX3;
				masuidou1Y = masuidou1Y + nanameidouY3;
				countmark = 3;
			}
			//if (tuikamasuidou2 > 13 && tuikamasuidou2 < 15 &&
			//	pos[enemyY1][enemyX1][0] + 70 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3  > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
			//	pos[enemyY1][enemyX1][0] - 60 + playerattackhanndou + playerattackhanndou2  +playerattackhanndou3 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
			//	pos[enemyY1][enemyX1][1] + 20 + playerattackhanndou3 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 &&
			//	pos[enemyY1][enemyX1][1] - 20 + playerattackhanndou3 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
				//pos[enemyY][enemyX][0] + 30 < pos[playerY][playerX][0] + 20 + playerattackhanndou + nanameidouX + migiidou&&
				//★元々は-150だったが、敵の攻撃範囲と近いと動かなくなるバグがあるのでXの方は-100にした、-120でもいいかもしれないが試していない。

			//	) {
			//	LEFTmark = 122221;
				//if (masusaveframe > 10 && masusaveframe < 13) {
			//	playerattackhanndou = playerattackhanndou + 30;
				//}
			//}
			if (tuikamasuidou2 > 15) {
				tuikamasuidou2 = 0;
				zannzoulock = 0;
				tuikaidouframe2 = 0;
				tuikaidouframe3 = 1;
				R1botannlock = 1;
				nextattack = 0;
				InputX = 0;//スライド後も銃を撃てるように。
				InputY = 0;
			}

			//四回目のスライド移動
			if (tuikaidouframe3 > 0)//★tuikamasuidou2が最後に0にならないとここで反応して一気にカウントが3に上がることが発生してしまうのでは？
			{
				//++motonomasunimodoru;
				if (Pad[PAD_6] == 1) {
					tuikaidouframe3 = 0;
					tuikamasuidou3 = 1;
					//masusaveframe = 0;
					zannzoulock = 1;
					countmark = 4;
					nextattack = 1;
				}
			}
			if (tuikamasuidou3 > 0 && ++tuikamasuidou3 < 15) {
				if (((GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_1) == 0))
					// パッド１の入力を取得
					GetJoypadAnalogInput(&InputX, &InputY, DX_INPUT_KEY_PAD1);
				++suraidobyouga4;
				if (migimuki == 1) {
					suraidoidoubyouga4();
				}
				if (hidarimuki == 1) {
					suraidohidariidoubyouga4();
				}
				if (InputY < 0) {
					nanameidouY4 = InputY / 36;
					//右上斜め移動に関する部分
					if (InputX > 0) {
						nanameidouX4 = InputX / 6;
						migimuki = 1;
						hidarimuki = 0;
					}
					//左上斜め移動に関する部分
					else if (InputX < 0) {
						komanndomark = 112;
						nanameidouX4 = InputX / 6;
						migimuki = 0;
						hidarimuki = 1;
					}
				}
				if (InputY > 0) {
					nanameidouY4 = InputY / 36;
					//右下斜め移動に関する部分
					if (InputX > 0) {
						nanameidouX4 = InputX / 6;
						migimuki = 1;
						hidarimuki = 0;
					}
					//左下斜め移動に関する部分
					else if (InputX < 0) {
						nanameidouX4 = InputX / 6;
						migimuki = 0;
						hidarimuki = 1;
					}
				}
				//Yが1000でXが0より大きい時に一気に進むこともあるので
				else if (InputY > 0 && InputY == 1000) {
					//右下斜め移動に関する部分
					if (InputX > 0) {
						nanameidouX4 = InputX / 6;
						migimuki = 1;
						hidarimuki = 0;
					}
				}

				//横に直進する部分
				else if (InputX > 0 && InputY == 0) {
					nanameidouX4 = InputX / 8;
					migimuki = 1;
					hidarimuki = 0;
				}
				//後ろに下がる
				else if (InputX < 0 && InputY == 0) {
					nanameidouX4 = InputX / 7;
					migimuki = 0;
					hidarimuki = 1;
				}

				//LEFTmark = 9877;
				masuidou1X = masuidou1X + nanameidouX4;
				masuidou1Y = masuidou1Y + nanameidouY4;
				countmark = 5;
			}
			//if (tuikamasuidou2 > 13 && tuikamasuidou2 < 15 &&
			//	pos[enemyY1][enemyX1][0] + 70 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3  > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
			//	pos[enemyY1][enemyX1][0] - 60 + playerattackhanndou + playerattackhanndou2  +playerattackhanndou3 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
			//	pos[enemyY1][enemyX1][1] + 20 + playerattackhanndou3 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 &&
			//	pos[enemyY1][enemyX1][1] - 20 + playerattackhanndou3 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
				//pos[enemyY][enemyX][0] + 30 < pos[playerY][playerX][0] + 20 + playerattackhanndou + nanameidouX + migiidou&&
				//★元々は-150だったが、敵の攻撃範囲と近いと動かなくなるバグがあるのでXの方は-100にした、-120でもいいかもしれないが試していない。

			//	) {
			//	LEFTmark = 122221;
				//if (masusaveframe > 10 && masusaveframe < 13) {
			//	playerattackhanndou = playerattackhanndou + 30;
				//}
			//}
			if (tuikamasuidou3 > 15) {
				tuikamasuidou3 = 0;
				zannzoulock = 0;
				tuikaidouframe4 = 1;
				R1botannlock = 1;
				nextattack = 0;
				InputX = 0;//スライド後も銃を撃てるように。
				InputY = 0;
			}

			//5回目のスライド移動。
			if (tuikaidouframe4 > 0)//★tuikamasuidou2が最後に0にならないとここで反応して一気にカウントが3に上がることが発生してしまうのでは？
			{
				//++motonomasunimodoru;
				if (Pad[PAD_6] == 1) {
					tuikaidouframe4 = 0;
					tuikamasuidou4 = 1;
					//masusaveframe = 0;
					zannzoulock = 1;
					countmark = 5;
					nextattack = 1;
				}
			}
			if (tuikamasuidou4 > 0 && ++tuikamasuidou4 < 15) {
				if (((GetJoypadInputState(DX_INPUT_KEY_PAD1) & PAD_INPUT_1) == 0))
					// パッド１の入力を取得
					GetJoypadAnalogInput(&InputX, &InputY, DX_INPUT_KEY_PAD1);
				++suraidobyouga5;
				if (migimuki == 1) {
					suraidoidoubyouga5();
				}
				if (hidarimuki == 1) {
					suraidohidariidoubyouga5();
				}
				if (InputY < 0) {
					nanameidouY5 = InputY / 36;
					//右上斜め移動に関する部分
					if (InputX > 0) {
						nanameidouX5 = InputX / 6;
						migimuki = 1;
						hidarimuki = 0;
					}
					//左上斜め移動に関する部分
					else if (InputX < 0) {
						komanndomark = 112;
						nanameidouX5 = InputX / 6;
						migimuki = 0;
						hidarimuki = 1;
					}
				}
				if (InputY > 0) {
					nanameidouY5 = InputY / 36;
					//右下斜め移動に関する部分
					if (InputX > 0) {
						nanameidouX5 = InputX / 6;
						migimuki = 1;
						hidarimuki = 0;
					}
					//左下斜め移動に関する部分
					else if (InputX < 0) {
						nanameidouX5 = InputX / 6;
						migimuki = 0;
						hidarimuki = 1;
					}
				}
				//Yが1000でXが0より大きい時に一気に進むこともあるので
				else if (InputY > 0 && InputY == 1000) {
					//右下斜め移動に関する部分
					if (InputX > 0) {
						nanameidouX5 = InputX / 6;
						migimuki = 1;
						hidarimuki = 0;
					}
				}

				//横に直進する部分
				else if (InputX > 0 && InputY == 0) {
					nanameidouX5 = InputX / 8;
					migimuki = 1;
					hidarimuki = 0;
				}
				//後ろに下がる
				else if (InputX < 0 && InputY == 0) {
					nanameidouX5 = InputX / 7;
					migimuki = 0;
					hidarimuki = 1;
				}

				//LEFTmark = 9877;
				masuidou1X = masuidou1X + nanameidouX5;
				masuidou1Y = masuidou1Y + nanameidouY5;
				countmark = 5;
			}
			//if (tuikamasuidou2 > 13 && tuikamasuidou2 < 15 &&
			//	pos[enemyY1][enemyX1][0] + 70 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3  > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
			//	pos[enemyY1][enemyX1][0] - 60 + playerattackhanndou + playerattackhanndou2  +playerattackhanndou3 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
			//	pos[enemyY1][enemyX1][1] + 20 + playerattackhanndou3 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 &&
			//	pos[enemyY1][enemyX1][1] - 20 + playerattackhanndou3 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
				//pos[enemyY][enemyX][0] + 30 < pos[playerY][playerX][0] + 20 + playerattackhanndou + nanameidouX + migiidou&&
				//★元々は-150だったが、敵の攻撃範囲と近いと動かなくなるバグがあるのでXの方は-100にした、-120でもいいかもしれないが試していない。

			//	) {
			//	LEFTmark = 122221;
				//if (masusaveframe > 10 && masusaveframe < 13) {
			//	playerattackhanndou = playerattackhanndou + 30;
				//}
			//}
			if (tuikamasuidou4 > 15) {
				tuikamasuidou4 = 0;
				zannzoulock = 0;
				//tuikaidouframe5 = 1;
				R1botannlock = 1;
				nextattack = 0;
				InputX = 0;//スライド後も銃を撃てるように。
				InputY = 0;
			}

			if (motonomasunimodoru < 0) {
				motonomasunimodoru = 500;
				playerkonntororulock = 0;//どうせすぐにmotonomasunimodoru = 180;になるので、この瞬間に0にしておく、その方が
				playermovelock = 0;//
				nextattack = 0;
				syuzinnkouyokerulock = 0;
				if (motonomasunimodoru == 500) {//攻撃によって増えた時間で攻撃を伸ばす方法をとったが、たまに残る時間のせいでバグが起きたりしていた。なので減る方法をとった。
					//if (motonomasunimodoru == 350)のままで外に出すと攻撃中で時間が伸びて350になると元に戻ってしまう。なのでどんなに増えても0に成ったら350という攻撃しなかった場合のノルマタイムである定数になるようにした。
					kougekidekinailock = 1;//これで攻撃できない。
					playerkonntororulock = 0;
					playermovelock = 0;
					masusaveframe2 = 0;
					motonomasunimodoru = 0;
					nanameidouX = 0;//元の位置に戻った後も主人公の描画にはnanameidouXやYを考慮しているため、0にする必要がある。
					nanameidouY = 0;
					nanameidouX2 = 0;
					nanameidouY2 = 0;
					nanameidouX3 = 0;
					nanameidouY3 = 0;
					nanameidouX4 = 0;
					nanameidouY4 = 0;
					nanameidouX5 = 0;
					nanameidouY5 = 0;
					migiidou = 0;
					yokeruX = 0;
					InputX = 0;
					InputY = 0;
					
					pos[playerY][playerX][0] = saveplayerX;
					pos[playerY][playerX][1] = saveplayerY;
					//saveplayerX = 0;
					//saveplayerY = 0;
					//R1botannlock = 0;
					tuikamasuidou = 0;
					tuikaidouframe = 0;
					tuikamasuidou2 = 0;
					tuikaidouframe2 = 0;
					tuikamasuidou3 = 0;
					tuikaidouframe3 = 0;
					tuikamasuidou4 = 0;
					tuikaidouframe4 = 0;

					enemyattackdekinai = 0;
					//playerattackhanndou = 0;//★攻撃後に敵も一が戻るとつまらないので、どうせ移動の確率でちゃんとしたマスに移動するので

					kaburulock = 0;
					tabakosuenai = 0;
					//countmark = 0;
					hannilock = 0;
					zannzoulock = 0;
					kougekikannkaku = 0;//攻撃の間隔の数値が途中でもここで0にしてリセットする。
					RightTriggerlock = 0;
					KABURI = 0;//たまに1のままで重なる部分がうまくいかないのでここで0にする。

					suraidoidoukaisi = 0;
					nextattack = 0;//たまに同時押しで起こってしまうのでバグって1のままになってしまい攻撃ができない時があるので、ここで念のために0にする。
					enemyattaking = 0;

					attackframe = 0;
					attackframe2 = 0;
					attackframe3 = 0;

					countmark = 0;
					sennkounyuuryokubunnki3 = 0;


					kericount = 0;
					R1botannlock = 0;

					hidariaruku = 0;
					uearuku = 0;
					migiaruku = 0;
					sitaaruku = 0;

					enemysabunHPpoint = 0;
					enemy2sabunHPpoint = 0;
					//★マスに戻った後は右向きにする。
					migimuki = 1;
					hidarimuki = 0;

					rockon = 0;
				}
			}

			//if (Rbotanosenaiframe > 0 && ++Rbotanosenaiframe < 100) {
			//	Rbotanosenailock = 1;
			//}
			//if (Rbotanosenaiframe > 100) {
				//念のために
			//	nanameidouX = 0;//元の位置に戻った後も主人公の描画にはnanameidouXやYを考慮しているため、0にする必要がある。
			//	nanameidouY = 0;
			//	nanameidouX2 = 0;
			//	nanameidouY2 = 0;
			//	nanameidouX3 = 0;
			//	nanameidouY3 = 0;//ここまで。
			//	Rbotanosenaiframe = 0;
			//	Rbotanosenailock = 1;
			//}
			//ここで終わった直後に攻撃できないようにした。
			if (motonomasunimodoru < 50 && motonomasunimodoru > 0) {
				R1botannlock = 1;
				//playerkonntororulock3 = 1;
			}
			//たまに180になる直前でR1を押すとその後の処理が書いていないためnanameidouX3が0以外の値になるので、ここで念入りに0にしておく。
			if (syuzinnkouyokerulock == 0)//敵の攻撃をかわすための変数のロック。
			{
				if (motonomasunimodoru == 0) {
					//playerHPlock = 0;//かすり攻撃の蹴りの際にマスに戻る特にYを押すとplayerHPlockが1のままでコマンドを押さないと処理されずに1の
					//が残ってしまう。
					//playerkonntororulock3 = 0;
					R1botannlock = 0;
					kougekidekinailock = 1;//これで攻撃できない。
					playermovelock = 0;
					masusaveframe2 = 0;
					motonomasunimodoru = 0;
					nanameidouX = 0;//元の位置に戻った後も主人公の描画にはnanameidouXやYを考慮しているため、0にする必要がある。
					nanameidouY = 0;
					nanameidouX2 = 0;
					nanameidouY2 = 0;
					nanameidouX3 = 0;
					nanameidouY3 = 0;
					nanameidouX4 = 0;
					nanameidouY4 = 0;
					nanameidouX5 = 0;
					nanameidouY5 = 0;
					migiidou = 0;
					InputX = 0;
					InputY = 0;
					yokeruX = 0;
					tuikamasuidou = 0;
					tuikaidouframe = 0;
					tuikamasuidou2 = 0;
					tuikaidouframe2 = 0;
					enemyattackdekinai = 0;
					kaburulock = 0;
					tabakosuenai = 0;
					//countmark = 0;
					hannilock = 0;
					kougekikannkaku = 0;//攻撃の間隔の数値が途中でもここで0にしてリセットする。
					RightTriggerlock = 0;
					KABURI = 0;//たまに1のままで重なる部分がうまくいかないのでここで0にする。

					tuikamasuidou = 0;
					tuikaidouframe = 0;
					tuikamasuidou2 = 0;
					tuikaidouframe2 = 0;
					tuikamasuidou3 = 0;
					tuikaidouframe3 = 0;
					tuikamasuidou4 = 0;
					tuikaidouframe4 = 0;

					suraidobyouga = 0;
					suraidobyouga2 = 0;
					suraidobyouga3 = 0;
					suraidobyouga4 = 0;
					suraidobyouga5 = 0;
					suraidoidoukaisi = 0;
					nextattack = 0;//たまに同時押しで起こってしまうのでバグって1のままになってしまい攻撃ができない時があるので、ここで念のために0にする。
					enemyattaking = 0;
					sennkounyuuryokubunnki = 0;
					sennkounyuuryokubunnki3 = 0;
					attackframe = 0;
					attackframe2 = 0;
					attackframe3 = 0;
					attackframe5 = 0;
					attackframe6 = 0;
					attackframe7 = 0;
					nagurugazou = 0;
					nagurugazou2 = 0;
					countmark = 0;
					//playermovelock = 0;
					//playerHPlock = 0;//たまに動きが勝手に止まるので念のためにここに書いて置き。//ここでこいつが0だとかすり攻撃の時にずっとダメージ状態の時にダメージ状態の画像が描画されてしまう。
					jyuuzikeysousa = 0;//たまに移動ができない時があるので、
					jyuuzikeysousa2 = 0;

					//スライド移動しないで銃攻撃した場合はポイントは溜まらないように0にする。
					enemysabunHPpoint = 0;
					enemy2sabunHPpoint = 0;
					//playerHPlock = 0;
					//keriwaza = 0;
					//if (attackframe5 > 0 && attackframe5 < 50) {//たまに40とかで止まるのでここで念のために書いておく。
					//	attackframe = 0;
					//	attackframe5 = 0;
					//	R1botannlock = 0;
					//	keriwaza = 0;
					//}
					//kasurikeri = 0;//かすり判定の蹴り技がマスに戻るすれすれでキックしようとして1になるので、ここで0にする。
					//★マスに戻った後は右向きにする。



					migimuki = 1;//通常状態は常に右向きなのでmigimukiは1になるが、hidarimukiは0になる、
					hidarimuki = 0;

					rockon = 0;
				}
			}
			//念のため
			//if (attackframe == 0 && attackframe2 == 0 && attackframe3 == 0 && attackframe5 == 0 && attackframe6 == 0 && attackframe7 == 0)
			//{
			//	playerkonntororulock = 0;
			//	playerkonntororulock3 = 0;
			//}

		}

	}
	//途中で左ボタンを押すと瞬時に元の位置に戻る。
	if (suraidoidoukaisi == 1) {
		if (Pad[PAD_11] == 1) {
			suraidoidoukaisiA = 1;
			playerkonntororulock = 0;
			R1botannlock = 0;
			syuzinnkouyokerulock = 0;
			enemysabunHPpoint = 0;
			enemy2sabunHPpoint = 0;

			attackframe = 0;
			attackframe2 = 0;
			attackframe3 = 0;
			attackframe5 = 0;
			attackframe6 = 0;
			attackframe7 = 0;
			nagurugazou = 0;
			nagurugazou2 = 0;
		}
	}
	//瞬間移動した場合の処理//ここから
	if (suraidoidoukaisiA > 0) {
		suraidoidoukaisi = 0;
	}
	//★元々は++suraidoidoukaisiAで30に成ったら戻るようにしたが、30になる前にmotonomasunimodoruが0になってしまい、バグが起きた。なのでmotonomasunimodoruで統一した。
	if (suraidoidoukaisiA == 1 && motonomasunimodoru > 30) {
		motonomasunimodoru = 0;//★ここで0にすることで主人公のスライド移動での変数がすべて0になるので、セーブした位置に戻れる。セーブだけではスライド移動での移動数値がそのままなので0にしないとならない。
		syunnkannidou = 0;
		suraidoidoukaisi = 0;
		suraidoidoukaisiA = 0;
		playerkonntororulock = 0;
		nanameidouX = 0;//元の位置に戻った後も主人公の描画にはnanameidouXやYを考慮しているため、0にする必要がある。
		nanameidouY = 0;
		nanameidouX2 = 0;
		nanameidouY2 = 0;
		nanameidouX3 = 0;
		nanameidouY3 = 0;
		nanameidouX4 = 0;
		nanameidouY4 = 0;
		nanameidouX5 = 0;
		nanameidouY5 = 0;
		migiidou = 0;
		pos[playerY][playerX][0] = saveplayerX;
		pos[playerY][playerX][1] = saveplayerY;
		hidariaruku = 0;
		uearuku = 0;
		migiaruku = 0;
		sitaaruku = 0;
		yokeruX = 0;

	}
	//ここまで。
		//攻撃判定その2(物理的な攻撃)//銃での攻撃判定その1と被らないように0にした。
	if (hannilock == 1) {
		if (pos[enemyY][enemyX][0] + 40 + playerattackhanndou + playerattackhanndou2 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX &&
			pos[enemyY][enemyX][0] - 100 + playerattackhanndou + playerattackhanndou2 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX &&
			pos[enemyY][enemyX][1] + 20 + playerattackhanndou3 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 &&
			pos[enemyY][enemyX][1] - 20 + playerattackhanndou3 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 
			//pos[enemyY][enemyX][0] + 30 < pos[playerY][playerX][0] + 20 + playerattackhanndou + nanameidouX + migiidou&&
			//★元々は-150だったが、敵の攻撃範囲と近いと動かなくなるバグがあるのでXの方は-100にした、-120でもいいかもしれないが試していない。

			) {
			//LEFTmark = 4323;
			kougekilock = 1;
			kougekiKANOU = 2;
			//input.RightTrigger = 1;
			kougekidekinailock = 0;
			//playerkonntororulock = 1;
			//★この範囲内であれば、攻撃できるが、この期間中は攻撃できないとする。外でelse ifで書くと「上の攻撃での範囲外の時」での
			//プログラムとなるため作用する部分が意図したものではないため、ここに書いた。
			//if (kougekikannkaku > 0 && ++kougekikannkaku < 50) {
			//	kougekidekinailock = 0;
			//}
			//if (kougekikannkaku > 50) {
			//	kougekidekinailock = 1;
			//	kougekikannkaku = 0;
			//}
		}
		else {
			//playerattackhanndou = 0;
			//playerattackhanndou2 = 0;
			kougekiKANOU = 0;
			playerkonntororulock = 0;
			kasurikougeki();
			kougekidekinailock = 0;

		}
	}
	if (masusaveframe > 40) {
		masusaveframe = 0;
	}







	//★ドットなどの画像を扱う関数は透明化できないため、透明化ができる映像を扱う関数を使う。
	/*if (settokutoumeika > 0) {//★toumeikaが0より大きくなっている間だけ敵を消したいので{}でまとめた。以前のif (mark == 0 && enemyHP < 1)では{}の中の描き方に関係なく、if (mark == 0 && enemyHP < 1)の条件に当てはまるものがすべて透明化してしまうので
				//if(toumeika >0)のように透明化したいもののみが透明化するように限定的にif(toumeika >0)の条件が働いている間だけ{}の働きがあるようにした。
		++settokutoumeikaframe;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 4 * settokutoumeikaframe);		//ブレンドモードをα(128/255)に設定
		PlayMovieToGraph(sentougoHandle);
		DrawExtendGraph(0, 0, 1770, 980, sentougoHandle, FALSE);
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);		//ブレンドモードをリセット（他の画像が薄くならないようにするため）	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - toumeika);		//ブレンドモードをα(128/255)に設定
	*/


//敵の物理攻撃を描画する部分//※攻撃中の画像が前に出るようにしたかったので、ここの位置に追いた。まあ、同じプログラムを二つ作り、違う名前の二つの関数化して
	//場合に応じて呼び出すという手もある。
	if (ENEMYmovelock2 == 0) {
		if (ENEMYkougekigazouA1frame > 0 && ++ENEMYkougekigazouA1frame < 60) {
			enemyzannzoulock = 1;//攻撃した瞬間に点滅して敵の残像が0になるときがあるのでここで1にする。
			//ENEMYkougekiA1Image = ENEMYkougekiA1Handle[1];
			enemyattackinglock = 1;//敵が攻撃するときだけは攻撃する画像のみが描画されるようにするための変数。
			if (enemyzannzoulock == 0) {
				DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] + playerattackhanndou3, bairituY, 0, ENEMYkougekiA1Handle[0], TRUE);
				//攻撃中の敵と、主人公の重なり方。
					//if (pos[enemyY][enemyX][0] + 100 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
					//	pos[enemyY][enemyX][0] - 100 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3
					//	&& pos[enemyY][enemyX][1] + playerattackhanndou3 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3){
					//	DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, 5, 0, playerImage, TRUE);
					//}
					//++ENEMYkougekigazouA1frame;
					//if (playerY == enemyY - 1 && playerX == enemyX) {
					//	enemyzannzoulock = 1;
					//	DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, 5, 0, playerImage, TRUE);  // 俺キャラの描画
					//	DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] + playerattackhanndou3, 4, 0, ENEMYkougekiA1Handle[0], TRUE);
						// 敵キャラの描画
					//}
					//else if (playerY == enemyY + 1 && playerX == enemyX) {
					//	enemyzannzoulock = 1;
					//	DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2, pos[enemyY][enemyX][1] + playerattackhanndou3, 4, 0, ENEMYkougekiA1Handle[0], TRUE);
					//	DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + playerattackhanndou3 + nanameidouX3, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, 5, 0, playerImage, TRUE);  // 俺キャラの描画
					//
						// 敵キャラの描画
					//}


			}
			
		}
	}
	if (ENEMYkougekigazouA1frame > 80) {
		ENEMYkougekigazouA1frame = 0;
		ENEMYkougekigazouA1lock = 1;
	}
	if (ENEMYkougekigazouA1lock == 1 && ENEMYkougekigazouA1frame == 0) {
		++ENEMYkougekigazouA2frame;
	}
	//ランダム数値でランダムの値が変わらないことで2frameを大きくすると攻撃する前に再び、1frameになってしまい攻撃できないことがある。
	//なのでここのフレームは短くする。
	if (ENEMYkougekigazouA2frame > 8 && ENEMYkougekigazouA2frame < 50) {
		enemyzannzoulock = 1;//攻撃した瞬間に点滅して敵の残像が0になるときがあるのでここで1にする。
		if (enemyzannzoulock == 0) {
			DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 80, pos[enemyY][enemyX][1] + playerattackhanndou3, bairituY, 0, ENEMYkougekiA2Handle[0], TRUE);
			//	if (pos[enemyY][enemyX][0] + 100 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
			//		pos[enemyY][enemyX][0] - 100 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3
			//		&& pos[enemyY][enemyX][1] + playerattackhanndou3 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3) {
			//		DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, 5, 0, playerImage, TRUE);
			//	}
		}
		//if (pos[enemyY][enemyX][0] + 40 + playerattackhanndou + playerattackhanndou2 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
		//	pos[enemyY][enemyX][0] - 200 + playerattackhanndou + playerattackhanndou2 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
		//	pos[enemyY][enemyX][1] + 20 + playerattackhanndou3 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 &&
		//	pos[enemyY][enemyX][1] - 20 + playerattackhanndou3 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3)
		//{
		if (pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
			pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 130 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
			pos[enemyY][enemyX][1] + playerattackhanndou3 + 15 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 &&
			pos[enemyY][enemyX][1] + playerattackhanndou3 - 15 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
			) {

			//zannzoulock = 0;

			if (Pad[PAD_1] == 1) {
				++kaunntacount;//カウンターを連打してもカウンターをとれないように、タイミングを計るようにした。
				enemyhirumaseframe = 1;
				ENEMYkougekigazouA1frame = 80;
				ENEMYkougekigazouA2frame = 50;
				ranndamukougeki = 0;
				DAMEGE = 1;
				playerHPsubun = 0;
				enemyzannzoulock = 1;
				//enemyzannzoulock2 = 1;//カウンターを食らった敵だけ描画できるように1にする。

				playerattackhanndou = playerattackhanndou + 60;
			}
		}
	}

	//相手の攻撃を防いで、一定時間で怯ませロックが再び0に戻る。
	if (enemyhirumaseframe > 0) {
		++enemyhirumaseframe;
	}
	//★重要部分。怯んだ場合の時の場合を考えて220に設定する。それよりも短いとhirumaselock = 0;になってしまい、通常攻撃が当たった場合での処理を通ってしまい、
	//フレーム数分だけ怯まずに攻撃してきてしまう。
	if (hirumaselockframe > 150) {//以前に攻撃が終わった際に一瞬通常状態の敵が描画されていたが、その時は怯む部分もうまく機能していなかったため
		//怯みが早く終わってしまい、通常状態が描画された状態で確率により攻撃する画像も描画されてしまい、攻撃中に通常状態が描画されてしまっていたのあろう。
		//あるいは、攻撃が終わった後での処理がうまくいっていなかったのだろう。
		hirumaselockframe = 0;
		hirumaselock = 0;
		kaunntacount = 0;
		stayhere3 = 0;
		//★カウンターを食らった後hirumaselockframeは上がり続けるのでenemyhirumaseframeが140より大きくなってすぐの攻撃よりも
		//こちらのhirumaselockframeで220よりも大きくなったら再び敵が攻撃してくるにした。
		ranndamulock = 0;//自分と敵の重なるプログラムを有効にするために0にする。
	}
	//怯ませる間のフレーム
	if (enemyhirumaseframe > 0 && ++enemyhirumaseframe < 140) {
		//LEFTmark = 1234;

		//処理が重いと敵がダメージを負いながら点滅して、同時に攻撃するようになるのはいいが、見栄えが良くないので
		//処理が軽くしないとスムーズに見えない。
		//★点滅してる回数が長いとダメージを食らった場合で点滅する場合のプログラムが先に終わるため敵の残像が先に1になってしまう。
		//なので通常の敵が描画された状態で上に点滅したカウンターを食らった敵が描画されてしまっていた。
		//なのでそうならないようにここでの数値を小さくして100くらいにした。
		//短いほうが敵が死ぬ際に青い状態が重ならないのでちょうどいい。
		if (enemyhirumaseframe > 0 && enemyhirumaseframe < 20 ||
			enemyhirumaseframe > 40 && enemyhirumaseframe < 60 ||
			enemyhirumaseframe > 80 && enemyhirumaseframe < 100 ||
			enemyhirumaseframe > 120 && enemyhirumaseframe < 140
			//enemyhirumaseframe > 160 && enemyhirumaseframe < 180 or 
			//enemyhirumaseframe > 200 && enemyhirumaseframe < 220 
			//enemyhirumaseframe > 260 && enemyhirumaseframe < 280 or
			//enemyhirumaseframe > 300 && enemyhirumaseframe < 320 or
			//enemyhirumaseframe > 340 && enemyhirumaseframe < 360 or
			//enemyhirumaseframe > 380 && enemyhirumaseframe < 400
			)
		{


			DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] + playerattackhanndou3, bairituY, 0, enemygameGHandle[0], TRUE);
			//カウンターを食らった状態での敵と重なる際に主人公が前にくるようにここに書いた。
			if (playerHP > 200) {
				if (pos[enemyY][enemyX][0] + 200 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
					pos[enemyY][enemyX][0] - 200 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3
					&& pos[enemyY][enemyX][1] + playerattackhanndou3 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3) {

					if (zannzoulock == 0 && motonomasunimodoru == 0) {
						DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] + playerattackhanndou3, bairituY, 0, enemyImage, TRUE);

					}
				}
			}

		}
	}

	//if (enemyhirumaseframe == 0 && enemyhirumaseframelock == 1) {
	//	
	//	stayherelock = 0;
	//}
	//フレームが動いているので、攻撃後にランダムで数を変えて、繰り返しを防いだうえで、最初の一回目の10から12のフレームの一フレーム
//が攻撃を食らうようにした。
	if (hirumaselock == 0) {
		if (pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
			pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 130 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
			pos[enemyY][enemyX][1] + playerattackhanndou3 + 15 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 &&
			pos[enemyY][enemyX][1] + playerattackhanndou3 - 15 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
			&& ENEMYkougekigazouA2frame > 48 && ENEMYkougekigazouA2frame < 50) {
			playerHPsubun = 31;

			//ranndamukougeki = 1;
			//DAMEGE = 1;
			playermovelock2 = 0;//タバコ中に攻撃を食らった際に1のままでは移動できないので、ここで0にした。
			//ENEMYkougekigazouA1frame = 0;★★こいつは処理の過程で0になり、++のような繰り上がりはないので0と過程で書いたので
			//そのまま0になったのでここに再度書かなくてもよい。
			//tekinoKOUGEKITYUUhahyouzisinailock = 0;
			//ENEMYkougekigazouA2frame = 0;//★★描画が連続で出てくるような状況についての解決法
			//ここにENEMYkougekigazouA2frame = 0を書くとENEMYkougekigazouA1lock == 1 &&ENEMYkougekigazouA1frame == 0に
			//通らないようにとここにENEMYkougekigazouA1lock = 0;とENEMYkougekigazouA1frame = 1;書いてもランダム変数の数値が変化しなければ
			//最初から処理を行うため意味はない。なので30という値で固定したのだ。そして、最初のランダムの関数の値が
			//変更するまでは30に固定して、ランダム変数が変化したら0になるようにしたのだ。
			//playerkonntororulock = 1;//攻撃を食らった瞬間は動けないようにする。

		}
		//攻撃を食らった場合。//怯みが解除された後と同じようなするために141とした。
		if (ENEMYkougekigazouA2frame > 50) {
			ENEMYkougekigazouA2frame = 0;
			//enemyzannzoulock2 = 0;
			enemyzannzoulock = 0;//
			ranndamulock = 0;//自分と敵の重なるプログラムを有効にするために0にする。
			ranndamulockframe = 0;
			ranndamukougeki = 0;
			enemygazoukesu = 0;
			enemyattackinglock = 0;//敵が攻撃するときだけは攻撃する画像のみが描画されるようにするための変数。
			ENEMYkougekigazouA1lock = 0;//ENEMYkougekigazouA2frameを繰り上げないためにここで0にする。
			ENEMYkougekigazouA1 = 0;
			kougekiframe = 0;
			//ranndamukougeki = 10;
			//LEFTmark = 909;
			kaunntacount = 0;
			enemystayhere = 0;//たまに何かしらの原因で1になってしまいコンティニュー後に敵が描画されないので、
			//コンティニューする場合の関数内にもenemystayhere = 0;と書いたがうまく機能しないことがあるので攻撃後には0にしておく。
			overattacklock = 0;
			ranndamulock = 0;//自分と敵の重なるプログラムを有効にするために0にする。
			//stayherelock = 0;
			stayhere3 = 0;//★怯ませる処理での途中で0にしていたため、カウンターを食らってもすぐに敵が攻撃してきて、その際にif (overattacklock == 0) によって
			//ダメージを負った際でも攻撃してくる敵の画像が描画され、怯んでる状態で攻撃画像が同時に描画されてしまうようになっていた。
			//if (overattacklock == 0) はカウンターを食らって時ではなく、普通に攻撃した時に敵が攻撃してきた際に、攻撃してきたことがわかるように敵の攻撃画像を描画するためのプログラムである。
	//		
		}
		//if (ENEMYkougekigazouA2frame == 60) { ++ENEMYkougekigazouA2frame2; }
		//if (ENEMYkougekigazouA2frame2 > 220) {
		//	ENEMYkougekigazouA2frame2 = 220;
		//	enemyhirumaseframe = 221;
		//}
		//★if (ENEMYkougekigazouA2frame > 8 && ENEMYkougekigazouA2frame < 40)の間で攻撃する2枚目が描画されるので、
		//この間と重ならないようにENEMYkougekigazouA2frameが40になったらenemyzannzoulockを0にするようにした。


		//★今までとは違い、敵が攻撃して縦に避けた際に敵が上書きされないように、主人公が上書きされるように。範囲的に主人公の画像を描画する。
		if (pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 200 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
			pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 200 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
			//pos[enemyY][enemyX][1] + playerattackhanndou3> pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 &&
			pos[enemyY][enemyX][1] + playerattackhanndou3 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
			&& nextattack == 0) {// nextattack == 0で主人公が攻撃していない時
			if (migimuki == 1 && zannzoulock == 0) {
				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage, TRUE);

			}
			if (hidarimuki == 1 && zannzoulock == 0) {
				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage2, TRUE);

			}
		}
	}

	//★★下の★は敵の攻撃を表現することにおいて大変重要である。※if (hirumaselockframe > 140) でもよいが、カウンターを食らった敵がすぐに攻撃してこないようにするために用意した
	//二つ目の変数hirumaselockframeを使った。
	if (enemyhirumaseframe > 140) {//★★50フレームだとなぜか攻撃後に一瞬すばやくさらに攻撃するようになってしまう。
		//カウンターを食らった状態でこっちが最初に効果が切れると怯んだ状態で敵が移動するので、ここは怯んだ場合のフレーム数並みの数値をとる。
		//前までは敵が攻撃するまでが短かったため怯んでからすぐに攻撃してくるため、移動などしないため怯んだままで移動せずに攻撃してきたため
		//症状が目立たのかったのだろう。今回はカウンターを食らった場合、150になるまでは敵が攻撃してこないようにしたので、それまでは何もして来ない。
		//カウンターを与えた時はENEMYkougekigazouA2frameを0としたが、確率がそのままなので値が再び上がるのだろう。
		//確率自体も変えてみたが、確率自体がまた変わるので意味がない。なので140とした。
		//たぶんランダム数が一定期間のままなので、50フレームでランダム数が入る変数の値を10にする前に、変わる前の値の時で一周してしまうのだろう、

		enemyhirumaseframe = 0;
		//enemyhirumaseframelock = 1;
		enemyzannzoulock = 0;

		ranndamulock = 0;//敵からの攻撃をカウンターした場合も値が0になるようにする。
		enemyattackinglock = 0;//

		enemyattaking = 0;//カウンターを食らって主人公が攻撃する際に主人公が元の位置に戻るまではenemyattakingは1のままなので、
		//相手に近寄る際に正しく位置状況が描画されるために0にする。
		enemyzannzoulock = 0;//
		//enemyhirumaseframe = 0;//★たぶん原因はここを0にしていたため、ランダムでの数字が一定の際に
		//そのランダム数値のまま再び値が上がってしまい敵の画像がすごい勢いで描画されるのかと思う。なのでここは70にする。
		//そうすればランダムの値がまだ変化しなくても70のままなので下のif文で敵は自分に攻撃できない。
		//しかし、たまに一瞬のうちに2回攻撃が入るので、そこはランダム関数でなんとかしてみる。
		ENEMYkougekigazouA1 = 0;
		kougekiframe = 0;
		//ranndamukougeki = 10;
		//LEFTmark = 909;
		kaunntacount = 0;
		//enemystayhere = 0;//たまに何かしらの原因で1になってしまいコンティニュー後に敵が描画されないので、
		//コンティニューする場合の関数内にもenemystayhere = 0;と書いたがうまく機能しないことがあるので攻撃後には0にしておく。
		overattacklock = 0;
		//stayherelock = 0;
		stayhere3 = 0;//★怯ませる処理での途中で0にしていたため、カウンターを食らってもすぐに敵が攻撃してきて、その際にif (overattacklock == 0) によって
		//ダメージを負った際でも攻撃してくる敵の画像が描画され、怯んでる状態で攻撃画像が同時に描画されてしまうようになっていた。
		//if (overattacklock == 0) はカウンターを食らって時ではなく、普通に攻撃した時に敵が攻撃してきた際に、攻撃してきたことがわかるように敵の攻撃画像を描画するためのプログラムである。
//		
		enemyattackagein = 1;
	}

	//攻撃を食らうと敵の攻撃が止み、攻撃を受けている最中は敵の色が反転するようにした。
//敵1の「通常状態」と「攻撃中」に対する攻撃を食らったときの半透明になる部分。
//if (kougekiKANOU == 1 or kougekiKANOU == 2 or kougekiKANOU == 10) {//攻撃中は攻撃の方の画像が描画されるようにする。
	if (enemyhanntoumei3 == 0) {//敵が死んで消える際に点滅しないようにするための物。
		if (enemysabunHP > 0 or enemysabunHPA > 0 or KenemysabunHP > 0 or enemysabunHPB > 0 or GenemysabunHP > 0 or GenemysabunHPA > 0) {
			LEFTmark = 1;
			++enemyzannzoulockframe1;

			stayhere3 = 1;
			++stayhereframe;
			//ENEMYmovelock2 = 1;
			ENEMYkougekigazouA1frame = 0;//攻撃を受けたら攻撃が止まる。
			ENEMYkougekigazouA1lock = 0;
			ENEMYkougekigazouA2frame = 0;
			//enemyzannzoulock2 = 1;//★攻撃を与えたら敵の攻撃する「画像」を無しにする。
		}
		//差分での奴は他の差分が0の時に他の攻撃で再び差分が上がるので攻撃を食らいながらも違う画像で攻撃になるのでこっちの書き方にした。
		if (enemyzannzoulockframe1 > 0 && ++enemyzannzoulockframe1 < 150) {//100くらいがちょうどいい、50だと
			enemyzannzoulock = 1;//★「通常状態」のダメージを食らった際の半透明について
			//★敵の画像を一時的に消す。これでダメージを食らったっぽくなる。
			//ここで敵が一瞬消えてif (enemyzannzoulockframe > 25) で0になるので、以前に書いた敵の通常状態の画像が半透明になる。
			//KABURI = 1;
			//★主人公の攻撃中も敵の攻撃中が攻撃した際に敵の攻撃が描画されるようにここに書いた。
			if (enemyzannzoulockframe1 > 0 && enemyzannzoulockframe1 < 5) {
				DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 50, pos[enemyY][enemyX][1] + playerattackhanndou3 - 30, bairituY, 0, enemydamegeHandle[0], TRUE);
			}
			if (enemyzannzoulockframe1 > 10 && enemyzannzoulockframe1 < 15) {
				DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 50, pos[enemyY][enemyX][1] + playerattackhanndou3 - 30, bairituY, 0, enemydamegeHandle[0], TRUE);
			}
			if (enemyzannzoulockframe1 > 20 && enemyzannzoulockframe1 < 25) {
				DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 50, pos[enemyY][enemyX][1] + playerattackhanndou3 - 30, bairituY, 0, enemydamegeHandle[0], TRUE);
			}
			if (enemyzannzoulockframe1 > 30 && enemyzannzoulockframe1 < 35) {
				DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 50, pos[enemyY][enemyX][1] + playerattackhanndou3 - 30, bairituY, 0, enemydamegeHandle[0], TRUE);
			}
			if (enemyzannzoulockframe1 > 40 && enemyzannzoulockframe1 < 45) {
				DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 50, pos[enemyY][enemyX][1] + playerattackhanndou3 - 30, bairituY, 0, enemydamegeHandle[0], TRUE);
				enemyzannzoulockframe1 = 1;
			}

		}
	}

	if (stayhereframe > 0 && ++stayhereframe > 150) {
		stayhereframe = 0;
		ranndamulock = 0;//再び物理攻撃できるように0にする。
		enemyzannzoulockframe1 = 0;
		if (ENEMYkougekigazouA1frame == 0 && ENEMYkougekigazouA2frame == 0) {
			enemyzannzoulock = 0;
		}
		stayhere3 = 0;
		enemyzannzoulock = 0;//★攻撃を与えたら敵の攻撃する「画像」を無しにする。
	}

	//敵に攻撃が当たらなかった際に主人公の攻撃画像が奥になるようにここに書いた。
	//主人公の攻撃中の敵と主人公の重なり具合。
	if (KABURI == 0) {//★攻撃中にここで重なる際の敵がそのままの表示では上でのif (enemyzannzoulockframe > 0 && ++enemyzannzoulockframe < 30)
		//の点滅の敵の画像に重なってしまい点滅していないように見えてしまうので、ダメージを受けてる状態の時はKABURIを1にしてここを反応させないためにここにif (KABURI == 0)を作った。
		if (motonomasunimodoru > 0) {//スライド移動中での敵との重なり具合を決める部分。
			//if (ranndamulock == 0) {//この数値で丁度いい//ランダムロックは重ならないためではなく敵の攻撃中は重なりがないようにするための物である。
			if (pos[enemyY][enemyX][0] + 100 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
				pos[enemyY][enemyX][0] - 100 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3
				&& pos[enemyY][enemyX][1] + playerattackhanndou3 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3) {
				//if (tabakosutterulock == 0) {
				KABURImark = 888;
				LEFTmark = 77777;
				//攻撃するときは1にしてるので、ここでさらにわざわざ1にしなくてもよい。それにif (ranndamulock == 0)の条件より攻撃する先は
				//ここを通らないのでここでは描画されない。
				//enemyzannzoulock = 1;//通常状態の敵を消して、こっちの画像にする。

				//こいつがここにあったため、タバコ回復中に静止した通常状態の画像が描画されてしまっていた。
				//なので上の主人公と同じ条件としてif (zannzoulock == 0)を加えた。

				if (enemyattaking == 0 && ranndamukougeki == 0 && enemyhirumaseframe == 0) {
					DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] + playerattackhanndou3, bairituY, 0, enemyImage, TRUE);
					LEFTmark = 1234;
				}//}
				//この部分はよくわかならないけど何かのために書いたのだろう。
				//if (enemyattaking == 1 && ranndamukougeki == 0 && enemyhirumaseframe == 0) {//★攻撃中の画像が出る瞬間は主人公が近寄ると通常状態の敵が描画され、
					//かつ攻撃が終わる場合には通常状態の敵が描画されないようにする。
				//	DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] + playerattackhanndou3, 4, 0, enemyImage, TRUE);
				//	LEFTmark = 5678;
				//}
			//}
			}
		}
		//★★通常状態であれ、攻撃状態であれ、主人公が攻撃しない場合は敵が前に重なるようにするために、ここに書いた。
		//KABURIの方はif (ranndamulock == 0) より敵が攻撃してこない場合でしか効果をなさないため、もしかしたら敵のranndamulockが0以外の時は反応しないため
		//この部分が必要だったのかもしれない。
		if (motonomasunimodoru == 0) {//スライド移動中での敵との重なり具合を決める部分。
			//if (ranndamulock == 0) {//この数値で丁度いい//ランダムロックは重ならないためではなく敵の攻撃中は重なりがないようにするための物である。
			if (pos[enemyY][enemyX][0] + 100 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
				pos[enemyY][enemyX][0] - 100 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3
				&& pos[enemyY][enemyX][1] + playerattackhanndou3 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3) {
				//if (tabakosutterulock == 0) {
				KABURImark = 888;
				LEFTmark = 77777;
				//攻撃するときは1にしてるので、ここでさらにわざわざ1にしなくてもよい。それにif (ranndamulock == 0)の条件より攻撃する先は
				//ここを通らないのでここでは描画されない。
				//enemyzannzoulock = 1;//通常状態の敵を消して、こっちの画像にする。

				//こいつがここにあったため、タバコ回復中に静止した通常状態の画像が描画されてしまっていた。
				//なので上の主人公と同じ条件としてif (zannzoulock == 0)を加えた。
				//zannzoulock = 1;
				if (enemyattaking == 0 && ranndamukougeki == 0 && enemyhirumaseframe == 0 ) {
					//DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, playerImage, TRUE);

					DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] + playerattackhanndou3, bairituY, 0, enemyImage, TRUE);
					LEFTmark = 1234;
				}//}
				//この部分はよくわかならないけど何かのために書いたのだろう。
				//if (enemyattaking == 1 && ranndamukougeki == 0 && enemyhirumaseframe == 0) {//★攻撃中の画像が出る瞬間は主人公が近寄ると通常状態の敵が描画され、
					//かつ攻撃が終わる場合には通常状態の敵が描画されないようにする。
				//	DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] + playerattackhanndou3, 4, 0, enemyImage, TRUE);
				//	LEFTmark = 5678;
				//}
			//}
			}
		}
	}

	//右回転して攻撃を避ける。
	if (input.RightTrigger == 255 && motonomasunimodoru > 0) {
		if (contorora == (PAD_INPUT_RIGHT) && kaitenncount == 0) {
			//zannzoulock = 1;
			kaitenn = 1;
			migimuki = 0;
			hidarimuki = 0;
			kaihilock = 1;
			++kaitenncount;
			nagurugazou = 0;

			migiaruku = 0;
			hidariaruku = 0;

		}
	}
	if (kaitenn == 1) {
		++kaitennframe;//右への回避は分母があると最初がのろくなり攻撃を食らってしまうので、ここは左回避とは違うようにする。
		//ステージ上ではマス移動しかないので、避ける場合はマス移動での避け方にする。
		//if (kaitennframe > 0 && kaitennframe < 2 && motonomasunimodoru == 0 && playerX < 2) {
		//	playerX = playerX + 1;//スライド無しでずっと移動でのyokeruXだと値が一方的に溜まるのでスライド移動なしでの避けるはpos[playerY][playerX][0]にする。
		//}
		//スライド攻撃中はマス移動は関係ないので、このままでいい。
		if (kaitennframe > 0 && kaitennframe < 15) {
			yokeruX = yokeruX + kaitennframe;
		}

		if (kaitennframe > 0 && kaitennframe < 3) {
			DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playeridouAHandle[0], TRUE);

		}
		if (kaitennframe > 3 && kaitennframe < 6) {
			DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playeridouA4Handle[0], TRUE);

		}
		if (kaitennframe > 6 && kaitennframe < 9) {
			DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playeridouA2Handle[0], TRUE);

		}
		if (kaitennframe > 9 && kaitennframe < 15) {
			DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playeridouA3Handle[0], TRUE);

		}
	}
	if (kaitennframe > 15) {
		kaitennframe = 0;
		zannzoulock = 0;
		kaitenn = 0;
		hidarimuki = 1;
		kaihilock = 0;
		++kaitenncountframe;
		nextattack = 0;
	}
	if (kaitenncountframe > 0) {
		++kaitenncountframe;
	}
	if (kaitenncountframe > 100) {
		kaitenncountframe = 0;
		kaitenncount = 0;
	}

	//左回転して攻撃を避ける。
	if (input.RightTrigger == 255 && motonomasunimodoru > 0) {//★YボタンとBボタンの同時押しでの移動だとなぜかtabakolockが1になりスライド移動後にタバコが吸えなかったり
		//R2を押してもロックオンが出ないバグが起きた。もしかしたらBボタンでの殴るボタンと方なるためのバグかもしれない。
		//なんにしてもバグがあるままではまずいので、ロックマークでの銃攻撃はなかったことにして、避ける攻撃にR2を使うことにして簡略化した。
		if (contorora == (PAD_INPUT_LEFT) && kaitenncount2 == 0) {
			//zannzoulock = 1;
			kaitenn2 = 1;
			migimuki = 0;
			hidarimuki = 0;
			kaihilock = 1;
			++kaitenncount2;
			nagurugazou = 0;

			migiaruku = 0;
			hidariaruku = 0;
		}
	}
	if (kaitenn2 == 1) {
		++kaitennframe2;
		//if (kaitennframe2 > 0 && kaitennframe2 < 2 && motonomasunimodoru == 0 && playerX > 0) {
		//	playerX = playerX - 1;//スライド無しでずっと移動でのyokeruXだと値が一方的に溜まるのでスライド移動なしでの避けるはpos[playerY][playerX][0]にする。
		//}
		if (kaitennframe2 > 0 && kaitennframe2 < 15) {
			yokeruX = yokeruX - kaitennframe2;
		}

		if (kaitennframe2 > 0 && kaitennframe2 < 3) {
			DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playeridouAhidariHandle[0], TRUE);

		}
		if (kaitennframe2 > 3 && kaitennframe2 < 6) {
			DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playeridouA4hidariHandle[0], TRUE);

		}
		if (kaitennframe2 > 6 && kaitennframe2 < 9) {
			DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playeridouA2hidariHandle[0], TRUE);

		}
		if (kaitennframe2 > 9 && kaitennframe2 < 15) {
			DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playeridouA3hidariHandle[0], TRUE);

		}
	}
	if (kaitennframe2 > 15) {
		kaitennframe2 = 0;
		zannzoulock = 0;
		kaitenn2 = 0;
		migimuki = 1;
		kaihilock = 0;
		++kaitenncountframe2;
		nextattack = 0;
	}
	if (kaitenncountframe2 > 0) {
		++kaitenncountframe2;
	}
	if (kaitenncountframe2 > 300) {
		kaitenncountframe2 = 0;
		kaitenncount2 = 0;
	}
	//主人公の倍率の部分//ステージを作る際の計算により(詳しくは画用紙に書いたが)、
	//+ 65の部分によりstage[0][6][1]より大きくて、stage[1][6][1]より小さい
	//pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3が交わり、その範囲がbairituX = 4.6となる条件となる。
	if (stage[0][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + 25 &&
		stage[0][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + 25 &&
		stage[1][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + 25 &&
		stage[1][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + 25 &&
		stage[0][0][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + 65 &&
		stage[1][0][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + 65 &&
		stage[0][6][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + 65 &&
		stage[1][6][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + 65
		) {
		bairituX = 4.2;
	}
	if (stage[1][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + 25 &&
		stage[1][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + 25 &&
		stage[2][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + 25 &&
		stage[2][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + 25 &&
		stage[1][0][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + 65 &&
		stage[2][0][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + 65 &&
		stage[1][6][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + 65 &&
		stage[2][6][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + 65
		) {
		bairituX = 4.5;

	}
	if (stage[2][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + 25 &&
		stage[2][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + 25 &&
		stage[3][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + 25 &&
		stage[3][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + 25 &&
		stage[2][0][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + 65 &&//①
		//stage[3][0][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + 65 &&//②
		stage[2][6][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + 65
		//stage[3][6][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + 65//ここを消しても一部分が変化しない奴は出来る。
		) {
		bairituX = 4.8;
	}

	//敵の倍率の部分
	if (stage[0][0][0] < pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 25 &&
		stage[0][6][0]>  pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 25 &&
		stage[1][0][0] <  pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 25 &&
		stage[1][6][0]>  pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 25 &&
		stage[0][0][1] < pos[enemyY][enemyX][1] + playerattackhanndou3 + 65 &&
		stage[1][0][1] > pos[enemyY][enemyX][1] + playerattackhanndou3 + 65 &&
		stage[0][6][1] < pos[enemyY][enemyX][1] + playerattackhanndou3 + 65 &&
		stage[1][6][1] > pos[enemyY][enemyX][1] + playerattackhanndou3 + 65
		) {
		bairituY = 4.6;

	}
	if (stage[1][0][0] <  pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 25 &&
		stage[1][6][0]>  pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 25 &&
		stage[2][0][0] <  pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 25 &&
		stage[2][6][0]>  pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 25 &&
		stage[1][0][1] < pos[enemyY][enemyX][1] + playerattackhanndou3 + 65 &&
		stage[2][0][1] > pos[enemyY][enemyX][1] + playerattackhanndou3 + 65 &&
		stage[1][6][1] < pos[enemyY][enemyX][1] + playerattackhanndou3 + 65 &&
		stage[2][6][1] > pos[enemyY][enemyX][1] + playerattackhanndou3 + 65
		) {
		bairituY = 5;

	}
	if (stage[2][0][0] <  pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 25 &&
		stage[2][6][0]>  pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 25 &&
		stage[3][0][0] <  pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 25 &&
		stage[3][6][0]>  pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 25 &&
		stage[2][0][1] < pos[enemyY][enemyX][1] + playerattackhanndou3 + 65 &&//①
		stage[3][0][1] > pos[enemyY][enemyX][1] + playerattackhanndou3 + 65 &&//②
		stage[2][6][1] < pos[enemyY][enemyX][1] + playerattackhanndou3 + 65 &&
		stage[3][6][1] > pos[enemyY][enemyX][1] + playerattackhanndou3 + 65//ここを消しても一部分が変化しない奴は出来る。
		) {
		bairituY = 5.4;
	}

	
	if (count < 50) {
		//DrawFormatString(50, 300, GetColor(0, 255, 255), "%d", count);//ここでcountの情報だけを条件(count < 500)より呼び出して、countの色を変えた
	}

	if (mozimark == 1) {
		//SetFontSize(44);
		//DrawFormatString(1000, 0, GetColor(255, 0, 0), "GOOD!!");
	}

	Red = GetColor(255, 0, 0);
	Bule = GetColor(0, 255, 0);
	//DrawBox(50, 100, 650, 110, Bule, TRUE);   // 四角形を描画(塗りつぶし))
	//if (playerHP > 200) {
	//	color = Red;
	//}
	//else if (playerHP <= 200) {
	//	color = Bule;
	//}
	//if (playerHPsubun > 0) {
	//	DrawBox(50, 100, playerHP + 50 + playerHPsubun, 110, Red, TRUE);   // 四角形を描画(塗りつぶし))
	//}
	DrawBox(50, 100, playerHP + 50, 110, Red, TRUE);
	DrawFormatString(60 + 600, 100, GetColor(255, 255, 0),
		"%d/600", playerHP);
	//敵のHP
	DrawBox(800, 100, 800 + 400, 110, Bule, TRUE);   // 四角形を描画(塗りつぶし))
	//if (playerHPsubun > 0) {
	//	DrawBox(50, 100, playerHP + 50 + playerHPsubun, 110, Red, TRUE);   // 四角形を描画(塗りつぶし))
	//}
	enemyHPgage = enemyHP / 2;
	DrawBox(800, 100, 800 + enemyHPgage, 110, Red, TRUE);
	DrawFormatString(810 + 400, 100, GetColor(255, 255, 0),
		"%d/800", enemyHP);
	
	DrawBox(0, 230, playerattackhanndou, 270, GetColor(255, 200, 30), TRUE);

	DrawFormatString(1, 700, GetColor(255, 255, 0),
	"向きhidarimukiは%d,向きmigimukiは%d,zannzoulockは%d,DAMEGEは%d,DAMEGEframeは%d",hidarimuki, migimuki, zannzoulock, playerkonntororulock, DAMEGE, DAMEGEframe);
	
	DrawFormatString(1, 800, GetColor(255, 255, 50),
		"playerkonntororulockは%d",playerkonntororulock);


	DrawFormatString(25, 200, GetColor(255, 255, 0), "Time to attack continuously");

	if (enemyHP > 0) {
		DrawFormatString(25, 20, GetColor(255, 255, 0), "※If you set the opponent's HP to 0, you will kill the opponent.");
		DrawFormatString(25, 40, GetColor(255, 255, 0), "※Try to persuade and not kill while fighting as much as possible.");
	}
	//何を選択しているかの表示
	if (GcountA == 1) { DrawFormatString(25, 250, GetColor(10, 100, 255), "グロッグリロード中"); }

	if (Gfunction_status == 0 && GcountA == 0) {
		DrawFormatString(25, 250, GetColor(255, 255, 0), "グロッグ射撃可能");
		DrawFormatString(25, 280, GetColor(255, 255, 0), "Gcount%d/Gcount%d", Gcount, Gcount2);
	}
	//関数settoku1()を呼んだままではこっちに帰ってくるとフリーズして終了するので、ここで関数の方に飛んですべて解決してから、こっちに帰ってくるようにする。
	if (enemyHP > 100 && enemyHP < 700) {
		settoku1();

	}
	//一回目の説得をこなさないと表示されないように一回目の説得をした場合のみserekutobotanncountを1とした。
	if (enemyHP > 100 && enemyHP < 400) {
		settoku2();

	}
	//一回目の説得をこなさないと表示されないように一回目の説得をした場合のみserekutobotanncountを1とした。
	if (enemyHP > 0 && enemyHP < 100) {
		settoku3();

	}
	if (serekutobotanncount == 4) {
		settoku4();
	}


	//敵の通常状態の動きを制御する部分。
	if (enemyMove >= 0 && ++enemyMove < 50) {//pcが60フレームで一周するためenemyMoveが61以上だとenemyGHandle[8]が反映されず元のままで移動が終わる。なのでenemyMoveは60以下でなくてはならない
		enemyImage = enemyGHandle[0];//60になる前に画像11を描画するようにしなければならないため、60より小さい40フレームにした。
	}
	if (enemyMove > 50 && enemyMove < 100) {//pcが60フレームで一周するためenemyMoveが61以上だとenemyGHandle[8]が反映されず元のままで移動が終わる。なのでenemyMoveは60以下でなくてはならない
		enemyImage = enemyGHandle[1];//60になる前に画像11を描画するようにしなければならないため、60より小さい40フレームにした。
	}
	if (enemyMove > 100 && enemyMove < 150) {//pcが60フレームで一周するためenemyMoveが61以上だとenemyGHandle[8]が反映されず元のままで移動が終わる。なのでenemyMoveは60以下でなくてはならない
		enemyImage = enemyGHandle[2];//60になる前に画像11を描画するようにしなければならないため、60より小さい40フレームにした。
	}
	if (enemyMove > 150) {
		enemyMove = 0;
	}

	if (DAMEGE == 0) {

		//ここにダメージを受けた際の主人公の情報を書いたほうが反応が速い
		if (playerHPsubun > 0 && --playerHPsubun > 0) {//playerHPsubunが0の時も減るので、残像ロックが0になってしまいif (playerHPsubun < 0)
					//でループしてしまいずっと0のままになるのでif (playerMove4 > 16)ように書いた。//敵と同じ原理。
			playerkonntororulock = 1;//攻撃を食らった最中は攻撃できないようにした。
			playerkonntororulock3 = 1;//攻撃を食らった最中は攻撃できないようにした。
			playerHP = playerHP - 1;
			zannzoulock = 1;
			playerHPsubunlock = 1;
			nextattack = 1;
			playerHPlock = 1;
			++sakebi;
			tabakosuenai = 1;//ダメージ中はタバコ画像を消す。
			//攻撃を食らったら攻撃の際の画像がでないように0にする。
			attackframe = 0;
			attackframe2 = 0;
			attackframe3 = 0;
			attackframe5 = 0;
			attackframe6 = 0;
		    attackframe7 =0;
			nagurugazou = 0;
			nagurugazou2 = 0;
		}

		if (playerHPsubunlock == 1) {
			++playerMove4;
		}

		if (playerMove4 > 0) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた
			DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerdamegeGHandle[0], TRUE);  // 俺キャラの描画


		}

		if (playerMove4 > 10) {
			int guasound = LoadSoundMem("ぐあ.m4a");
			ChangeVolumeSoundMem(170, guasound);//この関数によって音声のボリュームを設定できる。
			PlaySoundMem(guasound, DX_PLAYTYPE_BACK);
			playerMove4 = 1;
			//playerHPsubun = 0;
		}
		//2週目に入った際に主人公の操作が1のままとなり、動かせなったりするのだろう。なのでplayerMove4 = 0はここでなく下にかく。
		//与えたダメージ分でしか描画されないため、それに考慮しなくていいように改造した。
		//ずっとマイナスの方へ行かないようにここで0にする。
		//playerHPsubun
		if (playerHPsubun < 1 && playerHPsubunlock == 1) {//★<=ではなく<として、上の書き方によりplayerHPsubunが1で最後止まり,
		//	再びif (playerHPsubun > 0 && --playerHPsubun > 0)のplayerHPsubun > 0により1になり-1されを繰り返し、playerHPsubunが0になったら
			//if (playerHPsubun > 0 && --playerHPsubun > 0)の 条件は通らず1にはならず、条件の--だけ動き
			//playerHPsubunが1より小さくなり、ここを通りenemyHPsubunが0となる。
			
			playerMove4 = 0;
			playerHPsubun = 0;
			playerHPsubunlock = 0;
			playerkonntororulock = 0;
			playerkonntororulock3 = 0;//攻撃を食らった最中は攻撃できないようにした。
			//if(attackframe == 0 && attackframe2 == 0 && attackframe3 == 0 && attackframe5 == 0 && attackframe6 == 0 &&
			//	attackframe7 == 0 && naihuframe == 0 &&naihuframe2 == 0 ){
			zannzoulock = 0;
			//}
			nextattack = 0;
			playerHPlock = 0;
			DAMEGE = 0;
			sakebi = 0;
			tabakosuenai = 0;
			playermovelock2 = 0;//念のために
			playermovelock = 0;//念のために
			RIGHTbotannlock = 0;//念のために。

			playerHPsubunninnsiki = 0;
		}

	}
	if (sakebi == 1) {
		damegi1sound = LoadSoundMem("_game_swordman-damage2.mp3");
		PlaySoundMem(damegi1sound, DX_PLAYTYPE_BACK);
	}
	//主人公のHPの上限の設定
	if (playerHP > 600) {
		playerHP = 600;
	}
	if (DAMEGE == 0) {

		//ここにダメージを受けた際の主人公の情報を書いたほうが反応が速い
		if (playerHPsubun > 0 && --playerHPsubun > 0) {//playerHPsubunが0の時も減るので、残像ロックが0になってしまいif (playerHPsubun < 0)
					//でループしてしまいずっと0のままになるのでif (playerMove4 > 16)ように書いた。//敵と同じ原理。
			playerkonntororulock = 1;//攻撃を食らった最中は攻撃できないようにした。
			playerkonntororulock3 = 1;//攻撃を食らった最中は攻撃できないようにした。
			playerHP = playerHP - 1;
			zannzoulock = 1;
			playerHPsubunlock = 1;
			nextattack = 1;
			playerHPlock = 1;
			++sakebi;
			tabakosuenai = 1;//ダメージ中はタバコ画像を消す。
			//攻撃を食らったら攻撃の際の画像がでないように0にする。
			attackframe = 0;
			attackframe2 = 0;
			attackframe3 = 0;
			attackframe5 = 0;
			attackframe6 = 0;
			attackframe7 = 0;
			nagurugazou = 0;
			nagurugazou2 = 0;
		}

		if (playerHPsubunlock == 1) {
			++playerMove4;
		}

		if (playerMove4 > 0) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた
			DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerdamegeGHandle[0], TRUE);  // 俺キャラの描画


		}

		if (playerMove4 > 10) {
			int guasound = LoadSoundMem("ぐあ.m4a");
			ChangeVolumeSoundMem(170, guasound);//この関数によって音声のボリュームを設定できる。
			PlaySoundMem(guasound, DX_PLAYTYPE_BACK);
			playerMove4 = 1;
			//playerHPsubun = 0;
		}
		//2週目に入った際に主人公の操作が1のままとなり、動かせなったりするのだろう。なのでplayerMove4 = 0はここでなく下にかく。
		//与えたダメージ分でしか描画されないため、それに考慮しなくていいように改造した。
		//ずっとマイナスの方へ行かないようにここで0にする。
		//playerHPsubun
		if (playerHPsubun < 1 && playerHPsubunlock == 1) {//★<=ではなく<として、上の書き方によりplayerHPsubunが1で最後止まり,
		//	再びif (playerHPsubun > 0 && --playerHPsubun > 0)のplayerHPsubun > 0により1になり-1されを繰り返し、playerHPsubunが0になったら
			//if (playerHPsubun > 0 && --playerHPsubun > 0)の 条件は通らず1にはならず、条件の--だけ動き
			//playerHPsubunが1より小さくなり、ここを通りenemyHPsubunが0となる。

			playerMove4 = 0;
			playerHPsubun = 0;
			playerHPsubunlock = 0;
			playerkonntororulock = 0;
			playerkonntororulock3 = 0;//攻撃を食らった最中は攻撃できないようにした。
			//if(attackframe == 0 && attackframe2 == 0 && attackframe3 == 0 && attackframe5 == 0 && attackframe6 == 0 &&
			//	attackframe7 == 0 && naihuframe == 0 &&naihuframe2 == 0 ){
			zannzoulock = 0;
			//}
			nextattack = 0;
			playerHPlock = 0;
			DAMEGE = 0;
			sakebi = 0;
			tabakosuenai = 0;
			playermovelock2 = 0;//念のために
			playermovelock = 0;//念のために
			RIGHTbotannlock = 0;//念のために。

			playerHPsubunninnsiki = 0;
		}

	}
	if (sakebi == 1) {
		damegi1sound = LoadSoundMem("_game_swordman-damage2.mp3");
		PlaySoundMem(damegi1sound, DX_PLAYTYPE_BACK);
	}
	//主人公のHPの上限の設定
	if (playerHP > 600) {
		playerHP = 600;
	}





	//ロックオンマークの描画。//敵の上に重なるように最後に書いた。
	if (lock == 1 && InputX == 0 && InputY == 0) {

		//LEFTmark = 43;
		lockmarkXzahyou = pos[playerY][playerX][0] + 150 - lockmarkyokoidou;
		lockmarkYzahyou = pos[playerY][playerX][1] - lockmarktateidou;
		DrawRotaGraph(lockmarkXzahyou, lockmarkYzahyou, 4, 0, lockImge, TRUE);
		//DrawExtendGraph(pos[playerX][playerX][0] - 10, pos[Y][enemyX][1] - 20, pos[enemyY][enemyX][0] + 35, pos[enemyY][enemyX][1] + 40, lockImge, TRUE);
	}//ロックマークの描画
	if (lock == 1 && InputX == 0 && InputY == 0) {
		DrawFormatString(100, 200, GetColor(255, 255, 255), "LOCK");//ループ内に書くと条件式lockのによりlockの値を0にしてもずっと表示されるため、必要な時に表示するようにここに書いた

		//DrawFormatString(50, 300, GetColor(255, 0, 0), "%d/%d", count, count2);//1回殴った時にすべて消費して、再び溜まるまでの過程を表示するための関数
	}


}


#endif