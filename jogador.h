#ifndef FUNCOES_JOGADOR
#define FUNCOES_JOGADOR

typedef struct Jogador
{
    char nickname[20];
    int pontuacao;
    char dificuldade[10];

} Jogador;

Jogador jogador;



void ordenarRanking(Jogador jogadores[],int qtdJogadores);
void printRanking(Jogador jogadores[],int qtdJogador);
int qtdJogador();
void menuInicial();
void mostrarRanking();
void gerarRanking();
void voltarAoMenu();
void printRanking(Jogador jogadores[],int qtdJogadores);
void jogar();
void comoJogar();
void ranking();
void dificuldade();

void sair();

void terminoDeJogo();
void creditos();
#endif
