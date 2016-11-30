#include "menu.h"

void menu_displayMenu (BITMAP* target) {
	int menuitemcount = sizeof(menuItems) / sizeof(const char*);
	int menuGap = 32;
	int i=0;
	for (i=0; i<menuitemcount; i++)
	{
		textprintf_ex(
			target, font, SCREEN_W / 2, SCREEN_H / 4 + i * menuGap,
			makecol(255, 100, 200), -1, menuItems[i]);
	}

}