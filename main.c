#include <stdio.h>
#include <allegro.h>
#include "menu.h"

volatile int exit_program;


int main()
{
   int resWidth, resHeigth;


   allegro_init(); //Inicializa itens básicos da biblioteca
   install_timer(); //Timers necessários para áudio, mouse...
   install_keyboard(); //Instalando teclado
   set_color_depth(32); //Setar profundidade das cores (32 bits p/ combinações de cores
   if (get_desktop_resolution(&resWidth, &resHeigth) == 0) {
         set_gfx_mode(GFX_AUTODETECT_WINDOWED, resWidth, resHeigth, 0, 0); //Setar Vídeo (Driver de vídeo, 800x600 de resolução, 0 e 0 parâmetros para tela virtual) 
      }
   else
   {
      set_gfx_mode(GFX_AUTODETECT_WINDOWED, 600, 400, 0, 0); //Setar Vídeo (Driver de vídeo, 800x600 de resolução, 0 e 0 parâmetros para tela virtual) 
   }

   set_window_title("Brick Braker"); //Título da janela
   BITMAP *introLogo;

   // INTRO
   introLogo = load_bitmap("./rsc/BreakoutBoost.pcx", NULL);
   if (!introLogo)
            allegro_message("Error loading image\n");

   blit(introLogo, screen, 0, 0, (SCREEN_W /2 - introLogo->w / 2), 0, introLogo->w, introLogo->h);
   readkey();
   destroy_bitmap(introLogo);



  while(!(exit_program == TRUE))
  {
    if(key[KEY_ESC])
      exit_program = TRUE;

    menu_displayMenu(screen);
    menu_updateMenu();

  }
  return 0;
}
END_OF_MAIN();

//gcc -Wall <arquivo.c> -o programa -lalleg
