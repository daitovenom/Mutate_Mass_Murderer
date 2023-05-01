#include "DxLib.h"
#include "talk.h"
#pragma warning(disable: 4996)

#ifndef DEF_TAITOLH_H //二重include防止

#define DEF_TAITOLH_H
int tai = 1;
int cheak = 0;
int haikei = 1;

int sound1 = 0;
int sound2 = 0;
//FILE* fp;
//char filename[] = "test.dat";
int  buf_r[1], buf_w[1];
int yomikomi = 0;
typedef struct {
	int Seen;
}SaveData_t;

void taitol() {
	if (Seen == 0) {
		if (taitolhaikei == 0) {
			DrawExtendGraph(0, 0, 1470, 480, taitolhaikeiHandle, FALSE);
		}
		
		if (tai == 1) {
			
			if (taitollock == 0) {
				++taitoitoumeika;
			}

			//mutate mass murderの部分。
				if (taitoitoumeika > 0) {
					//taitoitoumeika = taitoitoumeika / 10;
					SetDrawBlendMode(DX_BLENDMODE_ALPHA,taitoitoumeika/6);		//ブレンドモードをα(128/255)に設定
					DrawExtendGraph(50, 50, 1420, 380, taitolHandle[0], FALSE);
				}
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);		//ブレンドモードをリセット（他の画像が薄くならないようにするため）	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - toumeika);		//ブレンドモードをα(128/255)に設定
				if (taitoitoumeika > 1800) {
					taitoitoumeika = 1800;
					taitolred = 1;
					taitollock = 1;
				}
				if (taitoitoumeika > 100 && taitoitoumeika < 102) {
					taitolsound = LoadSoundMem("taitol.mp3");
					ChangeVolumeSoundMem(170, taitolsound);//この関数によって音声のボリュームを設定できる。
					PlaySoundMem(taitolsound, DX_PLAYTYPE_BACK);
					wakaresound = LoadSoundMem("グリンカ：ノクターン 別れ.mp4");
					ChangeVolumeSoundMem(130, wakaresound);//この関数によって音声のボリュームを設定できる。
					PlaySoundMem(wakaresound, DX_PLAYTYPE_BACK);
					
				}
				//最後らへんに少し赤が薄くなるようにしたが、真っ赤なままにした。
				//if (taitolred == 1) {
				//	--taitoitoumeika;
				//	SetDrawBlendMode(DX_BLENDMODE_ALPHA, taitoitoumeika/8);		//ブレンドモードをα(128/255)に設定
				//	DrawExtendGraph(50, -400, 1420, 680, taitolHandle[0], FALSE);
				//	if (taitoitoumeika < 1350) {
				//		taitoitoumeika = 1350;
				//		taitolred = 0;
				//	}
				//}

				//HAND OF DEATHの部分。
				if (taitollock2 == 0 && taitoitoumeika > 150) {
					++taitoitoumeika2;
				}
				if (taitoitoumeika2 > 0) {
					SetDrawBlendMode(DX_BLENDMODE_ALPHA, taitoitoumeika2 / 6);		//ブレンドモードをα(128/255)に設定
					DrawExtendGraph(180,450, 1320, 550, taitol2Handle[0], FALSE);

				}
				SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);		//ブレンドモードをリセット（他の画像が薄くならないようにするため）	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 - toumeika);		//ブレンドモードをα(128/255)に設定
				if (taitoitoumeika2 > 1500) {
					taitoitoumeika2 = 1500;
					taitolred2 = 1;
					taitollock2 = 1;
					taitolhaikei = 1;//タイトルの背景を消すための変数。
				}
				//if (taitolred2 == 1) {
				//	--taitoitoumeika2;
				//	SetDrawBlendMode(DX_BLENDMODE_ALPHA, taitoitoumeika2 / 8);		//ブレンドモードをα(128/255)に設定
				//	DrawExtendGraph(80, 450, 1420, 550, taitol2Handle[0], FALSE);
				//	if (taitoitoumeika2 < 1350) {
				//		taitoitoumeika2 = 1350;
				//		taitolred2 = 0;
				//	}
				//}
																	
																	//他の文字の部分は255、ようはそのままの明るさでの文字になるようにするためにコイツが必要。
				
				//DrawFormatString(0, 540, GetColor(255, 105, 0), " taitolredは%d,taitoitoumeikaは%d,taitoitoumeika2は%d", taitolred, taitoitoumeika, taitoitoumeika2);

				// 描画する文字列のサイズを設定
			SetFontSize(16);
			//DrawFormatString(560, 580, GetColor(255, 255, 0), "mutate mass murder");
			DrawFormatString(560, 620, GetColor(255, 255, 0), "スペースキーを押してスタート");
			//DrawFormatString(50, 450, GetColor(255, 255, 0), "yomikomiは%d,buf_r[yomikomi]は%d", yomikomi, buf_r[1]);
			if (Pad[PAD_8] == 1) {
				startmark = 1;
				mark = 1;
				sound1 = LoadSoundMem("タイトル画面のカチャ.mp3");
				PlaySoundMem(sound1, DX_PLAYTYPE_BACK);
			}
			if (mark == 1) {
				SetFontSize(16);//★if (tai == 1)での時のフォントサイズSetFontSize(44);に上書きされないように、ここに指定したい
				//フォントの情報を書いて置く。
				//DrawFormatString(500, 650, GetColor(255, 255, 0), "キーBを押して続きから");
				DrawFormatString(570, 700, GetColor(255, 255, 0), "キーAを押して最初から");
				last = 0;
			}
			//Pad[PAD_1] == 1はAボタン
			if (startmark == 1 && Pad[PAD_1] == 1) {
				StopSoundMem(wakaresound);//★BGMを途中で止めるための関数
				sound2 = LoadSoundMem("タイトルの銃声.mp3");
				PlaySoundMem(sound2, DX_PLAYTYPE_BACK);
				tai = 0;
				mark = 0;
				startmark = 2;
			}
			
		}
	}
}
#endif