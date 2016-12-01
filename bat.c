#include "bat.h"
#include "options.h"

int options_batColor = 1;

void displayBat(BITMAP* buffer, int xPos, int yPos, int size)
{

}

BITMAP* loadBatStyle()
{
	BITMAP* batImg;

	switch (options_batColor)
	{
		case 0:
			batImg = load_bitmap("./rsc/Pack/Bats/bat_yellow.png", NULL);
		break;

		case 1:
			batImg = load_bitmap("./rsc/Pack/Bats/bat_black.png", NULL);
		break;

		case 2:
			batImg = load_bitmap("./rsc/Pack/Bats/bat_blue.png", NULL);
		break;

		case 3:
			batImg = load_bitmap("./rsc/Pack/Bats/bat_orange.png", NULL);
		break;

		case 4:
			batImg = load_bitmap("./rsc/Pack/Bats/bat_rose.png", NULL);
		break;
	}

	if (!batImg)
		allegro_message("Error loading bat image\n");

	return batImg;
	
}
