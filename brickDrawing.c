#include "brickDrawing.h"
#include <allegro.h>

void povoamento(){
	int i, j, col1 = 0, col2 = 125, col3 = 250;
  for(i=0; i<8; i++){
    for(j=0; j<10; j++){
      bX1[i][j] = 20 + (j*190);
      bY1[i][j] = 20 + (i*50);
      bX2[i][j] = 20 + (j*190) + 180;
  		bY2[i][j] = 20 + (i*50) + 40;
      colVM[i][j] = col1;
			colVD[i][j] = col2;
			colAZ[i][j] = col3;
      rectfill(buffer, bX1[i][j], bY1[i][j], bX2[i][j], bY2[i][j], makecol(colVM[i][j],colVD[i][j],colAZ[i][j]));
      col1 += 25;
      col2 += 10;
      col3 -= 25;
    }
  }
  draw_sprite(screen, buffer, 0, 0);
}