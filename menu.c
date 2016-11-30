#include "menu.h"
#include "functions.h"

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
			target, font, SCREEN_W / 2, SCREEN_H / 4 + i * menuGap,
			menuSelectedItemColor, -1, menuItems[i], NULL);
		}
		else
		{
			textprintf_ex(
			target, font, SCREEN_W / 2, SCREEN_H / 4 + i * menuGap,
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
	allegro_message("New game, new fame!\n");
	return;
}

void menu_optionsAction()
{
	return;
}

void menu_quitAction()
{
	allegro_exit();
	return;
}

void menu_debugAction()
{
	return;
}