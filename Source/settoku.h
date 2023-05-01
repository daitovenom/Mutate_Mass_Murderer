

#ifndef DEF_settoku_H //二重include防止

#define DEF_settoku_H




void settoku1() {

	if (serekutobotanncount == 0) {
		DrawFormatString(25, 150, GetColor(255, 255, 0), "You can persuade the first time with the select button.");
		//攻撃中にセレクトするとバグでplayerkonntororulockの値が0のままになるので motonomasunimodoruが0、攻撃が終わった後に押せるようにした。
		if (Pad[PAD_7] == 1 && motonomasunimodoru == 0) {
			settokuSeen = 1;//説得するためのシーンへ移動する。
			stayhere = 1;//敵の動きを止める
			playerkonntororulock = 1;//主人公の操作を止める。
			R1botannlock = 1;
		}
		if (settokuSeen == 1) {
			stayhere = 1;//敵の動きを止める
			playerkonntororulock = 1;//主人公の操作を止める。
			//Aボタンを押すと
			//PlayMovieToGraph(settokugamenntyuunohaikeiHandle);
			//DrawExtendGraph(0, 0, 870, 780, settokugamenntyuunohaikeiHandle, FALSE);
			drawString(0, 100, 600, Cr);
			drawString(1, 100, 630, Cr);
			drawString(2, 100, 660, Cr);
			//Aボタン
			if (Pad[PAD_1] == 1) {
				settokubunnki = 1;
			}

			//Bボタンを押すと
			if (Pad[PAD_2] == 1) {
				settokubunnki = 2;
			}
			//Yボタンを押すと
			if (Pad[PAD_4] == 1) {
				settokubunnki = 3;
			}
		}
		if (settokubunnki == 1) {
			settokuSeen = 0;
			drawString(3, 100, 600, RED);
			settokubunnkiframe = 1;
		}
		if (settokubunnki == 2) {
			settokuSeen = 0;
			drawString(4, 100, 600, RED);
			settokubunnkiframe = 1;
		}
		if (settokubunnki == 3) {
			settokuSeen = 0;
			drawString(5, 100, 600, RED);
			settokubunnkiframe = 1;
		}
		if (settokubunnkiframe > 0) {
			++settokubunnkiframe2;
		}
		if (settokubunnkiframe2 > 600) {
			serekutobotanncount = 1;//一回説得したら一回目の説得が出ないように。
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 0;//敵の動きを止める
			playerkonntororulock = 0;//主人公の操作を止める。
			R1botannlock = 0;
			settokubunnki = 0;
		}
	}
}


void settoku2() {

	if (serekutobotanncount == 1) {
		DrawFormatString(25, 150, GetColor(255, 255, 0), "You can persuade the Second time with the select button.");
		//攻撃中にセレクトするとバグでplayerkonntororulockの値が0のままになるので motonomasunimodoruが0、攻撃が終わった後に押せるようにした。
		if (Pad[PAD_7] == 1 && motonomasunimodoru == 0) {
			settokuSeen = 1;//説得するためのシーンへ移動する。
			stayhere = 1;//敵の動きを止める
			playerkonntororulock = 1;//主人公の操作を止める。
			R1botannlock = 1;
		}
		if (settokuSeen == 1) {
			stayhere = 1;//敵の動きを止める
			playerkonntororulock = 1;//主人公の操作を止める。
			//Aボタンを押すと
			//PlayMovieToGraph(settokugamenntyuunohaikeiHandle);
			//DrawExtendGraph(0, 0, 870, 780, settokugamenntyuunohaikeiHandle, FALSE);
			drawString(6, 100, 600, Cr);
			drawString(7, 100, 630, Cr);
			drawString(8, 100, 660, Cr);
			//Aボタン
			if (Pad[PAD_1] == 1) {
				settokubunnki = 1;
			}

			//Bボタンを押すと
			if (Pad[PAD_2] == 1) {
				settokubunnki = 2;
			}
			//Yボタンを押すと
			if (Pad[PAD_4] == 1) {
				settokubunnki = 3;
			}
		}
		if (settokubunnki == 1) {
			settokuSeen = 0;
			drawString(9, 100, 600, RED);
			settokubunnkiframe = 1;
		}
		if (settokubunnki == 2) {
			settokuSeen = 0;
			drawString(10, 100, 600, RED);
			settokubunnkiframe = 1;
		}
		if (settokubunnki == 3) {
			settokuSeen = 0;
			drawString(11, 100, 600, RED);
			settokubunnkiframe = 1;
		}
		if (settokubunnkiframe > 0) {
			++settokubunnkiframe2;
		}
		if (settokubunnkiframe2 > 600) {
			serekutobotanncount = 2;//一回説得したら一回目の説得が出ないように。
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 0;//敵の動きを止める
			playerkonntororulock = 0;//主人公の操作を止める。
			R1botannlock = 0;
			settokubunnki = 0;
		}
	}

}

