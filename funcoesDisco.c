#include "funcoesDisco.h"
#include "funcoesProjetil.h"


void trajetoriaDisco1(){


    if (disco1.x<115 && !disco1.isHit){
      int yPassado = (int)((0.002* (disco1.x-1)* (disco1.x-1)) - disco1.b*(disco1.x-1) + disco1.c+ 21);
      gotoxy(disco1.x-1,yPassado-1);
      printf("   ");
      gotoxy(disco1.x-1,yPassado);
      printf("    ");
      disco1.y = (int)((0.002 * (disco1.x) * (disco1.x)) - disco1.b*(disco1.x) + disco1.c+ 21); // achar uma equsção em que o Xv seja a metade da tela do jogo
      gotoxy(disco1.x+1,disco1.y-1);
      printf("/\\");
      gotoxy(disco1.x,disco1.y);
      printf("/__\\");
      disco1.x++;
    }
    else{
      gotoxy(disco1.x-1,disco1.y-1);
      printf("    ");
      gotoxy(disco1.x-1,disco1.y);
      printf("    ");
      valoresPadroesDisco1();
      randomizador(&disco1.c,&disco1.b);
    }

}
void trajetoriaDisco2(){

    if (disco2.x<115 && !disco2.isHit){
      int yPassado = (int)((0.002* (disco2.x-1)* (disco2.x-1)) - disco2.b*(disco2.x-1) + disco2.c+27);
      gotoxy(disco2.x-1,yPassado-1);
      printf("    ");
      gotoxy(disco2.x-1,yPassado);
      printf("    ");
      disco2.y = (int)((0.002 * (disco2.x) * (disco2.x)) - disco2.b*(disco2.x) + disco2.c+27);
      gotoxy(disco2.x,disco2.y-1);
      printf("[OO]");
      gotoxy(disco2.x,disco2.y);
      printf("||||");
      disco2.x++;
    }

    else{
      gotoxy(disco2.x-1,disco2.y-1);
      printf("    ");
      gotoxy(disco2.x-1,disco2.y);
      printf("    ");
      valoresPadroesDisco2();
      randomizador(&disco2.c,&disco2.b);
    }

}
void trajetoriaDisco3(){

    if (disco3.x<115 && !disco3.isHit){
      int yPassado = (int)((0.002* (disco3.x-1)* (disco3.x-1)) - disco3.b*(disco3.x-1) + disco3.c+33);
      gotoxy(disco3.x-1,yPassado-1);
      printf("    ");
      gotoxy(disco3.x-1,yPassado);
      printf("    ");
      disco3.y = (int)((0.002 * (disco3.x) * (disco3.x)) - disco3.b*(disco3.x) + disco3.c+33);
      gotoxy(disco3.x,disco3.y-1);
      printf("/||\\");
      gotoxy(disco3.x,disco3.y);
      printf("\\||/");
      disco3.x++;

    }

    else{
      gotoxy(disco3.x-1,disco3.y-1);
      printf("    ");
      gotoxy(disco3.x-1,disco3.y);
      printf("    ");
      valoresPadroesDisco3();
      randomizador(&disco3.c,&disco3.b);
    }

}



int checkHit(){
  if((disco1.x-1 == projetil.x || disco1.x  == projetil.x || disco1.x+1 == projetil.x || disco1.x+2 == projetil.x) && (disco1.y == projetil.y || disco1.y-1 == projetil.y)){ // coloquei o -1 pq so tava acertando o segundo @
    disco1.isHit = 1;
    return 1;
  } else if((disco2.x-1 == projetil.x || disco2.x  == projetil.x || disco2.x+1 == projetil.x || disco2.x+2 == projetil.x) && (disco2.y == projetil.y || disco2.y-1 == projetil.y)){
    disco2.isHit = 1;
    return 2;
  }else if((disco3.x-1 == projetil.x || disco3.x  == projetil.x || disco3.x+1 == projetil.x || disco3.x+2 == projetil.x) && (disco3.y == projetil.y || disco3.y-1 == projetil.y)){
    disco3.isHit = 1;
    return 3;
  }
  return 0;
}



