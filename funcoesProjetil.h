
#ifndef FUNCOES_PROJETIL
#define FUNCOES_PROJETIL


typedef struct Projetil
{
    int x;
    int y;
    int isMoving;
} Projetil;
struct Projetil projetil;



void tiroReto();

void tiroDeclinado();

void tiroInclinado();

#endif
