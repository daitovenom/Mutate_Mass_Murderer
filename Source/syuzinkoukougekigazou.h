

#ifndef DEF_syuzinkoukougekigazou_H //二重include防止

#define DEF_syuzinkoukougekigazou_H



void syuzinkoukougekigazou() {
	if (playerkonntororulock == 0) {
		//if (motonomasunimodoru > 10) {//これをやっても10になった瞬間に殴る2をやって残像が1のままになるの場合を考えると意味がないので、いらない。
			//185行目の方が有効。

		//ステージ1の老婆とステージ2のボデーブロー右向きに殴る攻撃//

		//右向きと左向きの描画画像の部分//左向きは138行目から。
			if (migimuki == 1) {
				//殴る攻撃の画像を扱う部分。//★配列のままでは値が保てないため、lockImge = lockonHandle[1]のようImageでまとめて書かないといけないのかも。
				if (nagurugazou > 0) {//描画関数にそのままplayernaguruAGHandle[0]をぶち込んで書くと==の時しか描画されない。
					//★描画関数を使って==の方法で書いてもいいが、if (nagurugazou>0&& nagurugazou<20)と範囲で書いたほうがちらつきがない。
					++nagurugazou;
					//zannzoulock = 1;//攻撃画像がでてるときは通常の画像を消すので値を1に変更する。
					tabakolock = 1;//★★殴る中はタバコを吸ったり、主人公が殴っていない際も描画されるようにするためにここでtabakokirikaeを1にする。
					DrawRotaGraph(pos[playerY][playerX][0] + 20 + (70) + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playernaguruImage, TRUE);
					tabakosutterulock = 1;


					Xbotannlock = 1;//ボタンの連打をすると血しぶきの画像に到達する前に画像が切り替わるので、連打できないようにするための変数。
				}if (nagurugazou > 0 && nagurugazou < 20) {//殴るフレームはこれくらいでいい
					playernaguruImage = playernaguruAGHandle[0];
					//StartJoypadVibration(DX_INPUT_PAD1, 400, 200);
				}
				if (nagurugazou > 20 && nagurugazou < 35) {
					playernaguruImage = playernaguruBGHandle[0];
				}
				if (nagurugazou2 > 0) {
					nagurugazou = 0;//二発目を打つときは一発目が描画されないように消す。
					playerHPlock = 1;
					++nagurugazou2;
					zannzoulock = 1;//攻撃画像がでてるときは通常の画像を消すので値を1に変更する。
					tabakolock = 1;//★★殴る中はタバコを吸ったり、主人公が殴っていない際も描画されるようにするためにここでtabakokirikaeを1にする。
					
					//部分はいらないif (nagurugazou2 > 0 && nagurugazou2 < 30)で書いてあるので
					//DrawRotaGraph(pos[playerY][playerX][0] + 20 + (70) + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playernaguruImage, TRUE);
					tabakosutterulock = 1;

				}

				//ボデーブローの描画。
				if (nagurugazou2 > 0 && nagurugazou2 < 30) {
					playernaguruImage = playernaguruBGHandle2[0];
					DrawRotaGraph(pos[playerY][playerX][0] + 20 + (70) + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playernaguruImage, TRUE);


				}
				if (nagurugazou2 > 30 && nagurugazou2 < 60) {

					if (nagurugazou2 > 58 && nagurugazou2 < 60)
					{
						//enemysabunHP = 20;
					}//殴るの二発目の攻撃


					playernaguruImage = playernaguruBGHandle3[0];
					DrawRotaGraph(pos[playerY][playerX][0] + 20 + (70) + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playernaguruImage, TRUE);


				}

				//ステージ1の老婆とステージのふたりをを殴るプログラムの続き//
				if (nagurugazou > 35) {
					nagurugazou = 0;
					zannzoulock = 0;
					Xbotannlock = 0;
					tabakolock = 0;
					playerHPlock = 0;
					//playermovelock = 0;//バグ対策のためにここで0にする。
					tabakosutterulock = 0;
					nextattack = 0;//ここで0になっているためアッパーでのif文が0で良いのだ。
					//if (playerHP < 400) {
					//	playerHPlock = 0;//HPが少ない際に元の位置に戻る際にダメージ判定の通常状態に戻る。
					//}
					//kougekikannkaku = 0;
					attackframeA = 0;//①
				}
				if (nagurugazou2 > 60) {
					attackframe = 0;//★attackframeが80を超える前に二発目のパンチで0になってしまい、attackframeAが1のままになるので
					//上の①で0にする。
					nagurugazou = 0;
					nagurugazou2 = 0;
					zannzoulock = 0;
					Xbotannlock = 0;
					tabakolock = 0;
					playerHPlock = 0;
					//playermovelock = 0;//バグ対策のためにここで0にする。
					tabakosutterulock = 0;
					nextattack = 0;

				}
				
				//ステージ2の男二人に対する殴る攻撃//

				//一人目への殴る攻撃
				if (kougekiKANOU == 2 && stage2damage == 1) {
					if (nagurugazou2 > 58 && nagurugazou2 < 60) {
						//nagurusound = LoadSoundMem("殴る音.mp3");
						//PlaySoundMem(nagurusound, DX_PLAYTYPE_BACK);
						//nanameidouX = nanameidouX + 20;
						enemysabunHP = 30;
						playerHPlock = 0;
						playerattackhanndou = playerattackhanndou + 30;//敵が奥に進む
						enemyzannzoulockframe1 = 1;//相手のダメージを食らった際の怯みを初期に戻すため
						stayhereframe = 1;
						bloodMove = 1;
						kakuninn = 25;
						
					}
				}//もう一人への殴る攻撃。
				if (kougekiKANOU == 3 && stage2damage == 1) {
					if (nagurugazou2 > 58 && nagurugazou2 < 60) {
						//nagurusound = LoadSoundMem("殴る音.mp3");
						//PlaySoundMem(nagurusound, DX_PLAYTYPE_BACK);
						//nanameidouX = nanameidouX + 20;
						anotherenemysabunHP = 30;
						playerHPlock = 0;
						playerattackhanndouB = playerattackhanndouB + 30;//敵が奥に進む
						enemyzannzoulockBframe = 1;//相手のダメージを食らった際の怯みを初期に戻すため
						stayhere2frame = 1;
						bloodMove = 1;
					}
				}


				
			}


			//ステージ1の老婆と青い服の敵と赤い服の敵に対する左向きにボデーブローする攻撃//
			if (hidarimuki == 1) {
				//殴る攻撃の画像を扱う部分。//★配列のままでは値が保てないため、lockImge = lockonHandle[1]のようImageでまとめて書かないといけないのかも。
				if (nagurugazou > 0) {//描画関数にそのままplayernaguruAGHandle[0]をぶち込んで書くと==の時しか描画されない。
					//★描画関数を使って==の方法で書いてもいいが、if (nagurugazou>0&& nagurugazou<20)と範囲で書いたほうがちらつきがない。
					++nagurugazou;
					//zannzoulock = 1;//攻撃画像がでてるときは通常の画像を消すので値を1に変更する。
					tabakolock = 1;//★★殴る中はタバコを吸ったり、主人公が殴っていない際も描画されるようにするためにここでtabakokirikaeを1にする。
					DrawRotaGraph(pos[playerY][playerX][0] + 20 + (30) + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playernaguruImage, TRUE);
					tabakosutterulock = 1;
					point = 12;

					Xbotannlock = 1;//ボタンの連打をすると血しぶきの画像に到達する前に画像が切り替わるので、連打できないようにするための変数。
				}if (nagurugazou > 0 && nagurugazou < 20) {//殴るフレームはこれくらいでいい
					playernaguruImage = playernaguruAGHandleB[0];
					//StartJoypadVibration(DX_INPUT_PAD1, 400, 200);
				}
				if (nagurugazou > 20 && nagurugazou < 35) {
					playernaguruImage = playernaguruBGHandleB[0];
				}
				if (nagurugazou2 > 0) {
					nagurugazou = 0;//二発目を打つときは一発目が描画されないように消す。
					playerHPlock = 1;
					++nagurugazou2;//★かすり攻撃の後にここで殴るが上がってしまうからかすり攻撃なのにダメージがはいってしまう？
					zannzoulock = 1;//攻撃画像がでてるときは通常の画像を消すので値を1に変更する。
					tabakolock = 1;//★★殴る中はタバコを吸ったり、主人公が殴っていない際も描画されるようにするためにここでtabakokirikaeを1にする。
					
					//部分はいらないif (nagurugazou2 > 0 && nagurugazou2 < 30)で書いてあるので
					//DrawRotaGraph(pos[playerY][playerX][0] + 20 + (30) + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playernaguruImage, TRUE);
					tabakosutterulock = 1;

				}
				if (nagurugazou2 > 0 && nagurugazou2 < 30) {
					playernaguruImage = playernaguruBGHandle2B[0];
					DrawRotaGraph(pos[playerY][playerX][0] + 20 + (30) + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playernaguruImage, TRUE);


				}
				if (nagurugazou2 > 30 && nagurugazou2 < 60) {
					if (nagurugazou2 > 58 && nagurugazou2 < 60)
					{
						//enemysabunHP = 20;//ここでかすりかすり攻撃で上がったnagurugazou2により反応して
						//かすり攻撃なのにダメージを与えてしまっていた。
						point2 = 18;
					}//殴るの二発目の攻撃

					playernaguruImage = playernaguruBGHandle3B[0];
					DrawRotaGraph(pos[playerY][playerX][0] + 20 + (30) + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playernaguruImage, TRUE);


				}
				if (kougekiKANOU == 2) {
					if (nagurugazou2 > 58 && nagurugazou2 < 60) {
						//nagurusound = LoadSoundMem("殴る音.mp3");
						//PlaySoundMem(nagurusound, DX_PLAYTYPE_BACK);
						//nanameidouX = nanameidouX + 20;
						enemysabunHP = 30;
						playerHPlock = 0;
						playerattackhanndou = playerattackhanndou - 30;//敵が奥に進む
						enemyzannzoulockframe1 = 1;//相手のダメージを食らった際の怯みを初期に戻すため
						stayhereframe = 1;
						bloodMove = 1;
						kakuninn = 56;
					}
				}
				if (nagurugazou > 35) {
					nagurugazou = 0;
					zannzoulock = 0;
					Xbotannlock = 0;
					tabakolock = 0;
					playerHPlock = 0;
					//playermovelock = 0;//バグ対策のためにここで0にする。
					tabakosutterulock = 0;
					nextattack = 0;//ここで0になっているためアッパーでのif文が0で良いのだ。
					//if (playerHP < 400) {
					//	playerHPlock = 0;//HPが少ない際に元の位置に戻る際にダメージ判定の通常状態に戻る。
					//}
					//kougekikannkaku = 0;
					attackframeA = 0;//①
				}
				if (nagurugazou2 > 60) {
					nagurugazou = 0;
					attackframe = 0;//★attackframeが80を超える前に二発目のパンチで0になってしまい、attackframeAが1のままになるので
					//上の①で0にする。
					nagurugazou = 0;
					nagurugazou2 = 0;
					//★多分motonomasunimodoru が0になる瞬間に殴るをしているとzannzoulockは１のままになってしまうので、ここで強制的に0にする。
					//if (motonomasunimodoru == 0) {
					//	zannzoulock = 0;
					//}
					Xbotannlock = 0;
					tabakolock = 0;
					playerHPlock = 0;
					//playermovelock = 0;//バグ対策のためにここで0にする。
					tabakosutterulock = 0;
					nextattack = 0;
					zannzoulock = 0;
				}
				if (nagurugazou2 > 35 && nagurugazou2 < 60) {
					zannzoulock = 1;
				}

			}
		//}
		//motonomasunimodoruが0になる前にnagurugazouやnagurugazou2の値が0に行かないとzannzoulockが1のままなのでここで0にする。
		//if (motonomasunimodoru == 0 && Gtime == 0 && tabakocount == 0) {
		//	if (nagurugazou2 == 0 or nagurugazou == 0) {
		//		zannzoulock = 0;
		//	}
		//}

		//殴る攻撃での間隔のプログラム。
		//if (nagurugazou == 16) {//★nagurugazou == 1にすると、kougekikannkakulockを1にしてロックしたはずが先に進んでしまい再び、殴るになってしまう。
		//	//なので、あえて、処理の終了する16の部分を選んだ。
		//	nagurugazoulock = 1;
		//	kougekikannkakulock = 1;
		//	++kougekikannkaku;
		//	zannzoulock = 0;
		//}//★攻撃を与える瞬間は他の処理も動くため、かすり攻撃の時よりは少し遅くなるが、それは仕方ないのかもしれない。
		//if (nagurugazoulock == 1) {
		//	++kougekikannkaku;
		//}
		//if (kougekikannkaku > 4) {
		//	nagurugazoulock = 0;
		//	kougekikannkakulock = 0;
		//	kougekikannkaku = 0;
		//}



		//タバコ回復の描画の部分
		if (tabakokasanari == 0) {
			
			if (tabakocount2 > 0) {
				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playertabakoImage, TRUE);
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
			if (tabakocount2 > 0 && tabakocount2 < 100) {
				StartJoypadVibration(DX_INPUT_PAD1, 100, 200);
			}
		}
		//if (pos[enemyY1][enemyX1][0] + 200 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX &&
		//	pos[enemyY1][enemyX1][0] - 200 + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX
		//	&& pos[enemyY1][enemyX1][1] + playerattackhanndou3 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5) {
		//	tabakokasanari = 1;
		//}
		//else if (pos[enemyY2][enemyX2][0] + 200 + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX &&
		//	pos[enemyY2][enemyX2][0] - 200 + playerattackhanndouB + playerattackhanndou2B + playerattackhanndou3B < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX
		//	&& pos[enemyY2][enemyX2][1] + playerattackhanndou3B > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5) {
		//	tabakokasanari = 1;
		//}
		//else {
		//	tabakokasanari = 0;
		//}

		//★★敵と重なり描画されていしまう問題の解決の方法。
		//他のタバコを吸うプログラムで通常状態の主人公が描画されないようにzannzoulockが1になり、
		//playertabakoImageに値が入るようになっているので以下のように書くだけでいいのだ。その前の時はタバコを吸う画像は最後に書いていたので
		//敵を越してタバコを吸う画像を描画してしまっていた。しかし、そのタバコを吸う画像を超えて、if文で敵の画像を改めて描画したので
		//敵を超えることなく、書いた通りに描画された。

		//R1lockの事情ですぐに0になってしまうので++されない、なので押すことで他の値が伸びるようにした。

		if (migimuki == 1) {
			if (KONNBO1A > 0) {
				tabakosutterulock = 1;
				++KONNBO1Aframe;
				//playerHPlock = 0;//HPが少ない際の通常状態の画像を消す。
				//if (playerHP < 400) {
				//	playerHPlock = 1;//HPが少ない際に元の位置に戻る際にダメージ判定の通常状態に戻る。
				//}
			}
			if (KONNBO1Aframe > 0) {
				//LEFTmark = 200;
				zannzoulock = 1;
				//X座標を+100して、相手に踏み込む感じにした。
				//DrawRotaGraph(pos[playerY][playerX][0], pos[playerY][playerX][1], 5, 0, playerKONNBO1AHandle[0], TRUE);

				if (KONNBO1Aframe > 0) {


					DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerKONNBO1AHandle[0], TRUE);

				}
				if (KONNBO1Aframe > 6) {

					DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerKONNBO1ANOIZU1Handle[0], TRUE);

				}
				if (KONNBO1Aframe > 12) {

					DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerKONNBO1ANOIZU2Handle[0], TRUE);

				}
				if (KONNBO1Aframe > 18) {

					DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerKONNBO1ANOIZU3Handle[0], TRUE);

				}
				if (KONNBO1Aframe > 24) {

					DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerKONNBO1ANOIZU4Handle[0], TRUE);

				}//DrawExtendGraph(pos[playerY][playerX][0]-40, pos[playerY][playerX][1]-70, pos[playerY][playerX][0]+80, pos[playerY][playerX][1]+70, K1Handle, TRUE);
			}

			if (KONNBO1Aframe > 24) {
				KONNBO1A = 0;//どうせ最後のアドが0に成ったらこいつも0になるので。
				KONNBO1Aframe = 0;
				zannzoulock = 0;//30を超えたら元の画像に戻る。
				kougekilock = 1;//コンボ入力が成功した際に再びコンボを決めたい際に上のYボタンのif文を通過できるように
				//playermovelock = 0;
				tabakosutterulock = 0;
				nextattack = 0;//コンボが失敗した場合も次の攻撃ができるように0にする。
				//if (playerHP < 400) {
				//	playerHPlock = 0;//HPが少ない際に元の位置に戻る際にダメージ判定の通常状態に戻る。
				//}

			}
			//蹴り攻撃の最後の蹴り上げる画像において。
			if (KONNBO1B > 0) {
				tabakosutterulock = 1;
				KONNBO1Aframe = 0;
				++KONNBO1Bframe;
				zannzoulock = 1;
				attackframe2 = 0;//if (attackframe2 > 20)の場合に進まないようにこっちにきたらattackframe2は0にしていく。
				//KONNBO1Aframe1 = 0;//コンボが決まった際にKONNBO1Aでの画像が消えるように。
				//X座標を+100して、相手に踏み込む感じにした。

				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerKONNBO1BHandle[0], TRUE);

				//StartJoypadVibration(DX_INPUT_PAD1, 1000, 500);

				//if (playerHP < 400) {
					//playerHPlock = 0;//HPが少ない際に元の位置に戻る際にダメージ判定の通常状態に戻る。
				//}
			}

			if (KONNBO1Bframe > 20) {
				playerHPlock = 0;
				KONNBO1B = 0;
				KONNBO1Bframe = 0;
				zannzoulock = 0;//30を超えたら元の画像に戻る。
				//kougekilock = 1;//コンボ入力が成功した際に再びコンボを決めたい際に上のYボタンのif文を通過できるように
				KONNBO1A = 0;//けり上げる時に、蹴る前の画像を描画しないように
				//playermovelock = 0;
				tabakosutterulock = 0;
				//if (playerHP < 400) {
				//	playerHPlock = 0;//HPが少ない際に元の位置に戻る際にダメージ判定の通常状態に戻る。
				//}
				nextattack = 0;
			}
		}
		else if (hidarimuki == 1) {
			if (KONNBO1A > 0) {
				tabakosutterulock = 1;
				++KONNBO1Aframe;
				//playerHPlock = 0;//HPが少ない際の通常状態の画像を消す。
				//if (playerHP < 400) {
				//	playerHPlock = 1;//HPが少ない際に元の位置に戻る際にダメージ判定の通常状態に戻る。
				//}
			}
			if (KONNBO1Aframe > 0) {
				//LEFTmark = 200;
				zannzoulock = 1;
				//X座標を+100して、相手に踏み込む感じにした。
				//DrawRotaGraph(pos[playerY][playerX][0], pos[playerY][playerX][1], 5, 0, playerKONNBO1AHandle[0], TRUE);

				if (KONNBO1Aframe > 0) {


					DrawRotaGraph(pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerKONNBO1AHandleB[0], TRUE);

				}
				if (KONNBO1Aframe > 6) {

					DrawRotaGraph(pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerKONNBO1ANOIZU1HandleB[0], TRUE);

				}
				if (KONNBO1Aframe > 12) {

					DrawRotaGraph(pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerKONNBO1ANOIZU2HandleB[0], TRUE);

				}
				if (KONNBO1Aframe > 18) {

					DrawRotaGraph(pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerKONNBO1ANOIZU3HandleB[0], TRUE);

				}
				if (KONNBO1Aframe > 24) {

					DrawRotaGraph(pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerKONNBO1ANOIZU4HandleB[0], TRUE);

				}//DrawExtendGraph(pos[playerY][playerX][0]-40, pos[playerY][playerX][1]-70, pos[playerY][playerX][0]+80, pos[playerY][playerX][1]+70, K1Handle, TRUE);
			}

			if (KONNBO1Aframe > 24) {
				KONNBO1A = 0;//どうせ最後のアドが0に成ったらこいつも0になるので。
				KONNBO1Aframe = 0;
				zannzoulock = 0;//30を超えたら元の画像に戻る。
				kougekilock = 1;//コンボ入力が成功した際に再びコンボを決めたい際に上のYボタンのif文を通過できるように
				//playermovelock = 0;
				tabakosutterulock = 0;
				nextattack = 0;//コンボが失敗した場合も次の攻撃ができるように0にする。
				//if (playerHP < 400) {
				//	playerHPlock = 0;//HPが少ない際に元の位置に戻る際にダメージ判定の通常状態に戻る。
				//}

			}
			//蹴り攻撃の最後の蹴り上げる画像において。
			if (KONNBO1B > 0) {
				tabakosutterulock = 1;
				KONNBO1Aframe = 0;
				++KONNBO1Bframe;
				zannzoulock = 1;
				attackframe2 = 0;//if (attackframe2 > 20)の場合に進まないようにこっちにきたらattackframe2は0にしていく。
				//KONNBO1Aframe1 = 0;//コンボが決まった際にKONNBO1Aでの画像が消えるように。
				//X座標を+100して、相手に踏み込む感じにした。

				DrawRotaGraph(pos[playerY][playerX][0] - 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playerKONNBO1BHandleB[0], TRUE);

				//StartJoypadVibration(DX_INPUT_PAD1, 1000, 500);

				//if (playerHP < 400) {
					//playerHPlock = 0;//HPが少ない際に元の位置に戻る際にダメージ判定の通常状態に戻る。
				//}
			}

			if (KONNBO1Bframe > 20) {
				playerHPlock = 0;
				KONNBO1B = 0;
				KONNBO1Bframe = 0;
				zannzoulock = 0;//30を超えたら元の画像に戻る。
				//kougekilock = 1;//コンボ入力が成功した際に再びコンボを決めたい際に上のYボタンのif文を通過できるように
				KONNBO1A = 0;//けり上げる時に、蹴る前の画像を描画しないように
				//playermovelock = 0;
				tabakosutterulock = 0;
				//if (playerHP < 400) {
				//	playerHPlock = 0;//HPが少ない際に元の位置に戻る際にダメージ判定の通常状態に戻る。
				//}
				nextattack = 0;
			}
		}
		//刀
		if (migimuki == 1) {
			if (attackframe4 > 0 && ++attackframe4 < 120) {
				zannzoulock = 1;
				if (attackframe4 > 0 && attackframe4 < 40) {
					DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 18 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, KATANA[0], TRUE);

				}
				if (attackframe4 > 40 && attackframe4 < 80) {
					DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 18 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, KATANA2[0], TRUE);

				}
				if (attackframe4 > 80 && attackframe4 < 110) {
					DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 18 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, KATANA3A[0], TRUE);
					LEFTmark2 = 123;
				}
			}
			if (attackframe5 > 0 && ++attackframe5 < 50) {
				DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 18 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, KATANA3[0], TRUE);
			}
		}
		else if (hidarimuki == 1) {
			if (attackframe4 > 0 && ++attackframe4 < 110) {
				zannzoulock = 1;
				if (attackframe4 > 10 && attackframe4 < 40) {
					DrawRotaGraph(pos[playerY][playerX][0] - 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 18 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, KATANAB[0], TRUE);

				}
				if (attackframe4 > 50 && attackframe4 < 80) {
					DrawRotaGraph(pos[playerY][playerX][0] - 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 18 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, KATANA2B[0], TRUE);

				}
				if (attackframe4 > 80 && attackframe4 < 110) {
					DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 18 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, KATANA3B1[0], TRUE);

				}
			}
			if (attackframe5 > 0 && ++attackframe5 < 50) {
				DrawRotaGraph(pos[playerY][playerX][0] - 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX, pos[playerY][playerX][1] - 18 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, KATANA3B[0], TRUE);

			}
		}
		//ナイフ攻撃
		//if (naihukougeki == 1) {




		//ステージ1の敵1に関して、
		//後ろから蹴って前に押す攻撃。//同時押しだとスライドが誤発することもあるので、コマンド入力にした。

		if (stage1 == 1 &&//後ろ蹴りでバグをステージ1に移動しないようにするための変数。
			//pos[enemyY][enemyX][1] + 15 + playerattackhanndou3 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 &&
			//pos[enemyY][enemyX][1] - 15 + playerattackhanndou3 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 &&
			pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX
			//pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + 80 &&
			) {
			if (hidarimuki == 1) {
				LEFT = 100;
				if (kericount == 0) {
					if (motonomasunimodoru > 0) {
						//後ろから蹴る攻撃 B→R1と→十字キーの左
						if (Key[KEY_INPUT_F] == 1
							//contorora == (PAD_INPUT_LEFT | PAD_INPUT_2 | PAD_INPUT_6)
							) {
							++attackframe7;
							++douziosicount;
							++kericount;
							bloodMove = 1;
						}

					}

				}
				//相手を蹴り飛ばした後で上に範囲内だとに被らないとかでバグってattackframe5が止まるのでここに書く。
				if (attackframe7 > 0 && attackframe7 < 50) {
					if (attackframe7 > 20 && attackframe7 < 50) {
						Seen = 999;
						//bairituX = 10;
						//bairituY = 10;
						StartJoypadVibration(DX_INPUT_PAD1, 1500, 100);
						DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] - 25 + playerattackhanndou3, bairituY, 0, kikkuhanntenn[0], TRUE);
					}

				}
			}
		}



		if (stage1 == 1 &&//後ろ蹴りでバグをステージ1に移動しないようにするための変数。
			//pos[enemyY][enemyX][1] + 15 + playerattackhanndou3 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 &&
			//pos[enemyY][enemyX][1] - 15 + playerattackhanndou3 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 &&
			pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX
			//pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + 80 &&
			) {
			if (migimuki == 1) {
				if (kericount == 0) {
					if (motonomasunimodoru > 0) {
						//後ろから蹴る攻撃 B→R1と→十字キーの左//Key[KEY_INPUT_P] == 1
						if (Key[KEY_INPUT_G] == 1
							//contorora == (PAD_INPUT_RIGHT | PAD_INPUT_2 | PAD_INPUT_6)
							) {
							++attackframe7;
							++douziosicount;
							++kericount;
							bloodMove = 1;
						}

					}

				}
				//相手を蹴り飛ばした後で上に範囲内だとに被らないとかでバグってattackframe5が止まるのでここに書く。
				if (attackframe7 > 0 && attackframe7 < 50) {
					if (attackframe7 > 20 && attackframe7 < 50) {
						Seen = 999;
						//bairituX = 10;
						//bairituY = 10;
						StartJoypadVibration(DX_INPUT_PAD1, 1500, 100);
						DrawRotaGraph(pos[enemyY][enemyX][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY][enemyX][1] - 25 + playerattackhanndou3, bairituY, 0, playerKONNBO1BHandle[0], TRUE);
					}

				}
			}
		}
		//押されていない時はkericountは0となる。これにより連続して後ろ蹴りが出来なくなった。
		if (contorora == !(PAD_INPUT_LEFT | PAD_INPUT_2 | PAD_INPUT_6) && kericount > 0) {
			kericount = 0;
		}






		//後ろから蹴って前に押す攻撃。//同時押しだとスライドが誤発することもあるので、コマンド入力にした。
		//★Seen = 2と同じ攻撃部分として共有しているので、内部でkericountとkericount2を作り差別化をはからないとkericountでバグって
		//Seen = 2に移っていたとか？//★原因は不明だが連続蹴りとかいろんな問題で生じたバグかもしれない。
		//夜分ここに&& kericount2 == 0を条件で書くと中の++kericount2により条件外になってしまい、後ろ蹴りが出来ないのだろう。




		if (stage2 == 1 &&
			pos[enemyY1][enemyX1][1] + 15 + playerattackhanndou3 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 &&
			pos[enemyY1][enemyX1][1] - 15 + playerattackhanndou3 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 &&
			pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 > pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX
			//pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + 80 &&
			) {
			
		}
		

		if (stage2 == 1 &&
			pos[enemyY1][enemyX1][1] + 15 + playerattackhanndou3 > pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 &&
			pos[enemyY1][enemyX1][1] - 15 + playerattackhanndou3 < pos[playerY][playerX][1] + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5 &&
			pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX
			//pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3 < pos[playerY][playerX][0] + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + 80 &&
			) {
			if (migimuki == 1) {
				
				if (motonomasunimodoru > 0) {//ここに && kericount2 == 0を書いてもいい。
					//後ろから蹴る攻撃 B→R1と→十字キーの左
					if (contorora == (PAD_INPUT_RIGHT | PAD_INPUT_2 | PAD_INPUT_6) && kericount2 == 0) {
						//R1botannlock = 1;//操作キーを押せなくする、バグを無くすために
						++attackframe7;
						++douziosicount;
						++kericount2;
						bloodMove = 1;
					}

				}
				//相手を蹴り飛ばした後で上に範囲内だとに被らないとかでバグってattackframe5が止まるのでここに書く。
				if (attackframe7 > 0 && attackframe7 < 50) {
					if (attackframe7 > 20 && attackframe7 < 50) {
						Seen = 1000;
						//bairituX = 10;
						//bairituY = 10;
						StartJoypadVibration(DX_INPUT_PAD1, 1500, 100);
						DrawRotaGraph(pos[enemyY1][enemyX1][0] + playerattackhanndou + playerattackhanndou2 + playerattackhanndou3, pos[enemyY1][enemyX1][1] - 25 + playerattackhanndou3, bairituY, 0, playerKONNBO1BHandle[0], TRUE);
					}

				}
			}
		}
		

		//押されていない時はkericountは0となる。これにより連続して後ろ蹴りが出来なくなった。
		if (contorora == !(PAD_INPUT_LEFT | PAD_INPUT_2 | PAD_INPUT_6) && kericount2 > 0) {
			kericount2 = 0;
		}


	}
	
	if (attackframe8 > 0 && ++attackframe8 > 50) {
		//attackframe = 0;
		attackframe8 = 0;
		//R1botannlock = 0;//こいつをここで0で書いてるせいでスライド移動一回目の瞬間も押してしまいplayermovelockが1になるとか？
		keriwaza = 0;
	}
	if (attackframe6 > 0 && ++attackframe6 > 50) {
		attackframe6 = 0;
		keriwaza = 0;
		//playermovelock = 0;//念のために。//★スライド移動の際にマス移動しないための滑り止めとして作った変数。
	}
	if (attackframe7 > 0 && ++attackframe7 > 200) {//連続でキックできないように少しフレームを長くした。
		attackframe7 = 0;
		keriwaza = 0;
		//zannzoulock = 0;
		sennkounyuuryokubunnki3 = 0;
		kericount = 0;
		//playermovelock = 0;//念のために。//★スライド移動の際にマス移動しないための滑り止めとして作った変数。
	}

	//ガードの画像を描画
	//if (gardframe > 0 && gardframe < 100) {
	//DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playergardGHandle[0], TRUE);
	//}
}

#endif