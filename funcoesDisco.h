#ifndef FUNCOES_DISCO
#define FUNCOES_DISCO


typedef struct Disco
{
    int x;
    int x2;
    int y;
    float c;
    float b;
    int isHit;

} Disco;
//Não conseguimos fazer com que fique de um jeito legal com uma array de discos
Disco disco1;
Disco disco2;
Disco disco3;

void trajetoriaDisco1();
void trajetoriaDisco2();
void trajetoriaDisco3();
int checkHit();

#endif
