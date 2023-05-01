

#ifndef DEF_settoku2_H //二重include防止

#define DEF_settoku2_H

void settoku5() {
	SetFontSize(16);
	if (serekutobotanncount2 == 0) {
		DrawFormatString(25, 150, GetColor(255, 255, 0), "You can persuade the first time with the select button.");
		//攻撃中にセレクトするとバグでplayerkonntororulockの値が0のままになるので motonomasunimodoruが0、攻撃が終わった後に押せるようにした。
		if (Pad[PAD_7] == 1 && motonomasunimodoru == 0 && zannzou == 0 && zannzouA == 0 && zannzouB == 0 && zannzouC == 0) {
			settokuSeen = 1;//説得するためのシーンへ移動する。
			stayhere = 1;//敵の動きを止める
			stayhere2 = 1;
			R1botannlock = 1;
			playerkonntororulock3 = 1;//主人公の操作を止める。
		}
		if (settokuSeen == 1) {
			//敵の攻撃がジャストヒットして以下2つの変数が0になったさいのためにここで再び１にする。
			stayhere = 1;//敵の動きを止める
			stayhere2 = 1;
			//Aボタンを押すと
			//PlayMovieToGraph(settokugamenntyuunohaikeiHandle);
			//DrawExtendGraph(0, 0, 870, 780, settokugamenntyuunohaikeiHandle, FALSE);
			drawString(20, 100, 600, Cr);
			drawString(21, 100, 630, Cr);
			drawString(22, 100, 660, Cr);
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
			drawString(23, 100, 600, RED);
			settokubunnkiframe = 1;
			if (settokubunnkiframe2 > 0 && settokubunnkiframe2 < 2) {
				playerHPsubun =  101;//足を撃たれた。//★HPの定義をfloatにして、400フレームで100になるように0.25とした。だが、描画関数でfloatが使えないのでやめる。
			}
		}
		if (settokubunnki == 2) {
			settokuSeen = 0;
			drawString(24, 100, 600, RED);
			settokubunnkiframe = 1;
			if (settokubunnkiframe2 > 0 && settokubunnkiframe2 < 2) {
				enemysabunHP =  100;
				Gcount = Gcount - 1;
			}
		}
		if (settokubunnki == 3) {
			settokuSeen = 0;
			drawString(25, 100, 600, RED);
			settokubunnkiframe = 1;
		}
		if (settokubunnkiframe > 0) {
			playerkonntororulock3 = 1;//主人公の操作を止める。//ジャスト攻撃で0になるときがあるので。
			++settokubunnkiframe2;
		}
		if (settokubunnkiframe2 > 1000) {
			serekutobotanncount2 = 1;//一回説得したら一回目の説得が出ないように。
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 0;//敵の動きを止める
			stayhere2 = 0;//敵の動きを止める
			playerkonntororulock3 = 0;//主人公の操作を止める。
			R1botannlock = 0;
			settokubunnki = 0;
			//敵が攻撃を食らった際にstayhereframeが長くなってしまうので、ここで強制的に0にする。
			stayhereframe = 0;
			ranndamulock = 0;//再び物理攻撃できるように0にする。
			enemyzannzoulockframe1 = 0;
			enemyzannzoulock2 = 0;
			stayhere = 0;
		}
	}
}

