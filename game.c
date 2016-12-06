#include <allegro.h>

#include "game.h"
#include "options.h"
#include "brickDrawing.h"
#include "bat.h"
#include "menu.h"

unsigned int lives = INITIAL_LIVE_COUNT;
unsigned int score = 0;
int gameOverBool = FALSE;

void initGame()
{
	gameOverBool = FALSE;
	lives = INITIAL_LIVE_COUNT;
	score = 0;
	povoamento();

	return;
}

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

	clear(screen);
	printBrick(screen);
	drawBat(screen, batPosition, options_batSize);

	textprintf_ex(
			screen, font, SCREEN_W / 2, SCREEN_H / 2,
			makecol(255,255,255), -1, "Press SPACE to resume");


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
	BITMAP *gameOverLogo;

   // INTRO
   	gameOverLogo = load_bitmap("./rsc/gameOver.bmp", NULL);
   	if (!gameOverLogo)
   	{
   		allegro_message("Error loading game over image\n");
   		return;
   	}

   	clear(screen);
   	blit(gameOverLogo, screen, 0, 0, (SCREEN_W /2 - gameOverLogo->w / 2), 0, gameOverLogo->w, gameOverLogo->h);

   	destroy_bitmap(gameOverLogo);

	textprintf_ex(
			screen, font, SCREEN_W / 2, SCREEN_H / 2,
			makecol(255,255,255), -1, "Game Over, final score : %d", score);

	textprintf_ex(
			screen, font, SCREEN_W / 2, (SCREEN_H / 2 + 50),
			makecol(255,255,255), -1, "Press SPACE to return to menu");

	int resume = FALSE;
	while (resume==FALSE)
	{
		if (key[KEY_SPACE])
			resume = TRUE;
	}

	gameOverBool = TRUE;
	return;
}

// int score()
// {
// 	return score;
// }