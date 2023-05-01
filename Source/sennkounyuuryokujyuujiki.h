

#ifndef DEF_SURAIDOKANNSUU_H //二重include防止

#define DEF_SURAIDOKANNSUU_H

void suraidoidoukannsuu() {


	//右コマンドの残像//原因はif (zannzou < 1) {zannzou = 0; zannzoulock = 0;}の部分でした。if (zannzou == 1) {zannzou = 0; zannzoulock = 0;}
	if (zannzouD <= 30 && zannzouD > 0) { //★残像を出すためにRキーでAを押したら変数zannzouが20になり、zannouの変数が0より大きいならば—1をしていき、その間だけ画像を描画する。
		--zannzouD;
		//X軸のzannzouの分母を大きくすると減速する
		DrawRotaGraph(pos[playerY][playerX][0] + 20 - 30 * zannzouD / 5, pos[playerY][playerX][1], 5.0, 0, playeridouA4Handle[0], TRUE);


		//敵の目の前にいるが、左や右の入力が速いと相手の前にいくがロックマークが現れないバグが起こるので以下のように書いて置く。
		if (enemyY == playerY && playerX == enemyX - 1) {
			
			LEFTmark = 4545;

			if (Pad[PAD_6] == 1) {
				//kougekiroclmark = 1;//R1を押しても前の座標を記憶しないように
			}



		}


	}//移動した一瞬に元の位置に自分を描画したい、しかしうまく機能していない。
	///★多分一瞬過ぎるのであえてcount < 8と範囲を付けることでほんの一瞬だが残像が見えるようにした。
	///攻撃してcountが50に溜まるまでの期間を利用した。
	if (zannzouD <= 25 && zannzouD > 0) {

		DrawRotaGraph(pos[playerY][playerX][0] + 20 - 24 * zannzouD / 5, pos[playerY][playerX][1], 5.0, 0, playeridouA2Handle[0], TRUE);
	}
	if (zannzouD <= 21 && zannzouD > 0) {
		DrawRotaGraph(pos[playerY][playerX][0] + 20 - 15 * zannzouD / 5, pos[playerY][playerX][1], 5.0, 0, playeridouA2Handle[0], TRUE);
	}
	if (zannzouD <= 18 && zannzouD > 0) {
		DrawRotaGraph(pos[playerY][playerX][0] + 20 - 10 * zannzouD / 5, pos[playerY][playerX][1], 5.0, 0, playeridouA2Handle[0], TRUE);
	}
	if (zannzouD <= 16 && zannzouD > 0) {

		DrawRotaGraph(pos[playerY][playerX][0] + 20 - 5 * zannzouD / 5, pos[playerY][playerX][1], 5.0, 0, playeridouA2Handle[0], TRUE);
	}
	if (zannzouD <= 15 && zannzouD > 0) {
		//これで残像Dがアドが0にならなくても残像Dの範囲によって残像ロックが0に成れば主人公が描画されるので途切れたようには見えない。
	
	}
	if (zannzouD <= 6 && zannzouD > 0) {
		DrawRotaGraph(pos[playerY][playerX][0] + 20 - zannzouD / 5, pos[playerY][playerX][1], 5.0, 0, playeridouA2Handle[0], TRUE);
		
	}
	if (zannzouD <= 1 && zannzouD > 0){ zannzoulock = 0; }
	


	//残像Eにおいてのプログラム。
	//右コマンドの残像//原因はif (zannzou < 1) {zannzou = 0; zannzoulock = 0;}の部分でした。if (zannzou == 1) {zannzou = 0; zannzoulock = 0;}
	if (zannzouE <= 30 && zannzouE > 0) { //★残像を出すためにRキーでAを押したら変数zannzouが20になり、zannouの変数が0より大きいならば—1をしていき、その間だけ画像を描画する。
		--zannzouE;
		//X軸のzannzouの分母を大きくすると減速する
		DrawRotaGraph(pos[playerY][playerX][0] + 20 - 30 * zannzouE / 5, pos[playerY][playerX][1], 5.0, 0, playeridouA4Handle[0], TRUE);


	}//移動した一瞬に元の位置に自分を描画したい、しかしうまく機能していない。
	///★多分一瞬過ぎるのであえてcount < 8と範囲を付けることでほんの一瞬だが残像が見えるようにした。
	///攻撃してcountが50に溜まるまでの期間を利用した。
	if (zannzouE <= 25 && zannzouE > 0) {

		DrawRotaGraph(pos[playerY][playerX][0] + 20 - 24 * zannzouE / 5, pos[playerY][playerX][1], 5.0, 0, playeridouA4Handle[0], TRUE);
	}
	if (zannzouE <= 21 && zannzouE > 0) {
		DrawRotaGraph(pos[playerY][playerX][0] + 20 - 15 * zannzouE / 5, pos[playerY][playerX][1], 5.0, 0, playeridouA4Handle[0], TRUE);
	}
	if (zannzouE <= 18 && zannzouE > 0) {
		DrawRotaGraph(pos[playerY][playerX][0] + 20 - 10 * zannzouE / 5, pos[playerY][playerX][1], 5.0, 0, playeridouA4Handle[0], TRUE);
	}
	if (zannzouE <= 16 && zannzouE > 0) {

		DrawRotaGraph(pos[playerY][playerX][0] + 20 - 5 * zannzouE / 5, pos[playerY][playerX][1], 5.0, 0, playeridouA4Handle[0], TRUE);
	}
	if (zannzouE <= 15 && zannzouE> 0) {
		//これで残像Dがアドが0にならなくても残像Dの範囲によって残像ロックが0に成れば主人公が描画されるので途切れたようには見えない。

	}
	if (zannzouE <= 6 && zannzouE > 0) {
		DrawRotaGraph(pos[playerY][playerX][0] + 20 - zannzouE / 5, pos[playerY][playerX][1], 5.0, 0, playeridouA4Handle[0], TRUE);

	}
	if (zannzouE <= 1 && zannzouE > 0) { zannzoulock = 0; }



}
#endif