

#ifndef DEF_kasurikougeki_H //二重include防止

#define DEF_kasurikougeki_H

void kasurikougeki() {
	if (kougekikannkakulock == 0) {
		if (playerkonntororulock == 0) {
			if (attackframe == 0) {

				if (migimuki == 1) {
					if (Pad[PAD_2] == 1 && sousakanou == 0 && nextattack == 0 && kougekiKANOU == 0 && Pad[PAD_6] == 0) {
						
						lock = 0;//移動ボタンが押せないように。
						//LEFTmark = 9;
						R1lock = 1;//再度殴ってる最中にR1を押して、攻撃中の座標を保存しないために1とした。
						//enemysabunHP = 20;
						stayherelock = 1;//★敵のHP表示を消すために必要な変数。
						//addattacktime = 300;//先行入力でコンボが決まった時のためのアドアタックタイム。
						++attackframe;
						//nagurusound = LoadSoundMem("殴る音.mp3");
						//PlaySoundMem(nagurusound, DX_PLAYTYPE_BACK);
						nagurugazou = 1;
						//kougekiKANOU = 1;
						//追加で殴るときにコンボの画像が消えるように。
						//KONNBO1A = 1;
						//KONNBO1B = 0;
						//zannzoulock = 0;
						//++nagurucount;
						//pos[playerY][playerX][0] = playerkougekiXzahyou - 100;
						//pos[playerY][playerX][1] = playerkougekiYzahyou;
						konnbokakuninn = 1;
						nagurukasanaru = 1;

						enemykougekilock = 1;

						playerHPlock = 1;//殴るときにダメージを負った状態の画像を描画しないための物。

						tabakolock = 1;//ロック中はタバコが吸えないように1にする。

						//playerattackhanndou = playerattackhanndou + 10;

						//motonomasunimodoru = 10;//コンボが決まると一定の値になるようにした。

						//if (GetRand(10) < 8) {
						//	playerattackhanndou2 = playerattackhanndou2 + 60;
						//}
						//playerHPlock = 1;//攻撃中はダメージを追った状態の画像を描画しないようにするために1とする。
						zannzoulock = 1;
						nextattack = 1;
					}
				}
				else if (hidarimuki == 1) {
					if (Pad[PAD_2] == 1 && sousakanou == 0 && nextattack == 0 && kougekiKANOU == 0 && Pad[PAD_6] == 0) {

						lock = 0;//移動ボタンが押せないように。
						//LEFTmark = 9;
						R1lock = 1;//再度殴ってる最中にR1を押して、攻撃中の座標を保存しないために1とした。
						//enemysabunHP = 20;
						stayherelock = 1;//★敵のHP表示を消すために必要な変数。
						//addattacktime = 300;//先行入力でコンボが決まった時のためのアドアタックタイム。
						++attackframe;
						//nagurusound = LoadSoundMem("殴る音.mp3");
						//PlaySoundMem(nagurusound, DX_PLAYTYPE_BACK);
						nagurugazou = 1;
						//kougekiKANOU = 1;
						//追加で殴るときにコンボの画像が消えるように。
						//KONNBO1A = 1;
						//KONNBO1B = 0;
						//zannzoulock = 0;
						//++nagurucount;
						//pos[playerY][playerX][0] = playerkougekiXzahyou - 100;
						//pos[playerY][playerX][1] = playerkougekiYzahyou;
						konnbokakuninn = 1;
						nagurukasanaru = 1;

						enemykougekilock = 1;

						playerHPlock = 1;//殴るときにダメージを負った状態の画像を描画しないための物。

						tabakolock = 1;//ロック中はタバコが吸えないように1にする。

						//playerattackhanndou = playerattackhanndou + 10;

						//motonomasunimodoru = 10;//コンボが決まると一定の値になるようにした。

						//if (GetRand(10) < 8) {
						//	playerattackhanndou2 = playerattackhanndou2 + 60;
						//}
						//playerHPlock = 1;//攻撃中はダメージを追った状態の画像を描画しないようにするために1とする。
						zannzoulock = 1;
						nextattack = 1;
					}
				}




			}
			//連続で殴る場合のプログラム。//1より大きい時は繰り上がり、30より小さい間に{}をする。
			if (attackframe > 0 && ++attackframe < 80) {
				if (attackframe > 35 && attackframe < 80) {//この間にボタンを押すと連続攻撃に移る。
					if (Pad[PAD_2] == 1 && sousakanou == 0 && nextattack == 0 && attackframeA == 0 && kougekiKANOU == 0) {
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

				//ステージ1の老婆とステージ2のふたりをかする殴るプログラムの続き//
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

				//ステージ2の男二人に対する二発目のかする殴る攻撃//

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
						kakuninn = 1;
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
						//enemysabunHP = 30;
						playerHPlock = 0;
						playerattackhanndou = playerattackhanndou - 30;//敵が奥に進む
						enemyzannzoulockframe1 = 1;//相手のダメージを食らった際の怯みを初期に戻すため
						stayhereframe = 1;
						bloodMove = 1;
						kakuninn = 2;
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



















			//★★ && kougekilock == 1&& kougekiKANOU == 1はR1を押さない場合の時は上に書いたように
			//R1lockは0になるので、コンボが出来ないので他の変数konnbokakuninnを使った。
			//最初からコンボ出ない場合はR1lockは1のままなのでそのままキックできる。
			//Yボタンからのコンボを決めるためのYボタンを入力する部分
			
				if (Pad[PAD_4] == 1 && sousakanou == 0 && nextattack == 0 && kougekiKANOU == 0) {
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
					//sennkounyuuryokubunnki = 1;
					kougekilock = 1;////先行入力でコンボが決まった時に誤作動でXボタンを押しても殴るがでないように他の値にする。
					zannzoulock = 1;

					KONNBO1A = 1;

					//kougekiKANOU = 1;

					nagurukasanaru = 0;
					KONNBO1kasanaru = 1;

					enemykougekilock = 1;

					playerHPlock = 1;//キックするときにダメージを負った状態の画像を描画しないための物。
					playermovelock = 1;//ここで1にしないとキック攻撃の右コマンドと右移動を勘違いして右に移動しながらのキックになるのでここで1にして、
					//右移動でのコントロールの影響を受けないようにする。
					//motonomasunimodoru = 10;//コンボが決まると一定の値になるようにした。
					kasurikeri = 1;
					nextattack = 1;
				}
			
			
			if (kasurikeri == 1 && kougekiKANOU == 0 && motonomasunimodoru > 0) {
				++attackframe2;
				//LEFTmark = 114;
				//ここの先行入力に成功すると殴るバージョン3に続く。
				//★★このフレームがちょうどいい。



			}

			if (migimuki == 1) {
				if (attackframe2 > 0 && attackframe2 < 40 && kougekiKANOU == 0) {//下のif (attackframe2 > 0 && attackframe2 < 15)と被らないようにする。
					if (Pad[PAD_RIGHT] == 1) {//★↑の方は左はじきで反応しないように少し遅めに9にして、仮に遅めに左ははじきで右が入力されても反応しないように15とした。
						//LEFTmark = 514;
						//KONNBO1A = 0;//けり上げる時に、蹴る前の画像を描画しないように。
						//enemysabunHPA = 70;//最初の普通の殴るの攻撃もXボタンを押すことのコンボをなるため
						//LEFTmark = 114514;//描画用に作った先行入力の確認用の変数
						LEFTmarklock = 1;//先行入力が再びできるようにするにはXボタンで相手を殴るために、ここに1として、追加の方でLEFTmarklock = 0とした。
						//addattacktime = 300;
						attackframe = 0;//攻撃後に追加殴るをしなくても1としておけば0より大きいのでコンボがつながる。追加殴るで今コンボを繋げてもいい。
						stayherelock = 1;//敵のHPを消すために必要な変数
						//sennkounyuuryokubunnki = 1;//★if文よりsennkounyuuryokubunnki==1の時でないとここのif文は動かないので、sennkounyuuryokubunnkiが0の時は前のif文の条件に合わないのでattackframe2内であっても殴る2の攻撃できないのは当然である。
						//attackframe2 = 0;//先行入力の分岐でsennkounyuuryokubunnki2に行かなかった場合にattackframe2の値が0になるように書いた。
						//naguru2sound = LoadSoundMem("damage01.m4a");
						//PlaySoundMem(naguru2sound, DX_PLAYTYPE_BACK);
						//sennkounyuuryokubunnki3 = 0;//ここの先行入力が成功した際は続けて殴る3がでないようにここの変数を0にする。
						//attackframe3 = 150;//★先行入力が成功した際は続けて殴る3がでないように殴る3に引っ掛からないような変数の値にする。

						//kougekilock = 1;//コンボ入力が成功した際に再びコンボを決めたい際に上のYボタンのif文を通過できるように
						//kougekilockの値を1にする。

						KONNBO1A = 0;//前の蹴る前の画像を消すための物。
						KONNBO1B = 1;//蹴り上げるの画像を描画するためのもの


						KONNBO1kasanaru = 0;
						KONNBO2kasanaru = 1;

						//motonomasunimodoru = 10;//コンボが決まると一定の値になるようにした。
						//playerattackhanndou = playerattackhanndou + 30;
						//playermovelock = 0;

						attackframe2 = 0;
						kasurikeri = 0;
						//++attackframe3;
					}
					//sennkounyuuryokubunnki3 = 0;
					//attackframe3 = 0;//殴る2バージョンをやった後で値がそのままだと右を押しただけで殴るバージョン3ができてしまうので。
					//★殴る2に分岐した場合は殴る3の情報をすべて0にする。
					//attackframe = 0;//殴る2が成功したするかは別にこのフレームの時に一旦0にするとXボタンからのコンボがつながりやすい。
				}

			}
			else if (hidarimuki == 1) {
				if (attackframe2 > 0 && attackframe2 < 40 && kougekiKANOU == 0) {//下のif (attackframe2 > 0 && attackframe2 < 15)と被らないようにする。
					if (Pad[PAD_LEFT] == 1) {//★↑の方は左はじきで反応しないように少し遅めに9にして、仮に遅めに左ははじきで右が入力されても反応しないように15とした。
						//LEFTmark = 514;
						//KONNBO1A = 0;//けり上げる時に、蹴る前の画像を描画しないように。
						//enemysabunHPA = 70;//最初の普通の殴るの攻撃もXボタンを押すことのコンボをなるため
						//LEFTmark = 114514;//描画用に作った先行入力の確認用の変数
						LEFTmarklock = 1;//先行入力が再びできるようにするにはXボタンで相手を殴るために、ここに1として、追加の方でLEFTmarklock = 0とした。
						//addattacktime = 300;
						attackframe = 0;//攻撃後に追加殴るをしなくても1としておけば0より大きいのでコンボがつながる。追加殴るで今コンボを繋げてもいい。
						stayherelock = 1;//敵のHPを消すために必要な変数
						//sennkounyuuryokubunnki = 1;//★if文よりsennkounyuuryokubunnki==1の時でないとここのif文は動かないので、sennkounyuuryokubunnkiが0の時は前のif文の条件に合わないのでattackframe2内であっても殴る2の攻撃できないのは当然である。
						//attackframe2 = 0;//先行入力の分岐でsennkounyuuryokubunnki2に行かなかった場合にattackframe2の値が0になるように書いた。
						//naguru2sound = LoadSoundMem("damage01.m4a");
						//PlaySoundMem(naguru2sound, DX_PLAYTYPE_BACK);
						//sennkounyuuryokubunnki3 = 0;//ここの先行入力が成功した際は続けて殴る3がでないようにここの変数を0にする。
						//attackframe3 = 150;//★先行入力が成功した際は続けて殴る3がでないように殴る3に引っ掛からないような変数の値にする。

						//kougekilock = 1;//コンボ入力が成功した際に再びコンボを決めたい際に上のYボタンのif文を通過できるように
						//kougekilockの値を1にする。

						KONNBO1A = 0;//前の蹴る前の画像を消すための物。
						KONNBO1B = 1;//蹴り上げるの画像を描画するためのもの


						KONNBO1kasanaru = 0;
						KONNBO2kasanaru = 1;

						//motonomasunimodoru = 10;//コンボが決まると一定の値になるようにした。
						//playerattackhanndou = playerattackhanndou + 30;
						//playermovelock = 0;

						attackframe2 = 0;
						kasurikeri = 0;
						//++attackframe3;
					}
					//sennkounyuuryokubunnki3 = 0;
					//attackframe3 = 0;//殴る2バージョンをやった後で値がそのままだと右を押しただけで殴るバージョン3ができてしまうので。
					//★殴る2に分岐した場合は殴る3の情報をすべて0にする。
					//attackframe = 0;//殴る2が成功したするかは別にこのフレームの時に一旦0にするとXボタンからのコンボがつながりやすい。
				}

			}


			if (Pad[PAD_1] == 1 && motonomasunimodoru > 0 && kougekiKANOU == 0) {
				//zannzoulock = 1;
				//KONNBO1Aframe1 = 0;//こいつを0にすることで描画のキックをする前の画像を描画できなようにした。
				KONNBO1A = 0;//別のコンボに進んだため、値を0にする。//注意、まだ画像が作れていないので何も表示されない。
				KONNBO1Aframe = 0;//こいつを0にすることで描画のキックをする前の画像を描画できなようにした。
				KONNBO1Bframe = 0;
				//KONNBO1B = 0;//別のコンボに進んだため、値を0にする。//注意、まだ画像が作れていないので何も表示されない。
				sennkounyuuryokubunnki3 = 1;//ここの先行入力に成功すると殴るバージョン3に続く。
				LEFTmark = 2;//確認のために。
		//		addattacktime = 300;//★コンボのつなぎとして、殴る3のコンボが入らな過ぎるのも困るので。
				//★addattacktime = 50では短くて入力が成功してattackframe3が上がってもaddattacktimeが0になってしまい元のマスに戻ってしまい殴る3が出来なかった。
				//sennkounyuuryokubunnki = 0;//殴る2に行かない様にするため。
				attackframe2 = 0;//殴る3に行った際に、attackframe2が0になるようにする。★コンボの際はほかのフレームは関係ないので0にする。
				attackframe3 = 1;

				nagurukasanaru = 0;
				KONNBO1kasanaru = 0;
				//	KONN0BO2kasanaru = 0;
				playerHPlock = 1;
			}


			if (sennkounyuuryokubunnki3 == 1 && kougekiKANOU == 0) {
				++attackframe3;//ちゃんと値が上がっている、
				//attackframe2 = 0;//★↑の殴る2に引っ掛かり、殴る3を入力する際に殴る2もでないようにする。
				//attackframe3のフレーム内に右入力が成功すれば殴る3バージョンができる。
				attackframe2 = 0;//ここでのアタックフレーム2は殴る3には関係ないので0にする。
				//ここに問題はない。ここを消してもattackframe3が300に行く前に左の入力でattackframe3が0?になっていた。
				//これでOK。
				playerHPlock = 1;

			}


			//空振りの刀の画像ではなく技を出すうえでのフレーム数。
			if (attackframe3 > 5 && attackframe3 < 100 && kougekiKANOU == 0) {//attackframe3>0からにすると前の左にはじいた反動で右入力をしてしまい最初のフレームの範囲に反応することで、簡単にコンボが出来るので、左にはじいた反動では反応しない様に範囲をattackframe3>20からにした。これで入力が誤差もなく難しく出来た。
				if (Pad[PAD_LEFT] == 1) {
					++attackframe4;
				}
			}

			if (attackframe4 > 0 && attackframe4 < 110 && kougekiKANOU == 0) {//attackframe3>0からにすると前の左にはじいた反動で右入力をしてしまい最初のフレームの範囲に反応することで、簡単にコンボが出来るので、左にはじいた反動では反応しない様に範囲をattackframe3>20からにした。これで入力が誤差もなく難しく出来た。
				if (Pad[PAD_RIGHT] == 1) {
					
					RIGHTmarklock = 1;
					//attackframe2 = 0;
					//enemysabunHPB = 300;
					lockmark = 1;
					//sinnzoubyouga = 1;
					//addattacktime = 300;
					//attackframe = 1;//追加の殴る攻撃ができるようにここで1に戻す。
					attackframe3 = 0;//追加の殴る攻撃ができるようにここで0に戻す。
					//attackframe4 = 0;
					++attackframe5;
					kougekilock = 1;
					stayherelock = 1;//敵のHPを消すために必要な変数
					sennkounyuuryokubunnki3 = 0;//再び殴る2などをできるようにするためにここで0にする。
					//naguru3sound = LoadSoundMem("damage03.m4a");
					//PlaySoundMem(naguru3sound, DX_PLAYTYPE_BACK);
					//++attackframe4;
					//sennkounyuuryokubunnki = 0;//★追加の殴る攻撃ができるように。追加殴るに繋がると、再び殴る2や殴る3ができるため。
					//ememydontmovetime = 1;
				}
			}
		}

	

	}
	//攻撃範囲外でのかすり判定での攻撃間隔。
	//この5フレーム内なら攻撃でいる。
	//if (kougekikannkaku2 > 0 && ++kougekikannkaku2 < 100) {
	//	playerkonntororulock = 1;//30フレームを超えるまでは攻撃できない。//この時点でplayerkonntororulockは1になるのでプレイヤードロウイングヘッダ
	//	//の条件に合わず、残像ロックが機能しない、なのでここで残像ロックを書き足す。
	//	zannzoulock = 0;


	//}
	//if (kougekikannkaku2 > 100) {
	//	kougekikannkaku2 = 0;
	//}
}
#endif