void settoku6() {
	SetFontSize(16);
	if (serekutobotanncount2 == 1) {
		DrawFormatString(25, 150, GetColor(255, 255, 0), "You can persuade the Second time with the select button.");
		//攻撃中にセレクトするとバグでplayerkonntororulockの値が0のままになるので motonomasunimodoruが0、攻撃が終わった後に押せるようにした。
		if (Pad[PAD_7] == 1 && motonomasunimodoru == 0 && zannzou == 0 && zannzouA == 0 && zannzouB == 0 && zannzouC == 0) {
			settokuSeen = 1;//説得するためのシーンへ移動する。
			stayhere = 1;//敵の動きを止める
			stayhere2 = 1;
			playerkonntororulock3 = 1;//主人公の操作を止める。
			R1botannlock = 1;
		}
		if (settokuSeen == 1) {
			stayhere = 1;//敵の動きを止める
			stayhere2 = 1;
			//Aボタンを押すと
			//PlayMovieToGraph(settokugamenntyuunohaikeiHandle);
			//DrawExtendGraph(0, 0, 870, 780, settokugamenntyuunohaikeiHandle, FALSE);
			drawString(26, 100, 600, Cr);
			drawString(27, 100, 630, Cr);
			drawString(28, 100, 660, Cr);
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
			drawString(29, 100, 600, RED);
			settokubunnkiframe = 1;
			if (settokubunnkiframe2 > 0 && settokubunnkiframe2 < 2) {
				playerHPsubun = 61;//足を撃たれた。//★HPの定義をfloatにして、400フレームで100になるように0.25とした。だが、描画関数でfloatが使えないのでやめる。
			}
		}
		if (settokubunnki == 2) {
			settokuSeen = 0;
			drawString(30, 100, 600, RED);
			settokubunnkiframe = 1;
			if (settokubunnkiframe2 > 0 && settokubunnkiframe2 < 2) {
				//enemy1HP = enemy1HP + 100;
			}
		}
		if (settokubunnki == 3) {
			settokuSeen = 0;
			drawString(31, 100, 600, RED);
			settokubunnkiframe = 1;
			if (settokubunnkiframe2 > 0 && settokubunnkiframe2 < 2) {
				playerHPsubun = 101;//足を撃たれた。//★HPの定義をfloatにして、400フレームで100になるように0.25とした。だが、描画関数でfloatが使えないのでやめる。
			}
		}
		if (settokubunnkiframe > 0) {
			playerkonntororulock3 = 1;//主人公の操作を止める。
			++settokubunnkiframe2;
		}
		if (settokubunnkiframe2 > 1500) {
			serekutobotanncount2 = 2;//一回説得したら一回目の説得が出ないように。
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 1;//敵の動きを止める
			stayhere2 = 1;//敵の動きを止める
			playerkonntororulock3 = 0;//主人公の操作を止める。
			R1botannlock = 0;
			settokubunnki = 0;
			//敵が攻撃を食らった際にstayhereframeが長くなってしまうので、ここで強制的に0にする。
			stayhereframe = 0;
			ranndamulock = 0;//再び物理攻撃できるように0にする。
			enemyzannzoulockframe1 = 0;
			enemyzannzoulock2 = 0;
			stayhere = 0;
		}
	}
}

void settoku7() {
	SetFontSize(16);
	if (serekutobotanncount2 == 2) {
		DrawFormatString(25, 150, GetColor(255, 255, 0), "You can persuade the Second time with the select button.");
		//攻撃中にセレクトするとバグでplayerkonntororulockの値が0のままになるので motonomasunimodoruが0、攻撃が終わった後に押せるようにした。
		if (Pad[PAD_7] == 1 && motonomasunimodoru == 0 && zannzou == 0 && zannzouA == 0 && zannzouB == 0 && zannzouC == 0) {
			settokuSeen = 1;//説得するためのシーンへ移動する。
			stayhere = 1;//敵の動きを止める
			stayhere2 = 1;
			playerkonntororulock3 = 1;//主人公の操作を止める。
			R1botannlock = 1;
		}
		if (settokuSeen == 1) {
			stayhere = 1;//敵の動きを止める
			stayhere2 = 1;
			//Aボタンを押すと
			//PlayMovieToGraph(settokugamenntyuunohaikeiHandle);
			//DrawExtendGraph(0, 0, 870, 780, settokugamenntyuunohaikeiHandle, FALSE);
			drawString(32, 100, 600, Cr);
			drawString(33, 100, 630, Cr);
			drawString(34, 100, 660, Cr);
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
			drawString(35, 100, 600, RED);
			settokubunnkiframe = 1;
			if (settokubunnkiframe2 > 0 && settokubunnkiframe2 < 2) {
				enemysabunHP = 300;
				heartpoint = 1;
			}
		}
		if (settokubunnki == 2) {
			settokuSeen = 0;
			drawString(36, 100, 600, RED);
			settokubunnkiframe = 1;
			
		}
		if (settokubunnki == 3) {
			settokuSeen = 0;
			drawString(37, 100, 600, RED);
			settokubunnkiframe = 1;
		}
		if (settokubunnkiframe > 0) {
			playerkonntororulock3 = 1;//主人公の操作を止める。
			++settokubunnkiframe2;
		}
		if (settokubunnkiframe2 > 1500) {//コメントが長いのでここだめ1500にする。
			serekutobotanncount2 = 3;//一回説得したら一回目の説得が出ないように。
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 1;//敵の動きを止める
			stayhere2 = 1;//敵の動きを止める
			playerkonntororulock3 = 0;//主人公の操作を止める。//たまに説得に入る直前に攻撃されsettokubunnkiframe2が400を超える前にここが0になることがあるが、こればかりは面倒なのでこれでいい。
			R1botannlock = 0;
			settokubunnki = 0;
			//敵が攻撃を食らった際にstayhereframeが長くなってしまうので、ここで強制的に0にする。
			stayhereframe = 0;
			ranndamulock = 0;//再び物理攻撃できるように0にする。
			enemyzannzoulockframe1 = 0;
			enemyzannzoulock2 = 0;
			stayhere = 0;
		}
	}
}

