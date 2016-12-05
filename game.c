#include <allegro.h>

#include "game.h"
#include "options.h"
#include "brickDrawing.h"
#include "bat.h"

unsigned int lives = INITIAL_LIVE_COUNT;
unsigned int score = 0;

void loseLife()
{
	lives --;
	allegro_message("Nombre de vies : %d\n", lives);
	/* Implement here driver access to LEDs */

	batPosition = SCREEN_W/2 - options_batSize/2;
	bola.bolX = SCREEN_W/2;
	bola.bolY = SCREEN_H - BAT_Y_OFFSET - BAT_HEIGHT;
	// eventually allow the player to move the bat to reengage the game

	if (lives<=0)
	{
		gameOver();
		return;
	}

	int resume = FALSE;
	while (resume==FALSE)
	{
		if (key[KEY_SPACE])
			resume = TRUE;
	}

	
	return;
}

void gameOver()
{
	allegro_message("Game over, score final : %d \n", score);
	return;
}

// int score()
// {
// 	return score;
// }