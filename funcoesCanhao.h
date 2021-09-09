
#ifndef FUNCOES_CANHAO
#define FUNCOES_CANHAO

typedef struct Canhao
{
    int x;
    int y;
    int posicaoMira;
} Canhao;

Canhao canhao;

void inclinarCanhaoDireita();

void inclinarCanhaoEsquerda();

void moverCanhaoDireita();

void moverCanhaoEsquerda();

#endif
