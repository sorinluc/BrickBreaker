#include "bat.h"
#include "options.h"

int options_batColor = 0;

void displayBat(BITMAP* buffer, int xPos, int size)
{
	switch (options_batColor)
	{
		case 0:
			rectfill(
				buffer, (xPos-size/2),(SCREEN_H - (BAT_Y_OFFSET + BAT_HEIGTH)),
				(xPos+size/2), (SCREEN_H - BAT_Y_OFFSET), makecol(255, 193, 0));
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
			rectfill(
				buffer, (xPos-size/2), BAT_Y_OFFSET + BAT_HEIGTH,
				(xPos+size/2), BAT_Y_OFFSET, makecol(255, 193, 0));
		break;

	}
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