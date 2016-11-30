#include "brickDrawing.h"
#include <allegro.h>

void povoamento(BITMAP* buffer){
	int i, j, col1 = 0, col2 = 125, col3 = 250;

  for(i=0; i<10; i++)  //i é coluna
  {
    for(j=0; j<8; j++)  //j é linha
    {
      brick[i][j].bX1 = 20 + (i*190);
      brick[i][j].bY1 = 20 + (j*50);
      brick[i][j].bX2 = 20 + (i*190) + 180;
  		brick[i][j].bY2 = 20 + (j*50) + 40;
      brick[i][j].colVM = col1;
			brick[i][j].colVD = col2;
			brick[i][j].colAZ = col3;
      rectfill(buffer, brick[i][j].bX1, brick[i][j].bY1, brick[i][j].bX2, brick[i][j].bY2, makecol(brick[i][j].colVM,brick[i][j].colVD,brick[i][j].colAZ));
      col1 += 25;
      col2 += 10;
      col3 -= 25;
      brick[i][j].bit = 1;
    }
  }
  draw_sprite(screen, buffer, 0, 0);
  return;
}

void breakbrick(BITMAP* buffer,int Bi, int Bj){
  brick[Bi][Bj].bit = 0;
  rectfill(buffer, brick[Bi][Bj].bX1, brick[Bi][Bj].bY1, brick[Bi][Bj].bX2, brick[Bi][Bj].bY2, makecol(0,0,0));
  draw_sprite(screen, buffer, 0, 0);
}
