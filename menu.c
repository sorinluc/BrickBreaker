#include "menu.h"

void menu_displayMenu (BITMAP* target) {
	int menuitemcount = sizeof(menuItems) / sizeof(const char*);
	int i=0;
	for (i=0; i<menuitemcount; i++)
	{
		textprintf_ex(
			target, font, menuItems[i],
			SCREEN_W / 2, SCREEN_H / 2,
			makecol(255, 0, 0), makecol(0, 0, 0));
	}

}