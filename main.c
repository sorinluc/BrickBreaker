#include <stdio.h>
#include <allegro.h>
#include "menu.h"

volatile int exit_program;

int main()
{
   allegro_init(); //Inicializa itens básicos da biblioteca
   install_timer(); //Timers necessários para áudio, mouse...
   install_keyboard(); //Instalando teclado
   set_color_depth(32); //Setar profundidade das cores (32 bits p/ combinações de cores
   set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1920, 1080, 0, 0); //Setar Vídeo (Driver de vídeo, 800x600 de resolução, 0 e 0 parâmetros para tela virtual) 
   set_window_title("Brick Braker"); //Título da janela

   while(!key[KEY_ESC]) //Enquanto key ESC não pressionada. KEY_ESC é um define para o número da tecla ESC

   {
	 menu_displayMenu(screen);
	 menu_updateMenu();
   }

   return 0;
}
END_OF_MAIN();
