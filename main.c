#include <stdio.h>
#include <allegro.h>
#include "brickDrawing.h"

volatile int exit_program;


void bolinha(){
}

int main()
{ 
  BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
  allegro_init(); //Inicializa itens básicos da biblioteca
  install_timer(); //Timers necessários para áudio, mouse...
  install_keyboard(); //Instalando teclado
  set_color_depth(32); //Setar profundidade das cores (32 bits p/ combinações de cores
  set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1920, 1080, 0, 0); //Setar Vídeo (Driver de vídeo, 800x600 de resolução, 0 e 0 parâmetros para tela virtual) 
  set_window_title("Brick Braker"); //Título da janela
  
   exit_program = FALSE;
  povoamento(&buffer);
  
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