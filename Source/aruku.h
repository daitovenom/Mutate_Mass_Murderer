#ifndef aruku_H //“ñdinclude–h~

#define aruku_H

void arukukannsuu() {
	
	if (migiaruku > 0 && migiaruku < 20 && motonomasunimodoru == 0) {
		zannzoulock = 1;
		if (migiaruku > 0 && migiaruku < 10) {
			DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, migiarukugazou[0], TRUE);
			
		}
		if (migiaruku > 10 && migiaruku < 20) {
			DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, migiaruku2gazou[0], TRUE);

		}
	}
	if (migiaruku > 20) {
		migiaruku = 0;
	}

	if (hidariaruku > 0 && hidariaruku < 20 && motonomasunimodoru == 0) {
		zannzoulock = 1;
		if (hidariaruku > 0 && hidariaruku < 10) {
			DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, hidariarukugazou[0], TRUE);
			
		}
		if (hidariaruku > 10 && hidariaruku < 20) {
			DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, hidariaruku2gazou[0], TRUE);

		}
	}
	if (hidariaruku > 20) {
		hidariaruku = 0;
	}

	if (sitaaruku > 0 && sitaaruku < 20 && motonomasunimodoru == 0) {
		zannzoulock = 1;
		if (sitaaruku > 0 && sitaaruku < 10) {
			DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0,sitaarukugazou[0], TRUE);

		}
		if (sitaaruku > 10 && sitaaruku < 20) {
			DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0,sitaaruku2gazou[0], TRUE);

		}
	}
	if (sitaaruku > 20) {
		sitaaruku = 0;
	}

	if (uearuku > 0 && uearuku < 20 && motonomasunimodoru == 0) {
		zannzoulock = 1;
		if (uearuku > 0 && uearuku < 10) {
			DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0, uearukugazou[0], TRUE);

		}
		if (uearuku > 10 && uearuku < 20) {
			DrawRotaGraph(pos[playerY][playerX][0] + 20 + nanameidouX + migiidou + nanameidouX2 + nanameidouX3, pos[playerY][playerX][1] - 13 + nanameidouY + nanameidouY2 + nanameidouY3, bairituX, 0,uearuku2gazou[0], TRUE);

		}
	}
	if (uearuku > 20) {
		uearuku = 0;
	}






	
}


#endif