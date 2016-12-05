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
  int incA;
  int incB;
};


struct colisao {
  int setC, setB, setE, setD;
};

#define Plinha 3
#define Ulinha 7
#define Nlinha 10
#define Pcol 3
#define Ucol 20
#define Ncol 22
#define VEL 1
#define RAIO 20
// #define LARG 1920
// #define ALT 900
#define MeB 10
// #define Blarg (((LARG - 40) / (Ncol)) - MeB)
// #define Balt ((((ALT/2) - 20) / (Nlinha)) - MeB)

struct brickers brick[Ucol][Ulinha];
extern struct bol bola;
struct colisao col [Ucol][Ulinha];

void printBrick(BITMAP* buffer);
void povoamento();
void breakbrick();
void bolinha();
void barrabrick();
