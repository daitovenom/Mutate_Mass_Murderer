

#ifndef DEF_suraidoidoubyouga_H //二重include防止

#define DEF_suraidoidoubyouga_H


//R1でスライド移動する部分。
void suraidoidoubyouga() {
	
		if (suraidobyouga > 0 && suraidobyouga < 5) {
			DrawRotaGraph(pos[playerY][playerX][0] - 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + yokeruX,
				pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, playeridouA4Handle[0], TRUE);
			zannzoulock = 1;
		}
		if (suraidobyouga > 5 && suraidobyouga < 10) {
			DrawRotaGraph(pos[playerY][playerX][0] - 30 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + yokeruX,
				pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, playeridouA4Handle[0], TRUE);
		}
		if (suraidobyouga > 10 && suraidobyouga < 15) {
			DrawRotaGraph(pos[playerY][playerX][0] - 40 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + yokeruX,
				pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, playeridouA4Handle[0], TRUE);
		}
		if (suraidobyouga > 15 && suraidobyouga < 20) {
			DrawRotaGraph(pos[playerY][playerX][0] - 50 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + yokeruX,
				pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, playeridouA4Handle[0], TRUE);
			zannzoulock = 0;
		}
		if (suraidobyouga > 20) {
			suraidobyouga = 0;
			zannzoulock = 0;
		}
	}



void suraidoidoubyouga2() {
	if (suraidobyouga2 > 0 && suraidobyouga2 < 5) {
		DrawRotaGraph(pos[playerY][playerX][0] - 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, playeridouA2Handle[0], TRUE);
		zannzoulock = 1;
	}
	if (suraidobyouga2 > 5 && suraidobyouga2 < 10) {
		DrawRotaGraph(pos[playerY][playerX][0] - 30 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, playeridouA2Handle[0], TRUE);
	}
	if (suraidobyouga2 > 10 && suraidobyouga2 < 15) {
		DrawRotaGraph(pos[playerY][playerX][0] - 40 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, playeridouA2Handle[0], TRUE);
	}
	if (suraidobyouga2 > 15 && suraidobyouga2 < 20) {
		DrawRotaGraph(pos[playerY][playerX][0] - 50  + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, playeridouA2Handle[0], TRUE);
	}
	if (suraidobyouga2 > 20) {
		suraidobyouga2 = 20;
		
	}
	if (suraidobyouga2 == 20) {
		zannzoulock = 0;
	}
}
void suraidoidoubyouga3() {
	if (suraidobyouga3 > 0 && suraidobyouga3 < 5) {
		DrawRotaGraph(pos[playerY][playerX][0] - 20  + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, playeridouA3Handle[0], TRUE);
		zannzoulock = 1;
	}
	if (suraidobyouga3 > 5 && suraidobyouga3 < 10) {
		DrawRotaGraph(pos[playerY][playerX][0] - 30  + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, playeridouA3Handle[0], TRUE);
	}
	if (suraidobyouga3 > 10 && suraidobyouga3 < 15) {
		DrawRotaGraph(pos[playerY][playerX][0] - 40  + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, playeridouA3Handle[0], TRUE);
	}
	if (suraidobyouga3 > 15 && suraidobyouga3 < 20) {
		DrawRotaGraph(pos[playerY][playerX][0] - 50  + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, playeridouA3Handle[0], TRUE);
	}
	if (suraidobyouga3 > 20) {
		suraidobyouga3 = 0;
		zannzoulock = 0;
	}
	

	
}
void suraidoidoubyouga4() {
	if (suraidobyouga4 > 0 && suraidobyouga4 < 5) {
		DrawRotaGraph(pos[playerY][playerX][0] - 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4, bairituX, 0, playeridouA4Handle[0], TRUE);
		zannzoulock = 1;
	}
	if (suraidobyouga4 > 5 && suraidobyouga4 < 10) {
		DrawRotaGraph(pos[playerY][playerX][0] - 30 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4, bairituX, 0, playeridouA4Handle[0], TRUE);
	}
	if (suraidobyouga4 > 10 && suraidobyouga4 < 15) {
		DrawRotaGraph(pos[playerY][playerX][0] - 40 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4, bairituX, 0, playeridouA4Handle[0], TRUE);
	}
	if (suraidobyouga4 > 15 && suraidobyouga4 < 20) {
		DrawRotaGraph(pos[playerY][playerX][0] - 50 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4, bairituX, 0, playeridouA4Handle[0], TRUE);
	}
	if (suraidobyouga4 > 20) {
		suraidobyouga4 = 0;
		zannzoulock = 0;
	}
}

void suraidoidoubyouga5() {
	if (suraidobyouga5 > 0 && suraidobyouga5 < 5) {
		DrawRotaGraph(pos[playerY][playerX][0] - 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playeridouA5Handle[0], TRUE);
		zannzoulock = 1;
	}
	if (suraidobyouga5 > 5 && suraidobyouga5 < 10) {
		DrawRotaGraph(pos[playerY][playerX][0] - 30 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playeridouA5Handle[0], TRUE);
	}
	if (suraidobyouga5 > 10 && suraidobyouga5 < 15) {
		DrawRotaGraph(pos[playerY][playerX][0] - 40 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playeridouA5Handle[0], TRUE);
	}
	if (suraidobyouga5 > 15 && suraidobyouga5 < 20) {
		DrawRotaGraph(pos[playerY][playerX][0] - 50 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playeridouA5Handle[0], TRUE);
	}
	if (suraidobyouga5 > 20) {
		suraidobyouga5 = 0;
		zannzoulock = 0;
	}
}








