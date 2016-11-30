#include <stdio.h>
#include <allegro.h>
#include "menu.h"

volatile int exit_program;


int main()
{
  
  while(!exit_program)
  {
     //INPUT
      if(key[KEY_ESC])
       exit_program = TRUE;
       menu_displayMenu(screen);
	menu_updateMenu();

  }
  return 0;
}
END_OF_MAIN();

//gcc -Wall <arquivo.c> -o programa -lalleg
