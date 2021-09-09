#include <stdio.h>
#include <stdlib.h>
#include "jogador.h"
#include <string.h>
#include <conio.h>
#include "main.h"
#include "funcoesEssenciais.h"
#include "windows.h"
//Gera os rankings iniciais
void gerarRanking(){
    FILE *ranking;
    ranking = fopen("Ranking.txt", "w+");


    fprintf(ranking,"? 0 ?\n");
    fprintf(ranking,"? 0 ?\n");
    fprintf(ranking,"? 0 ?\n");
    fprintf(ranking,"? 0 ?\n");
    fprintf(ranking,"? 0 ?\n");
    fprintf(ranking,"? 0 ?\n");
    fprintf(ranking,"? 0 ?\n");
    fprintf(ranking,"? 0 ?\n");
    fprintf(ranking,"? 0 ?\n");
    fprintf(ranking,"? 0 ?\n");


    fclose(ranking);

}

//Descobre a quantidade de linhas(jogadores) do arquivo texto
int qtdJogador(){
    FILE *ranking;
    ranking = fopen("Ranking.txt", "r");
    char c;
    int qtdJogadores = 0;

    if(ranking == NULL){
        gerarRanking();
        mostrarRanking();
    }

    while (!feof(ranking)) {
        c = fgetc(ranking);
        if(c == '\n'){
            qtdJogadores++;
        }
    }
    fclose(ranking);
    return qtdJogadores;
}

//mostra o ranking no console
void mostrarRanking(){
    int qtdJogadores = qtdJogador();

    FILE *ranking;

    int x = 0;

    Jogador jogadores[qtdJogadores];
    ranking = fopen("Ranking.txt", "r");

    while(x < qtdJogadores){
        fscanf(ranking, "%s %d %s\n",jogadores[x].nickname,&jogadores[x].pontuacao,jogadores[x].dificuldade);
        x++;
    }

    fclose(ranking);


    ordenarRanking(jogadores,qtdJogadores);
    printRanking(jogadores,qtdJogadores);
    voltarAoMenu();
}
//Mostra o ranking no console
void printRanking(Jogador jogadores[],int qtdJogadores){
    puts("Posicao\tJogador\tPontuacao Dificuldade");
    //Printa os 10 primeiros do ranking

    for(int i = 0;i<10;i++){
        //printf("%s", jogadores[i].dificuldade);
            printf("#%d\t%s\t%d\t%s\t\t\n", i+1, jogadores[i].nickname,jogadores[i].pontuacao,jogadores[i].dificuldade);

    }
}

//reordena a array de jogadores
void ordenarRanking(Jogador jogadores[],int qtdJogadores){
    Jogador temp;
    for(int i=0;i<qtdJogadores; i++){
        for(int j = i+1;j<qtdJogadores;j++){
        if(jogadores[i].pontuacao<jogadores[j].pontuacao){
            temp = jogadores[i];
            jogadores[i] = jogadores[j];
            jogadores[j] = temp;
            }
        }
    }
}


//adiciona um jogador
void alterarRanking(){
    FILE *ranking;
    ranking = fopen("Ranking.txt","a+");

    if(qtdJogador() < 10){
        gerarRanking();
        alterarRanking();

    }else{
        printf("Nome: ");
        scanf("%s", jogador.nickname);

        fprintf(ranking,"%s %d %s\n", jogador.nickname,jogador.pontuacao,jogador.dificuldade);

    }






    fclose(ranking);

}




int main(){
    SetConsoleTitle("Galaxy defenders");
    redimensionarTela();
    escondeCursor();
    jogador.pontuacao = 0;
    menuInicial();
    //gerarRanking(ranking);
    //alterarRanking();
    //mostrarRanking();
}