void settoku8() {
	SetFontSize(16);
	if (serekutobotanncount2 == 3) {
		DrawFormatString(25, 150, GetColor(255, 255, 0), "You can persuade the Fourth time with the select button.");
		//攻撃中にセレクトするとバグでplayerkonntororulockの値が0のままになるので motonomasunimodoruが0、攻撃が終わった後に押せるようにした。
		if (Pad[PAD_7] == 1 && motonomasunimodoru == 0 && zannzou == 0 && zannzouA == 0 && zannzouB == 0 && zannzouC == 0) {
			settokuSeen = 1;//説得するためのシーンへ移動する。
			stayhere = 1;//敵の動きを止める
			stayhere2 = 1;
			playerkonntororulock3 = 1;//主人公の操作を止める。
			R1botannlock = 1;
		}
		if (settokuSeen == 1) {
			stayhere = 1;//敵の動きを止める
			stayhere2 = 1;
			//Aボタンを押すと
			//PlayMovieToGraph(settokugamenntyuunohaikeiHandle);
			//DrawExtendGraph(0, 0, 870, 780, settokugamenntyuunohaikeiHandle, FALSE);
			drawString(38, 100, 600, Cr);
			drawString(39, 100, 630, Cr);
			drawString(40, 100, 660, Cr);
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
			drawString(41, 100, 600, RED);
			settokubunnkiframe = 1;
			if (settokubunnkiframe2 > 0 && settokubunnkiframe2 < 2) {
				enemysabunHP = 50;
				heartpoint = 2;
			}
		}
		if (settokubunnki == 2) {
			settokuSeen = 0;
			drawString(42, 100, 600, RED);
			settokubunnkiframe = 1;

		}
		//諦めて敵を殺す。
		if (settokubunnki == 3) {
			settokuSeen = 0;
			drawString(43, 100, 600, RED);
			settokubunnkiframe3 = 1;
		}
		if (settokubunnkiframe > 0) {
			playerkonntororulock3 = 1;//主人公の操作を止める。
			++settokubunnkiframe2;
		}
		if (settokubunnkiframe3 > 0) {
			++settokubunnkiframe3;
		}
		if (settokubunnkiframe3 > 200) {
			settokubunnki = 0;
			settokubunnkiframe3 = 0;
			enemy1HP = 0;//諦めた。青い服の男を殺した。test2.cppのkiller == 1に続く。
			killer = 1;
		}
		if (settokubunnkiframe2 > 1500) {
			serekutobotanncount2 = 4;//一回説得したら一回目の説得が出ないように。
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 1;//敵の動きを止める
			stayhere2 = 1;//敵の動きを止める
			playerkonntororulock3 = 0;//主人公の操作を止める。//たまに説得に入る直前に攻撃されsettokubunnkiframe2が400を超える前にここが0になることがあるが、こればかりは面倒なのでこれでいい。
			R1botannlock = 0;
			settokubunnki = 0;
			//敵が攻撃を食らった際にstayhereframeが長くなってしまうので、ここで強制的に0にする。
			stayhereframe = 0;
			ranndamulock = 0;//再び物理攻撃できるように0にする。
			enemyzannzoulockframe1 = 0;
			enemyzannzoulock2 = 0;
			stayhere = 0;
		}
	}
}


