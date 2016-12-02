#include <allegro.h>
#include <stdio.h>
#include "brickDrawing.h"
#include "bat.h"
#include "options.h"

void printBrick(BITMAP* buffer){
  int i, j;
  //clear(buffer);
  circlefill(buffer, bola.bolX, bola.bolY, bola.bolR, makecol(255,0,0));

  for(i=Pcol - 1; i<Ucol; i++){
    for(j=Plinha - 1; j<Ulinha; j++){
      if(brick[i][j].bit == 1){
        rectfill(buffer, brick[i][j].bX1, brick[i][j].bY1, brick[i][j].bX2, brick[i][j].bY2, makecol(brick[i][j].colVM,brick[i][j].colVD,brick[i][j].colAZ));
      }
    }
  }
  return;
}

void povoamento(){

  int Blarg = (((SCREEN_W - 40) / (Ncol)) - MeB);
  int Balt = ((((SCREEN_H/2) - 20) / (Nlinha)) - MeB);

  int i, j, col1 = 0, col2 = 125, col3 = 250;
  for(i=Pcol - 1; i<Ucol; i++){
    for(j=Plinha - 1; j<Ulinha; j++){
      brick[i][j].bX1 = 20 + (i*(Blarg + MeB));
      brick[i][j].bY1 = 20 + (j*(Balt + MeB));
      brick[i][j].bX2 = 20 + (i*(Blarg + MeB)) + Blarg;
      brick[i][j].bY2 = 20 + (j*(Balt + MeB)) + Balt;
      brick[i][j].colVM = col1;
      brick[i][j].colVD = col2;
      brick[i][j].colAZ = col3;
      col1 += 25;
      col2 += 10;
      col3 -= 25;
      brick[i][j].bit = 1;
      col[i][j].setC=0;
      col[i][j].setB=0;
      col[i][j].setE=0;
      col[i][j].setD=0;
    }
  }
  bola.bolX = SCREEN_W / 2;
  bola.bolY = SCREEN_H;
  bola.bolR = RAIO;
  bola.psB = -1;
  bola.psL = 1;
  bola.incA = 1;
  bola.incB = 1;
  return;
}

void breakbrick(){
  int i, j;
  for(i=Pcol - 1; i<Ucol; i++){
    for(j=Plinha - 1; j<Ulinha; j++){
      if(((bola.bolY - RAIO) <= brick[i][j].bY2) && ((bola.bolY - RAIO) >= brick[i][j].bY1) && (brick[i][j].bit == 1)){  //Em cima
        if(col[i][j].setD == 1 || col[i][j].setE == 1){
          bola.psB = 1;
          brick[i][j].bit = 0;
        }
        col[i][j].setC = 1;
      }
      else
        col[i][j].setC = 0;
      
      if(((bola.bolY + RAIO) <= brick[i][j].bY2) && ((bola.bolY + RAIO) >= brick[i][j].bY1) && (brick[i][j].bit == 1)){  //Embaixo
        if(col[i][j].setD == 1 || col[i][j].setE == 1){
          bola.psB = -1;
          brick[i][j].bit = 0;
        }
        col[i][j].setB = 1;
      }
      else
        col[i][j].setB = 0;
      
      if((brick[i][j].bit == 1) && ((bola.bolX + RAIO) <= brick[i][j].bX2) && ((bola.bolX + RAIO) >= brick[i][j].bX1)){ //Direita
        if(col[i][j].setC == 1 || col[i][j].setB == 1){
          bola.psL = -1;
          brick[i][j].bit = 0;
        }
        col[i][j].setD = 1;
      }
      else
        col[i][j].setD = 0;
      
      if((brick[i][j].bit == 1) && ((bola.bolX - RAIO) <= brick[i][j].bX2) && ((bola.bolX - RAIO) >= brick[i][j].bX1)){ //Esquerda
        if(col[i][j].setC == 1 || col[i][j].setB == 1){
          bola.psL = 1;
          brick[i][j].bit = 0;
        }
        col[i][j].setE = 1;
      }
      else 
        col[i][j].setE = 0;
    }
  }
  return;
}

void bolinha(){
  bola.bolX = bola.bolX + (bola.psL*VEL)*bola.incB;
  bola.bolY = bola.bolY + (bola.psB*VEL)*bola.incA;
  if((bola.bolX + RAIO) >= SCREEN_W){
    bola.psL = -1;
  }
  if((bola.bolX - RAIO) <= 0){
    bola.psL = 1;
  }
  if((bola.bolY + RAIO) >= SCREEN_H){
    bola.psB = -1;
  }
  if((bola.bolY - RAIO) <= 0){
    bola.psB = 1;
  }
  return;
}



void barrabrick(){

  int batYTopPosition = SCREEN_H - (BAT_Y_OFFSET + BAT_HEIGTH);
  int batDivisionStep = options_batSize / 7;
  printf("%d\n", batDivisionStep);


  if((bola.bolY + RAIO) >= (batYTopPosition)){
    if((bola.bolX >= batPosition) && (bola.bolX <= (batPosition + 40))){
      bola.psB = -1;
      bola.incA = 1;
      bola.incB = 3;
    } 
    else if((bola.bolX > batPosition + batDivisionStep) && (bola.bolX <= (batPosition + batDivisionStep*2))){
      bola.psB = -1;
      bola.incA = 2;
      bola.incB = 2;
    }
    else if((bola.bolX > batPosition + batDivisionStep*2) && (bola.bolX <= (batPosition + batDivisionStep*3))){
      bola.psB = -1;
      bola.incA = 3;
      bola.incB = 1;
    }
    else if((bola.bolX > batPosition + batDivisionStep*3) && (bola.bolX <= (batPosition + batDivisionStep*4))){
      bola.psB = -1;
      bola.incA = 4;
      bola.incB = 0;
    }
    else if((bola.bolX > batPosition + batDivisionStep*4) && (bola.bolX <= (batPosition + batDivisionStep*5))){
      bola.psB = -1;
      bola.incA = 3;
      bola.incB = 1;
    }
    else if((bola.bolX > batPosition + batDivisionStep*5) && (bola.bolX <= (batPosition + batDivisionStep*6))){
      bola.psB = -1;
      bola.incA = 2;
      bola.incB = 2;
    }
    else if((bola.bolX > batPosition + batDivisionStep*6) && (bola.bolX <= (batPosition + batDivisionStep*7))){
      bola.psB = -1;
      bola.incA = 1;
      bola.incB = 3;
    }
  }
  return;
}
