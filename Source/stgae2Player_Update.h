#include <time.h>

void Player_Update2() {
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
	if (playerHP > 0) {//★主人公が攻撃している最中に通常状態や瀕死状態での画像が描画されないようにplayerHPlockがある。なぜplayerHPlockなんて名前にしたのかはわからない。
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
	}



	//敵の通常状態の動きを制御する部分。
	if (enemyMove >= 0 && ++enemyMove < 100) {//pcが60フレームで一周するためenemyMoveが61以上だとenemyGHandle[8]が反映されず元のままで移動が終わる。なのでenemyMoveは60以下でなくてはならない
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
	}

	//敵の通常状態の動きを制御する部分。
	if (enemyMove >= 0 && ++enemyMove < 80) {//pcが60フレームで一周するためenemyMoveが61以上だとenemyGHandle[8]が反映されず元のままで移動が終わる。なのでenemyMoveは60以下でなくてはならない
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
	}


	//playerkonntororulockはR2でのロックしているかしていないかためをっ制御するための変数。playerkonntororulock3は説得中にR2が押せてしまうため
	//押せないようにするために作った変数。playerkonntororulock2は特になくてもいい。
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



				/*if (motonomasunimodoru == 0) {//★相手陣地の中なら攻撃を食らってもその場に止まり移動しないが
					//自分の陣地にいる際は攻撃された際に立ったまま移動できてしまうので条件を付けくわえた。
					if (jyuuzikeysousa2 == 0 && kaihilock == 0) {
						if (jyuuzikeysousa == 0) {
							if (playermovelock == 0 && playermovelock2 == 0) {
								if (stage[0][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 160 &&
									stage[3][0][0] < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 160 &&
									stage[0][3][0] > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 55 &&
									stage[3][3][0] > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + 55 &&
									stage[0][0][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 45 &&
									stage[3][0][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65 &&//完成
									stage[0][3][1] < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 45 &&
									stage[3][3][1] > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 + 65
									)
								{
									if (RIGHTbotannlock == 0) {
										if (
											(PrevPadState & PAD_INPUT_RIGHT && nextattack == 0) != 0  //前回は押されている
											&&  //且つ
											(CurrPadState & PAD_INPUT_RIGHT && nextattack == 0) != 0  //今回は押されている
											) {
											RIGHTkey = 1;
										}
										else
											if (
												(PrevPadState & PAD_INPUT_RIGHT && nextattack == 0) == 0  //前回は押されていない
												&&  //且つ
												(CurrPadState & PAD_INPUT_RIGHT && nextattack == 0) == 0  //今回は押されていない
												) {
												RIGHTkey = 0;
											}

									} //playerMove = 1;があると下に書いたplayerMoveより足踏みするplayerMoveが無いと初期値の1でそのまま足踏みするので遅く反応するのでは？
									if (LEFTbotannlock == 0) {
										if (
											(PrevPadState & PAD_INPUT_LEFT && nextattack == 0) != 0  //前回は押されている
											&&  //且つ
											(CurrPadState & PAD_INPUT_LEFT && nextattack == 0) != 0  //今回は押されている
											) {
											LEFTkey = 1;
										}
										else
											if (
												(PrevPadState & PAD_INPUT_LEFT && nextattack == 0) == 0  //前回は押されていない
												&&  //且つ
												(CurrPadState & PAD_INPUT_LEFT && nextattack == 0) == 0  //今回は押されていない
												) {
												LEFTkey = 0;
											}

									}
									if (UPbotannlock == 0) {
										if (
											(PrevPadState & PAD_INPUT_UP && nextattack == 0) != 0  //前回は押されている
											&&  //且つ
											(CurrPadState & PAD_INPUT_UP && nextattack == 0) != 0  //今回は押されている
											) {
											UPkey = 1;
										}
										else
											if (
												(PrevPadState & PAD_INPUT_UP && nextattack == 0) == 0  //前回は押されていない
												&&  //且つ
												(CurrPadState & PAD_INPUT_UP && nextattack == 0) == 0  //今回は押されていない
												) {
												UPkey = 0;
											}
									}
									if (DOWNbotannlock == 0) {
										if (
											(PrevPadState & PAD_INPUT_DOWN && nextattack == 0) != 0  //前回は押されている
											&&  //且つ
											(CurrPadState & PAD_INPUT_DOWN && nextattack == 0) != 0  //今回は押されている
											) {
											DOWNkey = 1;
										}
										else
											if (
												(PrevPadState & PAD_INPUT_DOWN && nextattack == 0) == 0  //前回は押されていない
												&&  //且つ
												(CurrPadState & PAD_INPUT_DOWN && nextattack == 0) == 0  //今回は押されていない
												) {
												DOWNkey = 0;
											}

										if (RIGHTkey == 1) {
											pos[playerY][playerX][0] = pos[playerY][playerX][0] + 3;
										}
										else if (LEFTkey == 1) {
											pos[playerY][playerX][0] = pos[playerY][playerX][0] - 3;
										}
										else if (UPkey == 1) {
											pos[playerY][playerX][1] = pos[playerY][playerX][1] - 1;//下向きの軸が正になっているため。
										}
										else if (DOWNkey == 1) {
											pos[playerY][playerX][1] = pos[playerY][playerX][1] + 1;
										}

										//範囲外に来たら座標を戻すことにする。
										if (pos[playerY][playerX][0] > 680) {
											pos[playerY][playerX][0] = 680;
										}
										if (pos[playerY][playerX][0] < 265) {
											pos[playerY][playerX][0] = 265;
										}
										if (pos[playerY][playerX][1] < 390) {
											pos[playerY][playerX][1] = 390;
										}
										if (pos[playerY][playerX][1] > 440) {
											pos[playerY][playerX][1] = 440;
										}
									}
								}
							}
						}
					}
				}*/
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
								stayherelock = 1;//★敵のHP表示を消すために必要な変数。
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
								kakuninn = 14;
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
								stayherelock = 1;//★敵のHP表示を消すために必要な変数。
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
								stayherelock = 1;//★敵のHP表示を消すために必要な変数。
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

								kakuninn = 17;//++kougekikannkaku;
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
								stayherelock = 1;//★敵のHP表示を消すために必要な変数。
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
					if (attackframe > 0 && ++attackframe < 80) {
						if (attackframe > 35 && attackframe < 80) {//★この間にボタンを押すと連続攻撃に移る。
							//最初の殴ると一緒にatatackframeは立ち上がるため、一発目の攻撃が表示された後くらいのフレームから
							//二発目を描画したいので、60からにした。

							//敵1に対する連続で殴る部分。
							if (Pad[PAD_2] == 1 && kougekiKANOU == 2 && sousakanou == 0 && nextattack == 0 && attackframeA == 0) {
								attackframeA = 1;//連続で二発目の殴るコンボが出来ないようにするための変数。
								nagurugazou = 0;
								++nagurugazou2;
							}

							//敵2に対して連続で殴る部分
							if (Pad[PAD_2] == 1 && kougekiKANOU == 3 && sousakanou == 0 && nextattack == 0 && attackframeA == 0) {
								attackframeA = 1;
								nagurugazou = 0;
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
						stayherelock = 1;//★敵のHP表示を消すために必要な変数。
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
								stayherelock = 1;//敵のHPを消すために必要な変数
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
								kakuninn = 19;//コンボ
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
								stayherelock = 1;//敵のHPを消すために必要な変数
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
								kakuninn = 20;
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
								stayherelock = 1;//敵のHPを消すために必要な変数
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
								stayherelock = 1;//敵のHPを消すために必要な変数
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
							if (Pad[PAD_RIGHT] == 1) {
								//敵1への刀の攻撃。
								if (kougekiKANOU == 2) {//刀のコンボはやりにくいため、ここに範囲を持ってくるプログラムの方がいい。
									point2 = 100;
									playerHPlock = 1;
									RIGHTmarklock = 1;
									//attackframe2 = 0;
									enemysabunHPB = 100;
									lockmark = 1;
									sinnzoubyouga = 1;
									LEFTmark2 = 890;
									//addattacktime = addattacktime + 100;
									//attackframe = 1;//追加の殴る攻撃ができるようにここで1に戻す。
									attackframe3 = 0;//追加の殴る攻撃ができるようにここで0に戻す。
									attackframe4 = 0;
									++attackframe5;
									kougekilock = 1;
									stayherelock = 1;//敵のHPを消すために必要な変数
									sennkounyuuryokubunnki3 = 0;//再び殴る2などをできるようにするためにここで0にする。
									naguru3sound = LoadSoundMem("damage03.m4a");
									PlaySoundMem(naguru3sound, DX_PLAYTYPE_BACK);
									//++attackframe4;
									//sennkounyuuryokubunnki = 0;//★追加の殴る攻撃ができるように。追加殴るに繋がると、再び殴る2や殴る3ができるため。
									playerattackhanndou = playerattackhanndou + 5;

									kakuninn = 20;//ememydontmovetime = 1;
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
						if (attackframe4 > 50 && attackframe4 < 110) {
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
									stayherelock = 1;//敵のHPを消すために必要な変数
									sennkounyuuryokubunnki3 = 0;//再び殴る2などをできるようにするためにここで0にする。
									naguru3sound = LoadSoundMem("damage03.m4a");
									PlaySoundMem(naguru3sound, DX_PLAYTYPE_BACK);
									//++attackframe4;
									//sennkounyuuryokubunnki = 0;//★追加の殴る攻撃ができるように。追加殴るに繋がると、再び殴る2や殴る3ができるため。
									playerattackhanndou = playerattackhanndou - 5;
									kakuninn = 21;
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
					}
					//}
					//敵2に対する右向きの刀攻撃。
					if (migimuki == 1) {
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
						if (attackframe4 > 50 && attackframe4 < 110) {
							if (Pad[PAD_RIGHT] == 1) {
								if (kougekiKANOU == 3) {//刀のコンボはやりにくいため、ここに範囲を持ってくるプログラムの方がいい。
									point = 123;
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
									stayherelock = 1;//敵のHPを消すために必要な変数
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
						if (attackframe4 > 50 && attackframe4 < 110) {
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
									stayherelock = 1;//敵のHPを消すために必要な変数
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
					}
					//}

						//if (gardframe > 0 && ++gardframe < 100 && kougekiKANOU == 3) {

						//}
						//if (gardframe > 100) {
						//	gardframe = 0;
						//}
				}

			}

		}


		//R2を押さない場合。
		/*if (input.RightTrigger == 0) {
			if (RightTriggerlock == 0) { playermovelock = 0; }
			lock = 0;
			lockmarkyokoidou = 0;
			lockmarktateidou = 0;
			jyuuzikeysousa2 = 0;
			playerkonntororulock = 0;
		}*/


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
		if (attackframe4 > 120) {
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



		//銃を使った攻撃
		if (Gunkirikae == 0) {
			if (Gfunction_status == 0) {

				if (pos[enemyY1][enemyX1][1] + 20 + playerattackhanndou3 >= pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 &&
					pos[enemyY1][enemyX1][1] - 20 + playerattackhanndou3 <= pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
					) {
					tyokusennkougeki = 1;

				}
				else if (pos[enemyY2][enemyX2][1] + 20 + playerattackhanndou3B >= pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 &&
					pos[enemyY2][enemyX2][1] - 20 + playerattackhanndou3B <= pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
					) {
					tyokusennkougeki = 2;


				}






				if (jyuuosenai == 0) {
					// Gkey == 1はいらないように思える。//Pad[PAD_6] == 1はR1ボタン
					//ここlockが0の時と書いてあるため、ロックマークで撃つ場合と差別化できている。
					if (Pad[PAD_3] == 1 && Gcount >= 1 && Gtime == 0 && Gkey == 1 && Pad[PAD_5] == 0 &&
						Pad[PAD_6] == 0 && lock == 0 && sousakanou == 0 && nextattack == 0)
					{//「右」は今押された
					  //「右」が押されたときの処理
						zannzoulock = 1;
						Gtime = 1; //銃を撃ってからの経過時間を1にする
						Gcount = Gcount - 1; //残弾数を-1する
						//playerImage = playerGHandle[0];	//真正面の状態にする
						//sound2 = LoadSoundMem("タイトルの銃声.mp3");
						//PlaySoundMem(sound2, DX_PLAYTYPE_NORMAL);
						sound2 = LoadSoundMem("タイトルの銃声.mp3");
						//PlaySoundMem(sound2, DX_PLAYTYPE_BACK);
						StartJoypadVibration(DX_INPUT_PAD1, 2800, 200);
						PlaySoundMem(sound2, DX_PLAYTYPE_BACK);

						++SHOTbyouga;

						nextattack = 1;
						playerHPlock = 1;
						//nanameidouX = nanameidouX - 0;
						tabakosuenai = 1;//同時にタバコを吸えないように。

						//<★重要★>
						//★敵は常に移動しているためダメージを与えたい敵のYの軸の情報を使わないと意味がない、
						//銃はダメージを与えたい敵のY軸を狙っているのだから。
						//Y軸は敵1にして、主人公と敵1が同じY座標にいる。
						//X軸が主人公＜敵2＜敵1の順に書かれている。//★主人公が敵2に足しして攻撃するのにY軸が敵1であるため、消した。
					/*if (migimuki == 1 && pos[enemyY1][enemyX1][1] + 20 + playerattackhanndou3 >= pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 &&
						pos[enemyY1][enemyX1][1] - 20 + playerattackhanndou3 <= pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3
						&& pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 >= pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 - 15
						&& pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 >= pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B
						&& pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 <= pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B
						)
					{

						kougekiKANOU = 10;
						GenemysabunHP = 40;
						point = 130;

					}*/



						


























					//★↓ここからは右向きの敵1のY軸と敵2のY軸の主人公が敵1にダメージを与える部分になる。
						//長いif文は敵1や敵2をまたいで攻撃してリ、貫通してふたりの敵に攻撃しないようにしたり、同じY軸にふたり敵がいる時に
						//主人公の向く方向の敵だけに攻撃を当てれるようにするためのプログラムである。




						int a = pos[enemyY1][enemyX1][1] + playerattackhanndou3;
						int b = pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3;

						int c = pos[enemyY1][enemyX1][0]
							+ playerattackhanndou + playerattackhanndou2 + playerattackhanndou3;
						int d = pos[playerY][playerX][0]
							+ nanameidouX + migiidou + nanameidouX2 + nanameidouX3;
						int e = pos[enemyY2][enemyX2][0]
							+ playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B;

						if (a + 15 >= b && a - 15 <= b) {
							tyokusennkougeki = 1;
							if (tyokusennkougeki == 1) {
								if (c >= d - 15 && c <= e && d <= e ||
									c >= d - 15 && c >= e && d >= e ||
									c >= d - 15 && c >= e && d <= e ||
									c >= d - 15 && c >= e && d >= e) {

									kougekiKANOU = 10;
									GenemysabunHP = 40;
									point = 123;
								}
							}
						}
						a = pos[enemyY2][enemyX2][1] + playerattackhanndou3B;
						if (a + 15 >= b && a - 15 <= b) {
							tyokusennkougeki = 2;
							if (tyokusennkougeki == 2) {
								if (c >= d - 15 && c >= e && d <= e ||
									c <= d - 15 && c <= e && d <= e ||
									c >= d - 15 && c <= e && d <= e ||
									c <= d - 15 && c <= e && d >= e) {

									kougekiKANOU = 10;
									AGenemysabunHP = 40;
									point = 123;
								}
							}
						}
						else {
							tyokusennkougeki = 0;
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

				}


				if (Gtime > 0) { //銃を撃ってからの経過時間が0より大きい場合のみ
					++Gtime; //銃を撃ってからの経過時間を+1する
					//jyuuosenai = 1;
					// = 90911;
					KENJYUUgazou = 1;
					if (Gtime == 20) { //銃を撃ってから１秒( 60 )経過したら
					//playerImage = playerGHandle[0]; //左横向きの状態にする
					}
					if (Gtime == 40) { //銃を撃ってから２秒( 120 )経過したら
						//playerImage = playerGHandle[0];	//右横向きの状態に戻す
						Gtime = 0; //銃を撃ってからの経過時間を0に戻す
						//jyuuosenai = 0;
						DrawExtendGraph(0, 0, 1770, 980, SHOTHandle, FALSE);
						playerattackhanndou = 0;
						playerattackhanndouB = 0;
						nanameidouX = 0;
						nextattack = 0;
						KENJYUUgazou = 1;
						zannzoulock = 0;
						playerHPlock = 0;

						R1lock = 0;


					}
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










		//もう一人に敵に関してのダメージ

		//とりあえず、攻撃の最中も上がるようにif (addattacktime == 501){}の外にif文を出した。


		//キーLを押したまま別のキーを押すと武器が切り替わる



		//敵の攻撃や移動などの部分。
		if (stayhere == 0) {// 敵の移動
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

				
				if (ranndamulock == 0) {
					ranndamukougeki = GetRand(5);//★確率の間隔が小さいと敵描画されないバグが起きるので小手でいい。
					
				}
				
			
				//右からの殴る攻撃
				if (ranndamukougeki == 1 or ranndamukougeki == 3) {//GetRand(30) < 30とすると攻撃する途中でやめたり、カウンタが2を超えて上がってしまったりする。
					ranndamulock = 1;//範囲が重なるときだけ主人公と敵の位置が変わるようにした。を無効にするために1にした。
					++enemyattack;
					enemyzannzoulock2 = 1;//★enemyzannzoulock = 1;と書いていたから攻撃画像と同時に通常状態も描画されていた。正しくはenemyzannzoulock2 = 1;である
					//いままでちゃんと動いたっぽく見えたのは誤って敵1の攻撃画像を描画するための
					//if文にzannzoulockを書いていたり、
					//その他の攻撃中のこことかにzannzoulockを書いて色んな所に書いていたenemyzannzoulockがうまい具合に働いていたからだろう。
					//要はenemyzannzoulockは間違いで、正しくはenemyzannzoulock2であるため。
					
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
					enemyzannzoulock2 = 1;
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
							enemyzannzoulock2 = 1;
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
							enemyzannzoulock2 = 1;
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
							enemyzannzoulock2 = 1;
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


		}


		//敵の攻撃や移動などの部分。
			/*if (stayhere2 == 0) {// 敵の移動
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
						ranndamukougeki2 = GetRand(10);

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
			}*/

			//中に書くにしてもif (enemycount == 0)の場合を書かなかったら敵が目の前に来た、0の場合の処理を書いた方がいいようだ。攻撃以外は目の前に来るようなコードは書いていないが。
			//まあ、「0の時の場合を書いていないので不自然な動きが起きてしまった」ということも考えられる。
			//if (frames < 500) { frames = 0; }




		//ループ内に書いたenemyMoveについてenemyMoveが0より大きくて40を超えたら｛｝の中身を実行。
		//enemyMoveが0より大きいならば+1されて、40より大きい数値になれば両方の条件を満たすので+１される。40より大きい数値になったら敵の画像が変わる。
		//enemyMoveが40より+１されて大きくなるために++enemyMove > 40









			// 入力状態を取得//★if (input.RightTrigger == 255)を使う上で必要

		GetJoypadXInputState(DX_INPUT_PAD1, &input);
		//★stgae2Player_Update.hはif文の構造上if(playerkonntororulock == 0){}の中にif (R1lock == 0){}が入っていなかっただけ。
		if (R1lock == 0) {


			//R2で狙っての銃攻撃。
			if (input.RightTrigger == 255)
			{
				playerkonntororulock = 1;
				jyuuzikeysousa2 = 1;
				suraidoidou = 1;
				
				//playermovelock = 1;//★kougekilock的な奴は攻撃した時でないと値が1にならず、失敗すると値が0のままで

				//R1attack = 1;
				lock = 1;//描画のため
				++lockonMove;//描画関数に使うイメージを送るための変数
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
				// 
				// 
				//銃の切り替えの最中は銃は撃てない。
				if (Pad[PAD_5] == 1)
				{//「四角」は今押された
				  //「四角」が押されたときの処理
					Gunkirikae = 1;
					Lcount = 1;
					//LEFTmark = 133;

				}
			}

			//R2を押さない場合。
			if (input.RightTrigger == 0) {
				if (RightTriggerlock == 0) { playermovelock = 0; }
				lock = 0;
				lockmarkyokoidou = 0;
				lockmarktateidou = 0;
				jyuuzikeysousa2 = 0;
				playerkonntororulock = 0;
			}

		}




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
	}


}
//#endif
//if (kasokudo = 49) { A = 4; }
//if (function_status == 0) {//function_status = 0の時はメニュー画面でfunction_statusが1の時は戦闘画面とした。
//