void menuInicial(){
    system("color 9");
    system("cls");
    gotoxy(19,1);
    printf("---GALAXY DEFENDERS---");
    gotoxy(10,3);
    printf("\t\tMENU INICIAL\t\n\n");
    printf("Dificuldade: %s\n\n", jogador.dificuldade);
    printf("Escolha uma opcao\n\n\n");
    printf("1-Jogar\n\n");
    printf("2-Como Jogar\n\n");
    printf("3-Ranking\n\n");
    printf("4-Dificuldade\n\n");
    printf("5-Creditos\n\n");
    printf("6-Sair\n\n");

    char opcoes = getch();
    switch(opcoes){
        case '1':
            printf("Carregando...");
            jogar();
        break;
        case '2':
            printf("Carregando...");
            comoJogar();
        break;
        case '3':
            printf("Carregando...");
            ranking();
        break;
        case '4':
            printf("Carregando...");
            dificuldade();
        break;
        case '5':
            printf("Carregando...");
            creditos();
        case '6':
            printf("Carregando...");
            sair();
        default:
            break;



    }
}
void voltarAoMenu(){
    int voltar;

    printf("\n\nDigite q para voltar ao menu");
    while(voltar != 'q'){
        limparBuffer();
        voltar = getch();
        switch(voltar){
            case 'q':
                menuInicial();
                break;
            default:
                break;
        }
    }
    printf("Carregando...");
    menuInicial();
}


void jogar(){
    system("cls");
    if(!strcmp(jogador.dificuldade ,"Facil")){
        //adiciona modificadores de pontuacao
        jogo(1,39000);
    }
    else if(!strcmp(jogador.dificuldade ,"Normal")){
        //adiciona modificadores de pontuacao
        jogo(2,29000);
    }
    else if(!strcmp(jogador.dificuldade ,"Dificil")){
        //adiciona modificadores de pontuacao
        jogo(3,10000);
    }
    else{

        printf("Selecione uma dificuldade antes de jogar");
        voltarAoMenu();
    }



}

void comoJogar(){
    system("cls");
    printf("Pressione (J) para atirar\n");
    printf("Pressione (D) para mover o canhao para direita\n");
    printf("Pressione (A) para mover o canhao para esquerda\n");
    printf("Pressione (H) para inclinar o canhao para esquerda\n");
    printf("Pressione (K) para inclinar o canhao para direita\n");
    printf("Antes de comecar o jogo voce devera escolher uma dificuldade, \no jogo nao iniciara se voce nao escolher uma dificuldade.");
    printf("Discos possuem pontuacoes diferentes:\n");
    printf(" /\\ \n/__\\ vale 300 pontos\n\n");
    printf("[OO]\n|||| vale 100 pontos\n\n");
    printf("/||\\ \n\\||/ vale 50 pontos\n\n");
    voltarAoMenu();
}

void dificuldade(){
    int dificuldade;
    system("cls");
    printf("Escolha a dificuldade\n\n");
    printf("1-Facil: multiplicador 1x na pontuacao\n\n");
    printf("2-Normal: multiplicador 2x na pontuacao\n\n");
    printf("3-Dificil: multiplicador 3x na pontuacao\n\n");

    dificuldade = getch();
    switch(dificuldade){
        case '1':
            strncpy(jogador.dificuldade,"Facil",8);

            break;
        case '2':
            strncpy(jogador.dificuldade,"Normal",8);

            break;
        case '3':
             strncpy(jogador.dificuldade,"Dificil",8);


            break;
    }
    printf("Voce escolheu a dificuldade %s!\n\n",jogador.dificuldade);
    voltarAoMenu();
}

void sair(){
    exit(0);
}

void ranking(){
    system("color 9");
    system("cls");

    mostrarRanking();
}

void terminoDeJogo(){
    system("cls");
    limparBuffer();

    printf("FIM DE JOGO\nDigite o seu nome para salvar o score\n");
    alterarRanking();

    ranking();
}

void creditos(){
 system("cls");
 printf("\t\t\t\t........AUTORES........\n\n");
 printf("Osvaldo Azevedo Costa\n\n");
 printf("Gustavo Antonio Porto Cardoso\n\n");
 printf("Marcel de Sales Castanha Lima\n\n");
 printf("Felipe Luiz Pianco Montepin\n\n");
        voltarAoMenu();
}