void settoku9() {
	SetFontSize(16);
	if (serekutobotanncount2 == 4) {
		DrawFormatString(25, 150, GetColor(255, 255, 0), "You can persuade the five time with the select button.");
		//攻撃中にセレクトするとバグでplayerkonntororulockの値が0のままになるので motonomasunimodoruが0、攻撃が終わった後に押せるようにした。
		if (Pad[PAD_7] == 1 && motonomasunimodoru == 0 && zannzou == 0 && zannzouA == 0 && zannzouB == 0 && zannzouC == 0) {
			settokuSeen = 1;//説得するためのシーンへ移動する。
			stayhere = 1;//敵の動きを止める
			stayhere2 = 1;
			playerkonntororulock3 = 1;//主人公の操作を止める。
			R1botannlock = 1;
		}
		if (settokuSeen == 1) {
			stayhere = 1;//敵の動きを止める
			stayhere2 = 1;
			//Aボタンを押すと
			//PlayMovieToGraph(settokugamenntyuunohaikeiHandle);
			//DrawExtendGraph(0, 0, 870, 780, settokugamenntyuunohaikeiHandle, FALSE);
			drawString(44, 100, 600, Cr);
			drawString(45, 100, 630, Cr);
			//drawString(40, 100, 700, Cr);
			//Aボタン
			if (Pad[PAD_1] == 1) {
				settokubunnki = 1;
			}

			//Bボタンを押すと
			if (Pad[PAD_2] == 1) {
				settokubunnki = 2;
			}
			//Yボタンを押すと
			//if (Pad[PAD_4] == 1) {
			//	settokubunnki = 3;
			//}
		}
		//彼女が待ってる！彼女のためにも罪を償おう！　怒りの目で睨みつけられた。
		if (settokubunnki == 1) {
			settokuSeen = 0;
			drawString(46, 100, 600, RED);
			settokubunnkiframe = 1;
			if (settokubunnkiframe2 > 0 && settokubunnkiframe2 < 2) {
				playerHPsubun = 51;//プログラムの都合上＋1だけする。
			}
		}
		//罪を償わないなら彼女をお前から遠ざける！　頼む！やめてくれ！
		if (settokubunnki == 2) {
			settokuSeen = 0;
			drawString(47, 100, 600, RED);
			settokubunnkiframe = 1;
			heartpoint = 3;
		}
		if (settokubunnkiframe > 0) {
			playerkonntororulock3 = 1;//主人公の操作を止める。
			++settokubunnkiframe2;
		}
		if (settokubunnkiframe2 > 1500) {
			serekutobotanncount2 = 5;//一回説得したら一回目の説得が出ないように。
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 1;//敵の動きを止める
			stayhere2 = 1;//敵の動きを止める
			playerkonntororulock3 = 0;//主人公の操作を止める。//たまに説得に入る直前に攻撃されsettokubunnkiframe2が400を超える前にここが0になることがあるが、こればかりは面倒なのでこれでいい。
			R1botannlock = 0;
			settokubunnki = 0;
			//敵が攻撃を食らった際にstayhereframeが長くなってしまうので、ここで強制的に0にする。
			stayhereframe = 0;
			ranndamulock = 0;//再び物理攻撃できるように0にする。
			enemyzannzoulockframe1 = 0;
			enemyzannzoulock2 = 0;
			stayhere = 0;
		}
	}
}