void settoku3() {

	if (serekutobotanncount == 2) {
		DrawFormatString(25, 150, GetColor(255, 255, 0), "You can persuade the Third time with the select button.");
		//攻撃中にセレクトするとバグでplayerkonntororulockの値が0のままになるので motonomasunimodoruが0、攻撃が終わった後に押せるようにした。
		if (Pad[PAD_7] == 1 && motonomasunimodoru == 0) {
			settokuSeen = 1;//説得するためのシーンへ移動する。
			stayhere = 1;//敵の動きを止める
			playerkonntororulock = 1;//主人公の操作を止める。
			R1botannlock = 1;
		}
		if (settokuSeen == 1) {
			stayhere = 1;//敵の動きを止める
			playerkonntororulock = 1;//主人公の操作を止める。
			//Aボタンを押すと
			//PlayMovieToGraph(settokugamenntyuunohaikeiHandle);
			//DrawExtendGraph(0, 0, 870, 780, settokugamenntyuunohaikeiHandle, FALSE);
			drawString(12, 100, 600, Cr);
			drawString(13, 100, 630, Cr);
			drawString(14, 100, 660, Cr);
			//Aボタン
			if (Pad[PAD_1] == 1) {
				settokubunnki = 1;
			}

			//Bボタンを押すと
			if (Pad[PAD_2] == 1) {
				settokubunnki = 2;
			}
			//Yボタンを押すと
			if (Pad[PAD_4] == 1) {
				settokubunnki = 3;
			}
		}
		if (settokubunnki == 1) {
			settokuSeen = 0;
			drawString(15, 100, 600, RED);
			settokubunnkiframe = 1;
		}
		if (settokubunnki == 2) {
			settokuSeen = 0;
			drawString(16, 100, 600, RED);
			settokubunnkiframe = 1;
		}
		if (settokubunnki == 3) {
			settokuSeen = 0;
			drawString(17, 100, 600, RED);
			settokubunnkiframe = 1;
		}
		if (settokubunnkiframe > 0) {
			++settokubunnkiframe2;
		}
		//相手が負けを見とける展開へ進む。
		if (settokubunnkiframe2 > 1000&& settokubunnki == 1) {
			serekutobotanncount = 3;//一回説得したら一回目の説得が出ないように。
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 1;//敵の動きを止める
			playerkonntororulock = 1;//主人公の操作を止める。
			R1botannlock = 0;
			settokubunnki = 0;
			settokutoumeika = 1;//Seen 11に進むために必要な変数。
			analognoizu = 1;
			//Seen = 100;
			
		}
		if (settokubunnkiframe2 > 1000 && settokubunnki == 2) {
			serekutobotanncount = 3;//一回説得したら一回目の説得が出ないように。
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 1;//敵の動きを止める
			playerkonntororulock = 1;//主人公の操作を止める。
			R1botannlock = 0;
			settokubunnki = 0;
			settokutoumeika = 1;//Seen 11に進むために必要な変数。
			analognoizu = 1;
		}
		//相手を殺す展開。なのでserekutobotanncountの値を4に変更する。
		//相手を殺す展開だが、この選択によりsettoku4に進み、本当に殺すかどうかを2択で判断する。
		if (settokubunnkiframe2 > 1000 && settokubunnki == 3) {
			serekutobotanncount = 4;//一回説得したら一回目の説得が出ないように。
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 0;//敵の動きを止める
			playerkonntororulock = 0;//主人公の操作を止める。
			settokubunnki = 0;
		}
	}
	
}

void settoku4() {

	if (serekutobotanncount == 4) {
		DrawFormatString(25, 150, GetColor(255, 255, 0), "You can persuade the last time with the select button.");
		//攻撃中にセレクトするとバグでplayerkonntororulockの値が0のままになるので motonomasunimodoruが0、攻撃が終わった後に押せるようにした。
		if (Pad[PAD_7] == 1 && motonomasunimodoru == 0) {
			settokuSeen = 1;//説得するためのシーンへ移動する。
			stayhere = 1;//敵の動きを止める
			playerkonntororulock = 1;//主人公の操作を止める。
			R1botannlock = 1;
		}
		if (settokuSeen == 1) {
			stayhere = 1;//敵の動きを止める
			playerkonntororulock = 1;//主人公の操作を止める。
			//Aボタンを押すと
			//PlayMovieToGraph(settokugamenntyuunohaikeiHandle);
			//DrawExtendGraph(0, 0, 870, 780, settokugamenntyuunohaikeiHandle, FALSE);
			drawString(18, 100, 600, Cr);
			drawString(19, 100, 630, Cr);
			//Aボタン
			if (Pad[PAD_1] == 1) {
				settokuSeen = 0;
				settokubunnki = 1;
				settokubunnkiframe = 1;
			}

			//Bボタンを押すと
			if (Pad[PAD_2] == 1) {
				settokuSeen = 0;
				settokubunnki = 2;
				settokubunnkiframe = 1;
			}
		}
		if (settokubunnkiframe > 0) {
			++settokubunnkiframe2;
		}
		//出来れば殺したくない。となり、自己判断を誤りゲームオーバーへ。
		if (settokubunnkiframe2 > 600 && settokubunnki == 1) {
			serekutobotanncount = 5;//一回説得したら一回目の説得が出ないように。
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 1;//敵の動きを止めるをやめる
			playerkonntororulock = 0;//主人公の操作を止めるをやめる。
			R1botannlock = 0;
			settokubunnki = 0;
			settokutoumeika = 1;//Seen 11に進むために必要な変数。
		}//敵を殺すことで新たな未来に続く。
		if (settokubunnkiframe2 > 600 && settokubunnki == 2) {
			serekutobotanncount = 5;//一回説得したら一回目の説得が出ないように。
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 1;//敵の動きを止める
			playerkonntororulock = 0;//主人公の操作を止める。
			R1botannlock = 0;
			settokubunnki = 0;
			
		}
		
	}

}





#endif