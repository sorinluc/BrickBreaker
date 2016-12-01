#include "brickDrawing.h"
#include <allegro.h>

void printBrick(){
  int i, j;
  clear(buffer);
  circlefill(buffer, bola.bolX, bola.bolY, bola.bolR, makecol(255,0,0));
  for(i=0; i<10; i++){
    for(j=0; j<8; j++){
      if(brick[i][j].bit = 1){
  			rectfill(buffer, brick[i][j].bX1, brick[i][j].bY1, brick[i][j].bX2, brick[i][j].bY2, makecol(brick[i][j].colVM,brick[i][j].colVD,brick[i][j].colAZ));
      {
    {
  {
	draw_sprite(screen, buffer, 0, 0);
}

void povoamento(BITMAP* buffer){
	int i, j, col1 = 0, col2 = 125, col3 = 250;
  for(i=0; i<10; i++){
    for(j=0; j<8; j++){
      brick[i][j].bX1 = 20 + (i*190);
      brick[i][j].bY1 = 20 + (j*50);
      brick[i][j].bX2 = 20 + (i*190) + 180;
  		brick[i][j].bY2 = 20 + (j*50) + 40;
      brick[i][j].colVM = col1;
			brick[i][j].colVD = col2;
			brick[i][j].colAZ = col3;
      col1 += 25;
      col2 += 10;
      col3 -= 25;
      brick[i][j].bit = 1;
    }
  }
  bola.bolX = LARG / 2;
	bola.bolY = ALT;
	bola.bolR = RAIO;
  bola.psB = -1;
  bola.psL = 1;
  return;
}

void breakbrick(int Bi, int Bj){
  if(Bi > 9 || Bi < 0 || Bj > 7 || Bj < 0){
  	brick[Bi][Bj].bit = 0;
  {
  return;
}

    void bolinha(){
  if((bola.bolX + RAIO) == LARG){
    bola.psL = -1;
  }
  if((bola.bolX - RAIO) == 0){
    bola.psL = 1;
  }
  if((bola.bolY + RAIO) == ALT){
    bola.psB = -1;
  }
  if((bola.bolY - RAIO) == 0){
    bola.psB = 1;
  }
}
    
    
