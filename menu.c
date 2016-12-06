#include <allegro.h>
#include <stdio.h>

#include "menu.h"
#include "functions.h"
#include "bat.h"
#include "options.h"
#include "brickDrawing.h"
#include "game.h"


extern int exit_program;

BITMAP *buffer;

static const char* menuItems[] = 
{
	"New Game",
	"Options",
	"Quit",
	"Debug Test"
};

static int menuSelectedIndex = 0;

int getMenuSize()
{
	return sizeof(menuItems) / sizeof(const char*);
}

void menu_displayMenu (BITMAP* target) {
	int menuSelectedItemColor = makecol(255, 255, 0); // yellow
	int menuUnselectedItemColor = makecol(128, 128, 128); // grey

	int menuitemcount = getMenuSize();
	int menuGap = 32;
	int i=0;

	for (i=0; i<menuitemcount; i++)
	{
		if (i == menuSelectedIndex)
		{
			textprintf_ex(
			target, font, SCREEN_W / 2, SCREEN_H / 2 + i * menuGap,
			menuSelectedItemColor, -1, menuItems[i], NULL);
		}
		else
		{
			textprintf_ex(
			target, font, SCREEN_W / 2, SCREEN_H / 2 + i * menuGap,
			menuUnselectedItemColor, -1, menuItems[i], NULL);
		}
		
	}

}

void menu_itemSelected()
{
	static void (*actions[]) () = 
	{
		&menu_newGameAction,
		&menu_optionsAction,
		&menu_quitAction,
		&menu_debugAction
	};

	actions[menuSelectedIndex]();
}

void menu_updateMenu()
{
	int key = readkey();
	key = toScanCode(key);

	if (key == KEY_UP) {
		menuSelectedIndex --;
		if (menuSelectedIndex == -1)
			menuSelectedIndex = 0;
	}

	if (key == KEY_DOWN) {
		menuSelectedIndex = (menuSelectedIndex + 1) % getMenuSize();
	}

	if (key == KEY_ENTER) {
		menu_itemSelected();
	}

}

void menu_newGameAction()
{
	clear(screen);	

	allegro_message("New game, new fame!\n");
	initGame();

	if (!initBuffer())
		allegro_message("Error : init buffer failed\n");


	while(!gameOverBool)
  {
    if(key[KEY_ESC])
    {
      gameOver();
      key[KEY_ESC] = 0;
    }

  	clear(buffer);

  	bolinha();
    breakbrick();
    barrabrick();
    printBrick(buffer);

  	updateBatPosition();
  	drawBat(buffer, batPosition, options_batSize);
  	bufferToScreen();
    rest(10);

  }
  	destroy_bitmap(buffer);

	return;
}

void menu_optionsAction()
{
	return;
}

void menu_quitAction()
{
	exit_program = TRUE;
	return;
}

void menu_debugAction()
{
	return;
}



int initBuffer()
{
	buffer = create_bitmap(SCREEN_W, SCREEN_H);
	if (!buffer)
		return FALSE;

	return TRUE;
}


void bufferToScreen()
{
	draw_sprite(screen, buffer, 0, 0);
}