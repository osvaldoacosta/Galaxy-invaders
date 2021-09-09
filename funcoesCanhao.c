#include "funcoesCanhao.h"
#include<stdio.h>
void inclinarCanhaoDireita()
{
    gotoxy(canhao.x,canhao.y);
    if(canhao.posicaoMira==-1)
    {
        printf("_|o|_");
        canhao.posicaoMira = 0;
    }
    else
    {
        printf("_/o/_");
        canhao.posicaoMira = 1;
    }
}
void inclinarCanhaoEsquerda()
{
    gotoxy(canhao.x,canhao.y);
    if(canhao.posicaoMira==1)
    {
        printf("_|o|_");
        canhao.posicaoMira = 0;
    }
    else
    {
        // "\\" imprime 1 backslash(\)
        printf("_\\o\\_");;
        canhao.posicaoMira = -1;
    }
}

void moverCanhaoDireita(){
  if(canhao.x < 112){
      gotoxy(canhao.x,canhao.y);
      printf("     ");
      canhao.x+=2;
      valoresPadroesProjetil();
      gotoxy(canhao.x,canhao.y);



    switch (canhao.posicaoMira) {
      case 0:
        printf("_|o|_");
        break;
      case -1:
        printf("_\\o\\_");
        break;
      case 1:
        printf("_/o/_");
        break;
    }
  }
}
void moverCanhaoEsquerda(){
  if(canhao.x > 2){
  gotoxy(canhao.x,canhao.y);
  printf("      ");
  canhao.x-=2;
  valoresPadroesProjetil();
  gotoxy(canhao.x,canhao.y);
  switch (canhao.posicaoMira) {
    case 0:
      printf("_|o|_");
      break;
    case -1:
      printf("_\\o\\_");
      break;
    case 1:
      printf("_/o/_");
      break;
  }
}
}
