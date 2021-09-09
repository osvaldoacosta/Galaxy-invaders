#include <stdio.h>
#include "funcoesEssenciais.h"
#include<windows.h>
#include "funcoesCanhao.h"
#include "funcoesProjetil.h"
#include "funcoesDisco.h"
#include "jogador.h"
#include <time.h>
#include <stdlib.h>
#define WIDTH 121
#define HEIGHT 41

void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

//Limpa as os inputs pressionadas pelo teclado
void limparBuffer(){
     FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
}

void valoresPadroesCanhao() {
  canhao.x = 60;
  canhao.y = 37;
  canhao.posicaoMira = 0;
}
void valoresPadroesProjetil(){
  projetil.x = canhao.x+2;
  projetil.y = canhao.y;
  projetil.isMoving = 0;
}
void valoresPadroesDisco1(){
  disco1.isHit = 0;
  disco1.x = 2;
  disco1.y = 0;
}
void valoresPadroesDisco2(){
  disco2.isHit = 0;
  disco2.x = 2;
  disco2.y = 0;
}
void valoresPadroesDisco3(){
  disco3.isHit = 0;
  disco3.x = 2;
  disco3.y = 0;
}
void valoresPadroesJogador(){
    jogador.pontuacao = 0;
}
void valoresPadroes()
{
    valoresPadroesCanhao();
    valoresPadroesProjetil();
    valoresPadroesDisco1();
    valoresPadroesDisco2();
    valoresPadroesDisco3();
    valoresPadroesJogador();
}

void randomizador(float *rc, float *rb){
    float outroc;
    float outrob;
    outroc = rand()%5;
    outrob = 24+(rand()%6);
    outrob = outrob/100;
    if (outrob>0.27){
        outroc = 5;
    }
    *rc = outroc;
    *rb = outrob;

}

void escondeCursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

int tempoLoop(int tempoJogo)
{
    gotoxy(1,1);
    printf("TEMPO: %d ", tempoJogo);
    return 1;
}

void borda(){
  for(int i=0;i <= 40;i++){
    if(i==1 || i==40){
      for(int j=0; j<119; j++){
        printf("*");
      }
    }else{
      for(int j=0; j<119; j++){
        if(j==0 || j==118){
        printf("*");
      }
      else printf(" ");
    }
    }
    printf("\n");
  }
}


//funcao para checar como anda as coordenadas do jogo ligar e desativar ao comentar na  na main
void modoDebug()
{
    gotoxy(50,30);
    printf("posicao da mira %d  ", canhao.posicaoMira );
    gotoxy(50,29);
    printf("posicao do x Projetil %d  ", projetil.x );
    gotoxy(50,28);
    printf("posicao do y Projetil %d  ", projetil.y );
    gotoxy(50,27);
    printf("posicao do x Canhao %d  ", canhao.x );

    gotoxy(50,26);
    printf("posicao do y Disco 1 %d  ", disco1.y );
    gotoxy(50,25);
    printf("posicao do x Disco 1 %d  ", disco1.x );
    gotoxy(50,24);
    printf("posicao do x Disco 2 %d  ", disco2.y );
    gotoxy(50,23);
    printf("posicao do x Disco 2 %d  ", disco2.x );
    gotoxy(50,22);
    printf("posicao do y Disco 1 %d  ", disco3.y );
    gotoxy(50,21);
    printf("posicao do x Disco 1 %d  ", disco3.x );
}

void redimensionarTela(){
    HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT windowSize = {0, 0, WIDTH - 1, HEIGHT - 1};
    COORD bufferSize = {WIDTH, HEIGHT};
    SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
    SetConsoleScreenBufferSize(wHnd, bufferSize);
}

//Substituto para o usleep(usleep tava depreciado :( )
void msSleep(long miliseg)
{
   struct timespec rem;
   struct timespec req= {
       (int)(miliseg / 1000),
       (miliseg % 1000) * 1000000
   };
   nanosleep(&req , &rem);
}
