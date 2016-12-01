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

struct bol {
  int bolX;
	int bolY;
	int bolR;
  int psB;
  int psL;
};

struct brickers brick[8][10];
struct bol bola;
int LARG = 1920;
int ALT = 1080;
int RAIO = 20;

void printBrick();
void povoamento(BITMAP* buffer);
void breakbrick(BITMAP* buffer, int Bi, int Bj);
void bolinha();
