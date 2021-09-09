#include <stdio.h>
#include "funcoesProjetil.h"
#include "funcoesCanhao.h"
#include "main.h"
#include <windows.h>
#include "funcoesEssenciais.h"
void tiroReto(){
  //trocar isso dps por ponteiro e recursao
  gotoxy(projetil.x,projetil.y+1);
  printf(" ");
  if(projetil.y > 10){
    projetil.isMoving = 1;
    gotoxy(projetil.x,projetil.y);
    printf("O");
    gotoxy(canhao.x,canhao.y);
    printf("_| |_");
    projetil.y--;
  }
  else{
        qtdBalas--;
        gotoxy(projetil.x,projetil.y);
        printf(" ");
        valoresPadroesProjetil();
  }


}


void tiroInclinado(){
  //trocar isso dps por ponteiro e recursao
  gotoxy(projetil.x-1,projetil.y+1);
  printf(" ");
  if(projetil.y > 10 && projetil.x < 117){
    projetil.isMoving = 1;
    gotoxy(projetil.x,projetil.y);
    printf("O");
    gotoxy(canhao.x,canhao.y);
    printf("_/ /_");
    projetil.y--;
    projetil.x++;
  }
  else{

    qtdBalas--;
    gotoxy(projetil.x,projetil.y);
    printf(" ");
    valoresPadroesProjetil();
  }

}
void tiroDeclinado(){
  //trocar isso dps por ponteiro e recursao
  gotoxy(projetil.x+1,projetil.y+1);
  printf(" ");
  if(projetil.y > 10  && projetil.x > 2){
    projetil.isMoving = 1;
    gotoxy(projetil.x,projetil.y);
    printf("O");
    gotoxy(canhao.x,canhao.y);
    printf("_\\ \\_");
    projetil.x--;
    projetil.y--;
  }
  else{
    qtdBalas--;
    gotoxy(projetil.x,projetil.y);
    printf(" ");
    valoresPadroesProjetil();
  }

}
