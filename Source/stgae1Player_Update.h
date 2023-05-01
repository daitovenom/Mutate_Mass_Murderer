#include "DxLib.h"
#include "key.h"
#include "Player/playerhensuuVr2.h"
#include "talk.h"
#include "taitol.h"	// !! taitolh.hをtaitol.hに変更しました
#include "stage1Player_Draw.h"




void Player_Update() {
	//gpUpdateKey();  // キーの入力状態を取得
	//arukukannsuu();
	//★コンティニューしても途中からBGMが再生するように戦闘内にstart == 2の時のに残ったsound3と同じ関数を入れて、PlaySoundMemの第三引数をFALSEとした。
	if (playerHP > 0) {
		ChangeVolumeSoundMem(150, sound3);//この関数によって音声のボリュームを設定できる。
		PlaySoundMem(sound3, DX_PLAYTYPE_LOOP, FALSE);
	}
	//playerMove = 1;
	//説得中は戦闘中のキーが押せないようにするためのロックを設けた。
	if (playerkonntororulock == 0) {


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
				//斜め押しをした際に斜めではなく右に進むようにする。
					playerkonntororulock = 1;
					if (Pad[PAD_DOWN] == 1) {
						//if分より右ボタンを押している時点でzannzou = 30;とplayerkonntororulockを通っているのでここに書かなくていい
						//余計に書くとplayerkonntororulockが1になってしまいバグで主人公が動かなくなる。
						//左ボタンはなぜか書いて合ってもバグは起きなかったが、これはコントローラの仕様的なものもあるので、とりあえず書かないでおく。
						//zannzou = 30; zannzouA = 0; zannzouB = 0; zannzouC = 0;
						komanndomark = 12;
						playerX = preplayerX;
						//playerkonntororulock = 1;
					}
					else if (Pad[PAD_UP] == 1) {
						//zannzou = 30; zannzouA = 0; zannzouB = 0; zannzouC = 0;
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
					playerkonntororulock = 1;
					if (motonomasunimodoru > 0) {
						migimuki = 0;
						hidarimuki = 1;
					}
					if (Pad[PAD_DOWN] == 1) {
						//zannzouA = 30; zannzou = 0; zannzouB = 0; zannzouC = 0;
						komanndomark = 14;
						playerX = preplayerX;
						//playerkonntororulock = 1;
					}
					else if (Pad[PAD_UP] == 1) {
						//zannzouA = 30; zannzou = 0; zannzouB = 0; zannzouC = 0;
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


		/*if (lock == 1) {
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

		}*/


		//gpUpdateKey();  // キーの入力状態を取得　上のifで既にgpUpdateKey();があり、elseはif以外の情報は引き継ぐので再びgpUpdateKey();書く必要はなかった。
		// 俺の移動

		//playerMove = 1;があると下に書いたplayerMoveより足踏みするplayerMoveが無いと初期値の1でそのまま足踏みするので遅く反応するのでは？


		// 入力状態を取得//★if (input.RightTrigger == 255)を使う上で必要
		GetJoypadXInputState(DX_INPUT_PAD1, &input);

		//Color = GetColor(255, 255, 255);
		//DrawFormatString(0, 0, RED, "LeftTrigger:%d RightTrigger:%d",
		//	input.LeftTrigger, input.RightTrigger);


		

		//こいつがあると敵に攻撃できないときがあるので、攻撃中はこのプログラムを無効にする。
		//主人公と敵が被らないようにするためのプログラム。
		if (kaburulock == 0) {
			if (playerX == enemyX - 1&& playerY == enemyY) {
				RIGHTbotannlock = 1;
				//playerX = enemyX - 1;
				//playerY = enemyY;
				//LEFTmark = 2345;
			//	playerHP = playerHP - 100;
				//addattacktime = 40;

			//	damegi1sound = LoadSoundMem("_game_swordman-damage2.mp3");
			//	PlaySoundMem(damegi1sound, DX_PLAYTYPE_BACK);


			}
			else{
				RIGHTbotannlock = 0;
				
			}

			if (playerX == enemyX + 1 && playerY == enemyY) {
				LEFTbotannlock = 1;
			}
			else{
				LEFTbotannlock = 0;

			}
			if (playerX == enemyX && playerY - 1 == enemyY) {
				UPbotannlock = 1;
			}
			else{
				UPbotannlock = 0;

			}
			if (playerX == enemyX && playerY + 1 == enemyY) {
				DOWNbotannlock = 1;
			}
			else {
				DOWNbotannlock = 0;

			}
		
		}
		
		//↓通常殴ると連続殴るのプログラム。
		//★if (Pad[PAD_6] == 1 && kougekilock == 0&&kougekiroclmark == 0&&enemyY == playerY)の中に書くと
		//Pad[PAD_6] == 1が押されている間のみしか発動しないので前の条件式が発動しなくてもkougekilockの値があれば良いようにした。
		if (kougekikannkakulock == 0) {
			if (kougekidekinailock == 0) {
				if (attackframe == 0) {
					if (Pad[PAD_2] == 1 && kougekilock == 1 && kougekiKANOU == 2 && sousakanou == 0 && nextattack == 0 &&
						motonomasunimodoru > 0 && Pad[PAD_6] == 0 && Pad[PAD_LEFT] == 0) {
						lock = 0;//移動ボタンが押せないように。
						//LEFTmark = 9;
						R1lock = 1;//再度殴ってる最中にR1を押して、攻撃中の座標を保存しないために1とした。
						enemysabunHP = 10;
						stayherelock3 = 1;//★敵のHP表示を消すために必要な変数。
						//addattacktime = 300;//先行入力でコンボが決まった時のためのアドアタックタイム。
						++attackframe;
						//nagurusound = LoadSoundMem("殴る音.mp3");
						//PlaySoundMem(nagurusound, DX_PLAYTYPE_BACK);
						nagurugazou = 1;
						//kougekiKANOU = 0;

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
						if(migimuki == 1){
						nanameidouX = nanameidouX + 10;
						playerattackhanndou = playerattackhanndou + 40;//自分が吹っ飛ぶのではなく、敵が吹っ飛ぶための反動なので自分の描画部分の一には書かない
						//sinnzoubyouga = 1;//血しぶきを描画するための変数。
						motonomasunimodoru = motonomasunimodoru + 40;//攻撃中に攻撃が当たったら時間が延びる
						}
						else if (hidarimuki == 1) {
							nanameidouX = nanameidouX - 10;
							playerattackhanndou = playerattackhanndou - 40;//自分が吹っ飛ぶのではなく、敵が吹っ飛ぶための反動なので自分の描画部分の一には書かない
							//sinnzoubyouga = 1;//血しぶきを描画するための変数。
							motonomasunimodoru = motonomasunimodoru + 40;//攻撃中に攻撃が当たったら時間が延びる
						}
						//★足すにするとたまに総合で180になったときにif文で0になってしまうので足すではなく定数にした。
						//nextattack = 1;//攻撃の同時押しを防ぐための変数。
						//★★たまに相手をより奥に突き飛ばすことがある。そんな時はさらにR1を押して追いかけて追加攻撃するといい。
						notattacklock = 1;
						enemyattaking = 1;
						if (GetRand(10) < 4) {
							playerattackhanndou2 = playerattackhanndou2 + 30;//どこに移動するかわからないようにしてギャンブル性を高めてマンネリ化を防ぐ。
							//playerattackhanndou3 = playerattackhanndou3 + 5;// playerattackhanndou3はY軸に吹っ飛ばすための変数。
						}
						enemyzannzoulockframe1 = 1;
						stayhereframe = 1;
						//続けて殴るとバグで敵の攻撃を一気に受けて即死することがあるので一定の区間での攻撃とする。
						//キックや刀と同じ変数で使えれば同時押しによる攻撃などもより強化できると思う。
						//++kougekikannkaku;
						bloodMove = 1;
						kakuninn = 4;
					}
				}
				if (attackframe > 0 && ++attackframe < 80) {
					if (attackframe > 35 && attackframe < 80) {//★この間にボタンを押すと連続攻撃に移る。
						//最初の殴ると一緒にatatackframeは立ち上がるため、一発目の攻撃が表示された後くらいのフレームから
						//二発目を描画したいので、60からにした。
						if (Pad[PAD_2] == 1 && kougekiKANOU == 2 && sousakanou == 0 && nextattack == 0 && attackframeA == 0) {
							attackframeA = 1;
							++nagurugazou2;
						}
					}
				}
				if (attackframe > 80) {//コンボが決まらなかった場合で早く元に戻ると、仮にコンボが決まった際にここのフレームが50とかだと
					//コンボが終わった後に上のボタンをまた押せてしまい、二段目の技が連続で出てきてしまう。
					//なのでここではコンボが決まった後にもう少し長くすることで連続で二段目の攻撃が連続でできないようにした。
					//まああるいは、上のフレームをもっと短くして100ではなく、50とかにしても解決できるかもしれない。
					//解決できるが、50は短すぎるため連続押し自体が難しいからこれでいい。
					attackframe = 0;
					attackframeA = 0;
				}
				
				//★★ && kougekilock == 1&& kougekiKANOU == 1はR1を押さない場合の時は上に書いたように
				//R1lockは0になるので、コンボが出来ないので他の変数konnbokakuninnを使った。
				//最初からコンボ出ない場合はR1lockは1のままなのでそのままキックできる。
			//Yボタンからのコンボを決めるためのYボタンを入力する部分//キックするボタン
				  if (Pad[PAD_4] == 1 && kougekilock == 1 && kougekiKANOU == 2 && enemysabunHP == 0&&sousakanou == 0 && nextattack == 0) {//enemysabunHPが0となるときに押せるようにしたので殴るが押されていないときにキックができるようにした。
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
					//attackframe = 0;//コンボへ分岐する際に殴るなどがでないようにアタックフレーム1は0にする。
					sennkounyuuryokubunnki = 1;
					kougekilock = 1;////先行入力でコンボが決まった時に誤作動でXボタンを押しても殴るがでないように他の値にする。
					zannzoulock = 1;
					//++attackframe;
					KONNBO1A = 1;

					//kougekiKANOU = 0;

					nagurukasanaru = 0;
					KONNBO1kasanaru = 1;

					enemykougekilock = 1;

					playerHPlock = 1;//キックするときにダメージを負った状態の画像を描画しないための物。
					nextattack = 1;
					//motonomasunimodoru = 160;//コンボが決まると一定の値になるようにした。

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
				if (sennkounyuuryokubunnki == 1) {
					++attackframe2;
					//LEFTmark = 114;
					if (attackframe2 > 5 && attackframe2 < 40) {//下のif (attackframe2 > 0 && attackframe2 < 15)と被らないようにする。
						if (migimuki == 1) {
							if (Pad[PAD_RIGHT] == 1) {//★↑の方は左はじきで反応しないように少し遅めに9にして、仮に遅めに左ははじきで右が入力されても反応しないように15とした。
							//LEFTmark = 514;
							//KONNBO1A = 0;//けり上げる時に、蹴る前の画像を描画しないように。
								enemysabunHPA = 40;//最初の普通の殴るの攻撃もXボタンを押すことのコンボをなるため
								//LEFTmark = 114514;//描画用に作った先行入力の確認用の変数
								LEFTmarklock = 1;//先行入力が再びできるようにするにはXボタンで相手を殴るために、ここに1として、追加の方でLEFTmarklock = 0とした。
								//addattacktime = 300;
								attackframe = 0;//攻撃後に追加殴るをしなくても1としておけば0より大きいのでコンボがつながる。追加殴るで今コンボを繋げてもいい。
								stayherelock3 = 1;//敵のHPを消すために必要な変数
								//sennkounyuuryokubunnki = 1;//★if文よりsennkounyuuryokubunnki==1の時でないとここのif文は動かないので、sennkounyuuryokubunnkiが0の時は前のif文の条件に合わないのでattackframe2内であっても殴る2の攻撃できないのは当然である。
								//attackframe2 = 0;//先行入力の分岐でsennkounyuuryokubunnki2に行かなかった場合にattackframe2の値が0になるように書いた。
								//naguru2sound = LoadSoundMem("damage01.m4a");
								//PlaySoundMem(naguru2sound, DX_PLAYTYPE_BACK);
								//sennkounyuuryokubunnki3 = 0;//ここの先行入力が成功した際は続けて殴る3がでないようにここの変数を0にする。
								//attackframe3 = 150;//★先行入力が成功した際は続けて殴る3がでないように殴る3に引っ掛からないような変数の値にする。

								kougekilock = 1;//コンボ入力が成功した際に再びコンボを決めたい際に上のYボタンのif文を通過できるように
								//kougekilockの値を1にする。

								KONNBO1A = 0;//前の蹴る前の画像を消すための物。
								KONNBO1B = 1;//蹴り上げるの画像を描画するためのもの


								KONNBO1kasanaru = 0;
								KONNBO2kasanaru = 1;
								sinnzoubyouga = 1;//血しぶきを描画するための変数。
								nanameidouX = nanameidouX + 5;
								motonomasunimodoru = motonomasunimodoru + 60;//攻撃中に攻撃が当たったら時間が延びる
								playerattackhanndou = playerattackhanndou + 60;
								enemyattaking = 1;
								//★★たまに相手をより奥に突き飛ばすことがある。そんな時はさらにR1を押して追いかけて追加攻撃するといい。
								if (GetRand(10) < 3) {
									playerattackhanndou2 = playerattackhanndou2 + 20;
									playerattackhanndou3 = playerattackhanndou3 + 10;// playerattackhanndou3はY軸に吹っ飛ばすための変数。
								}
								enemyzannzoulockframe1 = 1;
								stayhereframe = 1;
								bloodMove = 1;
								kakuninn = 5;
							}
						}
						else if (hidarimuki == 1) {
							if (Pad[PAD_LEFT] == 1) {//★↑の方は左はじきで反応しないように少し遅めに9にして、仮に遅めに左ははじきで右が入力されても反応しないように15とした。
							//LEFTmark = 514;
							//KONNBO1A = 0;//けり上げる時に、蹴る前の画像を描画しないように。
								enemysabunHPA = 40;//最初の普通の殴るの攻撃もXボタンを押すことのコンボをなるため
								//LEFTmark = 114514;//描画用に作った先行入力の確認用の変数
								LEFTmarklock = 1;//先行入力が再びできるようにするにはXボタンで相手を殴るために、ここに1として、追加の方でLEFTmarklock = 0とした。
								//addattacktime = 300;
								attackframe = 0;//攻撃後に追加殴るをしなくても1としておけば0より大きいのでコンボがつながる。追加殴るで今コンボを繋げてもいい。
								stayherelock3 = 1;//敵のHPを消すために必要な変数
								//sennkounyuuryokubunnki = 1;//★if文よりsennkounyuuryokubunnki==1の時でないとここのif文は動かないので、sennkounyuuryokubunnkiが0の時は前のif文の条件に合わないのでattackframe2内であっても殴る2の攻撃できないのは当然である。
								//attackframe2 = 0;//先行入力の分岐でsennkounyuuryokubunnki2に行かなかった場合にattackframe2の値が0になるように書いた。
								//naguru2sound = LoadSoundMem("damage01.m4a");
								//PlaySoundMem(naguru2sound, DX_PLAYTYPE_BACK);
								//sennkounyuuryokubunnki3 = 0;//ここの先行入力が成功した際は続けて殴る3がでないようにここの変数を0にする。
								//attackframe3 = 150;//★先行入力が成功した際は続けて殴る3がでないように殴る3に引っ掛からないような変数の値にする。

								kougekilock = 1;//コンボ入力が成功した際に再びコンボを決めたい際に上のYボタンのif文を通過できるように
								//kougekilockの値を1にする。

								KONNBO1A = 0;//前の蹴る前の画像を消すための物。
								KONNBO1B = 1;//蹴り上げるの画像を描画するためのもの


								KONNBO1kasanaru = 0;
								KONNBO2kasanaru = 1;
								sinnzoubyouga = 1;//血しぶきを描画するための変数。
								nanameidouX = nanameidouX - 5;
								motonomasunimodoru = motonomasunimodoru + 60;//攻撃中に攻撃が当たったら時間が延びる
								playerattackhanndou = playerattackhanndou - 60;
								enemyattaking = 1;
								//★★たまに相手をより奥に突き飛ばすことがある。そんな時はさらにR1を押して追いかけて追加攻撃するといい。
								if (GetRand(10) < 3) {
									playerattackhanndou2 = playerattackhanndou2 + 20;
									playerattackhanndou3 = playerattackhanndou3 + 10;// playerattackhanndou3はY軸に吹っ飛ばすための変数。
								}
								enemyzannzoulockframe1 = 1;
								stayhereframe = 1;
								bloodMove = 1;
								kakuninn = 6;
							}
						}
						//sennkounyuuryokubunnki3 = 0;
						//attackframe3 = 0;//殴る2バージョンをやった後で値がそのままだと右を押しただけで殴るバージョン3ができてしまうので。
						//★殴る2に分岐した場合は殴る3の情報をすべて0にする。
						//attackframe = 0;//殴る2が成功したするかは別にこのフレームの時に一旦0にするとXボタンからのコンボがつながりやすい。
					}


					

					//ここの先行入力に成功すると殴るバージョン3に続く。
					//★★このフレームがちょうどいい。
					//if (attackframe2 > 0 && attackframe2 < 5) {
					//	if (Pad[PAD_LEFT] == 1) {

							//KONNBO1Aframe1 = 0;//こいつを0にすることで描画のキックをする前の画像を描画できなようにした。
					//		KONNBO1A = 0;//別のコンボに進んだため、値を0にする。//注意、まだ画像が作れていないので何も表示されない。
					//		KONNBO1B = 0;//別のコンボに進んだため、値を0にする。//注意、まだ画像が作れていないので何も表示されない。
					//		sennkounyuuryokubunnki3 = 1;//ここの先行入力に成功すると殴るバージョン3に続く。
					//		LEFTmark = 2;//確認のために。
					//		addattacktime = 300;//★コンボのつなぎとして、殴る3のコンボが入らな過ぎるのも困るので。
							//★addattacktime = 50では短くて入力が成功してattackframe3が上がってもaddattacktimeが0になってしまい元のマスに戻ってしまい殴る3が出来なかった。
					//		sennkounyuuryokubunnki = 0;//殴る2に行かない様にするため。
					//		attackframe2 = 0;//殴る3に行った際に、attackframe2が0になるようにする。★コンボの際はほかのフレームは関係ないので0にする。


					//		nagurukasanaru = 0;
					//		KONNBO1kasanaru = 0;
					//		KONNBO2kasanaru = 0;
					//	}
					//}
				}



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
					if (attackframe4 > 50 && attackframe4 < 110) {
						if (kougekiKANOU == 2) {
							if (Pad[PAD_RIGHT] == 1) {
								playerHPlock = 1;
								RIGHTmarklock = 1;
								//attackframe2 = 0;
								enemysabunHP = 100;
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
								playerattackhanndou = playerattackhanndou + 70;
								//ememydontmovetime = 1;
								//コンボ
								++conbocount;
								enemyzannzoulockframe1 = 1;
								stayhereframe = 1;
								bloodMove = 1;
								kakuninn = 7;
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
					if (attackframe4 > 50 && attackframe4 < 110) {
						if (kougekiKANOU == 2) {
							if (Pad[PAD_LEFT] == 1) {
								playerHPlock = 1;
								RIGHTmarklock = 1;
								//attackframe2 = 0;
								enemysabunHP = 100;
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
								playerattackhanndou = playerattackhanndou + 70;
								//ememydontmovetime = 1;
								//コンボ
								++conbocount;
								enemyzannzoulockframe1 = 1;
								stayhereframe = 1;
								bloodMove = 1;
								kakuninn = 8;
							}
						}


					}
				}
			}

		}


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
		if (attackframe3 > 100) {
			sennkounyuuryokubunnki3 = 0;
			attackframe3 = 0;
			zannzoulock = 0;
			playerHPlock = 0;
			kougekiKANOU = 0;
			nextattack = 0;//キック後に再びキックできるように。
		}
		if (attackframe3 > 0 && ++attackframe3 > 100 && kougekiKANOU == 0) {
			attackframe3 = 0;
		}
		if (attackframe4 > 60) {
			attackframe4 = 0;
			zannzoulock = 0;
			playerHPlock = 0;
			//playermovelock = 0;//念のために。//敵に攻撃された際に主人公の攻撃が止むように
			//attackframe4が50になるように書いたため、ここにきてしまい、スライド中なのにplayermovelockになり、通常移動動作がでてしまい、
			//マスに帰ってきた時にバグるので、ここには書かない。
		}//もしかしたらkougekiKANOUが0の時にフレームがあまり、誤発するかもしれないのでここで0の場合も書いて置く。
		if (attackframe4 > 0 && ++attackframe4 > 110 && kougekiKANOU == 0) {
			attackframe4 = 0;
		}
		if (attackframe5 > 30) {
			attackframe5 = 0;
			zannzoulock = 0;
			playerHPlock = 0;
			nextattack = 0;
		}
		if (attackframe5 > 0 && ++attackframe5 > 30 && kougekiKANOU == 0) {
			attackframe5 = 0;
			nextattack = 0;
		}

		//銃を使った攻撃

		
		if (Gunkirikae == 0) {
			if (Gfunction_status == 0) {

				if (jyuuosenai == 0) {
					// Gkey == 1はいらないように思える。//Pad[PAD_6] == 1はR1ボタン
					//ここlockが0の時と書いてあるため、ロックマークで撃つ場合と差別化できている。
					if (Pad[PAD_3] == 1 && Gcount >= 1 && Gtime == 0 && Gkey == 1 && Pad[PAD_5] == 0 &&
						Pad[PAD_6] == 0 && lock == 0 && sousakanou == 0 && nextattack == 0 && InputX == 0 && InputY == 0)
					{//「右」は今押された
					  //「右」が押されたときの処理
						Gtime = 1; //銃を撃ってからの経過時間を1にする
						Gcount = Gcount - 1; //残弾数を-1する
						playerImage = playerGHandle[0];	//真正面の状態にする
						//sound2 = LoadSoundMem("タイトルの銃声.mp3");
						//PlaySoundMem(sound2, DX_PLAYTYPE_NORMAL);
						sound2 = LoadSoundMem("タイトルの銃声.mp3");
						PlaySoundMem(sound2, DX_PLAYTYPE_BACK);
						StartJoypadVibration(DX_INPUT_PAD1, 2800, 200);

						++SHOTbyouga;

						nextattack = 1;
						nanameidouX = nanameidouX + 10;
						tabakosuenai = 1;
						if (migimuki == 1) {
							if (pos[enemyY][enemyX][1] + 20 + playerattackhanndou3 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 &&
								pos[enemyY][enemyX][1] - 20 + playerattackhanndou3 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
								&& pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 - 15
								//情報が足りなかったのだろう。敵2と主人公の位置の大小があいまいだったのでより詳しく付け足した。
								) {//これで前に敵がいるときのみに攻撃が出来る。//1と4
								//敵1が敵2よりもX軸的に前にいたら
								kougekiKANOU = 10;
								GenemysabunHP = 40;
								//enemyImage = enemyGHandle[5];
								sinnzoubyouga = 1;//心臓のギフを描画するために必要な変数
								//★↑の変数により心臓を描画する値が繰り上がると血が噴き出す画像も描画されるので直線の銃攻撃が当たると
								//血が噴き出る画像が描画される。
								//stayherelock = 1;//敵のHPを消すために必要な変数
								//playerattackhanndou = playerattackhanndou + 20;//ハンドガンが当たった際に反動で相手が少し下がるように。
								//★なので敵の攻撃の際に銃を撃った際には反動を受けた相手の残像が後ろに見える。
								KABURImark = 100;
								kakuninn = 9;
								//コンボ
								++conbocount;
								enemyzannzoulockframe1 = 1;//相手のダメージを食らった際の怯みを初期に戻すため
								stayhereframe = 1;

								playerattackhanndou = playerattackhanndou + 20;

								enemysabunHPpoint = enemysabunHPpoint + 5;
								bloodMove = 1;
							}//else ifにするとどっちかの場合を取るため一直線に敵がいても一方しか受けないのでここは普通にifにする。
							//どっちか一方的の方だけ食らうようにしたいのでifで範囲にした。
							
						}
						else if (hidarimuki == 1) {
							if (
								pos[enemyY][enemyX][1] + 20 + playerattackhanndou3 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 &&
								pos[enemyY][enemyX][1] - 20 + playerattackhanndou3 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
								&& pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 <= pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 - 15
								) {//これで前に敵がいるときのみに攻撃が出来る。//1と4
								//敵1が敵2よりもX軸的に前にいたら
								kougekiKANOU = 10;
								GenemysabunHP = 40;
								//enemyImage = enemyGHandle[5];
								sinnzoubyouga = 1;//心臓のギフを描画するために必要な変数
								//★↑の変数により心臓を描画する値が繰り上がると血が噴き出す画像も描画されるので直線の銃攻撃が当たると
								//血が噴き出る画像が描画される。
								//stayherelock = 1;//敵のHPを消すために必要な変数
								//playerattackhanndou = playerattackhanndou + 20;//ハンドガンが当たった際に反動で相手が少し下がるように。
								//★なので敵の攻撃の際に銃を撃った際には反動を受けた相手の残像が後ろに見える。
								KABURImark = 100;
								kakuninn = 11;
								//コンボ
								++conbocount;
								enemyzannzoulockframe1 = 1;//相手のダメージを食らった際の怯みを初期に戻すため
								stayhereframe = 1;

								playerattackhanndou = playerattackhanndou - 20;

								enemysabunHPpoint = enemysabunHPpoint + 5;
								bloodMove = 1;
							}//else ifにするとどっちかの場合を取るため一直線に敵がいても一方しか受けないのでここは普通にifにする。
							
						}



					}
					//もう一つのロックしないで銃を撃つプログラムと同じような条件だと被ってしまい、こっちが動かないので条件を変えた。
					//★ロック＝＝1としたため、//攻撃判定その一(銃による攻撃判定)がどうなるかわからず、敵がいないところにも弾を撃てた。
					//そして、hannilock == 2でもどっちの場合か書いていないので下のようにif文で範囲を書く。でないと範囲に関係なく
					//ただ撃つだけで相手のHPが減ってしまう。
					if (lock == 1) {
						if (Pad[PAD_3] == 1 && Gcount >= 1 && Gtime == 0 && sousakanou == 0 && nextattack == 0)
						{//「右」は今押された
						  //「右」が押されたときの処理
							Gtime = 1; //銃を撃ってからの経過時間を1にする
							Gcount = Gcount - 1; //残弾数を-1する
							//playerImage = playerGHandle[0];	//真正面の状態にする
							//LEFTmark = 989;
							//sound2 = LoadSoundMem("タイトルの銃声.mp3");
							PlaySoundMem(sound2, DX_PLAYTYPE_BACK);
							StartJoypadVibration(DX_INPUT_PAD1, 2800, 200);
							nextattack = 1;
							//jyuuzikeysousa2 = 1;
							if (kougekiKANOU == 1) {
								GenemysabunHP = 50;
								R1attackframe = 0;
								enemyzannzoulockframe1 = 1;
								stayhereframe = 1;
								kakuninn = 231;
							}
							else if (kougekiKANOU == 0) {
								GenemysabunHP = 0;
								R1attackframe = 0;
							}
						}
					}
					else if (lock == 0) {
						//jyuuzikeysousa2 = 0;
					}
				}


				if (Gtime > 0) { //銃を撃ってからの経過時間が0より大きい場合のみ
					++Gtime; //銃を撃ってからの経過時間を+1する
					KENJYUUgazou = 1;
				}
				if (Gtime == 20) { //銃を撃ってから１秒( 60 )経過したら
					playerImage = playerGHandle[0]; //左横向きの状態にする
				}
				if (Gtime == 40) { //銃を撃ってから２秒( 120 )経過したら
					playerImage = playerGHandle[0];	//右横向きの状態に戻す
					Gtime = 0; //銃を撃ってからの経過時間を0に戻す
					//jyuuosenai = 0;
					DrawExtendGraph(0, 0, 1770, 980, SHOTHandle, FALSE);
					nextattack = 0;
				}
				///if (Gcount <= 0) { Gcount = 0; }//こいつによってGcountが負の値に進まずにいる。
				if (Gcount <= 0) {	//銃の弾の数が0以下だったら
					Gcount = 0;
					GcountA = 1;//リロード中を描画するために作った変数
					++GcountZeroCounter;	//『銃の弾が0になってから経過したフレーム数をカウントする変数』を+1する
					if (GcountZeroCounter >= 2000) {	//銃の弾が0になってから経過したフレーム数が15秒( 60 × 15 )経過したら
						Gcount = 13;	//銃の弾の数を15に増やす
						GcountZeroCounter = 0;	//次回のカウント処理のために『銃の弾が0になってから経過したフレーム数をカウントする変数』を0にする
						GcountA = 0;
					}
				}
			}//if (Gfunction_status == 0)の{}である。


			if (Gfunction_status == 1) {
				
				if (lock == 1) {
					
							if (
								(PrevPadState & PAD_INPUT_3 && MGcount >= 1 && MGtime == 0 && Gkey == 2 && sousakanou == 0 && nextattack == 0) != 0  //前回は押されている
								&&  //且つ
								(CurrPadState & PAD_INPUT_3 && MGcount >= 1 && MGtime == 0 && Gkey == 2&& sousakanou == 0 && nextattack == 0) != 0  //今回は押されている
								)
							{
								
								MGframe = 1;
								R1attackframe = 50;
								//範囲内なら引かれる。
							}
							
						if (
							(PrevPadState & PAD_INPUT_5 && MGcount > 0 && MGframe == 1 && nextattack == 0) == 0  //前回は押されていなくて
							&&  //且つ
							(CurrPadState & PAD_INPUT_5 && MGcount > 0 && MGframe == 1 && nextattack == 0) == 0  //今回は押されていない
							)
						{

							if (
								(PrevPadState & PAD_INPUT_3 && MGcount > 0 && MGframe == 1 && nextattack == 0) != 0  //前回は押されている
								&&  //且つ
								(CurrPadState & PAD_INPUT_3 && MGcount > 0 && MGframe == 1 && nextattack == 0) != 0  //今回は押されている
								) {
								nextattack = 1;//上のハンドガンと同じで撃つときに1にして、で終わったときに0になるようにする。
								--MGcount;//マシンガンの弾が減っていき、かつ相手が同じ行にいるときに相手のHPが減る。そうかかないと一度マシンガンを使った後、ボタンを押していなくても敵が同じ行にいるだけで相手のHPが勝手に減る。
								++MGtime;
								StartJoypadVibration(DX_INPUT_PAD1, 1800, MGcount);
								if (kougekiKANOU == 1) {
									GenemysabunHPA = 2;
								}
								//enemyImage = enemyGHandle[5];
								stayherelock3 = 1;//敵のHPを消すために必要な変数
							}


							if (MGtime > 0) { //銃を撃ってからの経過時間が0より大きい場合のみ
								++MGtime; //銃を撃ってからの経過時間を+1する
								nextattack = 0;//★たまにMGtimeが30より小さく、nextattackが1のままになってしまい撃てなくなる時があるので、
								//確実に0よりは大きくなるのでここでnextattack = 0にした。
								//jyuuosenai = 1;
							}
							if (MGtime == 10) { //銃を撃ってから１秒( 60 )経過したら
								playerImage = playerGHandle[0]; //左横向きの状態にする
							}
							if (MGtime == 20) { //銃を撃ってから２秒( 120 )経過したら
								playerImage = playerGHandle[0]; //左横向きの状態にする
							}
							if (MGtime > 30) {
								MGtime = 1; //銃を撃ってからの経過時間を0に戻す//ここを0に戻すことで再び連続で撃ったり、再度撃つことができる。
								
								//ChangeVolumeSoundMem(80, sound3);//この関数によって音声のボリュームを設定できる。
								soundM = LoadSoundMem("マシンガンの弾の落ちる音.mp3");
								PlaySoundMem(soundM, DX_PLAYTYPE_BACK);
							}

							//Gを押していない時はMGtimeは0にしたことで、マシンガンを撃っている間はMGtimeが1になってループするようにした。
							//★押していない時は0になる。そうしないと垂れ流しになる。一回押すと値がMGcount > 0、MGframe == 1の条件を満たすので一回押しただけで連射できる
							if (Pad[PAD_3] == 0) { MGframe = 0; MGtime = 0; }//キーGを押していない時は止まるようにする

						}
					
					else if (kougekiKANOU == 0) {
						GenemysabunHP = 0;
						R1attackframe = 0;
					}
				}
				//ロックマークとは違うタイプのマシンガン。if(lock == 0)でもいける。
				if (lock == 0) {

					if (
						(PrevPadState & PAD_INPUT_3 && MGcount >= 1 && MGtime == 0 && Gkey == 2 && sousakanou == 0 && nextattack == 0) != 0  //前回は押されている
						&&  //且つ
						(CurrPadState & PAD_INPUT_3 && MGcount >= 1 && MGtime == 0 && Gkey == 2 && sousakanou == 0 && nextattack == 0) != 0  //今回は押されている
						)
					{
						komanndomark = 121;
						MGframe = 1;
						
					}

					//L1ボタンが押されていない時に撃てるようにした。
					if (
						(PrevPadState & PAD_INPUT_5 && MGcount > 0 && MGframe == 1) == 0  //前回は押されていなくて
						&&  //且つ
						(CurrPadState & PAD_INPUT_5 && MGcount > 0 && MGframe == 1) == 0  //今回は押されていない
						)
					{
						if (
							(PrevPadState & PAD_INPUT_3 && MGcount > 0 && MGframe == 1) != 0  //前回は押されている
							&&  //且つ
							(CurrPadState & PAD_INPUT_3 && MGcount > 0 && MGframe == 1) != 0  //今回は押されている
							) {
							--MGcount;//マシンガンの弾が減っていき、かつ相手が同じ行にいるときに相手のHPが減る。そうかかないと一度マシンガンを使った後、ボタンを押していなくても敵が同じ行にいるだけで相手のHPが勝手に減る。
							++MGtime;
							StartJoypadVibration(DX_INPUT_PAD1, 1800, MGcount);
							if (pos[enemyY][enemyX][1] + 25 + playerattackhanndou3 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 &&
								pos[enemyY][enemyX][1] - 25 + playerattackhanndou3 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
								&& pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3
								) {//if (Key[KEY_INPUT_G] == 1 && Gcount >= 1 && Gtime == 0 && Gkey == 2)の中ではKey[KEY_INPUT_] == 1の都合で押し続けても一回しか押さないようにしかカウントされないため、中には書かなかった。
								GenemysabunHPA = 2;
								//enemyImage = enemyGHandle[5];
								stayherelock3 = 1;//敵のHPを消すために必要な変数

							}

						}


						//★多分ここで本来銃を使う上で押されていないボタンがあるため、そのボタンが押されない時に再び途中から打てるようにと作られた部分なのでは？
						//if (
						//	(PrevPadState & PAD_INPUT_1 && MGcount > 0 && MGframe == 1) == 0  //前回は押されていなくて
						//	&&  //且つ
						//	(CurrPadState & PAD_INPUT_1 && MGcount > 0 && MGframe == 1) == 0  //今回は押されていない
						//	)
						//{
						//	MGframe = 0; // MGtime = 0;

						//}//キーGを押していない時は止まるようにする



						if (MGtime > 0) { //銃を撃ってからの経過時間が0より大きい場合のみ
							++MGtime; //銃を撃ってからの経過時間を+1する
							//jyuuosenai = 1;
						}
						if (MGtime > 10 && MGtime < 15) { //銃を撃ってから１秒( 60 )経過したら
							playerImage = playerGHandle[0]; //左横向きの状態にする
						}
						if (MGtime > 15 && MGtime < 20) { //銃を撃ってから２秒( 120 )経過したら
							//playerImage = playerGHandle[1];	//右横向きの状態に戻す
							//jyuuosenai = 0;
							if (MGtime < 17) {
								nextattack = 0;
								MGtime = 0; //銃を撃ってからの経過時間を0に戻す//ここを0に戻すことで再び連続で撃ったり、再度撃つことができる。

								//ChangeVolumeSoundMem(80, sound3);//この関数によって音声のボリュームを設定できる。
								soundM = LoadSoundMem("マシンガンの弾の落ちる音.mp3");
								PlaySoundMem(soundM, DX_PLAYTYPE_BACK);
							}
						}
						//Gを押していない時はMGtimeは0にしたことで、マシンガンを撃っている間はMGtimeが1になってループするようにした。
						//★押していない時は0になる。そうしないと垂れ流しになる。一回押すと値がMGcount > 0、MGframe == 1の条件を満たすので一回押しただけで連射できる
						//if (Pad[PAD_3] == 0) { MGframe = 0; MGtime = 0; }//キーGを押していない時は止まるようにする
						//MGtimeが0の時でないと打てないようにしたので、こいつはいらない。
					}


				}
			
			}

		}
			//ワイヤーを使って相手を前の列に引っ張る
			if (Key[KEY_INPUT_Y] == 1) {//playerX + 1 == enemyXより敵が自分の位置に+1するときの位置にいる場合を表す、なので多分playerX== enemyX-1でもいいと思う。
				if (playerY == enemyY && playerX + 1 == enemyX || playerY == enemyY && playerX + 2 == enemyX || playerY == enemyY && playerX + 3 == enemyX ||
					playerY == enemyY && playerX + 4 == enemyX || playerY == enemyY && playerX + 5 == enemyX) {
					enemyX = 3;//敵を最前列に引っ張る
				}
			}

			//ガード
			if (Key[KEY_INPUT_P] == 1) {
				protect = 1;
			}
			if (protect == 1) { ++protectcount; }
			if (protectcount > 0 && protectcount < 50) {
				protect = 1;
			}if (protectcount == 50) { protect = 0; protectcount = 0; }

			


			if (MGcount <= 0) {	//銃の弾の数が0以下だったら
				MGcount = 0;
				MGcountA = 1;//リロード中を描画するために作った変数
				++MGcountZeroCounter;	//『銃の弾が0になってから経過したフレーム数をカウントする変数』を+1する
				if (MGcountZeroCounter >= 1500) {	//銃の弾が0になってから経過したフレーム数が25秒( 60 × 25 )経過したら
					MGcount = 200;	//銃の弾の数を15に増やす
					MGcountZeroCounter = 0;	//次回のカウント処理のために『銃の弾が0になってから経過したフレーム数をカウントする変数』を0にする
					MGcountA = 0;
				}
			}

		
		//タバコ回復
		//押したままではずっと回復するので変数tabakokirikaeを入れる。
			if (motonomasunimodoru == 0) {
				if (tabakosuenai == 0 && nextattack == 0) {
					if (tabakolock == 0 && lock == 0 && masusave == 0) {
						if (
							(PrevPadState & PAD_INPUT_1) != 0  //前回は押されている
							&&  //且つ
							(CurrPadState & PAD_INPUT_1) != 0  //今回は押されている
							)
						{
							tabakocount = 1;
							R1lock = 1;//爆弾コンボのために押して1にする。
							playermovelock2 = 1;
							playerHPlock = 1;
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
						//tabakogazoulock = 0;
						playermovelock = 0;
						R1lock = 0;
						playerHPlock = 0;
						tabakosutterulock = 0;
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
		

		





		//差分の計算部分
		//キーAが押されたままでも一回しか押していない時と同じなので偽となり、関数を呼んでいる時はキーAは押されていないので前のif文が偽となり、if文の中の関数が働かない。なので外に書いた。
		if (enemysabunHP >= 0&& --enemysabunHP>=0) {
			enemyHP = enemyHP - 1;
			
		}
		if (enemysabunHP < 0) {

			enemysabunHP = 0;
		}

		if (enemysabunHPA >= 0 && --enemysabunHPA >= 0) {
			enemyHP = enemyHP - 1;

		}
		if (enemysabunHPA < 0) {

			enemysabunHPA = 0;
		}

		if (KenemysabunHP >= 0 && --KenemysabunHP >= 0) {
			enemyHP = enemyHP - 1;

		}
		if (KenemysabunHP < 0) {

			KenemysabunHP = 0;
		}
		if (GenemysabunHP >= 0 && --GenemysabunHP >= 0) {
			enemyHP = enemyHP - 1;

		}
		
		if (enemysabunHPB < 0) {

			enemysabunHPB = 0;
		}
		if (GenemysabunHPA >= 0 && --GenemysabunHPA >= 0) {
			enemyHP = enemyHP - 1;

		}
		if (GenemysabunHPA < 0) {

			GenemysabunHPA = 0;
		}
		
		
		
		
		
		//とりあえず、攻撃の最中も上がるようにif (addattacktime == 501){}の外にif文を出した。

		
		//キーLを押したまま別のキーを押すと武器が切り替わる

		


			//敵の攻撃や移動などの部分。
			if (stayhere3 == 0) {// 敵の移動
				int t = GetNowCount();
				pre2enemyX = enemyX;//ここに書いたことで変数pre2enemyXに敵のX座標が入る。
				if (t >= nextMoveTime) { // 指定の時間が経ったら(1sごとに)
					nextMoveTime = t + MOVE_INTERVAL; // 次回移動処理をする時刻
					if (stopCount > 0) { // 停止中のとき
						stopCount--; // 止まっている残り時間(回数)を減らす
					}

					else { // 9マス上のいずれかのパネルに移動させる
						int cy = enemyY, cx = enemyX;
						do {
							enemyidou = GetRand(10);
							if (enemyidou > 3) {//主人公の攻撃中はstayhereが1になるので、ちゃんとコンボもできて、終わったら敵は正常に移動する。
								enemyY = GetRand(2);
								enemyX = GetRand(2) + 3;
								DAMEGE = 0;//★重要。ここで攻撃をカウンターしても0になるので、再び攻撃をしても攻撃を食らう。
								playerattackhanndou = 0;
								playerattackhanndou2 = 0;
								playerattackhanndou3 = 0;
								//kericount = 0;
								//yokkerucouunt = 0;
							}
							//playermovelock = 0;
							//敵の移動先に主人公がいた場合は再度移動先を選ぶようにさせる。
							if (cy == playerY && cx == playerX) {
								enemyY = GetRand(2);
								enemyX = GetRand(2) + 3;
							}
							
	
						} while (enemyX == cx && enemyY == cy ||
							enemyX == playerX && enemyY == playerY);

						//enemyImage = enemyGHandle[10];






						//if (ENEMYkougekigazouA1lock == 1) {
							//もしかしたら、一方通行でここを通ってきたが、急に描画ヘッダに飛び移らなくてはいけないとかで
							//描画の方に行っているため、ここには行けずに書いたように動かなったのでは？
						//なので攻撃の終わった瞬間のフレームを入れる。
							//条件が描画ヘッダの条件と若干重なることでここに書いていたようにできなかったのかもしれない。

						//}
						//if (randamulock == 0) { if (aa >= 0) { aa = GetRand(6); } }//こいつが一番上のelseとつながっている。
					//ココではない上にif (enemycountframe > 0 && ++enemycountframe < 30)に enemyattackB = 0;を
						//書いたが{}の外とかで反映されないのかもしれない。上のように書くとenemyattackBは0になった、しかし、目の前に来る。enemyattackB = 0と同じように反映されないかったのかもしれない。
						//だとしたらここにも同じものを書かなくてはならない。
						//if (enemycountframe == 30) { enemycount = 0; enemycountframe = 0; }
					}
					//投げる攻撃
					if (enemyattackdekinai == 0) {
						if (randamulock == 0)
						{
							aa = GetRand(4);//aa = 2の時攻撃
							//ranndamukougeki = 2;
						}
						//もう一つの投げる攻撃。
						if (randamulock2 == 0) {
							bb = GetRand(5);//bb = 3の時攻撃
						}
						
						
					}
					if (enemykougekilock == 0) {
						//突進攻撃
						if (enemyattack3 == 0) { a = GetRand(5); }//enemyattack3が0の時にランダムが動く。
						if (a == 2) { a = 2; }
						if (a == 5) { a = 5; }
						if (a == 1) { a = 1; }
					}


					//弱攻撃
					if (ranndamulock == 0) {
						ranndamukougeki = GetRand(3);
						if (ranndamukougeki == 2) {//GetRand(30) < 30とすると攻撃する途中でやめたり、カウンタが2を超えて上がってしまったりする。
							ranndamulock = 1;//範囲が重なるときだけ主人公と敵の位置が変わるようにした。を無効にするために1にした。
							enemyattack = 1;
							enemyzannzoulock = 1;
							//kaburulock = 1;//相手が目の前にいても踏み込めるように。
							//randamulock = 1;//近距離攻撃中は投げ攻撃をしないように値を1にする。
							ENEMYkougekigazouA2frame = 0;//★ここでランダムのif文により0に戻ることで30のままだった
							//tekinoKOUGEKITYUUhahyouzisinailock = 1;//敵の攻撃中は重なるプログラムを無効にする。
							//enemygazoukesu = 1; //if (playerHPlock == 0 && playerHP <= 200)での敵の画像を一時的に消す。
							//ENEMYkougekigazouA2frameが0に戻り、途中で攻撃が止まることはなくなった。
							//他の解決法としてはif (ENEMYkougekigazouA1lock == 1 &&ENEMYkougekigazouA1frame == 0)
							//の部分で++ENEMYkougekigazouA2frameではなくENEMYkougekigazouA2frame=と固定にすればいいが
							//新しい変数が増えてめんどくさくなるので++として、ここのランダム変数により0にすることで解決した。
							//初めての敵の攻撃もランダムで0になってもif文により値が上がるので問題なく敵は攻撃できる。
							if (enemyattack == 1) {//if (enemyattack == 1)は別にいらない。
								preenemyX = pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + 100;
								preenemyY = pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3;
								//pos[enemyY][enemyX][0] = pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3+ 100;
								//pos[enemyY][enemyX][1] = pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3;
								//preenemyX = pos[enemyY][enemyX][0];
								//preenemyY = pos[enemyY][enemyX][1];
								++enemycount;
								ENEMYkougekigazouA1 = 1;
								
								kasanarulock = 1;//★重なる画像に関してのプログラムにより通常状態の敵が描画されないように、ここで値を1にする。
								enemyattack = 0;
							}
						}
					}
					if (ENEMYkougekigazouA1 == 1) {
						ENEMYkougekigazouA1frame = 1;
						//ENEMYkougekigazouA1lock = 1;
						pos[enemyY][enemyX][0] = preenemyX;
						pos[enemyY][enemyX][1] = preenemyY;
						enemyattack = 0;

						//LEFTmark = 739;
					}
				}
				if (GetRand(5) < 3) { // たまに(70%の確率で)
					stopCount = GetRand(2); // 数秒間(0秒間)その場に止まる
				}
				//中に書くにしてもif (enemycount == 0)の場合を書かなかったら敵が目の前に来た、0の場合の処理を書いた方がいいようだ。攻撃以外は目の前に来るようなコードは書いていないが。
				//まあ、「0の時の場合を書いていないので不自然な動きが起きてしまった」ということも考えられる。
				//if (frames < 500) { frames = 0; }


			}
		


		//ループ内に書いたenemyMoveについてenemyMoveが0より大きくて40を超えたら｛｝の中身を実行。
		//enemyMoveが0より大きいならば+1されて、40より大きい数値になれば両方の条件を満たすので+１される。40より大きい数値になったら敵の画像が変わる。
		//enemyMoveが40より+１されて大きくなるために++enemyMove > 40

		

	}


	//


	



	//もう一つのロックしないで銃を撃つプログラムと同じような条件だと被ってしまい、こっちが動かないので条件を変えた。
					//★ロック＝＝1としたため、//攻撃判定その一(銃による攻撃判定)がどうなるかわからず、敵がいないところにも弾を撃てた。
					//そして、hannilock == 2でもどっちの場合か書いていないので下のようにif文で範囲を書く。でないと範囲に関係なく
					//ただ撃つだけで相手のHPが減ってしまう。
	if (lock == 1) {
		if (Pad[PAD_3] == 1 && Gcount >= 1 && Gtime == 0 && sousakanou == 0 && nextattack == 0)
		{//「右」は今押された
		  //「右」が押されたときの処理
			Gtime = 1; //銃を撃ってからの経過時間を1にする
			Gcount = Gcount - 1; //残弾数を-1する
			//playerImage = playerGHandle[0];	//真正面の状態にする
			//LEFTmark = 989;
			//sound2 = LoadSoundMem("タイトルの銃声.mp3");
			//PlaySoundMem(sound2, DX_PLAYTYPE_BACK);
			StartJoypadVibration(DX_INPUT_PAD1, 2800, 200);
			nextattack = 1;
			playerHPlock = 1;
			jyuuzikeysousa2 = 1;
			if (kougekiKANOU == 1) {
				kakuninn = 24;
				GenemysabunHP = 50;
				R1attackframe = 0;
				//コンボ
				++conbocount;//if (Pad[PAD_3] == 1 && Gcount >= 1 && Gtime == 0 && sousakanou == 0 && nextattack == 0)も考慮しているため一気に増えず、打って当たった分だけカウントされる。
				enemyzannzoulockframe1 = 1;
				stayhereframe = 1;
				enemysabunHPpoint = enemysabunHPpoint + 5;
			}
			if (kougekiKANOU == 4) {
				AGenemysabunHP = 50;
				R1attackframe = 0;
				//コンボ
				++conbocount;
				enemyzannzoulockBframe = 1;
				stayhere2frame = 1;
				enemy2sabunHPpoint = enemy2sabunHPpoint + 5;
			}
			else if (kougekiKANOU == 0) {
				GenemysabunHP = 0;
				R1attackframe = 0;
			}
		}
	}


	//★stgae2Player_Update.hのif文の構造が少し異なるため、ここにif (R1lock == 0)を書いた。

	if (R1lock == 0) {



		//たまに十字キーの入力とR1ボタンの入力が同時になり、R1によって移動した主人公が消えるバグがあるので下のif文のようにした。
		//if (kougekilock == 0 && kougekiroclmark == 0 && lockdekinai == 0) {
			//{
		if (input.RightTrigger == 255 && InputX == 0 && InputY == 0)
		{  //殴る//(lock){}の中に書くとロックする度にcountが0になるので意味がない
			//count++;　　ここにcount書くとifの条件よりcountが0の時の下のlockやplayerX = enemyX - 1など条件になるため、++でcountが1になったらロックできても攻撃できないんだ
			//ここのcountの情報がそのまま下の描画関数に渡されるだけ。
			//if (count >= 0 && ++count > 40) {//countが0から15になるまでを一フレームで表しただけでは？ようはcountを0～1にするのに15フレームかかっただけでは？いや、単純にここにフレームは働いていないなので++count > 40と書いて39回行うはずがフレームが働かないので1しか上がっていないので一回しか攻撃が出来ないのだ
			LEFTmark = 4321;
			lock = 1;//描画のため
			++lockonMove;//描画関数に使うイメージを送るための変数

		//十字キーのための先行入力
		//sennkounyuuryokujyuujiki = 1;
			suraidoidou = 1;
			//R1count = 1;
			//zannzoulock = 1;
			//addattacktime = 180;
			//premasuframe;
			//殴る部分
			//++attackframe;
			// 
			// スライド移動から帰ったときに動けないバグがあったためアドアタックタイムが0でもplayermovelock= 0とかいたので
			// playermovelock = 1は意味がない。
			//playermovelock = 1;//★kougekilock的な奴は攻撃した時でないと値が1にならず、失敗すると値が0のままで
			//描画の方に書いたアドアタックの減る方に行くだけなので、そこに1にするように書いてもいいが、
			//ここに値を1として書いた。
			playerkonntororulock = 1;


			//	playerX = playerX + 1;
			//masusave = 1;
			//if (masusave == 1) {
			//	saveplayerX = pos[playerY][playerX][0];
			//	saveplayerY = pos[playerY][playerX][1];
			//}
			//LEFTmark = 13;
			R1attack = 1;

			//R1lock = 1;//連続押しできないようにアドアタックタイムが0になるまでは1のままにする。
			kougekilock = 1;
			//敵の目の前にいるが、左や右の入力が速いと相手の前にいくがロックマークが現れないバグが起こるので以下のように書いて置く。
			//2マス移動して、相手の目の前に出た時。
				// ウエイトをかけます、あまり速く描画すると画面がちらつくからです
			//WaitTimer(17);
			//敵と重なった際はHPが減る。
				// preplayerXが入ってたまにややこしくなるというか変になるのでここはダメージだけを食らうだけにする。
			hannilock = 2;
			//Gunkirikae = 1;//ロック中は銃が切り替えられないようにする。
			//銃の切り替えの最中は銃は撃てない。
			if (Pad[PAD_5] == 1)
			{//「四角」は今押された
			  //「四角」が押されたときの処理
				Gunkirikae = 1;
				Lcount = 1;
				//LEFTmark = 133;

			}
		}
		//}
	//}
	//途中でロックマークの時間が終わる前にR1を離した場合。


	//if (input.RightTrigger > 0 && input.RightTrigger < 2) {
	//	lock = 0;
	//	R1attack = 0;
	//	lockmarkyokoidou = 0;
	//	lockmarktateidou = 0;
	//	playermovelock = 0;
		//kougekiKANOU = 0;
		//kougekilock = 0;
		//kougekiroclmark = 0;
		//lockdekinai = 0;
	//	R1attackframe = 0;//離すと0になり、再びロックできるようになる。
		//R1lock = 0;
		//masusave = 0;
	//	lockmarkXzahyou = 0;
	//	lockmarkYzahyou = 0;
		//hannilock = 0;
	//}
	//ロックマークの描画期間の時間。
	//if (R1attack == 1) {
	//	++R1attackframe;
	//}

	//if (R1attackframe > 60) {
	//	R1attackframe = 100;
		//R1attack = 0;
	//	zannzoulock = 0;
	//	kougekiKANOU = 0;
	//	kougekilock = 0;
	//	lock = 0;
	//	R1lock = 0;
	//	kougekilock = 0;
	//	kougekiroclmark = 0;
	//	lockdekinai = 0;
		//tabakolock = 0;
	//	masusave = 0;
	//	playermovelock = 0;
		//lockmarkXzahyou = 0;
		//lockmarkYzahyou = 0;

	//	R1attack = 0;
	//	hannilock = 0;
	//}

	}
	if (input.RightTrigger == 0) {
		if (RightTriggerlock == 0) { playermovelock = 0; }
		lock = 0;
		lockmarkyokoidou = 0;
		lockmarktateidou = 0;
		jyuuzikeysousa2 = 0;
		playerkonntororulock = 0;
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

		
	}



	//主人公のHPの上限の設定
	if (playerHP > 600) {
		playerHP = 600;
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
	}

	//コンティニューしてから敵が動くまでの期間のための部分。
	//★強制的にstayhereを1にすると死んだ直前で敵からの攻撃が止まったままになってしまい連続で攻撃を食らうような状態になってしまう。
	//なのでstayhereは消す。
	
	//これより以下は描画するためのプログラム
	//ClearDrawScreen();  // 裏画面を
}

//if (kasokudo = 49) { A = 4; }
//if (function_status == 0) {//function_status = 0の時はメニュー画面でfunction_statusが1の時は戦闘画面とした。
//

