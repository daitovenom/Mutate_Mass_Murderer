/*

    *  やること  *
     1 Loadにエラーチェックを書く

   例
	if (MovieGraphHandle = LoadGraph("180half_f.gif") == -1) {
		return false;
	}

      2 Game.hにGame.cppに使われていない変数を消す
      3 使われている変数は初期化値をコンストラクタに入れる


	 *変数名,関数名,クラス名 命名規則*
	  1. 統一する
	  2. 英語
	  3. 関数名とクラス名は最初大文字
	  4. メンバ変数は接頭語に_つける (_flower)
	  
	  クラスイメージ
	  https://docs.google.com/presentation/d/1_T5DsPLDy3s-Na2KTRN0iSM_7fKJoNdbUCPRaOMMROk/edit?usp=sharing

*/