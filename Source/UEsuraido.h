

#ifndef DEF_UEsuraido_H //二重include防止

#define DEF_UEsuraido_H




void UEsuraido() {
	//上のコマンドの残像//このままでいい。
	if (zannzouC > 0 && zannzouC <= 15) { //★残像を出すためにRキーでAを押したら変数zannzouが20になり、zannouの変数が0より大きいならば?1をしていき、その間だけ画像を描画する。
		--zannzouC;
		playerkonntororulock = 1;
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
}
#endif