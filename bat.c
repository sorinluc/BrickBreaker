#include "bat.h"
#include "options.h"

int options_batColor = 0;

void displayBat(BITMAP* buffer, int xPos, int size)
{
	int color;
	
	switch (options_batColor)
	{
		case 0:
			color = makecol(255, 193, 0);
		break;

		case 1:
			//batImg = load_bitmap("./rsc/Pack/Bats/bat_black.pcx", NULL);
		break;

		case 2:
			//batImg = load_bitmap("./rsc/Pack/Bats/bat_blue.pcx", NULL);
		break;

		case 3:
			//batImg = load_bitmap("./rsc/Pack/Bats/bat_orange.pcx", NULL);
		break;

		case 4:
			//batImg = load_bitmap("./rsc/Pack/Bats/bat_rose.pcx", NULL);
		break;

		default:
			color = makecol(255, 193, 0);
		break;

	}

	rectfill(
		buffer,
		(xPos-size/2), SCREEN_H - (BAT_Y_OFFSET + BAT_HEIGTH),
		(xPos+size/2), (SCREEN_H - BAT_Y_OFFSET),
		color);

	return;
}

/*BITMAP* loadBatStyle()
{
	BITMAP *batImg;
	options_batColor = 0;

	switch (options_batColor)
	{
		case 0:
			rectfill( )
		break;

		case 1:
			batImg = load_bitmap("./rsc/Pack/Bats/bat_black.pcx", NULL);
		break;

		case 2:
			batImg = load_bitmap("./rsc/Pack/Bats/bat_blue.pcx", NULL);
		break;

		case 3:
			batImg = load_bitmap("./rsc/Pack/Bats/bat_orange.pcx", NULL);
		break;

		case 4:
			batImg = load_bitmap("./rsc/Pack/Bats/bat_rose.pcx", NULL);
		break;

		default:
			batImg = load_bitmap("./rsc/Pack/Bats/bat_yellow.pcx", NULL);
		break;

	}

	if (!batImg)
		allegro_message("Error loading bat image\n");

	return batImg;
	
}
*/