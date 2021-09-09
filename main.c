#include<stdio.h>
#include<conio.h> //precisa pro getch
#include <time.h> //Necessario para o cronometro
#include <unistd.h>//Preciso pro
#include <stdlib.h>
#include "funcoesEssenciais.h"
#include "funcoesCanhao.h"
#include "funcoesProjetil.h"
#include "funcoesDisco.h"
#include "jogador.h"
#include "main.h"



void mostrarMunicao(){
    gotoxy(1,3);
    printf("Municao:%d  ",qtdBalas);
}

void atirar()
{

    switch (canhao.posicaoMira)
    {
    case 0:
        tiroReto();
        break;
    case -1:
        tiroDeclinado();
        break;
    case 1:
        tiroInclinado();
        break;
    }
}



void registrarComando(char input)
{
    switch (input)
    {
    case 'j':
        atirar();
        break;
    case 'k':
        inclinarCanhaoDireita();
        break;
    case 'h':
        inclinarCanhaoEsquerda();
        break;
    case 'd':
        moverCanhaoDireita();
        break;
    case 'a':
        moverCanhaoEsquerda();
        break;
    default:
        break;
    }
}

void pontuacaoJogo(int modPontuacao){
     switch(checkHit()){
            case 1:
                jogador.pontuacao += 300 * modPontuacao;
                gotoxy(disco1.x-1,disco1.y);
                printf("    ");
                gotoxy(disco1.x,disco1.y-1);
                printf("   ");
                valoresPadroesDisco1();
                randomizador(&disco1.c,&disco1.b);
                break;
            case 2:
                jogador.pontuacao += 100*modPontuacao;
                gotoxy(disco2.x-1,disco2.y);
                printf("    ");
                gotoxy(disco2.x-1,disco2.y-1);
                printf("    ");
                valoresPadroesDisco2();
                randomizador(&disco2.c,&disco2.b);
                break;
            case 3:
                jogador.pontuacao += 50*modPontuacao;
                gotoxy(disco3.x-1,disco3.y);
                printf("    ");
                gotoxy(disco3.x-1,disco3.y-1);
                printf("    ");
                valoresPadroesDisco3();
                randomizador(&disco3.c,&disco3.b);
                break;
            default:
                break;
        }

    gotoxy(1,2);

    printf("Pontuacao %d",(jogador.pontuacao));
}



int jogo(int modPontuacao,int velDificuldade)
{
    borda();
    system("color 9");
    qtdBalas = 10;
    valoresPadroes();
    gotoxy(canhao.x,canhao.y);
    printf("_|o|_");
    srand(time(NULL));

    randomizador(&disco1.c,&disco1.b);
    randomizador(&disco2.c,&disco2.b);
    randomizador(&disco3.c,&disco3.b);
    clock_t start = clock();
    do
    {
        limparBuffer();
        mostrarMunicao();

        //modoDebug(); //descomentar para ver as coordenadas
        pontuacaoJogo(modPontuacao);
        //usleep(velDificuldade); // velocidade do jogo (delay) DEPRECIADO LOGO TROCAMOS pro nanosleep

        msSleep(velDificuldade/1000); //velocidade do jogo (delay)
        trajetoriaDisco1();
        trajetoriaDisco2();
        trajetoriaDisco3();
        char kbInput;

        if(kbhit() && !projetil.isMoving)
        {

            kbInput = getch();

            registrarComando(kbInput);
        }
        else if(projetil.isMoving)
        {
            //input = ' ';
            atirar();
        }

    }
    while (tempoLoop((clock()-start)/CLOCKS_PER_SEC) && qtdBalas > 0);
    terminoDeJogo();

    return 0;
}
