#include <allegro.h>

struct brickers {
  int bX1;
	int bX2;
	int bY1;
	int bY2;
	int colVM;
	int colVD;
	int colAZ;
  int bit;
};

struct brickers brick[8][10];

void povoamento(BITMAP* buffer);
void breakbrick(BITMAP* buffer, int Bi, int Bj);
