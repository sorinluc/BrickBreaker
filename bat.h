#include <allegro.h>

extern int batPosition;

/* Draws the bat in the given buffer, at the given position,
eventualy resized */
void drawBat(BITMAP* buffer, int xPos, int size);

/* Displays the bat at the screen using double buffering */
void displayBat(BITMAP* buffer, int xPos);

/* Loads the correct image based on the options */
//BITMAP* loadBatStyle();


int updateBatPosition();