//ハートポイントがたまった場合の最後の選択肢。
void settoku10() {
	SetFontSize(16);
	if (serekutobotanncount2 == 5) {
		DrawFormatString(25, 150, GetColor(255, 255, 0), "You can persuade the last time with the select button.");
		//攻撃中にセレクトするとバグでplayerkonntororulockの値が0のままになるので motonomasunimodoruが0、攻撃が終わった後に押せるようにした。
		if (Pad[PAD_7] == 1 && motonomasunimodoru == 0 && zannzou == 0 && zannzouA == 0 && zannzouB == 0 && zannzouC == 0) {
			settokuSeen = 1;//説得するためのシーンへ移動する。
			stayhere = 1;//敵の動きを止める
			stayhere2 = 1;
			playerkonntororulock3 = 1;//主人公の操作を止める。
			R1botannlock = 1;
		}
		if (settokuSeen == 1) {
			stayhere = 1;//敵の動きを止める
			stayhere2 = 1;
			//Aボタンを押すと
			//PlayMovieToGraph(settokugamenntyuunohaikeiHandle);
			//DrawExtendGraph(0, 0, 870, 780, settokugamenntyuunohaikeiHandle, FALSE);
			drawString(48, 100, 600, Cr);
			drawString(49, 100, 630, Cr);
			//drawString(40, 100, 700, Cr);
			//Aボタン
			if (Pad[PAD_1] == 1) {
				settokubunnki = 1;
			}

			//Bボタンを押すと
			if (Pad[PAD_2] == 1) {
				settokubunnki = 2;
			}
			//Yボタンを押すと
			//if (Pad[PAD_4] == 1) {
			//	settokubunnki = 3;
			//}
		}
		//彼女が待っている！　何も知らないくせに言いやがって、もういい戦うのをやめる
		if (settokubunnki == 1) {
			settokuSeen = 0;
			drawString(50, 100, 600, RED);
			settokubunnkiframe = 1;
			//analognoizu = 1;//test2.cppへ進む。
		}
		//もう戦う必要はないようだ。　ああ降参だ。
		if (settokubunnki == 2) {
			settokuSeen = 0;
			drawString(51, 100, 600, RED);
			settokubunnkiframe = 1;
			//analognoizu = 1;//test2.cppへ進む。

		}
		if (settokubunnkiframe > 0 && settokubunnki == 1) {
			playerkonntororulock3 = 1;//主人公の操作を止める。
			R1botannlock = 1;//ここで1にして、スライド移動できないようにする。
			++settokubunnkiframe2;
		}
		if (settokubunnkiframe > 0 && settokubunnki == 2) {
			playerkonntororulock3 = 1;//主人公の操作を止める。
			R1botannlock = 1;//ここで1にして、スライド移動できないようにする。
			++settokubunnkiframe3;
		}
		if (settokubunnkiframe2 > 1000) {
			serekutobotanncount2 = 6;//一回説得したら一回目の説得が出ないように。
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 1;//敵の動きを止める
			stayhere2 = 1;//敵の動きを止める
			analognoizu = 2;//test2.cppへ進む。
		}
		if (settokubunnkiframe3 > 1000) {
			serekutobotanncount2 = 6;//一回説得したら一回目の説得が出ないように。
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 1;//敵の動きを止める
			stayhere2 = 1;//敵の動きを止める
			analognoizu = 2;//test2.cppへ進む。
		}
	}
}

//ハートポイントがたまらなかった場合の最後の選択肢。
void settoku11() {
	SetFontSize(16);
	if (serekutobotanncount2 == 5) {
		DrawFormatString(25, 150, GetColor(255, 255, 0), "セレクトボタンで最後の説得に入ることが出来ます。");
		//攻撃中にセレクトするとバグでplayerkonntororulockの値が0のままになるので motonomasunimodoruが0、攻撃が終わった後に押せるようにした。
		if (Pad[PAD_7] == 1 && motonomasunimodoru == 0 && zannzou == 0 && zannzouA == 0 && zannzouB == 0 && zannzouC == 0) {
			settokuSeen = 1;//説得するためのシーンへ移動する。
			stayhere = 1;//敵の動きを止める
			stayhere2 = 1;
			playerkonntororulock3 = 1;//主人公の操作を止める。
			R1botannlock = 1;
		}
		if (settokuSeen == 1) {
			stayhere = 1;//敵の動きを止める
			stayhere2 = 1;
			//Aボタンを押すと
			//PlayMovieToGraph(settokugamenntyuunohaikeiHandle);
			//DrawExtendGraph(0, 0, 870, 780, settokugamenntyuunohaikeiHandle, FALSE);
			drawString(52, 100, 600, Cr);
			//drawString(40, 100, 700, Cr);
			//Aボタン
			if (Pad[PAD_1] == 1) {
				settokubunnki = 1;
			}

		}
		//どうやら殺すしかないようだ。
		if (settokubunnki == 1) {
			settokuSeen = 0;
			drawString(53, 100, 600, RED);
			settokubunnkiframe = 1;
		}
		
		if (settokubunnkiframe > 0) {
			playerkonntororulock3 = 1;//主人公の操作を止める。
			++settokubunnkiframe2;
		}
		if (settokubunnkiframe2 > 1000) {
			serekutobotanncount2 = 6;//一回説得したら一回目の説得が出ないように。
			settokubunnkiframe = 0;
			settokubunnkiframe2 = 0;
			stayhere = 1;//敵の動きを止める
			stayhere2 = 1;//敵の動きを止める
			playerkonntororulock3 = 1;//主人公の操作を止める。//たまに説得に入る直前に攻撃されsettokubunnkiframe2が400を超える前にここが0になることがあるが、こればかりは面倒なのでこれでいい。
			settokubunnki = 0;
			//敵が攻撃を食らった際にstayhereframeが長くなってしまうので、ここで強制的に0にする。
			stayhereframe = 0;
			ranndamulock = 0;//再び物理攻撃できるように0にする。
			enemyzannzoulockframe1 = 0;
			enemyzannzoulock2 = 0;
			stayhere = 0;

		}
	}
}


#endif