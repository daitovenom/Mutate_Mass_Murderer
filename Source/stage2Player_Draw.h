#include "Player/playerhensuuVr2.h"
#include "syuzinnkouKOUGEKI.h"
#include "settoku2.h"
#include "suraidoidoubyouga.h"
#include "kasurikougeki.h"
#include "UEsuraido.h"
#include "syuzinkoukougekigazou.h"
#include "syuzinnkouKENJYUU.h"
#include "syuzinnkouDAMEGIjyoutai.h"
#include "settoku2.h"
#include "aruku.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>




#ifndef DEF_STAGE2PLAYER_DRAW_H //二重include防止

#define DEF_STAGE2PLAYER_DRAW_H
//★★ヘッダファイルと関数について。
//多分、関数stage1PlayerDraw()を呼ぶ際にここにもstage1.hを書くとstage1.hに書いてある関数stage1PlayerDraw()を呼んでしまい、二重になるため、
//このヘッダファイルにはstage1.hを書くとエラーが出る。それ以外のヘッダファイルは書く意味はないが、もし書いたとしてもエラーにはならないだろう。


void stage2PlayerDraw() {

	if (gamenidou == 0) {
		if (playerHP > 0) {
			PlaySoundMem(stage2sound, DX_PLAYTYPE_LOOP, FALSE);
		}
		DrawExtendGraph(0, 0, 1470, 480, stage2haikeiHandle, FALSE);




		// Ｚバッファを有効にする
		//SetUseZBuffer3D(TRUE);

		// Ｚバッファへの書き込みを有効にする
		//SetWriteZBuffer3D(TRUE);

		// ３Ｄ空間上に円錐を描画する
		//DrawCone3D(VGet(0, 249, 0), VGet(0, 109, 100), 80.0, 16, GetColor(200, 49, 255), GetColor(255, 255, 255), TRUE);

		// !!!!追加//レンガの地面を描画する部分。
		//DrawModiGraph(398, 433, 1102, 433,
		//	1440, 510, 60, 510,
		//	jimenGHandle, 1);


		// !!!!囲い
		//DrawLine3D(VGet(398, 433, 0), VGet(1102, 433, 0), GetColor(255, 200, 255));//一番奥
		//DrawLine3D(VGet(398, 433, 0), VGet(60, 510, 0), GetColor(255, 200, 255));//左
		//DrawLine3D(VGet(60, 510, 0), VGet(1440, 510, 0), GetColor(255, 200, 255));//右
		//DrawLine3D(VGet(1102, 433, 0), VGet(1440, 510, 0), GetColor(255, 200, 255));//前


		// 家モデルの座標を変更する
		//MV1SetPosition(houseModel, VGet(500, 600, 0));
		// ３Ｄモデルの描画
		//MV1DrawModel(houseModel);


		//画面に映る位置に３Ｄモデルを移動
		MV1SetPosition(poleModel, VGet(-1050 + 3097 + 1525 + -2 - 2935 + 13 + ugokuX, 257 + 878 - 773 + 9, 2000.f + 161 - 2.0 - 2657 - 4));
		//第二引数の回転角度をセット
		MV1SetRotationXYZ(poleModel, VGet(0.2 - 0.15 + 0.01 + 0.22 + 0.32 - 0.43, 99.9 + 0.32 + 1.33 - 0.08 + 1.58999 + ugokuX2, 0.01f - 0.01 + 0.08 + 0.01));//縦向きの角度、横向きの角度、全体を回す的な角度//整数だと調節が難しいので、小数点で調節する。
		// ３Ｄモデルの描画
		MV1DrawModel(poleModel);
		// モデルハンドルの削除
		//MV1DeleteModel(poleModel);

			//画面に映る位置に３Ｄモデルを移動
		MV1SetPosition(jimenGHandle, VGet(741, 375, -526));
		//第二引数の回転角度をセット
		MV1SetRotationXYZ(jimenGHandle, VGet(0, 1.56999, 0));//縦向きの角度、横向きの角度、全体を回す的な角度//整数だと調節が難しいので、小数点で調節する。

		// ３Ｄモデルの描画
		MV1DrawModel(jimenGHandle);
		// モデルハンドルの削除



		//画面に映る位置に３Ｄモデルを移動
		//MV1SetPosition(firudoModel, VGet(397+403,49+243,-462-0.07));
		//第二引数の回転角度をセット
		//MV1SetRotationXYZ(firudoModel, VGet(0.05,0.02,1.43999+0.14));//縦向きの角度、横向きの角度、全体を回す的な角度//整数だと調節が難しいので、小数点で調節する。
		// ３Ｄモデルの描画
		//MV1DrawModel(firudoModel);


		//画面に映る位置に３Ｄモデルを移動
		MV1SetPosition(old_trailerHandle, VGet(-1050 + 3097 + 1525 - 2 - 482 - 57, 257 + 878 - 59 + 118, 5900.f + 161 - 2.0 - 1189 + 413));
		//第二引数の回転角度をセット
		MV1SetRotationXYZ(old_trailerHandle, VGet(0.2 - 0.15 + 0.01 + 0.22 - 0.18 - 0.05 - 0.01 + 0.2 - 0.1 - 0.09, 99.9 + 0.32 + 1.33 - 0.08 - 0.34 - 0.07 - 0.08 + 0.2 + 0.05, 0.01f - 0.01 - 0.08 + 0.03));//縦向きの角度、横向きの角度、全体を回す的な角度//整数だと調節が難しいので、小数点で調節する。

		// ３Ｄモデルの描画
		MV1DrawModel(old_trailerHandle);
		// モデルハンドルの削除
		//MV1DeleteModel(old_trailerHandle);

		// ムービー映像を、背景を画面いっぱいに描画します
		//DrawExtendGraph(327, 348, 1173, 100, MovieGraphHandle, FALSE);

		//雪の降る演出のための部分
		//if (snow == 1) {
		//	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 70);		//ブレンドモードをα(128/255)に設定
		//	DrawExtendGraph(0, 0, 1770, 980, snowGraphHandle, FALSE);
		//}
		//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//ブレンドモードをリセット（他の画像が薄くならないようにするため）	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - toumeika);		//ブレンドモードをα(128/255)に設定




		// ウエイトをかけます、あまり速く描画すると画面がちらつくからです
		//WaitTimer(0);//この部分の数値を上げると敵の攻撃が遅くなる。
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
				if (Pad[PAD_6] == 1) {
					//lockmark = 1;
					//lockonMove = 1;//アタックする時　ロックオンの画像が消えるように値を0にする。
					//zannzou = 0;//i★f (zannzou <= 30 && zannzou > 0)の条件を通って再び主人公が描画されるので、その条件を通過しないように
					//zannzou = 0と書いてしまうと主人公が敵の目の前に飛んだ後に消えてしまう。
					R1lock = 1;
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
					if (enemyY == playerY && playerX == enemyX - 1) {
						//zannzou = 50;
						lockmark = 1;
						lockonMove = 1;//何枚かのロックオンマークをフレームで描画してロックオンマークが動くようにするための変数。
						lock = 1;//ロックオンした際に左上にlockという文字を描画するための変数。
						sinnzoubyouga = 1;
						kougekilock = 1;
						//LEFTmark = 4545;

						if (Pad[PAD_6] == 1) {
							kougekiroclmark = 1;//R1を押しても前の座標を記憶しないように
						}



					}
				}
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
			playerkonntororulock = 1;
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
			zannzoulock = 0;
			playerkonntororulock = 0;
		}

		//★下と上のスライドコマンドは倍率は固定のままでいい。
		//下コマンドの残像
		//★最初の方は画像の倍率を2にして、後は通常と同じ5倍にして、若干画像を移動方向に少しずらし、かつX方向は下に移動する際は少し前に出る感じでずらしてステップを踏むように移動させた。上の場合は下バージョンの逆を行った。
		if (zannzouB <= 15 && zannzouB > 0) { //★残像を出すためにRキーでAを押したら変数zannzouが20になり、zannouの変数が0より大きいならば—1をしていき、その間だけ画像を描画する。
			--zannzouB;
			DrawRotaGraph(pos[playerY][playerX][0] + 30 + 3 * zannzouB / 2, pos[playerY][playerX][1] - 5 * zannzouB, 2.0, 0, playerGHandle[0], TRUE);
			//移動中にR1を押すとzannzouの変数が1になりにバグが応じて主人公が消えてしまうことがある。
			//なので移動中はR1を押しても反応しないようにする。
			lockdekinai = 1;//R1が押せないように条件外の変数の値にする。
			if (Pad[PAD_6] == 1) {
				lockmark = 0;//ロックマークを描画するための変数
				lockonMove = 0;//何枚かのロックオンマークをフレームで描画してロックオンマークが動くようにするための変数。
				lock = 0;//ロックオンした際に左上にlockという文字を描画するための変数。
			}
		}
		if (zannzouB <= 13 && zannzouB > 0) {
			DrawRotaGraph(pos[playerY][playerX][0] + 30 + 3 * zannzouB / 2.5, pos[playerY][playerX][1] - 5 * zannzouB / 1.5, 5.0, 0, playerGHandle[0], TRUE);
		}
		if (zannzouB <= 11 && zannzouB > 0) {
			DrawRotaGraph(pos[playerY][playerX][0] + 30 + 3 * zannzouB / 3, pos[playerY][playerX][1] - 5 * zannzouB / 2, 5.0, 0, playerGHandle[0], TRUE);
		}
		if (zannzouB <= 9 && zannzouB > 0) {
			DrawRotaGraph(pos[playerY][playerX][0] + 30 + 3 * zannzouB / 3.5, pos[playerY][playerX][1] - 5 * zannzouB / 2.5, 5.0, 0, playerGHandle[0], TRUE);
		}
		if (zannzouB <= 7 && zannzouB > 0) {
			DrawRotaGraph(pos[playerY][playerX][0] + 30 + 3 * zannzouB / 4, pos[playerY][playerX][1] - 5 * zannzouB / 3, 5.0, 0, playerGHandle[0], TRUE);
		}
		if (zannzouB <= 3 && zannzouB > 0) {
			DrawRotaGraph(pos[playerY][playerX][0] + 30 + 2 * zannzouB / 4.5, pos[playerY][playerX][1] - 5 * zannzouB / 3.5, 5.0, 0, playerGHandle[0], TRUE);
			zannzouBsaigo = 1;
		}
		if (zannzouBsaigo == 1) {
			zannzoulock = 0;
			lockdekinai = 0;
			zannzouBsaigo = 0;
			zannzouB = 0;
			R1lock = 0;
		}

		//上のコマンドの残像//このままでいい。
		if (zannzouC > 0 && zannzouC <= 15) { //★残像を出すためにRキーでAを押したら変数zannzouが20になり、zannouの変数が0より大きいならば—1をしていき、その間だけ画像を描画する。
			--zannzouC;
			DrawRotaGraph(pos[playerY][playerX][0] + 30 - 3 * zannzouC / 5, pos[playerY][playerX][1] - 1 * zannzouC / 4, 2.0, 0, playerGHandle[0], TRUE);
			//移動中にR1を押すとzannzouの変数が1になりにバグが応じて主人公が消えてしまうことがある。
			//なので移動中はR1を押しても反応しないようにする。
			lockdekinai = 1;//R1が押せないように条件外の変数の値にする。
			if (Pad[PAD_6] == 1) {
				lockmark = 0;//ロックマークを描画するための変数
				lockonMove = 0;//何枚かのロックオンマークをフレームで描画してロックオンマークが動くようにするための変数。
				lock = 0;//ロックオンした際に左上にlockという文字を描画するための変数。
			}
		}
		if (zannzouC <= 3 && zannzouC > 0) {
			DrawRotaGraph(pos[playerY][playerX][0] + 30 - 3 * zannzouC / 4.5, pos[playerY][playerX][1] - 1 * zannzouC / 3.5, 2.0, 0, playerGHandle[0], TRUE);
			zannzouCsaigo = 1;
		}
		if (zannzouC <= 7 && zannzouC > 0) {
			DrawRotaGraph(pos[playerY][playerX][0] + 30 - 3 * zannzouC / 4, pos[playerY][playerX][1] - 1 * zannzouC / 3, 5.0, 0, playerGHandle[0], TRUE);
		}
		if (zannzouC <= 9 && zannzouC > 0) {
			DrawRotaGraph(pos[playerY][playerX][0] + 30 - 3 * zannzouC / 3.5, pos[playerY][playerX][1] - 1 * zannzouC / 2.5, 5.0, 0, playerGHandle[0], TRUE);
		}
		if (zannzouC <= 11 && zannzouC > 0) {
			DrawRotaGraph(pos[playerY][playerX][0] + 30 - 3 * zannzouC / 3, pos[playerY][playerX][1] - 1 * zannzouC / 2, 5.0, 0, playerGHandle[0], TRUE);
		}
		if (zannzouC <= 13 && zannzouC > 0) {
			DrawRotaGraph(pos[playerY][playerX][0] + 30 - 3 * zannzouC / 2.5, pos[playerY][playerX][1] - 1 * zannzouC / 1.5, 5.0, 0, playerGHandle[0], TRUE);
		}
		if (zannzouCsaigo == 1) {
			zannzoulock = 0;
			lockdekinai = 0;
			zannzouCsaigo = 0;
			zannzouC = 0;
			R1lock = 0;
		}


		//上のコマンドの残像//このままでいい。
		UEsuraido();


		KENJYUU();

		//★敵の初期位置
		//敵が開始直後にいきなり動かない様にするためのプログラム。
		//★この部分は戦闘開始の瞬間ではすでに敵が動いてしまい、中心にいないので開始して数フレームの間は真ん中に固定した。そのほうが戦闘がきれいに始まる・
		if (enemybyougablock == 0) {//敵の二人殺されたときの一瞬に敵が描画されないようにするための変数。
			if (stayhere == 1 && stayherelock3 == 1) {//↓if (stayhere == 1&& stayherelock == 0)とした理由。
//stayhere == 1だけでは敵を倒した際に敵を動かなくするためにstayhereが1になるため、ここで引っ掛かり、敵は動かないで消えるが、同時にここに書いた
//固定の座標の敵が再び描画されてしまう。なのでif (stayhere == 1&& stayherelock == 0)と書いた。敵のHPが0より小さくなった際の下に書いた
//if文より、敵が動かないようにstayhereは1としたがstayherelockが0のままだとif(stayhere == 1 && stayherelock == 0)に引っ掛かり固定された敵が描画
//されるのでここに引っ掛からない様にstayhereの値を1にした。
				++enemystayhere;
			}

			// !! 50になっている値を150へ変更しました

			if (enemystayhere > 0 && enemystayhere < 100) {
				//★battle start中にボタンを押しまくったりするとstayherelockが1になりフenemystayhere

								 //が繰り上がらなくなり敵の値が止まり、動かないままになるので
				//この期間中は何が起きてもstayherelockが0のままになるようにここに書いた。
				enemyImage = enemyGHandle[0];
				enemyImage2 = enemy2[0];
				enemyImage3 = enemy3[0];
				DrawRotaGraph(pos[1][4][0], pos[1][4][1] - 30, 4.6, 0, enemyImage2, TRUE);
				DrawRotaGraph(pos[2][5][0], pos[2][5][1] - 30, 5.4, 0, enemyImage3, TRUE);
				//★座標を定めても画像自体の描画までが少し時間がかかるため、上のように書いた。
				////DrawExtendGraph(pos[1][4][0]-15 , pos[1][4][1] - 66, pos[1][4][0] + 40, pos[1][4][1] + 66, enemyImage, TRUE);
				//DrawExtendGraph(pos[1][4][0] - 14, pos[1][4][1] - 66, pos[1][4][0] + 64, pos[1][4][1] + 66, enemyGHandle[11], TRUE);でもよい。その場合は前のenemyImage = enemyGHandle[11];はいらない
			}
			if (enemystayhere > 100) {
				enemystayhere = 0;
				stayhere = 0;
				stayhere2 = 0;
				stayherelock3 = 0;//この変数によってenemystayhereがⅭを超えてから初期位置の敵が描画されない。
				//if (stayhere == 1 && stayherelock3 == 1)と値を持たせた上で0にしたので仮に0にする必要がなくても
				//値を持たせた以上0にする必要があったのだろう。
				stayherelock2 = 0;
				enemy1HPhyouji = 0;
				enemy2HPhyouji = 0;
				//enemymovelock = 0;
				//stayherelock = 1;//★if (stayhere == 1&& stayherelock == 0)の条件に引っ掛かり条件の{}の働きが出てこないようにstayherelockの値を0にした。
				enemybyougablock = 1;
				//enemybyougablock2 =1;
			}

		}
		//syuzinnkouKOUGEKI();
		syuzinkoukougekigazou();//★この関数に含まれる部分と下の重なりの部分で敵に被っても違和感のないようにタバコが吸える。


	//主人公を描画
	//DrawExtendGraph(pos[playerY][playerX][0] - 14, pos[playerY][playerX][1] - 66, pos[playerY][playerX][0] + 64, pos[playerY][playerX][1] + 66, playerImage, TRUE);
	//↓回転させる関数の方で5.5倍にした奴。
	//★スライド移動中での左右反転の部分
		if (byougajyunnbann == 0) {
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

				}
			}

			//マス移動での主人公の描画
			//主人公を描画
				//DrawExtendGraph(pos[playerY][playerX][0] - 14, pos[playerY][playerX][1] - 66, pos[playerY][playerX][0] + 64, pos[playerY][playerX][1] + 66, playerImage, TRUE);
				//↓回転させる関数の方で5.5倍にした奴。
			if (zannzoulock == 0 && migimuki == 1) {
				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage, TRUE);
			}
			//試しのドット画像を使った部分
			//LoadGraphScreen(pos[playerY][playerX][0]-50, pos[playerY][playerX][1]-100, "image2 (1).jpeg", TRUE); // 画像を描画する

			//敵1の攻撃を描画
			if (ENEMYkougekigazouA1frame > 0 && ENEMYkougekigazouA1frame < 60) {

				if (enemyzannzoulock2 == 1) {
					UEsuraido();
					DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiB1Handle[0], TRUE);

				}

			}
			if (ENEMYkougekigazouA2frame > 0 && ENEMYkougekigazouA2frame < 70) {

				if (enemyzannzoulock2 == 1) {
					UEsuraido();
					DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiA1Handle[0], TRUE);

				}

			}

			//敵を描画
			if (enemyzannzoulock2 == 0 && enemyhirumaseframe == 0 && enemyKENJYUUcount == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
				//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
				//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。
				if (enemystayhere == 0) {
					//LEFTmark = 1234;
					DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, enemyImage2, TRUE);
				}
				//LEFTmark = 7364898;
			}

			if (stayherelock2 == 0) {
				if (anotherenemyzannzoulock == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
					//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
					//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。

					//LEFTmark = 65432;
					DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, enemyImage3, TRUE);

				}

			}
		}

		//stayhere1==1やstayhere2==1は書いているとどっちかが死んだ場合だと動かなくなるので、書かなくていい。
		//敵1がやられた際にHPが消えて、敵の動きが止まるように書いた。





	}


	if (playerkonntororulock == 0) {
		//回復を表す?マーク
		if (tabakokaihukumark > 0) {//1フレームで処理を終わらせるためifの後はelse ifを使った。//フレームがあってもplayerMove++を書かないと1ずつ上がらない。playerMove++をフレームの60回ループするするところに書くことで以下のように書いて足踏みしている画像が描けた。
			tabakokaihukumark++;//60フレームの中で、このifで条件(playerMove > 0)が真であるためplayerMove++を「フレーム」と「条件式」により繰り返しplayerMove++して、
			if (tabakokaihukumark > 0 && tabakokaihukumark < 20)//以前の文を否定しないelse ifが次にあるためplayerMoveの情報を引き継ぎplayerMove == 20となるまで繰り返しplayerMove++をした。次にもelse ifがあるので同様、、、
			{

				DrawExtendGraph(pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 200 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, pos[playerY][playerX][0] + 60 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 100 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, hartmarkhanndle[0], TRUE);

			}
			if (tabakokaihukumark > 20 && tabakokaihukumark < 40)//条件式として書くため=は==と書いた。//else ifによりplayerMoveが20を超えて(20の場合を否定し)30の場合を表す。
			{

				DrawExtendGraph(pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 200 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, pos[playerY][playerX][0] + 60 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 100 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, hartmarkhanndle[1], TRUE);

			}
			if (tabakokaihukumark > 40 && tabakokaihukumark < 60) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた
				//上に書いてることには誤りがある、60フレームで1sなだけ、超えてもいい。
				DrawExtendGraph(pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 200 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, pos[playerY][playerX][0] + 60 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 100 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, hartmarkhanndle[2], TRUE);
				tabakokaihukumark = 0;//
			}

		}


		//敵に攻撃した時の敵から出る血の描画のための部分。
		if (motonomasunimodoru >= 0) {
			if (bloodMove > 0) {//1フレームで処理を終わらせるためifの後はelse ifを使った。//フレームがあってもplayerMove++を書かないと1ずつ上がらない。playerMove++をフレームの60回ループするするところに書くことで以下のように書いて足踏みしている画像が描けた。
				++bloodMove;//60フレームの中で、このifで条件(playerMove > 0)が真であるためplayerMove++を「フレーム」と「条件式」により繰り返しplayerMove++して、
				if (bloodMove == 5)//以前の文を否定しないelse ifが次にあるためplayerMoveの情報を引き継ぎplayerMove == 20となるまで繰り返しplayerMove++をした。次にもelse ifがあるので同様、、、
				{
					bloodImage = bloodGHandle[0];
				}
				else if (bloodMove == 8)//条件式として書くため=は==と書いた。//else ifによりplayerMoveが20を超えて(20の場合を否定し)30の場合を表す。
				{
					bloodImage = bloodGHandle[1];
				}
				else if (bloodMove == 13)//30まで上がったものが40に上がった時、playerGHandle[4]になる。if文の連続では文法のルールで前の文を否定するため連続的に画像が流れず足踏みできない、なのでelse ifにしたのだ。
				{
					bloodImage = bloodGHandle[2];
				}
				else if (bloodMove > 13)//30まで上がったものが40に上がった時、playerGHandle[4]になる。if文の連続では文法のルールで前の文を否定するため連続的に画像が流れず足踏みできない、なのでelse ifにしたのだ。
				{
					bloodMove = 0;//
					bloodImage = 0;
					sinnzoubyouga = 0;//sinnzoubyougaが0より大きい時はbloodMoveが繰り返すので心臓の描画を消すのを利用してbloodの描画を繰り返さないようにした。っていうか心臓の描画もいらないかもしれない。

				}

			}
		}
		//敵1への銃で遠くから撃って当たった時の血しぶき
		if (sinnzoubyouga > 0 && kougekiKANOU == 10) {
			//++bloodMove;
			//enemystayhere = 0;//たぶんここで敵の通常の動きを消して、やられたときの動きと血しぶきにする。
			//++enemymigi;
			DrawExtendGraph(pos[enemyY1][enemyX1][0] - 14 + (20) + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] - (30) + playerattackhanndou3, pos[enemyY1][enemyX1][0] + 64 + (30) + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] + playerattackhanndou3, bloodImage, TRUE);

		}

		//敵1への銃で遠くから撃って当たった時の血しぶき
		if (sinnzoubyouga > 0 && kougekiKANOU == 20) {
			//++bloodMove;
			//enemystayhere = 0;//たぶんここで敵の通常の動きを消して、やられたときの動きと血しぶきにする。
			//++enemymigi;
			DrawExtendGraph(pos[enemyY2][enemyX2][0] - 14 + (20) + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B, pos[enemyY2][enemyX2][1] - (30) + playerattackhanndou3B, pos[enemyY2][enemyX2][0] + 64 + (30) + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B, pos[enemyY2][enemyX2][1] + playerattackhanndou3B, bloodImage, TRUE);

		}


	}

	//主人公の攻撃の画僧を描画するための関数
	if (motonomasunimodoru > 0) {
		syuzinkoukougekigazou();
	}

	//攻撃判定その一(ロックしてから銃による攻撃判定)
	if (hannilock == 2) {
		//敵1への攻撃
		if (pos[enemyY1][enemyX1][0] - 30 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 < lockmarkXzahyou && pos[enemyY1][enemyX1][0] + 30 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 > lockmarkXzahyou
			&& pos[enemyY1][enemyX1][1] - 30 - 35 + playerattackhanndou3 < lockmarkYzahyou && pos[enemyY1][enemyX1][1] - 30 + 35 + playerattackhanndou3 > lockmarkYzahyou)
		{
			kougekiKANOU = 1;

			if (sinnzoubyouga > 0) {
				++bloodMove;
				//enemystayhere = 0;//たぶんここで敵の通常の動きを消して、やられたときの動きと血しぶきにする。
				//++enemymigi;
				DrawExtendGraph(pos[enemyY2][enemyX2][0] - 14 + (20) + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B, pos[enemyY2][enemyX2][1] - (30) + playerattackhanndou3B, pos[enemyY2][enemyX2][0] + 64 + (30) + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B, pos[enemyY2][enemyX2][1] + playerattackhanndou3B, bloodImage, TRUE);

			}

		}
		//敵2への攻撃
		else if (pos[enemyY2][enemyX2][0] - 30 + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B < lockmarkXzahyou && pos[enemyY2][enemyX2][0] + 30 + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B > lockmarkXzahyou
			&& pos[enemyY2][enemyX2][1] - 30 - 35 + playerattackhanndou3B < lockmarkYzahyou && pos[enemyY2][enemyX2][1] - 30 + 35 + playerattackhanndou3B > lockmarkYzahyou) {
			kougekiKANOU = 4;

			if (sinnzoubyouga > 0) {
				++bloodMove;
				//enemystayhere = 0;//たぶんここで敵の通常の動きを消して、やられたときの動きと血しぶきにする。
				//++enemymigi;
				DrawExtendGraph(pos[enemyY1][enemyX1][0] - 14 + (20) + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B, pos[enemyY1][enemyX1][1] - (30) + playerattackhanndou3B, pos[enemyY1][enemyX1][0] + 64 + (30) + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B, pos[enemyY1][enemyX1][1] + playerattackhanndou3B, bloodImage, TRUE);

			}

		}
		else {

			kougekiKANOU = 0;

		}
	}








	// 入力状態を取得
	GetJoypadXInputState(DX_INPUT_PAD1, &input);

	//Color = GetColor(255, 255, 255);
	//DrawFormatString(0, 0, RED, "LeftTrigger:%d RightTrigger:%d",
		//input.LeftTrigger, input.RightTrigger);

	//R1を押してから攻撃する。
		//説得中はスライド移動できない。//今★★書いてある数値が今のところ一番ちょうどいい。
	if (playerkonntororulock == 0) {
		if (keriwaza == 0) {
			//R1を押してからのスライド移動からの攻撃。
			if (R1botannlock == 0) {
				//移動中にスライド移動できないようにzannzoulockはここで0の時にしか押せないようにした。//殴るやキックと同時のボタンでスライドしないように。
				if (Pad[PAD_6] == 1 && zannzoulock == 0) {
					//★走りながらでもスライド攻撃できるようにした。
					RightTriggerlock = 1;//★R2でのロックが解けた後でスライド中にアナログパッドで移動しないようにするための変数。
					kaburulock = 1;
					//LEFTmark = 321321;
					kougekidekinailock = 1;
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


					rockon = 1;//スライド移動中がR2ボタンでのロックオン攻撃ができない様にするための変数。
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
					InputX = 0;
					InputY = 0;
					yokeruX = 0;
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
				playerkonntororulock3 = 0;
			}
			//たまに180になる直前でR1を押すとその後の処理が書いていないためnanameidouX3が0以外の値になるので、ここで念入りに0にしておく。
			if (syuzinnkouyokerulock == 0)//敵の攻撃をかわすための変数のロック。
			{
				if (motonomasunimodoru == 0) {
					//playerHPlock = 0;//かすり攻撃の蹴りの際にマスに戻る特にYを押すとplayerHPlockが1のままでコマンドを押さないと処理されずに1の
					//が残ってしまう。
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
					migimuki = 1;
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
		if (pos[enemyY1][enemyX1][0] + 40 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX &&
			pos[enemyY1][enemyX1][0] - 150 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX &&
			pos[enemyY1][enemyX1][1] + 20 + playerattackhanndou3 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY4 &&
			pos[enemyY1][enemyX1][1] - 20 + playerattackhanndou3 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5

			//pos[enemyY][enemyX][0] + 30 < pos[playerY][playerX][0] + 20 + playerattackhanndou + nanameidouX + migiidou&&
			//★元々は-150だったが、敵の攻撃範囲と近いと動かなくなるバグがあるのでXの方は-100にした、-120でもいいかもしれないが試していない。
			) {

			kougekilock = 1;
			kougekiKANOU = 2;

			//敵がダメージを受けると血が噴き出す。sinnzoutoumeikaの上がる値を利用する。
			//if (sinnzoubyouga > 0) {
			//	++bloodMove;
				//enemystayhere = 0;//たぶんここで敵の通常の動きを消して、やられたときの動きと血しぶきにする。
				//++enemymigi;
			//	DrawExtendGraph(pos[enemyY1][enemyX1][0] - 14 + (20) + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] - (30) + playerattackhanndou3, pos[enemyY1][enemyX1][0] + 64 + (30) + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] + playerattackhanndou3, bloodImage, TRUE);

			//}
			if (yokeru == 0) {
				yokeru = GetRand(10);
				if (yokeru == 5 && stayhereframe == 0) {//攻撃を食らってる場合は確率で5が出ても避けない。でないとダメージを食らったまま避けてしまう。
					yokeru = 0;
					playerattackhanndou3 = playerattackhanndou3 + 100;
				}
				else {
					++yokeruframe;
				}
			}
		}
		//敵2への物理攻撃//★敵1と敵2で範囲が被ると敵1に攻撃できないことがあるので、else ifとする。
		else if (pos[enemyY2][enemyX2][0] + 40 + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX &&
			pos[enemyY2][enemyX2][0] - 150 + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX &&
			pos[enemyY2][enemyX2][1] + 20 + playerattackhanndou3B > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 &&
			pos[enemyY2][enemyX2][1] - 20 + playerattackhanndou3B < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5) {


			kougekilock = 1;
			kougekiKANOU = 3;
			//input.RightTrigger = 1;


			//もう一人の敵がダメージを受けると血が噴き出す。sinnzoutoumeikaの上がる値を利用する。
			//if (sinnzoubyouga > 0) {
			//	++bloodMove;
				//enemystayhere = 0;//たぶんここで敵の通常の動きを消して、やられたときの動きと血しぶきにする。
				//++enemymigi;
			//	DrawExtendGraph(pos[enemyY2][enemyX2][0] - 14 + (20) + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B, pos[enemyY2][enemyX2][1] - (30) + playerattackhanndou3B, pos[enemyY2][enemyX2][0] + 64 + (30) + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B, pos[enemyY2][enemyX2][1] + playerattackhanndou3B, bloodImage, TRUE);

			//}

		}
		else {
			kougekiKANOU = 0;
			kasurikougeki();
		}
	}


	if (yokeruframe > 0 && ++yokeruframe > 100) {
		yokeruframe = 0;
		yokeru = 0;
	}










	//★ドットなどの画像を扱う関数は透明化できないため、透明化ができる映像を扱う関数を使う。
	if (settokutoumeika > 0) {//★toumeikaが0より大きくなっている間だけ敵を消したいので{}でまとめた。以前のif (mark == 0 && enemyHP < 1)では{}の中の描き方に関係なく、if (mark == 0 && enemyHP < 1)の条件に当てはまるものがすべて透明化してしまうので
				//if(toumeika >0)のように透明化したいもののみが透明化するように限定的にif(toumeika >0)の条件が働いている間だけ{}の働きがあるようにした。
		++settokutoumeikaframe;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 4 * settokutoumeikaframe);		//ブレンドモードをα(128/255)に設定
		PlayMovieToGraph(sentougoHandle);
		DrawExtendGraph(0, 0, 1770, 980, sentougoHandle, FALSE);
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);		//ブレンドモードをリセット（他の画像が薄くならないようにするため）	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - toumeika);		//ブレンドモードをα(128/255)に設定



	//if (pos[enemyY2][enemyX2][1] + playerattackhanndou3B > pos[enemyY1][enemyX1][1] + playerattackhanndou3 && enemyattaking == 1
	//	or pos[enemyY2][enemyX2][1] + playerattackhanndou3B < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 && enemyattaking == 0) {

	//	DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B, pos[enemyY2][enemyX2][1] + playerattackhanndou3B, bairituY2, 0, enemyImage, TRUE);
	//	UEsuraido();
	//}

	//敵の攻撃
	//敵の物理攻撃を描画する部分//※攻撃中の画像が前に出るようにしたかったので、ここの位置に追いた。まあ、同じプログラムを二つ作り、違う名前の二つの関数化して
		//場合に応じて呼び出すという手もある。

		//敵の攻撃
	//敵の物理攻撃を描画する部分//※攻撃中の画像が前に出るようにしたかったので、ここの位置に追いた。まあ、同じプログラムを二つ作り、違う名前の二つの関数化して
		//場合に応じて呼び出すという手もある。
	if (ENEMYmovelock2 == 0) {
		if (ENEMYkougekigazouA1frame > 0 && ++ENEMYkougekigazouA1frame < 60) {
			//LEFTmark = 23232323;
			//ENEMYkougekiA1Image = ENEMYkougekiA1Handle[1];
			enemyattackinglock = 1;//敵が攻撃するときだけは攻撃する画像のみが描画されるようにするための変数。
			if (enemyzannzoulock2 == 1  && byougajyunnbann == 0) {
				//enemyImage = ENEMYkougekiA1Handle[0];
				//UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiB1Handle[0], TRUE);

			}
			//if (pos[enemyY1][enemyX1][0] + 40 + playerattackhanndou + playerattackhanndou2 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
			//	pos[enemyY1][enemyX1][0] - 250 + playerattackhanndou + playerattackhanndou2 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
			//	pos[enemyY1][enemyX1][1] + 20 + playerattackhanndou3 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 &&
			//	pos[enemyY1][enemyX1][1] - 20 + playerattackhanndou3 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3)
			//{
			//★カウンターを連打して簡単にカウンターされないように。
			if (Pad[PAD_1] == 1) {
				++kaunntacount;//カウンターを連打してもカウンターをとれないように、タイミングを計るようにした。
			}
			//}
		}
	}
	if (ENEMYkougekigazouA1frame > 60) {
		ENEMYkougekigazouA1frame = 0;
		ENEMYkougekigazouA1lock = 1;
	}
	if (ENEMYkougekigazouA1lock == 1 && ENEMYkougekigazouA1frame == 0) {
		++ENEMYkougekigazouA2frame;
	}
	//ランダム数値でランダムの値が変わらないことで2frameを大きくすると攻撃する前に再び、1frameになってしまい攻撃できないことがある。
	//なのでここのフレームは短くする。
	if (ENEMYkougekigazouA2frame > 0 && ENEMYkougekigazouA2frame < 70) {

		if (enemyzannzoulock2 == 1 && byougajyunnbann == 0) {
			//enemyImage = ENEMYkougekiA2Handle[0];
			UEsuraido();
			DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiA1Handle[0], TRUE);

		}
		//if (pos[enemyY2][enemyX2][0] + 40 + playerattackhanndou + playerattackhanndou2 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
		//	pos[enemyY2][enemyX2][0] - 250 + playerattackhanndou + playerattackhanndou2 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 &&
		//	pos[enemyY2][enemyX2][1] + 20 + playerattackhanndou3 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 &&
		//	pos[enemyY2][enemyX2][1] - 20 + playerattackhanndou3 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3)
		//{
		/*if (pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX &&
			pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 150 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX &&
			pos[enemyY1][enemyX1][1] + playerattackhanndou3 + 15 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 &&
			pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 15 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5) {
			if (kaunntacount == 0) {
				if (Pad[PAD_1] == 1) {
					++kaunntacount;//カウンターを連打してもカウンターをとれないように、タイミングを計るようにした。
					enemyhirumaseframe = 1;
					ENEMYkougekigazouA1frame = 60;
					ENEMYkougekigazouA2frame = 60;
					ranndamukougeki = 0;
					DAMEGE = 1;
					playerHPsubun = 0;
					enemyzannzoulock2 = 1;//カウンターを食らった敵だけ描画できるように1にする。
				}
			}
		}*/

	}
	//敵1の拳銃攻撃
	//一番上
	if (a == 3) {


		if (enemyKENJYUUcount > 0 && ++enemyKENJYUUcount < 60) {
			if (enemyKENJYUUcount > 0 && enemyKENJYUUcount < 30) {
				DrawRotaGraph(1230, 300, 4.6, 0, enemy1KENJYUUHandle[0], TRUE);
				StartJoypadVibration(DX_INPUT_PAD1, 1000, 3 * enemyKENJYUUcount);//両方のモーターが振動。
			}
			if (enemyKENJYUUcount > 30 && enemyKENJYUUcount < 60) {
				DrawRotaGraph(1230, 300, 4.6, 0, enemy1KENJYUUHandle[1], TRUE);
				if (enemyKENJYUUcount > 30 && enemyKENJYUUcount < 32) {
					sound2 = LoadSoundMem("タイトルの銃声.mp3");
					PlaySoundMem(sound2, DX_PLAYTYPE_BACK);
				}
			}
		}


		//敵1が攻撃してくるときの振動して避ける合図を出している。
		if (stage[0][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX + 25 &&
			stage[0][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX + 25 &&
			stage[1][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX + 25 &&
			stage[1][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX + 25 &&
			stage[0][0][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
			stage[1][0][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
			stage[0][6][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
			stage[1][6][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65
			&& enemyKENJYUUcount > 0 && enemyKENJYUUcount < 50) {

			StartJoypadVibration(DX_INPUT_PAD1, 2000, 100);

		}


		if (stage[0][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX + 25 &&
			stage[0][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX + 25 &&
			stage[1][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX + 25 &&
			stage[1][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX + 25 &&
			stage[0][0][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
			stage[1][0][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
			stage[0][6][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
			stage[1][6][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65
			&& enemyKENJYUUcount > 58 && enemyKENJYUUcount < 60) {
			playerHPsubun = 51;
			//StartJoypadVibration(DX_INPUT_PAD1, 900, 100);
			//DAMEGE = 1;


		}

	}
	//真ん中//else ifだと他の銃攻撃がまだ動いてるときに他の銃攻撃を受けない時があるので。普通のifにした。
	else if (a == 6) {
		if (enemyKENJYUUcount > 0 && ++enemyKENJYUUcount < 60) {
			if (enemyKENJYUUcount > 0 && enemyKENJYUUcount < 30) {
				DrawRotaGraph(1260, 370, 5, 0, enemy1KENJYUUHandle[0], TRUE);
				StartJoypadVibration(DX_INPUT_PAD1, 1000, 3 * enemyKENJYUUcount);//両方のモーターが振動。

			}
			if (enemyKENJYUUcount > 30 && enemyKENJYUUcount < 60) {
				DrawRotaGraph(1260, 370, 5, 0, enemy1KENJYUUHandle[1], TRUE);
				if (enemyKENJYUUcount > 30 && enemyKENJYUUcount < 32) {
					sound2 = LoadSoundMem("タイトルの銃声.mp3");
					PlaySoundMem(sound2, DX_PLAYTYPE_BACK);
				}
			}

		}

		if (stage[1][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX + 25 &&
			stage[1][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX + 25 &&
			stage[2][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX + 25 &&
			stage[2][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX + 25 &&
			stage[1][0][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
			stage[2][0][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
			stage[1][6][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
			stage[2][6][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65
			&& enemyKENJYUUcount > 0 && enemyKENJYUUcount < 50) {
			StartJoypadVibration(DX_INPUT_PAD1, 2000, enemyKENJYUUcount);
		}

		if (stage[1][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX + 25 &&
			stage[1][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX + 25 &&
			stage[2][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX + 25 &&
			stage[2][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX + 25 &&
			stage[1][0][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
			stage[2][0][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
			stage[1][6][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
			stage[2][6][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65
			&& enemyKENJYUUcount > 58 && enemyKENJYUUcount < 60) {
			playerHPsubun = 51;
			//StartJoypadVibration(DX_INPUT_PAD1, 900, 100);
			//DAMEGE = 1;
			keriwaza = 0;
		}

	}
	//一番下。
	else if (a == 9) {
		if (enemyKENJYUUcount > 0 && ++enemyKENJYUUcount < 60) {
			if (enemyKENJYUUcount > 0 && enemyKENJYUUcount < 30) {
				DrawRotaGraph(1290, 400, 5.4, 0, enemy1KENJYUUHandle[0], TRUE);
				StartJoypadVibration(DX_INPUT_PAD1, 1000, 3 * enemyKENJYUUcount);//両方のモーターが振動。

			}
			if (enemyKENJYUUcount > 30 && enemyKENJYUUcount < 60) {
				DrawRotaGraph(1290, 400, 5.4, 0, enemy1KENJYUUHandle[1], TRUE);
				if (enemyKENJYUUcount > 30 && enemyKENJYUUcount < 32) {
					PlaySoundMem(sound2, DX_PLAYTYPE_BACK);
				}
			}
		}

		if (stage[2][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX + 25 &&
			stage[2][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX + 25 &&
			stage[3][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX + 25 &&
			stage[3][6][0] > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX + 25 &&
			stage[2][0][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&//①
			stage[3][0][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&//②
			stage[2][6][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
			stage[3][6][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65//ここを消しても一部分が変化しない奴は出来る。
			&& enemyKENJYUUcount > 0 && enemyKENJYUUcount < 50) {

			StartJoypadVibration(DX_INPUT_PAD1, 2000, enemyKENJYUUcount);
		}

		if (stage[2][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX + 25 &&
			stage[2][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX + 25 &&
			stage[3][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX + 25 &&
			stage[3][6][0] > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX + 25 &&
			stage[2][0][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&//①
			stage[3][0][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&//②
			stage[2][6][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
			stage[3][6][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65//ここを消しても一部分が変化しない奴は出来る。
			&& enemyKENJYUUcount > 58 && enemyKENJYUUcount < 60) {
			playerHPsubun = 51;
			//StartJoypadVibration(DX_INPUT_PAD1, 900, 100);
			//DAMEGE = 1;
		}

	}

	if (enemyKENJYUUcount > 60) {
		enemy1HPhyouji = 0;
		enemyKENJYUUcount = 0;
		enemyzannzoulock2 = 0;
		stayhere = 0;
		//stayhere2 = 0;
		ranndamukougeki3 = 0;
		//ranndamukougeki = 0;
		a = 0;

		//青い敵が攻撃する時は赤い敵の攻撃を止めておくを解除。
		//stayhere2 = 0;
	}
	if (enemyKENJYUUcount > 60) {
		enemy1HPhyouji = 0;
		enemyKENJYUUcount = 0;
		enemyzannzoulock2 = 0;
		stayhere = 0;
		//stayhere2 = 0;
		ranndamulock = 0;
		ranndamukougeki4 = 0;
		//ranndamukougeki = 0;
		a = 0;

		//青い敵が攻撃する時は赤い敵の攻撃を止めておくを解除。
		//stayhere2 = 0;
	}
	if (enemyKENJYUUcount > 60) {
		enemy1HPhyouji = 0;
		enemyKENJYUUcount = 0;
		enemyzannzoulock2 = 0;
		stayhere = 0;
		//stayhere2 = 0;
		ranndamulock = 0;
		ranndamukougeki5 = 0;
		//ranndamukougeki = 0;
		a = 0;
		//青い敵が攻撃する時は赤い敵の攻撃を止めておくを解除。
		//stayhere2 = 0;
	}
	//else {
	//	++enemyKENJYUUcount;
	//	if (enemyKENJYUUcount > 60) {
	//		ranndamulock = 0;
	//		enemyKENJYUUcount = 0;
			//a = 0;
	//		DAMEGE = 0;
	//	}
	//}
	//相手の攻撃を防いで、一定時間で怯ませロックが再び0に戻る。
	if (enemyhirumaseframe > 0) {
		++enemyhirumaseframe;
	}
	//怯んだ場合の時の場合を考えて220に設定する。それよりも短いとhirumaselock = 0;になってしまい、通常攻撃が当たった場合での処理を通ってしまい、
	//フレーム数分だけ怯まずに攻撃してきてしまう。
	if (enemyhirumaseframe > 190) {//以前に攻撃が終わった際に一瞬通常状態の敵が描画されていたが、その時は怯む部分もうまく機能していなかったため
		//怯みが早く終わってしまい、通常状態が描画された状態で確率により攻撃する画像も描画されてしまい、攻撃中に通常状態が描画されてしまっていたのあろう。
		//あるいは、攻撃が終わった後での処理がうまくいっていなかったのだろう。
		enemyhirumaseframe = 0;
		hirumaselock = 0;
		kaunntacount = 0;
		stayhere = 0;
		ranndamulock = 0;//0でも良い。
		enemyzannzoulock2 = 0;
		enemyhirumaseframe = 0;
		//stayherelock = 0;

		//ENEMYmovelock2 = 0;
		//ENEMYkougekigazouA1lock = 1;
		playerHPsubun = 0;
	}


	//怯ませる間のフレーム
	if (enemyhirumaseframe > 0 && ++enemyhirumaseframe < 190) {
		//LEFTmark = 1234;
		//anotherenemyzannzoulock = 1;
		ENEMYkougekigazouA1frame = 0;//念のためにここを付け足しても良い。
		ENEMYkougekigazouA2frame = 0;//ラグの問題で再び攻撃する時に繰り上がるのでそうならないように70にした。
		ENEMYkougekigazouA1lock = 0;//ENEMYkougekigazouA2framが繰り上がらないように。
		enemyzannzoulock2 = 1;
		stayhere = 1;

		//ranndamulock = 1;
		//処理が重いと敵がダメージを負いながら点滅して、同時に攻撃するようになるのはいいが、見栄えが良くないので
		//処理が軽くしないとスムーズに見えない。
		//★点滅してる回数が長いとダメージを食らった場合で点滅する場合のプログラムが先に終わるため敵の残像が先に1になってしまう。
		//なので通常の敵が描画された状態で上に点滅したカウンターを食らった敵が描画されてしまっていた。
		//なのでそうならないようにここでの数値を小さくして100くらいにした。
		if (enemyhirumaseframe > 0 && enemyhirumaseframe < 20 or
			enemyhirumaseframe > 40 && enemyhirumaseframe < 60 or
			enemyhirumaseframe > 80 && enemyhirumaseframe < 100 or
			enemyhirumaseframe > 120 && enemyhirumaseframe < 140 or
			enemyhirumaseframe > 160 && enemyhirumaseframe < 180)

		{
			//if (enemy1count == 1) {
			DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1hirumiHandle[0], TRUE);
			//}//カウンターを食らった状態での敵と重なる際に主人公が前にくるようにここに書いた。


		}
		if (enemyhirumaseframe > 0 && enemyhirumaseframe < 20) {
			//pos[playerY][playerX][0] = pos[playerY][playerX][0] - 1.5;
		}
	}
	if (enemyhirumaseframe > 0 && enemyhirumaseframe < 190) {
		stayhere = 1;
	}
	//敵1が攻撃してくるときの振動して避ける合図を出している。
	if (pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX &&
		pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 150 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX &&
		pos[enemyY1][enemyX1][1] + playerattackhanndou3 + 15 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 &&
		pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 15 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5
		&& ENEMYkougekigazouA2frame > 0 && ENEMYkougekigazouA2frame < 60 && ranndamukougeki == 1
		or
		pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX &&
		pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 150 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX &&
		pos[enemyY1][enemyX1][1] + playerattackhanndou3 + 15 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 &&
		pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 15 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5
		&& ENEMYkougekigazouA2frame > 0 && ENEMYkougekigazouA2frame < 60 && ranndamukougeki == 3) {

		StartJoypadVibration(DX_INPUT_PAD1, 100, 5 * ENEMYkougekigazouA2frame, 1);//右のモーターが振動。

	//enemyattackaizu;
	//	DrawBox(100 + pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX,
	//		-100 + pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5,
	//		200 + pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX,
	//		-50 + pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, color, TRUE);//四角を描画

	//この間に入力ボタンと、アナログパッドの方向キーが成功すれば、if文に行く。
		if (Pad[PAD_1] == 1) {
			++Rbotun;
		}

	}








	//もう一人の敵の攻撃。
		//敵の物理攻撃を描画する部分//※攻撃中の画像が前に出るようにしたかったので、ここの位置に追いた。まあ、同じプログラムを二つ作り、違う名前の二つの関数化して
		//場合に応じて呼び出すという手もある。
	if (ENEMYmovelock2 == 0) {
		if (ENEMYkougekigazouB1frame > 0 && ++ENEMYkougekigazouB1frame < 70) {
			//LEFTmark = 76767676;
			//ENEMYkougekiA1Image = ENEMYkougekiA1Handle[1];
			enemyattackinglock = 1;//敵が攻撃するときだけは攻撃する画像のみが描画されるようにするための変数。
			if (anotherenemyzannzoulock == 1 && byougajyunnbann == 0) {
				//enemyImage = ENEMYkougekiA1Handle[0];
				//UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiA1Handle[0], TRUE);

			}
			if (Pad[PAD_1] == 1) {
				++kaunntacount;//カウンターを連打してもカウンターをとれないように、タイミングを計るようにした。
			}
		}
	}
	if (ENEMYkougekigazouB1frame > 70) {
		ENEMYkougekigazouB1frame = 0;
		ENEMYkougekigazouB1lock = 1;
	}
	if (ENEMYkougekigazouB1lock == 1 && ENEMYkougekigazouB1frame == 0) {
		++ENEMYkougekigazouB2frame;
	}
	//ランダム数値でランダムの値が変わらないことで2frameを大きくすると攻撃する前に再び、1frameになってしまい攻撃できないことがある。
	//なのでここのフレームは短くする。
	if (ENEMYkougekigazouB2frame > 0 && ENEMYkougekigazouB2frame < 60) {

		if (anotherenemyzannzoulock == 1 && byougajyunnbann == 0) {
			//enemyImage = ENEMYkougekiA2Handle[0];
			//UEsuraido();
			DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiB1Handle[0], TRUE);

		}

		//避ける画像
		/*if (contorora == (PAD_INPUT_4 | PAD_INPUT_2)) {
			nagurugazou = 0;

			playerHPsubun = 0;
			jyuuzikeysousa2 = 1;//十字キーを押せないように
			syuzinnkouyokerulock = 1;//下の条件でのnanameidouX1～3が0にならないように1にする。
			++syuzinnkouyokeru;
		}
		if (syuzinnkouyokeru > 0) {
			++syuzinnkouyokeruframe;
		}
		if (syuzinnkouyokeruframe > 0 && syuzinnkouyokeruframe < 2) {
			//yokeruX = yokeruX - 30;
			zannzoulock = 1;
		}
		if (syuzinnkouyokeruframe > 10 && syuzinnkouyokeruframe < 25) {
			if (syuzinnkouyokeruframe > 10 && syuzinnkouyokeruframe < 12) {
				//yokeruX = yokeruX - 30;
			}
			DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, syuzinnkouyokerugazou[0], TRUE);

		}
		if (syuzinnkouyokeruframe > 35 && syuzinnkouyokeruframe < 50) {
			if (syuzinnkouyokeruframe > 35 && syuzinnkouyokeruframe < 37) {
				pos[playerY][playerX][0] = pos[playerY][playerX][0] - 100;
			}
			DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, syuzinnkouyokerugazou2[0], TRUE);
		}
		if (syuzinnkouyokeruframe > 50) {
			syuzinnkouyokeruframe = 50;
			syuzinnkouyokeru = 0;
			zannzoulock = 0;
			//yokeruX = 0;
			jyuuzikeysousa2 = 0;

		}*/
		//スライド移動で相手の攻撃を避けた際にグッドと出る。できれば、音声でCOOL!とか言ってほしい。

		/*if (pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX &&
			pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 150 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX &&
			pos[enemyY2][enemyX2][1] + playerattackhanndou3B + 15 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 &&
			pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 15 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5
			) {
			if (kaunntacount2 == 0) {
				if (Pad[PAD_1] == 1) {
					++kaunntacount2;//カウンターを連打してもカウンターをとれないように、タイミングを計るようにした。
					enemy2hirumaseframe = 1;
					ENEMYkougekigazouB1frame = 60;
					ENEMYkougekigazouB2frame = 60;
					ranndamukougeki = 0;
					DAMEGE = 1;
					playerHPsubun = 0;
					enemyzannzoulock3 = 1;
				}
			}
		}*/

	}

	//相手の攻撃を防いで、一定時間で怯ませロックが再び0に戻る。
	if (enemy2hirumaseframe > 0) {
		++enemy2hirumaseframe;
	}
	//怯んだ場合の時の場合を考えて220に設定する。それよりも短いとhirumaselock = 0;になってしまい、通常攻撃が当たった場合での処理を通ってしまい、
	//フレーム数分だけ怯まずに攻撃してきてしまう。
	if (enemy2hirumaseframe > 190) {//以前に攻撃が終わった際に一瞬通常状態の敵が描画されていたが、その時は怯む部分もうまく機能していなかったため
		//怯みが早く終わってしまい、通常状態が描画された状態で確率により攻撃する画像も描画されてしまい、攻撃中に通常状態が描画されてしまっていたのあろう。
		//あるいは、攻撃が終わった後での処理がうまくいっていなかったのだろう。
		enemy2hirumaseframe = 0;
		hirumaselock = 0;
		kaunntacount2 = 0;
		//stayhere2 = 0;//怯んだ場合ここで0になるので、下の方で0を書かなくてもよい。
		ranndamulock2 = 0;
		anotherenemyzannzoulock = 0;
		stayherelock2 = 0;
		ENEMYmovelock2 = 0;

		ENEMYmovelock2 = 0;
		ENEMYkougekigazouB1lock = 1;
		ENEMYkougekigazouB2frame = 0;
		//ENEMYkougekigazouB1lock = 0;
		stayhere2 = 0;
		playerHPsubun = 0;
		DAMEGE = 1;
		stayhereLOCK = 0;

		ENEMYmovelock2 = 0;//ラグによる画像の描画を無効化
		//enemyzannzoulock3 = 0;//画像の描画を無効化
		byougajyunnbann = 0;//画像の描画を無効化
		DrawBoxbyouga = 0;//赤い四角の描画の無効化
	}




	//敵2の怯ませる間のフレーム

	//フレームが動いているので、攻撃後にランダムで数を変えて、繰り返しを防いだうえで、最初の一回目の10から12のフレームの一フレーム
//が攻撃を食らうようにした。
	if (hirumaselock == 0) {
		if (pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX &&
			pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 150 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX &&
			pos[enemyY1][enemyX1][1] + playerattackhanndou3 + 15 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 &&
			pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 15 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5
			&& ENEMYkougekigazouA2frame > 58 && ENEMYkougekigazouA2frame < 60) {
			playerHPsubun = 51;

			//ranndamukougeki = 1;
			tabakosuenai = 1;//タバコ回復を邪魔する。
			//StartJoypadVibration(DX_INPUT_PAD1, 700, 100);
			//ENEMYkougekigazouA1frame = 0;★★こいつは処理の過程で0になり、++のような繰り上がりはないので0と過程で書いたので
			//そのまま0になったのでここに再度書かなくてもよい。
			//tekinoKOUGEKITYUUhahyouzisinailock = 0;
			//ENEMYkougekigazouA2frame = 0;//★★描画が連続で出てくるような状況についての解決法
			//ここにENEMYkougekigazouA2frame = 0を書くとENEMYkougekigazouA1lock == 1 &&ENEMYkougekigazouA1frame == 0に
			//通らないようにとここにENEMYkougekigazouA1lock = 0;とENEMYkougekigazouA1frame = 1;書いてもランダム変数の数値が変化しなければ
			//最初から処理を行うため意味はない。なので30という値で固定したのだ。そして、最初のランダムの関数の値が
			//変更するまでは30に固定して、ランダム変数が変化したら0になるようにしたのだ。
			//attackframe = 50;//★攻撃を食らった瞬間に残像ロックが0になり、ダメージを受けてる状態や攻撃している最中に通常画像が描画されてしまうので
			//新しい変数DAMEGEを作った。
			//attackframe2 = 50;//こいつが繰がるための変数を0にしても1にしてもこいつの数値が1から50より小さい間は蹴るが描画されるので、ここで50にする。
			//attackframe3 = 50;
			//attackframe5 = 60;
			//attackframe6 = 60;
			//attackframe7 = 60;
			//naihuframe = 700;
			//naihuframe2 = 100;
			//prenaihuframe = 0;
			//nagurugazou = 40;
			//nagurugazou2 = 40;
			//DAMEGE = 1;
			//playerkonntororulock = 1;
			//playerkonntororulock3 = 1;
			playermovelock2 = 0;//タバコ中に攻撃を食らった際に1のままでは移動できないので、ここで0にした。
			//keriwaza = 0;


		}



		if (pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX &&
			pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 150 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX &&
			pos[enemyY2][enemyX2][1] + playerattackhanndou3B + 15 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 &&
			pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 15 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5
			&& ENEMYkougekigazouB2frame > 58 && ENEMYkougekigazouB2frame < 60) {
			playerHPsubun = 31;
			tabakosuenai = 1;//タバコ回復を邪魔する。

			//StartJoypadVibration(DX_INPUT_PAD1, 700, 100);
			//ranndamukougeki = 1;
			//attackframe = 50;
			//attackframe2 = 50;//こいつが繰がるための変数を0にしても1にしてもこいつの数値が1から50より小さい間は蹴るが描画されるので、ここで50にする。
			//attackframe3 = 50;
			//attackframe5 = 60;
			//attackframe6 = 60;
			//attackframe7 = 60;
			//naihuframe = 700;
			//naihuframe2 = 100;
			//prenaihuframe = 0;
			//nagurugazou = 40;
			//nagurugazou2 = 40;
			//DAMEGE = 1;
			//playerkonntororulock = 1;
			//playerkonntororulock3 = 1;
			playermovelock2 = 0;//タバコ中に攻撃を食らった際に1のままでは移動できないので、ここで0にした。
			//keriwaza = 0;
			//ENEMYkougekigazouA1frame = 0;★★こいつは処理の過程で0になり、++のような繰り上がりはないので0と過程で書いたので
			//そのまま0になったのでここに再度書かなくてもよい。
			//tekinoKOUGEKITYUUhahyouzisinailock = 0;
			//ENEMYkougekigazouA2frame = 0;//★★描画が連続で出てくるような状況についての解決法
			//ここにENEMYkougekigazouA2frame = 0を書くとENEMYkougekigazouA1lock == 1 &&ENEMYkougekigazouA1frame == 0に
			//通らないようにとここにENEMYkougekigazouA1lock = 0;とENEMYkougekigazouA1frame = 1;書いてもランダム変数の数値が変化しなければ
			//最初から処理を行うため意味はない。なので30という値で固定したのだ。そして、最初のランダムの関数の値が
			//変更するまでは30に固定して、ランダム変数が変化したら0になるようにしたのだ。


		}

		//攻撃を食らった場合。//怯みが解除された後と同じようなするために141とした。
		if (ENEMYkougekigazouA2frame > 70) {//100からここに来ればすぐにランダムが変えられるので、敵が抵抗してこないのだと思う。
			ENEMYkougekigazouA2frame = 70;
			enemyzannzoulock2 = 0;//
			ranndamulock = 0;//自分と敵の重なるプログラムを有効にするために0にする。
			ranndamulockframe = 0;
			ranndamukougeki = 0;
			enemygazoukesu = 0;
			enemyattackinglock = 0;//敵が攻撃するときだけは攻撃する画像のみが描画されるようにするための変数。
			ENEMYkougekigazouA1 = 0;
			kougekiframe = 0;
			//ranndamukougeki = 10;
			//LEFTmark = 909;
			kaunntacount = 0;
			enemystayhere = 0;//たまに何かしらの原因で1になってしまいコンティニュー後に敵が描画されないので、
			//コンティニューする場合の関数内にもenemystayhere = 0;と書いたがうまく機能しないことがあるので攻撃後には0にしておく。
			overattacklock = 0;
			stayherelock = 0;
			//stayhere = 0;//★怯ませる処理での途中で0にしていたため、カウンターを食らってもすぐに敵が攻撃してきて、その際にif (overattacklock == 0) によって
			//ダメージを負った際でも攻撃してくる敵の画像が描画され、怯んでる状態で攻撃画像が同時に描画されてしまうようになっていた。
			//if (overattacklock == 0) はカウンターを食らって時ではなく、普通に攻撃した時に敵が攻撃してきた際に、攻撃してきたことがわかるように敵の攻撃画像を描画するためのプログラムである。
			ENEMYkougekigazouA1lock = 0;
			tabakosuenai = 0;//タバコ回復を邪魔する。
			tabakocount = 0;
			tabakocount2 = 0;
			playerHPlock = 0;//念のため
			playerkonntororulock = 0;
			preenemyX = 0;
			preenemyY = 0;

			//青い敵が攻撃する時は赤い敵の攻撃を止めておくを解除。
			stayhere2 = 0;

			zannzoulock = 0;
		}
		//もう一人の敵から攻撃を食らった場合。//怯みが解除された後と同じようなするために141とした。
		if (ENEMYkougekigazouB2frame > 60) {
			ENEMYkougekigazouB2frame = 60;
			anotherenemyzannzoulock = 0;
			//enemyzannzoulock3 = 0;//
			ranndamulock2 = 0;//自分と敵の重なるプログラムを有効にするために0にする。
			ranndamulockframe = 0;
			ranndamukougeki2 = 0;
			enemygazoukesu = 0;
			enemyattackinglock = 0;//敵が攻撃するときだけは攻撃する画像のみが描画されるようにするための変数。

			ENEMYkougekigazouB1 = 0;
			kougekiframe = 0;
			//ranndamukougeki = 10;
			//LEFTmark = 909;
			kaunntacount = 0;
			enemystayhere = 0;//たまに何かしらの原因で1になってしまいコンティニュー後に敵が描画されないので、
			//コンティニューする場合の関数内にもenemystayhere = 0;と書いたがうまく機能しないことがあるので攻撃後には0にしておく。
			overattacklock = 0;
			stayherelock = 0;
			//stayhere = 0;//★怯ませる処理での途中で0にしていたため、カウンターを食らってもすぐに敵が攻撃してきて、その際にif (overattacklock == 0) によって
			//ダメージを負った際でも攻撃してくる敵の画像が描画され、怯んでる状態で攻撃画像が同時に描画されてしまうようになっていた。
			//if (overattacklock == 0) はカウンターを食らって時ではなく、普通に攻撃した時に敵が攻撃してきた際に、攻撃してきたことがわかるように敵の攻撃画像を描画するためのプログラムである。
			ENEMYkougekigazouB1lock = 0;
			tabakosuenai = 0;//タバコ回復を邪魔する。
			tabakocount = 0;
			tabakocount2 = 0;
			playerHPlock = 0;//念のため
			playerkonntororulock = 0;
			preenemyX2 = 0;
			preenemyY2 = 0;

			//赤い敵が攻撃する時は青い敵の攻撃を止めておく。を解除
			stayhere = 0;

			zannzoulock = 0;
		}

	}








	if (Rbotun > 0 && ++Rbotun < 100 && ranndamukougeki == 2
		or
		Rbotun > 0 && ++Rbotun < 100 && ranndamukougeki == 3) {
		//★なんで右のキーを押しても主人公が動かないかと言うとタバコを吸うボタンAによりplayermovelock2が1になるためである。
		//要は十字キーはplayermovelock2が0の時にしか動かないように組んだためである。
		if (Pad[PAD_RIGHT] == 1) {
			ENEMYkougekigazouA1frame = 60;
			ENEMYkougekigazouA2frame = 60;
			ranndamukougeki = 1;
			DAMEGE = 1;
			playerHPsubun = 0;
			//enemyzannzoulock3 = 1;
			enemyhirumaseframe = 1;
			Rbotun = 0;
			stayhere = 1;

		}
	}
	if (Rbotun > 100) {
		Rbotun = 0;
	}

	else if (pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX &&
		pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 150 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX &&
		pos[enemyY1][enemyX1][1] + playerattackhanndou3 + 15 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 &&
		pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 15 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5
		&& ENEMYkougekigazouA2frame > 0 && ENEMYkougekigazouA2frame < 60 && ranndamukougeki == 2
		or
		pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX &&
		pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 150 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX &&
		pos[enemyY1][enemyX1][1] + playerattackhanndou3 + 15 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 &&
		pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 15 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5
		&& ENEMYkougekigazouA2frame > 0 && ENEMYkougekigazouA2frame < 60 && ranndamukougeki == 4
		) {

		StartJoypadVibration(DX_INPUT_PAD1, 100, 5 * ENEMYkougekigazouA2frame, 0);//左のモーターが振動。

	//enemyattackaizu;
	//	DrawBox(100 + pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX,
	//		-100 + pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5,
	//		200 + pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX,
	//		-50 + pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, color, TRUE);//四角を描画

	//このAボタン押した後に素早くアナログパッドの方向キーが成功すれば、if文に行く。
		if (Pad[PAD_1] == 1) {
			++Rbotun;
		}

	}
	if (Rbotun > 0 && ++Rbotun < 100 && ranndamukougeki == 4
		or
		Rbotun > 0 && ++Rbotun < 100 && ranndamukougeki == 1) {

		if (Pad[PAD_LEFT] == 1) {
			ENEMYkougekigazouA1frame = 60;
			ENEMYkougekigazouA2frame = 70;
			ranndamukougeki = 1;
			DAMEGE = 1;
			playerHPsubun = 0;
			//enemyzannzoulock3 = 1;
			enemyhirumaseframe = 1;
			Rbotun = 0;
			stayhere = 1;

		}
	}
	if (Rbotun > 100) {
		Rbotun = 0;
	}
	//フレームが動いているので、攻撃後にランダムで数を変えて、繰り返しを防いだうえで、最初の一回目の10から12のフレームの一フレーム
//が攻撃を食らうようにした。
	if (hirumaselock == 0) {
		if (pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX &&
			pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 150 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX &&
			pos[enemyY1][enemyX1][1] + playerattackhanndou3 + 15 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 &&
			pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 15 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5
			&& ENEMYkougekigazouA2frame > 68 && ENEMYkougekigazouA2frame < 70) {
			playerHPsubun = 51;

			//ranndamukougeki = 1;
			tabakosuenai = 1;//タバコ回復を邪魔する。
			//StartJoypadVibration(DX_INPUT_PAD1, 700, 100);
			//ENEMYkougekigazouA1frame = 0;★★こいつは処理の過程で0になり、++のような繰り上がりはないので0と過程で書いたので
			//そのまま0になったのでここに再度書かなくてもよい。
			//tekinoKOUGEKITYUUhahyouzisinailock = 0;
			//ENEMYkougekigazouA2frame = 0;//★★描画が連続で出てくるような状況についての解決法
			//ここにENEMYkougekigazouA2frame = 0を書くとENEMYkougekigazouA1lock == 1 &&ENEMYkougekigazouA1frame == 0に
			//通らないようにとここにENEMYkougekigazouA1lock = 0;とENEMYkougekigazouA1frame = 1;書いてもランダム変数の数値が変化しなければ
			//最初から処理を行うため意味はない。なので30という値で固定したのだ。そして、最初のランダムの関数の値が
			//変更するまでは30に固定して、ランダム変数が変化したら0になるようにしたのだ。
			//attackframe = 50;//★攻撃を食らった瞬間に残像ロックが0になり、ダメージを受けてる状態や攻撃している最中に通常画像が描画されてしまうので
			//新しい変数DAMEGEを作った。
			//attackframe2 = 50;//こいつが繰がるための変数を0にしても1にしてもこいつの数値が1から50より小さい間は蹴るが描画されるので、ここで50にする。
			//attackframe3 = 50;
			//attackframe5 = 60;
			//attackframe6 = 60;
			//attackframe7 = 60;
			//naihuframe = 700;
			//naihuframe2 = 100;
			//prenaihuframe = 0;
			//nagurugazou = 40;
			//nagurugazou2 = 40;
			//DAMEGE = 1;
			//playerkonntororulock = 1;
			//playerkonntororulock3 = 1;
			playermovelock2 = 0;//タバコ中に攻撃を食らった際に1のままでは移動できないので、ここで0にした。
			//keriwaza = 0;


		}



		//攻撃を食らった場合。//怯みが解除された後と同じようなするために141とした。
		if (ENEMYkougekigazouA2frame > 70) {//100からここに来ればすぐにランダムが変えられるので、敵が抵抗してこないのだと思う。
			ENEMYkougekigazouA2frame = 70;//★if (ENEMYkougekigazouA2frame > 60)を100とかにすると100になるまでの間にランダムは0にならず一定の
			//ままなので再びENEMYkougekigazouA1frameが上がってしまいダメージを与える前に上がったENEMYkougekigazouA1frameが効果がでずダメージも受けないのかもしれない。
			enemyzannzoulock2 = 0;//
			ranndamulock = 0;//自分と敵の重なるプログラムを有効にするために0にする。
			ranndamulockframe = 0;
			ranndamukougeki = 0;
			enemygazoukesu = 0;
			enemyattackinglock = 0;//敵が攻撃するときだけは攻撃する画像のみが描画されるようにするための変数。
			ENEMYkougekigazouA1 = 0;
			kougekiframe = 0;
			//ranndamukougeki = 10;
			//LEFTmark = 909;
			kaunntacount = 0;
			enemystayhere = 0;//たまに何かしらの原因で1になってしまいコンティニュー後に敵が描画されないので、
			//コンティニューする場合の関数内にもenemystayhere = 0;と書いたがうまく機能しないことがあるので攻撃後には0にしておく。
			overattacklock = 0;
			//stayherelock3 = 0;
			//stayhere = 0;//★怯ませる処理での途中で0にしていたため、カウンターを食らってもすぐに敵が攻撃してきて、その際にif (overattacklock == 0) によって
			//ダメージを負った際でも攻撃してくる敵の画像が描画され、怯んでる状態で攻撃画像が同時に描画されてしまうようになっていた。
			//if (overattacklock == 0) はカウンターを食らって時ではなく、普通に攻撃した時に敵が攻撃してきた際に、攻撃してきたことがわかるように敵の攻撃画像を描画するためのプログラムである。
			ENEMYkougekigazouA1lock = 0;
			tabakosuenai = 0;//タバコ回復を邪魔する。
			tabakocount = 0;
			tabakocount2 = 0;
			playerHPlock = 0;//念のため
			playerkonntororulock = 0;
			preenemyX = 0;
			preenemyY = 0;

			//青い敵が攻撃する時は赤い敵の攻撃を止めておくを解除。
			stayhere2 = 0;
		}

	}



	//一パターン。主＜敵2＜敵1
	if (pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 < pos[enemyY2][enemyX2][1] + playerattackhanndou3B &&
		pos[enemyY2][enemyX2][1] + playerattackhanndou3B < pos[enemyY1][enemyX1][1] + playerattackhanndou3 + 25

		&& pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 <
		pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B
		&&
		pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 <
		pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3
		&&
		pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B <
		pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3
		) {
		//LEFTmark = 9933;
		if (zannzoulock == 0 && migimuki == 1) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage, TRUE); }
		if (zannzoulock == 0 && hidarimuki == 1) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage2, TRUE); }
		if (playerHPlock == 0 && playerHP <= 200) {
			//playerMove2 = 0;
			hinnsiattack = 1;
			zannzoulock = 1;


		}
		//もう一人の敵を描画
		if (stayherelock2 == 0) {
			if (anotherenemyzannzoulock == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
				//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
				//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。

				//LEFTmark = 65432;
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, enemyImage3, TRUE);

			}
		}
		//敵2の攻撃を描画
		if (ENEMYkougekigazouB1frame > 0 && ++ENEMYkougekigazouB1frame < 70) {

			if (anotherenemyzannzoulock == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiA1Handle[0], TRUE);
			}

		}
		if (ENEMYkougekigazouB2frame > 0 && ENEMYkougekigazouB2frame < 60) {

			if (anotherenemyzannzoulock == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiB1Handle[0], TRUE);
			}
		}
		//敵を描画
		if (enemyzannzoulock2 == 0 && enemyhirumaseframe == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
			//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
			//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。
			if (enemystayhere == 0) {
				//LEFTmark = 1234;
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, enemyImage2, TRUE);
			}
			//LEFTmark = 4388;
		}



		//敵1の攻撃を描画
		if (ENEMYkougekigazouA1frame > 0 && ENEMYkougekigazouA1frame < 60) {

			if (enemyzannzoulock2 == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiB1Handle[0], TRUE);

			}

		}
		if (ENEMYkougekigazouA2frame > 0 && ENEMYkougekigazouA2frame < 70) {

			if (enemyzannzoulock2 == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiA1Handle[0], TRUE);

			}

		}
	}

	//一パターンA。主＜敵2＜敵1
	if (pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 < pos[enemyY2][enemyX2][1] + playerattackhanndou3B &&
		pos[enemyY2][enemyX2][1] + playerattackhanndou3B < pos[enemyY1][enemyX1][1] + playerattackhanndou3
		//A
		&& pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 <
		pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3
		&&
		pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 <
		pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B
		&&
		pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 <
		pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B
		) {
		//LEFTmark = 3344;
		if (zannzoulock == 0 && migimuki == 1) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage, TRUE); }
		if (zannzoulock == 0 && hidarimuki == 1) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage2, TRUE); }

		
		//もう一人の敵を描画
		if (stayherelock2 == 0) {
			if (anotherenemyzannzoulock == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
				//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
				//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。

				//LEFTmark = 65432;
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, enemyImage3, TRUE);

			}
		}

		//敵2の攻撃を描画
		if (ENEMYkougekigazouB1frame > 0 && ENEMYkougekigazouB1frame < 70) {

			if (anotherenemyzannzoulock == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiA1Handle[0], TRUE);
			}

		}
		if (ENEMYkougekigazouB2frame > 0 && ENEMYkougekigazouB2frame < 60) {

			if (anotherenemyzannzoulock == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiB1Handle[0], TRUE);
			}
		}
		//敵を描画
		if (enemyzannzoulock2 == 0 && enemyhirumaseframe == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
			//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
			//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。
			if (enemystayhere == 0) {
				//LEFTmark = 1234;
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, enemyImage2, TRUE);
			}
			//LEFTmark = 4388;
		}

		//敵1の攻撃を描画
		if (ENEMYkougekigazouA1frame > 0 && ENEMYkougekigazouA1frame < 60) {

			if (enemyzannzoulock2 == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiB1Handle[0], TRUE);

			}

		}
		if (ENEMYkougekigazouA2frame > 0 && ENEMYkougekigazouA2frame < 70) {

			if (enemyzannzoulock2 == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiA1Handle[0], TRUE);

			}

		}
	}

	//パターン2、主＜敵1＜敵2//ここと下のパターンAを修正した。
	if (pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 < pos[enemyY1][enemyX1][1] + playerattackhanndou3 &&
		pos[enemyY1][enemyX1][1] + playerattackhanndou3 < pos[enemyY2][enemyX2][1] + playerattackhanndou3B

		&& pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 <
		pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 <
		pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B
		) {
		//LEFTmark = 111;
		if (zannzoulock == 0 && migimuki == 1) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage, TRUE); }
		if (zannzoulock == 0 && hidarimuki == 1) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage2, TRUE); }

		

		//敵を描画
		if (enemyzannzoulock2 == 0 && enemyhirumaseframe == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
			//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
			//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。
			if (enemystayhere == 0) {
				//LEFTmark = 1234;
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, enemyImage2, TRUE);
			}
			//LEFTmark = 8877;
		}

		//敵1の攻撃を描画
		if (ENEMYkougekigazouA1frame > 0 && ENEMYkougekigazouA1frame < 60) {

			if (enemyzannzoulock2 == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiB1Handle[0], TRUE);

			}

		}
		if (ENEMYkougekigazouA2frame > 0 && ENEMYkougekigazouA2frame < 70) {

			if (enemyzannzoulock2 == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiA1Handle[0], TRUE);

			}

		}
		//もう一人の敵を描画
		if (stayherelock2 == 0) {
			if (anotherenemyzannzoulock == 1) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
				//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
				//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。

				//LEFTmark = 65432;
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, enemyImage3, TRUE);

			}
		}


		//敵2の攻撃を描画
		if (ENEMYkougekigazouB1frame > 0 && ENEMYkougekigazouB1frame < 70) {

			if (anotherenemyzannzoulock == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiA1Handle[0], TRUE);
			}

		}
		if (ENEMYkougekigazouB2frame > 0 && ENEMYkougekigazouB2frame < 60) {

			if (anotherenemyzannzoulock == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiB1Handle[0], TRUE);
			}
		}
	}

	//パターン2A、主＜敵1＜敵2
	if (pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 < pos[enemyY1][enemyX1][1] + playerattackhanndou3 &&
		pos[enemyY1][enemyX1][1] + playerattackhanndou3 < pos[enemyY2][enemyX2][1] + playerattackhanndou3B
		//A
		&& pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 <
		pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B <
		pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3

		) {
		//LEFTmark = 333;
		if (zannzoulock == 0 && migimuki == 1) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage, TRUE); }
		if (zannzoulock == 0 && hidarimuki == 1) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage2, TRUE); }

		
		//敵を描画
		if (enemyzannzoulock2 == 0 && enemyhirumaseframe == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
			//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
			//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。
			if (enemystayhere == 0) {
				//LEFTmark = 1234;
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, enemyImage2, TRUE);
			}
			//LEFTmark = 5555;
		}

		//敵1の攻撃を描画
		if (ENEMYkougekigazouA1frame > 0 && ENEMYkougekigazouA1frame < 60) {

			if (enemyzannzoulock2 == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiB1Handle[0], TRUE);

			}

		}
		if (ENEMYkougekigazouA2frame > 0 && ENEMYkougekigazouA2frame < 70) {

			if (enemyzannzoulock2 == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiA1Handle[0], TRUE);

			}

		}

		//もう一人の敵を描画
		if (stayherelock2 == 0) {
			if (anotherenemyzannzoulock == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
				//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
				//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。

				//LEFTmark = 65432;
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, enemyImage3, TRUE);

			}
		}
		//敵2の攻撃を描画
		if (ENEMYkougekigazouB1frame > 0 && ENEMYkougekigazouB1frame < 70) {

			if (anotherenemyzannzoulock == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiA1Handle[0], TRUE);
			}

		}
		if (ENEMYkougekigazouB2frame > 0 && ENEMYkougekigazouB2frame < 60) {

			if (anotherenemyzannzoulock == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiB1Handle[0], TRUE);
			}
		}
	}


	//パターン3　敵2＜主＜敵1
	if (pos[enemyY2][enemyX2][1] + playerattackhanndou3B < pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5
		&& pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 < pos[enemyY1][enemyX1][1] + playerattackhanndou3

		&&
		pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B <
		pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 <
		pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3
		) {
		//もう一人の敵を描画
		if (stayherelock2 == 0) {
			if (anotherenemyzannzoulock == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
				//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
				//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。

				//LEFTmark = 65432;
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, enemyImage3, TRUE);

			}
		}
		//敵2の攻撃を描画
		if (ENEMYkougekigazouB1frame > 0 && ++ENEMYkougekigazouB1frame < 70) {

			if (anotherenemyzannzoulock == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiA1Handle[0], TRUE);
			}

		}
		if (ENEMYkougekigazouB2frame > 0 && ENEMYkougekigazouB2frame < 60) {

			if (anotherenemyzannzoulock == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiB1Handle[0], TRUE);
			}
		}
		//LEFTmark = 9989898;
		if (zannzoulock == 0 && migimuki == 1) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage, TRUE); }
		if (zannzoulock == 0 && hidarimuki == 1) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage2, TRUE); }

		
		syuzinkoukougekigazou();
		if (enemyzannzoulock2 == 0 && enemyhirumaseframe == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
			//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
			//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。
			if (enemystayhere == 0) {
				//LEFTmark = 1234;
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, enemyImage2, TRUE);

				//DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY2][enemyX2][1] + playerattackhanndou3, bairituY2, 0, enemyImage, TRUE);
			}
		}

		//敵1の攻撃を描画
		if (ENEMYkougekigazouA1frame > 0 && ENEMYkougekigazouA1frame < 60) {

			if (enemyzannzoulock2 == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiB1Handle[0], TRUE);

			}

		}
		if (ENEMYkougekigazouA2frame > 0 && ENEMYkougekigazouA2frame < 70) {

			if (enemyzannzoulock2 == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiA1Handle[0], TRUE);

			}

		}

	}

	//パターン3A　敵2＜主＜敵1
	if (pos[enemyY2][enemyX2][1] + playerattackhanndou3B < pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5
		&& pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 < pos[enemyY1][enemyX1][1] + playerattackhanndou3

		&&//A
		pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B <
		pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 <
		pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5
		) {
		//もう一人の敵を描画
		if (stayherelock2 == 0) {
			if (anotherenemyzannzoulock == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
				//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
				//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。

				//LEFTmark = 65432;
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, enemyImage3, TRUE);

			}
		}
		//敵2の攻撃を描画
		if (ENEMYkougekigazouB1frame > 0 && ++ENEMYkougekigazouB1frame < 70) {

			if (anotherenemyzannzoulock == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiA1Handle[0], TRUE);
			}

		}
		if (ENEMYkougekigazouB2frame > 0 && ENEMYkougekigazouB2frame < 60) {

			if (anotherenemyzannzoulock == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiB1Handle[0], TRUE);
			}
		}
		//LEFTmark = 99111198;
		if (zannzoulock == 0 && migimuki == 1) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage, TRUE); }
		if (zannzoulock == 0 && hidarimuki == 1) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage2, TRUE); }

		
		syuzinkoukougekigazou();
		if (enemyzannzoulock2 == 0 && enemyhirumaseframe == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
			//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
			//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。
			if (enemystayhere == 0) {
				//LEFTmark = 1234;
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, enemyImage2, TRUE);

				//DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY2][enemyX2][1] + playerattackhanndou3, bairituY2, 0, enemyImage, TRUE);
			}
		}

		//敵1の攻撃を描画
		if (ENEMYkougekigazouA1frame > 0 && ENEMYkougekigazouA1frame < 60) {

			if (enemyzannzoulock2 == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiB1Handle[0], TRUE);

			}

		}
		if (ENEMYkougekigazouA2frame > 0 && ENEMYkougekigazouA2frame < 70) {

			if (enemyzannzoulock2 == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiA1Handle[0], TRUE);

			}

		}
	}


	//パターン4
	if (pos[enemyY2][enemyX2][1] + playerattackhanndou3B <= pos[enemyY1][enemyX1][1] + playerattackhanndou3 &&
		pos[enemyY1][enemyX1][1] + playerattackhanndou3 <= pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5

		&&
		pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B <
		pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 <
		pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5
		) {

		//もう一人の敵を描画
		if (stayherelock2 == 0) {
			if (anotherenemyzannzoulock == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
				//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
				//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。

				//LEFTmark = 65432;
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, enemyImage3, TRUE);

			}
		}

		//敵2の攻撃を描画
		if (ENEMYkougekigazouB1frame > 0 && ENEMYkougekigazouB1frame < 70) {

			if (anotherenemyzannzoulock == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiA1Handle[0], TRUE);
			}

		}
		if (ENEMYkougekigazouB2frame > 0 && ENEMYkougekigazouB2frame < 60) {

			if (anotherenemyzannzoulock == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiB1Handle[0], TRUE);
			}
		}
		//敵を描画
		if (enemyzannzoulock2 == 0 && enemyhirumaseframe == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
		//	//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
			//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。
			if (enemystayhere == 0) {
				//LEFTmark = 1234;
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, enemyImage2, TRUE);
			}
			//LEFTmark = 711117;
		}
		//敵1の攻撃を描画
		if (ENEMYkougekigazouA1frame > 0 && ENEMYkougekigazouA1frame < 60) {

			if (enemyzannzoulock2 == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiB1Handle[0], TRUE);

			}

		}
		if (ENEMYkougekigazouA2frame > 0 && ENEMYkougekigazouA2frame < 70) {

			if (enemyzannzoulock2 == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiA1Handle[0], TRUE);

			}

		}

		if (zannzoulock == 0 && migimuki == 1) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage, TRUE); }
		if (zannzoulock == 0 && hidarimuki == 1) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage2, TRUE); }

		
		syuzinkoukougekigazou();

	}
	//パターン5、敵1＜主＜敵2
	if (pos[enemyY1][enemyX1][1] + playerattackhanndou3 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
		&& pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 <= pos[enemyY2][enemyX2][1] + playerattackhanndou3B

		&&
		pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 <
		pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 <
		pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B
		) {

		//敵を描画
		if (enemyzannzoulock2 == 0 && enemyhirumaseframe == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
		//	//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
			//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。
			if (enemystayhere == 0) {
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, enemyImage2, TRUE);
			}
			//LEFTmark = 11011;
		}
		//敵1の攻撃を描画
		if (ENEMYkougekigazouA1frame > 0 && ENEMYkougekigazouA1frame < 60) {

			if (enemyzannzoulock2 == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiB1Handle[0], TRUE);

			}

		}
		if (ENEMYkougekigazouA2frame > 0 && ENEMYkougekigazouA2frame < 70) {

			if (enemyzannzoulock2 == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiA1Handle[0], TRUE);

			}

		}

		if (zannzoulock == 0 && migimuki == 1) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage, TRUE); }
		if (zannzoulock == 0 && hidarimuki == 1) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage2, TRUE); }

		
		syuzinkoukougekigazou();
		//もう一人の敵を描画
		if (stayherelock2 == 0) {
			if (anotherenemyzannzoulock == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
				//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
				//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。

				//LEFTmark = 65432;
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, enemyImage3, TRUE);

			}
		}
		//敵2の攻撃を描画
		if (ENEMYkougekigazouB1frame > 0 && ENEMYkougekigazouB1frame < 70) {

			if (anotherenemyzannzoulock == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiA1Handle[0], TRUE);
			}

		}
		if (ENEMYkougekigazouB2frame > 0 && ENEMYkougekigazouB2frame < 60) {

			if (anotherenemyzannzoulock == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiB1Handle[0], TRUE);
			}
		}

	}



	//パターン6、敵1＜敵2＜主
	if (pos[enemyY1][enemyX1][1] + playerattackhanndou3 < pos[enemyY2][enemyX2][1] + playerattackhanndou3B
		&& pos[enemyY2][enemyX2][1] + playerattackhanndou3B < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5

		&&
		pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 <
		pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B <
		pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5
		) {

		//敵を描画
		if (enemyzannzoulock2 == 0 && enemyhirumaseframe == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
		//	//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
			//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。
			if (enemystayhere == 0) {
				//LEFTmark = 1234;
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, enemyImage2, TRUE);
			}
			//LEFTmark = 99999;
		}

		//敵1の攻撃を描画
		if (ENEMYkougekigazouA1frame > 0 && ENEMYkougekigazouA1frame < 60) {

			if (enemyzannzoulock2 == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiB1Handle[0], TRUE);

			}

		}
		if (ENEMYkougekigazouA2frame > 0 && ENEMYkougekigazouA2frame < 70) {

			if (enemyzannzoulock2 == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiA1Handle[0], TRUE);

			}

		}

		//もう一人の敵を描画
		if (stayherelock2 == 0) {
			if (anotherenemyzannzoulock == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
				//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
				//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。

				//LEFTmark = 65432;
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, enemyImage3, TRUE);

			}
		}

		//敵2の攻撃を描画
		if (ENEMYkougekigazouB1frame > 0 && ENEMYkougekigazouB1frame < 70) {

			if (anotherenemyzannzoulock == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiA1Handle[0], TRUE);
			}

		}
		if (ENEMYkougekigazouB2frame > 0 && ENEMYkougekigazouB2frame < 60) {

			if (anotherenemyzannzoulock == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiB1Handle[0], TRUE);
			}
		}

		if (zannzoulock == 0 && migimuki == 1) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage, TRUE); }
		if (zannzoulock == 0 && hidarimuki == 1) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage2, TRUE); }

		
		syuzinkoukougekigazou();

	}


	//パターン6A、敵1＜敵2＜主
	if (pos[enemyY1][enemyX1][1] + playerattackhanndou3 < pos[enemyY2][enemyX2][1] + playerattackhanndou3B
		&& pos[enemyY2][enemyX2][1] + playerattackhanndou3B < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5

		&&
		pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 <
		pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 <
		pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B
		) {

		//敵を描画
		if (enemyzannzoulock2 == 0 && enemyhirumaseframe == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
		//	//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
			//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。
			if (enemystayhere == 0) {
				//LEFTmark = 1234;
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, enemyImage2, TRUE);
			}
			//LEFTmark = 99999;
		}



		//もう一人の敵を描画
		if (stayherelock2 == 0) {
			if (anotherenemyzannzoulock == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
				//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
				//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。

				//LEFTmark = 65432;
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, enemyImage3, TRUE);

			}
		}



		if (zannzoulock == 0 && migimuki == 1) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage, TRUE); }
		if (zannzoulock == 0 && hidarimuki == 1) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage2, TRUE); }

		
		//敵1の攻撃を描画
		if (ENEMYkougekigazouA1frame > 0 && ENEMYkougekigazouA1frame < 60) {

			if (enemyzannzoulock2 == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiB1Handle[0], TRUE);

			}

		}
		if (ENEMYkougekigazouA2frame > 0 && ENEMYkougekigazouA2frame < 70) {

			if (enemyzannzoulock2 == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiA1Handle[0], TRUE);

			}

		}


		//敵2の攻撃を描画
		if (ENEMYkougekigazouB1frame > 0 && ENEMYkougekigazouB1frame < 70) {

			if (anotherenemyzannzoulock == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiA1Handle[0], TRUE);
			}

		}
		if (ENEMYkougekigazouB2frame > 0 && ENEMYkougekigazouB2frame < 60) {

			if (anotherenemyzannzoulock == 1) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiB1Handle[0], TRUE);
			}
		}
		syuzinkoukougekigazou();

	}


	//右回転して攻撃を避ける。
	if (input.RightTrigger == 255 && motonomasunimodoru > 0) {
		if (contorora == (PAD_INPUT_RIGHT) && kaitenncount == 0) {
			//zannzoulock = 1;
			kaitenn = 1;
			migimuki = 0;
			hidarimuki = 1;
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
	if (kaitenncountframe2 > 100) {//連続して押せないように100まってから押せるようにした。
		kaitenncountframe2 = 0;
		kaitenncount2 = 0;
	}
	//	if (enemyattackagein > 0) {
	//		++enemyattackageinframe;
	//		
	//	}
	//	if (enemyattackageinframe > 200) {
	//		stayhere = 0;//★怯ませる処理での途中で0にしていたため、カウンターを食らってもすぐに敵が攻撃してきて、その際にif (overattacklock == 0) によって
			//ダメージを負った際でも攻撃してくる敵の画像が描画され、怯んでる状態で攻撃画像が同時に描画されてしまうようになっていた。
			//if (overattacklock == 0) はカウンターを食らって時ではなく、普通に攻撃した時に敵が攻撃してきた際に、攻撃してきたことがわかるように敵の攻撃画像を描画するためのプログラムである。
	//		enemyattackagein = 0;
	//		enemyattackageinframe = 0;
	//	}
		//攻撃を食らうと敵の攻撃が止み、攻撃を受けている最中は敵の色が反転するようにした。
	//敵1の「通常状態」と「攻撃中」に対する攻撃を食らったときの半透明になる部分。
	//if (kougekiKANOU == 1 or kougekiKANOU == 2 or kougekiKANOU == 10) {//攻撃中は攻撃の方の画像が描画されるようにする。

	//}

	//敵1の「通常状態」と「攻撃中」に対する攻撃を食らったときの半透明になる部分。
	//if (kougekiKANOU == 1 or kougekiKANOU == 2 or kougekiKANOU == 10) {//攻撃中は攻撃の方の画像が描画されるようにする。


	//if (point == 1) {

	//}



	//if (count < 50) {
		//DrawFormatString(50, 300, GetColor(0, 255, 255), "%d", count);//ここでcountの情報だけを条件(count < 500)より呼び出して、countの色を変えた
	//}


	//敵二人のHP表示
	/*if (enemy1HPhyouji == 1) {
		DrawFormatString(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 100, GetColor(255, 0, 0), "enemy1HP%d", enemy1HP);
	}*/


	//コンボ表示と一定のコンボ以上は音声が流れる。
	if (conbocount > 0) {
		DrawFormatString(500, 100, GetColor(255, 100, 200), "conbocountは%d", conbocount);//1回殴った時にすべて消費して、再び溜まるまでの過程を表示するための関数
		++conbocounttime;
	}
	if (conbocount > 10) {
		++conbocountframe;
	}
	if (conbocountframe > 0 && conbocountframe < 2) {
		conbosound = LoadSoundMem("people-studio-laugh-large3.mp3");
		PlaySoundMem(conbosound, DX_PLAYTYPE_BACK);

	}
	if (conbocountframe > 2) {
		conbocountframe = 0;
		conbocount = 0;
	}

	if (conbocounttime > 300) {
		conbocounttime = 0;
		conbocount = 0;
	}



	//主人公の倍率の部分//ステージを作る際の計算により(詳しくは画用紙に書いたが)、
//+ 65の部分によりstage[0][6][1]より大きくて、stage[1][6][1]より小さい
//pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3が交わり、その範囲がbairituX = 4.6となる条件となる。
	if (stage[0][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
		stage[0][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
		stage[1][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
		stage[1][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
		stage[0][0][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
		stage[1][0][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
		stage[0][6][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
		stage[1][6][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65
		//or stage[0][6][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + 65
		) {
		bairituX = 4;
	}
	if (stage[1][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
		stage[1][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
		stage[2][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
		stage[2][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
		stage[1][0][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
		stage[2][0][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
		stage[1][6][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
		stage[2][6][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65
		) {
		bairituX = 4.5;

	}
	if (stage[2][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
		stage[2][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
		stage[3][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
		stage[3][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
		stage[2][0][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&//①
		//stage[3][0][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + 65 &&//②
		stage[2][6][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65
		//stage[3][6][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + 65//ここを消しても一部分が変化しない奴は出来る。
		) {
		bairituX = 5;
	}

	//敵の倍率の部分
	if (stage[0][0][0] < pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 25 &&
		stage[0][6][0]>  pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 25 &&
		stage[1][0][0] <  pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 25 &&
		stage[1][6][0]>  pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 25 &&
		stage[0][0][1] < pos[enemyY1][enemyX1][1] + playerattackhanndou3 + 65 &&
		stage[1][0][1] > pos[enemyY1][enemyX1][1] + playerattackhanndou3 + 65 &&
		stage[0][6][1] < pos[enemyY1][enemyX1][1] + playerattackhanndou3 + 65 &&
		stage[1][6][1] > pos[enemyY1][enemyX1][1] + playerattackhanndou3 + 65
		or stage[0][6][1] > pos[enemyY1][enemyX1][1] + playerattackhanndou3 + 65
		) {
		bairituY = 4.6;

	}
	if (stage[1][0][0] <  pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 25 &&
		stage[1][6][0]>  pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 25 &&
		stage[2][0][0] <  pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 25 &&
		stage[2][6][0]>  pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 25 &&
		stage[1][0][1] < pos[enemyY1][enemyX1][1] + playerattackhanndou3 + 65 &&
		stage[2][0][1] > pos[enemyY1][enemyX1][1] + playerattackhanndou3 + 65 &&
		stage[1][6][1] < pos[enemyY1][enemyX1][1] + playerattackhanndou3 + 65 &&
		stage[2][6][1] > pos[enemyY1][enemyX1][1] + playerattackhanndou3 + 65
		) {
		bairituY = 5;

	}
	if (stage[2][0][0] <  pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 25 &&
		stage[2][6][0]>  pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 25 &&
		stage[3][0][0] <  pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 25 &&
		stage[3][6][0]>  pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 + 25 &&
		stage[2][0][1] < pos[enemyY1][enemyX1][1] + playerattackhanndou3 + 65 &&//①
		stage[3][0][1] > pos[enemyY1][enemyX1][1] + playerattackhanndou3 + 65 &&//②
		stage[2][6][1] < pos[enemyY1][enemyX1][1] + playerattackhanndou3 + 65 &&
		stage[3][6][1] > pos[enemyY1][enemyX1][1] + playerattackhanndou3 + 65//ここを消しても一部分が変化しない奴は出来る。
		or stage[3][6][1] < pos[enemyY1][enemyX1][1] + playerattackhanndou3 + 65
		) {
		bairituY = 5.4;
	}

	//もう一人の敵の倍率の部分//もう一人の敵の移動でもう一人の倍率が変化しないように新しい変数のbairituY2を作った。
	if (stage[0][0][0] < pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B + 25 &&
		stage[0][6][0]>  pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B + 25 &&
		stage[1][0][0] <  pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B + 25 &&
		stage[1][6][0]>  pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B + 25 &&
		stage[0][0][1] < pos[enemyY2][enemyX2][1] + playerattackhanndou3B + 65 &&
		stage[1][0][1] > pos[enemyY2][enemyX2][1] + playerattackhanndou3B + 65 &&
		stage[0][6][1] < pos[enemyY2][enemyX2][1] + playerattackhanndou3B + 65 &&
		stage[1][6][1] > pos[enemyY2][enemyX2][1] + playerattackhanndou3B + 65
		or stage[0][6][1] > pos[enemyY2][enemyX2][1] + playerattackhanndou3B + 65
		) {
		bairituY2 = 4.6;

	}
	if (stage[1][0][0] <  pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B + 25 &&
		stage[1][6][0]>  pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B + 25 &&
		stage[2][0][0] < pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B + 25 &&
		stage[2][6][0]> pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B + 25 &&
		stage[1][0][1] < pos[enemyY2][enemyX2][1] + playerattackhanndou3B + 65 &&
		stage[2][0][1] > pos[enemyY2][enemyX2][1] + playerattackhanndou3B + 65 &&
		stage[1][6][1] <pos[enemyY2][enemyX2][1] + playerattackhanndou3B + 65 &&
		stage[2][6][1] > pos[enemyY2][enemyX2][1] + playerattackhanndou3B + 65
		) {
		bairituY2 = 5;

	}
	if (stage[2][0][0] < pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B + 25 &&
		stage[2][6][0]> pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B + 25 &&
		stage[3][0][0] <  pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B + 25 &&
		stage[3][6][0]>  pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B + 25 &&
		stage[2][0][1] < pos[enemyY2][enemyX2][1] + playerattackhanndou3B + 65 &&//①
		stage[3][0][1] > pos[enemyY2][enemyX2][1] + playerattackhanndou3B + 65 &&//②
		stage[2][6][1] < pos[enemyY2][enemyX2][1] + playerattackhanndou3B + 65 &&
		stage[3][6][1] > pos[enemyY2][enemyX2][1] + playerattackhanndou3B + 65//ここを消しても一部分が変化しない奴は出来る。
		or stage[3][6][1] < pos[enemyY2][enemyX2][1] + playerattackhanndou3B + 65
		) {
		bairituY2 = 5.4;
	}


	//敵が吹っ飛ぶ上でのゲージを表すもの。
	DrawBox(800, 130, 800 + enemysabunHPpoint, 140, GetColor(0, 0, 255), TRUE);
	DrawFormatString(810 + 100, 130, GetColor(255, 255, 0),
		"Continuous attack gauge to enemy %d/100", enemysabunHPpoint);



	//300ダメージを与えると敵が吹っ飛ぶ。
	if (enemysabunHPpoint > 100) {
		playerattackhanndou3 = playerattackhanndou3 + GetRand(5);
		huttobu = 1;
	}
	else if (enemy2sabunHPpoint > 100) {
		playerattackhanndou3B = playerattackhanndou3B + GetRand(5);
		huttobu2 = 1;
	}
	if (huttobu == 1) {
		++huttobuframe;
	}
	else if (huttobu2 == 1) {
		++huttobu2frame;
	}
	if (huttobuframe > 180) {
		huttobu = 0;
		huttobuframe = 0;
		playerattackhanndou3 = 0;
		enemysabunHPpoint = 0;
	}
	else if (huttobu2frame > 180) {
		huttobu2 = 0;
		huttobu2frame = 0;
		playerattackhanndou3B = 0;
		enemy2sabunHPpoint = 0;
	}
	//if (mozimark == 1) {
	//	SetFontSize(44);
	//	DrawFormatString(1000, 0, GetColor(255, 0, 0), "GOOD!!");
	//}


	//if (playerHPhyouzi == 0) {


		//if (playerHP > 200) {
		//	color = Red;
		//}
		//else if (playerHP <= 200) {
		//	color = Bule;
		//}
		//if (playerHPsubun > 0) {
		//	DrawBox(50, 100, playerHP + 50 + playerHPsubun, 110, Red, TRUE);   // 四角形を描画(塗りつぶし))
		//}


	//}




	//ここのif文で上の間に入ったカウンターボタンをてhirumaseを上げればいい。



	Red = GetColor(255, 0, 0);
	Bule = GetColor(0, 255, 0);
	DrawBox(50, 100, 650, 110, Bule, TRUE);   // 四角形を描画(塗りつぶし))

	DrawBox(50, 100, playerHP + 50, 110, Red, TRUE);
	DrawFormatString(60 + 600, 100, GetColor(255, 255, 0),
		"%d/600", playerHP);
	//敵1のHP

	if (enemy1HP > 0) {
		DrawBox(800, 100, 800 + 500, 110, Bule, TRUE);   // 四角形を描画(塗りつぶし))
		//if (playerHPsubun > 0) {
		//	DrawBox(50, 100, playerHP + 50 + playerHPsubun, 110, Red, TRUE);   // 四角形を描画(塗りつぶし))
		//}
		enemy1HPgage = enemy1HP / 3;
		DrawBox(800, 100, 800 + enemy1HPgage, 110, Red, TRUE);
		DrawFormatString(810 + 500, 100, GetColor(255, 255, 0),
			"%d/1500", enemy1HP);

	}
	if (enemy2HP > 0) {
		DrawBox(800, 120, 800 + 500, 130, Bule, TRUE);   // 四角形を描画(塗りつぶし))
		//if (playerHPsubun > 0) {
		//	DrawBox(50, 100, playerHP + 50 + playerHPsubun, 110, Red, TRUE);   // 四角形を描画(塗りつぶし))
		//}
		enemy2HPgage = enemy2HP / 3;
		DrawBox(800, 120, 900 + enemy2HPgage, 130, Red, TRUE);
		DrawFormatString(810 + 500, 130, GetColor(255, 255, 0),
			"%d/1200", enemy2HP);

	}
	//敵二人のHP表示
	if (enemy1HP > 0) {
		DrawFormatString(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 100, GetColor(255, 0, 0), "enemy1HP%d", enemy1HP);
	}
	if (enemy2HP > 0) {
		DrawFormatString(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 100, GetColor(255, 100, 0), "enemy2HP%d", enemy2HP);

	}


	if (enemy1HP > 0) {
		DrawFormatString(25, 20, GetColor(255, 255, 0), "※If you set the opponent's HP to 0, you will kill the opponent.");
		DrawFormatString(25, 40, GetColor(255, 255, 0), "※Try to persuade and not kill while fighting as much as possible.");
	}

	//何を選択しているかの表示
	if (GcountA == 1) { DrawFormatString(25, 250, GetColor(0, 100, 255), "グロッグリロード中"); }

	if (Gfunction_status == 0 && GcountA == 0) {
		DrawFormatString(25, 250, GetColor(255, 255, 0), "グロッグ射撃可能");
		DrawFormatString(25, 280, GetColor(255, 255, 0), "Gcount%d/Gcount%d", Gcount, Gcount2);
	}
	//関数settoku1()を呼んだままではこっちに帰ってくるとフリーズして終了するので、ここで関数の方に飛んですべて解決してから、こっちに帰ってくるようにする。

	if (enemy2HP > 0) { //相方が生きた状態でないと説得出来ないようにした。
		if (enemy1HP > 100 && enemy1HP < 1500) {
			settoku5();
		}
		if (enemy1HP > 100 && enemy1HP < 1300) {
			settoku6();
		}
		if (enemy1HP > 100 && enemy1HP < 1000) {
			settoku7();
		}
		if (enemy1HP > 100 && enemy1HP < 700) {
			settoku8();
		}
		if (enemy1HP > 100 && enemy1HP < 300) {
			settoku9();
		}
		//ハートポイントがたまらなかった場合の選択肢。
		if (enemy1HP > 0 && enemy1HP < 100 && heartpoint < 2) {
			settoku11();
		}
		//★heartpointが2以上の場合殺さずに説得することが出来るが、そうでないと上の選択肢となる。。
		if (enemy1HP > 0 && enemy1HP < 100 && heartpoint >= 2) {
			settoku10();
		}
	}
	//一回目の説得をこなさないと表示されないように一回目の説得をした場合のみserekutobotanncountを1とした。





	//★関数だと処理が遅れたりするので、ここに直接ダメージを食らったときの処理を書いた。これならほぼリアルタイムで処理できる。
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



















	//gpUpdateKey();  // キーの入力状態を取得
	ranndamuBGM = GetRand(4000);
	if (ranndamuBGM == 1) {
		ChangeVolumeSoundMem(140, waraigoesound);//この関数によって音声のボリュームを設定できる。
		waraigoesound = LoadSoundMem("waraigoe.mp3");
		PlaySoundMem(waraigoesound, DX_PLAYTYPE_BACK, FALSE);
		ranndamuBGM = 0;
	}
	else if (ranndamuBGM == 10) {
		ChangeVolumeSoundMem(140, waraigoesound2);//この関数によって音声のボリュームを設定できる。
		waraigoesound2 = LoadSoundMem("著作権フリー 商用利用可能 な 【効果音】　笑い声　大勢　一昔前のアメリカのコメディのような、わざとらしい笑い声.mp4");
		PlaySoundMem(waraigoesound2, DX_PLAYTYPE_BACK, FALSE);
		ranndamuBGM = 0;
	}

	//★コンティニューしても途中からBGMが再生するように戦闘内にstart == 2の時のに残ったsound3と同じ関数を入れて、PlaySoundMemの第三引数をFALSEとした。
	//★ここがあったせいで主人公が倒された後も音楽が止まなかった。
	//ChangeVolumeSoundMem(160, stage2sound);//この関数によって音声のボリュームを設定できる。
	//PlaySoundMem(stage2sound, DX_PLAYTYPE_BACK, FALSE);
































	//★説得中に通常状態の主人公の動きが止まらないようにここに書いた。敵も同じく。
	//右向き
	/*if (playerHP > 0) {//★主人公が攻撃している最中に通常状態や瀕死状態での画像が描画されないようにplayerHPlockがある。なぜplayerHPlockなんて名前にしたのかはわからない。
		hinnsiattack = 0;//回復した際に0になるようにする。
		KABURI = 0;//★HPが200以上の時は通常状態の重なりを有効にするために0にする。
		//zannzoulock = 0;//瀕死状態からタバコ回復で回復した際に再び元の画像に戻れるようにここで0にする。
		tabakomark = 23939;
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
	}

	//主人公左向き
	if (hidarimuki == 1) {
		++hidarimukiframe;
		//playerImage2 = lockonHandle[0];//情報lockonMove == 10やlockonHandle[0]を引き継いで下に書いた描画関数に入るため、ここには関数に入れる情報だけ入るのだ。
		//その時の情報lockonMove == 10やlockonHandle[0]以外の引き継がれたとうかその時の敵の座標なども関数に入る。関数が求めるものが入るので、関数に必要なものを揃える。
	}
	if (hidarimukiframe == 20) {
		playerImage2 = playerHandle2[1];

	}
	if (hidarimukiframe == 40) {
		playerImage2 = playerHandle2[2];


	}
	if (hidarimukiframe == 60) {
		playerImage2 = playerHandle2[1];
	}
	if (hidarimukiframe == 80) {
		playerImage2 = playerHandle2[0];
	}
	if (hidarimukiframe == 100) {
		hidarimukiframe = 0;
	}*/



	//敵の通常状態の動きを制御する部分。
	/*if (enemyMove >= 0 && ++enemyMove < 100) {//pcが60フレームで一周するためenemyMoveが61以上だとenemyGHandle[8]が反映されず元のままで移動が終わる。なのでenemyMoveは60以下でなくてはならない
		enemyImage3 = enemy3[0];//60になる前に画像11を描画するようにしなければならないため、60より小さい40フレームにした。
	}
	if (enemyMove > 100 && enemyMove < 200) {//pcが60フレームで一周するためenemyMoveが61以上だとenemyGHandle[8]が反映されず元のままで移動が終わる。なのでenemyMoveは60以下でなくてはならない
		enemyImage3 = enemy3[1];//60になる前に画像11を描画するようにしなければならないため、60より小さい40フレームにした。
	}
	if (enemyMove > 200 && enemyMove < 300) {//pcが60フレームで一周するためenemyMoveが61以上だとenemyGHandle[8]が反映されず元のままで移動が終わる。なのでenemyMoveは60以下でなくてはならない
		enemyImage3 = enemy3[2];//60になる前に画像11を描画するようにしなければならないため、60より小さい40フレームにした。
	}
	if (enemyMove > 300) {
		enemyMove = 0;
	}*/

	//敵の通常状態の動きを制御する部分。
	/*if (enemyMove >= 0 && ++enemyMove < 80) {//pcが60フレームで一周するためenemyMoveが61以上だとenemyGHandle[8]が反映されず元のままで移動が終わる。なのでenemyMoveは60以下でなくてはならない
		enemyImage2 = enemy2[0];//60になる前に画像11を描画するようにしなければならないため、60より小さい40フレームにした。
	}
	if (enemyMove > 80 && enemyMove < 160) {//pcが60フレームで一周するためenemyMoveが61以上だとenemyGHandle[8]が反映されず元のままで移動が終わる。なのでenemyMoveは60以下でなくてはならない
		enemyImage2 = enemy2[1];//60になる前に画像11を描画するようにしなければならないため、60より小さい40フレームにした。
	}
	if (enemyMove > 160 && enemyMove < 240) {//pcが60フレームで一周するためenemyMoveが61以上だとenemyGHandle[8]が反映されず元のままで移動が終わる。なのでenemyMoveは60以下でなくてはならない
		enemyImage2 = enemy2[2];//60になる前に画像11を描画するようにしなければならないため、60より小さい40フレームにした。
	}
	if (enemyMove > 240) {
		enemyMove = 0;
	}*/

	if (playerkonntororulock3 == 0) {
		//playerMove = 1;
		//説得中は戦闘中のキーが押せないようにするためのロックを設けた。
		if (playerkonntororulock == 0) {
			if (playerkonntororulock2 == 0) {
				gpUpdateKey();

				if (CheckHitKey(KEY_INPUT_Z) != 0) {
					++s;
				}

				//ガード
				if (CheckHitKey(KEY_INPUT_B) != 0) {
					--s;
				}
				//ガード
				if (CheckHitKey(KEY_INPUT_A) != 0) {
					++y;
				}
				//ガード
				if (CheckHitKey(KEY_INPUT_S) != 0) {
					--y;
				}
				//ガード
				if (CheckHitKey(KEY_INPUT_Q) != 0) {
					++x;
				}
				//ガード
				if (CheckHitKey(KEY_INPUT_W) != 0) {
					--x;
				}

				if (CheckHitKey(KEY_INPUT_C) != 0) {
					s2 = s2 + 0.01;
				}

				//ガード
				if (CheckHitKey(KEY_INPUT_V) != 0) {
					s2 = s2 - 0.01;
				}
				//ガード
				if (CheckHitKey(KEY_INPUT_D) != 0) {
					y2 = y2 + 0.01;
				}
				//ガード
				if (CheckHitKey(KEY_INPUT_F) != 0) {
					y2 = y2 - 0.01;
				}
				//ガード
				if (CheckHitKey(KEY_INPUT_E) != 0) {
					x2 = x2 + 0.01;
				}
				//ガード
				if (CheckHitKey(KEY_INPUT_R) != 0) {
					x2 = x2 - 0.01;
				}



				if (motonomasunimodoru == 0) {//★相手陣地の中なら攻撃を食らってもその場に止まり移動しないが
					//自分の陣地にいる際は攻撃された際に立ったまま移動できてしまうので条件を付けくわえた。
					if (jyuuzikeysousa2 == 0 && kaihilock == 0) {
						if (jyuuzikeysousa == 0) {
							if (playermovelock == 0 && playermovelock2 == 0) {
								if (RIGHTbotannlock == 0) {
									if (Pad[PAD_RIGHT] == 1 && playerX < 2) { //キーを入力する以外にも押した後に早く画像を切り替えて足踏みするようにするために初期値にも1はあるがキーにもplayerMove=1を書いたり、キーを押したらどうしたいかをするためにplayerX++を書いている。
										//playerMove = 1; 
										playerX++;  nomove = 1;//最大まで右には二回しか進めないのでplayerX < 2と書いた。
										zannzou = 30; zannzouA = 0; zannzouB = 0; zannzouC = 0;
										zannzoulock = 1;
										//	R1botannlock =  1;
											//R1lock = 1;//移動中にR1が押せないようにするための変数
										preplayerX = playerX - 1;
										//R1lock = 1;
										//ugokuX = ugokuX + 0.5;
										//ugokuX2 = ugokuX2 + 0.5;
										//★スライド移動中での反転を可能にする部分。
										playerkonntororulock = 1;
										if (motonomasunimodoru > 0) {
											migimuki = 1;
											hidarimuki = 0;
										}

										if (Pad[PAD_DOWN] == 1) {//斜め押しをした際に斜めではなく右に進むようにする。しかし正しく機能していない。
											komanndomark = 12;
											playerX = preplayerX;//★多分、マスから相手の目の前に瞬間移動して攻撃する際の名残だと思うので関係ないかもしれない。
											//playerkonntororulock = 1;
										}
										else if (Pad[PAD_UP] == 1) {
											komanndomark = 13;
											playerX = preplayerX;
											//playerkonntororulock = 1;
										}

									}
								} //playerMove = 1;があると下に書いたplayerMoveより足踏みするplayerMoveが無いと初期値の1でそのまま足踏みするので遅く反応するのでは？
								if (LEFTbotannlock == 0) {
									if (Pad[PAD_LEFT] == 1 && playerX > 0) {//キーにplayerMove=1を書くと初期値の1よりも早くキーに書いたplayerMoveの1が行くため早く足踏みに行くため、止まってから足踏みに行くまでの間にある向きを変える画像playerGHandle[2]が一瞬であるため、向きを変えるのが早く見えるのでは？足踏みを速く来るようにしたため。
									//playerMove = 1; 
										playerX--;//まあ、足踏みさせなくても、ただ書くだけでも方向を十分早く変えれる
										zannzouA = 30; zannzou = 0; zannzouB = 0; zannzouC = 0;
										zannzoulock = 1; //R1lock = 1;
										preplayerX = playerX + 1;
										//	R1botannlock = 1;
											//preframeA = 1;
										//★スライド移動中での反転を可能にする部分。
										playerkonntororulock = 1;
										if (motonomasunimodoru > 0) {
											migimuki = 0;
											hidarimuki = 1;
										}
										if (Pad[PAD_DOWN] == 1) {
											komanndomark = 14;
											playerX = preplayerX;
											//playerkonntororulock = 1;
										}
										else if (Pad[PAD_UP] == 1) {
											komanndomark = 15;
											playerX = preplayerX;
											//playerkonntororulock = 1;
										}
									}
								}
								if (UPbotannlock == 0) {
									if (Pad[PAD_UP] == 1 && playerY > 0) {
										//playerMove = 1;
										playerY--;
										zannzouC = 15; zannzouA = 0; zannzou = 0; zannzouB = 0;
										zannzoulock = 1;// R1lock = 1;
										//preframeB = 1;
										//定数として小数点の値を使うのはよかったのだ。変数自体が最初から小数になったりするのは型によっては駄目なのでは？
										syuzinnkoubairitu = syuzinnkoubairitu - 0.4;
										//	R1botannlock = 1;
										playerkonntororulock = 1;
									}
								}
								if (DOWNbotannlock == 0) {
									if (Pad[PAD_DOWN] == 1 && playerY < 2) {

										//playerMove = 1;
										playerY++;
										zannzouC = 0; zannzouA = 0; zannzou = 0; zannzouB = 15;
										zannzoulock = 1; //R1lock = 1;
										//preframeC = 1;
										syuzinnkoubairitu = syuzinnkoubairitu + 0.4;
										//	R1botannlock = 1;
										//pos[playerY][playerX][1] = pos[playerY][playerX][1] - 100;
										playerkonntororulock = 1;
									}
								}

							}
						}
					}
				}
			}

			//↓通常殴ると連続殴るのプログラム。
		//★if (Pad[PAD_6] == 1 && kougekilock == 0&&kougekiroclmark == 0&&enemyY == playerY)の中に書くと
		//Pad[PAD_6] == 1が押されている間のみしか発動しないので前の条件式が発動しなくてもkougekilockの値があれば良いようにした。
			if (kougekikannkakulock == 0) {
				if (kougekidekinailock == 1) {
					if (attackframe == 0) {

						if (migimuki == 1) {
							if (Pad[PAD_2] == 1 && kougekilock == 1 && kougekiKANOU == 2 && sousakanou == 0 && nextattack == 0 &&
								motonomasunimodoru > 0 && Pad[PAD_6] == 0 && Pad[PAD_LEFT] == 0) {
								lock = 0;//移動ボタンが押せないように。
								//LEFTmark = 9;
								R1lock = 1;//再度殴ってる最中にR1を押して、攻撃中の座標を保存しないために1とした。
								enemysabunHP = 5;
								stayherelock3 = 1;//★敵のHP表示を消すために必要な変数。
								//addattacktime = 300;//先行入力でコンボが決まった時のためのアドアタックタイム。
								++attackframe;
								nagurusound = LoadSoundMem("殴る音.mp3");
								//PlaySoundMem(nagurusound, DX_PLAYTYPE_BACK);
								nagurugazou = 1;
								//kougekiKANOU = 0;
								sinnzoubyouga = 1;
								//追加で殴るときにコンボの画像が消えるように。
								//KONNBO1A = 1;
								//KONNBO1B = 0;
								zannzoulock = 1;
								//++nagurucount;
								//pos[playerY][playerX][0] = pos[playerY][playerX][0] + 30;
								//pos[playerY][playerX][1] = playerkougekiYzahyou;
								konnbokakuninn = 1;
								nagurukasanaru = 1;

								enemykougekilock = 1;

								tabakolock = 1;//ロック中はタバコが吸えないように1にする。

								playerHPlock = 1;//キックするときにダメージを負った状態の画像を描画しないための物。
								//nanameidouX = nanameidouX + 5;
								playerattackhanndou = playerattackhanndou + 10;//自分が吹っ飛ぶのではなく、敵が吹っ飛ぶための反動なので自分の描画部分の一には書かない
								sinnzoubyouga = 1;//血しぶきを描画するための変数。
								motonomasunimodoru = motonomasunimodoru + 40;//攻撃中に攻撃が当たったら時間が延びる
								//★足すにするとたまに総合で180になったときにif文で0になってしまうので足すではなく定数にした。
								nextattack = 1;//攻撃の同時押しを防ぐための変数。
								//★★たまに相手をより奥に突き飛ばすことがある。そんな時はさらにR1を押して追いかけて追加攻撃するといい。
								notattacklock = 1;
								enemyattaking = 1;
								//nanameidouX = nanameidouX + 8;
								//playerattackhanndou = playerattackhanndou + 5;//敵が奥に進む
								//if (GetRand(10) < 4) {
								//	playerattackhanndou2 = playerattackhanndou2 + 30;//どこに移動するかわからないようにしてギャンブル性を高めてマンネリ化を防ぐ。
								//	playerattackhanndou3 = playerattackhanndou3 + 5;// playerattackhanndou3はY軸に吹っ飛ばすための変数。
								//}

								//コンボ
								++conbocount;
								//続けて殴るとバグで敵の攻撃を一気に受けて即死することがあるので一定の区間での攻撃とする。
								//キックや刀と同じ変数で使えれば同時押しによる攻撃などもより強化できると思う。
								//++kougekikannkaku;
								enemyzannzoulockframe1 = 1;//相手のダメージを食らった際の怯みを初期に戻すため
								stayhereframe = 1;

								enemysabunHPpoint = enemysabunHPpoint + 10;//敵を吹っ飛ばすために必要なポイント
								bloodMove = 1;
							}
							if (Pad[PAD_2] == 1 && kougekilock == 1 && kougekiKANOU == 3 && sousakanou == 0 && nextattack == 0 &&
								motonomasunimodoru > 0 && Pad[PAD_6] == 0 && Pad[PAD_LEFT] == 0) {
								lock = 0;//移動ボタンが押せないように。
								//LEFTmark = 9;
								R1lock = 1;//再度殴ってる最中にR1を押して、攻撃中の座標を保存しないために1とした。
								anotherenemysabunHP = 5;
								stayherelock3 = 1;//★敵のHP表示を消すために必要な変数。
								//addattacktime = 300;//先行入力でコンボが決まった時のためのアドアタックタイム。
								++attackframe;
								nagurusound = LoadSoundMem("殴る音.mp3");
								//PlaySoundMem(nagurusound, DX_PLAYTYPE_BACK);
								nagurugazou = 1;
								//kougekiKANOU = 0;
								sinnzoubyouga = 1;
								//追加で殴るときにコンボの画像が消えるように。
								//KONNBO1A = 1;
								//KONNBO1B = 0;
								zannzoulock = 1;
								//++nagurucount;
								//pos[playerY][playerX][0] = playerkougekiXzahyou - 100;
								//pos[playerY][playerX][1] = playerkougekiYzahyou;
								konnbokakuninn = 1;
								nagurukasanaru = 1;

								enemykougekilock = 1;

								tabakolock = 1;//ロック中はタバコが吸えないように1にする。

								playerHPlock = 1;//キックするときにダメージを負った状態の画像を描画しないための物。

								//playerattackhanndou = playerattackhanndou + 10;//自分が吹っ飛ぶのではなく、敵が吹っ飛ぶための反動なので自分の描画部分の一には書かない
								sinnzoubyouga = 1;//血しぶきを描画するための変数。
								motonomasunimodoru = motonomasunimodoru + 40;//攻撃中に攻撃が当たったら時間が延びる
								//nanameidouX = nanameidouX + 5;
								playerattackhanndouB = playerattackhanndouB + 10;
								//★足すにするとたまに総合で180になったときにif文で0になってしまうので足すではなく定数にした。
								nextattack = 1;//攻撃の同時押しを防ぐための変数。
								//★★たまに相手をより奥に突き飛ばすことがある。そんな時はさらにR1を押して追いかけて追加攻撃するといい。
								notattacklock = 1;
								enemyattaking = 1;
								//if (GetRand(10) < 4) {
								//	playerattackhanndou2B = playerattackhanndou2B + 30;//どこに移動するかわからないようにしてギャンブル性を高めてマンネリ化を防ぐ。
								//	playerattackhanndou3B = playerattackhanndou3B + 25;// playerattackhanndou3はY軸に吹っ飛ばすための変数。
								//}
								//コンボ
								++conbocount;
								//続けて殴るとバグで敵の攻撃を一気に受けて即死することがあるので一定の区間での攻撃とする。
								//キックや刀と同じ変数で使えれば同時押しによる攻撃などもより強化できると思う。
								//++kougekikannkaku;
								enemyzannzoulockBframe = 1;
								stayhere2frame = 1;
								enemy2sabunHPpoint = enemy2sabunHPpoint + 10;
								bloodMove = 1;
							}
						}


						else if (hidarimuki == 1) {
							if (Pad[PAD_2] == 1 && kougekilock == 1 && kougekiKANOU == 2 && sousakanou == 0 && nextattack == 0 &&
								motonomasunimodoru > 0 && Pad[PAD_6] == 0 && Pad[PAD_LEFT] == 0) {
								lock = 0;//移動ボタンが押せないように。
								//LEFTmark = 9;
								R1lock = 1;//再度殴ってる最中にR1を押して、攻撃中の座標を保存しないために1とした。
								enemysabunHP = 5;
								stayherelock3 = 1;//★敵のHP表示を消すために必要な変数。
								//addattacktime = 300;//先行入力でコンボが決まった時のためのアドアタックタイム。
								++attackframe;
								nagurusound = LoadSoundMem("殴る音.mp3");
								//PlaySoundMem(nagurusound, DX_PLAYTYPE_BACK);
								nagurugazou = 1;
								//kougekiKANOU = 0;
								sinnzoubyouga = 1;
								//追加で殴るときにコンボの画像が消えるように。
								//KONNBO1A = 1;
								//KONNBO1B = 0;
								zannzoulock = 1;
								//++nagurucount;
								//pos[playerY][playerX][0] = pos[playerY][playerX][0] + 30;
								//pos[playerY][playerX][1] = playerkougekiYzahyou;
								konnbokakuninn = 1;
								nagurukasanaru = 1;

								enemykougekilock = 1;

								tabakolock = 1;//ロック中はタバコが吸えないように1にする。

								playerHPlock = 1;//キックするときにダメージを負った状態の画像を描画しないための物。
								//nanameidouX = nanameidouX + 5;
								playerattackhanndou = playerattackhanndou - 10;//自分が吹っ飛ぶのではなく、敵が吹っ飛ぶための反動なので自分の描画部分の一には書かない
								sinnzoubyouga = 1;//血しぶきを描画するための変数。
								motonomasunimodoru = motonomasunimodoru + 40;//攻撃中に攻撃が当たったら時間が延びる
								//★足すにするとたまに総合で180になったときにif文で0になってしまうので足すではなく定数にした。
								nextattack = 1;//攻撃の同時押しを防ぐための変数。
								//★★たまに相手をより奥に突き飛ばすことがある。そんな時はさらにR1を押して追いかけて追加攻撃するといい。
								notattacklock = 1;
								enemyattaking = 1;
								//nanameidouX = nanameidouX + 8;
								//playerattackhanndou = playerattackhanndou + 5;//敵が奥に進む
								//if (GetRand(10) < 4) {
								//	playerattackhanndou2 = playerattackhanndou2 + 30;//どこに移動するかわからないようにしてギャンブル性を高めてマンネリ化を防ぐ。
								//	playerattackhanndou3 = playerattackhanndou3 + 5;// playerattackhanndou3はY軸に吹っ飛ばすための変数。
								//}

								//コンボ
								++conbocount;
								//続けて殴るとバグで敵の攻撃を一気に受けて即死することがあるので一定の区間での攻撃とする。
								//キックや刀と同じ変数で使えれば同時押しによる攻撃などもより強化できると思う。
								//++kougekikannkaku;
								enemyzannzoulockframe1 = 1;//相手のダメージを食らった際の怯みを初期に戻すため
								stayhereframe = 1;

								enemysabunHPpoint = enemysabunHPpoint + 10;//敵を吹っ飛ばすために必要なポイント
								bloodMove = 1;
							}
							if (Pad[PAD_2] == 1 && kougekilock == 1 && kougekiKANOU == 3 && sousakanou == 0 && nextattack == 0 &&
								motonomasunimodoru > 0 && Pad[PAD_6] == 0 && Pad[PAD_LEFT] == 0) {
								lock = 0;//移動ボタンが押せないように。
								//LEFTmark = 9;
								R1lock = 1;//再度殴ってる最中にR1を押して、攻撃中の座標を保存しないために1とした。
								anotherenemysabunHP = 5;
								stayherelock3 = 1;//★敵のHP表示を消すために必要な変数。
								//addattacktime = 300;//先行入力でコンボが決まった時のためのアドアタックタイム。
								++attackframe;
								nagurusound = LoadSoundMem("殴る音.mp3");
								//PlaySoundMem(nagurusound, DX_PLAYTYPE_BACK);
								nagurugazou = 1;
								//kougekiKANOU = 0;
								sinnzoubyouga = 1;
								//追加で殴るときにコンボの画像が消えるように。
								//KONNBO1A = 1;
								//KONNBO1B = 0;
								zannzoulock = 1;
								//++nagurucount;
								//pos[playerY][playerX][0] = playerkougekiXzahyou - 100;
								//pos[playerY][playerX][1] = playerkougekiYzahyou;
								konnbokakuninn = 1;
								nagurukasanaru = 1;

								enemykougekilock = 1;

								tabakolock = 1;//ロック中はタバコが吸えないように1にする。

								playerHPlock = 1;//キックするときにダメージを負った状態の画像を描画しないための物。

								//playerattackhanndou = playerattackhanndou + 10;//自分が吹っ飛ぶのではなく、敵が吹っ飛ぶための反動なので自分の描画部分の一には書かない
								sinnzoubyouga = 1;//血しぶきを描画するための変数。
								motonomasunimodoru = motonomasunimodoru + 40;//攻撃中に攻撃が当たったら時間が延びる
								//nanameidouX = nanameidouX + 5;
								playerattackhanndouB = playerattackhanndouB - 10;
								//★足すにするとたまに総合で180になったときにif文で0になってしまうので足すではなく定数にした。
								nextattack = 1;//攻撃の同時押しを防ぐための変数。
								//★★たまに相手をより奥に突き飛ばすことがある。そんな時はさらにR1を押して追いかけて追加攻撃するといい。
								notattacklock = 1;
								enemyattaking = 1;
								//if (GetRand(10) < 4) {
								//	playerattackhanndou2B = playerattackhanndou2B + 30;//どこに移動するかわからないようにしてギャンブル性を高めてマンネリ化を防ぐ。
								//	playerattackhanndou3B = playerattackhanndou3B + 25;// playerattackhanndou3はY軸に吹っ飛ばすための変数。
								//}
								//コンボ
								++conbocount;
								//続けて殴るとバグで敵の攻撃を一気に受けて即死することがあるので一定の区間での攻撃とする。
								//キックや刀と同じ変数で使えれば同時押しによる攻撃などもより強化できると思う。
								//++kougekikannkaku;
								enemyzannzoulockBframe = 1;
								stayhere2frame = 1;
								enemy2sabunHPpoint = enemy2sabunHPpoint + 10;
								bloodMove = 1;
							}
						}

					}//1より大きい時は繰り上がり、30より小さい間に{}をする。
					//attackframeAが1の後に一発目の攻撃が終わることですぐに0になってしまい、ここをロックできず、再び殴る攻撃をしていた。
					//たまに時間の影響で正しく動くこともあった。
					if (kougekiKANOU == 2) {
						if (attackframe > 0 && ++attackframe < 80) {
							if (attackframe > 35 && attackframe < 80) {//★この間にボタンを押すと連続攻撃に移る。
								//最初の殴ると一緒にatatackframeは立ち上がるため、一発目の攻撃が表示された後くらいのフレームから
								//二発目を描画したいので、60からにした。
								if (Pad[PAD_2] == 1 && kougekiKANOU == 2 && sousakanou == 0 && nextattack == 0 && attackframeA == 0) {
									attackframeA = 1;
									nagurugazou = 0;
									++nagurugazou2;
								}

							}
						}
					}

					if (kougekiKANOU == 3) {
						if (attackframe > 0 && ++attackframe < 80) {
							if (attackframe > 35 && attackframe < 80) {//★この間にボタンを押すと連続攻撃に移る。
								//最初の殴ると一緒にatatackframeは立ち上がるため、一発目の攻撃が表示された後くらいのフレームから
								//二発目を描画したいので、60からにした。

								if (Pad[PAD_2] == 1 && kougekiKANOU == 3 && sousakanou == 0 && nextattack == 0 && attackframeA == 0) {
									attackframeA = 1;
									nagurugazou = 0;
									++nagurugazou2;
								}
							}
						}
					}

					/*if (attackframe > 80) {//コンボが決まらなかった場合で早く元に戻ると、仮にコンボが決まった際にここのフレームが50とかだと
						//コンボが終わった後に上のボタンをまた押せてしまい、二段目の技が連続で出てきてしまう。
						//なのでここではコンボが決まった後にもう少し長くすることで連続で二段目の攻撃が連続でできないようにした。
						//まああるいは、上のフレームをもっと短くして100ではなく、50とかにしても解決できるかもしれない。
						//解決できるが、50は短すぎるため連続押し自体が難しいからこれでいい。
						attackframe = 0;
						attackframeA = 0;
					}*/

					//★★ && kougekilock == 1&& kougekiKANOU == 1はR1を押さない場合の時は上に書いたように
					//R1lockは0になるので、コンボが出来ないので他の変数konnbokakuninnを使った。
					//最初からコンボ出ない場合はR1lockは1のままなのでそのままキックできる。
				//Yボタンからのコンボを決めるためのYボタンを入力する部分//キックするボタン
					//★どうせフレームとkougekiKANOUの範囲でダメージが与えられるので、これとフレーム上げの個所は一つでいい。
					if (Pad[PAD_4] == 1 && kougekilock == 1 && enemysabunHP == 0 && sousakanou == 0 && nextattack == 0) {//enemysabunHPが0となるときに押せるようにしたので殴るが押されていないときにキックができるようにした。
					   //R1での移動時にplayermovelockを1にしてるのでここにplayermovelock=1を書かなくていい。
						R1lock = 1;
						lock = 0;//ロックマークが消え、かつロックマークが移動して、攻撃判定外になり攻撃ボタンを押しているのに攻撃できない
						//ことを避けるために0にして、if (lock == 1)が働かないよにする。
						//pos[playerY][playerX][0] = playerkougekiXzahyou - 100;
						//pos[playerY][playerX][1] = playerkougekiYzahyou;
						//LEFTmark = 1000;
						//lockmark = 1;
						//lockonMove = 1;//アタックする時　ロックオンの画像が消えるように値を0にする。
						stayherelock3 = 1;//★敵のHP表示を消すために必要な変数。
						//addattacktime = 300;//先行入力でコンボが決まった時のためのアドアタックタイム。
						attackframe = 0;//コンボへ分岐する際に殴るなどがでないようにアタックフレーム1は0にする。
						sennkounyuuryokubunnki = 1;
						kougekilock = 1;////先行入力でコンボが決まった時に誤作動でXボタンを押しても殴るがでないように他の値にする。
						zannzoulock = 1;

						KONNBO1A = 1;


						nagurukasanaru = 0;
						KONNBO1kasanaru = 1;

						enemykougekilock = 1;

						playerHPlock = 1;//キックするときにダメージを負った状態の画像を描画しないための物。
						nextattack = 1;
						//motonomasunimodoru = 160;//コンボが決まると一定の値になるようにした。

					}

					if (sennkounyuuryokubunnki == 1) {
						++attackframe2;
						//LEFTmark = 114;
					}

					//★上と下でattackframeの範囲があるが、上のは通常攻撃での最初の殴るのフレーム、
					//★下は相手の目の前に移動した後の下のif文を考慮したうえでのattackframeなのでattackframeの範囲が被っているわけではないので問題ない。
					//先行入力の攻撃設定//ロックの中に書くとロックボタンを押した一瞬しかattackframeの値が上がらないのでここに書いた。
					//if (kougekilock == 1 && kougekiKANOU == 2) {
						//attackframe1～3に関して、攻撃中は動けない様に書いた。attackframe1は上の方のif文の中に書いた。
					//	if (attackframe > 0 && attackframe <= 150) {
					//		playermovelock = 1;
					//	}
					//	if (attackframe2 > 0 && attackframe2 <= 150) {
					//		playermovelock = 1;
					//	}
					//	if (attackframe3 > 0 && attackframe3 <= 150) {
					//		playermovelock = 1;
					//	}
					//}
					//++attackframe;
					//★以前はkougekiKANOUも条件に合ったため、敵から離れている際はkougekiKANOUが0となり、attackframe2の値が中途半端になってしまい、スライドの横移動
					//だけで勝手に蹴り攻撃が出てしまった。


					if (attackframe2 > 0 && attackframe2 < 40 && kougekiKANOU == 2) {//下のif (attackframe2 > 0 && attackframe2 < 15)と被らないようにする。
						if (migimuki == 1) {
							if (Pad[PAD_RIGHT] == 1) {//★↑の方は左はじきで反応しないように少し遅めに9にして、仮に遅めに左ははじきで右が入力されても反応しないように15とした。
								//LEFTmark = 514;
								//KONNBO1A = 0;//けり上げる時に、蹴る前の画像を描画しないように。
								enemysabunHPA = 10;//最初の普通の殴るの攻撃もXボタンを押すことのコンボをなるため
								//LEFTmark = 114514;//描画用に作った先行入力の確認用の変数
								LEFTmarklock = 1;//先行入力が再びできるようにするにはXボタンで相手を殴るために、ここに1として、追加の方でLEFTmarklock = 0とした。
								//addattacktime = 300;
								attackframe = 0;//攻撃後に追加殴るをしなくても1としておけば0より大きいのでコンボがつながる。追加殴るで今コンボを繋げてもいい。
								stayherelock3 = 1;//敵のHPを消すために必要な変数
								//sennkounyuuryokubunnki = 1;//★if文よりsennkounyuuryokubunnki==1の時でないとここのif文は動かないので、sennkounyuuryokubunnkiが0の時は前のif文の条件に合わないのでattackframe2内であっても殴る2の攻撃できないのは当然である。
								attackframe2 = 0;//先行入力の分岐でsennkounyuuryokubunnki2に行かなかった場合にattackframe2の値が0になるように書いた。
								naguru2sound = LoadSoundMem("damage01.m4a");
								//PlaySoundMem(naguru2sound, DX_PLAYTYPE_BACK);
								//sennkounyuuryokubunnki3 = 0;//ここの先行入力が成功した際は続けて殴る3がでないようにここの変数を0にする。
								//attackframe3 = 150;//★先行入力が成功した際は続けて殴る3がでないように殴る3に引っ掛からないような変数の値にする。
								//sennkounyuuryokubunnki = 0;
								kougekilock = 1;//コンボ入力が成功した際に再びコンボを決めたい際に上のYボタンのif文を通過できるように
								//kougekilockの値を1にする。

								KONNBO1A = 0;//前の蹴る前の画像を消すための物。
								KONNBO1B = 1;//蹴り上げるの画像を描画するためのもの

								sennkounyuuryokubunnki = 0;
								KONNBO1kasanaru = 0;
								KONNBO2kasanaru = 1;
								sinnzoubyouga = 1;//血しぶきを描画するための変数。
								motonomasunimodoru = motonomasunimodoru + 30;//攻撃中に攻撃が当たったら時間が延びる
								playerattackhanndou = playerattackhanndou + 15;
								//nanameidouX = nanameidouX + 15;//★連続で蹴れるにしても、同じ40だとずっと蹴られるので、途中で差が出て、
								//範囲が2から0になるように30とする。
								//playerattackhanndou3 = playerattackhanndou3 + 30;
								enemyattaking = 1;
								//★★たまに相手をより奥に突き飛ばすことがある。そんな時はさらにR1を押して追いかけて追加攻撃するといい。
								if (GetRand(10) < 4) {
									playerattackhanndou2 = playerattackhanndou2 + 20;
									playerattackhanndou3 = playerattackhanndou3 + 10;// playerattackhanndou3はY軸に吹っ飛ばすための変数。
								}
								//コンボ
								++conbocount;
								enemyzannzoulockframe1 = 1;//相手のダメージを食らった際の怯みを初期に戻すため
								stayhereframe = 1;

								enemysabunHPpoint = enemysabunHPpoint + 20;
								bloodMove = 1;
							}
						}

						else if (hidarimuki == 1) {
							if (Pad[PAD_LEFT] == 1) {//★↑の方は左はじきで反応しないように少し遅めに9にして、仮に遅めに左ははじきで右が入力されても反応しないように15とした。
								//LEFTmark = 514;
								//KONNBO1A = 0;//けり上げる時に、蹴る前の画像を描画しないように。
								enemysabunHPA = 10;//最初の普通の殴るの攻撃もXボタンを押すことのコンボをなるため
								//LEFTmark = 114514;//描画用に作った先行入力の確認用の変数
								LEFTmarklock = 1;//先行入力が再びできるようにするにはXボタンで相手を殴るために、ここに1として、追加の方でLEFTmarklock = 0とした。
								//addattacktime = 300;
								attackframe = 0;//攻撃後に追加殴るをしなくても1としておけば0より大きいのでコンボがつながる。追加殴るで今コンボを繋げてもいい。
								stayherelock3 = 1;//敵のHPを消すために必要な変数
								//sennkounyuuryokubunnki = 1;//★if文よりsennkounyuuryokubunnki==1の時でないとここのif文は動かないので、sennkounyuuryokubunnkiが0の時は前のif文の条件に合わないのでattackframe2内であっても殴る2の攻撃できないのは当然である。
								attackframe2 = 0;//先行入力の分岐でsennkounyuuryokubunnki2に行かなかった場合にattackframe2の値が0になるように書いた。
								naguru2sound = LoadSoundMem("damage01.m4a");
								//PlaySoundMem(naguru2sound, DX_PLAYTYPE_BACK);
								//sennkounyuuryokubunnki3 = 0;//ここの先行入力が成功した際は続けて殴る3がでないようにここの変数を0にする。
								//attackframe3 = 150;//★先行入力が成功した際は続けて殴る3がでないように殴る3に引っ掛からないような変数の値にする。
								//sennkounyuuryokubunnki = 0;
								kougekilock = 1;//コンボ入力が成功した際に再びコンボを決めたい際に上のYボタンのif文を通過できるように
								//kougekilockの値を1にする。

								KONNBO1A = 0;//前の蹴る前の画像を消すための物。
								KONNBO1B = 1;//蹴り上げるの画像を描画するためのもの

								sennkounyuuryokubunnki = 0;
								KONNBO1kasanaru = 0;
								KONNBO2kasanaru = 1;
								sinnzoubyouga = 1;//血しぶきを描画するための変数。
								motonomasunimodoru = motonomasunimodoru + 30;//攻撃中に攻撃が当たったら時間が延びる
								playerattackhanndou = playerattackhanndou - 15;
								//nanameidouX = nanameidouX + 15;//★連続で蹴れるにしても、同じ40だとずっと蹴られるので、途中で差が出て、
								//範囲が2から0になるように30とする。
								//playerattackhanndou3 = playerattackhanndou3 + 30;
								enemyattaking = 1;
								//★★たまに相手をより奥に突き飛ばすことがある。そんな時はさらにR1を押して追いかけて追加攻撃するといい。
								if (GetRand(10) < 4) {
									playerattackhanndou2 = playerattackhanndou2 - 20;
									playerattackhanndou3 = playerattackhanndou3 - 10;// playerattackhanndou3はY軸に吹っ飛ばすための変数。
								}
								//コンボ
								++conbocount;
								enemyzannzoulockframe1 = 1;//相手のダメージを食らった際の怯みを初期に戻すため
								stayhereframe = 1;

								enemysabunHPpoint = enemysabunHPpoint + 20;
								bloodMove = 1;
							}
						}
						//sennkounyuuryokubunnki3 = 0;
						//attackframe3 = 0;//殴る2バージョンをやった後で値がそのままだと右を押しただけで殴るバージョン3ができてしまうので。
						//★殴る2に分岐した場合は殴る3の情報をすべて0にする。
						//attackframe = 0;//殴る2が成功したするかは別にこのフレームの時に一旦0にするとXボタンからのコンボがつながりやすい。
					}





					if (attackframe2 > 0 && attackframe2 < 40 && kougekiKANOU == 3) {//下のif (attackframe2 > 0 && attackframe2 < 15)と被らないようにする。
					   //Aボタン
						if (migimuki == 1) {
							if (Pad[PAD_RIGHT] == 1) {//★↑の方は左はじきで反応しないように少し遅めに9にして、仮に遅めに左ははじきで右が入力されても反応しないように15とした。
								//LEFTmark = 514;
								//KONNBO1A = 0;//けり上げる時に、蹴る前の画像を描画しないように。
								anotherenemysabunHPA = 10;//最初の普通の殴るの攻撃もXボタンを押すことのコンボをなるため
								//LEFTmark = 114514;//描画用に作った先行入力の確認用の変数
								LEFTmarklock = 1;//先行入力が再びできるようにするにはXボタンで相手を殴るために、ここに1として、追加の方でLEFTmarklock = 0とした。
								//addattacktime = 300;
								attackframe = 0;//攻撃後に追加殴るをしなくても1としておけば0より大きいのでコンボがつながる。追加殴るで今コンボを繋げてもいい。
								stayherelock3 = 1;//敵のHPを消すために必要な変数
								//sennkounyuuryokubunnki = 1;//★if文よりsennkounyuuryokubunnki==1の時でないとここのif文は動かないので、sennkounyuuryokubunnkiが0の時は前のif文の条件に合わないのでattackframe2内であっても殴る2の攻撃できないのは当然である。
								attackframe2 = 0;//先行入力の分岐でsennkounyuuryokubunnki2に行かなかった場合にattackframe2の値が0になるように書いた。
								//naguru2sound = LoadSoundMem("damage01.m4a");
								//PlaySoundMem(naguru2sound, DX_PLAYTYPE_BACK);
								//sennkounyuuryokubunnki3 = 0;//ここの先行入力が成功した際は続けて殴る3がでないようにここの変数を0にする。
								//attackframe3 = 150;//★先行入力が成功した際は続けて殴る3がでないように殴る3に引っ掛からないような変数の値にする。

								kougekilock = 1;//コンボ入力が成功した際に再びコンボを決めたい際に上のYボタンのif文を通過できるように
								//kougekilockの値を1にする。

								KONNBO1A = 0;//前の蹴る前の画像を消すための物。
								KONNBO1B = 1;//蹴り上げるの画像を描画するためのもの
								//sennkounyuuryokubunnki = 0;
								sennkounyuuryokubunnki = 0;

								KONNBO1kasanaru = 0;
								KONNBO2kasanaru = 1;
								sinnzoubyouga = 1;//血しぶきを描画するための変数。
								motonomasunimodoru = motonomasunimodoru + 30;//攻撃中に攻撃が当たったら時間が延びる
								//nanameidouX = nanameidouX + 15;
								playerattackhanndouB = playerattackhanndouB + 15;
								//playerattackhanndou3B = playerattackhanndou3B + 30;
								enemyattaking = 1;
								//★★たまに相手をより奥に突き飛ばすことがある。そんな時はさらにR1を押して追いかけて追加攻撃するといい。
								if (GetRand(10) < 4) {
									playerattackhanndou2B = playerattackhanndou2B + 20;
									playerattackhanndou3B = playerattackhanndou3B + 10;// playerattackhanndou3はY軸に吹っ飛ばすための変数。
								}
								//コンボ
								++conbocount;
								enemyzannzoulockBframe = 1;//相手のダメージを食らった際の怯みを初期に戻すため
								stayhere2frame = 1;

								enemy2sabunHPpoint = enemy2sabunHPpoint + 20;
							}
							bloodMove = 1;
						}
						else if (hidarimuki == 1) {
							if (Pad[PAD_LEFT] == 1) {//★↑の方は左はじきで反応しないように少し遅めに9にして、仮に遅めに左ははじきで右が入力されても反応しないように15とした。
								//LEFTmark = 514;
								//KONNBO1A = 0;//けり上げる時に、蹴る前の画像を描画しないように。
								anotherenemysabunHPA = 10;//最初の普通の殴るの攻撃もXボタンを押すことのコンボをなるため
								//LEFTmark = 114514;//描画用に作った先行入力の確認用の変数
								LEFTmarklock = 1;//先行入力が再びできるようにするにはXボタンで相手を殴るために、ここに1として、追加の方でLEFTmarklock = 0とした。
								//addattacktime = 300;
								attackframe = 0;//攻撃後に追加殴るをしなくても1としておけば0より大きいのでコンボがつながる。追加殴るで今コンボを繋げてもいい。
								stayherelock3 = 1;//敵のHPを消すために必要な変数
								//sennkounyuuryokubunnki = 1;//★if文よりsennkounyuuryokubunnki==1の時でないとここのif文は動かないので、sennkounyuuryokubunnkiが0の時は前のif文の条件に合わないのでattackframe2内であっても殴る2の攻撃できないのは当然である。
								attackframe2 = 0;//先行入力の分岐でsennkounyuuryokubunnki2に行かなかった場合にattackframe2の値が0になるように書いた。
								//naguru2sound = LoadSoundMem("damage01.m4a");
								//PlaySoundMem(naguru2sound, DX_PLAYTYPE_BACK);
								//sennkounyuuryokubunnki3 = 0;//ここの先行入力が成功した際は続けて殴る3がでないようにここの変数を0にする。
								//attackframe3 = 150;//★先行入力が成功した際は続けて殴る3がでないように殴る3に引っ掛からないような変数の値にする。

								kougekilock = 1;//コンボ入力が成功した際に再びコンボを決めたい際に上のYボタンのif文を通過できるように
								//kougekilockの値を1にする。

								KONNBO1A = 0;//前の蹴る前の画像を消すための物。
								KONNBO1B = 1;//蹴り上げるの画像を描画するためのもの
								//sennkounyuuryokubunnki = 0;
								sennkounyuuryokubunnki = 0;

								KONNBO1kasanaru = 0;
								KONNBO2kasanaru = 1;
								sinnzoubyouga = 1;//血しぶきを描画するための変数。
								motonomasunimodoru = motonomasunimodoru + 30;//攻撃中に攻撃が当たったら時間が延びる
								//nanameidouX = nanameidouX + 15;
								playerattackhanndouB = playerattackhanndouB - 15;
								//playerattackhanndou3B = playerattackhanndou3B + 30;
								enemyattaking = 1;
								//★★たまに相手をより奥に突き飛ばすことがある。そんな時はさらにR1を押して追いかけて追加攻撃するといい。
								if (GetRand(10) < 4) {
									playerattackhanndou2B = playerattackhanndou2B - 20;
									playerattackhanndou3B = playerattackhanndou3B - 10;// playerattackhanndou3はY軸に吹っ飛ばすための変数。
								}
								//コンボ
								++conbocount;
								enemyzannzoulockBframe = 1;//相手のダメージを食らった際の怯みを初期に戻すため
								stayhere2frame = 1;

								enemy2sabunHPpoint = enemy2sabunHPpoint + 20;
								bloodMove = 1;
							}
						}
						//sennkounyuuryokubunnki3 = 0;
						//attackframe3 = 0;//殴る2バージョンをやった後で値がそのままだと右を押しただけで殴るバージョン3ができてしまうので。
						//★殴る2に分岐した場合は殴る3の情報をすべて0にする。
						//attackframe = 0;//殴る2が成功したするかは別にこのフレームの時に一旦0にするとXボタンからのコンボがつながりやすい。



					//ここの先行入力に成功すると殴るバージョン3に続く。
					//★★このフレームがちょうどいい。

					}


					/*
					//刀攻撃の際のAボタンのプログラム。
					if (Pad[PAD_1] == 1 && motonomasunimodoru > 0 && nextattack == 0) {
						//zannzoulock = 1;
						KONNBO1Aframe = 0;//こいつを0にすることで描画のキックをする前の画像を描画できなようにした。
						KONNBO1Bframe = 0;
						KONNBO1A = 0;//別のコンボに進んだため、値を0にする。//注意、まだ画像が作れていないので何も表示されない。
						KONNBO1B = 0;//別のコンボに進んだため、値を0にする。//注意、まだ画像が作れていないので何も表示されない。
						sennkounyuuryokubunnki3 = 1;//ここの先行入力に成功すると殴るバージョン3に続く。
				//		LEFTmark = 2;//確認のために。
				//		addattacktime = 300;//★コンボのつなぎとして、殴る3のコンボが入らな過ぎるのも困るので。
						//★addattacktime = 50では短くて入力が成功してattackframe3が上がってもaddattacktimeが0になってしまい元のマスに戻ってしまい殴る3が出来なかった。
						sennkounyuuryokubunnki = 0;//殴る2に行かない様にするため。
						attackframe2 = 0;//殴る3に行った際に、attackframe2が0になるようにする。★コンボの際はほかのフレームは関係ないので0にする。
						attackframe3 = 1;
						nextattack = 1;
						nagurukasanaru = 0;
						KONNBO1kasanaru = 0;
						KONNBO2kasanaru = 0;
					}


					if (sennkounyuuryokubunnki3 == 1) {
						++attackframe3;//ちゃんと値が上がっている、
						//attackframe2 = 0;//★↑の殴る2に引っ掛かり、殴る3を入力する際に殴る2もでないようにする。
						//attackframe3のフレーム内に右入力が成功すれば殴る3バージョンができる。
						attackframe2 = 0;//ここでのアタックフレーム2は殴る3には関係ないので0にする。
						//ここに問題はない。ここを消してもattackframe3が300に行く前に左の入力でattackframe3が0?になっていた。
						//これでOK。
					}

					if (migimuki == 1) {
						if (attackframe3 > 5 && attackframe3 < 100) {//attackframe3>0からにすると前の左にはじいた反動で右入力をしてしまい最初のフレームの範囲に反応することで、簡単にコンボが出来るので、左にはじいた反動では反応しない様に範囲をattackframe3>20からにした。これで入力が誤差もなく難しく出来た。
							if (Pad[PAD_LEFT] == 1) {
								++attackframe4;
							}
						}
						//if (attackframe5 > 0 && ++attackframe5 > 0) {
						if (attackframe4 > 10 && attackframe4 < 100) {
							if (Pad[PAD_RIGHT] == 1) {

								if (kougekiKANOU == 2) {//刀のコンボはやりにくいため、ここに範囲を持ってくるプログラムの方がいい。
									playerHPlock = 1;
									RIGHTmarklock = 1;
									//attackframe2 = 0;
									enemysabunHPB = 100;
									lockmark = 1;
									sinnzoubyouga = 1;
									//addattacktime = addattacktime + 100;
									//attackframe = 1;//追加の殴る攻撃ができるようにここで1に戻す。
									attackframe3 = 0;//追加の殴る攻撃ができるようにここで0に戻す。
									attackframe4 = 0;
									++attackframe5;
									kougekilock = 1;
									stayherelock3 = 1;//敵のHPを消すために必要な変数
									sennkounyuuryokubunnki3 = 0;//再び殴る2などをできるようにするためにここで0にする。
									naguru3sound = LoadSoundMem("damage03.m4a");
									PlaySoundMem(naguru3sound, DX_PLAYTYPE_BACK);
									//++attackframe4;
									//sennkounyuuryokubunnki = 0;//★追加の殴る攻撃ができるように。追加殴るに繋がると、再び殴る2や殴る3ができるため。
									playerattackhanndou = playerattackhanndou + 5;
									//ememydontmovetime = 1;
									//コンボ
									++conbocount;
									enemyzannzoulockframe1 = 1;//相手のダメージを食らった際の怯みを初期に戻すため
									stayhereframe = 1;
									nextattack = 0;
									enemysabunHPpoint = enemysabunHPpoint + 50;
									bloodMove = 1;
									StartJoypadVibration(DX_INPUT_PAD1, 2000, 150);
								}
							}
						}
					}
					else if (hidarimuki == 1) {
						if (attackframe3 > 5 && attackframe3 < 100) {//attackframe3>0からにすると前の左にはじいた反動で右入力をしてしまい最初のフレームの範囲に反応することで、簡単にコンボが出来るので、左にはじいた反動では反応しない様に範囲をattackframe3>20からにした。これで入力が誤差もなく難しく出来た。
							if (Pad[PAD_RIGHT] == 1) {
								++attackframe4;
							}
						}
						//if (attackframe5 > 0 && ++attackframe5 > 0) {
						//★左向きは少し押すまでを長めにした。
						if (attackframe4 > 10 && attackframe4 < 100) {
							if (Pad[PAD_LEFT] == 1) {
								if (kougekiKANOU == 2) {//刀のコンボはやりにくいため、ここに範囲を持ってくるプログラムの方がいい。
									playerHPlock = 1;
									RIGHTmarklock = 1;
									//attackframe2 = 0;
									enemysabunHPB = 100;
									lockmark = 1;
									sinnzoubyouga = 1;
									//addattacktime = addattacktime + 100;
									//attackframe = 1;//追加の殴る攻撃ができるようにここで1に戻す。
									attackframe3 = 0;//追加の殴る攻撃ができるようにここで0に戻す。
									attackframe4 = 0;
									++attackframe5;
									kougekilock = 1;
									stayherelock3 = 1;//敵のHPを消すために必要な変数
									sennkounyuuryokubunnki3 = 0;//再び殴る2などをできるようにするためにここで0にする。
									naguru3sound = LoadSoundMem("damage03.m4a");
									PlaySoundMem(naguru3sound, DX_PLAYTYPE_BACK);
									//++attackframe4;
									//sennkounyuuryokubunnki = 0;//★追加の殴る攻撃ができるように。追加殴るに繋がると、再び殴る2や殴る3ができるため。
									playerattackhanndou = playerattackhanndou - 5;
									//ememydontmovetime = 1;
									//コンボ
									++conbocount;
									enemyzannzoulockframe1 = 1;//相手のダメージを食らった際の怯みを初期に戻すため
									stayhereframe = 1;
									nextattack = 0;
									enemysabunHPpoint = enemysabunHPpoint + 50;
									bloodMove = 1;
								}
							}
						}
					}*/
					//}
					//敵2に対する右向きの刀攻撃。
					/*if (migimuki == 1) {
						if (attackframe3 > 5 && attackframe3 < 100) {//attackframe3>0からにすると前の左にはじいた反動で右入力をしてしまい最初のフレームの範囲に反応することで、簡単にコンボが出来るので、左にはじいた反動では反応しない様に範囲をattackframe3>20からにした。これで入力が誤差もなく難しく出来た。
							if (Pad[PAD_LEFT] == 1) {
								++attackframe4;
							}
						}
						//else if(attackframe3 > 20 && attackframe3 < 40 && kougekiKANOU == 3) {//attackframe3>0からにすると前の左にはじいた反動で右入力をしてしまい最初のフレームの範囲に反応することで、簡単にコンボが出来るので、左にはじいた反動では反応しない様に範囲をattackframe3>20からにした。これで入力が誤差もなく難しく出来た。
						//	if (Pad[PAD_LEFT] == 1) {
						//		++gardframe;
						//	}
						//}
						//if (attackframe5 > 0 && ++attackframe5 > 0) {
						if (attackframe4 > 50 && attackframe4 < 100) {
							if (Pad[PAD_RIGHT] == 1) {
								if (kougekiKANOU == 3) {//刀のコンボはやりにくいため、ここに範囲を持ってくるプログラムの方がいい。
									playerHPlock = 1;
									RIGHTmarklock = 1;
									//attackframe2 = 0;
									AenemysabunHPB = 100;
									lockmark = 1;
									sinnzoubyouga = 1;
									attackframe3 = 0;//追加の殴る攻撃ができるようにここで0に戻す。
									attackframe4 = 0;
									++attackframe5;
									kougekilock = 1;
									stayherelock3 = 1;//敵のHPを消すために必要な変数
									sennkounyuuryokubunnki3 = 0;//再び殴る2などをできるようにするためにここで0にする。
									naguru3sound = LoadSoundMem("damage03.m4a");
									PlaySoundMem(naguru3sound, DX_PLAYTYPE_BACK);
									//++attackframe4;
									sennkounyuuryokubunnki = 0;//★追加の殴る攻撃ができるように。追加殴るに繋がると、再び殴る2や殴る3ができるため。
									//ememydontmovetime = 1;
									playerattackhanndouB = playerattackhanndouB + 5;
									//コンボ
									++conbocount;
									enemyzannzoulockBframe = 1;//相手のダメージを食らった際の怯みを初期に戻すため
									stayhere2frame = 1;
									nextattack = 0;
									enemy2sabunHPpoint = enemy2sabunHPpoint + 50;//相手を吹っ飛ばすための物。
									bloodMove = 1;
								}
							}
						}
					}

					else if (hidarimuki == 1) {
						if (attackframe3 > 5 && attackframe3 < 100) {//attackframe3>0からにすると前の左にはじいた反動で右入力をしてしまい最初のフレームの範囲に反応することで、簡単にコンボが出来るので、左にはじいた反動では反応しない様に範囲をattackframe3>20からにした。これで入力が誤差もなく難しく出来た。
							if (Pad[PAD_RIGHT] == 1) {
								++attackframe4;
							}
						}
						//else if(attackframe3 > 20 && attackframe3 < 40 && kougekiKANOU == 3) {//attackframe3>0からにすると前の左にはじいた反動で右入力をしてしまい最初のフレームの範囲に反応することで、簡単にコンボが出来るので、左にはじいた反動では反応しない様に範囲をattackframe3>20からにした。これで入力が誤差もなく難しく出来た。
						//	if (Pad[PAD_LEFT] == 1) {
						//		++gardframe;
						//	}
						//}
						//if (attackframe5 > 0 && ++attackframe5 > 0) {
						if (attackframe4 > 30 && attackframe4 < 100) {
							if (Pad[PAD_LEFT] == 1) {
								if (kougekiKANOU == 3) {//刀のコンボはやりにくいため、ここに範囲を持ってくるプログラムの方がいい。
									playerHPlock = 1;
									RIGHTmarklock = 1;
									//attackframe2 = 0;
									AenemysabunHPB = 100;
									lockmark = 1;
									sinnzoubyouga = 1;
									attackframe3 = 0;//追加の殴る攻撃できるようにここで0に戻す。
									attackframe4 = 0;
									++attackframe5;
									kougekilock = 1;
									stayherelock3 = 1;//敵のHPを消すために必要な変数
									sennkounyuuryokubunnki3 = 0;//再び殴る2などをできるようにするためにここで0にする。
									naguru3sound = LoadSoundMem("damage03.m4a");
									PlaySoundMem(naguru3sound, DX_PLAYTYPE_BACK);
									//++attackframe4;
									sennkounyuuryokubunnki = 0;//★追加の殴る攻撃ができるように。追加殴るに繋がると、再び殴る2や殴る3ができるため。
									//ememydontmovetime = 1;
									playerattackhanndouB = playerattackhanndouB - 5;
									//コンボ
									++conbocount;
									enemyzannzoulockBframe = 1;//相手のダメージを食らった際の怯みを初期に戻すため
									stayhere2frame = 1;
									nextattack = 0;
									enemy2sabunHPpoint = enemy2sabunHPpoint + 50;
									bloodMove = 1;
								}
							}
						}
					}*/
					//}

						//if (gardframe > 0 && ++gardframe < 100 && kougekiKANOU == 3) {

						//}
						//if (gardframe > 100) {
						//	gardframe = 0;
						//}
				}

			}

		}





		//キックのコンボが出来なかった場合はすべて0に戻る。//以前はkougekiKANOUの値も条件に入れていたため、その条件の時でないと
		//sennkounyuuryokubunnkiが0にならず、1のままであったため、移動の先の「横」のコマンドによってキックが出てしまっていた。
		if (attackframe2 > 40) {
			sennkounyuuryokubunnki = 0;
			attackframe2 = 0;
			playerHPlock = 0;
			kougekiKANOU = 0;
			zannzoulock = 0;
			nextattack = 0;//キック後に再びキックできるように。
			kasurikeri = 0;//かすり判定でのキックもここで0にする。
		}
		if (attackframe2 > 0 && ++attackframe2 > 40 && kougekiKANOU == 0) {
			attackframe2 = 0;
		}
		if (attackframe3 > 60) {
			sennkounyuuryokubunnki3 = 0;
			attackframe3 = 0;
			zannzoulock = 0;
			playerHPlock = 0;
			kougekiKANOU = 0;
			nextattack = 0;//キック後に再びキックできるように。
		}
		if (attackframe3 > 0 && ++attackframe3 > 60 && kougekiKANOU == 0) {
			attackframe3 = 0;
		}
		if (attackframe4 > 110) {
			attackframe4 = 0;
			zannzoulock = 0;
			playerHPlock = 0;
			nextattack = 0;
			//playermovelock = 0;//念のために。//敵に攻撃された際に主人公の攻撃が止むように
			//attackframe4が50になるように書いたため、ここにきてしまい、スライド中なのにplayermovelockになり、通常移動動作がでてしまい、
			//マスに帰ってきた時にバグるので、ここには書かない。
		}//もしかしたらkougekiKANOUが0の時にフレームがあまり、誤発するかもしれないのでここで0の場合も書いて置く。
		if (attackframe4 > 0 && ++attackframe4 > 110 && kougekiKANOU == 0) {
			attackframe4 = 0;
			zannzoulock = 0;
		}
		if (attackframe5 > 50) {
			attackframe5 = 0;
			zannzoulock = 0;
			playerHPlock = 0;
		}
		if (attackframe5 > 0 && ++attackframe5 > 50 && kougekiKANOU == 0) {
			attackframe5 = 0;
		}

		//キックの誤発を防ぐための部分。
		if (motonomasunimodoru == 0) {
			if (attackframe2 > 0) {
				attackframe2 = 0;
				sennkounyuuryokubunnki = 0;
			}
		}







		//タバコ回復
		//押したままではずっと回復するので変数tabakokirikaeを入れる。
		if (motonomasunimodoru == 0) {//★刀攻撃と被るのでここで条件を付けた。
			if (tabakosuenai == 0) {
				if (tabakolock == 0 && lock == 0 && masusave == 0) {
					if (
						(PrevPadState & PAD_INPUT_1 && nextattack == 0) != 0  //前回は押されている
						&&  //且つ
						(CurrPadState & PAD_INPUT_1 && nextattack == 0) != 0  //今回は押されている
						)
					{
						tabakocount = 1;
						R1lock = 1;//爆弾コンボのために押して1にする。
						playermovelock2 = 1;
						playerHPlock = 1;
						nextattack = 1;

						//プレイヤーのHPがある一定の数値以下に成ったらダメージを受けた通常状態の画像に代わる。
						//if (playerHP < 400) {
						//	playerHPlock = 1;
						//}
						if (playerY == enemyY - 1 && playerX == enemyX) {
							kasanarulockA = 1;
							tabakosutterulock = 1;
						}
						if (playerY == enemyY + 1 && playerX == enemyX) {
							kasanarulockA = 2;

						}
					}

					//Bボタンを押した際に1に上がるので、そこからBボタンを離した際に通常描画にしたほうが移動中のzannzoulockに影響が少ないのでこれでいい。
					if (tabakocount > 0) {

						//playerHPlock = 0;
						if (
							(PrevPadState & PAD_INPUT_1) == 0  //前回は押されていない
							&&  //且つ
							(CurrPadState & PAD_INPUT_1) == 0  //今回は押されていない
							)
						{
							tabakocount = 0;
							tabakocount2 = 0;

							tabakokirikae = 0;
							zannzoulock = 0;//途中でボタンの入力が途切れたら主人公の画像が元に戻る。
							kasanarulock = 0;//敵と重なって途中で吸うのをやめても敵に上書きされないように。
							//tabakogazoulock = 0;//途中でボタンの入力が途切れてもタバコを吸う画像が描画されるように0にする。
							R1lock = 0;
							playerHPlock = 0;//if (tabakocount > 0)の時に、PAD_INPUT_1が押されていないときはずっと0にする。
							tabakosutterulock = 0;
							playermovelock2 = 0;
							nextattack = 0;
						}
					}
				}


				if (tabakocount > 0) {
					++tabakocount2;
					zannzoulock = 1;//攻撃画像がでてるときは通常の画像を消すので値を1に変更する。

				}
				if (tabakocount2 > 0 && tabakocount2 < 200) {
					playerHPlock = 1;
				}
				if (tabakocount2 == 1) {
					tabakosound = LoadSoundMem("Hit01-1.mp3");
					PlaySoundMem(tabakosound, DX_PLAYTYPE_BACK);
				}
				if (tabakocount2 > 200) {
					playerHP = playerHP + 50;
					tabakocount = 0;
					tabakocount2 = 0;
					tabakokirikae = 1;
					tabakokaihukumark = 1;
					zannzoulock = 0;
					kasanarulock = 0;
					tabakogazoulock = 0;
					playermovelock = 0;
					R1lock = 0;
					playerHPlock = 0;
					tabakosutterulock = 0;
					nextattack = 0;
				}

			}
		}
		//ここまでが主人公の攻撃のプログラム。




















		//敵が大ダメージを受けた際に敵が怯む期間を書いた部分。
		//if (ememydontmovetime == 1) {
		//	++ememydontmovetimeframe;
		//	stayhere = 1;
		//}
		//if (ememydontmovetimeframe > 500) {
		//	ememydontmovetime = 0;
		//	ememydontmovetimeframe = 0;
		//	stayhere = 0;
		//}

		//Rが一度押された上でフレームを利用してループさせるためにif文を新しく外に書いたのだ。
		//★敵の移動を書いた部分にpre2enemyX = enemyX;を付け足して、以前に書いた同じY座標にいる条件の時に前のX座標がpre2enemyXに入らないと書くと
		//主人公も動かない場合はその条件から抜けないため、以前と同じ座標のデータのままなのでif (enemyX != pre2enemyX)の条件を通らなかった。
		//なので★に書いたように同じY座標以外ではなく敵が移動すればX座標が更新されるように書けばenemyX != pre2enemyXの条件を通るので敵の移動を描いた部分にpre2enemyX = enemyX;を付け足した。
		//ちなみに、if (Pad[PAD_6] == 1の中に書いた際はPad[PAD_6] == 1は一瞬しか働かないので条件enemyX != pre2enemyXには一瞬しか通らないのでまるで条件が通っていない様に見えた。









		//差分の計算部分
		//キーAが押されたままでも一回しか押していない時と同じなので偽となり、関数を呼んでいる時はキーAは押されていないので前のif文が偽となり、if文の中の関数が働かない。なので外に書いた。
		/*if (enemysabunHP >= 0 && --enemysabunHP >= 0) {
			enemy1HP = enemy1HP - 1;
			//敵に攻撃を与えているときは敵は何もできない。
			ENEMYkougekigazouA1frame = 60;
			ENEMYkougekigazouA2frame = 70;
		}
		if (enemysabunHP < 0) {

			enemysabunHP = 0;
		}

		if (enemysabunHPA >= 0 && --enemysabunHPA >= 0) {
			enemy1HP = enemy1HP - 1;
			ENEMYkougekigazouA1frame = 60;
			ENEMYkougekigazouA2frame = 70;
		}
		if (enemysabunHPA < 0) {

			enemysabunHPA = 0;
		}

		if (KenemysabunHP >= 0 && --KenemysabunHP >= 0) {
			enemy1HP = enemy1HP - 1;
			ENEMYkougekigazouA1frame = 60;
			ENEMYkougekigazouA2frame = 70;
		}
		if (KenemysabunHP < 0) {

			KenemysabunHP = 0;
		}
		if (GenemysabunHP >= 0 && --GenemysabunHP >= 0) {
			enemy1HP = enemy1HP - 1;
			ENEMYkougekigazouA1frame = 60;
			ENEMYkougekigazouA2frame = 70;
		}
		if (GenemysabunHP < 0) {

			GenemysabunHP = 0;
		}
		if (enemysabunHPB >= 0 && --enemysabunHPB >= 0) {
			enemy1HP = enemy1HP - 1;
			ENEMYkougekigazouA1frame = 60;
			ENEMYkougekigazouA2frame = 70;
		}
		if (enemysabunHPB < 0) {

			enemysabunHPB = 0;
		}
		if (GenemysabunHPA >= 0 && --GenemysabunHPA >= 0) {
			enemy1HP = enemy1HP - 1;
			ENEMYkougekigazouA1frame = 60;
			ENEMYkougekigazouA2frame = 70;
		}
		if (GenemysabunHPA < 0) {

			GenemysabunHPA = 0;
		}*/
		//もう一人に敵に関してのダメージ

		//とりあえず、攻撃の最中も上がるようにif (addattacktime == 501){}の外にif文を出した。


		//キーLを押したまま別のキーを押すと武器が切り替わる



		//敵の攻撃や移動などの部分。
		/*if (stayhere == 0) {// 敵の移動
			int t = GetNowCount();
			//pre2enemyX = enemyX;//ここに書いたことで変数pre2enemyXに敵のX座標が入る。
			if (t >= nextMoveTime) { // 指定の時間が経ったら(1sごとに)
				nextMoveTime = t + MOVE_INTERVAL; // 次回移動処理をする時刻
				if (stopCount > 0) { // 停止中のとき
					stopCount--; // 止まっている残り時間(回数)を減らす
				}

				else { // 9マス上のいずれかのパネルに移動させる
					int cy = enemyY1, cx = enemyX1;
					do {
						enemyidou2 = GetRand(10);
						if (enemyidou2 > 2) {
							enemyY1 = GetRand(2);
							enemyX1 = GetRand(2) + 3;

							//移動したら元のマスに戻るようにする。
							playerattackhanndou = 0;
							playerattackhanndou2 = 0;
							playerattackhanndou3 = 0;
							enemyKENJYUUcount = 0;
							//kericount = 0;
							//yokkerucouunt = 0;
						}
						//その場に止まる確率
						if (GetRand(10) < 5) { // たまに(70%の確率で)
							stopCount = GetRand(1); // 数秒間(0秒間)その場に止まる
						}
						//敵の移動先に主人公がいた場合は再度移動先を選ぶようにさせる。
						if (cy == playerY && cx == playerX) {
							enemyY1 = GetRand(2);
							enemyX1 = GetRand(2) + 3;
						}
						//二人の敵がある一定の楯列にしか並ばないようにするための部分。
						//なぜかY座標が同じ座標の時はフリーズするのでここで同じ座標にならないようにする。
						else if (pos[enemyY1][enemyX1][1] == pos[enemyY2][enemyX2][1]) {
							enemyY1 = GetRand(2);
							enemyX1 = GetRand(2) + 3;
							enemyY2 = GetRand(2);
							enemyX2 = GetRand(2) + 3;
						}


					} while (enemyX1 == cx && enemyY1 == cy ||
						enemyX1 == playerX && enemyY1 == playerY);

					//enemyImage = enemyGHandle[10];

				}



				//敵1の攻撃
				if (ranndamulock == 0) {
					ranndamukougeki = GetRand(10);//★確率の間隔が小さいと敵描画されないバグが起きるので小手でいい。

				}
				//右からの殴る攻撃
				if (ranndamukougeki == 1 or ranndamukougeki == 3) {//GetRand(30) < 30とすると攻撃する途中でやめたり、カウンタが2を超えて上がってしまったりする。
					ranndamulock = 1;//範囲が重なるときだけ主人公と敵の位置が変わるようにした。を無効にするために1にした。
					++enemyattack;
					enemyzannzoulock = 1;
					ENEMYkougekigazouA2frame = 0;//★ここでランダムのif文により0に戻ることで30のままだった
					//初めての敵の攻撃もランダムで0になってもif文により値が上がるので問題なく敵は攻撃できる。

					//青い敵が攻撃する時は赤い敵の攻撃を止めておく。
					stayhere2 = 1;
					if (enemyattack > 0 && enemyattack < 2) {//if (enemyattack == 1)は別にいらない。
						preenemyX = pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 100;
						preenemyY = pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5;
						++enemycount;
						ENEMYkougekigazouA1 = 1;
						kasanarulock = 1;//★重なる画像に関してのプログラムにより通常状態の敵が描画されないように、ここで値を1にする。
						enemyattack = 0;
					}
				}
				//左からの殴る攻撃
				else if (ranndamukougeki == 2 or ranndamukougeki == 4) {//GetRand(30) < 30とすると攻撃する途中でやめたり、カウンタが2を超えて上がってしまったりする。
					ranndamulock = 1;//範囲が重なるときだけ主人公と敵の位置が変わるようにした。を無効にするために1にした。
					++enemyattack;
					enemyzannzoulock = 1;
					ENEMYkougekigazouA2frame = 0;//★ここでランダムのif文により0に戻ることで30のままだった
					//初めての敵の攻撃もランダムで0になってもif文により値が上がるので問題なく敵は攻撃できる。

					//青い敵が攻撃する時は赤い敵の攻撃を止めておく。
					stayhere2 = 1;
					if (enemyattack > 0 && enemyattack < 2) {//if (enemyattack == 1)は別にいらない。
						preenemyX = pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 100;
						preenemyY = pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5;
						++enemycount;
						ENEMYkougekigazouA1 = 1;
						kasanarulock = 1;//★重なる画像に関してのプログラムにより通常状態の敵が描画されないように、ここで値を1にする。
						enemyattack = 0;
					}
				}
				//敵1の銃攻撃
				else if (ranndamukougeki == 3) {
					if (stage[0][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
						stage[0][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
						stage[1][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
						stage[1][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
						stage[0][0][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
						stage[1][0][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
						stage[0][6][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
						stage[1][6][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65
						//or stage[0][6][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + 65
						) {
						ranndamulock = 1;
						ranndamukougeki3 = 1;
						if (ranndamukougeki3 == 1) {
							enemy1HPhyouji = 0;
							enemyzannzoulock = 1;
							++enemyKENJYUUcount;
							ranndamulock = 1;
							a = 3;
							//青い敵が攻撃する時は赤い敵の攻撃を止めておく。
							stayhere2 = 1;
							// ここで３秒まつ
							//WaitTimer(50);
						}
					}
				}
				else if (ranndamukougeki == 4) {
					if (stage[1][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
						stage[1][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
						stage[2][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
						stage[2][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
						stage[1][0][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
						stage[2][0][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
						stage[1][6][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
						stage[2][6][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65
						&& ranndamulock == 0
						) {
						ranndamulock = 1;
						ranndamukougeki4 = 1;
						if (ranndamukougeki4 == 1) {

							enemy1HPhyouji = 0;
							enemyzannzoulock = 1;
							++enemyKENJYUUcount;
							ranndamulock = 1;
							a = 6;
							//青い敵が攻撃する時は赤い敵の攻撃を止めておく。
							stayhere2 = 1;
							// ここで３秒まつ
							//WaitTimer(50);
						}
					}
				}
				else if (ranndamukougeki == 5) {
					if (stage[2][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
						stage[2][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
						stage[3][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
						stage[3][6][0]> pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 25 &&
						stage[2][0][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&//①
						stage[3][0][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&//②
						stage[2][6][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&
						stage[3][6][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65//ここを消しても一部分が変化しない奴は出来る。
						&& ranndamulock == 0
						) {
						ranndamulock = 1;
						ranndamukougeki5 = 1;
						if (ranndamukougeki5 == 1) {

							enemy1HPhyouji = 0;
							enemyzannzoulock = 1;
							++enemyKENJYUUcount;
							ranndamulock = 1;
							a = 9;
							//青い敵が攻撃する時は赤い敵の攻撃を止めておく。
							stayhere2 = 1;
							// ここで３秒まつ
							//WaitTimer(50);
						}
					}
				}










				if (ENEMYkougekigazouA1 == 1) {
					ENEMYkougekigazouA1frame = 1;
					//ENEMYkougekigazouA1lock = 1;
					pos[enemyY1][enemyX1][0] = preenemyX;
					pos[enemyY1][enemyX1][1] = preenemyY;
					enemyattack = 0;
					ENEMYkougekigazouA1lock = 1;
					//LEFTmark = 100;

				}

			}

			//中に書くにしてもif (enemycount == 0)の場合を書かなかったら敵が目の前に来た、0の場合の処理を書いた方がいいようだ。攻撃以外は目の前に来るようなコードは書いていないが。
			//まあ、「0の時の場合を書いていないので不自然な動きが起きてしまった」ということも考えられる。
			//if (frames < 500) { frames = 0; }


		}*/


		/*//敵の攻撃や移動などの部分。
			if (stayhere2 == 0) {// 敵の移動
				int t = GetNowCount();
				//pre2enemyX = enemyX;//ここに書いたことで変数pre2enemyXに敵のX座標が入る。
				if (t >= nextMoveTime2) { // 指定の時間が経ったら(1sごとに)
					nextMoveTime2 = t + MOVE_INTERVAL2; // 次回移動処理をする時刻
					if (stopCount2 > 0) { // 停止中のとき
						stopCount2--; // 止まっている残り時間(回数)を減らす
					}

					else { // 9マス上のいずれかのパネルに移動させる
						int cy = enemyY2, cx = enemyX2;
						do {
							enemyidou3 = GetRand(10);//enemyidou3が5より大きい時に移動する。
							if (enemyidou3 > 5) {
								enemyY2 = GetRand(2);
								enemyX2 = GetRand(2) + 3;
								//移動したら元のマスに戻るようにする。
								//DAMEGE = 0;
								playerattackhanndouB = 0;
								playerattackhanndou2B = 0;
								playerattackhanndou3B = 0;
								playerkonntororulock3 = 0;
								playerkonntororulock = 0;
								playerkonntororulock2 = 0;
								//kericount = 0;
								//yokkerucouunt = 0;
							}
							//その場に止まる確率
							if (GetRand(10) < 8) { // たまに(70%の確率で)
								stopCount2 = GetRand(6); // 数秒間(0秒間)その場に止まる
							}
							//敵の移動先に主人公がいた場合は再度移動先を選ぶようにさせる。
							if (cy == playerY && cx == playerX) {

								enemyY2 = GetRand(2);
								enemyX2 = GetRand(2) + 3;
							}
							//二人の敵がある一定の楯列にしか並ばないようにするための部分。
							else if (pos[enemyY1][enemyX1][1] == pos[enemyY2][enemyX2][1]) {
								enemyY1 = GetRand(2);
								enemyX1 = GetRand(2) + 3;
								enemyY2 = GetRand(2);
								enemyX2 = GetRand(2) + 3;
							}



						} while (enemyX1 == cx && enemyY1 == cy ||
							enemyX1 == playerX && enemyY1 == playerY);

						//enemyImage = enemyGHandle[10];

					}


					//敵2の攻撃
					//★二つ目の確率の変動は遅いため、攻撃が終わった後も通常状態に重なった攻撃画像が出てきてしまう。
						//なので、確率の変動の早いもう一人の敵の攻撃している最中はif (stayhere == 0 && stayhere2 == 0)
						//により確率が動いてももう一人に影響が出ないようにして、もう一人の攻撃が終わった後くらいに
						//もう一人の確率が変わっているくらいの程度なので攻撃画像が重なることはない。
						//仮にもう一人が連続攻撃してきても、もう一人の敵が攻撃してこない間はif (stayhere == 0 && stayhere2 == 0)
						//によりここを通ることはないため攻撃画像が重なることはない。
					if (ranndamulock2 == 0) {
						ranndamukougeki2 = GetRand(2);

					}
					//敵2が同時攻撃だとフリーズすることがあるので、敵2も敵1と同じ確率の関数を共有する。
					if (ranndamukougeki2 == 2) {//GetRand(30) < 30とすると攻撃する途中でやめたり、カウンタが2を超えて上がってしまったりする。
						ranndamulock2 = 1;//範囲が重なるときだけ主人公と敵の位置が変わるようにした。を無効にするために1にした。
						++enemyattackB;
						anotherenemyzannzoulock = 1;
						//kaburulock = 1;//相手が目の前にいても踏み込めるように。
						//randamulock = 1;//近距離攻撃中は投げ攻撃をしないように値を1にする。
						ENEMYkougekigazouB2frame = 0;//★ここでランダムのif文により0に戻ることで30のままだった
						//tekinoKOUGEKITYUUhahyouzisinailock = 1;//敵の攻撃中は重なるプログラムを無効にする。
						//enemygazoukesu = 1; //if (playerHPlock == 0 && playerHP <= 200)での敵の画像を一時的に消す。
						//ENEMYkougekigazouA2frameが0に戻り、途中で攻撃が止まることはなくなった。
						//他の解決法としてはif (ENEMYkougekigazouA1lock == 1 &&ENEMYkougekigazouA1frame == 0)
						//の部分で++ENEMYkougekigazouA2frameではなくENEMYkougekigazouA2frame=と固定にすればいいが
						//新しい変数が増えてめんどくさくなるので++として、ここのランダム変数により0にすることで解決した。
						//初めての敵の攻撃もランダムで0になってもif文により値が上がるので問題なく敵は攻撃できる。

						//赤い敵が攻撃する時は青い敵の攻撃を止めておく。
						stayhere = 1;
						if (enemyattackB > 0 && enemyattackB < 2) {//if (enemyattack == 1)は別にいらない。
							preenemyX2 = pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + +nanameidouX4 + nanameidouX5 + 100;
							preenemyY2 = pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5;
							++enemycount;
							ENEMYkougekigazouB1 = 1;

							kasanarulock = 1;//★重なる画像に関してのプログラムにより通常状態の敵が描画されないように、ここで値を1にする。
							enemyattackB = 0;
						}
					}



					if (ENEMYkougekigazouB1 == 1) {
						ENEMYkougekigazouB1frame = 1;
						//ENEMYkougekigazouA1lock = 1;
						pos[enemyY2][enemyX2][0] = preenemyX2;
						pos[enemyY2][enemyX2][1] = preenemyY2;
						enemyattackB = 0;

						//LEFTmark = 739;
					}
				}
			}
			*/
			//中に書くにしてもif (enemycount == 0)の場合を書かなかったら敵が目の前に来た、0の場合の処理を書いた方がいいようだ。攻撃以外は目の前に来るようなコードは書いていないが。
			//まあ、「0の時の場合を書いていないので不自然な動きが起きてしまった」ということも考えられる。
			//if (frames < 500) { frames = 0; }




		//ループ内に書いたenemyMoveについてenemyMoveが0より大きくて40を超えたら｛｝の中身を実行。
		//enemyMoveが0より大きいならば+1されて、40より大きい数値になれば両方の条件を満たすので+１される。40より大きい数値になったら敵の画像が変わる。
		//enemyMoveが40より+１されて大きくなるために++enemyMove > 40




//差分の計算部分
		//キーAが押されたままでも一回しか押していない時と同じなので偽となり、関数を呼んでいる時はキーAは押されていないので前のif文が偽となり、if文の中の関数が働かない。なので外に書いた。

//stgae2Player_Update.hにこいつを書いたらラグで攻撃判定が少しずれるのですぐ下にダメージを受けた時の画像が出るここに書いた
		if (enemysabunHP >= 0 && --enemysabunHP >= 0) {
			enemy1HP = enemy1HP - 1;
			//敵に攻撃を与えているときは敵は何もできない。
			ENEMYkougekigazouA1frame = 60;
			ENEMYkougekigazouA2frame = 70;
		}
		if (enemysabunHP < 0) {

			enemysabunHP = 0;
		}

		if (enemysabunHPA >= 0 && --enemysabunHPA >= 0) {
			enemy1HP = enemy1HP - 1;
			ENEMYkougekigazouA1frame = 60;
			ENEMYkougekigazouA2frame = 70;
		}
		if (enemysabunHPA < 0) {

			enemysabunHPA = 0;
		}

		if (KenemysabunHP >= 0 && --KenemysabunHP >= 0) {
			enemy1HP = enemy1HP - 1;
			ENEMYkougekigazouA1frame = 60;
			ENEMYkougekigazouA2frame = 70;
		}
		if (KenemysabunHP < 0) {

			KenemysabunHP = 0;
		}
		if (GenemysabunHP >= 0 && --GenemysabunHP >= 0) {
			enemy1HP = enemy1HP - 1;
			ENEMYkougekigazouA1frame = 60;
			ENEMYkougekigazouA2frame = 70;
		}
		if (GenemysabunHP < 0) {

			GenemysabunHP = 0;
		}
		if (enemysabunHPB >= 0 && --enemysabunHPB >= 0) {
			enemy1HP = enemy1HP - 1;
			ENEMYkougekigazouA1frame = 60;
			ENEMYkougekigazouA2frame = 70;
		}
		if (enemysabunHPB < 0) {

			enemysabunHPB = 0;
		}
		if (GenemysabunHPA >= 0 && --GenemysabunHPA >= 0) {
			enemy1HP = enemy1HP - 1;
			ENEMYkougekigazouA1frame = 60;
			ENEMYkougekigazouA2frame = 70;
		}
		if (GenemysabunHPA < 0) {

			GenemysabunHPA = 0;
		}


		//もう一人に敵に関してのダメージ
		if (anotherenemysabunHP >= 0 && --anotherenemysabunHP >= 0) {
			enemy2HP = enemy2HP - 1;

		}
		if (anotherenemysabunHP < 0) {

			anotherenemysabunHP = 0;
		}
		if (anotherenemysabunHPA >= 0 && --anotherenemysabunHPA >= 0) {
			enemy2HP = enemy2HP - 1;

		}
		if (anotherenemysabunHPA < 0) {

			anotherenemysabunHPA = 0;
		}

		if (AKenemysabunHP >= 0 && --AKenemysabunHP >= 0) {
			enemy2HP = enemy2HP - 1;

		}
		if (AKenemysabunHP < 0) {

			AKenemysabunHP = 0;
		}
		if (AGenemysabunHP >= 0 && --AGenemysabunHP >= 0) {
			enemy2HP = enemy2HP - 1;

		}
		if (AGenemysabunHP < 0) {

			AGenemysabunHP = 0;
		}
		if (AenemysabunHPB >= 0 && --AenemysabunHPB >= 0) {
			enemy2HP = enemy2HP - 1;

		}
		if (AenemysabunHPB < 0) {

			AenemysabunHPB = 0;
		}
		if (AGenemysabunHPA >= 0 && --AGenemysabunHPA >= 0) {
			enemy2HP = enemy2HP - 1;

		}
		if (AGenemysabunHPA < 0) {

			AGenemysabunHPA = 0;
		}






		if (enemysabunHP > 0 or enemysabunHPA > 0 or KenemysabunHP > 0 or enemysabunHPB > 0 or GenemysabunHP > 0 or GenemysabunHPA > 0) {
			//LEFTmark = 1;
			++enemyzannzoulockframe1;

			point = 191919;
			stayhere = 1;
			++stayhereframe;
			//敵の攻撃をやめさせる。
			a = 0;
			enemyKENJYUUcount = 0;
			ranndamukougeki = 0;
			ranndamukougeki3 = 0;
			ranndamukougeki4 = 0;
			ranndamukougeki5 = 0;

			ENEMYkougekigazouA1frame = 0;//★ENEMYkougekigazouA1frame = 60;でもよい。どうせ範囲外の数値を維持していればいいだけなので。
			ENEMYkougekigazouA2frame = 0;//★ENEMYkougekigazouA2frame = 70;でもよい。どうせ範囲外の数値を維持していればいいだけなので。
			//敵の攻撃画像を描画するための変数を止めるために1にした。
			//enemyzannzoulock2 = 1;
			//byougajyunnbann = 1;

		}


		//★攻撃を食らわないようにするためのカウンターの部分。
		if (DAMEGE == 1) {
			++DAMEGEframe;
		}
		if (DAMEGEframe > 300) {
			DAMEGEframe = 0;
			playerHPsubun = 0;
			DAMEGE = 0;//重要★ここで攻撃をカウンターしても0になるので、再び攻撃をしても攻撃を食らう。
		}
		//コンティニューしてから敵が動くまでの期間のための部分。
		//★強制的にstayhereを1にすると死んだ直前で敵からの攻撃が止まったままになってしまい連続で攻撃を食らうような状態になってしまう。
		//なのでstayhereは消す。

		//これより以下は描画するためのプログラム
		//ClearDrawScreen();  // 裏画面を



		//差分での奴は他の差分が0の時に他の攻撃で再び差分が上がるので攻撃を食らいながらも違う画像で攻撃になるのでこっちの書き方にした。
		if (enemyzannzoulockframe1 > 0 && ++enemyzannzoulockframe1 < 150) {//100くらいがちょうどいい、50だと
			//enemyKENJYUUcount = 0;
			point = 191919;
			enemyzannzoulock2 = 1;//★「通常状態」のダメージを食らった際の半透明について
			//★敵の画像を一時的に消す。これでダメージを食らったっぽくなる。
			//ここで敵が一瞬消えてif (enemyzannzoulockframe > 25) で0になるので、以前に書いた敵の通常状態の画像が半透明になる。
			//KABURI = 1;
			//★主人公の攻撃中も敵の攻撃中が攻撃した際に敵の攻撃が描画されるようにここに書いた。
			if (enemyzannzoulockframe1 > 0 && enemyzannzoulockframe1 < 5) {
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 0, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, enemy2damegeHandle[0], TRUE);
			}
			if (enemyzannzoulockframe1 > 10 && enemyzannzoulockframe1 < 15) {
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 0, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, enemy2damegeHandle[0], TRUE);
			}
			if (enemyzannzoulockframe1 > 20 && enemyzannzoulockframe1 < 25) {
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 0, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, enemy2damegeHandle[0], TRUE);
			}
			if (enemyzannzoulockframe1 > 30 && enemyzannzoulockframe1 < 35) {
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 0, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, enemy2damegeHandle[0], TRUE);
			}
			if (enemyzannzoulockframe1 > 40 && enemyzannzoulockframe1 < 45) {
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 0, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, enemy2damegeHandle[0], TRUE);
				enemyzannzoulockframe1 = 1;
			}

		}
		if (stayhereframe > 0 && ++stayhereframe > 150) {
			stayhereframe = 0;
			ranndamulock = 0;//再び物理攻撃できるように0にする。
			enemyzannzoulockframe1 = 0;
			stayhere = 0;//★敵が死んだ後にここで0になってしまうので、上でenemybyougablockが0の時のみ0になるようにした。
			//また敵1が死んだ後はstayhereが1になり初期位置に反応してしまうためenemybyougablockが必要。敵が一体だけならenemybyougablock
			//は必要ないが、二体いるため、一体が死んだあとにどっちかの敵が再び描画されないようにenemybyougablockは必要なのだ。
			enemyzannzoulock2 = 0;
			//byougajyunnbann = 0;

		}


		//敵2の「通常状態」と「攻撃中」に対する攻撃を食らったときの半透明になる部分。
			//else if (kougekiKANOU == 4 or kougekiKANOU == 3 or kougekiKANOU == 20) {//攻撃中は攻撃の方の画像が描画されるようにする。
		if (anotherenemysabunHP > 0 or anotherenemysabunHPA > 0 or AKenemysabunHP > 0 or AGenemysabunHP > 0 or AenemysabunHPB > 0 or AGenemysabunHPA > 0) {
			//LEFTmark = 808080;
			++enemyzannzoulockBframe;
			anotherenemyzannzoulock = 1;
			//enemystayhere = 1;
			stayhere2 = 1;
			++stayhere2frame;
		}
		//差分での奴は他の差分が0の時に他の攻撃で再び差分が上がるので攻撃を食らいながらも違う画像で攻撃になるのでこっちの書き方にした。
		if (enemyzannzoulockBframe > 0 && ++enemyzannzoulockBframe < 150) {//100くらいがちょうどいい、50だと
			//★敵の画像を一時的に消す。これでダメージを食らったっぽくなる。
			if (enemyzannzoulockBframe > 0 && enemyzannzoulockBframe < 5) {
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 0, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, enemy3damegeHandle[0], TRUE);
			}
			if (enemyzannzoulockBframe > 10 && enemyzannzoulockBframe < 15) {
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 0, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, enemy3damegeHandle[0], TRUE);
			}
			if (enemyzannzoulockBframe > 20 && enemyzannzoulockBframe < 25) {
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 0, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, enemy3damegeHandle[0], TRUE);
			}
			if (enemyzannzoulockBframe > 30 && enemyzannzoulockBframe < 35) {
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 0, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, enemy3damegeHandle[0], TRUE);
			}
			if (enemyzannzoulockBframe > 40 && enemyzannzoulockBframe < 45) {
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 0, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, enemy3damegeHandle[0], TRUE);
				enemyzannzoulockBframe = 1;
			}
		}

		if (stayhere2frame > 0 && ++stayhere2frame > 150 && enemybyougablock2 == 0) {
			stayhere2frame = 0;
			stayhere2 = 0;
			ranndamulock2 = 0;//再び物理攻撃できるように0にする。
			enemyzannzoulockBframe = 0;
			anotherenemyzannzoulock = 0;
		}



		if (enemysabunHP >= enemy1HP && stayherelock == 1 || KenemysabunHP >= enemy1HP && stayherelock == 1 || GenemysabunHP >= enemy1HP && stayherelock == 1 || enemysabunHPA >= enemy1HP && stayherelock == 1 || enemysabunHPB >= enemy1HP && stayherelock == 1) {

			enemy1HPhyouji = 0; //敵のHPの表記を消す
			//stayhere = 1;//攻撃をやめる、また初期位置と被らないために1ではなく、2とした。
			stayherelock = 1;//0のままだと初期位置の敵の画像が出てしまうので、ここで1にする。
			enemy1HP = 0;
			ENEMYkougekigazouA1lock = 0;//敵が攻撃する際に値が繰り上がったままだと敵の攻撃が描画されるので、ここで0にする。
			//ENEMYkougekigazouA2frame = 0;
			enemystayhere = 1;//敵を描画しないために値を1にした。またif (enemystayhere > 1 && enemystayhere < 50) の条件に引っ掛かり固定した敵が出てこない様にenemystayhere > 1と変更した。
			a = 0;
			ranndamulock = 1;
			ranndamukougeki = 0;
		}
		else if (enemy1HP == 0 && stayherelock == 1) {//★敵のHPと攻撃が同じ数値の時は＞の条件に入っていなかったのでここで付け足した。それにより同じ値の時でも相手のHPが消えるようにできた
			//enemyzannzoulock = 1;
			//sousakanou = 1;//★この変数のおかげで敵を倒した後に主人公は消えずに描画される。									 
			//playerkonntororulock = 1;//敵を倒した後は操作できないように1にする。
			enemy1HPhyouji = 0; //敵のHPの表記を消す
			//stayhere = 1;//攻撃をやめる
			stayherelock = 1;//0のままだと初期位置の敵の画像が出てしまうので、ここで1にする。
			//mark = 0;
			enemy1HP = 0;
			enemystayhere = 1;//敵を描画しないために値を1にした。またif (enemystayhere > 1 && enemystayhere < 50) の条件に引っ掛かり固定した敵が出てこない様にenemystayhere > 1と変更した。
			//敵を倒した際に敵が徐々に消えていく原理について。//
			ENEMYkougekigazouA1lock = 0;
			//ENEMYkougekigazouA2frame = 0;
			a = 0;
			ranndamulock = 1;
			ranndamukougeki = 0;
		}

		//敵1がやられた際にHPが消えて、敵の動きが止まるように書いた。
		/*if (enemysabunHP >= enemy1HP && stayherelock == 1 || KenemysabunHP >= enemy1HP && stayherelock == 1 || GenemysabunHP >= enemy1HP && stayherelock == 1 || enemysabunHPA >= enemy1HP && stayherelock == 1 || enemysabunHPB >= enemy1HP && stayherelock == 1) {

			enemy1HPhyouji = 0; //敵のHPの表記を消す
			//stayhere = 1;//攻撃をやめる、また初期位置と被らないために1ではなく、2とした。
			stayherelock = 1;//0のままだと初期位置の敵の画像が出てしまうので、ここで1にする。
			enemy1HP = 0;
			ENEMYkougekigazouA1lock = 0;//敵が攻撃する際に値が繰り上がったままだと敵の攻撃が描画されるので、ここで0にする。
			//ENEMYkougekigazouA2frame = 0;
			enemystayhere = 1;//敵を描画しないために値を1にした。またif (enemystayhere > 1 && enemystayhere < 50) の条件に引っ掛かり固定した敵が出てこない様にenemystayhere > 1と変更した。
			a = 0;
			ranndamulock = 1;
			ranndamukougeki = 0;
		}
		else if (enemy1HP == 0 && stayherelock == 1) {//★敵のHPと攻撃が同じ数値の時は＞の条件に入っていなかったのでここで付け足した。それにより同じ値の時でも相手のHPが消えるようにできた
			//enemyzannzoulock = 1;
			//sousakanou = 1;//★この変数のおかげで敵を倒した後に主人公は消えずに描画される。
			//playerkonntororulock = 1;//敵を倒した後は操作できないように1にする。
			enemy1HPhyouji = 0; //敵のHPの表記を消す
			//stayhere = 1;//攻撃をやめる
			stayherelock = 1;//0のままだと初期位置の敵の画像が出てしまうので、ここで1にする。
			//mark = 0;
			enemy1HP = 0;
			enemystayhere = 1;//敵を描画しないために値を1にした。またif (enemystayhere > 1 && enemystayhere < 50) の条件に引っ掛かり固定した敵が出てこない様にenemystayhere > 1と変更した。
			//敵を倒した際に敵が徐々に消えていく原理について。//
			ENEMYkougekigazouA1lock = 0;
			//ENEMYkougekigazouA2frame = 0;
			a = 0;
			ranndamulock = 1;
			ranndamukougeki = 0;
		}*/

		//敵2がやられた際にHPが消えて、敵の動きが止まるように書いた。
		if (anotherenemysabunHP >= enemy2HP || AKenemysabunHP >= enemy2HP || AGenemysabunHP >= enemy2HP || anotherenemysabunHPA >= enemy2HP || AenemysabunHPB >= enemy2HP) {
			//playerkonntororulock = 1;//敵を倒した後は操作できないように1にする。
			//enemyzannzoulock = 1;
			//sousakanou = 1;//★この変数のおかげで敵を倒した後に主人公は消えずに描画される。
			//overattacklock = 1;
			//playerkonntororulock = 0;//敵を倒したら攻撃できないようにするための変数。
			enemy2HPhyouji = 0; //敵のHPの表記を消す
			//stayhere2 = 1;//攻撃をやめる、また初期位置と被らないために1ではなく、2とした。
			//stayherelock = 1;//0のままだと初期位置の敵の画像が出てしまうので、ここで1にする。
			//mark = 0;//★しかし、ダメージが多いとフレーム処理が長いため敵が1で消えるがtest2.cppで再び現れて消えるため、あまりいい消え方ではない
			//なのでenemystayhere = 1ではなく、markを1として、すぐにtest2.cppに移動して、消えるようにした。消えた後でenemystayhereを一とした。
			enemy2HP = 0;
			ENEMYkougekigazouB1lock = 0;//敵が攻撃する際に値が繰り上がったままだと敵の攻撃が描画されるので、ここで0にする。
			//ENEMYkougekigazouA2frame = 0;
			//enemystayhere = 1;//敵を描画しないために値を1にした。またif (enemystayhere > 1 && enemystayhere < 50) の条件に引っ掛かり固定した敵が出てこない様にenemystayhere > 1と変更した。
			//敵を倒した際に敵が徐々に消えていく原理について。//
			//kougekilock = 0;//攻撃のフレームの問題でフレームの上がっている間はkougekilockは0にならないため、敵が消えるのに一瞬描画されたりと変な感じになるので0にした。

			ranndamulock2 = 1;
			ranndamukougeki2 = 0;
		}
		else if (enemy2HP == 0 && stayherelock2 == 1) {//★敵のHPと攻撃が同じ数値の時は＞の条件に入っていなかったのでここで付け足した。それにより同じ値の時でも相手のHPが消えるようにできた
			//enemyzannzoulock = 1;
			//sousakanou = 1;//★この変数のおかげで敵を倒した後に主人公は消えずに描画される。									 
			//playerkonntororulock = 1;//敵を倒した後は操作できないように1にする。
			enemy2HPhyouji = 0; //敵のHPの表記を消す
			//stayhere2 = 1;//攻撃をやめる
			stayherelock2 = 1;//0のままだと初期位置の敵の画像が出てしまうので、ここで1にする。
			//mark = 0;
			enemy2HP = 0;
			//enemystayhere = 1;//敵を描画しないために値を1にした。またif (enemystayhere > 1 && enemystayhere < 50) の条件に引っ掛かり固定した敵が出てこない様にenemystayhere > 1と変更した。
			//敵を倒した際に敵が徐々に消えていく原理について。//
			ENEMYkougekigazouB1lock = 0;
			//ENEMYkougekigazouA2frame = 0;

			ranndamulock2 = 1;
			ranndamukougeki2 = 0;
		}
	}



	if (rockon == 0) {

		//ロックマーク
		if (lockonMove == 10) {
			lockImge = lockonHandle[0];//情報lockonMove == 10やlockonHandle[0]を引き継いで下に書いた描画関数に入るため、ここには関数に入れる情報だけ入るのだ。
			//その時の情報lockonMove == 10やlockonHandle[0]以外の引き継がれたとうかその時の敵の座標なども関数に入る。関数が求めるものが入るので、関数に必要なものを揃える。
		}
		else if (lockonMove == 20) {
			lockImge = lockonHandle[1];

		}
		else if (lockonMove == 30) {
			lockImge = lockonHandle[2];


		}
		else if (lockonMove == 40) {
			lockImge = lockonHandle[1];
			lockonMove = 1;
		}



		if (lock == 1) {
			if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_RIGHT) == 0) { //キーを入力する以外にも押した後に早く画像を切り替えて足踏みするようにするために初期値にも1はあるがキーにもplayerMove=1を書いたり、キーを押したらどうしたいかをするためにplayerX++を書いている。
				lockmarkyokoidou = lockmarkyokoidou + 4;

			} //playerMove = 1;があると下に書いたplayerMoveより足踏みするplayerMoveが無いと初期値の1でそのまま足踏みするので遅く反応するのでは？
			if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_LEFT) == 0) {//キーにplayerMove=1を書くと初期値の1よりも早くキーに書いたplayerMoveの1が行くため早く足踏みに行くため、止まってから足踏みに行くまでの間にある向きを変える画像playerGHandle[2]が一瞬であるため、向きを変えるのが早く見えるのでは？足踏みを速く来るようにしたため。
				lockmarkyokoidou = lockmarkyokoidou - 4;
			}
			if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_UP) == 0) {
				lockmarktateidou = lockmarktateidou - 3;
			}
			if ((GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_DOWN) == 0) {
				lockmarktateidou = lockmarktateidou + 3;
			}
			//LEFTmark = 19;

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

	//#endif
	//if (kasokudo = 49) { A = 4; }
	//if (function_status == 0) {//function_status = 0の時はメニュー画面でfunction_statusが1の時は戦闘画面とした。
	//



	//#ifndef DEF_ PLAYER_UPDATE2_H //二重include防止

	//#define DEF_ PLAYER_UPDATE2_H



}



#endif
