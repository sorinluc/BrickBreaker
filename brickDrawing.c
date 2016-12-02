#include <allegro.h>
#include "brickDrawing.h"

void printBrick(BITMAP* buffer){
  int i, j;
  clear(buffer);
  circlefill(buffer, bola.bolX, bola.bolY, bola.bolR, makecol(255,0,0));
  rectfill(buffer, barra.barX1, barra.barY1, barra.barX2, barra.barY2, makecol(0,255,0));
  for(i=Pcol - 1; i<Ucol; i++){
    for(j=Plinha - 1; j<Ulinha; j++){
      if(brick[i][j].bit == 1){
        rectfill(buffer, brick[i][j].bX1, brick[i][j].bY1, brick[i][j].bX2, brick[i][j].bY2, makecol(brick[i][j].colVM,brick[i][j].colVD,brick[i][j].colAZ));
      }
    }
  }
  draw_sprite(screen, buffer, 0, 0);
  return;
}

void povoamento(){
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
  bola.bolX = LARG / 2;
  bola.bolY = ALT;
  bola.bolR = RAIO;
  bola.psB = -1;
  bola.psL = 1;
  bola.incA = 1;
  bola.incB = 1;
  barra.barX1 = 0; 
  barra.barY1 = ALT - 40;
  barra.barX2 = 280;
  barra.barY2 = ALT;
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
  if((bola.bolX + RAIO) >= LARG){
    bola.psL = -1;
  }
  if((bola.bolX - RAIO) <= 0){
    bola.psL = 1;
  }
  if((bola.bolY + RAIO) >= ALT){
    bola.psB = -1;
  }
  if((bola.bolY - RAIO) <= 0){
    bola.psB = 1;
  }
  return;
}

void barrinha(){
  if(key[KEY_A]){
      key[KEY_A] = FALSE;
      barra.barX1 -= 60; 
      barra.barX2 -= 60;
    }
  else if(key[KEY_S]){
      key[KEY_S] = FALSE;
      barra.barX1 += 60; 
      barra.barX2 += 60;
    }
return;
}

void barrabrick(){
  if((bola.bolY + RAIO) >= (barra.barY1)){
    if((bola.bolX >= barra.barX1) && (bola.bolX <= (barra.barX1 + 40))){
      bola.psB = -1;
      bola.incA = 1;
      bola.incB = 3;
    } 
    if((bola.bolX > barra.barX1 + 40) && (bola.bolX <= (barra.barX1 + 80))){
      bola.psB = -1;
      bola.incA = 2;
      bola.incB = 2;
    }
    if((bola.bolX > barra.barX1 + 80) && (bola.bolX <= (barra.barX1 + 120))){
      bola.psB = -1;
      bola.incA = 3;
      bola.incB = 1;
    }
    if((bola.bolX > barra.barX1 + 120) && (bola.bolX <= (barra.barX1 + 160))){
      bola.psB = -1;
      bola.incA = 4;
      bola.incB = 0;
    }
    if((bola.bolX > barra.barX1 + 160) && (bola.bolX <= (barra.barX1 + 200))){
      bola.psB = -1;
      bola.incA = 3;
      bola.incB = 1;
    }
    if((bola.bolX > barra.barX1 + 200) && (bola.bolX <= (barra.barX1 + 240))){
      bola.psB = -1;
      bola.incA = 2;
      bola.incB = 2;
    }
    if((bola.bolX > barra.barX1 + 240) && (bola.bolX <= (barra.barX1 + 280))){
      bola.psB = -1;
      bola.incA = 1;
      bola.incB = 3;
    }
  }
  return;
}
