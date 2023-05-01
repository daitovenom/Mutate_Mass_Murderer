#include "DxLib.h"

#ifndef DEF_KEY_H //二重include防止

#define DEF_KEY_H
int Key[256];


int gpUpdateKey()
{
	char tmpKey[256];
	GetHitKeyStateAll(tmpKey);
	for (int i = 0; i < 256; i++)
		(tmpKey[i] == 0) ? (Key[i] = 0) : Key[i]++;
	return 0;
}
int Pad[32];
//ジョイパッドのボタンのための関数
int gpUpdatePad()
{
	int padStat = GetJoypadInputState(DX_INPUT_KEY_PAD1);    //入力状態を padStat に格納
	for (int i = 0; i < 28; i++) {                            //ボタン28個分ループ
		if (padStat & (1 << i)) {                            //ボタンiの入力フラグが立っていたら
			Pad[i]++;                                        //加算
		}
		else {                                            //入力がなければ
			Pad[i] = 0;                                        //0 にする
		}
	}

	return 0;
}
int PrevPadState = 0;  //適切な初期値は0かなきっと
int CurrPadState = 0;  //適切な初期値は0かなきっと
void UpdatePadState()
{
	//「前回」情報を更新
	PrevPadState = CurrPadState;
	//「今回」情報を更新
	CurrPadState = GetJoypadInputState(DX_INPUT_KEY_PAD1);  //引数はこれで良いのかな？
}



#endif
#pragma once