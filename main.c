#include <stdio.h>
#include <allegro.h>

volatile int exit_program;
int bX1[10][10];
int bX2[10][10];
int bY1[10][10];
int bY2[10][10];
int colVM[10][10];
int colVD[10][10];
int colAZ[10][10];
BITMAP* buffer;
  
void povoamento(){
	int i, j, col1 = 0, col2 = 125, col3 = 250;
  for(i=0; i<10; i++){
    for(j=0; j<10; j++){
      bX1[i][j] = 20 + (j*190);
  		bX2[i][j] = 20 + (j*190) + 180;
  		bY1[i][j] = 20 + (i*100);
  		bY2[i][j] = 20 + (i*100) + 90;
      colVM[i][j] = col1;
			colVM[i][j] = col2;
			colAZ[i][j] = col3;
      rectfill(buffer, bX1[i][j], bX2[i][j], bY1[i][j], bY2[i][j], makecol(colVM[i][j],colVM[i][j],colAZ[i][j]));
      col1 += 25;
      col2 += 10;
      col3 -= 25;
    }
  }
}

int main()
{
  allegro_init(); //Inicializa itens básicos da biblioteca
  install_timer(); //Timers necessários para áudio, mouse...
  install_keyboard(); //Instalando teclado
  set_color_depth(32); //Setar profundidade das cores (32 bits p/ combinações de cores
  set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1920, 1080, 0, 0); //Setar Vídeo (Driver de vídeo, 800x600 de resolução, 0 e 0 parâmetros para tela virtual) 
  set_window_title("Brick Braker"); //Título da janela
  
	buffer = create_bitmap(SCREEN_W, SCREEN_H);
	exit_program = FALSE;
  povoamento();
  draw_sprite(screen, buffer, 0, 0);
  
  while(!exit_program)
  {
     //INPUT
      if(key[KEY_ESC])
       exit_program = TRUE;

     //UPDATE

     //DRAW
     //clear(buffer);
  }

  ///FINALIZAÇÃO
  destroy_bitmap(buffer);

  return 0;
}
END_OF_MAIN();

//gcc -Wall <arquivo.c> -o programa -lalleg
