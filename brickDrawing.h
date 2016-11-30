#include <allegro.h>

BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
int bX1[8][10];
int bX2[8][10];
int bY1[8][10];
int bY2[8][10];
int colVM[10][10];
int colVD[10][10];
int colAZ[10][10];

void povoamento();