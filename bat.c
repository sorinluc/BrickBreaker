#include "bat.h"
#include "options.h"

int options_batColor = 0;
int options_batSize = BAT_SIZE_MEDIUM;
int batPosition = 500;

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
		(xPos-size/2), 0,
		(xPos+size/2), BAT_HEIGTH,
		color);

	return;
}


int updateBatPosition()
{

	if (key[KEY_LEFT] && ((batPosition - options_batSize/2) >= 0))
	{
		batPosition -= BAT_MOVEMENT_STEP;
		key[KEY_LEFT] = 0;
	}

	if (key[KEY_RIGHT] && ((batPosition + options_batSize/2) <= SCREEN_W))
	{
		batPosition += BAT_MOVEMENT_STEP;
		key[KEY_RIGHT] = 0;
	}

	return batPosition;
}