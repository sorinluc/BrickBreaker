#include <stdio.h>
#include <allegro.h>
#include "brickDrawing.h"

volatile int exit_program;


void bolinha(){
}

int main()
{ 
  
  allegro_init(); //Inicializa itens básicos da biblioteca
  install_timer(); //Timers necessários para áudio, mouse...
  install_keyboard(); //Instalando teclado
  set_color_depth(32); //Setar profundidade das cores (32 bits p/ combinações de cores
  set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1920, 1080, 0, 0); //Setar Vídeo (Driver de vídeo, 800x600 de resolução, 0 e 0 parâmetros para tela virtual) 
  set_window_title("Brick Breaker"); //Título da janela
  
  BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
  exit_program = FALSE;
  povoamento(buffer);
  
  int x = 0, y = 0;
  
  while(!exit_program)
  {
  //INPUT
    if(key[KEY_ESC])
      exit_program = TRUE;
  //UPDATE
    if(key[KEY_M]){
      breakbrick(buffer, x, y);
      x++;
      y++;
    {
  //DRAW
  }

  //FINALIZAÇÃO
  destroy_bitmap(buffer);
  return 0;
}
END_OF_MAIN();