//左向きスライド
void suraidohidariidoubyouga() {

	if (suraidobyouga > 0 && suraidobyouga < 5) {
		DrawRotaGraph(pos[playerY][playerX][0] - 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, playeridouA4hidariHandle[0], TRUE);
		zannzoulock = 1;
	}
	if (suraidobyouga > 5 && suraidobyouga < 10) {
		DrawRotaGraph(pos[playerY][playerX][0] - 30 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, playeridouA4hidariHandle[0], TRUE);
	}
	if (suraidobyouga > 10 && suraidobyouga < 15) {
		DrawRotaGraph(pos[playerY][playerX][0] - 40 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, playeridouA4hidariHandle[0], TRUE);
	}
	if (suraidobyouga > 15 && suraidobyouga < 20) {
		DrawRotaGraph(pos[playerY][playerX][0] - 50 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, playeridouA4hidariHandle[0], TRUE);
		zannzoulock = 0;
	}
	if (suraidobyouga > 20) {
		suraidobyouga = 0;
		zannzoulock = 0;
	}
}



void suraidohidariidoubyouga2() {
	if (suraidobyouga2 > 0 && suraidobyouga2 < 5) {
		DrawRotaGraph(pos[playerY][playerX][0] - 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, playeridouA2hidariHandle[0], TRUE);
		zannzoulock = 1;
	}
	if (suraidobyouga2 > 5 && suraidobyouga2 < 10) {
		DrawRotaGraph(pos[playerY][playerX][0] - 30 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, playeridouA2hidariHandle[0], TRUE);
	}
	if (suraidobyouga2 > 10 && suraidobyouga2 < 15) {
		DrawRotaGraph(pos[playerY][playerX][0] - 40 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, playeridouA2hidariHandle[0], TRUE);
	}
	if (suraidobyouga2 > 15 && suraidobyouga2 < 20) {
		DrawRotaGraph(pos[playerY][playerX][0] - 50 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, playeridouA2hidariHandle[0], TRUE);
	}
	if (suraidobyouga2 > 20) {
		suraidobyouga2 = 20;

	}
	if (suraidobyouga2 == 20) {
		zannzoulock = 0;
	}
}
void suraidohidariidoubyouga3() {
	if (suraidobyouga3 > 0 && suraidobyouga3 < 5) {
		DrawRotaGraph(pos[playerY][playerX][0] - 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, playeridouA3hidariHandle[0], TRUE);
		zannzoulock = 1;
	}
	if (suraidobyouga3 > 5 && suraidobyouga3 < 10) {
		DrawRotaGraph(pos[playerY][playerX][0] - 30 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, playeridouA3hidariHandle[0], TRUE);
	}
	if (suraidobyouga3 > 10 && suraidobyouga3 < 15) {
		DrawRotaGraph(pos[playerY][playerX][0] - 40 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, playeridouA3hidariHandle[0], TRUE);
	}
	if (suraidobyouga3 > 15 && suraidobyouga3 < 20) {
		DrawRotaGraph(pos[playerY][playerX][0] - 50 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, playeridouA3hidariHandle[0], TRUE);
	}
	if (suraidobyouga3 > 20) {
		suraidobyouga3 = 0;
		zannzoulock = 0;
	}



}
void suraidohidariidoubyouga4() {
	if (suraidobyouga4 > 0 && suraidobyouga4 < 5) {
		DrawRotaGraph(pos[playerY][playerX][0] - 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + yokeruX,
		pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4, bairituX, 0, playeridouA4hidariHandle[0], TRUE);
		zannzoulock = 1;
	}
	if (suraidobyouga4 > 5 && suraidobyouga4 < 10) {
		DrawRotaGraph(pos[playerY][playerX][0] - 30 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + yokeruX,
		pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4, bairituX, 0, playeridouA4hidariHandle[0], TRUE);
	}
	if (suraidobyouga4 > 10 && suraidobyouga4 < 15) {
		DrawRotaGraph(pos[playerY][playerX][0] - 40 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + yokeruX,
		pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4, bairituX, 0, playeridouA4hidariHandle[0], TRUE);
	}
	if (suraidobyouga4 > 15 && suraidobyouga4 < 20) {
		DrawRotaGraph(pos[playerY][playerX][0] - 50 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + yokeruX,
		pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4, bairituX, 0, playeridouA4hidariHandle[0], TRUE);
	}
	if (suraidobyouga4 > 20) {
		suraidobyouga4 = 0;
		zannzoulock = 0;
	}
}

void suraidohidariidoubyouga5() {
	if (suraidobyouga5 > 0 && suraidobyouga5 < 5) {
		DrawRotaGraph(pos[playerY][playerX][0] - 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playeridouA5hidariHandle[0], TRUE);
		zannzoulock = 1;
	}
	if (suraidobyouga5 > 5 && suraidobyouga5 < 10) {
		DrawRotaGraph(pos[playerY][playerX][0] - 30 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playeridouA5hidariHandle[0], TRUE);
	}
	if (suraidobyouga5 > 10 && suraidobyouga5 < 15) {
		DrawRotaGraph(pos[playerY][playerX][0] - 40 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playeridouA5hidariHandle[0], TRUE);
	}
	if (suraidobyouga5 > 15 && suraidobyouga5 < 20) {
		DrawRotaGraph(pos[playerY][playerX][0] - 50 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3 + nanameidouX4 + nanameidouX5 + yokeruX,
			pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3 + nanameidouY4 + nanameidouY5, bairituX, 0, playeridouA5hidariHandle[0], TRUE);
	}
	if (suraidobyouga5 > 20) {
		suraidobyouga5 = 0;
		zannzoulock = 0;
	}
}
#endif