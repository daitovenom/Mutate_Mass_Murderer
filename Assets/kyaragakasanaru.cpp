

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
		LEFTmark = 9933;
		if (zannzoulock == 0) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage, TRUE); }
		//syuzinnkouDAMEGE();
		/*if (playerHPlock == 0 && playerHP <= 200) {
			//playerMove2 = 0;
			hinnsiattack = 1;
			zannzoulock = 1;

			if (playerMove3 > 0) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた
				hinsikawanarilock = 1;
				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player1GHandle[0], TRUE);  // 俺キャラの描画

			}

			if (playerMove3 > 15) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				//DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] + playerattackhanndou3, 4, 0, enemyImage, TRUE);
				//★200以下である時にenemyzannzoulockが1の時も条件を書いていないため通常状態が描画されるのでenemyzannzoulockが0という条件付きにした。
				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player2GHandle[0], TRUE);  // 俺キャラの描画


			}
			if (playerMove3 > 25) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player3GHandle[0], TRUE);  // 俺キャラの描画


			}
			if (playerMove3 > 35) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player4GHandle[0], TRUE);  // 俺キャラの描画


			}
			if (playerMove3 > 45) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player4GHandle[0], TRUE);  // 俺キャラの描画

			}
			if (playerMove3 == 55) {
				playerMove3 = 1;

			}

		}*/
		//もう一人の敵を描画
		if (stayherelock2 == 0) {
			if (anotherenemyzannzoulock == 0 && enemyzannzoukieru == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
				//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
				//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。

				//LEFTmark = 65432;
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, enemyImage3, TRUE);

			}
		}
		//敵2の攻撃を描画
		if (ENEMYkougekigazouB1frame > 0 && ++ENEMYkougekigazouB1frame < 40) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiA1Handle[0], TRUE);
			}

		}
		if (ENEMYkougekigazouB2frame > 0 && ENEMYkougekigazouB2frame < 20) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiB1Handle[0], TRUE);
			}
		}
		//敵を描画
		if (enemyzannzoulock == 0 && enemyhirumaseframe == 0 && enemyzannzoukieru == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
			//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
			//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。
			if (enemystayhere == 0) {
				//LEFTmark = 1234;
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, enemyImage2, TRUE);
			}
			//LEFTmark = 4388;
		}



		//敵1の攻撃を描画
		if (ENEMYkougekigazouA1frame > 0 && ENEMYkougekigazouA1frame < 40 && enemyzannzoukieru == 0) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiB1Handle[0], TRUE);

			}

		}
		if (ENEMYkougekigazouA2frame > 0 && ENEMYkougekigazouA2frame < 20 && enemyzannzoukieru == 0) {

			if (enemyzannzoulock2 == 0) {
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
		LEFTmark = 3344;
		if (zannzoulock == 0) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage, TRUE); }
		//syuzinnkouDAMEGE();
		/*if (playerHPlock == 0 && playerHP <= 200) {
			//playerMove2 = 0;
			hinnsiattack = 1;
			zannzoulock = 1;

			if (playerMove3 > 0) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた
				hinsikawanarilock = 1;
				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player1GHandle[0], TRUE);  // 俺キャラの描画

			}

			if (playerMove3 > 15) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				//DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] + playerattackhanndou3, 4, 0, enemyImage, TRUE);
				//★200以下である時にenemyzannzoulockが1の時も条件を書いていないため通常状態が描画されるのでenemyzannzoulockが0という条件付きにした。
				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player2GHandle[0], TRUE);  // 俺キャラの描画


			}
			if (playerMove3 > 25) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player3GHandle[0], TRUE);  // 俺キャラの描画


			}
			if (playerMove3 > 35) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player4GHandle[0], TRUE);  // 俺キャラの描画


			}
			if (playerMove3 > 45) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player4GHandle[0], TRUE);  // 俺キャラの描画

			}
			if (playerMove3 == 55) {
				playerMove3 = 1;

			}

		}*/
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
		if (ENEMYkougekigazouB1frame > 0 && ENEMYkougekigazouB1frame < 40) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiA1Handle[0], TRUE);
			}

		}
		if (ENEMYkougekigazouB2frame > 0 && ENEMYkougekigazouB2frame < 20) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiB1Handle[0], TRUE);
			}
		}
		//敵を描画
		if (enemyzannzoulock == 0 && enemyhirumaseframe == 0 && enemyzannzoukieru == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
			//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
			//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。
			if (enemystayhere == 0) {
				//LEFTmark = 1234;
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, enemyImage2, TRUE);
			}
			LEFTmark = 4388;
		}

		//敵1の攻撃を描画
		if (ENEMYkougekigazouA1frame > 0 && ENEMYkougekigazouA1frame < 40 && enemyzannzoukieru == 0) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiB1Handle[0], TRUE);

			}

		}
		if (ENEMYkougekigazouA2frame > 0 && ENEMYkougekigazouA2frame < 20 && enemyzannzoukieru == 0) {

			if (enemyzannzoulock2 == 0) {
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
		LEFTmark = 111;
		if (zannzoulock == 0) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage, TRUE); }
		//syuzinnkouDAMEGE();
		/*if (playerHPlock == 0 && playerHP <= 200) {
			//playerMove2 = 0;
			hinnsiattack = 1;
			zannzoulock = 1;

			if (playerMove3 > 0) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた
				hinsikawanarilock = 1;
				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player1GHandle[0], TRUE);  // 俺キャラの描画

			}

			if (playerMove3 > 15) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				//DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] + playerattackhanndou3, 4, 0, enemyImage, TRUE);
				//★200以下である時にenemyzannzoulockが1の時も条件を書いていないため通常状態が描画されるのでenemyzannzoulockが0という条件付きにした。
				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player2GHandle[0], TRUE);  // 俺キャラの描画


			}
			if (playerMove3 > 25) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player3GHandle[0], TRUE);  // 俺キャラの描画


			}
			if (playerMove3 > 35) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player4GHandle[0], TRUE);  // 俺キャラの描画


			}
			if (playerMove3 > 45) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player4GHandle[0], TRUE);  // 俺キャラの描画

			}
			if (playerMove3 == 55) {
				playerMove3 = 1;

			}

		}*/

		//敵を描画
		if (enemyzannzoulock == 0 && enemyhirumaseframe == 0 && enemyzannzoukieru == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
			//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
			//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。
			if (enemystayhere == 0) {
				//LEFTmark = 1234;
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, enemyImage2, TRUE);
			}
			LEFTmark = 8877;
		}

		//敵1の攻撃を描画
		if (ENEMYkougekigazouA1frame > 0 && ENEMYkougekigazouA1frame < 40 && enemyzannzoukieru == 0) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiB1Handle[0], TRUE);

			}

		}
		if (ENEMYkougekigazouA2frame > 0 && ENEMYkougekigazouA2frame < 20 && enemyzannzoukieru == 0) {

			if (enemyzannzoulock2 == 0) {
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
		if (ENEMYkougekigazouB1frame > 0 && ENEMYkougekigazouB1frame < 40) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiA1Handle[0], TRUE);
			}

		}
		if (ENEMYkougekigazouB2frame > 0 && ENEMYkougekigazouB2frame < 20) {

			if (enemyzannzoulock2 == 0) {
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
		LEFTmark = 333;
		if (zannzoulock == 0) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage, TRUE); }
		//syuzinnkouDAMEGE();
		/*if (playerHPlock == 0 && playerHP <= 200) {
			//playerMove2 = 0;
			hinnsiattack = 1;
			zannzoulock = 1;

			if (playerMove3 > 0) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた
				hinsikawanarilock = 1;
				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player1GHandle[0], TRUE);  // 俺キャラの描画

			}

			if (playerMove3 > 15) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				//DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] + playerattackhanndou3, 4, 0, enemyImage, TRUE);
				//★200以下である時にenemyzannzoulockが1の時も条件を書いていないため通常状態が描画されるのでenemyzannzoulockが0という条件付きにした。
				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player2GHandle[0], TRUE);  // 俺キャラの描画


			}
			if (playerMove3 > 25) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player3GHandle[0], TRUE);  // 俺キャラの描画


			}
			if (playerMove3 > 35) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player4GHandle[0], TRUE);  // 俺キャラの描画


			}
			if (playerMove3 > 45) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player4GHandle[0], TRUE);  // 俺キャラの描画

			}
			if (playerMove3 == 55) {
				playerMove3 = 1;

			}

		}*/
		//敵を描画
		if (enemyzannzoulock == 0 && enemyhirumaseframe == 0 && enemyzannzoukieru == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
			//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
			//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。
			if (enemystayhere == 0) {
				//LEFTmark = 1234;
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, enemyImage2, TRUE);
			}
			LEFTmark = 5555;
		}

		//敵1の攻撃を描画
		if (ENEMYkougekigazouA1frame > 0 && ENEMYkougekigazouA1frame < 40 && enemyzannzoukieru == 0) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiB1Handle[0], TRUE);

			}

		}
		if (ENEMYkougekigazouA2frame > 0 && ENEMYkougekigazouA2frame < 20 && enemyzannzoukieru == 0) {

			if (enemyzannzoulock2 == 0) {
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
		if (ENEMYkougekigazouB1frame > 0 && ENEMYkougekigazouB1frame < 40) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiA1Handle[0], TRUE);
			}

		}
		if (ENEMYkougekigazouB2frame > 0 && ENEMYkougekigazouB2frame < 20) {

			if (enemyzannzoulock2 == 0) {
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
		if (ENEMYkougekigazouB1frame > 0 && ++ENEMYkougekigazouB1frame < 40) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiA1Handle[0], TRUE);
			}

		}
		if (ENEMYkougekigazouB2frame > 0 && ENEMYkougekigazouB2frame < 20) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiB1Handle[0], TRUE);
			}
		}
		LEFTmark = 9989898;
		if (zannzoulock == 0) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage, TRUE); }
		//syuzinnkouDAMEGE();
		/*if (playerHPlock == 0 && playerHP <= 200) {
			//playerMove2 = 0;
			hinnsiattack = 1;
			zannzoulock = 1;

			if (playerMove3 > 0) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた
				hinsikawanarilock = 1;
				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player1GHandle[0], TRUE);  // 俺キャラの描画

			}

			if (playerMove3 > 15) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				//DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] + playerattackhanndou3, 4, 0, enemyImage, TRUE);
				//★200以下である時にenemyzannzoulockが1の時も条件を書いていないため通常状態が描画されるのでenemyzannzoulockが0という条件付きにした。
				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player2GHandle[0], TRUE);  // 俺キャラの描画


			}
			if (playerMove3 > 25) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player3GHandle[0], TRUE);  // 俺キャラの描画


			}
			if (playerMove3 > 35) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player4GHandle[0], TRUE);  // 俺キャラの描画


			}
			if (playerMove3 > 45) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player4GHandle[0], TRUE);  // 俺キャラの描画

			}
			if (playerMove3 == 55) {
				playerMove3 = 1;

			}

		}*/

		syuzinkoukougekigazou();
		if (enemyzannzoulock == 0 && enemyhirumaseframe == 0 && enemyzannzoukieru == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
			//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
			//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。
			if (enemystayhere == 0) {
				//LEFTmark = 1234;
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, enemyImage2, TRUE);

				//DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY2][enemyX2][1] + playerattackhanndou3, bairituY2, 0, enemyImage, TRUE);
			}
		}

		//敵1の攻撃を描画
		if (ENEMYkougekigazouA1frame > 0 && ENEMYkougekigazouA1frame < 40 && enemyzannzoukieru == 0) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiB1Handle[0], TRUE);

			}

		}
		if (ENEMYkougekigazouA2frame > 0 && ENEMYkougekigazouA2frame < 20 && enemyzannzoukieru == 0) {

			if (enemyzannzoulock2 == 0) {
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
		if (ENEMYkougekigazouB1frame > 0 && ++ENEMYkougekigazouB1frame < 40) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiA1Handle[0], TRUE);
			}

		}
		if (ENEMYkougekigazouB2frame > 0 && ENEMYkougekigazouB2frame < 20) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiB1Handle[0], TRUE);
			}
		}
		LEFTmark = 9989898;
		if (zannzoulock == 0) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage, TRUE); }
		//syuzinnkouDAMEGE();
		/*if (playerHPlock == 0 && playerHP <= 200) {
			//playerMove2 = 0;
			hinnsiattack = 1;
			zannzoulock = 1;

			if (playerMove3 > 0) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた
				hinsikawanarilock = 1;
				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player1GHandle[0], TRUE);  // 俺キャラの描画

			}

			if (playerMove3 > 15) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				//DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] + playerattackhanndou3, 4, 0, enemyImage, TRUE);
				//★200以下である時にenemyzannzoulockが1の時も条件を書いていないため通常状態が描画されるのでenemyzannzoulockが0という条件付きにした。
				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player2GHandle[0], TRUE);  // 俺キャラの描画


			}
			if (playerMove3 > 25) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player3GHandle[0], TRUE);  // 俺キャラの描画


			}
			if (playerMove3 > 35) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player4GHandle[0], TRUE);  // 俺キャラの描画


			}
			if (playerMove3 > 45) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player4GHandle[0], TRUE);  // 俺キャラの描画

			}
			if (playerMove3 == 55) {
				playerMove3 = 1;

			}

		}*/
		syuzinkoukougekigazou();
		if (enemyzannzoulock == 0 && enemyhirumaseframe == 0 && enemyzannzoukieru == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
			//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
			//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。
			if (enemystayhere == 0) {
				//LEFTmark = 1234;
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, enemyImage2, TRUE);

				//DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY2][enemyX2][1] + playerattackhanndou3, bairituY2, 0, enemyImage, TRUE);
			}
		}

		//敵1の攻撃を描画
		if (ENEMYkougekigazouA1frame > 0 && ENEMYkougekigazouA1frame < 40 && enemyzannzoukieru == 0) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiB1Handle[0], TRUE);

			}

		}
		if (ENEMYkougekigazouA2frame > 0 && ENEMYkougekigazouA2frame < 20 && enemyzannzoukieru == 0) {

			if (enemyzannzoulock2 == 0) {
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
		if (ENEMYkougekigazouB1frame > 0 && ENEMYkougekigazouB1frame < 40) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiA1Handle[0], TRUE);
			}

		}
		if (ENEMYkougekigazouB2frame > 0 && ENEMYkougekigazouB2frame < 20) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiB1Handle[0], TRUE);
			}
		}
		//敵を描画
		if (enemyzannzoulock == 0 && enemyhirumaseframe == 0 && enemyzannzoukieru == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
		//	//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
			//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。
			if (enemystayhere == 0) {
				//LEFTmark = 1234;
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, enemyImage2, TRUE);
			}
			LEFTmark = 711117;
		}
		//敵1の攻撃を描画
		if (ENEMYkougekigazouA1frame > 0 && ENEMYkougekigazouA1frame < 40 && enemyzannzoukieru == 0) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiB1Handle[0], TRUE);

			}

		}
		if (ENEMYkougekigazouA2frame > 0 && ENEMYkougekigazouA2frame < 20 && enemyzannzoukieru == 0) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiA1Handle[0], TRUE);

			}

		}

		if (zannzoulock == 0) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage, TRUE); }
		//syuzinnkouDAMEGE();
		/*if (playerHPlock == 0 && playerHP <= 200) {
			//playerMove2 = 0;
			hinnsiattack = 1;
			zannzoulock = 1;

			if (playerMove3 > 0) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた
				hinsikawanarilock = 1;
				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player1GHandle[0], TRUE);  // 俺キャラの描画

			}

			if (playerMove3 > 15) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				//DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] + playerattackhanndou3, 4, 0, enemyImage, TRUE);
				//★200以下である時にenemyzannzoulockが1の時も条件を書いていないため通常状態が描画されるのでenemyzannzoulockが0という条件付きにした。
				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player2GHandle[0], TRUE);  // 俺キャラの描画


			}
			if (playerMove3 > 25) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player3GHandle[0], TRUE);  // 俺キャラの描画


			}
			if (playerMove3 > 35) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player4GHandle[0], TRUE);  // 俺キャラの描画


			}
			if (playerMove3 > 45) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player4GHandle[0], TRUE);  // 俺キャラの描画

			}
			if (playerMove3 == 55) {
				playerMove3 = 1;

			}

		}*/
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
		if (enemyzannzoulock == 0 && enemyhirumaseframe == 0 && enemyzannzoukieru == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
		//	//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
			//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。
			if (enemystayhere == 0) {
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, enemyImage2, TRUE);
			}
			LEFTmark = 11011;
		}
		//敵1の攻撃を描画
		if (ENEMYkougekigazouA1frame > 0 && ENEMYkougekigazouA1frame < 40 && enemyzannzoukieru == 0) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiB1Handle[0], TRUE);

			}

		}
		if (ENEMYkougekigazouA2frame > 0 && ENEMYkougekigazouA2frame < 20 && enemyzannzoukieru == 0) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiA1Handle[0], TRUE);

			}

		}

		if (zannzoulock == 0) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage, TRUE); }
		//syuzinnkouDAMEGE();
		/*if (playerHPlock == 0 && playerHP <= 200) {
			//playerMove2 = 0;
			hinnsiattack = 1;
			zannzoulock = 1;

			if (playerMove3 > 0) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた
				hinsikawanarilock = 1;
				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player1GHandle[0], TRUE);  // 俺キャラの描画

			}

			if (playerMove3 > 15) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				//DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] + playerattackhanndou3, 4, 0, enemyImage, TRUE);
				//★200以下である時にenemyzannzoulockが1の時も条件を書いていないため通常状態が描画されるのでenemyzannzoulockが0という条件付きにした。
				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player2GHandle[0], TRUE);  // 俺キャラの描画


			}
			if (playerMove3 > 25) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player3GHandle[0], TRUE);  // 俺キャラの描画


			}
			if (playerMove3 > 35) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player4GHandle[0], TRUE);  // 俺キャラの描画


			}
			if (playerMove3 > 45) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player4GHandle[0], TRUE);  // 俺キャラの描画

			}
			if (playerMove3 == 55) {
				playerMove3 = 1;

			}

		}*/
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
		if (ENEMYkougekigazouB1frame > 0 && ENEMYkougekigazouB1frame < 40) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiA1Handle[0], TRUE);
			}

		}
		if (ENEMYkougekigazouB2frame > 0 && ENEMYkougekigazouB2frame < 20) {

			if (enemyzannzoulock2 == 0) {
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
		if (enemyzannzoulock == 0 && enemyhirumaseframe == 0 && enemyzannzoukieru == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
		//	//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
			//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。
			if (enemystayhere == 0) {
				//LEFTmark = 1234;
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, enemyImage2, TRUE);
			}
			LEFTmark = 99999;
		}

		//敵1の攻撃を描画
		if (ENEMYkougekigazouA1frame > 0 && ENEMYkougekigazouA1frame < 40 && enemyzannzoukieru == 0) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiB1Handle[0], TRUE);

			}

		}
		if (ENEMYkougekigazouA2frame > 0 && ENEMYkougekigazouA2frame < 20 && enemyzannzoukieru == 0) {

			if (enemyzannzoulock2 == 0) {
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
		if (ENEMYkougekigazouB1frame > 0 && ENEMYkougekigazouB1frame < 40) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiA1Handle[0], TRUE);
			}

		}
		if (ENEMYkougekigazouB2frame > 0 && ENEMYkougekigazouB2frame < 20) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiB1Handle[0], TRUE);
			}
		}

		if (zannzoulock == 0) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage, TRUE); }
		//syuzinnkouDAMEGE();
		
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
		if (enemyzannzoulock == 0 && enemyhirumaseframe == 0 && enemyzannzoukieru == 0) {//カウンターを食らった際に主人公がアナログパッドで初期位置に戻ると敵の残像が0になる。
		//	//そうするとカウンターを食らってる最中なのに敵の画像が描画されてしまう。なので、enemyhirumaseframe == 0を付け足した。
			//多分if (enemyzannzoulockframe > 25)で主人公の攻撃によって早くenemyzannzoulockが0になってしまうのだと思う。
			if (enemystayhere == 0) {
				//LEFTmark = 1234;
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, enemyImage2, TRUE);
			}
			LEFTmark = 99999;
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



		//if (zannzoulock == 0) { DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerImage, TRUE); }
		//syuzinnkouDAMEGE();
		/*if (playerHPlock == 0 && playerHP <= 200) {
			//playerMove2 = 0;
			hinnsiattack = 1;
			zannzoulock = 1;

			if (playerMove3 > 0) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた
				hinsikawanarilock = 1;
				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player1GHandle[0], TRUE);  // 俺キャラの描画

			}

			if (playerMove3 > 15) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				//DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] + playerattackhanndou3, 4, 0, enemyImage, TRUE);
				//★200以下である時にenemyzannzoulockが1の時も条件を書いていないため通常状態が描画されるのでenemyzannzoulockが0という条件付きにした。
				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player2GHandle[0], TRUE);  // 俺キャラの描画


			}
			if (playerMove3 > 25) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player3GHandle[0], TRUE);  // 俺キャラの描画


			}
			if (playerMove3 > 35) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player4GHandle[0], TRUE);  // 俺キャラの描画


			}
			if (playerMove3 > 45) {//下に書いているように60フレームないに納めないといけないため、50まで上がったところで終わっている。もともと60 * 4と書いた

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, player4GHandle[0], TRUE);  // 俺キャラの描画

		}
			if (playerMove3 == 55) {
				playerMove3 = 1;

			}

		}*/
		//敵1の攻撃を描画
		if (ENEMYkougekigazouA1frame > 0 && ENEMYkougekigazouA1frame < 40 && enemyzannzoukieru == 0) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiB1Handle[0], TRUE);

			}

		}
		if (ENEMYkougekigazouA2frame > 0 && ENEMYkougekigazouA2frame < 20 && enemyzannzoukieru == 0) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 - 50, pos[enemyY1][enemyX1][1] + playerattackhanndou3 - 30, bairituY, 0, STAGE2ENEMY1kougekiA1Handle[0], TRUE);

			}

		}


		//敵2の攻撃を描画
		if (ENEMYkougekigazouB1frame > 0 && ENEMYkougekigazouB1frame < 40) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiA1Handle[0], TRUE);
			}

		}
		if (ENEMYkougekigazouB2frame > 0 && ENEMYkougekigazouB2frame < 20) {

			if (enemyzannzoulock2 == 0) {
				UEsuraido();
				DrawRotaGraph(pos[enemyY2][enemyX2][0] + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B - 50, pos[enemyY2][enemyX2][1] + playerattackhanndou3B - 30, bairituY2, 0, STAGE2ENEMY2kougekiB1Handle[0], TRUE);
			}
		}
		syuzinkoukougekigazou();

	}

